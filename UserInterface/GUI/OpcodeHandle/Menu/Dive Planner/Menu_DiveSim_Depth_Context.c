/******************************************************************************/
//File: Dive planner DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/**/
static void DivePlanner_SetDepthValue_Content(char* pStrRet)
{
    /*DEPTH VALUE*/
    if(Imperial)
        sprintf(pStrRet, "  %d", GUI_DIVE_SIMULATOR_DEPTH_Ft);
    else
        sprintf(pStrRet, "  %d", GUI_DIVE_SIMULATOR_DEPTH_Mt);
}
/*Depth value*/
const contentDispContext_st DiveSimulator_SetDepth_Context =
{
    &DivePlanner_SetDepthValue_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
