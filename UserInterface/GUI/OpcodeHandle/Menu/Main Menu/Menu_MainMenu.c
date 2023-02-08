/******************************************************************************/
//File: MAIN MENU
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextMainMenuCfg.h"
extern const listItemInMenu_ts* MainMenu_ListOfContext[DIVEMODE_MAX];
extern NVD_DIVEMODE_t GUI_DIVE_Mode;

void IniOrClrScrFunc_S404_TMT_SWITCH(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_TMTSWITCH, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S432_DIVE_MODE(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_DIVEMODE, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S18_SP_SWITCH(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_SPSWITCH, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S21_GAS_SWITCH(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_GASSWITCH, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S62_DIVE_PLANNER(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_DIVEPLANNER, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S27_LOG(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_LOG, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S41_SET_MENU(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_SETMENU, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S185_INFO(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_INFOR, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S_SLATE(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainMenu_SLATES, MainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S18_SP_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_SPSWITCH);
}
void HandlePreOCFunc_S18_SP_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_SPSWITCH);
}
void UpdPorFunc_S185_INFO()
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_INFOR);
}
void HandlePreOCFunc_S185_INFO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_INFOR);
}
void UpdPorFunc_S41_SET_MENU(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_SETMENU);
}
void HandlePreOCFunc_S41_SET_MENU(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_SETMENU);
}
void UpdPorFunc_S62_DIVE_PLANNER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_DIVEPLANNER);
}
void HandlePreOCFunc_S62_DIVE_PLANNER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_DIVEPLANNER);
}
void UpdPorFunc_S27_LOG(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_LOG);
}
void HandlePreOCFunc_S27_LOG(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_LOG);
}
void UpdPorFunc_S_SLATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_SLATES);
}
void HandlePreOCFunc_S_SLATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_SLATES);
}
void UpdPorFunc_S21_GAS_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_GASSWITCH);
}
void HandlePreOCFunc_S21_GAS_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_GASSWITCH);
}
void UpdPorFunc_S404_TMT_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_TMTSWITCH);
}
void HandlePreOCFunc_S404_TMT_SWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_TMTSWITCH);
}
void UpdPorFunc_S432_DIVE_MODE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainMenu_DIVEMODE);
}
void HandlePreOCFunc_S432_DIVE_MODE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainMenu_DIVEMODE);
}
