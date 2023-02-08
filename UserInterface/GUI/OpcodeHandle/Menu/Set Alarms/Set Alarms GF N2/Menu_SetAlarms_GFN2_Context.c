/******************************************************************************/
//File: Alarms GF N2
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_GFN2.h"

/*Local prototype*/
static void GF_TextContext(char* pStrRet);
static void GF_StatusContext(char* pStrRet);
static void GF_ValueContext(char* pStrRet);
static void N2_TextContext(char* pStrRet);
static void N2_StatusContext(char* pStrRet);
static void N2_ValueContext(char* pStrRet);
/*GF context*/
const txtDispContext_st GF_Text_Context =
{
    &GF_TextContext,
    GUI_CYAN,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Point_SetAlarms_GFN2_GF_Text,
};
/*GF Value context*/
const contentDispContext_st GF_Value_Context =
{
    &GF_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetAlarms_GFN2_GF_Value,
};
/*GF On/Off/Set*/
const contentDispContext_st GF_Status_Context =
{
    &GF_StatusContext, /*ON/OFF/SET*/
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetAlarms_GFN2_GF_Value,
};
/*-------------------------------------------------------------------*/
/*N2 context*/
const txtDispContext_st N2_Text_Context =
{
    &N2_TextContext,
    GUI_CYAN,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Point_SetAlarms_GFN2_N2_Text,
};
/*N2 Value context*/
const contentDispContext_st N2_Value_Context =
{
    &N2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetAlarms_GFN2_N2_Value,
};
/*N2 On/Off/Set*/
const contentDispContext_st N2_Status_Context =
{
    &N2_StatusContext, /*ON/OFF/SET*/
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetAlarms_GFN2_N2_Value,
};
/*Local context handle*/
/*GF content*/
static void GF_TextContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GF));
}
static void GF_StatusContext(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_GF_OOS]));
}
static void GF_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %d ", ALARM_GF);
}
/*-------------------------------------------------------------------*/
/*N2 content*/
static void N2_TextContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_N2));
}
static void N2_StatusContext(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARM_N2_OOS]));
}
static void N2_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %d%% ", ALARM_N2);
}