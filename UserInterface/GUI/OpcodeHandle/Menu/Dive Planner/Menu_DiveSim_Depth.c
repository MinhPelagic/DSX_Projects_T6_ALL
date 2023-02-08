/******************************************************************************/
//File: Dive planner Depth
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/*SET*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text DEPTH*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DEPTH));
    /*Display FT/M*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_SetDepth_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_DEPTH_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSimulator_SetDepth_Context);
}