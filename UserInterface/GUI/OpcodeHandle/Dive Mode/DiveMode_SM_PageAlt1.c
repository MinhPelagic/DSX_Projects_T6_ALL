#include "L4X9_includes.h"
#include "DiveMode.h"

void IniOrClrScrFunc_DIVE_SM_ALT_1(void)
{
    ClearPortionToUpdateDiveMode();
    /*Alarm in the bottom*/
    DiveModeOCHandle_AltPage01_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_SM_ALT_1(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Alarm in the bottom*/
    DiveModeOCHandle_AltPage01_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
