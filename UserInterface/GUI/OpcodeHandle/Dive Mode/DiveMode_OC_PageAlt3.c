#include "L4X9_includes.h"
#include "DiveMode.h"
/*Alternate page 3*/
void DiveModeOCHandle_AltPage03_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*GTR*/
        DiveModeHandle_OC_Display_GTR();
        /*GF*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Value);
        /*O2 Sat*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Value);
    }
}
void IniOrClrScrFunc_DIVE_OC_ALT_3(void)
{
    ClearPortionToUpdateDiveMode();
    /*Alternate page display*/
    DiveModeOCHandle_AltPage03_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_OC_ALT_3(void)
{
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*bottom*/
    DiveModeOCHandle_AltPage03_CheckDisplayBottom();
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
