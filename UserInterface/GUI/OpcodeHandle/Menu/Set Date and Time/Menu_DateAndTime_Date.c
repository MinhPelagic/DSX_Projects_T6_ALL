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

void IniOrClrScrFunc_S154_SET_YY(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text YEAR*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DATE));
    /*Display YEAR/MONTH/DATE*/
    GUI_SetFont(&FontAaux_6);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    /*Display 2 slashes*/
    GUI_DispStringAt("/", Point_DateAndTime_Slash_01->x, Point_DateAndTime_Slash_01->y);
    GUI_DispStringAt("/", Point_DateAndTime_Slash_02->x, Point_DateAndTime_Slash_02->y);
    /*Display YEAR*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetYear_Context);
    /*Display MONTH*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetMonth_Context);
    /*Display DAY*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetDay_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*MONTH*/
void UpdOrFlasFunc_S154_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetMonth_Context);
}
void UpdPorFunc_S154_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetMonth_Context);
}
void HandlePreOCFunc_S154_SET_MM(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetMonth_Context);
}
/*DAY*/
void UpdOrFlasFunc_S154_SET_DD(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetDay_Context);
}
void UpdPorFunc_S154_SET_DD(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetDay_Context);
}
void HandlePreOCFunc_S154_SET_DD(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetDay_Context);
}
/*YEAR*/
void UpdOrFlasFunc_S154_SET_YY(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetYear_Context);
}
void UpdPorFunc_S154_SET_YY(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetDateTime_SetYear_Context);
}
void HandlePreOCFunc_S154_SET_YY(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SetDateTime_SetYear_Context);
}
