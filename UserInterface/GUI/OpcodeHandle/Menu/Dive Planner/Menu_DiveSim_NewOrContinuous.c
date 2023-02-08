/******************************************************************************/
//File: Alarms Audible and Virbration
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"
/*
SET NEW OR CONTINUOUS
*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_NEW_OR_CONTINUOUS));
    /*Display main set*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_NewOrContinous_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET(void)
{
    /*Flashing value*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSimulator_NewOrContinous_Context);
}