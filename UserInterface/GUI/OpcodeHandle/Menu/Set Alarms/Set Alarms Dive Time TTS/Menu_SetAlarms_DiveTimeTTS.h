/******************************************************************************/
//File: Alarms Dive Time and TTS
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#define ALARM_DIVETIMETTS_DIVETIME_OOS                  GUI_DIVE_T_AL_STAT     //ON/OFF/SET flag
#define ALARM_DIVETIMETTS_TTS_OOS                       GUI_TTS_AL_STAT        //ON/OFF/SET flag
#define ALARM_DIVETIMETTS_DIVETIME_VAL                  GUI_DIVE_T_AL          //Depth time in Minutes
#define ALARM_DIVETIMETTS_TTS_VAL                       GUI_TTS_AL             //TTS time in Mintues

/*Extern variable*/
extern const listItemInMenu_ts* SetAlarm_DiveTimeTTS_ListOfContext[DIVEMODE_MAX];
extern void SETALARMS_DiveTime_Value_Context(char*);
extern void SETALARMS_TTS_Value_Context(char*);
extern void SetSS_MINUnit(char*);
extern const contentDispContext_st SetAlarms_MIN_Context;
extern const contentDispContext_st SetAlarm_TTS_Context;
extern const contentDispContext_st SetAlarm_DiveTime_Context;
extern const contentDispContext_st Set_SetAlarm_DiveTime_STAT_Ctx;
extern const contentDispContext_st Set_SetAlarm_TTS_STAT_Ctx;
