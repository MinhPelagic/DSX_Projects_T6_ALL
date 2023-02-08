/******************************************************************************/
//File: SET MENU -> Initilialize GPS
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"
/**/
static void GPSMenu_DeleteLocationToSaveNew_00_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SAVE_LOCATION_1));
}
const contentDispContext_st GPSMenu_DeleteLocationToSaveNew_00 =
{
    &GPSMenu_DeleteLocationToSaveNew_00_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_00,
};
/**/
static void GPSMenu_DeleteLocationToSaveNew_01_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SAVE_LOCATION_2));
}
const contentDispContext_st GPSMenu_DeleteLocationToSaveNew_01 =
{
    &GPSMenu_DeleteLocationToSaveNew_01_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_01,
};
/**/
static void GPSMenu_DeleteLocationToSaveNew_02_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_SAVE_LOCATION_3));
}
const contentDispContext_st GPSMenu_DeleteLocationToSaveNew_02 =
{
    &GPSMenu_DeleteLocationToSaveNew_02_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GPS_Page_Txt_02,
};
void IniOrClrScrFunc_S503_GPS_20DATA_DELETE_TO_SAVE(void)
{
    GUI_Clear();
    /*Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocationToSaveNew_00);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocationToSaveNew_01);
    HandleDisplayTextWithMemdev(IteStat_Select, GPSMenu_DeleteLocationToSaveNew_02);
};