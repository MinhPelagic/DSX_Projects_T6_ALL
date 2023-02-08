/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_EXTRA_LARGE));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_Extralarge_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_MAINDISPLAY_EXTRALARGE_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Extralarge_Ctx);
}

