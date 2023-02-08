/******************************************************************************/
//File: Alarms TURN
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_TurnEndSwitchPress.h"
#include "../ContextSetAlarmsCfg.h"
extern const contentDispContext_st SetAlarm_TankPressUnit_Context; //Reuse this
extern void SetAlarms_TurnEndPress_END_Context(char* pStrRet);

/*Context memdev config*/
const contentDispContext_st SetAlarms_TurnEndPress_END =
{
    &SetAlarms_TurnEndPress_END_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value, //Re use this
};
/*Function to handle*/
void IniOrClrScrFunc_S286_ALARM_ENDPRESS_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_END_PRESS));
    /*Display FT/M*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarm_TankPressUnit_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_TurnEndPress_END);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S286_ALARM_ENDPRESS_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_TurnEndPress_END);
};