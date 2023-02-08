/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "stm32l4xx_it.h"
#include "board.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
#if 0
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}
#endif

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
  
  delay_enabled = false;

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l4xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/*******************************************************************************
 * @brief   External Line Interrupts [9:5] handler
 ******************************************************************************/
#if 1
void ButIntHandler(int IntNo, void *pCtx)
{
	SystemStatus.user_act_timestamp = MonotonicClock_s;
	
	
        if(DEV_Board())
        {  
          switch (IntNo)
          {
            case BUT_BL_PIN:
                    //printf("BUT_BL_PIN\n");
                    HW_Buttons |= HW_BUTTON_G0;
                    break;
            case BUT_BR_PIN:
                    //printf("BUT_BR_PIN\n");
                    HW_Buttons |= HW_BUTTON_G3;
                    break;
            case BUT_TL_PIN: // S2
                    //printf("BUT_TL_PIN\n");
                    HW_Buttons |= HW_BUTTON_G1;
                    break;
            case BUT_TR_PIN:
                    //printf("BUT_TR_PIN\n");
                    HW_Buttons |= HW_BUTTON_G2;
                    break;
          }
        }               
        else               
        {
          switch (IntNo)
          {
            case PROD_BUT_L_PIN:
                    //printf("BUT_BL_PIN\n");
                    HW_Buttons |= PROD_HW_BUTTON_L;
                    break;
            case PROD_BUT_R_PIN:
                    //printf("BUT_BR_PIN\n");
                    HW_Buttons |= PROD_HW_BUTTON_R;
                    break;
            case PROD_BUT_M_PIN: // S2
                    //printf("BUT_TL_PIN\n");
                    HW_Buttons |= PROD_HW_BUTTON_M;
                    break;
            case PROD_BUT_X_PIN:
                    //printf("BUT_TR_PIN\n");
                    HW_Buttons |= PROD_HW_BUTTON_X;
                    break;
          }
        }
	
}
#else
#ifdef BUTTON_TR_PIN    // DEV_Board(): TR,  PROD_Board: G2, NOT Used in DSX 
void BUTTON_TR_IRQHANDLER (void)
{  
  if(DEV_Board())
  {
    __HAL_GPIO_EXTI_CLEAR_IT(BUTTON_TR_PIN);
    
    HW_Buttons |= HW_BUTTON_G2;
  }
  else
  {
    __HAL_GPIO_EXTI_CLEAR_IT(BUTTON_TR_PIN);
    
    HW_Buttons |= PROD_HW_BUTTON_X;
  }  

  SystemStatus.user_act_timestamp = MonotonicClock_s;
}
#endif

#ifdef BUTTON_BL_PIN    // DEV_Board(): BL,  PROD_Board: G1, for M Button 
void BUTTON_BL_IRQHANDLER (void)
{  
  if(DEV_Board())
  {
    __HAL_GPIO_EXTI_CLEAR_IT(BUTTON_BL_PIN);
    
    HW_Buttons |= HW_BUTTON_G0;
  }
  else
  {
    __HAL_GPIO_EXTI_CLEAR_IT(PROD_BUTTON_L_PIN);
    
    HW_Buttons |= PROD_HW_BUTTON_L;  
  }  

  SystemStatus.user_act_timestamp = MonotonicClock_s;
}
#endif

#ifdef BUTTON_BR_PIN    // DEV_Board(): BR,  PROD_Board: G3, for R Button
void BUTTON_BR_IRQHANDLER (void)
{  
  if(DEV_Board())
  {
    __HAL_GPIO_EXTI_CLEAR_IT(BUTTON_BR_PIN);    
    
    HW_Buttons |= HW_BUTTON_G3;
  }
  else
  {
    __HAL_GPIO_EXTI_CLEAR_IT(PROD_BUTTON_R_PIN);
    
    HW_Buttons |= PROD_HW_BUTTON_R; 
  }

  SystemStatus.user_act_timestamp = MonotonicClock_s;
}
#endif

#ifdef BUTTON_TL_PIN    // DEV_Board: TL,  PROD_Board: G0, for L Button
void BUTTON_TL_IRQHANDLER(void)
{  
  if(DEV_Board())
  {
    __HAL_GPIO_EXTI_CLEAR_IT(BUTTON_TL_PIN);
    
    HW_Buttons |= HW_BUTTON_G1;
  }
  else
  {
    __HAL_GPIO_EXTI_CLEAR_IT(PROD_BUTTON_M_PIN);
    
    HW_Buttons |= PROD_HW_BUTTON_M;
  }
  
  SystemStatus.user_act_timestamp = MonotonicClock_s;
}
#endif
#endif

