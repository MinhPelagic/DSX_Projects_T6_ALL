#include "L4X9_includes.h"
#include "ContextDiveMainMenuCfg.h"
#include "DiveMainMenu.h"

/*GAS SWITCH*/
void IniOrClrScrFunc_DIVEMAINMENU_GASSWITCH(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_GASSWITCH, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_GASSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_GASSWITCH);
}
void HandlePreOCFunc_DIVEMAINMENU_GASSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_GASSWITCH);
}
/*BRIGHTNESS*/
void IniOrClrScrFunc_DIVEMAINMENU_BRIGHTNESS(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_BRIGHTNESS, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_BRIGHTNESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_BRIGHTNESS);
}
void HandlePreOCFunc_DIVEMAINMENU_BRIGHTNESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_BRIGHTNESS);
}
/*DIVEMAINMENU_DIVEMENU*/
void IniOrClrScrFunc_DIVEMAINMENU_DIVEMENU(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_DIVEMENU, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_DIVEMENU(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_DIVEMENU);
}
void HandlePreOCFunc_DIVEMAINMENU_DIVEMENU(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_DIVEMENU);
}
/*DIVEMAINMENU_SLATES*/
void IniOrClrScrFunc_DIVEMAINMENU_SLATES(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_SLATES, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_SLATES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_SLATES);
}
void HandlePreOCFunc_DIVEMAINMENU_SLATES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_SLATES);
}
/*DIVEMAINMENU_TMTSWITCH*/
void IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_TMTSWITCH, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_TMTSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_TMTSWITCH);
}
void HandlePreOCFunc_DIVEMAINMENU_TMTSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_TMTSWITCH);
}
/*DIVEMAINMENU_RESETAVGDEPTH*/
void IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_RESETAVGDEPTH, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_RESETAVGDEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_RESETAVGDEPTH);
}
void HandlePreOCFunc_DIVEMAINMENU_RESETAVGDEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_RESETAVGDEPTH);
}
/*DIVEMAINMENU_DIVEPROFILE*/
void IniOrClrScrFunc_DIVEMAINMENU_DIVEPROFILE(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_DIVEPROFILEGRAPH, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_DIVEPROFILE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_DIVEPROFILEGRAPH);
}
void HandlePreOCFunc_DIVEMAINMENU_DIVEPROFILE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_DIVEPROFILEGRAPH);
}
/*DIVEMAINMENU_SPSWITCH*/
void IniOrClrScrFunc_DIVEMAINMENU_SPSWITCH(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_SPSWITCH, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_SPSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_SPSWITCH);
}
void HandlePreOCFunc_DIVEMAINMENU_SPSWITCH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_SPSWITCH);
}
/*DIVEMAINMENU_SWITCHCC2BO*/
void IniOrClrScrFunc_DIVEMAINMENU_SWITCHCC2BO(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_SWITCH_CC_TO_BO, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_SWITCHCC2BO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_SWITCH_CC_TO_BO);
}
void HandlePreOCFunc_DIVEMAINMENU_SWITCHCC2BO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_SWITCH_CC_TO_BO);
}
/*DIVEMAINMENU_SWITCHCC2BO*/
void IniOrClrScrFunc_DIVEMAINMENU_SWITCHBO2CC(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveMainMenu_SWITCH_BO_TO_CC, DiveMainMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_DIVEMAINMENU_SWITCHBO2CC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveMainMenu_SWITCH_BO_TO_CC);
}
void HandlePreOCFunc_DIVEMAINMENU_SWITCHBO2CC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveMainMenu_SWITCH_BO_TO_CC);
}
