/******************************************************************************/
//File: GTR left and right
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_MAINDISPLAY_GFBG_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text YEAR*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_GFBG_OR_N2_BAR));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_MainDisp_GFBGorN2bar_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_MAINDISPLAY_GFBG_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_MainDisp_GFBGorN2bar_Ctx);
}