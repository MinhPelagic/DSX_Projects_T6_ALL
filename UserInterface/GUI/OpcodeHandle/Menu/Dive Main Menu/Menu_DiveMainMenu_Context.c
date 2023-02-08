/******************************************************************************/
//File: DiveMainMenu_Context.c
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDiveMainMenuCfg.h"

void DiveMainMenu_SPSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SP_SWITCH));
}
void DiveMainMenu_GASSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GAS_SWITCH));
}
void DiveMainMenu_SWITCH_CC_TO_BO_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SWITCH_CC_TO_BO));
}
void DiveMainMenu_SWITCH_BO_TO_CC_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SWITCH_BO_TO_CC));
}
void DiveMainMenu_BRIGHTNESS_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BRIGHTNESS));
}
void DiveMainMenu_DIVEMENU_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_MENU));
}
void DiveMainMenu_SLATES_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SLATES));
}
void DiveMainMenu_TMTSWITCH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_SWITCH));
}
void DiveMainMenu_RESETAVGDEPTH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESET_AGV_DEPTH));
}
void DiveMainMenu_DIVEPROFILEGRAPH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_PROFILE_GRAPH));
}

