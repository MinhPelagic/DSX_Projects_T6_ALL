/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*Context memdev config to SetAlarm_Vibration*/
static void SetAlarms_AudVib_VIBRATION_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_SWITCH_AlarmVibeOn]));
}
const contentDispContext_st Set_SetAlarm_Vibration_Ctx =
{
    &SetAlarms_AudVib_VIBRATION_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};