/******************************************************************************/
//File: Alarms END WOB ICD
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_EndWobIcd.h"
/*SP Setting*/
const listItemInMenu_ts SetEndWobIcd_CC_Context=
{
    4,/*Number of items*/
    {
        &Context_SetAlarms_EndWobIcd_END,
        &Context_SetAlarms_EndWobIcd_WOB,
        &Context_SetAlarms_EndWobIcd_ICD,
        &Context_SetAlarms_EndWobIcd_O2NARCOTIC,
    }
};
const listItemInMenu_ts* SetEndWobIcd_ListOfContext[DIVEMODE_MAX] =
{
    &SetEndWobIcd_CC_Context,
    &SetEndWobIcd_CC_Context,
    &SetEndWobIcd_CC_Context,
    &SetEndWobIcd_CC_Context,
    &SetEndWobIcd_CC_Context,
    &SetEndWobIcd_CC_Context, /*BO*/
};
