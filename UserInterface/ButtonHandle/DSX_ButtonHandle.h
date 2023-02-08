/*******************************************************************************
 * @file        : i330_ButtonHandle.h
 * @brief       : ........
 *
 * @version     XX.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Phu Thinh Nguyen, Pelagic Pressure Systems
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __DSX_BUTTON_H__
#define __DSX_BUTTON_H__


#define BUTTON_L_PIN                    BUTTON_TL_PIN
#define BUTTON_L_PORT                   BUTTON_TL_PORT
#define BUTTON_L_IRQ                    BUTTON_TL_IRQ
#define BUTTON_L_IRQHANDLER             BUTTON_TL_IRQHANDLER

#define BUTTON_M_PIN                    BUTTON_BL_PIN
#define BUTTON_M_PORT                   BUTTON_BL_PORT
#define BUTTON_M_IRQ                    BUTTON_BL_IRQ
#define BUTTON_M_IRQHANDLER             BUTTON_BL_IRQHANDLER

#define BUTTON_R_PIN                    BUTTON_BR_PIN
#define BUTTON_R_PORT                   BUTTON_BR_PORT
#define BUTTON_R_IRQ                    BUTTON_BR_IRQ
#define BUTTON_R_IRQHANDLER             BUTTON_BR_IRQHANDLER

#define KEYPRESS_TIMOUT  					6 //16 counts = 2s


#define HW_BUTTON_L             HW_BUTTON_G1
#define HW_BUTTON_M             HW_BUTTON_G0
#define HW_BUTTON_R             HW_BUTTON_G3

#define PROD_HW_BUTTON_L        HW_BUTTON_G0
#define PROD_HW_BUTTON_M        HW_BUTTON_G1
#define PROD_HW_BUTTON_R        HW_BUTTON_G3
#define PROD_HW_BUTTON_X        HW_BUTTON_G2

typedef struct
{
    uint32_t      N2Bar :1;               // 1-bit
    uint32_t      ASCBar :1;              // 1-bit
    uint32_t      CDTime :1;              // 1-bit
    uint32_t      Colon :1;               // 1-bit
    uint32_t      First2Digits :1;        // 1-bit
    uint32_t      Last2Digits :1;         // 1-bit
    uint32_t      AlarmFlash :1;          // 1-bit
    uint32_t      ErrorFlash :1;          // 1-bit
    uint32_t      Warning :1;             // 1-bit
    uint32_t      MaxDepth :1;            // 1-bit
    uint32_t      DiveTime :1;            // 1-bit
    uint32_t      DepthAlarm :1;          // 1-bit
    uint32_t      DTR :1;                 // 1-bit
    uint32_t      LowBatt1 :1;            // 1-bit
    uint32_t      LowBatt2 :1;            // 1-bit
    uint32_t      LowBatt3 :1;            // 1-bit

    uint32_t      LowO2   :1;             // 1-bit
    uint32_t      HighO2   :1;            // 1-bit
    uint32_t      DecoStopDepth   :1;     // 1-bit
    uint32_t      DecoStopTime   :1;      // 1-bit
    uint32_t      SafetyStopDepth   :1;   // 1-bit
    uint32_t      SafetyStopTime   :1;    // 1-bit
    uint32_t      DepthStopDepth   :1;    // 1-bit
    uint32_t      DepthStopTime   :1;     // 1-bit
    uint32_t      NoDecoTime   :1;        // 1-bit
    uint32_t      FreeViolation :1;       // 1-bit
    uint32_t      Reserved26   :1;        // 1-bit
    uint32_t      Reserved27   :1;        // 1-bit
    uint32_t      Reserved28   :1;        // 1-bit
    uint32_t      Reserved29   :1;        // 1-bit
    uint32_t      Reserved30   :1;        // 1-bit
    uint32_t      Reserved31   :1;        // 1-bit

} FlashUnion;    // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control

union FlashUNION
{
    FlashUnion    Bit;
    uint32_t      AllBits;            // Combination of all above
};
enum {
    KeyStatus_Idle, KeyStatus_Pressed, KeyStatus_Released, KeyStatus_Inused, KeyStatus_Scroll
};
enum {
    menu_index, data_setting
};
typedef enum {
    nothing, data_increase, data_decrease, short_press, long_press, doube_Longpress, doube_Shortpress
} buttonPress_e;
enum {
    goup, godown
};
enum {
    needupdate, updated
};
enum {
    Flashing, NoFlashing
};
enum {
    STAT_OFF, STAT_ON, STAT_SET
};
enum {
    CONFIRM_NO, CONFIRM_YES
};

enum {
    bypass_NONE,bypass_INFO2, bypass_ATL3, bypass_LOG1, bypass_10minDive, bypass_LOG3
};

typedef enum {
    TIMER_OFF,TIMER_PAUSE, TIMER_RUN,
} StopTimer_t;

enum {
    CDT_OFF, CDT_RUN
};

enum {
    AM, PM
};
enum
{
    GASES_00 = 0x0,
    GASES_01,
    GASES_02,
    GASES_03,
    GASES_04,
    GASES_05,
    GASES_06,
    GASES_MAX,
};
enum
{
    SIM_MODE_NEW_00 = 0x0,
    SIM_MODE_CONT_01,
    SIM_MODE_MAX,
};
typedef struct {
    uint8_t Key_Status;
    uint8_t Timer;
    uint8_t Key_Rolling;
    buttonPress_e DataType;
    uint8_t ResetTimer;
    uint8_t Cnt;            // added by YS, use Cnt for "button pushing actions information"
} Buttonstatus;
typedef enum
{
    GAS_SWITCH_PO2_OK = 0x0,      // 0.21 <= PO2 <= 1.60
    GAS_SWITCH_PO2_TOO_LOW,       // PO2 < 0.17
    GAS_SWITCH_PO2_HYPOXIC,       // 0.17 <= PO2 < 0.21
    GAS_SWITCH_PO2_TOO_HIGH       // PO2 > 1.60
} GAS_SWITCH_PO2_STAT_t;

extern uint8_t VAR_CONSER_SETPOINTS			;   //TEC, SPORT
extern uint8_t VAR_CONSER_SPORT_SETPOINTS		;    //HIGH/MEDIUM/LOW
extern uint8_t VAR_CONSER_TEC_GFLOW	        ;
extern uint8_t VAR_CONSER_TEC_GFHIGH	        ;
extern uint8_t VAR_CONSER_SPORT_GFLOW		    ;
extern uint8_t VAR_CONSER_SPORT_GFMED	        ;
extern uint8_t VAR_CONSER_SPORT_GFHIGH     	;
extern DSX_OPCODE_t DSX_Opcode;
extern DSX_OPCODE_t DSX_OPCODE;  // New Opcode for DSX
extern DSX_OPCODE_t pre_DSX_Opcode;
extern DSX_OPCODE_t NewOpcode;
extern SP_Switch_t     GUI_SP_Switch;
extern uint8_t         GUI_SP_HighVal;
extern uint8_t         GUI_SP_LowVal;
extern uint8_t         GUI_SP_CustomVal;
extern NVD_status_t    GUI_SP_CustomSwitch;     // for GUI displaying
extern NVD_status_t    GUI_SP_AutoHighSwitch;   // for GUI displaying
extern NVD_status_t    GUI_SP_AutoLowSwitch;    // for GUI displaying
extern uint8_t         GUI_SP_AutoHighMtVal;    // for GUI displaying
extern uint8_t         GUI_SP_AutoLowMtVal;     // for GUI displaying
extern uint16_t        GUI_SP_AutoHighFtVal;    // for GUI displaying
extern uint16_t        GUI_SP_AutoLowFtVal;     // for GUI displaying
extern uint8_t         GUI_SP_ActualVal;
extern NVD_DIVEMODE_t GUI_DIVE_Mode;            // GUI settings for DIVE_MODE

extern uint8_t GUI_OC_SM_PO2_Min;               // GUI settings for OCmin       // updated by YS 2022 1026
extern uint8_t GUI_OC_SM_PO2_Max;               // GUI settings for OCmax       // updated by YS 2022 1026
extern uint8_t GUI_OC_SM_PO2_Deco;              // GUI settings for OCdeco      // updated by YS 2022 1026
extern uint8_t GUI_BO_PO2_Min;                  // GUI settings for BOmin       // updated by YS 2022 1026
extern uint8_t GUI_BO_PO2_Max;                  // GUI settings for BOmax       // updated by YS 2022 1026
extern uint8_t GUI_BO_PO2_Deco;                 // GUI settings for BOdeco      // updated by YS 2022 1026

extern CONSV_TecSport_t GUI_CONSV_Switch;                 // GUI settings for Conserv: Tec or Sport
extern uint8_t GUI_TecGF_Hi;                           // GUI settings for TecGF_Hi
extern uint8_t GUI_TecGF_Lo;                           // GUI settings for TecGF_Lo
extern CONSV_Sport_t GUI_CONSV_Sport_Switch;    // GUI settings for Conserv: Tec or Sport
extern uint8_t GUI_SportGF_Hi;                           // GUI settings for SportGF_Hi
extern uint8_t GUI_SportGF_Lo;                           // GUI settings for SportGF_Lo
extern NVD_status_t GUI_SafetyStopMode;                // GUI settings for SafetyStopMode
extern uint8_t GUI_SafetyStopMin;                      // GUI settings for SafetyStopMin
extern uint16_t GUI_SS_DepthFt;                        // GUI settings for DepthAlarmFT
extern uint16_t GUI_SS_DepthM;                         // GUI settings for DepthAlarmM
extern uint8_t GUI_LastStopFt;	                        // GUI settings for LastStopFt
extern uint8_t GUI_LastStopM;	                        // GUI settings for LastStopMt
extern uint8_t GUI_SWITCH_AlarmAudible;                //USER_Set.SwitchSet.Bit.AlarmAudible      // 1-bit Alarm Audible Active   0: OFF (not audible)    1: ON: audible, to follow the rest of bit statuses.
extern uint8_t GUI_SWITCH_AlarmVibeOn;                 //USER_Set.SwitchSet.Bit.AlarmVibeOn       // 1-bit Alarm Vibration Active 0: OFF (not vibrate)    1: ON: vibrate, to follow the rest of bit statuses.
extern uint8_t GUI_SWITCH_AlarmLED;                    //USER_Set.SwitchSet.Bit.AlarmLED          // 1-bit Alarm LED is Active    0: OFF (no LED)         1: ON: LED, to follow the rest of bit statuses.
extern uint8_t GUI_SWITCH_BluetoothOn;                 //USER_Set.SwitchSet.Bit.BluetoothOn       // 1-bit Bluetooth Switch ON    0: OFF                  1: ON
extern uint8_t GUI_SWITCH_ConservativeOn;              //USER_Set.SwitchSet.Bit.ConservativeOn    // 1-bit Conservative Factor ON 0: OFF                  1: ON
extern uint8_t GUI_SWITCH_DeepStopOn;                  //USER_Set.SwitchSet.Bit.DeepStopOn        // 1-bit DeepStop is Active     0: OFF                  1: ON
extern uint8_t GUI_SWITCH_WaterContactOn;              //USER_Set.SwitchSet.Bit.WaterContactOn    // 1-bit WaterContact is Active 0: OFF                  1: ON
extern uint8_t GUI_SWITCH_ClockAlarm;                  //USER_Set.SwitchSet.Bit.ClockAlarm        // 1-bit ClockAlarm is Active   0: OFF                  1: ON
extern uint8_t GUI_SWITCH_NoFlyAlarm;                  //USER_Set.SwitchSet.Bit.NoFlyAlarm        // 1-bit NoFlyAlarm is Active   0: OFF                  1: ON
extern uint8_t GUI_SWITCH_AutoDimOn;                   //USER_Set.SwitchSet.Bit.AutoDimOn         // 1-bit AutoDim is Active      0:                      1:
extern uint8_t GUI_SWITCH_PowerSavingOn;               //USER_Set.SwitchSet.Bit.PowerSavingOn     // 1-bit PowerSaving is Active  0:                      1:
extern uint8_t GUI_SWITCH_HomeAway;                    //USER_Set.SwitchSet.Bit.HomeAway          // 1-bit HomeAway               0:

extern uint8_t GUI_SWITCH_CDT_Enable;                  //USER_Set.SwitchSet.Bit.CDT_Enable        // 1-bit CDT_Enable             0:                      1:
extern uint8_t GUI_SWITCH_WaterType;                   //USER_Set.SwitchSet.Bit.WaterType         // 1-bit WaterType              0:                      1:
extern uint8_t GUI_SWITCH_Backlight;                   //USER_Set.SwitchSet.Bit.Backlight         // 1-bit Backlight Active       0:                     1:
extern uint8_t GUI_SWITCH_SafetyStopOn;                //USER_Set.SwitchSet.Bit.SafetyStopOn      // 1-bit SafetyStopOn Active    0:
extern uint8_t GUI_SWITCH_DiverTimerState;             //USER_Set.SwitchSet.Bit.DiverTimerState   // 2-bit DiveTimerState         0: Stop (back to 0)     1: Pause             2: Run
extern uint8_t GUI_SWITCH_DiverTimerDisp;              //USER_Set.SwitchSet.Bit.DiverTimerDisp    // 1-bit DiveTimerDisplay       0: Hide                 1: Display to GUI
extern uint8_t GUI_PageIndex;          // The GUI Page Index to distinguish the Different Info/Data showning on the Same Page
extern uint8_t GUI_PageIndexMAX;       // The MAX of GUI_PageIndex
extern uint8_t GUI_MenuIndex;          // The GUI Menu Index to distinguish the Different Info/Data showning on the Same Page
extern uint8_t GUI_MenuIndexMAX;       // The MAX of GUI_MenuIndex
extern DSX_OPCODE_t BackupOpcode;
extern DSX_OPCODE_t OpcodeForR2s;
extern DSX_OPCODE_t OpcodeForL2s;
extern uint8_t UnderWaterFlat;
extern uint8_t AnyKeyPress;
extern uint8_t AutoDim_timout_cnt;
// GUI Variables for Alarms Menu (CC, OC, SM, Gauge-SM, Gauge)
extern NVD_status_t      GUI_DEPTHAL_STAT;       // GUI settings for DEPTHAL_STAT
extern uint16_t          GUI_DepthAlarmFT;       // GUI settings for DEPTHAL_FT
extern uint16_t          GUI_DepthAlarmM;        // GUI settings for DEPTHAL_M
extern NVD_status_t      GUI_DIVE_T_AL_STAT;     // GUI settings for DIVE_T_STAT (Off, On, Set)
extern uint8_t           GUI_DIVE_T_AL;          // GUI settings for DIVE_T_AL
extern NVD_status_t      GUI_TTS_AL_STAT;        // GUI settings for TTS_AL_STAT (Off, On, Set)
extern uint8_t           GUI_TTS_AL;             // GUI settings for TTS_AL
extern NVD_status_t      GUI_DTR_AL_STAT;        // GUI settings for DTR_AL_STAT (Off, On, Set)
extern uint8_t           GUI_DTR_AL;             // GUI settings for DTR_AL
extern NVD_status_t      GUI_TankP_AL_STAT;      // GUI settings for TankP_AL_STAT (Off, On, Set)
extern uint16_t          GUI_TankP_AL_PSI;       // GUI settings for TankP_AL_PSI_PSI
extern uint8_t           GUI_TankP_AL_BAR;       // GUI settings for TankP_AL_BAR_BAR
extern NVD_status_t      GUI_CC6P_AL_STAT;       // GUI settings for CC6P_AL_STAT (Off, On, Set)
extern uint16_t          GUI_CC6P_AL_PSI;        // GUI settings for CC6P_AL_PSI
extern uint8_t           GUI_CC6P_AL_BAR;        // GUI settings for CC6P_AL_BAR
extern NVD_status_t      GUI_TurnP_AL_STAT;      // GUI settings for TurnP_AL_STAT (Off, On, Set)
extern uint16_t          GUI_TurnP_AL_PSI;       // GUI settings for TurnP_AL_PSI
extern uint8_t           GUI_TurnP_AL_BAR;       // GUI settings for TurnP_AL_BAR
extern NVD_status_t      GUI_EndP_AL_STAT;       // GUI settings for EndP_AL_STAT (Off, On, Set)
extern uint16_t          GUI_EndP_AL_PSI;        // GUI settings for EndP_AL_PSI
extern uint8_t           GUI_EndP_AL_BAR;        // GUI settings for EndP_AL_BAR
extern NVD_status_t      GUI_SwitchP_AL_STAT;    // GUI settings for Switch_AL_STAT (Off, On, Set)
extern uint16_t          GUI_SwitchP_AL_PSI;     // GUI settings for Switch_AL_PSI
extern uint8_t           GUI_SwitchP_AL_BAR;     // GUI settings for Switch_AL_BAR
extern NVD_status_t      GUI_GF_AL_STAT;         // GUI settings for GF_AL_STAT(Off, On, Set)
extern uint8_t           GUI_GF_AL;              // GUI settings for GF_AL
extern NVD_status_t      GUI_N2_AL_STAT;            // GUI settings for N2_STAT (Off, On, Set)
extern uint8_t           GUI_N2_AL;              // GUI settings for N2_AL
extern NVD_status_t      GUI_END_AL_STAT;        // GUI settings for END_AL_STAT
extern uint16_t          GUI_END_AL_FT;          // GUI settings for END_AL_FT
extern float             GUI_END_AL_M;           // GUI settings for END_AL_M
extern NVD_status_t      GUI_WOB_AL_STAT;        // GUI settings for WOB_AL_STAT
extern uint16_t          GUI_WOB_AL_FT;          // GUI settings for WOB_AL_FT
extern float             GUI_WOB_AL_M;           // GUI settings for WOB_AL_M
extern NVD_status_t      GUI_ICD_AL_STAT;        // GUI settings for ICD_AL_STAT
extern NVD_status_t      GUI_O2_NARCOTIC_AL_STAT;
extern uint8_t GAS_ASSIGN_INDEX;   // 1 to 6, Gas 1 to 6
extern uint8_t MODE_ASSIGN_INDEX;  // 0 to 4, CC, OC, SM, GSM, GAUGE
extern LanguageSelect_t GUI_LANG_Select;
extern NVD_status_t  GUI_SWITCH_LCD_Flip;
extern NVD_YesNo_t  GUI_SWITCH_LCD_GTR_L_R;
extern NVD_status_t GUI_BRIGHTNESS_DIM_MODE;
extern uint16_t GUI_BRIGHTNESS_DIM_TIME;
extern uint8_t GUI_DIM_BRIGHT_LV;
extern NVD_DIVEMODE_t		DiveMode_Set;
extern User_Settings_t          USER_Set;

extern NVD_UNITS_t       GUI_Unit;             // for GUI display
extern NVD_WATER_t       GUI_WaterType;        // for GUI display
extern NVD_SAMPLETIME_t  GUI_SampleTime;       // for GUI display
extern NVD_status_t      GUI_BluetoothState;   // for GUI display
extern uint8_t           GUI_Welcome_Screen;	// for GUI display

extern uint8_t  GUI_MAINDISPLAY_3RD_ROW_LEFT;
extern uint8_t  GUI_MAINDISPLAY_3RD_ROW_RIGHT;
extern uint8_t  GUI_MAINDISPLAY_N2_OR_GF_BAR;
extern uint8_t  GUI_MAINDISPLAY_EXTRA_LARGE;
extern uint8_t MidNight;

extern uint16_t GUI_DIVE_SIMULATOR_NEW_CONT;
extern uint16_t GUI_DIVE_SIMULATOR_SAC_CuFt;
extern uint16_t GUI_DIVE_SIMULATOR_SAC_Ltr;
extern uint16_t GUI_DIVE_SIMULATOR_DEPTH_Ft;
extern uint16_t GUI_DIVE_SIMULATOR_DEPTH_Mt;
extern uint16_t GUI_DIVE_SIMULATOR_Time;
extern uint16_t GUI_DIVE_SIMULATOR_SP;
extern uint16_t GUI_DIVE_TIMELIMITS_Time;
extern uint16_t GUI_DIVE_TIMELIMITS_Depth;

extern uint8_t GUI_O2ANALYZER_FO2_SET;
//extern uint8_t GUI_O2ANALYZER_CELL_mV;
//extern float GUI_O2ANALYZER_SURF_PRES;
extern uint8_t GUI_O2ANALYZER_CALIB_FLAT;
extern uint8_t GUI_O2ANALYZER_FO2_CONFIRM_FLAT;
extern uint8_t GUI_O2ANALYZER_FO2_ASSIGN_FLAT;
extern NVD_DIVEMODE_t  GUI_O2ANALYZER_DIVEMODE_ASSIGN;

extern uint16_t GUI_Activation_mBAR;
extern float GUI_Activation_PSI;
extern float O2_SetForCalib_Pct;
extern union FlashUNION LCD_Flash;      /* 4-Byte LCD Flash Flags */
extern uint8_t BatteryStatus;           /* 1-Byte BatteryStatus for warning */
extern uint8_t GUI_GAS_SWITCH_Step;     // the flag to display GAS_SWITCH_MOD or GAS_SWITCH_TMT
extern TMT_NUM_t  GUI_TMT_Num_InSetting;       // The selected TMT Number during setting, NOT YET the one previously selected and saved onto EEPROM
extern uint8_t RollingKeyNonStop(void);
extern uint8_t UpKeyShortPressed(void);
extern uint8_t DownKeyShortPressed(void);
extern uint8_t UpKeyLongPressed(void);
extern uint8_t DownKeyLongPressed(void);
extern void LOG_Handle_PreviewPage(void);
extern uint8_t GoToPageFlag;
extern void AbortKeyInput(void);
extern int32_t DiverTimerControl(int8_t);
extern Buttonstatus Key_U, Key_D, Key_L, Key_M, Key_R;
extern uint8_t CDT_Set;                 // for Free Dive CDT setting during Surface Menu OFF (disabled), ON (enabled), SET (for setting)
extern uint8_t CDT_Run;                 // 0: stop;     1: run
extern uint8_t CDT_Alarm;               // CDT Alarm (FreeDive Only)                    0: Not Alarm;   1: Alarm Triggered
extern uint32_t GUI_ON_DelayCtr;        // Time Delay for displaying WELCOME S1 or Main Surf Page for a controlled time (8: 1 second / 16: 2 seconds / 40: 5 seconds, etc.
extern uint8_t BRIGHTNESS_LV_Cap;       // work for the temporary top cap during Low Battery (Yellow Battery for 50%, Red Battery for 30%)
extern uint8_t ProposedCURRENT_TANK_NUM;            // temporary CURRENT_TANK_NUM during Gas Switch, but before confirming and saving
extern SystemTimeDate_t      GUI_SetDateTime;

