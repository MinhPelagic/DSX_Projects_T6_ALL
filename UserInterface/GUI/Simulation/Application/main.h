
#ifndef STUB_PRTOS_L4_H
#define STUB_PRTOS_L4_H

//#define DEMO_TEST
#define TRUE	(0==0)
#define FALSE (0!=0)
#define PROFILE_CHART_SIZE  200
#define XSIZE_PHYS  320
#define YSIZE_PHYS  240
#define EE_S_PAGE_ADDR 1
#define LOG_DIVE_NUM	1
#define LOG_DATA_SIZE	1
#define STFwr_Version	1
#define R_ACK 1
#define FLASH_READ_SHIFT_ONE 1
#define FLASH_READ_NO_SHIFT 1
#define HW_BUTTON_TL            0x01
#define HW_BUTTON_TR            0x02
#define HW_BUTTON_BL            0x04
#define HW_BUTTON_BR            0x08
#define EE_MFGCAL       0x00
#define EE_DEVREC       0x01
#define EE_USERSET      0x02
#define EE_SCUBASET     0x03
#define EE_TRIMIXSET     0x03
#define EE_SCUBAREC     0x04    // USE RAM ONLY, NOT SAVED ON EE
#define EE_FREESET      0x05    // EE NOT USED
#define EE_FREEREC      0x06    // EE NOT USED
#define EE_FLASHMAP     0x07
#define BUTTON_TL_PORT     0x00
#define BUTTON_BL_PIN     0x00
#define BUTTON_TL_PIN     0x00
#define BUTTON_BR_PORT     0x00
#define BUTTON_BR_PIN     0x00
#define BUTTON_BL_PORT     0x00
#define MAX_TOTAL_TANK_NUM          6    
#define TOTAL_TANK_NUM              6       // 6 for DSX; 3 for i330R, 
#define PLAN_INDEX_HI              0   
#define PLAN_INDEX_LO              0       
#define HW_BUTTON_G0              0       
#define HW_BUTTON_G1              0       
#define HW_BUTTON_G2              0       
#define HW_BUTTON_G3              0       
#define PROD_BUTTON_R_PORT              0       
#define PROD_BUTTON_R_PIN              0       
#define PROD_BUTTON_M_PORT              0       
#define PROD_BUTTON_M_PIN              0       
#define PROD_BUTTON_L_PORT              0       
#define PROD_BUTTON_L_PIN              0       
#define TP2_HIGH              0       
#define TP2_LOW               0       
#define TP3_HIGH               0       
#define TP3_LOW               0       
#define GUI_ROTATION_180               0       
#define GUI_ROTATION_0               0       
#define BLE_HDL_CONNECT               0       
#define BLE_HDL_READY               0       
#define CURRENT_TANK_NUM	SCUBA_Set.CurrGasNumber
#define CURRENT_TANK_NUM_CC	SCUBA_Set.CurrGasNumber
#define CURRENT_TANK_NUM_OC	SCUBA_Set.CurrGasNumber
#define CURRENT_TANK_NUM_SM	SCUBA_Set.CurrGasNumber
#define CURRENT_TANK_NUM_BO	SCUBA_Set.CurrGasNumber
#define SURF_MENU_TIMEOUT_S             0  
#define MAG_CAL_SAMPLES             0  
#define CONST_PSI_TO_BAR        0  
#define PSM_TIMEOUT_S        0         
#define USER_SIMULATE_PORT        0         
#define USER_DEMO_PIN        0         
#define MINIMUM_SATELLITE        0         
#define GNSS_ON        0         
#define CURRENT_TMT_NUM        0         
#define CONST_FT_TO_M        0         
#define GNSS_SLEEP        1         
#define CONST_mBAR_TO_PSI        1         
#define NVD_DEVREC_LOC1        1         
#define MAG_CAL_DURATION_SEC        1         
#define GPS_LOCATION_Num        1         
#define CONST_CUFT_TO_LITER        1         
#define BACKLIGHT_DIM        1         
#define SYS_ACTIVE        1         
#define GPS_LOCATION_NUM_MAX        1         
#define ALARM_ENDPRESS_PSI        1         
#define ALARM_ENDPRESS_BAR        1         
#define PASSCODE_ON        1         
#define u16DiveTimeTotalSec        1         

typedef enum
{
	HIGH_SP = 0x00,
	LOW_SP = 0x01,
	CUSTOM_SP = 0x02
}SP_Switch_t;
typedef enum
{
	TANK_OFF = 0x00,
	TANK_1 = 0x01,
	TANK_2 = 0x02,
	TANK_3 = 0x03,
	TANK_4 = 0x04,
	TANK_5 = 0x05,
	TANK_6 = 0x06
}TANK_NUM_t;
typedef enum
{
	TMT_OFF = 0x00,
	TMT_1 = 0x01,
	TMT_2 = 0x02,
	TMT_3 = 0x03,
	TMT_4 = 0x04,
	TMT_5 = 0x05,
	TMT_6 = 0x06
}TMT_NUM_t;
typedef enum
{
	NVD_2SEC = 2,
	NVD_15SEC = 15,
	NVD_30SEC = 30,
	NVD_60SEC = 60,
}NVD_SAMPLETIME_t;

typedef enum 
{
  CONSV_TEC   = 0x00,
  CONSV_SPORT = 0x04
}CONSV_TecSport_t;

