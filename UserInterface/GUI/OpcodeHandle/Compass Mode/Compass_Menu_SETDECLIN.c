/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "ContextCompassMenuCfg.h"

void IniOrClrScrFunc_C14_COMPASS_DECLIN_SETTING(void)
{
    /*Clear the list of previous content*/
    ClearUnusedInList(0);
    /*Sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SET_DECLIN));
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, CompassMenu_SetDecline_STAT_Ctx);
}
void UpdOrFlasFunc_C14_COMPASS_DECLIN_SETTING(void)
{
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, CompassMenu_SetDecline_STAT_Ctx);
}