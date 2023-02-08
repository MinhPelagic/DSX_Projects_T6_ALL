/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*Context memdev config to SetAlarm_Audible*/
static void SetAlarms_AudVib_AUDIBLE_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_SWITCH_AlarmAudible]));
}
const contentDispContext_st Set_SetAlarm_Audible_Ctx =
{
    &SetAlarms_AudVib_AUDIBLE_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};