/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_DeleteLocation_00_Context(char* pStrRet)
{
    sprintf(pStrRet, "%.6f, %.6f", Target_Loc.Latitude, Target_Loc.Longitude);
}
const contentDispContext_st GPSMenu_DeleteLocation_00 =
{
    &GPSMenu_DeleteLocation_00_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
/**/
static void GPSMenu_DeleteLocation_01_Context(char* pStrRet)
{
    strcpy(pStrRet, Target_Loc.LocationName);
}
const contentDispContext_st GPSMenu_DeleteLocation_01 =
{
    &GPSMenu_DeleteLocation_01_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_03,
};
/**/
static void GPSMenu_DeleteLocation_02_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DELETE_LOCATION));
}
const contentDispContext_st GPSMenu_DeleteLocation_02 =
{
    &GPSMenu_DeleteLocation_02_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_04,
};
void IniOrClrScrFunc_S522_GPS_DELETE_LOCATION(void)
{
    GUI_Clear();
    DisplayIconGPS(GUI_CYAN);
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocation_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocation_01);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocation_02);
    /*Bottom icons*/
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
};