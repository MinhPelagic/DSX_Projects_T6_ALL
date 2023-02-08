/******************************************************************************/
//File: Alarms END WOB ICD
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

extern const listItemInMenu_ts* SetTurnEndSwitchPress_MenuList[DIVEMODE_MAX];
/*Local decaration*/
void SetAlarms_TurnEndPress_TURN_Context(char*);
/*List of menu*/
enum
{
    SeAlarms_TurnEndSwitchPress_TURN,
    SeAlarms_TurnEndSwitchPress_END,
    SeAlarms_TurnEndSwitchPress_SWITCH,
    SeAlarms_TurnEndSwitchPress_MAX,
};
