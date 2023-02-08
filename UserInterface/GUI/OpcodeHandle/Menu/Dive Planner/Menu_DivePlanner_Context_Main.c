/******************************************************************************/
//File: Dive planner.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

void DivePlanner_TIMELIMITS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME_LIMITS));
}
void DivePlanner_DEPTHLIMITS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEPTHS_LIMITS));
}
void DivePlanner_DIVESIMULATOR_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
}