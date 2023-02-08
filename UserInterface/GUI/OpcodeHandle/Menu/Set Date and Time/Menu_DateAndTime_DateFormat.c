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

void IniOrClrScrFunc_S150_SET_DATE_FORMAT_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text YEAR*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DATE_FORMAT));
    /*Display DATE FORMAT*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetDateTime_DateFormat_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S150_SET_DATE_FORMAT_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetDateTime_DateFormat_Ctx);
}