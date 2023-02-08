#include "L4X9_includes.h"
#include "SurfaceMode_Context.h"
#include "SurfaceMode.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
#include "..\Menu\Set SP\Menu_SetSP.h"

/*Context memdev config*/
const contentDispContext_st SurfaceMode_SurfTime_TitleText =
{
    &SurfaceMode_SurfTime_TitleText_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SurfTime_TxtTitle,
};
/*HOUR*/
const contentDispContext_st SurfaceMode_SurfTime_Hour =
{
    &SurfaceMode_SurfTime_Hour_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_SurfTime_Hour,
};
/*MIN*/
const contentDispContext_st SurfaceMode_SurfTime_Min =
{
    &SurfaceMode_SurfTime_Min_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_5,
    &Pos_SurfTime_Min,
};
/*Surface Colon*/
const contentDispContext_st SurfaceMode_SurfTime_Colon =
{
    &SurfaceMode_SurfTime_Colon_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SurfTime_Colon,
};
/*Fly Text*/
const contentDispContext_st SurfaceMode_Fly_Tittle =
{
    &SurfaceMode_FlyTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_FLY_TxtTitle,
};
/*Fly Value*/
const contentDispContext_st SurfaceMode_Fly_Time =
{
    &SurfaceMode_FlyTittle_Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_FLY_Value,
};
/*Last dive title*/
const contentDispContext_st SurfaceMode_LastDive_Tittle =
{
    &SurfaceMode_LastDive_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_LastDive_TxtTitle,
};
const contentDispContext_st SurfaceMode_LastDive_OnLeft = //Applied to CC/OC/SM
{
    &SurfaceMode_LastDive_Context,
    &SurfaceMode_isViolation_Text_Color,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDive_Content,
};
/*Last dive title -> Specific to GAUGE SM mode*/
const contentDispContext_st SurfaceMode_GSM_LastDive_Tittle =
{
    &SurfaceMode_LastDive_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_LastDiveInSM_TxtTittle,
};
const contentDispContext_st SurfaceMode_GSM_LastDiveInCenter =
{
    &SurfaceMode_LastDive_Context,
    &SurfaceMode_isViolation_Text_Color,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDiveInSM_Content,
};
/*RUN TIME*/
const contentDispContext_st SurfaceMode_Runtime_Tittle =
{
    &SurfaceMode_Runtime_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Runtime_TxtTittle,
};
const contentDispContext_st SurfaceMode_Runtime_Value =
{
    &SurfaceMode_Runtime_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Runtime_Value,
};
/*DESAT*/
const contentDispContext_st SurfaceMode_Desat_Tittle =
{
    &SurfaceMode_Desat_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
const contentDispContext_st SurfaceMode_Desat_Value =
{
    &SurfaceMode_Desat_ValueContext,
    &SurfaceMode_isViolation_Text_Color,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_DESAT_Content,
};
/*PO2*/
const contentDispContext_st SurfaceMode_PO2_Tittle =
{
    &SurfaceMode_PO2_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_PO2_TxtTittle,
};
/*PO2 - Specific to SM MODE*/
const contentDispContext_st SurfaceMode_PO2_SMMode_Tittle =
{
    &SurfaceMode_PO2_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_3rdRowRight_TxtTittle,
};
const contentWithStateHandle_st SurfaceMode_PO2_SMMode_Value =
{
    &DiveMode_DispStat_PO2,
    &SurfaceMode_PO2_ValueContext,
    &AlarmColorHandle_PO2,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_SM_PO2_Value,
};
/*Pressure*/
const contentDispContext_st SurfaceMode_TankPressure_Tittle =
{
    &SurfaceMode_Pressure_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Pressure_TxtTittle,
};
const contentDispContext_st SurfaceMode_Linked_TankPressure_Value =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &SurfaceMode_PressAlarm_Color,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
const contentDispContext_st SurfaceMode_LooseLink_TankPressure_Value =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
const contentDispContext_st SurfaceMode_OffLink_TankPressure_Value =
{
    &SurfaceMode_TankPressure_OffLink_ValueContext,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
/*O2 SAT*/
const contentDispContext_st SurfaceMode_O2Sat_Tittle =
{
    &SurfaceMode_O2Sat_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Pressure_TxtTittle,
};
const contentDispContext_st SurfaceMode_O2Sat_Value =
{
    &SurfaceMode_O2Sat_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
/*Fi O2*/
const contentDispContext_st SurfaceMode_FiO2_Tittle =
{
    &SurfaceMode_FiO2_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Pressure_TxtTittle,
};
const contentDispContext_st SurfaceMode_FiO2_Value =
{
    &SurfaceMode_FiO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
/*TMT number -> SM mode*/
const contentDispContext_st SurfaceMode_TMT_Value =
{
    &SurfaceMode_TMT_ValueContext,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_SURFT_TMT,
};
/*Time*/
const contentDispContext_st SurfaceMode_Time_Tittle =
{
    &SurfaceMode_Time_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st SurfaceMode_TimeValue =
{
    &SurfaceMode_TimeValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Time_Value,
};
/*Dil PO2*/
const contentDispContext_st SurfaceMode_DilPO2_Tittle =
{
    &SurfaceMode_DilPO2_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st SurfaceMode_DilPO2_Value =
{
    &SurfaceMode_DilPO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Time_Value,
};
/*Temperature*/
const contentDispContext_st SurfaceMode_Temperature_Tittle =
{
    &SurfaceMode_Temperature_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Temperature_TxtTitle,
};
const contentDispContext_st SurfaceMode_Temperature_Value =
{
    &SurfaceMode_Temperature_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Temperature_Value,
};
/*Main GF*/
void SurfaceMode_MainGF_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, "  %d  ", (uint8_t)GFBGVal);
}
const contentDispContext_st SurfaceMode_MainGF_Tittle =
{
    &SurfaceMode_MainGF_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Temperature_TxtTitle,
};
const contentDispContext_st SurfaceMode_MainGF_Value =
{
    &SurfaceMode_MainGF_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Temperature_Value,
};
/*Elev*/
const contentDispContext_st SurfaceMode_Elev_Tittle =
{
    &SurfaceMode_Elev_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Pressure_TxtTittle,
};
const contentDispContext_st SurfaceMode_Elev_Value =
{
    &SurfaceMode_Elev_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
const contentDispContext_st SurfaceMode_SmallFont_Elev_Value =
{
    &SurfaceMode_Elev_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_Pressure_Value,
};
/*Press at activiation*/
const contentDispContext_st SurfaceMode_PressActivation_Tittle =
{
    &SurfaceMode_PressActivation_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_PressAtActivation_TxtTitle,
};
const contentDispContext_st SurfaceMode_PressActivation_Value =
{
    &SurfaceMode_PressActivation_ValueContext,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_SURF_PressAtActivation_Value,
};
const contentDispContext_st SurfaceMode_PressActivation_Unit =
{
    &SurfaceMode_PressActivation_UnitContext,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_SURF_PressAtActivation_Unit,
};
/*Current press*/
const contentDispContext_st SurfaceMode_CurrentPress_Tittle =
{
    &SurfaceMode_CurrentPress_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_CurrentPress_TxtTitle,
};
const contentDispContext_st SurfaceMode_CurrentPress_Value =
{
    &SurfaceMode_CurrentPress_ValueContext,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_SURF_CurrentPress_Value,
};
const contentDispContext_st SurfaceMode_CurrentPress_Unit =
{
    &SurfaceMode_PressActivation_UnitContext,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_SURF_CurrentPress_Unit,
};
/*OC RIGHT*/
const contentDispContext_st SurfaceMode_OCRight_Tittle =
{
    &SurfaceMode_OCRight_TittleContext,
    &SurfaceMode_OCRightTittleColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_Pressure_TxtTittle,
};
const contentDispContext_st SurfaceMode_OffLink_OCRight_Value =
{
    &SurfaceMode_TankPressure_OffLink_ValueContext,
    &SurfaceMode_OCRightValueColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
const contentDispContext_st SurfaceMode_TMTRight_Value =
{
    &SurfaceMode_OCRight_ValueContext,
    &SurfaceMode_OCRightValueColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Pressure_Value,
};
/*OC LEFT*/
const contentDispContext_st SurfaceMode_OCLeft_Tittle =
{
    &SurfaceMode_OCLeft_TittleContext,
    &SurfaceMode_OCLeftTittleColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st SurfaceMode_TMTLeft_Value =
{
    &SurfaceMode_OCLeft_ValueContext,
    &SurfaceMode_OCLeftValueColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Time_Value,
};
const contentDispContext_st SurfaceMode_OffLink_OCLeft_Value =
{
    &SurfaceMode_TankPressure_OffLink_ValueContext,
    &SurfaceMode_OCLeftValueColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Time_Value,
};
const contentDispContext_st SurfaceMode_OCLeftStatus_Value =
{
    &SurfaceMode_OCLeftStatus_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_OC_Status,
};
const contentDispContext_st SurfaceMode_NotBestGas_OCLeftStatus_Value =
{
    &SurfaceMode_OCLeftStatus_ValueContext,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_OC_Status,
};
const contentDispContext_st SurfaceMode_OCLeftStatusViolation_Value =
{
    &SurfaceMode_OCLeftStatusViolation_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_Runtime_Value,
};
/*3rd Row on the Left*/
const contentDispContext_st SurfaceMode_3rdRowLeft_Tittle =
{
    &MainDisplay_LEFT_Context_Right,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_3rdRowLeft_TxtTittle,
};
/*Define context of 3rd row left*/
const contentDispContext_st SurfaceMode_3rdRowLeft_O2SAT =
{
    &SurfaceMode_O2Sat_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
const p_VoidFunc_t SurfMode_3rdContentLeft[_3rdRowSet_MAX] =
{
    &FuncDoNothing, //Not use
    &SurfaceHandle_3rdRowLeft_O2Sat,
    &SurfaceHandle_3rdRowLeft_GF,
    &SurfaceHandle_3rdRowLeft_Ceiling,
    &SurfaceHandle_3rdRowLeft_MaxDepth,
    &SurfaceHandle_3rdRowLeft_AvgDepth,
    &SurfaceHandle_3rdRowLeft_TIME,
    &SurfaceHandle_3rdRowLeft_DilPO2,
    &SurfaceHandle_3rdRowLeft_FiO2,
    &SurfaceHandle_3rdRowLeft_GTR
};
/*3rd Row on the Right*/
const contentDispContext_st SurfaceMode_3rdRowRight_Tittle =
{
    &MainDisplay_RIGHT_Context_Right,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_3rdRowRight_TxtTittle,
};
const p_VoidFunc_t SurfMode_3rdContentRight[_3rdRowSet_MAX] =
{
    &FuncDoNothing, //Not use
    &SurfaceHandle_3rdRowRight_O2Sat,
    &SurfaceHandle_3rdRowRight_GF,
    &SurfaceHandle_3rdRowRight_Ceiling,
    &SurfaceHandle_3rdRowRight_MaxDepth,
    &SurfaceHandle_3rdRowRight_AvgDepth,
    &SurfaceHandle_3rdRowRight_TIME,
    &SurfaceHandle_3rdRowRight_DilPO2,
    &SurfaceHandle_3rdRowRight_FiO2,
    &SurfaceHandle_3rdRowRight_GTR
};
/*GTR - Specific to Gauge MODE*/
const contentDispContext_st SurfaceMode_Gauge_GTR_Tittle =
{
    &SurfaceMode_Gauge_GTR_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_3rdRowRight_TxtTittle,
};
const contentDispContext_st SurfaceMode_Gauge_GTR_Value =
{
    &SurfaceMode_Gauge_GTR_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_SM_PO2_Value,
};
const contentDispContext_st SurfaceMode_Gauge_GTR_Dash =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_SM_PO2_Value,
};
/**
 * @brief Compass mode -> Tank pressure display
 *
 */
const contentDispContext_st CompassMode_TankPressure_Tittle =
{
    &SurfaceMode_Pressure_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Compass_TankPressure_Tittle,
};
const contentDispContext_st CompassMode_Linked_TankPressure_Value =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &SurfaceMode_PressAlarm_Color,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_TankPressure_Value,
};
const contentDispContext_st CompassMode_LooseLink_TankPressure_Value =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_TankPressure_Value,
};
const contentDispContext_st CompassMode_OffLink_TankPressure_Value =
{
    &SurfaceMode_TankPressure_OffLink_ValueContext,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Compass_TankPressure_Value,
};
