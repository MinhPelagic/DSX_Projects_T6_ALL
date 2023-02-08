/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/*GET CURRENT LOCATION*/
void IniOrClrScrFunc_S502_GPS_GET_CURRENT_LOCATION(void)
{
    GUI_Clear();
    /*Tittle*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_GPS_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_GPSMenu_SAVECURRENTLOCATION, GPSMenuListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S502_GPS_GET_CURRENT_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_GPSMenu_SAVECURRENTLOCATION);
}
void HandlePreOCFunc_S502_GPS_GET_CURRENT_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_GPSMenu_SAVECURRENTLOCATION);
}
/*WAY FINDER*/
void IniOrClrScrFunc_S509_GPS_WAYFINDER(void)
{
    ClearUnusedInList(0);
    /*Tittle*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_GPS_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_GPSMenu_WAYFINDER, GPSMenuListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S509_GPS_WAYFINDER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_GPSMenu_WAYFINDER);
}
void HandlePreOCFunc_S509_GPS_WAYFINDER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_GPSMenu_WAYFINDER);
}
/*DELETE LOCATION*/
void IniOrClrScrFunc_S520_GPS_DELETE_LOCATION(void)
{
    ClearUnusedInList(0);
    /*Tittle*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_GPS_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_GPSMenu_DELETELOCATION, GPSMenuListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S520_GPS_DELETE_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_GPSMenu_DELETELOCATION);
}
void HandlePreOCFunc_S520_GPS_DELETE_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_GPSMenu_DELETELOCATION);
}
