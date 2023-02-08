
#ifndef STUB_L4X9_H_
#define STUB_L4X9_H_

#define _SIMULATE_PC
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "GUI.h"
#include "WM.h"
#include "main.h"
#include "MainTask.h"
#include "..\..\LangTextString\TxtStr_Order_DSX.h"
#include "..\..\Icon_DSX.h"
#include "..\..\OC_DSX.h"
#include "..\..\DSX_Data_Decode.h"
#include "..\..\DSX_Data_Process.h"
#include "..\..\DSX_Coordinate.h"
#include "..\..\ShapeDSX.h"
#include "..\..\DSX_FontStruct.h"
#include "..\..\Text_DSX.h"
#include "..\..\..\DsxOCDefine.h"
#include "..\..\..\GUI\DsxOcConfig.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

/*Extern from algorithm*/
extern float PO2atDepth;
extern bool isSSorDS;
extern union AlarmUNION Alarming;
extern union AlarmUNION Alarming2;
extern union AlarmUNION AlarmOn;
extern union AlarmUNION AlarmOn2;
extern union AlarmUNION AlarmOccured;
extern union AlarmUNION AlarmDueAck;
extern union AlarmUNION AlarmDueAck2;
extern uint16_t GFmaxValue;
extern uint8_t SensorReadbackLux;
extern uint8_t CurrGasNumber;
extern uint8_t ButtonNoResponseCnt;
extern uint8_t BestGasNumber;
extern uint8_t u32DiveTimeHr;
extern uint8_t GFHighSettingValue;
extern uint8_t OTUpercent;
extern Scuba_Settings_t     SCUBA_Set;
extern TP_Info_struct_t TP_Info;
extern Dive_Info_struct_t Dive_Info;
extern uint8_t FLYtime;
extern uint8_t DSATtime;
extern uint8_t SwitchFO2_InFlashing;
extern uint8_t AlarmID;
extern uint8_t GFvalue;
extern uint8_t  PO2A[];
extern User_Settings_t         USER_Set;
// extern GUI_COLOR Shape_Color_TopBar;
extern EcData_struct_t EcData;
extern DSX_OPCODE_t DSX_Opcode;
extern SystemTimeDate_t SysTimeDatePST;
extern uint16_t NDT_Data; 
extern int DecoStop[42], DecoTime[42], DecoGas[42], DecoFO2[42], DecoFHe[42];
extern int BDecoStop[42], BDecoTime[42], BDecoGas[42], BDecoFO2[42], BDecoFHe[42];
extern unsigned int otrTime, TDT, TAT_Data, Total_DST, EDTtime;
extern unsigned char TLBGVal, ASCBGVal, MaxASCBGVal, OTUpercent, DelayFlag;
extern unsigned char isSwitchGas;
extern unsigned char NeedToSwitchGas;
extern unsigned char DeclinedGasNumber;
extern unsigned char SuggestedBestGasNumber;
extern Device_Records_t DEV_Rec;
extern Mfg_Calibration_t  MFG_Calib;
extern L4X9_SysStat_t SystemStatus;
extern DSX_OPCODE_t pre_DSX_Opcode;
extern uint8_t HW_Buttons;
extern uint8_t GUI_CurrGasNum;
extern DSX_OPCODE_t DSX_OPCODE;  // New Opcode for DSX
extern int32_t MonotonicClock_s;
extern uint8_t in_buf[];
extern uint8_t fFO2[];
extern uint8_t GUI_BRIGHTNESS_LV;   
extern NVD_status_t  GUI_DIVE_T_AL_STAT;     // GUI settings for DIVE_T_STAT (Off, On, Set)
extern L4X9_SystemSupplyMonitor_t SystemSupplyMonitor;
extern GPS_LocationRec_t Target_Loc;
extern LOG_Data_t Log_Data_7[];
extern TRIMIX_Settings_t       TRIMIX_Set;
extern Free_Settings_t          FREE_Set;
extern Free_Records_t           FREE_Rec; 
extern FLASH_Map_t              FLASH_Map;
extern unsigned char debugBuff[];
extern unsigned char TLBG_ARRAY[];
extern unsigned char SIMOTUpercent;
extern LOG_Data_t Log_DataTest[];
extern LOG_Data_t Log_Data;
extern int Plan_DEPTH_NDT_OTR_PO2[25][4];
extern uint8_t hadc1;
extern uint8_t ccSPcurrent;
extern uint8_t SIM_MESSAGE;
extern float O2_Analyzer_Volt;
extern float Pamb;
extern uint8_t O2_Analyzer_Pct;
extern uint8_t O2_ADC_V_Analyze1;
extern uint8_t CURRENT_PRESSURE_MBAR;
extern uint8_t GUI_O2_AnalyzerFO2Set;
extern float O2_SetForCalib_Pct;
extern uint8_t Compensated_Uint8_O2_Pct;
extern float CellNewToDepletedFactor;
extern uint16_t O2_Cell_mV_Of_Set_FO2;
extern float Calculated_Tank_FO2_Pct;
extern uint8_t GUI_O2_AnalyzerFHeSet;
extern L4X9_TickHanlder_t TickHandler;
extern EcRawData_struct_t EcRawData;
extern unsigned int CONS_FO2_FHe_RMV[7][3];
extern TMT_NUM_t  GUI_TMT_Num_InSetting;
extern TMT_NUM_t  GUI_TankN_Linked;
extern uint8_t isViolation;
extern uint8_t isGaugeMode;
extern uint8_t isCCMode;
extern uint8_t GFBGVal;
extern float fMaxDepthFt;
extern uint8_t fMaxDepthM;
extern uint8_t DS_Counter;
extern float fAvgDepthM;
extern uint8_t fAvgDepthFt;
extern uint8_t FiO2;
extern uint8_t Dil_PO2;
extern uint8_t ConditionTime;
extern uint8_t ATR;
extern uint8_t DECOSTOP_Depth;
extern uint8_t DECOSTOP_Min;
extern uint8_t DecoStatus;
extern uint8_t ccSPlow;
extern uint8_t ccSPhigh;
extern uint8_t AutoSP_Low_MaunalOverwrite;
extern uint8_t AutoSP_High_MaunalOverwrite;
extern uint8_t ccSP_ManualChangedToLow;
extern uint8_t ccSP_ManualChangedToHigh;
extern uint8_t GUI_TMT_Connection_Status;
extern TIMER_t Chrono;
extern TIMER_t Runtime;
extern uint32_t GUI_TMT_InSetting_PSI;
extern uint16_t GUI_TMT_PressPSI_ofGAS[8];
extern uint16_t GUI_TMT_PressPSI[8];
extern uint16_t Pi_iN2[8];
extern uint16_t GUI_TMT_TimeStamp[8];
extern uint16_t FO2A[8];
extern uint16_t FHeA[8];
extern uint16_t GUI_TMT_id[8];
extern uint16_t CTANK[7];
extern uint16_t u32DiveTimeMin;
extern uint16_t u32DiveTimeSec;
extern float fDepthFt;
extern float fDepthM;
extern uint16_t GUI_CC6_TimeStamp;
extern uint16_t GUI_CC6_PressPSI;
extern TankData_t g_Data;
extern GnssGGA_struct_t GnssGGA;
extern uint8_t GnssStatus;
extern uint8_t O2_Primary_V_ZeroOffset;
extern uint8_t O2_ADC_V_ZeroOffset;
extern uint8_t O2_ADC_V_Calib;
extern uint8_t CURRENT_TMT_NUM_GSM;
extern uint8_t CURRENT_TMT_NUM_GAUGE;
extern uint8_t AutoBRIGHTNESS;
extern unsigned char DVSTAT;
extern unsigned char isSSdisplayON;
extern bool isSSflagON;
extern unsigned char isDSflagON;
extern unsigned char OC_END_AtDepthFT;
extern unsigned char OC_WOB_depthFT;
extern unsigned char SS_Counter;
extern unsigned char fMaxDepthM;
extern bool CableCharging(void);
extern bool BatteryCharging(void);
extern uint8_t ButtonNoResponseCnt;   
extern LOG_Chart_t Log_Chart_7[];
extern LOG_Chart_t Log_Chart;
extern LOOSE_LINK_t GUI_TMT_InLinking[10];
extern TMT_Connection_t GUI_TMT_Battery[10];
extern GPS_WayFinder_t GUI_WayFinder;  // The GPS Database read back from ExFLASH
extern uint16_t ProfileChartData[200];  
extern MMC_Output_t MMC_Output;
extern uint32_t CounterCaliCompass;
extern NVD_YesNo_t GUI_SWITCH_LCD_GTR_L_R;

#endif
