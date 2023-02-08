/**-------------------------------------------------------------------------
@file	EMPulse.h

@brief	Electromagnetic Pulse transceiver

@author	Hoang Nguyen Hoan
@date	June 13, 2021

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
#ifndef __EMPULSE_H__
#define __EMPULSE_H__

#include "coredev/iopincfg.h"

typedef enum {
	EMPULSE_EVENT_SCAN_START,	//!< Reciver start scaning for sync byte
	EMPULSE_EVENT_DATA_READY,	//!< Data received
	EMPULSE_EVENT_TX_READY,		//!< Transmit ready
	EMPULSE_EVENT_TIMEOUT
} EMPULSE_EVENT;

typedef void (*EMPulseEventHandler)(EMPULSE_EVENT Evt);

typedef union {
	uint64_t Val;
	struct {
		uint64_t CheckSum:8;
		uint64_t BatCond:2;
		uint64_t Extra:2;
		uint64_t TankPres:12;
		uint64_t ID6:4;
		uint64_t ID5:4;
		uint64_t ID4:4;
		uint64_t ID3:4;
		uint64_t ID2:4;
		uint64_t ID1:4;
		uint64_t Sync:8;
	};
} EMPulsePacket_t;

#pragma pack(push, 4)
typedef struct {
  uint32_t Timestamp;		//!< Time stamp received packet
  uint8_t Id[6];			//!< Tank ID
  uint32_t Pres;			//!< Tank pressure
  uint8_t BatCond;			//!< battery condition
} TankData_t;
#pragma pack(pop)

#define EMPULSE_RCVR_PINS_MAX			3	//!< Max number of pins
#define EMPULSE_RCVR_ENABLE_PIN_IDX		0	//!< Index to enable pin definition in the pins array
#define EMPULSE_RCVR_DATA_PIN_IDX		1	//!< Index to data pin
#define EMPULSE_RCVR_DESEN_PIN_IDX		2	//!< Index to desen pin

#define EMPULSE_RCVR_OPTION_ALWAYS_ON           1       //!< Keeps the receiver always on

typedef struct {
  	int TimerNo;		//!< Timer device number to use
	uint32_t IntPrio;	//!< Interrupt priority
	const IOPinCfg_t *pPins;	//!< GPIO pin map array see above pin idex order
	int NbPins;			//!< Total number of I/O pins defined
	EMPulseEventHandler EvtHandler;	//!< Event handler 
        uint32_t options;               //!< Bitwise options: EMPULSE_RCVR_OPTION_ALWAYS_ON
} EMPuslseRcvrCfg_t;

/// Private driver data. Do not access directly from user application
typedef struct {
  	EMPuslseRcvrCfg_t Cfg;
	EMPulsePacket_t Pkt;	//!< Last received packet data
	uint64_t Bits;
	volatile uint32_t Timestamp;		//!< Last received packet time stamp
	volatile int BitCnt;
	volatile uint32_t State;
	volatile uint32_t StartTime;
    volatile uint32_t doTimeout;
    volatile uint32_t powerState;
    volatile uint32_t StartBitErrCnt;
    uint32_t dummy;
} EMPulseRcvrDev_t;


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief	Initialize electromagnetic pulse receiver
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param	pCfg : Pointer to configuration data
 *
 * @return	true - Success
 */
bool EMPulseRcvrInit(EMPulseRcvrDev_t *pDev, EMPuslseRcvrCfg_t const *pCfg);

/**
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 */
void EMPulseRcvrPoweroff(EMPulseRcvrDev_t *pDev);

/**
 * @brief	Read decoded tank data
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param 	pData : Pointer to buffer to receive tank data
 *
 * @return	true - Tank data is valid (passed checksum)
 * 			false - Checksum failed
 */
bool EMPulseRcvrRead(EMPulseRcvrDev_t *pDev, TankData_t *pData);

/**
 * @brief	Read raw packet
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param 	pPkt : Pointer to buffer to receive raw packet data
 *
 * @return	Time stamp of the return packed
 */
uint32_t EMPulseRcvrPacket(EMPulseRcvrDev_t *pDev, EMPulsePacket_t *pPkt);

#ifdef __cplusplus
}
#endif // __cplusplus
  
#endif // __EMPULSE_H__

