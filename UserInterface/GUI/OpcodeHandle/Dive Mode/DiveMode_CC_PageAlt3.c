#include "L4X9_includes.h"
#include "DiveMode.h"
/*Alternate page 3*/
static void DiveModeCCHandle_AltPage03_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*CC-6 Tank pressure*/
        SurfaceMode_CC6TankPressure();
        /*GF*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Value);
        /*O2 Sat*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Value);
    }
}
void IniOrClrScrFunc_DIVE_CC_ALT_3(void)
{
    ClearPortionToUpdateDiveMode();
    DiveModeCCHandle_AltPage03_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_CC_ALT_3(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    DiveModeCCHandle_AltPage03_CheckDisplayBottom();
}
