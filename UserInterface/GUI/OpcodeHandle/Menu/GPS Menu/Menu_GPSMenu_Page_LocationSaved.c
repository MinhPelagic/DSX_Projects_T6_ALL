/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_LocationSaved_00_Context(char* pStrRet)
{
    sprintf(pStrRet, " %.7f, %.7f ", GnssGGA.Latitude_DD, GnssGGA.Longitude_DD);
}
const contentDispContext_st GPSMenu_LocationSaved_00 =
{
    &GPSMenu_LocationSaved_00_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
/**/
static void GPSMenu_LocationSaved_01_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOCATION_SAVED));
}
const contentDispContext_st GPSMenu_LocationSaved_01 =
{
    &GPSMenu_LocationSaved_01_Context,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_04,
};
void IniOrClrScrFunc_S508_GPS_LOCATION_SAVED(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_LocationSaved_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_LocationSaved_01);
    Display_Icon_Buttons(IconBottDisp_HomeSelect);
};
