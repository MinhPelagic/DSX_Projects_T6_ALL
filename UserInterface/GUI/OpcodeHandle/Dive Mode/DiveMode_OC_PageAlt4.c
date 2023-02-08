#include "L4X9_includes.h"
#include "DiveMode.h"

void IniOrClrScrFunc_DIVE_OC_ALT_4(void)
{
    ClearPortionToUpdateDiveMode();
    /*Tissue bar*/
    HandleItem_SurfaceMode_Main_TISSUES();
}
void UpdOrFlasFunc_DIVE_OC_ALT_4(void)
{
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Display PO2, 3rd row left right*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
