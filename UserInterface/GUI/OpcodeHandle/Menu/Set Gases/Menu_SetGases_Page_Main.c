/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

/*Main routine*/
void IniOrClrScrFunc_S70_SET_GAS_01(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_01, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_01, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_SET_GAS_02(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_02, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_02, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_SET_GAS_03(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_03, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_03, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_SET_GAS_04(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_04, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_04, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_SET_GAS_05(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_05, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_05, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_SET_GAS_06(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_06, SetGases_DiveMode_ListOfContext);
    else
        HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_06, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S70_O2_ANALYZER(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_Row_O2_ANALYZER, SetGases_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
/*----------------------------------------------------------------*/
void UpdPorFunc_S70_SET_GAS_01(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_01);
}
void HandlePreOCFunc_S70_SET_GAS_01(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_01);
}
void UpdPorFunc_S70_SET_GAS_02(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_02);
}
void HandlePreOCFunc_S70_SET_GAS_02(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_02);
}
void UpdPorFunc_S70_SET_GAS_03(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_03);
}
void HandlePreOCFunc_S70_SET_GAS_03(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_03);
}
void UpdPorFunc_S70_SET_GAS_04(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_04);
}
void HandlePreOCFunc_S70_SET_GAS_04(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_04);
}
void UpdPorFunc_S70_SET_GAS_05(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_05);
}
void HandlePreOCFunc_S70_SET_GAS_05(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_05);
}
void UpdPorFunc_S70_SET_GAS_06(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_06);
}
void HandlePreOCFunc_S70_SET_GAS_06(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_06);
}
void UpdPorFunc_S70_O2_ANALYZER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_Row_O2_ANALYZER);
}
void HandlePreOCFunc_S70_O2_ANALYZER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_Row_O2_ANALYZER);
}
/**
 * @brief SET GAS BO mode
 *
 */
void IniOrClrScrFunc_SETGASES_SET_CC_GASES(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGasesMenu_SetCCGases, SetGasesMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_SETGASES_SET_BO_GASES(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGasesMenu_SetBOGases, SetGasesMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_SETGASES_O2_ANALYZER(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGasesMenu_O2Analyzer, SetGasesMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_SETGASES_SET_CC_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGasesMenu_SetCCGases);
}
void HandlePreOCFunc_SETGASES_SET_CC_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGasesMenu_SetCCGases);
}
void UpdPorFunc_SETGASES_SET_BO_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGasesMenu_SetBOGases);
}
void HandlePreOCFunc_SETGASES_SET_BO_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGasesMenu_SetBOGases);
}
void UpdPorFunc_SETGASES_O2_ANALYZER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGasesMenu_O2Analyzer);
}
void HandlePreOCFunc_SETGASES_O2_ANALYZER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGasesMenu_O2Analyzer);
}
