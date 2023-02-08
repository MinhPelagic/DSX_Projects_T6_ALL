/*******************************************************************************
 * @file        : L4X9_NVData.c
 * @brief       : This file contains all routines handling the NonVolatile
 *                Data Structure
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_NVDATA_H_

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/
#define RET_NEW_DAY     0
#define RET_A           1
#define RET_B           2

/*********************************************************************************************************************************************************
* @brief The Data Initializations for RAM Data Structures
*********************************************************************************************************************************************************/
uint8_t MyInfoBuff[BLOCK_SIZE/INFO_DATA_SIZE][INFO_DATA_SIZE]; // RAM For Reading MyInfo[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];

#if 0
uint8_t* sInfoName =    &MyInfoBuff[0][0];
uint8_t* sInfoAddr =    &MyInfoBuff[1][0];
uint8_t* sInfoPhone =   &MyInfoBuff[2][0];
uint8_t* sInfoEmail =   &MyInfoBuff[3][0];
uint8_t* sInfoBlood =   &MyInfoBuff[4][0];
uint8_t* sInfoContact = &MyInfoBuff[5][0];
#endif
/*******************************************************************************
 * @brief   Initialize Hardware Calibration Global Structure
 ******************************************************************************/

void HW_Cal_Init( Mfg_Calibration_t *Data )
{
    //uint8_t PN[6] = {'A','B','C',1,2,3};
   // uint8_t PF[2] = {'G','D'};
    //uint8_t *pPN;
    //uint8_t *pPF;
    /* Initilize Data Structure all values to 0 */
    memset(Data, 0, sizeof(Mfg_Calibration_t));

    //pPN = PN;
    //pPF = PF;

    //-----------------------------------------------------------
    Data->Date.Month= 6;
    Data->Date.Day = 1;
    Data->Date.Year = 20; // for 2020

    //Data->PartNumber[0] = *(pPN);
    //Data->PartNumber[1] = *(pPN+1);
    //Data->PartNumber[2] = *(pPN+2);
    //Data->PartNumber[3] = *(pPN+3);
    //Data->PartNumber[4] = *(pPN+4);
    //Data->PartNumber[5] = *(pPN+5);

    //Data->Prefix[0] = *(pPF);
    //Data->Prefix[1] = *(pPF+1);

    //Data->SN.SerialNum = 222222;      /* 4-Byte, or 32-bit Serial Number 0000000001 to 4294967295 */
    Data->SN.KeyToDive = 0xFF;
    //-----------------------------------------------------------


    Data->BattWarning_mV = 4000;	// 3700mV  /*YELLOW*/
    Data->BattCutoff_mV = 4000;	// 3650mV  /*RED*/
    Data->LF_Crystal_Cal = 0;
    Data->LF_Crystal_Sign = 0;       // 0: (+),   1: (-)
    Data->CalibrationTempF = 25;    // 25 C
    Data->TemperatureCount = 0;
    Data->ClearID = 0x0797;        // Pelagic Clear ID: 1943 = 0x0797
    //-----------------------------------------------------------

    Data->TankOffset = 0;
    Data->TankGain1 = 0;
    Data->TankCount1 = 0;
    Data->TankGain2 = 0;
    Data->TankCount2 = 0;
    Data->TankGain3 = 0;
    Data->TankCount3 = 0;
    Data->CKSU7 = 0;
    //-----------------------------------------------------------

    Data->LP_Sensor_Offset_ubarx10 = 0;
    Data->Temp_Sensor_Offset_mCx10 = 0;
    Data->TankCntPerDeg = 0;               /* 2-Byte Tank Count per PSI 4st session*/
    Data->TankGainSign = 0;

    Data->PassCodeEnable = 0;

    srand(MonotonicClock_s);
    for(uint32_t i = 0; i<16; i++)
    {
        uint32_t Random = (uint32_t)rand();
        Data->MacId[i] = (uint8_t)(Random%0xFF);
    }

    /*
      Data->GainCount = 0;
      Data->MaxBL = 0;
      Data->DegreeC = 25;            // Default TempF = 25 C
      Data->Phantom = 5;            // Phantom Dive = 5 seconds
      Data->KMFlag = 0;
      Data->KOFFN = 0;
      Data->TOFFN = 0;
      Data->CrystalCaliH = 0;
      Data->CrystalCaliL = 0;
      Data->TankGain4 = 0;
      Data->TankGainSign = 0;
    */
    //-----------------------------------------------------------    
    Data->CRC_MSB = 0;
    Data->CRC_LSB = 0;
}

/*******************************************************************************
 * @brief   Initialize Device Parameters Global Structure
 ******************************************************************************/

void DEV_Rec_Init( Device_Records_t *Data )
{
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        /* Initilize Data Structure all values to 0 */
        memset(Data, 0, sizeof(Device_Records_t));
    }
    
    //-----------------------------------------------------------
    Data->OldFW_Ver = Data->FW_Ver;
    Data->FW_Ver = GET_FW_VERSION;
    Data->FW_Addr = EXFLASH_FIRMWARE;
    Data->RetainIndex = 0;        // 0: A  1: B
    Data->LockForGaugeDive = 0;   // Reset to release the lockup at Gauge Dive or GSM Dive
    //-----------------------------------------------------------

    Data->FW_PST.Hour = SysTimeDatePST.Hour;
    Data->FW_PST.Minute = SysTimeDatePST.Minute;
    Data->FW_PST.Second = SysTimeDatePST.Second;
    Data->FW_PST.Day = SysTimeDatePST.Day;
    Data->FW_PST.WeekDay = SysTimeDatePST.WeekDay;
    Data->FW_PST.Month = SysTimeDatePST.Month;
    Data->FW_PST.Year = SysTimeDatePST.Year;

    Data->RTC_PST.Hour = SysTimeDatePST.Hour;
    Data->RTC_PST.Minute = SysTimeDatePST.Minute;
    Data->RTC_PST.Second = SysTimeDatePST.Second;
    Data->RTC_PST.Day = SysTimeDatePST.Day;
    Data->RTC_PST.WeekDay = SysTimeDatePST.WeekDay;
    Data->RTC_PST.Month = SysTimeDatePST.Month;
    Data->RTC_PST.Year = SysTimeDatePST.Year;
    //-----------------------------------------------------------

    Data->MonoClockSec = MonotonicClock_s;

    if( CheckBrandNewEE() || ToManualResetEE() )
    {        
        Data->DiveNumOfDay = 0;
        Data->LogNumRecorded = 0;
        Data->LogNumLast = 0;
        Data->LogNumDisp = 0;

        Data->DevLowestTempF10 = 1220;
        Data->DevHighestTempF10 = 0;

        //-----------------------------------------------------------
        Data->DevMaxDepthFt10 = 0;
        Data->DevMaxDepthM10 = 0;
        Data->DevAvgDepthFt = 0;
        Data->DevAvgDepthM = 0;
        Data->DevMaxPressurePSI = 0;
        Data->DevMaxPressureMbar10 = 0;
        //-----------------------------------------------------------

        Data->TotalHours = 0;
        Data->TotalMins = 0;
        Data->TotalSecs = 0;
        Data->TotalDiveTimeSec = 0;
        Data->MaxDiveTimeSec = 0;
        Data->LogNormNumRecorded = 0;
        Data->LogGaugeNumRecorded = 0;
        Data->LogFreeNumRecorded = 0;
        //-----------------------------------------------------------

        Data->AddrNewProfileHead = EXFLASH_PROFILE;
        Data->AddrNewProfileEnd  = EXFLASH_PROFILE;
        Data->AddrLastProfile    = EXFLASH_PROFILE;
        Data->AddrNextProfile    = EXFLASH_PROFILE;

        Data->DevTotalDiveNum = 0;     /* 2-Byte Device Total Dive Number */
        Data->MaxAltitudeFt = 0;       /* 2-Byte Max Altitude Feet */
        Data->MaxAltitudeM = 0;        /* 2-Byte Max Altitude Meter */
        Data->FreeDiveNumOfDay = 0;    /* 2-Byte Free Dive Number of the NEWDAY */
        Data->FreeLogNumRecorded = 0;  /* 2-Byte Free Dive Total LOG Number can be saved in Device (a constant) */
        Data->FreeLogNumLast = 0;      /* 2-Byte Free Dive Total Number of LOG already saved */
        Data->FreeLogNumDisp = 0;      /* 2-Byte Free Dive Current Number of LOG */
        
        Data->CompassCali.HI_Bias[0] =  29.1;
        Data->CompassCali.HI_Bias[1] =  9.4;
        Data->CompassCali.HI_Bias[2] = -19.9;
        Data->CompassCali.SF_Matrix[0][0] =  0.97;
        Data->CompassCali.SF_Matrix[0][1] =  0.09;
        Data->CompassCali.SF_Matrix[0][2] =  0.17;
        Data->CompassCali.SF_Matrix[1][0] =  0.09;
        Data->CompassCali.SF_Matrix[1][1] =  1.34;
        Data->CompassCali.SF_Matrix[1][2] = -0.06;
        Data->CompassCali.SF_Matrix[2][0] =  0.17;
        Data->CompassCali.SF_Matrix[2][1] = -0.06;
        Data->CompassCali.SF_Matrix[2][2] =  1.15;
        Data->CompassCali.CalQuality = MMC_CALQSTATUSGOOD;
    }
    Data->RXCtrl = 0;
    Data->GXCtrl = 0;

    Data->SystemErrorWarningBits.AllBits = 0;
    
    Data->O2_Analyzer_V2Pct_Slope = 1.0;    // Based on YS's test on first O2 Cell sample (2021 Oct)
    Data->O2_Analyzer_V2Pct_Offset = 0.0;   // Based on YS's test on first O2 Cell sample (2021 Oct)
    
    //-----------------------------------------------------------
    Data->CRC_MSB = 0;
    Data->CRC_LSB = 0;
}


/*******************************************************************************
 * @brief   Initialize General System Settings Global Structure
 ******************************************************************************/

void User_Set_Init( User_Settings_t *Data )
{
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        /* Initilize Data Structure all values to 0 */
        memset(Data, 0, sizeof(User_Settings_t));
    }
    
    //------------------------------------------
    Data->TitleColor = ColorSel_CYAN;
    
    Data->SwitchSet.Bit.HR24_Format = NVD_12HR;
    Data->SwitchSet.Bit.DDMM_Format = NVD_MD;

    Data->SwitchSet.Bit.LCD_Flip = 0;
    Data->RefTZidx = 0;
    Data->HomeAway = NVD_HOME;
    Data->HomeTZidx = 0;
    Data->AwayTZidx = 0;

    Data->HomeTZhrdiff = 0;
    Data->HomeTZmindiff = 0;
    Data->AwayTZhrdiff = 0;
    Data->AwayTZmindiff = 0;

    Data->PhantomSec = 5;         /* 1-Byte 8-bit Phantom Dive Sec = 5 seconds */
    Data->PTAlarmSec = 5;         /* 1-Byte 8-bit PT?  is this redundant? */
    Data->ChronoCntDwnSec = 5;    /* 2-Byte 16-bit Chrono Count Down Second */
    //------------------------------------------
    Data->ReturnDiveMode = Data->DiveMode;
    
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        Data->DiveMode = NVD_MDOC;              // OC Mode is set as manufactuer default mode
        Data->ReturnDiveMode = Data->DiveMode;  // OC Mode is set as manufactuer default mode
        Data->LangSelec = Select_ENGLISH;                 // Reset for language
        Data->SwitchSet.Bit.Unit = NVD_IMPERIAL;          // Reset for UNIT
        Data->WayFinderLocNum = 0;        
    }
    Data->WaterType = NVD_SALT;           // Sea
    Data->SamplingTime = NVD_2SEC;        // 1 Data Sample per 2 Seconds
    Data->ScreenSet = 0;                  // default Welcome Screen 
    Data->BacklightMode = NVD_ON;         // Not really applied to DSX, reserved for other products
    Data->BacklightLevel = 70;            // ranged from 10% to 100%
    Data->DimBacklightMode = NVD_OFF;     // ranged from 10% to 60%
    Data->DimBacklightLevel = 30;         // ranged from 10% to 60%
    Data->BacklightOnTimeSec = 600;       // fixed at 600 sec
    Data->BacklightDimTimeSec = 120;      // ranged from 20 sec to 120 sec
    Data->YellowBacklightLevel = 60;      // initilaized to 60%
    Data->YellowDimBacklightLevel = 30;   // initilaized to 30%
    Data->RedBacklightLevel = 30;         // initilaized to 30%
    Data->RedDimBacklightLevel = 10;      // initilaized to 10%
    //------------------------------------------

    //Data->SwitchSet.AllBits = 0x00000000;
    Data->SwitchSet.Bit.BluetoothOn = true;
    Data->SwitchSet.Bit.AlarmAudible = true;
    Data->SwitchSet.Bit.AlarmVibeOn = true;
    Data->SwitchSet.Bit.DeepStopOn = false;                                     // DSX does NOT have Deep Stop feature
    Data->SwitchSet.Bit.GTRforLnR = false;                                      // R1005 Set NO first, otherwise the user does not know it, and may finish unexpectedly
    
    Data->CompassDirection = NVD_EAST;
    Data->COMOD = 0;
    Data->CompassDeclinationDeg = 0;
    Data->COMflag = 0;    
    //------------------------------------------------------------

    Data->SAC_Rate = 0;
      
    Data->AlarmTimeout1 = 30;
    Data->AlarmTimeout2 = 30;
    Data->AlarmTimeout3 = 30;

    Data->SleepTimeoutSec = 30;
    Data->DeepSleepTimeoutSec = 30;

    Data->ClockAlarmHH = 0;
    Data->ClockAlarmMM = 0;
    Data->ClockAlarmSS = 0;
    Data->ClockAlarmWD = 0;
    //------------------------------------------------------------

    Data->StartDiveDepthFt = START_DIVE_DEPTH_FT;         //5;
    Data->EndDiveDepthFt = END_DIVE_DEPTH_FT;             //3;
    Data->StartDiveDepthdM = 15;
    Data->EndDiveDepthdM = 9;
    
    Data->CC_3RowL = 0;
    Data->CC_3RowR = 0;
    Data->OC_3RowL = 0;
    Data->OC_3RowR = 0;
    Data->SM_3RowL = 0;
    Data->SM_3RowR = 0;
    
    Data->GForN2 = 0;   // default is 0 (0: GF;   1: N2)
    Data->FontSize = 0;
    
    Data->SIM_Mode = SIM_MODE_NEW_00; // 1: Continouous Dive Simulator;   0: New Dive Simulator
    Data->SIM_SP = 100;
    Data->SIM_Time = 30;
    Data->SIM_DepthFT = 100;
    Data->SIM_DepthM = 30;
    Data->SIM_SAC_CuFt = 85;
    Data->SIM_SAC_Ltr = 24;
    
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        for(uint8_t i=0; i<16; i++)
        {
            Data->SLATE_Idx[i] = 0;
            Data->SLATE_Stat[i] = 0;
            Data->SLATE_Data[i] = 0;
        }

        for(uint8_t i=0; i<3; i++)
        {
            Data->Welcome_Idx[i] = 0;
            Data->Welcome_Stat[i] = 0;
        }

        Data->CurrWelcome_Idx = 0;
        Data->MyInfo_Idx = 0;
        Data->MyInfo_Stat = 0;
    }

    /* Initilize Data Structure all values to 0 */
    memset(Data->reserved, 0, sizeof(Data->reserved));

    Data->CRC_MSB = 0;
    Data->CRC_LSB = 0;

}


/*******************************************************************************
 * @brief   Initialize Scuba Mode Settings Global Structure
 ******************************************************************************/

