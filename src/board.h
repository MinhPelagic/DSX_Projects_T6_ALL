/**-------------------------------------------------------------------------
@file	board.h

@brief	Board specific definitions

This file contains all I/O definitions for a specific board for the DSX

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
#ifndef __BOARD_H__
#define __BOARD_H__

#include "stm32l4xx.h"
#include "coredev/i2c.h"
#include "coredev/spi.h"
#include "coredev/iopincfg.h"

// DSX board

// Buttons S11
#define BUT_BL_PORT				IOPORTG	// Port G
#define BUT_BL_PIN				0
#define BUT_BL_PINOP			0

#define BUT_BR_PORT				IOPORTG	// Port G
#define BUT_BR_PIN				3
#define BUT_BR_PINOP			0
// S2
#define BUT_TL_PORT				IOPORTG	// Port G
#define BUT_TL_PIN				1
#define BUT_TL_PINOP			0

#define BUT_TR_PORT				IOPORTG	// Port G
#define BUT_TR_PIN				2
#define BUT_TR_PINOP			0

#define BUT_INT_PRIO			3

#define BUT_PINS_MAP	{ \
	{BUT_BL_PORT, BUT_BL_PIN, BUT_BL_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{BUT_BR_PORT, BUT_BR_PIN, BUT_BR_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{BUT_TL_PORT, BUT_TL_PIN, BUT_TL_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{BUT_TR_PORT, BUT_TR_PIN, BUT_TR_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
}

#define PROD_BUT_L_PORT				IOPORTG	// Port G
#define PROD_BUT_L_PIN				0
#define PROD_BUT_L_PINOP			0

#define PROD_BUT_R_PORT				IOPORTG	// Port G
#define PROD_BUT_R_PIN				3
#define PROD_BUT_R_PINOP			0
// S2
#define PROD_BUT_M_PORT				IOPORTG	// Port G
#define PROD_BUT_M_PIN				1
#define PROD_BUT_M_PINOP			0

#define PROD_BUT_X_PORT				IOPORTG	// Port G
#define PROD_BUT_X_PIN				2
#define PROD_BUT_X_PINOP			0

#define PROD_BUT_PINS_MAP	{ \
	{PROD_BUT_L_PORT, PROD_BUT_L_PIN, PROD_BUT_L_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{PROD_BUT_R_PORT, PROD_BUT_R_PIN, PROD_BUT_R_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{PROD_BUT_M_PORT, PROD_BUT_M_PIN, PROD_BUT_M_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
	{PROD_BUT_X_PORT, PROD_BUT_X_PIN, PROD_BUT_X_PINOP, IOPINDIR_INPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
}


// Bluetooth pins
#define BLE_RST_PORT				IOPORTG	// Port G
#define BLE_RST_PIN				4
#define BLE_RST_PINOP			0

#define BLE_P1_PORT				IOPORTF	// Port F
#define BLE_P1_PIN				2
#define BLE_P1_PINOP				0

#define BLE_P2_PORT				IOPORTF	// Port F
#define BLE_P2_PIN				3
#define BLE_P2_PINOP				0

#define BLE_P3_PORT				IOPORTF	// Port F
#define BLE_P3_PIN				4
#define BLE_P3_PINOP				0

#define BLE_P4_PORT				IOPORTF	// Port F
#define BLE_P4_PIN				5
#define BLE_P4_PINOP				0

#define BLE_PINS_MAP	{ \
	{BLE_RST_PORT, BLE_RST_PIN, BLE_RST_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{BLE_P1_PORT, BLE_P1_PIN, BLE_P1_PINOP, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
	{BLE_P2_PORT, BLE_P2_PIN, BLE_P2_PINOP, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
	{BLE_P3_PORT, BLE_P3_PIN, BLE_P3_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{BLE_P4_PORT, BLE_P4_PIN, BLE_P4_PINOP, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
}
/*
#define BLEUART_DEVNO			0
#define BLEUART_RX_PORT			IOPORTG
#define BLEUART_RX_PIN			8
#define BLEUART_RX_PINOP		IOPINOP_FUNC8//0x82	// AF8
#define BLEUART_TX_PORT			IOPORTG
#define BLEUART_TX_PIN			7
#define BLEUART_TX_PINOP		IOPINOP_FUNC8//0x82	// AF8

#define BLEUART_PINS_MAP	{ \
	{BLEUART_RX_PORT, BLEUART_RX_PIN, BLEUART_RX_PINOP, IOPINDIR_INPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},\
	{BLEUART_TX_PORT, BLEUART_TX_PIN, BLEUART_TX_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL},}
*/
// LSM303
#define LSM303_INT_PRIO			3

