/*******************************************************************************
 * @file        MAX17262.c
 * @brief       MAX17262 Fuel Gauge 1-Cell with internal Sense
 * @version     1.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020 Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

#include "L4X9_includes.h"

#ifdef _MAX17262_H_

#define FGAUGE_I2C      I2C_BUS_B

bool MAX17262_ReadRegister (uint8_t register_address, uint16_t *register_value)
{
  uint8_t buff[2];
  
  buff[0] = register_address;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)buff, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)buff, 2, 10000)!= HAL_OK)
    return false;

  uint16_t reg = (uint16_t)buff[1];
  reg <<= 8;
  reg += (uint16_t)buff[0];
      
  (*register_value) = reg;
	
  return true;
}

bool MAX17262_WriteRegister (uint8_t register_address, uint16_t register_value)
{
  uint8_t w_buff[3];
  
  w_buff[0] = register_address;
  w_buff[1] = (uint8_t)(register_value & 0x00FF);
  w_buff[2] = (uint8_t)((register_value>>8) & 0x00FF);
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)w_buff, 3, 10000) != HAL_OK)
    return false;

  return true;
}


bool MAX17262_WriteReadVerifyRegister (uint8_t register_address, uint16_t register_value)
{ 
  uint8_t r_buff[2];
  uint8_t w_buff[3];
  
  w_buff[0] = register_address;
  w_buff[1] = (uint8_t)(register_value & 0x00FF);
  w_buff[2] = (uint8_t)((register_value>>8) & 0x00FF);
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)w_buff, 3, 10000) != HAL_OK)
    return false;

  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)w_buff, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&FGAUGE_I2C, MAX17262_I2C_ADDR, (uint8_t*)r_buff, 2, 10000)!= HAL_OK)
    return false;

  uint16_t reg = (uint16_t)r_buff[1];
  reg <<= 8;
  reg += (uint16_t)r_buff[0];
      
  if (reg == register_value)
      return true;
  else
      return false;
}

bool MAX17262_SaveLearnedParameters ( MAX17262_Learned_t *data )
{
  if ( !MAX17262_ReadRegister (MAX17262_RCOMP0, &data->RCOMP0) )
  {
    data->valid = false;
    return false;
  }
  
  if ( !MAX17262_ReadRegister (MAX17262_TEMPCO, &data->TempCo) )
  {
    data->valid = false;
    return false;
  }
  
  if ( !MAX17262_ReadRegister (MAX17262_FULLCAPREP, &data->FullCapRep) )
  {
    data->valid = false;
    return false;
  }
  
  if ( !MAX17262_ReadRegister (MAX17262_CYCLES, &data->Cycles) )
  {
    data->valid = false;
    return false;
  }
  
  if ( !MAX17262_ReadRegister (MAX17262_FULLCAPNOM, &data->FullCapNom) )
  {
    data->valid = false;
    return false;
  }

  data->valid = true;

  return true;
}


bool MAX17262_SetLearnedParameters (  MAX17262_Learned_t data  )
{
  if(data.valid)
  {
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_RCOMP0, data.RCOMP0) )
      return false;
    
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_TEMPCO, data.TempCo) )
      return false;
    
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_FULLCAPREP, data.FullCapRep) )
      return false;
    
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_DPACC, 0x0C80) )
      return false;
        
    uint16_t dQacc = data.FullCapNom / 2;
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_DQACC, dQacc) )
      return false;
    
    if ( !MAX17262_WriteReadVerifyRegister (MAX17262_CYCLES, data.Cycles) )
      return false;
  }

  return true;
}

bool MAX17262_Init ( MAX17262_Learned_t learned_data )
{
  uint16_t stat, fstat;
  bool i2c_txrx;
  int retry;
    
  /* Set Alert Output for Low Battery Notification */
  if(DEV_Board())
  {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Pin = MAX17262_ALRT_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.Alternate = 0;
    HAL_GPIO_Init(MAX17262_ALRT_PORT, &GPIO_InitStructure);
  }
  else
  {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Pin = PROD_MAX17262_ALRT_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.Alternate = 0;
    HAL_GPIO_Init(PROD_MAX17262_ALRT_PORT, &GPIO_InitStructure);
  }
  
  retry = 10;
  while((MAX17262_ReadRegister (MAX17262_STATUS, &stat) == false) && (retry-- > 0))
  {
  }
  if ( retry <= 0 )
    return false;
  
  /* Check If Power On Reset */
  if( stat & MAX17262_STAT_POR_MSK )
  {
    /* Wait for Chip to be ready */
    i2c_txrx = false;
    retry = 100;
    do{
      ms_delay(10);
      i2c_txrx = MAX17262_ReadRegister (MAX17262_FSTATUS, &fstat);
      if(!i2c_txrx)
        fstat = 0xFFFF;
    }while( (fstat & MAX17262_FSTAT_DNR_MSK) && (retry-- > 0) );
    if ( retry <= 0 )
      return false;
    
    /* Safe Hibernate Register and exit Hibernate Status */
    uint16_t HibCfg;
    retry = 10;
    while((MAX17262_ReadRegister (MAX17262_HIBCFG, &HibCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_SWCMD, 0x0090) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_HIBCFG, 0x0000) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_SWCMD, 0x0000) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    /* Set Battery Parameters */
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_DESIGNCAP, ((uint16_t)MAX17262_CAP_MA*2)) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
     
    uint32_t iterm = (((uint32_t)MAX17262_ITERM_MA)*100000)/15625;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_ICHRTERM, (uint16_t)iterm) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_VEMPTY, MAX17262_VEMPTY_V) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    uint16_t ModelCfg;
    if(MAX17262_CH_VOLT_HIGH == 1)
      ModelCfg = 0x8404;
    else
      ModelCfg = 0x8004;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_MODELCFG, ModelCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Wait for Model Refresh */
    i2c_txrx = false;
    retry = 1000;
    do{
      i2c_txrx = MAX17262_ReadRegister (MAX17262_MODELCFG, &ModelCfg);
      if(!i2c_txrx)
        ModelCfg = 0xFFFF;
    }while( (ModelCfg & MAX17262_MODELCFG_REFRESH_MSK) && (retry-- > 0) );
    if ( retry <= 0 )
      return false;
      
    uint16_t cfg1 = 0x0000;
    cfg1 |= MAX17262_CFG1_TSEL_INTERNAL;
    cfg1 |= MAX17262_CFG1_VS_AUTO;
    cfg1 |= MAX17262_CFG1_AEN_ON;
    cfg1 |= MAX17262_CFG1_TEN_CHOFF;
    cfg1 |= MAX17262_CFG1_TEX_OFF;
    cfg1 |= MAX17262_CFG1_ETHRM_OFF;
    cfg1 |= MAX17262_CFG1_FTHRM_OFF;
    cfg1 |= MAX17262_CFG1_AEN_OFF;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_CFG1, cfg1) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    uint16_t cfg2 = 0x0010;
    cfg2 |= MAX17262_CFG2_CPM_ON;
    cfg2 |= MAX17262_CFG2_DRCFG_SHORT;
    cfg2 |= MAX17262_CFG2_TALRTEN_OFF;
    cfg2 |= MAX17262_CFG2_DSOCEN_OFF;
    cfg2 |= MAX17262_CFG2_POWR_11S25;
    cfg2 |= MAX17262_CFG2_DPEN_OFF;
    cfg2 |= MAX17262_CFG2_ATRATEN_OFF;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_CFG2, cfg2) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Set Low Voltage Alert threshold */
    uint16_t valrt = (uint16_t)(MAX17262_LOW_BAT_ALRT_MV/20);
    valrt |= 0xFF00;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_VALRT_TH, valrt) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Restore Hibernate register and Enter Hibernate mode */
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_HIBCFG, HibCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Get Status Register and Clear POR flag */
    retry = 10;
    while((MAX17262_ReadRegister (MAX17262_STATUS, &stat) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_STATUS, (stat &0xFFFD)) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* If learned data available and valid set FG */
    if(learned_data.valid)
    {
      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_RCOMP0, learned_data.RCOMP0) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;
           
      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_TEMPCO, learned_data.TempCo) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;
      
      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_FULLCAPREP, learned_data.FullCapRep) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;

      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_DPACC, 0x0C80) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;
      
      uint16_t dQacc = learned_data.FullCapNom / 2;
      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_DQACC, dQacc) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;
      
      retry = 10;
      while((MAX17262_WriteReadVerifyRegister (MAX17262_CYCLES, learned_data.Cycles) == false) && (retry-- > 0))
      {
      }
      if ( retry <= 0 )
        return false;
    }
  }
  return true;
}

