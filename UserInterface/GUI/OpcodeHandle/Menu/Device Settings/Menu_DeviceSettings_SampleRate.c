/******************************************************************************/
//File: Device settings -> Sample rate
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"

void IniOrClrScrFunc_DEVICE_SAMPLERATE_SET(void)
{
    /*Clear the list of previous content*/
    ClearUnusedInList(0);
    /*Sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SAMPLE_RATE));
    /*Display SEC*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_SampleRate_Unit_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_SampleRate_Value_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DEVICE_SAMPLERATE_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_SampleRate_Value_Ctx);
}