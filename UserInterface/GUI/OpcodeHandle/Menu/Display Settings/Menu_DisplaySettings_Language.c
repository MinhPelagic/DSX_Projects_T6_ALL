/******************************************************************************/
//File: Language
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_DISPLAY_LANGUAGE_SET(void)
{
    GUI_Clear();
    /*Clear all the previous content*/
    /*Display sub title text */
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_LANGUAGE));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_Language_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DISPLAY_LANGUAGE_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Language_Ctx);
}
