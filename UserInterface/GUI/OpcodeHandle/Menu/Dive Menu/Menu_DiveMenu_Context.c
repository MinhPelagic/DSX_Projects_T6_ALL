/******************************************************************************/
//File: DIVE MENU
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDiveMenuCfg.h"
extern uint8_t GFHighSettingValue;

/*Context*/
void DiveMenu_SETSP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_SP));
}
void DiveMenu_SETGASES_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_GASES));
}
void DiveMenu_DIVEPROFILEGRAPH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_PROFILE_GRAPH));
}
void DiveMenu_BAILOUTPO2LIMITS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BAILOUT_PO2_LIMITS));
}
void DiveMenu_PO2LIMITS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PO2_LIMITS));
}
void DiveMenu_DECOSTOPS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DECO_STOP));
}
void DiveMenu_SETGFHIGH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_GF_HIGH));
}
void DiveMenu_SETGFHIGH_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d", GFHighSettingValue);
}