typedef enum {
	ColorSel_CYAN = 0x00,
	ColorSele_GREEN,
	ColorSel_WHITE,
	ColorSel_ORANGE,
	ColorSel_MAGENTA,
	ColorSel_MAX
} ColorSel_t;
typedef enum
{
	CONSV_GF_LOW = 0x00,
	CONSV_GF_HIGH,
}CONSV_GF_Switch_t;
typedef enum {
	Select_ENGLISH = 0,
	Select_GERMAN,
	Select_FRENCH,
	Select_ITALIAN,
	Select_ESPANOL,
	Select_PORTUGESE,
	Select_POLISH,
	Select_RUSSIAN,
	Select_CZECH,
	Select_CHINESE_S,   //Simplified Chinese
	Select_CHINESE_T,   //Traditional Chinese
	Select_KOREAN,
	MAX_LANGUAGE
} LanguageSelect_t;
enum O2_ANALYZER_STAGES
{
	O2_ANALYZER_OFF = 0x00,
	O2_ANALYZER_INIT,
	O2_ANALYZER_WE1,
	O2_ANALYZER_WE2,
	O2_ANALYZER_WE3,
	O2_ANALYZER_FO2_CHECK,
	O2_ANALYZER_CELL_CALIBRATION,
	O2_ANALYZER_CELL_ANALYZE,
	O2_ANALYZER_MAX,
};
typedef enum
{
	MODE_SWITCH_DONE = 0,
	MODE_SWITCH_CC2OC,
	MODE_SWITCH_OC2CC,
	MODE_SWITCH_CC2BO,
	MODE_SWITCH_BO2CC,
	MODE_SWITCH_MAX,
} MODE_SWITCH_t;
//======================================================================================
typedef struct
{
	uint8_t      Gas1 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Gas2 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Gas3 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Gas4 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Gas5 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Gas6 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
}Gas_Bit_t;
typedef struct
{
	uint8_t Allbits;
	uint8_t      TMT1 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      TMT2 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      TMT3 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      TMT4 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      TMT5 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      TMT6 : 1;     // 1-bit #1 --> 0: OFF, 1: ON:
	uint8_t      Resv7 : 1;
	uint8_t      Resv8 : 1;
}TMT_Bit_t;

typedef enum {

	//----- [10 beeps]--------------------
	ALARM_CondiVio = 0,         // 0
	ALARM_DelayedVio1,
	ALARM_DelayedVio2,
	ALARM_DepthMax,
	ALARM_AscRate5,
	ALARM_PO2_Lo,
	ALARM_PO2_Hi,
	ALARM_DepthSet,

	ALARM_DiveN2Bar,            // 8
	ALARM_O2_80Pct,
	ALARM_O2_100Pct,
	ALARM_DECO_Entry,
	ALARM_DiveTime,
	ALARM_DiveDTR,
	//----- [3 short beeps]----------------
	ALARM_AscRate4,
	ALARM_FreeDiveT,            // NOT used in DSX 
	//----- [3 short beeps x 3 times]------
	ALARM_FreeDepth1,           // NOT used in DSX 
	ALARM_FreeDepth2,           // NOT used in DSX 
	ALARM_FreeDepth3,           // NOT used in DSX 
	ALARM_FreeN2Bar,            // NOT used in DSX 
	ALARM_FreeCDT,              // NOT used in DSX 
	ALARM_FreeViol,             // NOT used in DSX 
	//----- [10 beeps]--------------------
	ALARM_DECO_Depth70,
	ALARM_SwitchFO2,

	ALARM_SetupVIOLATION,       // 24
	ALARM_DECO_Warning,
	ALARM_DECO_Alarm,
	ALARM_GFBG_Alarm,
	ALARM_Reserved28,
	ALARM_LowBattShutdown,
	ALARM_LowBatteryWarning,
	ALARM_LowBatteryAlarm,
	ALARM_NoOpShutdown,

	//--- ALARM2    
	//------------------------------- [1 beep per sec for 10 sec]---------------------------------
	ALARM_SP_AutoHi,            // 32
	ALARM_SP_AutoLo,
	ALARM_TEC_GF_Hi,
	ALARM_TEC_GF_Lo,
	ALARM_TTS_T,
	ALARM_TankP,
	ALARM_CC6P,
	ALARM_TurnP,

	ALARM_EndP,                 // 40
	ALARM_SwitchP,
	ALARM_GF,
	ALARM_N2,
	ALARM_End,
	ALARM_WOB,
	ALARM_ICD,
	ALARM_Narcotic,

	ALARM_GTR5,                 // 48
	ALARM_GTR0,
	ALARM_LostLink,
	ALARM_OCSM_MinPO2,
	ALARM_OCSM_MaxPO2,
	ALARM_OCSM_DecoPO2,
	ALARM_Reserved54,
	ALARM_Reserved55,

	ALARM_Reserved56,           // 56
	ALARM_Reserved57,
	ALARM_Reserved58,
	ALARM_Reserved59,
	ALARM_Reserved60,
	ALARM_Reserved61,	// comment out to avoid overflow that caused Buzzer NOT working
	ALARM_TMT_LowBattWarning,
	ALARM_TMT_LowBattAlarm,

	ALARM_MAX,                  // 64 as total Alarm Flags
} ALARM_ID_t;

