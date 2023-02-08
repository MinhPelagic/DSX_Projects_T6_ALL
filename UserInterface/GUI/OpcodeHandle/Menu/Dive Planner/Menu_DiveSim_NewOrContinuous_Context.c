/******************************************************************************/
//File: Dive planner New or Continuous settings
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"

static const TxtStr_Name_e TxtDef_NewOrContinuous_Context[SettDivePlanner_MAX] =
{
    TxtStr_NEW,
    TxtStr_CONTINUOUS,
};
/*Context memdev config to Dive planner -> New or continuous settings*/
static void DiveSimulator_NewOrContinous_Content(char* pStrRet)
{
    sprintf(pStrRet, "      %s      ", GUI_LANG_GetText(TxtDef_NewOrContinuous_Context[GUI_DIVE_SIMULATOR_NEW_CONT])); //Put the real data
}
const contentDispContext_st DiveSimulator_NewOrContinous_Context =
{
    &DiveSimulator_NewOrContinous_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};