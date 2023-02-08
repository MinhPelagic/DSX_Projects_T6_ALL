/*******************************************************************************
 * @file        : LSM303AGr.c
 * @brief       : Low Level Driver for 6-Axis Mems LSM303AGR
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _LSM303AGR_H_

#define EC_I2C          I2C_BUS_B
   
// Accelerometer Resolution
static uint8_t AccRes = 0;
uint8_t AccFs = 0;

bool LSM303AGR_GetReg_A( uint8_t RegAddress, uint8_t *reg )
{	 
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)RegAddress;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_A, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_A, (uint8_t*)I2C_RxBuffer, 1, 10000)!= HAL_OK)
    return false;
  
  (*reg) = I2C_RxBuffer[0];

  return true;
}

bool LSM303AGR_SetReg_A( uint8_t RegAddress, uint8_t reg )
{	 
  uint8_t I2C_TxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)RegAddress;
  I2C_TxBuffer[1] = (uint8_t)reg;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_A, (uint8_t*)I2C_TxBuffer, 2, 10000) != HAL_OK)
    return false;

  return true;
}

bool LSM303AGR_GetReg_M( uint8_t RegAddress, uint8_t *reg )
{	 
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)RegAddress;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_M, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_M, (uint8_t*)I2C_RxBuffer, 1, 10000)!= HAL_OK)
    return false;
  
  (*reg) = I2C_RxBuffer[0];

  return true;
}

bool LSM303AGR_SetReg_M( uint8_t RegAddress, uint8_t reg )
{	 
  uint8_t I2C_TxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)RegAddress;
  I2C_TxBuffer[1] = (uint8_t)reg;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_M, (uint8_t*)I2C_TxBuffer, 2, 10000) != HAL_OK)
    return false;

  return true;
}


//-------------------------------- Accelerometer -------------------------------

bool LSM303AGR_WhoAmI_A( uint8_t *value )
{	 
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)LSM303AGR_WHO_AM_I_A;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_A, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_A, (uint8_t*)I2C_RxBuffer, 1, 10000)!= HAL_OK)
    return false;
  
  (*value) = I2C_RxBuffer[0];

  return true;
}


bool LSM303AGR_Reboot_A( void )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL5_A, &Reg ))
    return false;
  
  Reg |= 0x80;
  
  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL5_A, Reg ))
    return false;
   
  ms_delay(10);
  
  return true;
}

bool LSM303AGR_SetOdr_A( uint8_t Odr )
{
  uint8_t Reg1, Reg4;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL1_A, &Reg1 ))
    return false;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL4_A, &Reg4 ))
    return false;
  
  Reg1 &= ~(0x0F<<4);
  Reg1 |= Odr << 4;

  // Force LP Mode For 1.62Khz selection
  if(   (Odr == LSM303AGR_A_ODR_5k37Hz)
     || (Odr == LSM303AGR_A_ODR_1k62Hz)
    )
  {
    Reg4 &= ~(1<<3);
    if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL4_A, Reg4 ))
      return false;
    
    Reg1 |= (1<<3);
    AccRes = 8;
  }
  else
    Reg1 &= ~(1<<3);

  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL1_A, Reg1 ))
    return false;

  return true;
}

bool LSM303AGR_SetFs_A( uint8_t Fs)
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL4_A, &Reg ))
    return false;
  
  Reg &= ~(0x03<<4);
  Reg |= Fs << 4;
  
  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL4_A, Reg ))
    return false;
   
  switch (Fs)
  {
    case LSM303AGR_A_2g:
      AccFs = 2;
      break;
    
    case LSM303AGR_A_4g:
      AccFs = 4;
      break;
      
    case LSM303AGR_A_8g:
      AccFs = 8;
      break;
      
    case LSM303AGR_A_16g:
      AccFs = 16;
      break;
  }
  
  return true;
}


bool LSM303AGR_SetBdu_A( bool enable )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL4_A, &Reg ))
    return false;
  
  Reg &= ~(0x80);
  if(enable)
    Reg |= 0x80;
  
  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL4_A, Reg ))
    return false;
   
  return true;
}

bool LSM303AGR_SetResolution( uint8_t Resolution )
{
  uint8_t Reg1, Reg4;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL1_A, &Reg1 ))
    return false;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_CTRL4_A, &Reg4 ))
    return false;
  
  Reg1 &= ~(0x01<<3);
  Reg4 &= ~(0x01<<3);
  
  switch(Resolution)
  {
    case LSM303AGR_A_8B:
      
      Reg1 |= (0x01<<3);
        
      AccRes = 8;
      
      break;
      
    case LSM303AGR_A_10B:
        
      AccRes = 10;
      
      break;
      
    case LSM303AGR_A_12B:
      
      Reg4 |= (0x01<<3);
        
      AccRes = 12;
      
      break;
  }
  
  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL1_A, Reg1 ))
    return false;
  
  if(!LSM303AGR_SetReg_A( LSM303AGR_CTRL4_A, Reg4 ))
    return false;

  return true;
}

bool LSM303AGR_GetRawData_A( int16_t *x, int16_t *y, int16_t *z )
{
  uint8_t X_L, X_H, Y_L, Y_H, Z_L, Z_H;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_X_L_A, &X_L ))
    return false;
  
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_X_H_A, &X_H ))
    return false;
    
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_Y_L_A, &Y_L ))
    return false;
    
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_Y_H_A, &Y_H ))
    return false;
    
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_Z_L_A, &Z_L ))
    return false;
    
  if(!LSM303AGR_GetReg_A( LSM303AGR_OUT_Z_H_A, &Z_H ))
    return false;
  
  (*x) = (int16_t)X_L;
  (*x) += (((int16_t)X_H)<<8);
  
  (*y) = (int16_t)Y_L;
  (*y) += (((int16_t)Y_H)<<8);
  
  (*z) = (int16_t)Z_L;
  (*z) += (((int16_t)Z_H)<<8);
  
  switch(AccRes)
  {
    case 0:
      (*x) = 0;
      (*y) = 0;
      (*z) = 0;
      break;
      
    case 8:
      (*x) >>= 8;
      (*y) >>= 8;
      (*z) >>= 8;
      break;
      
    case 10:
      (*x) >>= 6;
      (*y) >>= 6;
      (*z) >>= 6;
      break;
      
    case 12:
      (*x) >>= 4;
      (*y) >>= 4;
      (*z) >>= 4;
      break;
  }
  
  return true;
}



//-------------------------------- Magnetometer --------------------------------

bool LSM303AGR_WhoAmI_M( uint8_t *value )
{	 
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[0] = (uint8_t)LSM303AGR_WHO_AM_I_M;
  
  /* Try to Transmit Data */
  if(HAL_I2C_Master_Transmit(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_M, (uint8_t*)I2C_TxBuffer, 1, 10000) != HAL_OK)
    return false;
  
  /* Try to Read Data */
  if(HAL_I2C_Master_Receive(&EC_I2C, (uint16_t)LSM303AGR_I2C_ADD_M, (uint8_t*)I2C_RxBuffer, 1, 10000)!= HAL_OK)
    return false;
  
  (*value) = I2C_RxBuffer[0];

  return true;
}


