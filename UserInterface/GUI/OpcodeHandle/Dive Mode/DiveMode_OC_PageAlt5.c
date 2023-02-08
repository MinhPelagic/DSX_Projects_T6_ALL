#include "L4X9_includes.h"
#include "DiveMode.h"
/**
 * @brief IniOrClrScrFunc_DIVE_OC_ALT_5
 *
 */
void IniOrClrScrFunc_DIVE_OC_ALT_5(void)
{
    ClearPortionToUpdateDiveMode();
    /*Bottom*/
    DiveModeOCHandle_AltPage05_CheckDisplayBottom();
}
/**
 * @brief UpdOrFlasFunc_DIVE_OC_ALT_5
 *
 */
void UpdOrFlasFunc_DIVE_OC_ALT_5(void)
{
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    DiveModeOCHandle_AltPage05_CheckDisplayBottom();
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
/**
 * @brief Alternate page 5
 *
 */
void DiveModeOCHandle_AltPage05_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*END*/
        DiveModeHandle_Display_OC_END(IteStat_Initial);
        /*WOB*/
        DiveModeHandle_Display_OC_WOB(IteStat_Initial);
        /*MOD*/
        DiveModeHandle_Display_OC_MOD(IteStat_Initial);
    }
}
