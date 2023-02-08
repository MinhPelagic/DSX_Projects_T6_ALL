/******************************************************************************/
//File: DateAndTime.c
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Created
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetDateAndTimeCfg.h"
#include "Menu_DateAndTime.h"
/*SET DATE*/
void IniOrClrScrFunc_S154_SET_DATE(void)
{
    ClearUnusedInList(SettDateTime_Context_MAX);
    HandleDisplayTextWithMemdev(IteStat_Clear, SetDateTime_SetYear_Context); //#tempsoulution
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DATE_TIME));
    for (uint8_t u8_i = SettDateTime_Context_DATE; u8_i < SettDateTime_Context_MAX; u8_i++)
    {
        /*Display all the item in list of DATE and TIME Setting*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, ((SettDateTime_Context_DATE == u8_i) ? IteStat_Select : IteStat_UnSelect), *(pContext_DATEnTIMESETT[u8_i]));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void HandlePreOCFunc_S154_SET_DATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetDateAndTime_DATE);
}
void UpdPorFunc_S154_SET_DATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetDateAndTime_DATE);
}
/*SET TIME*/
void IniOrClrScrFunc_S158_SET_TIME(void)
{
    ClearUnusedInList(SettDateTime_Context_MAX);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DATE_TIME));
    for (uint8_t u8_i = SettDateTime_Context_DATE; u8_i < SettDateTime_Context_MAX; u8_i++)
    {
        /*Display all the item in list of DATE and TIME Setting*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, ((SettDateTime_Context_TIME == u8_i) ? IteStat_Select : IteStat_UnSelect), *(pContext_DATEnTIMESETT[u8_i]));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S158_SET_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetDateAndTime_TIME);
}
void HandlePreOCFunc_S158_SET_TIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetDateAndTime_TIME);
}
/*DATE FORMAT*/
void IniOrClrScrFunc_S150_SET_DATE_FORMAT(void)
{
    ClearUnusedInList(SettDateTime_Context_MAX);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DATE_TIME));
    for (uint8_t u8_i = SettDateTime_Context_DATE; u8_i < SettDateTime_Context_MAX; u8_i++)
    {
        /*Display all the item in list of DATE and TIME Setting*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, ((SettDateTime_Context_DATEFORMAT == u8_i) ? IteStat_Select : IteStat_UnSelect), *(pContext_DATEnTIMESETT[u8_i]));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S150_SET_DATE_FORMAT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetDateAndTime_DATEFORMAT);
}
void HandlePreOCFunc_S150_SET_DATE_FORMAT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetDateAndTime_DATEFORMAT);
}
/*TIME FORMAT*/
void IniOrClrScrFunc_S152_SET_TIME_FORMAT(void)
{
    ClearUnusedInList(SettDateTime_Context_MAX);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DATE_TIME));
    for (uint8_t u8_i = SettDateTime_Context_DATE; u8_i < SettDateTime_Context_MAX; u8_i++)
    {
        /*Display all the item in list of DATE and TIME Setting*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, ((SettDateTime_Context_TIMEFORMAT == u8_i) ? IteStat_Select : IteStat_UnSelect), *(pContext_DATEnTIMESETT[u8_i]));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S152_SET_TIME_FORMAT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetDateAndTime_TIMEFORMAT);
}
void HandlePreOCFunc_S152_SET_TIME_FORMAT(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetDateAndTime_TIMEFORMAT);
}
