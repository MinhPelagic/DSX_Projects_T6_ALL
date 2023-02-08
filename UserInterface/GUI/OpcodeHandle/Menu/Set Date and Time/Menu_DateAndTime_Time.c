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

/*Set Hour/MIN*/
void IniOrClrScrFunc_S158_SET_HH(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    GUI_SetFont(&FontAaux_6);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(":", Point_DateAndTime_SetTime_Colon->x, Point_DateAndTime_SetTime_Colon->y);
    /*Display sub title text TIME*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TIME));
    HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetHour_Context);
    HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetMin_Context);
    if(GUI_12H24H_Format == NVD_12HR)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetAmPm_Context);
    }
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*HOUR*/
void UpdOrFlasFunc_S158_SET_HH(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetHour_Context);
}
void UpdPorFunc_S158_SET_HH(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetHour_Context);
}
void HandlePreOCFunc_S158_SET_HH(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetHour_Context);
}
/*MIN*/
void UpdOrFlasFunc_S158_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetMin_Context);
}
void UpdPorFunc_S158_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetMin_Context);
}
void HandlePreOCFunc_S158_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetMin_Context);
}
/*AM/PM*/
void UpdOrFlasFunc_S158_SET_AM_PM(void)
{
    if(GUI_12H24H_Format == NVD_12HR)
    {
        HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetAmPm_Context);
    }
    else
    {
        /*Do nothing*/
    }
}
void UpdPorFunc_S158_SET_AM_PM(void)
{
    if(GUI_12H24H_Format == NVD_12HR)
    {
        HandleDisplayTextWithMemdev(IteStat_Flashing, SetDateTime_SetAmPm_Context);
    }
    else
    {
        /*Do nothing*/
    }
}
void HandlePreOCFunc_S158_SET_AM_PM(void)
{
    if(GUI_12H24H_Format == NVD_12HR)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, SetDateTime_SetAmPm_Context);
    }
    else
    {
        /*Do nothing*/
    }
}
