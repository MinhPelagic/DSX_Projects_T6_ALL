/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"


void CompassMode_ChronoTittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CHRONO));
};
void CompassMode_ChronoTime_Value(char* pStrRet)
{
    sprintf(pStrRet, " %d:%.2d ", Chrono.Run_S/60, Chrono.Run_S%60);
};
void CompassMode_CurrentLocation_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CURRENT_LOCATION));
};
void CompassMode_CurrentLocation_Latitude_Data(char* pStrRet)
{
    sprintf(pStrRet, "    %.6f    ", GnssGGA.Latitude_DD);
};
void CompassMode_CurrentLocation_Longitude_Data(char* pStrRet)
{
    sprintf(pStrRet, "    %.6f    ", GnssGGA.Longitude_DD);
};
void CompassMode_TargetLocation_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TARGET_LOCATION));
};
void CompassMode_TargetLocation_Latitude_Data(char* pStrRet)
{
    sprintf(pStrRet, "    %.6f    ", GnssGGA.Latitude_Target_DD);
}
void CompassMode_TargetLocation_Longitude_Data(char* pStrRet)
{
    sprintf(pStrRet, "    %.6f    ", GnssGGA.Longitude_Target_DD);
};
void CompassMode_Target_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TARGET));
};
void CompassMode_Target_Value_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f°  ", GnssGGA.Target_Direction);
}
void CompassMode_Distance_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DISTANCE));
};
void CompassMode_Distance_Value_Context(char* pStrRet)
{
    float Dist;

    if(UNITS==NVD_IMPERIAL)
        Dist = 0.62*GnssGGA.Target_Distance;
    else
        Dist = GnssGGA.Target_Distance;

    if(Dist < 10.0)
        sprintf(pStrRet, " %.2f ", Dist);
    else
        sprintf(pStrRet, " %.1f ", Dist);
}
void CompassMode_DiveTimeTittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME));
};
void CompassMode_DiveTime_Value(char* pStrRet)
{
    sprintf(pStrRet, " %d:%.2d ", Chrono.Run_S/60, Chrono.Run_S%60);
};
void CompassMode_Depth_Value(char* pStrRet)
{
    sprintf(pStrRet, " %d:%.2d ", Chrono.Run_S/60, Chrono.Run_S%60);
};
void CompassMode_ReferenceHeading_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_REFERENCE));
};
void CompassMode_ReferenceHeading_Value_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %d°  ", GUI_CompassReferenceHeadingDegree);
};
void CompassMode_ReverseHeading_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, "  REVERSE  ");                // DT, please add TxtStr_REVERSE
};
void CompassMode_ReverseHeading_Value_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %d°  ", GUI_CompassReverseHeadingDegree);
};
/*Chrono Text*/
const contentDispContext_st CompassMode_Chrono_Tittle =
{
    &CompassMode_ChronoTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_FLY_TxtTitle,
};
/*Chrono Value*/
const contentDispContext_st CompassMode_Chrono_Time =
{
    &CompassMode_ChronoTime_Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_FLY_Value,
};
/*Current Location Text*/
const contentDispContext_st CompassMode_CurrentLocation_Tittle =
{
    &CompassMode_CurrentLocation_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_CurrentLocation_Tittle,
};
/*Current Location Latitude*/
const contentDispContext_st CompassMode_CurrentLocation_Latitude =
{
    &CompassMode_CurrentLocation_Latitude_Data,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_CurrentLocation_Latitude,
};
/*Current Location Longitude*/
const contentDispContext_st CompassMode_CurrentLocation_Longitude =
{
    &CompassMode_CurrentLocation_Longitude_Data,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_CurrentLocation_Longtitude,
};
/*Target Location Text*/
const contentDispContext_st CompassMode_TargetLocation_Tittle =
{
    &CompassMode_TargetLocation_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TargetLocation_Tittle,
};
/*Target Location Latitude*/
const contentDispContext_st CompassMode_TargetLocation_Latitude =
{
    &CompassMode_TargetLocation_Latitude_Data,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TargetLocation_Latitude,
};
/*Target Location Longitude*/
const contentDispContext_st CompassMode_TargetLocation_Longitude =
{
    &CompassMode_TargetLocation_Longitude_Data,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TargetLocation_Longtitude,
};
/*TARGET*/
const contentDispContext_st CompassMode_Target_Tittle =
{
    &CompassMode_Target_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_ReferenceHeading_Tittle, /*Reuse*/
};
const contentDispContext_st CompassMode_Target_Value =
{
    &CompassMode_Target_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_ReferenceHeading_Value,
};
/*DISTANCE*/
const contentDispContext_st CompassMode_Distance_Tittle =
{
    &CompassMode_Distance_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TankPressure_Tittle,
};
const contentDispContext_st CompassMode_Distance_Value =
{
    &CompassMode_Distance_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_TankPressure_Value,
};

/*DiveTime Text*/
const contentDispContext_st CompassMode_DiveTime_Tittle =
{
    &CompassMode_DiveTimeTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_FLY_TxtTitle,
};
/*DiveTime Value*/
const contentDispContext_st CompassMode_DiveTime_Time =
{
    &CompassMode_DiveTime_Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_FLY_Value,
};
/*Depth Text*/
const contentDispContext_st CompassMode_Depth_Tittle =
{
    &CompassMode_DiveTimeTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_FLY_TxtTitle,
};
/*Depth Value*/
const contentDispContext_st CompassMode_Depth =
{
    &CompassMode_Depth_Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_FLY_Value,
};
/*Compass Reference Heading Text*/
const contentDispContext_st CompassMode_ReferenceHeading_Tittle =
{
    &CompassMode_ReferenceHeading_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_ReferenceHeading_Tittle,
};
/*Compass Reference Heading Value*/
const contentDispContext_st CompassMode_ReferenceHeading_Value =
{
    &CompassMode_ReferenceHeading_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_ReferenceHeading_Value,
};
/*Compass Reverse Heading Text*/
const contentDispContext_st CompassMode_ReverseHeading_Tittle =
{
    &CompassMode_ReverseHeading_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_ReferenceHeading_Tittle,
};
/*Compass Reverse Heading Value*/
const contentDispContext_st CompassMode_ReverseHeading_Value =
{
    &CompassMode_ReverseHeading_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_ReferenceHeading_Value,
};
/*Pressure*/
const contentDispContext_st DiveMode_TankPressure_Tittle =
{
    &SurfaceMode_Pressure_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TankPressure_Tittle,
};

