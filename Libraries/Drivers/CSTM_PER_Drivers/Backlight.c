/*******************************************************************************
 * @file        : Backlight.c
 * @brief       : Low Level Driver for Backlight Chip TPS61165DBV
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

#ifdef _BACKLIGHT_H_

/******************************************************************************
 * @brief   Initialize Backlight Driver
 *
 * @note
 *
 ******************************************************************************/
#define ES_DETECT_DELAY         150
#define ES_DETECT_TIME          350

uint8_t Backlight_Val;                  // current Backlight Percentage Level, returned from Backlight_Set()
uint8_t ButtonNoResponseCnt = 0;      // 0: no delay;  1: delay Menu /Data for one more button pushing

void Backlight_Init( void )
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  

    
  if(DEV_Board())
  {
      /* Configure BKL Pins *******************************************************/
      GPIO_InitStruct.Pin = BKL_PIN;
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
  
      HAL_GPIO_Init(BKL_PORT, &GPIO_InitStruct); 
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
      
      /* Start One-Wire Setup Procedure */
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
      us_delay(ES_DETECT_DELAY);
      
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
      us_delay(ES_DETECT_TIME);
      
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
  }
  else
  {
      /* Configure BKL Pins *******************************************************/
      GPIO_InitStruct.Pin = PROD_BKL_PIN;
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
    
      HAL_GPIO_Init(PROD_BKL_PORT, &GPIO_InitStruct); 
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
      
      /* Start One-Wire Setup Procedure */
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
      us_delay(ES_DETECT_DELAY);
      
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
      us_delay(ES_DETECT_TIME);
      
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
  }  
  
  /* Wait ES Mode Time Window expires */
  us_delay(800);
}

/******************************************************************************
 * @brief   Start Backlight
 *
 * @note
 *
 ******************************************************************************/
#define ES_CHIP_ADDRESS         0x72
#define ES_CHIP_LEVELS          31
#define ES_T_START              50
#define ES_T_EOS                50

#define ES_L0_HT                50
#define ES_L0_LT                2*ES_L0_HT

#define ES_L1_LT                50
#define ES_L1_HT                2*ES_L1_LT

void ES_send(uint8_t data)
{
  if(DEV_Board())
  {  
      /* Assert ES Program Start */
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
      us_delay(ES_T_START);
      
      for (uint8_t a = 0; a<8; a++)
      {
        if((data<<a) & 0x80)
        {
          HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
          us_delay(ES_L1_LT);
          HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
          us_delay(ES_L1_HT);
        }
        else
        {
          HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
          us_delay(ES_L0_LT);
          HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
          us_delay(ES_L0_HT);
        }
      }
        
      /* Assert ES Program End */
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
      us_delay(ES_T_EOS);
      HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
  }
  else
  {
      /* Assert ES Program Start */
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
      us_delay(ES_T_START);
      
      for (uint8_t a = 0; a<8; a++)
      {
        if((data<<a) & 0x80)
        {
          HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
          us_delay(ES_L1_LT);
          HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
          us_delay(ES_L1_HT);
        }
        else
        {
          HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
          us_delay(ES_L0_LT);
          HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
          us_delay(ES_L0_HT);
        }
      }
        
      /* Assert ES Program End */
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
      us_delay(ES_T_EOS);
      HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
  }
 
}


