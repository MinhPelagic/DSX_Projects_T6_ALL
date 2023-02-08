/******************************************************************************/
//File: Dive planner DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"
/**/
void SetDivePlanner_Time_Min_content(char* pStrRet)
{
    if(Imperial)
        strcpy(pStrRet, "CUFT/MIN");
    else
        strcpy(pStrRet, "L/MIN");
}
const contentDispContext_st SetDivePlanner_CuftMin_Context =
{
    &SetDivePlanner_Time_Min_content,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_5,
    &Pos_SetDivePlanner_CuftMin, //MIN
};
/**/
static void DiveSimulator_SetSAC_Content(char* pStrRet)
{
    /*value*/
    if(Imperial)
        sprintf(pStrRet, "  %.2f", 0.01*GUI_DIVE_SIMULATOR_SAC_CuFt);
    else
        sprintf(pStrRet, "  %d", GUI_DIVE_SIMULATOR_SAC_Ltr);
}
/*Minute value*/
const contentDispContext_st DiveSimulator_SetSAC_Context =
{
    &DiveSimulator_SetSAC_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
