/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_SaveLocation_00_Context(char* pStrRet)
{
    sprintf(pStrRet, " %.7f, %.7f ", GnssGGA.Latitude_DD, GnssGGA.Longitude_DD);
}
const contentDispContext_st GPSMenu_SaveLocation_00 =
{
    &GPSMenu_SaveLocation_00_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
/**/
static void GPSMenu_SaveLocation_01_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAVE_LOCATIONS));
}
const contentDispContext_st GPSMenu_SaveLocation_01 =
{
    &GPSMenu_SaveLocation_01_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_04,
};
void IniOrClrScrFunc_S507_GPS_SAVE_LOCATION_STAT(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_SaveLocation_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_SaveLocation_01);
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
};
void UpdOrFlasFunc_S507_GPS_SAVE_LOCATION_STAT(void)
{
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_SaveLocation_00);
}
