/******************************************************************************/
//File: SET MENU
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetMenuCfg.h"
/*Manual implement the context content*/
void SetMenu_SETGAS_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_SET_GASES));
}
void SetMenu_SETSP_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_SET_SP));
}
void SetMenu_DIVESETTINGS_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_DIVE_SETTING));
}
void SetMenu_ALARMS_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_ALARMS));
}
void SetMenu_DEVICESETTINGS_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
}
void SetMenu_DATETIME_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_DATE_TIME));
}
void SetMenu_DISPLAYSETTINGS_Context_Center(char* pStrInput)
{
    sprintf(pStrInput, "%s", GUI_LANG_GetText(TxtStr_DISPLAY_SETTING));
}