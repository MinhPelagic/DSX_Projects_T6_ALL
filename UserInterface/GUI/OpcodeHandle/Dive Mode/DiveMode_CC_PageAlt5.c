#include "L4X9_includes.h"
#include "DiveMode.h"
static void DiveModeCCHandle_AltPage05_CheckDisplayBottom(void);

void IniOrClrScrFunc_DIVE_CC_ALT_5(void)
{
    ClearPortionToUpdateDiveMode();
    if(CC_MODE)
        DiveModeCCHandle_AltPage05_CheckDisplayBottom();
    else if(BO_MODE)
        DiveModeOCHandle_AltPage05_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_CC_ALT_5(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    if(CC_MODE)
        DiveModeCCHandle_AltPage05_CheckDisplayBottom();
    else if(BO_MODE)
        DiveModeOCHandle_AltPage05_CheckDisplayBottom();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
}

/*Alternate page 5*/
static void DiveModeCCHandle_AltPage05_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*Dil PO2*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_DilPO2_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_DilPO2_Value);
        /*Fi O2*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_FiO2_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_FiO2_Value);
    }
}
