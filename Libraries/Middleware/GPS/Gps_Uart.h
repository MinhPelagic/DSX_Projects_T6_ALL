
#ifndef __USB_UART_H
#define __USB_UART_H
/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "usart.h"

#define GPS_UART_TIMEOUT				1000

extern int ProcessInput(void);
extern void GpsRecvUart_IT(UART_HandleTypeDef *huart);

#define MAX_COMBUF_MAX 4832				// 8192+640 for rollover extra 640 (512+extra)
#define MAX_COMBUF 4192

#define MAX_COMMANDS	32				// max commands from com buffer conversion


extern char *Commands[MAX_COMMANDS],*MaxCommandStrPtr;
extern short MaxCommandPtr, CurCommandPtr,NextCommandPtr;
extern short MaxComBuf;
extern char ComBuf[MAX_COMBUF_MAX];
extern unsigned char BT_DataRxFlag;
void SendCommandToGps(uint8_t *cmd);

#endif
