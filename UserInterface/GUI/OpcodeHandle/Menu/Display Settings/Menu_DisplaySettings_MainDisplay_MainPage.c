/******************************************************************************/
//File:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

/*3rd Row Right*/
void IniOrClrScrFunc_MAINDISPLAY_RIGHT(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainDisplay_RIGHT, MainDisplay_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_MAINDISPLAY_RIGHT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainDisplay_RIGHT);
}
void HandlePreOCFunc_MAINDISPLAY_RIGHT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainDisplay_RIGHT);
}
/*3rd Row left*/
void IniOrClrScrFunc_MAINDISPLAY_LEFT(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainDisplay_LEFT, MainDisplay_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_MAINDISPLAY_LEFT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainDisplay_LEFT);
}
void HandlePreOCFunc_MAINDISPLAY_LEFT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainDisplay_LEFT);
}
/*GFBR or N2 Bar*/
void IniOrClrScrFunc_MAINDISPLAY_GFBG(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainDisplay_GFBG_OR_N2, MainDisplay_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_MAINDISPLAY_GFBG(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainDisplay_GFBG_OR_N2);
}
void HandlePreOCFunc_MAINDISPLAY_GFBG(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainDisplay_GFBG_OR_N2);
}
/*Extralarge*/
void IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_MainDisplay_EXTRALARGE, MainDisplay_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_MAINDISPLAY_EXTRALARGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_MainDisplay_EXTRALARGE);
}
void HandlePreOCFunc_MAINDISPLAY_EXTRALARGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_MainDisplay_EXTRALARGE);
}