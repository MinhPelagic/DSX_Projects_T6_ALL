/******************************************************************************/
//File: MAIN MENU
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextMainMenuCfg.h"
/*Context*/
void MainMenu_SPSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SP_SWITCH));
}
void MainMenu_GASSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GAS_SWITCH));
}
void MainMenu_DIVEPLANNER_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_PLANNER));
}
void MainMenu_LOG_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOG));
}
void MainMenu_SETMENU_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_MENU));
}
void MainMenu_INFOR_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_INFOR));
}
void MainMenu_SLATES_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SLATES));
}
void MainMenu_TMTSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_SWITCH));
}
void MainMenu_DIVEMODE_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_MODE));
}