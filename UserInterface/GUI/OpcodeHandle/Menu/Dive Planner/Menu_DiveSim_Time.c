/******************************************************************************/
//File: Dive planner Depth
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/*TIME*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
        DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DIVE_TIME));          // Use TxtStr_DIVE_TIME in Chiniese-T and Chiniese-S
    else
        DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TIME));
    /*Display MIN*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_MIN_Context);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_SetTime_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_TIME_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, DiveSimulator_SetTime_Context);
}
