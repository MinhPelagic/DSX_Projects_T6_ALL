/******************************************************************************/
//File: Device settings -> Water type
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"

void IniOrClrScrFunc_DEVICE_WATERTYPE_SET(void)
{
    /*Clear the list of previous content*/
    ClearUnusedInList(0);
    /*Sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_WATER_TYPE));
    /*Display water type set*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_WaterType_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DEVICE_WATERTYPE_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_WaterType_Ctx);
}