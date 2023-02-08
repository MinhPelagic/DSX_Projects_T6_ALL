/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

extern STRING_LANG StrLang_Select[];

/*Function handle to each Opcode*/
void IniOrClrScrFunc_S162_DISPLAY_BRIGHTNESS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_BRIGHTNESS, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S162_DISPLAY_BRIGHTNESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_BRIGHTNESS);
}
void HandlePreOCFunc_S162_DISPLAY_BRIGHTNESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_BRIGHTNESS);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S164_DISPLAY_AUTODIM(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_AUTODIM, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S164_DISPLAY_AUTODIM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_AUTODIM);
}
void HandlePreOCFunc_S164_DISPLAY_AUTODIM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_AUTODIM);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S173_DISPLAY_TITLESCOLOR(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_TITLECOLOR, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S173_DISPLAY_TITLESCOLOR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_TITLECOLOR);
}
void HandlePreOCFunc_S173_DISPLAY_TITLESCOLOR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_TITLECOLOR);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S179_DISPLAY_LANGUAGE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_LANGUAGE, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S179_DISPLAY_LANGUAGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_LANGUAGE);
}
void HandlePreOCFunc_S179_DISPLAY_LANGUAGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_LANGUAGE);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S178_DISPLAY_FLIPSCREEN(void)
{
    /*Check the status when flipscreen is changed*/
    if(pre_DSX_Opcode == DISPLAY_FLIPSCREEN_SET)
    {
        GUI_DISPLAY_Update();
    }
    else
    {
        /*Do nothing*/
    }
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_FLIPSCREEN, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    Backlight_Set(USER_Set.BacklightLevel);
}
void UpdPorFunc_S178_DISPLAY_FLIPSCREEN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_FLIPSCREEN);
}
void HandlePreOCFunc_S178_DISPLAY_FLIPSCREEN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_FLIPSCREEN);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S166_DISPLAY_MAINDISPLAY(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_MAINDISPLAY, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S166_DISPLAY_MAINDISPLAY(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_MAINDISPLAY);
}
void HandlePreOCFunc_S166_DISPLAY_MAINDISPLAY(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_MAINDISPLAY);
}
/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S372_DISPLAY_GTR(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_GTR_LEF_RIGHT, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S372_DISPLAY_GTR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_GTR_LEF_RIGHT);
}
void HandlePreOCFunc_S372_DISPLAY_GTR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_GTR_LEF_RIGHT);
}

/*----------------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_S428_DISPLAY_EXTRALARGE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DispSett_EXTRALARGE, DisplaySettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S428_DISPLAY_EXTRALARGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DispSett_EXTRALARGE);
}
void HandlePreOCFunc_S428_DISPLAY_EXTRALARGE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DispSett_EXTRALARGE);
}
