#include "L4X9_includes.h"
#include "DiveMode.h"

void IniOrClrScrFunc_DIVE_SM_ALT_4(void)
{
    ClearPortionToUpdateDiveMode();
    /*Tissue bar*/
    HandleItem_SurfaceMode_Main_TISSUES();
}
void UpdOrFlasFunc_DIVE_SM_ALT_4(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
