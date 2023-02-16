/******************************************************************************/
//File: Device settings -> Units
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"
/*Downloading Text*/
static void DownloadingText_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DOWNLOADING));
}
static const contentDispContext_st DownloadingText =
{
    &DownloadingText_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_Bluetooth_DownLoadData_01,
};
/*Data Text*/
static void DataText_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DATA));
}
static const contentDispContext_st DataText =
{
    &DataText_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_Bluetooth_DownLoadData_02,
};
/**
 * @brief
 *
 */
void IniOrClrScrFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA(void)
{
    /*Clear all the screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    /*Bluetooth icon*/
    DispBleMainIcon();
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, DownloadingText);
    HandleDisplayTextWithMemdev(IteStat_Select, DataText);
}
void UpdOrFlasFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DownloadingText);
    HandleDisplayTextWithMemdev(IteStat_Flashing, DataText);
}
