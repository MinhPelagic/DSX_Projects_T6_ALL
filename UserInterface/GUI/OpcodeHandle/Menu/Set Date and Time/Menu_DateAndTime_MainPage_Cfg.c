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

/*Handle DATE&TIME SETTINGS context*/
const menuItemContext_ts* pContext_DATEnTIMESETT[SettDateTime_Context_MAX]=
{
    &Context_SetDateAndTime_DATE,
    &Context_SetDateAndTime_TIME,
    &Context_SetDateAndTime_DATEFORMAT,
    &Context_SetDateAndTime_TIMEFORMAT,
};

/*TIME FORMAT context*/
void SetDateAndTime_TIMEFORMAT_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME_FORMAT));
}
void SetDateAndTime_TIMEFORMAT_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, TxtDef_Set_TimeFormat[DATESET_TIME_FORMAT]);
}
/*DATE FORMAT context*/
void SetDateAndTime_DATEFORMAT_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DATE_FORMAT));
}
void SetDateAndTime_DATEFORMAT_Context_Right(char* pStrRet)
{
    //strcpy(pStrRet, TxtDef_Set_DateFormat[DATESET_DATE_FORMAT]);
    if(DATESET_DATE_FORMAT) {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_D_M_Y));
    }
    else {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_M_D_Y));
    }
}
/*DATE Context*/
void SetDateAndTime_DATE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DATE));
}
void SetDateAndTime_DATE_Context_Right(char* pStrRet)
{
    if(GUI_MMDD_Format == NVD_MD)
    {   /*month, day*/
        sprintf(pStrRet,
                "%d/%.2d/20%.2d",
                DATESET_DATE_MONTH,
                DATESET_DATE_DAY,
                DATESET_DATE_YEAR
               );
    }
    else
    {   /*day, month*/
        sprintf(pStrRet,
                "%.2d/%d/20%.2d",
                DATESET_DATE_DAY,
                DATESET_DATE_MONTH,
                DATESET_DATE_YEAR
               );
    }

}
/*TIME context*/
void SetDateAndTime_TIME_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME));
}
void SetDateAndTime_TIME_Context_Right(char* pStrRet)
{
    uint8_t _12h_conv = 0;
    uint8_t MidNight;
    if(GUI_12H24H_Format == NVD_12HR)
    {
        ret12Hfrom24H(	DATESET_TIME_HOUR, &_12h_conv, & MidNight);
        sprintf(pStrRet, "%.2d:%.2d %s", _12h_conv, DATESET_TIME_MINUTE, TxtDef_Set_Midday[MidNight]);
    }
    else {
        sprintf(pStrRet, "%.2d:%.2d ", DATESET_TIME_HOUR, DATESET_TIME_MINUTE);
    }
}
