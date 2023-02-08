/******************************************************************************/
//File: Alarms DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
/*DEPTH ALARM*/
#define SETALARM_DEPTH_FT                       GUI_DepthAlarmFT
#define SETALARM_DEPTH_M                        GUI_DepthAlarmM
#define USR_UNIT_SET                            0 // User setting
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*OOS Flag : ON/OFF/SET flag*/
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this
extern const contentDispContext_st SetAlarm_DEPTH_Context;
extern const contentDispContext_st SetAlarm_DEPTH_Stat_Context;