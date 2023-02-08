/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

#define ALARM_AUDIBLEVIBE_AUDIBLE_STAT                  GUI_SWITCH_AlarmAudible             //ON/OFF flag
#define ALARM_AUDIBLEVIBE_VIBE_STAT                     GUI_SWITCH_AlarmVibeOn              //ON/OFF flag
/*
Conext Menu
===============================================================================================================
AUDIBLE/VIBRATION
    -> AUDIBLE
    -> VIBRATION
===============================================================================================================
*/
const listItemInMenu_ts SetAlarm_AudibleVibration_CC_Context=
{
    2,/*Number of items*/
    {
        &Context_SetAlarms_AudVib_AUDIBLE,
        &Context_SetAlarms_AudVib_VIBRATION,
    }
};
const listItemInMenu_ts* SetAlarmAudibleVibration_ListOfContext[DIVEMODE_MAX]=
{
    &SetAlarm_AudibleVibration_CC_Context,
    &SetAlarm_AudibleVibration_CC_Context,
    &SetAlarm_AudibleVibration_CC_Context,
    &SetAlarm_AudibleVibration_CC_Context,
    &SetAlarm_AudibleVibration_CC_Context,
    &SetAlarm_AudibleVibration_CC_Context, /*BO*/
};

/*Context*/
void SetAlarms_AudVib_AUDIBLE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUDIBLE));
};
void SetAlarms_AudVib_AUDIBLE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_AUDIBLEVIBE_AUDIBLE_STAT]));
}
void SetAlarms_AudVib_VIBRATION_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_VIBRATION));
}
void SetAlarms_AudVib_VIBRATION_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_AUDIBLEVIBE_VIBE_STAT]));
}