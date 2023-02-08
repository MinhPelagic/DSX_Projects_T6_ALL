/**-------------------------------------------------------------------------
@file	flash.cpp

@brief	Flash device

This file handle external flash device

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

#include "coredev/spi.h"
#include "diskio_flash.h"
#include "idelay.h"
#include "convutil.h"
#include "iopinctrl.h"
#include "dsx.h"
#include "board.h"
/*
static const IOPinCfg_t s_Spi3Pins[] = SPI3_PINS_MAP;

static const SPICfg_t s_Spi3Cfg = {
	.DevNo = SPI3_DEVNO,
	.Phy = SPI3_PHY,
    .Mode = SPIMODE_MASTER,
	.pIOPinMap = s_Spi3Pins,
	.NbIOPins = sizeof(s_Spi3Pins) / sizeof(IOPinCfg_t),
    .Rate = 8000000,   // Speed in Hz
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
*/
SPI g_Spi3;

/// Flash
bool FlashWriteDelayCallback(int DevNo, DeviceIntrf *pInterf);
bool MT25QL512_Init(int DevNo, DeviceIntrf* pInterface);

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

FlashDiskIO g_FlashDisk;

static uint8_t s_FlashCacheMem[4][DISKIO_SECT_SIZE];
DiskIOCache_t g_FlashCache[4] = {
    -1, 0xFFFFFFFF, s_FlashCacheMem[0],
    -1, 0xFFFFFFFF, s_FlashCacheMem[1],
    -1, 0xFFFFFFFF, s_FlashCacheMem[2],
    -1, 0xFFFFFFFF, s_FlashCacheMem[3],
};
static const int s_NbFlashCache = sizeof(g_FlashCache) / sizeof(DiskIOCache_t);

bool FlashWriteDelayCallback(int DevNo, DeviceIntrf *pInterf)
{
	msDelay(4);
	return true;
}

bool MT25QL512_Init(int DevNo, DeviceIntrf* pInterface)
{
    if (pInterface == NULL)
        return false;

    uint32_t d;
    uint32_t r = 0;

    d = FLASH_CMD_RESET_ENABLE;
    pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    d = FLASH_CMD_RESET_DEVICE;
    pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    msDelay(1);

    d = FLASH_CMD_READID;
    pInterface->Read(DevNo, (uint8_t*)&d, 1, (uint8_t*)&r, 3);

    msDelay(1);

	if (r != 0x20ba20)
	{
	  	return false;
	}
    //printf("Flash found!\r\n");
    // Enable write
    d = FLASH_CMD_EN4B;
    pInterface->Tx(DevNo, (uint8_t*)&d, 1);

    return true;
}

int FlashRead(uint32_t Addr, uint8_t *pBuff, int BuffLen)
{
  	return g_FlashDisk.Read(Addr, pBuff, BuffLen);
}

int FlashWrite(uint32_t Addr, uint8_t *pData, int DataLen)
{
  	return g_FlashDisk.Write(Addr, pData, DataLen);
}

void FlashErase(uint32_t Block, int NbBlock)
{
	g_FlashDisk.EraseBlock(Block, NbBlock);
}

bool FlashReadId(uint8_t *pMan, uint8_t *pType, uint8_t *pDensity)
{
	uint8_t d[4];
  	uint32_t *p = (uint32_t*)d;
	
	*p = g_FlashDisk.ReadId(3);
	*pMan = d[0];
	*pType = d[1];
	*pDensity = d[2];

	return true;
}

bool FlashTest()
{
	uint8_t buff[512];
	uint8_t buff2[512];
	uint8_t tmp[512];
	uint16_t *p = (uint16_t*)buff;

	memset(tmp, 0xa5, 512);
	for (int i = 0; i < 256; i++)
	{
		p[i] = 255-i;
	}

	printf("Erasing... Please wait\r\n");

	// Ease could take a few minutes
	//g_FlashDiskIO.EraseBlock(0, 4);
	g_FlashDisk.Erase();
	printf("Writing 2KB data...\r\n");

	g_FlashDisk.SectWrite(1, buff);

	p = (uint16_t*)buff2;
	for (int i = 0; i < 256; i++)
	{
		p[i] = i;
	}
	g_FlashDisk.SectWrite(2UL, buff2);
	//g_FlashDiskIO.SectWrite(4, buff);
	//g_FlashDiskIO.SectWrite(8, buff);

	printf("Validate readback...\r\n");

	g_FlashDisk.SectRead(1, tmp);

	for (int i = 0; i < 512; i++)
	{
		if (buff[i] != tmp[i])
		{
			printf("Failed %d\r\n", i);
			break;
		}
	}
	if (memcmp(buff, tmp, 512) != 0)
	{
		return false;
	}

	return true;
}

bool FlashEnable()
{
	if (IOPinRead(BLE_P1_PORT, BLE_P1_PIN))
	{
		return false;
	}

	IOPinSet(BLE_P3_PORT, BLE_P3_PIN);

  	// Init SPI3
//	if (g_Spi3.Init(s_Spi3Cfg))
	{
		if (g_FlashDisk.Init(s_MT25QL512Cfg, &g_Spi3, g_FlashCache, s_NbFlashCache))
		{
			//FlashTest();
			return true;
		}
	}

	IOPinClear(BLE_P3_PORT, BLE_P3_PIN);

	return false;
}

void FlashDisable()
{
	IOPinClear(BLE_P3_PORT, BLE_P3_PIN);

//	g_Spi3.PowerOff();
}

