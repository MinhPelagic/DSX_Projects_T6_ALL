/*******************************************************************************
 * @file        : CXD5605GF.c
 * @brief       : Low Level Driver for Sony GNSS.
 *                Driver is implemented on UART 1                 
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *      Reimplemntation of Avinash Kumar example code, for Pelagic system integration.
 ******************************************************************************/
#include "L4X9_includes.h"

#ifdef _CXD5605GF_H_

UART_HandleTypeDef GnssUartHandle;

char Cxd5605gfComBuf[CXD5605GF_MAX_COMBUF_MAX];
uint16_t Cxd5605gfMaxComBuf;
bool FwUpdateMode = false;

// Initialize GPIO. At system start up the GNSS chip is off.
// To be called after system reset in main.c
void CXD5605GF_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  GPIO_InitStruct.Pin       = GPS_PW_CTRL_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(GPS_PW_CTRL_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_PW_CTRL_PORT, GPS_PW_CTRL_PIN, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin       = GPS_RST_PIN;
  HAL_GPIO_Init(GPS_RST_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_RST_PORT, GPS_RST_PIN, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin       = GPS_RX_USART1_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPS_RX_USART1_TX_AF;
  HAL_GPIO_Init(GPS_RX_USART1_TX_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = GPS_TX_USART1_RX_PIN;
  GPIO_InitStruct.Alternate = GPS_TX_USART1_RX_AF;
  HAL_GPIO_Init(GPS_TX_USART1_RX_PORT, &GPIO_InitStruct);
}


// Switches On the GNSS chip and configures the UART
void CXD5605GF_On(void)
{
  // Switch On UART Clock
  __HAL_RCC_USART1_CLK_ENABLE();
  
  // Switch on HSI Clock
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_NONE;
  while (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK){};
  
  // Routew Clock to UART
  RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_HSI;
  while(HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK){}; 
  
  GnssUartHandle.Instance = USART1;
  GnssUartHandle.Init.BaudRate = 115200;
  GnssUartHandle.Init.WordLength = UART_WORDLENGTH_8B;
  GnssUartHandle.Init.StopBits = UART_STOPBITS_1;
  GnssUartHandle.Init.Parity = UART_PARITY_NONE;
  GnssUartHandle.Init.Mode = UART_MODE_TX_RX;
  GnssUartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  GnssUartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
  GnssUartHandle.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  GnssUartHandle.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  GnssUartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  while (HAL_UART_Init(&GnssUartHandle) != HAL_OK){};

  __HAL_UART_FLUSH_DRREGISTER(&GnssUartHandle);
    
  HAL_NVIC_SetPriority(UART_GNSS_IRQ, 0, 0);
  HAL_NVIC_EnableIRQ(UART_GNSS_IRQ);
  
  __HAL_UART_ENABLE_IT(&GnssUartHandle, UART_IT_RXNE);
  
  // Initialize Gpio
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  GPIO_InitStruct.Pin       = GPS_PW_CTRL_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(GPS_PW_CTRL_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_PW_CTRL_PORT, GPS_PW_CTRL_PIN, GPIO_PIN_SET);

  GPIO_InitStruct.Pin       = GPS_RST_PIN;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  HAL_GPIO_Init(GPS_RST_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_RST_PORT, GPS_RST_PIN, GPIO_PIN_SET);

  GPIO_InitStruct.Pin       = GPS_RX_USART1_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPS_RX_USART1_TX_AF;
  HAL_GPIO_Init(GPS_RX_USART1_TX_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = GPS_TX_USART1_RX_PIN;
  GPIO_InitStruct.Alternate = GPS_TX_USART1_RX_AF;
  HAL_GPIO_Init(GPS_TX_USART1_RX_PORT, &GPIO_InitStruct);
  
  // Update SystemStatus Flag
  SystemStatus.GnssOn = true;
}

// Switches OFF the GNSS chip, UART and reinit the GPIO for low power
void CXD5605GF_Off(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  GPIO_InitStruct.Pin       = GPS_PW_CTRL_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(GPS_PW_CTRL_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_PW_CTRL_PORT, GPS_PW_CTRL_PIN, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin       = GPS_RST_PIN;
  HAL_GPIO_Init(GPS_RST_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(GPS_RST_PORT, GPS_RST_PIN, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin       = GPS_RX_USART1_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPS_RX_USART1_TX_AF;
  HAL_GPIO_Init(GPS_RX_USART1_TX_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin       = GPS_TX_USART1_RX_PIN;
  GPIO_InitStruct.Alternate = GPS_TX_USART1_RX_AF;
  HAL_GPIO_Init(GPS_TX_USART1_RX_PORT, &GPIO_InitStruct);
  
  // Reset UART
  __HAL_RCC_USART1_FORCE_RESET();
  __HAL_RCC_USART1_RELEASE_RESET();
  
  // Switch Off UART Clock
  __HAL_RCC_USART1_CLK_DISABLE();
  
  // Switch Off HSI clock
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState            = RCC_HSI_OFF;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_NONE;
  while (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK){};
  
  // Update SystemStatus Flag
  SystemStatus.GnssOn = false;
}

// Reset the GNSS chip,
void CXD5605GF_Reset(void)
{
  HAL_GPIO_WritePin(GPS_RST_PORT, GPS_RST_PIN, GPIO_PIN_RESET);
  ms_delay(10);
  HAL_GPIO_WritePin(GPS_RST_PORT, GPS_RST_PIN, GPIO_PIN_SET);
}
  
  
// To be called before StopMode0/1
void CXD5605GF_StopModeEnter (void)
{
  UART_WakeUpTypeDef WakeUpSelection;
  
  // Check that no UART transfer is on-going
  while(__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_BUSY) == SET){};
  
  // Check that UART is ready to receive
  while(__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_REACK) == RESET){};
  
  // Config the wake-up event
  WakeUpSelection.WakeUpEvent = UART_WAKEUP_ON_STARTBIT;
  while (HAL_UARTEx_StopModeWakeUpSourceConfig(&GnssUartHandle, WakeUpSelection)!= HAL_OK){};
  
  // Enable the UART Wake UP from STOP mode Interrupt
  __HAL_UART_ENABLE_IT(&GnssUartHandle, UART_IT_WUF);
  
  // Enable MCU wake-up by UART
  HAL_UARTEx_EnableStopMode(&GnssUartHandle);
}

// To be called after StopMode0/1 exit
void CXD5605GF_StopModeExit (void)
{
  // Disable MCU wake-up by UART
  HAL_UARTEx_DisableStopMode(&GnssUartHandle);
}

// Uart Interrupt Handler
void UART_GNSS_IRQHDL(void)
{
  static uint8_t prevdata;
  
  uint32_t interrupt = USART1->ISR;
  uint32_t UartCr3   = USART1->CR3;
  
  if(interrupt & USART_ISR_RXNE_RXFNE)
  {
    if(FwUpdateMode == false)
    {
      volatile uint8_t rxdata;
      rxdata = (uint8_t)( USART1->RDR & (uint8_t)0xFFU );
      Cxd5605gfComBuf[Cxd5605gfMaxComBuf] = rxdata;

      if (rxdata == 0x0A)
      {
        if (prevdata ==0x0D)
          SystemStatus.GnssDataRxFlag = true;
      }
      prevdata = rxdata;
      Cxd5605gfMaxComBuf++;
      if (Cxd5605gfMaxComBuf >= CXD5605GF_MAX_COMBUF)
        Cxd5605gfMaxComBuf = 0;   
    }
    else
    {
      volatile uint8_t rxdata;
      rxdata = (uint8_t)( USART1->RDR & (uint8_t)0xFFU );
      Cxd5605gfComBuf[Cxd5605gfMaxComBuf] = rxdata;
    
      if (rxdata == 0x20)
      {
        if (prevdata ==0x3E)
          SystemStatus.GnssDataRxFlag = true;
      }
      
      if ( (rxdata == 0x0A) || (rxdata == 0x0D) )
      {
        SystemStatus.GnssDataRxFlag = true;
      }
      
      prevdata = rxdata;
      Cxd5605gfMaxComBuf++;
      if (Cxd5605gfMaxComBuf >= CXD5605GF_MAX_COMBUF)
        Cxd5605gfMaxComBuf = 0;   
    }
  }

  if(interrupt & USART_ISR_ORE)
  {
    __HAL_UART_CLEAR_OREFLAG(&GnssUartHandle);
  }
  
  if( ((interrupt & USART_ISR_WUF) != 0) && ((UartCr3 & USART_CR3_WUFIE) != 0) )
  {
    // Disable the UART Wake UP from STOP mode Interrupt
    __HAL_UART_DISABLE_IT(&GnssUartHandle, UART_IT_WUF);
  
    __HAL_UART_CLEAR_FLAG(&GnssUartHandle, UART_CLEAR_WUF);
  }
}

#endif // _CXD5605GF_H_