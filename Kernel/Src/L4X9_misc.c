/*******************************************************************************
 * @file        : L4X9_misc.c
 * @brief       : MCU initilitation and miscellaneous RTOS routines.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_MISC_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/* Global variable used in all PRTOS delay functions */
volatile bool delay_enabled = false;

/******************************************************************************
 * @brief   Initializes the NVIC.
 *
 * @note
 ******************************************************************************/
void L4X9_NVICInit(void)
{

  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* System interrupt initialization */
  /* NonMaskableInt_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(NonMaskableInt_IRQn, 0, 0);
  /* HardFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(HardFault_IRQn, 0, 0);
  /* MemoryManagement_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  /* BusFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  /* UsageFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
  /* SVCall_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
  /* DebugMonitor_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/******************************************************************************
 * @brief   Initializes the MCU FLASH.
 *
 * @note
 ******************************************************************************/
void L4X9_FlashInit(void)
{
  /* Set Flash Latency to 4 wait states, see RM0351 p.100 */
  //__HAL_FLASH_SET_LATENCY(FLASH_LATENCY_4);   // will be set later by frequency scaling routine

  /* Enable Instruction cache */
  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();

  /* Enable Data cache */
  __HAL_FLASH_DATA_CACHE_ENABLE();

  /* Enable Prefetch buffer */
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
}


/******************************************************************************
 * @brief   Initializes the System Clock as defined in the XXX_hal.h.
 *
 * @note
 ******************************************************************************/
void L4X9_SystemClockInit(void)
{
  //RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  //RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  
  // Configure LSE Drive Capability
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

#if 0
  // Configure the main internal regulator output voltage to Range 1 for 80MHz
  while (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST) != HAL_OK) {};
    
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  
  // Configure Oscillator
  while (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {};

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  
  // Configure Clock Tree
  while (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {};
#endif

  // Initialize the RCC extended peripherals clocks
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_LPTIM2|RCC_PERIPHCLK_OSPI;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_MSI;              //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1M = 6;                                   //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1N = 8;                                   //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV2;                       //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;                       //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;                       //YS, added for O2 Analyzer
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;          //YS, added for O2 Analyzer
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  PeriphClkInit.Lptim2ClockSelection = RCC_LPTIM2CLKSOURCE_LSE;
  PeriphClkInit.OspiClockSelection = RCC_OSPICLKSOURCE_SYSCLK;  
  while (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {};

  /* Enable Clock to CRC Interface */
  __HAL_RCC_CRC_CLK_ENABLE();

  /* Update SystemCoreClock Global System Variable */
  SystemCoreClockUpdate();

  /* Disable SysTick Timer of Cortex M4 Core */
  SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk;

/*
#ifdef BUILD_DEBUG
    // Set Debugger clock for LowPower Modes
    HAL_DBGMCU_EnableDBGSleepMode();
    HAL_DBGMCU_EnableDBGStopMode();
    HAL_DBGMCU_EnableDBGStandbyMode();
    __HAL_RCC_DMA2_CLK_ENABLE();
#endif
*/
}


/******************************************************************************
 * @brief   Initializes the Independant WatchDog.
 *
 * @note    The WatchDog is feed with LSI clock source and is internally
 *          precaled by 256. This means that it counts 125 ticks per second.
 ******************************************************************************/
void L4X9_WatchDogInit(void)
{
    WatchDogHandle.Instance = IWDG;
    WatchDogHandle.Init.Window = IWDG_WINDOW_DISABLE;

    // Set Watchdog Prescaler to 256 for LSI; So module clock is 125Hz
    WatchDogHandle.Init.Prescaler = IWDG_PRESCALER_256;

    // Set Reload Value
    WatchDogHandle.Init.Reload = 25UL * 125UL;

    while(HAL_IWDG_Init(&WatchDogHandle) != HAL_OK) {};
}


/******************************************************************************
 * @brief   Reloads the Independant WatchDog.
 *
 * @note
 ******************************************************************************/
void L4X9_WatchDogReload(void)
{
    while(HAL_IWDG_Refresh(&WatchDogHandle) != HAL_OK) {};
}

/******************************************************************************
 * @brief   Initializes the Stop Mode.
 *          Set the SCB->SCR Cortex-M4 to enter deepsleep mode.
 *
 * @note    Call just at upon Reset or PowerOn, or if some of the following
 *          configuration has been changed during application execution.
 ******************************************************************************/
void L4X9_StopModeInit(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();
    /* Set HSI as wake-up system clock */
    __HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);
    //MODIFY_REG(RCC->CFGR, RCC_CFGR_STOPWUCK, RCC_STOP_WAKEUPCLOCK_MSI);

    /* Set SRAM3 Retain during Stop Mode 2 */
    MODIFY_REG(PWR->CR1, PWR_CR1_RRSTP_Msk, PWR_CR1_RRSTP);
    __HAL_RCC_PWR_CLK_DISABLE();
}

/******************************************************************************
 * @brief   Enter Stop Mode 1 in WFI mode and restores the System clock
 *          configuration according to XXX_hal.h.
 *
 * @note
 ******************************************************************************/
void L4X9_StopMode1Enter(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();
    /* Set Stop mode 1 */
    MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP1);
    __HAL_RCC_PWR_CLK_DISABLE();  
    /* Use DeepSleep as low power mode in Cortex-M4 Module */
    SET_BIT (SCB->SCR, SCB_SCR_SLEEPDEEP_Msk);

    /* Deactivate SleepOnExit feature in Cortex-M4 Module */
    CLEAR_BIT (SCB->SCR, SCB_SCR_SLEEPONEXIT_Msk);

    /* Wait For Interrupt */
    __WFI();

    /* Enable MSI */
    __HAL_RCC_MSI_ENABLE();

    /* Enable the main PLL. */
    __HAL_RCC_PLL_ENABLE();

    /* Switch System clock to PLLCLK */         
    __HAL_RCC_SYSCLK_CONFIG (RCC_SYSCLKSOURCE_PLLCLK);

    while(__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK ){};

    /* Update SystemCoreClock Global System Variable */
    SystemCoreClockUpdate();
}

/******************************************************************************
 * @brief   Enter Stop Mode 2 in WFI mode and restores the System clock
 *          configuration according to XXX_hal.h.
 *
 * @note
 ******************************************************************************/
void L4X9_StopMode2Enter(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();
    /* Set Stop mode 2 */
    MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP2);
    __HAL_RCC_PWR_CLK_DISABLE();  
    /* Use DeepSleep as low power mode in Cortex-M4 Module */
    SET_BIT (SCB->SCR, SCB_SCR_SLEEPDEEP_Msk);

    /* Deactivate SleepOnExit feature in Cortex-M4 Module */
    CLEAR_BIT (SCB->SCR, SCB_SCR_SLEEPONEXIT_Msk);

    /* Wait For Interrupt */
    __WFI();

    /* Enable MSI */
    __HAL_RCC_MSI_ENABLE();

    /* Enable the main PLL. */
    __HAL_RCC_PLL_ENABLE();

    /* Switch System clock to PLLCLK */         
    __HAL_RCC_SYSCLK_CONFIG (RCC_SYSCLKSOURCE_PLLCLK);

    while(__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK ){};

    /* Update SystemCoreClock Global System Variable */
    SystemCoreClockUpdate();
}

