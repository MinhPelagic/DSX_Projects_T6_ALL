/******************************************************************************/
//File: Alarms DTR
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_DTR.h"

/*Hanlde functions*/
void IniOrClrScrFunc_ALARM_DTR_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DTR));
    /*Display Depth ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_DTR_STAT_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_DTR_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_DTR_STAT_Ctx);
}
void HandlePreOCFunc_ALARM_DTR_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarm_DTR_STAT_Ctx);
}
void UpdPorFunc_ALARM_DTR_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_MIN_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_DTR_Value_Ctx);
}
void UpdOrFlasFunc_ALARM_DTR_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_DTR_Value_Ctx);
}