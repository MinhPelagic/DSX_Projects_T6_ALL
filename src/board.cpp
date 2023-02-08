/**-------------------------------------------------------------------------
@file	board.cpp

@brief	Board specific initializations

This file contains all hardware initializations and device instances for the
specific board 

@author	Hoang Nguyen Hoan
@date	May 9, 2021

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

#include "coredev/spi.h"
#include "coredev/i2c.h"
#include "coredev/timer.h"
#include "diskio_flash.h"
#include "idelay.h"
#include "convutil.h"
#include "iopinctrl.h"

#include "board.h"

#if 1
/// I2C pins
#define I2C1_DEVNO				0			// I2C device 1
#define I2C1_SCL_PORT			IOPORTB
#define I2C1_SCL_PIN			6
#define I2C1_SCL_PINOP			IOPINOP_FUNC4//0x42		// AF4
#define I2C1_SDA_PORT			IOPORTG
#define I2C1_SDA_PIN			13
#define I2C1_SDA_PINOP			IOPINOP_FUNC4//0x42		// AF4

#define I2C1_PINS_MAP	{ \
	{I2C1_SDA_PORT, I2C1_SDA_PIN, I2C1_SDA_PINOP, IOPINDIR_BI, IOPINRES_NONE, IOPINTYPE_OPENDRAIN},\
	{I2C1_SCL_PORT, I2C1_SCL_PIN, I2C1_SCL_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_OPENDRAIN},}

#define I2C2_DEVNO				1			// I2C device 2
#define I2C2_SCL_PORT			IOPORTF
#define I2C2_SCL_PIN			1
#define I2C2_SCL_PINOP			IOPINOP_FUNC4//0x42		// AF4
#define I2C2_SDA_PORT       	IOPORTF
#define I2C2_SDA_PIN			0
#define I2C2_SDA_PINOP			IOPINOP_FUNC4//0x42		// AF4

#define I2C2_PINS_MAP	{ \
	{I2C2_SDA_PORT, I2C2_SDA_PIN, I2C2_SDA_PINOP, IOPINDIR_BI, IOPINRES_NONE, IOPINTYPE_OPENDRAIN},\
	{I2C2_SCL_PORT, I2C2_SCL_PIN, I2C2_SCL_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_OPENDRAIN},}

/// Flash pins
#define FLASH_CS_PORT			IOPORTA // Port A
#define FLASH_CS_PIN			15
#define FLASH_CS_PINOP			0
#define FLASH_HOLD_PORT			IOPORTE // Port E
#define FLASH_HOLD_PIN			4
#define FLASH_HOLD_PINOP		0
#define FLASH_WP_PORT			IOPORTE // Port E
#define FLASH_WP_PIN			5
#define FLASH_WP_PINOP			0

/// SPI pins
#define SPI3_DEVNO				2	// SPI3 device
#define SPI3_PHY				SPIPHY_NORMAL
#define SPI3_CS_MODE			SPICSEL_DRIVER
#define SPI3_CLK_PORT			IOPORTB // Port B
#define SPI3_CLK_PIN			3
#define SPI3_CLK_PINOP			IOPINOP_FUNC6//0x62		// AF6 
#define SPI3_MISO_PORT			IOPORTB // Port B
#define SPI3_MISO_PIN			4
#define SPI3_MISO_PINOP			IOPINOP_FUNC6//0x62		// AF6
#define SPI3_MOSI_PORT			IOPORTC // Port C
#define SPI3_MOSI_PIN			12
#define SPI3_MOSI_PINOP			IOPINOP_FUNC6//0x62		//AF6

#define SPI3_PINS_MAP	{ \
	{SPI3_CLK_PORT, SPI3_CLK_PIN, SPI3_CLK_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},\
	{SPI3_MISO_PORT, SPI3_MISO_PIN, SPI3_MISO_PINOP, IOPINDIR_INPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},\
	{SPI3_MOSI_PORT, SPI3_MOSI_PIN, SPI3_MOSI_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},\
	{FLASH_CS_PORT, FLASH_CS_PIN, FLASH_CS_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},\
}

#endif
// Buttons
static const IOPinCfg_t s_ButPins[] = BUT_PINS_MAP;
static const int s_NbButPins = sizeof(s_ButPins) / sizeof(IOPinCfg_t);

// BT 
static const IOPinCfg_t s_BlePins[] = BLE_PINS_MAP;
//static const int s_NbBlePins = sizeof(s_BlePins) / sizeof(IOPinCfg_t);

// I2C1
static const IOPinCfg_t s_I2c1Pins[] = I2C1_PINS_MAP;
/*
static const I2CCfg_t s_I2c1Cfg = {
  	.DevNo = I2C1_DEVNO,
	.Type = I2CTYPE_STANDARD,
	.Mode = I2CMODE_MASTER,
	.pIOPinMap = s_I2c1Pins,
	.NbIOPins = sizeof(s_I2c1Pins)/sizeof(IOPinCfg_t),
	.Rate = 100000,
	.MaxRetry = 3,
	.AddrType = I2CADDR_TYPE_NORMAL,
	.NbSlaveAddr = 0,
};
*/
I2C g_I2c1;

