/******************************************************************************/
//File: Alarms Tank press
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_TankPress.h"
/**/
void IniOrClrScrFunc_ALARM_TANK_PRESS_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TANK_PRESS));
    /*Display Depth ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetAlarm_TankPress_STAT_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_TANK_PRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetAlarm_TankPress_STAT_Ctx);
}
void HandlePreOCFunc_ALARM_TANK_PRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, Set_SetAlarm_TankPress_STAT_Ctx);
}
void UpdPorFunc_ALARM_TANK_PRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPressUnit_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPress_Context);
}
void UpdOrFlasFunc_ALARM_TANK_PRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_TankPress_Context);
}