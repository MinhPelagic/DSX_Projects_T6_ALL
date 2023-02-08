/**-------------------------------------------------------------------------
@file	emWin_com24h2p39ulc.c

@brief	COM24H2P39ULC LCD display driver for emWin

@author	Hoang Nguyen Hoan
@date	May 17, 2021

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

#include "idelay.h"
#include "iopinctrl.h"

#include "stm32l4xx.h"
#include "stm32l4xx_hal_rcc.h"
#include "stm32l4xx_ll_fmc.h"
#include "stm32l4xx_hal_dma.h"
#include "stm32l4xx_hal_sram.h"
#include "GUI.h"
#include "GUIDRV_FlexColor.h"

#include "emWin_com24h2p39ulc.h"

#include "board.h"

#define ES_DETECT_DELAY         150
#define ES_DETECT_TIME          350

#define ES_CHIP_ADDRESS         0x72
#define ES_CHIP_LEVELS          31
#define ES_T_START              50
#define ES_T_EOS                50

#define ES_L0_HT                50
#define ES_L0_LT                (2*ES_L0_HT)

#define ES_L1_LT                50
#define ES_L1_HT                (2*ES_L1_LT)

typedef struct
{
	__IO uint16_t REG;
	__IO uint16_t RAM;
} LCD_CONTROLLER_TypeDef;

#define FMC_BANK1_BASE  ((uint32_t)(0x60000000 | 0x00000000))
#define FMC_LCD_BASE    ((uint32_t)(0x60000000 | 0x00100000)) // 0x00100000
#define FMC_BANK1_ADDR  ((LCD_CONTROLLER_TypeDef *) FMC_BANK1_BASE)
#define LCD_ADDR        ((LCD_CONTROLLER_TypeDef *) FMC_LCD_BASE)


static const IOPinCfg_t s_LcdPins[] = LCD_PINS_MAP;
static const int s_NbLcdPins = sizeof(s_LcdPins) / sizeof(IOPinCfg_t);

void lcd_com24h2p39ulc_essend(uint8_t data)
{
    /* Assert ES Program Start */
    IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
    usDelay(ES_T_START);

    for (uint8_t a = 0; a<8; a++)
    {
        if((data<<a) & 0x80)
        {
			IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
			usDelay(ES_L1_LT);
			IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
			usDelay(ES_L1_HT);
        }
        else
        {
			IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
			usDelay(ES_L0_LT);
			IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
			usDelay(ES_L0_HT);
        }
    }

	/* Assert ES Program End */
	IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
	usDelay(ES_T_EOS);
	IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
}


void lcd_com24h2p39ulc_backlight_set(int Level)
{
	uint16_t ChipLev = 0;

	if (Level >= 100)
	{
		Level = 100;
		ChipLev = (uint16_t)ES_CHIP_LEVELS;
	}
	else if(Level <= 0)
	{
		ChipLev = 0;
	}
	else
	{
		ChipLev = (100*(uint16_t)Level) / (10000 / ES_CHIP_LEVELS) + 1;
	}

	if(ChipLev == 0)
	{
		IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
	}
	else
	{
		// Start One-Wire Setup Procedure
		IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
		usDelay(ES_DETECT_DELAY);

		IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
		usDelay(ES_DETECT_TIME);

		IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);

		// Wait ES Mode Time Window expires
		usDelay(800);

		lcd_com24h2p39ulc_essend(ES_CHIP_ADDRESS);
		lcd_com24h2p39ulc_essend(ChipLev);
	}
}


void lcd_com24h2p39ulc_backlight_init()
{
	IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);

	// Start One-Wire Setup Procedure
	IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);
	usDelay(ES_DETECT_DELAY);

	IOPinClear(LCD_BKL_PORT, LCD_BKL_PIN);
	usDelay(ES_DETECT_TIME);

	IOPinSet(LCD_BKL_PORT, LCD_BKL_PIN);

	// Wait ES Mode Time Window expires
	usDelay(800);
}

void lcd_com24h2p39ulc_writereg(uint16_t Reg, uint16_t Val)
{
	FMC_BANK1_ADDR->REG = Reg;
	LCD_ADDR->REG = Val;
}

