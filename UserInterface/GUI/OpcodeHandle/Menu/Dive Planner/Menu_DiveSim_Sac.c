/******************************************************************************/
//File: Dive planner Depth
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/*SAC*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SAC));
    /*Display MIN*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetDivePlanner_CuftMin_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_SetSAC_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SAC_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSimulator_SetSAC_Context);
}