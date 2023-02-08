/******************************************************************************/
//File: Alarms TURN
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_TurnEndSwitchPress.h"
#include "../ContextSetAlarmsCfg.h"
/*Extern variable*/
extern const contentDispContext_st SetAlarm_TankPressUnit_Context; //Reuse this

/*Context memdev config*/
const contentDispContext_st SetAlarms_TurnEndPress_TURN =
{
    &SetAlarms_TurnEndPress_TURN_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Set Alarms END value*/
const contentDispContext_st SetAlarms_TurnEndPress_TURN_SET =
{
    &SetAlarms_TurnEndPress_TURN_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value, //Reuse
};
/*Function to handle*/
void IniOrClrScrFunc_S283_ALARM_TURNPRESS_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TURN_PRESS));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_TurnEndPress_TURN);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S283_ALARM_TURNPRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_TurnEndPress_TURN);
}
/*SET*/
void IniOrClrScrFunc_S284_ALARM_TURNPRESS_SET(void)
{
    /*Clear the previous portion*/
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarms_TurnEndPress_TURN);
    /*Display unit*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPressUnit_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_TurnEndPress_TURN_SET);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S284_ALARM_TURNPRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_TurnEndPress_TURN_SET);
}