void SCUBA_Set_Init( Scuba_Settings_t *Data )
{
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        /* Initilize Data Structure all values to 0 */
        memset(Data, 0, sizeof(Scuba_Settings_t));
    }    

    Data->DivingAlgo = NVD_DVS_DSAT;
    Data->TotalActiveGases = 1;           // one gase is selected
    Data->CurrGasNumber = 1;              // starts from Tank-#1
    Data->TankActive.Tank1 = true;        // Tank1 is selected
    Data->TankActive.Tank2 = false;        // Tank2 is selected
    Data->TankActive.Tank3 = false;        // Tank3 is selected
    Data->TankActive.Tank4 = false;        // Tank4 is selected
    Data->TankActive.Tank5 = false;        // Tank5 is selected
    Data->TankActive.Tank6 = false;        // Tank6 is selected
    Data->GasActive.Gas1 =  true;         // Gas-1 is selected
    Data->GasActive.Gas2 =  false;         // Gas-2 is selected
    Data->GasActive.Gas3 =  false;         // Gas-3 is selected
    Data->GasActive.Gas4 =  false;         // Gas-4 is selected
    Data->GasActive.Gas5 =  false;         // Gas-5 is selected
    Data->GasActive.Gas6 =  false;         // Gas-6 is selected
    Data->Consv.ConservMode = CONSV_TEC;
    Data->Consv.ConservSportMode = CONSV_SPORT_HIGH;
    Data->GF_Low = 35;
    Data->GF_High = 80;
    Data->TEC_GF_Lo = 35;    
    Data->TEC_GF_Hi = 80;
	

    Data->SafetyStopMode = NVD_ON;
    Data->SafetyStopMin = 3;
    Data->SS_DepthFt = 15;                 /* 1-Byte 8-bit Safety stop in ft       0: 10Ft,  1: 15Ft,    2: 20Ft         */
    Data->SS_DepthM = 5;                   /* 1-Byte 8-bit Safety stop in meter    0: 3Mt,  1: 4Mt,   2: 5Mt,  3: 6Mt    */
    Data->DepthAlarmFT = 150;              /* 2-Byte Depth Alarm at 100 feet */
    Data->DepthAlarmM = 50;                /* 2-Byte Depth Alarm at 30 meters */     
    //-------------------------------------------

    Data->AlarmSet.AllBits = 0;   // 0x00000000;
    Data->Alarm2Set.AllBits = 0; /* 4-Byte Alarm Set */
    Data->Alarm2Set.Bit.EndP = true;    // only EndP is turned ON
    Data->Alarm2Set.Bit.TankP = true;   // only TankP is turned ON
    Data->Alarm2Set.Bit.CC6P = true;    // only CC6P is turned ON
    
    Data->TLBG_Alarm = 5;         /* 1-Byte Tissue Loading Alarm Level */
    Data->ASCBG_Alarm = 5;        /* 1-Byte ASC BG Alarm Level */
    Data->DTR_Alarm = 5;          /* 1-Byte Dive Time Remaining Level */
    Data->EDT_Alarm = 100;        /* 1-Byte Dive Time Level */          

    Data->TTS_min = 30;
    Data->GF_Alarm = 80;          /* GF Alarm  = 80% */
    Data->N2_Alarm = 70;          /* GF Alarm  = 70% */
    
    Data->LastStopFt = 10;        /* 1-Byte Last Stop Ft */
    Data->LastStopM = 3;          /* 1-Byte Last Stop M */
    
    //Data->SwitchSet.AllSwitches = 0x00000000;
    //-------------------------------------------
    Data->PO2A[0] = 160;
    Data->PO2A[1] = 160;
    Data->PO2A[2] = 160;
    Data->PO2A[3] = 160;
    Data->PO2A[4] = 160;
    Data->PO2A[5] = 160;
    Data->PO2A[6] = 160;
    Data->Reserved27 = 0;
    Data->FO2A[0] = 21;
    Data->FO2A[1] = 21;
    Data->FO2A[2] = 18;
    Data->FO2A[3] = 25;
    Data->FO2A[4] = 32;
    Data->FO2A[5] = 50;
    Data->FO2A[6] = 100;
    Data->Reserved2F = 0;
    //-------------------------------------------

    Data->FHeA[0] = 0;
    Data->FHeA[1] = 0;
    Data->FHeA[2] = 30;
    Data->FHeA[3] = 35;
    Data->FHeA[4] = 0;
    Data->FHeA[5] = 0;
    Data->FHeA[6] = 0;
    Data->Reserved37 = 0;
    // FN2 = 100 - (FO2 + FHe)
    for(uint8_t i=0; i<7; i++)
        Data->FN2A[i] = 100 - (Data->PO2A[i] + Data->FHeA[i]);

    Data->Reserved3F = 0;
    //-------------------------------------------

    Data->SP_Current =  70;             // set as Customer SP = 0.70 
    Data->SP_SetHigh  = 130;  	        // 1.30        
    Data->SP_SetLow   = 70;		// 0.70
    Data->SP_Switch   = LOW_SP;         // Set for LOW SP as default
    Data->SP_CustomSW = NVD_OFF;        // Custom SP set OFF and SP = 0.70 
    Data->SP_SetCustomer = 100;    
    
    Data->SP_AutoHighM =  20;           // set SP AutoHigh 20 M
    Data->SP_AutoLowM =   10;           //     SP AutoLow 10 M
    Data->SP_AutoHighFT = 60;           // set SP AutoHigh 60 ft
    Data->SP_AutoLowFT =  30;           //     SP AutoLow 30 ft

    Data->OCmin       = 20;	//0.20
    Data->OCmax       = 140;	//1.4
    Data->OCdeco      = 161;	//1.61
    Data->BOmin       = 20;	//0.20
    Data->BOmax       = 140;	//1.4
    Data->BOdeco      = 161;	//1.61
    Data->CONS = 0;
    //-------------------------------------------    
    
    Data->TankPressBAR = 50;    /* 2-Byte TankP_BAR */
    Data->TankPressPSI = 800;   /* 2-Byte TankP_PSI */
    Data->CC6PressBAR = 50;     /* 2-Byte CC6P_BAR */
    Data->CC6PressPSI = 800;    /* 2-Byte CC6P_PSI */
    Data->TurnPressBAR = 105;
    Data->TurnPressPSI = 1500;
    Data->EndPressBAR = 50;
    Data->EndPressPSI = 800;
    //-------------------------------------------

    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        Data->TMTID[0] = 0;
        Data->TMTID[1] = 0;
        Data->TMTID[2] = 0;
        Data->TMTID[3] = 0;
        Data->TMTID[4] = 0;
        Data->TMTID[5] = 0;
        Data->TMTID[6] = 0;
        
        Data->TMT_On.TMT1 = 1;
        Data->TMT_On.TMT2 = 1;
        Data->TMT_On.TMT3 = 0;
        Data->TMT_On.TMT4 = 0;
        Data->TMT_On.TMT5 = 0;
        Data->TMT_On.TMT6 = 0;
        Data->Reserved8D = 0;
        Data->Reserved8E = 0;
    }    
    
    Data->GASTMT[0] = TMT_OFF;
    Data->GASTMT[1] = TMT_OFF;
    Data->GASTMT[2] = TMT_OFF;
    Data->GASTMT[3] = TMT_OFF;
    Data->GASTMT[4] = TMT_OFF;
    Data->GASTMT[5] = TMT_OFF;
    Data->GASTMT[6] = TMT_OFF;

    Data->Reserved97 = 0;
    
    for(uint8_t i=0; i<7; i++)
        Data->MOD[i] = 223;
    
    Data->Reserved9F = 0;
    
    Data->Wob_AL_Ft = 100;      /* 2-Byte WOB AL in Ft */ 
    Data->Wob_AL_dM = 300;      /* 2-Byte WOB AL in dM */ 
    Data->End_AL_Ft = 100;      /* 2-Byte End AL in Ft */  
    Data->End_AL_dM = 300;      /* 2-Byte End AL in dM */   

    Data->SwitchP_PSI = 400;    /* 2-Byte SwitchP_PSI */ 
    Data->SwitchP_BAR = 30;     /* 2-Byte SwitchP_BAR */  
    Data->ReservedBC = 0;       /* 2-Byte Reserved */ 
    Data->ReservedBE = 0;       /* 2-Byte Reserved */

    Data->FreeDiveEDT_S = 30;
    Data->FreeDiveAlarm1_Ft = 330;
    Data->FreeDiveAlarm2_Ft = 330;
    Data->FreeDiveAlarm3_Ft = 330;
    Data->FreeDiveAlarm1_M = 100;
    Data->FreeDiveAlarm2_M = 100;
    Data->FreeDiveAlarm3_M = 100;

    Data->CountDownSec = 0;

    Data->CRC_MSB = 0;
    Data->CRC_LSB = 0;
}


/*******************************************************************************
 * @brief   Initialize Scuba Mode Data Global Structure
 ******************************************************************************/

void TRIMIX_Set_Init( TRIMIX_Settings_t *Data )
{
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        /* Initilize Data Structure all values to 0 */
        memset(Data, 0, sizeof(TRIMIX_Settings_t));
    }

    Data->CC_Select.Tank1 = true;       // Tank1 is selected
    Data->CC_Select.Tank2 = false;      // Tank2 is not selected
    Data->CC_Select.Tank3 = false;      // Tank3 is not selected
    Data->CC_Select.Tank4 = false;      // Tank4 is not selected
    Data->CC_Select.Tank5 = false;      // Tank5 is not selected
    Data->CC_Select.Tank6 = false;      // Tank6 is not selected
	
    Data->CC_Active.Gas1 =  true;       // Gas-1 is selected
    Data->CC_Active.Gas2 =  false;       // Gas-2 is selected
    Data->CC_Active.Gas3 =  false;       // Gas-3 is selected
    Data->CC_Active.Gas4 =  false;       // Gas-4 is selected
    Data->CC_Active.Gas5 =  false;       // Gas-5 is selected
    Data->CC_Active.Gas6 =  false;       // Gas-6 is selected
    
    Data->CC_GASTMT[0] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[1] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[2] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[3] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[4] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[5] = (TMT_NUM_t)TMT_OFF;
    Data->CC_GASTMT[6] = (TMT_NUM_t)TMT_OFF;
    
    Data->CC_PO2A[0] = 140;
    Data->CC_PO2A[1] = 140;
    Data->CC_PO2A[2] = 140;
    Data->CC_PO2A[3] = 140;
    Data->CC_PO2A[4] = 140;
    Data->CC_PO2A[5] = 140;
    Data->CC_PO2A[6] = 140;
    
    Data->CC_FO2[0] = 21;
    Data->CC_FO2[1] = 21;
    Data->CC_FO2[2] = 18;
    Data->CC_FO2[3] = 25;
    Data->CC_FO2[4] = 32;
    Data->CC_FO2[5] = 50;
    Data->CC_FO2[6] = 100;
    
    Data->CC_FHe[0] = 0;
    Data->CC_FHe[1] = 0;
    Data->CC_FHe[2] = 30;
    Data->CC_FHe[3] = 35;
    Data->CC_FHe[4] = 0;
    Data->CC_FHe[5] = 0;
    Data->CC_FHe[6] = 0;

    Data->OC_Select.Tank1 = true;       // Tank1 is selected
    Data->OC_Select.Tank2 = false;      // Tank2 is not selected
    Data->OC_Select.Tank3 = false;      // Tank3 is not selected
    Data->OC_Select.Tank4 = false;      // Tank4 is not selected
    Data->OC_Select.Tank5 = false;      // Tank5 is not selected
    Data->OC_Select.Tank6 = false;      // Tank6 is not selected
    Data->OC_Active.Gas1 =  true;       // Gas-1 is selected
    Data->OC_Active.Gas2 =  false;       // Gas-2 is selected
    Data->OC_Active.Gas3 =  false;       // Gas-3 is selected
    Data->OC_Active.Gas4 =  false;       // Gas-4 is selected
    Data->OC_Active.Gas5 =  false;       // Gas-5 is selected
    Data->OC_Active.Gas6 =  false;       // Gas-6 is selected

    Data->OC_GASTMT[0] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[1] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[2] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[3] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[4] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[5] = (TMT_NUM_t)TMT_OFF;
    Data->OC_GASTMT[6] = (TMT_NUM_t)TMT_OFF;
    
    Data->OC_PO2A[0] = 140;
    Data->OC_PO2A[1] = 140;
    Data->OC_PO2A[2] = 140;
    Data->OC_PO2A[3] = 140;
    Data->OC_PO2A[4] = 140;
    Data->OC_PO2A[5] = 140;
    Data->OC_PO2A[6] = 140;
    
    Data->OC_FO2[0] = 21;
    Data->OC_FO2[1] = 21;
    Data->OC_FO2[2] = 18;
    Data->OC_FO2[3] = 25;
    Data->OC_FO2[4] = 32;
    Data->OC_FO2[5] = 50;
    Data->OC_FO2[6] = 100;
    
    Data->OC_FHe[0] = 0;
    Data->OC_FHe[1] = 0;
    Data->OC_FHe[2] = 30;
    Data->OC_FHe[3] = 35;
    Data->OC_FHe[4] = 0;
    Data->OC_FHe[5] = 0;
    Data->OC_FHe[6] = 0;
    
    Data->SM_Select.Tank1 = true;       // Tank1 is selected
    Data->SM_Select.Tank2 = true;      // Tank2 is not selected
    Data->SM_Select.Tank3 = false;      // Tank3 is not selected
    Data->SM_Select.Tank4 = false;      // Tank4 is not selected
    Data->SM_Select.Tank5 = false;      // Tank5 is not selected
    Data->SM_Select.Tank6 = false;      // Tank6 is not selected
    Data->SM_Active.Gas1 =  true;       // Gas-1 is selected
    Data->SM_Active.Gas2 =  true;       // Gas-2 is selected
    Data->SM_Active.Gas3 =  false;       // Gas-3 is selected
    Data->SM_Active.Gas4 =  false;       // Gas-4 is selected
    Data->SM_Active.Gas5 =  false;       // Gas-5 is selected
    Data->SM_Active.Gas6 =  false;       // Gas-6 is selected

    Data->SM_GASTMT[0] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[1] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[2] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[3] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[4] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[5] = (TMT_NUM_t)TMT_OFF;
    Data->SM_GASTMT[6] = (TMT_NUM_t)TMT_OFF;
    
    Data->SM_PO2A[0] = 140;
    Data->SM_PO2A[1] = 140;
    Data->SM_PO2A[2] = 140;
    Data->SM_PO2A[3] = 140;
    Data->SM_PO2A[4] = 140;
    Data->SM_PO2A[5] = 140;
    Data->SM_PO2A[6] = 140;
    
    Data->SM_FO2[0] = 21;
    Data->SM_FO2[1] = 21;
    Data->SM_FO2[2] = 21;
    Data->SM_FO2[3] = 25;
    Data->SM_FO2[4] = 32;
    Data->SM_FO2[5] = 50;
    Data->SM_FO2[6] = 80;

    Data->SM_FHe[0] = 0;
    Data->SM_FHe[1] = 0;
    Data->SM_FHe[2] = 0;
    Data->SM_FHe[3] = 35;
    Data->SM_FHe[4] = 0;
    Data->SM_FHe[5] = 0;
    Data->SM_FHe[6] = 0;

    Data->BO_Select.Tank1 = true;       // Tank1 is selected
    Data->BO_Select.Tank2 = false;      // Tank2 is not selected
    Data->BO_Select.Tank3 = false;      // Tank3 is not selected
    Data->BO_Select.Tank4 = false;      // Tank4 is not selected
    Data->BO_Select.Tank5 = false;      // Tank5 is not selected
    Data->BO_Select.Tank6 = false;      // Tank6 is not selected
    Data->BO_Active.Gas1 =  true;       // Gas-1 is selected
    Data->BO_Active.Gas2 =  false;       // Gas-2 is selected
    Data->BO_Active.Gas3 =  false;       // Gas-3 is selected
    Data->BO_Active.Gas4 =  false;       // Gas-4 is selected
    Data->BO_Active.Gas5 =  false;       // Gas-5 is selected
    Data->BO_Active.Gas6 =  false;       // Gas-6 is selected

    Data->BO_GASTMT[0] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[1] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[2] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[3] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[4] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[5] = (TMT_NUM_t)TMT_OFF;
    Data->BO_GASTMT[6] = (TMT_NUM_t)TMT_OFF;
    
    Data->BO_PO2A[0] = 140;
    Data->BO_PO2A[1] = 140;
    Data->BO_PO2A[2] = 140;
    Data->BO_PO2A[3] = 140;
    Data->BO_PO2A[4] = 140;
    Data->BO_PO2A[5] = 140;
    Data->BO_PO2A[6] = 140;
    
    Data->BO_FO2[0] = 21;
    Data->BO_FO2[1] = 21;
    Data->BO_FO2[2] = 18;
    Data->BO_FO2[3] = 25;
    Data->BO_FO2[4] = 32;
    Data->BO_FO2[5] = 50;
    Data->BO_FO2[6] = 100;
    
    Data->BO_FHe[0] = 0;
    Data->BO_FHe[1] = 0;
    Data->BO_FHe[2] = 30;
    Data->BO_FHe[3] = 35;
    Data->BO_FHe[4] = 0;
    Data->BO_FHe[5] = 0;
    Data->BO_FHe[6] = 0;
    
    Data->CurrGasNumber_CC = TANK_1;
    Data->CurrGasNumber_OC = TANK_1;
    Data->CurrGasNumber_SM = TANK_1;
    Data->CurrGasNumber_BO = TANK_1;
    Data->CurrTMT_Number_GSM = TMT_1;
    Data->CurrTMT_Number_GAUGE = TMT_1;
    
    Data->CC_Active.Allbits = 0x01;
    Data->OC_Active.Allbits = 0x01;
    Data->SM_Active.Allbits = 0x03;
    Data->GSM_TMT_Active.Allbits = 0x03;
    Data->GAUGE_TMT_Active.Allbits = 0x01;
    Data->BO_Active.Allbits = 0x01;
}




