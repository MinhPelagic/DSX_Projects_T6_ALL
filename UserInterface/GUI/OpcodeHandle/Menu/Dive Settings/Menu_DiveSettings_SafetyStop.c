/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/**/
void IniOrClrScrFunc_SET_SAFETYSTOP_STAT(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SAFETY_STOP));
    /*Display the content*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DiveSett_SafetyStop_STAT_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SET_SAFETYSTOP_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DiveSett_SafetyStop_STAT_Ctx);
}
/*------------------------------------------------------------------*/

void IniOrClrScrFunc_SET_SAFETYSTOP_DEPTHT(void)
{
    /*Set font sequence*/
    /*Clear the previous content first*/
    HandleDisplayTextWithMemdev(IteStat_Clear, Set_DiveSett_SafetyStop_STAT_Ctx);
    /*Display the dash center*/
    GUI_SetColor(TxtColor_Select);
    GUI_SetFont(&FontAaux_6);
    GUI_DispStringAt("-", Point_SetGas_Slash->x, Point_SetGas_Slash->y);
    /*Display FT/M - MIN text*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSS_UNITSET_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, SetSS_MIN_Context);
    /*Display the value*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSett_SafetyStopTime_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSett_SafetyStopDepth_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SET_SAFETYSTOP_DEPTHT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSett_SafetyStopDepth_Context);
}
void HandlePreOCFunc_SET_SAFETYSTOP_DEPTHT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSett_SafetyStopDepth_Context);
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSett_SafetyStopTime_Context);
}
void UpdOrFlasFunc_SET_SAFETYSTOP_TIME(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSett_SafetyStopTime_Context);
}