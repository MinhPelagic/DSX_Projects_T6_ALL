/**-------------------------------------------------------------------------
@file	blecom.cpp

@brief	BLE communication

This file handle BLE communications

@author	Hoang Nguyen Hoan
@date	May 23, 2021

Copyright (c) 2021 Pelagic Pressure Systems, all rights reserved

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------*/

#include "coredev/uart.h"
#include "diskio_flash.h"
#include "cfifo.h"
#include "idelay.h"
#include "convutil.h"
#include "iopinctrl.h"
#include "slip_intrf.h"
#include "pelagic_protocol.h"
#include "dsx.h"
#include "flash_cmd.h"
#include "board.h"

// BLE pins 
static const IOPinCfg_t s_BlePins[] = BLE_PINS_MAP;
static const int s_NbBlePins = sizeof(s_BlePins) / sizeof(IOPinCfg_t);


int nRFUartEvthandler(UARTDev_t *pDev, UART_EVT EvtId, uint8_t *pBuffer, int BufferLen);

#define RXFIFOSIZE			CFIFO_MEMSIZE(10*1024)
#define TXFIFOSIZE			CFIFO_MEMSIZE(10*1024)

alignas(4) uint8_t g_BleUartRxBuff[RXFIFOSIZE];
alignas(4) uint8_t g_BleUartTxBuff[TXFIFOSIZE];

static const IOPinCfg_t s_BleUartPins[] = BLEUART_PINS_MAP;

// UART configuration data
static const UARTCfg_t s_BleUartCfg = {
	.DevNo = BLEUART_DEVNO,
	.pIOPinMap = s_BleUartPins,
	.NbIOPins = sizeof(s_BleUartPins) / sizeof(IOPinCfg_t),
	.Rate = 115200,
	.DataBits = 8,
	.Parity = UART_PARITY_NONE,
	.StopBits = 1,
	.FlowControl = UART_FLWCTRL_NONE,
	.bIntMode = true,
	.IntPrio = 1,
	.EvtCallback = nRFUartEvthandler,
	.bFifoBlocking = true,
	.RxMemSize = 0,
	.pRxMem = NULL,
	.TxMemSize = 0,//FIFOSIZE,
	.pTxMem = NULL,//g_TxBuff,
	.bDMAMode = false,
};

UART g_BleUart;
Slip g_BleSlip;

#define BLE_RXFIFO_OUESZIE				30
#define BLE_RXFIFO_BLKSIZE				(PELAGIC_PROTOCOL_MTU + 2)
#define BLE_RXFIFO_MEMSIZE				CFIFO_TOTAL_MEMSIZE(BLE_RXFIFO_OUESZIE, BLE_RXFIFO_BLKSIZE)
alignas(4) uint8_t g_BleRxFifoMem[BLE_RXFIFO_MEMSIZE];
static HCFIFO g_hBleRxFifo = nullptr;
static volatile bool g_BleRxFlag = false;

bool CmdBlePowerDown()
{
    return SendCmd(&g_BleSlip, PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_BLE_SHUTDOWN, nullptr, 0);
}

int nRFUartEvthandler(UARTDev_t *pDev, UART_EVT EvtId, uint8_t *pBuffer, int BufferLen)
{
	static uint8_t buff[PELAGIC_PROTOCOL_MTU];
	static int len = 0;
	
	if (buff == nullptr)
	{
	  	g_BleRxFlag = false;
	}
	switch (EvtId)
	{
		case UART_EVT_RXTIMEOUT:
		case UART_EVT_RXDATA:
		  	{
  				int l = g_BleSlip.Rx(0, &buff[len], PELAGIC_PROTOCOL_MTU - len);
				if (g_BleSlip.RxCompleted())
				{
					uint8_t *p = CFifoPut(g_hBleRxFifo);
					if (p)
					{
					  	memcpy(p, buff, PELAGIC_PROTOCOL_MTU);
					}
					len = 0;
		  			g_BleRxFlag = true;
				}
				else
				{
				  	len += l;
					if ((PELAGIC_PROTOCOL_MTU - len) <=0)
					{
					  	// Bad packet, flush it
					  	len = 0;
					}
				}
			}
			break;
		case UART_EVT_TXREADY:
			break;
		case UART_EVT_LINESTATE:
			break;
	}

	return 0;
}

void BleComHandler()
{
  	if (g_BleRxFlag)
	{
	  	PelagicPacket_t *pkt = (PelagicPacket_t*)CFifoGet(g_hBleRxFifo);
		if (pkt)
		{
		  	ProcessPacket(&g_BleSlip, pkt);
		}
	}
}

bool BleComInit()
{
	// Init BT pins
	IOPinCfg(s_BlePins, s_NbBlePins);
	IOPinClear(BLE_RST_PORT, BLE_RST_PIN);
	IOPinClear(BLE_P3_PORT, BLE_P3_PIN);
  	IOPinSet(BLE_RST_PORT, BLE_RST_PIN);

	g_hBleRxFifo = CFifoInit(g_BleRxFifoMem, BLE_RXFIFO_MEMSIZE, BLE_RXFIFO_BLKSIZE, true);

	g_BleUart.Init(s_BleUartCfg);
	g_BleSlip.Init(&g_BleUart);
	
	return true;
}


