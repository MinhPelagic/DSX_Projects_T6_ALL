/******************************************************************************/
//File: SP
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"
/*
SP
*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP_SET(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_SP));
    /*Display main set*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_SP_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SP_SET(void)
{
    /*Flashing value*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSimulator_SP_Context);
}