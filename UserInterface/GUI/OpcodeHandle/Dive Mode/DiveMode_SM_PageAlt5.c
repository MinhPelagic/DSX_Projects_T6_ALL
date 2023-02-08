#include "L4X9_includes.h"
#include "DiveMode.h"

void IniOrClrScrFunc_DIVE_SM_ALT_5(void)
{
    ClearPortionToUpdateDiveMode();
    /*Alarm*/
    DiveModeOCHandle_AltPage05_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_SM_ALT_5(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Check display extra large*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Alarm*/
    DiveModeOCHandle_AltPage05_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
