/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "Gps_Uart.h"
#include "usart.h"
#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include "GpsHeaderFile.h"


void SendCommandToGps(uint8_t *cmd);
void GpsRecvUart_IT(UART_HandleTypeDef *huart);
int ProcessInput(void);
char combuffer[150];

char 			ComBuf[MAX_COMBUF_MAX];
unsigned char 	BT_DataRxFlag = 0;
short 			MaxComBuf=0;
uint8_t     	prevdata;
short PtrComBuf=0;
// comport data
char *Commands[MAX_COMMANDS], *MaxCommandStrPtr;
short MaxCommandPtr=0, CurCommandPtr=0, NextCommandPtr=0; 

void GpsRecvUart_IT(UART_HandleTypeDef *huart)
{
    volatile uint8_t rxdata;
		rxdata = (uint8_t)(huart->Instance->RDR & (uint8_t)0xFFU);
		ComBuf[MaxComBuf] = rxdata;
		if (rxdata == 0x0A)
		{
            if (prevdata ==0x0D)
              BT_DataRxFlag = 1;
		}
		prevdata = rxdata;
		MaxComBuf++;
		if (MaxComBuf >= MAX_COMBUF)
			MaxComBuf = 0;        

}

int ProcessInput()  //05 Feb Simulator + 16 Feb Firmware download new
{
	short i=0;

	i = PtrComBuf;
	while (i != MaxComBuf)								// loop through to catchup with MaxComBuf. 
	{
        if(ComBuf[i]==0x24)
        {
            PtrComBuf = i;
        }
        if(ComBuf[i] == '\n' && (ComBuf[i-1] == '\r'))
        {
            memcpy(combuffer, &ComBuf[PtrComBuf], (i-PtrComBuf));
            PtrComBuf=i;
            Commands[MaxCommandPtr] = &combuffer[0];
            MaxCommandPtr++;
            if (MaxCommandPtr >= MAX_COMMANDS) 
                MaxCommandPtr = 0;
        }
		if (i == MaxComBuf)
        {
			break;
        }
		if (i >= MAX_COMBUF)
        {            
            i = 0;											// Roll back when exceeding limit
            PtrComBuf=0;
        }
		if (i >= MaxComBuf && MAX_COMBUF-MaxComBuf < 200)							// saftey measure to prevent accental exceed
		{
			PtrComBuf = MaxComBuf=0;
			break;
		}
        i++;
	}
	return 0;
}
void SendCommandToGps(uint8_t *cmd)
{
	HAL_UART_Transmit(&huart1,cmd,strlen((char *)cmd),GPS_UART_TIMEOUT);
}
