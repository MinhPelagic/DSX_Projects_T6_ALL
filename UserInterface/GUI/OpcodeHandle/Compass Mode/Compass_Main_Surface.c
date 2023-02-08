/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "..\Surface Mode\Surfacemode.h"
#include "..\Dive Mode\DiveMode.h"
/*
COMPASS MODE Display
*/
void IniOrClrScrFunc_C1_COMPASS_MAIN(void)
{
    GUI_Clear();
    /*GF*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Compass main display*/
    CoDis_DisplayScaleVerticalLines(359U);
    CoDis_DisplayCompassMainValue(359U);
    if(GnssStatus!=GNSS_ON)
    {
        /*Surface Time*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
        /*Chrono*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Time);
        /*Reference Heading or Reverse Heading*/
        CompassHandle_SetReferenceOrReverse();
        /*Pressure*/
        if(CheckIfGasToTMT_Assigned())
        {
            CompassHandle_PressureDisplay();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        GUI_CompassHeadingStat = 0;     // reset Compass Reference/Reverse heading index
        /*Current Locatoin*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_CurrentLocation_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_CurrentLocation_Latitude);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_CurrentLocation_Longitude);
        /*Target Location*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_TargetLocation_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_TargetLocation_Latitude);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_TargetLocation_Longitude);
        /*Target Direction*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Target_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Target_Value);
        /*Target Distance*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Distance_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Distance_Value);
    }
}
void UpdOrFlasFunc_C1_COMPASS_MAIN(void)
{
    /*verify the compass value*/
    const int compassValue = (int16_t)CoDis_VerifyTheCompassValue();
    /*Display the line and main value*/
    CoDis_DisplayScaleVerticalLines(compassValue);
    CoDis_DisplayCompassMainValue(compassValue);
    if(GnssStatus!=GNSS_ON)
    {
        /*Update*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
        HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Chrono_Time);
        /*Reference Heading or Reverse Heading*/
        CompassHandle_SetReferenceOrReverse();
        /*Pressure*/
        if(CheckIfGasToTMT_Assigned())
        {
            CompassHandle_PressureDisplay();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        GnssGGA.Target_Distance = Gnss_Calc_Distance (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);
        GnssGGA.Target_Direction = Gnss_WayFinderBrearing (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);
        /*Current Locatoin*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_CurrentLocation_Latitude);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_CurrentLocation_Longitude);
        /*Target Location*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_TargetLocation_Latitude);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_TargetLocation_Longitude);
        /*Target Direction*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Target_Value);
        /*Target Distance*/
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_Distance_Value);
    }
}
