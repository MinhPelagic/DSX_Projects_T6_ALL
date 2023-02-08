/******************************************************************************/
//File: Alarms DTR
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "../Menu_SetAlarms.h"

/**/
static void SETALARMS_DTR_Value_Context(char* pStrRet)
{
    /*DTR*/
    sprintf(pStrRet, "  %d", GUI_DTR_AL);
}
static void SetAlarms_DTR_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_DTR_OOS]));
}
/*Set Alarms Depth value*/
const contentDispContext_st SetAlarm_DTR_Value_Ctx =
{
    &SETALARMS_DTR_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Context memdev config to SetAlarm_DTR_STAT*/
const contentDispContext_st SetAlarm_DTR_STAT_Ctx =
{
    &SetAlarms_DTR_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};