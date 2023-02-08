/*******************************************************************************
 * @file        : LCD_COM24H2P39ULC.h
 * @brief       : Low Level Driver for COM24H2P39ULC Blanview TFT-LCD
 *                Display.
 *                Display Controller is Himax HX8347-A01.
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The COM24H2P39ULC is build on the FMC module.
 *
 ******************************************************************************/

#ifndef _LCD_COM24H2P39ULC_
#define _LCD_COM24H2P39ULC_

/* Physical display size */
#define XSIZE_PHYS  240
#define YSIZE_PHYS  320

/*******************************************************************************
 * @brief   Structures
 ******************************************************************************/
typedef struct
{
  __IO uint16_t REG;
  __IO uint16_t RAM;
} LCD_CONTROLLER_TypeDef;

#define FMC_BANK1_BASE  ((uint32_t)(0x60000000 | 0x00000000))
#define FMC_LCD_BASE    ((uint32_t)(0x60000000 | 0x00100000)) // 0x00100000
#define FMC_BANK1_ADDR  ((LCD_CONTROLLER_TypeDef *) FMC_BANK1_BASE)
#define LCD_ADDR        ((LCD_CONTROLLER_TypeDef *) FMC_LCD_BASE)

/******************************************************************************
 * @brief   Write LCD Controller Register
 *
 * @note
 ******************************************************************************/
void LCD_WriteReg(uint16_t Reg);

/******************************************************************************
 * @brief   Write LCD Data on internal GRAM
 *
 * @note
 ******************************************************************************/
void LCD_WriteData(uint16_t Data);

void LCD_WriteDataMultiple(uint8_t *pData, uint32_t Size) ;

/******************************************************************************
 * @brief   Read LCD Data on internal GRAM
 *
 * @note
 ******************************************************************************/
uint16_t LCD_ReadData(void);

/******************************************************************************
 * @brief   Initlialize LCD Controller
 *
 * @note
 ******************************************************************************/
void LCD_Init (void);
   
/******************************************************************************
 * @brief   DeInitlialize LCD Controller
 *
 * @note
 ******************************************************************************/
void LCD_DeInit(void);

#endif // _LCD_COM24H2P39ULC_