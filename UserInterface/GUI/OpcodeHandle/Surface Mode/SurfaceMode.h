#ifndef _SURFACEMODE_H_
#define _SURFACEMODE_H_

#include "L4X9_includes.h"
#include "SurfaceMode_Context.h"

/*Battery information struct*/
typedef bool (*p_charingStatus)(void); //pfunction of charing status
/*  */
typedef struct
{
    unsigned char *battValue;           /*pointer to batt value*/
    p_charingStatus battChargingStatus; /*get charging status*/
} battInfo_st;

/*extern variables*/
extern LOG_Data_t Log_Data;
extern const battInfo_st pDataSurfBatt;
extern const contentDispContext_st SurfaceMode_SurfTime_TitleText;
extern const contentDispContext_st SurfaceMode_SurfTime_Hour;
extern const contentDispContext_st SurfaceMode_SurfTime_Min;
extern const contentDispContext_st SurfaceMode_SurfTime_Colon;
extern const contentDispContext_st SurfaceMode_Fly_Tittle;
extern const contentDispContext_st SurfaceMode_Fly_Time;
extern const contentDispContext_st SurfaceMode_LastDive_Tittle;
extern const contentDispContext_st SurfaceMode_LastDive_OnLeft;
extern const contentDispContext_st SurfaceMode_LastDive_Violation;
extern const contentDispContext_st SurfaceMode_GSM_LastDiveInCenter;
extern const contentDispContext_st SurfaceMode_GSM_LastDive_Tittle;
extern const contentDispContext_st SurfaceMode_Runtime_Tittle;
extern const contentDispContext_st SurfaceMode_TMTLeft_Value;
extern const contentDispContext_st SurfaceMode_TMTRight_Value;
extern const contentDispContext_st SurfaceMode_Runtime_Value;
extern const contentDispContext_st SurfaceMode_TMT_Value;
extern const contentDispContext_st SurfaceMode_Desat_Tittle;
extern const contentDispContext_st SurfaceMode_Desat_Value;
extern const contentDispContext_st SurfaceMode_PO2_Tittle;
extern const contentDispContext_st ALARM_LowBattShutDownLine0;
extern const contentDispContext_st ALARM_LowBattShutDownLine1;
extern const contentDispContext_st SurfaceMode_PO2_SMMode_Tittle;
extern const contentDispContext_st SurfaceMode_OCLeftStatusViolation_Value;
extern const contentWithStateHandle_st SurfaceMode_PO2_SMMode_Value;
extern const contentDispContext_st SurfaceMode_Time_Tittle;
extern const contentDispContext_st SurfaceMode_TimeValue;
extern const contentDispContext_st SurfaceMode_TankPressure_Tittle;
extern const contentDispContext_st SurfaceMode_Linked_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_LooseLink_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_OffLink_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_Temperature_Tittle;
extern const contentDispContext_st SurfaceMode_Temperature_Value;
extern const contentDispContext_st DiveMode_TTSBottomRow_Content;
extern const contentDispContext_st DiveMode_TTSBottomRow_Tittle;
extern const contentDispContext_st DepthDiveTimeMode_CenterDivetimeTittle;
extern const contentDispContext_st DepthDiveTimeMode_CenterDivetimeValue;
extern const contentDispContext_st DepthDiveTimeMode_CenterDecoStopTittle;
extern const contentDispContext_st DepthDiveTimeMode_CenterDecoStopValue;
extern const contentDispContext_st DepthDiveTimeMode_CenterDeepOrSSStopTittle;
extern const contentDispContext_st DepthDiveTimeMode_CenterDeepOrSSStopValue;
extern const contentDispContext_st DepthDiveTimeMode_DiveTimeLeft_Tittle;
extern const contentDispContext_st DepthDiveTimeMode_DiveTimeLeft_Value;
extern const contentDispContext_st DepthDiveTimeMode_TankPressRight_Tittle;
extern const contentDispContext_st DepthDiveTimeMode_TankPressRightLinkedValue;
extern const contentDispContext_st DepthDiveTimeMode_TankPressureLooseLinkValue;
extern const contentDispContext_st DepthDiveTimeMode_TankPressureOffLinkValue;
extern const contentDispContext_st SurfaceMode_Elev_Tittle;
extern const contentDispContext_st SurfaceMode_Elev_Value;
extern const contentDispContext_st SurfaceMode_SmallFont_Elev_Value;
extern const contentDispContext_st SurfaceMode_PressActivation_Tittle;
extern const contentDispContext_st SurfaceMode_PressActivation_Value;
extern const contentDispContext_st SurfaceMode_PressActivation_Unit;
extern const contentDispContext_st SurfaceMode_CurrentPress_Tittle;
extern const contentDispContext_st SurfaceMode_CurrentPress_Value;
extern const contentDispContext_st SurfaceMode_CurrentPress_Unit;
extern const contentDispContext_st SurfaceMode_MainGF_Tittle;
extern const contentDispContext_st SurfaceMode_MainGF_Value;
extern const contentDispContext_st SurfaceMode_O2Sat_Tittle;
extern const contentDispContext_st SurfaceMode_O2Sat_Value;
extern const contentDispContext_st SurfaceMode_DilPO2_Tittle;
extern const contentDispContext_st SurfaceMode_DilPO2_Value;
extern const contentDispContext_st SurfaceMode_FiO2_Tittle;
extern const contentDispContext_st SurfaceMode_OCLeft_Tittle;
extern const contentDispContext_st SurfaceMode_OffLink_OCLeft_Value;
extern const contentDispContext_st SurfaceMode_OCRight_Tittle;
extern const contentDispContext_st SurfaceMode_OffLink_OCRight_Value;
extern const contentDispContext_st SurfaceMode_FiO2_Value;
extern const contentDispContext_st SurfaceMode_3rdRowLeft_Tittle;
extern const contentDispContext_st SurfaceMode_3rdRowLeft_Value;
extern const contentDispContext_st SurfaceMode_3rdRowRight_Tittle;
extern const contentDispContext_st SurfaceMode_3rdRowRight_Value;
extern const contentDispContext_st SurfaceMode_OCLeftStatus_Value;
extern const contentDispContext_st SurfaceMode_NotBestGas_OCLeftStatus_Value;
extern const contentDispContext_st DiveMode_NoDecoOrO2TimeTittle;
extern const contentWithStateHandle_st DiveMode_NoDecoOrO2TimeValue;
extern const contentWithStateHandle_st DiveMode_PO2_Value;
extern const contentDispContext_st DiveMode_O2TimeTittle;
extern const contentDispContext_st DiveMode_TTS_Tittle;
extern const contentDispContext_st SurfaceMode_Gauge_GTR_Tittle;
extern const contentDispContext_st SurfaceMode_Gauge_GTR_Value;
extern const contentDispContext_st SurfaceMode_Gauge_GTR_Dash;
extern const contentDispContext_st CompassMode_TankPressure_Tittle;
extern const contentDispContext_st CompassMode_Linked_TankPressure_Value;
extern const contentDispContext_st CompassMode_OffLink_TankPressure_Value;
extern const contentDispContext_st CompassMode_LooseLink_TankPressure_Value;
extern const contentWithStateHandle_st DepthDiveTimeMode_AlarmInBottom;
extern const char* TxtDef_Set_PressActiveUnit[SetUnit_MAX];
extern const char* TxtDef_Set_LowerDepthUnit[SetUnit_MAX];
extern const contentDispContext_st ALARM_LowBattWarning;
extern const contentDispContext_st ALARM_LowBattAlarm;
extern const contentDispContext_st ALARM_LowBattNoOp;
extern const contentDispContext_st ALARM_O2Sat;
/**/
void Display_Battery_Surface(void * pData_st);
void SurfaceMode_SurfTime_TitleText_Context(char*);
void SurfaceMode_SurfTime_Hour_Context(char*);
void SurfaceMode_SurfTime_Min_Context(char*);
void SurfaceMode_SurfTime_Colon_Context(char*);
void SurfaceMode_FlyTittle_Context(char*);
void SurfaceMode_FlyTittle_Value(char*);
void SurfaceMode_LastDive_TittleContext(char*);
void SurfaceMode_LastDive_Context(char*);
void ALARM_FullViolation_Context(char*);
void SurfaceMode_Desat_TittleContext(char*);
void SurfaceMode_Runtime_TittleContext(char*);
void SurfaceMode_Runtime_ValueContext(char*);
void SurfaceMode_Desat_ValueContext(char*);
void SurfaceMode_PO2_TittleContext(char*);
void SurfaceMode_PO2_ValueContext(char*);
void SurfaceMode_Pressure_TittleContext(char*);
void SurfaceMode_TankPressure_Linked_ValueContext(char*);
void SurfaceMode_TankPressure_LooseLink_ValueContext(char*);
void SurfaceMode_TankPressure_OffLink_ValueContext(char*);
void SurfaceMode_TankPressure_InitValueContext(char*);
void SurfaceMode_FO2Default_ValueContext(char*);
void SurfaceMode_TMT_ValueContext(char*);
void SurfaceMode_Time_TittleContext(char*);
void SurfaceMode_TimeValue_Context(char*);
void SurfaceMode_Temperature_TittleContext(char*);
void SurfaceMode_Temperature_ValueContext(char*);
void SurfaceMode_Elev_TittleContext(char*);
void SurfaceMode_Elev_ValueContext(char*);
void SurfaceMode_PressActivation_TittleContext(char*);
void SurfaceMode_PressActivation_ValueContext(char*);
void SurfaceMode_CurrentPress_TittleContext(char*);
void SurfaceMode_PressActivation_UnitContext(char*);
void SurfaceMode_CurrentPress_ValueContext(char*);
void SurfaceMode_MainGF_TittleContext(char*);
void SurfaceMode_MainGF_ValueContext(char*);
void SurfaceMode_Ceiling_ValueContext(char*);
void SurfaceMode_MaxDepth_ValueContext(char*);
void SurfaceMode_AvgDepth_ValueContext(char*);
void SurfaceMode_O2Sat_TittleContext(char*);
void SurfaceMode_O2Sat_ValueContext(char*);
void SurfaceMode_DilPO2_TittleContext(char*);
void SurfaceMode_DilPO2_ValueContext(char*);
void SurfaceMode_FiO2_ValueContext(char*);
void SurfaceMode_FiO2_TittleContext(char*);
void SurfaceMode_OCLeft_TittleContext(char*);
void SurfaceMode_OCLeft_ValueContext(char*);
void SurfaceMode_OCRight_TittleContext(char*);
void SurfaceMode_OCRight_ValueContext(char*);
void SurfaceMode_OCLeftStatus_ValueContext(char*);
void SurfaceMode_OCLeftStatusViolation_ValueContext(char*);
void SurfaceHandle_CheckDispASCBGnN2Bar(void);
void SurfaceHandle_Display3rRowRightContent(void);
void SurfaceHandle_Display3rRowLeftContent(void);
void SurfaceMode_Gauge_GTR_TittleContext(char*);
void SurfaceMode_Gauge_GTR_ValueContext(char*);
void Dive_SM_Handle_MainPage_CheckDisplayBottom(void);
void DiveMode_DashDash_Context(char*);
void SurfaceMode_LastDiveHandle(void);
void SurfaceMode_GSM_LastDiveHandle(void);
void SetSP_UNITSET(char* pStrRet);
void SurfaceMode_CC_MainPage_CheckDisplayBottom(void);
void SurfaceMode_GSM_MainPage_CheckDisplayBottom(void);
void SurfaceMode_SM_MainPage_CheckDisplayBottom(void);
void SurfaceMode_CC6TankPressure(void);
bool Check_All_TMTs_Is_Off(void);
unsigned char SurfaceCheckTMTLeftRightStatus(void);
unsigned char AlarmStatusCheck_LowBattery(void);
ItemStatus_te AlarmStatusHandle_DecoStop(void);
GUI_COLOR SurfaceMode_SurfTime_TitleText_Color(void);
GUI_COLOR AlarmColorHandle_TimeToSurface(void);
GUI_COLOR AlarmColorHandle_DiveTimeAlarm(void);
GUI_COLOR AlarmColorHandle_DepthAlarm(void);
GUI_COLOR AlarmColorHandle_DTR_Alarm(void);
GUI_COLOR Select_TxtColor(void);
GUI_COLOR Unselect_TxtColor(void);
GUI_COLOR Battery_SetColorBaseOnValue(uint8_t battVal);
uint16_t GasSwitchGetPO2A(void);
void DiveModeHandle_Display_Clock(ItemStatus_te dispStat);
GUI_COLOR GTR_ColorHanlde(void);
ItemStatus_te DiveMode_DispStat_PO2(void);
ItemStatus_te CheckPressureLinkingStatus(TMT_NUM_t);
// ItemStatus_te CheckPressureLinkingStatus_GAS_N(TANK_NUM_t, TANK_NUM_t);
// ItemStatus_te DispPressFlashingCheck(TMT_NUM_t);
TxtStr_Name_e SetGasGetMode(unsigned char diveModeInput, unsigned char gasNumPos);
void SurfaceHandle_PressureDisplay(void);
void CompassHandle_PressureDisplay(void);
void DiveModeHandle_Violation_Display_GTRBottom(void);
void SurfaceHandle_DisplayGTR(ItemStatus_te dispStatus);
void SurfaceHandle_DisplayTANK_LR(void);        // for SM only
void SurfaceHandle_DisplayTMT_LR(void);         // for GSM only

#endif
