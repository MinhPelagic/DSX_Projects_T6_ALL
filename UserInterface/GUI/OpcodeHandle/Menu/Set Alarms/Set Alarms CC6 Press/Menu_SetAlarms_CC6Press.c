/******************************************************************************/
//File: Alarms Tank press
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_CC6Press.h"

void IniOrClrScrFunc_ALARM_CC6_PRESS_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_CC_PRESS));
    /*Display Depth ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_CC6PRESS_SET_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_CC6_PRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_CC6PRESS_SET_Ctx);
}
void HandlePreOCFunc_ALARM_CC6_PRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarm_CC6PRESS_SET_Ctx);
}
/**/
void UpdPorFunc_ALARM_CC6_PRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPressUnit_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_CC6PRESS_STAT_Ctx);
}
void UpdOrFlasFunc_ALARM_CC6_PRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarm_CC6PRESS_STAT_Ctx);
}
