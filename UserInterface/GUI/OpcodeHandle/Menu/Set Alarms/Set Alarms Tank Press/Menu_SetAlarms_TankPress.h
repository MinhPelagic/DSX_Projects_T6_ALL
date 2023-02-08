/******************************************************************************/
//File: Alarms Tank press
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*Input data*/
#define ALARM_TANKPRESS_PSI                      GUI_TankP_AL_PSI      // TankP in PSI
#define ALARM_TANKPRESS_BAR                      GUI_TankP_AL_BAR      // TankP in BAR
extern contentDispContext_st SetSP_UnitSet_Ctx;
extern const char* TxtDef_Set_PressUnit[];
extern void SETALARMS_TankPress_Value_Context(char* pStrRet);
extern const contentDispContext_st Set_SetAlarm_TankPress_STAT_Ctx;
extern const contentDispContext_st SetAlarm_TankPressUnit_Context;
extern const contentDispContext_st SetAlarm_TankPress_Context;
