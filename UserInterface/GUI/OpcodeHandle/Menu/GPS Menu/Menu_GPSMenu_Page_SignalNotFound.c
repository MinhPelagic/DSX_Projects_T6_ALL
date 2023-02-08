/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_SignalNotFound_00_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SIGNAL_NOT_FOUND_1));
}
const contentDispContext_st GPSMenu_SignalNotFound_00 =
{
    &GPSMenu_SignalNotFound_00_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
/**/
static void GPSMenu_SignalNotFound_01_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SIGNAL_NOT_FOUND_2));
}
const contentDispContext_st GPSMenu_SignalNotFound_01 =
{
    &GPSMenu_SignalNotFound_01_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_03,
};
void IniOrClrScrFunc_S506_GPS_NO_SIGNAL(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_SignalNotFound_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_SignalNotFound_01);
};
