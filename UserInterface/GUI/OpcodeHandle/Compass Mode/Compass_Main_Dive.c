/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "..\Surface Mode\Surfacemode.h"
#include "..\Dive Mode\DiveMode.h"

void IniOrClrScrFunc_C2_COMPASS_MAIN_DIVE(void)
{
    GUI_Clear();
    GUI_CompassHeadingStat = 0;     // reset Compass Reference/Reverse heading index
    /*Depth*/
    DiveModeHandle_Display_Depth(IteStat_Initial);
    /*Dive Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_Compass_DiveTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_Compass_DiveTime_Value);
    /*Chrono*/
    HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Time);
    /*Pressure*/
    if(CheckIfGasToTMT_Assigned())
    {
        CompassHandle_PressureDisplay();
    }
    else
    {
        /*Do nothing*/
    }
    /*GF*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Compass main display*/
    CoDis_DisplayScaleVerticalLines(359);
    CoDis_DisplayCompassMainValue(359);
    /*Reference Heading or Reverse Heading*/
    CompassHandle_SetReferenceOrReverse();
    /*AR bar*/
    Display_AR(ASCBGVal);
}
void UpdOrFlasFunc_C2_COMPASS_MAIN_DIVE(void)
{
    int compassValue = 0;
    /*verify the compass value*/
    compassValue = CoDis_VerifyTheCompassValue();
    /*Display the line and main value*/
    CoDis_DisplayScaleVerticalLines(compassValue);
    CoDis_DisplayCompassMainValue(compassValue);
    /*Reference Heading or Reverse Heading*/
    CompassHandle_SetReferenceOrReverse();
    /*Depth*/
    DiveModeHandle_Display_Depth(IteStat_Update);
    /*Dive Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_Compass_DiveTime_Value);
    /*Chrono*/
    HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Time);
    /*Pressure*/
    if(CheckIfGasToTMT_Assigned())
    {
        CompassHandle_PressureDisplay();
    }
    else
    {
        /*Do nothing*/
    }
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
}
