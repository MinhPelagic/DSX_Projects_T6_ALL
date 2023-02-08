/*******************************************************************************
 * @file        : STM32L4_MCU_LPUART.h
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

#ifndef _MCU_LPUART_H_
#define _MCU_LPUART_H_


/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

/* Slip Protocol Defines */
#define SLIP_END        0xC0
#define SLIP_ESC        0xDB
#define SLIP_ESC_END    0xDC
#define SLIP_ESC_ESC    0xDD


/* BLE Defines */
#define BLE_FIFO_SIZE           2UL*1024UL+32
   
#define BLE_OFF                 0
#define BLE_ON                  1

/*******************************************************************************
 * @brief   Structures
 ******************************************************************************/
typedef struct 
{
  uint16_t first;               /* Index of the first byte */
  uint16_t last;                /* Index of the last byte */
  uint16_t size;                /* Number of valid data bytes into the Fifo.*/
  uint8_t fifo[BLE_FIFO_SIZE];  /* Fifo  */
} BLE_Fifo_t;


/*******************************************************************************
 * @brief   Global Variables
 ******************************************************************************/

/* Tx/Rx FIFO */
extern volatile BLE_Fifo_t BLE_FIFO_Tx;
extern volatile BLE_Fifo_t BLE_FIFO_Rx;

extern volatile bool BLE_RxProcessRequest;

/******************************************************************************
 * @brief       Initialize FIFO
 *
 * @note        
 *              
 ******************************************************************************/
void UART_InitFifo( volatile BLE_Fifo_t *fifo );

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
uint16_t UART_FillTxFifoSlip( USART_TypeDef* UARTx, volatile BLE_Fifo_t *fifo, const void *data2send, uint16_t size );

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
bool UART_ReadRxFifoSlip( USART_TypeDef* UARTx );

/******************************************************************************
 * @brief       BLE Comunication Peripheral Initialization
 *
 * @note        
 *              
 ******************************************************************************/
void UART_BLE_Init( USART_TypeDef* UARTx );

/******************************************************************************
 * @brief       BLE Comunication Peripheral On
 *
 * @note        
 *
 ******************************************************************************/
void UART_BLE_On( USART_TypeDef* UARTx );

/******************************************************************************
 * @brief       BLE Comunication Peripheral Off
 *
 * @note        
 *     
 ******************************************************************************/
void UART_BLE_Off( USART_TypeDef* UARTx );

/******************************************************************************
 * @brief       BLE Comunication Peripheral Off
 *
 * @note        
 *     
 ******************************************************************************/
void UART_BLE_Stb( USART_TypeDef* UARTx );

#endif //_MCU_UART_H_