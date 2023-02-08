#ifndef _DIVEMODE_H_
#define _DIVEMODE_H_

#include "L4X9_includes.h"
#include "../Surface Mode/SurfaceMode.h"
#include "../Menu/Set Alarms/ContextSetAlarmsCfg.h"
#include "../Menu/Dive Planner/ContextDivePlannerCfg.h"

#define DIVEMODE_DEEPnSAFETYSTOP     (0x30)
#define DIVEMODE_FULLVIOLATION       (0x80U)
/*Arrow alarm in middle*/
enum
{
    Alarm_2ArrowUp = 0x00,
    Alarm_2ArrowDown,
    Alarm_1ArrowUp,
    Alarm_1ArrowDown
};
/*Struct handle alarm arrow*/
typedef struct
{
    ItemStatus_te dispStatus;   /**/
    GUI_COLOR arrColor;     /*Color */
    unsigned char arrUpDown;
} AlarmArrowHandle_st;

extern const battInfo_st pDataSurfBatt;
extern bool isSSorDS, isSSflagON;
extern uint16_t NDT_Data;
extern const contentDispContext_st DiveMode_Depth_TitleText;
extern const contentDispContext_st DiveModeExtrDepth_DecoStop_Tittle;
extern const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Metric_Decimal;
extern const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Metric_Floating;
extern const contentWithStateHandle_st DiveMode_ExtralargeDepth_DepthValue_Imperial;
extern const contentWithStateHandle_st DiveMode_Depth_DepthValue_Imperial;
extern const contentWithStateHandle_st DiveMode_Depth_DepthValue_Metric_Decimal;
extern const contentWithStateHandle_st DiveMode_Depth_DepthValue_Metric_Floating;
extern const contentWithStateHandle_st DiveMode_VGM_DepthDashes;
extern const contentDispContext_st DiveMode_AvgDepth_TitleTxt;
extern const contentDispContext_st DiveMode_AvgDepth_Value;
extern const contentDispContext_st DiveModeGSM_MaxDepth_TitleTxt;
extern const contentDispContext_st DiveModeGSM_MaxDepth_Value;
extern const contentDispContext_st DiveMode_MaxDepth_TitleTxt;
extern const contentDispContext_st Dive_Gauge_MaxDepth_Value;
extern const contentDispContext_st DiveMode_GTR_TitleTxt;
extern const contentDispContext_st DiveMode_GTR_Value;
extern const contentDispContext_st DiveMode_GTR_Dash;
extern const contentDispContext_st DiveMode_NoDecoOrO2TimeTittle;
extern const contentDispContext_st SurfaceMode_TMT_Value;
extern const contentDispContext_st DiveMode_Pressure_TitleTxt;
extern const contentWithStateHandle_st DiveMode_DiveTime_Value;
extern const contentWithStateHandle_st DiveMode_DiveTimeExtra_Value;
extern const contentDispContext_st DiveMode_DiveTime_TitleText;
extern const contentDispContext_st SurfaceMode_Runtime_Tittle;
extern const contentDispContext_st SurfaceMode_Runtime_Value;
extern const contentDispContext_st SurfaceMode_TankPressure_Tittle;
extern const contentDispContext_st SurfaceMode_Linked_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_LooseLink_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_OffLink_TankPressure_Value;
extern const contentWithStateHandle_st DiveMode_NoDecoOrO2TimeValue;
extern const contentDispContext_st DiveMode_TTS_Tittle;
extern const contentDispContext_st DiveMode_TTS_Content;
extern const contentDispContext_st DiveMode_OC_MaxDepth_Tittle;
extern const contentDispContext_st DiveMode_OC_MaxDepthValue_Imperial;
extern const contentDispContext_st DiveMode_OC_MaxDepthValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_MaxDepthValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_MaxDepthDash;
extern const contentDispContext_st DiveMode_OC_AvgDepth_Tittle;
extern const contentDispContext_st DiveMode_OC_AvgDepthValue_Imperial;
extern const contentDispContext_st DiveMode_OC_AvgDepthValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_AvgDepthValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_CeilingValue_Imperial;
extern const contentDispContext_st DiveMode_OC_CeilingValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_CeilingValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_Ceiling_Tittle;
extern const contentDispContext_st DiveMode_OC_GTR_Tittle;
extern const contentDispContext_st DiveMode_OC_GTR_Value;
extern const contentDispContext_st DiveMode_Violation_GTRInBottom_Tittle;
extern const contentDispContext_st DiveMode_Violation_GTRInBottom_Value;
extern const contentDispContext_st DiveMode_OC_GTR_Dash;
extern const contentDispContext_st DiveMode_Violation_GTRInBottom_Dash;
extern const contentDispContext_st DiveMode_Violation_GTRInMiddle_Tittle;
extern const contentDispContext_st DiveMode_Violation_GTRInMiddle_Dash;
extern const contentDispContext_st DiveMode_Violation_GTRInMiddle_Value;
extern const contentDispContext_st DiveMode_OC_WOBDepth_Tittle;
extern const contentDispContext_st DiveMode_OC_WOBDepthValue_Imperial;
extern const contentDispContext_st DiveMode_OC_WOBDepthValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_WOBDepthValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_ENDDepth_Tittle;
extern const contentDispContext_st DiveMode_OC_MODDepthValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_MODDepthValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_ENDDepthValue_Imperial;
extern const contentDispContext_st DiveMode_OC_ENDDepthValue_Metric_Decimal;
extern const contentDispContext_st DiveMode_OC_ENDDepthValue_Metric_Floating;
extern const contentDispContext_st DiveMode_OC_MODDepth_Tittle;
extern const contentDispContext_st DiveMode_OC_MODDepthValue_Imperial;
extern const contentDispContext_st DepthDiveTimeMode_DepthTittle;
extern const contentDispContext_st DepthDiveTimeMode_MaxDepthAlarm;
extern const contentDispContext_st DepthDiveTimeMode_DepthMetric_Decimal;
extern const contentDispContext_st DepthDiveTimeMode_DepthMetric_Floating;
extern const contentDispContext_st DepthDiveTimeMode_DepthImperial;
extern const contentDispContext_st DiveMode_DecoStop_Tittle;
extern const contentDispContext_st DiveModeExtrDepth_DeepOrSSStop_Tittle;
extern const contentDispContext_st DiveModeExtrDepth_DeepOrSSStop_DepthAndTime;
extern const contentDispContext_st DiveModeExtrDepth_NoDecoOrO2TimeTittle;
extern const contentWithStateHandle_st DiveModeExtrDepth_DecoStop_MaxDepth;
extern const contentWithStateHandle_st DiveModeExtrDepth_NoDecoOrO2TimeValue;
extern const contentWithStateHandle_st DiveModeExtrDepth_DecoStop_DepthAndTime;
extern const contentWithStateHandle_st DepthDiveTimeMode_DecoStop_MaxDepth;
extern const contentWithStateHandle_st DepthDiveTimeMode_DecoStop_DepthAndTime;
extern const contentWithStateHandle_st DiveMode_DecoStop_DepthAndTime;
extern const contentWithStateHandle_st DiveMode_DecoStop_MaxDepth;
extern const contentWithStateHandle_st DiveMode_PO2_Value;
extern const contentDispContext_st DiveMode_DeepOrSSStop_DepthAndTime;
extern const contentDispContext_st DiveMode_DeepOrSSStop_Tittle;
extern const contentDispContext_st DiveMode_Compass_DiveTime_TitleText;
extern const contentDispContext_st DiveMode_Compass_DiveTime_Value;
extern const contentDispContext_st CompassMode_ReferenceHeading_Tittle;
extern const contentDispContext_st CompassMode_ReferenceHeading_Value;
extern const contentDispContext_st CompassMode_ReverseHeading_Tittle;
extern const contentDispContext_st CompassMode_ReverseHeading_Value;
extern const contentDispContext_st ALARM_ConditionalViolation;
extern const contentDispContext_st ALARM_CV_GF_90;
extern const contentDispContext_st ALARM_GasSwitch;
extern const contentDispContext_st ALARM_AscentTooFast;
extern const contentDispContext_st ALARM_HighPO2;
extern const contentDispContext_st ALARM_LowPO2;
extern const contentDispContext_st ALARM_OCSM_MaxPO2Alarm;
extern const contentDispContext_st ALARM_OCSM_MinPO2Alarm;
extern const contentDispContext_st ALARM_DecoPO2;
extern const contentDispContext_st ALARM_DecoEntryAlarm;
extern const contentDispContext_st ALARM_DecoWarning;
extern const contentDispContext_st ALARM_DecoAlarm;
extern const contentDispContext_st ALARM_O2Sat;
extern const contentDispContext_st ALARM_O2SatWarning;
extern const contentDispContext_st ALARM_FullViolation;
extern const contentDispContext_st ALARM_GradientFactor;
extern const contentDispContext_st ALARM_N2Bar;
extern const contentDispContext_st ALARM_DepthAlarm;
extern const contentDispContext_st ALARM_DiveTimeAlarm;
extern const contentDispContext_st ALARM_SP_AutoHiAlarm_Line01;
extern const contentDispContext_st ALARM_SP_AutoHiAlarm_Line02;
extern const contentDispContext_st ALARM_SP_AutoLoAlarm_Line01;
extern const contentDispContext_st ALARM_SP_AutoLoAlarm_Line02;
extern const contentDispContext_st ALARM_TimeToSurface;
extern const contentDispContext_st ALARM_TMTLowBattery;
extern const contentDispContext_st WARNING_TMTLowBattery;
extern const contentDispContext_st ALARM_LowBattWarning;
extern const contentDispContext_st ALARM_LowBattAlarm;
extern const contentDispContext_st ALARM_LowBattNoOp;
extern const contentDispContext_st ALARM_WorkOfBreathing;
extern const contentDispContext_st ALARM_EquivalentNarcoticDepth;
extern const contentDispContext_st ALARM_LostTMT;
extern const contentDispContext_st ALARM_GasTimeRemaining;
extern const contentDispContext_st ALARM_GasSwitch;
extern const contentDispContext_st ALARM_SwitchTank;
extern const contentDispContext_st SurfaceMode_3rdRowLeft_Tittle;
extern const char* TxtDef_Set_LowerDepthUnit[SetUnit_MAX];
extern const char* TxtDef_Set_ExLDepthTimeLowerDepthUnit[SetUnit_MAX];
/**/
void DepthAndDiveTime_DepthDashesContext(char* pStrRet);
void DiveMode_DepthValueNormal_Imperial_Context(char* pStrRet);
void DiveMode_DepthValue_MetricDecimal_Context(char* pStrRet);
void DepthAndDiveTime_DepthValueNormal_Imperial_Context(char* pStrRet);
void DiveMode_DepthValueNormal_MetricFloat_Context(char* pStrRet);
void DiveMode_VGM_DepthDashesContext(char* pStrRet);
void DiveMode_DiveTime_Context(char* pStrRet);
void DiveMode_AvgDepth_TitleTxt_Context(char* pStrRet);
void DiveMode_AvgDepthValue_Context(char* pStrRet);
void DiveMode_MaxDepth_TitleTxt_Context(char* pStrRet);
void DiveMode_MaxDepthValue_Context(char* pStrRet);
void DiveMode_GTR_TitleTxt_Context(char* pStrRet);
void DiveMode_GTR_Value_Context(char* pStrRet);
void DiveMode_DashDash_Context(char* pStrRet);
void DiveMode_NoDecoOrO2TimeValue_Context(char* pStrRet);
void DiveMode_NoDecoOrO2TimeTittle_Context(char* pStrRet);
void DiveMode_DecoStop_Minute_Text_Context(char* pStrRet);
void DiveMode_TTS_Tittle_Context(char* pStrRet);
void DiveMode_TTS_Content_Context(char* pStrRet);
void DiveMode_PO2_Tittle_Context(char* pStrRet);
void DiveMode_PO2_Value_Context(char* pStrRet);
void DiveMode_OC_MaxDepth_Tittle_Context(char* pStrRet);
void DiveMode_OC_MaxDepth_Value_Imperial_Context(char* pStrRet);
void DiveMode_OC_MaxDepthValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_MaxDepthValue_MetricFloating_Context(char* pStrRet);
void DiveMode_OC_MaxDepthDash_Context(char* pStrRet);
void DiveMode_OC_AvgDepth_Tittle_Context(char* pStrRet);
void DiveMode_OC_AvgDepthValue_Imperial_Context(char* pStrRet);
void DiveMode_OC_AvgDepthValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_AvgDepthValue_MetricFloating_Context(char* pStrRet);
void DiveMode_OC_AvgDepthDash_Context(char* pStrRet);
void DiveMode_DiveTime_NoDecoTittle_Context(char* pStrRet);
void DiveMode_OC_Ceiling_Tittle_Context(char* pStrRet);
void DiveMode_OC_CeilingValue_Imperial_Context(char* pStrRet);
void DiveMode_OC_CeilingValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_CeilingValue_MetricFloating_Context(char* pStrRet);
void DiveMode_OC_ENDDepth_Tittle_Context(char* pStrRet);
void DiveMode_OC_ENDDepthValue_Imperial_Context(char* pStrRet);
void DiveMode_OC_ENDDepthValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_ENDDepthValue_MetricFloating_Context(char* pStrRet);
void DiveMode_OC_WOBDepth_Tittle_Context(char* pStrRet);
void DiveMode_OC_WOBDepthValue_Imperial_Context(char* pStrRet);
void DiveMode_OC_WOBDepthValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_WOBDepthValue_MetricFloating_Context(char* pStrRet);
void DiveMode_OC_MODDepth_Tittle_Context(char* pStrRet);
void DiveMode_OC_MODDepthValue_Imperial_Context(char* pStrRet);
void DiveMode_OC_MODDepthValue_MetricDecimal_Context(char* pStrRet);
void DiveMode_OC_MODDepthValue_MetricFloating_Context(char* pStrRet);
void DiveMode_DecoStop_DepthAndTime_Context(char* pStrRet);
void ExtraDepthDiveTime_DecoStop_DepthAndTime_Context(char* pStrRet);
void DiveMode_DeepOrSSStop_DepthAndTime_Context(char* pStrRet);
void DiveMode_DeepOrSSStopTittle_Context(char* pStrRet);
void DepthDiveTimeMode_DeepOrSSStop_DepthAndTime_Context(char* pStrRet);
void SurfaceMode_FO2Default_ValueContext(char* pStrRet);
void DiveModeHandle_Display_Clock(ItemStatus_te dispStat);
void DiveModeHandle_BatteryDisplay(void);
void ClearPortion_DiveSM_MiddleRowTitte(void);
void ClearPortion_GTRDisplay(void);
void ClearPortion_CC_PO23rdRowLeftRight(void);
void ClearPortion_3rdContentRight(void);
void ClearPortion_3rdContentLeft(void);
void ClearPortion_BelowSurfaceTime(void);
void ClearPortion_TankPressure(void);
void ClearPortion_NextToBottomSurfTMT(void);
void ClearPortion_GSM_PortionAVGvsMaxDepth(void);
void ClearPortion_BottomAlarmFull(void);
void ClearPortionToUpdateSurfaceMode(void);
void ClearPortionAfterUpdateMenuInList(void);
void ClearPortion_CompassMode_TankPressure(void);
void Display_AR(int Value);
void SurfaceHandle_Deco_NoDeco_DeepStop_SafetyStop(void);
void DiveHandleExtrDepth_NoDecoDecoDeepOrSSStopAndViolation(void);
void DiveModeHandle_Display_Depth(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_MaxDepth(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_AvgDepth(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_Ceiling(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_END(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_WOB(ItemStatus_te dispStatus);
void DiveModeHandle_Display_OC_MOD(ItemStatus_te dispStatus);
void DepthDiveTimeMode_DisplayDepth(ItemStatus_te dispStatus);
void DiveModeHandle_Gauge_Display_GTR(ItemStatus_te dispStatus);
void DiveModeHandle_OC_Display_GTR(void);
void DiveModeHandle_DisplayFO2(void);
void ALARM_GasSwitch_Context(char* pStrRet);
void DiveModeHandle_10Mins_DispDecoSSStopOrViolation(void);
void DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive(void);
void DiveModeOCHandle_AltPage01_CheckDisplayBottom(void);
void DiveModeOCHandle_AltPage02_CheckDisplayBottom(void);
void DiveModeOCHandle_AltPage03_CheckDisplayBottom(void);
void DiveModeOCHandle_AltPage05_CheckDisplayBottom(void);
void Dive_SM_Handle_CheckDisplayMiddle(void);
void Dive_CC_Handle_CheckDisplayMiddle(void);
void DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime(void);
void DiveModeHandle_GSM_SwitchDisplayExtralargeDepthOrDiveTime(void);
void DiveMenu_DECOSTOPS_Context_Left(char*);
unsigned char ColorCheck_DecoStop(void);
AlarmArrowHandle_st DiveMode_AlarmArrowHandleStatus(void);
void DiveMode_AlarmHandleDisplay2ArrowsUpDown(void);
void DepthAndDiveTime_AlarmHandleDisplay2ArrowsUpDown(void);
unsigned char AlarmStatusCheck_ConditionalViolation(void);
unsigned char AlarmStatusCheck_DelayedViolation1(void);
unsigned char AlarmStatusCheck_CV_GF90(void);
unsigned char AlarmStatusCheck_N2Bar(void);
unsigned char AlarmStatusCheck_DepthAlarm(void);
unsigned char AlarmStatusCheck_DepthMaxAlarm(void);
unsigned char AlarmStatusCheck_DiveTimeAlarm(void);
unsigned char AlarmStatusCheck_TimeToSurface(void);
unsigned char AlarmStatusCheck_TMTLowBattery(void);
unsigned char AlarmStatusCheck_WorkOfBreathing(void);
unsigned char AlarmStatusCheck_EquivalentNarcoticDepth(void);
unsigned char AlarmStatusCheck_LostTMT(void);
unsigned char AlarmStatusCheck_GasTimeRemaining(void);
unsigned char AlarmStatusCheck_O2Sat(void);
unsigned char AlarmStatusCheck_DecoAlarm(void);
unsigned char AlarmStatusCheck_LowPO2(void);
unsigned char AlarmStatusCheck_HighPO2(void);
unsigned char AlarmStatusCheck_DecoPO2(void);
unsigned char AlarmStatusCheck_DecoEntry(void);
unsigned char AlarmStatusCheck_OCmaxPO2(void);
unsigned char AlarmStatusCheck_OCminPO2(void);
unsigned char AlarmStatusCheck_AscentTooFast(void);
unsigned char AlarmStatusCheck_LowBatteryWarning(void);
unsigned char AlarmStatusCheck_LowBatteryAlarm(void);
unsigned char AlarmStatusCheck_LowBatteryShutdown(void);
unsigned char AlarmStatusCheck_TurnP(void);
unsigned char AlarmStatusCheck_EndP(void);
bool AlarmStatusCheck_FullViolation(void);
unsigned char AlarmStatusCheck_GasSwitch(void);
unsigned char AlarmStatusCheck_O2SatWarning(void);
unsigned char AlarmStatusCheck_O2SatWarning_FlashingArrow(void);
unsigned char AlarmStatusCheck_GradientFactor(void);
unsigned char AlarmStatusCheck_DecoWarning(void);
ItemStatus_te DiveMode_DispStat_DepthValue(void);
ItemStatus_te DiveMode_DispStat_DiveTimeValue(void);
ItemStatus_te DiveMode_DispStat_PO2(void);
ItemStatus_te DiveMode_DispStat_DTR_Alarm(void);
void DiveModeAlarm_SwitchTankArrow(void);
unsigned char DiveModeAlarm_BottomAlarms(void);
void DiveModeHandle_Display_ExtraDepth(ItemStatus_te dispStatus);
void SurfaceMode_CC6TankPressure(void);
void DivemodeHandle_GSM_CheckDisplayViolationMiddle(ItemStatus_te dispStat);
void DivemodeHandle_GSM_CheckDisplayViolationAboveMiddle(void);

#endif