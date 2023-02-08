/*******************************************************************************
 * @file        : STM32L4_MCU_LPUART.c
 * @brief       : STM32L4xx UART Module Driver.
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/
 
/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _MCU_LPUART_H_

/* Tx/Rx FIFO */
volatile BLE_Fifo_t BLE_FIFO_Tx;
volatile BLE_Fifo_t BLE_FIFO_Rx;

volatile bool BLE_RxProcessRequest = false;

/******************************************************************************
 * @brief       Initialize FIFO
 *
 * @note        
 *              
 ******************************************************************************/
void UART_InitFifo( volatile BLE_Fifo_t *fifo )
{
  fifo->first = 0;
  fifo->last = 0;
  fifo->size = 0;
} 

/******************************************************************************
 * @brief       Fill Tx Fifo with 'size' data bytes, if Tx Fifo has sapce.
 *              The Tx Fifo is encapsulated in with a Slip Protocol.
 *              https://en.wikipedia.org/wiki/Serial_Line_Internet_Protocol
 *              https://www.tutorialspoint.com/serial-line-internet-protocol-slip
 *              https://tools.ietf.org/html/rfc1055
 *              Return number of data bytes feed into the Tx Fifo.
 *
 * @note        
 *              
 ******************************************************************************/
uint16_t UART_FillTxFifoSlip( USART_TypeDef* UARTx, volatile BLE_Fifo_t *fifo, const void *data2send, uint16_t size )
{
  /* Disable Transmit empty Interrupt */  
  LL_LPUART_DisableIT_TXE(UARTx);
  
  uint16_t databytes = 0;
  const uint8_t *data2send_buf = (const uint8_t *)data2send;

  while ( (databytes < size) && ((BLE_FIFO_SIZE - fifo->size) > 0) )
  {
    uint8_t data = *data2send_buf++;
    
    switch (data)
    {
      case SLIP_END:
          fifo->fifo[fifo->last] = SLIP_ESC;
          
          if( ++fifo->last == BLE_FIFO_SIZE )
            fifo->last = 0;
          fifo->size++;
          
          fifo->fifo[fifo->last] = SLIP_ESC_END;
        break;
     
      case SLIP_ESC:
          fifo->fifo[fifo->last] = SLIP_ESC;
          
          if( ++fifo->last == BLE_FIFO_SIZE )
            fifo->last = 0;
          fifo->size++;
          
          fifo->fifo[fifo->last] = SLIP_ESC_ESC;
        break;
        
    default:
      fifo->fifo[fifo->last] = data; 
    }
 
    if( ++fifo->last == BLE_FIFO_SIZE )
      fifo->last = 0;
    
    fifo->size++;
    
    databytes++;
  }
  
  /* Send SLIP END */
  fifo->fifo[fifo->last] = SLIP_END;
  
  if( ++fifo->last == BLE_FIFO_SIZE )
    fifo->last = 0;
    
  fifo->size++;
  
  /* Enable Transmit empty Interrupt */
  LL_LPUART_EnableIT_TXE(UARTx);

  return databytes;
}

/******************************************************************************
 * @brief       Read Data form RX Fifo.
 *              The Tx Fifo is encapsulated in with a Slip Protocol.
 *              https://en.wikipedia.org/wiki/Serial_Line_Internet_Protocol
 *              https://www.tutorialspoint.com/serial-line-internet-protocol-slip
 *              https://tools.ietf.org/html/rfc1055
 *
 * @note        Returns true when SLPI_END has been received 
 *              Returns false otherwise
 ******************************************************************************/
