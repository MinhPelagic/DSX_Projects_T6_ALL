/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_AudibleVibration.h"

/*
VIBARTION -> Set Vibration value
*/
void IniOrClrScrFunc_ALARM_VIBRATION_SET(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_VIBRATION));
    /*Display main set*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetAlarm_Vibration_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_VIBRATION_SET(void)
{
    /*Flashing value*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetAlarm_Vibration_Ctx);
}