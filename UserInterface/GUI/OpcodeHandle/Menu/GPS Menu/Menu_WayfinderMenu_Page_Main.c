/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/*WAYFINDER -> EXIT*/
void IniOrClrScrFunc_S519_GPS_WAYFINDER_EXIT(void)
{
    GUI_Clear();
    /*Tittle*/
    DisplayText_TopBar_Title("WAYFINDER MENU");
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_WayFinder_EXITFROMWAYFINDER, WayFinderListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S519_GPS_WAYFINDER_EXIT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_WayFinder_EXITFROMWAYFINDER);
}
void HandlePreOCFunc_S519_GPS_WAYFINDER_EXIT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_WayFinder_EXITFROMWAYFINDER);
}
/*WAYFINDER -> LOCATION*/
void IniOrClrScrFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void)
{
    GUI_Clear();
    /*Tittle*/
    DisplayText_TopBar_Title("WAYFINDER MENU");
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_WayFinder_CHANGETARGETLOCATION, WayFinderListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_WayFinder_CHANGETARGETLOCATION);
}
void HandlePreOCFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_WayFinder_CHANGETARGETLOCATION);
}
