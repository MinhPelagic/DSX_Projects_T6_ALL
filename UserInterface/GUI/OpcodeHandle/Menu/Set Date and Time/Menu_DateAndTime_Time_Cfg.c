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

const char* TxtDef_Set_TimeFormat[TimeFormat_MAX] =
{
    "12H",
    "24H",
};
const char* TxtDef_Set_Midday[MiddayFormat_MAX] =
{
    "AM",
    "PM",
};

/*Set Hour*/
static void SetHour_Value_Context(char* pStrRet)
{
    /**/
    uint8_t _12h_conv = 0;
    //uint8_t MidNight;
    if(GUI_12H24H_Format == NVD_12HR)
    {
        ret12Hfrom24H(DATESET_TIME_HOUR, &_12h_conv, & MidNight);
        sprintf(pStrRet, " %.2d ", _12h_conv);
    }
    else
    {
        sprintf(pStrRet, " %.2d ", DATESET_TIME_HOUR);
    }
}
/*Context memdev config set Hour*/
const contentDispContext_st SetDateTime_SetHour_Context =
{
    &SetHour_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_HOUR,
};
/*Set Minute*/
static void SetMin_Value_Context(char* pStrRet)
{
    /**/
    sprintf(pStrRet, " %.2d ", DATESET_TIME_MINUTE);
}
/*Context memdev config set Minutes*/
const contentDispContext_st SetDateTime_SetMin_Context =
{
    &SetMin_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_MIN,
};
/*Set AM/PM*/
static void SetAmPm_Value_Context(char* pStrRet)
{
    /**/
    strcpy(pStrRet, TxtDef_Set_Midday[DATESET_TIME_AMPM]);
}
/*Context memdev config set Am/Pm*/
const contentDispContext_st SetDateTime_SetAmPm_Context =
{
    &SetAmPm_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_AmPm,
};