/*******************************************************************************
 * @brief   Initialize Scuba Mode Data Global Structure
 ******************************************************************************/

void FLASH_Map_Init( FLASH_Map_t *Data )
{
    if( CheckBrandNewEE() || ToManualResetEE() )
    {
        /* Initilize Data Structure all values to 0 */
        memset(Data, 0, sizeof(FLASH_Map_t));
    
        Data->BootloaderHeadAddr = EXFLASH_BOOTREC;
        Data->BootloaderTailAddr = EXFLASH_BOOTREC + 0x7FFF;
        Data->FirmwareHeadAddr =   EXFLASH_FIRMWARE;
        Data->FirmwareTailAddr =   EXFLASH_FIRMWARE+0x7FFFF;
           
        Data->GPS_HeadAddr =       EXFLASH_GPS;
        Data->GPS_TailAddr =       EXFLASH_GPS+0xFFF;
        Data->GPS_FirstPointAddr = EXFLASH_GPS+0xFFF;
        Data->GPS_LastPointAddr =  EXFLASH_GPS+0xFFF;

        Data->MyInfoHeadAddr = EXFLASH_MYINFO;
        Data->MyInfoTailAddr = EXFLASH_MYINFO+0xFF;

        Data->NormLogHeadAddr =      EXFLASH_LOG;
        Data->NormLogTailAddr =      EXFLASH_LOG_END;
        Data->NormLogFirstDiveAddr = EXFLASH_LOG_END;
        Data->NormLogNextDiveAddr =  EXFLASH_LOG_END;

        Data->ProfileHeadAddr =      EXFLASH_PROFILE;
        Data->ProfileTailAddr =      EXFLASH_PROFILE_END;
        Data->ProfileLastDiveHeadAddr = EXFLASH_PROFILE_END;
        Data->ProfileLastDiveEndAddr =  EXFLASH_PROFILE_END;    
    }
}


/*******************************************************************************
 * @brief   Initialize Free Mode Settings Global Structure
 ******************************************************************************/

void FREE_Set_Init( Free_Settings_t *Data )
{
    /* Initilize Data Structure all values to 0 */
    memset(Data, 0, sizeof(Free_Settings_t));

}


void FREE_Rec_Init( Free_Records_t *Data )
{
    /* Initilize Data Structure all values to 0 */
    memset(Data, 0, sizeof(Free_Records_t));

}

/*******************************************************************************
 * @brief   Initialize Algorithm rentined Data Structs
 ******************************************************************************/

void RetData_Init( void )
{
    /* Initilize Data Structure all values to 0 */
    memset(&RETA_Data0, 0, sizeof(RETA_Data0));
    memset(&RETA_Data1, 0, sizeof(RETA_Data1));
    memset(&RETA_Data2, 0, sizeof(RETA_Data2));
    memset(&RETA_Data3, 0, sizeof(RETA_Data3));
    memset(&RETA_Data4, 0, sizeof(RETA_Data4));
    memset(&RETA_Data5, 0, sizeof(RETA_Data5));
    memset(&RETA_Data6, 0, sizeof(RETA_Data6));
    memset(&RETA_Data7, 0, sizeof(RETA_Data7));
    
    memset(&RETB_Data0, 0, sizeof(RETB_Data0));
    memset(&RETB_Data1, 0, sizeof(RETB_Data1));
    memset(&RETB_Data2, 0, sizeof(RETB_Data2));
    memset(&RETB_Data3, 0, sizeof(RETB_Data3));
    memset(&RETB_Data4, 0, sizeof(RETB_Data4));
    memset(&RETB_Data5, 0, sizeof(RETB_Data5));
    memset(&RETB_Data6, 0, sizeof(RETB_Data6));
    memset(&RETB_Data7, 0, sizeof(RETB_Data7));
}

void NVD_RAMTOTAL_to_ExtEEPROM (void)
{
  //NVD_RAMBLOCK_to_ExtEEPROM(EE_MFGCAL);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_USERSET);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_SCUBASET);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_TRIMIXSET);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_FREESET);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_FLASHMAP);

  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA0);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA1);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA2);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA3);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA4);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA5);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA6);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA7);
  
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA0);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA1);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA2);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA3);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA4);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA5);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA6);
  NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA7);
}

void NVD_RAM_TOTAL_EE_SaveReq (void)
{
  //EE_SaveReq(EE_MFGCAL);
  EE_SaveReq(EE_DEVREC);
  EE_SaveReq(EE_USERSET);
  EE_SaveReq(EE_SCUBASET);
  EE_SaveReq(EE_TRIMIXSET);
  EE_SaveReq(EE_FREESET);
  EE_SaveReq(EE_FLASHMAP);

  EE_SaveReq(EE_RETA_DATA0);
  EE_SaveReq(EE_RETA_DATA1);
  EE_SaveReq(EE_RETA_DATA2);
  EE_SaveReq(EE_RETA_DATA3);
  EE_SaveReq(EE_RETA_DATA4);
  EE_SaveReq(EE_RETA_DATA5);
  EE_SaveReq(EE_RETA_DATA6);
  EE_SaveReq(EE_RETA_DATA7);
  
  EE_SaveReq(EE_RETB_DATA0);
  EE_SaveReq(EE_RETB_DATA1);
  EE_SaveReq(EE_RETB_DATA2);
  EE_SaveReq(EE_RETB_DATA3);
  EE_SaveReq(EE_RETB_DATA4);
  EE_SaveReq(EE_RETB_DATA5);
  EE_SaveReq(EE_RETB_DATA6);
  EE_SaveReq(EE_RETB_DATA7);
}

void NVD_EE_StressTestReq (void)
{
  //EE_SaveReq(EE_MFGCAL);
  EE_SaveReq(EE_DEVREC);
  EE_SaveReq(EE_USERSET);
  EE_SaveReq(EE_SCUBASET);
  EE_SaveReq(EE_TRIMIXSET);
  EE_SaveReq(EE_FLASHMAP);
}
/*******************************************************************************

    NVD_RAMBLOCK_to_ExtEEPROM( ) function is to handle each EE Block (256 Bytes)

    output 0: OK (CRC Correct); 1: No Good (CRC Error)

*******************************************************************************/
bool NVD_RAMBLOCK_to_ExtEEPROM (uint16_t block)
{
  uint16_t new_crc;
  bool status = true;   // set default as 1 (true):  EEPROM Com Error to start with
  int32_t retry;
  
  switch(block)
  {
      case EE_MFGCAL:
        
        // Calculate CRC of the RAM block
        new_crc = Eval_CRC16(&MFG_Calib, sizeof(MFG_Calib)-2);
        MFG_Calib.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        MFG_Calib.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_MFGCAL_LOC1, &MFG_Calib, sizeof(MFG_Calib)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes(NVD_MFGCAL_LOC1, &EE_Block1, sizeof(MFG_Calib)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &MFG_Calib, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good 
        break;
      
      case EE_DEVREC:
        {
          Device_Records_t DEV_Rec_tmp;

          /* Update Device Parameter MonotonicClock and PST time */
          DEV_Rec.MonoClockSec = MonotonicClock_s;
          memcpy(&DEV_Rec.RTC_PST, &SysTimeDatePST, sizeof(SystemTimeDate_t));

          /* Some variables of Device Parametetrs are updated in interrupt routines so we need to work on a copy */
          memcpy(&DEV_Rec_tmp, &DEV_Rec, sizeof(DEV_Rec_tmp));
            
          new_crc = Eval_CRC16(&DEV_Rec_tmp, sizeof(DEV_Rec_tmp)-2);
          DEV_Rec_tmp.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
          DEV_Rec_tmp.CRC_LSB = (uint8_t)(new_crc&0x00FF);
          retry = NVD_EEPROM_WRITE_TIMEOUT;
          do{}while( !EE24CWxxX_WriteNBytes( NVD_DEVREC_LOC1, &DEV_Rec_tmp, sizeof(DEV_Rec_tmp)) && (retry-- >0) );	// modified from R1006
          /*
          if(retry <= 0)
          {
            ErrHandle_EE();
            return true;
          }
          ms_delay(2);    // keep a time gap between Write and Read
          retry = NVD_EEPROM_READ_TIMEOUT;
          do{}while( !EE24CWxxX_ReadNBytes(NVD_DEVREC_LOC1, &EE_Block1, sizeof(DEV_Rec_tmp)) && (retry-- >0) );	        // modified from R1006
          if(retry <= 0)
          {
            ErrHandle_EE();
            return true;
          }
          status = CompEE256( &DEV_Rec_tmp, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
          */
          status = 0;   // Write Only, Bypass self-check of DEV_Rec
        }
        break;
      
      case EE_USERSET:

        new_crc = Eval_CRC16(&USER_Set, sizeof(USER_Set)-2);
        USER_Set.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        USER_Set.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_USERSET_LOC1, &USER_Set, sizeof(USER_Set)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_USERSET_LOC1, &EE_Block1, sizeof(USER_Set)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &USER_Set, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_SCUBASET:

        new_crc = Eval_CRC16(&SCUBA_Set, sizeof(SCUBA_Set)-2);
        SCUBA_Set.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        SCUBA_Set.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_SCUBASET_LOC1, &SCUBA_Set, sizeof(SCUBA_Set)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_SCUBASET_LOC1, &EE_Block1, sizeof(SCUBA_Set)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &SCUBA_Set, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good 
        break;
        
      case EE_TRIMIXSET:

        new_crc = Eval_CRC16(&TRIMIX_Set, sizeof(TRIMIX_Set)-2);
        TRIMIX_Set.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        TRIMIX_Set.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_TRIMIXSET_LOC1, &TRIMIX_Set, sizeof(TRIMIX_Set)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_TRIMIXSET_LOC1, &EE_Block1, sizeof(TRIMIX_Set)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &TRIMIX_Set, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_FLASHMAP:

        new_crc = Eval_CRC16(&FLASH_Map, sizeof(FLASH_Map)-2);
        FLASH_Map.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        FLASH_Map.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_FLASHMAP_LOC1, &FLASH_Map, sizeof(FLASH_Map)) && (retry-- >0) );		// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_FLASHMAP_LOC1, &EE_Block1, sizeof(FLASH_Map)) && (retry-- >0) );	        // modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &FLASH_Map, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
        
      case EE_RETA_DATA0:

        new_crc = Eval_CRC16(&RETA_Data0, sizeof(RETA_Data0)-2);
        RETA_Data0.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data0.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA0_LOC, &RETA_Data0, sizeof(RETA_Data0)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA0_LOC, &EE_Block1, sizeof(RETA_Data0)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data0, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETA_DATA1:

        new_crc = Eval_CRC16(&RETA_Data1, sizeof(RETA_Data1)-2);
        RETA_Data1.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data1.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA1_LOC, &RETA_Data1, sizeof(RETA_Data1)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA1_LOC, &EE_Block1, sizeof(RETA_Data1)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data1, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETA_DATA2:

        new_crc = Eval_CRC16(&RETA_Data2, sizeof(RETA_Data2)-2);
        RETA_Data2.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data2.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA2_LOC, &RETA_Data2, sizeof(RETA_Data2)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA2_LOC, &EE_Block1, sizeof(RETA_Data2)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data2, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETA_DATA3:

        new_crc = Eval_CRC16(&RETA_Data3, sizeof(RETA_Data3)-2);
        RETA_Data3.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data3.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA3_LOC, &RETA_Data3, sizeof(RETA_Data3)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA3_LOC, &EE_Block1, sizeof(RETA_Data3)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data3, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
         
      case EE_RETA_DATA4:

        new_crc = Eval_CRC16(&RETA_Data4, sizeof(RETA_Data4)-2);
        RETA_Data4.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data4.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA4_LOC, &RETA_Data4, sizeof(RETA_Data4)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA4_LOC, &EE_Block1, sizeof(RETA_Data4)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data4, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
       
      case EE_RETA_DATA5:

        new_crc = Eval_CRC16(&RETA_Data5, sizeof(RETA_Data5)-2);
        RETA_Data5.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data5.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA5_LOC, &RETA_Data5, sizeof(RETA_Data5)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA5_LOC, &EE_Block1, sizeof(RETA_Data5)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data5, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETA_DATA6:

        new_crc = Eval_CRC16(&RETA_Data6, sizeof(RETA_Data6)-2);
        RETA_Data6.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data6.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA6_LOC, &RETA_Data6, sizeof(RETA_Data6)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA6_LOC, &EE_Block1, sizeof(RETA_Data6)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data6, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETA_DATA7:

        new_crc = Eval_CRC16(&RETA_Data7, sizeof(RETA_Data7)-2);
        RETA_Data7.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETA_Data7.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA7_LOC, &RETA_Data7, sizeof(RETA_Data7)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA7_LOC, &EE_Block1, sizeof(RETA_Data7)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETA_Data7, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
      
      case EE_RETB_DATA0:

        new_crc = Eval_CRC16(&RETB_Data0, sizeof(RETB_Data0)-2);
        RETB_Data0.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data0.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA0_LOC, &RETB_Data0, sizeof(RETB_Data0)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA0_LOC, &EE_Block1, sizeof(RETB_Data0)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data0, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA1:

        new_crc = Eval_CRC16(&RETB_Data1, sizeof(RETB_Data1)-2);
        RETB_Data1.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data1.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA1_LOC, &RETB_Data1, sizeof(RETB_Data1)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA1_LOC, &EE_Block1, sizeof(RETB_Data1)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data1, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA2:

        new_crc = Eval_CRC16(&RETB_Data2, sizeof(RETB_Data2)-2);
        RETB_Data2.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data2.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA2_LOC, &RETB_Data2, sizeof(RETB_Data2)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA2_LOC, &EE_Block1, sizeof(RETB_Data2)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data2, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA3:

        new_crc = Eval_CRC16(&RETB_Data3, sizeof(RETB_Data3)-2);
        RETB_Data3.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data3.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA3_LOC, &RETB_Data3, sizeof(RETB_Data3)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA3_LOC, &EE_Block1, sizeof(RETB_Data3)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data3, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA4:

        new_crc = Eval_CRC16(&RETB_Data4, sizeof(RETB_Data4)-2);
        RETB_Data4.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data4.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA4_LOC, &RETB_Data4, sizeof(RETB_Data4)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA4_LOC, &EE_Block1, sizeof(RETB_Data4)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data4, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA5:

        new_crc = Eval_CRC16(&RETB_Data5, sizeof(RETB_Data5)-2);
        RETB_Data5.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data5.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA5_LOC, &RETB_Data5, sizeof(RETB_Data5)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA5_LOC, &EE_Block1, sizeof(RETB_Data5)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data5, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA6:

        new_crc = Eval_CRC16(&RETB_Data6, sizeof(RETB_Data6)-2);
        RETB_Data6.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data6.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA6_LOC, &RETB_Data6, sizeof(RETB_Data6)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA6_LOC, &EE_Block1, sizeof(RETB_Data6)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data6, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      case EE_RETB_DATA7:

        new_crc = Eval_CRC16(&RETB_Data7, sizeof(RETB_Data7)-2);
        RETB_Data7.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
        RETB_Data7.CRC_LSB = (uint8_t)(new_crc&0x00FF);
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA7_LOC, &RETB_Data7, sizeof(RETB_Data7)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        } 
        ms_delay(2);    // keep a time gap between Write and Read
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA7_LOC, &EE_Block1, sizeof(RETB_Data7)) && (retry-- >0) );	// modified from R1006
        if(retry <= 0)
        {
          ErrHandle_EE();
          return true;
        }
        status = CompEE256( &RETB_Data7, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good
        break;
        
      default:
        status = true;         // something is wrong, not supposed to be here, added from R1006
        break;
        
  }
  
  if(status == true)
      status = true;
  else
      status = false;
  
  return status;        // 0 (or false): OK;      1 (or true):  EEPROM Com Error
}