void lcd_com24h2p39ulc_init(void)
{
	// Enable FMC clock
	__HAL_RCC_FMC_CLK_ENABLE();

	IOPinCfg(s_LcdPins, s_NbLcdPins);

	IOPinSet(LCD_DPVCC_PORT, LCD_DPVCC_PIN);

	// *** This delay is extremely important for the LCD to work
	// *** DO NOT CHANGE
	msDelay(5);

	IOPinSet(LCD_RST_PORT, LCD_RST_PIN);
	IOPinClear(LCD_IM0_PORT, LCD_IM0_PIN);
	IOPinClear(LCD_IM3_PORT, LCD_IM3_PIN);

	// Init baclight
	lcd_com24h2p39ulc_backlight_init();
	lcd_com24h2p39ulc_backlight_set(0);


	__HAL_RCC_FMC_FORCE_RESET();
	__HAL_RCC_FMC_RELEASE_RESET();

	FMC_NORSRAM_TimingTypeDef Timing;
	SRAM_HandleTypeDef LCD_FMC;

	LCD_FMC.Instance                      = FMC_NORSRAM_DEVICE;
	LCD_FMC.Extended                      = FMC_NORSRAM_EXTENDED_DEVICE;
	LCD_FMC.Init.NSBank                   = FMC_NORSRAM_BANK1;
	LCD_FMC.Init.DataAddressMux           = FMC_DATA_ADDRESS_MUX_DISABLE;
	LCD_FMC.Init.MemoryType               = FMC_MEMORY_TYPE_SRAM;
	LCD_FMC.Init.MemoryDataWidth          = FMC_NORSRAM_MEM_BUS_WIDTH_16;
	LCD_FMC.Init.BurstAccessMode          = FMC_BURST_ACCESS_MODE_DISABLE;
	LCD_FMC.Init.WaitSignalPolarity       = FMC_WAIT_SIGNAL_POLARITY_LOW;
	LCD_FMC.Init.WaitSignalActive         = FMC_WAIT_TIMING_BEFORE_WS;
	LCD_FMC.Init.WriteOperation           = FMC_WRITE_OPERATION_ENABLE;
	LCD_FMC.Init.ExtendedMode             = FMC_EXTENDED_MODE_DISABLE;
	LCD_FMC.Init.AsynchronousWait         = FMC_ASYNCHRONOUS_WAIT_DISABLE;
	LCD_FMC.Init.WriteBurst               = FMC_WRITE_BURST_DISABLE;
	LCD_FMC.Init.ContinuousClock          = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	LCD_FMC.Init.WriteFifo                = FMC_WRITE_FIFO_ENABLE;
	LCD_FMC.Init.NBLSetupTime             = 0;
	LCD_FMC.Init.PageSize                 = FMC_PAGE_SIZE_NONE;

	Timing.AddressSetupTime       = 2;//15;
	Timing.AddressHoldTime        = 2;//15;
	Timing.DataSetupTime          = 2;//255;
	Timing.DataHoldTime           = 0;
	Timing.BusTurnAroundDuration  = 2;//15;
	Timing.CLKDivision            = 4;//16;
	Timing.DataLatency            = 2;//17;
	Timing.AccessMode             = FMC_ACCESS_MODE_A;

	while (HAL_SRAM_Init(&LCD_FMC, &Timing, NULL) != HAL_OK) {};


	// Initialization sequence based on datasheet recommendations

	IOPinSet(LCD_RST_PORT, LCD_RST_PIN);
	msDelay(2);
	IOPinClear(LCD_RST_PORT, LCD_RST_PIN);
	msDelay(1);
	IOPinSet(LCD_RST_PORT, LCD_RST_PIN);
	msDelay(120);

	lcd_com24h2p39ulc_writereg(0x0096, 0x0001);  // TEST 1

	lcd_com24h2p39ulc_writereg(0x0019, 0x0087);  // OSC CONTROL 1

	msDelay(10);

	/* Display OFF Settings */
	lcd_com24h2p39ulc_writereg(0x0026, 0x0080);  // DISPLAY OFF

	lcd_com24h2p39ulc_writereg(0x001B, 0x000C);  // POWER CONTROL 1

	lcd_com24h2p39ulc_writereg(0x0043, 0x0000);  // VCOM CONTROL 1

	/* Power Supply Setting Initializing */
	lcd_com24h2p39ulc_writereg(0x0020, 0x0000);  // POWER CONTROL 6

	lcd_com24h2p39ulc_writereg(0x001F, 0x0007);  // POWER CONTROL 5

	lcd_com24h2p39ulc_writereg(0x0044, 0x007F);  // VCOM CONTROL 2

	lcd_com24h2p39ulc_writereg(0x0045, 0x0014);  // VCOM CONTROL 3

	lcd_com24h2p39ulc_writereg(0x001D, 0x0005);  // POWER CONTROL 3

	lcd_com24h2p39ulc_writereg(0x001E, 0x0000);  // POWER CONTROL 4

	/* Power Supply Operation start setting */
	lcd_com24h2p39ulc_writereg(0x001C, 0x0004);  // POWER CONTROL 2

	lcd_com24h2p39ulc_writereg(0x001B, 0x0014);  // POWER CONTROL 1

	msDelay(40);

	lcd_com24h2p39ulc_writereg(0x0043, 0x0080);  // VCOM CONTROL 1

	/* Power Control Setting */
	lcd_com24h2p39ulc_writereg(0x0042, 0x0008);  // BGP CONTROL

	lcd_com24h2p39ulc_writereg(0x0023, 0x0095);  // CYCLE CONTROL 1

	lcd_com24h2p39ulc_writereg(0x0024, 0x0095);  // CYCLE CONTROL 2

	lcd_com24h2p39ulc_writereg(0x0025, 0x00FF);  // CYCLE CONTROL 3

	lcd_com24h2p39ulc_writereg(0x0021, 0x0010);  // POWER CONTROL 7

	lcd_com24h2p39ulc_writereg(0x002B, 0x0000);  // POWER CONTROL 11

	lcd_com24h2p39ulc_writereg(0x0095, 0x0001);  // DCCLK SYNC TO CL1

	/* OSC Control Setting */
	lcd_com24h2p39ulc_writereg(0x001A, 0x0000);  // OSC CONTROL 2

	lcd_com24h2p39ulc_writereg(0x0093, 0x000F);  // OSC CONTROL 3

	lcd_com24h2p39ulc_writereg(0x0070, 0x0066);  // INTERNAL USE 28

	lcd_com24h2p39ulc_writereg(0x0018, 0x0001);  // GATE SCAN CONTROL

	/* RGB Interface control Setting */
	lcd_com24h2p39ulc_writereg(0x0038, 0x0000);  // RGB INTERFACE CONTROL 1

	lcd_com24h2p39ulc_writereg(0x0039, 0x0000);  // RGB INTERFACE CONTROL 2

	/* Display control Setting */
	lcd_com24h2p39ulc_writereg(0x0027, 0x0002);  // DISPLAY CONTROL 2

	lcd_com24h2p39ulc_writereg(0x0028, 0x0003);  // DISPLAY CONTROL 3

	lcd_com24h2p39ulc_writereg(0x0029, 0x0008);  // DISPLAY CONTROL 4

	lcd_com24h2p39ulc_writereg(0x002A, 0x0008);  // DISPLAY CONTROL 5

	lcd_com24h2p39ulc_writereg(0x002C, 0x0008);  // DISPLAY CONTROL 6

	lcd_com24h2p39ulc_writereg(0x002D, 0x0008);  // DISPLAY CONTROL 7

	lcd_com24h2p39ulc_writereg(0x0035, 0x0009);  // DISPLAY CONTROL 9

	lcd_com24h2p39ulc_writereg(0x0036, 0x0009);  // DISPLAY CONTROL 10

	lcd_com24h2p39ulc_writereg(0x0091, 0x0014);  // DISPLAY CONTROL 11

	lcd_com24h2p39ulc_writereg(0x0037, 0x0000);  // DISPLAY CONTROL 12

	lcd_com24h2p39ulc_writereg(0x0001, 0x0002);  // DISPLAY MODE CONTROL

	lcd_com24h2p39ulc_writereg(0x003A, 0x00A1);  // CYCLE CONTROL 1

	lcd_com24h2p39ulc_writereg(0x003B, 0x00A1);  // CYCLE CONTROL 2

	lcd_com24h2p39ulc_writereg(0x003C, 0x00A0);  // CYCLE CONTROL 3

	lcd_com24h2p39ulc_writereg(0x003D, 0x0000);  // CYCLE CONTROL 4

	lcd_com24h2p39ulc_writereg(0x003E, 0x002D);  // CYCLE CONTROL 5

	lcd_com24h2p39ulc_writereg(0x0040, 0x0003);  // CYCLE CONTROL 6

	lcd_com24h2p39ulc_writereg(0x0041, 0x00CC);  // CYCLE CONTROL 7

	/* Partial Immage Display Setting */
	lcd_com24h2p39ulc_writereg(0x000A, 0x0000);  // PARTIAL AREA START ROW 2

	lcd_com24h2p39ulc_writereg(0x000B, 0x0000);  // PARTIAL AREA START ROW 1

	lcd_com24h2p39ulc_writereg(0x000C, 0x0001);  // PARTIAL AREA END ROW 2

	lcd_com24h2p39ulc_writereg(0x000D, 0x003F);  // PARTIAL AREA END ROW 1

	/* Vertical Scroll Settings */
	lcd_com24h2p39ulc_writereg(0x000E, 0x0000);

	lcd_com24h2p39ulc_writereg(0x000F, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0010, 0x0001);

	lcd_com24h2p39ulc_writereg(0x0011, 0x0040);

	lcd_com24h2p39ulc_writereg(0x0012, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0013, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0014, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0015, 0x0000);

	/* Window Address Setting */
	lcd_com24h2p39ulc_writereg(0x0002, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0003, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0004, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0005, 0x00EF);

	lcd_com24h2p39ulc_writereg(0x0006, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0007, 0x0000);

	lcd_com24h2p39ulc_writereg(0x0008, 0x0001);

	lcd_com24h2p39ulc_writereg(0x0009, 0x003F);

	lcd_com24h2p39ulc_writereg(0x0016, 0x0008);

	lcd_com24h2p39ulc_writereg(0x0072, 0x0000);

	msDelay(60);

	/* Display On setting */
	lcd_com24h2p39ulc_writereg(0x0094, 0x000A); // SAP IDLE MODE

	lcd_com24h2p39ulc_writereg(0x0090, 0x007F); // DISPLAY CONTROL 8

	lcd_com24h2p39ulc_writereg(0x0026, 0x0084); // DISPLAY CONTROL 1

	msDelay(40);

	lcd_com24h2p39ulc_writereg(0x0026, 0x00A4); // DISPLAY CONTROL 1

	lcd_com24h2p39ulc_writereg(0x0026, 0x00AC); // DISPLAY CONTROL 1

	msDelay(40);

	lcd_com24h2p39ulc_writereg(0x0026, 0x00BC); // DISPLAY CONTROL 1

	lcd_com24h2p39ulc_writereg(0x0096, 0x0000); // TEST 1
}

