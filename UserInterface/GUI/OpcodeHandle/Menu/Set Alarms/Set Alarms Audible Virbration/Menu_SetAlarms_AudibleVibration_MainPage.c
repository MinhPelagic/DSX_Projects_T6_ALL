/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_AudibleVibration.h"

/*Operation handle*/
void IniOrClrScrFunc_ALARM_AUDIBLE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_AUDIBLE_VIBRATION));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_AudVib_AUDIBLE, SetAlarmAudibleVibration_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_ALARM_AUDIBLE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_AudVib_AUDIBLE);
}
void HandlePreOCFunc_ALARM_AUDIBLE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_AudVib_AUDIBLE);
}
/*Vibration*/
void IniOrClrScrFunc_ALARM_VIBRATION(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_AUDIBLE_VIBRATION));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_AudVib_VIBRATION, SetAlarmAudibleVibration_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_ALARM_VIBRATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_AudVib_VIBRATION);
}
void HandlePreOCFunc_ALARM_VIBRATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_AudVib_VIBRATION);
}