bool LSM303AGR_SoftReset_M( void )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_A_M, &Reg ))
    return false;
  
  Reg |= 0x20;
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_A_M, Reg ))
    return false;
  
  return true;
}

bool LSM303AGR_SetOdr_M( uint8_t Odr)
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_A_M, &Reg ))
    return false;
  
  Reg &= ~(0x03<<2);
  Reg |= Odr << 2;
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_A_M, Reg ))
    return false;

  return true;
}

bool LSM303AGR_SetMode_M( uint8_t Mode)
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_A_M, &Reg ))
    return false;
  
  Reg &= ~(0x03<<0);
  Reg |= Mode << 0;
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_A_M, Reg ))
    return false;

  return true;
}

bool LSM303AGR_SetLP_M( bool enable)
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_A_M, &Reg ))
    return false;
  
  if(enable)
    Reg |= (1<<4);
  else
    Reg &= ~(0x01<<4);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_A_M, Reg ))
    return false;

  return true;
}

bool LSM303AGR_SetTempComp_M( bool enable)
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_A_M, &Reg ))
    return false;
  
  if(enable)
    Reg |= (1<<7);
  else
    Reg &= ~(0x01<<7);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_A_M, Reg ))
    return false;

  return true;
}


bool LSM303AGR_SetOffCanc_M( bool enable, bool OnlyAtStart )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_B_M, &Reg ))
    return false;
  
  if(enable)
    Reg |= (0x01<<1);
  else
    Reg &= ~(0x01<<1);
  
  if(OnlyAtStart)
    Reg |= (0x01<<2);
  else
    Reg &= ~(0x01<<2);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_B_M, Reg ))
    return false;

  return true;
}

bool LSM303AGR_SetLpFilter_M( bool enable )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_B_M, &Reg ))
    return false;
  
  if(enable)
    Reg |= (0x01<<0);
  else
    Reg &= ~(0x01<<0);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_B_M, Reg ))
    return false;

  return true;
}

bool LSM303AGR_SetBdu_M( bool enable )
{
  uint8_t Reg;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_C_M, &Reg ))
    return false;
  
  if(enable)
    Reg |= (0x01<<4);
  else
    Reg &= ~(0x01<<4);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_C_M, Reg ))
    return false;

  return true;
}


