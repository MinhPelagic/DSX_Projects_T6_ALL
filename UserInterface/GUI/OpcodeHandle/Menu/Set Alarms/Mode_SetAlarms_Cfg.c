#include "L4X9_includes.h"
#include "ContextSetAlarmsCfg.h"

/*
Conext Menu of MAIN ALARMS
===============================================================================================================
AUDIBLE/VIBRATION
DEPTH
DIVE TIME
DTR
TANK PRESS
CC6 PRESS
GF/N2
===============================================================================================================
*/
static const listItemInMenu_ts SetAlarm_CC_Context=
{
    7,/*Number of items*/
    {
        &Context_SetAlarms_AUDIBLEnVIBRATION,
        &Context_SetAlarms_DEPTH,
        &Context_SetAlarms_DIVETIME_TTS,
        &Context_SetAlarms_DTR,
        &Context_SetAlarms_TANKPRESS,
        &Context_SetAlarms_CCPRESS,
        &Context_SetAlarms_GFN2,
    }
};
static const listItemInMenu_ts SetAlarm_OC_Context=
{
    7,/*Number of items*/
    {
        &Context_SetAlarms_AUDIBLEnVIBRATION,
        &Context_SetAlarms_DEPTH,
        &Context_SetAlarms_DIVETIME_TTS,
        &Context_SetAlarms_DTR,
        &Context_SetAlarms_TURNENDPRESS,
        &Context_SetAlarms_GFN2,
        &Context_SetAlarms_ENDWOBICD,
    }
};
static const listItemInMenu_ts SetAlarm_GAUGE_Context=
{
    4,/*Number of items*/
    {
        &Context_SetAlarms_AUDIBLEnVIBRATION,
        &Context_SetAlarms_DEPTH,
        &Context_SetAlarms_DIVETIME,
        &Context_SetAlarms_TURNENDPRESS,
    }
};
const listItemInMenu_ts* SetAlarm_ListOfContext[DIVEMODE_MAX] =
{
    &SetAlarm_CC_Context,/*CC*/
    &SetAlarm_OC_Context,/*OC*/
    &SetAlarm_OC_Context,/*SM*/
    &SetAlarm_GAUGE_Context,/*GAUGE*/
    &SetAlarm_GAUGE_Context,/*GAUGE SM*/
    &SetAlarm_CC_Context,/*BO*/
};
/*
Conext Menu
===============================================================================================================
DIVE TIME/TTS ALARMS
    -> DIVE TIME
    -> TTS
===============================================================================================================
*/
static const listItemInMenu_ts SetAlarm_DiveTimeTTS_CC_Context=
{
    2,/*Number of items*/
    {
        &Context_SetAlarms_DiveTimeTTS_DIVETIME,
        &Context_SetAlarms_DiveTimeTTS_TTS,
    }
};
const listItemInMenu_ts* SetAlarm_DiveTimeTTS_ListOfContext[DIVEMODE_MAX] =
{
    &SetAlarm_DiveTimeTTS_CC_Context,/*CC*/
    &SetAlarm_DiveTimeTTS_CC_Context,/*OC*/
    &SetAlarm_DiveTimeTTS_CC_Context,/*SM*/
    &SetAlarm_DiveTimeTTS_CC_Context,/*GAUGE*/
    &SetAlarm_DiveTimeTTS_CC_Context,/*GAUGE SM*/
    &SetAlarm_DiveTimeTTS_CC_Context,/*BO*/
};
