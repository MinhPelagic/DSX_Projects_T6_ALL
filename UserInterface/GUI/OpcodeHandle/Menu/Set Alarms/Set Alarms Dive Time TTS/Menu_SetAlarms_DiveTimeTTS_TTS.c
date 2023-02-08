/******************************************************************************/
//File: Alarms Dive Time and TTS
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_DiveTimeTTS.h"
/*
DIVE TIME/TTS ALARMS
    -> TTS
*/
/*Set Alarms Depth value*/

void IniOrClrScrFunc_ALARM_TTS_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TTS));
    /*Display Depth ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetAlarm_TTS_STAT_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_TTS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetAlarm_TTS_STAT_Ctx);
}
void HandlePreOCFunc_ALARM_TTS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, Set_SetAlarm_TTS_STAT_Ctx);
}
void UpdPorFunc_ALARM_TTS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_MIN_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TTS_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_TTS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_TTS_Context);
}
