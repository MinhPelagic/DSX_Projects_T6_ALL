/*******************************************************************************
 * @file        : MS5837_30BA.c
 * @brief       : Low Level Driver for MS5837_30BA Pressure and Temperature 
 *                Sensor on I2C System BUS.
 *                This driver uses the HAL I2C driver of STMCUBE MX.
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The MS5837_30BA driver is build on the I2C system bus.
 *
 ******************************************************************************/

#include "L4X9_includes.h"

#ifdef _MS5837_30BA_H_

#define PSENSOR_I2C     I2C_BUS_B

/*******************************************************************************
 * @brief
 *   Reset Sensor the addressed sensor.
 *   Returns only after reset time elapsed.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_Reset( uint8_t sensor_address )
{
  uint8_t I2C_TxBuffer[32];

  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = MS5837_RESET;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;

  /* Wait Reset time in low power mode */
  ms_LP_delay(MS5837_RESET_RELOAD_DELAY_MS);
  
  return true;
}

/*******************************************************************************
 * @brief
 *   Start Pressure or Temperature measurement with the defined oversampling ratio
 *   of the addressed sensor.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_SM( uint8_t sensor_address, MS5837_CMD_t cmd )
{
  uint8_t I2C_TxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)cmd;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  else
    return true;
}

/*******************************************************************************
 * @brief
 *   Reads Pressure or Temperature conversion value of the addressed sensor and
 *   stores them in the sensor structure.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_ADC_Read( uint8_t sensor_address, MS5837_struct_t *sensor, MS5837_read_t read_type )
{
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = MS5837_ADC_READ;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_RxBuffer, 3, 10000)!= HAL_OK)
    return false;
  
  switch (read_type)
  {
    case MS5837_TEMP:
      sensor->D2 = 0;
      sensor->D2 = (uint32_t)I2C_RxBuffer[0];
      sensor->D2 <<= 8;
      sensor->D2 += (uint32_t)I2C_RxBuffer[1];
      sensor->D2 <<= 8;
      sensor->D2 += (uint32_t)I2C_RxBuffer[2];
      break;
      
    case MS5837_PRESS:
      sensor->D1 = 0;
      sensor->D1 = (uint32_t)I2C_RxBuffer[0];
      sensor->D1 <<= 8;
      sensor->D1 += (uint32_t)I2C_RxBuffer[1];
      sensor->D1 <<= 8;
      sensor->D1 += (uint32_t)I2C_RxBuffer[2];
      break;
  }

  sensor->valid_data = false;

  return true;
}

/*******************************************************************************
 * @brief
 *   Evaluates Pressure and Temperature value of the addressed sensor structure.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_PT_Eval ( MS5837_struct_t *sensor )
{
  /* Evaluate Temperature */
  int32_t dT = (int32_t)sensor->D2 - ((int32_t)sensor->CAL_5 * 256L);

  sensor->temp = (int32_t)(2000LL + ((int64_t)dT * sensor->CAL_6) / 8388608LL);

  sensor->OFFSET = ((int64_t)sensor->CAL_2 * 65536LL) + ((int64_t)sensor->CAL_4 * dT) / 128LL;

  sensor->SENS = ((int64_t)sensor->CAL_1 * 32768LL) + ((int64_t)sensor->CAL_3 * dT) / 256LL;

  /* Second order compensation */
  int64_t T2, OFFSET_2, SENS_2;

  if ( sensor->temp < 2000 )
  {
    T2 = ( 3LL *(int64_t)dT*dT ) / 8589934592LL;
    OFFSET_2 = ( 3LL * ((int64_t)sensor->temp - 2000LL) * ((int64_t)sensor->temp - 2000LL) ) / 2LL;
    SENS_2 = ( 5LL * ((int64_t)sensor->temp - 2000LL) * ((int64_t)sensor->temp - 2000LL) ) / 8LL;

    if (sensor->temp < -1500)
    {
      OFFSET_2 += 7LL * ((int64_t)sensor->temp + 1500LL) * ((int64_t)sensor->temp + 1500LL);
      SENS_2 += 4LL * ((int64_t)sensor->temp + 1500LL) * ((int64_t)sensor->temp + 1500LL);
    }
  }
  else
  {
    T2 = ( 2LL *(int64_t)dT*dT ) / 137438953472LL;
    OFFSET_2 = (((int64_t)sensor->temp - 2000LL) * ((int64_t)sensor->temp - 2000LL))  / 16LL;
    SENS_2 = 0;
  }

  sensor->temp -= (int32_t)T2;
  sensor->OFFSET -= OFFSET_2;
  sensor->SENS -= SENS_2;

  /* Evaluate Pressure */
  sensor->press = (int32_t)( ( ( ( (int64_t)sensor->D1 * sensor->SENS ) / 2097152LL ) - sensor->OFFSET) / 8192LL );

  sensor->valid_data = true;

  return true;
}