bool LSM303AGR_SaveOffSetValues_M( int16_t X, int16_t Y, int16_t Z )
{
  uint8_t x_l, x_h, y_l, y_h, z_l, z_h;
  
  if( ((uint16_t)X != 0xFFFF) && ((uint16_t)Y != 0xFFFF) && ((uint16_t)X != 0xFFFF) )
  {
    x_l = (uint8_t)(X);
    x_h = (uint8_t)(X>>8);
    y_l = (uint8_t)(Y);
    y_h = (uint8_t)(Y>>8);
    z_l = (uint8_t)(Z);
    z_h = (uint8_t)(Z>>8);
  }
  else
  {
    x_l = 0;
    x_h = 0;
    y_l = 0;
    y_h = 0;
    z_l = 0;
    z_h = 0;
  }
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_X_REG_L_M, x_l ))
    return false;
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_X_REG_H_M, x_h ))
    return false;
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_Y_REG_L_M, y_l ))
    return false;
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_Y_REG_H_M, y_h ))
    return false;
    
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_Z_REG_L_M, z_l ))
    return false;
  if(!LSM303AGR_SetReg_M( LSM303AGR_OFFSET_Z_REG_H_M, z_h ))
    return false;

  return true;
}



bool LSM303AGR_GetRawData_M( int16_t *x, int16_t *y, int16_t *z )
{ 
  uint8_t X_L, X_H, Y_L, Y_H, Z_L, Z_H;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTX_L_REG_M, &X_L ))
    return false;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTX_H_REG_M, &X_H ))
    return false;
    
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTY_L_REG_M, &Y_L ))
    return false;
    
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTY_H_REG_M, &Y_H ))
    return false;
    
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTZ_L_REG_M, &Z_L ))
    return false;
    
  if(!LSM303AGR_GetReg_M( LSM303AGR_OUTZ_H_REG_M, &Z_H ))
    return false;
  
  (*x) = (int16_t)X_L;
  (*x) += (((int16_t)X_H)<<8);
  
  (*y) = (int16_t)Y_L;
  (*y) += (((int16_t)Y_H)<<8);
  
  (*z) = (int16_t)Z_L;
  (*z) += (((int16_t)Z_H)<<8);
  
  return true;
}


//----------------------------------- Module -----------------------------------

bool LSM303AGR_Init( void )
{
  GPIO_InitTypeDef   GPIO_InitStructure = {0};
  
  // Configure INT GPIO
  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  GPIO_InitStructure.Pull = GPIO_PULLDOWN;
  GPIO_InitStructure.Pin = LSM303AGR_INTMAG_PIN;
  HAL_GPIO_Init(LSM303AGR_INTMAG_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.Pin = LSM303AGR_INT1_PIN;
  HAL_GPIO_Init(LSM303AGR_INT1_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.Pin = LSM303AGR_INT2_PIN;
  HAL_GPIO_Init(LSM303AGR_INT2_PORT, &GPIO_InitStructure);
  
  
/*
  // Enable and set EXTI_LINE Interrupt to priority NVIC_PRIORITY
  HAL_NVIC_SetPriority(LSM303AGR_INTMAG_IRQ, LSM303AGR_NVIC_PRIORITY, LSM303AGR_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(LSM303AGR_INTMAG_IRQ);
  
  // Configure INT GPIO
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = LSM303AGR_INT1_PIN;
  HAL_GPIO_Init(LSM303AGR_INT1_PORT, &GPIO_InitStructure);

  // Enable and set EXTI_LINE Interrupt to priority NVIC_PRIORITY
  HAL_NVIC_SetPriority(LSM303AGR_INT1_IRQ, LSM303AGR_NVIC_PRIORITY, LSM303AGR_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(LSM303AGR_INT1_IRQ);
  
  // Configure INT GPIO
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = LSM303AGR_INT2_PIN;
  HAL_GPIO_Init(LSM303AGR_INT2_PORT, &GPIO_InitStructure);

  // Enable and set EXTI_LINE Interrupt to priority NVIC_PRIORITY
  HAL_NVIC_SetPriority(LSM303AGR_INT2_IRQ, LSM303AGR_NVIC_PRIORITY, LSM303AGR_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(LSM303AGR_INT2_IRQ);
  */
  // Reboot AccelerometerDevice
  if(!LSM303AGR_Reboot_A())
    return false;
  
  ms_delay(10);
  
  // Reset Magnetometer
  if(!LSM303AGR_SoftReset_M())
  
  // Set Accelerometer
  if(!LSM303AGR_SetResolution( LSM303AGR_A_8B ))
    return false;
  if(!LSM303AGR_SetOdr_A( LSM303AGR_A_ODR_PD ))
    return false;
  if(!LSM303AGR_SetFs_A( LSM303AGR_A_2g))
    return false;
  if(!LSM303AGR_SetBdu_A( false ))
    return false;
  
  // Set Magnetometer
  if(!LSM303AGR_SetLP_M(false))
    return false;
  if(!LSM303AGR_SetTempComp_M(true))
    return false;
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_OFF1))
    return false;
  if(!LSM303AGR_SetOdr_M(LSM303AGR_M_ODR_10Hz))
    return false;
  if(!LSM303AGR_SetOffCanc_M( true, false ))
    return false;
  if(!LSM303AGR_SetLpFilter_M( true ))
    return false;
  if(!LSM303AGR_SetBdu_M( false ))
    return false;
  
  // Set Accelerometer Power Down
  if(!LSM303AGR_SetResolution( LSM303AGR_A_8B ))
    return false;
  if(!LSM303AGR_SetOdr_A( LSM303AGR_A_ODR_PD ))
    return false;

  // Set MAgnetometer Power Down
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_OFF1))
    return false;
  
  return true;
}