typedef struct
{
	//------------------------------- [1 beep per sec for 10 sec]---------------------------------
	uint32_t      CondiVio : 1;     // 1-bit      [1 beep per sec for 10 sec] Conditional Violation
	uint32_t      DelayedVio1 : 1;     // 1-bit      [1 beep per sec for 10 sec] Delayed Violation 1      // must be Saved to EEPROM
	uint32_t      DelayedVio2 : 1;     // 1-bit      [1 beep per sec for 10 sec] Delayed Violation 2  
	uint32_t      DepthMax : 1;     // 1-bit      [1 beep per sec for 10 sec] Depth Out of Range 
	uint32_t      AscRate5 : 1;     // 1-bit      [1 beep per sec for 10 sec] Ascent Rate (alarm) too fast - 5 segments    
	uint32_t      PO2_Lo : 1;     // 1-bit      [1 beep per sec for 10 sec] PO2 increases to .20 < Alarm Set Point 
	uint32_t      PO2_Hi : 1;     // 1-bit      [1 beep per sec for 10 sec] PO2 > Alarm Set Point 
	uint32_t      DepthSet : 1;     // 1-bit      [1 beep per sec for 10 sec] Depth Alarm 

	uint32_t      DiveN2Bar : 1;     // 1-bit      [1 beep per sec for 10 sec] DIVE N2 (N2BG) Alarm      
	uint32_t      O2_80Pct : 1;     // 1-bit      [1 beep per sec for 10 sec] DIVE O2 at 80%
	uint32_t      O2_100Pct : 1;     // 1-bit      [1 beep per sec for 10 sec] DIVE O2 at 100% // must be Saved to EEPROM
	uint32_t      DECO_Entry : 1;     // 1-bit      [1 beep per sec for 10 sec] Entry into Deco
	uint32_t      DiveTime : 1;     // 1-bit      [1 beep per sec for 10 sec] Dive Time EDT Alarm     
	uint32_t      DiveDTR : 1;     // 1-bit      [1 beep per sec for 10 sec] DIVE DTR Alarm          // works with SCUBA_Set.DTR_Alarm

	//------------------------------- [3 short beeps]---------------------------------
	uint32_t      AscRate4 : 1;     // 1-bit      [3 short beeps for once] DIVE/GAUGE Ascent Rate (warning) - 4 segments [3 short beeps]
	uint32_t      FreeDiveT : 1;     // 1-bit      [3 short beeps for once] FREE EDT Alarm
	uint32_t      FreeDepth1 : 1;     // 1-bit      [3 short beeps for 3 times] FREE Depth Alarms 1  
	uint32_t      FreeDepth2 : 1;     // 1-bit      [3 short beeps for 3 times] FREE Depth Alarms 2  
	uint32_t      FreeDepth3 : 1;     // 1-bit      [3 short beeps for 3 times] FREE Depth Alarms 3
	uint32_t      FreeN2Bar : 1;     // 1-bit      [3 short beeps for 3 times] Free N2 (N2BG) Alarm 
	uint32_t      FreeCDT : 1;     // 1-bit      [3 short beeps for 3 times] Free CDT Alarm 
	uint32_t      FreeViol : 1;     // 1-bit      [3 short beeps for 3 times] FREE Violation VGM

	//------------------------------- [1 beep per sec for 10 sec]---------------------------------
	uint32_t      DECO_Depth70 : 1;     // 1-bit      [1 beep per sec for 10 sec] Deco Stop Depth Violation > 70 FT (21 M) required
	uint32_t      SwitchFO2 : 1;     // 1-bit      [1 beep per sec for 10 sec] SwitchFO2 0: 1:

	uint32_t      SetupVIOLATION : 1;     // 1-bit      Confirm Immediate Violation or Delayed Violation 0: 1:
	uint32_t      LowBattShutdown : 1;     // 1-bit       Battery Volt < 3.65V CUTOFF_mVOLT    
	uint32_t      LowBattWarning : 1;     // 1-bit       Battery Volt < 3.70V BattWarning_mV
	uint32_t      LowBattAlarm : 1;     // 1-bit       Battery Volt < 3.66V BattCutoff_mV
	uint32_t      NoOpShutdown : 1;     // 1-bit       Battery Volt < 3.66V BattCutoff_mV
	uint32_t      End : 1;    
	uint32_t      WOB : 1;
	uint32_t      N2 : 1;
	uint32_t      EndP : 1;
	uint32_t      ICD : 1;
	uint32_t      GF : 1;
	uint32_t      CC6P : 1;   
	uint32_t      SP_AutoHi : 1;
	uint32_t      SP_AutoLo : 1;
	uint32_t      SwitchP : 1;
	uint32_t      TankP : 1;
	uint32_t      TTS_T : 1;
	uint32_t      TurnP : 1;
	uint32_t      Narcotic : 1;
	uint32_t      LostLink : 1;
	uint32_t      GTR5 : 1;
	uint32_t      DECO_Warning : 1;
	uint32_t      OCSM_DecoPO2 : 1;
	uint32_t      DECO_Alarm : 1;
	uint32_t      OCSM_MinPO2 : 1;
	uint32_t      OCSM_MaxPO2 : 1;
	uint32_t      GTR0 : 1;
	uint32_t      TMT_LowBattWarning : 1;
	uint32_t      TMT_LowBattAlarm : 1;

}AlarmUnion;     // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control
union AlarmUNION
{
	AlarmUnion    Bit;
	uint32_t      AllBits;              // Combination of all above
};
typedef union {
	uint8_t Allbits;
	struct {
		uint8_t   ConservMode : 4;     // 4-bit for TEC or SPORT
		uint8_t   ConservSportMode : 4;     // 4-bit for Consv SPORT Low, Med, or High      
	};
}CONSV_Set_t;