#if 1
bool LSM303IntHandler(void)
{
    bool status = false;    
    if(EcData.Status == COMPASS_CALIBRATING)
    {    
        if(EcAcquireSamples())
            status = true;
    }
    return status;
}
#else
void EXTI15_10_IRQHandler(void)
{
  uint32_t intflag = __HAL_GPIO_EXTI_GET_IT( GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 );
  
  //__HAL_GPIO_EXTI_CLEAR_IT(intflag);

  // Magnetometer Data Ready Interrupt
  if(intflag & LSM303AGR_INTMAG_PIN)
  {
    EcAcquireSamples();
  }
  
  __HAL_GPIO_EXTI_CLEAR_IT(intflag);
}
#endif

/*******************************************************************************
 * @brief   RTC WakeUp Timer Interrupt
 ******************************************************************************/
void RTC_WKUP_IRQHandler(void)
{
  /* Clear WakeUp Interrupt flag */
  LL_RTC_ClearFlag_WUT(RTC);

  /* Clear WakeUp flag in PWR */
  LL_PWR_ClearFlag_WU();

  /* Clear WakeUp EXTI Flag */
  LL_EXTI_ClearFlag_0_31(EXTI_IMR1_IM20);

  /* Update Monotonic clock */
  if(wakeup_counter == 7)
  {
    MonotonicClock_s++;
    wakeup_counter = 0;

    Update_SystemTimers(&SystemTimers);

    /* 1s update Interupt functions */
    L4X9_UpdateTimers1s_Int1();
    L4X9_UpdateTimers1s_Int2();
    L4X9_UpdateTimers1s_Int3();
    L4X9_UpdateTimers1s_Int4();
  }
  else
    wakeup_counter++;

  /* 125ms update Interupt functions */
  L4X9_UpdateTimers125ms_Int1();
  L4X9_UpdateTimers125ms_Int2();
  L4X9_UpdateTimers125ms_Int3();
  L4X9_UpdateTimers125ms_Int4();

  /* Update Tick to be handled only if previouse tick already processed */
  //if(TickHandler.tick_processed[TickHandler.scheduled_tick])
  if(TickHandler.allow_tick_scheduling) // inhibit/allow tick scheduling
  {
    if(TickHandler.scheduled_tick < 7)
      TickHandler.scheduled_tick++;
    else
      TickHandler.scheduled_tick = 0;
  }

  TickHandler.tick_processed[TickHandler.scheduled_tick] = false;

  TickHandler.wut_125ms_occurred = true;

  /* Update STMCube timebase */
  /* This is used to generate timouts in the library */
  /* This function is redefined int L4X9_misc.c */
  HAL_IncTick();
  
  /* System RTC Sync Operation Manager */
  L4X9_RtcSynchedOperationManager();
}


/*******************************************************************************
 * @brief   RTC ALARM Interrupt
 ******************************************************************************/
void RTC_Alarm_IRQHandler(void)
{
  //if (LL_RTC_IsActiveFlag_ALRA(RTC))
  {
    /* Clear WakeUp Interrupt flag */
    LL_RTC_ClearFlag_ALRA(RTC);

    /* Clear WakeUp EXTI Flag */
    LL_EXTI_ClearFlag_0_31(EXTI_IMR1_IM18);

    delay_enabled = false;
  }
}


/******************************************************************************
 * @brief   BLE UART Interrupt Handler
 ******************************************************************************/
void USART_BT_IRQHDL(void)
{
    /* Get interrupt flags */
    uint32_t interrupt = BT_USART->ISR;

    /* Update UART activity time */
    SystemStatus.BLE_last_activity_s = MonotonicClock_s;

    /* Receive Buffer 1 byte full intterupt */
    /* Is cleared by reading UART_RDR */
    //if(interrupt & LL_LPUART_ISR_RXNE)
    if(interrupt & LL_LPUART_ISR_RXNE_RXFNE)
    {
        if(UART_ReadRxFifoSlip(BT_USART))
            BLE_RxProcessRequest = true;
    }

    /* Transmit Buffer empty intterupt */
    /* Is cleared by writing UART_TDR */
    //if( (interrupt & LL_LPUART_ISR_TXE) && (interrupt & LL_LPUART_ISR_TC) )
    if( (interrupt & LL_LPUART_ISR_TXE_TXFNF) && (interrupt & LL_LPUART_ISR_TC) )
    {
        if( BLE_FIFO_Tx.size != 0 )
        {
            BT_USART->TDR = BLE_FIFO_Tx.fifo[BLE_FIFO_Tx.first];

            if ( ++BLE_FIFO_Tx.first == BLE_FIFO_SIZE )
                BLE_FIFO_Tx.first = 0;

            if(BLE_FIFO_Tx.size > 0)
                BLE_FIFO_Tx.size--;
        }
        else
        {
            /* No more Bytes to transmit in the TX Buffer so disable interrupt */
            LL_LPUART_DisableIT_TXE(BT_USART);
        }
    }
}

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