bool MAX17262_Reset ( void )
{
  uint16_t stat, fstat;
  bool i2c_txrx;
  int retry;

  {
    /* Wait for Chip to be ready */
    i2c_txrx = false;
    retry = 100;
    do{
      ms_delay(10);
      i2c_txrx = MAX17262_ReadRegister (MAX17262_FSTATUS, &fstat);
      if(!i2c_txrx)
        fstat = 0xFFFF;
    }while( (fstat & MAX17262_FSTAT_DNR_MSK) && (retry-- > 0) );
    if ( retry <= 0 )
      return false;
    
    /* Safe Hibernate Register and exit Hibernate Status */
    uint16_t HibCfg;
    retry = 10;
    while((MAX17262_ReadRegister (MAX17262_HIBCFG, &HibCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_SWCMD, 0x0090) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_HIBCFG, 0x0000) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    retry = 10;
    while((MAX17262_WriteRegister (MAX17262_SWCMD, 0x0000) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    /* Set Battery Parameters */
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_DESIGNCAP, ((uint16_t)MAX17262_CAP_MA*2)) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
     
    uint32_t iterm = (((uint32_t)MAX17262_ITERM_MA)*100000)/15625;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_ICHRTERM, (uint16_t)iterm) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_VEMPTY, MAX17262_VEMPTY_V) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    uint16_t ModelCfg;
    if(MAX17262_CH_VOLT_HIGH == 1)
      ModelCfg = 0x8404;
    else
      ModelCfg = 0x8004;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_MODELCFG, ModelCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Wait for Model Refresh */
    i2c_txrx = false;
    retry = 1000;
    do{
      i2c_txrx = MAX17262_ReadRegister (MAX17262_MODELCFG, &ModelCfg);
      if(!i2c_txrx)
        ModelCfg = 0xFFFF;
    }while( (ModelCfg & MAX17262_MODELCFG_REFRESH_MSK) && (retry-- > 0) );
    if ( retry <= 0 )
      return false;
      
    uint16_t cfg1 = 0x0000;
    cfg1 |= MAX17262_CFG1_TSEL_INTERNAL;
    cfg1 |= MAX17262_CFG1_VS_AUTO;
    cfg1 |= MAX17262_CFG1_AEN_ON;
    cfg1 |= MAX17262_CFG1_TEN_CHOFF;
    cfg1 |= MAX17262_CFG1_TEX_OFF;
    cfg1 |= MAX17262_CFG1_ETHRM_OFF;
    cfg1 |= MAX17262_CFG1_FTHRM_OFF;
    cfg1 |= MAX17262_CFG1_AEN_OFF;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_CFG1, cfg1) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
    
    uint16_t cfg2 = 0x0010;
    cfg2 |= MAX17262_CFG2_CPM_ON;
    cfg2 |= MAX17262_CFG2_DRCFG_SHORT;
    cfg2 |= MAX17262_CFG2_TALRTEN_OFF;
    cfg2 |= MAX17262_CFG2_DSOCEN_OFF;
    cfg2 |= MAX17262_CFG2_POWR_11S25;
    cfg2 |= MAX17262_CFG2_DPEN_OFF;
    cfg2 |= MAX17262_CFG2_ATRATEN_OFF;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_CFG2, cfg2) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Set Low Voltage Alert threshold */
    uint16_t valrt = (uint16_t)(MAX17262_LOW_BAT_ALRT_MV/20);
    valrt |= 0xFF00;
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_VALRT_TH, valrt) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Restore Hibernate register and Enter Hibernate mode */
    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_HIBCFG, HibCfg) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    /* Get Status Register and Clear POR flag */
    retry = 10;
    while((MAX17262_ReadRegister (MAX17262_STATUS, &stat) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;

    retry = 10;
    while((MAX17262_WriteReadVerifyRegister (MAX17262_STATUS, (stat &0xFFFD)) == false) && (retry-- > 0))
    {
    }
    if ( retry <= 0 )
      return false;
  }
  return true;
}



