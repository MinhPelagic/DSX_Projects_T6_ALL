/*******************************************************************************
 * @file        : MAX77950.h
 * @brief       : Low Level Driver for MAX77950 WPC/PMA Dual Mode Wirless 
 *                Power Receiver
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
 * 	The MAX77950 driver is build on the I2C system bus.
 *
 ******************************************************************************/

#include "L4X9_includes.h"

#ifdef _MAX77950_H_

/*******************************************************************************
 * @brief
 *   Initialize Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX77950_Init( void )
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  if(DEV_Board())
  {
    GPIO_InitStruct.Pin       = MAX77950_WPEN_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(MAX77950_WPEN_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(MAX77950_WPEN_PORT, MAX77950_WPEN_PIN, GPIO_PIN_RESET);
  }

  GPIO_InitStruct.Pin       = MAX77950_P2PEN_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(MAX77950_P2PEN_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(MAX77950_P2PEN_PORT, MAX77950_P2PEN_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin       = MAX77950_WPDET_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(MAX77950_WPDET_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = MAX77950_INT_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(MAX77950_INT_PORT, &GPIO_InitStruct);
  
  return true;
}

/*******************************************************************************
 * @brief
 *   Enable Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
void MAX77950_Enable( void )
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  if(DEV_Board())
  {
    GPIO_InitStruct.Pin       = MAX77950_WPEN_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(MAX77950_WPEN_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(MAX77950_WPEN_PORT, MAX77950_WPEN_PIN, GPIO_PIN_RESET);
  }
}

/*******************************************************************************
 * @brief
 *   Disable Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
void MAX77950_Disable( void )
{
  if(DEV_Board())
  {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin       = MAX77950_WPEN_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(MAX77950_WPEN_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(MAX77950_WPEN_PORT, MAX77950_WPEN_PIN, GPIO_PIN_SET);
  }
}

/*******************************************************************************
 * @brief
 *   Check if Wireless Power is beeing received.
 *
 * @note
 *
 * @return
 *	true : if power transfer in progress
 *	false : if no power is transferred
 ******************************************************************************/
bool MAX77950_IsPowerDetected( void )
{
  if(HAL_GPIO_ReadPin(MAX77950_WPDET_PORT, MAX77950_WPDET_PIN) == 0)
    return false;
  else
    return true;
}

#endif // _MAX77950_H_