// I2C2
static const IOPinCfg_t s_I2c2Pins[] = I2C2_PINS_MAP;
/*
static const I2CCfg_t s_I2c2Cfg = {
  	.DevNo = I2C2_DEVNO,
	.Type = I2CTYPE_STANDARD,
	.Mode = I2CMODE_MASTER,
	.pIOPinMap = s_I2c2Pins,
	.NbIOPins = sizeof(s_I2c2Pins) / sizeof(IOPinCfg_t),
	.Rate = 100000,
	.MaxRetry = 3,
	.AddrType = I2CADDR_TYPE_NORMAL,
	.NbSlaveAddr = 0,
};
*/
I2C g_I2c2;

static const IOPinCfg_t s_Spi3Pins[] = SPI3_PINS_MAP;

static const SPICfg_t s_Spi3Cfg = {
	.DevNo = SPI3_DEVNO,
	.Phy = SPI3_PHY,
    .Mode = SPIMODE_MASTER,
	.pIOPinMap = s_Spi3Pins,
	.NbIOPins = sizeof(s_Spi3Pins) / sizeof(IOPinCfg_t),
    .Rate = 32000000,   // Speed in Hz
    .DataSize = 8,      // Data Size
    .MaxRetry = 5,      // Max retries
    .BitOrder = SPIDATABIT_MSB,
    .DataPhase = SPIDATAPHASE_FIRST_CLK, // Data phase
    .ClkPol = SPICLKPOL_HIGH,         // clock polarity
    .ChipSel = SPI3_CS_MODE,
	.bDmaEn = false,	// DMA
	.bIntEn = false,
    .IntPrio = 6, 		// Interrupt priority
    .EvtCB = NULL
};

SPI g_Spi3;

/// Flash
bool FlashWriteDelayCallback(int DevNo, DeviceIntrf *pInterf);
bool MT25QL512_Init(int DevNo, DeviceIntrf* pInterface);
/*
static FlashDiskIOCfg_t s_MT25QL512Cfg = {
	.DevNo = 0,
	.TotalSize = 512 * 1024 / 8,      	// 512 Mbits
	.SectSize = 4,
	.BlkSize = 32,						// minimum erase block size
	.WriteSize = 256,					// Write page size
	.AddrSize = 4,                      // 3 bytes addressing
	.DevId = 0x20ba20,
	.DevIdSize = 3,
	.pInitCB = MT25QL512_Init,			// no special init require.
	.pWaitCB = FlashWriteDelayCallback,					// blocking, no wait callback
};
*/
FlashDiskIO g_FlashDiskIO;

static uint8_t s_FlashCacheMem[DISKIO_SECT_SIZE];
DiskIOCache_t g_FlashCache = {
    -1, 0xFFFFFFFF, s_FlashCacheMem
};

bool FlashWriteDelayCallback(int DevNo, DeviceIntrf *pInterf)
{
	msDelay(3);
	return true;
}

