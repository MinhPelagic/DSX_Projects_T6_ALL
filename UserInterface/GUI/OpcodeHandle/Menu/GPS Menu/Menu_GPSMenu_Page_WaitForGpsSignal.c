/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_WaitForGpsSignal_00_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SIGNAL_WAITING_1));
}
const contentDispContext_st GPSMenu_WaitForGpsSignal_00 =
{
    &GPSMenu_WaitForGpsSignal_00_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
/**/
static void GPSMenu_WaitForGpsSignal_01_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SIGNAL_WAITING_2));
}
const contentDispContext_st GPSMenu_WaitForGpsSignal_01 =
{
    &GPSMenu_WaitForGpsSignal_01_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_03,
};
void IniOrClrScrFunc_S505_GPS_WAIT_SIGNAL(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_WaitForGpsSignal_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_WaitForGpsSignal_01);
};
void UpdOrFlasFunc_S505_GPS_WAIT_SIGNAL(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, GPSMenu_WaitForGpsSignal_01);
};