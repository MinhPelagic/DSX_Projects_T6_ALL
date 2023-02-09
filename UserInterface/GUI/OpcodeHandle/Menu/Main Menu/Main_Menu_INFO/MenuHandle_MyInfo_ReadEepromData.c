/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"
#include "MenuHandle_MyInfo_ReadEepromData.h"

void DisplayBmpFromEEPROM(bmpInforToDisplay_ts datInfo)
{
    // bool status_b = false;
    /*Get the information*/
    int bmpWidth    = datInfo.width;
    int bmpHeight   = datInfo.height;
    int bmpSize     = 2U * bmpWidth * bmpHeight; //2 bytes per lines
    /*BMP file Data buffer */
    //unsigned char *pDataOfBmp = (unsigned char*)malloc(bmpSize * sizeof(unsigned char));
    unsigned char pDataOfBmp[320*240*2];
    int8_t retry;
    /*Validate if enough buffer to get data*/
    // if(pDataOfBmp!=NULL)
    // {
    GUI_BITMAP bmpDataToDisplay =
    {
        bmpWidth,                       // xSize
        bmpHeight,                      // ySize
        bmpHeight * (2U),               // BytesPerLine
        16,                             // BitsPerPixel
        (unsigned char *)pDataOfBmp,    // Pointer to picture data
        NULL,                           // Pointer to palette
        GUI_DRAW_BMP565
    };
    /* PowerOn External Flash */
    L4X9_QSPI_Init();
    MT25QL512ABB_PowerDownRelease();

    retry = NVD_FLASH_READ_TIMEOUT;
    do {} while((MT25QL512ABB_Read1I1O(datInfo.address, bmpSize, pDataOfBmp) != true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    /* PowerDown External Flash */
    while (MT25QL512ABB_PowerDownEnter() != true) {};
    L4X9_QSPI_DeInit();
    /*Display the bitmap file*/
    GUI_DrawBitmap(&bmpDataToDisplay, datInfo.x0, datInfo.y0);
    /*Set status success*/
    // status_b = true;
    // }
    // else
    // {
    //     /*Do nothing -> Not enough memory to allocate*/
    // }
    /*Free memory*/
    // free(pDataOfBmp);
    /*Return the status*/
    // return status_b;
}




