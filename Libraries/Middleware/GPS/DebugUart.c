/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
//#include "usart.h"
#include "Gps_Uart.h"
#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

void SendCommandToDebugUart(uint8_t *cmd)
{
	HAL_UART_Transmit(&huart4,cmd,strlen((char *)cmd),GPS_UART_TIMEOUT);
}

