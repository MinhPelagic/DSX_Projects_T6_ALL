/******************************************************************************/
//File: DateAndTime.c
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Created
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetDateAndTimeCfg.h"

/*Date format option*/
#define DATESET_TIME_FORMAT                          GUI_12H24H_Format  //Time format 12/24H
#define DATESET_DATE_FORMAT                          GUI_MMDD_Format    //M.D.Y or D.M.Y
#define DATESET_DATE_MONTH                           GUI_SET_MONTH      //Set Month value 0 -> 11 (Jan to Dec)
#define DATESET_DATE_DAY                             GUI_SET_DAY        //Day from 1 up to 31
#define DATESET_DATE_YEAR                            GUI_SET_YEAR       //
#define DATESET_TIME_HOUR                            GUI_SET_HOUR       //
#define DATESET_TIME_MINUTE                          GUI_SET_MINUTE     //
#define DATESET_TIME_AMPM                            AM_PM_FLAT     	//

/*Declare the functions*/
/*Setting DATE and TIME*/
enum SettDateTime_Context_e
{
    SettDateTime_Context_DATE = 0x00,
    SettDateTime_Context_TIME,
    SettDateTime_Context_DATEFORMAT,
    SettDateTime_Context_TIMEFORMAT,
    SettDateTime_Context_MAX,
};
/*Time format option*/
enum TimeFormat_e
{
    TimeFormat_12H = 0x00,
    TimeFormat_24H,
    TimeFormat_MAX,
};
/*Midday format option*/
enum MiddayFormat_e
{
    MiddayFormat_AM = 0x00,
    MiddayFormat_PM,
    MiddayFormat_MAX,
};
/**
Text define for DEPTH LIMITS
*/
enum Month_Setting
{
    Month_JANUARY,
    Month_FEBUARY,
    Month_MARCH,
    Month_APIRAL,
    Month_MAY,
    Month_JUNE,
    Month_JULY,
    Month_AUGUST,
    Month_SEPTEMPER,
    Month_OCTOBER,
    Month_NOVEMBER,
    Month_DECEMBER,
    Month_MAX,
};
enum DateFormat_e
{
    DateFormat_MDY = 0x00,
    DateFormat_DMY,
    DateFormat_MAX,
};
/*Extern variables*/
extern const menuItemContext_ts* pContext_DATEnTIMESETT[];
extern const char* TxtDef_Set_TimeFormat[];
//extern const char* TxtDef_Set_DateFormat[];
extern const char* TxtDef_Set_Midday[];
extern const contentDispContext_st Set_SetDateTime_DateFormat_Ctx;
extern const contentDispContext_st Set_SetDateTime_TimeFormat_Ctx;
extern const contentDispContext_st SetDateTime_SetHour_Context;
extern const contentDispContext_st SetDateTime_SetMin_Context;
extern const contentDispContext_st SetDateTime_SetAmPm_Context;
extern const contentDispContext_st SetDateTime_SetYear_Context;
extern const contentDispContext_st SetDateTime_SetMonth_Context;
extern const contentDispContext_st SetDateTime_SetDay_Context;
extern const char* TxtDef_Set_TimeFormat[TimeFormat_MAX];
