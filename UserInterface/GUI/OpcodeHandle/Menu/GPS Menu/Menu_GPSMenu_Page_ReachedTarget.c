/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_YouReachTarget_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_YOU_REACH_TO_YOUR_TARGET));
}
const contentDispContext_st GPSMenu_YouReachTarget =
{
    &GPSMenu_YouReachTarget_Context,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_03,
};

void IniOrClrScrFunc_S518_GPS_WAYFINDERLOCATION_REACHED(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_GREEN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_YouReachTarget);
    Display_Icon_Buttons(IconBottDisp_RightOnly_Select);
};