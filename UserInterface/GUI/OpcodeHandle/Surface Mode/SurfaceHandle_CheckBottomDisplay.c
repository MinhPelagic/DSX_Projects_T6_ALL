#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "..\Dive Mode\DiveMode.h"

/*Check display in the bottom of main page CC mode*/
void SurfaceMode_CC_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs*/
    if(SurfaceModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        if(CheckIfGasToTMT_Assigned())
        {
            /*Pressure display*/
            SurfaceHandle_PressureDisplay();
        }
        else
        {
            /*Do nothing*/
        }
        /*FO2*/
        DiveModeHandle_DisplayFO2();
    }
}
/*Check display in the bottom of main page CC mode*/
void SurfaceMode_GSM_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs*/
    if(SurfaceModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*Display either OC-L or OC-R or Both*/
        if(CheckIfGasToTMT_Assigned())
        {
            /*When TMT left and right has assigned*/
            if(SurfaceCheckTMTLeftRightStatus())
            {
                SurfaceHandle_DisplayTMT_LR();
                /*Alarm Switch tank arrow flashing -> Only when switch TMT between L-R*/
                DiveModeAlarm_SwitchTankArrow();
            }
            else
            {
                /*Pressure*/
                SurfaceHandle_PressureDisplay();
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_TMT_Value);
            }
        }
        else
        {
            /*Do nothing*/
        }
    }
}
/*
Content in the bottom
Alternate display between OC-L/R and alarm
*/
void SurfaceMode_SM_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(SurfaceModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*Display either OC-L or OC-R or Both*/
        if(CheckIfGasToTMT_Assigned())
        {
            /*When TMT left and right has assigned*/
            if(SurfaceCheckTMTLeftRightStatus())
            {
                SurfaceHandle_DisplayTANK_LR();
                /*Alarm Switch tank arrow flashing -> Only when switch TMT between L-R*/
                DiveModeAlarm_SwitchTankArrow();
            }
            else
            {
                /*FO2*/
                DiveModeHandle_DisplayFO2();
                /*Pressure*/
                SurfaceHandle_PressureDisplay();
            }
        }
        else
        {
            if(SurfaceCheckTMTLeftRightStatus())
            {
                /*Do nothing*/
            }
            else
            {
                /*When NO TMT is linked -> Display the FO2 with GAS 3/4/5/6 (not L/R because it already display on 3rd row*/
                DiveModeHandle_DisplayFO2();
            }

        }
    }
}
