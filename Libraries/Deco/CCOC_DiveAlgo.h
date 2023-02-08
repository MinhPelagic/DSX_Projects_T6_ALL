/*******************************************************************************
 * @file        : CCOC_DiveAlgo.h
 * @brief       : FW for Dive Computer and Dive Watch algorithms
 *                The whole project is based on the STMCubeMX L1 v1.8.1 HAL
 *                and LL package, to get advantage of portability on the whole
 *                L1 device range.
 *
 * @version     XX.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2020 --------.
 * Author: YeuShyr Wu and Anthony Ha, Pelagic Pressure Systems/Aqualung
 *******************************************************************************
 * Date updated: January 19-2022
 *
 ******************************************************************************/


#ifndef __CCOC_DIVEALGO__H__
#define __CCOC_DIVEALGO__H__

#include "..\UserInterface\GUI\OpcodeHandle\Menu\Dive Planner\Menu_DiveSim_SimulateDive.h"

// NumberOfGases for AQUA LUNG i330R is 3
#define TRUE                    1
#define FALSE                   0

#define NITROX_ARRAY_SIZE       17
#define DECO_LEVEL_MAX          42

typedef enum
{
    LAST_STOP_SHALLOWEST = 0,   // 10 Ft in Imperial; 3 M Metric
    LAST_STOP_DEEPER,           // 20 Ft in Imperial; 6 M Metric
    LAST_STOP_MAX,
} LAST_STOP_t;

#define CC_PO2_LIMIT  1.05

extern unsigned int ATR, CTANK[7];
extern bool is5MinATR, is0MinATR, isTURNalarm, isENDalarm;

// global routines and function declaration
// -----------------------------------------------------------------------------
extern void Init_TankPressure(void);
extern void Get_TankPressure (void);
extern void Cal_ATR (void);
extern void Cal_SAC (void);


extern uint8_t i330_key_task;



// ------------THE BEGINING OF DATA RETENTION ----------------------------------
// ATH declared variables for DATA RETENTION

extern bool isNitrox, isCCMode, isSwitchGas, NeedToSwitchGas;
extern bool isDecoDive, isHighPO2, isDiveMode, isDiveContinue, isDSATcalculate;
extern bool isGaugeMode, isConditional, isViolation, isViolationModeChanged;
extern bool isSSorDS, isSSflagON, isDSflagON, DM_Entried, isSSdoneYet, isDSdoneYet, isSSdisplayON, isDSdisplayON;
extern uint8_t AutoSP_Reached_High;     // a count for DepthOfAutoSPhigh is reached durig the dive, reset in each new dive
extern uint8_t AutoSP_Reached_Low;      // a count for DepthOfAutoSPlow is reached durig the dive, reset in each new dive
extern uint8_t AutoSP_Switched_High;    // a count to check if AutoSP High is switched durig the dive, reset in each new dive
extern uint8_t AutoSP_Switched_Low;     // a count to check if AutoSP Low is switched durig the dive, reset in each new dive
extern bool AutoSP_Started_High;        // a flag to note that the dive started from AutoSP High
extern bool AutoSP_Started_Low;         // a flag to note that the dive started from AutoSP Low

extern bool AutoSP_High_MaunalOverwrite;        // manual overwrite on Auto SP High logic 
extern bool AutoSP_Low_MaunalOverwrite;         // manual overwrite on Auto SP Low logic 

extern unsigned int FLYtime, DSATtime ;   // Count-Down
extern unsigned char GFBGVal, DVSTAT, TLBGVal, ASCBGVal, MaxASCBGVal, OTUpercent, DelayFlag, SIMOTUpercent, FiO2;
extern float Pamb, OTUD, OTUS, GFmaxValue;
extern float PO2MAXatDepth, CC_MaxPO2_SetofDive, MaxOpDepthFT, MaxOpDepthM;
extern unsigned int SImin, SItime;
extern unsigned char FO2A[7], FHeA[7], FN2A[7], PO2A[7] ;       // user setting in EEPROM
extern unsigned char FO2B[7], FHeB[7], FN2B[7], PO2B[7] ;       // user setting in EEPROM
extern float fFO2[7], fFHe[7], fFN2[7], fPO2[7];
extern float fPO2_MAX;
extern float fFO2B[7], fFHeB[7], fFN2B[7], fPO2B[7];
extern float Pi_iN2[NITROX_ARRAY_SIZE], Pi_iN2_prev[NITROX_ARRAY_SIZE], Pi_iHe[NITROX_ARRAY_SIZE], Pi_iHe_prev[NITROX_ARRAY_SIZE];
extern float SF_PiN2[NITROX_ARRAY_SIZE], SF_PiHe[NITROX_ARRAY_SIZE], Save_PiN2[NITROX_ARRAY_SIZE], Save_PiHe[NITROX_ARRAY_SIZE], Prev_PiN2[NITROX_ARRAY_SIZE], Prev_PiHe[NITROX_ARRAY_SIZE];

extern float MOPDAL[10];
extern unsigned char TLBG_ARRAY[NITROX_ARRAY_SIZE];
// ------------ THE END OF DATA RETENTION --------------------------------------