typedef struct
{
	uint8_t CRC_MSB;
	uint8_t CRC_LSB;
	uint8_t CC6PressPSI;
	uint8_t CC6PressBAR;
	uint8_t GF_High;
	uint8_t TEC_GF_Hi;
	uint8_t TEC_GF_Lo;
	uint8_t ConservMode;
	uint8_t CurrGasNumber;
	uint8_t Reserved3F;
	uint8_t DepthAlarmFT;
	uint8_t DepthAlarmM;
	uint8_t DTR_Alarm;
	uint8_t TTS_min;
	uint8_t SS_DepthFt;
	uint8_t SS_DepthM;
	uint8_t LastStopFt;
	uint8_t LastStopM;
	uint8_t SafetyStopMode;
	uint8_t SafetyStopMin;
	uint8_t EDT_Alarm;
	uint8_t SP_SetHigh;
	uint8_t SP_SetLow;
	uint8_t SP_SetCustomer;
	uint8_t AutoHighSP_Switch;
	uint8_t AutoLowSP_Switch;
	uint8_t SP_AutoHighM;
	uint8_t SP_AutoLowM;
	uint8_t SP_AutoHighFT;
	uint8_t CC6P_PSI;
	uint8_t CC6P_BAR;
	Gas_Bit_t GasActive;
	uint8_t GASTMT[100];
	uint8_t SP_Switch;
	uint8_t SP_AutoLowFT;
	uint8_t OCmin;
	uint8_t OCmax;
	uint8_t OCdeco;
	uint8_t TecSP_Hi;
	uint8_t TecSP_Lo;
	uint8_t GF_Low;
	uint8_t EndP_BAR;
	uint8_t EndP_PSI;
	uint8_t End_AL_dM;
	uint8_t End_AL_Ft;
	uint8_t Wob_AL_dM;
	uint8_t Wob_AL_Ft;
	uint8_t GFBG_Alarm;
	uint8_t SwitchP_BAR;
	uint8_t SwitchP_PSI;
	uint8_t TLBG_Alarm;
	uint8_t TankP_PSI;
	uint8_t TankP_BAR;
	uint8_t TurnP_BAR;
	uint8_t TurnP_PSI;
	uint8_t WOB_AL_dM;
	uint8_t WOB_AL_Ft;
	uint8_t EndPressBAR;
	uint8_t EndPressPSI;
	uint8_t GF_Alarm;
	uint8_t N2_Alarm;
	uint8_t TankPressBAR;
	uint8_t TankPressPSI;
	uint8_t TurnPressPSI;
	uint8_t TurnPressBAR;
	uint8_t BOmin;
	uint8_t BOmax;
	uint8_t BOdeco;
	uint8_t SP_CustomSW;
	uint8_t SP_Current;
	uint8_t  FO2A[10];    
	uint8_t  FHeA[10];
	uint8_t  PO2A[10];
	uint8_t  FN2A[10];
	CONSV_Set_t Consv;             
	uint8_t TMTID[MAX_TOTAL_TANK_NUM + 1];     /* 4-Byte x 7 Transmitter 1 ID */
	TMT_Bit_t TMT_On;     /* 4-Byte x 7 Transmitter 1 ID */
	union AlarmUNION  AlarmSet;   // Byte-12,13,14,15  4-Byte Alarms and Warnings of the system and dive
	union AlarmUNION  Alarm2Set;   // Byte-12,13,14,15  4-Byte Alarms and Warnings of the system and dive
} Scuba_Settings_t;  // can be modified by user settings about diving activities)
typedef struct
{
	uint8_t InstantTemperature_F;                                   
	uint8_t AverageTemperature_F;                                
	uint8_t InstantPressure_mbar;
	uint8_t InstantTemperature_C;
	uint8_t AverageTemperature_C;
} TP_Info_struct_t;
typedef struct
{
	uint8_t SurfacePressure_mbar;           /* Surface Pressure Expressed in mbar */
	uint8_t AltitudeLevel;       
	uint8_t SurfTime_s;
	uint8_t WaterDepth_ft;
	uint8_t WaterDepth_m;
	uint8_t DiveTime_s;
	uint8_t AvgWaterDepth_ft;
	uint8_t Status;
	uint8_t StartSurfTime_s;
	uint8_t PrevSurfTime_s;
	uint8_t PrevDiveTime_s;
	uint8_t PreStatus;
	uint8_t MaxWaterDepth_ft;
	uint8_t MaxWaterDepth_m;
	uint8_t ResetDiveDepthAvg;
	uint8_t ModeSwitchFlag;
} Dive_Info_struct_t;
typedef struct
{
	uint32_t      AlarmAudible : 1;        
	uint32_t      AlarmVibeOn : 1;       
	uint32_t      DateFormat : 1;
	uint32_t      TimeFormat : 1;
	uint32_t      AlarmLED : 1;
	uint32_t      BluetoothOn : 1;
	uint32_t      ConservativeOn : 1;
	uint32_t      ClockAlarm : 1;
	uint32_t      NoFlyAlarm : 1;
	uint32_t      VibrationOn : 1;
	uint32_t      LCD_Flip : 1;
	uint32_t      GTRforLnR : 1;
	uint32_t      Unit : 1;
	uint32_t      HR24_Format : 1;
	uint32_t      DDMM_Format : 1;
}SwitchUnion;


