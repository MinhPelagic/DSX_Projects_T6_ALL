/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"

void GPSMenu_SAVECURRENTLOCATION_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAVE_CURRENT_LOCATION));
}
void GPSMenu_WAYFINDER_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WAYFINDER));
}
void GPSMenu_DELETELOCATION_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS_DELETE_LOCATION));
}