/*******************************************************************************
 * @brief   Request to Save all or partial NVD Data in RAM to ExtEEPROM
 ******************************************************************************/
void EE_SaveReq (uint8_t blk)
{
    switch(blk)
    {
        case EE_MFGCAL:
            SystemStatus.NVD_EE_W_flag0 |= EE_MFGCAL_bit;
            break;
        case EE_DEVREC:
            SystemStatus.NVD_EE_W_flag0 |= EE_DEVREC_bit;
            break;
        case EE_USERSET:
            SystemStatus.NVD_EE_W_flag0 |= EE_USERSET_bit;
            break;
        case EE_SCUBASET:
            SystemStatus.NVD_EE_W_flag0 |= EE_SCUBASET_bit;
            break;
        case EE_TRIMIXSET:
            SystemStatus.NVD_EE_W_flag0 |= EE_TRIMIXSET_bit;
            break;            
        case EE_FLASHMAP:
            SystemStatus.NVD_EE_W_flag0 |= EE_FLASHMAP_bit;
            break;
            
        case EE_RETA_DATA0:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA0_bit;
            break;
        case EE_RETA_DATA1:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA1_bit;
            break;
        case EE_RETA_DATA2:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA2_bit;
            break;
        case EE_RETA_DATA3:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA3_bit;
            break;
        case EE_RETA_DATA4:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA4_bit;
            break;
        case EE_RETA_DATA5:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA5_bit;
            break;
        case EE_RETA_DATA6:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA6_bit;
            break;
        case EE_RETA_DATA7:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETA7_bit;
            break;
            
        case EE_RETB_DATA0:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB0_bit;
            break;
        case EE_RETB_DATA1:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB1_bit;
            break;
        case EE_RETB_DATA2:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB2_bit;
            break;
        case EE_RETB_DATA3:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB3_bit;
            break;
        case EE_RETB_DATA4:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB4_bit;
            break;
        case EE_RETB_DATA5:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB5_bit;
            break;
        case EE_RETB_DATA6:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB6_bit;
            break;
        case EE_RETB_DATA7:
            SystemStatus.NVD_EE_W_flag0 |= EE_RETB7_bit;
            break;
    }
}


/*******************************************************************************
 * @brief   Delayed Process for flagged NVD Data in RAM to ExtEEPROM in Tick-0
 *
 *      MAX_EE_BLOCK_WRITE_CNT_PER_TICK limit is added in R1006
 *      to limit the Max EE block writings within each Tick time (125 mS)
 *
 ******************************************************************************/
uint32_t NVD_Process_RAMBLOCK_to_ExtEEPROM (uint32_t flag)
{
  #define MAX_EE_BLOCK_WRITE_CNT_PER_TICK        1
  
  uint8_t EE_WR_ToRunCnt = MAX_EE_BLOCK_WRITE_CNT_PER_TICK;
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_MFGCAL_bit)==EE_MFGCAL_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_MFGCAL))
      flag &= ~EE_MFGCAL_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_DEVREC_bit)==EE_DEVREC_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC))
      flag &= ~EE_DEVREC_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_USERSET_bit)==EE_USERSET_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_USERSET))
      flag &= ~EE_USERSET_bit;
    
    EE_WR_ToRunCnt--;
  }

  if((EE_WR_ToRunCnt > 0)&&((flag & EE_SCUBASET_bit)==EE_SCUBASET_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_SCUBASET))
      flag &= ~EE_SCUBASET_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_TRIMIXSET_bit)==EE_TRIMIXSET_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_TRIMIXSET))
      flag &= ~EE_TRIMIXSET_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_FLASHMAP_bit)==EE_FLASHMAP_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_FLASHMAP))
      flag &= ~EE_FLASHMAP_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA0_bit)==EE_RETA0_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA0))
      flag &= ~EE_RETA0_bit;
    
    EE_WR_ToRunCnt--;
  }

  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA1_bit)==EE_RETA1_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA1))
      flag &= ~EE_RETA1_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA2_bit)==EE_RETA2_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA2))
      flag &= ~EE_RETA2_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA3_bit)==EE_RETA3_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA3))
      flag &= ~EE_RETA3_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA4_bit)==EE_RETA4_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA4))
      flag &= ~EE_RETA4_bit;
    
    EE_WR_ToRunCnt--;
  }

  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA5_bit)==EE_RETA5_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA5))
      flag &= ~EE_RETA5_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA6_bit)==EE_RETA6_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA6))
      flag &= ~EE_RETA6_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETA7_bit)==EE_RETA7_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETA_DATA7))
      flag &= ~EE_RETA7_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB0_bit)==EE_RETB0_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA0))
      flag &= ~EE_RETB0_bit;
    
    EE_WR_ToRunCnt--;
  }

  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB1_bit)==EE_RETB1_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA1))
      flag &= ~EE_RETB1_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB2_bit)==EE_RETB2_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA2))
      flag &= ~EE_RETB2_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB3_bit)==EE_RETB3_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA3))
      flag &= ~EE_RETB3_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB4_bit)==EE_RETB4_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA4))
      flag &= ~EE_RETB4_bit;
    
    EE_WR_ToRunCnt--;
  }

  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB5_bit)==EE_RETB5_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA5))
      flag &= ~EE_RETB5_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB6_bit)==EE_RETB6_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA6))
      flag &= ~EE_RETB6_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  if((EE_WR_ToRunCnt > 0)&&((flag & EE_RETB7_bit)==EE_RETB7_bit))
  {
    if(!NVD_RAMBLOCK_to_ExtEEPROM(EE_RETB_DATA7))
      flag &= ~EE_RETB7_bit;
    
    EE_WR_ToRunCnt--;
  }
  
  return flag;
}


/*******************************************************************************
 * @brief   Store all NVD Data in RAM to ExtEEPROM
 ******************************************************************************/
bool NVD_DataRetention_RAM_to_ExtEEPROM (void)
{ 
  static uint8_t Block2Update = 0;
  static uint8_t RetendCopy = RET_A;    // RetendCopy = 1 for CopyA, 2 for CopyB, alternate in every retention save cycle
  uint8_t UpdatedBlocks = 0;
  uint8_t CheckedBlocks = 0;
  bool UpdateLoop = true;
  bool status = 0;                      // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good                      
  uint16_t new_crc;
  int8_t retry = NVD_EEPROM_READ_TIMEOUT;
  
  while (UpdateLoop)
  {
    switch (Block2Update)
    {
      case 0:       
        
          // Now This case become initial Data Buffers Stuffing by SaveRetendedData before Saving them into EEPROM
          if(Dive_Info.Status==AMB_DIVEINFO_SURF)       // only do 
          {  
            if(RetendCopy == RET_A)
              SaveRetendedData(RET_A);  // only needs one of these two functoin every time             
            else
              SaveRetendedData(RET_B);           
          }
  
          CheckedBlocks++;
          Block2Update++;
        
        break;
      
      case 1:
        {
          Device_Records_t DEV_Rec_tmp;
          retry = NVD_EEPROM_READ_TIMEOUT;
          do{}while( !EE24CWxxX_ReadNBytes( NVD_DEVREC_LOC1, &DEV_Rec_tmp, sizeof(DEV_Rec_tmp) ) && (retry-- > 0));		// modified from R1006
          if(retry <= 0)
          {
            ErrHandle_EE();
            return true;                // to break the total cycle due to EE Com Error
          } 
          
          if(memcmp(&DEV_Rec_tmp, &DEV_Rec, sizeof(DEV_Rec_tmp)) != 0)
          {
            /* Update Device Parameter MonotonicClock and PST time */
            DEV_Rec.MonoClockSec = MonotonicClock_s;
            memcpy(&DEV_Rec.RTC_PST, &SysTimeDatePST, sizeof(SystemTimeDate_t));

            /* Some variables of Device Parametetrs are updated in interrupt routines so we need to work on a copy */
            memcpy(&DEV_Rec_tmp, &DEV_Rec, sizeof(DEV_Rec_tmp));
            
            new_crc = Eval_CRC16(&DEV_Rec_tmp, sizeof(DEV_Rec_tmp)-2);
            DEV_Rec_tmp.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
            DEV_Rec_tmp.CRC_LSB = (uint8_t)(new_crc&0x00FF);

            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_WriteNBytes( NVD_DEVREC_LOC1, &DEV_Rec_tmp, sizeof(DEV_Rec_tmp) ) && (retry-- > 0));	// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
            ms_delay(2);    // keep a time gap between Write and Read
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_DEVREC_LOC1, &EE_Block1, sizeof(DEV_Rec_tmp)) && (retry-- >0) );	// modified from R1006            
            status = CompEE256( &DEV_Rec_tmp, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
            if((retry <= 0) || status )
            {
              // ErrHandle_EE();          // don't do ErrHandle_EE for DEV_Rec, because of redundancy
              return true;                // to break the total cycle due to EE Com Error
            }
            UpdatedBlocks++;
          }
          
          CheckedBlocks++;
          Block2Update++;
        }
        break;
      
      case 2:        
          // Do Nothing
          CheckedBlocks++;
          Block2Update++;
        
        break;
        
      case 3: 
          // Do Nothing
          CheckedBlocks++;
          Block2Update++;
        
        break;
        
      case 4:
          // Do Nothing  
          CheckedBlocks++;
          Block2Update++;
        
        break;
        
        
      case 5:
          // Do Nothing        
          CheckedBlocks++;
          Block2Update++;
        
        break;
        
      case 6:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data0_t RETA_Data0_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA0_LOC, &RETA_Data0_tmp, sizeof(RETA_Data0_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            }
            
            if(memcmp(&RETA_Data0_tmp, &RETA_Data0, sizeof(RETA_Data0)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data0, sizeof(RETA_Data0)-2);
              RETA_Data0.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data0.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA0_LOC, &RETA_Data0, sizeof(RETA_Data0) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA0_LOC, &EE_Block1, sizeof(RETA_Data0)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data0, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;

      case 7:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data1_t RETA_Data1_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA1_LOC, &RETA_Data1_tmp, sizeof(RETA_Data1_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data1_tmp, &RETA_Data1, sizeof(RETA_Data1)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data1, sizeof(RETA_Data1)-2);
              RETA_Data1.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data1.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA1_LOC, &RETA_Data1, sizeof(RETA_Data1))  && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA1_LOC, &EE_Block1, sizeof(RETA_Data1)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data1, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 8:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data2_t RETA_Data2_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA2_LOC, &RETA_Data2_tmp, sizeof(RETA_Data2_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data2_tmp, &RETA_Data2, sizeof(RETA_Data2)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data2, sizeof(RETA_Data2)-2);
              RETA_Data2.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data2.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA2_LOC, &RETA_Data2, sizeof(RETA_Data2) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA2_LOC, &EE_Block1, sizeof(RETA_Data2)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data2, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 9:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data3_t RETA_Data3_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA3_LOC, &RETA_Data3_tmp, sizeof(RETA_Data3_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data3_tmp, &RETA_Data3, sizeof(RETA_Data3)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data3, sizeof(RETA_Data3)-2);
              RETA_Data3.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data3.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA3_LOC, &RETA_Data3, sizeof(RETA_Data3) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA3_LOC, &EE_Block1, sizeof(RETA_Data3)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data3, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 10:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data4_t RETA_Data4_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA4_LOC, &RETA_Data4_tmp, sizeof(RETA_Data4_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data4_tmp, &RETA_Data4, sizeof(RETA_Data4)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data4, sizeof(RETA_Data4)-2);
              RETA_Data4.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data4.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA4_LOC, &RETA_Data4, sizeof(RETA_Data4) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA4_LOC, &EE_Block1, sizeof(RETA_Data4)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data4, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 11:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data5_t RETA_Data5_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA5_LOC, &RETA_Data5_tmp, sizeof(RETA_Data5_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data5_tmp, &RETA_Data5, sizeof(RETA_Data5)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data5, sizeof(RETA_Data5)-2);
              RETA_Data5.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data5.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA5_LOC, &RETA_Data5, sizeof(RETA_Data5) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA5_LOC, &EE_Block1, sizeof(RETA_Data5)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data5, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 12:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data6_t RETA_Data6_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA6_LOC, &RETA_Data6_tmp, sizeof(RETA_Data6_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data6_tmp, &RETA_Data6, sizeof(RETA_Data6)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data6, sizeof(RETA_Data6)-2);
              RETA_Data6.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data6.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA6_LOC, &RETA_Data6, sizeof(RETA_Data6) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA6_LOC, &EE_Block1, sizeof(RETA_Data6)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data6, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 13:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_A)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data7_t RETA_Data7_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA7_LOC, &RETA_Data7_tmp, sizeof(RETA_Data7_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETA_Data7_tmp, &RETA_Data7, sizeof(RETA_Data7)) != 0)
            {
              new_crc = Eval_CRC16(&RETA_Data7, sizeof(RETA_Data7)-2);
              RETA_Data7.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETA_Data7.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETA_DATA7_LOC, &RETA_Data7, sizeof(RETA_Data7) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA7_LOC, &EE_Block1, sizeof(RETA_Data7)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETA_Data7, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 14:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data0_t RETB_Data0_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA0_LOC, &RETB_Data0_tmp, sizeof(RETB_Data0_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data0_tmp, &RETB_Data0, sizeof(RETB_Data0)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data0, sizeof(RETB_Data0)-2);
              RETB_Data0.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data0.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA0_LOC, &RETB_Data0, sizeof(RETB_Data0) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA0_LOC, &EE_Block1, sizeof(RETB_Data0)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data0, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 15:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data1_t RETB_Data1_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA1_LOC, &RETB_Data1_tmp, sizeof(RETB_Data1_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data1_tmp, &RETB_Data1, sizeof(RETB_Data1)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data1, sizeof(RETB_Data1)-2);
              RETB_Data1.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data1.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA1_LOC, &RETB_Data1, sizeof(RETB_Data1) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA1_LOC, &EE_Block1, sizeof(RETB_Data1)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data1, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 16:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data2_t RETB_Data2_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA2_LOC, &RETB_Data2_tmp, sizeof(RETB_Data2_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data2_tmp, &RETB_Data2, sizeof(RETB_Data2)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data2, sizeof(RETB_Data2)-2);
              RETB_Data2.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data2.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA2_LOC, &RETB_Data2, sizeof(RETB_Data2) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA2_LOC, &EE_Block1, sizeof(RETB_Data2)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data2, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 17:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data3_t RETB_Data3_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA3_LOC, &RETB_Data3_tmp, sizeof(RETB_Data3_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data3_tmp, &RETB_Data3, sizeof(RETB_Data3)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data3, sizeof(RETB_Data3)-2);
              RETB_Data3.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data3.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA3_LOC, &RETB_Data3, sizeof(RETB_Data3) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA3_LOC, &EE_Block1, sizeof(RETB_Data3)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data3, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 18:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data4_t RETB_Data4_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA4_LOC, &RETB_Data4_tmp, sizeof(RETB_Data4_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data4_tmp, &RETB_Data4, sizeof(RETB_Data4)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data4, sizeof(RETB_Data4)-2);
              RETB_Data4.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data4.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA4_LOC, &RETB_Data4, sizeof(RETB_Data4) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA4_LOC, &EE_Block1, sizeof(RETB_Data4)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data4, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 19:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data5_t RETB_Data5_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA5_LOC, &RETB_Data5_tmp, sizeof(RETB_Data5_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data5_tmp, &RETB_Data5, sizeof(RETB_Data5)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data5, sizeof(RETB_Data5)-2);
              RETB_Data5.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data5.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA5_LOC, &RETB_Data5, sizeof(RETB_Data5) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA5_LOC, &EE_Block1, sizeof(RETB_Data5)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data5, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 20:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data6_t RETB_Data6_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA6_LOC, &RETB_Data6_tmp, sizeof(RETB_Data6_tmp) ) && (retry-- > 0));		// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data6_tmp, &RETB_Data6, sizeof(RETB_Data6)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data6, sizeof(RETB_Data6)-2);
              RETB_Data6.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data6.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA6_LOC, &RETB_Data6, sizeof(RETB_Data6) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA6_LOC, &EE_Block1, sizeof(RETB_Data6)) && (retry-- >0) );	// modified from R1006
              status = CompEE256( &RETB_Data6, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }
          Block2Update++;        
        break;
        
      case 21:
          if((Dive_Info.Status==AMB_DIVEINFO_SURF)
             &&NewDiveProfileAndLogRecorded()
             &&(RetendCopy==RET_B)) // Only do data retention in Surface Mode, once every NVD_RAM_TO_EEPROM_PERIOD_S
          {
            RET_Data7_t RETB_Data7_tmp;
            retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA7_LOC, &RETB_Data7_tmp, sizeof(RETB_Data7_tmp) ) && (retry-- > 0));	// modified from R1006
            if(retry <= 0)
            {
              ErrHandle_EE();
              return true;                // to break the total cycle due to EE Com Error
            } 
          
            if(memcmp(&RETB_Data7_tmp, &RETB_Data7, sizeof(RETB_Data7)) != 0)
            {
              new_crc = Eval_CRC16(&RETB_Data7, sizeof(RETB_Data7)-2);
              RETB_Data7.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
              RETB_Data7.CRC_LSB = (uint8_t)(new_crc&0x00FF);

              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_WriteNBytes( NVD_EE_RETB_DATA7_LOC, &RETB_Data7, sizeof(RETB_Data7) ) && (retry-- > 0));		// modified from R1006
              if(retry <= 0)
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              } 
              ms_delay(2);    // keep a time gap between Write and Read
              retry = NVD_EEPROM_READ_TIMEOUT;
              do{}while( !EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA7_LOC, &EE_Block1, sizeof(RETB_Data7)) && (retry-- >0) );	        // modified from R1006
              status = CompEE256( &RETB_Data7, &EE_Block1 );   // Comparison old RAM with the new readback from EEPROM, 0: CRC Correct; 1: CRC No Good            
              if((retry <= 0) || status )
              {
                ErrHandle_EE();
                return true;                // to break the total cycle due to EE Com Error
              }
              UpdatedBlocks++;
            }
            CheckedBlocks++;
          }          
          Block2Update++;        
        break;
        
      default:
        break;
    }
    
    uint32_t RoutineTime = (uint32_t)UpdatedBlocks*35UL + (uint32_t)CheckedBlocks*4UL;
    if( (RoutineTime > 50) || (Block2Update > BLOCKS_2_UPDATE) )
      UpdateLoop = false;
  }
  
  if(Block2Update > BLOCKS_2_UPDATE)
  {
    Block2Update = 0;
    
    if(RetendCopy==RET_A)
      RetendCopy=RET_B;
    else
      RetendCopy=RET_A;
    
    return true;                // Completed the total cycle, wait for anohter 2 minutes
  }
  else
    return false;
}


