/******************************************************************************/
//File: OCSepia.h
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Created
//
/*****************************************************************************/
#ifndef _OPCODE_DSX_H__
#define _OPCODE_DSX_H__

#define MainMode      				USER_Set.DiveMode               // DSX USER_Set.DiveMode for CC, OC, SM, GaugeSM, Gauge, BO
#define INIT_OPCODE                 0x2000
/*Language define*/
#define LANGUAGE					GUI_LANG_Select
#define Language_Update				Language_Present = LANGUAGE
#define ColorTitle_Value			0

/*Define the setting status*/
enum
{
    Setting_OFF = 0x00,
    Setting_ON,
    Setting_SET,
    Setting_MAX,
};
/*Define extra large setting status*/
enum
{
    Setting_ExtraLarge_OFF = 0x00,
    Setting_ExtraLarge_DEPTH,
    Setting_ExtraLarge_DIVETIME,
    Setting_ExtraLarge_MAX,
};
/*Define the setting status*/
enum
{
    SettYesNo_YES = 0x00,
    SettYesNo_NO,
    SettYesNo_MAX
};
/*Main menu in Dive/Setting*/
enum
{
    DIVEMODE_CC = 0x00,
    DIVEMODE_OC,
    DIVEMODE_SM,
    DIVEMODE_GAUGSM,
    DIVEMODE_GAUG,
    DIVEMODE_BO, /*Bailout*/
    DIVEMODE_MAX,
};
#define Imperial                        (!UNITS)
#define TemperatureF                    TP_Info.AverageTemperature_F
#define TemperatureC                    TP_Info.AverageTemperature_C
#define ELEVATION						Dive_Info.AltitudeLevel                 // DSX Elevation Level
#define COMP_DEDLIN_DEG                 USER_Set.CompassDeclinationDeg          // signed -45 to +45
#define COMP_PELAGIC_DEG                (int16_t)350                            // A Correction to make DSX to be consistent with Pelagic Old Products' compass reading
/*If the data input is not in list dive mode then return to default is CC*/

#endif
