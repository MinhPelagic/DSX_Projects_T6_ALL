/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveMenu_SetGFHigh.h"

void IniOrClrScrFunc_DIVEMENU_SET_GF_HIGH_ENTER(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text */
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SET_GF_HIGH));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_GFHigh_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVEMENU_SET_GF_HIGH_ENTER(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_GFHigh_Ctx);
}
