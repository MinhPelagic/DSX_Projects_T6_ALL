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

/*DATE-> DATE FORMAT Context*/
void SETDATE_DATEFORMAT_Context(char* pStrRet)
{
    if(DATESET_DATE_FORMAT)
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_D_M_Y));
    }
    else
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_M_D_Y));
    }
}
/*Context memdev config to SetDateTime_DateFormat*/
const contentDispContext_st Set_SetDateTime_DateFormat_Ctx =
{
    &SETDATE_DATEFORMAT_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetLanguage_Language, //Reuse
};
