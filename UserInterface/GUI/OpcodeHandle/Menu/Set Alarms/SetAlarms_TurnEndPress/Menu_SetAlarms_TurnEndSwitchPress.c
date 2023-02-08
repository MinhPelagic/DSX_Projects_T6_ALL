/******************************************************************************/
//File: Alarms
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_TurnEndSwitchPress.h"
static void displayTittleTurnEndSwitchAlarm(void)
{
    /*speficiy to SM mode, display tittle Turn/End/Switch*/
    if(SM_MODE)
    {
        char stRet[LangMaxLength];
        sprintf(stRet, "%s %s", GUI_LANG_GetText(TxtStr_TURN_END_PRESS_SWITCH_PRESS), GUI_LANG_GetText(TxtStr_ALARMS));
        DisplayText_TopBar_Title(stRet);
    }
    else
    {
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TURNEND_PRESS_AL));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
/*TURN PRESS*/
void IniOrClrScrFunc_S282_ALARM_TURNPRESS(void)
{
    displayTittleTurnEndSwitchAlarm();
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_TurnEndPress_TURN, SetTurnEndSwitchPress_MenuList);
}
void UpdPorFunc_S282_ALARM_TURNPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_TurnEndPress_TURN);
}
void HandlePreOCFunc_S282_ALARM_TURNPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_TurnEndPress_TURN);
}
/*END PRESS*/
void IniOrClrScrFunc_S285_ALARM_ENDPRESS(void)
{
    displayTittleTurnEndSwitchAlarm();
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_TurnEndPress_END, SetTurnEndSwitchPress_MenuList);
}
void UpdPorFunc_S285_ALARM_ENDPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_TurnEndPress_END);
}
void HandlePreOCFunc_S285_ALARM_ENDPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_TurnEndPress_END);
}
/*SWITCH PRESS*/
void IniOrClrScrFunc_S353_ALARM_SWITCHPRESS(void)
{
    displayTittleTurnEndSwitchAlarm();
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_TurnEndPress_SWITCH, SetTurnEndSwitchPress_MenuList);
}
void UpdPorFunc_S353_ALARM_SWITCHPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_TurnEndPress_SWITCH);
}
void HandlePreOCFunc_S353_ALARM_SWITCHPRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_TurnEndPress_SWITCH);
}
