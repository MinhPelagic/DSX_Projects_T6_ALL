/*******************************************************************************
 * @file        : i330_ButtonHandle.c
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

/* Includes ------------------------------------------------------------------*/

#include "L4X9_includes.h"

/*i330 define start*/
uint8_t Key_Press_U = KeyStatus_Idle;
uint8_t Key_Press_D = KeyStatus_Idle;
uint8_t KeyTimer_U = 0;
uint8_t KeyTimer_D = 0;

Buttonstatus Key_L, Key_M, Key_R, Key_U, Key_D;

DSX_OPCODE_t DSX_OPCODE = (DSX_OPCODE_t) 0x1000;  // New Opcode for DSX
DSX_OPCODE_t NewOpcode;


uint16_t IdleTimer = 0;
//uint8_t DataRolling = FALSE;
//uint8_t buttonstatus = KeyStatus_Idle;
uint8_t key_task = menu_index;
uint8_t data_type = data_increase;

uint8_t SR_Buf[4] = {2,15,30,60};  //in second
uint8_t SS_DepthBuf_FT[3] = {10,15,20}; //FT
uint8_t SS_DepthBuf_M[4] = {3,4,5,6};	//M

/*i330 define end*/

/*need redefine again with real vars*/
uint8_t PlanDepthSet = 0;
uint8_t Brightness = 10;
uint8_t Conserv = 0;
uint8_t rolling_cnt = 0;
uint8_t lcd_Update_Stat = needupdate;
uint8_t lcd_FlashingFlat = Flashing;

uint8_t CC_BO_mode;

//uint32_t LastDiveTime_s = 0;
//uint16_t LastDiveMaxDpeth_ft = 0;

//uint8_t PLAN_index = 0;
//uint8_t PLAN_indexTop = 0;
//uint8_t PLAN_indexCapped = 0;

/* Collection of GUI Display Variables, For Adjustment on GUI and for saving to EE if EE_SaveReq() is called */
SystemTimeDate_t      GUI_SetDateTime;          // for GUI to display YY, MM, DD, HH, Min, etc during setting (not saved yet)

NVD_dateformat_t  GUI_MMDD_Format;      // 0: MMDD      1: DDMM
NVD_timeformat_t  GUI_12H24H_Format;    // 0: 12Hr      1:24Hr

SP_Switch_t     GUI_SP_Switch;
uint8_t         GUI_SP_HighVal;
uint8_t         GUI_SP_LowVal;
uint8_t         GUI_SP_CustomVal;
uint8_t         GUI_SP_AutoHighMtVal;    // for GUI displaying
uint8_t         GUI_SP_AutoLowMtVal;     // for GUI displaying
uint16_t        GUI_SP_AutoHighFtVal;    // for GUI displaying
uint16_t        GUI_SP_AutoLowFtVal;     // for GUI displaying
NVD_status_t    GUI_SP_CustomSwitch;     // for GUI displaying
NVD_status_t    GUI_SP_AutoHighSwitch;   // for GUI displaying
NVD_status_t    GUI_SP_AutoLowSwitch;    // for GUI displaying

NVD_UNITS_t       GUI_Unit;             // for GUI display
NVD_WATER_t       GUI_WaterType;        // for GUI display
NVD_SAMPLETIME_t  GUI_SampleTime;       // for GUI display
NVD_status_t      GUI_BluetoothState;   // for GUI display
uint8_t           GUI_Welcome_Screen;	// for GUI display

uint8_t         GUI_SP_ActualVal;

uint8_t GUI_DiverTimerState;
bool GUI_DiverTimerOn;
bool GUI_DiverTimerRun;
bool GUI_DiverTimerDisp;

uint8_t GPS_signal_stat = 0;    // 0: Get Current Location Loop,  1: Wayfinder Loop


bool  GUI_Tank1_ON;
bool  GUI_Tank2_ON;
bool  GUI_Tank3_ON;
bool  GUI_Tank4_ON;
bool  GUI_Tank5_ON;
bool  GUI_Tank6_ON;


TANK_NUM_t GUI_TankN_Linked;   // updated by real TANK sensing (TANK1 to TANK6)
//uint8_t GUI_ShowTMTid;

NVD_status_t    GUI_TMT_Status[8];      // On/Off/State of TMT#1~#6
uint8_t GUI_TMT_SerialNum[8][8];        // the first 8 is for TMT#1~6;  the second 8 is for 6 digits TMT Serial Numbers
uint8_t GUI_SN_Digit;                   // the digit index of SN during settings, starts from 6, 5, 4, ...2, 1.
#define GUI_isTMT1_LINKED         (bool)(GUI_TankN_Linked&0x01)
#define GUI_isTMT2_LINKED         (bool)(GUI_TankN_Linked&0x02)
#define GUI_isTMT3_LINKED         (bool)(GUI_TankN_Linked&0x04)
#define GUI_isTMT4_LINKED         (bool)(GUI_TankN_Linked&0x08)
#define GUI_isTMT5_LINKED         (bool)(GUI_TankN_Linked&0x10)
#define GUI_isTMT6_LINKED         (bool)(GUI_TankN_Linked&0x20)

uint8_t GUI_ShowTankNum = 1;

NVD_status_t GUI_SetPoints_Gas_CC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FO2_Gas_CC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FHe_Gas_CC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_PO2_Gas[MAX_TOTAL_TANK_NUM+1];
TMT_NUM_t GUI_NumOfTMT_Gas_CC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_TMT_LINKED[MAX_TOTAL_TANK_NUM+1];

NVD_status_t GUI_SetPoints_Gas_OC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FO2_Gas_OC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FHe_Gas_OC[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_PO2_Gas_OC[MAX_TOTAL_TANK_NUM+1];
TMT_NUM_t GUI_NumOfTMT_Gas_OC[MAX_TOTAL_TANK_NUM+1];

NVD_status_t GUI_SetPoints_Gas_SM[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FO2_Gas_SM[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FHe_Gas_SM[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_PO2_Gas_SM[MAX_TOTAL_TANK_NUM+1];
TMT_NUM_t GUI_NumOfTMT_Gas_SM[MAX_TOTAL_TANK_NUM+1];

NVD_status_t GUI_SetPoints_Gas_BO[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FO2_Gas_BO[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_FHe_Gas_BO[MAX_TOTAL_TANK_NUM+1];
uint8_t GUI_PO2_Gas_BO[MAX_TOTAL_TANK_NUM+1];
TMT_NUM_t GUI_NumOfTMT_Gas_BO[MAX_TOTAL_TANK_NUM+1];

int8_t  GUI_COMP_DEDLIN_DEG = 0;

uint8_t GUI_O2ANALYZER_FO2_SET = 21;
//uint8_t GUI_O2ANALYZER_CELL_mV = 46;
//float GUI_O2ANALYZER_SURF_PRES = 1012;

uint8_t GUI_O2ANALYZER_CALIB_FLAT = FALSE;
uint8_t GUI_O2ANALYZER_FO2_CONFIRM_FLAT = TRUE;
uint8_t GUI_O2ANALYZER_FO2_ASSIGN_FLAT = TRUE;
NVD_DIVEMODE_t  GUI_O2ANALYZER_DIVEMODE_ASSIGN = NVD_MDCC;
extern float CellNewToDepletedFactor;

uint8_t GAS_ASSIGN_INDEX = 1;   // 1 to 6, Gas 1 to 6
uint8_t MODE_ASSIGN_INDEX = 0;  // 0 to 4, CC, OC, SM, GSM, GAUGE

uint16_t GUI_GPS_WAYFINDER_id = 0;

uint8_t GUI_GAS_SWITCH_Step;       // the flag to display GAS_SWITCH_MOD or GAS_SWITCH_TMT

NVD_DIVEMODE_t TMT_LINKED_MODE;
uint8_t TMT_LINKED_GAS_INDEX;
uint8_t FHE_ZERO_WARNING = FALSE;
uint8_t TMT_LINKED_DUPLICATE;

uint8_t GUI_PageIndex;          // The GUI Page Index to distinguish the Different Info/Data showning on the Same Page
uint8_t GUI_PageIndexMAX;       // The MAX of GUI_PageIndex
uint8_t GUI_MenuIndex;          // The GUI Menu Index to distinguish the Different Info/Data showning on the Same Page
uint8_t GUI_MenuIndexMAX;       // The MAX of GUI_MenuIndex

NVD_DIVEMODE_t GUI_DIVE_Mode;                   // GUI settings for DIVE_MODE

uint8_t GUI_OC_SM_PO2_Min;              // GUI settings for OCmin       // updated by YS 2022 1026
uint8_t GUI_OC_SM_PO2_Max;              // GUI settings for OCmax       // updated by YS 2022 1026
uint8_t GUI_OC_SM_PO2_Deco;             // GUI settings for OCdeco      // updated by YS 2022 1026
uint8_t GUI_BO_PO2_Min;            // GUI settings for BOmin       // updated by YS 2022 1026
uint8_t GUI_BO_PO2_Max;            // GUI settings for BOmax       // updated by YS 2022 1026
uint8_t GUI_BO_PO2_Deco;           // GUI settings for BOdeco      // updated by YS 2022 1026

CONSV_TecSport_t GUI_CONSV_Switch;          // GUI settings for Conserv: Tec or Sport
uint8_t GUI_TecGF_Hi;                           // GUI settings for TecGF_Hi
uint8_t GUI_TecGF_Lo;                           // GUI settings for TecGF_Lo
CONSV_Sport_t GUI_CONSV_Sport_Switch;    // GUI settings for Conserv: Tec or Sport
uint8_t GUI_SportGF_Hi;                           // GUI settings for SportGF_Hi
uint8_t GUI_SportGF_Lo;                           // GUI settings for SportGF_Lo
NVD_status_t GUI_SafetyStopMode;            // GUI settings for SafetyStopMode
uint8_t GUI_SafetyStopMin = 0;                      // GUI settings for SafetyStopMin
uint16_t GUI_SS_DepthFt = 0;                        // GUI settings for DepthAlarmFT
uint16_t GUI_SS_DepthM = 0;                         // GUI settings for DepthAlarmM
uint8_t GUI_LastStopFt;	                        // GUI settings for LastStopFt
uint8_t GUI_LastStopM;	                        // GUI settings for LastStopMt


uint8_t GUI_SWITCH_AlarmAudible;                //USER_Set.SwitchSet.Bit.AlarmAudible      // 1-bit Alarm Audible Active   0: OFF (not audible)    1: ON: audible, to follow the rest of bit statuses.
uint8_t GUI_SWITCH_AlarmVibeOn;                 //USER_Set.SwitchSet.Bit.AlarmVibeOn       // 1-bit Alarm Vibration Active 0: OFF (not vibrate)    1: ON: vibrate, to follow the rest of bit statuses.
uint8_t GUI_SWITCH_AlarmLED;                    //USER_Set.SwitchSet.Bit.AlarmLED          // 1-bit Alarm LED is Active    0: OFF (no LED)         1: ON: LED, to follow the rest of bit statuses.
uint8_t GUI_SWITCH_BluetoothOn;                 //USER_Set.SwitchSet.Bit.BluetoothOn       // 1-bit Bluetooth Switch ON    0: OFF                  1: ON
uint8_t GUI_SWITCH_ConservativeOn;              //USER_Set.SwitchSet.Bit.ConservativeOn    // 1-bit Conservative Factor ON 0: OFF                  1: ON
uint8_t GUI_SWITCH_DeepStopOn;                  //USER_Set.SwitchSet.Bit.DeepStopOn        // 1-bit DeepStop is Active     0: OFF                  1: ON
uint8_t GUI_SWITCH_WaterContactOn;              //USER_Set.SwitchSet.Bit.WaterContactOn    // 1-bit WaterContact is Active 0: OFF                  1: ON
uint8_t GUI_SWITCH_ClockAlarm;                  //USER_Set.SwitchSet.Bit.ClockAlarm        // 1-bit ClockAlarm is Active   0: OFF                  1: ON
uint8_t GUI_SWITCH_NoFlyAlarm;                  //USER_Set.SwitchSet.Bit.NoFlyAlarm        // 1-bit NoFlyAlarm is Active   0: OFF                  1: ON
uint8_t GUI_SWITCH_AutoDimOn;                   //USER_Set.SwitchSet.Bit.AutoDimOn         // 1-bit AutoDim is Active      0:                      1:
uint8_t GUI_SWITCH_PowerSavingOn;               //USER_Set.SwitchSet.Bit.PowerSavingOn     // 1-bit PowerSaving is Active  0:                      1:
uint8_t GUI_SWITCH_HomeAway;                    //USER_Set.SwitchSet.Bit.HomeAway          // 1-bit HomeAway               0:

uint8_t GUI_SWITCH_CDT_Enable;                  //USER_Set.SwitchSet.Bit.CDT_Enable        // 1-bit CDT_Enable             0:                      1:
uint8_t GUI_SWITCH_WaterType;                   //USER_Set.SwitchSet.Bit.WaterType         // 1-bit WaterType              0:                      1:
uint8_t GUI_SWITCH_Backlight;                   //USER_Set.SwitchSet.Bit.Backlight         // 1-bit Backlight Active       0:                     1:


// GUI Variables for Alarms Menu (CC, OC, SM, Gauge-SM, Gauge)
NVD_status_t      GUI_DEPTHAL_STAT;       // GUI settings for DEPTHAL_STAT
uint16_t          GUI_DepthAlarmFT;       // GUI settings for DEPTHAL_FT
uint16_t          GUI_DepthAlarmM;        // GUI settings for DEPTHAL_M
NVD_status_t      GUI_DIVE_T_AL_STAT;     // GUI settings for DIVE_T_STAT (Off, On, Set)
uint8_t           GUI_DIVE_T_AL;          // GUI settings for DIVE_T_AL
NVD_status_t      GUI_TTS_AL_STAT;        // GUI settings for TTS_AL_STAT (Off, On, Set)
uint8_t           GUI_TTS_AL;             // GUI settings for TTS_AL
NVD_status_t      GUI_DTR_AL_STAT;        // GUI settings for DTR_AL_STAT (Off, On, Set)
uint8_t           GUI_DTR_AL;             // GUI settings for DTR_AL
NVD_status_t      GUI_TankP_AL_STAT;      // GUI settings for TankP_AL_STAT (Off, On, Set)
uint16_t          GUI_TankP_AL_PSI;       // GUI settings for TankP_AL_PSI_PSI
uint8_t           GUI_TankP_AL_BAR;       // GUI settings for TankP_AL_BAR_BAR
NVD_status_t      GUI_CC6P_AL_STAT;       // GUI settings for CC6P_AL_STAT (Off, On, Set)
uint16_t          GUI_CC6P_AL_PSI;        // GUI settings for CC6P_AL_PSI
uint8_t           GUI_CC6P_AL_BAR;        // GUI settings for CC6P_AL_BAR
NVD_status_t      GUI_TurnP_AL_STAT;      // GUI settings for TurnP_AL_STAT (Off, On, Set)
uint16_t          GUI_TurnP_AL_PSI;       // GUI settings for TurnP_AL_PSI
uint8_t           GUI_TurnP_AL_BAR;       // GUI settings for TurnP_AL_BAR
NVD_status_t      GUI_EndP_AL_STAT;       // GUI settings for EndP_AL_STAT (Off, On, Set)
uint16_t          GUI_EndP_AL_PSI;        // GUI settings for EndP_AL_PSI
uint8_t           GUI_EndP_AL_BAR;        // GUI settings for EndP_AL_BAR
NVD_status_t      GUI_SwitchP_AL_STAT;    // GUI settings for Switch_AL_STAT (Off, On, Set)
uint16_t          GUI_SwitchP_AL_PSI;     // GUI settings for Switch_AL_PSI
uint8_t           GUI_SwitchP_AL_BAR;     // GUI settings for Switch_AL_BAR
NVD_status_t      GUI_GF_AL_STAT;         // GUI settings for GF_AL_STAT(Off, On, Set)
uint8_t           GUI_GF_AL;              // GUI settings for GF_AL
NVD_status_t      GUI_N2_AL_STAT;            // GUI settings for N2_STAT (Off, On, Set)
uint8_t           GUI_N2_AL;              // GUI settings for N2_AL
NVD_status_t      GUI_END_AL_STAT;        // GUI settings for END_AL_STAT
uint16_t          GUI_END_AL_FT;          // GUI settings for END_AL_FT
float             GUI_END_AL_M;           // GUI settings for END_AL_M
NVD_status_t      GUI_WOB_AL_STAT;        // GUI settings for WOB_AL_STAT
uint16_t          GUI_WOB_AL_FT;          // GUI settings for WOB_AL_FT
float             GUI_WOB_AL_M;           // GUI settings for WOB_AL_M
NVD_status_t      GUI_ICD_AL_STAT;        // GUI settings for ICD_AL_STAT

NVD_status_t      GUI_O2_NARCOTIC_AL_STAT;// GUI settings for S297_ALARM_O2_NARCOTIC_SET

uint8_t GUI_MaxSlateNum = 0;           // Total number Slates saved on ExFLASH
uint8_t GUI_CurrSlateNum = 0;          // Current Slates saved on ExFLASH

// GUI Variables for Display Settings (CC, OC, SM, Gauge-SM, Gauge)
uint8_t GUI_BRIGHTNESS_LV;                // GUI Settings for BRIGHTNESS_LV
NVD_status_t GUI_BRIGHTNESS_DIM_MODE; // GUI Settings for BRIGHTNESS_DIM_MODE
uint16_t GUI_BRIGHTNESS_DIM_TIME;         // GUI Settings for BRIGHTNESS_DIM_TIME
uint8_t GUI_DIM_BRIGHT_LV;                // GUI Settings for DIM_BRIGHT_LV
LanguageSelect_t GUI_LANG_Select;         // GUI Settings for LANG_Select
NVD_status_t  GUI_SWITCH_LCD_Flip;        // GUI settings for LCD_Flip
NVD_YesNo_t  GUI_SWITCH_LCD_GTR_L_R;

uint8_t  GUI_MAINDISPLAY_3RD_ROW_LEFT;
uint8_t  GUI_MAINDISPLAY_3RD_ROW_RIGHT;
uint8_t  GUI_MAINDISPLAY_N2_OR_GF_BAR;
uint8_t  GUI_MAINDISPLAY_EXTRA_LARGE;

uint8_t GUI_LOG_DiveNumOfDay = 0;       // The Dive of Day of the LOG
uint8_t GUI_LOG_NumLast =  0;           // Total LOG number has been saved on EEPROM
uint8_t GUI_LOG_NumDisp = 0;            // The LOG Number for the one in Displaying
uint8_t GUI_LOG_Idx = 0;                // LOG GUI total cursor index (0 to (GUI_LOG_NumLast-1), total GUI_LOG_NumLast lines)
uint8_t GUI_LOG_PageIdx = 0;            // LOG GUI each page's cursor index (0 to 6, total 7 lines)
#define TITLE_Color                     USER_Set.TitleColor
#define LANG_Select                     USER_Set.LangSelec

uint16_t GUI_DIVE_SIMULATOR_NEW_CONT;
uint16_t GUI_DIVE_SIMULATOR_SAC_CuFt;
uint16_t GUI_DIVE_SIMULATOR_SAC_Ltr;
uint16_t GUI_DIVE_SIMULATOR_DEPTH_Ft;
uint16_t GUI_DIVE_SIMULATOR_DEPTH_Mt;
uint16_t GUI_DIVE_SIMULATOR_Time;
uint16_t GUI_DIVE_SIMULATOR_SP;
uint16_t GUI_DIVE_TIMELIMITS_Time;
uint16_t GUI_DIVE_TIMELIMITS_Depth;

int16_t    GUI_CompassReferenceHeadingDegree = 0;  // the degree value of Compass Reference Heading dot
int16_t    GUI_CompassReverseHeadingDegree = 0;    // the degree value of Compass Reverse Heading dot
int8_t     GUI_CompassHeadingStat = 0;                 // CompassHeadingStat: 0: Normal, 1: RefHeading, 2: RevHeading
bool    GUI_CompassReferenceHeadingOn = false;          // the true/false flag for displaying Compass Green Color Reference Heading dot
bool    GUI_CompassReverseHeadingOn = false;            // the true/false flag for displaying Compass Green Color Reverse Heading dot
MMC_Output_t MMC_Output_Original;

uint16_t GUI_Activation_mBAR;
float GUI_Activation_PSI;

NVD_timeformat_t      TimeFormat_set;
NVD_status_t		  BluetoothSet;
NVD_DIVEMODE_t		  DiveMode_Set;
uint8_t DVSTAT_Set = 0x10;
uint8_t CDT_Set = 0;            // CDT Setting at Surface for real three states 0: OFF,         1: ON,          2: SET
uint8_t CDT_Run = 0;            // CDT Control underwater (FreeDive Only)       0: stop;                        1: run
uint8_t CDT_Alarm = 0;          // CDT Alarm (FreeDive Only)                    0: No Trigger CDT Alarm;        1: To Trigger CDT Alarm

union FlashUNION LCD_Flash;      /* 4-Byte LCD Flash Flags */
uint8_t BatteryStatus = 0;       /* 1-Byte BatteryStatus for warning */
uint8_t BRIGHTNESS_LV_Cap;       // works for the temporary top cap during Low Battery (Yellow Battery for 50%, Red Battery for 30%)
uint8_t ProposedCURRENT_TANK_NUM;            // temporary CURRENT_TANK_NUM during Gas Switch, but before confirming and saving


DSX_OPCODE_t BackupOpcode;
DSX_OPCODE_t OpcodeForR2s = S2_SURFACE_MAIN;
DSX_OPCODE_t OpcodeForL2s;
uint8_t UnderWaterFlat = FALSE;
uint8_t AnyKeyPress =FALSE;
uint8_t AutoDim_timout_cnt = 0;

void EE2GUI_AlarmData(void);
void GUI2EE_AlarmData(void);
void UpdateGasStatus(void);
unsigned char SetGasGetFO2(unsigned char gasNumPos);
void CheckSlateMainPageStatus(DSX_OPCODE_t *opNewVal);
void Check3rdRowAfterDiveModeSwitch(void);

extern void Switch_To_SPlow(void);
extern void Switch_To_SPhigh(void);
extern void Switch_To_SPcustom(void);

extern STRING_LANG StrLang_Select[];

/*****************************************************
GoToPageFlag = 0    Do Nothing
GoToPageFlag = 1    Go to Surface Mode Main Page
GoToPageFlag = 2    Reserved
GoToPageFlag = 3    Reserved
******************************************************/
uint8_t GoToPageFlag = 0;

uint8_t DC_Inf_code12 = 0;
uint8_t DC_Inf_code34 = 0;
uint16_t DC_Inf_Timer = 0;
uint8_t DC_Inf_Clr_Confirm = CONFIRM_NO;
uint8_t _12H_hour = 12;
uint8_t MidNight = 0;  /*0 = AM, 1 = PM*/

uint8_t bypass_flat = bypass_NONE;
uint8_t SwitchOP_flat = false;
uint8_t Select_Gas = 1;
uint8_t Gas_timer = 0;
uint8_t rolling_support_flat = true;


uint8_t VAR_CONSER_SETPOINTS							;   //TEC, SPORT
uint8_t VAR_CONSER_SPORT_SETPOINTS	= CONSV_SPORT_LOW	;    //HIGH/MEDIUM/LOW
uint8_t VAR_CONSER_TEC_GFLOW	    = 10;        		;
uint8_t VAR_CONSER_TEC_GFHIGH       = 20;	       	 	;
uint8_t VAR_CONSER_SPORT_GFLOW		    				;
uint8_t VAR_CONSER_SPORT_GFMED	        				;
uint8_t VAR_CONSER_SPORT_GFHIGH     					;


uint16_t GPS_Loc_Num = 0;       // The GPS Location number for displaying, the one highlighted

/**
  * @brief	press/release button handle
  * @param	None
  * @retval None
  */

uint8_t data_update = 0;


int minor( int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}



uint8_t retdaysofmonth(uint8_t month, uint8_t year)/*year setting form 20 to 70*/
{
    const uint8_t MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint8_t day = 0;


    day = MONTHS[month-1];
    if((month ==2)&&(year%4==0)) {
        day = 29;
    }

    return day;
}

void InitButtonDefault(void)
{
    // Init Buttons
    Key_L.Key_Status = KeyStatus_Idle;
    Key_L.DataType = nothing;
    Key_L.Key_Rolling = KeyStatus_Idle;
    Key_L.Timer = KeyStatus_Idle;
    Key_L.ResetTimer = KeyStatus_Idle;

    Key_M.Key_Status = KeyStatus_Idle;
    Key_M.DataType = nothing;
    Key_M.Key_Rolling = KeyStatus_Idle;
    Key_M.Timer = KeyStatus_Idle;
    Key_M.ResetTimer = KeyStatus_Idle;

    Key_R.Key_Status = KeyStatus_Idle;
    Key_R.DataType = nothing;
    Key_R.Key_Rolling = KeyStatus_Idle;
    Key_R.Timer = KeyStatus_Idle;
    Key_R.ResetTimer = KeyStatus_Idle;

    // Old Init Buttons (for two-button i330T)
    Key_U.Key_Status = KeyStatus_Idle;
    Key_U.DataType = nothing;
    Key_U.Key_Rolling = KeyStatus_Idle;
    Key_U.Timer = KeyStatus_Idle;
    Key_U.ResetTimer = KeyStatus_Idle;

    Key_D.Key_Status = KeyStatus_Idle;
    Key_D.DataType = nothing;
    Key_D.Key_Rolling = KeyStatus_Idle;
    Key_D.Timer = KeyStatus_Idle;
    Key_D.ResetTimer = KeyStatus_Idle;

    HW_Buttons=0; // clear or ignore all button pushing during this wait, to clear all random button input data during SYS_SLEEP
}


void DSX_Button_Handle(void)
{

    if(DEV_Board())
    {
        if ((HW_Buttons & HW_BUTTON_L) || (HAL_GPIO_ReadPin(BUTTON_L_PORT, BUTTON_L_PIN) == 0x00)) {
            Key_L.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(BUTTON_L_PORT, BUTTON_L_PIN) == 0x01) && (Key_L.Key_Status == KeyStatus_Pressed)) {
            Key_L.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_L.Cnt = Key_L.Timer;
            Key_L.Timer = 0;
            Key_L.ResetTimer = 0;
        }
        else {}

        if ((HW_Buttons & HW_BUTTON_M) || (HAL_GPIO_ReadPin(BUTTON_M_PORT, BUTTON_M_PIN) == 0x00)) {
            Key_M.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(BUTTON_M_PORT, BUTTON_M_PIN) == 0x01) && (Key_M.Key_Status == KeyStatus_Pressed)) {
            Key_M.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_M.Cnt = Key_M.Timer;
            Key_M.Timer = 0;
            Key_M.ResetTimer = 0;
        }
        else {}

        if ((HW_Buttons & HW_BUTTON_R) || (HAL_GPIO_ReadPin(BUTTON_R_PORT, BUTTON_R_PIN) == 0x00)) {
            Key_R.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(BUTTON_R_PORT, BUTTON_R_PIN) == 0x01) && (Key_R.Key_Status == KeyStatus_Pressed)) {
            Key_R.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_R.Cnt = Key_R.Timer;
            Key_R.Timer = 0;
            Key_R.ResetTimer = 0;
        }
        else {}
    }
    else
    {
        if ((HW_Buttons & PROD_HW_BUTTON_L) || (HAL_GPIO_ReadPin(PROD_BUTTON_L_PORT, PROD_BUTTON_L_PIN) == 0x00)) {
            Key_L.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(PROD_BUTTON_L_PORT, PROD_BUTTON_L_PIN) == 0x01) && (Key_L.Key_Status == KeyStatus_Pressed)) {
            Key_L.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_L.Cnt = Key_L.Timer;
            Key_L.Timer = 0;
            Key_L.ResetTimer = 0;
        }
        else {}

        if ((HW_Buttons & PROD_HW_BUTTON_M) || (HAL_GPIO_ReadPin(PROD_BUTTON_M_PORT, PROD_BUTTON_M_PIN) == 0x00)) {
            Key_M.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(PROD_BUTTON_M_PORT, PROD_BUTTON_M_PIN) == 0x01) && (Key_M.Key_Status == KeyStatus_Pressed)) {
            Key_M.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_M.Cnt = Key_M.Timer;
            Key_M.Timer = 0;
            Key_M.ResetTimer = 0;
        }
        else {}

        if ((HW_Buttons & PROD_HW_BUTTON_R) || (HAL_GPIO_ReadPin(PROD_BUTTON_R_PORT, PROD_BUTTON_R_PIN) == 0x00)) {
            Key_R.Key_Status = KeyStatus_Pressed;
            data_update = 1;
        }
        else if ((HAL_GPIO_ReadPin(PROD_BUTTON_R_PORT, PROD_BUTTON_R_PIN) == 0x01) && (Key_R.Key_Status == KeyStatus_Pressed)) {
            Key_R.Key_Status = KeyStatus_Released;
            IdleTimer = 0;
            Key_R.Cnt = Key_R.Timer;
            Key_R.Timer = 0;
            Key_R.ResetTimer = 0;
        }
        else {}
    }

    HW_Buttons = 0;

    /*caculate the timing*/
    if (Key_L.Key_Status == KeyStatus_Pressed) {
        Key_L.Timer++; //1 count = 125ms, 2s = 16counts
        Key_L.ResetTimer++;
    }
    if (Key_M.Key_Status == KeyStatus_Pressed) {
        Key_M.Timer++; //1 count = 125ms, 2s = 16counts
        Key_M.ResetTimer++;
    }
    if (Key_R.Key_Status == KeyStatus_Pressed) {
        Key_R.Timer++; //1 count = 125ms, 2s = 16counts
        Key_R.ResetTimer++;
    }

    // the following is for i330R only
    if (Key_U.Key_Status == KeyStatus_Pressed) {
        Key_U.Timer++; //1 count = 125ms, 2s = 16counts
        Key_U.ResetTimer++;
    }
    if (Key_D.Key_Status == KeyStatus_Pressed) {
        Key_D.Timer++; //1 count = 125ms, 2s = 16counts
        Key_D.ResetTimer++;
    }
    // the above is for i330R only


    //}

}


DSX_OPCODE_t Opcode_Matrix(DSX_OPCODE_t L2_resp, DSX_OPCODE_t L_resp, DSX_OPCODE_t M_resp, DSX_OPCODE_t M2_resp, DSX_OPCODE_t R_resp, DSX_OPCODE_t R2_resp, DSX_OPCODE_t LR_resp, DSX_OPCODE_t LM2_resp, DSX_OPCODE_t Same_resp)
{
    DSX_OPCODE_t Opcode;

    Opcode = Same_resp;         // if no response

    if (Key_L.DataType == short_press)
    {
        Opcode = L_resp;
        Key_L.DataType = nothing;  //reset
    }
    else if ((Key_L.DataType == long_press)&&(Key_M.DataType != long_press)&&(Key_R.DataType != long_press)&&(Key_L.Key_Rolling != KeyStatus_Inused)&&(Key_L.Timer > KEYPRESS_TIMOUT)) /*long press key R*/
    {
        Opcode = L2_resp;
        if (L2_resp == ScrollDec)
        {
            Key_L.Key_Rolling = KeyStatus_Scroll;
            rolling_cnt++;

            if(0 == (rolling_cnt%1))
            {

            }
        }
        else
        {
            Key_L.Key_Rolling = KeyStatus_Inused;
        }
    }
    else if (Key_M.DataType == short_press)
    {
        Opcode = M_resp;
        Key_M.DataType = nothing;  //reset
    }
    else if ((Key_L.DataType != long_press)&&(Key_M.DataType == long_press)&&(Key_R.DataType != long_press)&&(Key_M.Key_Rolling != KeyStatus_Inused)&&(Key_M.Timer > KEYPRESS_TIMOUT)) /*long press key M*/
    {
        Opcode = M2_resp;
        if (M2_resp == ScrollInc)
        {
            Key_M.Key_Rolling = KeyStatus_Scroll;
            rolling_cnt++;

            if(0 == (rolling_cnt%1))
            {

            }
        }
        else
        {
            Key_M.Key_Rolling = KeyStatus_Inused;
        }
    }
    else if (Key_R.DataType == short_press)
    {
        Opcode = R_resp;
        Key_R.DataType = nothing;  //reset
    }
    else if ((Key_L.DataType != long_press)&&(Key_M.DataType != long_press)&&(Key_R.DataType == long_press)&&(Key_R.Key_Rolling != KeyStatus_Inused)&&(Key_R.Timer > KEYPRESS_TIMOUT)) /*long press key R*/
    {
        Opcode = R2_resp;

        Key_R.Key_Rolling = KeyStatus_Inused;

#if 0
        if (rolling_support_flat == TRUE)
        {
            Key_R.Key_Rolling = KeyStatus_Scroll;
            rolling_cnt++;

            if(0 == (rolling_cnt%1))
            {

            }
        }
        else
        {
            Key_R.Key_Rolling = KeyStatus_Inused;
        }
#endif

    }
    else
        Opcode = Same_resp;

    if(ButtonNoResponseCnt > 0)       // The Counter of Button Pressing (for No Response) until the button becoming responsive
    {
        ButtonNoResponseCnt--;

        Opcode = Same_resp;

        ResetButtonMemory();
    }

    return Opcode;
}

bool OpcodeChanged(uint16_t OldOpcode, uint16_t Newopcode)
{
    if(OldOpcode == Newopcode)
        return 0;
    else
        return 1;
}

uint16_t OPCODE_Matrix(DSX_OPCODE_t OldOpcode)
{
    uint8_t i;
    uint8_t daysofmonth = 0;

    DSX_OPCODE_t next_logic;

    switch(OldOpcode)
    {
    //L2_resp = return before,  L_resp = UP,  M_resp = DOWN,  M2_resp,  R_resp = ENTER,  R2_resp,
    case B1_BATT_CHARGE:
        NewOpcode = Opcode_Matrix( CheckConditions,  CheckConditions,	CheckConditions,     CheckConditions,     CheckConditions,     CheckConditions, OldOpcode, OldOpcode, 	OldOpcode);

        if(!BatteryCharging() || (NewOpcode == CheckConditions))
        {
            SystemStatus.user_GUI_timestamp = MonotonicClock_s;
            SystemSupplyMonitor.PreBattery_Percentage = 10;
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness

            if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
            {
                if(CC_MODE)
                    NewOpcode = DIVE_CC_MAIN;
                else if(OC_MODE||BO_MODE)
                    NewOpcode = DIVE_OC_MAIN;
                else if(SM_MODE)
                    NewOpcode = DIVE_SM_MAIN;
                else if(GSM_MODE)
                    NewOpcode = DIVE_GSM_MAIN;
                else if(GAUGE_MODE)
                    NewOpcode = DIVE_GAUGE_MAIN;
                else if(BO_MODE)
                    NewOpcode = DIVE_OC_MAIN;
            }
            else
            {
                if(CC_MODE||BO_MODE)
                    NewOpcode = S2_SURFACE_MAIN;
                else if(OC_MODE)
                    NewOpcode = S2_SURFACE_MAIN;
                else if(SM_MODE)
                    NewOpcode = SURFACE_SM_MAIN;
                else if(GSM_MODE)
                    NewOpcode = S2_SURFACE_MAIN;
                else if(GAUGE_MODE)
                    NewOpcode = SURFACE_GAUGE_MAIN;
            }
            GUI_SetBkColor(GUI_BLACK);
            GUI_Clear();
        }

        break;

    case W1_WELCOME:
        GUI_LANG_Select = LANG_Select;
        /*select Language for device*/

        GUI_LANG_LoadTextEx(_GetData, (void*)&StrLang_Select[LANGUAGE], LANGUAGE);
        GUI_LANG_SetLang(LANGUAGE);
        GUI_UC_SetEncodeUTF8();

        if(REGISTER_Done())
        {
            if(!StaySameOpcodeForNSec(5))   // for 5 seconds of idle time
            {
                // Read back from DEV_Rec EEPROM to DEV_Rec RAM for Compass Calibrated Data
                int8_t retry = NVD_EEPROM_READ_TIMEOUT;
                do{}while(!EE24CWxxX_ReadNBytes( NVD_DEVREC_LOC1, &DEV_Rec, sizeof(DEV_Rec))&& (retry-- > 0));      // Modified for R1006
                if(retry <= 0)
                {
                    ErrHandle_EE();
                }            
                PrepareForBacklightSetAgain();      // prepare Brightness setting again

                // migrate to next GUI page
                NewOpcode = MANUFACTURE_SCREEN;

                ResetButtonMemory();
                
                // St2Ble_PowerDown();         // R1006, added an St2Ble_PowerDown(); here to reset BLE chip
            }
        }
        else
        {
            NewOpcode = REGISTER_SCREEN;
        }

        break;

    case REGISTER_SCREEN:

        if(CheckTheBluetoothPasscodeDisplay())
            DSX_Opcode = DEVICE_BLUETOOTH_PASSCODE;
        else if(REGISTER_Done())
        {
            // Read back from DEV_Rec EEPROM to DEV_Rec RAM for Compass Calibrated Data
            //int8_t retry = NVD_EEPROM_READ_TIMEOUT;
            //do{}while(!EE24CWxxX_ReadNBytes( NVD_DEVREC_LOC1, &DEV_Rec, sizeof(DEV_Rec))&& (retry-- > 0));     		// Modified for R1006
            //if(retry <= 0)
            //{
            //    ErrHandle_EE();
            //}
            PrepareForBacklightSetAgain();      // prepare Brightness setting again

            EE_SaveReq(EE_DEVREC);            // save to EE
            // migrate to next GUI page
            NewOpcode = W1_WELCOME;
        }
        break;

    case MANUFACTURE_SCREEN:
        /*stay in 3 secs then go to Main surface*/
        if(!StaySameOpcodeForNSec(3))
        {
            NewOpcode = S2_SURFACE_MAIN;

            StaySameOpcodeForNSec(0);

            ResetButtonMemory();            
        }
        break;
    case W2_WAIT_MESSAGE:

        NewOpcode = Opcode_Matrix( W2_WAIT_MESSAGE,       OldOpcode,              ReturnToMainPage(),          OldOpcode,              OldOpcode,       OldOpcode,              OldOpcode,              OldOpcode,              OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    case S18_SP_SWITCH:
        BackupOpcode = S18_SP_SWITCH;
        if(CC_MODE) {
            // Read back from EERPOM for initial status or values to display
            if(SP_SWITCH == HIGH_SP)
                GUI_SP_Switch = HIGH_SP;
            else if(SP_SWITCH == LOW_SP)
                GUI_SP_Switch = LOW_SP;
            else
                GUI_SP_Switch = CUSTOM_SP;
            GUI_SP_HighVal            = HIGH_SP_Val;          // for GUI displaying
            GUI_SP_LowVal             = LOW_SP_Val;           // for GUI displaying
            GUI_SP_CustomVal          = CUSTOM_SP_Val;        			// for GUI displaying
            GUI_SP_CustomSwitch       = (NVD_status_t)CUSTOM_SP_STAT;  // for GUI displaying

            GUI_SP_AutoHighSwitch     = (NVD_status_t)AUTO_HIGH_SP_STAT;    // for GUI displaying
            GUI_SP_AutoLowSwitch      = (NVD_status_t)AUTO_LOW_SP_STAT;     // for GUI displaying
            GUI_SP_AutoHighMtVal      = SP_AUTOHIGH_M;        // for GUI displaying
            GUI_SP_AutoLowMtVal       = SP_AUTOLOW_M;         // for GUI displaying
            GUI_SP_AutoHighFtVal      = SP_AUTOHIGH_FT;       // for GUI displaying
            GUI_SP_AutoLowFtVal       = SP_AUTOLOW_FT;        // for GUI displaying SP_SWITCH_TO_LOW, SP_SWITCH_TO_HIGH,SP_SWITCH_TO_CUSTOM


            /*set actual sp*/
            if( GUI_SP_Switch == HIGH_SP) {
                GUI_SP_ActualVal = GUI_SP_HighVal;
            }
            else if( GUI_SP_Switch == LOW_SP) {
                GUI_SP_ActualVal = GUI_SP_LowVal;
            }
            else if( GUI_SP_Switch == CUSTOM_SP) {
                GUI_SP_ActualVal = GUI_SP_CustomVal;
            }

            /*go to switch menu*/

            if(GUI_SP_Switch == HIGH_SP)
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),         S_SLATE,  S21_GAS_SWITCH,         	OldOpcode,          SP_SWITCH_TO_LOW,    	ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
            else if(GUI_SP_Switch == LOW_SP)
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),         S_SLATE,  S21_GAS_SWITCH,         	OldOpcode,          SP_SWITCH_TO_HIGH,     	ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
            else
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),         S_SLATE,  S21_GAS_SWITCH,         	OldOpcode,          SP_SWITCH_TO_HIGH,  	ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        }


        else if(OC_MODE||SM_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), 	  S_SLATE,  S21_GAS_SWITCH, 	  	OldOpcode,	OldOpcode,	  		ReturnToMainPage(),		  OldOpcode,		  OldOpcode,		  S21_GAS_SWITCH);
        }
        break;

    case S21_GAS_SWITCH:
        //CURRENT_TANK_NUM = 1;//gas 1
        //CURRENT_TANK_NUM = GUI_TankN_Linked;
        OpcodeForL2s = S21_GAS_SWITCH;

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), 	  S18_SP_SWITCH,	  S62_DIVE_PLANNER, 	  OldOpcode,            SaveAndDone,	ReturnToMainPage(),			  OldOpcode,			  OldOpcode,			  OldOpcode);
        }
        else if(OC_MODE||SM_MODE) {

            NewOpcode = Opcode_Matrix( ReturnToMainPage(), 	  S_SLATE,		  S62_DIVE_PLANNER, 	  OldOpcode,		SaveAndDone,	ReturnToMainPage(),			  OldOpcode,			  OldOpcode,			  OldOpcode);
        }
        /*check which gas is need to switch?, npthinh*/
        if(NewOpcode == SaveAndDone) {
            NewOpcode = GAS_SWITCH_TO_GAS_0;
            BackupOpcode = S21_GAS_SWITCH;
            OpcodeForR2s = S2_SURFACE_MAIN;
        }

        break;

    case S62_DIVE_PLANNER:

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S21_GAS_SWITCH,         S27_LOG,                OldOpcode,          DIVE_PL_TIME_LIMITS,   ReturnToMainPage(),                  OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S27_LOG:

        if(CC_MODE||OC_MODE||SM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S62_DIVE_PLANNER,      S41_SET_MENU,      OldOpcode,  S28_LOG_DATA1,   ReturnToMainPage(),     OldOpcode, OldOpcode,   OldOpcode);
        else if(GAUGE_MODE||GSM_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),	S404_TMT_SWITCH,        S41_SET_MENU,	   OldOpcode,  S28_LOG_DATA1,   ReturnToMainPage(),     OldOpcode, OldOpcode,	OldOpcode);
        }

        else
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S404_TMT_SWITCH,       S41_SET_MENU,         OldOpcode,  S28_LOG_DATA1,   ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);

        if(NewOpcode==S28_LOG_DATA1)
        {
            /*Reset counter in display*/
            Log01PageResetCounterDisplay();
            /*Rtrieve the log data*/
            //EE2GUI_LogData();
        }

        break;

    case S41_SET_MENU:

        if(CC_MODE||OC_MODE||SM_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),      S27_LOG,        S185_INFO,	        OldOpcode,      S42_SET_GASES,	        ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        }
        else if(GSM_MODE||GAUGE_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), 	S27_LOG,	S432_DIVE_MODE,	        OldOpcode,	S105_ALARMS,	        ReturnToMainPage(),     OldOpcode,	OldOpcode,	OldOpcode);
        }
        break;

    case S185_INFO:

        if(CC_MODE||OC_MODE||SM_MODE) {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S41_SET_MENU,       S_SLATE,        OldOpcode,         S187_IM_MYINFO,         ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        }
        else if(GAUGE_MODE||GSM_MODE)
        {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S432_DIVE_MODE,     S_SLATE,        OldOpcode,         S187_IM_MYINFO,         ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S432_DIVE_MODE,     S_SLATE,        OldOpcode,         S187_IM_MYINFO,         ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        }
        break;

    case S_SLATE:
        HandleButton_MainMenu_SLATES(&NewOpcode, &OldOpcode);
        break;

    case S404_TMT_SWITCH:

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),       S_SLATE,           S27_LOG,                OldOpcode,              TMTSWITCH_TMT_SET,      ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S432_DIVE_MODE:

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),  S41_SET_MENU,           S185_INFO,	                OldOpcode,	DIVEMODE_SETPOINTS,	ReturnToMainPage(),        OldOpcode,      OldOpcode,	OldOpcode);
        break;
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // TMT SWITCH
    case TMTSWITCH_TMT_SET:
        HandleButton_TMTSwitch(&NewOpcode, &OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // LOG DATA
    case S28_LOG_DATA1:

        NewOpcode = Opcode_Matrix( S27_LOG,             DataInc,	DataDec,                OldOpcode,              S29_LOG_DATA2,          ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        /*Handle increase/decrease data*/
        HandleButtonLOG_1(&NewOpcode, &OldOpcode);
        break;

    case S29_LOG_DATA2:
        if(LogMenu_CheckLogIsEmpty()) {
            NewOpcode = S27_LOG;
        }
        else {
            NewOpcode = Opcode_Matrix( S28_LOG_DATA1,         OldOpcode,      OldOpcode,              OldOpcode,              S37_LOG_DATA3,        ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        }
        break;

    case S37_LOG_DATA3:

        NewOpcode = Opcode_Matrix( S29_LOG_DATA2,         OldOpcode,        OldOpcode,              OldOpcode,              S39_LOG_DATA4,          ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        if((NewOpcode==S39_LOG_DATA4)&&((Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDGSM)||(Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDGAUGE)))
        {

            NewOpcode=S28_LOG_DATA1;
        }

        if((Log_Data.AlarmOccured.Bit.SetupVIOLATION == true)&&(NewOpcode==S39_LOG_DATA4))
        {
            NewOpcode=S28_LOG_DATA1;
        }

        break;

    case S39_LOG_DATA4:

        NewOpcode = Opcode_Matrix( S37_LOG_DATA3,         OldOpcode,        OldOpcode,              OldOpcode,              S36_LOG_DATA5,          ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S36_LOG_DATA5:

        NewOpcode = Opcode_Matrix( S39_LOG_DATA4,         OldOpcode,          OldOpcode,              OldOpcode,              S28_LOG_DATA1,        ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        if((NewOpcode==S39_LOG_DATA4)&&((Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDGSM)||(Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDGAUGE)))
            NewOpcode=S37_LOG_DATA3;
        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET MENU
    case S42_SET_GASES:
        BackupOpcode = S42_SET_GASES;

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S41_SET_MENU, S161_DISPLAY_SETTINGS,  S53_SET_SP, OldOpcode, SETGASES_SET_CC_GASES, 		ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);

            GUI_SetPoints_Gas_CC[6] = NVD_ON;
            TRIMIX_Set.CC_Active.Gas6 = GUI_SetPoints_Gas_CC[6];
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S41_SET_MENU, S161_DISPLAY_SETTINGS,  S_DIVE_SETTINGS, OldOpcode, S70_SET_GAS_01, 	ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        }

        if(NewOpcode==S70_SET_GAS_01)   // read back from EEPROM
        {
            GUI_ShowTankNum = 1;

            UpdateGasStatus();
        }
        break;


    case SETGASES_SET_CC_GASES:
        BackupOpcode = SETGASES_SET_CC_GASES;
        NewOpcode = Opcode_Matrix( S42_SET_GASES, SETGASES_O2_ANALYZER, SETGASES_SET_BO_GASES, OldOpcode, S70_SET_GAS_01, ReturnToMainPage(),  OldOpcode, OldOpcode, OldOpcode);

        if(DIVE_MODE == NVD_MDBO)
        {
            DIVE_MODE = NVD_MDCC;       // switch back to CC mode before go diving or other surface settings
            RETURN_DIVE_MODE = NVD_MDCC;// switch back to CC mode before go diving or other surface settings
            GUI_DIVE_Mode = NVD_MDCC;   // switch back to CC mode before go diving or other surface settings
        }
        break;

    case SETGASES_SET_BO_GASES:
        BackupOpcode = SETGASES_SET_BO_GASES;
        NewOpcode = Opcode_Matrix( S42_SET_GASES, SETGASES_SET_CC_GASES, SETGASES_O2_ANALYZER, OldOpcode, S70_SET_GAS_01, ReturnToMainPage(),  OldOpcode, OldOpcode, OldOpcode);

        if(NewOpcode == S70_SET_GAS_01)
        {
            DIVE_MODE = NVD_MDBO;       // temporarily switch to BO mode to do SET GASES
            RETURN_DIVE_MODE = NVD_MDBO;// temporarily switch to BO mode to do SET GASES
            GUI_DIVE_Mode = NVD_MDBO;   // temporarily switch to BO mode to do SET GASES
        }
        else
        {
            DIVE_MODE = NVD_MDCC;       // switch back to CC mode before go diving or other surface settings
            RETURN_DIVE_MODE = NVD_MDCC;// switch back to CC mode before go diving or other surface settings
            GUI_DIVE_Mode = NVD_MDCC;   // switch back to CC mode before go diving or other surface settings
        }
        break;

    case SETGASES_O2_ANALYZER:
        BackupOpcode = SETGASES_O2_ANALYZER;
        NewOpcode = Opcode_Matrix( S42_SET_GASES, SETGASES_SET_BO_GASES, SETGASES_SET_CC_GASES, OldOpcode, S462_O2ANALYZER_CALIBRATE, ReturnToMainPage(),  OldOpcode, OldOpcode, OldOpcode);

        if(DIVE_MODE == NVD_MDBO)
        {
            DIVE_MODE = NVD_MDCC;       // switch back to CC mode before go diving or other surface settings
            RETURN_DIVE_MODE = NVD_MDCC;// switch back to CC mode before go diving or other surface settings
            GUI_DIVE_Mode = NVD_MDCC;   // switch back to CC mode before go diving or other surface settings
        }
        break;


    case S53_SET_SP:
        BackupOpcode = S53_SET_SP;
        OpcodeForR2s = S2_SURFACE_MAIN;

        NewOpcode = Opcode_Matrix( S41_SET_MENU,      S42_SET_GASES,          S_DIVE_SETTINGS,        OldOpcode,     S54_SP_HIGH_SP,  ReturnToMainPage(),   OldOpcode, OldOpcode, OldOpcode);
        if(NewOpcode==S54_SP_HIGH_SP)   // read back from EEPROM
        {
            GUI_SP_HighVal   = HIGH_SP_Val;     // for GUI displaying
            GUI_SP_LowVal    = LOW_SP_Val;      // for GUI displaying
            GUI_SP_CustomVal = CUSTOM_SP_Val;   // for GUI displaying
            GUI_SP_AutoHighMtVal    = SP_AUTOHIGH_M;     // for GUI displaying
            GUI_SP_AutoLowMtVal     = SP_AUTOLOW_M;      // for GUI displaying
            GUI_SP_AutoHighFtVal    = SP_AUTOHIGH_FT;    // for GUI displaying
            GUI_SP_AutoLowFtVal	    = SP_AUTOLOW_FT;     // for GUI displaying

            if(GUI_SP_AutoHighFtVal<(GUI_SP_AutoLowFtVal+20)) {
                GUI_SP_AutoHighFtVal = GUI_SP_AutoLowFtVal+20;
            }
            if(GUI_SP_AutoHighMtVal<(GUI_SP_AutoLowMtVal+6)) {
                GUI_SP_AutoHighMtVal = GUI_SP_AutoLowMtVal+6;
            }
        }
        break;

    case S_DIVE_SETTINGS:
        // to find SPORT mode is at Low, Medium or High
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)CONSER_SPORT_SETPOINTS;

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S41_SET_MENU, 	 S53_SET_SP,	S105_ALARMS,	OldOpcode, 	S99_SET_DIVEMODE,	ReturnToMainPage(),	  OldOpcode,	OldOpcode,	OldOpcode);
        }
        else if(OC_MODE||SM_MODE) {
            NewOpcode = Opcode_Matrix( S41_SET_MENU,	 S42_SET_GASES,	S105_ALARMS,	OldOpcode,	S99_SET_DIVEMODE,	ReturnToMainPage(),	  OldOpcode,	OldOpcode,	OldOpcode);
        }
        else
            NewOpcode = S105_ALARMS;    // in case that DSX returns from sub-menu of CC, OC or SM but already been switched to SM-Gauge or Gauge, force it to ALARMS in next second

        break;

    case S105_ALARMS:

        if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( S41_SET_MENU,      S_DIVE_SETTINGS,        S128_DEVICE_SETTINGS,   OldOpcode,     S106_AL_AUDIBLE,           ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        else
            NewOpcode = Opcode_Matrix( S41_SET_MENU,      S161_DISPLAY_SETTINGS,  S128_DEVICE_SETTINGS,   OldOpcode,     S106_AL_AUDIBLE,           ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S128_DEVICE_SETTINGS:
        NewOpcode = Opcode_Matrix( S41_SET_MENU,      S105_ALARMS,            S149_DATE_TIME,         OldOpcode,     S128_DEVICE_TRANSMITTERS,      ReturnToMainPage(),             OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S149_DATE_TIME:

        NewOpcode = Opcode_Matrix( S41_SET_MENU,      S128_DEVICE_SETTINGS,   S161_DISPLAY_SETTINGS,  OldOpcode,     S154_SET_DATE,                     ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        break;

    case S161_DISPLAY_SETTINGS:
        GUI_LANG_Select = LANG_Select;  // GUI Settings for LANG_Select
        GUI_SWITCH_LCD_GTR_L_R = (NVD_YesNo_t)SWITCH_LCD_GTR_L_R;
        if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( S41_SET_MENU,      S149_DATE_TIME,         S42_SET_GASES,        OldOpcode,     S162_DISPLAY_BRIGHTNESS,        ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        else
            NewOpcode = Opcode_Matrix( S41_SET_MENU,      S149_DATE_TIME,         S105_ALARMS,          OldOpcode,     S162_DISPLAY_BRIGHTNESS,        ReturnToMainPage(),              OldOpcode,              OldOpcode,              OldOpcode);
        break;



    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET DATE_TIME

    case S154_SET_DATE:

        NewOpcode = Opcode_Matrix( S149_DATE_TIME,		   S152_SET_TIME_FORMAT,  S158_SET_TIME,	OldOpcode,	S154_SET_YY,	ReturnToMainPage(),	   OldOpcode,	OldOpcode,	OldOpcode);

        UpdateRealTimeDate(&GUI_SetDateTime);
        // Read EE Data for GUI Display GUI_variables
        GUI_12H24H_Format = (NVD_timeformat_t)SWITCH_HR24_Format;
        GUI_MMDD_Format = (NVD_dateformat_t)SWITCH_DDMM_Format;
        UpdateRealTimeDate(&GUI_SetDateTime);
        break;

    case S158_SET_TIME:

        NewOpcode = Opcode_Matrix( S149_DATE_TIME,		   S154_SET_DATE,  S150_SET_DATE_FORMAT,	OldOpcode,	S158_SET_HH,	ReturnToMainPage(),	   OldOpcode,	OldOpcode,	OldOpcode);
        UpdateRealTimeDate(&GUI_SetDateTime);
        break;

    case S150_SET_DATE_FORMAT:

        NewOpcode = Opcode_Matrix( S149_DATE_TIME,		   S158_SET_TIME,  S152_SET_TIME_FORMAT,	OldOpcode,	S150_SET_DATE_FORMAT_SET, ReturnToMainPage(),		OldOpcode,			   OldOpcode,			   OldOpcode);
        UpdateRealTimeDate(&GUI_SetDateTime);
        GUI_MMDD_Format = (NVD_dateformat_t)SWITCH_DDMM_Format;
        break;

    case S152_SET_TIME_FORMAT:

        NewOpcode = Opcode_Matrix( S149_DATE_TIME,		   S150_SET_DATE_FORMAT,  S154_SET_DATE,	OldOpcode,	S152_SET_TIME_FORMAT_SET, ReturnToMainPage(),		OldOpcode,			   OldOpcode,			   OldOpcode);
        UpdateRealTimeDate(&GUI_SetDateTime);
        GUI_12H24H_Format = (NVD_timeformat_t)SWITCH_HR24_Format;
        break;

    case S150_SET_DATE_FORMAT_SET:

        NewOpcode = Opcode_Matrix( S150_SET_DATE_FORMAT,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:

            if(GUI_MMDD_Format == NVD_MD)
            {
                GUI_MMDD_Format = NVD_DM;
            }
            else
            {
                GUI_MMDD_Format = NVD_MD;
            }
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_MMDD_Format == NVD_MD)
            {
                SWITCH_DDMM_Format = false;
            }
            else
            {
                SWITCH_DDMM_Format = true;
            }
            // to save on EEPROM
            EE_SaveReq(EE_USERSET);
            NewOpcode = S150_SET_DATE_FORMAT;
            break;
        }
        break;

    case S152_SET_TIME_FORMAT_SET:

        NewOpcode = Opcode_Matrix( S152_SET_TIME_FORMAT,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:

            if(GUI_12H24H_Format == NVD_24HR)
            {
                GUI_12H24H_Format = NVD_12HR;
            }
            else
            {
                GUI_12H24H_Format = NVD_24HR;
            }
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_12H24H_Format == NVD_24HR)
            {
                SWITCH_HR24_Format = true;
            }
            else
            {
                SWITCH_HR24_Format = false;
            }
            // to save on EEPROM
            EE_SaveReq(EE_USERSET);
            NewOpcode = S152_SET_TIME_FORMAT;
            break;
        }
        break;

    case S154_SET_YY:

        NewOpcode = Opcode_Matrix( S154_SET_DATE,  DataDec,  DataInc,	ScrollInc,  S154_SET_MM,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SetDateTime.Year = (uint8_t)SettingData(GUI_SetDateTime.Year, 71, 21, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SetDateTime.Year = (uint8_t)SettingData(GUI_SetDateTime.Year, 71, 21, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        }
        break;

    case S154_SET_MM:

        NewOpcode = Opcode_Matrix( S154_SET_YY,   DataDec,  DataInc,	ScrollInc,  S154_SET_DD,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SetDateTime.Month = (uint8_t)SettingData(GUI_SetDateTime.Month, 12, 1, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SetDateTime.Month = (uint8_t)SettingData(GUI_SetDateTime.Month, 12, 1, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        }
        break;

    case S154_SET_DD:

        NewOpcode = Opcode_Matrix( S154_SET_MM,   DataDec,  DataInc,	ScrollInc,  S154_SET_DATE,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        daysofmonth = retdaysofmonth(GUI_SetDateTime.Month, GUI_SetDateTime.Year);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SetDateTime.Day = (uint8_t)SettingData(GUI_SetDateTime.Day, daysofmonth, 1, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SetDateTime.Day = (uint8_t)SettingData(GUI_SetDateTime.Day, daysofmonth, 1, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case S154_SET_DATE:
            // Update PST to RAM SysTimeDatePST
            Save_GUI_Set_TimeDate(&SysTimeDatePST);
            // Update PST to EEPROM Image DEV_Rec.RTC_PST
            Save_GUI_Set_TimeDate(&DEV_Rec.RTC_PST);
            // Restore RTC Date and Time from EEPROM DEV_Rec.RTC_PST
            L4X9_SetRtc(DEV_Rec.RTC_PST);
            // to save on EEPROM
            EE_SaveReq(EE_DEVREC);
            break;
        }
        break;

    case S158_SET_HH:

        NewOpcode = Opcode_Matrix( S158_SET_TIME, DataDec,  DataInc,	ScrollInc,  S158_SET_MM,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(GUI_12H24H_Format == NVD_24HR) {
                GUI_SetDateTime.Hour = (uint8_t)SettingData(GUI_SetDateTime.Hour, 23, 0, 1, data_type);
            }
            else {
                if(MidNight ==0) {
                    GUI_SetDateTime.Hour = (uint8_t)SettingData(GUI_SetDateTime.Hour, 11, 0, 1, data_type);
                }
                else {
                    GUI_SetDateTime.Hour = (uint8_t)SettingData(GUI_SetDateTime.Hour, 23, 12, 1, data_type);
                }
            }

            //GUI_SetDateTime.Hour = (uint8_t)SettingData(GUI_SetDateTime.Hour, 23, 0, 1, data_type);
            NewOpcode = OldOpcode;
            break;
            //case DataDec:
            //    GUI_SetDateTime.Hour = (uint8_t)SettingData(GUI_SetDateTime.Hour, 23, 0, 1, data_decrease);
            //    NewOpcode = OldOpcode;
            //    break;
        }
        break;
    case S158_SET_MM:

        NewOpcode = Opcode_Matrix( S158_SET_HH,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SetDateTime.Minute = (uint8_t)SettingData(GUI_SetDateTime.Minute, 59, 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SetDateTime.Minute = (uint8_t)SettingData(GUI_SetDateTime.Minute, 59, 0, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:

            GUI_SetDateTime.Second = 1;
            Save_GUI_Set_TimeDate(&SysTimeDatePST);
            L4X9_SetRtc(SysTimeDatePST);
            UpdateRealTimeDate(&SysTimeDatePST);      // to MFG save Calibration Time
            Save_GUI_Set_TimeDate(&DEV_Rec.RTC_PST);
            // to save on EEPROM
            EE_SaveReq(EE_DEVREC);	  // to save Hour and Min

            if(GUI_12H24H_Format == NVD_12HR)
            {
                NewOpcode = S158_SET_AM_PM;
            }
            else
            {
                NewOpcode = S158_SET_TIME;
            }
            break;
        }
        break;
    case S158_SET_AM_PM:

        NewOpcode = Opcode_Matrix( S158_SET_MM,   DataDec,  DataInc,	OldOpcode,  S158_SET_TIME,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:

            AM_PM_FLAT = (AM_PM_FLAT == AM)? PM:AM;

            NewOpcode = OldOpcode;
            break;

        case S158_SET_TIME:
            //uint8_t _12h_conv;
            //ret12Hfrom24H(SET_HOUR, &_12h_conv, & MidNight);

            if(AM_PM_FLAT == PM) {
                if(GUI_SET_HOUR < 12)
                {
                    GUI_SET_HOUR += 12;
                }
            }
            else {
                if(GUI_SET_HOUR >= 12)
                {
                    GUI_SET_HOUR = GUI_SET_HOUR - 12;
                }

            }
            GUI_SetDateTime.Second = 1;
            // Update PST to RAM SysTimeDatePST
            Save_GUI_Set_TimeDate(&SysTimeDatePST);
            // Update PST to EEPROM Image DEV_Rec.RTC_PST
            Save_GUI_Set_TimeDate(&DEV_Rec.RTC_PST);
            // Restore RTC Date and Time from EEPROM DEV_Rec.RTC_PST
            L4X9_SetRtc(DEV_Rec.RTC_PST);
            // to save on EEPROM
            EE_SaveReq(EE_DEVREC);    // to save Hour and Min
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET ALARM


    case S106_AL_AUDIBLE:

        if(CC_MODE)
            NewOpcode = Opcode_Matrix( S105_ALARMS,	  S122_AL_GF_N2,                S108_AL_DEPTH,	OldOpcode,	ALARM_AUDIBLE,  ReturnToMainPage(),     OldOpcode,	OldOpcode,	OldOpcode);
        else if(OC_MODE||SM_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( S105_ALARMS,	  S288_AL_END_WOB_ICD_ALARMS,   S108_AL_DEPTH,	OldOpcode,	ALARM_AUDIBLE,  ReturnToMainPage(),     OldOpcode,	OldOpcode,	OldOpcode);
        else
            NewOpcode = Opcode_Matrix( S105_ALARMS,	  S281_AL_TURN_END_PRESS,       S108_AL_DEPTH,	OldOpcode,	ALARM_AUDIBLE,  ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);

        GUI_SWITCH_AlarmAudible = SWITCH_AlarmAudible;          //USER_Set.SwitchSet.Bit.AlarmAudible      // 1-bit Alarm Audible Active   0: OFF (not audible)    1: ON: audible, to follow the rest of bit statuses.
        GUI_SWITCH_AlarmVibeOn = SWITCH_AlarmVibeOn;            //USER_Set.SwitchSet.Bit.AlarmVibeOn       // 1-bit Alarm Vibration Active 0: OFF (not vibrate)    1: ON: vibrate, to follow the rest of bit statuses.
        GUI_SWITCH_AlarmLED = SWITCH_AlarmLED;                  //USER_Set.SwitchSet.Bit.AlarmLED          // 1-bit Alarm LED is Active    0: OFF (no LED)         1: ON: LED, to follow the rest of bit statuses.
        GUI_SWITCH_BluetoothOn = SWITCH_BluetoothOn;            //USER_Set.SwitchSet.Bit.BluetoothOn       // 1-bit Bluetooth Switch ON    0: OFF                  1: ON
        GUI_SWITCH_ConservativeOn = SWITCH_ConservativeOn;      //USER_Set.SwitchSet.Bit.ConservativeOn    // 1-bit Conservative Factor ON 0: OFF                  1: ON
        //GUI_SWITCH_DeepStopOn;                                  //USER_Set.SwitchSet.Bit.DeepStopOn        // 1-bit DeepStop is Active     0: OFF                  1: ON
        //GUI_SWITCH_WaterContactOn;                              //USER_Set.SwitchSet.Bit.WaterContactOn    // 1-bit WaterContact is Active 0: OFF                  1: ON
        GUI_SWITCH_ClockAlarm = SWITCH_ClockAlarm;              //USER_Set.SwitchSet.Bit.ClockAlarm        // 1-bit ClockAlarm is Active   0: OFF                  1: ON
        GUI_SWITCH_NoFlyAlarm = SWITCH_NoFlyAlarm;              //USER_Set.SwitchSet.Bit.NoFlyAlarm        // 1-bit NoFlyAlarm is Active   0: OFF                  1: ON
        //GUI_SWITCH_AutoDimOn;                                   //USER_Set.SwitchSet.Bit.AutoDimOn         // 1-bit AutoDim is Active      0:                      1:
        //GUI_SWITCH_PowerSavingOn;                               //USER_Set.SwitchSet.Bit.PowerSavingOn     // 1-bit PowerSaving is Active  0:                      1:
        //GUI_SWITCH_HomeAway;                                    //USER_Set.SwitchSet.Bit.HomeAway          // 1-bit HomeAway               0:
        //GUI_SWITCH_CDT_Enable;                                  //USER_Set.SwitchSet.Bit.CDT_Enable        // 1-bit CDT_Enable             0:                      1:
        //GUI_SWITCH_WaterType;                                   //USER_Set.SwitchSet.Bit.WaterType         // 1-bit WaterType              0:                      1:
        //GUI_SWITCH_Backlight;                                   //USER_Set.SwitchSet.Bit.Backlight         // 1-bit Backlight Active       0:                     1:
        //GUI_SWITCH_SafetyStopOn;                                //USER_Set.SwitchSet.Bit.SafetyStopOn      // 1-bit SafetyStopOn Active    0:
        //GUI_SWITCH_DiverTimerState;                             //USER_Set.SwitchSet.Bit.DiverTimerState   // 2-bit DiveTimerState         0: Stop (back to 0)     1: Pause             2: Run
        //GUI_SWITCH_DiverTimerDisp;                              //USER_Set.SwitchSet.Bit.DiverTimerDisp    // 1-bit DiveTimerDisplay       0: Hide                 1: Display to GUI


        GUI_DEPTHAL_STAT = (NVD_status_t)DEPTHAL_STAT;        // GUI settings for DEPTHAL_STAT
        GUI_DepthAlarmFT = DEPTHAL_FT;        // GUI settings for DEPTHAL_FT
        GUI_DepthAlarmM = DEPTHAL_M;          // GUI settings for DEPTHAL_M
        GUI_DIVE_T_AL_STAT = (NVD_status_t)DIVE_T_AL_STAT;    // GUI settings for DIVE_T_STAT (Off, On, Set)
        GUI_DIVE_T_AL = DIVE_T_AL;              // GUI settings for DIVE_T_AL
        GUI_TTS_AL_STAT = (NVD_status_t)TTS_AL_STAT;          // GUI settings for TTS_AL_STAT (Off, On, Set)
        GUI_TTS_AL = TTS_AL;                    // GUI settings for TTS_AL
        GUI_DTR_AL_STAT = (NVD_status_t)DTR_AL_STAT;          // GUI settings for DTR_AL_STAT (Off, On, Set)
        GUI_DTR_AL = DTR_AL;                    // GUI settings for DTR_AL
        GUI_TankP_AL_STAT = (NVD_status_t)TANK_PRESS_STAT;    // GUI settings for TankP_AL_STAT (Off, On, Set)
        GUI_TankP_AL_PSI = TANK_PRESS_PSI;      // GUI settings for TANK_PRESS_PSI
        GUI_TankP_AL_BAR = TANK_PRESS_BAR;      // GUI settings for TANK_PRESS_PSI
        GUI_CC6P_AL_STAT = (NVD_status_t)CC6P_AL_STAT;        // GUI settings for CC6P_AL_STAT (Off, On, Set)
        GUI_CC6P_AL_PSI = CC6P_AL_PSI;          // GUI settings for CC6P_AL_PSI
        GUI_CC6P_AL_BAR = CC6P_AL_BAR;          // GUI settings for CC6P_AL_BAR
        GUI_TurnP_AL_STAT = (NVD_status_t)TurnP_AL_STAT;      // GUI settings for TurnP_AL_STAT (Off, On, Set)
        GUI_TurnP_AL_PSI = TurnP_AL_PSI;        // GUI settings for TurnP_AL_PSI
        GUI_TurnP_AL_BAR = TurnP_AL_BAR;        // GUI settings for TurnP_AL_BAR
        GUI_EndP_AL_STAT = (NVD_status_t)EndP_AL_STAT;        // GUI settings for EndP_AL_STAT (Off, On, Set)
        GUI_EndP_AL_PSI = EndP_AL_PSI;          // GUI settings for EndP_AL_PSI
        GUI_EndP_AL_BAR = EndP_AL_BAR;          // GUI settings for EndP_AL_BAR
        GUI_SwitchP_AL_STAT = (NVD_status_t)SwitchP_AL_STAT;  // GUI settings for Switch_AL_STAT (Off, On, Set)
        GUI_SwitchP_AL_PSI = SwitchP_AL_PSI;    // GUI settings for Switch_AL_PSI
        GUI_SwitchP_AL_BAR = SwitchP_AL_BAR;    // GUI settings for Switch_AL_BAR
        GUI_GF_AL_STAT = (NVD_status_t)GF_AL_STAT;            // GUI settings for GF_AL_STAT(Off, On, Set)
        GUI_GF_AL = GF_AL;                      // GUI settings for GF_AL
        GUI_N2_AL_STAT = (NVD_status_t)N2_AL_STAT;            // GUI settings for N2_STAT (Off, On, Set)
        GUI_N2_AL = N2_AL;                      // GUI settings for N2_AL
        GUI_END_AL_STAT = (NVD_status_t)END_AL_STAT;          // GUI settings for END_AL_STAT
        GUI_END_AL_FT = END_AL_FT;              // GUI settings for END_AL_FT
        GUI_END_AL_M = (float)0.1*END_AL_dM;                // GUI settings for END_AL_M
        GUI_WOB_AL_STAT = (NVD_status_t)WOB_AL_STAT;          // GUI settings for WOB_AL_STAT
        GUI_WOB_AL_FT = WOB_AL_FT;              // GUI settings for WOB_AL_FT
        GUI_WOB_AL_M = (float)0.1*WOB_AL_dM;                // GUI settings for WOB_AL_M
        GUI_ICD_AL_STAT = (NVD_status_t)ICD_AL_STAT;          // GUI settings for ICD_AL_STAT
        GUI_O2_NARCOTIC_AL_STAT = (NVD_status_t)NARCOTIC_AL_SW;
        break;

    case S108_AL_DEPTH:
        if(GAUGE_MODE|GSM_MODE)
        {
            NewOpcode = Opcode_Matrix( S105_ALARMS,	S106_AL_AUDIBLE,  S111_AL_DIVETIME,	OldOpcode,	ALARM_DEPTH_STAT,	ReturnToMainPage(),	   OldOpcode,			   OldOpcode,			   OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( S105_ALARMS,	S106_AL_AUDIBLE,  S000_AL_DIVETIME_TTS,	OldOpcode,	ALARM_DEPTH_STAT,	ReturnToMainPage(),	   OldOpcode,			   OldOpcode,			   OldOpcode);
        }

        GUI_DEPTHAL_STAT = (NVD_status_t)DEPTHAL_STAT;			// GUI settings for DEPTHAL_STAT
        GUI_DepthAlarmFT = DEPTHAL_FT;                          // GUI settings for DEPTHAL_FT
        GUI_DepthAlarmM = DEPTHAL_M;                            // GUI settings for DEPTHAL_M
        break;
    case S000_AL_DIVETIME_TTS:
        NewOpcode = Opcode_Matrix(S105_ALARMS, S108_AL_DEPTH, S116_AL_DTR, OldOpcode, ALARM_DIVETIME, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S111_AL_DIVETIME:
        NewOpcode = Opcode_Matrix(S105_ALARMS, S108_AL_DEPTH, S281_AL_TURN_END_PRESS,	OldOpcode,	ALARM_DIVETIME_STAT,	ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        break;

    case S116_AL_DTR:
        GUI_DTR_AL_STAT = (NVD_status_t)DTR_AL_STAT;
        GUI_DTR_AL = DTR_AL;

        if(CC_MODE)
            NewOpcode = Opcode_Matrix( S105_ALARMS,  S000_AL_DIVETIME_TTS,  S116_AL_TANK_PRESS,	OldOpcode,	ALARM_DTR_STAT,		ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        else if(OC_MODE||SM_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( S105_ALARMS,  S000_AL_DIVETIME_TTS,  S281_AL_TURN_END_PRESS,	OldOpcode,	ALARM_DTR_STAT,		ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        break;

    case S116_AL_TANK_PRESS:
        GUI_TankP_AL_STAT = (NVD_status_t)TANK_PRESS_STAT;
        GUI_TankP_AL_PSI = TANK_PRESS_PSI;
        GUI_TankP_AL_BAR = TANK_PRESS_BAR;

        NewOpcode = Opcode_Matrix( S105_ALARMS,	   S116_AL_DTR,  S119_AL_CC6_PRESS,             OldOpcode,	ALARM_TANK_PRESS_STAT,	   ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        break;

    case S119_AL_CC6_PRESS:
        GUI_CC6P_AL_STAT = (NVD_status_t)CC6P_AL_STAT;
        GUI_CC6P_AL_PSI = CC6P_AL_PSI;
        GUI_CC6P_AL_BAR = CC6P_AL_BAR;

        NewOpcode = Opcode_Matrix( S105_ALARMS,	   S116_AL_TANK_PRESS,  S122_AL_GF_N2,		OldOpcode,	ALARM_CC6_PRESS_STAT,	   ReturnToMainPage(),	OldOpcode,	OldOpcode,	OldOpcode);
        break;

    case S122_AL_GF_N2:
        GUI_GF_AL_STAT = (NVD_status_t)GF_AL_STAT;
        GUI_GF_AL = GF_AL;
        GUI_N2_AL_STAT = (NVD_status_t)N2_AL_STAT;
        GUI_N2_AL = N2_AL;

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S105_ALARMS, 	S119_AL_CC6_PRESS,  S106_AL_AUDIBLE,			OldOpcode,	ALARM_GFN2_GF_STAT,	ReturnToMainPage(),	OldOpcode,	OldOpcode,			  OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S105_ALARMS, 	S281_AL_TURN_END_PRESS,  S288_AL_END_WOB_ICD_ALARMS,	OldOpcode,	ALARM_GFN2_GF_STAT,	ReturnToMainPage(),	OldOpcode,	OldOpcode,			  OldOpcode);
        }

        break;

    case S281_AL_TURN_END_PRESS:
        GUI_TurnP_AL_STAT = (NVD_status_t)TurnP_AL_STAT;
        GUI_TurnP_AL_PSI = TurnP_AL_PSI;
        GUI_TurnP_AL_BAR = TurnP_AL_BAR;
        GUI_EndP_AL_STAT = (NVD_status_t)EndP_AL_STAT;
        GUI_EndP_AL_PSI = EndP_AL_PSI;
        GUI_EndP_AL_BAR = EndP_AL_BAR;

        if(OC_MODE||SM_MODE)
            NewOpcode = Opcode_Matrix( S105_ALARMS,	S116_AL_DTR,            S122_AL_GF_N2,		OldOpcode,	S282_ALARM_TURNPRESS,	ReturnToMainPage(),	OldOpcode,			   OldOpcode,			   OldOpcode);
        else
            NewOpcode = Opcode_Matrix( S105_ALARMS,	S111_AL_DIVETIME,       S106_AL_AUDIBLE,	OldOpcode,	S282_ALARM_TURNPRESS,	ReturnToMainPage(),	OldOpcode,			   OldOpcode,			   OldOpcode);
        break;

    case S288_AL_END_WOB_ICD_ALARMS:
        GUI_END_AL_STAT = (NVD_status_t)END_AL_STAT;
        GUI_END_AL_FT = END_AL_FT;
        GUI_END_AL_M = (float)(0.1*END_AL_dM);
        GUI_WOB_AL_STAT = (NVD_status_t)WOB_AL_STAT;
        GUI_WOB_AL_FT = WOB_AL_FT;
        GUI_WOB_AL_M = (float)(0.1*WOB_AL_dM);
        GUI_ICD_AL_STAT = (NVD_status_t)ICD_AL_STAT;

        NewOpcode = Opcode_Matrix( S105_ALARMS,		S122_AL_GF_N2,          S106_AL_AUDIBLE,	OldOpcode,	S289_ALARM_END,	        ReturnToMainPage(),	OldOpcode,			   OldOpcode,			   OldOpcode);
        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET SP Menu

    case S54_SP_HIGH_SP:
        GUI_SP_HighVal = HIGH_SP_Val;
        NewOpcode = Opcode_Matrix( BackupOpcode,		S59_SP_AUTO_LOW,        S54_SP_LOW_SP,	OldOpcode,	SP_HIGH_SP_SET,		ReturnToMainPage(),	OldOpcode,			   OldOpcode,			   OldOpcode);

        break;

    case S54_SP_LOW_SP:
        GUI_SP_LowVal = LOW_SP_Val;

        NewOpcode = Opcode_Matrix( BackupOpcode,		   S54_SP_HIGH_SP,  S56_SP_CUSTOM_SP,	OldOpcode,	 SP_LOW_SP_SET,		ReturnToMainPage(),	 OldOpcode,			   OldOpcode,			   OldOpcode);
        break;

    case S56_SP_CUSTOM_SP:
        GUI_SP_CustomSwitch = (NVD_status_t)CUSTOM_SP_STAT;
        GUI_SP_CustomVal = CUSTOM_SP_Val ;
        NewOpcode = Opcode_Matrix( BackupOpcode,		   S54_SP_LOW_SP,  S59_SP_AUTO_HIGH,	OldOpcode,	 SP_CUSTOM_SP_STAT,	ReturnToMainPage(),	 OldOpcode,			   OldOpcode,			   OldOpcode);
        break;

    case S59_SP_AUTO_HIGH:
        GUI_SP_AutoHighSwitch = (NVD_status_t)AUTO_HIGH_SP_STAT;
        GUI_SP_AutoHighFtVal = SP_AUTOHIGH_FT;
        GUI_SP_AutoHighMtVal = SP_AUTOHIGH_M ;
        NewOpcode = Opcode_Matrix( BackupOpcode,		   S56_SP_CUSTOM_SP,  S59_SP_AUTO_LOW,	OldOpcode,	 SP_AUTO_HIGH_STAT,	ReturnToMainPage(),	 OldOpcode,			   OldOpcode,			   OldOpcode);
        break;

    case S59_SP_AUTO_LOW:
        GUI_SP_AutoLowSwitch = (NVD_status_t)AUTO_LOW_SP_STAT;
        GUI_SP_AutoLowFtVal =  SP_AUTOLOW_FT;
        GUI_SP_AutoLowMtVal = SP_AUTOLOW_M;

        NewOpcode = Opcode_Matrix( BackupOpcode,		   S59_SP_AUTO_HIGH,  S54_SP_HIGH_SP,	OldOpcode,	 SP_AUTO_LOW_STAT,	ReturnToMainPage(),	 OldOpcode,			   OldOpcode,			   OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET SP Points

    case SP_HIGH_SP_SET:

        NewOpcode = Opcode_Matrix( S54_SP_HIGH_SP,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,    ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SP_HighVal = (uint8_t)SettingData(GUI_SP_HighVal, 150, 40, 10, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SP_HighVal = (uint8_t)SettingData(GUI_SP_HighVal, 150, 40, 10, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            HIGH_SP_Val = GUI_SP_HighVal;       // save to EE

            if(HIGH_SP_Val < LOW_SP_Val)        // according spec., "If user decreases High < Low, set Low = High automactically here"
            {
                LOW_SP_Val = HIGH_SP_Val;
                GUI_SP_LowVal = LOW_SP_Val;
            }
            Check_SPcurrent();  // Acknowledge DiveAlgo for the new change
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = S54_SP_HIGH_SP;         // return to menu
            break;
        }
        break;

    case SP_LOW_SP_SET:

        NewOpcode = Opcode_Matrix( S54_SP_LOW_SP,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,   ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SP_LowVal = (uint8_t)SettingData(GUI_SP_LowVal, HIGH_SP_Val, 40, 10, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SP_LowVal = (uint8_t)SettingData(GUI_SP_LowVal, HIGH_SP_Val, 40, 10, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            LOW_SP_Val = GUI_SP_LowVal;         // save to EE
            Check_SPcurrent();  // Acknowledge DiveAlgo for the new change
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = S54_SP_LOW_SP;          // return to menu
            break;
        }
        break;

    case SP_CUSTOM_SP_STAT:

        NewOpcode = Opcode_Matrix( S56_SP_CUSTOM_SP, DataDec, DataInc,  OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //GUI_SP_Switch = (SP_Switch_t)SettingData((uint8_t)GUI_SP_Switch, NVD_SET, NVD_OFF, 1, data_type);

        switch (NewOpcode)
        {
        case DataInc:
            if(GUI_SP_ActualVal == GUI_SP_CustomVal) { /*when active SP is custom sp*/
                GUI_SP_CustomSwitch = (NVD_status_t)SettingData(GUI_SP_CustomSwitch, NVD_SET, NVD_ON, 1, data_increase);
            }
            else {
                GUI_SP_CustomSwitch = (NVD_status_t)SettingData(GUI_SP_CustomSwitch, NVD_SET, NVD_OFF, 1, data_increase);
            }

            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(GUI_SP_ActualVal == GUI_SP_CustomVal) { /*when active SP is custom sp*/
                GUI_SP_CustomSwitch = (NVD_status_t)SettingData(GUI_SP_CustomSwitch, NVD_SET, NVD_ON, 1, data_decrease);
            }
            else {
                GUI_SP_CustomSwitch = (NVD_status_t)SettingData(GUI_SP_CustomSwitch, NVD_SET, NVD_OFF, 1, data_decrease);
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_SP_CustomSwitch==NVD_SET)
            {
                NewOpcode = SP_CUSTOM_SP_SET;               // move to SP_SET
            }
            else
            {
                CUSTOM_SP_STAT = (NVD_status_t)GUI_SP_CustomSwitch;       // save ON or OFF to EE
                EE_SaveReq(EE_SCUBASET);
                NewOpcode = S56_SP_CUSTOM_SP;               // return to menu
            }
            break;
        }
        break;

    case SP_CUSTOM_SP_SET:

        NewOpcode = Opcode_Matrix( SP_CUSTOM_SP_STAT,  DataDec,  DataInc, ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //GUI_SP_CustomVal = (uint16_t)SettingData(GUI_SP_CustomVal, 150, 40, 10, data_type);

        GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum] = (TMT_NUM_t)RectifyData(GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum], TANK_6, TANK_OFF);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_SP_CustomVal = (uint8_t)SettingData(GUI_SP_CustomVal, 150, 40, 10, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SP_CustomVal = (uint8_t)SettingData(GUI_SP_CustomVal, 150, 40, 10, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            CUSTOM_SP_Val = GUI_SP_CustomVal;       // save new value
            GUI_SP_CustomSwitch = NVD_ON;
            CUSTOM_SP_STAT = (NVD_status_t)GUI_SP_CustomSwitch;   // turn ON
            Check_SPcurrent();  // Acknowledge DiveAlgo for the new change
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);                // save to EE
            NewOpcode = S56_SP_CUSTOM_SP;           // return to menu
            break;
        }
        break;

    case SP_AUTO_HIGH_STAT:

        NewOpcode = Opcode_Matrix( S59_SP_AUTO_HIGH,  DataDec,  DataInc,        OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //GUI_SP_AutoHighSwitch = (SP_Switch_t)SettingData((uint8_t)GUI_SP_AutoHighSwitch, NVD_SET, NVD_OFF, 1, data_type);
        switch (NewOpcode)
        {
        case DataInc:
            GUI_SP_AutoHighSwitch = (NVD_status_t)SettingData(GUI_SP_AutoHighSwitch, NVD_SET, NVD_OFF, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SP_AutoHighSwitch = (NVD_status_t)SettingData(GUI_SP_AutoHighSwitch, NVD_SET, NVD_OFF, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_SP_AutoHighSwitch==NVD_SET)
            {
                NewOpcode = SP_AUTO_HIGH_SET;               // move to SP_SET
            }
            else
            {
                AUTO_HIGH_SP_STAT = (NVD_status_t)GUI_SP_AutoHighSwitch;     // save to EE
                EE_SaveReq(EE_SCUBASET);
                NewOpcode = S59_SP_AUTO_HIGH;               // return to menu
            }
            break;
        }
        break;

    case SP_AUTO_HIGH_SET:

        NewOpcode = Opcode_Matrix( SP_AUTO_HIGH_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:

            if(UNITS==NVD_IMPERIAL)
                GUI_SP_AutoHighFtVal = (uint16_t)SettingData(GUI_SP_AutoHighFtVal, 420, GUI_SP_AutoLowFtVal+20, 5, data_increase);
            else
                GUI_SP_AutoHighMtVal = (uint16_t)SettingData(GUI_SP_AutoHighMtVal, 130, GUI_SP_AutoLowMtVal+6,  1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_SP_AutoHighFtVal = (uint16_t)SettingData(GUI_SP_AutoHighFtVal, 420, GUI_SP_AutoLowFtVal+20, 5, data_decrease);
            else
                GUI_SP_AutoHighMtVal = (uint16_t)SettingData(GUI_SP_AutoHighMtVal, 130, GUI_SP_AutoLowMtVal+6,  1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(UNITS==NVD_IMPERIAL)
                SP_AUTOHIGH_FT = GUI_SP_AutoHighFtVal;  // save new value
            else
                SP_AUTOHIGH_M  = GUI_SP_AutoHighMtVal;  // save new value
            GUI_SP_AutoHighSwitch = NVD_ON;
            AUTO_HIGH_SP_STAT = GUI_SP_AutoHighSwitch;  // turn ON


            if(SP_AUTOHIGH_FT < SP_AUTOLOW_FT)
            {
                SP_AUTOLOW_FT = SP_AUTOHIGH_FT;
                GUI_SP_AutoLowFtVal = SP_AUTOLOW_FT;
            }

            if(SP_AUTOHIGH_M < SP_AUTOLOW_M)
            {
                SP_AUTOLOW_M = SP_AUTOHIGH_M;
                GUI_SP_AutoLowMtVal = SP_AUTOLOW_M;
            }

            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S59_SP_AUTO_HIGH;               // return to menu
            break;
        }
        break;

    case SP_AUTO_LOW_STAT:

        NewOpcode = Opcode_Matrix( S59_SP_AUTO_LOW,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            GUI_SP_AutoLowSwitch = (NVD_status_t)SettingData(GUI_SP_AutoLowSwitch, NVD_SET, NVD_OFF, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_SP_AutoLowSwitch = (NVD_status_t)SettingData(GUI_SP_AutoLowSwitch, NVD_SET, NVD_OFF, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_SP_AutoLowSwitch==NVD_SET)
            {
                NewOpcode = SP_AUTO_LOW_SET;                // move to SP_SET
            }
            else
            {
                AUTO_LOW_SP_STAT = GUI_SP_AutoLowSwitch;    // save to EE
                EE_SaveReq(EE_SCUBASET);
                NewOpcode = S59_SP_AUTO_LOW;                            // return to menu
            }
            break;
        }
        break;

    case SP_AUTO_LOW_SET:

        NewOpcode = Opcode_Matrix( SP_AUTO_LOW_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(UNITS==NVD_IMPERIAL)
                GUI_SP_AutoLowFtVal = (uint16_t)SettingData(GUI_SP_AutoLowFtVal, (GUI_SP_AutoHighFtVal-20), 10, 5, data_increase);
            else
                GUI_SP_AutoLowMtVal = (uint16_t)SettingData(GUI_SP_AutoLowMtVal, (GUI_SP_AutoHighMtVal-6),  3, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_SP_AutoLowFtVal = (uint16_t)SettingData(GUI_SP_AutoLowFtVal, (GUI_SP_AutoHighFtVal-20), 10, 5, data_decrease);
            else
                GUI_SP_AutoLowMtVal = (uint16_t)SettingData(GUI_SP_AutoLowMtVal, (GUI_SP_AutoHighMtVal-6),  3, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(UNITS==NVD_IMPERIAL)
                SP_AUTOLOW_FT = GUI_SP_AutoLowFtVal;  // save new value
            else
                SP_AUTOLOW_M  = GUI_SP_AutoLowMtVal;  // save new value
            GUI_SP_AutoLowSwitch = NVD_ON;
            AUTO_LOW_SP_STAT = GUI_SP_AutoLowSwitch;    // turn ON
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S59_SP_AUTO_LOW;                // return to menu
            break;
        }
        break;



    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // DIVE SETTING

    case S99_SET_DIVEMODE:

        NewOpcode = Opcode_Matrix( S_DIVE_SETTINGS,  S96_SET_LASTSTOPDEPTH,  S76_SET_BAILOUTPO2LIMITS,	OldOpcode,	DIVEMODE_SETPOINTS,	ReturnToMainPage(),        OldOpcode,      OldOpcode,      OldOpcode);

        GUI_DIVE_Mode = DIVE_MODE;                      // GUI settings for DIVE_MODE
        GUI_OC_SM_PO2_Min    = SCUBA_Set.OCmin;         // GUI settings for OCmin
        GUI_OC_SM_PO2_Max    = SCUBA_Set.OCmax;         // GUI settings for OCmax
        GUI_OC_SM_PO2_Deco   = SCUBA_Set.OCdeco;        // GUI settings for OCdeco
        GUI_BO_PO2_Min  = SCUBA_Set.BOmin;         // GUI settings for BOmin
        GUI_BO_PO2_Max  = SCUBA_Set.BOmax;         // GUI settings for BOmax
        GUI_BO_PO2_Deco = SCUBA_Set.BOdeco;        // GUI settings for BOdeco
        GUI_CONSV_Switch = (CONSV_TecSport_t)SCUBA_Set.Consv.ConservMode;               // GUI settings for TEC or SPORT Modes
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)SCUBA_Set.Consv.ConservSportMode;    // GUI Conservtism Sport Mode (Low, Medisum, High)
        GUI_TecGF_Hi = CONSER_TEC_GFHIGH;               // GUI settings for TEC GF High
        GUI_TecGF_Lo = CONSER_TEC_GFLOW;                // GUI settings for TEC GF Low

        if(GUI_CONSV_Sport_Switch==CONSV_SPORT_LOW)
        {
            GUI_SportGF_Hi = 90;
            GUI_SportGF_Lo = 90;
        }
        else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_MED)
        {
            GUI_SportGF_Hi = 80;
            GUI_SportGF_Lo = 35;
        }
        else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_HIGH)       // added by YeuShyr, to avoid mixup with TEC
        {
            GUI_SportGF_Hi = 70;
            GUI_SportGF_Lo = 30;
        }

        GUI_SafetyStopMode = SCUBA_Set.SafetyStopMode;  // GUI settings for SafetyStopMode
        GUI_SafetyStopMin = SCUBA_Set.SafetyStopMin;    // GUI settings for SafetyStopMin
        GUI_SS_DepthFt = SCUBA_Set.SS_DepthFt;          // GUI settings for DepthAlarmFT
        GUI_SS_DepthM = SCUBA_Set.SS_DepthM;            // GUI settings for DepthAlarmM
        GUI_LastStopFt = SCUBA_Set.LastStopFt;          // GUI settings for LastStopFt
        GUI_LastStopM = SCUBA_Set.LastStopM;	        // GUI settings for LastStopMt

        break;

    case S76_SET_BAILOUTPO2LIMITS:
        BackupOpcode = S76_SET_BAILOUTPO2LIMITS;

        NewOpcode = Opcode_Matrix(    S_DIVE_SETTINGS, S99_SET_DIVEMODE,  S83_SET_CONSERVATISM,	    	OldOpcode,  BAILOUT_PO2_OC_MIN,		ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        if(NewOpcode == BAILOUT_PO2_OC_MIN)
        {
            GUI_OC_SM_PO2_Min    = SCUBA_Set.OCmin;
            GUI_OC_SM_PO2_Max    = SCUBA_Set.OCmax;
            GUI_OC_SM_PO2_Deco   = SCUBA_Set.OCdeco;
            GUI_BO_PO2_Min  = SCUBA_Set.BOmin;
            GUI_BO_PO2_Max  = SCUBA_Set.BOmax;
            GUI_BO_PO2_Deco = SCUBA_Set.BOdeco;
        }
        break;

    case S83_SET_CONSERVATISM:
        GUI_CONSV_Switch = (CONSV_TecSport_t)SCUBA_Set.Consv.ConservMode;
        GUI_TecGF_Hi = SCUBA_Set.TEC_GF_Hi;
        GUI_TecGF_Lo = SCUBA_Set.TEC_GF_Lo;

        // ----------------added by YeuShyr, 2022 04 22 to check out-of-boundary----------------
        if(SCUBA_Set.Consv.ConservSportMode < CONSV_SPORT_LOW)
            SCUBA_Set.Consv.ConservSportMode = CONSV_SPORT_LOW;
        if(SCUBA_Set.Consv.ConservSportMode > CONSV_SPORT_HIGH)
            SCUBA_Set.Consv.ConservSportMode = CONSV_SPORT_HIGH;
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)SCUBA_Set.Consv.ConservSportMode;
        // ----------------added by YeuShyr, 2022 04 22 ----------------------------------------
        GUI_SportGF_Hi = SCUBA_Set.GF_High;
        GUI_SportGF_Lo = SCUBA_Set.GF_Low;

        NewOpcode = Opcode_Matrix( S_DIVE_SETTINGS, S76_SET_BAILOUTPO2LIMITS,  S91_SET_SAFETYSTOP, 		OldOpcode,	S105_SET_CONSERV_TEC_SPORT,	ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;

    case S91_SET_SAFETYSTOP:
        GUI_SafetyStopMode = SCUBA_Set.SafetyStopMode;
        GUI_SafetyStopMin = SCUBA_Set.SafetyStopMin;
        GUI_SS_DepthFt = SCUBA_Set.SS_DepthFt;
        GUI_SS_DepthM = SCUBA_Set.SS_DepthM;

        NewOpcode = Opcode_Matrix( S_DIVE_SETTINGS, S83_SET_CONSERVATISM,  S96_SET_LASTSTOPDEPTH, 		OldOpcode,	 SET_SAFETYSTOP_STAT,		 ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;

    case S96_SET_LASTSTOPDEPTH:
        GUI_LastStopFt = SCUBA_Set.LastStopFt;
        GUI_LastStopM = SCUBA_Set.LastStopM;

        NewOpcode = Opcode_Matrix( S_DIVE_SETTINGS, S91_SET_SAFETYSTOP,  S99_SET_DIVEMODE, 				OldOpcode,	 LASTSTOPDEPTH_SETPOINTS,	 ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;


    case DIVEMODE_SETPOINTS:

        NewOpcode = Opcode_Matrix( S99_SET_DIVEMODE,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
            if((!((RETURN_DIVE_MODE != DIVE_MODE)&&(GAUGE_MODE||GSM_MODE)))&&(DEV_Rec.LockForGaugeDive == 0))   // does not allow change during full violation waiting and after any new GSM or Gauge dive
                GUI_DIVE_Mode = (NVD_DIVEMODE_t)SettingData(GUI_DIVE_Mode, NVD_MDGAUGE, NVD_MDCC, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if((!((RETURN_DIVE_MODE != DIVE_MODE)&&(GAUGE_MODE||GSM_MODE)))&&(DEV_Rec.LockForGaugeDive == 0))   // does not allow change during full violation waiting and after any new GSM or Gauge dive
                GUI_DIVE_Mode = (NVD_DIVEMODE_t)SettingData(GUI_DIVE_Mode, NVD_MDGAUGE, NVD_MDCC, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:

            if((GUI_DIVE_Mode != DIVE_MODE)&&(DEV_Rec.LockForGaugeDive == 0))
            {
                DIVE_MODE = GUI_DIVE_Mode;
                RETURN_DIVE_MODE = DIVE_MODE;
                EE_SaveReq(EE_USERSET);
                Switch_Mode();
                Check3rdRowAfterDiveModeSwitch();
            }
            else
            {
                // NewOpcode = NEW_WARNING_OPCODE;
            }
            NewOpcode = S2_SURFACE_MAIN; // return to Surface Main menu

            break;
        }
        break;

    case SET_BAILOUT_PO2_LIMITS:

        NewOpcode = Opcode_Matrix( S99_SET_DIVEMODE,  OldOpcode,  OldOpcode,	OldOpcode,  OldOpcode,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case SET_CONSERVATISM:

        NewOpcode = Opcode_Matrix( S99_SET_DIVEMODE,  OldOpcode,  OldOpcode,	OldOpcode,  OldOpcode,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case SET_SAFETYSTOP_STAT:

        NewOpcode = Opcode_Matrix( S91_SET_SAFETYSTOP,  DataDec,  DataInc, OldOpcode, SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SafetyStopMode = (NVD_status_t)SettingData(GUI_SafetyStopMode, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_SafetyStopMode == NVD_SET)
                NewOpcode = SET_SAFETYSTOP_DEPTHT;
            else
            {
                SCUBA_Set.SafetyStopMode = GUI_SafetyStopMode;
                EE_SaveReq(EE_SCUBASET);
                NewOpcode = S91_SET_SAFETYSTOP; 						// return to menu
            }
            break;
        }
        break;

    case SET_SAFETYSTOP_DEPTHT:

        NewOpcode = Opcode_Matrix( SET_SAFETYSTOP_STAT,  DataDec,  DataInc,	OldOpcode,  SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //SAFETYSTOP_DEPTH_FT = (uint16_t)SettingData(SAFETYSTOP_DEPTH_FT, 20, 10, 5, data_type);
        //NewOpcode = OldOpcode;

        switch (NewOpcode)
        {
        case DataInc:
            if(UNITS==NVD_IMPERIAL)
                GUI_SS_DepthFt = (uint8_t)SettingData(GUI_SS_DepthFt, 20, 10, 5, data_increase);
            else
                GUI_SS_DepthM = (uint8_t)SettingData(GUI_SS_DepthM, 6,  3, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_SS_DepthFt = (uint8_t)SettingData(GUI_SS_DepthFt, 20, 10, 5, data_decrease);
            else
                GUI_SS_DepthM = (uint8_t)SettingData(GUI_SS_DepthM, 6,  3, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(UNITS==NVD_IMPERIAL)
                SCUBA_Set.SS_DepthFt = GUI_SS_DepthFt;  // save new value
            else
                SCUBA_Set.SS_DepthM  = GUI_SS_DepthM;   // save new value

            GUI_SafetyStopMode = NVD_ON;
            SAFETYSTOP_STAT = GUI_SafetyStopMode;
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = SET_SAFETYSTOP_TIME;            // return to menu
            break;
        }
        break;


    case SET_SAFETYSTOP_TIME:

        NewOpcode = Opcode_Matrix( SET_SAFETYSTOP_DEPTHT,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //NewOpcode = OldOpcode;

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SafetyStopMin = (uint8_t)SettingData(GUI_SafetyStopMin, 5, 3, 2, data_increase);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:

            GUI_SafetyStopMode = NVD_ON;
            SAFETYSTOP_STAT = GUI_SafetyStopMode;
            SAFETYSTOP_TIME = GUI_SafetyStopMin;  // save new value
            EE_SaveReq(EE_SCUBASET);              // save to EE
            NewOpcode = S91_SET_SAFETYSTOP;       // return to menu
            break;
        }
        break;

    case LASTSTOPDEPTH_SETPOINTS:

        NewOpcode = Opcode_Matrix( S96_SET_LASTSTOPDEPTH,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);
        //DEEPSTOP_STAT = (DEEPSTOP_STAT==NVD_ON)? NVD_OFF:NVD_ON;
        //NewOpcode = OldOpcode;

        switch (NewOpcode)
        {
        case DataInc:
            if(UNITS==NVD_IMPERIAL)
                GUI_LastStopFt = (uint8_t)SettingData(GUI_LastStopFt, 20, 10, 10, data_increase);
            else
                GUI_LastStopM = (uint8_t)SettingData(GUI_LastStopM, 6,  3, 3, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_LastStopFt = (uint8_t)SettingData(GUI_LastStopFt, 20, 10, 10, data_decrease);
            else
                GUI_LastStopM = (uint8_t)SettingData(GUI_LastStopM, 6,  3, 3, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(UNITS==NVD_IMPERIAL)
                SCUBA_Set.LastStopFt = GUI_LastStopFt;  // save new value
            else
                SCUBA_Set.LastStopM  = GUI_LastStopM;  // save new value

            EE_SaveReq(EE_SCUBASET);                // save to EE
            NewOpcode = S96_SET_LASTSTOPDEPTH;            // return to menu
            break;
        }
        break;


    /*
              // Assign Gas Tank 1 to 6's On/Off status according to current EEPROM record
              GUI_SetPoints_Gas_CC[1] = GUI_Tank1_ON;
              GUI_SetPoints_Gas_CC[2] = GUI_Tank2_ON;
              GUI_SetPoints_Gas_CC[3] = GUI_Tank3_ON;
              GUI_SetPoints_Gas_CC[4] = GUI_Tank4_ON;
              GUI_SetPoints_Gas_CC[5] = GUI_Tank5_ON;
              GUI_SetPoints_Gas_CC[6] = GUI_Tank6_ON;

              GUI_ShowTankNum = 1;
              for(i=1;i<=6;i++)
              {
                GUI_FO2_Gas_CC[i]      = SCUBA_Set.FO2A[i];
                GUI_FHe_Gas_CC[i]      = SCUBA_Set.FHeA[i];
                GUI_NumOfTMT_Gas_CC[i] = SCUBA_Set.GASTMT[i];
              }

    */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SET_GAS
    case S70_SET_GAS_01:

        if(DSX_Opcode != pre_DSX_Opcode)        // whenever new visit (revisit) here, refresh GUI Info according to TRIMIX data
            Update_GUI_GasInfo();

        if(BackupOpcode ==S42_SET_GASES)
        {
            /*set gas on surface*/
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_O2_ANALYZER,  S70_SET_GAS_02,	 OldOpcode,	SaveAndDone, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if( ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
                 ||((BackupOpcode == SETGASES_SET_CC_GASES)||(BackupOpcode == SETGASES_SET_BO_GASES)) )
        {
            /*set gas on surface*/
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_06,  S70_SET_GAS_02,	 OldOpcode,	SaveAndDone, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else
        {
            /*set gas on under water*/
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_O2_ANALYZER,  S70_SET_GAS_02,	 OldOpcode,	SaveAndDone, 	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        }


        GUI_ShowTankNum = 1;    // GUI marker for the number of selected tank
        if(CC_MODE)
        {
            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_01;
            }
        }
        else if(OC_MODE)
        {
            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_01;
            }
        }
        else if(SM_MODE)
        {
            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_01;
            }
        }
        else if(BO_MODE)
        {
            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_01;
            }
        }

        if(NewOpcode == SaveAndDone) {
            if(SM_MODE &&(GUI_ShowTankNum ==1)) {
                NewOpcode = S72_SET_GAS_FO2_01;
                GUI_SetPoints_Gas_SM[1] = NVD_ON;
                GUI_SetPoints_Gas_SM[2] = NVD_ON;
            }
            else {
                NewOpcode = S71_SET_GAS_STAT_01;
            }
        }
        break;

    case S70_SET_GAS_02:
        if(BackupOpcode ==S42_SET_GASES) {

            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_01,  S70_SET_GAS_03,	 OldOpcode,	SaveAndDone, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_01,  S70_SET_GAS_03,	 OldOpcode,	SaveAndDone, 	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        }
        GUI_ShowTankNum = 2;    // GUI marker for the number of selected tank

        if(CC_MODE)
        {
            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas2;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_OFF;

            GUI_FO2_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }
        else if(OC_MODE)
        {
            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas2;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_OC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }
        else if(SM_MODE)
        {
            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas2;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_SM[GUI_ShowTankNum])
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }
        else if(BO_MODE)
        {
            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas2;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_BO[GUI_ShowTankNum])
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }

        if(NewOpcode == SaveAndDone) {
            if(SM_MODE &&(GUI_ShowTankNum ==2)) {
                NewOpcode = S72_SET_GAS_FO2_02;
                GUI_SetPoints_Gas_SM[1] = NVD_ON;
                GUI_SetPoints_Gas_SM[2] = NVD_ON;
            }
            else {
                NewOpcode = S71_SET_GAS_STAT_02;
            }
        }

        break;

    case S70_SET_GAS_03:
        if(BackupOpcode ==S42_SET_GASES) {

            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_02,  S70_SET_GAS_04,	 OldOpcode,	S71_SET_GAS_STAT_03, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_02,  S70_SET_GAS_04,	 OldOpcode,	S71_SET_GAS_STAT_03, 	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        }
        GUI_ShowTankNum = 3;    // GUI marker for the number of selected tank

        if(CC_MODE)
        {
            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas3;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_03;
            }
        }
        else if(OC_MODE)
        {
            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas3;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_OC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_03;
            }
        }
        else if(SM_MODE)
        {
            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas3;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_SM[GUI_ShowTankNum])
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_03;
            }
        }
        else if(BO_MODE)
        {
            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas3;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_BO[GUI_ShowTankNum])
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }

        break;

    case S70_SET_GAS_04:
        if(BackupOpcode ==S42_SET_GASES)
        {

            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_03,  S70_SET_GAS_05,	 OldOpcode,	S71_SET_GAS_STAT_04, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_03,  S70_SET_GAS_05,	 OldOpcode,	S71_SET_GAS_STAT_04, 	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        }
        GUI_ShowTankNum = 4;    // GUI marker for the number of selected tank

        if(CC_MODE)
        {
            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas4;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_CC[GUI_ShowTankNum]      = TRIMIX_Set.CC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_CC[GUI_ShowTankNum]      = TRIMIX_Set.CC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum] = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_04;
            }
        }
        else if(OC_MODE)
        {
            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas4;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_OC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_04;
            }
        }
        else if(SM_MODE)
        {
            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas4;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_SM[GUI_ShowTankNum])
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_04;
            }
        }
        else if(BO_MODE)
        {
            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas4;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_BO[GUI_ShowTankNum])
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }
        break;

    case S70_SET_GAS_05:
        if(BackupOpcode ==S42_SET_GASES)
        {

            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_04,  S70_SET_GAS_06,	 OldOpcode,	S71_SET_GAS_STAT_05, 	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_04,  S70_SET_GAS_06,	 OldOpcode,	S71_SET_GAS_STAT_05, 	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        }
        GUI_ShowTankNum = 5;    // GUI marker for the number of selected tank

        if(CC_MODE)
        {
            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas5;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_05;
            }
        }
        else if(OC_MODE)
        {
            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas5;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_OC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_05;
            }
        }
        else if(SM_MODE)
        {
            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas5;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_SM[GUI_ShowTankNum])
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_05;
            }
        }
        else if(BO_MODE)
        {
            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas5;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_BO[GUI_ShowTankNum])
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }
        break;

    case S70_SET_GAS_06:
        if(BackupOpcode ==S42_SET_GASES)
        {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_05,	S70_O2_ANALYZER,    OldOpcode, SaveAndDone,	  ReturnToMainPage(), OldOpcode, OldOpcode,   OldOpcode);
        }
        else if( ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
                 ||((BackupOpcode == SETGASES_SET_CC_GASES)||(BackupOpcode == SETGASES_SET_BO_GASES)) )
        {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_05,	S70_SET_GAS_01,    OldOpcode, SaveAndDone,	  ReturnToMainPage(), OldOpcode, OldOpcode,   OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( BackupOpcode,  S70_SET_GAS_05,	S70_O2_ANALYZER,    OldOpcode, SaveAndDone,	  OpcodeForR2s, OldOpcode, OldOpcode,   OldOpcode);
        }
        GUI_ShowTankNum = 6;    // GUI marker for the number of selected tank

        if(CC_MODE)
        {
            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas6;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_CC[GUI_ShowTankNum]        = TRIMIX_Set.CC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_06;
            }
        }
        else if(OC_MODE)
        {
            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas6;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_OC[GUI_ShowTankNum])
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_OC[GUI_ShowTankNum]     = TRIMIX_Set.OC_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_06;
            }
        }
        else if(SM_MODE)
        {
            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas6;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_SM[GUI_ShowTankNum])
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_SM[GUI_ShowTankNum]     = TRIMIX_Set.SM_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_06;
            }
        }
        else if(BO_MODE)
        {
            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas6;		// 1: Gas ON;	0: Gas OFF

            if(GUI_SetPoints_Gas_BO[GUI_ShowTankNum])
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_ON;
            else
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = NVD_OFF;
            GUI_FO2_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FO2[GUI_ShowTankNum];
            GUI_FHe_Gas_BO[GUI_ShowTankNum]     = TRIMIX_Set.BO_FHe[GUI_ShowTankNum];
            GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum];

            if(FHE_ZERO_WARNING == TRUE) {
                FHE_ZERO_WARNING = FALSE;
                NewOpcode = S73_SET_GAS_FHe_02;
            }
        }

        if(CC_MODE &&(GUI_ShowTankNum ==6)) {
            GUI_FO2_Gas_CC[6] = 100;
            GUI_FHe_Gas_CC[6] = 0;
            TRIMIX_Set.CC_FO2[6] = 100;
            TRIMIX_Set.CC_FHe[6] = 0;

        }
        if(NewOpcode == SaveAndDone) {
            if(CC_MODE &&(GUI_ShowTankNum ==6)) {
                NewOpcode = S74_SET_GAS_TMT_06;
            }
            else {
                NewOpcode = S71_SET_GAS_STAT_06;
            }

        }

        break;

    case S70_O2_ANALYZER:
        //BackupOpcode = S70_O2_ANALYZER;
        NewOpcode = Opcode_Matrix( BackupOpcode,	S70_SET_GAS_06,  S70_SET_GAS_01,	 OldOpcode, S462_O2ANALYZER_CALIBRATE,   ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        if(NewOpcode == S462_O2ANALYZER_CALIBRATE) {
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_MAX;
            SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_OFF;
            if(BackupOpcode == DIVEMENU_SETGASES)
            {
                NewOpcode = S70_O2_ANALYZER;
            }
        }

        break;



    case S71_SET_GAS_STAT_01:
    case S71_SET_GAS_STAT_02:
    case S71_SET_GAS_STAT_03:
    case S71_SET_GAS_STAT_04:
    case S71_SET_GAS_STAT_05:
    case S71_SET_GAS_STAT_06:
        /*pybass SET STAT if underwater and STAT =OFF*/
        if(BackupOpcode == DIVEMENU_SETGASES)
        {
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_ShowTankNum] == NVD_OFF)) {
                NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);
            }
            else if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_ShowTankNum] == NVD_ON)) {
                NewOpcode = (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1);
            }

            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_ShowTankNum] == NVD_OFF)) {
                NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_ShowTankNum] == NVD_ON)) {
                NewOpcode = (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1);
            }

            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_ShowTankNum] == NVD_OFF)) {
                NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_ShowTankNum] == NVD_ON)) {
                NewOpcode = (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1);
            }

            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_ShowTankNum] == NVD_OFF)) {
                NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_ShowTankNum] == NVD_ON)) {
                NewOpcode = (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1);
            }

            if(FindGasNumOfDiveMode(DIVE_MODE) == GUI_ShowTankNum) { // can not set actual gas underwater
                NewOpcode = D41_ACTUAL_GAS_WARNING;
            }

        }
        else {
            if((FindGasNumOfDiveMode(DIVE_MODE) == GUI_ShowTankNum)&&(BackupOpcode == DIVEMENU_SETGASES)) { // can not set actual gas underwater
                NewOpcode = D41_ACTUAL_GAS_WARNING;
            }
            else {

                NewOpcode = Opcode_Matrix(CheckConditions,  DataDec,	DataInc,  OldOpcode,	SaveAndDone,   ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);
                switch (NewOpcode)
                {

                case CheckConditions:
                    Update_GUI_GasInfo();
                    NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);
                    break;


                case DataInc:
                    if(CC_MODE &&(GUI_ShowTankNum ==6)) {
                        GUI_SetPoints_Gas_CC[6] = NVD_ON;
                    }
                    else {
                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_CC[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_increase);
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_BO[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_increase);
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_OC[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_increase);
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_SM[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_increase);
                        }
                    }

                    NewOpcode = OldOpcode;
                    break;
                case DataDec:
                    if(CC_MODE &&(GUI_ShowTankNum ==6)) {
                        GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = NVD_ON;
                    }
                    else {
                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_CC[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_decrease);
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_BO[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_decrease);
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_OC[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_decrease);
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[GUI_ShowTankNum] = (NVD_status_t)SettingData(GUI_SetPoints_Gas_SM[GUI_ShowTankNum], NVD_SET, NVD_OFF, 1, data_decrease);
                        }
                    }
                    NewOpcode = OldOpcode;
                    break;
                case SaveAndDone:
                    if(GUI_SetPoints_Gas_CC[GUI_ShowTankNum]==NVD_SET ||GUI_SetPoints_Gas_OC[GUI_ShowTankNum]==NVD_SET||GUI_SetPoints_Gas_SM[GUI_ShowTankNum]==NVD_SET||GUI_SetPoints_Gas_BO[GUI_ShowTankNum]==NVD_SET)
                    {
                        NewOpcode = (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1);				  // move to SP_SET
                    }
                    else
                    {
                        switch(GUI_ShowTankNum)
                        {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        default:
                        {
                            if(CC_MODE)
                            {
                                if((GUI_SetPoints_Gas_CC[GUI_ShowTankNum]==NVD_OFF)&&(FindGasNumOfDiveMode(DIVE_MODE) == GUI_ShowTankNum))
                                {
                                    NewOpcode = S77_ACTUAL_GAS_WARNING;		   // do not change to OFF, show WARNING (actual gas cannot be OFF)
                                    GUI_SetPoints_Gas_CC[GUI_ShowTankNum]=NVD_ON;
                                }
                                else {
                                    if(GUI_ShowTankNum==1) {
                                        TRIMIX_Set.CC_Active.Gas1 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==2) {
                                        TRIMIX_Set.CC_Active.Gas2 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==3) {
                                        TRIMIX_Set.CC_Active.Gas3 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==4) {
                                        TRIMIX_Set.CC_Active.Gas4 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==5) {
                                        TRIMIX_Set.CC_Active.Gas5 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==6) {
                                        TRIMIX_Set.CC_Active.Gas6 = GUI_SetPoints_Gas_CC[GUI_ShowTankNum];
                                    }


                                    NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+(GUI_ShowTankNum-1));

                                }
                            }
                            else if(BO_MODE)
                            {
                                if(GUI_SetPoints_Gas_BO[(uint8_t)TANK_1]==NVD_OFF)
                                {
                                    NewOpcode = S77_ACTUAL_GAS_WARNING;		   // do not change to OFF, show WARNING (actual gas cannot be OFF)
                                    GUI_SetPoints_Gas_BO[(uint8_t)TANK_1]=NVD_ON;
                                }
                                else {
                                    if(GUI_ShowTankNum==1) {
                                        TRIMIX_Set.BO_Active.Gas1 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==2) {
                                        TRIMIX_Set.BO_Active.Gas2 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==3) {
                                        TRIMIX_Set.BO_Active.Gas3 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==4) {
                                        TRIMIX_Set.BO_Active.Gas4 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==5) {
                                        TRIMIX_Set.BO_Active.Gas5 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==6) {
                                        TRIMIX_Set.BO_Active.Gas6 = GUI_SetPoints_Gas_BO[GUI_ShowTankNum];
                                    }

                                    NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+(GUI_ShowTankNum-1));
                                }
                            }
                            else if(OC_MODE)
                            {
                                if((GUI_SetPoints_Gas_OC[GUI_ShowTankNum]==NVD_OFF)&&(FindGasNumOfDiveMode(DIVE_MODE) == GUI_ShowTankNum))
                                {
                                    NewOpcode = S77_ACTUAL_GAS_WARNING;		   // do not change to OFF, show WARNING (actual gas cannot be OFF)
                                    GUI_SetPoints_Gas_OC[GUI_ShowTankNum]=NVD_ON;
                                }
                                else {

                                    if(GUI_ShowTankNum==1) {
                                        TRIMIX_Set.OC_Active.Gas1 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==2) {
                                        TRIMIX_Set.OC_Active.Gas2 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==3) {
                                        TRIMIX_Set.OC_Active.Gas3 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==4) {
                                        TRIMIX_Set.OC_Active.Gas4 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==5) {
                                        TRIMIX_Set.OC_Active.Gas5 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==6) {
                                        TRIMIX_Set.OC_Active.Gas6 = GUI_SetPoints_Gas_OC[GUI_ShowTankNum];
                                    }
                                    NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+(GUI_ShowTankNum-1));

                                }
                            }
                            else if(SM_MODE)
                            {
                                if((GUI_SetPoints_Gas_SM[GUI_ShowTankNum]==NVD_OFF)&&(FindGasNumOfDiveMode(DIVE_MODE) == GUI_ShowTankNum))
                                {
                                    NewOpcode = S77_ACTUAL_GAS_WARNING;		   // do not change to OFF, show WARNING (actual gas cannot be OFF)
                                    GUI_SetPoints_Gas_SM[GUI_ShowTankNum]=NVD_ON;
                                }
                                else {

                                    if(GUI_ShowTankNum==1) {
                                        TRIMIX_Set.SM_Active.Gas1 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==2) {
                                        TRIMIX_Set.SM_Active.Gas2 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==3) {
                                        TRIMIX_Set.SM_Active.Gas3 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==4) {
                                        TRIMIX_Set.SM_Active.Gas4 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==5) {
                                        TRIMIX_Set.SM_Active.Gas5 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    else if(GUI_ShowTankNum==6) {
                                        TRIMIX_Set.SM_Active.Gas6 = GUI_SetPoints_Gas_SM[GUI_ShowTankNum];
                                    }
                                    NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+(GUI_ShowTankNum-1));

                                }
                            }
                        }

                        break;

                        }
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                    }
                    break;
                }

            }

        }

        break;


    case S77_ACTUAL_GAS_WARNING:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1), (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1),  (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1), 	   (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1),  (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1), ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);
        break;

    case D41_ACTUAL_GAS_WARNING:
        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1), (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1),  (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1),	   (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1),  (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1), OpcodeForR2s, OldOpcode, OldOpcode,	OldOpcode);
        break;



    case S72_SET_GAS_FO2_01:
    case S72_SET_GAS_FO2_02:
    case S72_SET_GAS_FO2_03:
    case S72_SET_GAS_FO2_04:
    case S72_SET_GAS_FO2_05:
    case S72_SET_GAS_FO2_06:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S71_SET_GAS_STAT_01+GUI_ShowTankNum-1),  DataDec,	DataInc,  ScrollInc,  SaveAndDone,	  ReturnToMainPage(), OldOpcode, OldOpcode,   OldOpcode);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(CC_MODE &&(GUI_ShowTankNum ==6)) {
                GUI_FO2_Gas_CC[6] = 100;
                TRIMIX_Set.CC_FO2[6] = 100;
            }
            else {
                if(CC_MODE) {
                    GUI_FO2_Gas_CC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_CC[GUI_ShowTankNum], (100-GUI_FHe_Gas_CC[GUI_ShowTankNum]), 7, 1, data_increase);
                }
                else if(BO_MODE) {
                    GUI_FO2_Gas_BO[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_BO[GUI_ShowTankNum], (100-GUI_FHe_Gas_BO[GUI_ShowTankNum]), 7, 1, data_increase);
                }
                else if(OC_MODE) {
                    GUI_FO2_Gas_OC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_OC[GUI_ShowTankNum], (100-GUI_FHe_Gas_OC[GUI_ShowTankNum]), 7, 1, data_increase);
                }
                else if(SM_MODE) {
                    GUI_FO2_Gas_SM[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_SM[GUI_ShowTankNum], (100-GUI_FHe_Gas_SM[GUI_ShowTankNum]), 7, 1, data_increase);
                }
            }

            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(CC_MODE &&(GUI_ShowTankNum ==6)) {
                GUI_FO2_Gas_CC[6] = 100;
            }
            else {
                if(CC_MODE) {
                    GUI_FO2_Gas_CC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_CC[GUI_ShowTankNum], (100-GUI_FHe_Gas_CC[GUI_ShowTankNum]), 7, 1, data_decrease);
                }
                else if(BO_MODE) {
                    GUI_FO2_Gas_BO[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_BO[GUI_ShowTankNum], (100-GUI_FHe_Gas_BO[GUI_ShowTankNum]), 7, 1, data_decrease);
                }
                else if(OC_MODE) {
                    GUI_FO2_Gas_OC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_OC[GUI_ShowTankNum], (100-GUI_FHe_Gas_OC[GUI_ShowTankNum]), 7, 1, data_decrease);
                }
                else if(SM_MODE) {
                    GUI_FO2_Gas_SM[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FO2_Gas_SM[GUI_ShowTankNum], (100-GUI_FHe_Gas_SM[GUI_ShowTankNum]), 7, 1, data_decrease);
                }
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
        {
            if(CC_MODE)
            {
                TRIMIX_Set.CC_FO2[GUI_ShowTankNum] = GUI_FO2_Gas_CC[GUI_ShowTankNum];
            }
            else if(BO_MODE)
            {
                TRIMIX_Set.BO_FO2[GUI_ShowTankNum] = GUI_FO2_Gas_BO[GUI_ShowTankNum];
            }
            else if(OC_MODE)
            {
                TRIMIX_Set.OC_FO2[GUI_ShowTankNum] = GUI_FO2_Gas_OC[GUI_ShowTankNum];
            }
            else if(SM_MODE)
            {
                TRIMIX_Set.SM_FO2[GUI_ShowTankNum] = GUI_FO2_Gas_SM[GUI_ShowTankNum];

                if((GUI_ShowTankNum ==1)||(GUI_ShowTankNum ==2)) {
                    GUI_FO2_Gas_SM[1] = GUI_FO2_Gas_SM[GUI_ShowTankNum];
                    GUI_FO2_Gas_SM[2] = GUI_FO2_Gas_SM[GUI_ShowTankNum];
                    TRIMIX_Set.SM_FO2[1] = GUI_FO2_Gas_SM[GUI_ShowTankNum];
                    TRIMIX_Set.SM_FO2[2] = GUI_FO2_Gas_SM[GUI_ShowTankNum];
                }
            }
        }

        Update_Algo();      // Acknowledge DiveAlgo for the new change
        EE_SaveReq(EE_SCUBASET);
        EE_SaveReq(EE_TRIMIXSET);
        NewOpcode = (DSX_OPCODE_t)(S73_SET_GAS_FHe_01+GUI_ShowTankNum-1);                // return to menu
        break;
        }
        break;

    case S73_SET_GAS_FHe_01:
    case S73_SET_GAS_FHe_02:
    case S73_SET_GAS_FHe_03:
    case S73_SET_GAS_FHe_04:
    case S73_SET_GAS_FHe_05:
    case S73_SET_GAS_FHe_06:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S72_SET_GAS_FO2_01+GUI_ShowTankNum-1),  DataDec,  DataInc,  ScrollInc,   SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:

            if(CC_MODE) {
                GUI_FHe_Gas_CC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_CC[GUI_ShowTankNum], (100-GUI_FO2_Gas_CC[GUI_ShowTankNum]), 0, 1, data_increase);
            }
            else if(BO_MODE) {
                GUI_FHe_Gas_BO[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_BO[GUI_ShowTankNum], (100-GUI_FO2_Gas_BO[GUI_ShowTankNum]), 0, 1, data_increase);
            }
            else if(OC_MODE) {
                GUI_FHe_Gas_OC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_OC[GUI_ShowTankNum], (100-GUI_FO2_Gas_OC[GUI_ShowTankNum]), 0, 1, data_increase);
            }
            else if(SM_MODE) {
                GUI_FHe_Gas_SM[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_SM[GUI_ShowTankNum], (100-GUI_FO2_Gas_SM[GUI_ShowTankNum]), 0, 1, data_increase);
            }
            NewOpcode = OldOpcode;
            break;
        case DataDec:

            if(CC_MODE) {
                GUI_FHe_Gas_CC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_CC[GUI_ShowTankNum], (100-GUI_FO2_Gas_CC[GUI_ShowTankNum]), 0, 1, data_decrease);
            }
            else if(BO_MODE) {
                GUI_FHe_Gas_BO[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_BO[GUI_ShowTankNum], (100-GUI_FO2_Gas_BO[GUI_ShowTankNum]), 0, 1, data_decrease);
            }
            else if(OC_MODE) {
                GUI_FHe_Gas_OC[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_OC[GUI_ShowTankNum], (100-GUI_FO2_Gas_OC[GUI_ShowTankNum]), 0, 1, data_decrease);
            }
            else if(SM_MODE) {
                GUI_FHe_Gas_SM[GUI_ShowTankNum] = (uint16_t)SettingData(GUI_FHe_Gas_SM[GUI_ShowTankNum], (100-GUI_FO2_Gas_SM[GUI_ShowTankNum]), 0, 1, data_decrease);
            }

            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(CC_MODE&&(GUI_FHe_Gas_CC[GUI_ShowTankNum] ==0)&&(GUI_FO2_Gas_CC[GUI_ShowTankNum]<21)) {
                /*warning FHE = 0, S79*/
                NewOpcode = S79_SET_GAS_FHE_WARNING;
            }
            else if(BO_MODE&&(GUI_FHe_Gas_BO[GUI_ShowTankNum] ==0)&&(GUI_FO2_Gas_BO[GUI_ShowTankNum]<21)) {
                /*warning FHE = 0, S79*/
                NewOpcode = S79_SET_GAS_FHE_WARNING;
            }
            else if(OC_MODE&&(GUI_FHe_Gas_OC[GUI_ShowTankNum] ==0)&&(GUI_FO2_Gas_OC[GUI_ShowTankNum]<21)) {
                /*warning FHE = 0, S79*/
                NewOpcode = S79_SET_GAS_FHE_WARNING;
            }
            else if(SM_MODE&&(GUI_FHe_Gas_SM[GUI_ShowTankNum] ==0)&&(GUI_FO2_Gas_SM[GUI_ShowTankNum]<21)) {
                /*warning FHE = 0, S79*/
                NewOpcode = S79_SET_GAS_FHE_WARNING;
            }
            else
            {
                if(CC_MODE)
                {
                    TRIMIX_Set.CC_FHe[GUI_ShowTankNum] = GUI_FHe_Gas_CC[GUI_ShowTankNum];
                }
                else if(BO_MODE)
                {
                    TRIMIX_Set.BO_FHe[GUI_ShowTankNum] = GUI_FHe_Gas_BO[GUI_ShowTankNum];
                }
                else if(OC_MODE)
                {
                    TRIMIX_Set.OC_FHe[GUI_ShowTankNum] = GUI_FHe_Gas_OC[GUI_ShowTankNum];
                }
                else if(SM_MODE)
                {
                    TRIMIX_Set.SM_FHe[GUI_ShowTankNum] = GUI_FHe_Gas_SM[GUI_ShowTankNum];

                    if((GUI_ShowTankNum ==1)||(GUI_ShowTankNum ==2))
                    {
                        GUI_FHe_Gas_SM[1] = GUI_FHe_Gas_SM[GUI_ShowTankNum];
                        GUI_FHe_Gas_SM[2] = GUI_FHe_Gas_SM[GUI_ShowTankNum];
                        TRIMIX_Set.SM_FHe[1] = GUI_FHe_Gas_SM[GUI_ShowTankNum];
                        TRIMIX_Set.SM_FHe[2] = GUI_FHe_Gas_SM[GUI_ShowTankNum];
                    }
                }
                GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InSetting();       // to start with a correct TMT Number of each mode: CC, OC, SM, GSM, or Gauge
                Update_Algo();      // Acknowledge DiveAlgo for the new change
                EE_SaveReq(EE_SCUBASET);
                EE_SaveReq(EE_TRIMIXSET);
                NewOpcode = (DSX_OPCODE_t)(S74_SET_GAS_TMT_01+GUI_ShowTankNum-1);                        // return to menu
            }
            break;
        }
        break;
    case S263_CHECKTMTLINKWITHGAS_01:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_01, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_01, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S263_CHECKTMTLINKWITHGAS_02:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_02, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_02, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S263_CHECKTMTLINKWITHGAS_03:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_03, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_03, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S263_CHECKTMTLINKWITHGAS_04:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_04, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_04, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S263_CHECKTMTLINKWITHGAS_05:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_05, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_05, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;
    case S263_CHECKTMTLINKWITHGAS_06:
        NewOpcode = Opcode_Matrix( S70_SET_GAS_06, OldOpcode, OldOpcode, OldOpcode, S70_SET_GAS_06, ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        break;

    case S74_SET_GAS_TMT_01:
    case S74_SET_GAS_TMT_02:
    case S74_SET_GAS_TMT_03:
    case S74_SET_GAS_TMT_04:
    case S74_SET_GAS_TMT_05:
    case S74_SET_GAS_TMT_06:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S73_SET_GAS_FHe_01+GUI_ShowTankNum-1),  DataDec,  DataInc,  OldOpcode, SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            if(CC_MODE) {
                GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_increase);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum];
            }
            else if(BO_MODE) {
                GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_increase);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum];
            }
            else if(OC_MODE) {
                GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_increase);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum];
            }
            else if(SM_MODE) {
                GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_increase);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum];
            }

            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(CC_MODE) {
                GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_decrease);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum];
            }
            else if(BO_MODE) {
                GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_decrease);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum];
            }
            else if(OC_MODE) {
                GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_decrease);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum];
            }
            else if(SM_MODE) {
                GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum] = (TMT_NUM_t)SettingData(GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum], TANK_6, TANK_OFF, 1, data_decrease);
                GUI_TMT_Num_InSetting = GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum];
            }
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(CC_MODE) {
                CheckTMTisDuplicate(GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum], &TMT_LINKED_MODE,&TMT_LINKED_GAS_INDEX);
            }
            else if(BO_MODE) {
                CheckTMTisDuplicate(GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum], &TMT_LINKED_MODE,&TMT_LINKED_GAS_INDEX);
            }
            else if(OC_MODE) {
                CheckTMTisDuplicate(GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum], &TMT_LINKED_MODE,&TMT_LINKED_GAS_INDEX);
            }
            else if(SM_MODE) {
                CheckTMTisDuplicate(GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum], &TMT_LINKED_MODE,&TMT_LINKED_GAS_INDEX);
            }

            if(TMT_LINKED_GAS_INDEX) {
                /*warning TMTx is linked, S75*/
                NewOpcode = S75_SET_GAS_TMT_WARNING;
            }
            else {
                if(CC_MODE) {
                    TMT_LINKED_DUPLICATE = CheckTMTisLinked(GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum]);
                }
                else if(BO_MODE) {
                    TMT_LINKED_DUPLICATE = CheckTMTisLinked(GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum]);
                }
                else if(OC_MODE) {
                    TMT_LINKED_DUPLICATE = CheckTMTisLinked(GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum]);
                }
                else if(SM_MODE) {
                    TMT_LINKED_DUPLICATE = CheckTMTisLinked(GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum]);
                }


                if(TMT_LINKED_DUPLICATE) { /*if TMT is linked, reset old linked gas*/
                    if(CC_MODE) {
                        GUI_NumOfTMT_Gas_CC[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)TANK_OFF;
                        TRIMIX_Set.CC_GASTMT[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[TMT_LINKED_DUPLICATE];	// save to EE
                    }
                    else if(BO_MODE) {
                        GUI_NumOfTMT_Gas_BO[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)TANK_OFF;
                        TRIMIX_Set.BO_GASTMT[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[TMT_LINKED_DUPLICATE];	// save to EE
                    }
                    else if(OC_MODE) {
                        GUI_NumOfTMT_Gas_OC[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)TANK_OFF;
                        TRIMIX_Set.OC_GASTMT[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[TMT_LINKED_DUPLICATE];	// save to EE
                    }
                    else if(SM_MODE) {
                        GUI_NumOfTMT_Gas_SM[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)TANK_OFF;
                        TRIMIX_Set.SM_GASTMT[TMT_LINKED_DUPLICATE] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[TMT_LINKED_DUPLICATE];	// save to EE
                    }
                }

                switch(GUI_ShowTankNum)
                {
                case 1:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[1]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas1 = true;
                        TRIMIX_Set.CC_GASTMT[1] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[1];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[1]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas1 = true;
                        TRIMIX_Set.BO_GASTMT[1] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[1];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[1]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas1 = true;
                        TRIMIX_Set.OC_GASTMT[1] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[1];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[1]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas1 = true;
                        TRIMIX_Set.SM_GASTMT[1] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[1];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_01;                // return to menu


                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_01;
                        }
                    }
                    break;
                case 2:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[2]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas2 = true;
                        TRIMIX_Set.CC_GASTMT[2] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[2];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[2]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas2 = true;
                        TRIMIX_Set.BO_GASTMT[2] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[2];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[2]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas2 = true;
                        TRIMIX_Set.OC_GASTMT[2] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[2];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[2]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas2 = true;
                        TRIMIX_Set.SM_GASTMT[2] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[2];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_02;                // return to menu
                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_02;
                        }
                    }
                    break;
                case 3:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[3]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas3 = true;
                        TRIMIX_Set.CC_GASTMT[3] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[3];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[3]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas3 = true;
                        TRIMIX_Set.BO_GASTMT[3] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[3];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[3]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas3 = true;
                        TRIMIX_Set.OC_GASTMT[3] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[3];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[3]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas3 = true;
                        TRIMIX_Set.SM_GASTMT[3] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[3];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_03;                // return to menu
                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_03;
                        }
                    }
                    break;
                case 4:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[4]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas4 = true;
                        TRIMIX_Set.CC_GASTMT[4] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[4];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[4]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas4 = true;
                        TRIMIX_Set.BO_GASTMT[4] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[4];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[4]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas4 = true;
                        TRIMIX_Set.OC_GASTMT[4] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[4];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[4]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas4 = true;
                        TRIMIX_Set.SM_GASTMT[4] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[4];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_04;                // return to menu
                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_04;
                        }
                    }
                    break;
                case 5:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[5]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas5 = true;
                        TRIMIX_Set.CC_GASTMT[5] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[5];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[5]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas5 = true;
                        TRIMIX_Set.BO_GASTMT[5] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[5];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[5]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas5 = true;
                        TRIMIX_Set.OC_GASTMT[5] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[5];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[5]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas5 = true;
                        TRIMIX_Set.SM_GASTMT[5] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[5];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_05;                // return to menu
                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_05;
                        }
                    }
                    break;
                case 6:
                default:
                    if(CC_MODE) {
                        GUI_SetPoints_Gas_CC[6]=NVD_ON;
                        TRIMIX_Set.CC_Active.Gas6 = true;
                        TRIMIX_Set.CC_GASTMT[6] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[6];
                    }
                    else if(BO_MODE) {
                        GUI_SetPoints_Gas_BO[6]=NVD_ON;
                        TRIMIX_Set.BO_Active.Gas6 = true;
                        TRIMIX_Set.BO_GASTMT[6] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[6];
                    }
                    else if(OC_MODE) {
                        GUI_SetPoints_Gas_OC[6]=NVD_ON;
                        TRIMIX_Set.OC_Active.Gas6 = true;
                        TRIMIX_Set.OC_GASTMT[6] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[6];
                    }
                    else if(SM_MODE) {
                        GUI_SetPoints_Gas_SM[6]=NVD_ON;
                        TRIMIX_Set.SM_Active.Gas6 = true;
                        TRIMIX_Set.SM_GASTMT[6] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[6];
                    }
                    NewOpcode = S263_CHECKTMTLINKWITHGAS_06; // return to menu
                    if(GUI_TMT_Num_InSetting ==TMT_OFF)
                    {
                        if(OpcodeForR2s>=DIVE_GAUGE_MAIN)
                        {
                            NewOpcode = DIVEMENU_SETGASES;
                        }
                        else
                        {
                            NewOpcode = S70_SET_GAS_06;
                        }
                    }

                    break;
                }
                EE_SaveReq(EE_SCUBASET);
                EE_SaveReq(EE_TRIMIXSET);
            }
            break;
        }
        break;

    case S75_SET_GAS_TMT_WARNING:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S74_SET_GAS_TMT_01+GUI_ShowTankNum-1)   , (DSX_OPCODE_t)(S74_SET_GAS_TMT_01+GUI_ShowTankNum-1),  NewOpcode, 	   OldOpcode,  SaveAndDone , ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        if(NewOpcode == SaveAndDone) {

            NewOpcode = (DSX_OPCODE_t)(S70_SET_GAS_01+GUI_ShowTankNum-1);

            if(TMT_LINKED_MODE == NVD_MDCC) {
                GUI_NumOfTMT_Gas_CC[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)TANK_OFF;
                TRIMIX_Set.CC_GASTMT[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[TMT_LINKED_GAS_INDEX];    // save to EE
            }
            else if(TMT_LINKED_MODE == NVD_MDBO) {
                GUI_NumOfTMT_Gas_BO[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)TANK_OFF;
                TRIMIX_Set.BO_GASTMT[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[TMT_LINKED_GAS_INDEX];    // save to EE
            }
            else if(TMT_LINKED_MODE == NVD_MDOC) {
                GUI_NumOfTMT_Gas_OC[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)TANK_OFF;
                TRIMIX_Set.OC_GASTMT[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[TMT_LINKED_GAS_INDEX];    // save to EE
            }
            else if(TMT_LINKED_MODE == NVD_MDSM) {
                GUI_NumOfTMT_Gas_SM[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)TANK_OFF;
                TRIMIX_Set.SM_GASTMT[TMT_LINKED_GAS_INDEX] 	= (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[TMT_LINKED_GAS_INDEX];    // save to EE
            }


            if(CC_MODE)
            {
                GUI_SetPoints_Gas_CC[GUI_ShowTankNum]=NVD_ON;
                TRIMIX_Set.CC_GASTMT[GUI_ShowTankNum] = (TMT_NUM_t)GUI_NumOfTMT_Gas_CC[GUI_ShowTankNum];
                TRIMIX_Set.CC_Active.Gas1 = GUI_SetPoints_Gas_CC[1];
                TRIMIX_Set.CC_Active.Gas2 = GUI_SetPoints_Gas_CC[2];
                TRIMIX_Set.CC_Active.Gas3 = GUI_SetPoints_Gas_CC[3];
                TRIMIX_Set.CC_Active.Gas4 = GUI_SetPoints_Gas_CC[4];
                TRIMIX_Set.CC_Active.Gas5 = GUI_SetPoints_Gas_CC[5];
                TRIMIX_Set.CC_Active.Gas6 = GUI_SetPoints_Gas_CC[6];
            }
            else if(BO_MODE)
            {
                GUI_SetPoints_Gas_BO[GUI_ShowTankNum]=NVD_ON;
                TRIMIX_Set.BO_GASTMT[GUI_ShowTankNum] = (TMT_NUM_t)GUI_NumOfTMT_Gas_BO[GUI_ShowTankNum];
                TRIMIX_Set.BO_Active.Gas1 = GUI_SetPoints_Gas_BO[1];
                TRIMIX_Set.BO_Active.Gas2 = GUI_SetPoints_Gas_BO[2];
                TRIMIX_Set.BO_Active.Gas3 = GUI_SetPoints_Gas_BO[3];
                TRIMIX_Set.BO_Active.Gas4 = GUI_SetPoints_Gas_BO[4];
                TRIMIX_Set.BO_Active.Gas5 = GUI_SetPoints_Gas_BO[5];
                TRIMIX_Set.BO_Active.Gas6 = GUI_SetPoints_Gas_BO[6];
            }
            else if(OC_MODE)
            {
                GUI_SetPoints_Gas_OC[GUI_ShowTankNum]=NVD_ON;
                TRIMIX_Set.OC_GASTMT[GUI_ShowTankNum] = (TMT_NUM_t)GUI_NumOfTMT_Gas_OC[GUI_ShowTankNum];
                TRIMIX_Set.OC_Active.Gas1 = GUI_SetPoints_Gas_OC[1];
                TRIMIX_Set.OC_Active.Gas2 = GUI_SetPoints_Gas_OC[2];
                TRIMIX_Set.OC_Active.Gas3 = GUI_SetPoints_Gas_OC[3];
                TRIMIX_Set.OC_Active.Gas4 = GUI_SetPoints_Gas_OC[4];
                TRIMIX_Set.OC_Active.Gas5 = GUI_SetPoints_Gas_OC[5];
                TRIMIX_Set.OC_Active.Gas6 = GUI_SetPoints_Gas_OC[6];
            }
            else if(SM_MODE)
            {
                GUI_SetPoints_Gas_SM[GUI_ShowTankNum]=NVD_ON;
                TRIMIX_Set.SM_GASTMT[GUI_ShowTankNum] = (TMT_NUM_t)GUI_NumOfTMT_Gas_SM[GUI_ShowTankNum];
                TRIMIX_Set.SM_Active.Gas1 = GUI_SetPoints_Gas_SM[1];
                TRIMIX_Set.SM_Active.Gas2 = GUI_SetPoints_Gas_SM[2];
                TRIMIX_Set.SM_Active.Gas3 = GUI_SetPoints_Gas_SM[3];
                TRIMIX_Set.SM_Active.Gas4 = GUI_SetPoints_Gas_SM[4];
                TRIMIX_Set.SM_Active.Gas5 = GUI_SetPoints_Gas_SM[5];
                TRIMIX_Set.SM_Active.Gas6 = GUI_SetPoints_Gas_SM[6];
            }

            EE_SaveReq(EE_SCUBASET);
            EE_SaveReq(EE_TRIMIXSET);
        }
        break;

    case S79_SET_GAS_FHE_WARNING:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(S73_SET_GAS_FHe_01+GUI_ShowTankNum-1)  , (DSX_OPCODE_t)(S73_SET_GAS_FHe_01+GUI_ShowTankNum-1),  NewOpcode, 	   OldOpcode,  SaveAndDone , ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        if(NewOpcode == SaveAndDone) {

            NewOpcode = (DSX_OPCODE_t)(S73_SET_GAS_FHe_01+GUI_ShowTankNum-1);
            //NewOpcode = (S70_SET_GAS_01+GUI_ShowTankNum-1);
            FHE_ZERO_WARNING = TRUE;
        }


        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // DEVICE SETTING

    case S128_DEVICE_TRANSMITTERS:

        if(pre_DSX_Opcode != DSX_Opcode)        // do following when first-time entry
        {
            // Device Settings Initializations here
            GUI_WaterType = H2OTYPE;
            GUI_Unit = (NVD_UNITS_t)UNITS;
            GUI_BluetoothState = (NVD_status_t)BLUETOOTH_STAT;
            GUI_SampleTime = SAMPLINGRATE;
            GUI_Welcome_Screen = WELCOME_SCREEN_SETPOINTS;
            GUI_TMT_Status[1] = (NVD_status_t)SCUBA_Set.TMT_On.TMT1;
            GUI_TMT_Status[2] = (NVD_status_t)SCUBA_Set.TMT_On.TMT2;
            GUI_TMT_Status[3] = (NVD_status_t)SCUBA_Set.TMT_On.TMT3;
            GUI_TMT_Status[4] = (NVD_status_t)SCUBA_Set.TMT_On.TMT4;
            GUI_TMT_Status[5] = (NVD_status_t)SCUBA_Set.TMT_On.TMT5;
            GUI_TMT_Status[6] = (NVD_status_t)SCUBA_Set.TMT_On.TMT6;
        }

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  TBD_DEVICE_WELCOMESCREEN,  S137_DEVICE_UNITS, 	   OldOpcode,  S128_TM_TMT1,   ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        if(NewOpcode == S128_TM_TMT1)
        {
            uint8_t i=0;

            for(i=1; i<=TOTAL_TANK_NUM; i++)
            {
                GUI_TMT_SerialNum[i][6] = (SCUBA_Set.TMTID[i]%10);
                GUI_TMT_SerialNum[i][5] = (SCUBA_Set.TMTID[i]%100)/10;
                GUI_TMT_SerialNum[i][4] = (SCUBA_Set.TMTID[i]%1000)/100;
                GUI_TMT_SerialNum[i][3] = (SCUBA_Set.TMTID[i]%10000)/1000;
                GUI_TMT_SerialNum[i][2] = (SCUBA_Set.TMTID[i]%100000)/10000;
                GUI_TMT_SerialNum[i][1] = (SCUBA_Set.TMTID[i]%1000000)/100000;
            }
        }
        break;
    case S137_DEVICE_UNITS:
        GUI_Unit = (NVD_UNITS_t)UNITS;

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  S128_DEVICE_TRANSMITTERS,  S139_DEVICE_WATERTYPE,	OldOpcode,  DEVICE_UNITS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S139_DEVICE_WATERTYPE:

        GUI_WaterType = H2OTYPE;
        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  S137_DEVICE_UNITS,  S141_DEVICE_SAMPLERATE,		OldOpcode,  DEVICE_WATERTYPE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S141_DEVICE_SAMPLERATE:
        GUI_SampleTime = SAMPLINGRATE;

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  S139_DEVICE_WATERTYPE,  S143_DEVICE_BLUETOOTH,	OldOpcode,  DEVICE_SAMPLERATE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S143_DEVICE_BLUETOOTH:
        GUI_BluetoothState = (NVD_status_t)BLUETOOTH_STAT;

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  S141_DEVICE_SAMPLERATE,  TBD_DEVICE_RESETSETTINGS,	OldOpcode,  DEVICE_BLUETOOTH_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DEVICE_BLUETOOTH_PASSCODE:
        GUI_BluetoothState = (NVD_status_t)BLUETOOTH_STAT;
        break;
    case TBD_DEVICE_RESETSETTINGS:
        if(pre_DSX_Opcode != DSX_Opcode)        // do following when first-time entry
        {
            // Device Settings Initializations here
            GUI_WaterType = H2OTYPE;
            GUI_Unit = (NVD_UNITS_t)UNITS;
            GUI_BluetoothState = (NVD_status_t)BLUETOOTH_STAT;
            GUI_SampleTime = SAMPLINGRATE;
            GUI_Welcome_Screen = WELCOME_SCREEN_SETPOINTS;
        }

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  S143_DEVICE_BLUETOOTH,  TBD_DEVICE_WELCOMESCREEN,	OldOpcode,  RESETSETTINGS_S1,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case TBD_DEVICE_WELCOMESCREEN:
        GUI_Welcome_Screen = WELCOME_SCREEN_SETPOINTS;

        NewOpcode = Opcode_Matrix( S128_DEVICE_SETTINGS,  TBD_DEVICE_RESETSETTINGS,  S128_DEVICE_TRANSMITTERS,	OldOpcode,  WELCOMESCREEN_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case DEVICE_UNITS_SET:

        NewOpcode = Opcode_Matrix( S137_DEVICE_UNITS,   DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_Unit = (GUI_Unit == NVD_IMPERIAL)? NVD_METRIC:NVD_IMPERIAL;
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            UNITS = GUI_Unit;
            EE_SaveReq(EE_USERSET);                   // save new value
            NewOpcode = S137_DEVICE_UNITS;            // return to menu
            break;
        }
        break;

    case DEVICE_WATERTYPE_SET:

        NewOpcode = Opcode_Matrix( S139_DEVICE_WATERTYPE,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            GUI_WaterType = (NVD_WATER_t)SettingData(GUI_WaterType, NVD_FRESH, NVD_SALT, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            GUI_WaterType = (NVD_WATER_t)SettingData(GUI_WaterType, NVD_FRESH, NVD_SALT, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            H2OTYPE = GUI_WaterType;
            EE_SaveReq(EE_USERSET);                   // save new value
            NewOpcode = S139_DEVICE_WATERTYPE;        // return to menu
            break;
        }
        break;

    case DEVICE_SAMPLERATE_SET:

        NewOpcode = Opcode_Matrix( S141_DEVICE_SAMPLERATE,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,        ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            if(GUI_SampleTime==NVD_2SEC)  GUI_SampleTime=NVD_15SEC;
            else if(GUI_SampleTime==NVD_15SEC)  GUI_SampleTime=NVD_30SEC;
            else if(GUI_SampleTime==NVD_30SEC)  GUI_SampleTime=NVD_60SEC;
            else GUI_SampleTime=NVD_2SEC;
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            if(GUI_SampleTime==NVD_30SEC)  GUI_SampleTime=NVD_15SEC;
            else if(GUI_SampleTime==NVD_60SEC)  GUI_SampleTime=NVD_30SEC;
            else if(GUI_SampleTime==NVD_2SEC)  GUI_SampleTime=NVD_60SEC;
            else GUI_SampleTime=NVD_2SEC;
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            SAMPLINGRATE = GUI_SampleTime;
            EE_SaveReq(EE_USERSET);                   // save new value
            NewOpcode = S141_DEVICE_SAMPLERATE;       // return to menu
            break;
        }
        break;

    case DEVICE_BLUETOOTH_SET:

        NewOpcode = Opcode_Matrix( S143_DEVICE_BLUETOOTH,  DataDec,  DataInc, OldOpcode,  SaveAndDone,          ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_BluetoothState = (GUI_BluetoothState==NVD_ON)? NVD_OFF:NVD_ON;
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            BLUETOOTH_STAT = GUI_BluetoothState;
            St2Ble_PowerDown();                         // R1006, added on 2023 02 06, to reset BLE chip when BLUETOOTH_STAT is updated by user
            EE_SaveReq(EE_USERSET);                   // save new value
            NewOpcode = S143_DEVICE_BLUETOOTH;        // return to menu
            break;
        }
        break;

    case RESETSETTINGS_S1:

        NewOpcode = Opcode_Matrix( TBD_DEVICE_RESETSETTINGS,  OldOpcode,  OldOpcode, OldOpcode,	RESETSETTINGS_S2, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case RESETSETTINGS_S2:

        if(!StaySameOpcodeForNSec(2))
        {
            // Start doing Manufacturer's Reset without stop and conditions
            DEV_Rec_Init (&DEV_Rec);				  // default Device Setup
            User_Set_Init (&USER_Set);				  // default User Setup
            SCUBA_Set_Init (&SCUBA_Set);			  // default Scuba Setup
            TRIMIX_Set_Init (&TRIMIX_Set);			  // default Scuba Record
            FLASH_Map_Init (&FLASH_Map);			  // default Scuba Record
            RetData_Init();
            NVD_RAMTOTAL_to_ExtEEPROM();			  // Save Default Initialization to EEPROM

            GUI_DIVE_Mode = DIVE_MODE;
            // Device Settings Initializations here
            GUI_WaterType = H2OTYPE;
            GUI_Unit = (NVD_UNITS_t)UNITS;
            GUI_BluetoothState = (NVD_status_t)BLUETOOTH_STAT;
            GUI_SampleTime = SAMPLINGRATE;
            GUI_Welcome_Screen = WELCOME_SCREEN_SETPOINTS;
            TITLE_Color = (ColorSel_t)TxtColor_UnSelect; //Default value
            GUI_SWITCH_LCD_Flip = (NVD_status_t)SWITCH_LCD_Flip;
            AsssignedCoordinated(0); //Default

            // Initialize Deco Variables
            ///////////////////////////////////////////////////////////
            //IntinalizeGasVariables();   // ALWAYS initialize Anthony's Variables for algorithm to run correctly
            //Dive_Info.StartSurfTime_s = MonotonicClock_s;
            //Dive_Info.PrevSurfTime_s = 0;
            //Dive_Info.SurfTime_s = 0;
            //Dive_Info.PrevDiveTime_s = 0;
            //Dive_Info.DiveTime_s = 0;
            NewOpcode = TBD_DEVICE_RESETSETTINGS;
            AlarmInit();
        }
        break;

    case WELCOMESCREEN_SET:

        NewOpcode = Opcode_Matrix( TBD_DEVICE_WELCOMESCREEN,  DataDec,  DataInc,	OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
            if(USER_Set.Welcome_Stat[0]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 0, 0, 1, data_increase);         // Std Welcome Only
            else if(USER_Set.Welcome_Stat[1]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 1, 0, 1, data_increase);         // Std, Upld1 Welcome Only
            else if(USER_Set.Welcome_Stat[2]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 2, 0, 1, data_increase);         // Std, Upld1, Upld2 Welcome Only
            else
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 3, 0, 1, data_increase);         // Std, Upld1, Upld2, Upld3 Welcome
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            if(USER_Set.Welcome_Stat[0]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 0, 0, 1, data_decrease);         // Std Welcome Only
            else if(USER_Set.Welcome_Stat[1]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 1, 0, 1, data_decrease);         // Std, Upld1 Welcome Only
            else if(USER_Set.Welcome_Stat[2]==0)
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 2, 0, 1, data_decrease);         // Std, Upld1, Upld2 Welcome Only
            else
                GUI_Welcome_Screen = (uint16_t)SettingData(GUI_Welcome_Screen, 3, 0, 1, data_decrease);         // Std, Upld1, Upld2, Upld3 Welcome
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            WELCOME_SCREEN_SETPOINTS = GUI_Welcome_Screen;
            EE_SaveReq(EE_USERSET);                   // save new value
            NewOpcode = TBD_DEVICE_WELCOMESCREEN;        // return to menu
            break;
        }

        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // DISPLAY SETTING
    case S162_DISPLAY_BRIGHTNESS:

        GUI_BRIGHTNESS_LV = BRIGHTNESS_LV;              // GUI Settings for BRIGHTNESS_LV
        GUI_BRIGHTNESS_DIM_MODE = BRIGHTNESS_DIM_MODE;  // GUI Settings for BRIGHTNESS_DIM_MODE
        GUI_BRIGHTNESS_DIM_TIME = BRIGHTNESS_DIM_TIME;  // GUI Settings for BRIGHTNESS_DIM_TIME
        GUI_DIM_BRIGHT_LV = DIM_BRIGHT_LV;              // GUI Settings for DIM_BRIGHT_LV
        GUI_LANG_Select = LANG_Select;                  // GUI Settings for LANG_Select
        GUI_SWITCH_LCD_Flip = (NVD_status_t)SWITCH_LCD_Flip;          // GUI settings for LCD_Flip
        BackupOpcode = S162_DISPLAY_BRIGHTNESS;

        if(SM_MODE||GSM_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S372_DISPLAY_GTR,  S164_DISPLAY_AUTODIM,	OldOpcode,  DISPLAY_BRIGHTNESS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(CC_MODE||OC_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S166_DISPLAY_MAINDISPLAY,  S164_DISPLAY_AUTODIM,	OldOpcode,  DISPLAY_BRIGHTNESS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S428_DISPLAY_EXTRALARGE,  S164_DISPLAY_AUTODIM,	OldOpcode,  DISPLAY_BRIGHTNESS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        break;
    case S164_DISPLAY_AUTODIM:
        GUI_BRIGHTNESS_DIM_MODE = BRIGHTNESS_DIM_MODE;
        GUI_BRIGHTNESS_DIM_TIME = BRIGHTNESS_DIM_TIME;

        NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S162_DISPLAY_BRIGHTNESS,  S173_DISPLAY_TITLESCOLOR,	OldOpcode,  DISPLAY_AUTODIM__STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S173_DISPLAY_TITLESCOLOR:
        NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S164_DISPLAY_AUTODIM,  S179_DISPLAY_LANGUAGE,	OldOpcode,  DISPLAY_TITLESCOLOR_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S179_DISPLAY_LANGUAGE:
        GUI_LANG_Select = LANG_Select;

        NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S173_DISPLAY_TITLESCOLOR,  S178_DISPLAY_FLIPSCREEN,	OldOpcode,  DISPLAY_LANGUAGE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        BackupOpcode = S179_DISPLAY_LANGUAGE;

        break;
    case S178_DISPLAY_FLIPSCREEN:
        GUI_SWITCH_LCD_Flip = (NVD_status_t)SWITCH_LCD_Flip;

        if(GSM_MODE||GAUGE_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S179_DISPLAY_LANGUAGE,  S428_DISPLAY_EXTRALARGE, OldOpcode,  DISPLAY_FLIPSCREEN_SET, ReturnToMainPage(), OldOpcode, OldOpcode,   OldOpcode);
        }
        else {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S179_DISPLAY_LANGUAGE,  S166_DISPLAY_MAINDISPLAY,	OldOpcode,	DISPLAY_FLIPSCREEN_SET, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }

        break;

    case S428_DISPLAY_EXTRALARGE:

        if(GSM_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S178_DISPLAY_FLIPSCREEN,  S372_DISPLAY_GTR,	OldOpcode,  S428_DISPLAY_EXTRALARGE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(GAUGE_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S178_DISPLAY_FLIPSCREEN,  S162_DISPLAY_BRIGHTNESS,	OldOpcode,  S428_DISPLAY_EXTRALARGE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }

        break;

    case S166_DISPLAY_MAINDISPLAY:

        if(SM_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S178_DISPLAY_FLIPSCREEN,  S372_DISPLAY_GTR,	OldOpcode,	MAINDISPLAY_LEFT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(CC_MODE||OC_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S178_DISPLAY_FLIPSCREEN,  S162_DISPLAY_BRIGHTNESS,	OldOpcode,	MAINDISPLAY_LEFT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        break;

    case S372_DISPLAY_GTR:

        if(GSM_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S428_DISPLAY_EXTRALARGE,  S162_DISPLAY_BRIGHTNESS,	OldOpcode,	S373_DISPLAY_GTR_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(SM_MODE) {
            NewOpcode = Opcode_Matrix( S161_DISPLAY_SETTINGS,  S166_DISPLAY_MAINDISPLAY,  S162_DISPLAY_BRIGHTNESS,	OldOpcode,	S373_DISPLAY_GTR_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }

        break;

    case S428_DISPLAY_EXTRALARGE_SET:

        NewOpcode = Opcode_Matrix( S428_DISPLAY_EXTRALARGE,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_MAINDISPLAY_EXTRA_LARGE = (uint16_t)SettingData(GUI_MAINDISPLAY_EXTRA_LARGE, 2, 0, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            MAINDISPLAY_EXTRA_LARGE = GUI_MAINDISPLAY_EXTRA_LARGE;
            EE_SaveReq(EE_USERSET);                    	// save to EE
            NewOpcode = S428_DISPLAY_EXTRALARGE;			// move to menu
            break;
        }

        break;


    //--DISPLAY SETTING-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //  DISPLAY -AUTODIM
    case DISPLAY_AUTODIM__STAT:

        NewOpcode = Opcode_Matrix( S164_DISPLAY_AUTODIM,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            if(BRIGHTNESS_LV ==110 ) { /*bypass auto dim if brighness AUTO*/
                GUI_BRIGHTNESS_DIM_MODE = NVD_OFF;
            }
            else {
                GUI_BRIGHTNESS_DIM_MODE = (NVD_status_t)SettingData((uint8_t)GUI_BRIGHTNESS_DIM_MODE, NVD_SET, NVD_OFF, 1, data_type);
            }
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_BRIGHTNESS_DIM_MODE == NVD_SET)
            {
                NewOpcode = DISPLAY_AUTODIM__TIME;              // go to settings
            }
            else
            {
                BRIGHTNESS_DIM_MODE = (NVD_status_t)GUI_BRIGHTNESS_DIM_MODE;  // update EE image
                EE_SaveReq(EE_USERSET);                         // save to EE
                NewOpcode = S164_DISPLAY_AUTODIM;               // back to Menu
            }
            break;
        }
        break;

    case DISPLAY_AUTODIM__TIME:

        NewOpcode = Opcode_Matrix( DISPLAY_AUTODIM__STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_BRIGHTNESS_DIM_TIME = (uint8_t)SettingData(GUI_BRIGHTNESS_DIM_TIME, 120, 20, 10, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            BRIGHTNESS_DIM_TIME = GUI_BRIGHTNESS_DIM_TIME;
            GUI_DIM_BRIGHT_LV = DIM_BRIGHT_LV;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DISPLAY_AUTODIM__PERCENT; 	        // return to menu
            break;
        }
        break;

    case DISPLAY_AUTODIM__PERCENT:

        NewOpcode = Opcode_Matrix( DISPLAY_AUTODIM__TIME,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        Backlight_Set(GUI_DIM_BRIGHT_LV);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_DIM_BRIGHT_LV = (uint8_t)SettingData(GUI_DIM_BRIGHT_LV, minor((BRIGHTNESS_LV-10),60), 10, 10, data_type);
            Backlight_Set(GUI_DIM_BRIGHT_LV);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            GUI_BRIGHTNESS_DIM_MODE = NVD_ON;            // set ON
            BRIGHTNESS_DIM_MODE = (NVD_status_t)GUI_BRIGHTNESS_DIM_MODE;      // update EE image
            DIM_BRIGHT_LV = GUI_DIM_BRIGHT_LV;
            EE_SaveReq(EE_USERSET);                             // save to EE
            if(GUI_BRIGHTNESS_LV ==110) {
                Backlight_Set((uint8_t)SensorReadbackLux);
            }
            else {
                Backlight_Set(BRIGHTNESS_LV);
            }
            NewOpcode = S164_DISPLAY_AUTODIM;                   // back to Menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //  DISPLAY -MAINDISPLAY

    case MAINDISPLAY_LEFT:
        //GUI_MAINDISPLAY_3RD_ROW_LEFT = MAIN_CC_3RD_ROW_LEFT;
        //GUI_MAINDISPLAY_3RD_ROW_RIGHT = MAIN_CC_3RD_ROW_RIGHT;
        Check3rdRowAfterDiveModeSwitch();
        GUI_MAINDISPLAY_N2_OR_GF_BAR = MAINDISPLAY_N2_OR_GF_BAR;
        GUI_MAINDISPLAY_EXTRA_LARGE = MAINDISPLAY_EXTRA_LARGE;

        NewOpcode = Opcode_Matrix( S166_DISPLAY_MAINDISPLAY,  MAINDISPLAY_EXTRALARGE,  MAINDISPLAY_RIGHT,	OldOpcode,  MAINDISPLAY_LEFT_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case MAINDISPLAY_RIGHT:
        //GUI_MAINDISPLAY_3RD_ROW_RIGHT = MAINDISPLAY_3RD_ROW_RIGHT;
        Check3rdRowAfterDiveModeSwitch();

        NewOpcode = Opcode_Matrix( S166_DISPLAY_MAINDISPLAY,  MAINDISPLAY_LEFT,  MAINDISPLAY_GFBG,	OldOpcode,  MAINDISPLAY_RIGHT_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case MAINDISPLAY_GFBG:
        GUI_MAINDISPLAY_N2_OR_GF_BAR = MAINDISPLAY_N2_OR_GF_BAR;

        NewOpcode = Opcode_Matrix( S166_DISPLAY_MAINDISPLAY,  MAINDISPLAY_RIGHT,  MAINDISPLAY_EXTRALARGE,	OldOpcode,  MAINDISPLAY_GFBG_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case MAINDISPLAY_EXTRALARGE:
        GUI_MAINDISPLAY_EXTRA_LARGE = MAINDISPLAY_EXTRA_LARGE;

        NewOpcode = Opcode_Matrix( S166_DISPLAY_MAINDISPLAY,  MAINDISPLAY_GFBG,  MAINDISPLAY_LEFT,	OldOpcode,  MAINDISPLAY_EXTRALARGE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case MAINDISPLAY_LEFT_SET:

        NewOpcode = Opcode_Matrix( MAINDISPLAY_LEFT,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(CC_MODE) {
                GUI_MAINDISPLAY_3RD_ROW_LEFT = (uint16_t)SettingData(GUI_MAINDISPLAY_3RD_ROW_LEFT, 8, 0, 1, data_type);
            }
            else {
                GUI_MAINDISPLAY_3RD_ROW_LEFT = (uint16_t)SettingData(GUI_MAINDISPLAY_3RD_ROW_LEFT, 9, 0, 1, data_type);

                if(data_type == data_increase) {
                    if(GUI_MAINDISPLAY_3RD_ROW_LEFT ==7) {
                        GUI_MAINDISPLAY_3RD_ROW_LEFT = 9;
                    }
                }
                else if(data_type == data_decrease) {
                    if(GUI_MAINDISPLAY_3RD_ROW_LEFT ==8) {
                        GUI_MAINDISPLAY_3RD_ROW_LEFT = 6;
                    }
                }

            }

            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:

            if(CC_MODE) {
                MAIN_CC_3RD_ROW_LEFT = GUI_MAINDISPLAY_3RD_ROW_LEFT;
            }
            else if(OC_MODE||BO_MODE) {
                MAIN_OC_3RD_ROW_LEFT = GUI_MAINDISPLAY_3RD_ROW_LEFT;

            }
            else if(SM_MODE) {
                MAIN_SM_3RD_ROW_LEFT = GUI_MAINDISPLAY_3RD_ROW_LEFT;
            }
            EE_SaveReq(EE_USERSET);                    	// save to EE
            NewOpcode = MAINDISPLAY_LEFT;				// move to menu
            break;
        }

        break;

    case MAINDISPLAY_RIGHT_SET:

        NewOpcode = Opcode_Matrix( MAINDISPLAY_RIGHT,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            //GUI_MAINDISPLAY_3RD_ROW_RIGHT = (uint16_t)SettingData(GUI_MAINDISPLAY_3RD_ROW_RIGHT, 8, 0, 1, data_type);

            if(CC_MODE) {
                GUI_MAINDISPLAY_3RD_ROW_RIGHT = (uint16_t)SettingData(GUI_MAINDISPLAY_3RD_ROW_RIGHT, 8, 0, 1, data_type);
            }
            else {
                GUI_MAINDISPLAY_3RD_ROW_RIGHT = (uint16_t)SettingData(GUI_MAINDISPLAY_3RD_ROW_RIGHT, 9, 0, 1, data_type);

                if(data_type == data_increase) {
                    if(GUI_MAINDISPLAY_3RD_ROW_RIGHT ==7) {
                        GUI_MAINDISPLAY_3RD_ROW_RIGHT = 9;
                    }
                }
                else if(data_type == data_decrease) {
                    if(GUI_MAINDISPLAY_3RD_ROW_RIGHT ==8) {
                        GUI_MAINDISPLAY_3RD_ROW_RIGHT = 6;
                    }
                }

            }

            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            //MAIN_CC_3RD_ROW_RIGHT = GUI_MAINDISPLAY_3RD_ROW_RIGHT;
            if(CC_MODE) {
                MAIN_CC_3RD_ROW_RIGHT = GUI_MAINDISPLAY_3RD_ROW_RIGHT;
            }
            else if(OC_MODE||BO_MODE) {
                MAIN_OC_3RD_ROW_RIGHT = GUI_MAINDISPLAY_3RD_ROW_RIGHT;

            }
            else if(SM_MODE) {
                MAIN_SM_3RD_ROW_RIGHT = GUI_MAINDISPLAY_3RD_ROW_RIGHT;
            }
            EE_SaveReq(EE_USERSET);                    	// save to EE
            NewOpcode = MAINDISPLAY_RIGHT;				// move to menu
            break;
        }


        break;

    case MAINDISPLAY_GFBG_SET:

        NewOpcode = Opcode_Matrix( MAINDISPLAY_GFBG,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_MAINDISPLAY_N2_OR_GF_BAR = (GUI_MAINDISPLAY_N2_OR_GF_BAR==1)? 0:1;

            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            MAINDISPLAY_N2_OR_GF_BAR = GUI_MAINDISPLAY_N2_OR_GF_BAR;
            EE_SaveReq(EE_USERSET);                    	// save to EE
            NewOpcode = MAINDISPLAY_GFBG;				// move to menu
            break;
        }



        break;

    case MAINDISPLAY_EXTRALARGE_SET:

        NewOpcode = Opcode_Matrix( MAINDISPLAY_RIGHT,   DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_MAINDISPLAY_EXTRA_LARGE = (uint16_t)SettingData(GUI_MAINDISPLAY_EXTRA_LARGE, 2, 0, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            MAINDISPLAY_EXTRA_LARGE = GUI_MAINDISPLAY_EXTRA_LARGE;
            EE_SaveReq(EE_USERSET);                    	// save to EE
            NewOpcode = MAINDISPLAY_EXTRALARGE;			// move to menu
            break;
        }

        break;

    //--DISPLAY SETTING ----------OTHER
    case DISPLAY_BRIGHTNESS_SET:

        NewOpcode = Opcode_Matrix( BackupOpcode,   DataDec,  DataInc,        ScrollInc, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        //Backlight_Set(GUI_BRIGHTNESS_LV);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
#if USE_REAL_BATTERY
            if(SystemSupplyMonitor.Battery_Percentage>15) {
                GUI_BRIGHTNESS_LV = (uint16_t)SettingData(GUI_BRIGHTNESS_LV, 110, 10, 10, data_type);
            }
            else {
                GUI_BRIGHTNESS_LV = (uint16_t)SettingData(GUI_BRIGHTNESS_LV, 30, 10, 10, data_type); /*low battery*/
            }
#else
            GUI_BRIGHTNESS_LV = (uint16_t)SettingData(GUI_BRIGHTNESS_LV, 110, 10, 10, data_type);
#endif

            if(GUI_BRIGHTNESS_LV > 100)
                Backlight_Set(AutoBRIGHTNESS);
            else
                Backlight_Set(GUI_BRIGHTNESS_LV);

            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            // save to EE
            //NewOpcode = S162_DISPLAY_BRIGHTNESS;	// move to menu
            NewOpcode = BackupOpcode;
            BRIGHTNESS_LV = GUI_BRIGHTNESS_LV;          // update data

            if(GUI_BRIGHTNESS_LV ==110) {
                Backlight_Set((uint8_t)SensorReadbackLux);
                GUI_BRIGHTNESS_DIM_MODE = NVD_OFF;
                BRIGHTNESS_DIM_MODE = (NVD_status_t)GUI_BRIGHTNESS_DIM_MODE;
            }
            else {
                Backlight_Set(BRIGHTNESS_LV);
            }

            EE_SaveReq(EE_USERSET);


            break;
        }
        break;

    /*
    uint8_t GUI_BRIGHTNESS_LV;                // GUI Settings for BRIGHTNESS_LV
    NVD_status_t GUI_BRIGHTNESS_DIM_MODE; // GUI Settings for BRIGHTNESS_DIM_MODE
    uint16_t GUI_BRIGHTNESS_DIM_TIME;         // GUI Settings for BRIGHTNESS_DIM_TIME
    uint8_t GUI_DIM_BRIGHT_LV;                // GUI Settings for DIM_BRIGHT_LV
    LanguageSelect_t GUI_LANG_Select;         // GUI Settings for LANG_Select
    NVD_status_t  GUI_SWITCH_LCD_Flip;    // GUI settings for LCD_Flip
    */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //  DISPLAY SETTINGS - TITLES COLOR
    case DISPLAY_TITLESCOLOR_SET:

        NewOpcode = Opcode_Matrix( S173_DISPLAY_TITLESCOLOR,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	CheckConditions, OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            TITLE_Color = (ColorSel_t)SettingData(TITLE_Color, ColorSel_MAGENTA, ColorSel_CYAN, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            EE_SaveReq(EE_USERSET);
            NewOpcode = S173_DISPLAY_TITLESCOLOR;	// move to menu
            break;
        case CheckConditions:
            /*When press and hold button -> Save the value also to EE*/
            EE_SaveReq(EE_USERSET);
            ReturnToMainPage();
            break;
        }
        break;

    case DISPLAY_LANGUAGE_SET:

        NewOpcode = Opcode_Matrix( BackupOpcode,  DataDec,  DataInc,	OldOpcode,   SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        //BackupOpcode = NewOpcode;

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_LANG_Select = (LanguageSelect_t)SettingData(GUI_LANG_Select, (MAX_LANGUAGE-1), Select_ENGLISH, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            GUI_LANG_LoadTextEx(_GetData, (void*)&StrLang_Select[LANGUAGE], LANGUAGE);
            GUI_LANG_SetLang(LANGUAGE);
            GUI_UC_SetEncodeUTF8();

            LANG_Select = GUI_LANG_Select;              // update data
            EE_SaveReq(EE_USERSET);                     // save to EE
            GUI_Clear();
            NewOpcode = BackupOpcode;

            TTF_CreateFontSequence(FontSize_General);

            break;
        }
        break;

    case DISPLAY_FLIPSCREEN_SET:

        NewOpcode = Opcode_Matrix( S178_DISPLAY_FLIPSCREEN,   DataDec,  DataInc,	OldOpcode,   SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SWITCH_LCD_Flip = (NVD_status_t)SettingData(GUI_SWITCH_LCD_Flip, NVD_ON, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            SWITCH_LCD_Flip = GUI_SWITCH_LCD_Flip;      // update data
            EE_SaveReq(EE_USERSET);                     // save to EE
            NewOpcode = S178_DISPLAY_FLIPSCREEN;	// move to menu
            break;
        }
        break;

    case S373_DISPLAY_GTR_SET:

        NewOpcode = Opcode_Matrix( S372_DISPLAY_GTR,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        data_type = Update_datatype(NewOpcode);
        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SWITCH_LCD_GTR_L_R = (NVD_YesNo_t)SettingData(GUI_SWITCH_LCD_GTR_L_R, NVD_YES, NVD_NO, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            SWITCH_LCD_GTR_L_R = GUI_SWITCH_LCD_GTR_L_R;		// update data
            EE_SaveReq(EE_USERSET); 					// save to EE
            NewOpcode = S372_DISPLAY_GTR;	// move to menu
            break;
        }
        break;

        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // TMT SETTING
    case S128_TM_TMT1:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT6,  S128_TM_TMT2,	OldOpcode,  TMT_1_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_1;
        GUI_SN_Digit = 0;
        break;

    case S128_TM_TMT2:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT1,  S128_TM_TMT3, OldOpcode,	TMT_2_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_2;
        GUI_SN_Digit = 0;
        break;

    case S128_TM_TMT3:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT2,  S128_TM_TMT4, OldOpcode,	TMT_3_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_3;
        GUI_SN_Digit = 0;
        break;

    case S128_TM_TMT4:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT3,  S128_TM_TMT5, OldOpcode,	TMT_4_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_4;
        GUI_SN_Digit = 0;
        break;

    case S128_TM_TMT5:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT4,  S128_TM_TMT6, OldOpcode,	TMT_5_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_5;
        GUI_SN_Digit = 0;
        break;

    case S128_TM_TMT6:

        NewOpcode = Opcode_Matrix( S128_DEVICE_TRANSMITTERS,  S128_TM_TMT5,  S128_TM_TMT1, OldOpcode,	TMT_6_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        GUI_TMT_Num_InSetting = TMT_6;
        GUI_SN_Digit = 0;
        break;


    case TMT_1_SET:
    case TMT_2_SET:
    case TMT_3_SET:
    case TMT_4_SET:
    case TMT_5_SET:
    case TMT_6_SET:

        NewOpcode = Opcode_Matrix( (DSX_OPCODE_t)(SET_TMT_1_DIGIT_1 + (DSX_OPCODE_t)(GUI_TMT_Num_InSetting-1)),  DataDec,  DataInc, OldOpcode,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            GUI_TMT_Status[GUI_TMT_Num_InSetting] = (NVD_status_t)SettingData(GUI_TMT_Status[GUI_TMT_Num_InSetting], NVD_SET, NVD_OFF, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_TMT_Status[GUI_TMT_Num_InSetting] = (NVD_status_t)SettingData(GUI_TMT_Status[GUI_TMT_Num_InSetting], NVD_SET, NVD_OFF, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_SET)
            {
                NewOpcode = (DSX_OPCODE_t)(SET_TMT_1_DIGIT_1 + 6*(GUI_TMT_Num_InSetting-1));               // continue to set SN
                GUI_SN_Digit = 1;       // starts from highest digit = 6
            }
            else
            {
                NewOpcode = (DSX_OPCODE_t)(S128_TM_TMT1+(DSX_OPCODE_t)(GUI_TMT_Num_InSetting-1));                // return to menu
                SCUBA_Set.TMT_On.TMT1 =  GUI_TMT_Status[1];
                SCUBA_Set.TMT_On.TMT2 =  GUI_TMT_Status[2];
                SCUBA_Set.TMT_On.TMT3 =  GUI_TMT_Status[3];
                SCUBA_Set.TMT_On.TMT4 =  GUI_TMT_Status[4];
                SCUBA_Set.TMT_On.TMT5 =  GUI_TMT_Status[5];
                SCUBA_Set.TMT_On.TMT6 =  GUI_TMT_Status[6];


                GUI_ShowTankNum = 0;
                for(int i =1; i<=6; i++) {
                    if(GUI_TMT_Status[i] == NVD_ON) {
                        GUI_ShowTankNum = i;
                        break;
                    }
                }

                if(GSM_MODE)
                {
                    CURRENT_TMT_NUM_GSM = (TMT_NUM_t)GUI_ShowTankNum;
                }
                else if(GAUGE_MODE)
                {
                    CURRENT_TMT_NUM_GAUGE = (TMT_NUM_t)GUI_ShowTankNum;
                }

                EE_SaveReq(EE_TRIMIXSET);


                EE_SaveReq(EE_SCUBASET);
            }
            break;

        }
        break;


    case SET_TMT_1_DIGIT_1:
    case SET_TMT_1_DIGIT_2:
    case SET_TMT_1_DIGIT_3:
    case SET_TMT_1_DIGIT_4:
    case SET_TMT_1_DIGIT_5:
    case SET_TMT_1_DIGIT_6:

    case SET_TMT_2_DIGIT_1:
    case SET_TMT_2_DIGIT_2:
    case SET_TMT_2_DIGIT_3:
    case SET_TMT_2_DIGIT_4:
    case SET_TMT_2_DIGIT_5:
    case SET_TMT_2_DIGIT_6:

    case SET_TMT_3_DIGIT_1:
    case SET_TMT_3_DIGIT_2:
    case SET_TMT_3_DIGIT_3:
    case SET_TMT_3_DIGIT_4:
    case SET_TMT_3_DIGIT_5:
    case SET_TMT_3_DIGIT_6:

    case SET_TMT_4_DIGIT_1:
    case SET_TMT_4_DIGIT_2:
    case SET_TMT_4_DIGIT_3:
    case SET_TMT_4_DIGIT_4:
    case SET_TMT_4_DIGIT_5:
    case SET_TMT_4_DIGIT_6:

    case SET_TMT_5_DIGIT_1:
    case SET_TMT_5_DIGIT_2:
    case SET_TMT_5_DIGIT_3:
    case SET_TMT_5_DIGIT_4:
    case SET_TMT_5_DIGIT_5:
    case SET_TMT_5_DIGIT_6:

    case SET_TMT_6_DIGIT_1:
    case SET_TMT_6_DIGIT_2:
    case SET_TMT_6_DIGIT_3:
    case SET_TMT_6_DIGIT_4:
    case SET_TMT_6_DIGIT_5:
    case SET_TMT_6_DIGIT_6:

        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec,  DataInc, ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        // GUI_SN_Digit
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_TMT_SerialNum[GUI_TMT_Num_InSetting][GUI_SN_Digit] = (uint8_t)SettingData(GUI_TMT_SerialNum[GUI_TMT_Num_InSetting][GUI_SN_Digit], 9, 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_TMT_SerialNum[GUI_TMT_Num_InSetting][GUI_SN_Digit] = (uint8_t)SettingData(GUI_TMT_SerialNum[GUI_TMT_Num_InSetting][GUI_SN_Digit], 9, 0, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case CheckConditions: // back to previous (Higher) digit
            GUI_SN_Digit--;
            if(GUI_SN_Digit == 0)    // when (SN digit == 6, the highest digit)
                NewOpcode = (DSX_OPCODE_t)(TMT_1_SET+(DSX_OPCODE_t)(GUI_TMT_Num_InSetting-1));               // back to SET POINTS
            else
                NewOpcode = (DSX_OPCODE_t)(SET_TMT_1_DIGIT_1+6*(GUI_TMT_Num_InSetting-1)+(GUI_SN_Digit-1));                // back to previous digit
            break;
        case SaveAndDone:     // forward to next (Lower) digit
            GUI_SN_Digit++;

            if(GUI_SN_Digit>6)
            {
                // save GUI SN number into EEPROM and save
                i = GUI_TMT_Num_InSetting;
                SCUBA_Set.TMTID[i]= GUI_TMT_SerialNum[i][6] + 10*GUI_TMT_SerialNum[i][5] + 100*GUI_TMT_SerialNum[i][4]
                                    + 1000*GUI_TMT_SerialNum[i][3] + 10000*GUI_TMT_SerialNum[i][2] + 100000*GUI_TMT_SerialNum[i][1];

                NewOpcode = (DSX_OPCODE_t)(S128_TM_TMT1+(DSX_OPCODE_t)(GUI_TMT_Num_InSetting-1));                // back to TMT Menu

                GUI_TMT_Status[GUI_TMT_Num_InSetting] = NVD_ON;
                SCUBA_Set.TMT_On.TMT1 =  GUI_TMT_Status[1];
                SCUBA_Set.TMT_On.TMT2 =  GUI_TMT_Status[2];
                SCUBA_Set.TMT_On.TMT3 =  GUI_TMT_Status[3];
                SCUBA_Set.TMT_On.TMT4 =  GUI_TMT_Status[4];
                SCUBA_Set.TMT_On.TMT5 =  GUI_TMT_Status[5];
                SCUBA_Set.TMT_On.TMT6 =  GUI_TMT_Status[6];

                EE_SaveReq(EE_SCUBASET);

            }
            else
                NewOpcode =(DSX_OPCODE_t) (SET_TMT_1_DIGIT_1+6*(GUI_TMT_Num_InSetting-1)+(GUI_SN_Digit-1));

            break;
        }
        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Info Menu

    case S187_IM_MYINFO:
        NewOpcode = Opcode_Matrix( S185_INFO,  S224_IM_MANUFACTURER,  S190_IM_DSXINFO,	OldOpcode,  S218_IM_MYINFO_SET,	        ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S190_IM_DSXINFO:
        NewOpcode = Opcode_Matrix( S185_INFO,  S187_IM_MYINFO,  S192_IM_HISTORY,	OldOpcode,  S190_IM_DSXINFO_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S192_IM_HISTORY:
        NewOpcode = Opcode_Matrix( S185_INFO,  S190_IM_DSXINFO,  S224_IM_MANUFACTURER,	OldOpcode,  S192_IM_HISTORY_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S224_IM_MANUFACTURER:
        NewOpcode = Opcode_Matrix( S185_INFO,  S192_IM_HISTORY,  S187_IM_MYINFO,	OldOpcode,  S224_IM_MANUFACTURER_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S218_IM_MYINFO_SET:
        NewOpcode = Opcode_Matrix( S187_IM_MYINFO,  OldOpcode,  OldOpcode,	OldOpcode,  S187_IM_MYINFO,		ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S190_IM_DSXINFO_SET:
        NewOpcode = Opcode_Matrix( S190_IM_DSXINFO,  OldOpcode,  OldOpcode,	OldOpcode,  S190_IM_DSXINFO,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S192_IM_HISTORY_SET:
        NewOpcode = Opcode_Matrix( S192_IM_HISTORY,  OldOpcode,  OldOpcode,	OldOpcode,  S192_IM_HISTORY,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S224_IM_MANUFACTURER_SET:
        NewOpcode = Opcode_Matrix( S224_IM_MANUFACTURER,  OldOpcode,  OldOpcode,	OldOpcode,  S224_IM_MANUFACTURER,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // SP Switch Menu

    /*
      Note: The following SP Set values are readback from EE Prom at S18_SP_SWITCH
      GUI_SP_HighVal   = HIGH_SP_Val;     // for GUI displaying
      GUI_SP_LowVal    = LOW_SP_Val;      // for GUI displaying
      GUI_SP_CustomVal = CUSTOM_SP_Val;   // for GUI displaying
    */
    case SP_SWITCH_TO_HIGH:
        if(GUI_SP_CustomSwitch ==NVD_OFF) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  NewOpcode,  NewOpcode, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }
        else if(GUI_SP_Switch == LOW_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_CUSTOM,  SP_SWITCH_TO_CUSTOM, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }
        else  if(GUI_SP_Switch == CUSTOM_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_LOW,  SP_SWITCH_TO_LOW, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }

        if(NewOpcode==SaveAndDone)
        {
            Switch_To_SPhigh();
            ccSP_ManualChangedToHigh = true;
            AutoSP_Low_MaunalOverwrite = true;
            GUI_SP_Switch = HIGH_SP;
            SP_SWITCH = GUI_SP_Switch;
            GUI_SP_ActualVal = GUI_SP_HighVal;
            SP_CURRENT_Val = GUI_SP_ActualVal;  // save to EE
            EE_SaveReq(EE_SCUBASET);
            Check_SPcurrent();
            Find_FiO2_DilPO2_Values();
            // NewOpcode = S18_SP_SWITCH;  // return to menu
            NewOpcode = OpcodeForR2s;
        }
        break;


    case SP_SWITCH_TO_LOW:
        if(GUI_SP_CustomSwitch ==NVD_OFF) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  NewOpcode,  NewOpcode, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }
        else if(GUI_SP_Switch == HIGH_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_CUSTOM,  SP_SWITCH_TO_CUSTOM, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }
        else  if(GUI_SP_Switch == CUSTOM_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_HIGH,  SP_SWITCH_TO_HIGH, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }

        if(NewOpcode==SaveAndDone)
        {
            Switch_To_SPlow();
            ccSP_ManualChangedToLow = true;
            AutoSP_High_MaunalOverwrite = true;
            GUI_SP_Switch = LOW_SP;
            SP_SWITCH = GUI_SP_Switch;
            GUI_SP_ActualVal = GUI_SP_LowVal;
            SP_CURRENT_Val = GUI_SP_ActualVal;  // save to EE
            EE_SaveReq(EE_SCUBASET);
            Check_SPcurrent();
            Find_FiO2_DilPO2_Values();
            //NewOpcode = S18_SP_SWITCH;  // return to menu
            NewOpcode = OpcodeForR2s;
        }
        break;


    case SP_SWITCH_TO_CUSTOM:

        if(GUI_SP_Switch == HIGH_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_LOW,  SP_SWITCH_TO_LOW, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }
        else  if(GUI_SP_Switch == LOW_SP) {
            NewOpcode = Opcode_Matrix( BackupOpcode,  SP_SWITCH_TO_HIGH,  SP_SWITCH_TO_HIGH, OldOpcode,  SaveAndDone,  OpcodeForR2s,  OldOpcode, OldOpcode,	  OldOpcode);
        }

        if(NewOpcode==SaveAndDone)
        {
            Switch_To_SPcustom();
            GUI_SP_Switch = CUSTOM_SP;
            SP_SWITCH = GUI_SP_Switch;
            GUI_SP_ActualVal = GUI_SP_CustomVal;
            SP_CURRENT_Val = GUI_SP_ActualVal;  // save to EE
            EE_SaveReq(EE_SCUBASET);
            Check_SPcurrent();
            Find_FiO2_DilPO2_Values();
            //NewOpcode = S18_SP_SWITCH;  // return to menu
            NewOpcode = OpcodeForR2s;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*GAUGE Mode*/
    case SURFACE_GAUGE_MAIN:
        UnderWaterFlat = FALSE;
        AutoDim_timout_cnt = BRIGHTNESS_DIM_TIME*4;
        UpdateGasStatus();

        if(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)
        {
            NewOpcode = Opcode_Matrix( CheckConditions, DataDec, DIVEMAINMENU_GASSWITCH, OldOpcode, SURFACE_GAUGE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( CheckConditions, DataDec, S404_TMT_SWITCH , OldOpcode, SURFACE_GAUGE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        Gnss_Standby();
        Ec_Off();
        if(NewOpcode == C1_COMPASS_MAIN)
            Ec_On();


        switch(NewOpcode)
        {
        case CheckConditions:		// L 2S Button to Reset Runtime
            Runtime.ResetReq = true;
            NewOpcode = OldOpcode;
            break;

        case DataDec:			   // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;
        }



        break;

    case SURFACE_GAUGE_ALT1:
        NewOpcode = Opcode_Matrix(SURFACE_GAUGE_MAIN,  OldOpcode,  S404_TMT_SWITCH,	OldOpcode,  SURFACE_GAUGE_ALT2, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case SURFACE_GAUGE_ALT2:
        NewOpcode = Opcode_Matrix(SURFACE_GAUGE_ALT1,  OldOpcode,  S404_TMT_SWITCH,	OldOpcode,  SURFACE_GAUGE_MAIN, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    /*GAUGE SM Mode*/
    case SURFACE_GSM_MAIN:
        UnderWaterFlat = FALSE;
        AutoDim_timout_cnt = BRIGHTNESS_DIM_TIME*4;
        UpdateGasStatus();

        if(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)
        {
            NewOpcode = Opcode_Matrix( CheckConditions, DataDec, DIVEMAINMENU_GASSWITCH, OldOpcode, SURFACE_GSM_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( CheckConditions, DataDec, S404_TMT_SWITCH , OldOpcode, SURFACE_GSM_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        Gnss_Standby();
        Ec_Off();
        if(NewOpcode == C1_COMPASS_MAIN)
            Ec_On();

        switch(NewOpcode)
        {
        case CheckConditions:		// L 2S Button to Reset Runtime
            Runtime.ResetReq = true;
            NewOpcode = OldOpcode;
            break;

        case DataDec:			   // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;
        }


        break;

    case SURFACE_GSM_ALT1:
        NewOpcode = Opcode_Matrix(SURFACE_GSM_MAIN,  OldOpcode,  S404_TMT_SWITCH,	OldOpcode,  SURFACE_GSM_ALT2, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        break;
    case SURFACE_GSM_ALT2:
        NewOpcode = Opcode_Matrix(SURFACE_GSM_ALT1,  OldOpcode,  S404_TMT_SWITCH,	OldOpcode,  SURFACE_GSM_MAIN, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;


    /*SM Mode*/
    case SURFACE_SM_MAIN:
        UnderWaterFlat = FALSE;
        AutoDim_timout_cnt = BRIGHTNESS_DIM_TIME*4;
        UpdateGasStatus();

        if(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)
        {
            NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0, OldOpcode, DIVEMAINMENU_GASSWITCH, OldOpcode, SURFACE_SM_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0, OldOpcode, S21_GAS_SWITCH, OldOpcode, SURFACE_SM_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
        }
        Gnss_Standby();
        Ec_Off();
        if(NewOpcode == C1_COMPASS_MAIN)
            Ec_On();
        //NewOpcode = NewOpcode_Overwrite(NewOpcode);     // for L+M > 2sec and L+R 2sec combinations
        break;
    case SURFACE_SM_ALT1:
        NewOpcode = Opcode_Matrix(SURFACE_SM_MAIN,  OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  SURFACE_SM_ALT2, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case SURFACE_SM_ALT2:
        if(isViolation)
            NewOpcode = Opcode_Matrix(SURFACE_SM_ALT1,  OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  SURFACE_SM_MAIN, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        else
            NewOpcode = Opcode_Matrix(SURFACE_SM_ALT1,  OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  SURFACE_SM_ALT3, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case SURFACE_SM_ALT3:
        NewOpcode = Opcode_Matrix(SURFACE_SM_ALT2,  OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  SURFACE_SM_ALT4, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case SURFACE_SM_ALT4:
        NewOpcode = Opcode_Matrix(SURFACE_SM_ALT3,  OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  SURFACE_SM_MAIN, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S2_SURFACE_MAIN:
        OpcodeForR2s = S2_SURFACE_MAIN;
        UnderWaterFlat = FALSE;
        AutoDim_timout_cnt = BRIGHTNESS_DIM_TIME*4;
        UpdateGasStatus();

        if(CC_MODE) {
            find_CC_SP_Current();
            NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0,  OldOpcode, S18_SP_SWITCH,	   OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            BackupOpcode = S2_SURFACE_MAIN;
        }
        else if(OC_MODE) {
            if(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE) {
                NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0,  OldOpcode, DIVEMAINMENU_GASSWITCH,    OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0,  OldOpcode, S21_GAS_SWITCH,    OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            }
            BackupOpcode = S2_SURFACE_MAIN;
        }
        else if(BO_MODE) {
            if(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE) {
                NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0,  OldOpcode, DIVEMAINMENU_GASSWITCH,    OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( GAS_SWITCH_TO_GAS_0,  OldOpcode, S21_GAS_SWITCH,    OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            }
            BackupOpcode = S2_SURFACE_MAIN;
        }
        else {  // for GSM and Gauge modes only
            NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, S404_TMT_SWITCH,      OldOpcode,	   S11_SURFACE_ALT1,	C1_COMPASS_MAIN,  OldOpcode,  OldOpcode, OldOpcode);
            switch(NewOpcode)
            {
            case CheckConditions:       // L 2S Button to Reset Runtime
                Runtime.ResetReq = true;
                NewOpcode = OldOpcode;
                break;

            case DataDec:              // L < 2S Button to Start/Stop Runtime
                if(Runtime.Status == TIMER_Run)
                    Runtime.PauseReq = true;
                else
                    Runtime.RunReq = true;

                NewOpcode = OldOpcode;
                break;
            }
        }
        Gnss_Standby();
        Ec_Off();
        if(NewOpcode == C1_COMPASS_MAIN)
            Ec_On();
        //NewOpcode = NewOpcode_Overwrite(NewOpcode);     // for L+M > 2sec and L+R 2sec combinations
        break;

    case S11_SURFACE_ALT1:

        if(CC_MODE||OC_MODE||BO_MODE)
        {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),  	OldOpcode,  S18_SP_SWITCH,	OldOpcode,  S12_SURFACE_ALT2,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else  // GSM_MODE or GAUGE_MODE modes
        {
            NewOpcode = Opcode_Matrix( CheckConditions,  	DataDec,  OldOpcode,	OldOpcode,  S12_SURFACE_ALT2,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

            switch(NewOpcode)
            {
            case CheckConditions:       // L 2S Button to Reset Runtime
                Runtime.ResetReq = true;
                NewOpcode = OldOpcode;
                break;

            case DataDec:              // L < 2S Button to Start/Stop Runtime
                if(Runtime.Status == TIMER_Run)
                    Runtime.PauseReq = true;
                else
                    Runtime.RunReq = true;

                NewOpcode = OldOpcode;
                break;
            }
        }
        break;
    case S12_SURFACE_ALT2:

        if(CC_MODE||OC_MODE||BO_MODE)
        {
            if(isViolation)     //bypass all other ALTx and return to Surf Main page
                NewOpcode = Opcode_Matrix( S11_SURFACE_ALT1,  OldOpcode,  S18_SP_SWITCH,	OldOpcode,  ReturnToMainPage(),	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
            else
                NewOpcode = Opcode_Matrix( S11_SURFACE_ALT1,  OldOpcode,  S18_SP_SWITCH,	OldOpcode,  S13_SURFACE_ALT3,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( CheckConditions,  	DataDec,    OldOpcode,	OldOpcode,  ReturnToMainPage(),	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

            switch(NewOpcode)
            {
            case CheckConditions:       // L 2S Button to Reset Runtime
                Runtime.ResetReq = true;
                NewOpcode = OldOpcode;
                break;

            case DataDec:              // L < 2S Button to Start/Stop Runtime
                if(Runtime.Status == TIMER_Run)
                    Runtime.PauseReq = true;
                else
                    Runtime.RunReq = true;

                NewOpcode = OldOpcode;
                break;
            }
        }
        break;
    case S13_SURFACE_ALT3:

        NewOpcode = Opcode_Matrix( S12_SURFACE_ALT2,  	OldOpcode,  S18_SP_SWITCH,	OldOpcode,  S14_SURFACE_ALT4,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S14_SURFACE_ALT4:

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S13_SURFACE_ALT3,  	OldOpcode,  S18_SP_SWITCH,	OldOpcode,  S15_SURFACE_ALT5,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S13_SURFACE_ALT3,  	OldOpcode,  S21_GAS_SWITCH,	OldOpcode,  ReturnToMainPage(),	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        break;
    case S15_SURFACE_ALT5:
        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S14_SURFACE_ALT4,  OldOpcode,  S18_SP_SWITCH, OldOpcode,  ReturnToMainPage(),  ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S14_SURFACE_ALT4,  OldOpcode,  S21_GAS_SWITCH, OldOpcode, ReturnToMainPage(),  ReturnToMainPage(), OldOpcode, OldOpcode, OldOpcode);
        }
        break;
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // GAS SWITCH  Menu

    case GAS_SWITCH_TO_GAS_0:

        GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page

        // GUI to display GAS SWITCH page S328
        // Assign Gas Tank 1 to 6's On/Off status according to current EEPROM record

            GUI_SetPoints_Gas_CC[1] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas1;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_CC[2] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas2;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_CC[3] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas3;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_CC[4] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas4;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_CC[5] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas5;          // 1: ON;  0: OFFF
            GUI_SetPoints_Gas_CC[6] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas6;          // 1: ON;  0: OFF

            for(i=1; i<=6; i++)
            {
                GUI_FO2_Gas_CC[i]      = TRIMIX_Set.CC_FO2[i];             // CC-x FO2/000
                GUI_FHe_Gas_CC[i]      = TRIMIX_Set.CC_FHe[i];             // CC-x 000/FHe
                GUI_PO2_Gas[i]      = TRIMIX_Set.CC_PO2A[i];            // CC-x PO2 set value
                GUI_NumOfTMT_Gas_CC[i] = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[i];          // CC-x
            }


            GUI_SetPoints_Gas_BO[1] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas1;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_BO[2] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas2;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_BO[3] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas3;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_BO[4] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas4;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_BO[5] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas5;          // 1: ON;  0: OFFF
            GUI_SetPoints_Gas_BO[6] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas6;          // 1: ON;  0: OFF

            for(i=1; i<=6; i++)
            {
                GUI_FO2_Gas_BO[i]      = TRIMIX_Set.BO_FO2[i];             // CC-x FO2/000
                GUI_FHe_Gas_BO[i]      = TRIMIX_Set.BO_FHe[i];             // CC-x 000/FHe
                GUI_PO2_Gas[i]      = TRIMIX_Set.BO_PO2A[i];            // CC-x PO2 set value
                GUI_NumOfTMT_Gas_BO[i] = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[i];          // CC-x
            }


            GUI_SetPoints_Gas_OC[1] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas1;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_OC[2] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas2;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_OC[3] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas3;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_OC[4] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas4;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_OC[5] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas5;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_OC[6] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas6;          // 1: ON;  0: OFF

            for(i=1; i<=6; i++)
            {
                GUI_FO2_Gas_OC[i]      = TRIMIX_Set.OC_FO2[i];             // OC-x FO2/000
                GUI_FHe_Gas_OC[i]      = TRIMIX_Set.OC_FHe[i];             // OC-x 000/FHe
                GUI_PO2_Gas_OC[i]      = TRIMIX_Set.OC_PO2A[i];            // OC-x PO2 set value
                GUI_NumOfTMT_Gas_OC[i] = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[i];          // OC-x
            }


            GUI_SetPoints_Gas_SM[1] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas1;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_SM[2] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas2;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_SM[3] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas3;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_SM[4] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas4;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_SM[5] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas5;          // 1: ON;  0: OFF
            GUI_SetPoints_Gas_SM[6] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas6;          // 1: ON;  0: OFF

            for(i=1; i<=6; i++)
            {
                GUI_FO2_Gas_SM[i]      = TRIMIX_Set.SM_FO2[i];             // SM-x FO2/000
                GUI_FHe_Gas_SM[i]      = TRIMIX_Set.SM_FHe[i];             // SM-x 000/FHe
                GUI_PO2_Gas_SM[i]      = TRIMIX_Set.SM_PO2A[i];          // SM-x PO2 set value
                GUI_NumOfTMT_Gas_SM[i] = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[i];          // SM-x
            }

        if(CURRENT_TANK_NUM ==GASES_01) {
            NewOpcode = GAS_SWITCH_TO_GAS_2;
        }
        else {
            NewOpcode =  GAS_SWITCH_TO_GAS_1;
        }
        GUI_Clear();
        break;

    case GAS_SWITCH_TO_GAS_1:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==1)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_2)
            {
                //GUI_TankN_Linked = 6;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                //NewOpcode = GAS_SWITCH_TO_GAS_6;

                if(CC_MODE) {
                    GUI_TankN_Linked = TANK_5;
                    NewOpcode = GAS_SWITCH_TO_GAS_5;
                }
                else {
                    GUI_TankN_Linked = TANK_6;
                    NewOpcode = GAS_SWITCH_TO_GAS_6;
                }

            }
            else
            {
                GUI_TankN_Linked = TANK_2;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_2;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_1;


            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_1;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_1;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_1;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_1;
            }

            //}

            if(CC_MODE) {
                NewOpcode = Opcode_Matrix( BackupOpcode,	GAS_SWITCH_TO_GAS_5,  GAS_SWITCH_TO_GAS_2,	 OldOpcode,  next_logic,	 OpcodeForR2s, OldOpcode, OldOpcode,   OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( BackupOpcode,	GAS_SWITCH_TO_GAS_6,  GAS_SWITCH_TO_GAS_2,	 OldOpcode,  next_logic,	 OpcodeForR2s, OldOpcode, OldOpcode,   OldOpcode);

            }

            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF)) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT		
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }


                        //CURRENT_TANK_NUM = GUI_TankN_Linked;
                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;


                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[1] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas1 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[1] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas1 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[1] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas1 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[1] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas1 = true;
                        }

                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }
                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }

                break;

            case GAS_SWITCH_TO_GAS_1:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)     // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);         // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_1;    // stays at same page

                break;
            }
        }
        break;
    case GAS_SWITCH_TO_GAS_2:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==2)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_1)
            {
                GUI_TankN_Linked = TANK_3;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_3;
            }
            else
            {
                GUI_TankN_Linked = TANK_1;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_1;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_2;

            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_2;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_2;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_2;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_2;
            }
            //}

            NewOpcode = Opcode_Matrix( BackupOpcode,  GAS_SWITCH_TO_GAS_1,  GAS_SWITCH_TO_GAS_3,	OldOpcode,  next_logic,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);


            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF))// change from GAS_SWITCH_MOD to GAS_SWITCH_TMT	
                    if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT))
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }

                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;

                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[2] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas2 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[2] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas2 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[2] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas2 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[2] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas2 = true;
                        }
                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }
                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }
                break;

            case GAS_SWITCH_TO_GAS_2:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)     // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);         // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_2;    // stays at same page

                break;
            }
        }
        break;

    case GAS_SWITCH_TO_GAS_3:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==3)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_2)
            {
                GUI_TankN_Linked = TANK_4;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_4;
            }
            else
            {
                GUI_TankN_Linked = TANK_2;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_2;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_3;

            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_3;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_3;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_3;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_3;
            }
            //}

            NewOpcode = Opcode_Matrix( BackupOpcode,  GAS_SWITCH_TO_GAS_2,  GAS_SWITCH_TO_GAS_4,	OldOpcode,  next_logic,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF)) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }

                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;

                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[3] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas3 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[3] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas3 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[3] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas3 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[3] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas1 = true;
                        }
                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }
                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }
                break;

            case GAS_SWITCH_TO_GAS_3:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)     // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);         // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_3;    // stays at same page

                break;
            }
        }
        break;
    case GAS_SWITCH_TO_GAS_4:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==4)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_3)
            {
                GUI_TankN_Linked = TANK_5;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_5;
            }
            else
            {
                GUI_TankN_Linked = TANK_3;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_3;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_4;
            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_4;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_4;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_4;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_4;
            }
            //}
            NewOpcode = Opcode_Matrix( BackupOpcode,  GAS_SWITCH_TO_GAS_3,  GAS_SWITCH_TO_GAS_5,	OldOpcode,  next_logic,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF)) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }

                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;

                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[4] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas4 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[4] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas4 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[4] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas4 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[4] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas1 = true;
                        }
                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }
                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }
                break;

            case GAS_SWITCH_TO_GAS_4:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)     // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);         // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_4;    // stays at same page

                break;
            }
        }
        break;
    case GAS_SWITCH_TO_GAS_5:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==5)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_4)
            {

                if(CC_MODE) {
                    GUI_TankN_Linked = TANK_1;
                    NewOpcode = GAS_SWITCH_TO_GAS_1;
                }
                else {
                    GUI_TankN_Linked = TANK_6;
                    NewOpcode = GAS_SWITCH_TO_GAS_6;
                }
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
            }
            else
            {
                GUI_TankN_Linked = TANK_4;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_4;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_5;
            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_5;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_5;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_5;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_5;
            }
            //}
            if(CC_MODE) {
                NewOpcode = Opcode_Matrix( BackupOpcode,	GAS_SWITCH_TO_GAS_4,  GAS_SWITCH_TO_GAS_1,	 OldOpcode,  next_logic,	 OpcodeForR2s, OldOpcode, OldOpcode,   OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( BackupOpcode,	GAS_SWITCH_TO_GAS_4,  GAS_SWITCH_TO_GAS_6,	 OldOpcode,  next_logic,	 OpcodeForR2s, OldOpcode, OldOpcode,   OldOpcode);

            }
            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF)) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }

                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;

                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[5] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas5 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[5] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas5 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[5] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas5 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[5] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas1 = true;
                        }
                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }
                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }
                break;

            case GAS_SWITCH_TO_GAS_5:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)     // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);         // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_5;    // stays at same page

                break;
            }
        }
        break;

    case GAS_SWITCH_TO_GAS_6:

        GUI_TMT_Num_InSetting = (TMT_NUM_t)Find_TMT_Num_InLinking();

        if(CURRENT_TANK_NUM==6)
        {
            if(pre_DSX_Opcode==GAS_SWITCH_TO_GAS_5)
            {
                GUI_TankN_Linked = TANK_1;
                NewOpcode = GAS_SWITCH_TO_GAS_1;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
            }
            else
            {
                GUI_TankN_Linked = TANK_5;
                GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD; // To show MOD at GAS SWITCH page
                NewOpcode = GAS_SWITCH_TO_GAS_5;
            }
        }
        else
        {
            GUI_TankN_Linked = TANK_6;
            next_logic = CheckConditions;
            //if(OpcodeForR2s>=DIVE_GAUGE_MAIN)  /*go to Switch gas from underwater*/
            //{
            if((CC_MODE)&&(GUI_SetPoints_Gas_CC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_6;
            }
            else if((BO_MODE)&&(GUI_SetPoints_Gas_BO[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_6;
            }
            else if((OC_MODE)&&(GUI_SetPoints_Gas_OC[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_6;
            }
            else if((SM_MODE)&&(GUI_SetPoints_Gas_SM[GUI_TankN_Linked] == NVD_OFF)) {
                next_logic = GAS_SWITCH_TO_GAS_6;
            }

            //}
            NewOpcode = Opcode_Matrix( BackupOpcode,  GAS_SWITCH_TO_GAS_5,  GAS_SWITCH_TO_GAS_1,	OldOpcode,	next_logic,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

            switch(NewOpcode)
            {
            case CheckConditions:

                if(GasSwitchPO2_Stat()!=GAS_SWITCH_PO2_TOO_LOW)
                {
                    //if((GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)&&(GUI_TMT_Num_InSetting != TMT_OFF)) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT)
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                    {
                        if(UnderWaterFlat==TRUE) {
                            NewOpcode = OpcodeForR2s;  /*back to DIVE MAIN if underwater*/
                        }
                        else {
                            NewOpcode = BackupOpcode;  /*back to setting menu if on surface*/
                        }

                        if(CC_MODE)
                            CURRENT_TANK_NUM_CC = GUI_TankN_Linked;
                        else if(OC_MODE)
                            CURRENT_TANK_NUM_OC = GUI_TankN_Linked;
                        else if(SM_MODE)
                            CURRENT_TANK_NUM_SM = GUI_TankN_Linked;
                        else if(BO_MODE)
                            CURRENT_TANK_NUM_BO = GUI_TankN_Linked;

                        if(CC_MODE) {
                            GUI_SetPoints_Gas_CC[6] =  NVD_ON;
                            TRIMIX_Set.CC_Active.Gas6 = true;
                        }
                        else if(OC_MODE) {
                            GUI_SetPoints_Gas_OC[6] =  NVD_ON;
                            TRIMIX_Set.OC_Active.Gas6 = true;
                        }
                        else if(SM_MODE) {
                            GUI_SetPoints_Gas_SM[6] =  NVD_ON;
                            TRIMIX_Set.SM_Active.Gas6 = true;
                        }
                        else if(BO_MODE) {
                            GUI_SetPoints_Gas_BO[6] =  NVD_ON;
                            TRIMIX_Set.BO_Active.Gas1 = true;
                        }
                        SCUBA_Set.CurrGasNumber = GUI_TankN_Linked;
                        EE_SaveReq(EE_SCUBASET);
                        EE_SaveReq(EE_TRIMIXSET);
                        Switch_Gas();   // acknowledge algorithm to switch gas according to new gas switch done above
                        if(GUI_TMT_Num_InSetting == TMT_OFF)
                        {
                            if(OpcodeForR2s>=DIVE_GAUGE_MAIN) /*go to Switch gas from underwater*/
                            {
                                NewOpcode = OpcodeForR2s;
                            }
                            else
                            {
                                NewOpcode = S21_GAS_SWITCH;
                            }
                        }

                    }
                }
                else
                {
                    if(GUI_GAS_SWITCH_Step != GAS_SWITCH_TMT) // change from GAS_SWITCH_MOD to GAS_SWITCH_TMT
                    {
                        GUI_GAS_SWITCH_Step = GAS_SWITCH_TMT; // To show TMT at GAS SWITCH page
                        NewOpcode = OldOpcode;
                    }
                    else
                        NewOpcode = OldOpcode;
                }
                break;

            case GAS_SWITCH_TO_GAS_6:

                if(GUI_TMT_Battery[GUI_TankN_Linked]==TMT_SEARCHING)	 // if linked, then start searching Connection Data (PSI or mBar)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and in searching TMT

                    // TMT_DataSearching(GUI_TankN_Linked);		   // Obtain Data from TMTx

                    if(GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW /* according to the check result from TMT_DataSearching(GUI_TankN_Linked) */)
                    {
                        GUI_TMT_Battery[GUI_TankN_Linked]=TMT_BATT_LOW;
                    }
                }
                else if((GUI_TMT_Battery[GUI_TankN_Linked]>=TMT_BATT_LOW)/* to add 10 second wait logic here */)
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure in PSI (or BAR)
                }
                else
                {
                    // GUI shows Gas#, TMTx, FO2/FHe and TMTx Pressure information all blank
                }

                NewOpcode = GAS_SWITCH_TO_GAS_6;    // stays at same page

                break;
            }
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Dive Planner Menu

    case DIVE_PL_TIME_LIMITS:

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S62_DIVE_PLANNER,  DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM,			OldOpcode,  DIVE_PL_TIME_LIMITS_SET,    ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S62_DIVE_PLANNER,  DIVE_PL_DIVE_SIM,  DIVE_PL_DEPTH_LIMITS,		OldOpcode,  DIVE_PL_TIME_LIMITS_SET,    ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }

        if(NewOpcode == DIVE_PL_TIME_LIMITS_SET)
        {
            /*Get the PLAN data everytime update the MENU*/
            InitializePLAN();
            Display_PLANGF();
            BrowsePLAN();
            //UpdateScr_MenuModeDive();
            //UpdateMenstat
            //prePlanIndex_u8 = 0;

            GUI_PageIndex = 1;
            GUI_MenuIndex = 1;

            for(i=24; i>=3; i--)
            {
                if(Plan_DEPTH_NDT_OTR_PO2[i][1]==0)
                {
                    GUI_MenuIndexMAX = i-2;
                }
            }
            //GUI_MenuIndexMAX = (PLAN_INDEX_HI - PLAN_INDEX_LO + 2);          // The index to distinguish the Different Info/Data showning on the Same Page

            GUI_PageIndexMAX = (uint8_t)ceil((float)GUI_MenuIndexMAX/6) ;            // 6 is for the Max menu items (lines) of the Plan Depth-TimeLimit page.  In DSX, there are 6 lines per page
        }

        break;

    case DIVE_PL_DEPTH_LIMITS:

        NewOpcode = Opcode_Matrix( S62_DIVE_PLANNER,  DIVE_PL_TIME_LIMITS,  DIVE_PL_DIVE_SIM,			OldOpcode,  DIVE_PL_DEPTH_LIMITS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case DIVE_PL_DIVE_SIM:
        GUI_DIVE_SIMULATOR_NEW_CONT     = DIVE_SIMULATOR_MODE;
        GUI_DIVE_SIMULATOR_SAC_CuFt     = DIVE_SIMULATOR_SAC_CUFT;
        GUI_DIVE_SIMULATOR_SAC_Ltr      = DIVE_SIMULATOR_SAC_LTR;
        GUI_DIVE_SIMULATOR_DEPTH_Ft     = DIVE_SIMULATOR_DEPTH_FT;
        GUI_DIVE_SIMULATOR_DEPTH_Mt     = DIVE_SIMULATOR_DEPTH_M;
        GUI_DIVE_SIMULATOR_Time         = DIVE_SIMULATOR_TIME;
        GUI_DIVE_SIMULATOR_SP           = DIVE_SIMULATOR_SP;
        //GUI_DIVE_TIMELIMITS_Depth       = DIVE_TIMELIMITS_DEPTH;
        //GUI_DIVE_TIMELIMITS_Time        = DIVE_TIMELIMITS_TIME;

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( S62_DIVE_PLANNER,  DIVE_PL_TIME_LIMITS,	DIVE_PL_TIME_LIMITS,    OldOpcode,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS,    ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( S62_DIVE_PLANNER,  DIVE_PL_DEPTH_LIMITS,  DIVE_PL_TIME_LIMITS,	OldOpcode,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS,    ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }

        break;

    case DIVE_PL_DIVE_SIM_NEWORCONTINUOS:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_SIMULATEDIVE,         DIVE_PL_DIVE_SIM_DEPTH,			OldOpcode,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DIVE_PL_DIVE_SIM_DEPTH:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS,     DIVE_PL_DIVE_SIM_TIME,		OldOpcode,  DIVE_PL_DIVE_SIM_DEPTH_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DIVE_PL_DIVE_SIM_TIME:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_DEPTH,  DIVE_PL_DIVE_SIM_SAC,	OldOpcode,  DIVE_PL_DIVE_SIM_TIME_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DIVE_PL_DIVE_SIM_SAC:

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_TIME,  DIVE_PL_DIVE_SIM_SP,	   OldOpcode,  DIVE_PL_DIVE_SIM_SAC_SET,   ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_TIME,  DIVE_PL_DIVE_SIM_SIMULATEDIVE,	   OldOpcode,  DIVE_PL_DIVE_SIM_SAC_SET,   ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }

        break;
    case DIVE_PL_DIVE_SIM_SP:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_SAC,     DIVE_PL_DIVE_SIM_SIMULATEDIVE,	OldOpcode,  DIVE_PL_DIVE_SIM_SP_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    /*Dive PLAN Page -> Bailout -> Bailout consumtion -> Summary
    *-----------------------------------------------------------------------------*/
    case DIVE_PL_DIVE_SIM_SIMULATEDIVE:
        /*Specific update to Dive simulator set*/
        HandleButtonDiveSimulator_SET(&NewOpcode, &OldOpcode);
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_01:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_02:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_03:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_04:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_05:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_06:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_07:
    case DIVE_SIMDIVE_DIVPLAN_PAGE_08:
        HandleButtonDiveSimulator_DIVEPLAN(&NewOpcode, &OldOpcode);
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_01:
    case DIVE_SIMDIVE_BAILOUT_PAGE_02:
    case DIVE_SIMDIVE_BAILOUT_PAGE_03:
    case DIVE_SIMDIVE_BAILOUT_PAGE_04:
    case DIVE_SIMDIVE_BAILOUT_PAGE_05:
    case DIVE_SIMDIVE_BAILOUT_PAGE_06:
    case DIVE_SIMDIVE_BAILOUT_PAGE_07:
    case DIVE_SIMDIVE_BAILOUT_PAGE_08:
    case DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS:
    case DIVE_SIMDIVE_SUMMARY:
        HandleButtonDiveSimulator_BAILOUTPLAN(&NewOpcode, &OldOpcode);
        break;
    /*Incase of these page -> return  back to DIVE SIMULATE DIVE inselect*/
    case DIVE_SIMDIVE_DIVPLAN_NODECO:       /*NO DECO page*/
    case DIVE_SIMDIVE_DIVPLAN_NOTENTIM:     /*Not enough time page*/
    case DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED: /*Max exceed value page*/
    case DIVE_SIMDIVE_DECOTIME_EXCEED: /*Deco time > 99 Min*/
    case DIVE_SIMDIVE_TOOHIGH_PO2: /*Too high PO2*/
        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_SIMULATEDIVE,  DIVE_PL_DIVE_SIM_SIMULATEDIVE,  DIVE_PL_DIVE_SIM_SIMULATEDIVE, DIVE_PL_DIVE_SIM_SIMULATEDIVE,  DIVE_PL_DIVE_SIM_SIMULATEDIVE, DIVE_PL_DIVE_SIM_SIMULATEDIVE, OldOpcode, OldOpcode, OldOpcode);
        break;
    case DIVE_SIMDIVE_DIVPLAN_CALCULATING:  /*Calculating -> Flashing state handle separately*/
        HandleButtonDiveSimulator_Calculating(&NewOpcode, &OldOpcode);
        break;
    /*-----------------------------------------------------------------------------*/
    case DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_NEWORCONTINUOS,  DataDec,  DataInc,		OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {

        case DataInc:
            GUI_DIVE_SIMULATOR_NEW_CONT = (uint8_t)SettingData(GUI_DIVE_SIMULATOR_NEW_CONT, SIM_MODE_CONT_01, SIM_MODE_NEW_00, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            GUI_DIVE_SIMULATOR_NEW_CONT = (uint8_t)SettingData(GUI_DIVE_SIMULATOR_NEW_CONT, SIM_MODE_CONT_01, SIM_MODE_NEW_00, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            DIVE_SIMULATOR_MODE = GUI_DIVE_SIMULATOR_NEW_CONT;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DIVE_PL_DIVE_SIM_NEWORCONTINUOS;						 // return to menu
            break;
        }
        break;

    case DIVE_PL_SIM_DIVE:

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_SAC,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS,	OldOpcode,  DIVE_PL_SIM_DIVE_DIVE_PLAN,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM,  DIVE_PL_DIVE_SIM_SAC,  DIVE_PL_DIVE_SIM_NEWORCONTINUOS,	OldOpcode,  DIVE_PL_SIM_DIVE_DIVE_PLAN,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }
        break;


    case DIVE_PL_TIME_LIMITS_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_TIME_LIMITS,  DataDec,  DataInc,	ScrollInc,  DIVE_PL_TIME_LIMITS,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);

        /*
          GUI_PageIndex                         to provides the page of Time Limits Menu needs to display

          Plan_DEPTH_NDT_OTR_PO2 matrix         to provide Time Limits data
        */

        switch (NewOpcode)
        {

        case DataInc:
            GUI_PageIndex = (uint8_t)SettingData(GUI_PageIndex, GUI_PageIndexMAX, 1, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            GUI_PageIndex = (uint8_t)SettingData(GUI_PageIndex, GUI_PageIndexMAX, 1, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;

        case ScrollInc:
            NewOpcode = OldOpcode;
            break;
        }
        break;

    /*
            GUI_DIVE_SIMULATOR_SAC_CuFt     = DIVE_SIMULATOR_SAC_CUFT;
            GUI_DIVE_SIMULATOR_SAC_Ltr      = DIVE_SIMULATOR_SAC_LTR;
            GUI_DIVE_SIMULATOR_DEPTH_Ft     = DIVE_SIMULATOR_DEPTH_FT;
            GUI_DIVE_SIMULATOR_DEPTH_Mt     = DIVE_SIMULATOR_DEPTH_M;
            GUI_DIVE_SIMULATOR_Time         = DIVE_SIMULATOR_TIME;
            GUI_DIVE_SIMULATOR_SP           = DIVE_SIMULATOR_SP;
            //GUI_DIVE_TIMELIMITS_Depth       = DIVE_TIMELIMITS_DEPTH;
            //GUI_DIVE_TIMELIMITS_Time        = DIVE_TIMELIMITS_TIME;
    */

    case DIVE_PL_DIVE_SIM_DEPTH_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_DEPTH,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(UNITS==NVD_IMPERIAL)
                GUI_DIVE_SIMULATOR_DEPTH_Ft = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_DEPTH_Ft, 420, 10, 1, data_increase);
            else
                GUI_DIVE_SIMULATOR_DEPTH_Mt = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_DEPTH_Mt, 130, 3, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_DIVE_SIMULATOR_DEPTH_Ft = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_DEPTH_Ft, 420, 10, 1, data_decrease);
            else
                GUI_DIVE_SIMULATOR_DEPTH_Mt = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_DEPTH_Mt, 130, 3, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            DIVE_SIMULATOR_DEPTH_FT = GUI_DIVE_SIMULATOR_DEPTH_Ft;
            DIVE_SIMULATOR_DEPTH_M = GUI_DIVE_SIMULATOR_DEPTH_Mt;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DIVE_PL_DIVE_SIM_DEPTH;						 // return to menu
            break;
        }


        break;
    case DIVE_PL_DIVE_SIM_TIME_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_TIME,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_DIVE_SIMULATOR_Time = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_Time, 200, 5, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_DIVE_SIMULATOR_Time = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_Time, 200, 5, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            DIVE_SIMULATOR_TIME = GUI_DIVE_SIMULATOR_Time;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DIVE_PL_DIVE_SIM_TIME; 						// return to menu
            break;
        }


        break;
    case DIVE_PL_DIVE_SIM_SAC_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_SAC,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        //DIVE_SIMULATOR_SAC = (uint16_t)SettingData(DIVE_SIMULATOR_SAC, 150, 40, 5, data_type);
        //NewOpcode = OldOpcode;

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_DIVE_SIMULATOR_SAC_CuFt = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_SAC_CuFt, 150, 40, 5, data_type);
            else
                GUI_DIVE_SIMULATOR_SAC_Ltr = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_SAC_Ltr, 42, 11, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(UNITS==NVD_IMPERIAL)
                DIVE_SIMULATOR_SAC_CUFT = GUI_DIVE_SIMULATOR_SAC_CuFt;
            else
                DIVE_SIMULATOR_SAC_LTR = GUI_DIVE_SIMULATOR_SAC_Ltr;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DIVE_PL_DIVE_SIM_SAC;						 // return to menu
            break;
        }

        break;

    case DIVE_PL_DIVE_SIM_SP_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DIVE_SIM_SP,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_DIVE_SIMULATOR_SP = (uint16_t)SettingData(GUI_DIVE_SIMULATOR_SP, 150, 40, 10, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            DIVE_SIMULATOR_SP = GUI_DIVE_SIMULATOR_SP;
            EE_SaveReq(EE_USERSET);
            NewOpcode = DIVE_PL_DIVE_SIM_SP;						 // return to menu
            break;
        }


        break;

    case DIVE_PL_DEPTH_LIMITS_SET:

        NewOpcode = Opcode_Matrix( DIVE_PL_DEPTH_LIMITS,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_DEPTH_LIMITS,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case DIVE_PL_SIM_DIVE_DIVE_PLAN:

        if(CC_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_SIM_DIVE,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_SIM_DIVE_BAILOUT_PLAN,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( DIVE_PL_SIM_DIVE,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        }

        break;

    case DIVE_PL_SIM_DIVE_BAILOUT_PLAN:

        NewOpcode = Opcode_Matrix( DIVE_PL_SIM_DIVE_DIVE_PLAN,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP:

        NewOpcode = Opcode_Matrix( DIVE_PL_SIM_DIVE_BAILOUT_PLAN,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_SIM_DIVE_SUMMARY,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case DIVE_PL_SIM_DIVE_SUMMARY:

        NewOpcode = Opcode_Matrix( DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP,  OldOpcode,  OldOpcode,	OldOpcode,  DIVE_PL_SIM_DIVE,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Bailout PO2 Limits Menu
    /*
    uint8_t GUI_OC_SM_PO2_Min;              // GUI settings for OCmin       // updated by YS 2022 1026
    uint8_t GUI_OC_SM_PO2_Max;              // GUI settings for OCmax       // updated by YS 2022 1026
    uint8_t GUI_OC_SM_PO2_Deco;             // GUI settings for OCdeco      // updated by YS 2022 1026
    uint8_t GUI_BO_PO2_Min;            // GUI settings for BOmin       // updated by YS 2022 1026
    uint8_t GUI_BO_PO2_Max;            // GUI settings for BOmax       // updated by YS 2022 1026
    uint8_t GUI_BO_PO2_Deco;           // GUI settings for BOdeco      // updated by YS 2022 1026

            GUI_OC_SM_PO2_Min = SCUBA_Set.OCmin;
            GUI_OC_SM_PO2_Min = SCUBA_Set.OCmax;
            GUI_OC_SM_PO2_Min = SCUBA_Set.OCdeco;
            GUI_BO_PO2_Min = SCUBA_Set.BOmin;
            GUI_BO_PO2_Min = SCUBA_Set.BOmax;
            GUI_BO_PO2_Min = SCUBA_Set.BOdeco;

    #define OC_SM_MIN_PO2		SCUBA_Set.OCmin         // 0.16 - 0.29 (incr.: 0.01),  display = data/100
    #define OC_SM_MAX_PO2		SCUBA_Set.OCmax         // 1.00 - 1.99 (incr.: 0.01),  display = data/100
    #define OC_SM_DECO_PO2		SCUBA_Set.OCdeco        // 1.00 - 1.99 (incr.: 0.01),  display = data/100

    #define BO_MIN_PO2	        SCUBA_Set.BOmin         // 0.16 - 0.29 (incr.: 0.01),  display = data/100
    #define BO_MAX_PO2	        SCUBA_Set.BOmax         // 1.00 - 1.99 (incr.: 0.01),  display = data/100
    #define BO_DECO_PO2	        SCUBA_Set.BOdeco        // 1.00 - 1.99 (incr.: 0.01),  display = data/100

    */

    case BAILOUT_PO2_OC_MIN:

        if(OC_MODE||SM_MODE)
        {
            NewOpcode = Opcode_Matrix( BackupOpcode,  BAILOUT_PO2_OC_DECO,  BAILOUT_PO2_OC_MAX,		OldOpcode,  BAILOUT_PO2_OC_MIN_SET,OpcodeForR2s	, OldOpcode, OldOpcode,	 OldOpcode);

            if(GUI_OC_SM_PO2_Min <16 || GUI_OC_SM_PO2_Min>29) {
                GUI_OC_SM_PO2_Min = 16; //set Min when out of range
                OC_SM_MIN_PO2 = GUI_OC_SM_PO2_Min;
                EE_SaveReq(EE_SCUBASET);
            }

            if(GUI_OC_SM_PO2_Max <100 || GUI_OC_SM_PO2_Max>199) {
                GUI_OC_SM_PO2_Max = 100; //set Min when out of range
                OC_SM_MAX_PO2 = GUI_OC_SM_PO2_Max;
                EE_SaveReq(EE_SCUBASET);
            }

            if(GUI_OC_SM_PO2_Deco <100 || GUI_OC_SM_PO2_Deco>199) {
                GUI_OC_SM_PO2_Deco = 100; //set Min when out of range
                OC_SM_DECO_PO2 = GUI_OC_SM_PO2_Deco;
                EE_SaveReq(EE_SCUBASET);
            }
        }
        else
        {   // for CC and BO Mode
            NewOpcode = Opcode_Matrix( BackupOpcode,  BAILOUT_PO2_OC_DECO,  BAILOUT_PO2_OC_MAX,		OldOpcode,  BAILOUT_PO2_OC_MIN_SET, OpcodeForR2s	, OldOpcode, OldOpcode,	 OldOpcode);

            if(GUI_BO_PO2_Min <16 || GUI_BO_PO2_Min>29) {
                GUI_BO_PO2_Min = 16; //set Min when out of range
                BO_MIN_PO2 = GUI_BO_PO2_Min;
                EE_SaveReq(EE_SCUBASET);
            }

            if(GUI_BO_PO2_Max <100 || GUI_BO_PO2_Max>199) {
                GUI_BO_PO2_Max = 100; //set Min when out of range
                BO_MAX_PO2 = GUI_BO_PO2_Max;
                EE_SaveReq(EE_SCUBASET);
            }

            if(GUI_BO_PO2_Deco <100 || GUI_BO_PO2_Deco>199) {
                GUI_BO_PO2_Deco = 100; //set Min when out of range
                BO_DECO_PO2 = GUI_BO_PO2_Deco;
                EE_SaveReq(EE_SCUBASET);
            }
        }
        break;

    case BAILOUT_PO2_OC_MIN_SET:
        NewOpcode = Opcode_Matrix( BAILOUT_PO2_OC_MIN,  DataDec,  DataInc,	ScrollInc,  SaveAndDone, OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Min = (uint8_t)SettingData(GUI_OC_SM_PO2_Min, 29, 16, 1, data_increase);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Min = (uint8_t)SettingData(GUI_BO_PO2_Min, 29, 16, 1, data_increase);
            }
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Min = (uint8_t)SettingData(GUI_OC_SM_PO2_Min, 29, 16, 1, data_decrease);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Min = (uint8_t)SettingData(GUI_BO_PO2_Min, 29, 16, 1, data_decrease);
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            OC_SM_MIN_PO2   = GUI_OC_SM_PO2_Min;
            BO_MIN_PO2      = GUI_BO_PO2_Min;
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = BAILOUT_PO2_OC_MIN; 						// return to menu
            break;
        }
        break;

    case BAILOUT_PO2_OC_MAX:
        NewOpcode = Opcode_Matrix( BackupOpcode,  BAILOUT_PO2_OC_MIN,  BAILOUT_PO2_OC_DECO,		OldOpcode,  BAILOUT_PO2_OC_MAX_SET,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case BAILOUT_PO2_OC_MAX_SET:
        NewOpcode = Opcode_Matrix( BAILOUT_PO2_OC_MAX,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,		OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Max = (uint8_t)SettingData(GUI_OC_SM_PO2_Max, 199, 100, 1, data_increase);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Max = (uint8_t)SettingData(GUI_BO_PO2_Max, 199, 100, 1, data_increase);
            }
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Max = (uint8_t)SettingData(GUI_OC_SM_PO2_Max, 199, 100, 1, data_decrease);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Max = (uint8_t)SettingData(GUI_BO_PO2_Max, 199, 100, 1, data_decrease);
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            OC_SM_MAX_PO2   = GUI_OC_SM_PO2_Max;
            BO_MAX_PO2      = GUI_BO_PO2_Max;
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = BAILOUT_PO2_OC_MAX; 						// return to menu
            break;
        }
        break;

    case BAILOUT_PO2_OC_DECO:
        NewOpcode = Opcode_Matrix( BackupOpcode,  BAILOUT_PO2_OC_MAX,  BAILOUT_PO2_OC_MIN,      OldOpcode,  BAILOUT_PO2_OC_DECO_SET,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case BAILOUT_PO2_OC_DECO_SET:
        NewOpcode = Opcode_Matrix( BAILOUT_PO2_OC_DECO, DataDec,  DataInc,	ScrollInc,  SaveAndDone,	OpcodeForR2s, OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Deco = (uint8_t)SettingData(GUI_OC_SM_PO2_Deco, 199, 100, 1, data_increase);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Deco = (uint8_t)SettingData(GUI_BO_PO2_Deco, 199, 100, 1, data_increase);
            }
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            if(OC_MODE||SM_MODE)
            {
                GUI_OC_SM_PO2_Deco = (uint8_t)SettingData(GUI_OC_SM_PO2_Deco, 199, 100, 1, data_decrease);
            }
            else
            {   // for CC and BO Mode
                GUI_BO_PO2_Deco = (uint8_t)SettingData(GUI_BO_PO2_Deco, 199, 100, 1, data_decrease);
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            OC_SM_DECO_PO2   = GUI_OC_SM_PO2_Deco;
            BO_DECO_PO2      = GUI_BO_PO2_Deco;
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = BAILOUT_PO2_OC_DECO; 						// return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set Conservatism - TEC, SPORT

    case S105_SET_CONSERV_TEC_SPORT:

        NewOpcode = Opcode_Matrix( S83_SET_CONSERVATISM,  DataDec, DataInc, OldOpcode,	SaveAndDone,  ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_CONSV_Switch = (CONSV_TecSport_t)SettingData(GUI_CONSV_Switch, CONSV_SPORT, CONSV_TEC, 4, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_CONSV_Switch == CONSV_TEC)
            {
                CONSER_SETPOINTS = CONSV_TEC;

                GUI_TecGF_Hi = CONSER_TEC_GFHIGH;               // GUI settings for TEC GF High
                GUI_TecGF_Lo = CONSER_TEC_GFLOW;                // GUI settings for TEC GF Low

                NewOpcode = CONSERV_TEC_GF_LOW;
            }
            else if(GUI_CONSV_Switch == CONSV_SPORT)
            {
                CONSER_SETPOINTS = CONSV_SPORT;

                if(GUI_CONSV_Sport_Switch==CONSV_SPORT_LOW)
                {
                    GUI_SportGF_Hi = 90;
                    GUI_SportGF_Lo = 90;
                }
                else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_MED)
                {
                    GUI_SportGF_Hi = 80;
                    GUI_SportGF_Lo = 35;
                }
                else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_HIGH)
                {
                    GUI_SportGF_Hi = 70;
                    GUI_SportGF_Lo = 30;
                }

                NewOpcode = S106_SET_CONSERV_SPORT;
            }
            CONSER_SETPOINTS = CONSER_SETPOINTS;
            EE_SaveReq(EE_SCUBASET);
            break;
        }
        break;

    case S106_SET_CONSERV_SPORT:

        NewOpcode = Opcode_Matrix( S105_SET_CONSERV_TEC_SPORT,  DataDec,  DataInc,  OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
            GUI_CONSV_Sport_Switch = (CONSV_Sport_t)SettingData(GUI_CONSV_Sport_Switch, CONSV_SPORT_HIGH, CONSV_SPORT_LOW, 1, data_increase);  // 2,1,0 = HIGH/MEDIUM/LOW
            if(GUI_CONSV_Sport_Switch==CONSV_SPORT_HIGH)
            {
                GUI_SportGF_Hi = 70;
                GUI_SportGF_Lo = 30;
            }
            else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_MED)
            {
                GUI_SportGF_Hi = 80;
                GUI_SportGF_Lo = 35;
            }
            else
            {
                GUI_SportGF_Hi = 90;
                GUI_SportGF_Lo = 90;
            }
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_CONSV_Sport_Switch = (CONSV_Sport_t)SettingData(GUI_CONSV_Sport_Switch, CONSV_SPORT_HIGH, CONSV_SPORT_LOW, 1, data_decrease);  // 2,1,0 = HIGH/MEDIUM/LOW
            if(GUI_CONSV_Sport_Switch==CONSV_SPORT_HIGH)
            {
                GUI_SportGF_Hi = 70;
                GUI_SportGF_Lo = 30;
            }
            else if(GUI_CONSV_Sport_Switch==CONSV_SPORT_MED)
            {
                GUI_SportGF_Hi = 80;
                GUI_SportGF_Lo = 35;
            }
            else
            {
                GUI_SportGF_Hi = 90;
                GUI_SportGF_Lo = 90;
            }
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            //CONSER_SPORT_SETPOINTS = GUI_CONSV_Sport_Switch;
            CONSER_SPORT_GFHIGH = GUI_SportGF_Hi;                           // GUI settings for SportGF_Hi
            CONSER_SPORT_GFLOW  = GUI_SportGF_Lo;                           // GUI settings for SportGF_Lo
            CONSER_SPORT_SETPOINTS = GUI_CONSV_Sport_Switch;
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = S83_SET_CONSERVATISM;
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Conservatism TEC Low, High
    case CONSERV_TEC_GF_LOW:
        GUI_TecGF_Lo = CONSER_TEC_GFLOW ;
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)CONSV_GF_LOW;

        NewOpcode = Opcode_Matrix( S83_SET_CONSERVATISM,  CONSERV_TEC_GF_HIGH,	CONSERV_TEC_GF_HIGH,   OldOpcode,  CONSERV_TEC_GF_LOW_SET, ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case CONSERV_TEC_GF_LOW_SET:

        NewOpcode = Opcode_Matrix( CONSERV_TEC_GF_LOW, DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_TecGF_Lo = (uint8_t)SettingData(GUI_TecGF_Lo, CONSER_TEC_GFHIGH, 10, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_TecGF_Lo = (uint8_t)SettingData(GUI_TecGF_Lo, CONSER_TEC_GFHIGH, 10, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            CONSER_TEC_GFLOW = GUI_TecGF_Lo;
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = CONSERV_TEC_GF_LOW; 						// return to menu
            break;
        }
        break;

    case CONSERV_TEC_GF_HIGH:

        NewOpcode = Opcode_Matrix( S83_SET_CONSERVATISM,	CONSERV_TEC_GF_LOW,  CONSERV_TEC_GF_LOW,  OldOpcode,  CONSERV_TEC_GF_HIGH_SET,	  ReturnToMainPage(), OldOpcode, OldOpcode,	   OldOpcode);
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)CONSV_GF_HIGH;
        GUI_TecGF_Hi =CONSER_TEC_GFHIGH;
        break;

    case CONSERV_TEC_GF_HIGH_SET:

        NewOpcode = Opcode_Matrix( CONSERV_TEC_GF_HIGH,  DataDec,  DataInc,	ScrollInc,  SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_TecGF_Hi = (uint8_t)SettingData(GUI_TecGF_Hi, 90, CONSER_TEC_GFLOW, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_TecGF_Hi = (uint8_t)SettingData(GUI_TecGF_Hi, 90, CONSER_TEC_GFLOW, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            CONSER_TEC_GFHIGH = GUI_TecGF_Hi;
            GFHighSettingValue = CONSER_TEC_GFHIGH;
            Update_Algo();      // Acknowledge DiveAlgo for the new change
            EE_SaveReq(EE_SCUBASET);
            NewOpcode = CONSERV_TEC_GF_HIGH; 						// return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM -> AUDIBLE/VIBRATION

    case ALARM_AUDIBLE:
        GUI_SWITCH_AlarmAudible = SWITCH_AlarmAudible;

        NewOpcode = Opcode_Matrix( S106_AL_AUDIBLE,  ALARM_VIBRATION,  ALARM_VIBRATION,	OldOpcode,  ALARM_AUDIBLE_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case ALARM_AUDIBLE_SET:
        NewOpcode = Opcode_Matrix( ALARM_AUDIBLE,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SWITCH_AlarmAudible = (GUI_SWITCH_AlarmAudible==NVD_ON)? NVD_OFF:NVD_ON;
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            SWITCH_AlarmAudible = GUI_SWITCH_AlarmAudible;
            EE_SaveReq(EE_USERSET);
            NewOpcode = ALARM_AUDIBLE; 						// return to menu
            break;
        }

        if(GUI_SWITCH_AlarmAudible==NVD_ON)
            SystemStatus.buzzer_on_req = true;

        break;

    case ALARM_VIBRATION:
        GUI_SWITCH_AlarmVibeOn = SWITCH_AlarmVibeOn;

        NewOpcode = Opcode_Matrix( S106_AL_AUDIBLE,  ALARM_AUDIBLE,  ALARM_AUDIBLE,	OldOpcode,  ALARM_VIBRATION_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case ALARM_VIBRATION_SET:

        NewOpcode = Opcode_Matrix( ALARM_VIBRATION,   DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SWITCH_AlarmVibeOn = (GUI_SWITCH_AlarmVibeOn==NVD_ON)? NVD_OFF:NVD_ON;
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            SWITCH_AlarmVibeOn = GUI_SWITCH_AlarmVibeOn;
            EE_SaveReq(EE_USERSET);
            NewOpcode = ALARM_VIBRATION; 						// return to menu
            break;
        }

        if(GUI_SWITCH_AlarmVibeOn==NVD_ON)
            SystemStatus.vibe_on_req = true;

        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    case ALARM_DEPTH_STAT:

        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_DEPTHAL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_DEPTHAL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case CheckConditions:
        case SaveAndDone:
            if(GUI_DEPTHAL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_DEPTH_SET;            // go to settings
            }
            else
            {
                DEPTHAL_STAT = GUI_DEPTHAL_STAT;       // update EE image
                EE_SaveReq(EE_SCUBASET);               // save to EE
                NewOpcode = S108_AL_DEPTH;             // back to Menu
            }
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    case ALARM_DEPTH_SET:

        NewOpcode = Opcode_Matrix( ALARM_DEPTH_STAT, DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        //data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            if(UNITS==NVD_IMPERIAL)
                GUI_DepthAlarmFT = (uint16_t)SettingData(GUI_DepthAlarmFT, 420, 30, 10, data_increase);
            else
                GUI_DepthAlarmM = (uint16_t)SettingData(GUI_DepthAlarmM, 130, 10, 5, data_increase);
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_DepthAlarmFT = (uint16_t)SettingData(GUI_DepthAlarmFT, 420, 30, 10, data_decrease);
            else
                GUI_DepthAlarmM = (uint16_t)SettingData(GUI_DepthAlarmM, 130, 10, 5, data_decrease);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            DEPTHAL_FT = GUI_DepthAlarmFT;
            DEPTHAL_M = GUI_DepthAlarmM;
            GUI_DEPTHAL_STAT = NVD_ON;   // force to turn ON
            DEPTHAL_STAT = GUI_DEPTHAL_STAT;    // update EE image
            EE_SaveReq(EE_SCUBASET);            // save to EE
            NewOpcode = S108_AL_DEPTH;		// return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  DIVE TIME/TT
    case ALARM_DIVETIME:
        GUI_DIVE_T_AL_STAT = (NVD_status_t)DIVE_T_AL_STAT;
        GUI_DIVE_T_AL = DIVE_T_AL;
        GUI_TTS_AL_STAT = (NVD_status_t)TTS_AL_STAT;
        GUI_TTS_AL = TTS_AL;

        NewOpcode = Opcode_Matrix( S000_AL_DIVETIME_TTS,  ALARM_TTS,  ALARM_TTS,	OldOpcode,	ALARM_DIVETIME_STAT,  ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case ALARM_DIVETIME_STAT:

        NewOpcode = Opcode_Matrix(CheckConditions,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_DIVE_T_AL_STAT = (NVD_status_t)SettingData(GUI_DIVE_T_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case CheckConditions:
        case SaveAndDone:
            if(GUI_DIVE_T_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_DIVETIME_SET;         // go to settings
            }
            else
            {
                DIVE_T_AL_STAT = GUI_DIVE_T_AL_STAT;          // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE

                if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)
                {
                    NewOpcode = ALARM_DIVETIME;

                }
                else if(GSM_MODE||GAUGE_MODE) {
                    NewOpcode = S111_AL_DIVETIME;
                }
            }
            break;
        }
        break;

    case ALARM_DIVETIME_SET:

        NewOpcode = Opcode_Matrix( ALARM_DIVETIME_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_DIVE_T_AL = (uint8_t)SettingData(GUI_DIVE_T_AL, 180, 10, 10, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            DIVE_T_AL = GUI_DIVE_T_AL;
            GUI_DIVE_T_AL_STAT = NVD_ON; // force to turn ON
            DIVE_T_AL_STAT = GUI_DIVE_T_AL_STAT;  // update EE image
            EE_SaveReq(EE_SCUBASET);            // save to EE

            if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)
            {
                NewOpcode = ALARM_DIVETIME;

            }
            else if(GSM_MODE||GAUGE_MODE) {
                NewOpcode = S111_AL_DIVETIME;
            }

            break;
        }
        break;

    case ALARM_TTS:
        GUI_DIVE_T_AL_STAT = (NVD_status_t)DIVE_T_AL_STAT;
        GUI_DIVE_T_AL = DIVE_T_AL;
        GUI_TTS_AL_STAT = (NVD_status_t)TTS_AL_STAT;
        GUI_TTS_AL = TTS_AL;

        NewOpcode = Opcode_Matrix(S000_AL_DIVETIME_TTS,  ALARM_DIVETIME,  ALARM_DIVETIME,	OldOpcode,	ALARM_TTS_STAT,  ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case ALARM_TTS_STAT:

        NewOpcode = Opcode_Matrix( ALARM_TTS, DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_TTS_AL_STAT = (NVD_status_t)SettingData(GUI_TTS_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_TTS_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_TTS_SET;         // go to settings
            }
            else
            {
                TTS_AL_STAT = GUI_TTS_AL_STAT;          // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = ALARM_TTS;           // back to Menu
            }
            break;
        }
        break;

    case ALARM_TTS_SET:

        NewOpcode = Opcode_Matrix( ALARM_TTS_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_TTS_AL = (uint8_t)SettingData(GUI_TTS_AL, 180, 10, 10, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            TTS_AL = GUI_TTS_AL;
            GUI_TTS_AL_STAT = NVD_ON; // force to turn ON
            TTS_AL_STAT = GUI_TTS_AL_STAT;  // update EE image
            EE_SaveReq(EE_SCUBASET);            // save to EE
            NewOpcode = ALARM_TTS;	// return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  DTR
    /*
        GUI_DTR_AL_STAT = DTR_AL_STAT;              // GUI settings for DTR_AL_STAT (Off, On, Set)
        GUI_DTR_AL = DTR_AL;                        // GUI settings for DTR_AL
    */
    case ALARM_DTR_STAT:

        NewOpcode = Opcode_Matrix( S116_AL_DTR,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_DTR_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_DTR_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_DTR_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_DTR_SET;              // go to settings
            }
            else
            {
                DTR_AL_STAT = GUI_DTR_AL_STAT;          // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S116_AL_DTR;                // back to Menu
            }
            break;
        }
        break;

    case ALARM_DTR_SET:

        NewOpcode = Opcode_Matrix( ALARM_DTR_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_DTR_AL = (uint8_t)SettingData(GUI_DTR_AL, 20, 1, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            DTR_AL = GUI_DTR_AL;
            GUI_DTR_AL_STAT = NVD_ON;    // force to turn ON
            DTR_AL_STAT = GUI_DTR_AL_STAT;      // update EE image
            EE_SaveReq(EE_SCUBASET);            // save to EE
            NewOpcode = S116_AL_DTR;	        // return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  TANK_PRESS
    case ALARM_TANK_PRESS_STAT:

        NewOpcode = Opcode_Matrix( S116_AL_TANK_PRESS,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_TankP_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_TankP_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_TankP_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_TANK_PRESS_SET;       // go to settings
            }
            else
            {
                TankP_AL_STAT = GUI_TankP_AL_STAT;      // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S116_AL_TANK_PRESS;                // back to Menu
            }
            break;
        }
        break;

    case ALARM_TANK_PRESS_SET:

        NewOpcode = Opcode_Matrix( ALARM_TANK_PRESS_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_TankP_AL_PSI = (uint16_t)SettingData(GUI_TankP_AL_PSI, 3000, 300, 100, data_type);
            else
                GUI_TankP_AL_BAR = (uint8_t)SettingData(GUI_TankP_AL_BAR, 200, 20, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            TANK_PRESS_PSI = GUI_TankP_AL_PSI;            // update data
            TANK_PRESS_BAR = GUI_TankP_AL_BAR;            // update data
            GUI_TankP_AL_STAT = NVD_ON;          // force to turn ON
            TankP_AL_STAT = GUI_TankP_AL_STAT;          // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S116_AL_TANK_PRESS;	        // return to menu
            break;
        }
        break;


    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  CC6_PRESS

    case ALARM_CC6_PRESS_STAT:

        NewOpcode = Opcode_Matrix( S119_AL_CC6_PRESS,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_CC6P_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_CC6P_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_CC6P_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_CC6_PRESS_SET;       // go to settings
            }
            else
            {
                CC6P_AL_STAT = GUI_CC6P_AL_STAT;        // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S119_AL_CC6_PRESS;          // back to Menu
            }
            break;
        }
        break;

    case ALARM_CC6_PRESS_SET:

        NewOpcode = Opcode_Matrix( ALARM_CC6_PRESS_STAT, DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_CC6P_AL_PSI = (uint16_t)SettingData(GUI_CC6P_AL_PSI, 3000, 300, 100, data_type);
            else
                GUI_CC6P_AL_BAR = (uint8_t)SettingData(GUI_CC6P_AL_BAR, 200, 20, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            CC6P_AL_PSI = GUI_CC6P_AL_PSI;              // update data
            CC6P_AL_BAR = GUI_CC6P_AL_BAR;              // update data
            GUI_CC6P_AL_STAT = NVD_ON;           // force to turn ON
            CC6P_AL_STAT = GUI_CC6P_AL_STAT;            // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S119_AL_CC6_PRESS;	        // return to menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  GFN2
    case ALARM_GFN2_GF_STAT:
        GUI_N2_AL_STAT = (NVD_status_t)N2_AL_STAT;
        GUI_N2_AL = N2_AL;

        NewOpcode = Opcode_Matrix( S122_AL_GF_N2,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_GF_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_GF_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_GF_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_GFN2_GF_SET;          // go to settings
            }
            else
            {
                GF_AL_STAT = GUI_GF_AL_STAT;            // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = ALARM_GFN2_N2_STAT;         // forward to N2_Alarm
            }
            break;
        }
        break;

    case ALARM_GFN2_GF_SET:

        NewOpcode = Opcode_Matrix( ALARM_GFN2_GF_STAT,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_GF_AL = (uint8_t)SettingData(GUI_GF_AL, 89, 20, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            GF_AL = GUI_GF_AL;                          // update data
            GUI_GF_AL_STAT = NVD_ON;             // force to turn ON
            GF_AL_STAT = GUI_GF_AL_STAT;                // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = ALARM_GFN2_N2_STAT;	        // move to N2 Set Point STAT
            break;
        }
        break;

    case ALARM_GFN2_N2_STAT:

        NewOpcode = Opcode_Matrix( ALARM_GFN2_GF_STAT,  DataDec,  DataInc,	OldOpcode, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_N2_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_N2_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_N2_AL_STAT == NVD_SET)
            {
                NewOpcode = ALARM_GFN2_N2_SET;          // go to settings
            }
            else
            {
                N2_AL_STAT = GUI_N2_AL_STAT;                  // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S122_AL_GF_N2;              // back to Menu
            }
            break;
        }


        break;

    case ALARM_GFN2_N2_SET:

        NewOpcode = Opcode_Matrix( ALARM_GFN2_N2_STAT, DataDec,  DataInc,	ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            GUI_N2_AL = (uint8_t)SettingData(GUI_N2_AL, 99, 70, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            N2_AL = GUI_N2_AL;                          // update data
            GUI_N2_AL_STAT = NVD_ON;             // force to turn ON
            N2_AL_STAT = GUI_N2_AL_STAT;                // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S122_AL_GF_N2;	                // move to N2 Set Point STAT
            break;
        }
        break;

    // Set ALARM ->  TURN/END PRESS ALARMS
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  Turn Pressure
    case S282_ALARM_TURNPRESS:

        if(SM_MODE||GSM_MODE)
            NewOpcode = Opcode_Matrix( S281_AL_TURN_END_PRESS,	S353_ALARM_SWITCHPRESS,  S285_ALARM_ENDPRESS,	OldOpcode,	S283_ALARM_TURNPRESS_STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        else if(OC_MODE||GAUGE_MODE)
            NewOpcode = Opcode_Matrix( S281_AL_TURN_END_PRESS,	S285_ALARM_ENDPRESS,  S285_ALARM_ENDPRESS,	OldOpcode,	S283_ALARM_TURNPRESS_STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case S283_ALARM_TURNPRESS_STAT:

        NewOpcode = Opcode_Matrix( S282_ALARM_TURNPRESS,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);
        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_TurnP_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_TurnP_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_TurnP_AL_STAT == NVD_SET)
            {
                NewOpcode = S284_ALARM_TURNPRESS_SET;          // go to settings
            }
            else
            {
                TurnP_AL_STAT = GUI_TurnP_AL_STAT;                  // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S281_AL_TURN_END_PRESS;              // back to Menu
            }
            break;
        }
        break;

    case S284_ALARM_TURNPRESS_SET:

        NewOpcode = Opcode_Matrix( S283_ALARM_TURNPRESS_STAT,  DataDec,  DataInc,	ScrollInc, SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_TurnP_AL_PSI = (uint16_t)SettingData(GUI_TurnP_AL_PSI, 3000, 1000, 100, data_type);
            else
                GUI_TurnP_AL_BAR = (uint8_t)SettingData(GUI_TurnP_AL_BAR, 200, 70, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            TurnP_AL_PSI = GUI_TurnP_AL_PSI;            // update data
            TurnP_AL_BAR = GUI_TurnP_AL_BAR;            // update data
            GUI_TurnP_AL_STAT = NVD_ON;          // force to turn ON
            TurnP_AL_STAT = GUI_TurnP_AL_STAT;          // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S282_ALARM_TURNPRESS;	        // move to N2 Set Point STAT
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  End Pressure
    case S285_ALARM_ENDPRESS:

        if(SM_MODE||GSM_MODE) {
            NewOpcode = Opcode_Matrix( S281_AL_TURN_END_PRESS,	S282_ALARM_TURNPRESS,  S353_ALARM_SWITCHPRESS,   OldOpcode,  S286_ALARM_ENDPRESS_SET,    ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }
        else if(OC_MODE||GAUGE_MODE) {
            NewOpcode = Opcode_Matrix( S281_AL_TURN_END_PRESS,	S282_ALARM_TURNPRESS,  S282_ALARM_TURNPRESS,   OldOpcode,  S286_ALARM_ENDPRESS_SET,    ReturnToMainPage(), OldOpcode, OldOpcode, 	OldOpcode);
        }

        break;
    case S286_ALARM_ENDPRESS_SET:

        NewOpcode = Opcode_Matrix( S285_ALARM_ENDPRESS,  DataDec,  DataInc,	ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_EndP_AL_PSI = (uint16_t)SettingData(GUI_EndP_AL_PSI, 1500, ALARM_ENDPRESS_PSI, 100, data_type);
            else
                GUI_EndP_AL_BAR = (uint8_t)SettingData(GUI_EndP_AL_BAR, 105, ALARM_ENDPRESS_BAR, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            EndP_AL_PSI = GUI_EndP_AL_PSI;              // update data
            EndP_AL_BAR = GUI_EndP_AL_BAR;              // update data
            GUI_EndP_AL_STAT = NVD_ON;           // force to turn ON
            EndP_AL_STAT = GUI_EndP_AL_STAT;            // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S285_ALARM_ENDPRESS;	        // move to N2 Set Point STAT
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  Turn/End Pressure
    case S353_ALARM_SWITCHPRESS:

        NewOpcode = Opcode_Matrix( S281_AL_TURN_END_PRESS,  S285_ALARM_ENDPRESS,  S282_ALARM_TURNPRESS,	OldOpcode,  S354_ALARM_SWITCHPRESS_STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case S354_ALARM_SWITCHPRESS_STAT:

        NewOpcode = Opcode_Matrix( S282_ALARM_TURNPRESS,  DataDec,  DataInc,	OldOpcode,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_SwitchP_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_SwitchP_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_SwitchP_AL_STAT == NVD_SET)
            {
                NewOpcode = S355_ALARM_SWITCHPRESS_SET;          // go to settings
            }
            else
            {
                SwitchP_AL_STAT = GUI_SwitchP_AL_STAT;                  // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S353_ALARM_SWITCHPRESS;              // back to Menu
            }
            break;
        }
        break;

    case S355_ALARM_SWITCHPRESS_SET:

        NewOpcode = Opcode_Matrix( S283_ALARM_TURNPRESS_STAT,  DataDec,  DataInc,	ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_SwitchP_AL_PSI = (uint16_t)SettingData(GUI_SwitchP_AL_PSI, 1500, 100, 100, data_type);
            else
                GUI_SwitchP_AL_BAR = (uint8_t)SettingData(GUI_SwitchP_AL_BAR, 100, 10, 10, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            SwitchP_AL_PSI = GUI_SwitchP_AL_PSI;              // update data
            SwitchP_AL_BAR = GUI_SwitchP_AL_BAR;              // update data
            GUI_SwitchP_AL_STAT = NVD_ON;           // force to turn ON
            SwitchP_AL_STAT = GUI_SwitchP_AL_STAT;            // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S353_ALARM_SWITCHPRESS;	        // move to N2 Set Point STAT
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set ALARM ->  END/WOB/ICD ALARMS
    case S289_ALARM_END:

        NewOpcode = Opcode_Matrix( S288_AL_END_WOB_ICD_ALARMS,  S297_ALARM_O2_NARCOTIC,  S292_ALARM_WOB,	OldOpcode,  S290_ALARM_END_STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S290_ALARM_END_STAT:

        NewOpcode = Opcode_Matrix( S289_ALARM_END,  DataDec,  DataInc,	OldOpcode,  SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_END_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_END_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_END_AL_STAT == NVD_SET)
            {
                NewOpcode = S291_ALARM_END_SET;         // go to settings
            }
            else
            {
                END_AL_STAT = GUI_END_AL_STAT;          // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S289_ALARM_END;             // back to Menu
            }
            break;
        }
        break;
    case S291_ALARM_END_SET:

        NewOpcode = Opcode_Matrix( S290_ALARM_END_STAT,  DataDec,  DataInc,	ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_END_AL_FT = (uint16_t)SettingData(GUI_END_AL_FT, 200, 100, 10, data_type);
            else
                GUI_END_AL_M = (uint16_t)SettingData(GUI_END_AL_M, 60, 30, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            END_AL_FT = GUI_END_AL_FT;                  // update data
            END_AL_dM = (uint16_t)(10.0*GUI_END_AL_M);   // update data
            GUI_END_AL_STAT = NVD_ON;                   // force to turn ON
            END_AL_STAT = GUI_END_AL_STAT;              // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S289_ALARM_END;	                // move to Set Point STAT
            break;
        }
        break;

    case S292_ALARM_WOB:

        NewOpcode = Opcode_Matrix( S288_AL_END_WOB_ICD_ALARMS,  S289_ALARM_END,  S295_ALARM_ICD,	OldOpcode,  S293_ALARM_WOB_STAT,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;
    case S293_ALARM_WOB_STAT:

        NewOpcode = Opcode_Matrix( S292_ALARM_WOB,  DataDec,  DataInc,	OldOpcode,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_WOB_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_WOB_AL_STAT, NVD_SET, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_WOB_AL_STAT == NVD_SET)
            {
                NewOpcode = S294_ALARM_WOB_SET; // go to settings
            }
            else
            {
                WOB_AL_STAT = GUI_WOB_AL_STAT;      // update EE image
                EE_SaveReq(EE_SCUBASET);                // save to EE
                NewOpcode = S292_ALARM_WOB;             // back to Menu
            }
            break;
        }
        break;
    case S294_ALARM_WOB_SET:

        NewOpcode = Opcode_Matrix( S293_ALARM_WOB_STAT,  DataDec,  DataInc,	ScrollInc,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
        case DataDec:
            if(UNITS==NVD_IMPERIAL)
                GUI_WOB_AL_FT = (uint16_t)SettingData(GUI_WOB_AL_FT, 200, 100, 10, data_type);
            else
                GUI_WOB_AL_M = (uint16_t)SettingData(GUI_WOB_AL_M, 60, 30, 5, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            WOB_AL_FT = GUI_WOB_AL_FT;                  // update data
            WOB_AL_dM = (uint16_t)(10.0*GUI_WOB_AL_M);                // update data
            GUI_WOB_AL_STAT = NVD_ON;                   // force to turn ON
            WOB_AL_STAT = GUI_WOB_AL_STAT;              // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S292_ALARM_WOB;	                // move to Set Point STAT
            break;
        }
        break;


    case S295_ALARM_ICD:

        NewOpcode = Opcode_Matrix( S288_AL_END_WOB_ICD_ALARMS,  S292_ALARM_WOB,  S297_ALARM_O2_NARCOTIC,	OldOpcode,  S296_ALARM_ICD_SET,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;

    case S297_ALARM_O2_NARCOTIC:

        NewOpcode = Opcode_Matrix( S288_AL_END_WOB_ICD_ALARMS,	S295_ALARM_ICD,  S289_ALARM_END,	OldOpcode,	S297_ALARM_O2_NARCOTIC_SET, ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        break;


    case S296_ALARM_ICD_SET:

        NewOpcode = Opcode_Matrix( S295_ALARM_ICD,  DataDec,  DataInc,	OldOpcode,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_ICD_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_ICD_AL_STAT, NVD_ON, NVD_OFF, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            ICD_AL_STAT = GUI_ICD_AL_STAT;              // update EE image
            EE_SaveReq(EE_SCUBASET);                    // save to EE
            NewOpcode = S295_ALARM_ICD;                 // back to Menu
            break;
        }
        break;

    case S297_ALARM_O2_NARCOTIC_SET:

        NewOpcode = Opcode_Matrix( S297_ALARM_O2_NARCOTIC,	DataDec,  DataInc,	OldOpcode,	SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_O2_NARCOTIC_AL_STAT = (NVD_status_t)SettingData((uint8_t)GUI_O2_NARCOTIC_AL_STAT, 1, 0, 1, data_type);  //0 = NO, 1 = YES
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            NARCOTIC_AL_SW = GUI_O2_NARCOTIC_AL_STAT;		        // update EE image
            EE_SaveReq(EE_SCUBASET);							// save to EE
            NewOpcode = S297_ALARM_O2_NARCOTIC; 						// back to Menu
            break;
        }
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set SLATES
    case SLATES_MAINPAGE:
        HandleButton_MainMenu_SlateMainPage(&NewOpcode, &OldOpcode);
        break;

    case SLATES_CONFIRM_DELETE: // S229 Are You Sure to Delete Slates
        HandleButton_MainMenu_SlateDelete(&NewOpcode, &OldOpcode);
        break;
    case SLATES_NO_SLATE:
        NewOpcode = Opcode_Matrix(BackupOpcode, OldOpcode, OldOpcode, OldOpcode, OldOpcode, OpcodeForR2s, OldOpcode, OldOpcode, OldOpcode);
        break;
    case SLATES_DELETED: // S230 Slate X Deleted
        HandleButton_MainMenu_DeletedSlate(&NewOpcode, &OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Set Compass

    /*
        C1_COMPASS_MAIN                         = 0x1110,
        C7_COMPASS_CALIBRATION                  = 0x1111,
        C13_COMPASS_DECLIN_SET                  = 0x1112,
        C14_COMPASS_DECLIN_SETTING              = 0x1113,
        C2_COMPASS_MAIN_DIVE                    = 0x1114,
        C3_COMPASS_MAIN_HEADING                 = 0x1115,
        C4_COMPASS_MAIN_HEADING_SET             = 0x1116,
        C5_COMPASS_MAIN_HEADING_REV             = 0x1117,
        C6_COMPASS_MAIN_HEADING_REV_SET         = 0x1118,
    */


    case C1_COMPASS_MAIN:       // C2_COMPASS_MAIN_DIVE if Dive Mode

        if(GnssStatus!=GNSS_ON)
        {
            NewOpcode = Opcode_Matrix( CheckConditions,  ButtonL1,  C7_COMPASS_CALIBRATION,	OldOpcode,  ButtonR1, ButtonR2, OldOpcode, OldOpcode,	 OldOpcode);

            Ec_On();

            switch(NewOpcode)
            {
            case CheckConditions:       // L 2S Button to Reset Chrono
                Chrono.ResetReq = true;
                NewOpcode = OldOpcode;
                break;

            case ButtonL1:              // L < 2S Button to Start/Stop Chrono
                if(Chrono.Status == TIMER_Run)
                    Chrono.PauseReq = true;
                else
                    Chrono.RunReq = true;

                NewOpcode = OldOpcode;
                break;

            case C7_COMPASS_CALIBRATION:
                if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
                    NewOpcode = OldOpcode;          // Don't go to COMPASS MENU during Dive Mode
                break;

            case ButtonR1:
                GUI_CompassHeadingStat++;
                if(GUI_CompassHeadingStat==1)
                {
                    GUI_CompassReferenceHeadingOn = true;
                    GUI_CompassReverseHeadingOn = false;
                    GUI_CompassReferenceHeadingDegree = CoDis_VerifyTheCompassValue();
                }
                else if(GUI_CompassHeadingStat==2)
                {
                    GUI_CompassReferenceHeadingOn = false;
                    GUI_CompassReverseHeadingOn = true;
                    GUI_CompassReverseHeadingDegree = ((GUI_CompassReferenceHeadingDegree+180)%360);
                }
                else
                {
                    GUI_CompassReferenceHeadingOn = false;
                    GUI_CompassReverseHeadingOn = false;
                    GUI_CompassHeadingStat=0;
                }
                NewOpcode = OldOpcode;
                break;

            case ButtonR2:

                Ec_Off();

                ReceiverInit(1);    // re-initialize Receiver, when getting out of Compass

                if((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
                {
                    if(CC_MODE)                // BO same to CC at Surface Mode
                        NewOpcode = DIVE_CC_MAIN;
                    else if(OC_MODE||BO_MODE)
                        NewOpcode = DIVE_OC_MAIN;
                    else if(SM_MODE)
                        NewOpcode = DIVE_SM_MAIN;
                    else if(GSM_MODE)
                        NewOpcode = DIVE_GSM_MAIN;
                    else if(GAUGE_MODE)
                        NewOpcode = DIVE_GAUGE_MAIN;
                }
                break;
            }
        }
        else
        {
            SystemStatus.user_act_timestamp = MonotonicClock_s;         // keep System Awake, NOT going to sleep as long as GPS Compass Main Page is ON

            NewOpcode = Opcode_Matrix( OldOpcode,       OldOpcode,      S519_GPS_WAYFINDER_EXIT,	OldOpcode,        OldOpcode,          ReturnToMainPage(),       OldOpcode,      OldOpcode,      OldOpcode);

            Ec_On();

            if(NewOpcode == OldOpcode)
            {
                if(UNITS==NVD_IMPERIAL)
                {
                    if(0.62*GnssGGA.Target_Distance < 0.02)
                        NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
                }
                else
                {
                    if(GnssGGA.Target_Distance < 0.02)
                        NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
                }

            }
        }
        break;

    case C7_COMPASS_CALIBRATION:
        GUI_COMP_DEDLIN_DEG = COMP_DEDLIN_DEG;
        NewOpcode = Opcode_Matrix( C1_COMPASS_MAIN,  C13_COMPASS_DECLIN_SET,  C13_COMPASS_DECLIN_SET,	OldOpcode,  C9_COMPASS_PROCESSING, C1_COMPASS_MAIN, OldOpcode, OldOpcode,	 OldOpcode);
        // if current CalQuality is not so good, then use the old parameters saved on EEPROM DEV_Rec
        if(MMC_Output.CalQuality < MMC_CALQSTATUSOK)
            memcpy(&MMC_Output, &DEV_Rec.CompassCali, sizeof(MMC_Output_t));
        break;

    case C9_COMPASS_PROCESSING:
        NewOpcode = Opcode_Matrix( C1_COMPASS_MAIN,  C13_COMPASS_DECLIN_SET,  C13_COMPASS_DECLIN_SET,	OldOpcode,  C9_COMPASS_PROCESSING, C1_COMPASS_MAIN, OldOpcode, OldOpcode,	 OldOpcode);
        // ROTATE AND TURN OVER IN MULTIPLE DIRECTIONS UNTIL BEEP
        if(OpcodeChanged(pre_DSX_Opcode, NewOpcode))
        {
            memcpy(&MMC_Output_Original, &MMC_Output, sizeof(MMC_Output_t));
            Ec_On();
            Ec_Calibrate();   // starts Compass Calibration, no matter if previously calibrated
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + MAG_CAL_DURATION_SEC + 5;           // Calibration MAG_CAL_DURATION_SEC seconds
            CounterCaliCompass = 0;
        }
        else
        {
            int32_t a, b;

            a = MonotonicClock_s;
            b = SystemStatus.GUI_Pause_timestamp;

            if((a > (b + 5))||((MMC_Output.CalQuality == MMC_CALQSTATUSGOOD)&&(EcData.CalGood == true)))
            {
                if(MMC_Output.CalQuality >= MMC_CALQSTATUSGOOD)
                {
                    NewOpcode = C10_COMPASS_CALIBRATION_PASSED;       // if Passed, show pass page for 3 seconds
                    memcpy(&DEV_Rec.CompassCali, &MMC_Output, sizeof(MMC_Output_t));    // Keep new data collected during calibration
                    EE_SaveReq(EE_DEVREC);                // save to EE
                }
                else
                {
                    NewOpcode = C11_COMPASS_CALIBRATION_FAILED;       // if Failed, show fialed page for 3 seconds
                    memcpy(&MMC_Output, &MMC_Output_Original, sizeof(MMC_Output_t));    // return whatever data was before calibration
                }
                SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 1;    // stay at the same GUI for extra 2 seconds

                SystemStatus.buzzer_on_req = true;
            }
        }
        break;

    case C10_COMPASS_CALIBRATION_PASSED:
    case C11_COMPASS_CALIBRATION_FAILED:
        NewOpcode = Opcode_Matrix( OldOpcode,  OldOpcode,  OldOpcode,	OldOpcode,  OldOpcode, OldOpcode, OldOpcode, OldOpcode,	 OldOpcode);

        if(MMC_Output.CalQuality < MMC_CALQSTATUSGOOD)
            SystemStatus.buzzer_on_req = true;

        int32_t a, b;

        a = MonotonicClock_s;
        b = SystemStatus.GUI_Pause_timestamp;

        if(a > b)
        {
            if(MMC_Output.CalQuality == MMC_CALQSTATUSGOOD)
            {
                NewOpcode = C1_COMPASS_MAIN;              // if Passed, show pass page for 3 seconds, and then back to display Compass
                EcData.Status = COMPASS_OFF;
                Ec_On();
            }
            else
            {
                NewOpcode = C7_COMPASS_CALIBRATION;       // if Failed, show fialed page for 3 seconds, and then back to Compass Menu
                EcData.Status = COMPASS_OFF;
            }
        }
        break;

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    case C13_COMPASS_DECLIN_SET:
        NewOpcode = Opcode_Matrix( C1_COMPASS_MAIN,  C7_COMPASS_CALIBRATION,  C7_COMPASS_CALIBRATION,	OldOpcode,  C14_COMPASS_DECLIN_SETTING,	C1_COMPASS_MAIN, OldOpcode, OldOpcode,	 OldOpcode);
        GUI_COMP_DEDLIN_DEG = COMP_DEDLIN_DEG;
        break;

    case C14_COMPASS_DECLIN_SETTING:
        NewOpcode = Opcode_Matrix( OldOpcode,  DataDec,  DataInc,	ScrollInc,  SaveAndDone,	C1_COMPASS_MAIN, OldOpcode, OldOpcode,	 OldOpcode);
        data_type = Update_datatype(NewOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
        case ScrollInc:
            GUI_COMP_DEDLIN_DEG = (int8_t)SettingData(GUI_COMP_DEDLIN_DEG, 45, -45, 1, data_type);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            COMP_DEDLIN_DEG = GUI_COMP_DEDLIN_DEG;				// update EE image
            EE_SaveReq(EE_USERSET);						// save to EE
            NewOpcode = C13_COMPASS_DECLIN_SET; 					// back to Menu
            break;
        }



        break;

    case C2_COMPASS_MAIN_DIVE:
        NewOpcode = Opcode_Matrix( ButtonL2,  ButtonL1,  OldOpcode,	OldOpcode,  ButtonR1,	ButtonR2, OldOpcode, OldOpcode,	 OldOpcode);
        Ec_On();
        switch (NewOpcode)
        {
        case ButtonL2:       // L 2S Button to Reset Chrono
            Chrono.ResetReq = true;
            NewOpcode = OldOpcode;
            break;

        case ButtonL1:       // L < 2S Button to Start/Stop Chrono
            if(Chrono.Status == TIMER_Run)
                Chrono.PauseReq = true;
            else
                Chrono.RunReq = true;

            NewOpcode = OldOpcode;
            break;

        case ButtonR1:
            GUI_CompassHeadingStat++;
            if(GUI_CompassHeadingStat==1)
            {
                GUI_CompassReferenceHeadingOn = true;
                GUI_CompassReverseHeadingOn = false;
                GUI_CompassReferenceHeadingDegree = CoDis_VerifyTheCompassValue();
            }
            else if(GUI_CompassHeadingStat==2)
            {
                GUI_CompassReferenceHeadingOn = false;
                GUI_CompassReverseHeadingOn = true;
                GUI_CompassReverseHeadingDegree = ((GUI_CompassReferenceHeadingDegree+180)%360);
            }
            else
            {
                GUI_CompassReferenceHeadingOn = false;
                GUI_CompassReverseHeadingOn = false;
                GUI_CompassHeadingStat=0;
            }
            NewOpcode = OldOpcode;
            break;

        case ButtonR2:

            Ec_Off();

            ReceiverInit(1);    // re-initialize Receiver, when getting out of Compass

            if((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
            {
                if(CC_MODE)
                    NewOpcode = DIVE_CC_MAIN;
                else if(OC_MODE||BO_MODE)
                    NewOpcode = DIVE_OC_MAIN;
                else if(SM_MODE)
                    NewOpcode = DIVE_SM_MAIN;
                else if(GSM_MODE)
                    NewOpcode = DIVE_GSM_MAIN;
                else if(GAUGE_MODE)
                    NewOpcode = DIVE_GAUGE_MAIN;
            }
            else
            {
                NewOpcode = S2_SURFACE_MAIN; // return to Surface Main menu
            }
            break;
        }
        break;

//    case C3_COMPASS_MAIN_HEADING:
//        NewOpcode = Opcode_Matrix( OldOpcode,  OldOpcode,  OldOpcode,	OldOpcode,  C5_COMPASS_MAIN_HEADING_REV,	OldOpcode, OldOpcode, OldOpcode,	 OldOpcode);
//        break;

//    case C4_COMPASS_MAIN_HEADING_SET:
//        NewOpcode = Opcode_Matrix( OldOpcode,  OldOpcode,  OldOpcode,	OldOpcode,  C6_COMPASS_MAIN_HEADING_REV_SET,	OldOpcode, OldOpcode, OldOpcode,	 OldOpcode);
//        GUI_CompassReferenceHeadingOn = true;
//        GUI_CompassReverseHeadingOn = false;
//        GUI_CompassReferenceHeadingDegree = EcData.RefHeadingSet;
//        break;

//    case C5_COMPASS_MAIN_HEADING_REV:
//        NewOpcode = Opcode_Matrix( OldOpcode,  OldOpcode,  OldOpcode,	OldOpcode,  C1_COMPASS_MAIN,	OldOpcode, OldOpcode, OldOpcode,	 OldOpcode);
//        break;

//    case C6_COMPASS_MAIN_HEADING_REV_SET:
//        NewOpcode = Opcode_Matrix( OldOpcode,  OldOpcode,  OldOpcode,	OldOpcode,  OldOpcode,  OldOpcode, OldOpcode, OldOpcode,	 OldOpcode);
//        GUI_CompassReferenceHeadingOn = false;
//        GUI_CompassReverseHeadingOn = true;
//        GUI_CompassReverseHeadingDegree = EcData.RevHeadingSet;
//
//        if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
//            NewOpcode = C2_COMPASS_MAIN_DIVE;
//        else
//            NewOpcode = C1_COMPASS_MAIN;
//        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // GPS MENU & WAYFINDER MODE


    case S502_GPS_GET_CURRENT_LOCATION:
        GPS_signal_stat = 0;

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),	S520_GPS_DELETE_LOCATION,	S509_GPS_WAYFINDER, 			OldOpcode,	S504_GPS_INIT, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        if(0) { /*if there is 20 saved locatons*/
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), S520_GPS_DELETE_LOCATION,	S509_GPS_WAYFINDER, 			OldOpcode,	S503_GPS_20DATA_DELETE_TO_SAVE, OldOpcode, OldOpcode, OldOpcode,  OldOpcode);
        }

        /*wait the  flat INIT finish, and go to next screen*/

        if(GnssStatus >= GNSS_SLEEP)
            Gnss_WakeUp();  // was Gnss_Off(); before 2022 04 19
        else
            Gnss_On();

        if(NewOpcode == S2_SURFACE_MAIN)
        {
            Gnss_Sleep();
        }
        break;

    case S503_GPS_20DATA_DELETE_TO_SAVE:
        NewOpcode = Opcode_Matrix( S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION, 	S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION, S502_GPS_GET_CURRENT_LOCATION, OldOpcode, OldOpcode,  OldOpcode);
        Gnss_Sleep();
        break;

    case S504_GPS_INIT:
        NewOpcode = Opcode_Matrix( S502_GPS_GET_CURRENT_LOCATION,	OldOpcode, 	OldOpcode, 	OldOpcode,	OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        /*wait the  flat INIT finish, and go to next screen*/

        if(GnssStatus == GNSS_ON)
        {
            NewOpcode = S505_GPS_WAIT_SIGNAL;
            Gnss_WakeUp();
        }
        else
        {
            if(GnssStatus >= GNSS_SLEEP)
                Gnss_WakeUp();  // was Gnss_Off(); before 2022 04 19
            else
                Gnss_On();
        }
        break;

    case S505_GPS_WAIT_SIGNAL:
        /*wait the GPS signal in 100 seconds or (SURF_MENU_TIMEOUT_S-20) seconds*/

        Ec_Off();       // starts with a Compass reset

        NewOpcode = Opcode_Matrix( S502_GPS_GET_CURRENT_LOCATION,	OldOpcode, 	OldOpcode, 	OldOpcode,	OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        if(StaySameOpcodeForNSec(100))
        {
            if((GnssStatus == GNSS_ON)&&(GnssGGA.NoOfSatellites_used >= MINIMUM_SATELLITE))
            {
                if(GPS_signal_stat==0)
                    NewOpcode = S507_GPS_SAVE_LOCATION_STAT;
                else
                {
                    GnssGGA.Target_Distance = Gnss_Calc_Distance (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);
                    GnssGGA.Target_Direction = Gnss_WayFinderBrearing (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);

                    NewOpcode = S516_GPS_WAYFINDER_MAIN;
                    Ec_On();                            // turn ON compass, when Wayfinder starts to display
                }

                StaySameOpcodeForNSec(0);       // NOT COMING BACK to this Opcode
            }
        }
        else
        {
            NewOpcode = S506_GPS_NO_SIGNAL;
            StaySameOpcodeForNSec(0);       // NOT COMING BACK to this Opcode
        }
        break;

    case S506_GPS_NO_SIGNAL:
        //S506 - GPS Signal Not Found
        NewOpcode = Opcode_Matrix( S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION, 	S502_GPS_GET_CURRENT_LOCATION,	S502_GPS_GET_CURRENT_LOCATION, S502_GPS_GET_CURRENT_LOCATION, OldOpcode, OldOpcode,  OldOpcode);

        if(NewOpcode == S502_GPS_GET_CURRENT_LOCATION)
        {
            Gnss_WakeUp();
        }
        break;

    case S507_GPS_SAVE_LOCATION_STAT:
        //S507 - Signal Found - Save Location Confirmation
        NewOpcode = Opcode_Matrix( S502_GPS_GET_CURRENT_LOCATION,  OldOpcode,	OldOpcode, 	OldOpcode,	S508_GPS_LOCATION_SAVED, OldOpcode, OldOpcode, OldOpcode,  OldOpcode);

        if(NewOpcode == S508_GPS_LOCATION_SAVED)
        {
            // to save GnssGGA.Latitude_DD; into ExFLASH
            // to save GnssGGA.Longitude_DD; into ExFLASH
            GPS_SaveCurrentLocation();
        }
        else if(NewOpcode == S502_GPS_GET_CURRENT_LOCATION)
        {
            /*no need to save new data*/
            // Gnss_Sleep();
        }
        break;

    case S508_GPS_LOCATION_SAVED:
        //S508 - Location Saved
        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 	OldOpcode,	S502_GPS_GET_CURRENT_LOCATION, OldOpcode, OldOpcode, OldOpcode,  OldOpcode);
        break;


    case S509_GPS_WAYFINDER:
        GPS_signal_stat = 1;
        GPS_Loc_Num = 0;

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),	S502_GPS_GET_CURRENT_LOCATION,	S520_GPS_DELETE_LOCATION, 	OldOpcode,	S510_GPS_WAYFINDER_LIST, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        if(NewOpcode == S510_GPS_WAYFINDER_LIST)
            Wayfinder_ReadAllLocations(0);
        break;

    case S510_GPS_WAYFINDER_LIST:
        HandleButton_GPSMenu_Wayfinder(&NewOpcode, &OldOpcode);
        break;

    case S511_GPS_WAYFINDER_GOTO:
        //S511 - Go to Location Conirrmation

        NewOpcode = Opcode_Matrix( S510_GPS_WAYFINDER_LIST,	OldOpcode,	OldOpcode, 	OldOpcode,	S504_GPS_INIT, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;

    case S516_GPS_WAYFINDER_MAIN:

        if(UNITS==NVD_IMPERIAL)
        {
            if(0.62*GnssGGA.Target_Distance < 0.02)
                NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
            else
                NewOpcode = C1_COMPASS_MAIN;
        }
        else
        {
            if(GnssGGA.Target_Distance < 0.02)
                NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
            else
                NewOpcode = C1_COMPASS_MAIN;
        }
        break;

    case S519_GPS_WAYFINDER_EXIT:

        NewOpcode = Opcode_Matrix( S516_GPS_WAYFINDER_MAIN,	S519a_GPS_WAYFINDER_CHANGE_LOCATION, S519a_GPS_WAYFINDER_CHANGE_LOCATION, OldOpcode,    S509_GPS_WAYFINDER,      ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;

    case S519a_GPS_WAYFINDER_CHANGE_LOCATION:

        NewOpcode = Opcode_Matrix( S516_GPS_WAYFINDER_MAIN,	S519_GPS_WAYFINDER_EXIT,	S519_GPS_WAYFINDER_EXIT, 	OldOpcode,	S510_GPS_WAYFINDER_LIST, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        if(NewOpcode ==S510_GPS_WAYFINDER_LIST)
        {
            Wayfinder_ReadAllLocations(0);
        }

        break;

    case S518_GPS_WAYFINDERLOCATION_REACHED:
        //S518 - Location Reached
        // it is handled by IC driver...
        SystemStatus.user_act_timestamp = MonotonicClock_s;         // keep System Awake, NOT going to sleep as long as GPS Compass Main Page is ON

        Gnss_On();
        GnssGGA.Target_Distance = Gnss_Calc_Distance (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);
        GnssGGA.Target_Direction = Gnss_WayFinderBrearing (GnssGGA.Longitude_DD, GnssGGA.Latitude_DD, GnssGGA.Longitude_Target_DD, GnssGGA.Latitude_Target_DD);

        NewOpcode = Opcode_Matrix( S509_GPS_WAYFINDER,	S509_GPS_WAYFINDER,	S509_GPS_WAYFINDER, S509_GPS_WAYFINDER,	S509_GPS_WAYFINDER, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        if(NewOpcode == OldOpcode)      // if no OpCode change, check distance to target and display S518 or C1
        {
            if(UNITS==NVD_IMPERIAL)
            {
                if(0.62*GnssGGA.Target_Distance < 0.02)
                    NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
                else
                    NewOpcode = C1_COMPASS_MAIN;
            }
            else
            {
                if(GnssGGA.Target_Distance < 0.02)
                    NewOpcode = S518_GPS_WAYFINDERLOCATION_REACHED;
                else
                    NewOpcode = C1_COMPASS_MAIN;
            }
        }
        break;

    case S520_GPS_DELETE_LOCATION:
        GPS_signal_stat = 3;

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),	S509_GPS_WAYFINDER,	S502_GPS_GET_CURRENT_LOCATION, 		OldOpcode,	S521_GPS_WAYFINDER_LIST, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        if(NewOpcode == S521_GPS_WAYFINDER_LIST)
        {
            Wayfinder_ReadAllLocations(0);
        }

        break;

    case S521_GPS_WAYFINDER_LIST:
        HandleButton_GPSMenu_DeleteLocation(&NewOpcode, &OldOpcode);
        /*need up/down list here*/
        break;

    case S522_GPS_DELETE_LOCATION:

        NewOpcode = Opcode_Matrix( S520_GPS_DELETE_LOCATION, S521_GPS_WAYFINDER_LIST,	OldOpcode, 	OldOpcode,	S523_GPS_LOCATION_DELETED, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        if(NewOpcode == S523_GPS_LOCATION_DELETED)
        {
            GPS_DeleteLocation();
        }


        break;

    case S523_GPS_LOCATION_DELETED:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 		OldOpcode,	S520_GPS_DELETE_LOCATION, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // O2 ANALYZER LOGIC

    case S462_O2ANALYZER_CALIBRATE:

        NewOpcode = Opcode_Matrix( BackupOpcode, S470_O2ANALYZER_ANALYZE,	S470_O2ANALYZER_ANALYZE,   ScrollInc,	S463_O2ANALYZER_CALIBRATE_SET_GAS, ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        GUI_O2ANALYZER_FO2_SET = 21;    // always starts from 21%

        switch (NewOpcode)
        {
        case ScrollInc:
            O2_Primary_V_ZeroOffset = SettingData(O2_Primary_V_ZeroOffset, 2.300, 1.700, 0.0002, data_increase);
            O2_ADC_V_ZeroOffset = O2_Primary_V_ZeroOffset;
            NewOpcode = OldOpcode;
            break;
        case ScrollDec:
            O2_Primary_V_ZeroOffset = SettingData(O2_Primary_V_ZeroOffset, 2.100, 1.700, 0.0002, data_decrease);
            O2_ADC_V_ZeroOffset = O2_Primary_V_ZeroOffset;
            NewOpcode = OldOpcode;
            break;
        }
        break;
    case S463_O2ANALYZER_CALIBRATE_SET_GAS:

        NewOpcode = Opcode_Matrix( S462_O2ANALYZER_CALIBRATE,  DataDec,	DataInc,  ScrollInc,  SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_O2ANALYZER_FO2_SET = (uint8_t)SettingData((float)GUI_O2ANALYZER_FO2_SET, 100.0, 17.0, 1.0, data_increase);

            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_O2ANALYZER_FO2_SET = (uint8_t)SettingData((float)GUI_O2ANALYZER_FO2_SET, 100.0, 17.0, 1.0, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            if(GUI_O2ANALYZER_FO2_SET == 21)
                O2_SetForCalib_Pct = 20.9;
            else
                O2_SetForCalib_Pct = (float)1.00*GUI_O2ANALYZER_FO2_SET;

            GUI_O2ANALYZER_CALIB_FLAT = FALSE;        // to void previous O2 Analzyer Calibration, to prohibit O2 Analyzing until a new good calibration is done
            NewOpcode = S464_O2ANALYZER_CALIBRATE_READY;
            break;
        case S462_O2ANALYZER_CALIBRATE:
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_OFF;
            SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_MAX;
            break;
        }
        break;

    case S464_O2ANALYZER_CALIBRATE_READY:

        NewOpcode = Opcode_Matrix( S463_O2ANALYZER_CALIBRATE_SET_GAS, OldOpcode,	OldOpcode, 		OldOpcode,	S465_O2ANALYZER_CALIBRATE_READ_O2, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        O2_ADC_V_Calib = O2_Analyzer_Volt;      // initialize O2_ADC_V_Calib from here

        break;
    case S465_O2ANALYZER_CALIBRATE_READ_O2:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode,		OldOpcode,	OldOpcode, ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);

        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_CELL_CALIBRATION;

        if(!StaySameOpcodeForNSec(30))
        {
            O2_ADC_V_Calib = O2_Analyzer_Volt;      // initialize O2_ADC_V_Calib from here

            /*need read real Cell here*/
            if(O2_ADC_V_Calib < 0.050) {              //No O2 Analyzer Found
                NewOpcode = S466_O2ANALYZER_CALIBRATE_NO_CELL_O2;       //S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER;
            }
            else if(O2_ADC_V_Calib > ((0.001*MFG_Calib.O2_Analyzer.O2_ADC_Offset) - 0.050)) {    // from R1006, "No O2 Analyzer" failure is checked against "The Theoretical Zero Point - 50 mV margin" = (O2_ADC_Offset mV - 50 mV)
            //else if(O2_ADC_V_Calib > 1.95) {          //No O2 Cell Found
                NewOpcode = S466_O2ANALYZER_CALIBRATE_NO_CELL_O2;
            }
            else if(CellNewToDepletedFactor < 0.8) {    //O2 Cell Depleted (cell missing from chamber), or O2 Analyzer is NOT Connected (O2_Analyzer_Volt = 0.04 Volt with 2.7M resistor added acrose D3 diode)
                NewOpcode = S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP;
            }
            else {                                      // O2 Analyzer connected to the AIR or Referenced Gas correctly
                NewOpcode = S468_O2ANALYZER_CALIBRATE_CELL_V;
            }
        }
        break;

    case S468_O2ANALYZER_CALIBRATE_CELL_V:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 		OldOpcode,	S469_O2ANALYZER_CALIBRATE_COMPLETE, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        break;
    case S469_O2ANALYZER_CALIBRATE_COMPLETE:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 		OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        GUI_O2ANALYZER_CALIB_FLAT =TRUE;

        if(NewOpcode == SaveAndDone)
        {
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_OFF;
            SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_MAX;
            DEV_Rec.O2_Analyzer_V2Pct_Slope = CellNewToDepletedFactor;
            EE_SaveReq(EE_DEVREC);            // save to EE
            NewOpcode = S462_O2ANALYZER_CALIBRATE;
        }
        break;

    case S466_O2ANALYZER_CALIBRATE_NO_CELL_O2:
    case S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP:
    case S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER:
        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 		OldOpcode,	S462_O2ANALYZER_CALIBRATE, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_OFF;
        SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_MAX;
        break;


    case S470_O2ANALYZER_ANALYZE:

        if(GUI_O2ANALYZER_CALIB_FLAT ==TRUE) {
            NewOpcode = Opcode_Matrix( BackupOpcode, S462_O2ANALYZER_CALIBRATE,	S462_O2ANALYZER_CALIBRATE,		OldOpcode,	S472_ANALYZE_READY, ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);
        }
        else { //Please Calibrate O2 Cell Befor Analyzing
            NewOpcode = Opcode_Matrix( BackupOpcode, S462_O2ANALYZER_CALIBRATE,	S462_O2ANALYZER_CALIBRATE,		OldOpcode,	S471_ANALYZE_CALIB_WARINING, ReturnToMainPage(), OldOpcode, OldOpcode,	OldOpcode);
        }
        break;


    case S471_ANALYZE_CALIB_WARINING:

        NewOpcode = Opcode_Matrix( S470_O2ANALYZER_ANALYZE, OldOpcode,	OldOpcode, 		OldOpcode,	S470_O2ANALYZER_ANALYZE, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;

    case S472_ANALYZE_READY:

        NewOpcode = Opcode_Matrix( S470_O2ANALYZER_ANALYZE, OldOpcode,	OldOpcode, 		OldOpcode,	S473_ANALYZE_ANALYZING, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        O2_ADC_V_Analyze1 = O2_Analyzer_Volt;     // Initialize the O2_ADC_V_Analyze value

        break;
    case S473_ANALYZE_ANALYZING:

        NewOpcode = Opcode_Matrix( S470_O2ANALYZER_ANALYZE, OldOpcode,	OldOpcode, 		OldOpcode,	OldOpcode, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_CELL_ANALYZE;

        if(!StaySameOpcodeForNSec(30))
        {
            /*need read real Cell here*/
            NewOpcode = S474_ANALYZE_CONFIRM;
        }
        break;
    case S474_ANALYZE_CONFIRM:

        NewOpcode = Opcode_Matrix( OldOpcode,  DataDec,	DataInc, 		OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);


        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_O2ANALYZER_FO2_CONFIRM_FLAT = (uint8_t)SettingData((uint8_t)GUI_O2ANALYZER_FO2_CONFIRM_FLAT, 1, 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_O2ANALYZER_FO2_CONFIRM_FLAT == 1) //YES
            {
                NewOpcode = S475_ANALYZE_ASSIGN_FO2_CONFIRM;
            }
            else//NO
            {

                NewOpcode = S470_O2ANALYZER_ANALYZE; 			 // back to Menu
            }
            break;
        }


        break;
    case S475_ANALYZE_ASSIGN_FO2_CONFIRM:

        NewOpcode = Opcode_Matrix( S474_ANALYZE_CONFIRM,  DataDec,	DataInc,		OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);

        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_O2ANALYZER_FO2_ASSIGN_FLAT = (uint8_t)SettingData((uint8_t)GUI_O2ANALYZER_FO2_ASSIGN_FLAT, 1, 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_O2ANALYZER_FO2_ASSIGN_FLAT == 1) //YES
            {
                GUI_O2_AnalyzerFO2Set = Compensated_Uint8_O2_Pct;
                GUI_O2ANALYZER_DIVEMODE_ASSIGN = NVD_MDCC;              // reset as CC to start the Gas Selection in nex step
                GAS_ASSIGN_INDEX = 1;                                   // reset back to 1 to start the Gas Tank selection
                GUI_O2_AnalyzerFHeSet = 0;                              // reset back to 1 to start the Gas Tank selection
                NewOpcode = S475A_ANALYZE_SET_FHE;
            }
            else//NO
            {

                NewOpcode = S470_O2ANALYZER_ANALYZE; 			 // back to Menu
            }
            break;
        }

        break;

    case S475A_ANALYZE_SET_FHE:

        NewOpcode = Opcode_Matrix(S475_ANALYZE_ASSIGN_FO2_CONFIRM,  DataDec,  DataInc,  ScrollInc,   SaveAndDone,	ReturnToMainPage(), OldOpcode, OldOpcode,	 OldOpcode);

        switch (NewOpcode)
        {
        case ScrollInc:
        case DataInc:
            GUI_O2_AnalyzerFHeSet = (uint16_t)SettingData(GUI_O2_AnalyzerFHeSet, (100-GUI_O2_AnalyzerFO2Set), 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case DataDec:
            GUI_O2_AnalyzerFHeSet = (uint16_t)SettingData(GUI_O2_AnalyzerFHeSet, (100-GUI_O2_AnalyzerFO2Set), 0, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            NewOpcode = S476_ANALYZE_SELECT_GAS_LIST_MODE;
            break;
        }
        break;

    case S476_ANALYZE_SELECT_GAS_LIST_MODE:

        NewOpcode = Opcode_Matrix( S470_O2ANALYZER_ANALYZE,  DataDec,	DataInc,	OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
            GUI_O2ANALYZER_DIVEMODE_ASSIGN = (NVD_DIVEMODE_t)SettingData(GUI_O2ANALYZER_DIVEMODE_ASSIGN, NVD_MDSM, NVD_MDCC, 1, data_increase);
            NewOpcode = OldOpcode;
            break;
        case DataDec:
            GUI_O2ANALYZER_DIVEMODE_ASSIGN = (NVD_DIVEMODE_t)SettingData(GUI_O2ANALYZER_DIVEMODE_ASSIGN, NVD_MDSM, NVD_MDCC, 1, data_decrease);
            NewOpcode = OldOpcode;
            break;
        case SaveAndDone:
            NewOpcode = S477_ANALYZE_SELECT_GAS_TO_ASSIGN;

            break;
        }

        break;

    case S477_ANALYZE_SELECT_GAS_TO_ASSIGN:
        /*up/down list to select*/
        HandleButton_O2AnalyzerList(&NewOpcode, &OldOpcode);
        break;
    case S486_ANALYZE_SET_BOTH_OCL_OCR:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode,		OldOpcode,	S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;
    case S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS:

        NewOpcode = Opcode_Matrix( OldOpcode, DataDec,	DataInc,		OldOpcode,	SaveAndDone, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        switch (NewOpcode)
        {
        case DataInc:
        case DataDec:
            GUI_O2ANALYZER_FO2_ASSIGN_FLAT = (uint8_t)SettingData((uint8_t)GUI_O2ANALYZER_FO2_ASSIGN_FLAT, 1, 0, 1, data_increase);
            NewOpcode = OldOpcode;
            break;

        case SaveAndDone:
            if(GUI_O2ANALYZER_FO2_ASSIGN_FLAT == 1) //YES
            {
                if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDCC)
                {
                    TRIMIX_Set.CC_FO2[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFO2Set;
                    TRIMIX_Set.CC_FHe[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFHeSet;
                }
                else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDOC)
                {
                    TRIMIX_Set.OC_FO2[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFO2Set;
                    TRIMIX_Set.OC_FHe[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFHeSet;
                }
                else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDSM)
                {
                    TRIMIX_Set.SM_FO2[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFO2Set;
                    TRIMIX_Set.SM_FHe[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFHeSet;
                }
                else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDGSM)
                {
                    TRIMIX_Set.GSM_FO2[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFO2Set;
                    TRIMIX_Set.GSM_FHe[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFHeSet;
                }
                else
                {
                    TRIMIX_Set.GAUGE_FO2[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFO2Set;
                    TRIMIX_Set.GAUGE_FHe[GAS_ASSIGN_INDEX] = GUI_O2_AnalyzerFHeSet;
                }

                EE_SaveReq(EE_TRIMIXSET);                // save to EE
                NewOpcode = S479_ANALYZE_ASSIGN_COMPLETE;
            }
            else//NO
            {
                NewOpcode = S477_ANALYZE_SELECT_GAS_TO_ASSIGN; 			 // back to Menu
            }
            break;
        }
        break;
    case S479_ANALYZE_ASSIGN_COMPLETE:

        NewOpcode = Opcode_Matrix( OldOpcode, OldOpcode,	OldOpcode, 		OldOpcode,	S470_O2ANALYZER_ANALYZE, ReturnToMainPage(), OldOpcode, OldOpcode,  OldOpcode);
        break;


    //========================================================================================================================================================================
    /*DIVE MODE*/
    //========================================================================================================================================================================
    /*DIVE MAIN MENU*/
    //========================================================================================================================================================================


    case D22_SP_SWITCH:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D53_SLATES,	D28_GAS_SWITCH,	   			OldOpcode,  SP_SWITCH_TO_HIGH,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D28_GAS_SWITCH:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D22_SP_SWITCH,	D32_SWITCH_MODE,	   	OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D32_SWITCH_MODE:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D28_GAS_SWITCH,	D33_BRIGHTNESS,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D33_BRIGHTNESS:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D32_SWITCH_MODE,	D35_DIVE_MENU,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D35_DIVE_MENU:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D33_BRIGHTNESS,	D53_SLATES,	   		OldOpcode,  D36_SET_SP,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D53_SLATES:
        NewOpcode = Opcode_Matrix( D1_DIVE_MAIN,  D35_DIVE_MENU,	D22_SP_SWITCH,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;



    /*DIVE MENU*/

    case D36_SET_SP:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D49_SET_GF_HIGH,		D37_SET_GASES,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D37_SET_GASES:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D36_SET_SP,			D42_DIVE_PROFILE_GRAPH,	   	OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D42_DIVE_PROFILE_GRAPH:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D37_SET_GASES,		D44_BAILOUT_PO2_LIMITS,	   	OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D44_BAILOUT_PO2_LIMITS:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D42_DIVE_PROFILE_GRAPH,	D45_DECO_STOPS,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D45_DECO_STOPS:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D44_BAILOUT_PO2_LIMITS,	D49_SET_GF_HIGH,	   	OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    case D49_SET_GF_HIGH:
        NewOpcode = Opcode_Matrix( D35_DIVE_MENU,  D45_DECO_STOPS,		D36_SET_SP,	   		OldOpcode,  OldOpcode,   OldOpcode, OldOpcode, OldOpcode, 	OldOpcode);
        break;

    //========================================================================================================================================================================
    /*DIVE MAIN PAGE*/
    //========================================================================================================================================================================

    case DIVE_GAUGE_MAIN:

        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, DIVEMAINMENU_TMTSWITCH,      DIVE_DEPTH_AND_DIVETIME,   DIVE_GAUGE_ALT,	C2_COMPASS_MAIN_DIVE,  OldOpcode,  OldOpcode, OldOpcode);

        if(pre_DSX_Opcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        switch(NewOpcode)
        {
        case CheckConditions:       // L 2S Button to Reset Runtime
            Runtime.ResetReq = true;
            NewOpcode = OldOpcode;
            break;

        case DataDec:              // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;
        }
        break;

    case DIVE_GAUGE_ALT:

        NewOpcode = Opcode_Matrix( DIVE_GAUGE_MAIN,   OldOpcode,      OldOpcode,      OldOpcode,      DIVE_GAUGE_MAIN,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_DEPTH_AND_DIVETIME:

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),  ReturnToMainPage(),  ReturnToMainPage(),  ReturnToMainPage(),  ReturnToMainPage(), ReturnToMainPage(),  ReturnToMainPage(),  ReturnToMainPage(),  OldOpcode);

        break;

#if 0   // Gauge Mode only has ALT1
    case DIVE_GAUGE_ALT_3:

        NewOpcode = Opcode_Matrix( OldOpcode,   OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_GAUGE_ALT_4:

        NewOpcode = Opcode_Matrix( OldOpcode,   OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_GAUGE_ALT_5:

        NewOpcode = Opcode_Matrix( OldOpcode,   OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode,      OldOpcode);

        break;
#endif

    case DIVE_CC_MAIN:
        OpcodeForR2s = DIVE_CC_MAIN;
        UnderWaterFlat = TRUE;
        find_CC_SP_Current();
        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, DIVEMAINMENU_SPSWITCH,      DIVE_DEPTH_AND_DIVETIME,   ButtonR1,	C2_COMPASS_MAIN_DIVE,  OldOpcode,  OldOpcode, OldOpcode);

        if(Dive_Info.Status == AMB_DIVEINFO_SURF)
            NewOpcode = S2_SURFACE_MAIN;

        if(pre_DSX_Opcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        switch(NewOpcode)
        {
        case CheckConditions:
            Runtime.ResetReq = true;    // L 2S Button to Reset Runtime, no Gas Switch Suggestion in CC Mode
            NewOpcode = OldOpcode;
            break;

        case DataDec:              // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;

        case ButtonR1:

            if(DoAlarmAck())
            {
                AlarmAcknowledgement();
                NewOpcode = OldOpcode;
            }
            else
            {
                NewOpcode = DIVE_CC_ALT_1;
            }
            break;
        }


        break;

    case DIVE_CC_ALT_1:
        NewOpcode = Opcode_Matrix( DIVE_CC_MAIN,   OldOpcode,       DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_ALT_2,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_CC_ALT_2:
        if(isViolation) // if isViolation, bypass the rest of ALTx
            NewOpcode = Opcode_Matrix( DIVE_CC_ALT_1,   OldOpcode,      DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_MAIN,   ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else
            NewOpcode = Opcode_Matrix( DIVE_CC_ALT_1,   OldOpcode,      DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_ALT_3,  ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_CC_ALT_3:
        NewOpcode = Opcode_Matrix( DIVE_CC_ALT_2,   OldOpcode,      DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_ALT_4,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_CC_ALT_4:

        NewOpcode = Opcode_Matrix( DIVE_CC_ALT_3,   OldOpcode,      DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_ALT_5,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_CC_ALT_5:

        NewOpcode = Opcode_Matrix( DIVE_CC_ALT_4,   OldOpcode,      DIVEMAINMENU_SPSWITCH,      OldOpcode,      DIVE_CC_MAIN,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_OC_MAIN:
        UnderWaterFlat = TRUE;
        OpcodeForR2s = DIVE_OC_MAIN;
        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, DIVEMAINMENU_GASSWITCH,      DIVE_DEPTH_AND_DIVETIME,   ButtonR1,	C2_COMPASS_MAIN_DIVE,  OldOpcode,  OldOpcode, OldOpcode);

        if(Dive_Info.Status == AMB_DIVEINFO_SURF)
            NewOpcode = S2_SURFACE_MAIN;

        if(pre_DSX_Opcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        switch(NewOpcode)
        {
        case CheckConditions:
            if(NeedToSwitchGas)
                DeclinedGasNumber = SuggestedBestGasNumber;     // L 2S Button to decline Gas Swtich
            else
                Runtime.ResetReq = true;                        // L 2S Button to Reset Runtime
            NewOpcode = OldOpcode;
            break;

        case DataDec:              // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;

        case ButtonR1:

            if(DoAlarmAck())
            {
                AlarmAcknowledgement();
                NewOpcode = OldOpcode;
            }
            else
            {
                NewOpcode = DIVE_OC_ALT_1;
            }
            break;
        }
        break;

    case DIVE_OC_ALT_1:

        NewOpcode = Opcode_Matrix( DIVE_OC_MAIN,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_ALT_2,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_OC_ALT_2:
        if(isViolation) // if isViolation, bypass the rest of ALTx
            NewOpcode = Opcode_Matrix( DIVE_OC_ALT_1,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_MAIN,  ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else
            NewOpcode = Opcode_Matrix( DIVE_OC_ALT_1,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_ALT_3, ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_OC_ALT_3:

        NewOpcode = Opcode_Matrix( DIVE_OC_ALT_2,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_ALT_4,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_OC_ALT_4:

        NewOpcode = Opcode_Matrix( DIVE_OC_ALT_3,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_ALT_5,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_OC_ALT_5:

        NewOpcode = Opcode_Matrix( DIVE_OC_ALT_4,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_OC_MAIN,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVE_SM_MAIN:
        UnderWaterFlat = TRUE;
        OpcodeForR2s = DIVE_SM_MAIN;
        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, DIVEMAINMENU_GASSWITCH,      DIVE_DEPTH_AND_DIVETIME,   ButtonR1,	C2_COMPASS_MAIN_DIVE,  OldOpcode,  OldOpcode, OldOpcode);

        if(Dive_Info.Status == AMB_DIVEINFO_SURF)
            NewOpcode = SURFACE_SM_MAIN;

        if(pre_DSX_Opcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        switch(NewOpcode)
        {
        case CheckConditions:
            if(NeedToSwitchGas)
                DeclinedGasNumber = SuggestedBestGasNumber;     // L 2S Button to decline Gas Swtich
            else
                Runtime.ResetReq = true;                        // L 2S Button to Reset Runtime
            NewOpcode = OldOpcode;
            break;

        case DataDec:			  // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;

        case ButtonR1:

            if(DoAlarmAck())
            {
                AlarmAcknowledgement();
                NewOpcode = OldOpcode;
            }
            else
            {
                NewOpcode = DIVE_SM_ALT_1;
            }
            break;
        }

        break;

    case DIVE_SM_ALT_1:
        NewOpcode = Opcode_Matrix( DIVE_SM_MAIN,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_ALT_2,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_SM_ALT_2:
        if(isViolation) // if isViolation, bypass the rest of ALTx
            NewOpcode = Opcode_Matrix( DIVE_SM_ALT_1,   OldOpcode,  DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_MAIN,  ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else
            NewOpcode = Opcode_Matrix( DIVE_SM_ALT_1,   OldOpcode,  DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_ALT_3, ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_SM_ALT_3:
        NewOpcode = Opcode_Matrix( DIVE_SM_ALT_2,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_ALT_4,  ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_SM_ALT_4:
        NewOpcode = Opcode_Matrix( DIVE_SM_ALT_3,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_ALT_5,  ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_SM_ALT_5:
        NewOpcode = Opcode_Matrix( DIVE_SM_ALT_4,   OldOpcode,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      DIVE_SM_MAIN,   ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVE_GSM_MAIN:
        UnderWaterFlat = TRUE;
        OpcodeForR2s = DIVE_GSM_MAIN;
        NewOpcode = Opcode_Matrix( CheckConditions,  DataDec, DIVEMAINMENU_TMTSWITCH,      DIVE_DEPTH_AND_DIVETIME,   DIVE_GSM_ALT,	C2_COMPASS_MAIN_DIVE,  OldOpcode,  OldOpcode, OldOpcode);

        if(Dive_Info.Status == AMB_DIVEINFO_SURF)
            NewOpcode = S2_SURFACE_MAIN;

        if(pre_DSX_Opcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        switch(NewOpcode)
        {
        case CheckConditions:       // L 2S Button to Reset Runtime
            Runtime.ResetReq = true;
            NewOpcode = OldOpcode;
            break;

        case DataDec:              // L < 2S Button to Start/Stop Runtime
            if(Runtime.Status == TIMER_Run)
                Runtime.PauseReq = true;
            else
                Runtime.RunReq = true;

            NewOpcode = OldOpcode;
            break;
        }
        break;

    case DIVE_GSM_ALT:

        NewOpcode = Opcode_Matrix( ReturnToMainPage(),   OldOpcode,      OldOpcode,      OldOpcode,      DIVE_GSM_MAIN,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;
    //========================================================================================================================================================================

    case DIVEMAINMENU_SPSWITCH:
        BackupOpcode = DIVEMAINMENU_SPSWITCH;
        if(CC_MODE) {
            // Read back from EERPOM for initial status or values to display
            if(SP_SWITCH == HIGH_SP)
                GUI_SP_Switch = HIGH_SP;
            else if(SP_SWITCH == LOW_SP)
                GUI_SP_Switch = LOW_SP;
            else
                GUI_SP_Switch = CUSTOM_SP;
            GUI_SP_HighVal            = HIGH_SP_Val;          // for GUI displaying
            GUI_SP_LowVal             = LOW_SP_Val;           // for GUI displaying
            GUI_SP_CustomVal          = CUSTOM_SP_Val;        			// for GUI displaying
            GUI_SP_CustomSwitch       = (NVD_status_t)CUSTOM_SP_STAT;  // for GUI displaying

            GUI_SP_AutoHighSwitch     = (NVD_status_t)AUTO_HIGH_SP_STAT;    // for GUI displaying
            GUI_SP_AutoLowSwitch      = (NVD_status_t)AUTO_LOW_SP_STAT;     // for GUI displaying
            GUI_SP_AutoHighMtVal      = SP_AUTOHIGH_M;        // for GUI displaying
            GUI_SP_AutoLowMtVal       = SP_AUTOLOW_M;         // for GUI displaying
            GUI_SP_AutoHighFtVal      = SP_AUTOHIGH_FT;       // for GUI displaying
            GUI_SP_AutoLowFtVal       = SP_AUTOLOW_FT;        // for GUI displaying SP_SWITCH_TO_LOW, SP_SWITCH_TO_HIGH,SP_SWITCH_TO_CUSTOM


            /*set actual sp*/
            if( GUI_SP_Switch == HIGH_SP) {
                GUI_SP_ActualVal = GUI_SP_HighVal;
            }
            else if( GUI_SP_Switch == LOW_SP) {
                GUI_SP_ActualVal = GUI_SP_LowVal;
            }
            else if( GUI_SP_Switch == CUSTOM_SP) {
                GUI_SP_ActualVal = GUI_SP_CustomVal;
            }

            /*go to switch menu*/
            if(GUI_SP_Switch == HIGH_SP)
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_SLATES,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      SP_SWITCH_TO_LOW,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            else
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_SLATES,      DIVEMAINMENU_GASSWITCH,      OldOpcode,      SP_SWITCH_TO_HIGH,     ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }

        break;

    case DIVEMAINMENU_GASSWITCH:

        BackupOpcode = DIVEMAINMENU_GASSWITCH;

        if(CC_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), DIVEMAINMENU_SPSWITCH,    DIVEMAINMENU_SWITCHCC2BO,     OldOpcode,      GAS_SWITCH_TO_GAS_0,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(BO_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), DIVEMAINMENU_SLATES,      DIVEMAINMENU_SWITCHBO2CC,     OldOpcode,      GAS_SWITCH_TO_GAS_0,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(OC_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), DIVEMAINMENU_SLATES,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      GAS_SWITCH_TO_GAS_0,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(SM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(), DIVEMAINMENU_SLATES,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      GAS_SWITCH_TO_GAS_0,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVEMAINMENU_SWITCHCC2BO:
    case DIVEMAINMENU_SWITCHBO2CC:

        if(CC_MODE||BO_MODE)
        {
            if(CC_MODE)
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_GASSWITCH,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      SaveAndDone,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            else // must be BO_MODE
                NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_GASSWITCH,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      SaveAndDone,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

            if(NewOpcode == SaveAndDone)
            {
                if(DIVE_MODE==NVD_MDCC)
                {
                    Alarming.Bit.PO2_Lo = 0;      // disabled the alarms not belong to BO mode
                    Alarming.Bit.PO2_Hi = 0;      // disabled the alarms not belong to BO mode
                    GUI_ShowTankNum = TRIMIX_Set.CurrGasNumber_BO;      // sync up GUI for the selected tank (always fixed in TANK_1?)
                    NewOpcode = DIVE_OC_MAIN;
                    DIVE_MODE = NVD_MDBO;
                    RETURN_DIVE_MODE = NVD_MDBO;
                    Dive_Info.ModeSwitchFlag = MODE_SWITCH_CC2BO;
                }
                else if(DIVE_MODE==NVD_MDBO)
                {
                    Alarming.Bit.SwitchFO2 = 0;         // disabled the alarms not belong to BO mode
                    Alarming2.Bit.OCSM_MinPO2 = 0;      // disabled the alarms not belong to CC mode
                    Alarming2.Bit.OCSM_MaxPO2 = 0;      // disabled the alarms not belong to CC mode
                    Alarming2.Bit.OCSM_DecoPO2 = 0;     // disabled the alarms not belong to CC mode
                    GUI_ShowTankNum = TRIMIX_Set.CurrGasNumber_CC;      // sync up GUI for the CC selected tank
                    NewOpcode = DIVE_CC_MAIN;
                    DIVE_MODE = NVD_MDCC;
                    RETURN_DIVE_MODE = NVD_MDCC;
                    Dive_Info.ModeSwitchFlag = MODE_SWITCH_BO2CC;
                }
                GUI_DIVE_Mode = DIVE_MODE;

                Switch_Mode();
                Check3rdRowAfterDiveModeSwitch();
                EE_SaveReq(EE_USERSET);         // save to EE
            }
        }
        break;


    case DIVEMAINMENU_DIVEMENU:

        if(CC_MODE)
        {
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_BRIGHTNESS,     DIVEMAINMENU_SLATES,       OldOpcode,      DIVEMENU_SETSP,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            GFHighSettingValue = SCUBA_Set.TEC_GF_Hi;
        }
        else if(OC_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_BRIGHTNESS,     DIVEMAINMENU_SLATES,       OldOpcode,      DIVEMENU_SETGASES,   ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(SM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_BRIGHTNESS,     DIVEMAINMENU_SLATES,       OldOpcode,      DIVEMENU_SETGASES,   ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVEMAINMENU_TMTSWITCH:
        if(GSM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_SLATES,      DIVEMAINMENU_RESETAVGDEPTH,      OldOpcode,      DIVEMAINMENU_TMTSWITCH_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GAUGE_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_SLATES,      DIVEMAINMENU_RESETAVGDEPTH,      OldOpcode,      DIVEMAINMENU_TMTSWITCH_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;
    case DIVEMAINMENU_TMTSWITCH_SET:
        HandleButton_DiveMainMenu_TMTSwitch(&NewOpcode, &OldOpcode);
        break;
    case DIVEMAINMENU_RESETAVGDEPTH:

        if(GSM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_TMTSWITCH,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      DIVEMAINMENU_RESETAVGDEPTH_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GAUGE_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_TMTSWITCH,      DIVEMAINMENU_BRIGHTNESS,      OldOpcode,      DIVEMAINMENU_RESETAVGDEPTH_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;
    case DIVEMAINMENU_RESETAVGDEPTH_SET:
        HandleButton_DiveMenu_ResetAVGDepth(&NewOpcode, &OldOpcode);
        break;

    case DIVEMAINMENU_BRIGHTNESS:
        BackupOpcode = DIVEMAINMENU_BRIGHTNESS;
        GUI_BRIGHTNESS_LV = BRIGHTNESS_LV;              // GUI Settings for BRIGHTNESS_LV
        GUI_DIM_BRIGHT_LV = DIM_BRIGHT_LV;              // GUI Settings for DIM_BRIGHT_LV
        if(CC_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_SWITCHCC2BO,      	DIVEMAINMENU_DIVEMENU,      OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(BO_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_SWITCHBO2CC,      	DIVEMAINMENU_DIVEMENU,      OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(OC_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_GASSWITCH,     	DIVEMAINMENU_DIVEMENU,      OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(SM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_GASSWITCH,      	DIVEMAINMENU_DIVEMENU,      OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GSM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_RESETAVGDEPTH,     DIVEMAINMENU_DIVEPROFILE,   OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GAUGE_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   	DIVEMAINMENU_RESETAVGDEPTH,     DIVEMAINMENU_DIVEPROFILE,   OldOpcode,      DISPLAY_BRIGHTNESS_SET,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);

        break;

    case DIVEMAINMENU_DIVEPROFILE:

        if(GSM_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_BRIGHTNESS,      DIVEMAINMENU_SLATES,      OldOpcode,      DIVEMAINMENU_DIVEPROFILE_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GAUGE_MODE)
            NewOpcode = Opcode_Matrix( ReturnToMainPage(),   DIVEMAINMENU_BRIGHTNESS,      DIVEMAINMENU_SLATES,      OldOpcode,      DIVEMAINMENU_DIVEPROFILE_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVEMAINMENU_DIVEPROFILE_ENTER:
        NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEPROFILE,   DIVEMAINMENU_DIVEPROFILE,      OldOpcode,      OldOpcode,      DIVEMAINMENU_DIVEPROFILE,      DIVEMAINMENU_DIVEPROFILE,      OldOpcode,      OldOpcode,      OldOpcode);
        break;
    case DIVEMAINMENU_SLATES:
        BackupOpcode = DIVEMAINMENU_SLATES;
        if(CC_MODE)
            NewOpcode = Opcode_Matrix( DIVE_CC_MAIN,   		DIVEMAINMENU_DIVEMENU,          DIVEMAINMENU_SPSWITCH,      OldOpcode,      CheckConditions,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(OC_MODE||BO_MODE)
            NewOpcode = Opcode_Matrix( DIVE_OC_MAIN,   		DIVEMAINMENU_DIVEMENU,      	DIVEMAINMENU_GASSWITCH,     OldOpcode,      CheckConditions,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(SM_MODE)
            NewOpcode = Opcode_Matrix( DIVE_SM_MAIN,   		DIVEMAINMENU_DIVEMENU,      	DIVEMAINMENU_GASSWITCH,     OldOpcode,      CheckConditions,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        else if(GSM_MODE)
            NewOpcode = Opcode_Matrix( DIVE_GSM_MAIN,   	DIVEMAINMENU_DIVEPROFILE,       DIVEMAINMENU_TMTSWITCH,     OldOpcode,      CheckConditions,      ReturnToMainPage(),     OldOpcode,      OldOpcode,      OldOpcode);
        else if(GAUGE_MODE)
            NewOpcode = Opcode_Matrix( DIVE_GAUGE_MAIN,   	DIVEMAINMENU_DIVEPROFILE,       DIVEMAINMENU_TMTSWITCH,     OldOpcode,      CheckConditions,      ReturnToMainPage(),   OldOpcode,      OldOpcode,      OldOpcode);

        CheckSlateMainPageStatus(&NewOpcode);
        break;


    /*DIVE MENU = SET GASES,DIVE PROFILE GRAPH... */

    case DIVEMENU_SETSP:
        BackupOpcode = DIVEMENU_SETSP;
        if(CC_MODE) {
            if(CONSER_SETPOINTS == CONSV_TEC) {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETGFHIGH,      DIVEMENU_SETGASES,      OldOpcode,      S54_SP_HIGH_SP,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DECOSTOPS,      DIVEMENU_SETGASES,      OldOpcode,      S54_SP_HIGH_SP,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
        }
        break;

    case DIVEMENU_SETGASES:
        BackupOpcode = DIVEMENU_SETGASES;
        if(OC_MODE||SM_MODE||BO_MODE)
        {
            if(CONSER_SETPOINTS == CONSV_TEC) {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETGFHIGH,      DIVEMENU_DIVEPROFILEGRAPH,      OldOpcode,      S70_SET_GAS_01,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DECOSTOPS,      DIVEMENU_DIVEPROFILEGRAPH,      OldOpcode,      S70_SET_GAS_01,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
        }
        else // for CC
        {
            if(CONSER_SETPOINTS == CONSV_TEC) {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETSP,      DIVEMENU_DIVEPROFILEGRAPH,      OldOpcode,      S70_SET_GAS_01,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETSP,      DIVEMENU_DIVEPROFILEGRAPH,      OldOpcode,      S70_SET_GAS_01,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
            }
        }
        break;

    case DIVEMENU_DIVEPROFILEGRAPH:
        if(CC_MODE)
        {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETGASES,      DIVEMENU_BAILOUTPO2LIMITS,      OldOpcode,      DIVEMENU_DIVEPROFILEGRAPH_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }
        else if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_SETGASES,      DIVEMENU_PO2LIMITS,      OldOpcode,      DIVEMENU_DIVEPROFILEGRAPH_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }
        break;


    case DIVEMENU_BAILOUTPO2LIMITS:
        BackupOpcode = DIVEMENU_BAILOUTPO2LIMITS;
        if(CC_MODE)
        {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DIVEPROFILEGRAPH,	   DIVEMENU_DECOSTOPS,		OldOpcode,		BAILOUT_PO2_OC_MIN, 	 ReturnToMainPage(),		OldOpcode,		OldOpcode,		OldOpcode);
        }
        break;


    case DIVEMENU_PO2LIMITS:
        BackupOpcode = DIVEMENU_PO2LIMITS;
        if(OC_MODE||SM_MODE||BO_MODE) {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DIVEPROFILEGRAPH,      DIVEMENU_DECOSTOPS,      OldOpcode,      BAILOUT_PO2_OC_MIN,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }
        break;

    case DIVEMENU_DECOSTOPS:
        if(OC_MODE||SM_MODE||BO_MODE)
        {
            if(CONSER_SETPOINTS == CONSV_TEC) {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_PO2LIMITS,		DIVEMENU_SETGFHIGH, 	 OldOpcode, 	 DIVEMENU_DECOSTOPS_ENTER,		ReturnToMainPage(),	   OldOpcode,	   OldOpcode,	   OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_PO2LIMITS,		DIVEMENU_SETGASES, 	 OldOpcode, 	 DIVEMENU_DECOSTOPS_ENTER,		ReturnToMainPage(),	   OldOpcode,	   OldOpcode,	   OldOpcode);
            }
        }
        else
        {
            if(CONSER_SETPOINTS == CONSV_TEC) {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_BAILOUTPO2LIMITS,	   DIVEMENU_SETGFHIGH,		OldOpcode,		DIVEMENU_DECOSTOPS_ENTER,	   ReturnToMainPage(),	  OldOpcode,	  OldOpcode,	  OldOpcode);
            }
            else {
                NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_BAILOUTPO2LIMITS,	   DIVEMENU_SETSP,		OldOpcode,		DIVEMENU_DECOSTOPS_ENTER,	   ReturnToMainPage(),	  OldOpcode,	  OldOpcode,	  OldOpcode);
            }
        }
        break;

    case DIVEMENU_SETGFHIGH:
        if(OC_MODE||SM_MODE||BO_MODE)
        {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DECOSTOPS,      DIVEMENU_SETGASES,      OldOpcode,      DIVEMENU_SET_GF_HIGH_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }
        else
        {
            NewOpcode = Opcode_Matrix( DIVEMAINMENU_DIVEMENU,  DIVEMENU_DECOSTOPS,      DIVEMENU_SETSP,      OldOpcode,      DIVEMENU_SET_GF_HIGH_ENTER,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        }
        break;

    case DIVEMENU_DIVEPROFILEGRAPH_ENTER:
        NewOpcode = Opcode_Matrix( DIVEMENU_DIVEPROFILEGRAPH,  OldOpcode,      OldOpcode,      OldOpcode,      DIVEMENU_DIVEPROFILEGRAPH,      ReturnToMainPage(),      OldOpcode,      OldOpcode,      OldOpcode);
        break;

    case DIVEMENU_DECOSTOPS_ENTER:
        HandleButton_DiveMenu_DecoStop(&NewOpcode, &OldOpcode);
        break;

    case DIVEMENU_SET_GF_HIGH_ENTER:
        HandleButton_DiveMenu_SetGFHigh(&NewOpcode, &OldOpcode);
        break;

    default:
        NewOpcode = S2_SURFACE_MAIN; // return to Surface Main menu
        break;

    }
    NewOpcode = NewOpcode_Overwrite(NewOpcode);

    return NewOpcode;
}

/*
	check TMT select is already link or not.
	return 0: not link
	or return 1-6 - GAS# is linked

*/

uint8_t CheckTMTisLinked(TMT_NUM_t TMT_index)
{
    uint8_t Flat_check = 0;

    for(uint8_t i = TMT_1; i<=TMT_6; i++) {
        if(GUI_ShowTankNum ==i) {	//bypass current gas
        }
        else {

            if(CC_MODE) {
                if((GUI_NumOfTMT_Gas_CC[i]==TMT_index)&&(TMT_index)) {
                    Flat_check = i;
                }
            }
            else if(BO_MODE) {
                if((GUI_NumOfTMT_Gas_BO[i]==TMT_index)&&(TMT_index)) {
                    Flat_check = i;
                }
            }
            else if(OC_MODE) {
                if((GUI_NumOfTMT_Gas_OC[i]==TMT_index)&&(TMT_index)) {
                    Flat_check = i;
                }
            }
            else if(SM_MODE) {
                if((GUI_NumOfTMT_Gas_SM[i]==TMT_index)&&(TMT_index)&&(i > TMT_1)) {
                    Flat_check = i;
                }
            }

        }
    }

    return Flat_check;
}


uint8_t CheckTMTisDuplicate(TMT_NUM_t TMT_index, NVD_DIVEMODE_t * mode_linked, uint8_t * gas_linked)   /*check full mode, it should only is linked 1 mode*/
{
    uint8_t Flat_check = 0;

    NVD_DIVEMODE_t mod_tmp = 0;

    if(CC_MODE) { /*current mode is CC*/
        for(uint8_t i = TMT_1; i<=TMT_6; i++) {
            if((GUI_NumOfTMT_Gas_OC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDOC;
            }
            else if((GUI_NumOfTMT_Gas_SM[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDSM;
            }
            else if((GUI_NumOfTMT_Gas_BO[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDBO;
            }
        }
    }

    else if(OC_MODE) { /*current mode is OC*/
        for(uint8_t i = TMT_1; i<=TMT_6; i++) {
            if((GUI_NumOfTMT_Gas_CC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDCC;
            }
            else if((GUI_NumOfTMT_Gas_SM[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDSM;
            }
            else if((GUI_NumOfTMT_Gas_BO[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDBO;
            }
        }
    }
    else if(SM_MODE) { /*current mode is OC*/
        for(uint8_t i = TMT_1; i<=TMT_6; i++) {
            if((GUI_NumOfTMT_Gas_CC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDCC;
            }
            else if((GUI_NumOfTMT_Gas_OC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDOC;
            }
            else if((GUI_NumOfTMT_Gas_BO[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDBO;
            }
        }
    }

    if(BO_MODE) { /*current mode is CC*/
        for(uint8_t i = TMT_1; i<=TMT_6; i++) {
            if((GUI_NumOfTMT_Gas_OC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDOC;
            }
            else if((GUI_NumOfTMT_Gas_SM[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDSM;
            }
            else if((GUI_NumOfTMT_Gas_CC[i]==TMT_index)&&(TMT_index)) {
                Flat_check = i;
                mod_tmp = NVD_MDCC;
            }
        }
    }


    * gas_linked = Flat_check;
    * mode_linked = mod_tmp;
	
    return Flat_check;

}

uint8_t ret12Hfrom24H(  uint8_t _24Hour, uint8_t * _12Hour, uint8_t * MidNight)
{

    /*12h or 24h format?*/
    if((_24Hour>12)&&(TimeSet12h_Format)) {
        *_12Hour = _24Hour-12;
        * MidNight = 1;
    }
    else if((_24Hour==12)&&(TimeSet12h_Format)) {
        * MidNight = 1;
        *_12Hour = _24Hour;
    }
    else if(_24Hour==0&&TimeSet12h_Format) {
        *_12Hour = 12;
        * MidNight = 0;
        //0,1...11	->1,2...12 AM
    }
    else {
        * MidNight = 0;
        *_12Hour = _24Hour;
    }

    return 0;
}

/*

*/
DSX_OPCODE_t NewOpcode_Overwrite(DSX_OPCODE_t Newopcode)
{
    DSX_OPCODE_t OverwriteOpcode;
    static DSX_OPCODE_t PreOverwriteOpcode = W2_WAIT_MESSAGE;
    int32_t MonotonicClock_s_tmp;


    OverwriteOpcode = Newopcode;

    switch(Newopcode)
    {
    /*
        case W1_WELCOME:

            // Displaying Opening Welcome Page, until timeout
            if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
            {
                SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 5;       // set 5 seconds for the timeout
            }
            else
            {
                MonotonicClock_s_tmp = MonotonicClock_s;
                if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
                {
                    OverwriteOpcode = S2_SURFACE_MAIN;   // jumps to Surface Main after the timeout
                }
            }

            break;
    */
    case S11_SURFACE_ALT1:
    case S12_SURFACE_ALT2:
    case S13_SURFACE_ALT3:
    case S14_SURFACE_ALT4:
    case S15_SURFACE_ALT5:
        // Jumps To GPS
        if(  ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType == long_press))
                &&((Key_M.Key_Status == KeyStatus_Pressed) && (Key_M.Timer >= KEYPRESS_TIMOUT) && (Key_M.DataType == long_press)) )
        {
            // Start GPS from Surface Main Page
            OverwriteOpcode = S502_GPS_GET_CURRENT_LOCATION;           // L+M > 2sec, go to GPS initial page
            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
        }
        // Jumps To O2 Analyzer
        else if(  ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType == long_press))
                  &&((Key_R.Key_Status == KeyStatus_Pressed) && (Key_R.Timer >= KEYPRESS_TIMOUT) && (Key_R.DataType == long_press)) )
        {
            // Start O2 Analyzer from Surface Main Page
            OverwriteOpcode = S462_O2ANALYZER_CALIBRATE;                // L+R > 2sec, go to O2 Analyzer initial page
            BackupOpcode = S2_SURFACE_MAIN; // return to Surface Main menu
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_OFF;
            SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_MAX;

            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
        }
        else if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
        {
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 120;       // set 2min for the timeout
        }
        else
        {
            MonotonicClock_s_tmp = MonotonicClock_s;
            if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
            {
                OverwriteOpcode = S2_SURFACE_MAIN;       // jumps to Surface Main after the timeout
            }
        }
        break;


    case SURFACE_SM_ALT1:
    case SURFACE_SM_ALT2:
    case SURFACE_SM_ALT3:
    case SURFACE_SM_ALT4:
    case SURFACE_GAUGE_ALT1:
    case SURFACE_GAUGE_ALT2:
    case SURFACE_GSM_ALT1:
    case SURFACE_GSM_ALT2:
        // Jumps To GPS
        if(  ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType == long_press))
                &&((Key_M.Key_Status == KeyStatus_Pressed) && (Key_M.Timer >= KEYPRESS_TIMOUT) && (Key_M.DataType == long_press)) )
        {
            // Start GPS from Surface Main Page
            OverwriteOpcode = S502_GPS_GET_CURRENT_LOCATION;		   // L+M > 2sec, go to GPS initial page
            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
        }
        break;


    case DIVE_OC_ALT_1:
    case DIVE_OC_ALT_2:
    case DIVE_OC_ALT_3:
    case DIVE_OC_ALT_4:
    case DIVE_OC_ALT_5:
        if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
        {
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 10;       // set 10 seconds for the timeout
        }
        else
        {
            MonotonicClock_s_tmp = MonotonicClock_s;
            if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
            {
                OverwriteOpcode = DIVE_OC_MAIN;       						// jumps to Surface Main after the timeout
            }
        }

        break;


    case DIVE_CC_ALT_1:
    case DIVE_CC_ALT_2:
    case DIVE_CC_ALT_3:
    case DIVE_CC_ALT_4:
    case DIVE_CC_ALT_5:

        if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
        {
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 10;       // set 10 seconds for the timeout
        }
        else
        {
            MonotonicClock_s_tmp = MonotonicClock_s;
            if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
            {
                OverwriteOpcode = DIVE_CC_MAIN;       						// jumps to Surface Main after the timeout
            }
        }

        break;


    case DIVE_SM_ALT_1:
    case DIVE_SM_ALT_2:
    case DIVE_SM_ALT_3:
    case DIVE_SM_ALT_4:
    case DIVE_SM_ALT_5:

        if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
        {
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 10;       // set 10 seconds for the timeout
        }
        else
        {
            MonotonicClock_s_tmp = MonotonicClock_s;
            if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
            {
                OverwriteOpcode = DIVE_SM_MAIN;       						// jumps to Surface Main after the timeout
            }
        }

        break;

    case DIVE_GSM_ALT:

        if(OpcodeChanged(PreOverwriteOpcode, Newopcode))
        {
            SystemStatus.GUI_Pause_timestamp = MonotonicClock_s + 10;       // set 10 seconds for the timeout
        }
        else
        {
            MonotonicClock_s_tmp = MonotonicClock_s;
            if((MonotonicClock_s_tmp > SystemStatus.GUI_Pause_timestamp))
            {
                OverwriteOpcode = DIVE_GSM_MAIN;       						// jumps to Surface Main after the timeout
            }
        }

        break;


    case S2_SURFACE_MAIN:
    case SURFACE_SM_MAIN:
    case SURFACE_GAUGE_MAIN:
    case SURFACE_GSM_MAIN:
        if(PreOverwriteOpcode == B1_BATT_CHARGE)
        {
            SystemStatus.backlight_on_req = true;
            SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
        }

        if(BO_MODE)
        {
            DIVE_MODE = NVD_MDCC;
            RETURN_DIVE_MODE = NVD_MDCC;
            GUI_DIVE_Mode = NVD_MDCC;
        }

        RestoreBrightnessAfterBattCharging();   // restore original brightness from Low Brightness during battery charging time
        // Jumps To GPS
        if(  ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType == long_press))
                &&((Key_M.Key_Status == KeyStatus_Pressed) && (Key_M.Timer >= KEYPRESS_TIMOUT) && (Key_M.DataType == long_press)) )
        {
            // Start GPS from Surface Main Page
            OverwriteOpcode = S502_GPS_GET_CURRENT_LOCATION;            // L+M > 2sec, go to GPS initial page
            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
        }
        // Jumps To O2 Analyzer
        else if(  ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType == long_press))
                  &&((Key_R.Key_Status == KeyStatus_Pressed) && (Key_R.Timer >= KEYPRESS_TIMOUT) && (Key_R.DataType == long_press)) )
        {
            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
            // Start O2 Analyzer from Surface Main Page
            OverwriteOpcode = S462_O2ANALYZER_CALIBRATE;                // L+R > 2sec, go to O2 Analyzer initial page
            if(CC_MODE||OC_MODE||BO_MODE)
                BackupOpcode = S2_SURFACE_MAIN;
            else
                BackupOpcode = SURFACE_SM_MAIN;

            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_OFF;
            SystemStatus.O2_Analyzer_PreStage = O2_ANALYZER_MAX;
        }
        else
        {
            if(CC_MODE||OC_MODE)
            {
                // no changes
            }
            else if(SM_MODE)
            {
                OverwriteOpcode = SURFACE_SM_MAIN;
            }
            else if(GSM_MODE)
            {
                OverwriteOpcode = SURFACE_GSM_MAIN;
            }
            else if(GAUGE_MODE)
            {
                OverwriteOpcode = SURFACE_GAUGE_MAIN;
            }
        }
        break;
    }


    if(  ((Key_R.Key_Status == KeyStatus_Pressed) && (Key_R.Timer >= KEYPRESS_TIMOUT) && (Key_R.DataType == long_press))
            &&((Key_M.Key_Status == KeyStatus_Pressed) && (Key_M.Timer >= KEYPRESS_TIMOUT) && (Key_M.DataType == long_press)) )
    {
        if(DSX_OPCODE<DIVE_GAUGE_MAIN) /*by pass under water*/
        {

            if(DSX_OPCODE!=DISPLAY_LANGUAGE_SET) {
                BackupOpcode = DSX_OPCODE;
            }

            OverwriteOpcode = DISPLAY_LANGUAGE_SET;              // r+M > 2sec, go to SET LANGUAGE
            Key_L.Timer = 0;
            Key_R.Timer = 0;
            Key_M.Timer = 0;
        }
    }

    PreOverwriteOpcode = OverwriteOpcode;

    return OverwriteOpcode;
}

/**
  * @brief	Opcode Switch according to Button Control Matrix
  * @param	None
  * @retval None
*/
void DSX_OpcodeSwitch(void) // will return OP for DSX, via the Opcode Matrix
{
    DSX_OPCODE = (DSX_OPCODE_t)OPCODE_Matrix(DSX_Opcode);

    DSX_Opcode = DSX_OPCODE;
}

void DSX_OpcodeTask(void)
{

    /*KEY L TASK BEGINS*/
    /*reInit after long press, double press*/
    if ((Key_L.Key_Status == KeyStatus_Released) && (Key_L.Timer < KEYPRESS_TIMOUT) && ((Key_L.DataType == doube_Longpress)||(Key_L.DataType == long_press)||(Key_L.DataType == doube_Shortpress)))
    {
        Key_L.Key_Status = KeyStatus_Idle;
        Key_L.DataType = nothing;
        Key_L.Key_Rolling = KeyStatus_Idle;
    }

    /*short press*/
    else if ((Key_L.Key_Status == KeyStatus_Released) && (Key_L.Timer < KEYPRESS_TIMOUT) && (Key_L.DataType != doube_Longpress))
    {
        Key_L.Key_Status = KeyStatus_Idle;
        Key_L.DataType = short_press;

        DSX_GenerateLogic();

        //UI_App();
        //}
    }

    /*long press >=2s*/
    else if ((Key_L.Key_Status == KeyStatus_Pressed) && (Key_L.Timer >= KEYPRESS_TIMOUT) && (Key_L.DataType != long_press))
    {
        Key_L.Timer = 0;
        Key_L.DataType = long_press;

        DSX_GenerateLogic();
    }
    else {};
    /*KEY L TASK ENDS*/


    /*KEY M TASK BEGINS*/
    /*reInit after long press, double press*/
    if ((Key_M.Key_Status == KeyStatus_Released) && (Key_M.Timer < KEYPRESS_TIMOUT) && ((Key_M.DataType == doube_Longpress)||(Key_M.DataType == long_press)||(Key_M.DataType == doube_Shortpress)))
    {
        Key_M.DataType = nothing;
        Key_M.Key_Status = KeyStatus_Idle;
        Key_M.Key_Rolling = KeyStatus_Idle;
    }

    /*short press*/
    else if ((Key_M.Key_Status == KeyStatus_Released) && (Key_M.Timer < KEYPRESS_TIMOUT) && (Key_M.DataType != long_press))
    {
        Key_M.Key_Status = KeyStatus_Idle;
        Key_M.DataType = short_press;

        DSX_GenerateLogic();

        //UI_App();

    }

    /*long press >=2s*/
    else if ((Key_M.Key_Status == KeyStatus_Pressed) && (Key_M.Timer >= KEYPRESS_TIMOUT) && (Key_M.DataType != long_press))
    {
        Key_M.Timer = 0;
        Key_M.DataType = long_press;

        DSX_GenerateLogic();

    }

    else {};
    /*KEY M TASK ENDS*/

    /*KEY R TASK BEGINS*/
    /*reInit after long press, double press*/
    if ((Key_R.Key_Status == KeyStatus_Released) && (Key_R.Timer < KEYPRESS_TIMOUT) && ((Key_R.DataType == doube_Longpress)||(Key_R.DataType == long_press)||(Key_R.DataType == doube_Shortpress)))
    {
        Key_R.DataType = nothing;
        Key_R.Key_Status = KeyStatus_Idle;
        Key_R.Key_Rolling = KeyStatus_Idle;
    }

    /*short press*/
    else if ((Key_R.Key_Status == KeyStatus_Released) && (Key_R.Timer < KEYPRESS_TIMOUT) && (Key_R.DataType != long_press))
    {
        Key_R.Key_Status = KeyStatus_Idle;
        Key_R.DataType = short_press;

        DSX_GenerateLogic();

        //UI_App();

    }

    /*long press >=2s*/
    else if ((Key_R.Key_Status == KeyStatus_Pressed) && (Key_R.Timer >= KEYPRESS_TIMOUT) && (Key_R.DataType != long_press))
    {
        Key_R.Timer = 0;
        Key_R.DataType = long_press;

        DSX_GenerateLogic();
    }

    else {};
    /*KEY R TASK ENDS*/


    // do UI_App at every Tick while Short Press on L, M buttons and Scrolling (L) and M button(s)
    if((Key_L.Key_Rolling == KeyStatus_Scroll)||(Key_M.Key_Rolling == KeyStatus_Scroll)||(Key_L.Key_Status != 0)||(Key_M.Key_Status != 0)||(Key_R.Key_Status != 0)) {

        if((DSX_Opcode != C1_COMPASS_MAIN)&&(DSX_Opcode != C2_COMPASS_MAIN_DIVE))         // for some Opcode(s) that do not display immediately during button long pressing
            UI_App();
        LCD_STAT = updated;
    }
    else {
        LCD_STAT = needupdate;
    }

}
void DSX_IdleControl(void)
{

}

/**
  * @brief	DSX_GenerateLogic for switch OP or MS. if it fail, just up/down menu list task
  * @param	None
  * @retval None
  */
void DSX_GenerateLogic(void)
{
    DSX_OPCODE = (DSX_OPCODE_t)OPCODE_Matrix(DSX_Opcode);

    //DSX_Opcode_String[];
    DSX_Opcode = DSX_OPCODE;


    AnyKeyPress =TRUE;

}



/**
	  * @brief	decrease code for key press
	  * @param	None
	  * @retval None
	  */
void decreaseCode(uint8_t *code, uint8_t max, uint8_t min)
{
    uint8_t temp = *code;
    if (temp <= min)
    {
        temp = max;
    }
    else
    {
        temp--;
    }
    *code = temp;
}

/**
	  * @brief	increase code for key press
	  * @param	None
	  * @retval None
	  */

void increaseCode(uint8_t *code, uint8_t max, uint8_t min)
{
    uint8_t temp = *code;
    if (temp >= max)
    {
        temp = min;
    }
    else
    {
        temp++;
    }
    *code = temp;
}

float SettingData(float code, float max, float min, float data_step, uint8_t down_up)
{
    float temp = code;

    if (down_up == data_increase)
    {
        if (temp >= max)
        {
            temp = min;
        }
        else
        {
            temp += data_step;
        }

    }

    else if (down_up == data_decrease)
    {
        if (temp <= min)
        {
            temp = max;
        }
        else
        {
            temp = temp - data_step;
        }
    }

    return temp;
}





void updateSettingData(uint8_t *code, uint8_t *data_buf, uint8_t buf_len, uint8_t down_up)
{
    uint8_t temp = *code;
    uint8_t loop = 0;
    if (down_up == data_increase)
    {
        if (temp == data_buf[buf_len - 1])
        {
            temp = data_buf[0]; /*when data = max, set data =	min*/
        }
        else
        {
            for (loop = 0; loop < buf_len; loop++)
            {
                if (temp < data_buf[loop])
                {
                    temp = data_buf[loop];
                    break;
                }
            }
        }
    }
    else if (down_up == data_decrease)
    {
        if (temp == data_buf[0])
        {
            temp = data_buf[buf_len - 1]; /*when data = min, set data =	max*/
        }
        else
        {
            for (loop = 0; loop < buf_len; loop++)
            {
                if (temp == data_buf[loop])
                {
                    temp = data_buf[loop - 1];
                    break;
                }
            }
        }
    }
    *code = temp;
}

/*******************************************************************************

    To rectify data value within the min and MAX legal range

    to avoid reading out-of-range data and causing unexpected result

*******************************************************************************/
float RectifyData(float code, float max, float min)
{
    float temp = code;

    if (temp > max)
    {
        temp = max;
    }

    if (temp < min)
    {
        temp = min;
    }

    return temp;
}


#if 0

/**
	  * @brief	get max index for each menu type
	  * @param	opcode

	  * @retval max index
	  */

uint8_t ReturnMenuList(uint8_t OC)
{
    uint8_t MaxList = 0;
    switch (OC)
    {
    case i330_NORM_MENU:
        //MaxList = i330_NSM_MAX;

        MaxList = (DIVE_MODE == NVD_MDFREE)?i330_FRE_MAX:i330_NSM_MAX;
        break;

    case i330_SETGAS_MENU:
        MaxList = i330_SETGAS_MAX;
        break;

    case i330_SETUTILITIES_MENU:

        if((DIVE_MODE == NVD_MDSCUBA) &&  (DVSTAT_STAT !=0x80)) {
            MaxList = i330_SU_CONSVE;
        }
        else {
            MaxList = i330_SU_BLUETOOTH;
        }



        break;

    case i330_SETALARM_MENU:
        if((DIVE_MODE == NVD_MDSCUBA) &&  (DVSTAT_STAT !=0x80))
        {
            MaxList = i330_SA_SETDTR;
        }
        else {
            MaxList = i330_SA_SETDIVETIME;
        }

        break;

    case i330_MENU_UNDER_WATER:
        MaxList = i330_UW_MAX;

        if((DIVE_MODE ==NVD_MDSCUBA) && ((DVSTAT_STAT & 0xF0) !=0x80)) {
            MaxList = i330_UW_MAX;      // allow Gas Switching only in (Scuba Dive AND No Violation)
        }
        else {
            MaxList = i330_UW_BRIGHTNESS;
        }

        break;

    case i330_SETDATE_MENU:
        MaxList = i330_ST_MAX;
        break;

    }
    return MaxList;
}

/*	@brief	control i330 from SUF to DIVE, DIVE to SUF.......
*	@param	none

*	@retval none
*/

void i330_SwitchOP(void)
{
    switch (i330_Opcode)
    {
    case i330_SURFACE_MODE:
        if (Dive_Info.Status == AMB_DIVEINFO_DIVE)
        {   /*condition to enter Dive mode*/
            /*go to DIVE MAIN*/
            i330_Opcode = i330_DIVE_MODE;
            i330_MENSTAT = i330_DIV_MAIN;
            i330_key_task = data_setting;
        }
        //if(Dive_Info.Status == AMB_DIVEINFO_SURF && SwitchOP_flat ==  FALSE) {
        //    i330_key_task = menu_index;
        //    SwitchOP_flat = TRUE;
        //}

        if(Dive_Info.Status == AMB_DIVEINFO_SURF) {
            i330_key_task = menu_index;
        }

        break;

    case i330_DIVE_MODE:

        //if((Dive_Info.Status == AMB_DIVEINFO_SURF) || (Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
        if(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)
        {
            /*go to SURFACE MAIN*/
            i330_Opcode = i330_SURFACE_MODE;
            i330_MENSTAT = i330_NSM_MAIN;
            //i330_key_task = menu_index;
            i330_key_task = data_setting;
            SwitchOP_flat = FALSE;

        }

        break;

    }



}

uint8_t retdaysofmonth(uint8_t month, uint8_t year)/*year setting form 20 to 70*/
{
    const uint8_t MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint8_t day = 0;


    day = MONTHS[month-1];
    if((month ==2)&&(year%4==0)) {
        day = 29;
    }

    return day;
}



uint8_t RollingKeyNonStop(void)
{
    if(Key_U.Key_Rolling == KeyStatus_Scroll)
        return true;
    else
        return false;
}


uint8_t UpKeyShortPressed(void)
{
    if((Key_U.DataType == short_press)||(Key_U.Key_Rolling == KeyStatus_Scroll))
        return true;
    else
        return false;
}


uint8_t DownKeyShortPressed(void)
{
    if(Key_D.DataType == short_press)
        return true;
    else
        return false;
}

uint8_t UpKeyLongPressed(void)
{
    if(Key_U.DataType == long_press)
        return true;
    else
        return false;
}


uint8_t DownKeyLongPressed(void)
{
    if(Key_D.DataType == long_press)
        return true;
    else
        return false;
}

uint8_t ret12Hfrom24H(  uint8_t _24Hour, uint8_t * _12Hour, uint8_t * MidNight)
{

    /*12h or 24h format?*/
    if((_24Hour>12)&&(TimeSet12h_Format)) {
        *_12Hour = _24Hour-12;
        * MidNight = 1;
    }
    else if((_24Hour==12)&&(TimeSet12h_Format)) {
        * MidNight = 1;
        *_12Hour = _24Hour;
    }
    else if(_24Hour==0&&TimeSet12h_Format) {
        *_12Hour = 12;
        * MidNight = 0;
        //0,1...11	->1,2...12 AM
    }
    else {
        * MidNight = 0;
        *_12Hour = _24Hour;
    }

    return 0;
}


int32_t DiverTimerControl(int8_t stage)
{

    static int32_t DiverTimerCounter = 0;
    static int32_t DiverTimerCounterDiff = 0;
    static int32_t DiverTimerStartStopStamp = 0;
    static int32_t DiverTimerRunPauseStamp = 0;
    static int32_t DiverTimerForDisp_s = 0;
    static int8_t PreDiverTimerStatus = 0;       // 0: Reset,   1: Pause,    2: Run

    /*
    #define DIVE_TIMER              SystemTimers.CounterUP1_s               // start counting UP from 0 when dive starts
    #define DIVE_TIMER_Reset()      SystemTimers.CounterUP1_s=0             // call to reset Dive Timer or CounterUP1_s
    #define DIVE_TIMER_On           GUI_DiverTimerOn      // 1: to Start Dive Timer,     or 0: to Stop or Reset
    #define DIVE_TIMER_Run          GUI_DiverTimerRun     // 1: to Run Dive Timer,       or 0: to Pause
    #define DIVE_TIMER_Display      GUI_DiverTimerDisp    // 1: to Display Dive Timer,   or 0: to hide
    */

    if(stage > 0)       // ON
    {
        if(stage >=2 )  // 3 = b11:  Run
        {
            DiverTimerStartStopStamp = DIVE_TIMER;                      // No Change for Start Stamp
            //DiverTimerRunPauseStamp = DIVE_TIMER;                      // No Change for Run Stamp

            if((DiverTimerStartStopStamp - DiverTimerRunPauseStamp)>=0)
                DiverTimerCounterDiff = (DiverTimerStartStopStamp - DiverTimerRunPauseStamp);    // Counter pauses
            else
                DiverTimerCounterDiff = (DiverTimerStartStopStamp - DiverTimerStartStopStamp);    // Counter pauses

            DiverTimerForDisp_s = DiverTimerCounter + DiverTimerCounterDiff;
            PreDiverTimerStatus = 2;
        }
        else                    // 1 = b01: Pause
        {
            if(PreDiverTimerStatus != 1)
            {
                DiverTimerCounter += DiverTimerCounterDiff;
            }

            DiverTimerStartStopStamp = DIVE_TIMER;                      // No Change for Start Stamp
            DiverTimerRunPauseStamp = DIVE_TIMER;                         // Let Timer Run

            DiverTimerCounterDiff = 0;    // Counter pauses
            //DiverTimerCounter = DiverTimerCounterDiff;
            DiverTimerForDisp_s = DiverTimerCounter + DiverTimerCounterDiff;
            PreDiverTimerStatus = 1;
        }
    }
    //else                        // 0 = b00: Off
    //{
    //    DIVE_TIMER_Reset();
    //    DiverTimerStartStopStamp = 0;      // reset Start Stamp;
    //    DiverTimerRunPauseStamp = 0;       // reset Stop Stamp
    //    DiverTimerCounter = 0;             // reset Counter to 0
    //    DiverTimerCounterDiff = 0;         // reset Counter to 0
    //    DiverTimerForDisp_s = 0;           // reset DiverTimer to 0
    //    PreDiverTimerStatus = 0;           // keeps Status at 0
    //}

    return DiverTimerForDisp_s;

}


void SwitchDiveMode(NVD_DIVEMODE_t mode)
{
    if(mode == NVD_MDSCUBA) {

    }
    else if(mode == NVD_MDGAUGE) {
        DVSTAT_STAT = 0x90;
    }

    else if(mode == NVD_MDFREE) {
        DVSTAT_STAT = 0xa0;
    }
}


void GUI2EE_AlarmData(void)
{
    // GUI Variables for Alarms Menu (CC, OC, SM, Gauge-SM, Gauge)
    DEPTHAL_STAT = GUI_DEPTHAL_STAT;            // GUI settings for DEPTHAL_STAT
    DepthAlarmFT = GUI_DepthAlarmFT;            // GUI settings for DEPTHAL_FT
    DepthAlarm = GUI_DepthAlarmM;               // GUI settings for DEPTHAL_M
    DIVE_T_STAT = GUI_DIVE_T_AL_STAT;              // GUI settings for DIVE_T_STAT (Off, On, Set)
    DIVE_T_AL = GUI_DIVE_T_AL;                  // GUI settings for DIVE_T_AL
    TTS_AL_STAT = GUI_TTS_AL_STAT;              // GUI settings for TTS_AL_STAT (Off, On, Set)
    TTS_AL = GUI_TTS_AL;                        // GUI settings for TTS_AL
    DTR_AL_STAT = GUI_DTR_AL_STAT;              // GUI settings for DTR_AL_STAT (Off, On, Set)
    DTR_AL = GUI_DTR_AL;                        // GUI settings for DTR_AL
    TankP_AL_STAT = GUI_TankP_AL_STAT;          // GUI settings for TankP_AL_STAT (Off, On, Set)
    TankP_AL_PSI = GUI_TankP_AL_PSI;            // GUI settings for TankP_AL_PSI_PSI
    TankP_AL_BAR = GUI_TankP_AL_BAR;            // GUI settings for TankP_AL_BAR_BAR
    CC6P_AL_STAT = GUI_CC6P_AL_STAT;            // GUI settings for CC6P_AL_STAT (Off, On, Set)
    CC6P_AL_PSI = GUI_CC6P_AL_PSI;              // GUI settings for CC6P_AL_PSI
    CC6P_AL_BAR = GUI_CC6P_AL_BAR;              // GUI settings for CC6P_AL_BAR
    TurnP_AL_STAT = GUI_TurnP_AL_STAT;          // GUI settings for TurnP_AL_STAT (Off, On, Set)
    TurnP_AL_PSI = GUI_TurnP_AL_PSI;            // GUI settings for TurnP_AL_PSI
    TurnP_AL_BAR = GUI_TurnP_AL_BAR;            // GUI settings for TurnP_AL_BAR
    EndP_AL_STAT = GUI_EndP_AL_STAT;            // GUI settings for EndP_AL_STAT (Off, On, Set)
    EndP_AL_PSI = GUI_EndP_AL_PSI;              // GUI settings for EndP_AL_PSI
    EndP_AL_BAR = GUI_EndP_AL_BAR;              // GUI settings for EndP_AL_BAR
    SwitchP_AL_STAT = GUI_SwitchP_AL_STAT;      // GUI settings for Switch_AL_STAT (Off, On, Set)
    SwitchP_AL_PSI = GUI_SwitchP_AL_PSI;        // GUI settings for Switch_AL_PSI
    SwitchP_AL_BAR = GUI_SwitchP_AL_BAR;        // GUI settings for Switch_AL_BAR
    GF_AL_STAT = GUI_GF_AL_STAT;                // GUI settings for GF_AL_STAT(Off, On, Set)
    GF_AL = GUI_GF_AL;                          // GUI settings for GF_AL
    N2_AL_STAT = GUI_N2_STAT;                   // GUI settings for N2_AL_STAT (Off, On, Set)
    N2_AL = GUI_N2_AL;                          // GUI settings for N2_AL
    END_AL_STA = GUI_END_AL_STAT;               // GUI settings for END_AL_STAT
    END_AL_FT = GUI_END_AL_FT;                  // GUI settings for END_AL_FT
    END_AL_dM = (uint16_t)(10.0*GUI_END_AL_M);      // GUI settings for END_AL_M
    WOB_AL_STAT = GUI_WOB_AL_STAT;              // GUI settings for WOB_AL_STAT
    WOB_AL_FT = GUI_WOB_AL_FT;                  // GUI settings for WOB_AL_FT
    WOB_AL_dM = (uint16_t)(10.0*GUI_WOB_AL_M);      // GUI settings for WOB_AL_M
    ICD_AL_STAT = GUI_ICD_AL_STAT;              // GUI settings for ICD_AL_STAT
    NARCOTIC_AL_SW = GUI_O2_NARCOTIC_AL_STAT;   // GUI settings for NARCOTIC_AL_SW
}

void EE2GUI_AlarmData(void)
{
    // GUI Variables for Alarms Menu (CC, OC, SM, Gauge-SM, Gauge)
    GUI_DEPTHAL_STAT = DEPTHAL_STAT;            // GUI settings for DEPTHAL_STAT
    GUI_DepthAlarmFT = DepthAlarmFT;            // GUI settings for DEPTHAL_FT
    GUI_DepthAlarmM = DepthAlarm;               // GUI settings for DEPTHAL_M
    GUI_DIVE_T_AL_STAT = DIVE_T_AL_STAT;              // GUI settings for DIVE_T_STAT (Off, On, Set)
    GUI_DIVE_T_AL = DIVE_T_AL;                  // GUI settings for DIVE_T_AL
    GUI_TTS_AL_STAT = TTS_AL_STAT;              // GUI settings for TTS_AL_STAT (Off, On, Set)
    GUI_TTS_AL = TTS_AL;                        // GUI settings for TTS_AL
    GUI_DTR_AL_STAT = DTR_AL_STAT;              // GUI settings for DTR_AL_STAT (Off, On, Set)
    GUI_DTR_AL = DTR_AL;                        // GUI settings for DTR_AL
    GUI_TankP_AL_STAT = TankP_AL_STAT;          // GUI settings for TankP_AL_STAT (Off, On, Set)
    GUI_TankP_AL_PSI = TankP_AL_PSI;            // GUI settings for TankP_AL_PSI_PSI
    GUI_TankP_AL_BAR = TankP_AL_BAR;            // GUI settings for TankP_AL_BAR_BAR
    GUI_CC6P_AL_STAT = CC6P_AL_STAT;            // GUI settings for CC6P_AL_STAT (Off, On, Set)
    GUI_CC6P_AL_PSI = CC6P_AL_PSI;              // GUI settings for CC6P_AL_PSI
    GUI_CC6P_AL_BAR = CC6P_AL_BAR;              // GUI settings for CC6P_AL_BAR
    GUI_TurnP_AL_STAT = TurnP_AL_STAT;          // GUI settings for TurnP_AL_STAT (Off, On, Set)
    GUI_TurnP_AL_PSI = TurnP_AL_PSI;            // GUI settings for TurnP_AL_PSI
    GUI_TurnP_AL_BAR = TurnP_AL_BAR;            // GUI settings for TurnP_AL_BAR
    GUI_EndP_AL_STAT = EndP_AL_STAT;            // GUI settings for EndP_AL_STAT (Off, On, Set)
    GUI_EndP_AL_PSI = EndP_AL_PSI;              // GUI settings for EndP_AL_PSI
    GUI_EndP_AL_BAR = EndP_AL_BAR;              // GUI settings for EndP_AL_BAR
    GUI_SwitchP_AL_STAT = SwitchP_AL_STAT;      // GUI settings for Switch_AL_STAT (Off, On, Set)
    GUI_SwitchP_AL_PSI = SwitchP_AL_PSI;        // GUI settings for Switch_AL_PSI
    GUI_SwitchP_AL_BAR = SwitchP_AL_BAR;        // GUI settings for Switch_AL_BAR
    GUI_GF_AL_STAT = GF_AL_STAT;                // GUI settings for GF_AL_STAT(Off, On, Set)
    GUI_GF_AL = GF_AL;                          // GUI settings for GF_AL
    GUI_N2_STAT = N2_AL_STAT;                   // GUI settings for N2_AL_STAT (Off, On, Set)
    GUI_N2_AL = N2_AL;                          // GUI settings for N2_AL
    GUI_END_AL_STAT = END_AL_STA;               // GUI settings for END_AL_STAT
    GUI_END_AL_FT = END_AL_FT;                  // GUI settings for END_AL_FT
    GUI_END_AL_M = END_AL_M;                    // GUI settings for END_AL_M
    GUI_WOB_AL_STAT = WOB_AL_STAT;              // GUI settings for WOB_AL_STAT
    GUI_WOB_AL_FT = WOB_AL_FT;                  // GUI settings for WOB_AL_FT
    GUI_WOB_AL_M = WOB_AL_M;                    // GUI settings for WOB_AL_M
    GUI_ICD_AL_STAT = ICD_AL_STAT;              // GUI settings for ICD_AL_STAT
}

#endif

void GUI2EE_LogData(void)
{

}


void UpdateGasStatus(void)
{
    uint8_t i;

    GUI_LANG_Select = LANG_Select;					// GUI Settings for LANG_Select
    GUI_SWITCH_LCD_Flip = (NVD_status_t)SWITCH_LCD_Flip;			// GUI settings for LCD_Flip

    if(CC_MODE)
    {
        GUI_SetPoints_Gas_CC[1] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas1;     // 1: CC-1 ON;  0: CC-1 OFF
        GUI_SetPoints_Gas_CC[2] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas2;     // 1: CC-2 ON;  0: CC-2 OFF
        GUI_SetPoints_Gas_CC[3] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas3;     // 1: CC-3 ON;  0: CC-3 OFF
        GUI_SetPoints_Gas_CC[4] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas4;     // 1: CC-4 ON;  0: CC-4 OFF
        GUI_SetPoints_Gas_CC[5] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas5;     // 1: CC-5 ON;  0: CC-5 OFF
        GUI_SetPoints_Gas_CC[6] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas6;     // 1: CC-6 ON;  0: CC-6 OFF
        //CURRENT_TANK_NUM = CURRENT_TANK_NUM_CC;
    } else if(OC_MODE) {
        GUI_SetPoints_Gas_OC[1] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas1;  // 1: OC-1 ON;  0: OC-1 OFF
        GUI_SetPoints_Gas_OC[2] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas2;  // 1: OC-2 ON;  0: OC-2 OFF
        GUI_SetPoints_Gas_OC[3] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas3;  // 1: OC-3 ON;  0: OC-3 OFF
        GUI_SetPoints_Gas_OC[4] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas4;  // 1: OC-4 ON;  0: OC-4 OFF
        GUI_SetPoints_Gas_OC[5] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas5;  // 1: OC-5 ON;  0: OC-5 OFF
        GUI_SetPoints_Gas_OC[6] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas6;  // 1: OC-6 ON;  0: OC-6 OFF
        //CURRENT_TANK_NUM = CURRENT_TANK_NUM_OC;
    } else if(SM_MODE) {
        GUI_SetPoints_Gas_SM[1] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas1;  // 1: SM-1 ON;  0: SM-1 OFF
        GUI_SetPoints_Gas_SM[2] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas2;  // 1: SM-2 ON;  0: SM-2 OFF
        GUI_SetPoints_Gas_SM[3] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas3;  // 1: SM-3 ON;  0: SM-3 OFF
        GUI_SetPoints_Gas_SM[4] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas4;  // 1: SM-4 ON;  0: SM-4 OFF
        GUI_SetPoints_Gas_SM[5] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas5;  // 1: SM-5 ON;  0: SM-5 OFF
        GUI_SetPoints_Gas_SM[6] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas6;  // 1: SM-6 ON;  0: SM-6 OFF
        //CURRENT_TANK_NUM = CURRENT_TANK_NUM_SM;
    } else if(BO_MODE) {
        GUI_SetPoints_Gas_BO[1] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas1;  // 1: BO-1 ON;  0: BO-1 OFF
        GUI_SetPoints_Gas_BO[2] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas2;  // 1: BO-2 ON;  0: BO-2 OFF
        GUI_SetPoints_Gas_BO[3] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas3;  // 1: BO-3 ON;  0: BO-3 OFF
        GUI_SetPoints_Gas_BO[4] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas4;  // 1: BO-4 ON;  0: BO-4 OFF
        GUI_SetPoints_Gas_BO[5] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas5;  // 1: BO-5 ON;  0: BO-5 OFF
        GUI_SetPoints_Gas_BO[6] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas6;  // 1: BO-6 ON;  0: BO-6 OFF
        //CURRENT_TANK_NUM = CURRENT_TANK_NUM_BO;
    }

    for(i=1; i<=6; i++)
    {
        if(CC_MODE) {
            GUI_NumOfTMT_Gas_CC[i]    = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[i];  // CC-x GASTMT
            GUI_FO2_Gas_CC[i]      = TRIMIX_Set.CC_FO2[i];      // CC-x FO2/000
            GUI_FHe_Gas_CC[i]      = TRIMIX_Set.CC_FHe[i];      // CC-x 000/FHe
        } else if(OC_MODE) {
            GUI_NumOfTMT_Gas_OC[i] = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[i];  // OC-x GASTMT
            GUI_FO2_Gas_OC[i]      = TRIMIX_Set.OC_FO2[i];      // OC-x FO2/000
            GUI_FHe_Gas_OC[i]      = TRIMIX_Set.OC_FHe[i];      // OC-x 000/FHe
        } else if(SM_MODE) {
            GUI_NumOfTMT_Gas_SM[i] = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[i];  // SM-x GASTMT
            GUI_FO2_Gas_SM[i]      = TRIMIX_Set.SM_FO2[i];      // SM-x FO2/000
            GUI_FHe_Gas_SM[i]      = TRIMIX_Set.SM_FHe[i];      // SM-x 000/FHe
        } else if(BO_MODE) {
            GUI_NumOfTMT_Gas_BO[i] = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[i];  // BO-x GASTMT
            GUI_FO2_Gas_BO[i]      = TRIMIX_Set.BO_FO2[i];      // BO-x FO2/000
            GUI_FHe_Gas_BO[i]      = TRIMIX_Set.BO_FHe[i];      // BO-x 000/FHe
        }
    }
}


uint8_t FindGasNumOfDiveMode(NVD_DIVEMODE_t mode)
{
    switch(mode)
    {
    case NVD_MDCC:
        return TRIMIX_Set.CurrGasNumber_CC;
        break;
    case NVD_MDOC:
        return TRIMIX_Set.CurrGasNumber_OC;
        break;
    case NVD_MDSM:
        return TRIMIX_Set.CurrGasNumber_SM;
        break;
    case NVD_MDGSM:
        return TRIMIX_Set.CurrTMT_Number_GSM;
        break;
    case NVD_MDGAUGE:
        return TRIMIX_Set.CurrTMT_Number_GAUGE;
        break;
    case NVD_MDBO:
        return TRIMIX_Set.CurrGasNumber_BO;
        break;
    default:
        return 0;
        break;
    }
}

uint8_t FindFO2OfDiveMode(NVD_DIVEMODE_t mode)
{
    switch(mode)
    {
    case NVD_MDCC:
        return TRIMIX_Set.CC_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDOC:
        return TRIMIX_Set.OC_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDSM:
        return TRIMIX_Set.SM_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGSM:
        return TRIMIX_Set.GSM_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGAUGE:
        return TRIMIX_Set.GAUGE_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDBO:
        return TRIMIX_Set.BO_FO2[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    default:
        return 0;
        break;
    }
}

uint8_t FindFO2OfGasNum(uint8_t num)
{
    switch(DIVE_MODE)
    {
    case NVD_MDCC:
        return TRIMIX_Set.CC_FO2[num];
        break;
    case NVD_MDOC:
        return TRIMIX_Set.OC_FO2[num];
        break;
    case NVD_MDSM:
        return TRIMIX_Set.SM_FO2[num];
        break;
    case NVD_MDGSM:
        return TRIMIX_Set.GSM_FO2[num];
        break;
    case NVD_MDGAUGE:
        return TRIMIX_Set.GAUGE_FO2[num];
        break;
    case NVD_MDBO:
        return TRIMIX_Set.BO_FO2[num];
        break;
    default:
        return 0;
        break;
    }
}

uint8_t FindFHeOfDiveMode(NVD_DIVEMODE_t mode)
{
    switch(mode)
    {
    case NVD_MDCC:
        return TRIMIX_Set.CC_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDOC:
        return TRIMIX_Set.OC_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDSM:
        return TRIMIX_Set.SM_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGSM:
        return TRIMIX_Set.GSM_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGAUGE:
        return TRIMIX_Set.GAUGE_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDBO:
        return TRIMIX_Set.BO_FHe[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    default:
        return 0;
        break;
    }
}

uint8_t FindPO2OfDiveMode(NVD_DIVEMODE_t mode)
{
    switch(mode)
    {
    case NVD_MDCC:
        return TRIMIX_Set.CC_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDOC:
        return TRIMIX_Set.OC_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDSM:
        return TRIMIX_Set.SM_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGSM:
        return TRIMIX_Set.GSM_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDGAUGE:
        return TRIMIX_Set.GAUGE_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    case NVD_MDBO:
        return TRIMIX_Set.BO_PO2A[FindGasNumOfDiveMode(DIVE_MODE)];
        break;
    default:
        return 0;
        break;
    }
}

/*Handle Dilutant PO2 content*/
float DilPO2Val(void)
{
    float retVal = 0.0f;
    /*PO2 value*/
    retVal = 0.01 * (float)SetGasGetFO2(FindGasNumOfDiveMode(DIVE_MODE)) *(((((float)GasSwitchGetPO2A()/(float)SetGasGetFO2(FindGasNumOfDiveMode(DIVE_MODE)))-1.0)*33.0)+33.0)/33.0;

    return retVal;
}
/*****************************************************************************************************
*
*
*       Only use inside of OPCODE_Matrix( ) function (CANNOT use outside of OPCODE_Matrix function)
*
*
*****************************************************************************************************/
bool StaySameOpcodeForNSec(uint8_t Sec)
{
    static int32_t DelayTimeStamp = -1;
    static int32_t EndDelayTimeStamp = -1;

    DelayTimeStamp = MonotonicClock_s;

    if(Sec == 0)
    {
        EndDelayTimeStamp = 0;  // force to reset and out of the loop
    }

    if(EndDelayTimeStamp < 0)
    {
        EndDelayTimeStamp = MonotonicClock_s + Sec;
        return 1;               // return true to keep staying at the same Opcode
    }
    else
    {
        if(DelayTimeStamp < EndDelayTimeStamp)
        {
            return 1;           // return true to keep staying at the same Opcode
        }
        else
        {
            EndDelayTimeStamp = -1;	// reset back to -1, for the next run
            return 0;                   // reutrn false to stop staying at the same Opcode
        }
    }
}

/*******************************************************************************

    Refresh GUI to display new SET GAS information according to TRIMIX Data

*******************************************************************************/
void Update_GUI_GasInfo(void)
{
    uint8_t i = 0;
    if(CC_MODE)
    {
        GUI_SetPoints_Gas_CC[1] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas1;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_CC[2] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas2;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_CC[3] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas3;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_CC[4] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas4;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_CC[5] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas5;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_CC[6] = (NVD_status_t)TRIMIX_Set.CC_Active.Gas6;		// 1: Gas ON;	0: Gas OFF
        for(i=0; i<=MAX_TOTAL_TANK_NUM; i++)
        {
            GUI_FO2_Gas_CC[i]        = TRIMIX_Set.CC_FO2[i];
            GUI_FHe_Gas_CC[i]        = TRIMIX_Set.CC_FHe[i];
            GUI_NumOfTMT_Gas_CC[i]   = (TMT_NUM_t)TRIMIX_Set.CC_GASTMT[i];
        }
    }
    else if(OC_MODE)
    {
        GUI_SetPoints_Gas_OC[1] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas1;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_OC[2] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas2;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_OC[3] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas3;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_OC[4] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas4;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_OC[5] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas5;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_OC[6] = (NVD_status_t)TRIMIX_Set.OC_Active.Gas6;		// 1: Gas ON;	0: Gas OFF
        for(i=0; i<=MAX_TOTAL_TANK_NUM; i++)
        {
            GUI_FO2_Gas_OC[i]        = TRIMIX_Set.OC_FO2[i];
            GUI_FHe_Gas_OC[i]        = TRIMIX_Set.OC_FHe[i];
            GUI_NumOfTMT_Gas_OC[i]   = (TMT_NUM_t)TRIMIX_Set.OC_GASTMT[i];
        }
    }
    else if(SM_MODE)
    {
        GUI_SetPoints_Gas_SM[1] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas1;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_SM[2] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas2;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_SM[3] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas3;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_SM[4] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas4;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_SM[5] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas5;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_SM[6] = (NVD_status_t)TRIMIX_Set.SM_Active.Gas6;		// 1: Gas ON;	0: Gas OFF
        for(i=0; i<=MAX_TOTAL_TANK_NUM; i++)
        {
            GUI_FO2_Gas_SM[i]        = TRIMIX_Set.SM_FO2[i];
            GUI_FHe_Gas_SM[i]        = TRIMIX_Set.SM_FHe[i];
            GUI_NumOfTMT_Gas_SM[i]   = (TMT_NUM_t)TRIMIX_Set.SM_GASTMT[i];
        }
    }
    else if(BO_MODE)
    {
        GUI_SetPoints_Gas_BO[1] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas1;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_BO[2] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas2;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_BO[3] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas3;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_BO[4] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas4;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_BO[5] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas5;		// 1: Gas ON;	0: Gas OFF
        GUI_SetPoints_Gas_BO[6] = (NVD_status_t)TRIMIX_Set.BO_Active.Gas6;		// 1: Gas ON;	0: Gas OFF
        for(i=0; i<=MAX_TOTAL_TANK_NUM; i++)
        {
            GUI_FO2_Gas_BO[i]        = TRIMIX_Set.BO_FO2[i];
            GUI_FHe_Gas_BO[i]        = TRIMIX_Set.BO_FHe[i];
            GUI_NumOfTMT_Gas_BO[i]   = (TMT_NUM_t)TRIMIX_Set.BO_GASTMT[i];
        }
    }

}

uint8_t Current_Tank_Num(void)
{
    if(CC_MODE)
    {
        return TRIMIX_Set.CurrGasNumber_CC;
    }
    else if(OC_MODE)
    {
        return TRIMIX_Set.CurrGasNumber_OC;
    }
    else if(SM_MODE)
    {
        return TRIMIX_Set.CurrGasNumber_SM;
    }
    else if(GSM_MODE)
    {
        return TRIMIX_Set.CurrTMT_Number_GSM;
    }
    else if(GAUGE_MODE)
    {
        return TRIMIX_Set.CurrTMT_Number_GAUGE;
    }
    else if(BO_MODE)
    {
        return TRIMIX_Set.CurrGasNumber_BO;
    }
    else
        return 0;
}

TMT_NUM_t Current_TMT_Num(void)
{
    TMT_NUM_t n = TMT_OFF;

    if(CC_MODE)
    {
        n = TRIMIX_Set.CC_GASTMT[TRIMIX_Set.CurrGasNumber_CC];
    }
    else if(OC_MODE)
    {
        n = TRIMIX_Set.OC_GASTMT[TRIMIX_Set.CurrGasNumber_OC];
    }
    else if(SM_MODE)
    {
        n = TRIMIX_Set.SM_GASTMT[TRIMIX_Set.CurrGasNumber_SM];
    }
    else if(GSM_MODE)
    {
        n = TRIMIX_Set.CurrTMT_Number_GSM;
    }
    else if(GAUGE_MODE)
    {
        n = TRIMIX_Set.CurrTMT_Number_GAUGE;
    }
    else if(BO_MODE)
    {
        n = TRIMIX_Set.BO_GASTMT[TRIMIX_Set.CurrGasNumber_BO];
    }

    return n;
}

uint8_t find_CC_SP_Current(void)
{
    if(SCUBA_Set.SP_Switch == LOW_SP)
        SCUBA_Set.SP_Current = SCUBA_Set.SP_SetLow;
    else if(SCUBA_Set.SP_Switch == HIGH_SP)
        SCUBA_Set.SP_Current = SCUBA_Set.SP_SetHigh;
    else
        SCUBA_Set.SP_Current = SCUBA_Set.SP_SetCustomer;
    return SCUBA_Set.SP_Current;
}

DSX_OPCODE_t ReturnToDiveMain(void)
{
    if(CC_MODE)
        return DIVE_CC_MAIN;
    else if(OC_MODE||BO_MODE)
        return DIVE_OC_MAIN;
    else if(SM_MODE)
        return DIVE_SM_MAIN;
    else if(GSM_MODE)
        return DIVE_GSM_MAIN;
    else if(GAUGE_MODE)
        return DIVE_GAUGE_MAIN;
    else
        return S2_SURFACE_MAIN;      // should never come to here, just a catch
}

DSX_OPCODE_t ReturnToSurfMain(void)
{
    if(CC_MODE||BO_MODE)
        return S2_SURFACE_MAIN;
    else if(OC_MODE)
        return S2_SURFACE_MAIN;
    else if(SM_MODE)
        return SURFACE_SM_MAIN;
    else if(GSM_MODE)
        return SURFACE_GSM_MAIN;
    else if(GAUGE_MODE)
        return SURFACE_GAUGE_MAIN;
    else
        return S2_SURFACE_MAIN;      // should never come to here, just a catch
}

DSX_OPCODE_t ReturnToMainPage(void)
{
    DSX_OPCODE_t ret;
    if((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
    {
        ret = ReturnToDiveMain();
    }
    else
    {
        ret = ReturnToSurfMain();
    }

    return ret;
}

void RestoreBrightnessAfterBattCharging(void)
{
    if(pre_DSX_Opcode == B1_BATT_CHARGE)
    {
        SystemStatus.user_GUI_timestamp = MonotonicClock_s;
        SystemSupplyMonitor.PreBattery_Percentage = 10;
        SystemStatus.backlight_on_req = true;
        //GUI_SetBkColor(GUI_BLACK);
        //GUI_Clear();
    }
}

/********************************************************************************************************
  GasSwitchPO2_Stat( ) is to determine the PO2 Stat of the Gas about to Swtich to (in GAS SWITCH menu)

    GAS_SWITCH_PO2_OK = 0x0,      // 0.21 <= PO2 <= 1.60
    GAS_SWITCH_PO2_TOO_LOW,       // PO2 < 0.17
    GAS_SWITCH_PO2_HYPOXIC,       // 0.17 <= PO2 < 0.21
    GAS_SWITCH_PO2_TOO_HIGH       // PO2 > 1.60

*********************************************************************************************************/
GAS_SWITCH_PO2_STAT_t GasSwitchPO2_Stat(void)
{
    float PO2GetValue = 0.0;

    PO2GetValue = 0.01 * SetGasGetFO2(GUI_TankN_Linked) * (( Pamb + fDepthFt * SaltEqDensityFactor() ) / 33.0);

    if(OC_MODE||BO_MODE||SM_MODE)
    {
        if(PO2GetValue < 0.17)
            return GAS_SWITCH_PO2_TOO_LOW;
        else if((PO2GetValue >= 0.17)&&(PO2GetValue < 0.21))
            return GAS_SWITCH_PO2_HYPOXIC;
        else if(PO2GetValue > 1.6)
            return GAS_SWITCH_PO2_TOO_HIGH;
        else
            return GAS_SWITCH_PO2_OK;
    }
    else
        return GAS_SWITCH_PO2_OK;
}


TMT_NUM_t SetGases_TMT_Num(TANK_NUM_t n)
{
    TMT_NUM_t t;

    if(CC_MODE)
    {
        t = TRIMIX_Set.CC_GASTMT[n];
    }
    else if(OC_MODE)
    {
        t = TRIMIX_Set.OC_GASTMT[n];
    }
    else if(SM_MODE)
    {
        t = TRIMIX_Set.SM_GASTMT[n];
    }
    else if(BO_MODE)
    {
        t = TRIMIX_Set.BO_GASTMT[n];
    }

    return t;
}

/*******************************************************************************

    NVD_status_t CheckIfGasEnabled(uint8_t gas)

    to return the On/Off status of the GUI highlighted Gas Tank

*******************************************************************************/
NVD_status_t CheckIfGasEnabled(uint8_t gas)
{
    NVD_status_t state = NVD_OFF;

    if(CC_MODE)
    {
        switch(gas)
        {
        case 1:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas1;
            break;
        case 2:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas2;
            break;
        case 3:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas3;
            break;
        case 4:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas4;
            break;
        case 5:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas5;
            break;
        case 6:
            state = (NVD_status_t)TRIMIX_Set.CC_Active.Gas6;
            break;
        }
    }
    else if(OC_MODE)
    {
        switch(gas)
        {
        case 1:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas1;
            break;
        case 2:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas2;
            break;
        case 3:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas3;
            break;
        case 4:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas4;
            break;
        case 5:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas5;
            break;
        case 6:
            state = (NVD_status_t)TRIMIX_Set.OC_Active.Gas6;
            break;
        }
    }
    else if(SM_MODE)
    {
        switch(gas)
        {
        case 1:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas1;
            break;
        case 2:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas2;
            break;
        case 3:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas3;
            break;
        case 4:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas4;
            break;
        case 5:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas5;
            break;
        case 6:
            state = (NVD_status_t)TRIMIX_Set.SM_Active.Gas6;
            break;
        }
    }
    else if(BO_MODE)
    {
        switch(gas)
        {
        case 1:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas1;
            break;
        case 2:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas2;
            break;
        case 3:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas3;
            break;
        case 4:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas4;
            break;
        case 5:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas5;
            break;
        case 6:
            state = (NVD_status_t)TRIMIX_Set.BO_Active.Gas6;
            break;
        }
    }

    return state;
}

void ToRestoreBrightness(void)
{
    if(SystemStatus.SystemPowerMode == SYS_ACTIVE)
    {
        SystemStatus.backlight_on_req = true;
        SystemStatus.backlight_on = BACKLIGHT_DIM; // starts as from a DIM condition, so the BacklightManager can correct the Brightness
    }
}

void ResetButtonMemory(void)
{
    Key_L.Key_Status = 0;
    Key_L.Timer = 0;
    Key_L.Key_Rolling = 0;
    Key_L.DataType = nothing;
    Key_L.ResetTimer = 0;
    Key_L.Cnt = 0;

    Key_M.Key_Status = 0;
    Key_M.Timer = 0;
    Key_M.Key_Rolling = 0;
    Key_M.DataType = nothing;
    Key_M.ResetTimer = 0;
    Key_M.Cnt = 0;

    Key_R.Key_Status = 0;
    Key_R.Timer = 0;
    Key_R.Key_Rolling = 0;
    Key_R.DataType = nothing;
    Key_R.ResetTimer = 0;
    Key_R.Cnt = 0;
}

bool REGISTER_Done(void)        // R1006 Added and orgnaized old similar code from then on
{
    if(DEV_Rec.Reg.Reg_KEY == PASSCODE_ON)
        return true;
    else
        return false;
}