#define LSM303_DRDY_PORT		IOPORTD	// Port D
#define LSM303_DRDY_PIN			11		// Mag Int pin
#define LSM303_DRDY_PINOP		0
#define LSM303_INT1_PORT		IOPORTD	// Port D
#define LSM303_INT1_PIN			12
#define LSM303_INT1_PINOP		0
#define LSM303_INT2_PORT		IOPORTD	// Port D
#define LSM303_INT2_PIN			13
#define LSM303_INT2_PINOP		0
#define LSM303_MCS_PORT			IOPORTD	// Port D
#define LSM303_MCS_PIN			6
#define LSM303_MCS_PINOP		0

#define CMP_EN_PORT				IOPORTE	// Port E
#define CMP_EN_PIN				6
#define CMP_EN_PINOP			0

#define LSM303_PINS_MAP	{\
	{LSM303_DRDY_PORT, LSM303_DRDY_PIN, LSM303_DRDY_PINOP, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
	{LSM303_INT1_PORT, LSM303_INT1_PIN, LSM303_INT1_PIN, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
	{LSM303_INT2_PORT, LSM303_INT2_PIN, LSM303_INT2_PIN, IOPINDIR_INPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \
	{LSM303_MCS_PORT, LSM303_MCS_PIN, LSM303_MCS_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL}, \
}
//	{CMP_EN_PORT, CMP_EN_PIN, CMP_EN_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL}, \

#define PULSE_RCV_DEV_PORT			IOPORTB	// Port B
#define PULSE_RCV_DEV_PIN			11
#define PULSE_RCV_DEV_PINOP			0//0x12

#define PULSE_RCVEN_DEV_PORT		IOPORTG	// Port G
#define PULSE_RCVEN_DEV_PIN			11
#define PULSE_RCVEN_DEV_PINOP		0

#define PULSE_DESENS_DEV_PORT		IOPORTG	// Port G
#define PULSE_DESENS_DEV_PIN		12
#define PULSE_DESENS_DEV_PINOP		0

#define PULSE_RCV_DEV_PIN_MAP { \
	{PULSE_RCVEN_DEV_PORT, PULSE_RCVEN_DEV_PIN, PULSE_RCVEN_DEV_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{PULSE_RCV_DEV_PORT, PULSE_RCV_DEV_PIN, PULSE_RCV_DEV_PINOP, IOPINDIR_INPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{PULSE_DESENS_DEV_PORT, PULSE_DESENS_DEV_PIN, PULSE_DESENS_DEV_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
}

#define PULSE_RCV_PORT			IOPORTG
#define PULSE_RCV_PIN			11
#define PULSE_RCV_PINOP			0//0x12

#define PULSE_RCVEN_PORT		IOPORTG
#define PULSE_RCVEN_PIN			10
#define PULSE_RCVEN_PINOP		0

#define PULSE_DESENS_PORT		IOPORTF	// Port F
#define PULSE_DESENS_PIN		5
#define PULSE_DESENS_PINOP		0


#define PULSE_RCV_PIN_MAP { \
	{PULSE_RCVEN_PORT, PULSE_RCVEN_PIN, PULSE_RCVEN_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{PULSE_RCV_PORT, PULSE_RCV_PIN, PULSE_RCV_PINOP, IOPINDIR_INPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
	{PULSE_DESENS_PORT, PULSE_DESENS_PIN, PULSE_DESENS_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
}

#if 0

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

// misc pins
#define USB_SEL_PORT			IOPORTC
#define USB_SEL_PIN				3
#define USB_SEL_PINOP			0
#define USB_CHARGING_PORT		IOPORTA
#define USB_CHARGING_PIN		0
#define USB_CHARGING_PINOP		0

#define BOARD_DETECT_PORT       IOPORTH
#define BOARD_DETECT_PIN        13
#define BOARD_DETECT_PINOP      0

// LCD Hw Defines
#define LCD_BKL_PORT					IOPORTC
#define LCD_BKL_PIN        				13
#define LCD_BKL_PINOP      				0

#define LCD_DPVCC_PORT                  IOPORTG
#define LCD_DPVCC_PIN                   15
#define LCD_DPVCC_PINOP                 0
#define LCD_RST_PORT                    IOPORTE
#define LCD_RST_PIN                     2
#define LCD_RST_PINOP                   0
#define LCD_IM0_PORT                    IOPORTE
#define LCD_IM0_PIN                     0
#define LCD_IM0_PINOP                   0
#define LCD_IM3_PORT                    IOPORTE
#define LCD_IM3_PIN                     1
#define LCD_IM3_PINOP                   0
#define LCD_CS_PORT                     IOPORTD
#define LCD_CS_PIN                      7
#define LCD_CS_PINOP                    IOPINOP_FUNC12
#define LCD_WE_PORT                     IOPORTD
#define LCD_WE_PIN                      5
#define LCD_WE_PINOP                    IOPINOP_FUNC12
#define LCD_OE_PORT                     IOPORTD
#define LCD_OE_PIN                      4
#define LCD_OE_PINOP                    IOPINOP_FUNC12
#define LCD_RS_PORT                     IOPORTE
#define LCD_RS_PIN                      3
#define LCD_RS_PINOP                    IOPINOP_FUNC12
#define LCD_D0_PORT                     IOPORTD
#define LCD_D0_PIN                      14
#define LCD_D0_PINOP                    IOPINOP_FUNC12
#define LCD_D1_PORT                     IOPORTD
#define LCD_D1_PIN                      15
#define LCD_D1_PINOP                    IOPINOP_FUNC12
#define LCD_D2_PORT                     IOPORTD
#define LCD_D2_PIN                      0
#define LCD_D2_PINOP                    IOPINOP_FUNC12
#define LCD_D3_PORT                     IOPORTD
#define LCD_D3_PIN                      1
#define LCD_D3_PINOP                    IOPINOP_FUNC12
#define LCD_D4_PORT                     IOPORTE
#define LCD_D4_PIN                      7
#define LCD_D4_PINOP                    IOPINOP_FUNC12
#define LCD_D5_PORT                     IOPORTE
#define LCD_D5_PIN                      8
#define LCD_D5_PINOP                    IOPINOP_FUNC12
#define LCD_D6_PORT                     IOPORTE
#define LCD_D6_PIN                      9
#define LCD_D6_PINOP                    IOPINOP_FUNC12
#define LCD_D7_PORT                     IOPORTE
#define LCD_D7_PIN                      10
#define LCD_D7_PINOP                    IOPINOP_FUNC12
#define LCD_D8_PORT                     IOPORTE
#define LCD_D8_PIN                      11
#define LCD_D8_PINOP                    IOPINOP_FUNC12
#define LCD_D9_PORT                     IOPORTE
#define LCD_D9_PIN                      12
#define LCD_D9_PINOP                    IOPINOP_FUNC12
#define LCD_D10_PORT                    IOPORTE
#define LCD_D10_PIN                     13
#define LCD_D10_PINOP                   IOPINOP_FUNC12
#define LCD_D11_PORT                    IOPORTE
#define LCD_D11_PIN                     14
#define LCD_D11_PINOP                   IOPINOP_FUNC12
#define LCD_D12_PORT                    IOPORTE
#define LCD_D12_PIN                     15
#define LCD_D12_PINOP                   IOPINOP_FUNC12
#define LCD_D13_PORT                    IOPORTD
#define LCD_D13_PIN                     8
#define LCD_D13_PINOP                   IOPINOP_FUNC12
#define LCD_D14_PORT                    IOPORTD
#define LCD_D14_PIN                     9
#define LCD_D14_PINOP                   IOPINOP_FUNC12
#define LCD_D15_PORT                    IOPORTD
#define LCD_D15_PIN                     10
#define LCD_D15_PINOP                   IOPINOP_FUNC12

#define LCD_PINS_MAP	{ \
    {LCD_BKL_PORT, LCD_BKL_PIN, LCD_BKL_PINOP, IOPINDIR_OUTPUT, IOPINRES_NONE, IOPINTYPE_NORMAL}, \
    {LCD_DPVCC_PORT, LCD_DPVCC_PIN, LCD_DPVCC_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_RST_PORT, LCD_RST_PIN, LCD_RST_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_IM0_PORT, LCD_IM0_PIN, LCD_IM0_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL},\
    {LCD_IM3_PORT, LCD_IM3_PIN, LCD_IM3_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLDOWN, IOPINTYPE_NORMAL},\
    {LCD_CS_PORT, LCD_CS_PIN, LCD_CS_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_WE_PORT, LCD_WE_PIN, LCD_WE_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_OE_PORT, LCD_OE_PIN, LCD_OE_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D0_PORT, LCD_D0_PIN, LCD_D0_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D1_PORT, LCD_D1_PIN, LCD_D1_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D2_PORT, LCD_D2_PIN, LCD_D2_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D3_PORT, LCD_D3_PIN, LCD_D3_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_RS_PORT, LCD_RS_PIN, LCD_RS_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D4_PORT, LCD_D4_PIN, LCD_D4_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D5_PORT, LCD_D5_PIN, LCD_D5_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D6_PORT, LCD_D6_PIN, LCD_D6_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D7_PORT, LCD_D7_PIN, LCD_D7_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D8_PORT, LCD_D8_PIN, LCD_D8_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D9_PORT, LCD_D9_PIN, LCD_D9_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D10_PORT, LCD_D10_PIN, LCD_D10_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D11_PORT, LCD_D11_PIN, LCD_D11_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D12_PORT, LCD_D12_PIN, LCD_D12_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D13_PORT, LCD_D13_PIN, LCD_D13_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D14_PORT, LCD_D14_PIN, LCD_D14_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
    {LCD_D15_PORT, LCD_D15_PIN, LCD_D15_PINOP, IOPINDIR_OUTPUT, IOPINRES_PULLUP, IOPINTYPE_NORMAL},\
}
#endif

#ifdef __cplusplus

/// Get I2C device instance
/// @param	DevNo : Physical Device Number (1 = I2C1, 2 = I2C2, ...)
I2C *GetI2c(int DevNo);

/// Get SPI device instance
SPI *GetSpi();

extern "C" {
#endif // __cplusplus

void BoardInit();
void ButIntHandler(int IntNo, void *pCtx);
bool LSM303IntHandler(void);

/// Get I2C device data (handle) to use in C only code
/// @param	DevNo : Physical Device Number (1 = I2C1, 2 = I2C2, ...)
DevIntrf_t *GetI2cDev(int DevNo);

/// Get SPI device data (handle) to use in C only code
DevIntrf_t *GetSpiDev();
bool SpiInit();
void SpiPowerOff();
  
#ifdef __cplusplus
}
#endif // __cplusplus
  
#endif // __BOARD_H__