/*******************************************************************************
 * @brief   UseRETAorB, to find which one is the newer copy RET_A or RET_B
            based on the time they were being recorded
 ******************************************************************************/
uint8_t UseRETAorB(void)
{
  uint32_t TimeA, TimeB;
  //uint16_t CrcA, CrcB;          // to do next
  
  TimeA = 86400*RETA_Data1.PST.Day + 3600*RETA_Data1.PST.Hour + 60*RETA_Data1.PST.Minute + RETA_Data1.PST.Second;
  TimeB = 86400*RETB_Data1.PST.Day + 3600*RETB_Data1.PST.Hour + 60*RETB_Data1.PST.Minute + RETB_Data1.PST.Second;
  
  if(TimeA == TimeB)    // considered NEW EEPROM      
    return RET_NEW_DAY;  // return 0
  else if(TimeA > TimeB)
    return RET_A;       // copy A is newer (later time)
  else
    return RET_B;       // copy B is newer (later time)
}

/*******************************************************************************
 * @brief   Retreive NVD data on ExtEEPROM and copy to RAM
 ******************************************************************************/
bool NVD_ExtEEPROM_to_RAM (void)
{
  Device_Records_t DEV_Rec_tmp;
  
  int8_t retry = NVD_EEPROM_TO_RAM_RETRY;
  int8_t CommandRetry;
  bool CrcWrong = true;

  do
  {
    retry--;

    /* Read Back NVD data from EEPROM to check integrity */
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_MFGCAL_LOC1, &MFG_Calib, sizeof(MFG_Calib) ) && (CommandRetry-- > 0) );		// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_DEVREC_LOC1, &DEV_Rec_tmp, sizeof(DEV_Rec_tmp) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_USERSET_LOC1, &USER_Set, sizeof(USER_Set) ) && (CommandRetry-- > 0) );			// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_SCUBASET_LOC1, &SCUBA_Set, sizeof(SCUBA_Set) ) && (CommandRetry-- > 0) );		// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_TRIMIXSET_LOC1, &TRIMIX_Set, sizeof(TRIMIX_Set) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_FLASHMAP_LOC1, &FLASH_Map, sizeof(FLASH_Map) ) && (CommandRetry-- > 0) );		// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA0_LOC, &RETA_Data0, sizeof(RETA_Data0) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA1_LOC, &RETA_Data1, sizeof(RETA_Data1) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA2_LOC, &RETA_Data2, sizeof(RETA_Data2) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA3_LOC, &RETA_Data3, sizeof(RETA_Data3) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA4_LOC, &RETA_Data4, sizeof(RETA_Data4) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA5_LOC, &RETA_Data5, sizeof(RETA_Data5) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA6_LOC, &RETA_Data6, sizeof(RETA_Data6) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETA_DATA7_LOC, &RETA_Data7, sizeof(RETA_Data7) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA0_LOC, &RETB_Data0, sizeof(RETB_Data0) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA1_LOC, &RETB_Data1, sizeof(RETB_Data1) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA2_LOC, &RETB_Data2, sizeof(RETB_Data2) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA3_LOC, &RETB_Data3, sizeof(RETB_Data3) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA4_LOC, &RETB_Data4, sizeof(RETB_Data4) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA5_LOC, &RETB_Data5, sizeof(RETB_Data5) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA6_LOC, &RETB_Data6, sizeof(RETB_Data6) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }
    
    CommandRetry = NVD_EEPROM_READ_TIMEOUT;
    do{}while(!EE24CWxxX_ReadNBytes( NVD_EE_RETB_DATA7_LOC, &RETB_Data7, sizeof(RETB_Data7) ) && (CommandRetry-- > 0) );	// modified from R1006
    if(CommandRetry <= 0)
    {
      ErrHandle_EE();
      return false;
    }    

    uint16_t a = Eval_CRC16(&DEV_Rec_tmp, sizeof(DEV_Rec_tmp));
    
    if( (Eval_CRC16(&MFG_Calib, sizeof(MFG_Calib)) == 0)        &&
        //(Eval_CRC16(&DEV_Rec_tmp, sizeof(DEV_Rec_tmp)) == 0)    &&
        (Eval_CRC16(&USER_Set, sizeof(USER_Set)) == 0)          &&
        (Eval_CRC16(&SCUBA_Set, sizeof(SCUBA_Set)) == 0)        &&
        (Eval_CRC16(&TRIMIX_Set, sizeof(TRIMIX_Set)) == 0)      &&  
        (Eval_CRC16(&FLASH_Map, sizeof(FLASH_Map)) == 0)        &&
          
        (Eval_CRC16(&RETA_Data0, sizeof(RETA_Data0)) == 0)        &&
        (Eval_CRC16(&RETA_Data1, sizeof(RETA_Data1)) == 0)        &&
        (Eval_CRC16(&RETA_Data2, sizeof(RETA_Data2)) == 0)        &&
        (Eval_CRC16(&RETA_Data3, sizeof(RETA_Data3)) == 0)        &&
        (Eval_CRC16(&RETA_Data4, sizeof(RETA_Data4)) == 0)        &&
        (Eval_CRC16(&RETA_Data5, sizeof(RETA_Data5)) == 0)        &&
        (Eval_CRC16(&RETA_Data6, sizeof(RETA_Data6)) == 0)        &&
        (Eval_CRC16(&RETA_Data7, sizeof(RETA_Data7)) == 0)        &&
          
        (Eval_CRC16(&RETB_Data0, sizeof(RETB_Data0)) == 0)        &&
        (Eval_CRC16(&RETB_Data1, sizeof(RETB_Data1)) == 0)        &&
        (Eval_CRC16(&RETB_Data2, sizeof(RETB_Data2)) == 0)        &&
        (Eval_CRC16(&RETB_Data3, sizeof(RETB_Data3)) == 0)        &&
        (Eval_CRC16(&RETB_Data4, sizeof(RETB_Data4)) == 0)        &&
        (Eval_CRC16(&RETB_Data5, sizeof(RETB_Data5)) == 0)        &&
        (Eval_CRC16(&RETB_Data6, sizeof(RETB_Data6)) == 0)        &&
        (Eval_CRC16(&RETB_Data7, sizeof(RETB_Data7)) == 0)
       )
    {
      retry = 0;
      CrcWrong = false;
    }
    else
      CrcWrong = true;

        DIVEMODE_SET = DIVE_MODE;    // retrieve

  } while( retry > 0 );

  if(CrcWrong)
    return false;

  /* Some variables of Device Parametetrs are updated in interrupt routines so we need to work on a copy */
  memcpy(&DEV_Rec, &DEV_Rec_tmp, sizeof(DEV_Rec_tmp));

  return true;
}


/*******************************************************************************
 * @brief   CheckBrandNewEE is to detect brand new EE with 0xFF on first page
 ******************************************************************************/
bool CheckBrandNewEE (void)
{
    if( ( (FLASH_Map.ProfileHeadAddr == 0xFFFFFFFF)&&(FLASH_Map.ProfileTailAddr == 0xFFFFFFFF)&&(FLASH_Map.ProfileLastDiveHeadAddr == 0xFFFFFFFF)&&(FLASH_Map.ProfileLastDiveEndAddr == 0xFFFFFFFF) )
      ||( (MFG_Calib.CRC_LSB == 0xFF)&&(MFG_Calib.CRC_MSB == 0xFF) ) )
        return true;
    else
        return false;
}


/************************************************************************************************
 * @brief   ToManualResetEE is to detect if manual EE Reset is needed (by two buttons)
 ***********************************************************************************************/
bool ToManualResetEE (void)
{
    if( (HAL_GPIO_ReadPin(BUTTON_TL_PORT, BUTTON_TL_PIN) == 0) && (HAL_GPIO_ReadPin(BUTTON_BL_PORT, BUTTON_BL_PIN) == 0) )
        return true;
    else
        return false;
}


/*******************************************************************************
 * @brief   Collect all variables to update the LOG Data
 ******************************************************************************/

void LOG_Data_Update(void)
{
    uint8_t i;    

    DEV_Rec.LogNumDisp = 0;       // point to the latest dive, after every new dive 
    
    Log_Data.LogNum = DEV_Rec.LogNumRecorded;       // synced up with LogNormNumRecorded in SaveLog( )
    Log_Data.DiveNum = DEV_Rec.DiveNumOfDay;            // reset to 1 for every NEW DAY
    
    // Log_Data.EntryHr ~ Log_Data.EntryYear recorded at Entry Time when Phantom Dive was ruled out
    
    Log_Data.ProfileHeadAddr = DEV_Rec.AddrNewProfileHead;
    Log_Data.ProfileTailAddr = DEV_Rec.AddrNewProfileEnd;
    
    Log_Data.MaxDepthFt10 = (uint16_t)(Dive_Info.MaxWaterDepth_ft*10);    // Max Depth (ft) recording to LOG
    Log_Data.AvgDepthFt10 = (uint16_t)(Dive_Info.AvgWaterDepth_ft*10);    // Avg Depth (ft) recording to LOG
    Log_Data.EDTsec = Dive_Info.DiveTime_s;                               // Total Dive-T (sec) recording to LOG
    if(CC_MODE)
        Log_Data.MaxPO2 = (uint16_t)(100.0*(CC_MaxPO2_SetofDive + 0.000001));
    else
        Log_Data.MaxPO2 = (uint16_t)(100.0*PO2MAXatDepth);
    
    // Log_Data.SurfInvT_Hr ~ Log_Data.SurfInvT_Min recorded at After Dive Time
    // Log_Data.ExitMin ~ Log_Data.ExitHr recorded at After Dive Time
    
    Log_Data.MinTempF10 = (int16_t)(Dive_Info.MinTemp_F*10);              // Min Temp (F) recording to LOG
    Log_Data.MaxTempF10 = (int16_t)(Dive_Info.MaxTemp_F*10);              // Max Temp (F) recording to LOG
    
    Log_Data.ModesConsv = (uint8_t)GFmaxValue;                            // Max GF recording to LOG
    Log_Data.SeaLevel = Dive_Info.AltitudeLevel;
    Log_Data.EndTLBG = TLBGVal_Log;                                       // End TLBG recording to LOG
    Log_Data.MaxASCBG = MaxASCBGVal;                                      // Max ASCBG recording to LOG

    Log_Data.GasNum = FindGasNumOfDiveMode(DIVE_MODE);                    // End Tank Gas Number
    Log_Data.MaxTLBG = MaxTLBGVal;                                        // Max TLBG recording to LOG
    Log_Data.O2Sat = (uint8_t) MaxOTUpercent; //DSATtime;                 // Max O2Sat recording to LOG
    
    if(CC_MODE)
      Log_Data.FO2 = TRIMIX_Set.CC_FO2[CURRENT_TANK_NUM];                 // End Tank FO2 setup
    else if(OC_MODE)
      Log_Data.FO2 = TRIMIX_Set.OC_FO2[CURRENT_TANK_NUM];                 // End Tank FO2 setup
    else if(SM_MODE)
      Log_Data.FO2 = TRIMIX_Set.SM_FO2[CURRENT_TANK_NUM];                 // End Tank FO2 setup
    else if(BO_MODE)
      Log_Data.FO2 = TRIMIX_Set.BO_FO2[CURRENT_TANK_NUM];                 // End Tank FO2 setup
    else
      Log_Data.FO2 = 0;                                                   // End Tank FO2 N/A
    
    Log_Data.CC_HiPO2 = SCUBA_Set.SP_SetHigh;
    Log_Data.CC_LoPO2 = SCUBA_Set.SP_SetLow;
    Log_Data.CC_MaxGF = (uint8_t)GFmaxValue;
    Log_Data.TLBG_Threshold = SCUBA_Set.N2_Alarm;
    Log_Data.AlarmOccured  = AlarmOccured;              // Byte-56,57,58,59
    Log_Data.AlarmOccured2 = AlarmOccured2;             // Byte-60,61,62,63
    Log_Data.SwitchSet.AllBits = Profile_Header.SwitchSet.AllBits;
    for(i=0;i<=TOTAL_TANK_NUM;i++)
    {        
        Log_Data.CC_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.CC_GASTMT[i];

        Log_Data.CC_FHe[i] = TRIMIX_Set.CC_FHe[i];

        Log_Data.OC_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.OC_GASTMT[i];

        Log_Data.OC_FHe[i] = TRIMIX_Set.OC_FHe[i];

        Log_Data.SM_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.SM_GASTMT[i];

        Log_Data.SM_FHe[i] = TRIMIX_Set.SM_FHe[i];          
    }
    
    for(i=0;i<16;i++)
        Log_Data.TLBGS[i] = TLBG_ARRAY[17-i];
    
    Log_Data.CC_Select = TRIMIX_Set.CC_Select;
    Log_Data.OC_Select = TRIMIX_Set.OC_Select;
    Log_Data.SM_Select = TRIMIX_Set.SM_Select;        
    Log_Data.TMT_On_Bits.Allbits = SCUBA_Set.TMT_On.Allbits;
}


