/******************************************************************************/
//File: SET MENU
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetMenuCfg.h"
extern const listItemInMenu_ts* SetMenu_ListOfContext[DIVEMODE_MAX];
/**/
void IniOrClrScrFunc_S42_SET_GASES(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_SETGAS, SetMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
};
void IniOrClrScrFunc_S53_SET_SP(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_SETSP, SetMenu_ListOfContext);
};
void IniOrClrScrFunc_S149_DATE_TIME(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_DATETIME, SetMenu_ListOfContext);
};
void IniOrClrScrFunc_S_DIVE_SETTINGS(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_DIVESETTINGS, SetMenu_ListOfContext);
};
void IniOrClrScrFunc_S105_ALARMS(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_ALARMS, SetMenu_ListOfContext);
};
void IniOrClrScrFunc_S128_DEVICE_SETTINGS(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_DEVICESETTINGS, SetMenu_ListOfContext);
}
void IniOrClrScrFunc_S161_DISPLAY_SETTINGS(void)
{
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetMenu_DISPLAYSETTINGS, SetMenu_ListOfContext);
}
/**/
void UpdPorFunc_S42_SET_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_SETGAS);
}
void HandlePreOCFunc_S42_SET_GASES(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_SETGAS);
}
void UpdPorFunc_S53_SET_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_SETSP);
}
void HandlePreOCFunc_S53_SET_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_SETSP);
}
void UpdPorFunc_S_DIVE_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_DIVESETTINGS);
}
void HandlePreOCFunc_S_DIVE_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_DIVESETTINGS);
}
void UpdPorFunc_S105_ALARMS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_ALARMS);
}
void HandlePreOCFunc_S105_ALARMS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_ALARMS);
}
void UpdPorFunc_S128_DEVICE_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_DEVICESETTINGS);
}
void HandlePreOCFunc_S128_DEVICE_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_DEVICESETTINGS);
}
void UpdPorFunc_S149_DATE_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_DATETIME);
}
void HandlePreOCFunc_S149_DATE_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_DATETIME);
}
void UpdPorFunc_S161_DISPLAY_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetMenu_DISPLAYSETTINGS);
}
void HandlePreOCFunc_S161_DISPLAY_SETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetMenu_DISPLAYSETTINGS);
}