/******************************************************************************/
//File: Dive planner New or Continuous settings
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"


/*Context memdev config to Dive planner -> Set SP settings*/
static void DiveSimulator_SP_Content(char* pStrRet)
{
    sprintf(pStrRet, " %.2f ", 0.01*GUI_DIVE_SIMULATOR_SP);
}
const contentDispContext_st DiveSimulator_SP_Context =
{
    &DiveSimulator_SP_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};