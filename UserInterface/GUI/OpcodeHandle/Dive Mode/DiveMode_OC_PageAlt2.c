#include "L4X9_includes.h"
#include "DiveMode.h"
/*Alternate page 2*/
void DiveModeOCHandle_AltPage02_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*Max Depth*/
        DiveModeHandle_Display_OC_MaxDepth(IteStat_Initial);
        /*Average Depth*/
        DiveModeHandle_Display_OC_AvgDepth(IteStat_Initial);
        /*Ceiling*/
        DiveModeHandle_Display_OC_Ceiling(IteStat_Initial);
    }
}
void IniOrClrScrFunc_DIVE_OC_ALT_2(void)
{
    ClearPortionToUpdateDiveMode();
    /*Alaternate page OC -> with alarm*/
    DiveModeOCHandle_AltPage02_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_OC_ALT_2(void)
{
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    DiveModeOCHandle_AltPage02_CheckDisplayBottom();
    /*Display PO2, 3rd row left right*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