/*******************************************************************************
 * @brief   Collect all variables to update the LOG Data
 ******************************************************************************/
void LOG_Data_Retrieve(uint16_t n)
{
    uint8_t *pLog;
    int8_t retry;
    
    pLog = (uint8_t*) &Log_Data;

    /*********** Must do this every time before FLASH Erase/Read/Write  ***********/
    L4X9_QSPI_Init();

    MT25QL512ABB_PowerDownRelease();
    /******************************************************************************/

    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O((EXFLASH_LOG+LOG_SIZE*(n-1)), LOG_SIZE, pLog)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
        
    /******** Must do this every time after FLASH Erase/Read/Write is done ********/
    MT25QL512ABB_PowerDownEnter();

    L4X9_QSPI_DeInit();
    /******************************************************************************/
}


/*******************************************************************************
 * @brief   Collect all variables to update the Profile Header, Data and Trailer
 ******************************************************************************/

void Profile_Data_Update(uint8_t n)
{
    uint8_t i = 0;
    
    switch(n)
    {
    case PROFILE_HEADER:
        Profile_Header.LogNum = DEV_Rec.LogNumRecorded;     // Byte-0:      Synced up with LogNormNumRecorded in SaveLog( )
        Profile_Header.DiveNum = DEV_Rec.DiveNumOfDay;          // Byte-1:      Dive Number (0 to 24 in i330R)
        Profile_Header.DiveType = USER_Set.DiveMode;            // Byte-2:      Dive Type =  CC, OC, SM, GSM, Gauge
        Profile_Header.EntryHr = Log_Data.EntryHr;              // Byte-3:      Hr 0 to 23
        Profile_Header.EntryMin = Log_Data.EntryMin;            // Byte-4:      Min 0 to 59
        Profile_Header.EntryDay = Log_Data.EntryDay;            // Byte-5:      Day 1 to 31
        Profile_Header.EntryMon = Log_Data.EntryMon;            // Byte-6:      Month 1 to 12
        Profile_Header.EntryYear = Log_Data.EntryYear;          // Byte-7:      Year 0 to 255 (2000 to 2255)
        Profile_Header.StartGasNum = FindGasNumOfDiveMode(DIVE_MODE);   // Byte-8:      Start Gas (Tank) Num and Gas # the Dive
        Profile_Header.SeaLevel = Log_Data.SeaLevel;            // Byte-9:      Sea Level 0 to 7
        Profile_Header.SurfInvT_Hr = Log_Data.SurfInvT_Hr;      // Byte-10:     Surf Interval Time Hour 0 to 255
        Profile_Header.SurfInvT_Min = Log_Data.SurfInvT_Min;    // Byte-11:     Surf Interval Time Min 0 to 59
        Profile_Header.SwitchSet.AllBits = USER_Set.SwitchSet.AllBits;   // Byte-12,13,14,15: Switch On/Off

        if(CC_MODE||BO_MODE)
        {
            // Byte-16 to Byte-21:
            Profile_Header.FO21=TRIMIX_Set.CC_FO2[1];   /* 1-Byte x 6   Fractional of O2 */
            Profile_Header.FO22=TRIMIX_Set.CC_FO2[2];
            Profile_Header.FO23=TRIMIX_Set.CC_FO2[3];
            Profile_Header.FO24=TRIMIX_Set.CC_FO2[4];
            Profile_Header.FO25=TRIMIX_Set.CC_FO2[5];
            Profile_Header.FO26=TRIMIX_Set.CC_FO2[6];
            // Byte-22 to Byte-27:
            Profile_Header.PO21=TRIMIX_Set.CC_PO2A[1];   /* 1-Byte x 6   Pressure of O2 */
            Profile_Header.PO22=TRIMIX_Set.CC_PO2A[2];
            Profile_Header.PO23=TRIMIX_Set.CC_PO2A[3];
            Profile_Header.PO24=TRIMIX_Set.CC_PO2A[4];
            Profile_Header.PO25=TRIMIX_Set.CC_PO2A[5];
            Profile_Header.PO26=TRIMIX_Set.CC_PO2A[6];
        }
        else if(OC_MODE)
        {
            // Byte-16 to Byte-21:
            Profile_Header.FO21=TRIMIX_Set.OC_FO2[1];   /* 1-Byte x 6   Fractional of O2 */
            Profile_Header.FO22=TRIMIX_Set.OC_FO2[2];
            Profile_Header.FO23=TRIMIX_Set.OC_FO2[3];
            Profile_Header.FO24=TRIMIX_Set.OC_FO2[4];
            Profile_Header.FO25=TRIMIX_Set.OC_FO2[5];
            Profile_Header.FO26=TRIMIX_Set.OC_FO2[6];
            // Byte-22 to Byte-27:
            Profile_Header.PO21=TRIMIX_Set.OC_PO2A[1];   /* 1-Byte x 6   Pressure of O2 */
            Profile_Header.PO22=TRIMIX_Set.OC_PO2A[2];
            Profile_Header.PO23=TRIMIX_Set.OC_PO2A[3];
            Profile_Header.PO24=TRIMIX_Set.OC_PO2A[4];
            Profile_Header.PO25=TRIMIX_Set.OC_PO2A[5];
            Profile_Header.PO26=TRIMIX_Set.OC_PO2A[6];
        }
        else if(SM_MODE)
        {
            // Byte-16 to Byte-21:
            Profile_Header.FO21=TRIMIX_Set.SM_FO2[1];   /* 1-Byte x 6   Fractional of O2 */
            Profile_Header.FO22=TRIMIX_Set.SM_FO2[2];
            Profile_Header.FO23=TRIMIX_Set.SM_FO2[3];
            Profile_Header.FO24=TRIMIX_Set.SM_FO2[4];
            Profile_Header.FO25=TRIMIX_Set.SM_FO2[5];
            Profile_Header.FO26=TRIMIX_Set.SM_FO2[6];
            // Byte-22 to Byte-27:
            Profile_Header.PO21=TRIMIX_Set.SM_PO2A[1];   /* 1-Byte x 6   Pressure of O2 */
            Profile_Header.PO22=TRIMIX_Set.SM_PO2A[2];
            Profile_Header.PO23=TRIMIX_Set.SM_PO2A[3];
            Profile_Header.PO24=TRIMIX_Set.SM_PO2A[4];
            Profile_Header.PO25=TRIMIX_Set.SM_PO2A[5];
            Profile_Header.PO26=TRIMIX_Set.SM_PO2A[6];
        }
        
        Profile_Header.Reserved29 = 0;
        Profile_Header.Reserved30 = 0;
        Profile_Header.Reserved31 = 0;
         
        Profile_Header.TLBG_Alarm = SCUBA_Set.TLBG_Alarm;       /* 1-Byte Tissue Loading Alarm Level */
        Profile_Header.ASCBG_Alarm = SCUBA_Set.ASCBG_Alarm;     /* 1-Byte ASC BG Alarm Level */
        Profile_Header.DTR_Alarm = SCUBA_Set.DTR_Alarm;         /* 1-Byte Dive Time Remaining Level */
        Profile_Header.EDT_Alarm = SCUBA_Set.EDT_Alarm;         /* 1-Byte Dive Time Level */

        Profile_Header.SamplingTime = USER_Set.SamplingTime;            /* 1-Byte Profile Data Sampleing Rate in Seconds */
        Profile_Header.ConservDSAT = (NVD_conserv_t)SCUBA_Set.Consv.ConservMode;       /* 1 Byte Byte-18:      Dive Modes, Level of Consv., Violation flag    */
        Profile_Header.GF_Low = SCUBA_Set.GF_Low;                       /* 1-Byte 8-bit BUHLMANN Gradient Factor Low */
        Profile_Header.GF_High = SCUBA_Set.GF_High;                     /* 1-Byte 8-bit BUHLMANN Gradient Factor High */

        Profile_Header.SafetyStopMode = SCUBA_Set.SafetyStopMode;       /* 1-Byte 8-bit NVD_DVS_SS_OFF: disabled;
                                                                        NVD_DVS_SS_NORMAL: Standard SS behaviour, start countdown of SafetyStopMin at SafetyStopDepthXX
                                                                        NVD_DVS_SS_TIMER: Timer Mode */
        Profile_Header.SafetyStopMin = SCUBA_Set.SafetyStopMin;         /* 1-Byte 8-bit Time for safety stop in min @ safety stop depth (used in NON DECOMPRESSION ZONE). */
        Profile_Header.SS_DepthFt = SCUBA_Set.SS_DepthFt;               /* 1-Byte 8-bit Safety stop in ft       0: 10Ft,  1: 15Ft,    2: 20Ft         */
        Profile_Header.SS_DepthM = SCUBA_Set.SS_DepthM;                 /* 1-Byte 8-bit Safety stop in meter    0: 3Mt,  1: 4Mt,   2: 5Mt,  3: 6Mt    */

        Profile_Header.DepthAlarmFT = SCUBA_Set.DepthAlarmFT;           /* 2-Byte Depth Alarm in feet */
        Profile_Header.DepthAlarmM = SCUBA_Set.DepthAlarmM;             /* 2-Byte Depth Alarm in Meter */

        for(i=0; i<N2COMPNUM; i++)
            Profile_Header.TLBGS[i] = TLBG_ARRAY[i];                    // Byte-48 to 63: 
  
        Profile_Header.SP_Current       = SCUBA_Set.SP_Current;         /* 1-Byte SP Current Set Value (40 to 150) */
        Profile_Header.SP_SetLow        = SCUBA_Set.SP_SetLow;          /* 1-Byte SP Set Point Low (40 to 150) */
        Profile_Header.SP_SetHigh       = SCUBA_Set.SP_SetHigh;         /* 1-Byte SP Set Point High (40 to 150) */
        Profile_Header.SP_SetCustomer   = SCUBA_Set.SP_SetCustomer;     /* 1-Byte SP Set Point Customer (40 to 150) */
        Profile_Header.SP_Switch        = SCUBA_Set.SP_Switch;          /* 1-Byte SP Set Point Set Switches */
        Profile_Header.SP_CustomSW      = SCUBA_Set.SP_CustomSW;        /* 1-Byte Customer SP Set Switches */
          
        Profile_Header.SP_AutoHighM     = SCUBA_Set.SP_AutoHighM;       /* 1-Byte SP Auto Set Point High (6 to 130) */
        Profile_Header.SP_AutoLowM      = SCUBA_Set.SP_AutoLowM;        /* 1-Byte SP Auto Set Point High (2 to 130) */
        Profile_Header.SP_AutoHighFT    = SCUBA_Set.SP_AutoHighFT;      /* 2-Byte SP Auto Set Point High (20 to 420) */
        Profile_Header.SP_AutoLowFT     = SCUBA_Set.SP_AutoLowFT;       /* 2-Byte SP Auto Set Point High (10 to 420) */
        if(CC_MODE||BO_MODE)
        {
            Profile_Header.OCmin        = SCUBA_Set.BOmin;              /* 1-Byte BOmin */
            Profile_Header.OCmax        = SCUBA_Set.BOmax;              /* 1-Byte BOmax */
            Profile_Header.OCdeco       = SCUBA_Set.BOdeco;             /* 1-Byte BOdeco */
        }
        else
        {
            Profile_Header.OCmin        = SCUBA_Set.OCmin;              /* 1-Byte OCmin */
            Profile_Header.OCmax        = SCUBA_Set.OCmax;              /* 1-Byte OCmax */
            Profile_Header.OCdeco       = SCUBA_Set.OCdeco;             /* 1-Byte OCdeco */
        }
        Profile_Header.CONS             = SCUBA_Set.CONS;               /* 1-Byte CONS */

        Profile_Header.Wob_AL_Ft        = SCUBA_Set.Wob_AL_Ft;          /* 2-Byte WOB AL in Ft, Work of Breathing (WOB) */ 
        Profile_Header.Wob_AL_dM        = SCUBA_Set.Wob_AL_dM;          /* 2-Byte WOB AL in dM, Work of Breathing (WOB) */ 
        Profile_Header.End_AL_Ft        = SCUBA_Set.End_AL_Ft;          /* 2-Byte END AL in Ft, Equivalent Narcotic Depth (END) */
        Profile_Header.End_AL_dM        = SCUBA_Set.End_AL_dM;          /* 2-Byte End AL in dM, Equivalent Narcotic Depth (END) */   
        Profile_Header.SwitchP_PSI      = SCUBA_Set.SwitchP_PSI;        /* 2-Byte SwitchP_PSI */ 
        Profile_Header.SwitchP_BAR      = SCUBA_Set.SwitchP_BAR;        /* 2-Byte SwitchP_BAR */  
        Profile_Header.ReservedAC       = SCUBA_Set.ReservedAC;         /* 2-Byte Reserved */
        Profile_Header.ReservedAE       = SCUBA_Set.ReservedAE;         /* 2-Byte Reserved */
        
        Profile_Header.TankPressState   = SCUBA_Set.TankPressState;     /* 1-Byte Tank Pressure State */ 
        Profile_Header.TankPressBAR     = SCUBA_Set.TankPressBAR;       /* 1-Byte Tank Pressure in BAR */
        Profile_Header.TankPressPSI     = SCUBA_Set.TankPressPSI;       /* 2-Byte Tank Pressure in PSI */ 
        Profile_Header.CC6PressState    = SCUBA_Set.CC6PressState;      /* 1-Byte CC6 Pressure State */ 
        Profile_Header.CC6PressBAR      = SCUBA_Set.CC6PressBAR;        /* 1-Byte CC6 Pressure in BAR */
        Profile_Header.CC6PressPSI      = SCUBA_Set.CC6PressPSI;        /* 2-Byte CC6 Pressure in PSI */ 
          
        Profile_Header.TurnPressState   = SCUBA_Set.TurnPressState;     /* 1-Byte Turn Pressure State */ 
        Profile_Header.TurnPressBAR     = SCUBA_Set.TurnPressBAR;       /* 1-Byte Turn Pressure in BAR */
        Profile_Header.TurnPressPSI     = SCUBA_Set.TurnPressPSI;       /* 2-Byte Turn Pressure in PSI */  
        Profile_Header.EndPressState    = SCUBA_Set.EndPressState;      /* 1-Byte End Pressure State */ 
        Profile_Header.EndPressBAR      = SCUBA_Set.EndPressBAR;        /* 1-Byte End Pressure in BAR */
        Profile_Header.EndPressPSI      = SCUBA_Set.EndPressPSI;        /* 2-Byte End Pressure in PSI */ 
  
        Profile_Header.TEC_GF_Lo        = SCUBA_Set.TEC_GF_Lo;          /* 1-Byte TEC_GF_Lo */
        Profile_Header.TEC_GF_Hi        = SCUBA_Set.TEC_GF_Hi;          /* 1-Byte TEC_GF_Hi */
        Profile_Header.TTS_min          = SCUBA_Set.TTS_min;            /* 1-Byte Reserved */ 
        Profile_Header.Reserved67       = SCUBA_Set.Reserved67;         /* 1-Byte Reserved */
        Profile_Header.Reserved68       = SCUBA_Set.Reserved68;         /* 1-Byte Reserved */
        Profile_Header.GF_Alarm         = SCUBA_Set.GF_Alarm;           /* 1-Byte GF Value Alarm */
        Profile_Header.Reserved6A       = SCUBA_Set.Reserved6A;         /* 1-Byte Reserved */
        Profile_Header.N2_Alarm         = SCUBA_Set.N2_Alarm;           /* 1-Byte N2 Value Alarm */
        Profile_Header.Alarm2Set        = SCUBA_Set.Alarm2Set;          // Byte-72 to 75:  4-Byte Alarms and Warnings of the system and dive
        Profile_Header.AlarmSet         = SCUBA_Set.AlarmSet;           /* 4-Byte Alarm Set */
         
        for(i=0;i<=MAX_TOTAL_TANK_NUM;i++)
        {
            Profile_Header.CC_PO2A[i]   = TRIMIX_Set.CC_PO2A[i];          /* 1-Byte x 7   Pressure of O2 */
            Profile_Header.CC_FO2[i]    = TRIMIX_Set.CC_FO2[i];           /* 1-Byte x 7   Fractional of O2 */
            Profile_Header.OC_PO2A[i]   = TRIMIX_Set.OC_PO2A[i];          /* 1-Byte x 7   Pressure of O2 */
            Profile_Header.OC_FO2[i]    = TRIMIX_Set.OC_FO2[i];           /* 1-Byte x 7   Fractional of O2 */
            Profile_Header.SM_PO2A[i]   = TRIMIX_Set.SM_PO2A[i];          /* 1-Byte x 7   Pressure of O2 */
            Profile_Header.SM_FO2[i]    = TRIMIX_Set.SM_FO2[i];           /* 1-Byte x 7   Fractional of O2 */
            Profile_Header.CC_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.CC_GASTMT[i];        /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
            Profile_Header.CC_FHe[i]    = TRIMIX_Set.CC_FHe[i];           /* 1-Byte x 7   Fractional of He */
            Profile_Header.OC_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.OC_GASTMT[i];        /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
            Profile_Header.OC_FHe[i]    = TRIMIX_Set.OC_FHe[i];           /* 1-Byte x 7   Fractional of He */
            Profile_Header.SM_GASTMT[i] = (TANK_NUM_t)TRIMIX_Set.SM_GASTMT[i];        /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
            Profile_Header.SM_FHe[i]    = TRIMIX_Set.SM_FHe[i];           /* 1-Byte x 7   Fractional of He */
            Profile_Header.GSM_GASTMT[i]        = (TANK_NUM_t)TRIMIX_Set.GSM_GASTMT[i];       /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
            Profile_Header.GSM_FHe[i]           = TRIMIX_Set.GSM_FHe[i];          /* 1-Byte x 7   Fractional of He */
            Profile_Header.GAUGE_GASTMT[i]      = (TANK_NUM_t)TRIMIX_Set.GAUGE_GASTMT[i];     /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
            Profile_Header.GAUGE_FHe[i]         = TRIMIX_Set.GAUGE_FHe[i];        /* 1-Byte x 7   Fractional of He */        
        }  
        
        Profile_Header.CurrGasNumber_CC = (TANK_NUM_t)TRIMIX_Set.CurrGasNumber_CC;                     /* 1-Byte currently selected Gas number  1 to 6 */        
        Profile_Header.CC_Active        = TRIMIX_Set.CC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
        
        Profile_Header.CurrGasNumber_OC = (TANK_NUM_t)TRIMIX_Set.CurrGasNumber_OC;                     /* 1-Byte currently selected Gas number  1 to 6 */        
        Profile_Header.OC_Active        = TRIMIX_Set.OC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 

        Profile_Header.CurrGasNumber_SM = (TANK_NUM_t)TRIMIX_Set.CurrGasNumber_SM;                     /* 1-Byte currently selected Gas number  1 to 6 */          
        Profile_Header.SM_Active        = TRIMIX_Set.SM_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 
        
        Profile_Header.CC_Select        = TRIMIX_Set.CC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/          
        Profile_Header.ReservedBF       = TRIMIX_Set.Reserved5F; 

        Profile_Header.OC_Select        = TRIMIX_Set.OC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/          
        Profile_Header.ReservedCF       = TRIMIX_Set.Reserved6F; 

        Profile_Header.SM_Select        = TRIMIX_Set.SM_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/        
        Profile_Header.ReservedDF       = TRIMIX_Set.Reserved7F; 

        Profile_Header.GSM_Select       = TRIMIX_Set.GSM_Select;                        /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/        
        Profile_Header.ReservedEF       = TRIMIX_Set.Reserved8F; 
        
        Profile_Header.GAUGE_Select     = TRIMIX_Set.GAUGE_Select;                      /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
        Profile_Header.ReservedFF       = TRIMIX_Set.Reserved9F; 
        
        break;

    case PROFILE_DATA:

        Profile_Data.ModeGas.DiveMode = USER_Set.DiveMode;                      //OK Byte-0:   Dive Mode
        Profile_Data.ModeGas.GASn     = FindGasNumOfDiveMode(DIVE_MODE);        //OK Byte-0:   Current Gas Number
        Profile_Data.ASC_TMT.ASC = ASCBGVal;                                    //OK Byte-1:   ASCBGVal  
        Profile_Data.ASC_TMT.TMTn = (uint8_t)FindTMTofGAS();                    //OK Byte-1:      Current TMT Number
        Profile_Data.DepthFt10 = (uint16_t)(Dive_Info.WaterDepth_ft*10);        //OK Byte-2,3:
        Profile_Data.NoDecoTime = NDT_Data;                                     //OK Byte-4,5;
        Profile_Data.DecoTime = (uint16_t)Total_DST;                            //OK Byte-6,7;
        Profile_Data.DecoDepthFt = (uint16_t)DecoStop[1];                       //OK Byte-8,9;
        Profile_Data.TempF10 = (int16_t)(TP_Info.AverageTemperature_F*10);      //OK Byte-10,11: Temperature in F, 0 to 65535, offset to 0 to 122, we use -18 C to 50 C
        Profile_Data.PO2x100 = (uint16_t)(PO2atDepth*100);                      //OK Byte-12,13: PO2 x 100
        Profile_Data.TankPSI = GUI_TMT_PressPSI[(uint8_t)FindTMTofGAS()];       //OK Byte-14,15 PressPSI of Find_TMT_Num_InLinking;
        
        Profile_Data.O2Pct = OTUpercent;
        Profile_Data.TLBGBar = TLBGVal;
        Profile_Data.TLBGBits = TLBit();
        Profile_Data.GTR = ATR;
        Profile_Data.Tank6PSI = GUI_TMT_PressPSI[(uint8_t)TRIMIX_Set.CC_GASTMT[6]];     //OK Byte-14,15 PressPSI of Find_TMT_Num_InLinking;
        Profile_Data.Alarming.AllBits |= AlarmProfileRec.AllBits;               // Byte-24,25,26,27:  Alarms and Warnings of the system and dive 
        Profile_Data.Alarming2.AllBits |= AlarmProfileRec2.AllBits;             // Byte-28,29,30,31:  Alarms and Warnings of the system and dive  
        
        if(OTUpercent > MaxOTUpercent)
            MaxOTUpercent = OTUpercent;   // Record Max O2% throughout the dive.

        if(TLBGVal > MaxTLBGVal)
            MaxTLBGVal = TLBGVal;        // Record Max TLBG throughout the dive.

        AlarmProfileRec.AllBits=0;      // reset to zero, continue to collect current Alarm Stat from App.c
        AlarmProfileRec2.AllBits=0;      // reset to zero, continue to collect current Alarm Stat from App.c
        break;

    case PROFILE_TRAILER:

        //---------- The Data collected in Profile Trailer----------------------------
        Profile_Trailer.LogNum = DEV_Rec.LogNumRecorded+1;  // Byte-0:      Synced up with LogNormNumRecorded in SaveLog( )
        Profile_Trailer.DiveNum = DEV_Rec.DiveNumOfDay;         // Byte-1:      Dive Number (0 to 24 in i330R)
        Profile_Trailer.EndDiveType = USER_Set.DiveMode;           //OK Byte-2:    Dive Type =  CC, OC, SM, GSM, Gauge
        Profile_Trailer.GasUsed = Profile_Trailer.GasUsed;      // 1-Byte Byte-3        Gas Num and Gas # the Dive, starts recording at NewDiveInitialization( ) and Gas Switiching underwater
        Profile_Trailer.ExitHr = Log_Data.ExitHr;               // 1-Byte Byte-4:       The Hour of Exit Time
        Profile_Trailer.ExitMin = Log_Data.ExitMin;             // 1-Byte Byte-5:       The Min of Exit Time
        Profile_Trailer.MaxBG.ASCBG = MaxASCBGVal;              // 1-Byte Byte-6a:       MaxTLBG and MaxAscBG
        Profile_Trailer.MaxBG.TLBG = TLBGVal;                   // 1-Byte Byte-6b:       Current N2 BG
        Profile_Trailer.Reserved7 = 0;
        Profile_Trailer.EDTsec = (uint16_t)Dive_Info.DiveTime_s;                        // 4-Byte Byte-20,21:     Elapsed Dive Time in minutes
        Profile_Trailer.MaxDepthFt10 = (uint16_t)(Dive_Info.MaxWaterDepth_ft * 10);     // 2-Byte Byte-10,11:   Maximum Depth in feet
        Profile_Trailer.AvgDepthFt10=(uint16_t)(Dive_Info.AvgWaterDepth_ft * 10);       // 2-Byte Byte-12,13:   Byte, Avg Depth Ft 0 to 65535 feet
        Profile_Trailer.O2Sat = MaxOTUpercent;                             // 1 Byte Byte-14:      O2 Saturation Toxic
        
        Profile_Trailer.MinTempF10 = (int16_t)(Dive_Info.MinTemp_F *10);                // 2-Byte Byte-16:      Min Temperature in F
        Profile_Trailer.MaxTempF10 = (int16_t)(Dive_Info.MaxTemp_F *10);                // 2-Byte Byte-18:      Max Temperature in F
        Profile_Trailer.TotalDiveSec = Dive_Info.TotalDiveTime; // 2-Byte saving time for Dive times + After-Dive Surface times, including re-entry in the same dive
        if(CC_MODE)
        {
            if(PO2MAXatDepth > CC_MaxPO2_SetofDive)
                Profile_Trailer.MaxPO2x100 = (uint16_t)(100.0*PO2MAXatDepth);
            else
                Profile_Trailer.MaxPO2x100 = (uint16_t)(100.0*(CC_MaxPO2_SetofDive + 0.000001));       // 1-Byte Byte-22,23:       MaxPO2 x 100
        }
        else
            Profile_Trailer.MaxPO2x100 = (uint16_t)(100.0*PO2MAXatDepth);
        Profile_Trailer.Reserved18 = 0;                                                 // 4-Byte Byte-24,25,26,27:     
        Profile_Trailer.Reserved1C = 0;                                                 // 4-Byte Byte-28,29,30,31:
                
        Profile_Trailer.AlarmFinal.AllBits = AlarmProfileRec.AllBits;                   // 4-Byte Byte-32,33,34,35:  Enabled Alarms and Warnings of the system and dive
        Profile_Trailer.AlarmOccured.AllBits = Profile_Trailer.AlarmOccured.AllBits;    // 4-Byte Byte-36,37,38,39:  Occured Alarms and Warnings of the system and dive
        Profile_Trailer.AlarmFinal2.AllBits = AlarmProfileRec2.AllBits;                 // 4-Byte Byte-40,41,42,43:  Occured Alarms and Warnings of the system and dive
        Profile_Trailer.AlarmOccured2.AllBits = Profile_Trailer.AlarmOccured2.AllBits;  // 4-Byte Byte-44,45,46,47:  Reserved

        Profile_Trailer.Reserved30 = 0;                         // 4-Byte Byte-48,49,50,51:  Reserved
        Profile_Trailer.Reserved34 = 0;                         // 4-Byte Byte-52,53,54,55:  Reserved
        Profile_Trailer.Reserved38 = 0;                         // 4-Byte Byte-56,57,58,59:  Reserved
        Profile_Trailer.Reserved3C = 0x64636261;                // 4-Byte Byte-60,61,62,63:  Reserved
        break;
    }
}


