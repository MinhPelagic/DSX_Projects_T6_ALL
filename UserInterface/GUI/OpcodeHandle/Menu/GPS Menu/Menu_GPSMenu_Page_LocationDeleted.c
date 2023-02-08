/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_LocationDeleted_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOCATION_DELETED));
}
const contentDispContext_st GPSMenu_LocationDeleted =
{
    &GPSMenu_LocationDeleted_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_03,
};
/**
 * @brief Deleted location page after confirm
 *
 */
void IniOrClrScrFunc_S523_GPS_LOCATION_DELETED(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_LocationDeleted);
    Display_Icon_Buttons(IconBottDisp_RightOnly_Select);
};
