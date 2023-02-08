/******************************************************************************/
//File: GTR for LEFT AND RIGHT
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_S373_DISPLAY_GTR_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text */
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_GTR_FOR_LR));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_GTRLeftRight_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S373_DISPLAY_GTR_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DispSett_GTRLeftRight_Ctx);
}
