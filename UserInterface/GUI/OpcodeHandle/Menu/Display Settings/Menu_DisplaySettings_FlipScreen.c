/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_DISPLAY_FLIPSCREEN_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_FLIP_SCREEN));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_FlipScreen_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DISPLAY_FLIPSCREEN_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DispSett_FlipScreen_Ctx);
}