static uint8_t s_last_level = 0xff;  // start with never used value
void Backlight_Set( uint8_t level )
{
  uint16_t lev = (uint16_t)level/10;
  uint16_t ChipLev = 0;
  // const static uint8_t ChipLevArray[16]={0,  1,3,5,7,9, 11,13,15,17,20, 25,30,30,30,30};	// Old BRIGHTNESS LEVEL before 2022 03 25
  const static uint8_t ChipLevArray[16]={0,  1,3,5,7,9, 11,13,16,20,24, 30,30,30,30,30};      	// New BRIGHTNESS LEVEL
  
    //if(SystemStatus.BLE_status != BLE_HDL_CONNECT)
    //{
        if (level == s_last_level) 
        {
          return;
        }
        s_last_level = level;
        if (lev >= sizeof(ChipLevArray)) 
        {
          lev = sizeof(ChipLevArray)-1;
        }
       
        if(lev == 0)
        {
          ChipLev = 0;
        }
        else
        {
          ChipLev = ChipLevArray[lev];
        }
        
        
        if(DEV_Board())
        {
            if(ChipLev == 0)
              HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
            else
            {
              /* Start One-Wire Setup Procedure */
              HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
              us_delay(ES_DETECT_DELAY);
              
              HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_RESET);
              us_delay(ES_DETECT_TIME);
              
              HAL_GPIO_WritePin(BKL_PORT, BKL_PIN, GPIO_PIN_SET);
              
              /* Wait ES Mode Time Window expires */
              us_delay(800);
              
              __disable_irq();
              ES_send(ES_CHIP_ADDRESS);
                
              //lev |= 0x40;
              ES_send(ChipLev);
              __enable_irq();
            }  
        }
        else
        {
            if(ChipLev == 0)
              HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
            else
            {
              /* Start One-Wire Setup Procedure */
              HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
              us_delay(ES_DETECT_DELAY);
              
              HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_RESET);
              us_delay(ES_DETECT_TIME);
              
              HAL_GPIO_WritePin(PROD_BKL_PORT, PROD_BKL_PIN, GPIO_PIN_SET);
              
              /* Wait ES Mode Time Window expires */
              us_delay(800);
              
              __disable_irq();
              ES_send(ES_CHIP_ADDRESS);
                
              //lev |= 0x40;
              ES_send(ChipLev);
              __enable_irq();
            }
        }
        
        Backlight_Val = lev * 10;
    
    //}
}



uint8_t AutoBackLight(float lux)
{
    float ALS_Dark_Lux;
    float ALS_Low_Lux;
    float ALS_Med_Lux;
    uint8_t Dark_BackLight;
    uint8_t Low_BackLight;
    uint8_t Med_BackLight;
    uint8_t Bright_BackLight;


    float lux_tmp = lux;
    uint8_t backlightVal; 

    ALS_Dark_Lux = MFG_Calib.ALS_Dark_Lux;
    ALS_Low_Lux = MFG_Calib.ALS_Low_Lux;
    ALS_Med_Lux = MFG_Calib.ALS_Med_Lux;
    Dark_BackLight = MFG_Calib.Dark_BackLight;
    Low_BackLight = MFG_Calib.Low_BackLight;
    Med_BackLight = MFG_Calib.Med_BackLight;
    Bright_BackLight = MFG_Calib.Bright_BackLight;

    

//float ALS_Dark_Lux;           / 4-Byte float for ALS Dark Level Lux threshold value /
// float ALS_Low_Lux;            / 4-Byte float for ALS Low Level Lux threshold value /
// float ALS_Med_Lux;            / 4-Byte float for ALS Med Level Lux threshold value /
// uint8_t Dark_BackLight;       / 1-Byte uint8 for ALS Dark Level's Brightness value /
// uint8_t Low_BackLight;        / 1-Byte uint8 for ALS Low Level's Brightness value /
// uint8_t Med_BackLight;        / 1-Byte uint8 for ALS Med Level's Brightness value /
// uint8_t Bright_BackLight;     / 1-Byte uint8 for ALS Bright Level's Brightness value /




    if((Low_BackLight  == 0)||(Low_BackLight  == 0xff))/*init new eeprom here*/
    {
      ALS_Dark_Lux = 5.0;               // 1.0 before 2022/02/03
      ALS_Low_Lux = 50.0;               // 87.05 before 2022/02/03
      ALS_Med_Lux = 500.0;              // 800.0 before 2022/02/03
      Dark_BackLight = 30;
      Low_BackLight = 50;
      Med_BackLight = 80;               // new update on 2022 03 31 requested by Minh and Hoang
      Bright_BackLight = 100;
    }

    if(lux_tmp<ALS_Dark_Lux )
    {
      backlightVal = Dark_BackLight;
    }
    else if((lux_tmp<ALS_Low_Lux)&&(lux_tmp >= ALS_Dark_Lux))
    {
      backlightVal = Low_BackLight;
    }
    else if((lux_tmp<ALS_Med_Lux)&&(lux_tmp >= ALS_Low_Lux))
    {
      backlightVal = Med_BackLight;
    }      
    else{
        backlightVal = Bright_BackLight;
    }

    return backlightVal;
}



#endif // _BACKLIGHT_H_
