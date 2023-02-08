/**-------------------------------------------------------------------------
@file	pelagic_protocl.h

@brief	Pelagic communication protocol

This file definitions of Pelagic protocol

@author	Hoang Nguyen Hoan
@date	Aug. 13, 2019

Copyright (c) 2019 Pelagic Pressure Systems, all rights reserved

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
#ifndef __PELAGIC_PROTOCOL_H__
#define __PELAGIC_PROTOCOL_H__

#include <stdint.h>
#include <stdbool.h>

// IOsonata include
#include "device_intrf.h"

#define PELAGIC_PROTOCOL_START_BYTE				0xCD

#pragma pack(push, 1)

typedef enum __Pelagic_Frame_Packet_Type {
	PFRAME_PKT_TYPE_CMDT = 0,		//!< Command destination to BLE
	PFRAME_PKT_TYPE_CMDA = 1,		//!< Command destination to App processor STM32 or App
	PFRAME_PKT_TYPE_DATA = 2,		//!< Data packet for multiple data packet in response to a command or data to be sent for a command
	PFRAME_PKT_TYPE_RESP = 3		//!< Response to a command. Usually when only 1 single packet data in response to a command
} PFRAME_PKT_TYPE;

typedef struct __Pelagic_Packet_Header {
	uint8_t StartByte;			//!< Packet start code : PELAGIC_PROTOCOL_START_BYTE
	union {
		uint8_t FrameType;
		struct {
			uint8_t PktSeqNo:5;	//!< Incremental sequence number
			uint8_t Cont:1;		//!< 0 : no more packet to come, 1 : more packet to come
			uint8_t PktType:2;		//!< PFRAME_TYPE
		};
	};
	uint8_t CmdRsp;				//!< Command/Response code
	uint8_t Crc;				//!< CRC of the whole packet. Intialize this to 0 before calc crc
	uint8_t PayloadLen;			//!< Payload length in bytes
} PelagicPacketHdr_t;

#define PELAGIC_PROTOCOL_MAX_PAYLOAD			(255)
#define PELAGIC_PROTOCOL_MTU					(PELAGIC_PROTOCOL_MAX_PAYLOAD + sizeof(PelagicPacketHdr_t))

typedef struct __Pelagic_Packet {
	PelagicPacketHdr_t Header;				//!< packet header
	uint8_t Payload[1];					//!< Variable length payload, can be more than 1 byte
} PelagicPacket_t;

/// Paload for response to PELAGIC_PROTOCOL_CMD_GET_INFO command
typedef struct __Pelagic_Cmd_Info_Resp {
	uint32_t HwRev;						//!< Hardware revision
	uint16_t FwVers;					//!< Firmware version
	uint32_t FwBuild;					//!< Firmware build number
	uint64_t Uid;
} PelagicCmdInfoResp_t;

/// Payload for FLASH Read/Write command
typedef struct __Pelagic_Cmd_Flash {
	uint32_t Addr;						//!< Flash address
	uint32_t Len;						//!< Length in bytes
} PelagicCmdFlash_t;

/// Response payload for flash write command
#define CMD_FLASH_RESP_OK			0		//!< Flash command accepted
#define CMD_FLASH_RESP_READY		1		//!< Ready to receive data
#define CMD_FLASH_RESP_DONE			2		//!< Flash read/write completed
#define CMD_FLASH_RESP_WRPROT		0xfe	//!< Flash write protected
#define CMD_FLASH_RESP_ABORT		0xff	//!< Flash in use, cmd aborted


typedef struct __Pelagic_Cmd_Flash_Resp {
	uint8_t RespCode;
} PelagicCmdFlashResp_t;

#pragma pack(pop)

#define PELAGIC_PROTOCOL_CMD_BLE_RESET				1	//!< Reset BLE device
#define PELAGIC_PROTOCOL_CMD_BLE_SETNAME			2	//!< Set BLE device name
#define PELAGIC_PROTOCOL_CMD_BLE_GETNAME			3	//!< Get BLE device name
#define PELAGIC_PROTOCOL_CMD_BLE_SHUTDOWN			8	//!< Force BLE shutdown
#define PELAGIC_PROTOCOL_CMD_BLE_DISC				9	//!< Force disconnect
#define PELAGIC_PROTOCOL_CMD_SET_TX_POWER			10	//!< Set BLE Tx power
#define PELAGIC_PROTOCOL_CMD_BOOT_OTA				11	//!< Boot BLE into OTA DFU
#define PELAGIC_PROTOCOL_CMD_GET_INFO				12	//!< Get device info.
#define PELAGIC_PROTOCOL_CMD_READ_FLASH				13	//!< Read from flash
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH			14	//!< Write to flash
#define PELAGIC_PROTOCOL_CMD_SET_ADV_INTERVAL		15	//!< Set BLE advertisement interval
#define PELAGIC_PROTOCOL_CMD_SET_WR_REGION			16	//!< Set Flash write region
#define PELAGIC_PROTOCOL_CMD_SEL_FLASH_DEV			17	//!< Select flash device to use
#define PELAGIC_PROTOCOL_CMD_UART_OFF				18	//!< Turn off UART
#define PELAGIC_PROTOCOL_CMD_READ_EEPROM        	20	//!< Read to EEPROM
#define PELAGIC_PROTOCOL_CMD_WRITE_EEPROM       	21	//!< Write to EEPROM

#define PELAGIC_PROTOCOL_CMD_RUTHERE            32
#define PELAGIC_PROTOCOL_CMD_WAKEUP_RDONLY      33
#define PELAGIC_PROTOCOL_CMD_WAKEUP_RDWR        34
#define PELAGIC_PROTOCOL_CMD_BACK2SURF          35
#define PELAGIC_PROTOCOL_CMD_ENTER_DEEPSLEEP    113
#define PELAGIC_PROTOCOL_CMD_ENTER_SLEEP        114

#define PELAGIC_PROTOCOL_CMD_SETCLOCK           36
#define PELAGIC_PROTOCOL_CMD_READ_A2D           37
#define PELAGIC_PROTOCOL_CMD_READ_INSTANT_PT    38

#define PELAGIC_PROTOCOL_CMD_READ_MFG_CAL       39
#define PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL      40
#define PELAGIC_PROTOCOL_CMD_READ_USER_SET      41
#define PELAGIC_PROTOCOL_CMD_WRITE_USER_SET     42
#define PELAGIC_PROTOCOL_CMD_READ_SCUBA_SET     43
#define PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET    44
#define PELAGIC_PROTOCOL_CMD_READ_FREE_SET      45
#define PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET     46
#define PELAGIC_PROTOCOL_CMD_READ_EXFLASH_MAP   47
#define PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP  48
#define PELAGIC_PROTOCOL_CMD_READ_DEV_REC       49
#define PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC      50
#define PELAGIC_PROTOCOL_CMD_READ_MY_INFO       51
#define PELAGIC_PROTOCOL_CMD_WRITE_MY_INFO      52

#define PELAGIC_PROTOCOL_CMD_SEND_NOTIFICATION          60
#define PELAGIC_PROTOCOL_CMD_SEND_AUTHENTICATION       151

#define PELAGIC_PROTOCOL_CMD_FW_UPDATE          112

#define PELAGIC_PROTOCOL_CMD_READ_SYSTEM_ERROR  115

#define PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS 250
#define PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE    251

#ifdef __cplusplus

// C++ function prototypes

bool ProcessPacket(DeviceIntrf *pIntrf, PelagicPacket_t *pPkt);
bool SendPacket(DeviceIntrf *pIntrf, PelagicPacket_t *pPacket);
bool SendCmd(DeviceIntrf *pIntrf, PFRAME_PKT_TYPE CmdType, uint8_t CmdRsp, void *pParam, int ParamLen);
bool SendDataRsp(DeviceIntrf *pIntrf, PFRAME_PKT_TYPE Type, uint8_t CmdRsp, void *pData, int DataLen);
bool ProcessCmd(DeviceIntrf *pIntrf, PelagicPacket_t *pPkt);
bool ProcessData(DeviceIntrf *pIntrf, PelagicPacket_t *pPkt);
bool ProcessResp(DeviceIntrf *pIntrf, PelagicPacket_t *pPkt);
bool isPacketValid(PelagicPacket_t *pPkt);

extern "C" {
#endif
// C function prototypes

#ifdef __cplusplus
}
#endif


#endif // __PELAGIC_PROTOCOL_H__
