/*******************************************************************************
 * @file        : Slates.c
 * @brief       : Middleware for Slates Readback and Display
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2021-2021.
 * Author: YeuShyr Wu and Duc Thinh Nguyen - Pelagic Pressure Systems, Aqualung
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
#include "L4X9_includes.h"

#ifdef _SLATES_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/******************************************************************************
 * @brief   Handle Ecompass.
 *
 * @note    
 ******************************************************************************/

bool ReadAndDisplaySlates(uint8_t Idx)
{

  uint32_t SlateAddr;
  // char pStrRet[LangMaxLength];
  bool Status = false;
  uint16_t SlateData[SLATE_PIXEL_SIZE];
  int8_t retry;
  
  GUI_BITMAP slate1 =
      {
          SLATE_W,                    // xSize
          SLATE_H,                    // ySize
          SLATE_H * (2U),             // BytesPerLine
          16,                         // BitsPerPixel
          (unsigned char *)SlateData, // Pointer to picture data
          NULL,                       // Pointer to palette
          GUI_DRAW_BMP565};
  /*Slate ID of address*/
  SlateAddr = SLATE_ADDR_HEAD + (SLATE_ADDR_GAP * (Idx - 1));

  /* PowerOn External Flash */
  L4X9_QSPI_Init();
  MT25QL512ABB_PowerDownRelease();

  retry = NVD_FLASH_READ_TIMEOUT;    
  do{} while((MT25QL512ABB_Read1I1O(SlateAddr, SLATE_DATA_SIZE, SlateData) != true) && (retry-- > 0));		// Timeout added from R1006     
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }

  /* PowerDown External Flash */
  while (MT25QL512ABB_PowerDownEnter() != true)
  {
  };
  L4X9_QSPI_DeInit();

  GUI_DrawBitmap(&slate1, 0, 26);
  return Status;
}

#endif