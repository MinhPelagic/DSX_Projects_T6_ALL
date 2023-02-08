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

void IniOrClrScrFunc_WELCOMESCREEN_SET(void)
{
    /*Clear the list of previous content*/
    ClearUnusedInList(0);
    /*Sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_WELCOME_SCREEN));
    /*Display set*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_WelcomeScr_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_WELCOMESCREEN_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_WelcomeScr_Ctx);
}