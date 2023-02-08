#include "L4X9_includes.h"
#include "DiveMode.h"
static void DiveModeCCHandle_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        if(CheckIfGasToTMT_Assigned())
        {
            /*Pressure only display when any TMTs be assigned*/
            SurfaceHandle_PressureDisplay();
        }
        else
        {
            /*Clear the portion -> Display empty*/
            ClearPortion_TankPressure();
        }
        /*FO2*/
        DiveModeHandle_DisplayFO2();
        /*Keep clear prevent overlap*/
        ClearPortionCCLeftRight();
    }
}
static void hanldeClearScrDiveCC_MainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if((DIVE_CC_ALT_1==pre_DSX_Opcode)||(DIVE_CC_ALT_5==pre_DSX_Opcode))
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_DIVE_CC_MAIN(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_CYAN);
    hanldeClearScrDiveCC_MainPage();
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    DiveModeCCHandle_MainPage_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_CC_MAIN(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Display bottom*/
    DiveModeCCHandle_MainPage_CheckDisplayBottom();
}
