/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_AudibleVibration.h"
/*
AUDIBLE -> Set Audible value
*/
void IniOrClrScrFunc_ALARM_AUDIBLE_SET(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_AUDIBLE));
    /*Display main set*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetAlarm_Audible_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_AUDIBLE_SET(void)
{
    /*Flashing value*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetAlarm_Audible_Ctx);
}