/*******************************************************************************
 * @brief
 *   Reads prom location of the addressed sensor.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_PROM_Read( uint8_t sensor_address, MS5837_CMD_t prom_address, uint16_t *value )
{	 
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)prom_address;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&PSENSOR_I2C, (uint16_t)sensor_address, (uint8_t*)I2C_RxBuffer, 2, 10000)!= HAL_OK)
    return false;
  
  (*value) = (((uint16_t)I2C_RxBuffer[0])<<8) + (uint16_t)I2C_RxBuffer[1];

  return true;
}

/*******************************************************************************
 * @brief
 *   Reads calibration values of the addressed sensor and stores them in the sensor structure.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_Read_CAL( uint8_t sensor_address, MS5837_struct_t *sensor )
{
  uint16_t cal_value;
  
  uint16_t n_prom[8];

  for (uint8_t i = 0; i < MS5837_CALIBRATION_VALUES; i++)
  {
    switch(i)
    {
      case 0:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_0, &cal_value ) )
          return false;
        
        sensor->CAL_0 = cal_value;
        n_prom[0] = sensor->CAL_0;
        break;
        
      case 1:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_1, &cal_value ) )
          return false;

        sensor->CAL_1 = cal_value;
        n_prom[1] = sensor->CAL_1;
        break;

      case 2:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_2, &cal_value ) )
          return false;

        sensor->CAL_2 = cal_value;
        n_prom[2] = sensor->CAL_2;
        break;

      case 3:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_3, &cal_value ) )
          return false;

        sensor->CAL_3 = cal_value;
        n_prom[3] = sensor->CAL_3;
        break;

      case 4:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_4, &cal_value ) )
          return false;

        sensor->CAL_4 = cal_value;
        n_prom[4] = sensor->CAL_4;
        break;

      case 5:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_5, &cal_value ) )
        return false;

        sensor->CAL_5 = cal_value;
        n_prom[5] = sensor->CAL_5;
        break;

      case 6:
        if ( !MS5837_PROM_Read( sensor_address, MS5837_READ_CAL_VALUE_6, &cal_value ))
          return false;

        sensor->CAL_6 = cal_value;
        n_prom[6] = sensor->CAL_6;
        break;
    }
  }
  
  uint16_t n_rem = 0;                           // crc remainder
  uint8_t CRC4 = (uint8_t)((n_prom[0] >> 12) & 0x000F);
  
  n_prom[0] = ((n_prom[0]) & 0x0FFF);           // CRC byte is replaced by 0
  n_prom[7] = 0;                                // Subsidiary value, set to 0
  
  for (int16_t cnt = 0; cnt < 16; cnt++)        // operation is performed on bytes
  {                                             // choose LSB or MSB
    if (cnt%2 == 1)
      n_rem ^= ((n_prom[cnt>>1]) & 0x00FF);
    else 
      n_rem ^= (n_prom[cnt>>1]>>8);
      
    for (int8_t n_bit = 8; n_bit > 0; n_bit--)
    {
      if (n_rem & (0x8000)) 
        n_rem = (n_rem << 1) ^ 0x3000;
      else 
        n_rem = (n_rem << 1);
    }
  }
  n_rem = ((n_rem >> 12) & 0x000F);             // final 4-bit remainder is CRC code
  n_rem ^= 0x00;
  
  if((uint8_t)n_rem == CRC4)
    return true;
  else
    return false;
}


/*******************************************************************************
 * @brief
 *   Reset Sensor.
 *   Initialize Sensor Data Structure.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_Init( uint8_t sensor_address, MS5837_struct_t *sensor )
{
  /* Reset Sensor */
  if ( !MS5837_Reset (sensor_address) )
    return false;

  /* Store the Calibration data in the sensor struct */
  if ( !MS5837_Read_CAL (sensor_address, sensor) )
    return false;

  /* Set data not valid */
  sensor->valid_data = false;

  return true;
}