bool UART_ReadRxFifoSlip( USART_TypeDef* UARTx )
{
  static bool esc_received = false;
  static int32_t RxTimeStamp;

  // Get data
  uint8_t data = BT_USART->RDR;
  
  // Reinit Queque on timeout
  if(MonotonicClock_s - RxTimeStamp > 2)
    UART_InitFifo(&BLE_FIFO_Rx);
  
  RxTimeStamp = MonotonicClock_s;
    
  if(esc_received)
  {
    switch (data)
    {
      case SLIP_ESC_END:
        data = SLIP_END;
        break;
            
      case SLIP_ESC_ESC:
        data = SLIP_ESC;
        break;
    }
    esc_received = false;
  }
  else
  {
    switch(data)
    {
      case SLIP_END:
        return true;
        break;
      
      case SLIP_ESC:
        esc_received = true;
        return false;
        break;
    }
  }
  
  // Fill Buffer once Start char received
  if(BLE_FIFO_Rx.last > 0)
  {
    BLE_FIFO_Rx.fifo[BLE_FIFO_Rx.last++] = (uint8_t)data;
    BLE_FIFO_Rx.size++;
  }
  // Wait for Start Char
  else if(data == PELAGIC_PROTOCOL_START_BYTE)
  {
    BLE_FIFO_Rx.fifo[BLE_FIFO_Rx.last++] = (uint8_t)data;
    BLE_FIFO_Rx.size = 1;
    BLE_FIFO_Rx.first = 0;
  }
  
  // On overflow Reset Rx fifo
  if(BLE_FIFO_Rx.last > BLE_FIFO_SIZE)
    UART_InitFifo(&BLE_FIFO_Rx);
  
  return false;
}

/******************************************************************************
 * @brief       BLE Comunication Peripheral Initialization
 *
 * @note        
 *              
 ******************************************************************************/
