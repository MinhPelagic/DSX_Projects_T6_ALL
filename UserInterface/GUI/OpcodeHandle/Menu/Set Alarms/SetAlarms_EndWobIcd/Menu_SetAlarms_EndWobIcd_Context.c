/******************************************************************************/
//File: Alarms END WOB ICD
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*END*/
void SetAlarms_EndWobIcd_END_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_END));
}
void SetAlarms_EndWobIcd_END_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_END_AL_STAT]));
}
void SetAlarms_EndWobIcd_END_Context_Right(char* pStrRet)
{
    if(Imperial)
    {
        sprintf(pStrRet, "%d FT", GUI_END_AL_FT);
    }
    else
    {
        sprintf(pStrRet, "%.0f M", GUI_END_AL_M);
    }
}
void EndWobIcd_END_SET_Context(char* pStrRet)
{
    if(Imperial)
    {
        sprintf(pStrRet, "  %d", GUI_END_AL_FT);
    }
    else
    {
        sprintf(pStrRet, "  %.0f", GUI_END_AL_M);
    }
}
/*WOB*/
void SetAlarms_EndWobIcd_WOB_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WOB));
}
void SetAlarms_EndWobIcd_WOB_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_WOB_AL_STAT]));
}
void SetAlarms_EndWobIcd_WOB_Context_Right(char* pStrRet)
{
    if(Imperial)
    {
        sprintf(pStrRet, "%d FT", GUI_WOB_AL_FT);
    }
    else
    {
        sprintf(pStrRet, "%.0f M", GUI_WOB_AL_M);
    }
}
void EndWobIcd_WOB_SET_Context(char* pStrRet)
{
    if(Imperial)
    {
        sprintf(pStrRet, "  %d", GUI_WOB_AL_FT);
    }
    else
    {
        sprintf(pStrRet, "  %.0f", GUI_WOB_AL_M);
    }
}
/*ICD*/
void SetAlarms_EndWobIcd_ICD_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ICD));
}
void SetAlarms_EndWobIcd_ICD_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_ICD_AL_STAT]));
}
/*O2 NARCOTIC*/
void SetAlarms_EndWobIcd_O2NARCOTIC_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2_NARCOTIC));
}
void SetAlarms_EndWobIcd_O2NARCOTIC_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_YesNo_Context[(GUI_O2_NARCOTIC_AL_STAT == NVD_ON) ? SettYesNo_NO : SettYesNo_YES]));
}
