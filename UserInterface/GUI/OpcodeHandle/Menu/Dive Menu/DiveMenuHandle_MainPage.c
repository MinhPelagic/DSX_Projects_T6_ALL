#include "L4X9_includes.h"
#include "ContextDiveMenuCfg.h"
#include "DiveMenu.h"

/*DIVEMENU_SETSP*/
void IniOrClrScrFunc_DIVEMENU_SETSP(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_SETSP, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_SETSP(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_SETSP);
}
void HandlePreOCFunc_DIVEMENU_SETSP(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_SETSP);
}
/*DIVEMENU_SETGASES*/
void IniOrClrScrFunc_DIVEMENU_SETGASES(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_SETGASES, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_SETGASES(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_SETGASES);
}
void HandlePreOCFunc_DIVEMENU_SETGASES(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_SETGASES);
}
/*DIVEMENU_DIVEPROFILEGRAPH*/
void IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_DIVEPROFILEGRAPH, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_DIVEPROFILEGRAPH(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_DIVEPROFILEGRAPH);
}
void HandlePreOCFunc_DIVEMENU_DIVEPROFILEGRAPH(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_DIVEPROFILEGRAPH);
}
/*DIVEMENU_BAILOUTPO2LIMITS*/
void IniOrClrScrFunc_DIVEMENU_BAILOUTPO2LIMITS(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_BAILOUTPO2LIMITS, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_BAILOUTPO2LIMITS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_BAILOUTPO2LIMITS);
}
void HandlePreOCFunc_DIVEMENU_BAILOUTPO2LIMITS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_BAILOUTPO2LIMITS);
}
/*DIVEMENU_DECOSTOPS*/
void IniOrClrScrFunc_DIVEMENU_DECOSTOPS(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_DECOSTOPS, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_DECOSTOPS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_DECOSTOPS);
}
void HandlePreOCFunc_DIVEMENU_DECOSTOPS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_DECOSTOPS);
}
/*DIVEMENU_SETGFHIGH*/
void IniOrClrScrFunc_DIVEMENU_SETGFHIGH(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_SETGFHIGH, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_SETGFHIGH(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_SETGFHIGH);
}
void HandlePreOCFunc_DIVEMENU_SETGFHIGH(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_SETGFHIGH);
}
/*DIVEMENU_PO2LIMITS*/
void IniOrClrScrFunc_DIVEMENU_PO2LIMITS(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_MENU));
    HandleFunc_DisplayInitListOfMenu(DiveMenu_GetTheCurrentDisplayStatus(), Context_DiveMenu_PO2LIMITS, DiveMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMENU_PO2LIMITS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_Select, Context_DiveMenu_PO2LIMITS);
}
void HandlePreOCFunc_DIVEMENU_PO2LIMITS(void)
{
    Handle_GeneralListMenuContext(DiveMenu_GetTheCurrentDisplayStatus(), IteStat_UnSelect, Context_DiveMenu_PO2LIMITS);
}
