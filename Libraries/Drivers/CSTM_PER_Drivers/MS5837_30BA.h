/*******************************************************************************
 * @file        : MS5837_30BA.h
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

#ifndef _MS5837_30BA_H_
#define _MS5837_30BA_H_

#define MS5837_I2C_ADDR         0x00EC

#define MS5837_MIN_TEMP		-2000L
#define MS5837_MAX_TEMP		8500L
#define MS5837_MIN_PRESS	0L
#define MS5837_MAX_PRESS	300000L

#define MS5837_RESET_RELOAD_DELAY_MS	5UL	// it was 3 but after HW reset first read value is wrong
#define MS5837_CALIBRATION_VALUES       7

#define MS5837_MEASURE_RETRIES          10

/* Maximum conversion times for different OSR expressed in us*/
#if 0
enum MS5837_CONVERSION_TIME_enum
{
  MS5837_CONVERSION_TIME_US_256   = 600UL,
  MS5837_CONVERSION_TIME_US_512   = 1170UL,
  MS5837_CONVERSION_TIME_US_1024  = 2280UL,
  MS5837_CONVERSION_TIME_US_2048  = 4540UL,
  MS5837_CONVERSION_TIME_US_4096  = 9040UL,
  MS5837_CONVERSION_TIME_US_8192  = 18080UL
};
#endif

/* Maximum conversion times for different OSR expressed in ms(rounded to higher integer)*/
enum MS5837_CONVERSION_TIME_enum
{
  MS5837_CONVERSION_TIME_MS_256   = 1UL,
  MS5837_CONVERSION_TIME_MS_512   = 2UL,
  MS5837_CONVERSION_TIME_MS_1024  = 3UL,
  MS5837_CONVERSION_TIME_MS_2048  = 5UL,
  MS5837_CONVERSION_TIME_MS_4096  = 10UL,
  MS5837_CONVERSION_TIME_MS_8192  = 19UL
};

/* Pressure convert commands */
typedef enum
{
  MS5837_ADC_READ               = 0x00,
  MS5837_RESET                  = 0x1E,
  MS5837_CONVERT_PRESSURE_256   = 0x40,
  MS5837_CONVERT_PRESSURE_512  	= 0x42,
  MS5837_CONVERT_PRESSURE_1024  = 0x44,
  MS5837_CONVERT_PRESSURE_2048  = 0x46,
  MS5837_CONVERT_PRESSURE_4096  = 0x48,
  MS5837_CONVERT_PRESSURE_8192  = 0x4A,
  MS5837_CONVERT_TEMP_256       = 0x50,
  MS5837_CONVERT_TEMP_512       = 0x52,
  MS5837_CONVERT_TEMP_1024      = 0x54,
  MS5837_CONVERT_TEMP_2048      = 0x56,
  MS5837_CONVERT_TEMP_4096      = 0x58,
  MS5837_CONVERT_TEMP_8192      = 0x5A,
  MS5837_READ_CAL_VALUE_0       = 0xA0,
  MS5837_READ_CAL_VALUE_1       = 0xA2,
  MS5837_READ_CAL_VALUE_2       = 0xA4,
  MS5837_READ_CAL_VALUE_3       = 0xA6,
  MS5837_READ_CAL_VALUE_4       = 0xA8,
  MS5837_READ_CAL_VALUE_5       = 0xAA,
  MS5837_READ_CAL_VALUE_6       = 0xAC,
  MS5837_READ_CAL_VALUE_7       = 0xAE
} MS5837_CMD_t;

/* Measure OSR */
typedef enum
{
  MS5837_OSR_256,
  MS5837_OSR_512,
  MS5837_OSR_1024,
  MS5837_OSR_2048,
  MS5837_OSR_4096,
  MS5837_OSR_8192
} MS5837_OSR_t;

/* Read type */
typedef enum
{
  MS5837_TEMP,
  MS5837_PRESS
} MS5837_read_t;

typedef struct
{
  /* Calibration words */
  uint16_t CAL_0;
  uint16_t CAL_1;
  uint16_t CAL_2;
  uint16_t CAL_3;
  uint16_t CAL_4;
  uint16_t CAL_5;
  uint16_t CAL_6;

  /* Conversion results */
  /* When updated press and temp will be set to their min value */
  uint32_t D1;			// pressure
  uint32_t D2;			//temperature

  /* Intermediate variables */
  int64_t OFFSET;
  int64_t SENS;

  /* Evaluation results */
  int32_t press;                  // Expressed in ubar x 100 (i.e. 31005 is 3100.5 mbar)
  int32_t temp;                   // Expressed in °mC x 10 (i.e. 2205 is 22.05°C)
  
  bool valid_data;
  
  bool sensor_failure;          // if true a failure on sensor or on comunication line has occurred

} MS5837_struct_t;

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
bool MS5837_Reset( uint8_t sensor_address );

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
bool MS5837_SM( uint8_t sensor_address, MS5837_CMD_t cmd );

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
bool MS5837_ADC_Read( uint8_t sensor_address, MS5837_struct_t *sensor, MS5837_read_t read_type );

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
bool MS5837_PT_Eval ( MS5837_struct_t *sensor );

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
bool MS5837_PROM_Read( uint8_t sensor_address, MS5837_CMD_t prom_address, uint16_t *value );

/*******************************************************************************
 * @brief
 *   Reads calibration values of the addressed sensor and stores them in the sensor structure.
 *
 * @details
 *
 * @note
 *
 * @param[in]
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MS5837_Read_CAL( uint8_t sensor_address, MS5837_struct_t *sensor );

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
bool MS5837_Init( uint8_t sensor_address, MS5837_struct_t *sensor );

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
bool MS5837_Meas( uint8_t sensor_address, MS5837_struct_t *sensor, MS5837_OSR_t osr, int32_t pressure_offset_ubarx100, int32_t temperature_offset_mCx10 );

#endif //_MS5837_30BA_H_