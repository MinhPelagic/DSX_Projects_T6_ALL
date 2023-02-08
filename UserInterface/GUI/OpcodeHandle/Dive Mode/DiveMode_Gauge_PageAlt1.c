#include "L4X9_includes.h"
#include "DiveMode.h"
/*handle display Alarms <-> No Alarms*/
static void DiveModeGaugeHandle_AltPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*TIME*/
        DiveModeHandle_Display_Clock(IteStat_Initial);
        /*Temperature*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Temperature_Tittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Temperature_Value);
        /*Clear rectangle Tank pressure*/
        ClearPortion_TankPressure();
    }
}
/*Alternate page*/
void IniOrClrScrFunc_DIVE_GAUGE_ALT(void)
{
    /*Alarm and display*/
    DiveModeGaugeHandle_AltPage_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
void UpdOrFlasFunc_DIVE_GAUGE_ALT(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_GSM_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Runtime & GTR*/
    DivemodeHandle_GSM_CheckDisplayViolationMiddle(IteStat_Update);
    /*Alarm and display*/
    DiveModeGaugeHandle_AltPage_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
