/*******************************************************************************
 * @file        : Buzzer.h
 * @brief       : Low Level Driver for Buzzer.
 *                Driver is implemented for use with LPTIM2 
 *                (please manage OS to not enter STOP MODE 2 while on)                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _BUZZER_H_

TIM_HandleTypeDef Tim3Handle = {0};

/******************************************************************************
 * @brief   Initialize Buzzer Driver
 *
 * @note
 *
 ******************************************************************************/
void Buzzer_Init( uint32_t frequencyHz, uint32_t dutyPercent )
{
  uint32_t prescaler = (uint32_t)(120000000/2000000)-1;
  uint32_t period = (uint32_t)(2000000/frequencyHz)-1;
  uint32_t pulse = (uint32_t)((period*dutyPercent)/100)-1;
  
  __HAL_RCC_TIM3_CLK_ENABLE();
    
  //TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  //TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  Tim3Handle.Instance = TIM3;
  Tim3Handle.Init.Prescaler = prescaler;
  Tim3Handle.Init.Period = period;
  Tim3Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  Tim3Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  while(HAL_TIM_PWM_Init(&Tim3Handle) != HAL_OK){};

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
  sConfigOC.Pulse = pulse;
  while (HAL_TIM_PWM_ConfigChannel(&Tim3Handle, &sConfigOC, TIM_CHANNEL_2) != HAL_OK){};
}

/******************************************************************************
 * @brief   Start Buzzer Beep
 *
 * @note
 *
 ******************************************************************************/
void Buzzer_On( void )
{
  GPIO_InitTypeDef GPIO_InitStruct  = {0};
  
  GPIO_InitStruct.Pin       = BUZZER_ENABLE_PIN|BUZZER_MODE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(BUZZER_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(BUZZER_ENABLE_PORT, BUZZER_ENABLE_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(BUZZER_ENABLE_PORT, BUZZER_MODE_PIN, GPIO_PIN_SET);
  
  /////////////////////////////////////
  /*
  GPIO_InitStruct.Pin       = BUZZER_MODE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(BUZZER_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(BUZZER_ENABLE_PORT, BUZZER_MODE_PIN, GPIO_PIN_RESET);
  */
  
  /* Set Alternate Port Function on the PWM Output pin */
  GPIO_InitStruct.Pin = BUZZER_DRIVE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;  
  HAL_GPIO_Init(BUZZER_DRIVE_PORT, &GPIO_InitStruct);  
  
  /* Enable LPTIM2 module and start PWM generation */
  while(HAL_TIM_PWM_Start(&Tim3Handle, TIM_CHANNEL_2) != HAL_OK){};
}

/******************************************************************************
 * @brief   Stop Buzzer Beep
 *
 * @note
 *
 ******************************************************************************/
void Buzzer_Off( void )
{
  GPIO_InitTypeDef GPIO_InitStruct  = {0};
    
  GPIO_InitStruct.Pin       = BUZZER_ENABLE_PIN|BUZZER_MODE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(BUZZER_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(BUZZER_ENABLE_PORT, BUZZER_ENABLE_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(BUZZER_ENABLE_PORT, BUZZER_MODE_PIN, GPIO_PIN_RESET);
  
  /* Disable LPTIM2 module */
  while(HAL_TIM_PWM_Stop(&Tim3Handle, TIM_CHANNEL_2) != HAL_OK){};
  
  /* Restore GPIO Normal Output Function and set Low */
  GPIO_InitStruct.Pin = BUZZER_DRIVE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = 0;  
  HAL_GPIO_Init(BUZZER_DRIVE_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin(BUZZER_DRIVE_PORT, BUZZER_DRIVE_PIN, GPIO_PIN_RESET);
}

#endif // _BUZZER_H_