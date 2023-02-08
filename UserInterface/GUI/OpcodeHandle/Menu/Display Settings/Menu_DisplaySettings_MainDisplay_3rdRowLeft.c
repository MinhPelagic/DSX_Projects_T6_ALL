/******************************************************************************/
//File: GTR left and right
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_MAINDISPLAY_LEFT_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_3rd_ROW_LEFT));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_MainDisp_3rdRowLeft_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_MAINDISPLAY_LEFT_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_MainDisp_3rdRowLeft_Ctx);
}