extern SP_Switch_t      GUI_SP_Switch;
extern uint8_t          GUI_SP_HighVal;
extern uint8_t          GUI_SP_LowVal;
extern uint8_t          GUI_SP_CustomVal;
extern NVD_status_t     GUI_SP_CustomSwitch;     // for GUI displaying
extern NVD_status_t     GUI_SP_AutoHighSwitch;   // for GUI displaying
extern NVD_status_t     GUI_SP_AutoLowSwitch;    // for GUI displaying
extern uint8_t          GUI_SP_AutoHighMtVal;    // for GUI displaying
extern uint8_t          GUI_SP_AutoLowMtVal;     // for GUI displaying
extern uint16_t         GUI_SP_AutoHighFtVal;    // for GUI displaying
extern uint16_t         GUI_SP_AutoLowFtVal;     // for GUI displaying
extern bool  GUI_Tank1_ON;
extern bool  GUI_Tank2_ON;
extern bool  GUI_Tank3_ON;
extern bool  GUI_Tank4_ON;
extern bool  GUI_Tank5_ON;
extern bool  GUI_Tank6_ON;
extern uint8_t GUI_ShowTankNum;
// extern TMT_Connection_t GUI_TMT_Battery[];     // 0: not linked,  1: linked,  2: connected
extern NVD_status_t    GUI_TMT_Status[8];      // On/Off/State of TMT#1~#6
extern uint8_t GUI_TMT_SerialNum[8][8];
extern uint8_t TMT_LINKED_GAS_INDEX;
extern NVD_DIVEMODE_t TMT_LINKED_MODE;
extern NVD_status_t GUI_SetPoints_Gas_CC[];
extern uint8_t GUI_FO2_Gas_CC[];
extern uint8_t GUI_FHe_Gas_CC[];
extern uint8_t GUI_PO2_Gas[];
extern TMT_NUM_t GUI_NumOfTMT_Gas_CC[];
extern NVD_status_t GUI_SetPoints_Gas_OC[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FO2_Gas_OC[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FHe_Gas_OC[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_PO2_Gas_OC[MAX_TOTAL_TANK_NUM+1];
extern TMT_NUM_t GUI_NumOfTMT_Gas_OC[MAX_TOTAL_TANK_NUM+1];
extern NVD_status_t GUI_SetPoints_Gas_SM[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FO2_Gas_SM[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FHe_Gas_SM[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_PO2_Gas_SM[MAX_TOTAL_TANK_NUM+1];
extern TMT_NUM_t GUI_NumOfTMT_Gas_SM[MAX_TOTAL_TANK_NUM+1];
extern NVD_status_t GUI_SetPoints_Gas_BO[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FO2_Gas_BO[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_FHe_Gas_BO[MAX_TOTAL_TANK_NUM+1];
extern uint8_t GUI_PO2_Gas_BO[MAX_TOTAL_TANK_NUM+1];
extern TMT_NUM_t GUI_NumOfTMT_Gas_BO[MAX_TOTAL_TANK_NUM+1];
extern int8_t  GUI_COMP_DEDLIN_DEG;
extern NVD_dateformat_t  GUI_MMDD_Format;      // 0: MMDD      1: DDMM
extern NVD_timeformat_t  GUI_12H24H_Format;    // 0: 12Hr      1:24Hr
extern int16_t    GUI_CompassReferenceHeadingDegree;  // the degree value of Compass Reference Heading dot
extern int16_t    GUI_CompassReverseHeadingDegree;    // the degree value of Compass Reverse Heading dot
extern int8_t     GUI_CompassHeadingStat;             // CompassHeadingStat: 0: Normal, 1: RefHeading, 2: RevHeading
extern bool    GUI_CompassReferenceHeadingOn;          // the true/false flag for displaying Compass Green Color Reference Heading dot
extern bool    GUI_CompassReverseHeadingOn;            // the true/false flag for displaying Compass Green Color Reverse Heading dot
extern uint32_t CounterCaliCompass;
//extern void EE2GUI_LogData();
extern void GUI2EE_LogData();
extern uint16_t GasSwitchGetPO2A(void);
extern void Check3rdRowAfterDiveModeSwitch(void);
extern TMT_NUM_t Find_TMT_Num_InSetting(void);
extern unsigned int log01HighlightItem_i;

#define DIVE_MODE		USER_Set.DiveMode
#define RETURN_DIVE_MODE        USER_Set.ReturnDiveMode
#define CC_MODE			(DIVE_MODE==NVD_MDCC)
#define OC_MODE			(DIVE_MODE==NVD_MDOC)
#define SM_MODE			(DIVE_MODE==NVD_MDSM)
#define GSM_MODE	        (DIVE_MODE==NVD_MDGSM)
#define GAUGE_MODE		(DIVE_MODE==NVD_MDGAUGE)
#define BO_MODE                 (DIVE_MODE==NVD_MDBO)

#define TITLESCOLOR			USER_Set.TitleColor     // CYAN, GREEN, WHITE, ORANGE, MAGENTA  = 0....4
#define LANGUAGE_LIST		USER_Set.LangSelec      //ENGLISH, DEUTSCH, FRAN�AIS....
#define FLIPSCREEN          USER_Set.SwitchSet.Bit.LCD_Flip  //OFF, ON
//SP MENU
#define SP_CURRENT_Val          SCUBA_Set.SP_Current
#define HIGH_SP_Val		SCUBA_Set.SP_SetHigh            // 0.40 - 1.50 (incr.: 0.1)
#define LOW_SP_Val		SCUBA_Set.SP_SetLow             // 0.40 - 1.50 High SP (incr.: 0.1)
#define SP_SWITCH               SCUBA_Set.SP_Switch             // 1: High SP;  0: Low SP;  2: Custom
#define CUSTOM_SP_STAT		SCUBA_Set.SP_CustomSW	        // OFF, ON, SET
#define CUSTOM_SP_Val		SCUBA_Set.SP_SetCustomer        // 0.40 - 1.50 (incr.: 0.1)
#define AUTO_HIGH_SP_STAT	SCUBA_Set.Alarm2Set.Bit.SP_AutoHi  // OFF, ON, SET
#define AUTO_LOW_SP_STAT	SCUBA_Set.Alarm2Set.Bit.SP_AutoLo  // OFF, ON, SET
#define SP_AUTOHIGH_M		SCUBA_Set.SP_AutoHighM	 		// 20 - 420 FT (6 - 130 M) (incr.: 5 FT, 1 M)
#define SP_AUTOLOW_M		SCUBA_Set.SP_AutoLowM    		// 20 - 420 FT (6 - 130 M) (incr.: 5 FT, 1 M)
#define SP_AUTOHIGH_FT		SCUBA_Set.SP_AutoHighFT  		// 20 - 420 FT (6 - 130 M) (incr.: 5 FT, 1 M)
#define SP_AUTOLOW_FT		SCUBA_Set.SP_AutoLowFT   		// 20 - 420 FT (6 - 130 M) (incr.: 5 FT, 1 M)

//SP BAILOUT

#define OC_SM_MIN_PO2		SCUBA_Set.OCmin         //  16 - 29  (incr.: 1),  display = data/100
#define OC_SM_MAX_PO2		SCUBA_Set.OCmax         // 100 - 199 (incr.: 1),  display = data/100
#define OC_SM_DECO_PO2		SCUBA_Set.OCdeco        // 100 - 199 (incr.: 1),  display = data/100

#define BO_MIN_PO2	        SCUBA_Set.BOmin         //  16 - 29  (incr.: 1),  display = data/100
#define BO_MAX_PO2	        SCUBA_Set.BOmax         // 100 - 199 (incr.: 1),  display = data/100
#define BO_DECO_PO2	        SCUBA_Set.BOdeco        // 100 - 199 (incr.: 1),  display = data/100

//SP CONSERVATISM

#define CONSER_SETPOINTS			SCUBA_Set.Consv.ConservMode   // TEC, SPORT
#define CONSER_SPORT_SETPOINTS			SCUBA_Set.Consv.ConservSportMode     // HIGH, MEDIUM and LOW

#define CONSER_TEC_GFLOW	        	SCUBA_Set.TEC_GF_Lo     // TEC GF Lo Value (customer setting)
#define CONSER_TEC_GFHIGH	        	SCUBA_Set.TEC_GF_Hi     // TEC GF Hi Value (customer setting) 
#define CONSER_SPORT_GFLOW		        SCUBA_Set.GF_Low        // SPORT GF Lo Value (fixed at 30. 35, 90)
#define CONSER_SPORT_GFHIGH     		SCUBA_Set.GF_High       // SPORT GF Hi Value (fixed at 70. 80, 90)

#define TANK_PRESS_STAT				SCUBA_Set.Alarm2Set.Bit.TankP   // OFF = 0, ON = 1 (SET no need to save, only showing at GUI)
#define TANK_PRESS_BAR				SCUBA_Set.TankPressBAR	        // 300 - 3000 PSI (20 - 200 BAR), (incr. 100 PSI, 5 BAR)
#define TANK_PRESS_PSI				SCUBA_Set.TankPressPSI	        // 300 - 3000 PSI (20 - 200 BAR), (incr. 100 PSI, 5 BAR)

#define CC6_PRESS_STAT				SCUBA_Set.Alarm2Set.Bit.CC6P	// OFF = 0, ON = 1 (SET no need to save, only showing at GUI)
#define CC6_PRESS_BAR				SCUBA_Set.CC6PressBAR	        // 300 - 3000 PSI (20 - 200 BAR), (incr. 100 PSI, 5 BAR)
#define CC6_PRESS_PSI				SCUBA_Set.CC6PressPSI	        // 300 - 3000 PSI (20 - 200 BAR), (incr. 100 PSI, 5 BAR)

#define TURN_PRESS_STAT				SCUBA_Set.Alarm2Set.Bit.TurnP   // OFF = 0, ON = 1 (SET no need to save, only showing at GUI)
#define TURN_PRESS_BAR				SCUBA_Set.TurnPressBAR	        // 1000 - 3000 PSI (70 - 200 BAR), (incr. 100 PSI, 5 BAR)
#define TURN_PRESS_PSI				SCUBA_Set.TurnPressPSI	        // 1000 - 3000 PSI (70 - 200 BAR), (incr. 100 PSI, 5 BAR)

#define END_PRESS_STAT				SCUBA_Set.Alarm2Set.Bit.EndP	// OFF = 0, ON = 1 (SET no need to save, only showing at GUI)
#define END_PRESS_BAR				SCUBA_Set.EndPressBAR	        // 300 - 1500 PSI (20 - 105 BAR), (incr. 100 PSI, 5 BAR)
#define END_PRESS_PSI				SCUBA_Set.EndPressPSI	        // 300 - 1500 PSI (20 - 105 BAR), (incr. 100 PSI, 5 BAR)

#define GF_ALARM_STAT				SCUBA_Set.Alarm2Set.Bit.GF	// OFF = 0, ON = 1 (SET no need to save)
#define GF_ALARM_DATA				SCUBA_Set.GF_Alarm	        // 20 - 89 (incr.: 1)

#define N2_ALARM_STAT				SCUBA_Set.Alarm2Set.Bit.N2	// OFF = 0, ON = 1 (SET no need to save, only showing at GUI)
#define N2_ALARM_DATA				SCUBA_Set.N2_Alarm	        // 70 - 99 (incr.: 1)

#define WELCOME_SCREEN_SETPOINTS		USER_Set.ScreenSet	// STANDARD, UPLOADED 1, UPLOADED 2, UPLOADED 3

#define  MAIN_CC_3RD_ROW_LEFT		        USER_Set.CC_3RowL	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, Dl PO2, FO2, (0 t0 9)
#define  MAIN_CC_3RD_ROW_RIGHT		        USER_Set.CC_3RowR	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, Dl PO2, FO2, (0 t0 9)

#define  MAIN_OC_3RD_ROW_LEFT		        USER_Set.OC_3RowL	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8)
#define  MAIN_OC_3RD_ROW_RIGHT		        USER_Set.OC_3RowR	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8)

#define  MAIN_SM_3RD_ROW_LEFT		        USER_Set.SM_3RowL	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8)
#define  MAIN_SM_3RD_ROW_RIGHT		        USER_Set.SM_3RowR	// BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8)

#define  MAINDISPLAY_N2_OR_GF_BAR		USER_Set.GForN2	        // 0: GF Bar, 1: N2 Bar
#define  MAINDISPLAY_EXTRA_LARGE		USER_Set.FontSize	// OFF/ DEPTH/DIVE TIME

//Dive Planner MENU
#define DIVE_SIMULATOR_MODE                     USER_Set.SIM_Mode       // 0: New Simulation;  1: Continue the Old Simulation
#define DIVE_SIMULATOR_DEPTH_FT			USER_Set.SIM_DepthFT	// 10 -  420 FT (3 -  130 M), (incr.: 1 FT, 1 M)
#define DIVE_SIMULATOR_DEPTH_M			USER_Set.SIM_DepthM	// 10 -  420 FT (3 -  130 M), (incr.: 1 FT, 1 M)
#define DIVE_SIMULATOR_TIME			USER_Set.SIM_Time	// 5 - 200 min (incr.: 1 min)
#define DIVE_SIMULATOR_SAC_CUFT			USER_Set.SIM_SAC_CuFt   // 0.40- 1.50 CUFT/MIN, (11 - 42 L/MIN), (incr.: 0.05 CUFT/MIN, 1 L/MIN,  display = data/100 
#define DIVE_SIMULATOR_SAC_LTR			USER_Set.SIM_SAC_Ltr    // 0.40- 1.50 CUFT/MIN, (11 - 42 L/MIN), (incr.: 0.05 CUFT/MIN, 1 L/MIN,  display = data/100 
#define DIVE_SIMULATOR_SP			USER_Set.SIM_SP         // 0.40- 1.50,  incr.: 0.10, ,  display = data/100 

/*========================================================================================================================*/
#define _2min		 				8*2*60 /*1sec = 8 count, 2min	= 960 count*/
#define _5sec		 				8*5
#define _10sec		 				8*10
#define _10min		 				8*60*10
#define _3sec		 				8*3
#define _2sec		 				8*2
#define _1sec		 				8

#define ENTERSETTINGMODE           0x01
//Data convert
#define DegreeConvert(x)             		((x) - 32)/1.8  //Convert from F to C degree
#define ImperialConvert(x)           		((x)*0.3048)//Convert from Imperial to Meter//((Metric)? ((X)*0.3048/16) : (X))
#define DataIsDiff(x,y)				 		(x!=y)
#define DataIsEqual(x,y)			 		(x==y)
#define UpdateData(x,y)				 		(x=y)
#define Resetdata(x,y)				 		(x=0,y =0)
#define Maxdata(x,y)				 		((x<y)?(x=x):(x=y))
#define LOW_BYTE(x)     					((unsigned char)((x)&0xFF))
#define HIGH_BYTE(x)    					((unsigned char)(((x)>>8)&0xFF))
#define LOW_NIBBLE(x)     					((x)&0x0F  )
#define HIGH_NIBBLE(x)     					(((x)&0xF0)>>4)

#define SetBit(number,bit) 					(number|=(1<<bit))
#define ClearBit(number,bit) 				(number&=(~(1<<bit)))
#define ToggleBit(number,bit) 				(number = number ^ (1<<bit))
#define ReadBit(number,bit) 				((number&=(1<<bit))?1:0)
#define SwapData(data,b,c) 					(((data) == (b)) ? (c) : (b))

#define retHour(x)           				((x)/3600)
#define retMin(x)           				((x%3600)/60)
#define retSec(x)           				((x%3600)%60)
#define CtoFDegree(x)           			((x)*1.8+32)
#define FtoCDegree(x)           			(((x)-32)*5/9)

#define Update_datatype(x) 					(x == DataDec)? data_decrease:data_increase;
#define ToggleData(number) 					(number = !number)

#define Menu_ItemList(x)             		(x*0x10)
#define Menu_ItemSetting(x)             	(x*0x10+0x01)

#define PLAN_DEPTH             				PlanDepthSet
#define LCD_STAT  							lcd_Update_Stat   //need display in gui when (LCD_STAT == needupdate)

/*SET UTILITIES*/
#define BRIGHTNESS_LV						USER_Set.BacklightLevel
#define DIM_BRIGHT_LV                   	USER_Set.DimBacklightLevel
#define YELLOW_BRIGHTNESS_LV				USER_Set.YellowBacklightLevel
#define YELLOW_DIM_BRIGHT_LV            	USER_Set.YellowDimBacklightLevel
#define RED_BRIGHTNESS_LV					USER_Set.RedBacklightLevel
#define RED_DIM_BRIGHT_LV               	USER_Set.RedDimBacklightLevel
#define RED_BATT_THRESH                         2       // Battery < 2% --> Dim along with Red Battery icon
#define YELLOW_BATT_THRESH                      15      // Battery < 15% --> Dim along with Yellow Battery icon
#define BRIGHTNESS_MODE						USER_Set.BacklightMode
#define BRIGHTNESS_DIM_MODE					USER_Set.DimBacklightMode
#define BRIGHTNESS_OFF_TIME					USER_Set.BacklightOnTimeSec
#define BRIGHTNESS_DIM_TIME	        		USER_Set.BacklightDimTimeSec
#define TITLE_Color                     	USER_Set.TitleColor
#define LANG_Select                     	USER_Set.LangSelec
#define H2OTYPE								USER_Set.WaterType
#define UNITS								USER_Set.SwitchSet.Bit.Unit
#define BLUETOOTH_STAT					  	USER_Set.SwitchSet.Bit.BluetoothOn
#define SAMPLINGRATE					  	USER_Set.SamplingTime
#define SAFETYSTOP_STAT					  	SCUBA_Set.SafetyStopMode
#define SAFETYSTOP_TIME					  	SCUBA_Set.SafetyStopMin
#define SAFETYSTOP_DEPTH_FT				  	SCUBA_Set.SS_DepthFt
#define SAFETYSTOP_DEPTH_M				  	SCUBA_Set.SS_DepthM
#define DEEPSTOP_STAT				  	  	USER_Set.SwitchSet.Bit.DeepStopOn
#define CONSERVATIVE				  	  	SCUBA_Set.ConservDSAT
#define SWITCH_AlarmAudible             USER_Set.SwitchSet.Bit.AlarmAudible      // 1-bit Alarm Audible Active   0: OFF (not audible)    1: ON: audible, to follow the rest of bit statuses.       
#define SWITCH_AlarmVibeOn              USER_Set.SwitchSet.Bit.AlarmVibeOn       // 1-bit Alarm Vibration Active 0: OFF (not vibrate)    1: ON: vibrate, to follow the rest of bit statuses. 
#define SWITCH_AlarmLED                 USER_Set.SwitchSet.Bit.AlarmLED          // 1-bit Alarm LED is Active    0: OFF (no LED)         1: ON: LED, to follow the rest of bit statuses. 
#define SWITCH_BluetoothOn              USER_Set.SwitchSet.Bit.BluetoothOn       // 1-bit Bluetooth Switch ON    0: OFF                  1: ON
#define SWITCH_ConservativeOn           USER_Set.SwitchSet.Bit.ConservativeOn    // 1-bit Conservative Factor ON 0: OFF                  1: ON
#define SWITCH_DeepStopOn               USER_Set.SwitchSet.Bit.DeepStopOn        // 1-bit DeepStop is Active     0: OFF                  1: ON
#define SWITCH_WaterContactOn           USER_Set.SwitchSet.Bit.WaterContactOn    // 1-bit WaterContact is Active 0: OFF                  1: ON 
#define SWITCH_ClockAlarm               USER_Set.SwitchSet.Bit.ClockAlarm        // 1-bit ClockAlarm is Active   0: OFF                  1: ON
#define SWITCH_NoFlyAlarm               USER_Set.SwitchSet.Bit.NoFlyAlarm        // 1-bit NoFlyAlarm is Active   0: OFF                  1: ON
#define SWITCH_AutoDimOn                USER_Set.SwitchSet.Bit.AutoDimOn         // 1-bit AutoDim is Active      0:                      1: 
#define SWITCH_PowerSavingOn            USER_Set.SwitchSet.Bit.PowerSavingOn     // 1-bit PowerSaving is Active  0:                      1: 
#define SWITCH_HomeAway                 USER_Set.SwitchSet.Bit.HomeAway          // 1-bit HomeAway               0: 
#define SWITCH_DDMM_Format              USER_Set.SwitchSet.Bit.DDMM_Format       // 1-bit DateFormat             0: 
#define SWITCH_HR24_Format              USER_Set.SwitchSet.Bit.HR24_Format       // 1-bit TimeFormat             0: 
#define SWITCH_Unit                     USER_Set.SwitchSet.Bit.Unit              // 1-bit Unit                   0: 
#define SWITCH_CDT_Enable               USER_Set.SwitchSet.Bit.CDT_Enable        // 1-bit CDT_Enable             0:                      1:       
#define SWITCH_WaterType                USER_Set.SwitchSet.Bit.WaterType         // 1-bit WaterType              0:                      1: 
#define SWITCH_Backlight                USER_Set.SwitchSet.Bit.Backlight         // 1-bit Backlight Active       0:                     1: 
#define SWITCH_LCD_Flip                 USER_Set.SwitchSet.Bit.LCD_Flip          // 1-bit reserved               0: LCD No Flip          1: LCD Flip 
#define SWITCH_LCD_GTR_L_R              USER_Set.SwitchSet.Bit.GTRforLnR         // 1-bit reserved               0: OFF			         1: ON

/*SET ALARM*/
#define VGM_DEPTHAL_STAT        SCUBA_Set.AlarmSet.Bit.DepthMax
#define VGM_DEPTHAL_FT          426
#define VGM_DEPTHAL_M           (uint16_t)(CONST_FT_TO_M*VGM_DEPTHAL_FT)
#define DEPTHAL_STAT         	SCUBA_Set.AlarmSet.Bit.DepthSet
#define DEPTHAL_FT         	SCUBA_Set.DepthAlarmFT
#define DEPTHAL_M         	SCUBA_Set.DepthAlarmM
#define DIVE_T_AL_STAT          SCUBA_Set.AlarmSet.Bit.DiveTime
#define DIVE_T_AL               SCUBA_Set.EDT_Alarm
#define TTS_AL_STAT             SCUBA_Set.Alarm2Set.Bit.TTS_T
#define TTS_AL                  SCUBA_Set.TTS_min
#define DTR_AL_STAT             SCUBA_Set.AlarmSet.Bit.DiveDTR
#define DTR_AL                  SCUBA_Set.DTR_Alarm

#define TankP_AL_STAT           SCUBA_Set.Alarm2Set.Bit.TankP
#define TankP_AL_PSI            SCUBA_Set.TankPressPSI
#define TankP_AL_BAR            SCUBA_Set.TankPressBAR
#define CC6P_AL_STAT            SCUBA_Set.Alarm2Set.Bit.CC6P
#define CC6P_AL_PSI             SCUBA_Set.CC6PressPSI
#define CC6P_AL_BAR             SCUBA_Set.CC6PressBAR
#define TurnP_AL_STAT           SCUBA_Set.Alarm2Set.Bit.TurnP
#define TurnP_AL_PSI            SCUBA_Set.TurnPressPSI
#define TurnP_AL_BAR            SCUBA_Set.TurnPressBAR
#define EndP_AL_STAT            SCUBA_Set.Alarm2Set.Bit.EndP
#define EndP_AL_PSI             SCUBA_Set.EndPressPSI
#define EndP_AL_BAR             SCUBA_Set.EndPressBAR

#define SwitchP_AL_STAT         SCUBA_Set.Alarm2Set.Bit.SwitchP
#define SwitchP_AL_PSI          SCUBA_Set.SwitchP_PSI
#define SwitchP_AL_BAR          SCUBA_Set.SwitchP_BAR

#define GF_AL_STAT              SCUBA_Set.Alarm2Set.Bit.GF
#define GF_AL                   SCUBA_Set.GF_Alarm
#define N2_AL_STAT              SCUBA_Set.Alarm2Set.Bit.N2
#define N2_AL                   SCUBA_Set.N2_Alarm

#define END_AL_STAT             SCUBA_Set.Alarm2Set.Bit.End
#define END_AL_FT               SCUBA_Set.End_AL_Ft
#define END_AL_dM               SCUBA_Set.End_AL_dM
#define WOB_AL_STAT             SCUBA_Set.Alarm2Set.Bit.WOB
#define WOB_AL_FT               SCUBA_Set.Wob_AL_Ft
#define WOB_AL_dM               SCUBA_Set.Wob_AL_dM
#define ICD_AL_STAT             SCUBA_Set.Alarm2Set.Bit.ICD
#define NARCOTIC_AL_SW          SCUBA_Set.Alarm2Set.Bit.Narcotic

#define N2BAR_AL         			  	SCUBA_Set.TLBG_Alarm
#define ASCBAR_AL         			  	SCUBA_Set.ASCBG_Alarm
#define DTR_AL         			  	  	SCUBA_Set.DTR_Alarm
#define DIVE_T_AL         			  	SCUBA_Set.EDT_Alarm

/*SET GAS*/
#define	FO2_GAS2							SCUBA_Set.FO2A[TANK2]
#define	PO2_GAS2							SCUBA_Set.PO2A[TANK2]
#define	FO2_GAS3							SCUBA_Set.FO2A[TANK3]
#define	PO2_GAS3							SCUBA_Set.PO2A[TANK3]
#define	FO2_GASx							SCUBA_Set.FO2A[CURRENT_TANK_NUM]

#define GUI_IDLE_Sec            SystemTimers.CounterDWN1_s
#define GUI_IDLE_TIMER_Set(x)   SystemTimers.CounterDWN1_s=x

/*FREE MODE*/
#define	CDT_SET 		CDT_Set
#define	CDT_MIN			SCUBA_Set.CountDownMin
#define	CDT_SEC			SCUBA_Set.CountDownSec
#define FREE_CDT_ALARM_S   	CDT_SEC+60*CDT_MIN

#define CDT_TIMER               SystemTimers.CounterDWN1_s                // start counting UP from 0 when dive starts
#define CDT_TIMER_Reset()       SystemTimers.CounterDWN1_s=60*SCUBA_Set.CountDownMin+SCUBA_Set.CountDownSec   // call to reset Dive Timer or CounterUP1_s
#define CDT_TIMER_Enable        USER_Set.SwitchSet.Bit.CDT_Enable       // 0: Disable (back to 0)       1: Enable
#define CDT_TIMER_Run           CDT_Run                                 // 0: Stop                      1: Run
#define CDT_TIMER_Alarm         CDT_Alarm                               // 0: Not Trigger CDT Alarm     1: To Trigger CDT Alarm

#define FREE_ALARM_DIVE_T                               SCUBA_Set.FreeDiveEDT_S
#define FREE_ALARM_DEPTH1_FT   				SCUBA_Set.FreeDiveAlarm1_Ft
#define FREE_ALARM_DEPTH2_FT   				SCUBA_Set.FreeDiveAlarm2_Ft
#define FREE_ALARM_DEPTH3_FT   				SCUBA_Set.FreeDiveAlarm3_Ft

#define FREE_ALARM_DEPTH1_M   				SCUBA_Set.FreeDiveAlarm1_M
#define FREE_ALARM_DEPTH2_M   				SCUBA_Set.FreeDiveAlarm2_M
#define FREE_ALARM_DEPTH3_M   				SCUBA_Set.FreeDiveAlarm3_M

/*GAUGE MODE*/

#define GUI_SET_YEAR					GUI_SetDateTime.Year
#define GUI_SET_MONTH					GUI_SetDateTime.Month
#define GUI_SET_DAY					GUI_SetDateTime.Day
#define GUI_SET_HOUR					GUI_SetDateTime.Hour
#define GUI_SET_MINUTE					GUI_SetDateTime.Minute
#define GUI_SET_SECOND					GUI_SetDateTime.Second
#define AM_PM_FLAT					MidNight//GUI_SetDateTime.res    //0 = AM, 1 = PM	

#define DIVE_TIMER              SystemTimers.CounterUP1_s                // start counting UP from 0 when dive starts
#define DIVE_TIMER_Reset()      SystemTimers.CounterUP1_s=0              // call to reset Dive Timer or CounterUP1_s
#define DIVE_TIMER_State        GUI_DiverTimerState                         // 0: Stop (back to 0)     1: Pause             2: Run
#define DIVE_TIMER_Display      GUI_DiverTimerDisp    // 1: to Display Dive Timer,   or 0: to hide

/*DIVE MODE*/
#define DIVEMODE_SET		        DiveMode_Set

#define ROLLINGKEY_NONSTOP              Key_U.Key_Rolling == KeyStatus_Scroll
#define TimeSet12h_Format           	(USER_Set.SwitchSet.Bit.HR24_Format == NVD_12HR)
#define GAS_SWITCH_MOD     0            // To show MOD at GAS SWITCH page
#define GAS_SWITCH_TMT     1            // To show TMT at GAS SWITCH page

DSX_OPCODE_t NewOpcode_Overwrite(DSX_OPCODE_t);
void decreaseCode(uint8_t * code, uint8_t max, uint8_t min);
void increaseCode(uint8_t * code, uint8_t max, uint8_t min);
uint8_t ReturnMenuList(uint8_t OC);
uint8_t retdaysofmonth(uint8_t month, uint8_t year);
void DSX_Button_Handle(void);
void DSX_OpcodeTask(void);
void DSX_IdleControl(void);
void DSX_GenerateLogic(void);
void DSX_OpcodeSwitch(void);       // will return OP for DSX, via the Opcode Matrix

void i330_Button_Handle(void);
void i330_OpcodeTask(void);
void i330_IdleControl(void);
void i330_SettingDataTask(uint8_t	curOPmode, uint8_t curMenstat, uint8_t*nextOPmode, uint8_t*nextMenstat);
uint8_t i330_GenerateLogic(uint8_t type);

void i330_Decode_Data(uint8_t OpCode);
void i330_SwitchOP(void);
float SettingData(float, float, float, float, uint8_t);
float RectifyData(float, float, float);
void updateSettingData(uint8_t *code, uint8_t *data_buf, uint8_t buf_len, uint8_t down_up);
bool StaySameOpcodeForNSec(uint8_t);
void i330_BypassCheck(uint8_t curOPmode, uint8_t curMenstat, uint8_t *nextOPmode, uint8_t *nextMenstat, uint8_t flat);
void i330_ExceptionCheck(uint8_t, uint8_t, uint8_t, uint8_t*, uint8_t*, uint8_t*, uint8_t);
void UI_Every125Exec(void);
void InitButtonDefault(void);

void UI_App(void);
uint8_t ret12Hfrom24H(uint8_t _24Hour, uint8_t * _12Hour, uint8_t * MidNight);
uint8_t ButtonIdleTime(uint32_t);
void SwitchDiveMode(NVD_DIVEMODE_t mode);
uint8_t  CheckTMTisLinked(TMT_NUM_t TMT_index);
uint8_t CheckTMTisDuplicate(TMT_NUM_t TMT_index, NVD_DIVEMODE_t * mode_linked, uint8_t * gas_linked);
uint8_t FindGasNumOfDiveMode(NVD_DIVEMODE_t mode);
uint8_t FindFO2OfDiveMode(NVD_DIVEMODE_t mode);
uint8_t FindFHeOfDiveMode(NVD_DIVEMODE_t mode);
uint8_t FindFO2OfGasNum(uint8_t num);
uint8_t Current_Tank_Num(void);
TMT_NUM_t Current_TMT_Num(void);
TMT_NUM_t SetGases_TMT_Num(TANK_NUM_t);
NVD_status_t CheckIfGasEnabled(uint8_t gas);
void ToRestoreBrightness(void);
void ResetButtonMemory(void);
bool REGISTER_Done(void);               // R1006 Added and orgnaized old similar code from then on
uint8_t find_CC_SP_Current(void);
DSX_OPCODE_t ReturnToDiveMain(void);
DSX_OPCODE_t ReturnToSurfMain(void);
DSX_OPCODE_t ReturnToMainPage(void);
void RestoreBrightnessAfterBattCharging(void);
GAS_SWITCH_PO2_STAT_t GasSwitchPO2_Stat(void);
float DilPO2Val(void);
/*******************************************************************************

    Refresh GUI to display new SET GAS information according to TRIMIX Data

*******************************************************************************/
void Update_GUI_GasInfo(void);


#endif /* __DSX_BUTTON_H__ */