bool LSM303AGR_On( void )
{
  // Switch On Accelerometer
  if(!LSM303AGR_SetOdr_A( LSM303AGR_A_ODR_10Hz ))
    return false;
  
  // Reset offset calibration values
  if(!LSM303AGR_SaveOffSetValues_M( 0, 0, 0 ))
    return false;

  // Switch On Magnetometer
  if(!LSM303AGR_SetOdr_M(LSM303AGR_M_ODR_10Hz))
    return false;
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_CONTINOUSE))
    return false;
  
 return true;
}

bool LSM303AGR_Off( void )
{
  // Set Accelerometer Power Down
  if(!LSM303AGR_SetResolution( LSM303AGR_A_8B ))
    return false;
  
  if(!LSM303AGR_SetOdr_A( LSM303AGR_A_ODR_PD ))
    return false;

  // Set MAgnetometer Power Down
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_OFF1))
    return false;
  
  return true;
}

bool LSM303AGR_MagCalModeOn( void )
{
  if(!LSM303AGR_SetOdr_M(LSM303AGR_M_ODR_50Hz))
    return false;
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_CONTINOUSE))
    return false;
  
  uint8_t Reg = 0;
  Reg |= (0x04);
  if(!LSM303AGR_SetReg_M( LSM303AGR_INTCTRL_REG_M, Reg ))
    return false;

  if(!LSM303AGR_GetReg_M( LSM303AGR_INTCTRL_REG_M, &Reg ))
    return false;
    
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_C_M, &Reg ))
    return false;
  
  Reg |= 0x01;
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_C_M, Reg ))
    return false;
  
  GPIO_InitTypeDef   GPIO_InitStructure = {0};
  
  // Configure INT GPIO
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = LSM303AGR_INTMAG_PIN;
  HAL_GPIO_Init(LSM303AGR_INTMAG_PORT, &GPIO_InitStructure);

  // Enable and set EXTI_LINE Interrupt to priority NVIC_PRIORITY
  HAL_NVIC_SetPriority(LSM303AGR_INTMAG_IRQ, LSM303AGR_NVIC_PRIORITY, LSM303AGR_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(LSM303AGR_INTMAG_IRQ);

  int16_t tmp;
  LSM303AGR_GetRawData_M(&tmp, &tmp, &tmp);
  
  return true;
}

bool LSM303AGR_MagCalModeOff( void )
{
  HAL_GPIO_DeInit(LSM303AGR_INTMAG_PORT, LSM303AGR_INTMAG_PIN);
  HAL_NVIC_DisableIRQ(LSM303AGR_INTMAG_IRQ);
  
  GPIO_InitTypeDef   GPIO_InitStructure = {0};
  
  // Configure INT GPIO
  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  GPIO_InitStructure.Pull = GPIO_PULLDOWN;
  GPIO_InitStructure.Pin = LSM303AGR_INTMAG_PIN;
  HAL_GPIO_Init(LSM303AGR_INTMAG_PORT, &GPIO_InitStructure);
  
  if(!LSM303AGR_SetOdr_M(LSM303AGR_M_ODR_10Hz))
    return false;
  if(!LSM303AGR_SetMode_M(LSM303AGR_M_MODE_CONTINOUSE))
    return false;

  uint8_t Reg = 0;
  
  if(!LSM303AGR_GetReg_M( LSM303AGR_CFG_REG_C_M, &Reg ))
    return false;
  
  Reg &= ~(0x01);
  
  if(!LSM303AGR_SetReg_M( LSM303AGR_CFG_REG_C_M, Reg ))
    return false;

  
  return true;
}


#endif