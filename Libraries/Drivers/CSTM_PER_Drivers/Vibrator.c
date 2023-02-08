/*******************************************************************************
 * @file        : Vibrator.h
 * @brief       : Low Level Driver for Vibrator.
 *                Driver is implemented for use with TIM8 Ch-1
 *                (please manage OS to not enter STOP MODE 2 while on)                   
 *
 * @version     0.0.1
 *******************************************************************************
 * Coder
 * YeuShyr Wu - Pelagic
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _VIBRATOR_H_

TIM_HandleTypeDef Tim8Handle = {0};

/******************************************************************************
 * @brief   Initialize Vibrator Driver
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_Init( uint32_t frequencyHz, uint32_t dutyPercent )
{
  uint32_t prescaler = (uint32_t)(120000000/2000000)-1;
  uint32_t period = (uint32_t)(2000000/frequencyHz)-1;
  uint32_t pulse = (uint32_t)((period*dutyPercent)/100)-1;
  
  __HAL_RCC_TIM8_CLK_ENABLE();
    
  //TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  //TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  Tim8Handle.Instance = TIM8;
  Tim8Handle.Init.Prescaler = prescaler;
  Tim8Handle.Init.Period = period;
  Tim8Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  Tim8Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  while(HAL_TIM_PWM_Init(&Tim8Handle) != HAL_OK){};

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
  sConfigOC.Pulse = pulse;
  while (HAL_TIM_PWM_ConfigChannel(&Tim8Handle, &sConfigOC, TIM_CHANNEL_1) != HAL_OK){};
}

/******************************************************************************
 * @brief   Start Vibrator Beep
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_On( void )
{
  GPIO_InitTypeDef GPIO_InitStruct  = {0};
  
  GPIO_InitStruct.Pin       = VIBRATOR_ENABLE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(VIBRATOR_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(VIBRATOR_ENABLE_PORT, VIBRATOR_ENABLE_PIN, GPIO_PIN_SET);
  
  /////////////////////////////////////
  /*
  GPIO_InitStruct.Pin       = VIBRATOR_MODE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(VIBRATOR_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(VIBRATOR_ENABLE_PORT, VIBRATOR_MODE_PIN, GPIO_PIN_RESET);
  */
  
  /* Set Alternate Port Function on the PWM Output pin */
  GPIO_InitStruct.Pin = VIBRATOR_DRIVE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;  
  HAL_GPIO_Init(VIBRATOR_DRIVE_PORT, &GPIO_InitStruct);  
  
  /* Enable TIM8 module and start PWM generation */
  while(HAL_TIM_PWM_Start(&Tim8Handle, TIM_CHANNEL_1) != HAL_OK){};
}

/******************************************************************************
 * @brief   Stop Vibrator Beep
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_Off( void )
{
  GPIO_InitTypeDef GPIO_InitStruct  = {0};
    
  GPIO_InitStruct.Pin       = VIBRATOR_ENABLE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(VIBRATOR_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(VIBRATOR_ENABLE_PORT, VIBRATOR_ENABLE_PIN, GPIO_PIN_RESET);
  
  /* Disable TIM8 module */
  while(HAL_TIM_PWM_Stop(&Tim8Handle, TIM_CHANNEL_1) != HAL_OK){};
  
  /* Restore GPIO Normal Output Function and set Low */
  GPIO_InitStruct.Pin = VIBRATOR_DRIVE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = 0;  
  HAL_GPIO_Init(VIBRATOR_DRIVE_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin(VIBRATOR_DRIVE_PORT, VIBRATOR_DRIVE_PIN, GPIO_PIN_RESET);
}

#endif // _VIBRATOR_H_