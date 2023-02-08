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

/*Context memdev config to SetDateTime_TimeFormat*/
void SetDateAndTime_TIMEFORMAT_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", TxtDef_Set_TimeFormat[DATESET_TIME_FORMAT]);
}
const contentDispContext_st Set_SetDateTime_TimeFormat_Ctx =
{
    &SetDateAndTime_TIMEFORMAT_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
