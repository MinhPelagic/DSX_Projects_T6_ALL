#include "L4X9_includes.h"
#include "DiveMode.h"
#include "..\Menu\Device Settings\ContextDeviceSettingsCfg.h"
#include "..\Menu\Set SP\Menu_SetSP.h"

/*Context memdev config*/
/*DEPTH text*/
const contentDispContext_st DiveMode_Depth_TitleText =
{
    &DiveSimulator_DEPTH_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SurfTime_TxtTitle,
};
/*Depth value*/
const contentWithStateHandle_st DiveMode_Depth_DepthValue_Imperial =
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_DepthValueNormal_Imperial_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_DepthValue_Imperial,
};
const contentWithStateHandle_st DiveMode_Depth_DepthValue_Metric_Decimal =
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_DepthValue_MetricDecimal_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_DepthValue_Metric_Decimal,
};
const contentWithStateHandle_st DiveMode_Depth_DepthValue_Metric_Floating =
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_DepthValueNormal_MetricFloat_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_DepthValue_Metric_Floating,
};
const contentWithStateHandle_st DiveMode_VGM_DepthDashes =                      // added by YeuShyr 2022 02 27
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_VGM_DepthDashesContext,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_DepthValue_Imperial,
};
/*Dive time*/
const contentDispContext_st DiveMode_DiveTime_TitleText =
{
    &SetAlarms_DiveTimeTTS_DIVETIME_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_FLY_TxtTitle,
};
/*Dive time value*/
const contentWithStateHandle_st DiveMode_DiveTime_Value =
{
    &DiveMode_DispStat_DiveTimeValue,
    &DiveMode_DiveTime_Context,
    &AlarmColorHandle_DiveTimeAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_FLY_Value,
};
const contentWithStateHandle_st DiveMode_DiveTimeExtra_Value =
{
    &DiveMode_DispStat_DiveTimeValue,
    &DiveMode_DiveTime_Context,
    &AlarmColorHandle_DiveTimeAlarm,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_Dive_Extralarge_DiveTime,
};
/*Dive time in Dive Compass*/                                   // added by YS 2021 12 14, remove comment after DT acknoledged
const contentDispContext_st DiveMode_Compass_DiveTime_TitleText =
{
    &SetAlarms_DiveTimeTTS_DIVETIME_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_DiveModeCompass_DiveTime_Title,//
};
/*Dive time in Dive Compass value*/                             // added by YS 2021 12 14, remove comment after DT acknoledged
const contentDispContext_st DiveMode_Compass_DiveTime_Value =
{
    &DiveMode_DiveTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_DiveModeCompass_DiveTime_Value,
};
/*AVG Depth*/
const contentDispContext_st DiveMode_AvgDepth_TitleTxt =
{
    &DiveMode_AvgDepth_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_AVGDepth_TxtTittle,
};
const contentDispContext_st DiveMode_AvgDepth_Value =
{
    &DiveMode_AvgDepthValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_AVGDepth_Value,
};
/*Max depth when set extra large DIVE TIME*/
const contentDispContext_st DiveModeGSM_MaxDepth_TitleTxt =
{
    &DiveMode_MaxDepth_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_AVGDepth_TxtTittle,
};
const contentDispContext_st DiveModeGSM_MaxDepth_Value =
{
    &DiveMode_MaxDepthValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_AVGDepth_Value,
};
/*Max depth*/
const contentDispContext_st DiveMode_MaxDepth_TitleTxt =
{
    &DiveMode_MaxDepth_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
const contentDispContext_st Dive_Gauge_MaxDepth_Value =
{
    &DiveMode_MaxDepthValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_DESAT_Content,
};
/*GTR*/
const contentDispContext_st DiveMode_GTR_TitleTxt =
{
    &DiveMode_GTR_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_GTR_TxtTittle,
};
const contentDispContext_st DiveMode_GTR_Value =
{
    &DiveMode_GTR_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_GTR_Content,
};
const contentDispContext_st DiveMode_GTR_Dash =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_GTR_Content,
};
/*NO DECO or O2 Time Tittle*/
const contentDispContext_st DiveMode_NoDecoOrO2TimeTittle =
{
    &DiveMode_NoDecoOrO2TimeTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Dive_NoDeco_Tittle,
};
/*NO DECO or O2 Time Value*/
const contentWithStateHandle_st DiveMode_NoDecoOrO2TimeValue =
{
    &DiveMode_DispStat_DTR_Alarm,
    &DiveMode_NoDecoOrO2TimeValue_Context,
    &AlarmColorHandle_DTR_Alarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_NoDeco_Value,
};
/*TTS*/
const contentDispContext_st DiveMode_TTS_Tittle =
{
    &DiveMode_TTS_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
const contentDispContext_st DiveMode_TTS_Content =
{
    &DiveMode_TTS_Content_Context,
    &AlarmColorHandle_TimeToSurface,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_NoDecoOnRight_Value,
};
/*OC - Max depth*/
const contentDispContext_st DiveMode_OC_MaxDepth_Tittle =
{
    &DiveMode_OC_MaxDepth_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st DiveMode_OC_MaxDepthValue_Imperial = /*Imperial max depth*/
{
    &DiveMode_OC_MaxDepth_Value_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_MaxDepthValue_Imperial,
};
const contentDispContext_st DiveMode_OC_MaxDepthValue_Metric_Decimal =
{
    &DiveMode_OC_MaxDepthValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_MaxDepthValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_MaxDepthValue_Metric_Floating =
{
    &DiveMode_OC_MaxDepthValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_MaxDepthValue_Metric_Floating,
};
const contentDispContext_st DiveMode_OC_MaxDepthDash = /*Dash for over Max Depthh*/
{
    &DiveMode_OC_MaxDepthDash_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_MaxDepthValue_Imperial,
};
/*OC - Avg depth*/
const contentDispContext_st DiveMode_OC_AvgDepth_Tittle =
{
    &DiveMode_OC_AvgDepth_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Temperature_TxtTitle,
};
const contentDispContext_st DiveMode_OC_AvgDepthValue_Imperial =
{
    &DiveMode_OC_AvgDepthValue_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_AvgDepthValue_Imperial,
};
const contentDispContext_st DiveMode_OC_AvgDepthValue_Metric_Decimal =
{
    &DiveMode_OC_AvgDepthValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_AvgDepthValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_AvgDepthValue_Metric_Floating =
{
    &DiveMode_OC_AvgDepthValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_AvgDepthValue_Metric_Floating,
};
const contentDispContext_st DiveMode_OC_AvgDepthDash =                          // added by YeuShyr 2022 02 27
{
    &DiveMode_OC_AvgDepthDash_Context,
    &AlarmColorHandle_DepthMaxAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_AvgDepthValue_Imperial,
};
/*OC - Ceiling*/
const contentDispContext_st DiveMode_OC_Ceiling_Tittle =
{
    &DiveMode_OC_Ceiling_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Dive_OC_Ceiling_TitleTxt,
};
const contentDispContext_st DiveMode_OC_CeilingValue_Imperial =
{
    &DiveMode_OC_CeilingValue_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_CeilingValue_Imperial,
};
const contentDispContext_st DiveMode_OC_CeilingValue_Metric_Decimal =
{
    &DiveMode_OC_CeilingValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_CeilingValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_CeilingValue_Metric_Floating =
{
    &DiveMode_OC_CeilingValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_CeilingValue_Metric_Floating,
};
/*GTR*/
const contentDispContext_st DiveMode_OC_GTR_Tittle =
{
    &DiveMode_GTR_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st DiveMode_OC_GTR_Value =
{
    &DiveMode_GTR_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_GTR_Value,
};
/*GTR - Bottom below -> Specific only dispay when Violation*/
const contentDispContext_st DiveMode_Violation_GTRInBottom_Tittle =
{
    &DiveMode_GTR_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Temperature_TxtTitle,
};
const contentDispContext_st DiveMode_Violation_GTRInMiddle_Tittle =
{
    &DiveMode_GTR_TitleTxt_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_PO2_TxtTittle,
};
const contentDispContext_st DiveMode_Violation_GTRInBottom_Value =
{
    &DiveMode_GTR_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Temperature_Value,
};
const contentDispContext_st DiveMode_Violation_GTRInMiddle_Value =
{
    &DiveMode_GTR_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_PO2_Value,
};
const contentDispContext_st DiveMode_OC_GTR_Dash =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_GTR_Value,
};
const contentDispContext_st DiveMode_Violation_GTRInBottom_Dash =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Temperature_Value,
};
const contentDispContext_st DiveMode_Violation_GTRInMiddle_Dash =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_PO2_Value,
};
/*OC - END*/
const contentDispContext_st DiveMode_OC_ENDDepth_Tittle =
{
    &DiveMode_OC_ENDDepth_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
const contentDispContext_st DiveMode_OC_ENDDepthValue_Imperial =
{
    &DiveMode_OC_ENDDepthValue_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_MaxDepthValue_Imperial,
};
const contentDispContext_st DiveMode_OC_ENDDepthValue_Metric_Decimal =
{
    &DiveMode_OC_ENDDepthValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_MaxDepthValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_ENDDepthValue_Metric_Floating =
{
    &DiveMode_OC_ENDDepthValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_MaxDepthValue_Metric_Floating,
};
/*OC - WOB*/
const contentDispContext_st DiveMode_OC_WOBDepth_Tittle =
{
    &DiveMode_OC_WOBDepth_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Temperature_TxtTitle,
};
const contentDispContext_st DiveMode_OC_WOBDepthValue_Imperial =
{
    &DiveMode_OC_WOBDepthValue_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_AvgDepthValue_Imperial,
};
const contentDispContext_st DiveMode_OC_WOBDepthValue_Metric_Decimal =
{
    &DiveMode_OC_WOBDepthValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_AvgDepthValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_WOBDepthValue_Metric_Floating =
{
    &DiveMode_OC_WOBDepthValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_AvgDepthValue_Metric_Floating,
};
/*OC - MOD*/
const contentDispContext_st DiveMode_OC_MODDepth_Tittle =
{
    &DiveMode_OC_MODDepth_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Dive_OC_Ceiling_TitleTxt,
};
const contentDispContext_st DiveMode_OC_MODDepthValue_Imperial =
{
    &DiveMode_OC_MODDepthValue_Imperial_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_CeilingValue_Imperial,
};
const contentDispContext_st DiveMode_OC_MODDepthValue_Metric_Decimal =
{
    &DiveMode_OC_MODDepthValue_MetricDecimal_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_5,
    &Pos_Dive_OC_CeilingValue_Metric_Decimal,
};
const contentDispContext_st DiveMode_OC_MODDepthValue_Metric_Floating =
{
    &DiveMode_OC_MODDepthValue_MetricFloating_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_Dive_OC_CeilingValue_Metric_Floating,
};
/*DECO STOP Tittle*/
const contentDispContext_st DiveMode_DecoStop_Tittle =
{
    &DiveMenu_DECOSTOPS_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_LastDive_TxtTitle,
};
const contentWithStateHandle_st DiveMode_DecoStop_DepthAndTime =
{
    &AlarmStatusHandle_DecoStop,
    &DiveMode_DecoStop_DepthAndTime_Context,
    &AlarmColorHandle_DecoStop,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDive_Content,
};
const contentWithStateHandle_st DiveMode_DecoStop_MaxDepth =
{
    &AlarmStatusHandle_DecoStop,
    &DiveMode_DashDash_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDive_Content,
};
/*DEEP STOP / Safety Stop Tittle*/
const contentDispContext_st DiveMode_DeepOrSSStop_Tittle =
{
    &DiveMode_DeepOrSSStopTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_LastDive_TxtTitle,
};
const contentDispContext_st DiveMode_DeepOrSSStop_DepthAndTime =
{
    &DiveMode_DeepOrSSStop_DepthAndTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDive_Content,
};
const contentWithStateHandle_st DiveMode_PO2_Value =
{
    &DiveMode_DispStat_PO2,
    &DiveMode_PO2_Value_Context,
    &AlarmColorHandle_PO2,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_PO2_Value,
};
/*Extra large Depth value*/
const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Imperial =
{
    &DiveMode_DispStat_DepthValue,
    &DepthAndDiveTime_DepthValueNormal_Imperial_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_Dive_ExtraLargeDepthValue_Imperial,
};
const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Metric_Decimal =
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_DepthValue_MetricDecimal_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_RIGHT,
    &FontAaux_7,
    &Pos_Dive_ExtraLargeDepthValue_Metric_Decimal,
};
const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Metric_Floating =
{
    &DiveMode_DispStat_DepthValue,
    &DiveMode_DepthValueNormal_MetricFloat_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_LEFT,
    &FontAaux_5,
    &Pos_Dive_ExtraLargeDepthValue_Metric_Floating,
};
/*Deco Stop when extra large Depth*/
const contentDispContext_st DiveModeExtrDepth_DecoStop_Tittle =
{
    &DiveMenu_DECOSTOPS_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
const contentWithStateHandle_st DiveModeExtrDepth_DecoStop_MaxDepth =
{
    &AlarmStatusHandle_DecoStop,
    &DiveMode_DashDash_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURFT_LastDiveOnRight_Content,
};
const contentWithStateHandle_st DiveModeExtrDepth_DecoStop_DepthAndTime =
{
    &AlarmStatusHandle_DecoStop,
    &DiveMode_DecoStop_DepthAndTime_Context,
    &AlarmColorHandle_DecoStop,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDiveOnRight_Content,
};
/*DEEP STOP / Safety Stop when extra large Depth*/
const contentDispContext_st DiveModeExtrDepth_DeepOrSSStop_Tittle =
{
    &DiveMode_DeepOrSSStopTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
const contentDispContext_st DiveModeExtrDepth_DeepOrSSStop_DepthAndTime =
{
    &DiveMode_DeepOrSSStop_DepthAndTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_LastDiveOnRight_Content,
};
const contentDispContext_st DiveModeExtrDepth_NoDecoOrO2TimeTittle =
{
    &DiveMode_NoDecoOrO2TimeTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURFT_DESAT_TxtTitle,
};
/*NO DECO or O2 Time Value*/
const contentWithStateHandle_st DiveModeExtrDepth_NoDecoOrO2TimeValue =
{
    &DiveMode_DispStat_DTR_Alarm,
    &DiveMode_NoDecoOrO2TimeValue_Context,
    &AlarmColorHandle_DTR_Alarm,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_NoDecoOnRight_Value,
};
/*TTS*/
const contentDispContext_st DiveMode_TTSBottomRow_Tittle =
{
    &DiveMode_TTS_Tittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_Dive_OC_Ceiling_TitleTxt,
};
const contentDispContext_st DiveMode_TTSBottomRow_Content =
{
    &DiveMode_TTS_Content_Context,
    &AlarmColorHandle_TimeToSurface,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_OC_CeilingValue_Imperial,
};
/*
Depth and Dive Time mode
*/
/*Depth tittle*/
const contentDispContext_st DepthDiveTimeMode_DepthTittle =
{
    &DiveSimulator_DEPTH_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_DepthTittle,
};
/*Max depth alarm*/
const contentDispContext_st DepthDiveTimeMode_MaxDepthAlarm =
{
    &DepthAndDiveTime_DepthDashesContext,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_DepthImperial,
};
/*Depth value in Imperial*/
const contentDispContext_st DepthDiveTimeMode_DepthImperial =
{
    &DepthAndDiveTime_DepthValueNormal_Imperial_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_DepthImperial,
};
/*Depth in metric*/
const contentDispContext_st DepthDiveTimeMode_DepthMetric_Decimal =
{
    &DiveMode_DepthValue_MetricDecimal_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_RIGHT,
    &FontAaux_8,
    &Pos_DepthDiveTime_DepthMetricDecimal,
};
const contentDispContext_st DepthDiveTimeMode_DepthMetric_Floating =
{
    &DiveMode_DepthValueNormal_MetricFloat_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_DepthDiveTime_DepthMetricFloat,
};
/*Dive Time on left*/
const contentDispContext_st DepthDiveTimeMode_DiveTimeLeft_Tittle =
{
    &SetAlarms_DiveTimeTTS_DIVETIME_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_DiveTimeLeftTittle,
};
const contentDispContext_st DepthDiveTimeMode_DiveTimeLeft_Value =
{
    &DiveMode_DiveTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_DiveTimeLeftValue,
};
/*Tank pressure on right*/
const contentDispContext_st DepthDiveTimeMode_TankPressRight_Tittle =
{
    &SurfaceMode_Pressure_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_TankPressRightTittle,
};
const contentDispContext_st DepthDiveTimeMode_TankPressRightLinkedValue =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &SurfaceMode_PressAlarm_Color,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_TankPressRightValue,
};
const contentDispContext_st DepthDiveTimeMode_TankPressureLooseLinkValue =
{
    &SurfaceMode_TankPressure_Linked_ValueContext,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_TankPressRightValue,
};
const contentDispContext_st DepthDiveTimeMode_TankPressureOffLinkValue =
{
    &SurfaceMode_TankPressure_OffLink_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_TankPressRightValue,
};
/*Dive time in center tittle*/
const contentDispContext_st DepthDiveTimeMode_CenterDivetimeTittle =
{
    &SetAlarms_DiveTimeTTS_DIVETIME_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_CenterDiveTimeTittle,
};
/*Dive time in center Value*/
const contentDispContext_st DepthDiveTimeMode_CenterDivetimeValue =
{
    &DiveMode_DiveTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_8,
    &Pos_DepthDiveTime_CenterDiveTimeValue,
};
/*Deco stop tittle in center Tittle*/
const contentDispContext_st DepthDiveTimeMode_CenterDecoStopTittle =
{
    &DiveMenu_DECOSTOPS_Context_Left,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_CenterDiveTimeTittle,
};
const contentDispContext_st DepthDiveTimeMode_CenterDecoStopValue =
{
    &ExtraDepthDiveTime_DecoStop_DepthAndTime_Context,
    &AlarmColorHandle_DecoStop,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_DepthDiveTime_CenterDiveTimeValue,
};
/*Deep/Safety stop tittle in center Value*/
const contentDispContext_st DepthDiveTimeMode_CenterDeepOrSSStopTittle =
{
    &DiveMode_DeepOrSSStopTittle_Context,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_CenterDiveTimeTittle,
};
const contentDispContext_st DepthDiveTimeMode_CenterDeepOrSSStopValue =
{
    &DepthDiveTimeMode_DeepOrSSStop_DepthAndTime_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_DepthDiveTime_CenterDiveTimeValue,
};
const contentWithStateHandle_st DepthDiveTimeMode_DecoStop_MaxDepth =
{
    &AlarmStatusHandle_DecoStop,
    &DiveMode_DashDash_Context,
    &AlarmColorHandle_DepthAlarm,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_DepthDiveTime_CenterDiveTimeValue,
};
const contentWithStateHandle_st DepthDiveTimeMode_DecoStop_DepthAndTime =
{
    &AlarmStatusHandle_DecoStop,
    &ExtraDepthDiveTime_DecoStop_DepthAndTime_Context,
    &AlarmColorHandle_DecoStop,
    GUI_TA_CENTER,
    &FontAaux_7,
    &Pos_DepthDiveTime_CenterDiveTimeValue,
};
