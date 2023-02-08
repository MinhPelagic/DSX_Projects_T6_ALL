/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/*Select betwee TEC / SPORT*/
void IniOrClrScrFunc_S105_SET_CONSERV_TEC_SPORT(void)
{
    /*Clear all the screen*/
    ClearUnusedInList(0);
    /*Display title*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_CONSERVATISM));
    /*Display the content*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DiveSett_Consrv_STAT_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S105_SET_CONSERV_TEC_SPORT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DiveSett_Consrv_STAT_Ctx);
}
/*Go to set Conservative SPORT*/

void IniOrClrScrFunc_S106_SET_CONSERV_SPORT(void)
{
    /*Display toptitle*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CONSERVATISM_SPORT));
    /*Display the content*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DiveSett_ConsrvSport_STAT_Ctx);
    /*Display sub content below */
    HandleDisplayTextWithMemdev(IteStat_Select, Conservative_SPORT_Bottom_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S106_SET_CONSERV_SPORT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DiveSett_ConsrvSport_STAT_Ctx);
    /*Display sub content below */
    HandleDisplayTextWithMemdev(IteStat_Select, Conservative_SPORT_Bottom_Context);
}