// global variables that do no tneed to saved for DATA RETENTION
//extern uint8_t i330_key_task;
extern int DecoStop[DECO_LEVEL_MAX], DecoTime[DECO_LEVEL_MAX], DecoGas[DECO_LEVEL_MAX], DecoFO2[DECO_LEVEL_MAX], DecoFHe[DECO_LEVEL_MAX];
extern int BDecoStop[DECO_LEVEL_MAX], BDecoTime[DECO_LEVEL_MAX], BDecoGas[DECO_LEVEL_MAX], BDecoFO2[DECO_LEVEL_MAX], BDecoFHe[DECO_LEVEL_MAX];
extern unsigned char  DS_Counter, SIM_MESSAGE;
extern unsigned int ConditionTime, SS_Counter, CONS_FO2_FHe_RMV[7][3];  //FO2/FHe/RMV
extern uint16_t NDT_Data;      // The variables as algorithm output in unsigned integer
extern float CurrDepthFt, PO2atDepth, Dil_PO2, ccSPlow, ccSPhigh, ccSPstart, ccSPcurrent, Pre_ccSPcurrent, ccSPcustom;
extern bool ccSP_AutoChangedToHigh, ccSP_AutoChangedToLow, ccSP_ManualChangedToHigh, ccSP_ManualChangedToLow;
extern int Plan_DEPTH_NDT_OTR_PO2[25][4];
extern unsigned int otrTime, TDT, TAT_Data, Total_DST, EDTtime, TOXIC;
extern float OC_END_AtDepthFT, OC_WOB_depthFT, OC_END_AtDepthM, OC_WOB_depthM;;
extern unsigned char CurrGasNumber, BCurrGasNumber, BestGasNumber, SuggestedBestGasNumber, DeclinedGasNumber, NumberOfActiveGases;
extern float BestGasPO2;
extern TANK_NUM_t BO_BestGasNum[];
extern uint8_t BO_GasFO2Hi2Lo[];
extern uint16_t BO_BestGasPO2[], BO_GasPO2[];
// -----------------------------------------------------------------------------
// global functions declanation
extern void DiveAlgo(void);
extern void IntinalizeGasVariables(void);

extern void UpdateCurrentGasNumber(unsigned char gas);
extern void Cal_4_Array(void);
extern float GetMaxOperationDepth(float, float);
extern void Display_PLANGF(void);
extern void DoNothing(void);
extern void DiveMode(void);
extern void InitAll(void);
extern void InitFO2_FHe(void);
extern void Switch_Gas(void);
extern void Switch_Mode(void);
extern void Predict_Deco_List(void);
extern void Check_For_Deco(void);
extern void SaveRetendedData(uint8_t);
extern void ReadRetendedData(uint8_t);
extern void Update_Algo(void);
extern float FindEND(void);
extern float FindHT(void);
extern float FindWOB(void);
extern float FindMOD(void);
extern float Find_BestGas_MOD(uint8_t);
extern float Find_GUI_MOD(void);
extern uint8_t Find_Gonsv_Hi(void);
extern uint8_t Find_Gonsv_Lo(void);
extern void Find_FiO2_DilPO2(float);
extern float fPO2_Value(void);
extern void Find_FiO2_DilPO2_Values (void);
extern void Check_SPcurrent(void);

extern uint16_t GF_Overtime(void);
extern bool VGM_Check(void);
extern bool ICD_Check(uint8_t, uint8_t);
extern uint16_t TLBit(void);
extern float SaltToFreshDepthFactor(void);
extern float SaltEqDensityFactor(void);
extern bool AutoSP_SwitchingToLow(void);
extern bool AutoSP_SwitchingToHigh(void);
extern TANK_NUM_t FindBestGasBO_WhenDiveIn(uint8_t*, TANK_NUM_t*);
extern TANK_NUM_t FindBestGasBO_WhenSwitchFromCCtoBO(TANK_NUM_t);
extern int16_t CoDis_VerifyTheCompassValue(void);
extern TANK_NUM_t FindBestGasAtDive(void);      // using MOD for caculation, but not in use
extern TANK_NUM_t FindBestGas(float, float*);
//------------------------------------------------------------------------------
// To display NORM Air dive
// FO2A[1] = 0
// DVSTAT = 0x10
// DTR using NDT_Data
// ASCBGVal
// TLBGVal

//------------------------------------------------------------------------------
// To display NORM Nitrox dive
// FO2A[1] >= 21
// DVSTAT = 0x20
// DTR using NDT_Data or OTRtime which ever is less.
// ASCBGVal
// TLBGVal
// PO2atDepth
//------------------------------------------------------------------------------
// To Display DEEP STOP
// DVSTAT = 0x30
// check: isSSorDS = true
// DEPTH: (fMaxDepthFt/ 2)
// time:  DS_Counter
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// To Display SAFETY STOP
// DVSTAT = 0x30
// check: isSSorDS = false
// DEPTH IMPERIAL: SCUBA_Set.SafetyStopDepthFt 0 = 10FT, 1 = 15 FT, 2 = 20FT
// DEPTH METRIC: SCUBA_Set.SafetyStopDepthM 0 = 3M, 1 = 4M, 2 = 5M, 3 = 6M
// time:  SS_Counter
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// To display HIGH O2 dive
// DVSTAT = 0x40
// 100% OTU
// ASCBGVal
// TLBGVal
// PO2atDepth
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// To display HIGH PO2 dive
// DVSTAT = 0x50
// DTR using NDT_Data or OTRtime which ever is less.
// ASCBGVal
// TLBGVal
// PO2atDepth
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// To display GAUGE dive
// DVSTAT = 0x90
// ASCBGVal
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// To display FREE dive
// DVSTAT = 0xa0
// DTR using NDT_Data
// TLBGVal

#endif //__CCOC_DIVEALGO__H__