/*******************************************************************************
 * @brief
 *   Temperature and Pressure measurement routine
 *
 * @note
 *	To allow correct execution MS5837_Init() must be called at least once
 *	after Power-on or any Reset.
 *      Do not use this in Interrupt routines.
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_Meas( uint8_t sensor_address, MS5837_struct_t *sensor, MS5837_OSR_t osr, int32_t pressure_offset_ubarx100, int32_t temperature_offset_mCx10 )
{
  MS5837_CMD_t pressure_cmd, temperature_cmd;
  uint32_t meas_delay;

  switch (osr)
  {
    case MS5837_OSR_256:
      pressure_cmd = MS5837_CONVERT_PRESSURE_256;
      temperature_cmd = MS5837_CONVERT_TEMP_256;
      meas_delay = MS5837_CONVERSION_TIME_MS_256+MS5837_CONVERSION_TIME_MS_256/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_256+MS5837_CONVERSION_TIME_US_256/2;
      break;

    case MS5837_OSR_512:
      pressure_cmd = MS5837_CONVERT_PRESSURE_512;
      temperature_cmd = MS5837_CONVERT_TEMP_512;
      meas_delay = MS5837_CONVERSION_TIME_MS_512+MS5837_CONVERSION_TIME_MS_512/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_512+MS5837_CONVERSION_TIME_US_512/2;
      break;

    case MS5837_OSR_1024:
      pressure_cmd = MS5837_CONVERT_PRESSURE_1024;
      temperature_cmd = MS5837_CONVERT_TEMP_1024;
      meas_delay = MS5837_CONVERSION_TIME_MS_1024+MS5837_CONVERSION_TIME_MS_1024/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_1024+MS5837_CONVERSION_TIME_US_1024/2;
      break;

    case MS5837_OSR_2048:
      pressure_cmd = MS5837_CONVERT_PRESSURE_2048;
      temperature_cmd = MS5837_CONVERT_TEMP_2048;
      meas_delay = MS5837_CONVERSION_TIME_MS_2048+MS5837_CONVERSION_TIME_MS_2048/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_2048+MS5837_CONVERSION_TIME_US_2048/2;
      break;

    case MS5837_OSR_4096:
      pressure_cmd = MS5837_CONVERT_PRESSURE_4096;
      temperature_cmd = MS5837_CONVERT_TEMP_4096;
      meas_delay = MS5837_CONVERSION_TIME_MS_4096+MS5837_CONVERSION_TIME_MS_4096/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_4096+MS5837_CONVERSION_TIME_US_4096/2;
      break;

    case MS5837_OSR_8192:
      pressure_cmd = MS5837_CONVERT_PRESSURE_8192;
      temperature_cmd = MS5837_CONVERT_TEMP_8192;
      meas_delay = MS5837_CONVERSION_TIME_MS_8192+MS5837_CONVERSION_TIME_MS_8192/2;
      //meas_delay = MS5837_CONVERSION_TIME_US_8192+MS5837_CONVERSION_TIME_US_8192/2;
      break;

    default:
      return false;
  }

  /* Start Temperature Measurement */
  int8_t retry = MS5837_MEASURE_RETRIES;
  while((MS5837_SM (sensor_address, temperature_cmd) == false) && (retry-- > 0))
  {
  }
  if ( retry <= 0 )
  {
    sensor->valid_data = false;
    sensor->sensor_failure = true;
    
    return false;
  }

  /* Wait Conversion time */
  ms_LP_delay(meas_delay);

  /* Read Temperature D2 value */
  retry = MS5837_MEASURE_RETRIES;
  while((MS5837_ADC_Read (sensor_address, sensor, MS5837_TEMP) == false) && (retry-- > 0))
  {
  }
  if ( retry <= 0 )
  {
    sensor->valid_data = false;
    sensor->sensor_failure = true;
    
    return false;
  }

  /* Start Pressure Measurement */
  retry = MS5837_MEASURE_RETRIES;
  while((MS5837_SM (sensor_address, pressure_cmd) == false) && (retry-- > 0))
  {
  }
  if ( retry <= 0 )
  {
    sensor->valid_data = false;
    sensor->sensor_failure = true;
    
    return false;
  }

  /* Wait Conversion time */
  ms_LP_delay(meas_delay);

  /* Read Pressure D1 value */
  retry = MS5837_MEASURE_RETRIES;
  while((MS5837_ADC_Read (sensor_address, sensor, MS5837_PRESS) == false) && (retry-- > 0))
  {
  }
  if ( retry <= 0 )
  {
    sensor->valid_data = false;
    sensor->sensor_failure = true;
    
    return false;
  }

  /* Evaluate Pressure and Temperature data */
  if ( !MS5837_PT_Eval (sensor) )
    return false;
  
  /* Apply Offset Calibration */
  if(pressure_offset_ubarx100 != 0xFFFFFFFF)
    sensor->press += pressure_offset_ubarx100;
  if(temperature_offset_mCx10 != 0xFFFFFFFF)
    sensor->temp += temperature_offset_mCx10;

  return true;
}

#endif //_MS5837_30BA_H_
