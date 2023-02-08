/******************************************************************************/
//File: Alarms Dive Time and TTS
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_DiveTimeTTS.h"

/*Context ALARM Setting DIVE TIME*/
void SetAlarms_DiveTimeTTS_DIVETIME_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME));
}
void SetAlarms_DiveTimeTTS_DIVETIME_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_DIVETIMETTS_DIVETIME_OOS]));
}
void SetAlarms_DiveTimeTTS_DIVETIME_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", ALARM_DIVETIMETTS_DIVETIME_VAL, GUI_LANG_GetText(TxtStr_MIN));
}

/*
DIVE TIME/TTS ALARMS
    -> TTS
*/
void SetAlarms_DiveTimeTTS_TTS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TTS));
}
void SetAlarms_DiveTimeTTS_TTS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_DIVETIMETTS_TTS_OOS]));
}
void SetAlarms_DiveTimeTTS_TTS_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", ALARM_DIVETIMETTS_TTS_VAL, GUI_LANG_GetText(TxtStr_MIN));
}
void SETALARMS_TTS_Value_Context(char* pStrRet)
{
    /*TS*/
    sprintf(pStrRet, "  %d", ALARM_DIVETIMETTS_TTS_VAL);
}
const contentDispContext_st SetAlarm_TTS_Context =
{
    &SETALARMS_TTS_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*
DIVE TIME/TTS ALARMS
    -> DIVE TIME
*/
/**/
static void SETALARMS_DiveTime_Value_Context(char* pStrRet)
{
    /*Dive time TTS*/
    sprintf(pStrRet, "  %d", ALARM_DIVETIMETTS_DIVETIME_VAL);
}
static void SetAlarms_DiveTimeTTS_DIVETIME_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_DIVETIMETTS_DIVETIME_OOS]));
}
/*Set Alarms Depth value*/
const contentDispContext_st SetAlarm_DiveTime_Context =
{
    &SETALARMS_DiveTime_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
const contentDispContext_st SetAlarms_MIN_Context =
{
    &SetSS_MINUnit,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_UnitSign, //MIN
};
/*Context memdev config to SetAlarm_DiveTime_STAT*/
const contentDispContext_st Set_SetAlarm_DiveTime_STAT_Ctx =
{
    &SetAlarms_DiveTimeTTS_DIVETIME_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
/*Context memdev config to SetAlarm_TTS_STAT*/
static void SetAlarms_DiveTimeTTS_TTS_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_DIVETIMETTS_TTS_OOS]));
}
const contentDispContext_st Set_SetAlarm_TTS_STAT_Ctx =
{
    &SetAlarms_DiveTimeTTS_TTS_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