union SwitchUNION
{
	SwitchUnion   Bit;
	uint32_t      AllBits;              // Combination of all above
};
typedef enum
{
	NVD_IMPERIAL = 0x00,
	NVD_METRIC = 0x01
}NVD_UNITS_t;

typedef enum
{
	NVD_SALT = 0x00,
	NVD_FRESH = 0x01,
	NVD_EN13319 = 0x02,
	NVD_WATERAUTO = 0x03,
	NVD_MAX
}NVD_WATER_t;

typedef enum
{
	NVD_DVS_SS_OFF = 0x00,
	NVD_DVS_SS_ON = 0x01,
	NVD_DVS_SS_SET = 0x02,
}NVD_DVS_SSMODE_t;
typedef enum 
{
  CONSV_SPORT_LOW   = 0x01,
  CONSV_SPORT_MED,
  CONSV_SPORT_HIGH
}CONSV_Sport_t;

typedef struct
{
	uint8_t DiveMode;
	uint8_t DateFormat;
	uint8_t TimeFormat;
	uint8_t Units;
	uint8_t WaterType;
	uint8_t SamplingTime;
	uint8_t Bluetooth;
	uint8_t DimBacklightMode;
	uint8_t BacklightDimTimeSec;
	uint8_t BacklightLevel;
	uint8_t DimBacklightLevel;
	uint8_t TitleColor;
	uint8_t Main3RowL;
	uint8_t Main3RowR;
	uint8_t LangSelec;
	uint8_t FontSize;
	uint8_t GFBGorBAR;
	uint8_t ScreenSet;
	uint8_t SIM_DepthFT;
	uint8_t SIM_SAC;
	uint8_t SIM_SP;
	uint8_t SIM_SAC_CuFt;
	uint8_t SIM_SAC_Ltr;
	uint8_t SIM_Time;
	uint8_t SIM_DepthM;
	uint8_t CompassDeclinationDeg;
	uint8_t SIM_Mode;
	uint8_t CC_3RowL;
	uint8_t CC_3RowR;
	uint8_t OC_3RowL;
	uint8_t SM_3RowL;
	uint8_t SM_3RowR;
	uint8_t OC_3RowR;
	uint8_t GForN2;
	uint8_t MyInfo_Idx;
	uint8_t ReturnDiveMode;
	uint8_t WayFinderLocNum;
	uint8_t SLATE_Idx[16];
	uint8_t Welcome_Idx[3];
	uint8_t SLATE_Stat[16];
	uint32_t SLATE_Data[16];
	uint32_t Welcome_Stat[16];
	union SwitchUNION SwitchSet;          
} User_Settings_t; // can be modified by user settings (user's preference about the device)

typedef struct
{
	uint8_t AvgHeading;
	uint8_t Status;
	uint8_t CalGood;
	uint8_t RefHeadingSet;
	uint8_t RevHeadingSet;
	uint8_t Heading;
}EcData_struct_t;

typedef enum
{
	NVD_MDCC = 0x00,   // equivalent to OC Mode in DSX
	NVD_MDOC = 0x01,
	NVD_MDSM = 0x02,
	NVD_MDGSM = 0x03,
	NVD_MDGAUGE = 0x04,
	NVD_MDSCUBA = 0x05,
	NVD_MDFREE = 0x06,
	NVD_MDBO,
	NVD_MDMAX,
}NVD_DIVEMODE_t;
/* System Time and Date structure */
typedef struct
{
	uint8_t Hour;                 // in Bin format
	uint8_t Minute;               // in Bin format
	uint8_t Second;               // in Bin format        
	uint8_t Day;                  // in Bin format
	uint8_t WeekDay;              // 1: Monday; 7: Sunday
	uint8_t Month;                // in Bin format
	uint8_t Year;                 // in Bin format
	uint8_t res;                  // reserved
} SystemTimeDate_t;
// System Supply Monitor Structure
typedef struct
{
	uint8_t Battery_Percentage;           // Battery Percentage 0-100%
	uint8_t PreBattery_Percentage;           // Battery Percentage 0-100%
} L4X9_SystemSupplyMonitor_t;

typedef struct 
{
    SystemTimeDate_t DateTime;  /* 8-Byte uint8 GPS Date and Time Info */
    float Latitude;             /* 4-Byte float GPS Latitude Data */
    float Longitude;            /* 4-Byte float GPS Longitude Data */
    char LocationName[20];      /* 20-Byte char GPS Location Name String */
    char Reserved[10];          /* 10-Byte Reserved */
    uint16_t DataCtrl;          /* 2-Byte Data Control bits */
    SystemTimeDate_t EndDiveDateTime;   /* 8-Byte uint8 GPS Date and Time Info */    
    float EndDiveLatitude;              /* 4-Byte float GPS Latitude Data for End of Dive */
    float EndDiveLongitude;             /* 4-Byte float GPS Longitude Data for End of Dive */
} GPS_LocationRec_t;

