/******************************************************************************/
//File: Alarms END WOB ICD
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
/*Local decaration*/
void EndWobIcd_END_SET_Context(char* pStrRet);
void EndWobIcd_WOB_SET_Context(char* pStrRet);
/*List of menu*/
enum
{
    SeAlarmsItem_END,
    SeAlarmsItem_WOB,
    SeAlarmsItem_ICD,
    SeAlarmsItem_O2NARCOTIC,
    SeAlarmsItem_MAX,
};
extern const listItemInMenu_ts* SetEndWobIcd_ListOfContext[DIVEMODE_MAX];
