/******************************************************************************/
//File: Turn End Swtich
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"

/*TURN*/
void SetAlarms_TurnEndPress_TURN_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TURN_PRESS));
}
void SetAlarms_TurnEndPress_TURN_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TurnP_AL_STAT]));
}
void SetAlarms_TurnEndPress_TURN_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d PSI", GUI_TurnP_AL_PSI);
    else
        sprintf(pStrRet, "%d BAR", GUI_TurnP_AL_BAR);
}
void SetAlarms_TurnEndPress_TURN_Context(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "  %d", GUI_TurnP_AL_PSI);
    else
        sprintf(pStrRet, "  %d", GUI_TurnP_AL_BAR);
}
/*END*/
void SetAlarms_TurnEndPress_END_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_END_PRESS));
}
void SetAlarms_TurnEndPress_END_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d PSI", GUI_EndP_AL_PSI);
    else
        sprintf(pStrRet, "%d BAR", GUI_EndP_AL_BAR);

}
void SetAlarms_TurnEndPress_END_Context(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "  %d", GUI_EndP_AL_PSI);
    else
        sprintf(pStrRet, "  %d", GUI_EndP_AL_BAR);
}
/*SWITCH*/
void SetAlarms_TurnEndPress_SWITCH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SWITCH_PRESS));
}
void SetAlarms_TurnEndPress_SWITCH_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_SwitchP_AL_STAT]));
}
void SetAlarms_TurnEndPress_SWITCH_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d PSI", GUI_SwitchP_AL_PSI);
    else
        sprintf(pStrRet, "%d BAR", GUI_SwitchP_AL_BAR);
}
void SetAlarms_TurnEndPress_SWITCH_Context(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "  %d", GUI_SwitchP_AL_PSI);
    else
        sprintf(pStrRet, "  %d", GUI_SwitchP_AL_BAR);
}