/* Dive LOG Data Structure */
typedef struct
{
	TMT_Bit_t  TMT_On_Bits;
	uint8_t       DiveType;      
	uint8_t       EndDiveType;
	uint8_t       LogNum;      
	uint8_t       DiveNum;
	uint8_t       EntryYear;
	uint8_t       EntryMin;
	uint8_t       EntryHr;
	uint8_t       EntryMon;
	uint8_t       EntryDay;
	uint8_t       MaxDepthFt10;
	uint8_t       AvgDepthFt10;
	uint8_t       EDTsec;
	uint8_t       MinTempF10;
	uint8_t       O2Sat;
	uint8_t       MaxPO2;
	uint8_t       Start_PSI[10];
	uint8_t       End_PSI[10];
	uint8_t       TankTimeMin[10];
	uint8_t       Bailout_Start_PSI[10];
	uint8_t       Bailout_End_PSI[10];
	uint8_t       Bailout_TankTimeMin[10];
	uint8_t       CC_HiPO2;
	uint8_t       CC_LoPO2;
	uint8_t       TLBG_Threshold;
	uint8_t       TotalDiveSec;
	uint8_t       CC_MaxGF;
	uint8_t       TLBGS[10];
	uint8_t       OC_StartGasPSI[10];
	uint8_t       OC_EndGasPSI[10];
	uint8_t       OC_GasTimeMin[10];
	uint8_t       CC_StartGasPSI[10];
	uint8_t       CC_GASTMT[10];
	uint8_t       OC_GASTMT[10];
	uint8_t       SM_GASTMT[10];
	uint8_t       CC_EndGasPSI[10];
	uint8_t       CC_GasTimeMin[10];
	union AlarmUNION  AlarmOccured;    // Byte-60,61,62,63:  4-Byte Alarms and Warnings of the system and dive
}LOG_Data_t; //128 bytes data structure  
typedef struct
{
	int16_t Data[100];      // 200 Bytes
	uint8_t Reserved[56];       //  56 Bytes
}LOG_Chart_t;   //256 bytes data structure 

typedef enum
{
	AMB_DIVEINFO_NEWDAY_SLEEP = 0x00,     // 24 hours after Surface Mode waiting for User Activity
	AMB_DIVEINFO_NEWDAY,                  // on POR or after any user action
	AMB_DIVEINFO_SURF,                    // 10 minutes after dive ends 
	AMB_DIVEINFO_DIVE,                    // during the diving
	AMB_DIVEINFO_10HDIVE,                 // during the 10 Hour diving
	AMB_DIVEINFO_AFTERDIVE,               // from 0 to 10 minutes after dive ends
}AMB_DIVEINFO_t;

enum COMPASS_Status
{
	COMPASS_OFF = 0,
	COMPASS_ON,
	COMPASS_CALIBRATING,
};
typedef enum
{
	NVD_MD = 0x00,
	NVD_DM = 0x01
}NVD_dateformat_t;
typedef enum
{
	NVD_12HR = 0x00,
	NVD_24HR = 0x01
}NVD_timeformat_t;
typedef enum
{
	NVD_OFF = 0x00,
	NVD_ON = 0x01,
	NVD_SET = 0x02
}NVD_status_t;
typedef enum
{
	NVD_NO = 0x00,
	NVD_YES = 0x01
}NVD_YesNo_t;
typedef enum
{
  MMC_CALQSTATUSUNKNOWN = 0,
  MMC_CALQSTATUSPOOR,
  MMC_CALQSTATUSOK,
  MMC_CALQSTATUSGOOD
} MMC_CalQuality_t;

