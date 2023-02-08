/******************************************************************************/
//File: Alarms DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_DEPTH.h"

void IniOrClrScrFunc_ALARM_DEPTH_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text DEPTH*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DEPTH));
    /*Display Depth ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_DEPTH_Stat_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_DEPTH_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_DEPTH_Stat_Context);
}
void HandlePreOCFunc_ALARM_DEPTH_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarm_DEPTH_Stat_Context);
}
/*SET*/
void UpdPorFunc_ALARM_DEPTH_SET(void)
{
    /*Display FT/M*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_DEPTH_Context);
}
void UpdOrFlasFunc_ALARM_DEPTH_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_DEPTH_Context);
}