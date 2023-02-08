/******************************************************************************/
//File: Titile color
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_DISPLAY_TITLESCOLOR_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TITLES_COLOR));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_TittleColor_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DISPLAY_TITLESCOLOR_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_TittleColor_Ctx);
}
