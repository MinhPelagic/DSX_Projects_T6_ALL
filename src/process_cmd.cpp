/**-------------------------------------------------------------------------
@file	process_cmd.cpp

@brief	Process command

This file process received commands

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

static volatile uint32_t g_RdCntx = 0;

bool ProcessCmd(DeviceIntrf *pIntrf, PelagicPacket_t * const pPacket)
{
	switch (pPacket->Header.CmdRsp)
	{
		case PELAGIC_PROTOCOL_CMD_BLE_RESET:
		   // NVIC_SystemReset();
			break;

		case PELAGIC_PROTOCOL_CMD_BLE_SETNAME:
			//g_Slip.Tx(0, (uint8_t*)pPacket, sizeof(PPACKET_HEADER) + pPacket->Header.Size);
			break;

		case PELAGIC_PROTOCOL_CMD_BLE_GETNAME:
			break;

		case PELAGIC_PROTOCOL_CMD_BLE_DISC:
			break;

		case PELAGIC_PROTOCOL_CMD_SET_TX_POWER:
			break;

		case PELAGIC_PROTOCOL_CMD_BOOT_OTA:
			break;

		case PELAGIC_PROTOCOL_CMD_GET_INFO:
			break;
		case PELAGIC_PROTOCOL_CMD_READ_FLASH:
		case 26:
		case 28:
		case 30:
		{
			if (FlashEnable() == true)
			{
				FlashReadCmd(pPacket);

				uint8_t buf[PELAGIC_PROTOCOL_MTU];
				PelagicPacket_t *pkt = (PelagicPacket_t*)buf;
				memcpy(pkt, pPacket, sizeof(PelagicPacketHdr_t));

				pkt->Header.PktSeqNo = 0;
				pkt->Header.Cont = 0;
				pkt->Header.PktType = PFRAME_PKT_TYPE_DATA;

				volatile bool flag = false;

				do {
					flag = FlashReadData(pkt);
					SendPacket(pIntrf, pkt);
					g_RdCntx++;
					msDelay(3);
				} while (flag == false);

				FlashDisable();

				PelagicCmdFlash_t resp = { CMD_FLASH_RESP_DONE };
				while (SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_READ_FLASH,
							&resp, sizeof(PelagicCmdFlash_t)) == false);
			}
			else
			{
				PelagicCmdFlash_t resp = { CMD_FLASH_RESP_ABORT };
				while (SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_READ_FLASH,
							&resp, sizeof(PelagicCmdFlash_t)) == false);
			}
#if 0
			pPacket->Header.PktSeqNo = 0;
			pPacket->Header.Cont = 0;
			pPacket->Header.Type = PFRAME_TYPE_DATA;
			PCMD_FLASH_RW cmd = *(PCMD_FLASH_RW*)pPacket->Payload;
			uint8_t buf[PELAGIC_PROTOCOL_MTU];
			PelagicPacket_t *pkt = (PelagicPacket_t*)buf;
			memcpy(pkt, pPacket, sizeof(PelagicPacketHdr_t));

			printf("CMD Read Flash %x %d\n", cmd.Addr, cmd.Len);

			while (cmd.Len > 0)
			{
				int len = min(cmd.Len, 96);

				pkt->Header.PayloadLen = len;

				if (len < cmd.Len)
				{
					pkt->Header.Cont = 1;
				}
				else
				{
					pkt->Header.Cont = 0;
				}

				g_FlashDisk.Read(cmd.Addr, pkt->Payload, len);

				cmd.Addr += len;
				cmd.Len -= len;

				while (SendPacket(&g_Slip, pkt) == false)
				{
					//taskYIELD();
					msDelay(5);
				}
//				SendDataRsp(&g_Slip, PFRAME_TYPE_DATA, pkt->Header.CmdRsp, pkt->Payload, len);
				g_RdCntx++;
				if (cmd.Len > 0)
				{
					pkt->Header.PktSeqNo++;
				}
				msDelay(10);
			}
#endif
	//		printf("g_RdCntx=%d\n", g_RdCntx);
		}
			break;
		case PELAGIC_PROTOCOL_CMD_WRITE_FLASH:
		case 27:
		case 29:
		case 31:
			printf("CMD Write Flash\n");
			if (FlashEnable() == true)
			{
				FlashWriteCmd(pPacket);

				PelagicCmdFlash_t resp = { CMD_FLASH_RESP_READY };
				bool flag = SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_WRITE_FLASH,
							&resp, sizeof(PelagicCmdFlash_t));
				if (flag == false)
				{
					printf("Resp WR failed");
				}
			}
			else
			{
				PelagicCmdFlash_t resp = { CMD_FLASH_RESP_ABORT };
				bool flag = SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_WRITE_FLASH,
							&resp, sizeof(PelagicCmdFlash_t));
				if (flag == false)
				{
					printf("Resp AB failed");
				}
			}
			break;
	}

	return true;
}

bool ProcessData(DeviceIntrf *pIntrf, PelagicPacket_t *pPacket)
{
	static uint32_t cnt = 0;
	static uint32_t badcnt = 0;
	static uint32_t pkcnt = 0;
	bool res = false;

	switch (pPacket->Header.CmdRsp)
	{
		case PELAGIC_PROTOCOL_CMD_WRITE_FLASH:
		case 27:
		case 29:
		case 31:
			if (cnt != pPacket->Header.PktSeqNo)
			{
				badcnt++;
				//printf("%d %d\n",  cnt, pPacket->Header.PktSeqNo);
				cnt = pPacket->Header.PktSeqNo;
			}

			cnt++;
			cnt &= 0x1F;
			pkcnt++;

			if (FlashWriteData(pPacket) == true)
			{
				printf("WR Flash Completed\n");

				FlashDisable();

				PelagicCmdFlashResp_t resp = { CMD_FLASH_RESP_DONE };
				SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_WRITE_FLASH,
							&resp, sizeof(PelagicCmdFlashResp_t));
			}
			else
			{
				PelagicCmdFlashResp_t resp = { 5 };
				SendDataRsp(pIntrf, PFRAME_PKT_TYPE_RESP,
						pPacket->Header.CmdRsp,//PELAGIC_PROTOCOL_CMD_WRITE_FLASH,
							&resp, sizeof(PelagicCmdFlashResp_t));
			}
			break;
	}

	return res;
}

bool ProcessResp(DeviceIntrf *pIntrf, PelagicPacket_t *pPacket)
{
	bool res = false;

	switch (pPacket->Header.CmdRsp)
	{
		case PELAGIC_PROTOCOL_CMD_BLE_SETNAME:
			res = true;
			break;
	}

	return res;
}