bool MT25QL512_Init(int DevNo, DeviceIntrf* pInterface)
{
    if (pInterface == NULL)
        return false;

	int cnt;
    uint32_t d;
    uint32_t r = 0;

    d = FLASH_CMD_RESET_ENABLE;
    cnt = pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    d = FLASH_CMD_RESET_DEVICE;
    cnt = pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    msDelay(1);

    d = FLASH_CMD_READID;
    cnt = pInterface->Read(DevNo, (uint8_t*)&d, 1, (uint8_t*)&r, 3 );

    printf("R=%x\r\n", r);

    msDelay(1);

	if (r != 0x20ba20)
    	return false;

    printf("Flash found!\r\n");
    // Enable write
    d = FLASH_CMD_EN4B;
    cnt = pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    return true;
}
#if 0
void ButIntHandler(int IntNo)
{
	switch (IntNo)
	{
		case BUT_BL_PIN:
		  	//printf("BUT_BL_PIN\n");
			HW_Buttons |= HW_BUTTON_BL;
			SystemStatus.user_act_timestamp = MonotonicClock_s;
			break;
		case BUT_BR_PIN:
		  	//printf("BUT_BR_PIN\n");
			HW_Buttons |= HW_BUTTON_BR;
			SystemStatus.user_act_timestamp = MonotonicClock_s;
			break;
		case BUT_TL_PIN: // S2
		  	//printf("BUT_TL_PIN\n");
			HW_Buttons |= HW_BUTTON_TL;
			SystemStatus.user_act_timestamp = MonotonicClock_s;
			break;
		case BUT_TR_PIN:
		  	//printf("BUT_TR_PIN\n");
			HW_Buttons |= HW_BUTTON_TR;
			SystemStatus.user_act_timestamp = MonotonicClock_s;
			break;
	}
}
#endif

void BoardInit()
{
	// Init BT pins
	//IOPinCfg(s_BlePins, s_NbBlePins);
	
	// Init Buttons
	IOPinCfg(s_ButPins, s_NbButPins);

	// Init SPI3
	//g_Spi3.Init(s_Spi3Cfg);
	
	//if (g_FlashDiskIO.Init(s_MT25QL512Cfg, &g_Spi3, &g_FlashCache, 1) == false)
	{
		//printf("Flash not found\r\n");
	}

	// Init I2C1
	//g_I2c1.Init(s_I2c1Cfg);
	
	// Init I2C2
	//g_I2c2.Init(s_I2c2Cfg);
	
	// Button interrupts
	IOPinEnableInterrupt(BUT_BL_PIN, BUT_INT_PRIO, BUT_BL_PORT, BUT_BL_PIN, IOPINSENSE_LOW_TRANSITION, ButIntHandler, NULL);
	IOPinEnableInterrupt(BUT_BR_PIN, BUT_INT_PRIO, BUT_BR_PORT, BUT_BR_PIN, IOPINSENSE_LOW_TRANSITION, ButIntHandler, NULL);
	IOPinEnableInterrupt(BUT_TL_PIN, BUT_INT_PRIO, BUT_TL_PORT, BUT_TL_PIN, IOPINSENSE_LOW_TRANSITION, ButIntHandler, NULL);
	IOPinEnableInterrupt(BUT_TR_PIN, BUT_INT_PRIO, BUT_TR_PORT, BUT_TR_PIN, IOPINSENSE_LOW_TRANSITION, ButIntHandler, NULL);
}

DevIntrf_t *GetI2cDev(int DevNo)
{
  	DevIntrf_t *retval = NULL;
	
	switch (DevNo)
	{
		case 1:
		  	retval = g_I2c1;
			break;
		case 2:
		  	retval = g_I2c2;
			break;
	}
	
	return retval;
}

I2C *GetI2c(int DevNo)
{
  	I2C *retval = NULL;
	
	switch (DevNo)
	{
		case 1:
		  	retval = &g_I2c1;
			break;
		case 2:
		  	retval = &g_I2c2;
			break;
	}
	
	return retval;
}

DevIntrf_t *GetSpiDev()
{
  	return g_Spi3;
}

SPI *GetSpi()
{
  	return &g_Spi3;
}

bool SpiInit()
{
	return g_Spi3.Init(s_Spi3Cfg);
}

void SpiPowerOff()
{
  	g_Spi3.PowerOff();
}

