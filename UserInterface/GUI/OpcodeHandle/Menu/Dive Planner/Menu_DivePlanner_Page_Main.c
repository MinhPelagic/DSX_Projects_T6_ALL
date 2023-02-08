/******************************************************************************/
//File: Dive planner.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

void IniOrClrScrFunc_DIVE_PL_TIME_LIMITS(void)
{
    /*Clear display screen*/
    ClearUnusedInList(0);
    /*Display title*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLANNER));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DivePlanner_TIMELIMITS, DivePlannerMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS(void)
{
    /*Clear display screen*/
    GUI_Clear();
    /*Display title*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLANNER));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DivePlanner_DEPTHLIMITS, DivePlannerMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM(void)
{
    /*Clear display screen*/
    ClearUnusedInList(0);
    /*Display title*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLANNER));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DivePlanner_DIVESIMULATOR, DivePlannerMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_TIME_LIMITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DivePlanner_TIMELIMITS);
}
void UpdPorFunc_DIVE_PL_DEPTH_LIMITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DivePlanner_DEPTHLIMITS);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DivePlanner_DIVESIMULATOR);
}
void HandlePreOCFunc_DIVE_PL_TIME_LIMITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DivePlanner_TIMELIMITS);
}
void HandlePreOCFunc_DIVE_PL_DEPTH_LIMITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DivePlanner_DEPTHLIMITS);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DivePlanner_DIVESIMULATOR);
}
