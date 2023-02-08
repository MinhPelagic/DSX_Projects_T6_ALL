/******************************************************************************/
//File: Alarms Dive Time and TTS
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_DiveTimeTTS.h"

/*Display functions*/
void IniOrClrScrFunc_ALARM_DIVETIME(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_TIME_TTS_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DiveTimeTTS_DIVETIME, SetAlarm_DiveTimeTTS_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_ALARM_DIVETIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DiveTimeTTS_DIVETIME);
}
void HandlePreOCFunc_ALARM_DIVETIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DiveTimeTTS_DIVETIME);
}
/*---------------------------------------------------------------*/
void IniOrClrScrFunc_ALARM_TTS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_TIME_TTS_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DiveTimeTTS_TTS, SetAlarm_DiveTimeTTS_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_ALARM_TTS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DiveTimeTTS_TTS);
}
void HandlePreOCFunc_ALARM_TTS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DiveTimeTTS_TTS);
}
