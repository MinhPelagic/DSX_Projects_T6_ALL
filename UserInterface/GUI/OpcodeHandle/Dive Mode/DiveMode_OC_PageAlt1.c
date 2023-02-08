#include "L4X9_includes.h"
#include "DiveMode.h"
/*Alternate page 1*/
void DiveModeOCHandle_AltPage01_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
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
        /*TTS : only display when no Violation or setting extralarge Depth/Divetime*/
        if(AlarmStatusCheck_FullViolation()||(Setting_ExtraLarge_OFF==GUI_MAINDISPLAY_EXTRA_LARGE))
        {
            /*No display*/
        }
        else
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_TTSBottomRow_Tittle);
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_TTSBottomRow_Content);
        }
    }
}
void IniOrClrScrFunc_DIVE_OC_ALT_1(void)
{
    ClearPortionToUpdateDiveMode();
    /*Alarm in the bottom*/
    DiveModeOCHandle_AltPage01_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_OC_ALT_1(void)
{
    /*Display the top portion*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Display PO2, 3rd row left right*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*Alarm in the bottom*/
    DiveModeOCHandle_AltPage01_CheckDisplayBottom();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
}