bool MAX17262_GetFgOutput ( void )
{   
  uint16_t reg;
  uint32_t utmp;
  int32_t itmp;
  
  /* Read RepSoc */
  if ( !MAX17262_ReadRegister (MAX17262_REPSOC, &reg) )
    return false;
  utmp = (uint32_t)reg;
  utmp *= 25600;
  utmp /= (256*256);                 
  MAX17262_Output.RepSoc_cx100 = utmp;  // in c%
    
  /* Read TTE */
  if( !MAX17262_ReadRegister (MAX17262_TTE, &reg) )
    return false;
  utmp = (uint32_t)reg;
  utmp *= 5625;
  utmp /= 1000;                                  
  MAX17262_Output.TTE_s = utmp;         // in s  

  /* Read TTF */
  if( !MAX17262_ReadRegister (MAX17262_TTF, &reg) )
    return false;
  utmp = (uint32_t)reg;
  utmp *= 5625;
  utmp /= 1000;                                  
  MAX17262_Output.TTF_s = utmp;         // in s  
  
  /* Read Average Voltage */
  if( !MAX17262_ReadRegister (MAX17262_VOLT_AVG, &reg) )
    return false;
  utmp = (uint32_t)reg;
  utmp *= 16*1250;
  utmp /= (16*16*1000);                              
  MAX17262_Output.AvgVoltage_mV = utmp; // in mV
  
  /* Read Average Current */
  if( !MAX17262_ReadRegister (MAX17262_CURR_AVG, &reg) )
    return false;
  itmp = (int32_t)((int16_t)reg);
  itmp *= (int32_t)15625;
  itmp /= (int32_t)100;                            
  MAX17262_Output.AvgCurrent_uA = itmp; // in uA
  
  return true;
}

#endif // _MAX17262_H_