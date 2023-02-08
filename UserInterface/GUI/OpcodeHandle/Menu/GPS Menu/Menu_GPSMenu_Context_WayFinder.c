/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"
#include "Menu_GPSMenu.h"

void WayFinder_EXITFROMWAYFINDER_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_EXIT_FROM_WAYFINDER));
}
void WayFinder_CHANGETARGETLOCATION_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CHANGE_TARGET_LOCATION));
}
