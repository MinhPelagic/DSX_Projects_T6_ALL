/******************************************************************************/
//File: Brightness.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_DISPLAY_BRIGHTNESS_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_BRIGHTNESS));
    DisplayBrightnessSettings(IteStat_Select);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DISPLAY_BRIGHTNESS_SET(void)
{
    DisplayBrightnessSettings(IteStat_Flashing);
}