/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"

void DisplayIconGPS(GUI_COLOR color)
{
    GUI_SetColor(color);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_SetFont(&FontAaux_7);
    GUI_DispStringAt("\xcb\x84", 160, 20); //GPS character
}
/**/
static void GPSMenu_InitializingGPS_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_INITIALIZING_GPS));
}
const contentDispContext_st GPSMenu_InitializingGPS =
{
    &GPSMenu_InitializingGPS_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
void IniOrClrScrFunc_S504_GPS_INIT(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_InitializingGPS);
};
void UpdOrFlasFunc_S504_GPS_INIT(void)
{
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, GPSMenu_InitializingGPS);
};
