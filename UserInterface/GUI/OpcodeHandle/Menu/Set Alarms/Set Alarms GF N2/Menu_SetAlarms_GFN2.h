/******************************************************************************/
//File: Alarms GF N2
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*Input data*/
#define ALARM_GF_OOS                    GUI_GF_AL_STAT  //ON/OFF/SET flag
#define ALARM_N2_OOS                    GUI_N2_AL_STAT  //ON/OFF/SET flag
#define ALARM_GF                        GUI_GF_AL       // GF Alarm
#define ALARM_N2                        GUI_N2_AL       // N2 Alarm

/*Extern variables*/
extern const txtDispContext_st GF_Text_Context;
extern const txtDispContext_st N2_Text_Context;
extern const contentDispContext_st N2_Status_Context;
extern const contentDispContext_st GF_Status_Context;
extern const contentDispContext_st GF_Value_Context;
extern const contentDispContext_st N2_Value_Context;