/******************************************************************************/
//File: Dive planner DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/**/
static void DiveSimulator_SetTime_Content(char* pStrRet)
{
    /*Minute value*/
    sprintf(pStrRet, "%d", GUI_DIVE_SIMULATOR_Time);
}
/*Minute value*/
const contentDispContext_st DiveSimulator_SetTime_Context =
{
    &DiveSimulator_SetTime_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
