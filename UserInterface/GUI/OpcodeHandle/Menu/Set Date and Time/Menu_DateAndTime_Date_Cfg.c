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

/*Set YEAR*/
static void SetYear_Value_Context(char* pStrRet)
{
    /**/
    sprintf(pStrRet, "20%.2d", DATESET_DATE_YEAR);

}
/*Context memdev config set Year*/
const contentDispContext_st SetDateTime_SetYear_Context =
{
    &SetYear_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_YEAR,
};
/*Set MONTH*/
static void SetMonth_Value_Context(char* pStrRet)
{
    /**/
    sprintf(pStrRet, "%.d", DATESET_DATE_MONTH);
}
/*Context memdev config set Month*/
const contentDispContext_st SetDateTime_SetMonth_Context =
{
    &SetMonth_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_MONTH,
};
/*Set Day*/
static void SetDay_Value_Context(char* pStrRet)
{
    /**/
    sprintf(pStrRet, "%.2d", DATESET_DATE_DAY);

}
/*Context memdev config set Day*/
const contentDispContext_st SetDateTime_SetDay_Context =
{
    &SetDay_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DAY,
};