void InitializePLAN(void)
{
    uint8_t i;

    FO2A[1] = SCUBA_Set.FO2A[1];       // unsigned char supposed to be in EEPROM
    FO2A[2] = SCUBA_Set.FO2A[2];       // unsigned char supposed to be in EEPROM
    FO2A[3] = SCUBA_Set.FO2A[3];       // unsigned char supposed to be in EEPROM
    FO2A[4] = SCUBA_Set.FO2A[4];       // unsigned char supposed to be in EEPROM
    FO2A[5] = SCUBA_Set.FO2A[5];       // unsigned char supposed to be in EEPROM
    FO2A[6] = SCUBA_Set.FO2A[6];       // unsigned char supposed to be in EEPROM


    PO2A[1] = SCUBA_Set.PO2A[1];       // unsigned char supposed to be in EEPROM
    PO2A[2] = SCUBA_Set.PO2A[2];       // unsigned char supposed to be in EEPROM
    PO2A[3] = SCUBA_Set.PO2A[3];       // unsigned char supposed to be in EEPROM
    PO2A[4] = SCUBA_Set.PO2A[4];       // unsigned char supposed to be in EEPROM
    PO2A[5] = SCUBA_Set.PO2A[5];       // unsigned char supposed to be in EEPROM
    PO2A[6] = SCUBA_Set.PO2A[6];       // unsigned char supposed to be in EEPROM


    if (isCCMode==false)
    {
        if(FO2A[1]<=21)    FO2A[1]=21;     // when AIR is selected, use 21% for calculation
        if(FO2A[2]<=21)    FO2A[2]=21;     // when AIR is selected, use 21% for calculation
        if(FO2A[3]<=21)    FO2A[3]=21;     // when AIR is selected, use 21% for calculation
        if(FO2A[4]<=21)    FO2A[4]=21;     // when AIR is selected, use 21% for calculation
        if(FO2A[5]<=21)    FO2A[5]=21;     // when AIR is selected, use 21% for calculation
        if(FO2A[6]<=21)    FO2A[6]=21;     // when AIR is selected, use 21% for calculation
    }

    //CurrentGasNumber = CURRENT_TANK_NUM;
    //NumberOfActiveGases = SCUBA_Set.TotalActiveGases;

    for (i = 1; i <= 6; i++)
    {
        FN2A[i] = 100 - (FO2A[i] + FHeA[i]);
        fFO2[i] = FO2A[i] / 100.0;
        fFHe[i] = FHeA[i] / 100.0;
        fFN2[i] = FN2A[i] / 100.0;
    }

    fFO2[0] = fFO2[CURRENT_TANK_NUM];
    FO2A[0] = FO2A[CURRENT_TANK_NUM];
    FHeA[0] = FHeA[CURRENT_TANK_NUM];
    FN2A[0] = FN2A[CURRENT_TANK_NUM];
    PO2A[0] = PO2A[CURRENT_TANK_NUM];

    //SCUBA_Set.FO2A[0] = FO2A[0];        // Do NOT return value back to SCUBA_Set.FO2A[0] !!!!
    SCUBA_Set.FHeA[0] = FHeA[0];
    SCUBA_Set.FN2A[0] = FN2A[0];
    SCUBA_Set.PO2A[0] = PO2A[0];

    // GAS1_MOD = (uint8_t)( ((float)SET_GAS1_PO2_ALARM/(float)SET_GAS1_FO2 - 1.0) * 33.0f );
    SCUBA_Set.MOD[1] = (uint8_t)( ((float)PO2A[1]/(fFO2[1]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[2] = (uint8_t)( ((float)PO2A[2]/(fFO2[2]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[3] = (uint8_t)( ((float)PO2A[3]/(fFO2[3]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[4] = (uint8_t)( ((float)PO2A[4]/(fFO2[4]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[5] = (uint8_t)( ((float)PO2A[5]/(fFO2[5]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[6] = (uint8_t)( ((float)PO2A[6]/(fFO2[6]*100) - 1.0) * 33.0 );

    SCUBA_Set.MOD[0] = (uint8_t)( ((float)PO2A[0]/(fFO2[0]*100) - 1.0) * 33.0 );
    SCUBA_Set.MOD[CURRENT_TANK_NUM] = SCUBA_Set.MOD[0];

    for (i = 0; i <= 24; i++)
    {
        *(Plan_DEPTH_NDT_OTR_PO2[i]) = 0;
        *(Plan_DEPTH_NDT_OTR_PO2[i]+1) = 0;
        *(Plan_DEPTH_NDT_OTR_PO2[i]+2) = 0;
        *(Plan_DEPTH_NDT_OTR_PO2[i]+3) = 0;
    }

    PLAN_INDEX_LO = 2;
    PLAN_INDEX    = 2;

}


void BrowsePLAN(void)
{

#define TOP_INDEX  24
    uint8_t i;

    PLAN_INDEX_LO = 2;

    for(i=PLAN_INDEX_LO; i<=TOP_INDEX; i++)
    {
        if(Plan_DEPTH_NDT_OTR_PO2[i][1] != 0)
            PLAN_INDEX_HI = i;
    }

    /*
    if(UpKeyShortPressed())
        PLAN_INDEX++;

    if(DownKeyShortPressed())
        PLAN_INDEX--;

    if(PLAN_INDEX < PLAN_INDEX_LO)
        PLAN_INDEX = PLAN_INDEX_HI;

    if(PLAN_INDEX > PLAN_INDEX_HI)
        PLAN_INDEX = PLAN_INDEX_LO;

    */
    // Find PLAN_indexTop in Plan_DEPTH_NDT_OTR_PO2

}


/*******************************************************************************
 * @brief   Read My Info From ExFLASH
 *
 * @note
 ******************************************************************************/
void ReadMyInfo(void)
{

    uint8_t i;
    uint8_t *pDst;
    int8_t retry;
    
    pDst = *MyInfoBuff;

    for(i=0; i<INFO_DATA_SIZE; i++)
    {
        *(sInfoName+i) =    *(pDst+i);
        *(sInfoAddr+i) =    *(pDst+INFO_DATA_SIZE+i);
        *(sInfoPhone+i) =   *(pDst+INFO_DATA_SIZE*2+i);
        *(sInfoEmail+i) =   *(pDst+INFO_DATA_SIZE*3+i);
        *(sInfoBlood+i) =   *(pDst+INFO_DATA_SIZE*4+i);
        *(sInfoContact+i) = *(pDst+INFO_DATA_SIZE*5+i);
    }

    /*********** Must do this every time before FLASH Erase/Read/Write  ***********/
    L4X9_QSPI_Init();

    MT25QL512ABB_PowerDownRelease();
    /******************************************************************************/

    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O(EXFLASH_MYINFO, 256, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    /******** Must do this every time after FLASH Erase/Read/Write is done ********/
    MT25QL512ABB_PowerDownEnter();

    L4X9_QSPI_DeInit();
    /******************************************************************************/

}


/*******************************************************************************
      NewDiveProfileAndLogRecorded(void) is for confirming 
      Profile and Log have been recorded after the new dive
      Wait until 10min:10sec for Scuba Dives and Gauge Dives
      Wait until 1min:10sec for Free Dives 
*******************************************************************************/
uint8_t NewDiveProfileAndLogRecorded(void)
{
    if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDGAUGE))
    {    // Scuba Dive or Gauge Dive waits 10min:10sec
        if((Dive_Info.Status==AMB_DIVEINFO_SURF)&&(Dive_Info.SurfTime_s > 610))
          return true;
        else
          return false;
    }
    else  // Free Dive waits for 1min:10sec 
    {
        if((Dive_Info.Status==AMB_DIVEINFO_SURF)&&(Dive_Info.SurfTime_s > 70))
          return true;
        else
          return false;
    }
}


/*******************************************************************************
    A Readback CRC Check after EEPROM Write for 256 Bytes (a block)
    bool CompEE256( void *write_data, void *read_data ) 
*******************************************************************************/
bool CompEE256( void *write_data,  void *read_data )
{
    EE_Block_t *wpt = (EE_Block_t*)write_data;
    EE_Block_t *rpt = (EE_Block_t*)read_data;
    
    if( (wpt->CRC_MSB == rpt->CRC_MSB) && (wpt->CRC_LSB == rpt->CRC_LSB) && (Eval_CRC16(read_data, sizeof(EE_Block_t)) == 0) )
      return 0;         // OK, Correct
    else
    {
      wpt->ErrCnt++;      // EE Write/Read Com Error (mismatch), increment ErrCnt Count by 1, which will trigger Write and Read of the EE Block again
      return 1;         // Not Correct
    }
}


/*******************************************************************************
 * @brief   AppInCommunicating to check if USB or BLE in communicating 
  (not just attached only)
 ******************************************************************************/
bool AppInCommunicating(void)
{
  bool Status=false;
  
    if(SystemStatus.BLE_status==BLE_HDL_CONNECT)
      Status=true;
    
    return Status;
}

/*******************************************************************************
 * @brief   CheckBTname to // Check if BTname on EE same to BLE chip, 
 *          otherwise assign valid EE-BTname to BLE chip
 ******************************************************************************/
uint8_t CheckBTname(void)
{
  uint8_t Err = 0;
  uint8_t LoopCnt = 0;
  char NameString[16] = {0};
  NameString[0] = MFG_Calib.Prefix[0];
  NameString[1] = MFG_Calib.Prefix[1]; 
  NameString[2] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF00000) >> 20);
  NameString[3] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF0000) >> 16);
  NameString[4] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF000) >> 12);
  NameString[5] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF00) >> 8);
  NameString[6] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF0) >> 4);
  NameString[7] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF));

  // check if 6 digits of SN are all legal (from 000001 to 999999)
  if( (MFG_Calib.SN.SerialNum > 0)
    &&((NameString[2]>=0x30)&&(NameString[2]<=0x39))
    &&((NameString[3]>=0x30)&&(NameString[3]<=0x39))
    &&((NameString[4]>=0x30)&&(NameString[4]<=0x39))
    &&((NameString[5]>=0x30)&&(NameString[5]<=0x39))
    &&((NameString[6]>=0x30)&&(NameString[6]<=0x39))
    &&((NameString[7]>=0x30)&&(NameString[7]<=0x39))
    )
    { 
      // OK, do nothing
    }  
    else
    {
      Err = 1;    // Prefix or Serial Number on EEPROM Not valid
      return Err;
    }
  

      uint8_t BTnameFlag = 10;
    
       // BleNameSetRequest = false;

        if( (BLE_IS_OFF && DEV_Board())
           || (PROD_BLE_IS_OFF && !DEV_Board())
           )
        {
            ////St2Ble_PowerOn();  20210205, moved to outside of CheckBTname
            if(DEV_Board())
            {
              while(BLE_IS_OFF && (LoopCnt < 100))  // timeout after 100 loops       
              {
                LoopCnt++;
              }
            }
            else
            {
              while(PROD_BLE_IS_OFF && (LoopCnt < 100))  // timeout after 100 loops       
              {
                LoopCnt++;
              }
            }
        }

        // Swtich On ST Uart.
        UART_BLE_On(BT_USART);
                
        ms_delay(10);
        
        //======================================================================
        while(BTnameFlag--)
        {       
          // Get BLE Name
          St2Ble_GetName();
          
          ms_delay(10);
       
          if( (BleName.NameString[0]==MFG_Calib.Prefix[0])    
            &&(BleName.NameString[1]==MFG_Calib.Prefix[1])    
            &&(BleName.NameString[2]==NameString[2])           
            &&(BleName.NameString[3]==NameString[3])
            &&(BleName.NameString[4]==NameString[4])
            &&(BleName.NameString[5]==NameString[5])
            &&(BleName.NameString[6]==NameString[6])
            &&(BleName.NameString[7]==NameString[7]) )
          {
              BTnameFlag = 0;
              // BTname SN matches with SN saved on EEPROM
              // Do Nothing
          }
          else
          {
            // BTname SN does NOT match with SN saved on EEPROM
            BleName.NameString[0]=MFG_Calib.Prefix[0];    
            BleName.NameString[1]=MFG_Calib.Prefix[1];    
            BleName.NameString[2]=NameString[2];
            BleName.NameString[3]=NameString[3];
            BleName.NameString[4]=NameString[4];
            BleName.NameString[5]=NameString[5];
            BleName.NameString[6]=NameString[6];
            BleName.NameString[7]=NameString[7];         
            
	        BleNameSetRequest = true;
	          
	        BleName.NameLength = 8;
    
        }
        }
        // Switch Off ST Uart
        UART_BLE_Off(BT_USART);
        


        // Restart BLE state machine
        SystemStatus.BLE_status = BLE_HDL_OFF;

  return Err;  
}


NVD_status_t FindSCUBA_TMT_Status(NVD_DIVEMODE_t mode, uint8_t GasNum)
{
  uint8_t TMT_Num = 0;
  //NVD_MDGSM
  if(mode==NVD_MDCC)
    TMT_Num = TRIMIX_Set.CC_GASTMT[GasNum];
  else if(mode==NVD_MDOC)
    TMT_Num = TRIMIX_Set.OC_GASTMT[GasNum];
  else if(mode==NVD_MDSM)
    TMT_Num = TRIMIX_Set.SM_GASTMT[GasNum];
  else if(mode==NVD_MDGSM)
    TMT_Num = TRIMIX_Set.GSM_GASTMT[GasNum];
  else if(mode==NVD_MDGAUGE)
    TMT_Num = TRIMIX_Set.GAUGE_GASTMT[GasNum];
  
  if(TMT_Num==1)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT1;
  else if(TMT_Num==2)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT2;  
  else if(TMT_Num==3)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT3;  
  else if(TMT_Num==4)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT4;  
  else if(TMT_Num==5)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT5;  
  else if(TMT_Num==6)  
    return (NVD_status_t)SCUBA_Set.TMT_On.TMT6;
  else
    return (NVD_status_t)0; 
}

/*******************************************************************************

    Add new configurations only starting from R1005

*******************************************************************************/
void PatchR1005(void)
{
    SCUBA_Set.BOmin     = 20;	//0.20
    SCUBA_Set.BOmax     = 140;	//1.4
    SCUBA_Set.BOdeco    = 161;	//1.61
    
    TRIMIX_Set.BO_Select.Tank1 = true;       // Tank1 is selected
    TRIMIX_Set.BO_Select.Tank2 = false;      // Tank2 is not selected
    TRIMIX_Set.BO_Select.Tank3 = false;      // Tank3 is not selected
    TRIMIX_Set.BO_Select.Tank4 = false;      // Tank4 is not selected
    TRIMIX_Set.BO_Select.Tank5 = false;      // Tank5 is not selected
    TRIMIX_Set.BO_Select.Tank6 = false;      // Tank6 is not selected
    TRIMIX_Set.BO_Active.Gas1 =  true;       // Gas-1 is selected
    TRIMIX_Set.BO_Active.Gas2 =  false;       // Gas-2 is selected
    TRIMIX_Set.BO_Active.Gas3 =  false;       // Gas-3 is selected
    TRIMIX_Set.BO_Active.Gas4 =  false;       // Gas-4 is selected
    TRIMIX_Set.BO_Active.Gas5 =  false;       // Gas-5 is selected
    TRIMIX_Set.BO_Active.Gas6 =  false;       // Gas-6 is selected

    TRIMIX_Set.BO_GASTMT[0] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[1] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[2] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[3] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[4] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[5] = (TMT_NUM_t)TMT_OFF;
    TRIMIX_Set.BO_GASTMT[6] = (TMT_NUM_t)TMT_OFF;
    
    TRIMIX_Set.BO_PO2A[0] = 140;
    TRIMIX_Set.BO_PO2A[1] = 140;
    TRIMIX_Set.BO_PO2A[2] = 140;
    TRIMIX_Set.BO_PO2A[3] = 140;
    TRIMIX_Set.BO_PO2A[4] = 140;
    TRIMIX_Set.BO_PO2A[5] = 140;
    TRIMIX_Set.BO_PO2A[6] = 140;
    
    TRIMIX_Set.BO_FO2[0] = 21;
    TRIMIX_Set.BO_FO2[1] = 21;
    TRIMIX_Set.BO_FO2[2] = 18;
    TRIMIX_Set.BO_FO2[3] = 25;
    TRIMIX_Set.BO_FO2[4] = 32;
    TRIMIX_Set.BO_FO2[5] = 50;
    TRIMIX_Set.BO_FO2[6] = 100;
    
    TRIMIX_Set.BO_FHe[0] = 0;
    TRIMIX_Set.BO_FHe[1] = 0;
    TRIMIX_Set.BO_FHe[2] = 30;
    TRIMIX_Set.BO_FHe[3] = 35;
    TRIMIX_Set.BO_FHe[4] = 0;
    TRIMIX_Set.BO_FHe[5] = 0;
    TRIMIX_Set.BO_FHe[6] = 0;

    TRIMIX_Set.CurrGasNumber_BO = TANK_1;
    TRIMIX_Set.BO_Active.Allbits = 0x01;
}


/*******************************************************************************

    Add new configurations only starting from R1006

*******************************************************************************/
void PatchR1006(void)
{
    DEV_Rec.FLASH_ErrCnt = 0;   // reset FLASH Comm Error count, added from R1006
    DEV_Rec.EE_ErrCnt = 0;      // reset EEPROM Comm Error count, added from R1006
}


/*******************************************************************************

    Error Handle for EEPROM Error, added from R1006

*******************************************************************************/
void ErrHandle_EE(void)
{
    DEV_Rec.SystemErrorWarningBits.Eeprom = true;
    DEV_Rec.EE_ErrCnt++;
}

/*******************************************************************************

    Error Handle for ExFLASH Error, added from R1006

*******************************************************************************/
void ErrHandle_FLASH(void)
{
    DEV_Rec.SystemErrorWarningBits.Flash = true;
    DEV_Rec.FLASH_ErrCnt++;
}

#endif //_L4X9_NVDATA_H_