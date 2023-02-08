/******************************************************************************/
//File: Alarms menu.c
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms.h"

/* ----------------------------------------- SET ALARM context handle ----------------------------------- */
/*Hanlde ALARM Setting AUDIBLE*/
void SetAlarms_AUDIBLEnVIBRATION_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUDIBLE_VIBRATION));
}
/*Hanlde ALARM Setting DEPTH*/
void SetAlarms_DEPTH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEPTH));
}
void SetAlarms_DEPTH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_DEPTH_OOS]));
}
void SetAlarms_DEPTH_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, TxtDef_Set_DepthStr[UNITS], ((Imperial)?ALARMS_DEPTH_FT:ALARMS_DEPTH_M));
}
/*Hanlde ALARM Setting DIVE TIME*/
void SetAlarms_DIVETIME_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME));
}
void SetAlarms_DIVETIME_TTS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME_TTS));
}
void SetAlarms_DIVETIME_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_DIVETIME_OOS]));
}
void SetAlarms_DIVETIME_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", ALARMS_DIVETIME_MIN, GUI_LANG_GetText(TxtStr_MIN));
}
/*Hanlde ALARM Setting DTR*/
void SetAlarms_DTR_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DTR));
}
void SetAlarms_DTR_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_DTR_OOS]));
}
void SetAlarms_DTR_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", ALARMS_DTR_MIN, GUI_LANG_GetText(TxtStr_MIN));
}
/*Hanlde ALARM Setting TANK PRESS*/
void SetAlarms_TANKPRESS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TANK_PRESS));
}
void SetAlarms_TANKPRESS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_TANKPRESS_OOS]));
}
void SetAlarms_TANKPRESS_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d PSI", ALARMS_TANKPRESS_PSI);
    else
        sprintf(pStrRet, "%d BAR", ALARMS_TANKPRESS_BAR);
}
/*Hanlde ALARM Setting TURNENDPRESS*/
void SetAlarms_TURNENDPRESS_Context_Left(char* pStrRet)
{
    if(SM_MODE||GSM_MODE)
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TURN_END_PRESS_SWITCH_PRESS));
    }
    else
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TURNEND_PRESS));
    }
}
/*Hanlde ALARM Setting CC-# PRESSURE*/
void SetAlarms_CCPRESS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CC_PRESS));
}
void SetAlarms_CCPRESS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_CCPRESS_OOS]));
}
void SetAlarms_CCPRESS_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d PSI", GUI_CC6P_AL_PSI);
    else
        sprintf(pStrRet, "%d BAR", GUI_CC6P_AL_BAR);
}
/*Hanlde ALARM Setting GF/N2*/
void SetAlarms_GFN2_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GF_N2));
}
void SetAlarms_GFN2_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, "%s/%s", \
            GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_GF_AL_STAT]),\
            GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_N2_AL_STAT]));
}
void SetAlarms_GFN2_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d/%d%%", GUI_GF_AL, GUI_N2_AL);
}
/*Hanlde ALARM Setting END/WOB/ICD*/
void SetAlarms_ENDWOBICD_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_END_WOB_ICD));
}

