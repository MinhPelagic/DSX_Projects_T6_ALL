/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*
Conext Menu
===============================================================================================================
TURN END SWITCH
    -> TURN
    -> END
    -> SWITCH
===============================================================================================================
*/
/*Setting*/
static const listItemInMenu_ts SetTurnEndSwitchPress_CC=
{
    2,/*Number of items*/
    {
        &Context_SetAlarms_TurnEndPress_TURN,
        &Context_SetAlarms_TurnEndPress_END,
    }
};
static const listItemInMenu_ts SetTurnEndSwitchPress_SM=
{
    3,/*Number of items*/
    {
        &Context_SetAlarms_TurnEndPress_TURN,
        &Context_SetAlarms_TurnEndPress_END,
        &Context_SetAlarms_TurnEndPress_SWITCH,
    }
};
const listItemInMenu_ts* SetTurnEndSwitchPress_MenuList[DIVEMODE_MAX] =
{
    &SetTurnEndSwitchPress_CC,/*CC*/
    &SetTurnEndSwitchPress_CC,/*OC*/
    &SetTurnEndSwitchPress_SM,/*SM*/
    &SetTurnEndSwitchPress_SM,/*GAUGE SM*/
    &SetTurnEndSwitchPress_CC,/*GAUGE*/
    &SetTurnEndSwitchPress_CC,/*BO*/
};