/******************************************************************************/
//File: Dive Dive simulator
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"

/*NEW OR CONTINUOUS*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_NEWORCONTINUOUS, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_NEWORCONTINUOUS);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_NEWORCONTINUOUS);
}
/*DEPTH*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_DEPTH, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_DEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_DEPTH);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_DEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_DEPTH);
}
/*TIME*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_TIME, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_TIME);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_TIME);
}
/*SAC*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_SAC, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_SAC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_SAC);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SAC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_SAC);
}
/*SP*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_SP, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_SP);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_SP);
}
/*SIMLUATE DIVE*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SIMULATOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSimulator_SIMULATEDIVE, DiveSimulator_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSimulator_SIMULATEDIVE);
}
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSimulator_SIMULATEDIVE);
}