void UART_BLE_Init( USART_TypeDef* UARTx )
{
  /* Configure RxTx Pins */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin           = USART_TX_BT_RX_PIN;
  GPIO_InitStruct.Mode          = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull          = GPIO_PULLUP;
  GPIO_InitStruct.Speed         = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate     = USART_TX_BT_RX_AF;
  HAL_GPIO_Init(USART_TX_BT_RX_PORT, &GPIO_InitStruct);
  GPIO_InitStruct.Pin           = USART_RX_BT_TX_PIN;
  GPIO_InitStruct.Alternate     = USART_RX_BT_TX_AF;
  HAL_GPIO_Init(USART_RX_BT_TX_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(USART_TX_BT_RX_PORT, USART_TX_BT_RX_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(USART_RX_BT_TX_PORT, USART_RX_BT_TX_PIN, GPIO_PIN_SET);
   
  /* Reinitalize Buffers */
  UART_InitFifo(&BLE_FIFO_Tx);
  UART_InitFifo(&BLE_FIFO_Rx);
  
  LL_LPUART_InitTypeDef BLE_UART = {0};
  
  BLE_UART.BaudRate             = 115200;
  BLE_UART.DataWidth            = LL_USART_DATAWIDTH_8B;
  BLE_UART.StopBits             = LL_USART_STOPBITS_1;
  BLE_UART.Parity               = LL_USART_PARITY_NONE;
  BLE_UART.TransferDirection    = LL_USART_DIRECTION_TX_RX;
  BLE_UART.HardwareFlowControl  = LL_USART_HWCONTROL_NONE;
  
  /* Peripheral clock enable */
  __HAL_RCC_LPUART1_CLK_ENABLE();
    
  LL_LPUART_Init(UARTx, &BLE_UART);
  
  LL_LPUART_EnableInStopMode(UARTx);
 
  #if defined (BT_USART_SWAP_PINS) && (BT_USART_SWAP_PINS)
    LL_LPUART_SetTXRXSwap(UARTx, LL_LPUART_TXRX_SWAPPED);
  #endif
}


/******************************************************************************
 * @brief       BLE Comunication Peripheral On
 *
 * @note        
 *
 ******************************************************************************/
void UART_BLE_On( USART_TypeDef* UARTx )
{
  /* Configure RxTx Pins */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin           = USART_TX_BT_RX_PIN;
  GPIO_InitStruct.Mode          = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull          = GPIO_NOPULL;
  GPIO_InitStruct.Speed         = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate     = USART_TX_BT_RX_AF;
  HAL_GPIO_Init(USART_TX_BT_RX_PORT, &GPIO_InitStruct);
  GPIO_InitStruct.Pin           = USART_RX_BT_TX_PIN;
  GPIO_InitStruct.Alternate     = USART_RX_BT_TX_AF;
  HAL_GPIO_Init(USART_RX_BT_TX_PORT, &GPIO_InitStruct);
  
  /* Clear RXIE Flag */
  LL_LPUART_RequestRxDataFlush(UARTx);
  
  /* Enable RX Interrupt */
  HAL_NVIC_SetPriority(USART_BT_IRQ, 0, 0);
  HAL_NVIC_EnableIRQ(USART_BT_IRQ);
  
  LL_LPUART_EnableIT_RXNE(UARTx);
  
  /* Reinitalize Buffers */
  UART_InitFifo(&BLE_FIFO_Tx);
  UART_InitFifo(&BLE_FIFO_Rx);
  
  /* Enable Module */
  LL_LPUART_Enable(UARTx);
  
  // Send Dummy Byte to wake BLE Uart
  uint8_t dummy[1];
  UART_FillTxFifoSlip( BT_USART, &BLE_FIFO_Tx, dummy, 0 );
  
  // wait 10ms for BLE to be ready
  ms_delay(10);
}

/******************************************************************************
 * @brief       BLE Comunication Peripheral Off
 *
 * @note        
 *     
 ******************************************************************************/
void UART_BLE_Off( USART_TypeDef* UARTx )
{
  /* Disable UART RX Interrupt */
  HAL_NVIC_DisableIRQ(USART_BT_IRQ);
  LL_LPUART_DisableIT_RXNE(UARTx);
  
  /* Configure RxTx Pins */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin           = USART_TX_BT_RX_PIN;
  GPIO_InitStruct.Mode          = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull          = GPIO_PULLUP;
  GPIO_InitStruct.Speed         = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate     = 0;//USART_TX_BT_RX_AF;
  HAL_GPIO_Init(USART_TX_BT_RX_PORT, &GPIO_InitStruct);
  GPIO_InitStruct.Pin           = USART_RX_BT_TX_PIN;
  GPIO_InitStruct.Alternate     = 0;//USART_RX_BT_TX_AF;
  HAL_GPIO_Init(USART_RX_BT_TX_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(USART_TX_BT_RX_PORT, USART_TX_BT_RX_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(USART_RX_BT_TX_PORT, USART_RX_BT_TX_PIN, GPIO_PIN_SET);
  
  /* Disable Module */  
  LL_LPUART_Disable(UARTx);
  
  /* Reinitalize Buffers */
  UART_InitFifo(&BLE_FIFO_Tx);
  UART_InitFifo(&BLE_FIFO_Rx);
}

/******************************************************************************
 * @brief       BLE Comunication Peripheral in StandBy
 *
 * @note        Intterupt on Falling RX pin edge enabled
 *     
 ******************************************************************************/
void UART_BLE_Stb( USART_TypeDef* UARTx )
{
  /* Disable UART RX Interrupt */
  HAL_NVIC_DisableIRQ(USART_BT_IRQ);
  LL_LPUART_DisableIT_RXNE(UARTx);
  
  /* DeInit RxTx Pins */
  HAL_GPIO_DeInit(USART_TX_BT_RX_PORT, USART_TX_BT_RX_PIN);
  HAL_GPIO_DeInit(USART_RX_BT_TX_PORT, USART_RX_BT_TX_PIN);
  
  /* Disable Module */  
  LL_LPUART_Disable(UARTx);
  
  // Eanble Interrupt on falling edge of Rx pin
  GPIO_InitTypeDef   GPIO_InitStructure = {0};
  GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = USART_TX_BT_RX_PIN;
  HAL_GPIO_Init(USART_TX_BT_RX_PORT, &GPIO_InitStructure);
  
  /* Enable and set 0 Interrupt to priority 0 */
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

#endif // _MCU_UART_H_