/******************************************************************************/
//File: Dive_Settings.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

void IniOrClrScrFunc_DIVEMODE_SETPOINTS(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DIVE_MODE));
    /*Display the content*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DiveSett_SetDiveMode_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVEMODE_SETPOINTS(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DiveSett_SetDiveMode_Ctx);;
}
