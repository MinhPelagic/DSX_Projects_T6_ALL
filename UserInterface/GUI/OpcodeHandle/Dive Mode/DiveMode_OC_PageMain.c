#include "L4X9_includes.h"
#include "DiveMode.h"
static void DiveModeOCHandle_MainPage_CheckDisplayBottom(void)
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
        /*This option specific when Violation only : display GTR*/
        DiveModeHandle_Violation_Display_GTRBottom();
    }
}
static void hanldeClearScrDiveMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if((DIVE_OC_ALT_1==pre_DSX_Opcode)||(DIVE_OC_ALT_5==pre_DSX_Opcode))
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_DIVE_OC_MAIN(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_CYAN);
    hanldeClearScrDiveMainPage();
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
    DiveModeOCHandle_MainPage_CheckDisplayBottom();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
}
void UpdOrFlasFunc_DIVE_OC_MAIN(void)
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
    /*Display bottom*/
    DiveModeOCHandle_MainPage_CheckDisplayBottom();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
}