typedef struct 
{
  uint8_t HI_Bias[3];            
  uint8_t SF_Matrix[3][3]; 
  MMC_CalQuality_t CalQuality; 	
} MMC_Output_t;
/* System Failure/Warnings */
typedef struct
{
	union
	{
		uint32_t AllBits;
		struct
		{
			uint32_t      NoErr : 1;        // 1-bit              N/A
			uint32_t      SensorPress : 1;        // 1-bit              ERR1
			uint32_t      Eeprom : 1;        // 1-bit (Page-A73)   ERR2
			uint32_t      Flash : 1;        // 1-bit              ERR3
			uint32_t      Calibration : 1;        // 1-bit (Page-A74)   ERR4
			uint32_t      CheckSum : 1;        // 1-bit (Page-A75)   ERR5
			uint32_t      Dive10h : 1;        // 1-bit              ERR6
			uint32_t      LowBattery : 1;        // 1-bit              ERR7
			uint32_t      Bluetooth : 1;        // 1-bit              ERR8
			uint32_t      NotYetCali : 1;        // 1-bit (Page-A80)   ERR9
			uint32_t      LastDive : 1;        // 1-bit (Page-A78)   ERR10
			uint32_t      ADC : 1;        // 1-bit (Page-A76)   ERR11    
			uint32_t      SensorTemp : 1;        // 1-bit              ERR12     
			uint32_t      SensorVolt : 1;        // 1-bit              ERR13
			uint32_t      TickTime : 1;        // 1-bit              ERR14
			uint32_t      Button : 1;        // 1-bit              ERR15

			uint32_t      Altitude : 1;        // 1-bit              ERR16
			uint32_t      Compass : 1;        // 1-bit              ERR17
			uint32_t      FuelGauge : 1;        // 1-bit              ERR18
			uint32_t      Receiver : 1;        // 1-bit              ERR19
			uint32_t      Gps : 1;        // 1-bit              ERR20
			uint32_t      O2Analyzer : 1;        // 1-bit              ERR21
			uint32_t      Reserved22 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved23 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved24 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved25 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved26 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved27 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved28 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved29 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved30 : 1;        // 1-bit reserved               0:                      1: 
			uint32_t      Reserved31 : 1;        // 1-bit reserved               0:                      1: 
		};
	};
} L4X9_SystemWarnings_t;
typedef struct
{
	SystemTimeDate_t RTC_PST;        
	uint8_t CC_DiveNumOfDay;
	uint8_t CC_LogNumLast;
	uint8_t CC_LogNumDisp;
	uint8_t OC_DiveNumOfDay;
	uint8_t OC_LogNumLast;
	uint8_t OC_LogNumDisp;
	uint8_t SM_DiveNumOfDay;
	uint8_t SM_LogNumLast;
	uint8_t SM_LogNumDisp;
	uint8_t GSM_DiveNumOfDay;
	uint8_t GSM_LogNumLast;
	uint8_t GSM_LogNumDisp;
	uint8_t GAUGE_DiveNumOfDay;
	uint8_t GAUGE_LogNumLast;
	uint8_t GAUGE_LogNumDisp;
	uint8_t O2_Analyzer_V2Pct_Slope;
	uint8_t DiveNumOfDay;
	uint8_t LogNumDisp;
	uint8_t LogNumLast;
	uint8_t TotalDiveTimeSec;
	uint8_t MaxDiveTimeSec;
	uint8_t LogNumRecorded;
	uint8_t DevLowestTempF10;
	uint8_t DevMaxDepthFt10;
	uint8_t Max_Elev;
	uint8_t WayFinderLocNum;
	uint8_t LockForGaugeDive;
	uint8_t DevAvgDepthFt;
	struct
	{
		uint8_t Reg_KEY;
	}Reg;
	MMC_Output_t CompassCali;
	L4X9_SystemWarnings_t SystemErrorWarningBits;
} Device_Records_t; 
typedef struct
{
	uint32_t  SerialNum : 24;
	uint32_t  KeyToDive : 8;
}Serial_32Byte;
typedef struct
{
	uint8_t Day;         // DD in HEX
	uint8_t Month;       // MM in HEX  
	uint8_t Year;         // 20XX, XX in HEX
	uint8_t Resv;         // reserved
}NVD_date_t;
typedef struct
{
	uint32_t  SerialNum : 24;
	uint32_t  Reserved : 8;
}O2_Serial_4Bytes;
/// Payload for response to O2 Analyzer Calibration/Analysis commands
typedef struct __Pelagic_Cmd_O2_Resp
{
	uint16_t O2_ADC_Offset;        //!< (mV) O2 Analyzer O2_ADC_Offset, the intercept point at Vadc axis
	uint16_t O2_ADC_Calib;         //!< (mV) O2 Analyzer O2_ADC_Calib, the calibration point at Vadc axis
	uint16_t O2_ADC_Analyze1;      //!< (mV) O2 Analyzer O2_ADC_Analyze1, the analyze point at Vadc axis  
	uint16_t O2_ADC_Analyze2;      //!< (mV) O2 Analyzer O2_ADC_Analyze2, the analyze point at Vadc axis
	uint16_t O2_Pct_Calib;         //!< (%) FO2x10 percentage at Calibration point
	uint16_t O2_Pct_Analyze1;      //!< (%) FO2x10 percentage at Analyze1 point
	uint16_t O2_Pct_Analyze2;      //!< (%) FO2x10 percentage at Analyze2 point
	uint16_t res;                  //!< (%) FO2x10 percentage at Analyze2 point
	O2_Serial_4Bytes O2_Analyzer_SN;  /* 4-Byte, 123456 saved as ascii 0x56, 0x34, 0x12 */
} PCMD_O2ANALYZER_RESP;
typedef struct
{
	uint8_t CRC_LSB;
	Serial_32Byte SN;
	uint8_t Prefix[10];
	NVD_date_t Date;       
	PCMD_O2ANALYZER_RESP O2_Analyzer;
}Mfg_Calibration_t;
/* System status structure */
typedef struct
{
	uint8_t backlight_on_req;
	uint8_t backlight_on;               
	uint8_t system_reboot_request;
	uint8_t GUI_Pause_timestamp;
	uint8_t BLE_status;
	uint8_t buzzer_on_req;
	uint8_t user_act_timestamp;
	uint8_t vibe_on_req;
	uint8_t user_GUI_timestamp;
	uint8_t O2_Analyzer_PreStage;
	uint8_t SystemPowerMode;
	uint8_t O2_Analyzer_Stage;
	uint8_t BLE_PassCode[6];
} L4X9_SysStat_t;
//======================================================================================
typedef struct
{
	uint8_t  CC_PO2A[MAX_TOTAL_TANK_NUM + 1];       /* 1-Byte x 7   Pressure of O2 */
	uint8_t  CC_FO2[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of O2 */
	Gas_Bit_t CC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
	Gas_Bit_t GSM_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
	TMT_NUM_t  CC_GASTMT[MAX_TOTAL_TANK_NUM + 1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
	uint8_t  Reserved17;                          /* 1-Byte Resered */
	uint8_t  CC_FHe[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of He */
	uint8_t  Reserved1F;
	uint8_t  OC_PO2A[MAX_TOTAL_TANK_NUM + 1];       /* 1-Byte x 7   Pressure of O2 */
	uint8_t  OC_FO2[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of O2 */
	Gas_Bit_t OC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
	TMT_NUM_t  OC_GASTMT[MAX_TOTAL_TANK_NUM + 1];/* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
	uint8_t  Reserved37;                  /* 1-Byte Resered */
	uint8_t  OC_FHe[MAX_TOTAL_TANK_NUM + 1];  /* 1-Byte x 7   Fractional of He */
	uint8_t  Reserved3F;
	uint8_t  SM_PO2A[MAX_TOTAL_TANK_NUM + 1];       /* 1-Byte x 7   Pressure of O2 */
	uint8_t  GSM_PO2A[MAX_TOTAL_TANK_NUM + 1];       /* 1-Byte x 7   Pressure of O2 */
	uint8_t  GAUGE_PO2A[MAX_TOTAL_TANK_NUM + 1];       /* 1-Byte x 7   Pressure of O2 */
	uint8_t  SM_FO2[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of O2 */
	uint8_t  GSM_FO2[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of O2 */
	uint8_t  GAUGE_FO2[MAX_TOTAL_TANK_NUM + 1];        /* 1-Byte x 7   Fractional of O2 */
	Gas_Bit_t SM_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
	Gas_Bit_t BO_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
	TMT_NUM_t  SM_GASTMT[MAX_TOTAL_TANK_NUM + 1];/* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
	uint8_t  Reserved57;                  /* 1-Byte Resered */
	uint8_t  SM_FHe[MAX_TOTAL_TANK_NUM + 1]; 
	uint8_t  BO_FO2[MAX_TOTAL_TANK_NUM + 1];
	uint8_t  BO_GASTMT[MAX_TOTAL_TANK_NUM + 1];
	uint8_t  BO_FHe[MAX_TOTAL_TANK_NUM + 1];
	uint8_t  BO_PO2A[MAX_TOTAL_TANK_NUM + 1];
	uint8_t  GSM_FHe[MAX_TOTAL_TANK_NUM + 1]; 
	uint8_t  GAUGE_FHe[MAX_TOTAL_TANK_NUM + 1]; 
	uint8_t  GSM_GASTMT[MAX_TOTAL_TANK_NUM + 1]; 
	uint8_t  GAUGE_GASTMT[MAX_TOTAL_TANK_NUM + 1];
	uint8_t  Reserved5F;
	uint8_t reserved[256 - 16 * 6 - 2]; // to make the whole structure size 16*n in the future
	uint8_t CRC_MSB;
	uint8_t CRC_LSB;
	uint8_t CurrGasNumber_OC;
	uint8_t CurrGasNumber_CC;
	uint8_t CurrGasNumber_SM;
	uint8_t CurrGasNumber_BO;
	uint8_t CurrGasNumber_GSM;
	uint8_t CurrGasNumber_GAUGE;
	uint8_t CurrTMT_Number_GSM;
	uint8_t CurrTMT_Number_GAUGE;
}TRIMIX_Settings_t;
typedef struct
{
	uint8_t CRC_LSB;
}Free_Settings_t;
typedef struct
{
	uint8_t CRC_LSB;
}Free_Records_t;
typedef struct
{
	uint8_t CRC_LSB;
}FLASH_Map_t;
typedef struct 
{
	uint8_t Timestamp;		
	uint8_t Pres;
	uint8_t Id[10];
} TankData_t;
/* Tick handler structure */
typedef struct
{
  uint8_t scheduled_tick;       // number of tick to be processed range 0-7;
} L4X9_TickHanlder_t;
typedef struct
{
  uint8_t CalibrationSamples;      
} EcRawData_struct_t;
typedef enum 
{
  TMT_NOT_AVAILABLE = 0x00,
  TMT_SEARCHING,
  TMT_BATT_LOW,
  TMT_BATT_GOOD
}TMT_Connection_t;
typedef enum Timer_Status
{
  TIMER_Reset = 0,
  TIMER_Pause,
  TIMER_Run,
}Timer_t;
typedef struct
{
  uint32_t Run_S;              // Run time of timer
  uint32_t TimeStamp_S;        // Time stamp from monotonic_clock
  Timer_t Status;               // 0: Reset;  1: Pause;  2: Run
  bool RunReq;                  
  bool PauseReq;
  bool ResetReq;
}TIMER_t;
typedef struct
{
	uint8_t GNSS_UtcTime_h;
	uint8_t GNSS_UtcTime_m;
	uint8_t GNSS_UtcTime_s;
	uint8_t GNSS_UtcTime_ms;
	uint8_t NoOfSatellites_used;
	uint8_t QualityIdx;
	uint8_t Longitude_DD;
	uint8_t Latitude_DD;
	uint8_t Latitude_Target_DD;
	uint8_t Longitude_Target_DD;
	int Target_Direction;
	uint8_t Target_Distance;
}GnssGGA_struct_t;
typedef enum
{
	LooseLink_OFF,      // TMT OFF Link
	LooseLink_LOOSE,    // TMT Loose Link  
	LooseLink_OK,       // TMT Linking OK
}LOOSE_LINK_t;

typedef struct 
{
  GPS_LocationRec_t GPS_Loc[8];      // Locations #1 to #8 (latest)
} GPS_WayFinder_t;

/*Stub prototype*/
uint8_t HAL_GPIO_ReadPin(uint8_t GPIOPort, uint16_t GPIO_Pin);
void Ec_Off(void);
void Ec_On(void);
void Ec_Calibrate(void);
void InitializePLAN(void);
void Display_PLANGF(void);
void BrowsePLAN(void);
uint8_t DEV_Board(void);
uint8_t ReadLog(uint16_t);
void HAL_ADC_MspInit(void *pContent);
void Predict_Deco_List(void);
bool ReadAndDisplaySlates(uint8_t Idx);
NVD_status_t FindSCUBA_TMT_Status(NVD_DIVEMODE_t, uint8_t);
TMT_NUM_t Find_TMT_Num_InSetting(void);
TMT_NUM_t Find_TMT_Num_InLinking(void);

#endif
