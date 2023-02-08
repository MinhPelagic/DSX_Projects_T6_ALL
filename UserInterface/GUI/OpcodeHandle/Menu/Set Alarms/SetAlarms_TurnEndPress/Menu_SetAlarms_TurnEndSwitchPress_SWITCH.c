/******************************************************************************/
//File: Alarms SWITCH
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_TurnEndSwitchPress.h"
#include "../ContextSetAlarmsCfg.h"
/*Extern variable*/
extern const contentDispContext_st SetAlarm_TankPressUnit_Context; //Reuse this
extern void SetAlarms_TurnEndPress_SWITCH_Context(char*);

/*Context memdev config*/
const contentDispContext_st SetAlarms_TurnEndPress_SWITCH =
{
    &SetAlarms_TurnEndPress_SWITCH_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Set Alarms SWITCH value*/
const contentDispContext_st SetAlarms_TurnEndPress_SWITCH_SET =
{
    &SetAlarms_TurnEndPress_SWITCH_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value, //Reuse
};
/*Function to handle*/
void IniOrClrScrFunc_S354_ALARM_SWITCHPRESS_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SWITCH_PRESS));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_TurnEndPress_SWITCH);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S354_ALARM_SWITCHPRESS_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_TurnEndPress_SWITCH);
}
/*SET*/
void IniOrClrScrFunc_S355_ALARM_SWITCHPRESS_SET(void)
{
    /*Clear the previous portion*/
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarms_TurnEndPress_SWITCH);
    /*Display unit*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPressUnit_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_TurnEndPress_SWITCH_SET);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S355_ALARM_SWITCHPRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_TurnEndPress_SWITCH_SET);
}