void lcd_com24h2p39ulc_poweroff(void)
{
	lcd_com24h2p39ulc_backlight_set(0);
	IOPinClear(LCD_DPVCC_PORT, LCD_DPVCC_PIN);
	
	/* USER CODE BEGIN FMC_MspInit 1 */
	__HAL_RCC_FMC_FORCE_RESET();
	__HAL_RCC_FMC_RELEASE_RESET();

	/* Peripheral clock enable */
	__HAL_RCC_FMC_CLK_DISABLE();

	IOPinDis(s_LcdPins, s_NbLcdPins);
}

void LcdWriteReg(uint16_t Reg)
{
	FMC_BANK1_ADDR->REG = Reg;
}

void LcdWriteData(uint16_t Data)
{
	LCD_ADDR->REG = Data;
}

void LcdWriteDataMultiple(uint16_t *pData, int Len)
{
	while (Len > 0)
	{
		LCD_ADDR->REG = *pData;
		pData++;
		Len--;
	}
}

void LcdReadDataMultiple(uint16_t *pData, int Len)
{
	while (Len > 0)
	{
		*pData = LCD_ADDR->REG;
		pData++;
		Len--;
	}
}

/*********************************************************************
*
*       LCD_X_Config
*
* Function description:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*
*/
void LCD_X_Config(void)
{
	GUI_DEVICE *pDevice;
	CONFIG_FLEXCOLOR Config = {0};
	GUI_PORT_API PortAPI = {0};

	/* Set display driver and color conversion */
	pDevice = GUI_DEVICE_CreateAndLink(GUIDRV_FLEXCOLOR, GUICC_565, 0, 0);

	/* Display driver configuration, required for Lin-driver */
	LCD_SetSizeEx(0, COM24H2P39ULC_XSIZE_PHYS, COM24H2P39ULC_YSIZE_PHYS);
	LCD_SetVSizeEx(0, COM24H2P39ULC_XSIZE_PHYS, COM24H2P39ULC_YSIZE_PHYS);
	Config.Orientation = GUI_ROTATION_CCW;
	GUIDRV_FlexColor_Config(pDevice, &Config);

	/* Set controller and operation mode */
	PortAPI.pfWrite16_A0 = LcdWriteReg;
	PortAPI.pfWrite16_A1 = LcdWriteData;
	PortAPI.pfWriteM16_A1 = LcdWriteDataMultiple;
	PortAPI.pfReadM16_A1 = LcdReadDataMultiple;
	GUIDRV_FlexColor_SetFunc(pDevice, &PortAPI, GUIDRV_FLEXCOLOR_F66712, GUIDRV_FLEXCOLOR_M16C0B16);
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Function description:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void *pData)
{
	int r;
	(void)LayerIndex;
	(void)pData;

	switch (Cmd)
	{
		case LCD_X_INITCONTROLLER:
		{
			return 0;
		}
		default:
			r = -1;
	}
	return r;
}