/******************************************************************************
 * @brief   Initializes the GPIO as defined in the XXX_hal.h
 *
 * @note
 ******************************************************************************/
void L4X9_GpioInit(void)
{
  /* Initialize GPIO Ports and Debug Pins as defined in the XXX_hal.h */

  /* Power Port G */
  HAL_PWREx_EnableVddIO2();

  /* Enable Clock to all Ports */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
#if defined(GPIOI)
  __HAL_RCC_GPIOI_CLK_ENABLE();
#endif /* GPIOI */

  GPIO_InitTypeDef GPIO_InitStruct = SYSTEM_GPIO_DEFAULT;

  /* Configure Board-Sensing Pin PH13 ***************************************/  
  GPIO_InitStruct.Mode          = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull          = GPIO_NOPULL;
  GPIO_InitStruct.Speed         = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate     = 0;

  GPIO_InitStruct.Pin           = BOARD_DETECT_PIN;
  HAL_GPIO_Init(BOARD_DETECT_PORT, &GPIO_InitStruct);
      
  /* Detecting the system is a Dev Board or a Production Board ****************/
  // HAL_GPIO_ReadPin(BOARD_DETECT_PORT, BOARD_DETECT_PIN);
  

      /* BLE Pins *****************************************************************/
      GPIO_InitStruct.Pin       = BT_RST_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_RST_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_RESET);

  if(DEV_Board())
  {
      GPIO_InitStruct.Pin       = BT_P3_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P3_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_RESET);

      GPIO_InitStruct.Pin       = BT_P1_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P1_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = BT_P2_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P2_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = BT_P4_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P4_PORT, &GPIO_InitStruct);

      HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_SET);         // needed here for Development Board      
  }
  else
  {
      GPIO_InitStruct.Pin       = PROD_BT_P3_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P3_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(PROD_BT_P3_PORT, PROD_BT_P3_PIN, GPIO_PIN_RESET);

      GPIO_InitStruct.Pin       = PROD_BT_P1_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P1_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = PROD_BT_P2_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P2_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = PROD_BT_P4_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P4_PORT, &GPIO_InitStruct);

      HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_SET);         // needed here for Prudction Board
  }
  
  
    /* Configure Simulation Pins ************************************************/
    if(DEV_Board())
  {
    GPIO_InitStruct.Pin       = USER_X60_PIN|USER_SHIFT_PIN|USER_DOWN_PIN|USER_UP_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(USER_SIMULATE_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = USER_DEMO_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(USER_SIMULATE_PORT, &GPIO_InitStruct);
  }
  else
  {
    GPIO_InitStruct.Pin       = PROD_USER_DEMO_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(PROD_USER_SIMULATE_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = PROD_USER_X60_PIN|PROD_USER_SHIFT_PIN|PROD_USER_DOWN_PIN|PROD_USER_UP_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(PROD_USER_SIMULATE_PORT, &GPIO_InitStruct);
  }
  
  /* Configure RECEIVER Pins ************************************************/
  GPIO_InitStruct.Pin       = RCVE_ENABLE_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(RCVE_ENABLE_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(RCVE_ENABLE_PORT, RCVE_ENABLE_PIN, GPIO_PIN_RESET);
    
  /* Configure O2 PORT ************************************************/
  GPIO_InitStruct.Pin       = O2_SEL_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(O2_SEL_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(O2_SEL_PORT, O2_SEL_PIN, GPIO_PIN_RESET);
  
  /* Configure ALS PORT ************************************************/
  GPIO_InitStruct.Pin       = OPT3001_INT_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(OPT3001_INT_PORT, &GPIO_InitStruct);

  /* Configure VCHG_FLG PORT ************************************************/
  GPIO_InitStruct.Pin       = VCHG_FLG_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(VCHG_FLG_PORT, &GPIO_InitStruct);
   
  /* Configure Battery Charger PORT ************************************************/
  GPIO_InitStruct.Pin       = PG_CHARGER_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(PG_CHARGER_PORT, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin       = CHG_STATUS_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(CHG_STATUS_PORT, &GPIO_InitStruct);
  
  if(!DEV_Board())
  {
    GPIO_InitStruct.Pin       = USB_CHARGING_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(USB_CHARGING_PORT, &GPIO_InitStruct);  

#if USE_REAL_BATTERY
    
#else    
    /* Configure Test Pins ******************************************************/
    GPIO_InitStruct.Mode          = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull          = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed         = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate     = 0;

    GPIO_InitStruct.Pin           = TP0_PIN;
    HAL_GPIO_Init(TP0_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(TP0_PORT, TP0_PIN, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin           = TP1_PIN;
    HAL_GPIO_Init(TP1_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(TP1_PORT, TP1_PIN, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin           = TP2_PIN;
    HAL_GPIO_Init(TP2_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(TP2_PORT, TP2_PIN, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin           = TP3_PIN;
    HAL_GPIO_Init(TP3_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(TP3_PORT, TP3_PIN, GPIO_PIN_RESET);  
#endif
    }
}

/******************************************************************************
 * @brief   RTC Initilization routine.
 *          Enables the RTC module.
 *          Initilize the RTC module with selected format and Sync/Async
 *          Prescaler settings.
 *          Sets default time and date.
 *
 * @note
 *          LSE must be already enabled.
 *          Backup restore not implemented.
 *          RTCSEL, RTCEN, LSEON, LSEBYP in RCC are write protected. (see RM0351 p.272)
 ******************************************************************************/
void L4X9_RTCInit(void)
{  
  LL_RTC_InitTypeDef RTC_InitStruct = RTC_INIT_DEFAULT;

  // Peripheral clock enable
  LL_RCC_EnableRTC();

  // Initialize RTC
  LL_RTC_Init(RTC, &RTC_InitStruct);
  
  // Set Default Time
  LL_RTC_TimeTypeDef Time_Init = RTC_INIT_TIME_DEFAULT;
  LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BCD, &Time_Init);
  
  // Set Default Date
  LL_RTC_DateTypeDef Date_Init = RTC_INIT_DATE_DEFAULT;
  LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BCD, &Date_Init);
}

/******************************************************************************
 * @brief   Calibrate Rtc
 *
 * @note    Requires as input the Seconds per Month to be add/subtract.
 *          Month duration is 2629800 seconds
 ******************************************************************************
 *
 *      32768/Sec x 32 Sec =  1,048,576
 *
 *      if n pulses/day need to be elminated by Smooth Calibration,
 *
 *          CALM = (32768 x 32) x n / 86400 = 1,048,576 x n / 86400
 *
 *      0: +50Sec/Day;       511: -25Sec/Day;        400: 
 *      200: -12/Day         160: -6/Day             100: -2/Day
 *      0: +3/Day            50: in testing
 *      
 ******************************************************************************/
void L4X9_CalRtc (int16_t SecondsPerMonth, uint8_t sign)
{
  //float error32s_ms = ((float)SecondsPerMonth) / ( ((float)RTC_REF_CALIBRATION_PERIOD)/32.00f );

  //float error = error32s_ms / (1.00f / 32768.00f);      // Min_Data=0x00 and Max_Data=0x1FF = 511
  
  /* Disable the write protection for RTC registers */
  LL_RTC_DisableWriteProtection(RTC);

  if(sign == 0)
  {
    while(LL_RTC_IsActiveFlag_RECALP(RTC)){}
      LL_RTC_CAL_SetPulse(RTC, LL_RTC_CALIB_INSERTPULSE_NONE);
    while(LL_RTC_IsActiveFlag_RECALP(RTC)){}
      LL_RTC_CAL_SetMinus(RTC, ((uint32_t)50));    // Min_Data=0x00 and Max_Data=0x1FF
  }
  else
  {
    while(LL_RTC_IsActiveFlag_RECALP(RTC)){}
      LL_RTC_CAL_SetPulse(RTC, LL_RTC_CALIB_INSERTPULSE_SET);
    while(LL_RTC_IsActiveFlag_RECALP(RTC)){}
      LL_RTC_CAL_SetMinus(RTC, ((uint32_t)19));
  }

  /* Enable the write protection for RTC registers */
  LL_RTC_EnableWriteProtection(RTC);
}

/******************************************************************************
 * @brief   Set Rtc Time
 *
 * @note
 ******************************************************************************/
void L4X9_SetRtc (SystemTimeDate_t time)
{
  /* Set RTC */
  /* Disable the write protection for RTC registers */
  LL_RTC_DisableWriteProtection(RTC);

  /* Enter RTC Init Mode */
  LL_RTC_EnableInitMode(RTC);

  /* Init mode confimration takes about 2 RTCCLK cycles, that on 32.768kHz is about 62us */
  while(LL_RTC_IsActiveFlag_INIT(RTC) != 1) {};

  /* Time data is sent in BCD format */
  LL_RTC_TIME_Config(RTC, LL_RTC_TIME_FORMAT_AM_OR_24, BIN2BCD(time.Hour), BIN2BCD(time.Minute), BIN2BCD(time.Second));

  /* Set Date */
  LL_RTC_DATE_Config(RTC, time.WeekDay, BIN2BCD(time.Day), BIN2BCD(time.Month), BIN2BCD(time.Year));

  /* Exit RTC Init Mode */
  LL_RTC_DisableInitMode(RTC);

  /* Enable the write protection for RTC registers */
  LL_RTC_EnableWriteProtection(RTC);

  /* Update system Date/Time */
  UpdateRealTimeDate(&SysTimeDatePST);
}

/******************************************************************************
 * @brief   RTC WakeUp Interrupt Initilization routine.
 *
 * @note    Must be called after STM32L1xx_RTCInit(void).
 *          Backup restore not implemented.
 ******************************************************************************/
void L4X9_RTC_WKU_INT_Init(void)
{
  /* Disable access to backup domain */
  LL_PWR_EnableBkUpAccess();

  /* Disable the write protection for RTC registers */
  LL_RTC_DisableWriteProtection(RTC);

  /* Disable wake up timer to allow modifications */
  LL_RTC_WAKEUP_Disable(RTC);

  while (LL_RTC_IsActiveFlag_WUTW(RTC) != 1) {};

  /* Set the Reload Register and Prescaler value for RTC WAKEUP module */
  LL_RTC_WAKEUP_SetAutoReload(RTC, RTC_WAKEUP_RELOAD);
  LL_RTC_WAKEUP_SetClock(RTC, RTC_WAKEUP_PRESCALER);

  /* Enable WakeUp Timer */
  LL_RTC_WAKEUP_Enable(RTC);

  /* Enable WakeUp Timer Interrupt */
  LL_RTC_EnableIT_WUT(RTC);

  /* Clear WakeUp Interrupt flag */
  LL_RTC_ClearFlag_WUT(RTC);

  /* Clear WakeUp flag in PWR */
  LL_PWR_ClearFlag_WU();

  /* Configure EXTI */
  LL_EXTI_EnableIT_0_31(EXTI_IMR1_IM20);
  LL_EXTI_EnableRisingTrig_0_31(EXTI_IMR1_IM20);

  /* Configure NVIC for RTC_WKUP_IRQHandler */
  NVIC_EnableIRQ(RTC_WKUP_IRQn);
  NVIC_SetPriority(RTC_WKUP_IRQn,0x02);

  /* Enable RTC registers write protection */
  LL_RTC_EnableWriteProtection(RTC);

  /* Disable access to backup domain */
  //LL_PWR_DisableBkUpAccess();
}

/******************************************************************************
 * @brief   I2C System Bus Initilization
 *
 * @note
 *
 ******************************************************************************/
void L4X9_I2C_Init(void)
{
  /*************************** I2C BUS A **************************************/
  
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  if(DEV_Board())
  {        
      GPIO_InitStruct.Pin = I2C2_SCL_PIN;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
      HAL_GPIO_Init(I2C2_SCL_PORT, &GPIO_InitStruct);
      GPIO_InitStruct.Pin = I2C2_SDA_PIN;
      HAL_GPIO_Init(I2C2_SDA_PORT, &GPIO_InitStruct);
  }   
  else
  {            
      GPIO_InitStruct.Pin = PROD_I2C2_SCL_PIN;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
      HAL_GPIO_Init(PROD_I2C2_SCL_PORT, &GPIO_InitStruct);
      GPIO_InitStruct.Pin = PROD_I2C2_SDA_PIN;
      HAL_GPIO_Init(PROD_I2C2_SDA_PORT, &GPIO_InitStruct);
  }
  
  /* Initilize I2C Bus */
  I2C_BUS_A.Instance             = I2C2;
  I2C_BUS_A.Init.Timing          = I2C2_TIMING;
  I2C_BUS_A.Init.OwnAddress1     = 0xFFFF;
  I2C_BUS_A.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
  I2C_BUS_A.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2C_BUS_A.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  I2C_BUS_A.Init.OwnAddress2     = 0xFF;
  I2C_BUS_A.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2C_BUS_A.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

  /* Enable Clock to I2C2 Interface */
  __HAL_RCC_I2C2_CLK_ENABLE();

  /* Initilize I2C module */
  while (HAL_I2C_Init(&I2C_BUS_A) != HAL_OK) {};
  
  
  /*************************** I2C BUS B **************************************/
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  GPIO_InitStruct.Pin = I2C1_SCL_PIN;
  HAL_GPIO_Init(I2C1_SCL_PORT, &GPIO_InitStruct);
  GPIO_InitStruct.Pin = I2C1_SDA_PIN;
  HAL_GPIO_Init(I2C1_SDA_PORT, &GPIO_InitStruct);

  /* Initilize I2C Bus */
  I2C_BUS_B.Instance             = I2C1;
  I2C_BUS_B.Init.Timing          = I2C1_TIMING;
  I2C_BUS_B.Init.OwnAddress1     = 0xFFFF;
  I2C_BUS_B.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
  I2C_BUS_B.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2C_BUS_B.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  I2C_BUS_B.Init.OwnAddress2     = 0xFF;
  I2C_BUS_B.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2C_BUS_B.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

  /* Enable Clock to I2C1 Interface */
  __HAL_RCC_I2C1_CLK_ENABLE();

  /* Initilize I2C module */
  while (HAL_I2C_Init(&I2C_BUS_B) != HAL_OK) {};
}


/******************************************************************************
 * @brief   ExFLASH Setting SPI 3 for DEV_Board(), SPI 2 for Production Board
 *
 * @note
 *
 ******************************************************************************/
void L4X9_QSPI_Init(void)
{ 
    if(DEV_Board())
    {
        // Notify ST is using ExFlash
        ST_FLASH_USE;
    
        __HAL_RCC_SPI3_CLK_ENABLE();
        __HAL_RCC_SPI3_FORCE_RESET();
        __HAL_RCC_SPI3_RELEASE_RESET();
        
        GPIO_InitTypeDef GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin = SPI3_CS_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = 0;
        HAL_GPIO_Init(SPI3_CS_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
        
        GPIO_InitStruct.Pin = SPI3_CLK_PIN;
        HAL_GPIO_Init(SPI3_CLK_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI3_MOSI_PIN;
        HAL_GPIO_Init(SPI3_MOSI_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI3_MISO_PIN;
        HAL_GPIO_Init(SPI3_MISO_PORT, &GPIO_InitStruct);
          
        SPI3Handle.Instance = SPI3;
        SPI3Handle.Init.Mode = SPI_MODE_MASTER;
        SPI3Handle.Init.Direction = SPI_DIRECTION_2LINES;
        SPI3Handle.Init.DataSize = SPI_DATASIZE_8BIT;
        SPI3Handle.Init.CLKPolarity = SPI_POLARITY_LOW;
        SPI3Handle.Init.CLKPhase = SPI_PHASE_1EDGE;
        SPI3Handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
        SPI3Handle.Init.FirstBit = SPI_FIRSTBIT_MSB;
        SPI3Handle.Init.TIMode = SPI_TIMODE_DISABLE;
        SPI3Handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
        SPI3Handle.Init.CRCPolynomial = 7;
        SPI3Handle.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
        SPI3Handle.Init.NSS = SPI_NSS_SOFT;
        SPI3Handle.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
        while (HAL_SPI_Init(&SPI3Handle) != HAL_OK) {};  
    }
    else
    {
      // Notify ST is using ExFlash
      PROD_ST_FLASH_USE;
        
      __HAL_RCC_OSPI2_CLK_ENABLE();
      __HAL_RCC_OSPI2_FORCE_RESET();
      __HAL_RCC_OSPI2_RELEASE_RESET();
      __HAL_RCC_OSPIM_CLK_ENABLE();
      __HAL_RCC_OSPIM_FORCE_RESET();
      __HAL_RCC_OSPIM_RELEASE_RESET();
  
      GPIO_InitTypeDef GPIO_InitStruct;
      
      GPIO_InitStruct.Pin = PROD_OSPI2_CS_PIN;
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_OSPI2_CS_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  
      GPIO_InitStruct.Pin       = PROD_OSPI2_CLK_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF5_OCTOSPIM_P2;
      HAL_GPIO_Init(PROD_OSPI2_CLK_PORT, &GPIO_InitStruct);
      
      GPIO_InitStruct.Pin       = PROD_OSPI2_MOSI_PIN;
      GPIO_InitStruct.Alternate = GPIO_AF5_OCTOSPIM_P2;
      HAL_GPIO_Init(PROD_OSPI2_MOSI_PORT, &GPIO_InitStruct);
      GPIO_InitStruct.Pin       = PROD_OSPI2_MISO_PIN;
      GPIO_InitStruct.Alternate = GPIO_AF5_OCTOSPIM_P2;
      HAL_GPIO_Init(PROD_OSPI2_MISO_PORT, &GPIO_InitStruct);
      
      OSPIM_CfgTypeDef OSPIM_Cfg_Struct = {0};

      OSPI2Handle.Instance = OCTOSPI2;
      OSPI2Handle.Init.FifoThreshold = 1;
      OSPI2Handle.Init.DualQuad = HAL_OSPI_DUALQUAD_DISABLE;
      OSPI2Handle.Init.MemoryType = HAL_OSPI_MEMTYPE_MICRON;
      OSPI2Handle.Init.DeviceSize = 32;
      OSPI2Handle.Init.ChipSelectHighTime = 1;
      OSPI2Handle.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
      OSPI2Handle.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
      OSPI2Handle.Init.ClockPrescaler = 1;
      OSPI2Handle.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
      OSPI2Handle.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
      OSPI2Handle.Init.ChipSelectBoundary = 0;
      while (HAL_OSPI_Init(&OSPI2Handle) != HAL_OK) {};

      OSPIM_Cfg_Struct.ClkPort = 2;
      OSPIM_Cfg_Struct.IOLowPort = HAL_OSPIM_IOPORT_2_LOW;
      while (HAL_OSPIM_Config(&OSPI2Handle, &OSPIM_Cfg_Struct, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {};
    }
}

/******************************************************************************
 * @brief   SPI 3 HW Detach.
 *
 * @note
 *
 ******************************************************************************/
void L4X9_QSPI_DeInit(void)
{  
    if(DEV_Board())
    {  
        /* DeInitialize QuadSPI */
        HAL_SPI_DeInit(&SPI3Handle);

        __HAL_RCC_SPI3_CLK_DISABLE();

        GPIO_InitTypeDef GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin = SPI3_CS_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = 0;
        HAL_GPIO_Init(SPI3_CS_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

        GPIO_InitStruct.Pin = SPI3_CLK_PIN;
        HAL_GPIO_Init(SPI3_CLK_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(SPI3_CLK_PORT, SPI3_CLK_PIN, GPIO_PIN_SET);
        
        GPIO_InitStruct.Pin = SPI3_MISO_PIN;
        HAL_GPIO_Init(SPI3_MISO_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(SPI3_MISO_PORT, SPI3_MISO_PIN, GPIO_PIN_SET);
        
        GPIO_InitStruct.Pin = SPI3_MOSI_PIN;
        HAL_GPIO_Init(SPI3_MOSI_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(SPI3_MOSI_PORT, SPI3_MOSI_PIN, GPIO_PIN_SET);  
            
        // Notify ST no more using Flash
        ST_FLASH_RELASE;
    
    }
    else
    {
        /* DeInitialize OSPI */
        HAL_OSPI_DeInit(&OSPI2Handle);

        __HAL_RCC_OSPI2_CLK_DISABLE();
        __HAL_RCC_OSPIM_CLK_DISABLE();
        
        GPIO_InitTypeDef GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin = PROD_OSPI2_CS_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = 0;
        HAL_GPIO_Init(PROD_OSPI2_CS_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);

        GPIO_InitStruct.Pin = PROD_OSPI2_CLK_PIN;
        HAL_GPIO_Init(PROD_OSPI2_CLK_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(PROD_OSPI2_CLK_PORT, PROD_OSPI2_CLK_PIN, GPIO_PIN_SET);
        
        GPIO_InitStruct.Pin = PROD_OSPI2_MISO_PIN;
        HAL_GPIO_Init(PROD_OSPI2_MISO_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(PROD_OSPI2_MISO_PORT, PROD_OSPI2_MISO_PIN, GPIO_PIN_SET);
        
        GPIO_InitStruct.Pin = PROD_OSPI2_MOSI_PIN;
        HAL_GPIO_Init(PROD_OSPI2_MOSI_PORT, &GPIO_InitStruct);
        HAL_GPIO_WritePin(PROD_OSPI2_MOSI_PORT, PROD_OSPI2_MOSI_PIN, GPIO_PIN_SET);  
         
        // Notify ST no more using Flash
        PROD_ST_FLASH_RELASE;
    } 
}


/******************************************************************************
 * @brief   Button Initilization routine.
 *          Initilize Port Pins as Input and Pull-Up.
 *          Activates the Interrupt on the EXTI Lines, on falling edge.
 *
 * @note
 *
 ******************************************************************************/
void L4X9_ButtonInit(void)
{
  GPIO_InitTypeDef   GPIO_InitStructure;

#ifdef BUTTON_BL_PIN
  /* Configure Buttons GPIO */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = BUTTON_BL_PIN;
  HAL_GPIO_Init(BUTTON_BL_PORT, &GPIO_InitStructure);

  /* Enable and set BUTTON_BL_EXTI_LINE Interrupt to priority BUTTON_NVIC_PRIORITY */
  HAL_NVIC_SetPriority(BUTTON_BL_IRQ, BUTTON_NVIC_PRIORITY, BUTTON_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(BUTTON_BL_IRQ);
#endif

#ifdef BUTTON_BR_PIN
  /* Configure Buttons GPIO */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = BUTTON_BR_PIN;
  HAL_GPIO_Init(BUTTON_BR_PORT, &GPIO_InitStructure);

  /* Enable and set BUTTON_BR_EXTI_LINE Interrupt to priority BUTTON_NVIC_PRIORITY */
  HAL_NVIC_SetPriority(BUTTON_BR_IRQ, BUTTON_NVIC_PRIORITY, BUTTON_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(BUTTON_BR_IRQ);
#endif

#ifdef BUTTON_TL_PIN
  /* Configure Buttons GPIO */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = BUTTON_TL_PIN;
  HAL_GPIO_Init(BUTTON_TL_PORT, &GPIO_InitStructure);

  /* Enable and set BUTTON_TL_EXTI_LINE Interrupt to priority BUTTON_NVIC_PRIORITY */
  HAL_NVIC_SetPriority(BUTTON_TL_IRQ, BUTTON_NVIC_PRIORITY, BUTTON_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(BUTTON_TL_IRQ);
#endif

#ifdef BUTTON_TR_PIN
  /* Configure Buttons GPIO */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = BUTTON_TR_PIN;
  HAL_GPIO_Init(BUTTON_TR_PORT, &GPIO_InitStructure);

  /* Enable and set BUTTON_TR_EXTI_LINE Interrupt to priority BUTTON_NVIC_PRIORITY */
  HAL_NVIC_SetPriority(BUTTON_TR_IRQ, BUTTON_NVIC_PRIORITY, BUTTON_NVIC_SUBPRIORITY);
  HAL_NVIC_EnableIRQ(BUTTON_TR_IRQ);
#endif

  /* Initilize Hardware Button Global Variable */
  HW_Buttons = 0;
}


/******************************************************************************
 * @brief Low Power Millisecond Delay Blocking Function
 *        This function is build up on the RTC Alarm A module.
 *        This function enters Stop mode, so do not use it if HF peripherals
 *        must be on.
 *
 * @note
 *
 * @param[in]
 *      uint32_t count : number of milliseconds to wait. Max Value: 999
 *
 ******************************************************************************/
void ms_LP_delay (uint32_t count)
{
  /* Disable the write protection for RTC registers */
  LL_RTC_DisableWriteProtection(RTC);

  /* Disable Bypass register to have fater access */
  LL_RTC_EnableShadowRegBypass(RTC);

  while (!LL_RTC_IsActiveFlag_ALRAW(RTC)) {};

  /* Set Don't care Masks on all registers except on sub second */
  LL_RTC_ALMA_SetMask(RTC, LL_RTC_ALMA_MASK_ALL);
  LL_RTC_ALMA_SetSubSecondMask(RTC, 14UL);

  /* Get updated Subsecons value */
  uint32_t ss = (RTC->SSR&0x00003FFF);

  /* Enable Bypass register */
  LL_RTC_DisableShadowRegBypass(RTC);

  //LL_RTC_ClearFlag_RS(RTC);

  /* Evaluate how many subsecond ticks to wait */
  uint32_t ticks = LL_RTC_GetSynchPrescaler(RTC);
  
  if ( count > 999UL )
    count = 999UL;

  ticks *= count;

  ticks /= 1000UL;

  ticks++;

  if (ss >= ticks)
    ss -= ticks;
  else
    ss = 8191UL - (ticks-ss);

  /* Set Subsescond register for ALarm A */
  LL_RTC_ALMA_SetSubSecond(RTC, (ss&0x00003FFF));

  delay_enabled = true;

  /* Enable Alarm A */
  LL_RTC_ALMA_Enable(RTC);

  /* Clear Alarm Interrupt flag */
  LL_RTC_ClearFlag_ALRA(RTC);

  /* Enable Alarm Interrupt */
  LL_RTC_EnableIT_ALRA(RTC);

  /* Configure EXTI */
  LL_EXTI_EnableIT_0_31(EXTI_IMR1_IM18);
  LL_EXTI_EnableRisingTrig_0_31(EXTI_IMR1_IM18);

  /* Configure NVIC for RTC_WKUP_IRQHandler */
  NVIC_EnableIRQ(RTC_Alarm_IRQn);
  NVIC_SetPriority(RTC_Alarm_IRQn,0x0F);
  
#if PSM_ENABLED
  /* Loop in Stop mode, other interrupts may wake up system */
  while (delay_enabled)
  {
    if(  ((LPUART1->CR1 & USART_CR1_UE)||(BLE_IS_CONNECTED))    // for Bluetooth ON
      || (TIM3->CR1 & TIM_CR1_CEN)                              // for Buzzer ON
      || (TIM8->CR1 & TIM_CR1_CEN)                              // for Vibrator ON
      || ((EcData.Status == COMPASS_CALIBRATING)||(DSX_Opcode == C9_COMPASS_PROCESSING))        // for Compass ON
      || ((GnssStatus==GNSS_ON)||(GnssReqOn==true)||(GnssReqWake==true)) )      // for GPS ON
    {
        // Wait to complete any comunication
        // ms_delay(1);	// for Debugging use only, NOT for product
    }
    else if( USART1->CR1 & USART_CR1_UE )
    {
      // Enter Stop Mode 1 only if UART1 is not busy
      if( (__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_BUSY) == RESET) 
            && (__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_IDLE) == SET)
              )
      {
        if(SystemStatus.GnssOn)
          CXD5605GF_StopModeEnter();
             
        L4X9_StopMode1Enter();
          
        if(SystemStatus.GnssOn)
          CXD5605GF_StopModeExit();
      }
    }
    else
      L4X9_StopMode2Enter();
  }
#else
  ms_delay(count);
#endif
  /* Disable Alarm Interrupt */
  LL_RTC_DisableIT_ALRA(RTC);

  /* Disable Alarm A */
  LL_RTC_ALMA_Disable(RTC);

  /* Enable RTC registers write protection */
  LL_RTC_EnableWriteProtection(RTC);
}

/******************************************************************************
 * @brief Millisecond Delay Blocking Function
 *
 * @note
 *  Uses the SysTick of Cortex-M4 module.
 *  For very low Clock speed may have less accuracy.
 *  Max value of ticks to be load in LOAD register is 0x00FFFFFF.
 *
 * @param[in]
 *      uint32_t count : number of milliseconds to wait. Max Value: 0x7FFFFFFF
 *
 ******************************************************************************/
void ms_delay (int32_t count)   // from R1006, changed from uint32_t to int32_t to avoid unexpected while loop lockup
{
  while (count-- > 0)
    us_delay(1000);
}


/******************************************************************************
 * @brief Microsecond Delay Blocking Function
 *
 * @note
 *  Uses the SysTick of Cortex-M4 module.
 *  For very low Clock speed may have less accuracy.
 *
 * @param[in]
 *      uint32_t count : number of microseconds to wait. Max Value depends on
 *                       SystemCoreClock. However if too high will be rounded to
 *                       SYSTICK_MAX_LOAD.
 *
 ******************************************************************************/
void us_delay (uint32_t count)
{
  uint32_t ticks = SystemCoreClock/1000000UL;
  uint32_t unity = ticks;

  //if(count > 1UL)
    ticks *= (count+1);                                             // Calculate ticks to wait

  if (ticks > SYSTICK_MAX_LOAD)                                       // Check max value
    ticks = SYSTICK_MAX_LOAD;

  if (ticks > 0UL)
  {
    SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk;                    // Disable SysTick Timer

    SysTick->LOAD  = ticks;//-1UL;                                     // set reload register
    SysTick->VAL   = 0;                                             // Load the SysTick Counter Value
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                         SysTick_CTRL_ENABLE_Msk;                       // Enable SysTick Timer

    while (SysTick->VAL == 0)
    {
    }

    while (SysTick->VAL > unity)
    {
    }

    SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk;                    // Disable SysTick Timer
  }
}



/******************************************************************************
 * @brief This function is called to increment a global variable "uwTick"
 *        used as STMCube library time base.
 *
 * @note
 *
 ******************************************************************************/
void HAL_IncTick(void)
{
  uwTick+=125;
}

/******************************************************************************
 * @brief Millisecond Delay Blocking Function Redefinition for STMCube library
 *
 * @note
 *  Uses the SysTick of Cortex-M4 module.
 *  For very low Clock speed may have less accuracy.
 *  Max value of ticks to be load in LOAD register is 0x00FFFFFF.
 *
 * @param[in]
 *      uint32_t count : number of milliseconds to wait. Max Value: 0xFFFFFFFF
 *
 ******************************************************************************/
void HAL_Delay (__IO uint32_t count)
{
#if 1
  ms_delay(count);
#else  
  count++;
  while (count--)
  {
    delay_enabled = true;

    uint32_t ticks = SystemCoreClock/1000UL;

    SysTick->LOAD  = ticks-1UL;                                             // set reload register
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); 	// set Priority for Systick Interrupt
    SysTick->VAL   = 0UL;                                             	// Load the SysTick Counter Value
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                         SysTick_CTRL_TICKINT_Msk    |
                         SysTick_CTRL_ENABLE_Msk;                         	// Enable SysTick IRQ and SysTick Timer

    while (delay_enabled)
    {
    }

    SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk;                        // Disable SysTick Timer
  }
#endif  
}

/******************************************************************************
 * @brief A test logic to switch system between Dev Board or Production Board
 *
 * @note
 * 
 *      0: Production Board
 *
 *      1: Development Board
 * 
 ******************************************************************************/
bool DEV_Board(void)
{
#ifdef DEV_BOARD_2020_IN_USE  
  return HAL_GPIO_ReadPin(BOARD_DETECT_PORT, BOARD_DETECT_PIN);         //modified from R1006, Firmware does not work at Old Model of Development Board made in 2019~2020
#else
  return false;
#endif
}

/******************************************************************************
 * @brief A test logic to check if system in charging by cable
 *
 * @note
 * 
 *      0: Charging Cable NOT connected
 *
 *      1: Charging Cable connected
 * 
 ******************************************************************************/
bool CableCharging(void)
{
  return HAL_GPIO_ReadPin(USB_CHARGING_PORT, USB_CHARGING_PIN);
}


/******************************************************************************************
 * @brief A test logic to check if system in charging either by cable or wireless charging
 *
 * @note
 * 
 *      0: Battery NOT in Charging: Both Charging Cable and Wireless Charging are OFF
 *
 *      1: Battery in Charging: Either Charging Cable or Wireless Charging is ON
 * 
 ******************************************************************************************/
bool BatteryCharging(void)
{
    if ( HAL_GPIO_ReadPin(USB_CHARGING_PORT, USB_CHARGING_PIN) || HAL_GPIO_ReadPin(MAX77950_WPDET_PORT, MAX77950_WPDET_PIN) )
    {
        SystemStatus.BatteryInCharging = true;
        return true;
    }
    else
    {
        SystemStatus.BatteryInCharging = false;
        SystemStatus.BatteryInChargingShowGUI = false;  // to remove Battery Charging GUI (B1)
        return false;
    }
}

/******************************************************************************************
 *
 * @brief       bool ShowChargingForNSec(int32_t n)
 * 
 * @note        0: User action time still NOT elapes long enough
 *
 *              1: User action elapes time long enough
 * 
 ******************************************************************************************/
bool ShowChargingForNSec(int32_t n)
{
    int32_t a, b;
    
    a = MonotonicClock_s;
    b = SystemStatus.user_act_timestamp;
    
    if((a - b) < n)
        return true;    // to display Charging B1 for n seconds
    else
        return false;   // NOT to wake up system to display Charging B1
}

/******************************************************************************************
 *
 * @brief       bool ShowChargingAfterNSec(int32_t n)
 * 
 * @note        0: No more delay, nor waiting 
 *
 *              1: User action time in delay, keep waiting 
 * 
 ******************************************************************************************/
bool ShowChargingAfterNSec(int32_t n)
{
    static bool FirstVisit = true;
    int32_t a, b, c;
    
    if( BatteryCharging() && (FirstVisit == true) && (SystemStatus.BatteryInChargingShowGUI == false) )
    {
        //PreBatteryInCharging = true;
        FirstVisit = false;
        SystemStatus.user_GUI_timestamp = MonotonicClock_s;
    }
    
    a = MonotonicClock_s;
    b = SystemStatus.user_GUI_timestamp;
    c = SystemStatus.user_act_timestamp;
    
    if( ( ( a - b ) > n )
      &&( ( a - c ) > n ) 
      &&( SystemStatus.BLE_status != BLE_HDL_CONNECT)  )
    {
        DSX_Opcode = B1_BATT_CHARGE;
        if( (( a - b ) > 30 )&&(( a - c ) > 30 ) )
        {
            Backlight_Set(0);
            GUI_SetBkColor(GUI_BLACK);
            GUI_Clear();
        }
        else
        {
            Backlight_Set(10);
        }
        
        SystemStatus.BatteryInChargingShowGUI = true;
        //PreBatteryInCharging = false;
        FirstVisit = true;
        return true;    // to display Charging B1 for n seconds
    }
    else
        return false;   // NOT to wake up system to display Charging B1
}

/******************************************************************************************
 * @brief A routine check on all around variables to assure values not out of range
 *
 * @note     VariableBoundaryCheck(void)           
 * 
 ******************************************************************************************/
void VariableBoundaryCheck(void)
{
    // Backlight Level Check and Range Limits
    if(USER_Set.BacklightLevel < 10)
        USER_Set.BacklightLevel = 10;
    
    if(USER_Set.BacklightLevel > 110)
        USER_Set.BacklightLevel = 110;
    
    // Dim Backlight Level Check and Range Limits
    if(USER_Set.DimBacklightLevel < 10)
        USER_Set.DimBacklightLevel = 10;
    
    if(USER_Set.DimBacklightLevel > 60)
        USER_Set.DimBacklightLevel = 60;    
}

/******************************************************************************************
 * @brief The routines to set TPn High or Low
 *
 * @note     void TPn_High(uint8_t n) and void TPn_Low(uint8_t n)           
 * 
 ******************************************************************************************/
void TPn_High(uint8_t n)
{
#if USE_REAL_BATTERY
#else
    switch(n)
    {
        case 0:
            HAL_GPIO_WritePin(TP0_PORT, TP0_PIN, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(TP1_PORT, TP1_PIN, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(TP2_PORT, TP2_PIN, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(TP3_PORT, TP3_PIN, GPIO_PIN_SET);
            break;
    }
#endif
}

void TPn_Low(uint8_t n)
{
#if USE_REAL_BATTERY
#else
    switch(n)
    {
        case 0:
            HAL_GPIO_WritePin(TP0_PORT, TP0_PIN, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(TP1_PORT, TP1_PIN, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(TP2_PORT, TP2_PIN, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(TP3_PORT, TP3_PIN, GPIO_PIN_RESET);
            break;
    }
#endif
}

#endif //_L4X9_MISC_H_