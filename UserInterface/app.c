/*******************************************************************************
 * @file        : app.c
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

void RedefineWaterLevel(void);

bool BLE_AcessInitDone = false;
bool SwitchFO2_InFlashing = false;      // when AlarmID == SwitchFO2 or MaxAlarm but in turn of flashing GAS SWITCH Message
char DSX_Opcode_String[32] = {0};
DSX_OPCODE_t DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
DSX_OPCODE_t pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;
uint8_t AlarmID = ALARM_MAX;
uint8_t SurfaceFirstPageInitFlag;
uint32_t GUI_ON_DelayCtr=0;       // Time Delay for displaying WELCOME S1 or Main Surf Page for a controlled time (8: 1 second / 16: 2 seconds / 40: 5 seconds, etc.
void Text_GUI(void);
extern STRING_LANG StrLang_Select[];
void ImmediateStopAlarmCheck(void);
bool NewDayInitDone = false;            // to complete NewDayInit before Dive
bool DataRetainDone = false;            // to complete DataRetain before Dive

void UI_Every125Exec(void)
{
    DSX_Button_Handle();
    DSX_OpcodeTask();
    DSX_IdleControl();
}
static uint8_t GUI_Init_Flag = 1;
/*
static const GUI_POINT Arrow[] = {
    { 0, 0},
    {25, -25},
    {0, 25},
    {-25, -25}
};
*/
#define EC_CAL      1

void UI_App (void)
{
#if 1
    //static bool caldone = false;
    //char _DispStringTemp[100];

    /*********************************************************************************************************************************************
    *
    *   Toto handle the GUI Change Request from DiverLog+ with all kinds of condition changes
    *
    *   Make the system return to Surface Main page after DiveLog+ finishing updates and disconnecting Bluetooth
    *
    *********************************************************************************************************************************************/
    if( ( SystemStatus.BLE_status != BLE_HDL_CONNECT ) && ( SystemStatus.BLE_last_status == BLE_HDL_CONNECT ) )
    {
        GUI_Init_Flag = 1;
    }
    SystemStatus.BLE_last_status = SystemStatus.BLE_status;

    if(GUI_Init_Flag == 1)
    {
        // DeInit/Init LCD and GUI after critical setting changes occur
        GUI_DISPLAY_Update();

        GUI_Init_Flag = 0;

        if(SWITCH_LCD_Flip)
        {
            AsssignedCoordinated(1); //Rotate 180
            // GUI_SetOrientation(GUI_ROTATION_180);
        }
        else
        {
            AsssignedCoordinated(0); //Default
            // GUI_SetOrientation(GUI_ROTATION_0);
        }

        if(BRIGHTNESS_LV == 0)
            BRIGHTNESS_LV = 10;
        else if(BRIGHTNESS_LV > 100)
            Backlight_Set(AutoBRIGHTNESS);
        else
        {
            //Backlight_Set(BRIGHTNESS_LV); DO NOT USE THIS LINE HERE, need to check Battery Condition before doing this
            SystemStatus.backlight_on = BACKLIGHT_DIM;  // force BacklightManager( ) to handle brightness, with consideration of Battery condition
            SystemStatus.backlight_on_req = true;
        }

        GUI_SetTextMode(GUI_TM_NORMAL);
        /*extra initialize*/
        GFHighSettingValue = SCUBA_Set.TEC_GF_Hi;
        // ----------------added by YeuShyr, 2022 04 22 to check out-of-boundary----------------
        if(SCUBA_Set.Consv.ConservSportMode < CONSV_SPORT_LOW)
            SCUBA_Set.Consv.ConservSportMode = CONSV_SPORT_LOW;
        if(SCUBA_Set.Consv.ConservSportMode > CONSV_SPORT_HIGH)
            SCUBA_Set.Consv.ConservSportMode = CONSV_SPORT_HIGH;
        GUI_CONSV_Sport_Switch = (CONSV_Sport_t)SCUBA_Set.Consv.ConservSportMode;
        GUI_CONSV_Switch = (CONSV_TecSport_t)SCUBA_Set.Consv.ConservMode;
        // ----------------added by YeuShyr, 2022 04 22 ----------------------------------------
        GUI_DIVE_Mode = DIVE_MODE;
        if( !REGISTER_Done() )
        {
            DSX_Opcode = REGISTER_SCREEN;

            pre_DSX_Opcode = W1_WELCOME;
        }
        else if( (DSX_Opcode != W1_WELCOME) )
        {
            if((CC_MODE||BO_MODE) && ((DSX_Opcode!=S2_SURFACE_MAIN)))
                DSX_Opcode = S2_SURFACE_MAIN;
            else if(OC_MODE && (DSX_Opcode!=S2_SURFACE_MAIN))
                DSX_Opcode = S2_SURFACE_MAIN;
            else if(SM_MODE && (DSX_Opcode!=SURFACE_SM_MAIN))
                DSX_Opcode = SURFACE_SM_MAIN;
            else if(GSM_MODE && (DSX_Opcode!=S2_SURFACE_MAIN))
                DSX_Opcode = S2_SURFACE_MAIN;
            else if( GAUGE_MODE && (DSX_Opcode!=SURFACE_GAUGE_MAIN))
                DSX_Opcode = SURFACE_GAUGE_MAIN;

            pre_DSX_Opcode = W1_WELCOME;
        }
    }
    else
    {
        /*
        After setting up once start/wake up
        -> Do the sequence every time this UI call
        Make the flashing state 500 ms
        */
        if((KeyStatus_Idle != Key_L.Key_Status)||(KeyStatus_Idle != Key_M.Key_Status)||(KeyStatus_Idle != Key_R.Key_Status))
        {
            /*flashing is Disabled while Short Press on L, M buttons and Scrolling M buttons*/
            FlashingState_u8 = FLASHING_STATE_OFF;
        }
        else
        {
            /*Alternately change the status to flashing every 500ms between FLASHING_STATE_ON~FLASHING_STATE_OFF*/
            FlashingState_u8 = ~FlashingState_u8;
        }
    }

    static uint8_t GUI_Phase = 0;
    static uint8_t GUI_PrePhase = 0;

    if(CheckTheBluetoothPasscodeDisplay())
    {
        GUI_Phase = 10;
        DSX_Opcode = DEVICE_BLUETOOTH_PASSCODE;
        if(GUI_PrePhase != GUI_Phase)
            ToRestoreBrightness();
    }
    else if( (SystemStatus.ShowDiag == true)&&( DEV_Rec.SystemErrorWarningBits.AllBits != 0) )   // show ERRx GUI pages when (ShowDiag==true) AND (Demo_On==false)      // Moved to the top of registration GUI from R1006
    {
        int32_t a, b;

        GUI_Phase = 20;

        Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
        if(SystemSupplyMonitor.Battery_Percentage <= BAT_NO_OPERATE_PERCENTAGE)
            DEV_Rec.SystemErrorWarningBits.LowBattery = true;
        else
            DEV_Rec.SystemErrorWarningBits.LowBattery = false;

        if( (DEV_Rec.SystemErrorWarningBits.LowBattery == true)
                ||(DEV_Rec.SystemErrorWarningBits.FuelGauge == true) )
            DSX_Opcode = E7_ERROR_BATTERY_TOO_LOW;
        else if(DEV_Rec.SystemErrorWarningBits.SensorPress == true)
            DSX_Opcode = E1_ERROR_DEPTH_SENSOR;
        else if(DEV_Rec.SystemErrorWarningBits.Dive10h == true)
            DSX_Opcode = E6_ERROR_DIVE_10HR;
        else if(DEV_Rec.SystemErrorWarningBits.LastDive == true)
            DSX_Opcode = E10_ERROR_DIVE_NOT_COMPLETE;
        else if(DEV_Rec.SystemErrorWarningBits.Altitude == true)
            DSX_Opcode = E12_ERROR_ALTITUDE;
        else if(DEV_Rec.SystemErrorWarningBits.Eeprom == true)
            DSX_Opcode = E2_ERROR_EEPROM;
        else if(DEV_Rec.SystemErrorWarningBits.Flash == true)
            DSX_Opcode = E3_ERROR_EXFLASH;
        else if( (DEV_Rec.SystemErrorWarningBits.Calibration == true)
                 ||(DEV_Rec.SystemErrorWarningBits.NotYetCali == true) )
            DSX_Opcode = E4_ERROR_CALIBRATION;
        else if(DEV_Rec.SystemErrorWarningBits.Bluetooth == true)
            DSX_Opcode = E8_ERROR_BLUETOOTH;
        else if(DEV_Rec.SystemErrorWarningBits.Compass == true)
            DSX_Opcode = E9_ERROR_COMPASS;
        else if(DEV_Rec.SystemErrorWarningBits.Gps == true)
            DSX_Opcode = E10_ERROR_GPS;
        else if(DEV_Rec.SystemErrorWarningBits.O2Analyzer == true)
            DSX_Opcode = E11_ERROR_O2_SENSOR;
        else if(DEV_Rec.SystemErrorWarningBits.SensorTemp == true)
            DSX_Opcode = E1_ERROR_DEPTH_SENSOR;
        else if(DEV_Rec.SystemErrorWarningBits.CheckSum == true)
            DSX_Opcode = E5_ERROR_CHECKSUM;

        a = SystemStatus.user_act_timestamp;
        b = MonotonicClock_s;

        // Allow button pressing to stop showing ERRx GUI messages
        if((a - b) >= 0)
        {
            GUI_Phase = 21;
            SystemStatus.ShowDiag = false;     // stop showing ERR GUIs
            GUI_Clear();
            DSX_Opcode = S2_SURFACE_MAIN;
        }
    }
    else if(!REGISTER_Done())
    {
        GUI_Phase = 30;
        DSX_Opcode = REGISTER_SCREEN;
        if(GUI_PrePhase != GUI_Phase)
            ToRestoreBrightness();
    }
    else if(BLUETOOTH_DOWNLOAD_DATA_InProgress())
    {
        GUI_Phase = 40;
        ResetButtonMemory();    // blocking any button input during the BLE Download, immediately after BLE_Connection is formed
        if(GUI_PrePhase != GUI_Phase)
        {  
            ToRestoreBrightness();
            SystemStatus.user_GUI_timestamp = MonotonicClock_s;
        }
        
        if( ( MonotonicClock_s - SystemStatus.user_GUI_timestamp ) > 3 )        // start to display BLUETOOTH_DOWNLOAD_DATA GUI after several seconds of delay
            DSX_Opcode = DEVICE_BLUETOOTH_DOWNLOAD_DATA;
    }
    else if( BatteryCharging() && (DSX_Opcode != B1_BATT_CHARGE) && ((pre_DSX_Opcode == 8192)||(pre_DSX_Opcode < 0)) )
    {
        GUI_Phase = 50;
        DSX_Opcode = B1_BATT_CHARGE;
    }
    else if( BatteryCharging() && ShowChargingAfterNSec(10)
             && (pre_DSX_Opcode != B1_BATT_CHARGE) && (SystemStatus.BLE_status != BLE_HDL_CONNECT) )
    {
        GUI_Phase = 60;
        if((DSX_Opcode != B1_BATT_CHARGE)||(pre_DSX_Opcode != B1_BATT_CHARGE))
            DSX_Opcode = B1_BATT_CHARGE;
    }
    else
    {
        GUI_Phase = 70;
        if(SystemStatus.BLE_status == BLE_HDL_CONNECT)
        {
            GUI_Phase = 71;
            // when BLE in connected, system gets out of B1_BATT_CHARGE GUI, and enter to Surface Main page
            if((DSX_Opcode == B1_BATT_CHARGE)&&(pre_DSX_Opcode == B1_BATT_CHARGE))
            {
                DSX_Opcode = S2_SURFACE_MAIN;
            }
        }

        if(GUI_PrePhase != GUI_Phase)
            ToRestoreBrightness();

        DSX_OpcodeSwitch();
    }

    GUI_PrePhase = GUI_Phase;

    Decode_DSX_Data();      // To display GUI, also including the test version Text_GUI();

#endif

}


/*******************************************************************************
    NewDayInit(void)

    Needed for every time wakeup from Sleep or Deep Sleep Mode, to NewDay
*******************************************************************************/
void NewDayInit(void)
{
    NVD_ExtEEPROM_to_RAM();

    // Init Buttons
    InitButtonDefault();

    // Initialize Deco Variables
    IntinalizeGasVariables();   // don't do Gas Initilizatiion, if NOT Real New Day (battery power interrupt or SYS RESET)
    Dive_Info.Status = AMB_DIVEINFO_NEWDAY_SLEEP;
    Dive_Info.StartSurfTime_s = MonotonicClock_s;
    Dive_Info.PrevSurfTime_s = 0;
    Dive_Info.SurfTime_s = 0;
    Dive_Info.PrevDiveTime_s = 0;
    Dive_Info.DiveTime_s = 0;
    Dive_Info.AfterDiveTime_s = 0;
    Dive_Info.Dive10hDetected = 0;

    RedefineWaterLevel();   // force mbar to be re-initialized in UpdateDiveInfo( );

    RemoveViolationStatus();
    GUI_DIVE_Mode = DIVE_MODE;

    GUI_TMT_Status[1] = (NVD_status_t)SCUBA_Set.TMT_On.TMT1;
    GUI_TMT_Status[2] = (NVD_status_t)SCUBA_Set.TMT_On.TMT2;
    GUI_TMT_Status[3] = (NVD_status_t)SCUBA_Set.TMT_On.TMT3;
    GUI_TMT_Status[4] = (NVD_status_t)SCUBA_Set.TMT_On.TMT4;
    GUI_TMT_Status[5] = (NVD_status_t)SCUBA_Set.TMT_On.TMT5;
    GUI_TMT_Status[6] = (NVD_status_t)SCUBA_Set.TMT_On.TMT6;

    Check3rdRowAfterDiveModeSwitch();
    GUI_Activation_mBAR = (uint16_t)CURRENT_PRESSURE_MBAR;
    GUI_Activation_PSI =  0.0145 * CURRENT_PRESSURE_MBAR;

    //==============Save Some Data to EEPROM right before NewDay==================
    DEV_Rec.DiveNumOfDay = 0;
    DEV_Rec.FreeDiveNumOfDay = 0;
    DEV_Rec.RetainIndex = 0;            // Removes Data Retaintion
    DEV_Rec.LockForGaugeDive = 0;       // Reset to release the lockup at Gauge Dive or GSM Dive
    DEV_Rec.FLASH_ErrCnt = 0;           // Reset previous FLASH Error back to 0, added from R1006
    DEV_Rec.EE_ErrCnt = 0;              // Reset previous EE Error back to 0, added from R1006
    // Save above data to EEPROM
    EE_SaveReq(EE_DEVREC);            // save to EE
    //============================================================================
    /*GUI Initial*/
    GUI_Init_Flag = 1;
    GUI_O2ANALYZER_CALIB_FLAT = false;          // to void previous O2 Analyzer Calibration result, a new one is now needed

    // GPS turns ON
    if(GnssStatus >= GNSS_SLEEP)
        Gnss_WakeUp();
    else
        Gnss_On();

    // Battery Charging GUI
    if(BatteryCharging())
        DSX_Opcode = B1_BATT_CHARGE;
    else if(!REGISTER_Done())
        DSX_Opcode = REGISTER_SCREEN;
    else
        DSX_Opcode = W1_WELCOME;

    NewDayInitDone = true;            //YeuShyr 20220304 for Complete NewDayInit before Dive
}



/*******************************************************************************
    PSM_Wakeup_Init(void))

    Needed for every time wakeup from PSM, different from NewDayInit( )
*******************************************************************************/
void PSM_Wakeup_Init(void)
{
    // Init Buttons
    InitButtonDefault();

    /*GUI Initial*/
    GUI_Init_Flag = 1;
}

/*******************************************************************************
    The function to determine using NewDay or Retained Data
              after waking up from sleep(s)
    void CheckForNewDayDataOrRetainedData(void)
*******************************************************************************/
void CheckForNewDayDataOrRetainedData(void)
{
#if DATA_RET_ENABLED   // Disable Data Retention for now (1: Enable;  0: Disable)  
    if(DEV_Rec.RetainIndex!=0)    // Retention Marker has been marked
    {
        // Fine the newer set or Retained Data (Copy-A or Copy-B)
        if(UseRETAorB()==1)
            ReadRetendedData(1);      // Read Data Retetioned Data back to RAM, use RET_A data
        else
            ReadRetendedData(2);      // Read Data Retetioned Data back to RAM, use RET_B data

        UI_BootToSurfMode();

        Switch_Gas();

        DataRetainDone = true;
    }
    else
    {
        // Initilizations for New Day, after Erased, or for New EEPROM
        NewDayInit();
    }
#else
    NewDayInit();
#endif  // For Enable/Disable Data Retention
}

void UI_PorMessage(void)
{
    char _DispStringTemp[15];

    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(GUI_FONT_24_ASCII);

    sprintf(_DispStringTemp, "%s", "SYSTEM");
    GUI_DispStringHCenterAt(_DispStringTemp, 160 ,90);
    sprintf(_DispStringTemp, "%s", "LOADING");
    GUI_DispStringHCenterAt(_DispStringTemp, 160 ,120);
    sprintf(_DispStringTemp, "R-%d", (int)GET_FW_VERSION);
    GUI_DispStringHCenterAt(_DispStringTemp, 160 ,150);
}


void UI_EnterDeepSleep(void)
{
    NewDayInitDone = false;             //YeuShyr 20220308 to complete NewDayInit before Dive
    DataRetainDone = false;             //YeuShyr 20220308 to complete DataRetain before Dive
    RedefineWaterLevel();   			// force mbar to be re-initialized in UpdateDiveInfo( );
    DEV_Rec.RetainIndex = 0;                    //YeuShyr 20221006 to clear up old dive data retaintion
    DEV_Rec.LockForGaugeDive = 0;               //YeuShyr 20220509 to clear up old dive lockup for GSM and Gauge mode
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);       //YeuShyr 20221006 to clear up old dive DEVREC
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;
}
void UI_WakeFromDeepSleep(void)
{
    // These three lines make sure to init Surface Main properly------------------
    /* Handle Data Initialization for NewDay */
    // Initilizations for New Day, after Erased, or for New EEPROM
    CheckForNewDayDataOrRetainedData();
    SurfaceFirstPageInitFlag = true;

    if(!BatteryCharging())        // Read Battery_mV, only when USB is not connected or not attached
    {
        //Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
        //SystemSupplyMonitor.OneWayBattery_mV = SystemSupplyMonitor.Battery_mV;  // update Display Volt from charging estimate mV
        SystemSupplyMonitor.OneWayBattery_mV = DEV_Rec.BATT_mV;
    }
    else
    {
        SystemSupplyMonitor.OneWayBattery_mV = DEV_Rec.BATT_mV;
    }
    GUI_ON_DelayCtr=40;
    GUI_Init_Flag = 1;
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;

    St2Ble_PowerDown();
    //----------------------------------------------------------------------------
}

void UI_EnterLowBatDeepSleep(void)
{
    NewDayInitDone = false;             //YeuShyr 20220308 to complete NewDayInit before Dive
    DataRetainDone = false;             //YeuShyr 20220308 to complete DataRetain before Dive
    RedefineWaterLevel();   			// force mbar to be re-initialized in UpdateDiveInfo( );
}
void UI_WakeFromLowBatDeepSleep(void)
{
    // These three lines make sure to init Surface Main properly------------------
    /* Handle Data Initialization for NewDay */
    CheckForNewDayDataOrRetainedData();
    SurfaceFirstPageInitFlag = true;

    GUI_ON_DelayCtr=4;
    GUI_Init_Flag = 1;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;

    St2Ble_PowerDown();
    //----------------------------------------------------------------------------
}
void UI_EnterFastDeepSleep(void)
{
    NewDayInitDone = false;             //YeuShyr 20220308 to complete NewDayInit before Dive
    DataRetainDone = false;             //YeuShyr 20220308 to complete DataRetain before Dive
    RedefineWaterLevel();   			// force mbar to be re-initialized in UpdateDiveInfo( );
    DEV_Rec.RetainIndex = 0;                    //YeuShyr 20221006 to clear up old dive data retaintion
    DEV_Rec.LockForGaugeDive = 0;               //YeuShyr 20220509 to clear up old dive lockup for GSM and Gauge mode
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);       //YeuShyr 20220509 to clear up old dive DEVREC
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;
}
void UI_WakeFromFastDeepSleep(void)
{
    // These three lines make sure to init Surface Main properly------------------
    /* Handle Data Initialization for NewDay */
    // Initilizations for New Day, after Erased, or for New EEPROM
    NewDayInit();
    SurfaceFirstPageInitFlag = true;

    GUI_ON_DelayCtr=40;
    GUI_Init_Flag = 1;
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;

    St2Ble_PowerDown();
    //----------------------------------------------------------------------------
}

void UI_EnterSleep(void)
{
    NewDayInitDone = false;             //YeuShyr 20220308 to complete NewDayInit before Dive
    DataRetainDone = false;             //YeuShyr 20220308 to complete DataRetain before Dive
    RedefineWaterLevel();   			// force mbar to be re-initialized in UpdateDiveInfo( );
    DEV_Rec.RetainIndex = 0;                    //YeuShyr 20221006 to clear up old dive data retaintion
    DEV_Rec.LockForGaugeDive = 0;               //YeuShyr 20220509 to clear up old dive lockup for GSM and Gauge mode
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);       //YeuShyr 20221006 to clear up old dive DEVREC
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;
}
void UI_WakeFromSleep(void)
{
    // These three lines make sure to init Surface Main properly------------------
    /* Handle Data Initialization for NewDay */
    NewDayInit();
    SurfaceFirstPageInitFlag = true;

    GUI_ON_DelayCtr=40;
    GUI_Init_Flag = 1;
    NewOpcode = (DSX_OPCODE_t) W1_WELCOME;
    DSX_Opcode = (DSX_OPCODE_t) W1_WELCOME;
    pre_DSX_Opcode = (DSX_OPCODE_t) INIT_OPCODE;

    St2Ble_PowerDown();
}

void UI_EnterPsm(void)
{
    // Do Nothing from 2022 11 04
}
void UI_WakeFromPsm(void)
{
    // These three lines make sure to init Surface Main properly------------------
    PSM_Wakeup_Init();
    SurfaceFirstPageInitFlag = true;
    GUI_ON_DelayCtr=4;
    GUI_Init_Flag = 1;
    GUI_TTF_Done();
    DSX_Opcode = (DSX_OPCODE_t)S2_SURFACE_MAIN;
    pre_DSX_Opcode =(DSX_OPCODE_t) 0xFFFF;

    St2Ble_PowerDown();
}

void UI_BootToSurfMode(void)
{
    SystemStatus.System_ActiveReq = true;
    Dive_Info.StartSurfTime_s = MonotonicClock_s - SItime;
    Dive_Info.PrevSurfTime_s = (int)60 * SImin;
}

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
/* Global variable used in all PRTOS delay functions */
//union AlarmUNION  AlarmOn;           // 4-Byte of 32 Alarms and Warnings 1-bit flags

/******************************************************************************
 * @brief   WarningsAlarmsTurnOn
 *
 * @note
 ******************************************************************************/



#define ALARM_LONG_10SEC      80      // Type 1:      [--------][--------][--------][--------][--------][--------][--------][--------][--------][--------]
#define ALARM_SHORT_3PULSES   16      // Type 2:      [- - -   ][        ]
#define ALARM_3SHORT_3PULSES  24      // Type 3:      [- - -   ][- - -   ][- - -   ]  
#define ALARM_FIFO_SIZE       (ALARM_MAX + 1)

union AlarmUNION ALARM_ON;          // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
union AlarmUNION AlarmOn;           // Current running Alarm for the condition, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
union AlarmUNION AlarmState;        // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
union AlarmUNION AlarmRepeat;       // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
union AlarmUNION AlarmOccured;      // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
union AlarmUNION Alarming;          // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
union AlarmUNION AlarmProfileRec;   // Alarm and Violation Record buffer for Profile Record recording
union AlarmUNION AlarmDueAck;       // Alarms and Violations that need Button Pressing as Acknowledgment

union Alarm2UNION ALARM_ON2;        // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
union Alarm2UNION AlarmOn2;         // Current running Alarm for the condition, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
union Alarm2UNION AlarmState2;      // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
union Alarm2UNION AlarmRepeat2;     // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
union Alarm2UNION AlarmOccured2;    // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
union Alarm2UNION Alarming2;        // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
union Alarm2UNION AlarmProfileRec2; // Alarm and Violation Record buffer for Profile Record recording
union Alarm2UNION AlarmDueAck2;     // Alarms and Violations that need Button Pressing as Acknowledgment

SHUTDOWN_struct_t Operate;        // Shutdown States from Run to Shutdown

uint8_t AlarmCtr[ALARM_FIFO_SIZE] = {0};
uint16_t AlarmRealtime[ALARM_FIFO_SIZE] = {0};
uint8_t AlarmInTicks[ALARM_FIFO_SIZE] = {0};
uint8_t AlarmFIFO[ALARM_FIFO_SIZE];
uint8_t CurrAlarmID = ALARM_MAX;

// to be continue later*******************************************************************************************
void Alarm_10Seonds(uint32_t *ON_Bit, uint32_t *On_bit, uint32_t *Pre_bit, uint32_t *State_bit, uint8_t *Ctr)
{

    if(*ON_Bit || *On_bit)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        *On_bit = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((*On_bit==true)&&(*Pre_bit==false))        // check if time for new alarm cycle
        {
            *Ctr=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            *ON_Bit = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        *Ctr--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if((*Ctr%8) >= 4)          // First Half Second 7,6,5,4 ON / Second Half Second 3,2,1,0 OFF
            *State_bit = true;
        else
            *State_bit = false;
        //----------------------------------------------------------------------------------------------------

        if(*Ctr==0)
        {
            *On_bit = false;
            *State_bit = false;
        }
    }

    *Pre_bit = *On_bit;
    //End of AlarmCtr[0]------------------------------------------------------------------------------------

}
// to be continue later*******************************************************************************************




/******************************************************************************
 * @brief   AlarmInit
 *
 * @note    Initialize alarms before each new dive
 ******************************************************************************/
void AlarmInit(void)
{
    uint8_t i;

    CurrAlarmID = ALARM_MAX;

    ALARM_ON.AllBits = 0x00000000;                // intialized all alarm OFF

    AlarmOn.AllBits = 0x00000000;                 // intialized all alarm OFF

    AlarmState.AllBits = 0x00000000;              // intialized all alarm OFF

    AlarmRepeat.AllBits = 0xFFFFFFFF;             // intialized repeatable for each new dive

    if(isViolation)
        AlarmOccured.AllBits &= 0x01000000;       // intialized all (except SetupVIOLATION) alarm to "NOT Occured"
    else
        AlarmOccured.AllBits &= 0x00000000;       // intialized all alarm NOT Occured

    Alarming.AllBits = 0x00000000;                // intialized all alarm NOT Occuring

    AlarmDueAck.AllBits = 0x00000000;             // intialized all alarm NOT Occuring

    AlarmProfileRec.AllBits = 0x00000000;         // reset profile's alarm record

    ALARM_ON2.AllBits = 0x00000000;                // intialized all alarm OFF

    AlarmOn2.AllBits = 0x00000000;                 // intialized all alarm OFF

    AlarmState2.AllBits = 0x00000000;              // intialized all alarm OFF

    AlarmRepeat2.AllBits = 0xFFFFFFFF;             // intialized repeatable for each new dive

    AlarmOccured2.AllBits = 0x00000000;            // intialized all alarm NOT Occured

    Alarming2.AllBits = 0x00000000;                // intialized all alarm NOT Occuring

    AlarmDueAck2.AllBits = 0x00000000;             // intialized all alarm NOT Occuring

    AlarmProfileRec2.AllBits = 0x00000000;         // reset profile's alarm record

    for(i=0; i<ALARM_FIFO_SIZE; i++)
        AlarmFIFO[i]=ALARM_MAX;

    for(i=0; i<=ALARM_MAX; i++)
        AlarmRealtime[i]=0;

    for(i=0; i<=ALARM_MAX; i++)
        AlarmInTicks[i]=0;

    ConditionTime = 0;

}

/******************************************************************************
 * @brief   AlarmFIFO_Arrange
 *
 * @note    Mark Alarm request into AlarmFIFO queue
 ******************************************************************************/
uint8_t AlarmFIFO_Arrange(uint8_t AlarmID)
{
    uint8_t i;
    uint8_t length;       // current AlarmFIFO queue length

    i=0;
    length=0;

    if((AlarmID == ALARM_AscRate5)||(AlarmID == ALARM_AscRate4))
    {   // process the Highest Priority Alarm(s) to the front of Alarm Buffer (LIFO)

        if(AlarmFIFO[0]==ALARM_MAX)     // if AlarmFIFO buffer is empty
        {
            AlarmFIFO[0]=AlarmID; // append the new coming AlarmID into the newest cell of the AlarmFIFO
            i++;           // i increments from 0 to 1 and done
            length = i;    // length is 1
        }
        else
        {
            while(AlarmFIFO[i]!=ALARM_MAX && i<ALARM_FIFO_SIZE)
            {
                i++;
                length = i;    // length of existing alarm queue detected
            }

            for(i=length; i>=1; i--)
            {
                AlarmFIFO[i]=AlarmFIFO[i-1];  // push one position to yield the new coming AlarmID, for length size
            }

            AlarmFIFO[0]=AlarmID;  // place the new coming AlarmID into the newest cell of the AlarmFIFO

            length++;             // increment by one for the new coming placed at the front
        }
    }
    else
    {   // Process the other normal priority alarms to the end of Alarm Buffer (FIFO)

        while(AlarmFIFO[i]!=ALARM_MAX && i<ALARM_FIFO_SIZE)
        {
            i++;           // counting the length of the existing queues
            length = i;    // length of existing alarm queue detected
        }

        AlarmFIFO[i]=AlarmID; // append the new coming AlarmID into the newest cell of the AlarmFIFO
    }

    return length;        // output the current length of the queue
}


/******************************************************************************
 * @brief   AlarmFIFO_Process
 *
 * @note    Process Alarm request from AlarmFIFO queue
 ******************************************************************************/
uint8_t AlarmFIFO_Process(void)
{
    uint8_t i;


    // do next alarm when the previous alarm is completely done
    if( (ALARM_ON.AllBits==0) && (AlarmOn.AllBits==0)
            && (ALARM_ON2.AllBits==0) && (AlarmOn2.AllBits==0) )
    {
        AlarmID = AlarmFIFO[0];       // processing this AlarmID change exactly at (TickHandler.scheduled_tick==0)

        switch(AlarmID)
        {
        //----- [10 long beeps, no repeat at the same dive]---------------
        case ALARM_CondiVio:
            ALARM_ON.Bit.CondiVio = true;
            AlarmOccured.Bit.CondiVio = true;
            break;
        case ALARM_DelayedVio1:
            ALARM_ON.Bit.DelayedVio1 = true;
            AlarmOccured.Bit.DelayedVio1 = true;
            break;
        case ALARM_DelayedVio2:
            ALARM_ON.Bit.DelayedVio2 = true;
            AlarmOccured.Bit.DelayedVio2 = true;
            break;
        case ALARM_O2_80Pct:
            ALARM_ON.Bit.O2_80Pct = true;
            AlarmOccured.Bit.O2_80Pct = true;
            break;
        case ALARM_O2_100Pct:
            ALARM_ON.Bit.O2_100Pct = true;
            AlarmOccured.Bit.O2_100Pct = true;
            break;
        case ALARM_DiveTime:
            ALARM_ON.Bit.DiveTime = true;
            AlarmOccured.Bit.DiveTime = true;
            break;

        //----- [10 long beeps, repeatable at the same dive]---------------
        case ALARM_DepthMax:
            ALARM_ON.Bit.DepthMax = true;
            AlarmOccured.Bit.DepthMax = true;
            break;
        case ALARM_AscRate5:
            ALARM_ON.Bit.AscRate5 = true;
            AlarmOccured.Bit.AscRate5 = true;
            break;
        case ALARM_PO2_Lo:
            ALARM_ON.Bit.PO2_Lo = true;
            AlarmOccured.Bit.PO2_Lo = true;
            break;
        case ALARM_PO2_Hi:
            ALARM_ON.Bit.PO2_Hi = true;
            AlarmOccured.Bit.PO2_Hi = true;
            break;
        case ALARM_DepthSet:
            ALARM_ON.Bit.DepthSet = true;
            AlarmOccured.Bit.DepthSet = true;
            break;
        case ALARM_DECO_Entry:
            ALARM_ON.Bit.DECO_Entry = true;
            AlarmOccured.Bit.DECO_Entry = true;
            break;
        case ALARM_DiveDTR:
            ALARM_ON.Bit.DiveDTR = true;
            AlarmOccured.Bit.DiveDTR = true;
            break;

        //----- [3 short beeps, repeatable at the same dive]----------------
        case ALARM_AscRate4:
            ALARM_ON.Bit.AscRate4 = true;
            AlarmOccured.Bit.AscRate4 = true;
            break;
        case ALARM_FreeDiveT:
            ALARM_ON.Bit.FreeDiveT = true;
            AlarmOccured.Bit.FreeDiveT = true;
            break;

        //----- [3 short beeps x 3 times, repeatable at the same dive]------
        case ALARM_FreeDepth1:
            ALARM_ON.Bit.FreeDepth1 = true;
            AlarmOccured.Bit.FreeDepth1 = true;
            break;
        case ALARM_FreeDepth2:
            ALARM_ON.Bit.FreeDepth2 = true;
            AlarmOccured.Bit.FreeDepth2 = true;
            break;
        case ALARM_FreeDepth3:
            ALARM_ON.Bit.FreeDepth3 = true;
            AlarmOccured.Bit.FreeDepth3 = true;
            break;
        case ALARM_FreeN2Bar:
            ALARM_ON.Bit.FreeN2Bar = true;
            AlarmOccured.Bit.FreeN2Bar = true;
            break;
        case ALARM_FreeCDT:
            ALARM_ON.Bit.FreeCDT = true;
            AlarmOccured.Bit.FreeCDT = true;
            break;
        case ALARM_FreeViol:
            ALARM_ON.Bit.FreeViol = true;
            AlarmOccured.Bit.FreeViol = true;
            break;

        //----- [10 long beeps, repeatable at the same dive]---------------
        case ALARM_DECO_Depth70:
            ALARM_ON.Bit.DECO_Depth70 = true;
            AlarmOccured.Bit.DECO_Depth70 = true;
            break;

        case ALARM_SwitchFO2:
            ALARM_ON.Bit.SwitchFO2 = true;
            AlarmOccured.Bit.SwitchFO2 = true;
            break;

        case ALARM_SetupVIOLATION:
            ALARM_ON.Bit.SetupVIOLATION = true;
            AlarmOccured.Bit.SetupVIOLATION = true;
            break;

        case ALARM_DECO_Warning:
            ALARM_ON.Bit.DECO_Warning = true;
            AlarmOccured.Bit.DECO_Warning = true;
            break;

        case ALARM_DECO_Alarm:
            ALARM_ON.Bit.DECO_Alarm = true;
            AlarmOccured.Bit.DECO_Alarm = true;
            break;

        case ALARM_GFBG_Alarm:
            ALARM_ON.Bit.GFBG_Alarm = true;
            AlarmOccured.Bit.GFBG_Alarm = true;
            break;

        case ALARM_NoOpShutdown:
            ALARM_ON.Bit.NoOpShutdown = true;
            AlarmOccured.Bit.NoOpShutdown = true;
            break;

        case ALARM_LowBatteryWarning:
            ALARM_ON.Bit.LowBattWarning = true;
            AlarmOccured.Bit.LowBattWarning = true;
            break;

        case ALARM_LowBatteryAlarm:
            ALARM_ON.Bit.LowBattAlarm = true;
            AlarmOccured.Bit.LowBattAlarm = true;
            break;

        // Alarm2 Group

        //----- [10 long beeps, no repeat at the same dive]---------------
        case ALARM_SP_AutoHi:
            ALARM_ON2.Bit.SP_AutoHi = true;
            AlarmOccured2.Bit.SP_AutoHi = true;
            break;
        case ALARM_SP_AutoLo:
            ALARM_ON2.Bit.SP_AutoLo = true;
            AlarmOccured2.Bit.SP_AutoLo = true;
            break;
        case ALARM_TEC_GF_Hi:
            ALARM_ON2.Bit.TEC_GF_Hi = true;
            AlarmOccured2.Bit.TEC_GF_Hi = true;
            break;
        case ALARM_TEC_GF_Lo:
            ALARM_ON2.Bit.TEC_GF_Lo = true;
            AlarmOccured2.Bit.TEC_GF_Lo = true;
            break;
        case ALARM_TTS_T:
            ALARM_ON2.Bit.TTS_T = true;
            AlarmOccured2.Bit.TTS_T = true;
            break;
        case ALARM_TankP:
            ALARM_ON2.Bit.TankP = true;
            AlarmOccured2.Bit.TankP = true;
            break;
        case ALARM_CC6P:
            ALARM_ON2.Bit.CC6P = true;
            AlarmOccured2.Bit.CC6P = true;
            break;
        case ALARM_TurnP:
            ALARM_ON2.Bit.TurnP = true;
            AlarmOccured2.Bit.TurnP = true;
            break;
        case ALARM_EndP:
            ALARM_ON2.Bit.EndP = true;
            AlarmOccured2.Bit.EndP = true;
            break;
        case ALARM_SwitchP:
            ALARM_ON2.Bit.SwitchP = true;
            AlarmOccured2.Bit.SwitchP = true;
            break;
        case ALARM_GF:
            ALARM_ON2.Bit.GF = true;
            AlarmOccured2.Bit.GF = true;
            break;
        case ALARM_N2:
            ALARM_ON2.Bit.N2 = true;
            AlarmOccured2.Bit.N2 = true;
            break;
        case ALARM_End:
            ALARM_ON2.Bit.End = true;
            AlarmOccured2.Bit.End = true;
            break;
        case ALARM_WOB:
            ALARM_ON2.Bit.WOB = true;
            AlarmOccured2.Bit.WOB = true;
            break;
        case ALARM_ICD:
            ALARM_ON2.Bit.ICD = true;
            AlarmOccured2.Bit.ICD = true;
            break;
        case ALARM_Narcotic:
            ALARM_ON2.Bit.Narcotic = true;
            AlarmOccured2.Bit.Narcotic = true;
            break;
        case ALARM_GTR5:
            ALARM_ON2.Bit.GTR5 = true;
            AlarmOccured2.Bit.GTR5 = true;
            break;
        case ALARM_GTR0:
            ALARM_ON2.Bit.GTR0 = true;
            AlarmOccured2.Bit.GTR0 = true;
            break;
        case ALARM_LostLink:
            ALARM_ON2.Bit.LostLink = true;
            AlarmOccured2.Bit.LostLink = true;
            break;
        case ALARM_OCSM_MinPO2:
            ALARM_ON2.Bit.OCSM_MinPO2 = true;
            AlarmOccured2.Bit.OCSM_MinPO2 = true;
            break;
        case ALARM_OCSM_MaxPO2:
            ALARM_ON2.Bit.OCSM_MaxPO2 = true;
            AlarmOccured2.Bit.OCSM_MaxPO2 = true;
            break;
        case ALARM_OCSM_DecoPO2:
            ALARM_ON2.Bit.OCSM_DecoPO2 = true;
            AlarmOccured2.Bit.OCSM_DecoPO2 = true;
            break;
        case ALARM_SystemERR:
            ALARM_ON2.Bit.SystemERR = true;
            AlarmOccured2.Bit.SystemERR = true;
            break;
        case ALARM_TMT_LowBattWarning:
            ALARM_ON2.Bit.TMT_LowBattWarning = true;
            AlarmOccured2.Bit.TMT_LowBattWarning = true;
            break;
        case ALARM_TMT_LowBattAlarm:
            ALARM_ON2.Bit.TMT_LowBattAlarm = true;
            AlarmOccured2.Bit.TMT_LowBattAlarm = true;
            break;

        // End of Alarm2 Group

        //----- [default, including ALARM_MAX for empty queue, no alarm needed]------
        default:

            break;

        }

        // remove the oldest alarm already addressed, pop up one position for each remaining alarm(s) to do next
        i=0;

        while((AlarmFIFO[i]!=ALARM_MAX)&&(i<ALARM_FIFO_SIZE))
        {
            AlarmFIFO[i]=AlarmFIFO[i+1];

            i++;           // counting the length of the existing queues
        }

    }

    return AlarmID;
}


/******************************************************************************
 * @brief   StopTheBuzzerAndVibrator
 *
 * @note    Stop the currently active alarm and vibrator (and start the next one if any)
 ******************************************************************************/
void StopTheBuzzerAndVibrator(void)
{
    /******************************************************************************************
        the way alarm stop is like following

          AlarmCtr[X]--;

          if(AlarmCtr[X]==0)
          {
            AlarmOn.Bit.X = false;
            AlarmState.Bit.X = false;
          }

        so, assigning 'AlarmCtr[X] = 1;', the X alarm would turn itself OFF within 125 mSec

    *******************************************************************************************/

    AlarmCtr[CurrAlarmID] = 1; // to turn OFF alarm in the next step

}



/******************************************************************************
 * @brief   WarningsAlarmsManager
 *
 * @note    Process Alarm Signals
 ******************************************************************************/
void WarningsAlarmsManager(void)
{

    static union AlarmUNION PreAlarmOn;   // Previous Alarm Status
    static union Alarm2UNION PreAlarmOn2;   // Previous Alarm Status

    ImmediateStopAlarmCheck();


    // Start of Alarm Linking Interface ==============================================================================
    if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
    {
        // CondiVio is only allowed to resume when ConditionTime == 0 and retrigger again.
        if(GFBGVal <= 90)
            AlarmRepeat.Bit.CondiVio = true;  // CondiVio is only allowed to resume when GFBGVal <= 90 and retrigger again.

        //----bit-CondiVio------------------------------------------------------------------
        // Missing a Deco shall enter CV and remain in CV from 0 second up to 5 minutes (300 seconds, Conditional Panel Time = 480 Seconds)  (not repeatable???)
        if(GFBGVal > 90)
        {
            AlarmRealtime[ALARM_CondiVio]++;
            AlarmInTicks[ALARM_CondiVio]=TICK_ID_PLUS_1;
            Alarming.Bit.CondiVio = true;
            AlarmOccured.Bit.CondiVio = true;

            if(AlarmRepeat.Bit.CondiVio == true)
            {
                AlarmFIFO_Arrange(ALARM_CondiVio);
                AlarmRepeat.Bit.CondiVio = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_CondiVio]=0;
            AlarmInTicks[ALARM_CondiVio]=0;
            Alarming.Bit.CondiVio = false;
        }
        //----bit-CondiVio------------------------------------------------------------------


        //----bit-DelayedVio1------------------------------------------------------------------
        // disregards a CV and for over 5 minutes (300 seconds)
        if((GF_Overtime() >= 300)&&(GFBGVal > 90))
        {
            AlarmRealtime[ALARM_DelayedVio1]++;
            AlarmInTicks[ALARM_DelayedVio1]=TICK_ID_PLUS_1;
            Alarming.Bit.DelayedVio1 = true;
            AlarmOccured.Bit.DelayedVio1 = true;

            if(AlarmRepeat.Bit.DelayedVio1 == true)
            {
                AlarmFIFO_Arrange(ALARM_DelayedVio1);
                AlarmRepeat.Bit.DelayedVio1 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_DelayedVio1]=0;
            AlarmInTicks[ALARM_DelayedVio1]=0;
            Alarming.Bit.DelayedVio1 = false;
        }
        //----bit-DelayedVio1------------------------------------------------------------------


        //----bit-DelayedVio2------------------------------------------------------------------
        // When Deco requires a Stop Depth deeper than 60 FT (18 M), but less than 70 FT (21 M) (not repeatable???)
        if(UNITS==NVD_IMPERIAL)
        {
            if((DecoStop[1]>=400)||(DecoTime[1]>=90))     // When Deco requires a Stop Depth deeper than 400 FT (133 M), but less than VGM_DEPTHAL_FT FT (VGM_DEPTHAL_M M)
            {
                AlarmRealtime[ALARM_DelayedVio2]++;
                AlarmInTicks[ALARM_DelayedVio2]=TICK_ID_PLUS_1;
                Alarming.Bit.DelayedVio2 = true;
                AlarmOccured.Bit.DelayedVio2 = true;

                if(AlarmRepeat.Bit.DelayedVio2 == true)
                {
                    AlarmFIFO_Arrange(ALARM_DelayedVio2);
                    AlarmRepeat.Bit.DelayedVio2 = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DelayedVio2]=0;
                AlarmInTicks[ALARM_DelayedVio2]=0;
                Alarming.Bit.DelayedVio2 = false;
            }
        }
        else
        {
            if((DecoStop[1]>=400)||(DecoTime[1]>=90))     // When Deco requires a Stop Depth deeper than 60 FT (18 M), but less than VGM_DEPTHAL_FT FT (VGM_DEPTHAL_M M)
            {
                AlarmRealtime[ALARM_DelayedVio2]++;
                AlarmInTicks[ALARM_DelayedVio2]=TICK_ID_PLUS_1;
                Alarming.Bit.DelayedVio2 = true;
                AlarmOccured.Bit.DelayedVio2 = true;

                if(AlarmRepeat.Bit.DelayedVio2 == true)
                {
                    AlarmFIFO_Arrange(ALARM_DelayedVio2);
                    AlarmRepeat.Bit.DelayedVio2 = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DelayedVio2]=0;
                AlarmInTicks[ALARM_DelayedVio2]=0;
                Alarming.Bit.DelayedVio2 = false;
            }
        }
        //----bit-DelayedVio2------------------------------------------------------------------
    }   // End of if((USER_Set.DiveMode==NVD_MDCC)||(USER_Set.DiveMode==NVD_MDOC)||(USER_Set.DiveMode==NVD_MDSM))


    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        //----bit-DepthMax---------------------------------------------------------------------
        // (Out Of Range Depth) of VGM_DEPTHAL_FT feet, or ((float)VGM_DEPTHAL_M) meters in all dive modes exceeded
        if(UNITS==NVD_IMPERIAL)
        {
            if(Dive_Info.WaterDepth_ft < (float)VGM_DEPTHAL_FT)
                AlarmRepeat.Bit.DepthMax = true;

            if((Dive_Info.WaterDepth_ft >= (float)VGM_DEPTHAL_FT)&&(VGM_DEPTHAL_FT > 0))
            {
                AlarmRealtime[ALARM_DepthMax]++;
                AlarmInTicks[ALARM_DepthMax]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthMax = true;
                AlarmOccured.Bit.DepthMax = true;

                if(AlarmRepeat.Bit.DepthMax == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthMax);
                    AlarmRepeat.Bit.DepthMax = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthMax]=0;
                AlarmInTicks[ALARM_DepthMax]=0;
                Alarming.Bit.DepthMax = false;
            }
        }
        else
        {
            if(Dive_Info.WaterDepth_m < (float)VGM_DEPTHAL_M)
                AlarmRepeat.Bit.DepthMax = true;

            if((Dive_Info.WaterDepth_m >= (float)VGM_DEPTHAL_M)&&(VGM_DEPTHAL_M > 0))
            {
                AlarmRealtime[ALARM_DepthMax]++;
                AlarmInTicks[ALARM_DepthMax]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthMax = true;
                AlarmOccured.Bit.DepthMax = true;

                if(AlarmRepeat.Bit.DepthMax == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthMax);
                    AlarmRepeat.Bit.DepthMax = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthMax]=0;
                AlarmInTicks[ALARM_DepthMax]=0;
                Alarming.Bit.DepthMax = false;
            }
        }
        //----bit-DepthMax--------------------------------------------------------------------



        //----bit-AscRate5--------------------------------------------------------------------
        // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.
        if(ASCBGVal < 5)
            AlarmRepeat.Bit.AscRate5 = true;

        if(ASCBGVal >= 5)
        {
            AlarmRealtime[ALARM_AscRate5]++;
            AlarmInTicks[ALARM_AscRate5]=TICK_ID_PLUS_1;
            Alarming.Bit.AscRate5 = true;

            if((AlarmRepeat.Bit.AscRate5 == true)&&(LCD_Flash.Bit.ASCBar==true))  // to sync-up with LCD_Flash.Bit.ASCBar ASCBar-5 flashing
            {
                AlarmFIFO_Arrange(ALARM_AscRate5);
                AlarmRepeat.Bit.AscRate5 = false; // stop for each cycle
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_AscRate5]=0;
            AlarmInTicks[ALARM_AscRate5]=0;
            Alarming.Bit.AscRate5 = false;
        }
        //----bit-AscRate5--------------------------------------------------------------------


        //----bit-AscRate4--------------------------------------------------------------------
        // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.
        if(ASCBGVal < 4)
            AlarmRepeat.Bit.AscRate4 = true;  // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.

        if(ASCBGVal >= 4)
        {
            AlarmRealtime[ALARM_AscRate4]++;
            AlarmInTicks[ALARM_AscRate4]=TICK_ID_PLUS_1;
            Alarming.Bit.AscRate4 = true;

            if(AlarmRepeat.Bit.AscRate4 == true)
            {
                AlarmFIFO_Arrange(ALARM_AscRate4);
                AlarmRepeat.Bit.AscRate4 = false; // stop for each cycle
            }
        }
        else
        {
            AlarmRealtime[ALARM_AscRate4]=0;
            AlarmInTicks[ALARM_AscRate4]=0;
            Alarming.Bit.AscRate4 = false;
        }
        //----bit-AscRate4--------------------------------------------------------------------

#if 0
        if((OC_MODE)||(SM_MODE)||(BO_MODE))
        {
            //----bit-PO2_Lo------------------------------------------------------------------
            if( PO2atDepth*100 > BAILOUT_OC_MIN_PO2 )
            {
                AlarmRepeat.Bit.PO2_Lo = true;  // PO2_Hi is only allowed to resume after PO2atDepth < PO2_Hi again.
            }

            if( PO2atDepth*100 <= BAILOUT_OC_MIN_PO2 )
            {
                AlarmRealtime[ALARM_PO2_Lo]++;
                AlarmInTicks[ALARM_PO2_Lo]=TICK_ID_PLUS_1;
                Alarming.Bit.PO2_Lo = true;
                AlarmOccured.Bit.PO2_Lo = true;

                if(AlarmRepeat.Bit.PO2_Lo == true)
                {
                    AlarmFIFO_Arrange(ALARM_PO2_Lo);
                    AlarmRepeat.Bit.PO2_Lo = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_PO2_Lo]=0;
                AlarmInTicks[ALARM_PO2_Lo]=0;
                Alarming.Bit.PO2_Lo = false;
            }
            //----bit-PO2_Lo------------------------------------------------------------------

            //----bit-PO2_Hi------------------------------------------------------------------
            // PO2 increases to the Alarm Set Point
            if( PO2atDepth*100 < BAILOUT_OC_MAX_PO2 )
            {
                AlarmRepeat.Bit.PO2_Hi = true;  // PO2_Hi is only allowed to resume after PO2atDepth < PO2_Hi again.
            }

            if( PO2atDepth*100 >= BAILOUT_OC_MAX_PO2 )
            {
                AlarmRealtime[ALARM_PO2_Hi]++;
                AlarmInTicks[ALARM_PO2_Hi]=TICK_ID_PLUS_1;
                Alarming.Bit.PO2_Hi = true;

                if(AlarmRepeat.Bit.PO2_Hi == true)
                {
                    AlarmFIFO_Arrange(ALARM_PO2_Hi);
                    AlarmRepeat.Bit.PO2_Hi = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_PO2_Hi]=0;
                AlarmInTicks[ALARM_PO2_Hi]=0;
                Alarming.Bit.PO2_Hi = false;
            }
            //----bit-PO2_Hi------------------------------------------------------------------
        } // End if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
#endif

        //----bit-ALARM_DepthSet------------------------------------------------------------------
        // Depth > DepthAlarmSetPoint
        if(UNITS==NVD_IMPERIAL)
        {
            if(Dive_Info.WaterDepth_ft < (float)DEPTHAL_FT)
                AlarmRepeat.Bit.DepthSet = true;  // DepthSet is only allowed to resume after Depth < DepthSet again.

            if((Dive_Info.WaterDepth_ft >= (float)DEPTHAL_FT)&&(DEPTHAL_FT > 0)&&(SCUBA_Set.AlarmSet.Bit.DepthSet == true))     // (DEPTHAL_M > 0) is the On/Off switch
            {
                AlarmRealtime[ALARM_DepthSet]++;
                AlarmInTicks[ALARM_DepthSet]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthSet = true;

                if(AlarmRepeat.Bit.DepthSet == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthSet);
                    AlarmRepeat.Bit.DepthSet = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthSet]=0;
                AlarmInTicks[ALARM_DepthSet]=0;
                Alarming.Bit.DepthSet = false;
            }
        }
        else
        {
            if(Dive_Info.WaterDepth_m < (float)DEPTHAL_M)
                AlarmRepeat.Bit.DepthSet = true;  // DepthSet is only allowed to resume after Depth < DepthSet again.

            if((Dive_Info.WaterDepth_m >= (float)DEPTHAL_M)&&(DEPTHAL_M > 0)&&(SCUBA_Set.AlarmSet.Bit.DepthSet == true))     // (DEPTHAL_M > 0) is the On/Off switch
            {
                AlarmRealtime[ALARM_DepthSet]++;
                AlarmInTicks[ALARM_DepthSet]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthSet = true;

                if(AlarmRepeat.Bit.DepthSet == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthSet);
                    AlarmRepeat.Bit.DepthSet = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthSet]=0;
                AlarmInTicks[ALARM_DepthSet]=0;
                Alarming.Bit.DepthSet = false;
            }
        }
        //----bit-ALARM_DepthSet------------------------------------------------------------------

#if 0   // disable this, use Alarming2.N2 for DSX N2 Bar 
        if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
        {

            //----bit-DiveN2Bar------------------------------------------------------------------
            // N2Bar Over the alarm set point
            if(TLBGVal < N2_ALARM_DATA)
                AlarmRepeat.Bit.DiveN2Bar = true;  // TLBG_Alarm is only allowed to resume after TLBGVal < TLBG_Alarm again.

            if((TLBGVal >= N2_ALARM_DATA)&&(N2_ALARM_DATA > 0))
            {
                AlarmRealtime[ALARM_DiveN2Bar]++;
                AlarmInTicks[ALARM_DiveN2Bar]=TICK_ID_PLUS_1;
                Alarming.Bit.DiveN2Bar = true;

                if(AlarmRepeat.Bit.DiveN2Bar == true)
                {
                    AlarmFIFO_Arrange(ALARM_DiveN2Bar);
                    AlarmRepeat.Bit.DiveN2Bar = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DiveN2Bar]=0;
                AlarmInTicks[ALARM_DiveN2Bar]=0;
                Alarming.Bit.DiveN2Bar = false;
            }
            //----bit-DiveN2Bar------------------------------------------------------------------
        } // End if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
#endif
        if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
        {

            //----bit-O2_80Pct------------------------------------------------------------------
            // DIVE O2 at 80% (not repeatable???)
            if((OTUpercent >= 80)&&(OTUpercent < 100)&&((DVSTAT&0xF0)!=0x80))        // > 80% O2, Non-AIR-Dive, and Not On during VIOTLATION
            {
                AlarmRealtime[ALARM_O2_80Pct]++;
                AlarmInTicks[ALARM_O2_80Pct]=TICK_ID_PLUS_1;
                Alarming.Bit.O2_80Pct = true;

                if(AlarmRepeat.Bit.O2_80Pct == true)
                {
                    AlarmFIFO_Arrange(ALARM_O2_80Pct);
                    AlarmRepeat.Bit.O2_80Pct = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_O2_80Pct]=0;
                AlarmInTicks[ALARM_O2_80Pct]=0;
                Alarming.Bit.O2_80Pct = false;
            }
            //----bit-O2_80Pct------------------------------------------------------------------
        } // End if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
    }   // End if(Dive_Info.Status==AMB_DIVEINFO_DIVE)


    if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
    {

        //----bit-O2_100Pct------------------------------------------------------------------
        // DIVE O2 at 100% (not repeatable???)
        if((OTUpercent >= 100)&&((DVSTAT&0xF0)!=0x80))    // > 100% O2, Non-AIR-Dive, and Not On during VIOTLATION
        {
            AlarmRealtime[ALARM_O2_100Pct]++;
            AlarmInTicks[ALARM_O2_100Pct]=TICK_ID_PLUS_1;
            Alarming.Bit.O2_100Pct = true;
            if(AlarmRepeat.Bit.O2_100Pct == true)
            {
                AlarmFIFO_Arrange(ALARM_O2_100Pct);
                AlarmRepeat.Bit.O2_100Pct = false; // stop for each cycle
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_O2_100Pct]=0;
            AlarmInTicks[ALARM_O2_100Pct]=0;
            Alarming.Bit.O2_100Pct = false;
        }
        //----bit-O2_100Pct------------------------------------------------------------------
    }       // End of if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))


    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {

        if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
        {
            //----bit-DECO_Entry------------------------------------------------------------------
            // to detect the moment entrying Deco-Mode from Non-Deco-Mode
            if(DecoStatus == 0)        // if Deco conition removed, re-enable the repeat of Deco-Entry alarm
                AlarmRepeat.Bit.DECO_Entry = true;

            if( DecoStatus &&(AlarmOccured.Bit.CondiVio!=true)
                    &&(AlarmOccured.Bit.DelayedVio1!=true)&&(AlarmOccured.Bit.DelayedVio2!=true)&&(AlarmOccured.Bit.DepthMax!=true))
            {
                AlarmRealtime[ALARM_DECO_Entry]++;
                AlarmInTicks[ALARM_DECO_Entry]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Entry = true;

                if(AlarmRepeat.Bit.DECO_Entry == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Entry);
                    AlarmRepeat.Bit.DECO_Entry = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Entry]=0;
                AlarmInTicks[ALARM_DECO_Entry]=0;
                Alarming.Bit.DECO_Entry = false;
            }
            //----bit-DECO_Entry------------------------------------------------------------------
        }



        //----bit-DiveTime------------------------------------------------------------------
        if((Dive_Info.DiveTime_s >= (int16_t)60*DIVE_T_AL)&&(DIVE_T_AL > 0)&&(SCUBA_Set.AlarmSet.Bit.DiveTime == true))    // (DIVE_T_AL > 0) is On/Off switch
        {
            AlarmRealtime[ALARM_DiveTime]++;
            AlarmInTicks[ALARM_DiveTime]=TICK_ID_PLUS_1;
            Alarming.Bit.DiveTime = true;

            if(AlarmRepeat.Bit.DiveTime == true)
            {
                AlarmFIFO_Arrange(ALARM_DiveTime);
                AlarmRepeat.Bit.DiveTime = false; // stop for each cycle
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_DiveTime]=0;
            AlarmInTicks[ALARM_DiveTime]=0;
            Alarming.Bit.DiveTime = false;
        }
        //----bit-DiveTime------------------------------------------------------------------


        if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
        {

            //----bit-DiveDTR------------------------------------------------------------------
            uint16_t DTR;
            if((Dive_Info.DiveTime_s > 10))
            {
                if(NDT_Data <= otrTime)
                    DTR = NDT_Data;
                else
                    DTR = otrTime;

                if(DTR > (int16_t)DTR_AL)
                    AlarmRepeat.Bit.DiveDTR = true;       // DiveDTR is only allowed to resume after DTR > SCUBA_Set.DTR_Alarm

                if((DTR <= (int16_t)DTR_AL)&&(DTR_AL > 0)&&((DVSTAT&0xF0)!=0x80)&&(SCUBA_Set.AlarmSet.Bit.DiveDTR == true))    // (DTR_AL > 0) is On/Off switch, and Not On during VIOTLATION
                {
                    AlarmRealtime[ALARM_DiveDTR]++;
                    AlarmInTicks[ALARM_DiveDTR]=TICK_ID_PLUS_1;
                    Alarming.Bit.DiveDTR = true;

                    if(AlarmRepeat.Bit.DiveDTR == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DiveDTR);
                        AlarmRepeat.Bit.DiveDTR = false; // stop for each cycle
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DiveDTR]=0;
                    AlarmInTicks[ALARM_DiveDTR]=0;
                    Alarming.Bit.DiveDTR = false;
                }
            }
            //----bit-DiveDTR------------------------------------------------------------------
        } // End if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))

#if 0
        //----bit-FreeDiveT--------------------------------------------------------------------
        if((USER_Set.DiveMode == NVD_MDFREE)&&(Dive_Info.DiveTime_s > 10)&&((Dive_Info.DiveTime_s % FREE_ALARM_DIVE_T)==0)&&(FREE_ALARM_DIVE_T > 0))  // avoid initial value = 0
        {
            AlarmRealtime[ALARM_FreeDiveT]++;
            AlarmInTicks[ALARM_FreeDiveT]=TICK_ID_PLUS_1;
            Alarming.Bit.FreeDiveT = true;

            if(AlarmRepeat.Bit.FreeDiveT == true)
            {
                AlarmFIFO_Arrange(ALARM_FreeDiveT);
                AlarmRepeat.Bit.FreeDiveT = false; // stop for each cycle
            }
        }
        else
        {
            AlarmRealtime[ALARM_FreeDiveT]=0;
            AlarmInTicks[ALARM_FreeDiveT]=0;
            Alarming.Bit.FreeDiveT = false;
        }
        //----bit-FreeDiveT--------------------------------------------------------------------



        //----bit-FreeDepth1--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(UNITS==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH1_FT)
                    AlarmRepeat.Bit.FreeDepth1 = true;      // is allowed to resume when FreeDepth1 is shallower than the retrigger FREE_ALARM_DEPTH1_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH1_FT)&&(FREE_ALARM_DEPTH1_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth1]++;
                    AlarmInTicks[ALARM_FreeDepth1]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth1 = true;

                    if(AlarmRepeat.Bit.FreeDepth1 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth1);
                        AlarmRepeat.Bit.FreeDepth1 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth1]=0;
                    AlarmInTicks[ALARM_FreeDepth1]=0;
                    Alarming.Bit.FreeDepth1 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH1_M)
                    AlarmRepeat.Bit.FreeDepth1 = true;      // is allowed to resume when FreeDepth1 is shallower than the retrigger FREE_ALARM_DEPTH1_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH1_M)&&(FREE_ALARM_DEPTH1_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth1]++;
                    AlarmInTicks[ALARM_FreeDepth1]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth1 = true;

                    if(AlarmRepeat.Bit.FreeDepth1 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth1);
                        AlarmRepeat.Bit.FreeDepth1 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth1]=0;
                    AlarmInTicks[ALARM_FreeDepth1]=0;
                    Alarming.Bit.FreeDepth1 = false;
                }
            }
        }
        //----bit-FreeDepth1--------------------------------------------------------------------

        //----bit-FreeDepth2--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(UNITS==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH2_FT)
                    AlarmRepeat.Bit.FreeDepth2 = true;      // is allowed to resume when FreeDepth2 is shallower than the retrigger FREE_ALARM_DEPTH2_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH2_FT)&&(FREE_ALARM_DEPTH2_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth2]++;
                    AlarmInTicks[ALARM_FreeDepth2]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth2 = true;

                    if(AlarmRepeat.Bit.FreeDepth2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth2);
                        AlarmRepeat.Bit.FreeDepth2 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth2]=0;
                    AlarmInTicks[ALARM_FreeDepth2]=0;
                    Alarming.Bit.FreeDepth2 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH2_M)
                    AlarmRepeat.Bit.FreeDepth2 = true;      // is allowed to resume when FreeDepth2 is shallower than the retrigger FREE_ALARM_DEPTH2_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH2_M)&&(FREE_ALARM_DEPTH2_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth2]++;
                    AlarmInTicks[ALARM_FreeDepth2]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth2 = true;

                    if(AlarmRepeat.Bit.FreeDepth2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth2);
                        AlarmRepeat.Bit.FreeDepth2 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth2]=0;
                    AlarmInTicks[ALARM_FreeDepth2]=0;
                    Alarming.Bit.FreeDepth2 = false;
                }
            }
        }
        //----bit-FreeDepth2--------------------------------------------------------------------

        //----bit-FreeDepth3--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(UNITS==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH3_FT)
                    AlarmRepeat.Bit.FreeDepth3 = true;      // is allowed to resume when FreeDepth3 is shallower than the retrigger FREE_ALARM_DEPTH3_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH3_FT)&&(FREE_ALARM_DEPTH3_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth3]++;
                    AlarmInTicks[ALARM_FreeDepth3]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth3 = true;

                    if(AlarmRepeat.Bit.FreeDepth3 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth3);
                        AlarmRepeat.Bit.FreeDepth3 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth3]=0;
                    AlarmInTicks[ALARM_FreeDepth3]=0;
                    Alarming.Bit.FreeDepth3 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH3_M)
                    AlarmRepeat.Bit.FreeDepth3= true;      // is allowed to resume when FreeDepth3 is shallower than the retrigger FREE_ALARM_DEPTH3_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH3_M)&&(FREE_ALARM_DEPTH3_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth3]++;
                    AlarmInTicks[ALARM_FreeDepth3]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth3 = true;

                    if(AlarmRepeat.Bit.FreeDepth3 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth3);
                        AlarmRepeat.Bit.FreeDepth3 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth3]=0;
                    AlarmInTicks[ALARM_FreeDepth3]=0;
                    Alarming.Bit.FreeDepth3 = false;
                }
            }
        }
        //----bit-FreeDepth3--------------------------------------------------------------------



        //----bit-FreeN2Bar--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(TLBGVal < SCUBA_Set.TLBG_Alarm)
                AlarmRepeat.Bit.FreeN2Bar = true;  // TLBG_Alarm is only allowed to resume after TLBGVal < TLBG_Alarm again.

            if((TLBGVal >= SCUBA_Set.TLBG_Alarm)&&(SCUBA_Set.TLBG_Alarm > 0))
            {
                AlarmRealtime[ALARM_FreeN2Bar]++;
                AlarmInTicks[ALARM_FreeN2Bar]=TICK_ID_PLUS_1;
                Alarming.Bit.FreeN2Bar = true;

                if(AlarmRepeat.Bit.FreeN2Bar == true)
                {
                    AlarmFIFO_Arrange(ALARM_FreeN2Bar);
                    AlarmRepeat.Bit.FreeN2Bar = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_FreeN2Bar]=0;
                AlarmInTicks[ALARM_FreeN2Bar]=0;
                Alarming.Bit.FreeN2Bar = false;
            }
        }
        //----bit-FreeN2Bar--------------------------------------------------------------------


        //----bit-FreeCDT--------------------------------------------------------------------
        if(CDT_TIMER_Run!=true)
            AlarmRepeat.Bit.FreeCDT = true;  // when CDT_TIMER_Run==false, that mean CDT Timer has been stop or reset before having a chance to run again

        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if((CDT_TIMER_Enable==true)&&(CDT_TIMER_Run==true)&&(CDT_TIMER_Alarm==true)&&(FREE_CDT_ALARM_S > 0))  // Turned ON, Countdown to 0, and set non-zero
            {
                AlarmRealtime[ALARM_FreeCDT]++;
                AlarmInTicks[ALARM_FreeCDT]=TICK_ID_PLUS_1;
                Alarming.Bit.FreeCDT = true;

                if(AlarmRepeat.Bit.FreeCDT == true)
                {
                    AlarmFIFO_Arrange(ALARM_FreeCDT);
                    AlarmRepeat.Bit.FreeCDT = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_FreeCDT]=0;
                AlarmInTicks[ALARM_FreeCDT]=0;
                Alarming.Bit.FreeCDT = false;
            }
        }
        //----bit-FreeCDT--------------------------------------------------------------------


        //----bit-FreeViol--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(DecoStop[1]!=0)
            {
                AlarmRealtime[ALARM_FreeViol]++;
                AlarmInTicks[ALARM_FreeViol]=TICK_ID_PLUS_1;
                Alarming.Bit.FreeViol = true;

                if(AlarmRepeat.Bit.FreeViol == true)
                {
                    AlarmFIFO_Arrange(ALARM_FreeViol);
                    AlarmRepeat.Bit.FreeViol = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_FreeViol]=0;
                AlarmInTicks[ALARM_FreeViol]=0;
                Alarming.Bit.FreeViol = false;
            }
        }
        //----bit-FreeViol--------------------------------------------------------------------
#endif

        if(0)   // DSX checks and displays DECO Depth400 by using DelayedVio2
        {
            //----bit-DECO_Depth70--------------------------------------------------------------------
            if(UNITS==NVD_IMPERIAL)
            {
                if((DecoStop[1]>=70)||((DVSTAT&0xF0)==0x80))     // When Deco requires a Stop Depth deeper than 70 FT (21 M), or ALGO reports Immediate Violation VGM
                {
                    AlarmRealtime[ALARM_DECO_Depth70]++;
                    AlarmInTicks[ALARM_DECO_Depth70]=TICK_ID_PLUS_1;
                    Alarming.Bit.DECO_Depth70 = true;
                    AlarmOccured.Bit.SetupVIOLATION = true;

                    if(AlarmRepeat.Bit.DECO_Depth70 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DECO_Depth70);
                        AlarmRepeat.Bit.DECO_Depth70 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DECO_Depth70]=0;
                    AlarmInTicks[ALARM_DECO_Depth70]=0;
                    Alarming.Bit.DECO_Depth70 = false;
                }
            }
            else
            {
                if((DecoStop[1]>=70)||((DVSTAT&0xF0)==0x80))     // When Deco requires a Stop Depth deeper than 70 FT (21 M)
                {
                    AlarmRealtime[ALARM_DECO_Depth70]++;
                    AlarmInTicks[ALARM_DECO_Depth70]=TICK_ID_PLUS_1;
                    Alarming.Bit.DECO_Depth70 = true;
                    AlarmOccured.Bit.SetupVIOLATION = true;

                    if(AlarmRepeat.Bit.DECO_Depth70 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DECO_Depth70);
                        AlarmRepeat.Bit.DECO_Depth70 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DECO_Depth70]=0;
                    AlarmInTicks[ALARM_DECO_Depth70]=0;
                    Alarming.Bit.DECO_Depth70 = false;
                }
            }
            //----bit-DECO_Depth70--------------------------------------------------------------------
        }


        if((OC_MODE)||(SM_MODE)||(BO_MODE))
        {
            //----bit-SwitchFO2--------------------------------------------------------------------

            if(BestGasNumber == (uint8_t)TANK_NumSelected())
                AlarmRepeat.Bit.SwitchFO2 = true;  // SwitchFO2 is reatable if same condition returns

            if((DecoStatus == true) && (SuggestedBestGasNumber != 0) && (DeclinedGasNumber != SuggestedBestGasNumber)
                    && (SuggestedBestGasNumber != (uint8_t)TANK_NumSelected()) && (BestGasNumber != (uint8_t)TANK_NumSelected()))     // when Switch GAS is needed
            {
                AlarmRealtime[ALARM_SwitchFO2]++;
                AlarmInTicks[ALARM_SwitchFO2]=TICK_ID_PLUS_1;
                Alarming.Bit.SwitchFO2 = true;

                if(AlarmRepeat.Bit.SwitchFO2 == true)
                {
                    AlarmFIFO_Arrange(ALARM_SwitchFO2);
                    AlarmRepeat.Bit.SwitchFO2 = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_SwitchFO2]=0;
                AlarmInTicks[ALARM_SwitchFO2]=0;
                Alarming.Bit.SwitchFO2 = false;
            }

            //----bit-SwitchFO2--------------------------------------------------------------------

        } // End if((USER_Set.DiveMode==NVD_MDOC)||(USER_Set.DiveMode==NVD_MDSM))

    } // End of (Dive_Info.Status==AMB_DIVEINFO_DIVE)



    //----bit-SetupVIOLATION--------------------------------------------------------------------
    if( CheckViolationManager() )    // keep this redundant isViolation check over here for safe
    {
        AlarmRealtime[ALARM_SetupVIOLATION]++;
        AlarmInTicks[ALARM_SetupVIOLATION]=TICK_ID_PLUS_1;
        Alarming.Bit.SetupVIOLATION = true;

        if(AlarmRepeat.Bit.SetupVIOLATION == true)
        {
            AlarmFIFO_Arrange(ALARM_SetupVIOLATION);
            AlarmRepeat.Bit.SetupVIOLATION = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_SetupVIOLATION]=0;
        AlarmInTicks[ALARM_SetupVIOLATION]=0;
        Alarming.Bit.SetupVIOLATION = false;
    }
    //----bit-SetupVIOLATION--------------------------------------------------------------------


    if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
    {

        if(((DVSTAT&0xF0)!=0x70)&&((DVSTAT&0xF0)!=0x80))
        {
            AlarmRepeat.Bit.DECO_Warning = true;  // DECO_Alarm is only allowed to resume after (ConditionTime < 90) again.
        }

        //----bit-DECO_Warning--------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            if(((DVSTAT&0xF0)==0x70)||((DVSTAT&0xF0)==0x80))     // When Depth < Stop Depth, or ALGO reports Immediate Violation VGM
            {
                AlarmRealtime[ALARM_DECO_Warning]++;
                AlarmInTicks[ALARM_DECO_Warning]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Warning = true;
                AlarmOccured.Bit.DECO_Warning = true;

                if(AlarmRepeat.Bit.DECO_Warning == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Warning);
                    AlarmRepeat.Bit.DECO_Warning = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Warning]=0;
                AlarmInTicks[ALARM_DECO_Warning]=0;
                Alarming.Bit.DECO_Warning = false;
            }
        }
        else
        {
            if(((DVSTAT&0xF0)==0x70)||((DVSTAT&0xF0)==0x80))     // When Depth < Stop Depth, or ALGO reports Immediate Violation VGM
            {
                AlarmRealtime[ALARM_DECO_Warning]++;
                AlarmInTicks[ALARM_DECO_Warning]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Warning = true;
                AlarmOccured.Bit.DECO_Warning = true;

                if(AlarmRepeat.Bit.DECO_Warning == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Warning);
                    AlarmRepeat.Bit.DECO_Warning = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Warning]=0;
                AlarmInTicks[ALARM_DECO_Warning]=0;
                Alarming.Bit.DECO_Warning = false;
            }
        }
        //----bit-DECO_Warning--------------------------------------------------------------------




        if(((DVSTAT&0xF0)!=0x70)&&(ConditionTime < 450)&&((DVSTAT&0xF0)!=0x80))
            AlarmRepeat.Bit.DECO_Alarm = true;  // DECO_Alarm is only allowed to resume after (ConditionTime < 90) again.

        //----bit-DECO_Alarm--------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            if(((DVSTAT&0xF0)==0x70)&&(ConditionTime >= 450)||((DVSTAT&0xF0)==0x80))     // When Depth < Stop Depth, or ALGO reports Immediate Violation VGM
            {
                AlarmRealtime[ALARM_DECO_Alarm]++;
                AlarmInTicks[ALARM_DECO_Alarm]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Alarm = true;
                AlarmOccured.Bit.DECO_Alarm = true;

                if(AlarmRepeat.Bit.DECO_Alarm == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Alarm);
                    AlarmRepeat.Bit.DECO_Alarm = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Alarm]=0;
                AlarmInTicks[ALARM_DECO_Alarm]=0;
                Alarming.Bit.DECO_Alarm = false;
            }
        }
        else
        {
            if(((DVSTAT&0xF0)==0x70)&&(ConditionTime >= 450)||((DVSTAT&0xF0)==0x80))     // When Depth < Stop Depth, or ALGO reports Immediate Violation VGM
            {
                AlarmRealtime[ALARM_DECO_Alarm]++;
                AlarmInTicks[ALARM_DECO_Alarm]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Alarm = true;
                AlarmOccured.Bit.DECO_Alarm = true;

                if(AlarmRepeat.Bit.DECO_Alarm == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Alarm);
                    AlarmRepeat.Bit.DECO_Alarm = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Alarm]=0;
                AlarmInTicks[ALARM_DECO_Alarm]=0;
                Alarming.Bit.DECO_Alarm = false;
            }
        }
        //----bit-DECO_Alarm--------------------------------------------------------------------
    }



    //----bit-LowBattWarning--------------------------------------------------------------------
    if(SystemSupplyMonitor.Battery_Percentage > LOW_BATT_WARNING_LEVEL)
        AlarmRepeat.Bit.LowBattWarning = true; // allow do Low Batt warning again if charged over this level

    if(SystemSupplyMonitor.Battery_Percentage <= LOW_BATT_WARNING_LEVEL)  // avoid initial value = 0
    {
        AlarmRealtime[ALARM_LowBatteryWarning]++;
        AlarmInTicks[ALARM_LowBatteryWarning]=TICK_ID_PLUS_1;
        Alarming.Bit.LowBattWarning = true;

        if(AlarmRepeat.Bit.LowBattWarning == true)
        {
            AlarmFIFO_Arrange(ALARM_LowBatteryWarning);
            AlarmRepeat.Bit.LowBattWarning = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_LowBatteryWarning]=0;
        AlarmInTicks[ALARM_LowBatteryWarning]=0;
        Alarming.Bit.LowBattWarning = false;
    }
    //----bit-LowBattWarning--------------------------------------------------------------------


    //----bit-LowBattAlarm--------------------------------------------------------------------
    if((SystemSupplyMonitor.Battery_Percentage > LOW_BATT_ALARM_LEVEL)/*||(( NewDiveWhenLowBatt==true)&&(Dive_Info.Status==AMB_DIVEINFO_DIVE))*/)
        AlarmRepeat.Bit.LowBattAlarm = true;      // allow do Low Batt alarm again if charged over this level

    if(SystemSupplyMonitor.Battery_Percentage <= LOW_BATT_ALARM_LEVEL)  // avoid initial value = 0
    {
        AlarmRealtime[ALARM_LowBatteryAlarm]++;
        AlarmInTicks[ALARM_LowBatteryAlarm]=TICK_ID_PLUS_1;
        Alarming.Bit.LowBattAlarm = true;

        if(AlarmRepeat.Bit.LowBattAlarm == true)
        {
            AlarmFIFO_Arrange(ALARM_LowBatteryAlarm);
            AlarmRepeat.Bit.LowBattAlarm = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_LowBatteryAlarm]=0;
        AlarmInTicks[ALARM_LowBatteryAlarm]=0;
        Alarming.Bit.LowBattAlarm = false;
    }
    //----bit-LowBattAlarm--------------------------------------------------------------------


    //----bit-NoOpShutdown--------------------------------------------------------------------
    //if((CheckForNoOperation()!=true)/*||(( NewDiveWhenLowBatt==true)&&(Dive_Info.Status==AMB_DIVEINFO_DIVE))*/)
    //    AlarmRepeat.Bit.NoOpShutdown = true;      // allow do Low Batt alarm again if charged over this level

    if(CheckForNoOperation()==SystemErrorWarning_LowBattery)
    {
        AlarmRealtime[ALARM_NoOpShutdown]++;
        AlarmInTicks[ALARM_NoOpShutdown]=TICK_ID_PLUS_1;
        Alarming.Bit.NoOpShutdown = true;

        if(AlarmRepeat.Bit.NoOpShutdown == true)
        {
            AlarmFIFO_Arrange(ALARM_NoOpShutdown);
            AlarmRepeat.Bit.NoOpShutdown = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_NoOpShutdown]=0;
        AlarmInTicks[ALARM_NoOpShutdown]=0;
        Alarming.Bit.NoOpShutdown = false;
    }
    //----bit-NoOpShutdown--------------------------------------------------------------------


    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)&&(CC_MODE)) // SP_AutoHi and SP_AutoLo are running in Dive Mode and CC mode only------------------------
    {
        //----bit-SP_AutoHi-------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            // SP_AutoHi is only allowed to resume when fDepthFt < SCUBA_Set.SP_AutoHighFT and retrigger again.
            if( ccSPcurrent != ccSPhigh )
                AlarmRepeat2.Bit.SP_AutoHi = true;  // SP_AutoHi

            if( (SCUBA_Set.SP_Switch != CUSTOM_SP)&&(SCUBA_Set.Alarm2Set.Bit.SP_AutoHi)&&(ccSPcurrent == ccSPhigh)&& AutoSP_SwitchingToHigh() )
            {
                AlarmRealtime[ALARM_SP_AutoHi]++;
                AlarmInTicks[ALARM_SP_AutoHi]=TICK_ID_PLUS_1;
                Alarming2.Bit.SP_AutoHi = true;
                AlarmOccured2.Bit.SP_AutoHi = true;

                if(AlarmRepeat2.Bit.SP_AutoHi == true)
                {
                    AlarmFIFO_Arrange(ALARM_SP_AutoHi);
                    AlarmRepeat2.Bit.SP_AutoHi = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_SP_AutoHi]=0;
                AlarmInTicks[ALARM_SP_AutoHi]=0;
                Alarming2.Bit.SP_AutoHi = false;
            }
        }
        else
        {
            // SP_AutoHi is only allowed to resume when fDepthFt < SCUBA_Set.SP_AutoHighFT and retrigger again.
            if( ccSPcurrent != ccSPhigh )
                AlarmRepeat2.Bit.SP_AutoHi = true;  // SP_AutoHi

            if( (SCUBA_Set.SP_Switch != CUSTOM_SP)&&(SCUBA_Set.Alarm2Set.Bit.SP_AutoHi)&&(ccSPcurrent == ccSPhigh)&& AutoSP_SwitchingToHigh() )
            {
                AlarmRealtime[ALARM_SP_AutoHi]++;
                AlarmInTicks[ALARM_SP_AutoHi]=TICK_ID_PLUS_1;
                Alarming2.Bit.SP_AutoHi = true;
                AlarmOccured2.Bit.SP_AutoHi = true;

                if(AlarmRepeat2.Bit.SP_AutoHi == true)
                {
                    AlarmFIFO_Arrange(ALARM_SP_AutoHi);
                    AlarmRepeat2.Bit.SP_AutoHi = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_SP_AutoHi]=0;
                AlarmInTicks[ALARM_SP_AutoHi]=0;
                Alarming2.Bit.SP_AutoHi = false;
            }
        }
        //----bit-SP_AutoHi------------------------------------------------------------------

        //----bit-SP_AutoLo------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            // SP_AutoLo is only allowed to resume when fDepthFt < SCUBA_Set.SP_AutoHighFT and retrigger again.
            if( ccSPcurrent != ccSPlow )
                AlarmRepeat2.Bit.SP_AutoLo = true;  // SP_AutoLo

            if( (SCUBA_Set.SP_Switch != CUSTOM_SP)&&(SCUBA_Set.Alarm2Set.Bit.SP_AutoLo)&&(ccSPcurrent == ccSPlow)&& AutoSP_SwitchingToLow() )
            {
                AlarmRealtime[ALARM_SP_AutoLo]++;
                AlarmInTicks[ALARM_SP_AutoLo]=TICK_ID_PLUS_1;
                Alarming2.Bit.SP_AutoLo = true;
                AlarmOccured2.Bit.SP_AutoLo = true;

                if(AlarmRepeat2.Bit.SP_AutoLo == true)
                {
                    AlarmFIFO_Arrange(ALARM_SP_AutoLo);
                    AlarmRepeat2.Bit.SP_AutoLo = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_SP_AutoLo]=0;
                AlarmInTicks[ALARM_SP_AutoLo]=0;
                Alarming2.Bit.SP_AutoLo = false;
            }
        }
        else
        {
            // SP_AutoLo is only allowed to resume when fDepthFt < SCUBA_Set.SP_AutoHighFT and retrigger again.
            if( ccSPcurrent != ccSPlow )
                AlarmRepeat2.Bit.SP_AutoLo = true;  // SP_AutoLo

            if( (SCUBA_Set.SP_Switch != CUSTOM_SP)&&(SCUBA_Set.Alarm2Set.Bit.SP_AutoLo)&&(ccSPcurrent == ccSPlow)&& AutoSP_SwitchingToLow() )
            {
                AlarmRealtime[ALARM_SP_AutoLo]++;
                AlarmInTicks[ALARM_SP_AutoLo]=TICK_ID_PLUS_1;
                Alarming2.Bit.SP_AutoLo = true;
                AlarmOccured2.Bit.SP_AutoLo = true;

                if(AlarmRepeat2.Bit.SP_AutoLo == true)
                {
                    AlarmFIFO_Arrange(ALARM_SP_AutoLo);
                    AlarmRepeat2.Bit.SP_AutoLo = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_SP_AutoLo]=0;
                AlarmInTicks[ALARM_SP_AutoLo]=0;
                Alarming2.Bit.SP_AutoLo = false;
            }
        }
        //----bit-SP_AutoLo------------------------------------------------------------------
    }   // End of if(CC_MODE)

    // TEC_GF_Hi is only allowed to resume when ConditionTime == 0 and retrigger again.
    if(0)       //TODO if(ConditionTime == 0)
        AlarmRepeat2.Bit.TEC_GF_Hi = true;  // TEC_GF_Hi ??????

    //----bit-TEC_GF_Hi------------------------------------------------------------------
    // ?????????
    if(0)       //TODO if(((ConditionTime > 0)&&(ConditionTime < 480))||((DVSTAT&0xF0)==0x70))
    {
        AlarmRealtime[ALARM_TEC_GF_Hi]++;
        AlarmInTicks[ALARM_TEC_GF_Hi]=TICK_ID_PLUS_1;
        Alarming2.Bit.TEC_GF_Hi = true;
        AlarmOccured2.Bit.TEC_GF_Hi = true;

        if(AlarmRepeat2.Bit.TEC_GF_Hi == true)
        {
            AlarmFIFO_Arrange(ALARM_TEC_GF_Hi);
            AlarmRepeat2.Bit.TEC_GF_Hi = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_TEC_GF_Hi]=0;
        AlarmInTicks[ALARM_TEC_GF_Hi]=0;
        Alarming2.Bit.TEC_GF_Hi = false;
    }
    //----bit-TEC_GF_Hi------------------------------------------------------------------


    // TEC_GF_Lo is only allowed to resume when ConditionTime == 0 and retrigger again.
    if(0)       //TODO if(ConditionTime == 0)
        AlarmRepeat2.Bit.TEC_GF_Lo = true;  // TEC_GF_Lo ??????

    //----bit-TEC_GF_Lo------------------------------------------------------------------
    //
    if(0) //TODO if((DelayFlag & 0x02)==0x02)
    {
        AlarmRealtime[ALARM_TEC_GF_Lo]++;
        AlarmInTicks[ALARM_TEC_GF_Lo]=TICK_ID_PLUS_1;
        Alarming2.Bit.TEC_GF_Lo = true;
        AlarmOccured2.Bit.TEC_GF_Lo = true;

        if(AlarmRepeat2.Bit.TEC_GF_Lo == true)
        {
            AlarmFIFO_Arrange(ALARM_TEC_GF_Lo);
            AlarmRepeat2.Bit.TEC_GF_Lo = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_TEC_GF_Lo]=0;
        AlarmInTicks[ALARM_TEC_GF_Lo]=0;
        Alarming2.Bit.TEC_GF_Lo = false;
    }
    //----bit-TEC_GF_Lo------------------------------------------------------------------


    if((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE))
    {
        // TTS_T is only allowed to resume when TAT_Data < TTS_AL and retrigger again.
        if(TAT_Data < TTS_AL)
            AlarmRepeat2.Bit.TTS_T = true;  // TTS_T ??????

        //----bit-TTS_T------------------------------------------------------------------
        // ?????????
        if((TAT_Data >= TTS_AL)&&(TTS_AL != 0))
        {
            AlarmRealtime[ALARM_TTS_T]++;
            AlarmInTicks[ALARM_TTS_T]=TICK_ID_PLUS_1;
            Alarming2.Bit.TTS_T = true;
            AlarmOccured2.Bit.TTS_T = true;

            if(AlarmRepeat2.Bit.TTS_T == true)
            {
                AlarmFIFO_Arrange(ALARM_TTS_T);
                AlarmRepeat2.Bit.TTS_T = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_TTS_T]=0;
            AlarmInTicks[ALARM_TTS_T]=0;
            Alarming2.Bit.TTS_T = false;
        }
        //----bit-TTS_T------------------------------------------------------------------
    }


    if(CC_MODE)
    {
        //----bit-TankP------------------------------------------------------------------
        //
        if(UNITS==NVD_IMPERIAL)
        {
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.TankPressPSI)
                AlarmRepeat2.Bit.TankP = true;

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= SCUBA_Set.TankPressPSI)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.TankP == true))
            {
                AlarmRealtime[ALARM_TankP]++;
                AlarmInTicks[ALARM_TankP]=TICK_ID_PLUS_1;
                Alarming2.Bit.TankP = true;
                AlarmOccured2.Bit.TankP = true;

                if(AlarmRepeat2.Bit.TankP == true)
                {
                    AlarmFIFO_Arrange(ALARM_TankP);
                    AlarmRepeat2.Bit.TankP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_TankP]=0;
                AlarmInTicks[ALARM_TankP]=0;
                Alarming2.Bit.TankP = false;
            }
        }
        else
        {
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > (CONST_BAR_TO_PSI * SCUBA_Set.TankPressBAR))
                AlarmRepeat2.Bit.TankP = true;

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= (CONST_BAR_TO_PSI * SCUBA_Set.TankPressBAR))
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.TankP == true))
            {
                AlarmRealtime[ALARM_TankP]++;
                AlarmInTicks[ALARM_TankP]=TICK_ID_PLUS_1;
                Alarming2.Bit.TankP = true;
                AlarmOccured2.Bit.TankP = true;

                if(AlarmRepeat2.Bit.TankP == true)
                {
                    AlarmFIFO_Arrange(ALARM_TankP);
                    AlarmRepeat2.Bit.TankP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_TankP]=0;
                AlarmInTicks[ALARM_TankP]=0;
                Alarming2.Bit.TankP = false;
            }

        }
        //----bit-TankP------------------------------------------------------------------


        //----bit-CC6P------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.CC6PressPSI)
                AlarmRepeat2.Bit.CC6P = true;

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= SCUBA_Set.CC6PressPSI)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.CC6P == true))
            {
                AlarmRealtime[ALARM_CC6P]++;
                AlarmInTicks[ALARM_CC6P]=TICK_ID_PLUS_1;
                Alarming2.Bit.CC6P = true;
                AlarmOccured2.Bit.CC6P = true;

                if(AlarmRepeat2.Bit.CC6P == true)
                {
                    AlarmFIFO_Arrange(ALARM_CC6P);
                    AlarmRepeat2.Bit.CC6P = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_CC6P]=0;
                AlarmInTicks[ALARM_CC6P]=0;
                Alarming2.Bit.CC6P = false;
            }
        }
        else
        {
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > (CONST_BAR_TO_PSI * SCUBA_Set.CC6PressBAR))
                AlarmRepeat2.Bit.CC6P = true;

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= (CONST_BAR_TO_PSI * SCUBA_Set.CC6PressBAR))
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.CC6P == true))
            {
                AlarmRealtime[ALARM_CC6P]++;
                AlarmInTicks[ALARM_CC6P]=TICK_ID_PLUS_1;
                Alarming2.Bit.CC6P = true;
                AlarmOccured2.Bit.CC6P = true;

                if(AlarmRepeat2.Bit.CC6P == true)
                {
                    AlarmFIFO_Arrange(ALARM_CC6P);
                    AlarmRepeat2.Bit.CC6P = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_CC6P]=0;
                AlarmInTicks[ALARM_CC6P]=0;
                Alarming2.Bit.CC6P = false;
            }
        }
        //----bit-CC6P------------------------------------------------------------------
    }

    if(!CC_MODE)
    {
        //----bit-TurnP------------------------------------------------------------------
        if(UNITS==NVD_IMPERIAL)
        {
            // TurnP
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.TurnPressPSI)
                AlarmRepeat2.Bit.TurnP = true;  // TurnP

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= SCUBA_Set.TurnPressPSI)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.TurnP == true))
            {
                AlarmRealtime[ALARM_TurnP]++;
                AlarmInTicks[ALARM_TurnP]=TICK_ID_PLUS_1;
                Alarming2.Bit.TurnP = true;
                AlarmOccured2.Bit.TurnP = true;

                if(AlarmRepeat2.Bit.TurnP == true)
                {
                    AlarmFIFO_Arrange(ALARM_TurnP);
                    AlarmRepeat2.Bit.TurnP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_TurnP]=0;
                AlarmInTicks[ALARM_TurnP]=0;
                Alarming2.Bit.TurnP = false;
            }
        }
        else
        {
            // TurnP
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > CONST_BAR_TO_PSI * SCUBA_Set.TurnPressBAR)
                AlarmRepeat2.Bit.TurnP = true;  // TurnP ??????

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= CONST_BAR_TO_PSI * SCUBA_Set.TurnPressBAR)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.TurnP == true))
            {
                AlarmRealtime[ALARM_TurnP]++;
                AlarmInTicks[ALARM_TurnP]=TICK_ID_PLUS_1;
                Alarming2.Bit.TurnP = true;
                AlarmOccured2.Bit.TurnP = true;

                if(AlarmRepeat2.Bit.TurnP == true)
                {
                    AlarmFIFO_Arrange(ALARM_TurnP);
                    AlarmRepeat2.Bit.TurnP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_TurnP]=0;
                AlarmInTicks[ALARM_TurnP]=0;
                Alarming2.Bit.TurnP = false;
            }
        }
        //----bit-TurnP------------------------------------------------------------------


        //----bit-EndP------------------------------------------------------------------
        if(UNITS == NVD_IMPERIAL)
        {
            // EndP is only allowed to resume when GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.EndPressPSI and retrigger again.
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.EndPressPSI)
                AlarmRepeat2.Bit.EndP = true;  // EndP ??????

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= SCUBA_Set.EndPressPSI)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.EndP == true))
            {
                AlarmRealtime[ALARM_EndP]++;
                AlarmInTicks[ALARM_EndP]=TICK_ID_PLUS_1;
                Alarming2.Bit.EndP = true;
                AlarmOccured2.Bit.EndP = true;

                if(AlarmRepeat2.Bit.EndP == true)
                {
                    AlarmFIFO_Arrange(ALARM_EndP);
                    AlarmRepeat2.Bit.EndP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_EndP]=0;
                AlarmInTicks[ALARM_EndP]=0;
                Alarming2.Bit.EndP = false;
            }
        }
        else
        {
            // EndP is only allowed to resume when GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.EndPressPSI and retrigger again.
            if(GUI_TMT_PressPSI[Current_TMT_Num()] > CONST_BAR_TO_PSI * SCUBA_Set.EndPressBAR)
                AlarmRepeat2.Bit.EndP = true;  // EndP ??????

            if((GUI_TMT_PressPSI[Current_TMT_Num()] <= CONST_BAR_TO_PSI * SCUBA_Set.EndPressBAR)
                    &&(GUI_TMT_PressPSI[Current_TMT_Num()] > 0)&&(SCUBA_Set.Alarm2Set.Bit.EndP == true) )
            {
                AlarmRealtime[ALARM_EndP]++;
                AlarmInTicks[ALARM_EndP]=TICK_ID_PLUS_1;
                Alarming2.Bit.EndP = true;
                AlarmOccured2.Bit.EndP = true;

                if(AlarmRepeat2.Bit.EndP == true)
                {
                    AlarmFIFO_Arrange(ALARM_EndP);
                    AlarmRepeat2.Bit.EndP = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_EndP]=0;
                AlarmInTicks[ALARM_EndP]=0;
                Alarming2.Bit.EndP = false;
            }
        }
        //----bit-EndP------------------------------------------------------------------
    }


    if(SM_MODE || GSM_MODE)
    {
        //----bit-SwitchP------------------------------------------------------------------
        if(!Check_L_R())
            AlarmRepeat2.Bit.SwitchP = true;

        if(Check_L_R() && SCUBA_Set.Alarm2Set.Bit.SwitchP)
        {
            AlarmRealtime[ALARM_SwitchP]++;
            AlarmInTicks[ALARM_SwitchP]=TICK_ID_PLUS_1;
            Alarming2.Bit.SwitchP = true;
            AlarmOccured2.Bit.SwitchP = true;

            if(AlarmRepeat2.Bit.SwitchP == true)
            {
                AlarmFIFO_Arrange(ALARM_SwitchP);
                AlarmRepeat2.Bit.SwitchP = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_SwitchP]=0;
            AlarmInTicks[ALARM_SwitchP]=0;
            Alarming2.Bit.SwitchP = false;
        }
        //----bit-SwitchP------------------------------------------------------------------
    }

    if(CC_MODE || OC_MODE || SM_MODE || BO_MODE)
    {
        // GF is only allowed to resume when GFBGVal < GF_ALARM_DATA and retrigger again.
        if(GFBGVal < GF_ALARM_DATA)
            AlarmRepeat2.Bit.GF = true;  // GF ??????

        //----bit-GF------------------------------------------------------------------
        //
        if((GFBGVal >= GF_ALARM_DATA)&&(SCUBA_Set.Alarm2Set.Bit.GF == true)&&(MAINDISPLAY_N2_OR_GF_BAR==0))  // 0 = GF_BG, 1 = N2_BAR        // N2 bar and GF bar are exclusive on LCD
        {
            AlarmRealtime[ALARM_GF]++;
            AlarmInTicks[ALARM_GF]=TICK_ID_PLUS_1;
            Alarming2.Bit.GF = true;
            AlarmOccured2.Bit.GF = true;

            if(AlarmRepeat2.Bit.GF == true)
            {
                AlarmFIFO_Arrange(ALARM_GF);
                AlarmRepeat2.Bit.GF = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_GF]=0;
            AlarmInTicks[ALARM_GF]=0;
            Alarming2.Bit.GF = false;
        }
        //----bit-GF------------------------------------------------------------------



        // N2 is only allowed to resume when ConditionTime == 0 and retrigger again.
        if(TLBGVal < N2_ALARM_DATA)
            AlarmRepeat2.Bit.N2 = true;  // N2 ??????

        //----bit-N2------------------------------------------------------------------
        //
        if((TLBGVal >= N2_ALARM_DATA)&&(SCUBA_Set.Alarm2Set.Bit.N2 == true)&&(MAINDISPLAY_N2_OR_GF_BAR==1))     // 0 = GF_BG, 1 = N2_BAR        // N2 bar and GF bar are exclusive on LCD
        {   // 0 = GF_BG, 1 = N2_BAR
            AlarmRealtime[ALARM_N2]++;
            AlarmInTicks[ALARM_N2]=TICK_ID_PLUS_1;
            Alarming2.Bit.N2 = true;
            AlarmOccured2.Bit.N2 = true;

            if(AlarmRepeat2.Bit.N2 == true)
            {
                AlarmFIFO_Arrange(ALARM_N2);
                AlarmRepeat2.Bit.N2 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_N2]=0;
            AlarmInTicks[ALARM_N2]=0;
            Alarming2.Bit.N2 = false;
        }
        //----bit-N2------------------------------------------------------------------
    }


    if(OC_MODE || SM_MODE || BO_MODE)
    {
        //----bit-End------------------------------------------------------------------

        if(UNITS == NVD_IMPERIAL)
        {
            // End is only allowed to resume when FindEND() < SCUBA_Set.End_AL_Ft and retrigger again.
            if((OC_END_AtDepthFT < END_AL_FT))
                AlarmRepeat2.Bit.End = true;  // End ??????

            if((OC_END_AtDepthFT >= END_AL_FT)&&(END_AL_FT > 0)&&(SCUBA_Set.Alarm2Set.Bit.End == true))
            {
                AlarmRealtime[ALARM_End]++;
                AlarmInTicks[ALARM_End]=TICK_ID_PLUS_1;
                Alarming2.Bit.End = true;
                AlarmOccured2.Bit.End = true;

                if(AlarmRepeat2.Bit.End == true)
                {
                    AlarmFIFO_Arrange(ALARM_End);
                    AlarmRepeat2.Bit.End = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_End]=0;
                AlarmInTicks[ALARM_End]=0;
                Alarming2.Bit.End = false;
            }
        }
        else
        {
            // End is only allowed to resume when FindEND() < END_AL_dM and retrigger again.
            if(10.0*OC_END_AtDepthFT*CONST_FT_TO_M < END_AL_dM)
                AlarmRepeat2.Bit.End = true;  // End ??????

            if((10.0*OC_END_AtDepthFT*CONST_FT_TO_M >= END_AL_dM)&&(END_AL_dM > 0)&&(SCUBA_Set.Alarm2Set.Bit.End == true))
            {
                AlarmRealtime[ALARM_End]++;
                AlarmInTicks[ALARM_End]=TICK_ID_PLUS_1;
                Alarming2.Bit.End = true;
                AlarmOccured2.Bit.End = true;

                if(AlarmRepeat2.Bit.End == true)
                {
                    AlarmFIFO_Arrange(ALARM_End);
                    AlarmRepeat2.Bit.End = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_End]=0;
                AlarmInTicks[ALARM_End]=0;
                Alarming2.Bit.End = false;
            }
        }
        //----bit-End------------------------------------------------------------------



        // WOB is only allowed to resume when 10*FindWOB() < SCUBA_Set.WOB_AL_Ft and retrigger again.
        if(UNITS == NVD_IMPERIAL)
        {
            if(OC_WOB_depthFT < WOB_AL_FT)
                AlarmRepeat2.Bit.WOB = true;  // WOB ??????

            //----bit-WOB------------------------------------------------------------------
            //
            if((OC_WOB_depthFT >= WOB_AL_FT)&&(WOB_AL_FT > 0)&&(SCUBA_Set.Alarm2Set.Bit.WOB == true))
            {
                AlarmRealtime[ALARM_WOB]++;
                AlarmInTicks[ALARM_WOB]=TICK_ID_PLUS_1;
                Alarming2.Bit.WOB = true;
                AlarmOccured2.Bit.WOB = true;

                if(AlarmRepeat2.Bit.WOB == true)
                {
                    AlarmFIFO_Arrange(ALARM_WOB);
                    AlarmRepeat2.Bit.WOB = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_WOB]=0;
                AlarmInTicks[ALARM_WOB]=0;
                Alarming2.Bit.WOB = false;
            }
        }
        else
        {
            if(10.0*OC_WOB_depthFT*CONST_FT_TO_M < WOB_AL_dM)
                AlarmRepeat2.Bit.WOB = true;  // WOB ??????

            if((10.0*OC_WOB_depthFT*CONST_FT_TO_M >= WOB_AL_dM)&&((WOB_AL_dM > 0))&&(SCUBA_Set.Alarm2Set.Bit.WOB == true))
            {
                AlarmRealtime[ALARM_WOB]++;
                AlarmInTicks[ALARM_WOB]=TICK_ID_PLUS_1;
                Alarming2.Bit.WOB = true;
                AlarmOccured2.Bit.WOB = true;

                if(AlarmRepeat2.Bit.WOB == true)
                {
                    AlarmFIFO_Arrange(ALARM_WOB);
                    AlarmRepeat2.Bit.WOB = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_WOB]=0;
                AlarmInTicks[ALARM_WOB]=0;
                Alarming2.Bit.WOB = false;
            }
        }
        //----bit-WOB------------------------------------------------------------------


        //----bit-ICD------------------------------------------------------------------
        // ICD is only allowed to resume when ConditionTime == 0 and retrigger again.
        if( !NeedToSwitchGas )
            AlarmRepeat2.Bit.ICD = true;

        if( SCUBA_Set.Alarm2Set.Bit.ICD && NeedToSwitchGas && (CurrGasNumber != BestGasNumber) && ICD_Check(CurrGasNumber, BestGasNumber) )
        {
            AlarmRealtime[ALARM_ICD]++;
            AlarmInTicks[ALARM_ICD]=TICK_ID_PLUS_1;
            Alarming2.Bit.ICD = true;
            AlarmOccured2.Bit.ICD = true;

            if(AlarmRepeat2.Bit.ICD == true)
            {
                AlarmFIFO_Arrange(ALARM_ICD);
                AlarmRepeat2.Bit.ICD = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_ICD]=0;
            AlarmInTicks[ALARM_ICD]=0;
            Alarming2.Bit.ICD = false;
        }
        //----bit-ICD------------------------------------------------------------------

#if 0
        //----bit-Narcotic------------------------------------------------------------------
        // Narcotic is only allowed to resume when ConditionTime == 0 and retrigger again.
        if(0)       //TODO if(ConditionTime == 0)
            AlarmRepeat2.Bit.Narcotic = true;  // Narcotic ??????

        if(SCUBA_Set.Alarm2Set.Bit.ICD && )
        {
            AlarmRealtime[ALARM_Narcotic]++;
            AlarmInTicks[ALARM_Narcotic]=TICK_ID_PLUS_1;
            Alarming2.Bit.Narcotic = true;
            AlarmOccured2.Bit.Narcotic = true;

            if(AlarmRepeat2.Bit.Narcotic == true)
            {
                AlarmFIFO_Arrange(ALARM_Narcotic);
                AlarmRepeat2.Bit.Narcotic = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_Narcotic]=0;
            AlarmInTicks[ALARM_Narcotic]=0;
            Alarming2.Bit.Narcotic = false;
        }
        //----bit-Narcotic------------------------------------------------------------------
#endif
    }

    if(OC_MODE || SM_MODE || GSM_MODE || GAUGE_MODE || BO_MODE)
    {
        //----bit-GTR5------------------------------------------------------------------
        //
        if(Find_GTR() > 5)
            AlarmRepeat2.Bit.GTR5 = true;  // GTR5

        if(SCUBA_Set.Alarm2Set.Bit.GTR5 && (Find_GTR() <= 5))
        {
            AlarmRealtime[ALARM_GTR5]++;
            AlarmInTicks[ALARM_GTR5]=TICK_ID_PLUS_1;
            Alarming2.Bit.GTR5 = true;
            AlarmOccured2.Bit.GTR5 = true;

            if(AlarmRepeat2.Bit.GTR5 == true)
            {
                AlarmFIFO_Arrange(ALARM_GTR5);
                AlarmRepeat2.Bit.GTR5 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_GTR5]=0;
            AlarmInTicks[ALARM_GTR5]=0;
            Alarming2.Bit.GTR5 = false;
        }
        //----bit-GTR5------------------------------------------------------------------

        //----bit-GTR0------------------------------------------------------------------
        if(Find_GTR() > 0)
            AlarmRepeat2.Bit.GTR0 = true;  // GTR0


        if(SCUBA_Set.Alarm2Set.Bit.GTR0 && (Find_GTR() == 0))
        {
            AlarmRealtime[ALARM_GTR0]++;
            AlarmInTicks[ALARM_GTR0]=TICK_ID_PLUS_1;
            Alarming2.Bit.GTR0 = true;
            AlarmOccured2.Bit.GTR0 = true;

            if(AlarmRepeat2.Bit.GTR0 == true)
            {
                AlarmFIFO_Arrange(ALARM_GTR0);
                AlarmRepeat2.Bit.GTR0 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_GTR0]=0;
            AlarmInTicks[ALARM_GTR0]=0;
            Alarming2.Bit.GTR0 = false;
        }
        //----bit-GTR0------------------------------------------------------------------
    }


    //----bit-LostLink------------------------------------------------------------------
    /*
        const TMT_NUM_t currentTMT = Current_TMT_Num();

        const LOOSE_LINK_t looseLinkStatus = CheckLooseLink_TMT(currentTMT);

        go alarming when all following condigitons are true:

        1. ( Current_TMT_Num() != TMT_OFF ) ===>        Current Gas (CC, OC or SM) is selected or Current TMT (GSM or Gauge) is selected (not zero)

        2. ((SCUBA_Set.TMT_On.Allbits >> Current_TMT_Num()) == true) ===>       assigned TMT is turned ON

        3. (GUI_TMT_id[Current_TMT_Num()] != 0) ===> TMT id is NOT zero

        4. (CheckLooseLink_TMT(Current_TMT_Num()) == LooseLink_OFF) ===> currently selected TMT is LooseLink_OFF

    */

    if(CheckLooseLink_TMT(Current_TMT_Num()) == LooseLink_OK)
        AlarmRepeat2.Bit.LostLink = true;  // LostLink ??????

    if( ( Current_TMT_Num() != TMT_OFF ) && (((SCUBA_Set.TMT_On.Allbits >> (Current_TMT_Num()-1))& 0x01 ) == true)
            && (GUI_TMT_id[Current_TMT_Num()] != 0) && (CheckLooseLink_TMT(Current_TMT_Num()) == LooseLink_OFF) )
    {
        AlarmRealtime[ALARM_LostLink]++;
        AlarmInTicks[ALARM_LostLink]=TICK_ID_PLUS_1;
        Alarming2.Bit.LostLink = true;
        AlarmOccured2.Bit.LostLink = true;

        if(AlarmRepeat2.Bit.LostLink == true)
        {
            AlarmFIFO_Arrange(ALARM_LostLink);
            AlarmRepeat2.Bit.LostLink = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_LostLink]=0;
        AlarmInTicks[ALARM_LostLink]=0;
        Alarming2.Bit.LostLink = false;
    }
    //----bit-LostLink------------------------------------------------------------------




    if(OC_MODE||SM_MODE||BO_MODE)
    {
        // OCSM_MinPO2 is only allowed to resume when GasSwitchGetPO2A() > BAILOUT_OC_MIN_PO2 and retrigger again.
        if( ((GasSwitchGetPO2A() > OC_SM_MIN_PO2)&&(OC_MODE||SM_MODE)) || ((GasSwitchGetPO2A() > BO_MIN_PO2)&&(BO_MODE)) )
            AlarmRepeat2.Bit.OCSM_MinPO2 = true;  // OCSM_MinPO2 ??????

        //----bit-OCSM_MinPO2------------------------------------------------------------------
        //
        if( ((GasSwitchGetPO2A() <= OC_SM_MIN_PO2)&&(OC_MODE||SM_MODE)) || ((GasSwitchGetPO2A() <= BO_MIN_PO2)&&(BO_MODE)) )
        {
            AlarmRealtime[ALARM_OCSM_MinPO2]++;
            AlarmInTicks[ALARM_OCSM_MinPO2]=TICK_ID_PLUS_1;
            Alarming2.Bit.OCSM_MinPO2 = true;
            AlarmOccured2.Bit.OCSM_MinPO2 = true;

            if(AlarmRepeat2.Bit.OCSM_MinPO2 == true)
            {
                AlarmFIFO_Arrange(ALARM_OCSM_MinPO2);
                AlarmRepeat2.Bit.OCSM_MinPO2 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_OCSM_MinPO2]=0;
            AlarmInTicks[ALARM_OCSM_MinPO2]=0;
            Alarming2.Bit.OCSM_MinPO2 = false;
        }
        //----bit-OCSM_MinPO2------------------------------------------------------------------



        // OCSM_MinPO2 is only allowed to resume when GasSwitchGetPO2A() < BAILOUT_OC_MAX_PO2 and retrigger again.
        if( ((GasSwitchGetPO2A() < OC_SM_MAX_PO2)&&(OC_MODE||SM_MODE)) || ((GasSwitchGetPO2A() < BO_MAX_PO2)&&(BO_MODE)) )
            AlarmRepeat2.Bit.OCSM_MaxPO2 = true;  // OCSM_MaxPO2 ??????

        //----bit-OCSM_MaxPO2------------------------------------------------------------------
        //
        if( ( ((GasSwitchGetPO2A() >= OC_SM_MAX_PO2)&&(OC_MODE||SM_MODE)) || ((GasSwitchGetPO2A() >= BO_MAX_PO2)&&(BO_MODE)) ) && !DecoStatus )
        {
            AlarmRealtime[ALARM_OCSM_MaxPO2]++;
            AlarmInTicks[ALARM_OCSM_MaxPO2]=TICK_ID_PLUS_1;
            Alarming2.Bit.OCSM_MaxPO2 = true;
            AlarmOccured2.Bit.OCSM_MaxPO2 = true;

            if(AlarmRepeat2.Bit.OCSM_MaxPO2 == true)
            {
                AlarmFIFO_Arrange(ALARM_OCSM_MaxPO2);
                AlarmRepeat2.Bit.OCSM_MaxPO2 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_OCSM_MaxPO2]=0;
            AlarmInTicks[ALARM_OCSM_MaxPO2]=0;
            Alarming2.Bit.OCSM_MaxPO2 = false;
        }
        //----bit-OCSM_MaxPO2------------------------------------------------------------------



        // OCSM_MinPO2 is only allowed to resume when GasSwitchGetPO2A() < BAILOUT_OC_DECO_PO2 and retrigger again.
        if( (( GasSwitchGetPO2A() < OC_SM_DECO_PO2 )&&(OC_MODE||SM_MODE)) || (( GasSwitchGetPO2A() < BO_DECO_PO2 )&&(BO_MODE)) )
            AlarmRepeat2.Bit.OCSM_DecoPO2 = true;  // OCSM_DecoPO2 ??????

        //----bit-OCSM_DecoPO2------------------------------------------------------------------
        //
        if( ((( GasSwitchGetPO2A() >= OC_SM_DECO_PO2 )&&(OC_MODE||SM_MODE)) && DecoStatus )
                ||((( GasSwitchGetPO2A() >= BO_DECO_PO2 )&&(BO_MODE)) && DecoStatus ) )
        {
            AlarmRealtime[ALARM_OCSM_DecoPO2]++;
            AlarmInTicks[ALARM_OCSM_DecoPO2]=TICK_ID_PLUS_1;
            Alarming2.Bit.OCSM_DecoPO2 = true;
            AlarmOccured2.Bit.OCSM_DecoPO2 = true;

            if(AlarmRepeat2.Bit.OCSM_DecoPO2 == true)
            {
                AlarmFIFO_Arrange(ALARM_OCSM_DecoPO2);
                AlarmRepeat2.Bit.OCSM_DecoPO2 = false; // stop, and not repeatable throughout the same dive
            }
        }
        else // for GUI
        {
            AlarmRealtime[ALARM_OCSM_DecoPO2]=0;
            AlarmInTicks[ALARM_OCSM_DecoPO2]=0;
            Alarming2.Bit.OCSM_DecoPO2 = false;
        }
        //----bit-OCSM_DecoPO2------------------------------------------------------------------
    }


    //----bit-SystemERR------------------------------------------------------------------
    //
    if( SystemStatus.ShowDiag == true )
    {
        AlarmRealtime[ALARM_SystemERR]++;
        AlarmInTicks[ALARM_SystemERR]=TICK_ID_PLUS_1;
        Alarming2.Bit.SystemERR = true;
        AlarmOccured2.Bit.SystemERR = true;

        if(AlarmRepeat2.Bit.SystemERR == true)
        {
            AlarmFIFO_Arrange(ALARM_SystemERR);
            AlarmRepeat2.Bit.SystemERR = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_SystemERR]=0;
        AlarmInTicks[ALARM_SystemERR]=0;
        Alarming2.Bit.SystemERR = false;
    }
    //----bit-SystemERR------------------------------------------------------------------


    //----bit-TMT_LowBattWarning------------------------------------------------------------------
    //
    if( (GUI_TMT_Battery[FindTMTofGAS()] == TMT_BATT_LOW) // TMT_BATT_GOOD: normal;  TMT_BATT_LOW: TMT Low Battery
            && ( ( Current_TMT_Num() != TMT_OFF ) && (((SCUBA_Set.TMT_On.Allbits >> (Current_TMT_Num()-1))& 0x01 ) == true)
                 && (GUI_TMT_id[Current_TMT_Num()] != 0) && (CheckLooseLink_TMT(Current_TMT_Num()) == LooseLink_OK) ) )
    {
        AlarmRealtime[ALARM_TMT_LowBattWarning]++;
        AlarmInTicks[ALARM_TMT_LowBattWarning]=TICK_ID_PLUS_1;
        Alarming2.Bit.TMT_LowBattWarning = true;
        AlarmOccured2.Bit.TMT_LowBattWarning = true;

        if(AlarmRepeat2.Bit.TMT_LowBattWarning == true)
        {
            AlarmFIFO_Arrange(ALARM_TMT_LowBattWarning);
            AlarmRepeat2.Bit.TMT_LowBattWarning = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_TMT_LowBattWarning]=0;
        AlarmInTicks[ALARM_TMT_LowBattWarning]=0;
        Alarming2.Bit.TMT_LowBattWarning = false;
    }
    //----bit-TMT_LowBattWarning------------------------------------------------------------------


    //----bit-TMT_LowBattAlarm------------------------------------------------------------------
    //
    if((GUI_TMT_Battery[FindTMTofGAS()] == TMT_SEARCHING) // TMT_BATT_GOOD: normal;  TMT_BATT_LOW: TMT Low Battery, TMT_SEARCHING: TMT_SEARCHING Low Battery Alarm
            && ( ( Current_TMT_Num() != TMT_OFF ) && (((SCUBA_Set.TMT_On.Allbits >> (Current_TMT_Num()-1))& 0x01 ) == true)
                 && (GUI_TMT_id[Current_TMT_Num()] != 0) && (CheckLooseLink_TMT(Current_TMT_Num()) == LooseLink_OK) ) )
    {
        AlarmRealtime[ALARM_TMT_LowBattAlarm]++;
        AlarmInTicks[ALARM_TMT_LowBattAlarm]=TICK_ID_PLUS_1;
        Alarming2.Bit.TMT_LowBattAlarm = true;
        AlarmOccured2.Bit.TMT_LowBattAlarm = true;

        if(AlarmRepeat2.Bit.TMT_LowBattAlarm == true)
        {
            AlarmFIFO_Arrange(ALARM_TMT_LowBattAlarm);
            AlarmRepeat2.Bit.TMT_LowBattAlarm = false; // stop, and not repeatable throughout the same dive
        }
    }
    else // for GUI
    {
        AlarmRealtime[ALARM_TMT_LowBattAlarm]=0;
        AlarmInTicks[ALARM_TMT_LowBattAlarm]=0;
        Alarming2.Bit.TMT_LowBattAlarm = false;
    }
    //----bit-TMT_LowBattAlarm------------------------------------------------------------------


    // End of Alarm Linking Interface =============================================================================

    // Must to use Bit-OR logic so none of Alarms and Violations would be missed,
    // Profile_Data_Update() resets it to 0s, after passing and saving the data to profile
    AlarmProfileRec.AllBits  |= Alarming.AllBits;  // Sync-Up Current Alarming Condition and updating the data to save on Profile
    AlarmProfileRec2.AllBits |= Alarming2.AllBits; // Sync-Up Current Alarming2 Condition and updating the data to save on Profile
    Profile_Trailer.AlarmOccured.AllBits  |= Alarming.AllBits;
    Profile_Trailer.AlarmOccured2.AllBits |= Alarming2.AllBits;

    //=============================================================================================================
    // only do AlarmFIFO_Process at Tick0 (once per second), to make sure do it once per second
    //=============================================================================================================
    if(TickHandler.scheduled_tick==0)
        CurrAlarmID = AlarmFIFO_Process();      // check AlarmFIFO buffer and then
    //=============================================================================================================



    //AlarmCtr[0]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.CondiVio || AlarmOn.Bit.CondiVio)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.CondiVio = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.CondiVio==true)&&(PreAlarmOn.Bit.CondiVio==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_CondiVio]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.CondiVio = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_CondiVio]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_CondiVio]%8) == 4)||((AlarmCtr[ALARM_CondiVio]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.CondiVio = true;
        else
            AlarmState.Bit.CondiVio = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_CondiVio]==0)
        {
            AlarmOn.Bit.CondiVio = false;
            AlarmState.Bit.CondiVio = false;
        }
    }

    PreAlarmOn.Bit.CondiVio = AlarmOn.Bit.CondiVio;
    //End of AlarmCtr[0]------------------------------------------------------------------------------------


    //AlarmCtr[1]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DelayedVio1 || AlarmOn.Bit.DelayedVio1)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DelayedVio1 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DelayedVio1==true)&&(PreAlarmOn.Bit.DelayedVio1==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DelayedVio1]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DelayedVio1 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DelayedVio1]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DelayedVio1]%8) == 4)||((AlarmCtr[ALARM_DelayedVio1]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DelayedVio1 = true;
        else
            AlarmState.Bit.DelayedVio1 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DelayedVio1]==0)
        {
            AlarmOn.Bit.DelayedVio1 = false;
            AlarmState.Bit.DelayedVio1 = false;
        }
    }

    PreAlarmOn.Bit.DelayedVio1 = AlarmOn.Bit.DelayedVio1;
    //End of AlarmCtr[1]------------------------------------------------------------------------------------


    //AlarmCtr[2]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DelayedVio2 || AlarmOn.Bit.DelayedVio2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DelayedVio2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DelayedVio2==true)&&(PreAlarmOn.Bit.DelayedVio2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DelayedVio2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DelayedVio2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DelayedVio2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DelayedVio2]%8) == 4)||((AlarmCtr[ALARM_DelayedVio2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DelayedVio2 = true;
        else
            AlarmState.Bit.DelayedVio2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DelayedVio2]==0)
        {
            AlarmOn.Bit.DelayedVio2 = false;
            AlarmState.Bit.DelayedVio2 = false;
        }
    }

    PreAlarmOn.Bit.DelayedVio2 = AlarmOn.Bit.DelayedVio2;
    //End of AlarmCtr[2]------------------------------------------------------------------------------------


    //AlarmCtr[3]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DepthMax || AlarmOn.Bit.DepthMax)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DepthMax = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DepthMax==true)&&(PreAlarmOn.Bit.DepthMax==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DepthMax]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DepthMax = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DepthMax]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DepthMax]%8) == 4)||((AlarmCtr[ALARM_DepthMax]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DepthMax = true;
        else
            AlarmState.Bit.DepthMax = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DepthMax]==0)
        {
            AlarmOn.Bit.DepthMax = false;
            AlarmState.Bit.DepthMax = false;
            //AlarmRepeat.Bit.DepthMax = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DepthMax = AlarmOn.Bit.DepthMax;
    //End of AlarmCtr[3]------------------------------------------------------------------------------------


    //AlarmCtr[4]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.AscRate5 || AlarmOn.Bit.AscRate5)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.AscRate5 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.AscRate5==true)&&(PreAlarmOn.Bit.AscRate5==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_AscRate5]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.AscRate5 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_AscRate5]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_AscRate5]%8) == 4)||((AlarmCtr[ALARM_AscRate5]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.AscRate5 = true;
        else
            AlarmState.Bit.AscRate5 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_AscRate5]==0)
        {
            AlarmOn.Bit.AscRate5 = false;
            AlarmState.Bit.AscRate5 = false;
            //AlarmRepeat.Bit.AscRate5 = true;        // repeatable if occurs again
        }

        if(((AlarmCtr[ALARM_AscRate5]%8)==0)&&(ASCBGVal < 5))          // if (ASCBGVal < 5) during the ten beeps, those ten beeps would be interrupted and stopped
        {
            AlarmOn.Bit.AscRate5 = false;
            AlarmState.Bit.AscRate5 = false;
            AlarmCtr[ALARM_AscRate5]=0;
        }

    }

    PreAlarmOn.Bit.AscRate5 = AlarmOn.Bit.AscRate5;
    //End of AlarmCtr[4]------------------------------------------------------------------------------------


    //================================================================================================================================
    // for testing only, but do not remove
    //Alarm_10Seonds(&ALARM_ON.Bit.AscRate5, &AlarmOn.Bit.AscRate5, &PreAlarmOn.Bit.AscRate5, &AlarmState.Bit.AscRate5, &AlarmCtr[4]);
    // for testing only, but do not remove
    //================================================================================================================================



    //AlarmCtr[5]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.PO2_Lo || AlarmOn.Bit.PO2_Lo)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.PO2_Lo = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.PO2_Lo==true)&&(PreAlarmOn.Bit.PO2_Lo==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_PO2_Lo]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.PO2_Lo = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_PO2_Lo]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_PO2_Lo]%8) == 4)||((AlarmCtr[ALARM_PO2_Lo]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.PO2_Lo = true;
        else
            AlarmState.Bit.PO2_Lo = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_PO2_Lo]==0)
        {
            AlarmOn.Bit.PO2_Lo = false;
            AlarmState.Bit.PO2_Lo = false;
            //AlarmRepeat.Bit.PO2_Lo = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.PO2_Lo = AlarmOn.Bit.PO2_Lo;
    //End of AlarmCtr[5]------------------------------------------------------------------------------------



    //AlarmCtr[6]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.PO2_Hi || AlarmOn.Bit.PO2_Hi)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.PO2_Hi = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.PO2_Hi==true)&&(PreAlarmOn.Bit.PO2_Hi==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_PO2_Hi]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.PO2_Hi = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_PO2_Hi]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_PO2_Hi]%8) == 4)||((AlarmCtr[ALARM_PO2_Hi]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.PO2_Hi = true;
        else
            AlarmState.Bit.PO2_Hi = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_PO2_Hi]==0)
        {
            AlarmOn.Bit.PO2_Hi = false;
            AlarmState.Bit.PO2_Hi = false;
            //AlarmRepeat.Bit.PO2_Hi = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.PO2_Hi = AlarmOn.Bit.PO2_Hi;
    //End of AlarmCtr[6]------------------------------------------------------------------------------------


    //AlarmCtr[7]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DepthSet || AlarmOn.Bit.DepthSet)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DepthSet = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DepthSet==true)&&(PreAlarmOn.Bit.DepthSet==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DepthSet]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DepthSet = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DepthSet]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DepthSet]%8) == 4)||((AlarmCtr[ALARM_DepthSet]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DepthSet = true;
        else
            AlarmState.Bit.DepthSet = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DepthSet]==0)
        {
            AlarmOn.Bit.DepthSet = false;
            AlarmState.Bit.DepthSet = false;
            //AlarmRepeat.Bit.DepthSet = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DepthSet = AlarmOn.Bit.DepthSet;
    //End of AlarmCtr[7]------------------------------------------------------------------------------------



    //AlarmCtr[8]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveN2Bar || AlarmOn.Bit.DiveN2Bar)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveN2Bar = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveN2Bar==true)&&(PreAlarmOn.Bit.DiveN2Bar==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DiveN2Bar]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveN2Bar = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DiveN2Bar]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DiveN2Bar]%8) == 4)||((AlarmCtr[ALARM_DiveN2Bar]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveN2Bar = true;
        else
            AlarmState.Bit.DiveN2Bar = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DiveN2Bar]==0)
        {
            AlarmOn.Bit.DiveN2Bar = false;
            AlarmState.Bit.DiveN2Bar = false;
            //AlarmRepeat.Bit.DiveN2Bar = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DiveN2Bar = AlarmOn.Bit.DiveN2Bar;
    //End of AlarmCtr[8]------------------------------------------------------------------------------------



    //AlarmCtr[9]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.O2_80Pct || AlarmOn.Bit.O2_80Pct)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.O2_80Pct = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.O2_80Pct==true)&&(PreAlarmOn.Bit.O2_80Pct==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_O2_80Pct]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.O2_80Pct = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_O2_80Pct]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_O2_80Pct]%8) == 4)||((AlarmCtr[ALARM_O2_80Pct]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.O2_80Pct = true;
        else
            AlarmState.Bit.O2_80Pct = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_O2_80Pct]==0)
        {
            AlarmOn.Bit.O2_80Pct = false;
            AlarmState.Bit.O2_80Pct = false;
        }
    }

    PreAlarmOn.Bit.O2_80Pct = AlarmOn.Bit.O2_80Pct;
    //End of AlarmCtr[9]------------------------------------------------------------------------------------




    //AlarmCtr[10]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.O2_100Pct || AlarmOn.Bit.O2_100Pct)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.O2_100Pct = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.O2_100Pct==true)&&(PreAlarmOn.Bit.O2_100Pct==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_O2_100Pct]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.O2_100Pct = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_O2_100Pct]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_O2_100Pct]%8) == 4)||((AlarmCtr[ALARM_O2_100Pct]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.O2_100Pct = true;
        else
            AlarmState.Bit.O2_100Pct = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_O2_100Pct]==0)
        {
            AlarmOn.Bit.O2_100Pct = false;
            AlarmState.Bit.O2_100Pct = false;
        }
    }

    PreAlarmOn.Bit.O2_100Pct = AlarmOn.Bit.O2_100Pct;
    //End of AlarmCtr[10]------------------------------------------------------------------------------------



    //AlarmCtr[11]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Entry || AlarmOn.Bit.DECO_Entry)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Entry = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Entry==true)&&(PreAlarmOn.Bit.DECO_Entry==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DECO_Entry]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Entry = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DECO_Entry]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DECO_Entry]%8) == 4)||((AlarmCtr[ALARM_DECO_Entry]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Entry = true;
        else
            AlarmState.Bit.DECO_Entry = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DECO_Entry]==0)
        {
            AlarmOn.Bit.DECO_Entry = false;
            AlarmState.Bit.DECO_Entry = false;
            //AlarmRepeat.Bit.DECO_Entry = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DECO_Entry = AlarmOn.Bit.DECO_Entry;
    //End of AlarmCtr[11]------------------------------------------------------------------------------------


    //AlarmCtr[12]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveTime || AlarmOn.Bit.DiveTime)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveTime = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveTime==true)&&(PreAlarmOn.Bit.DiveTime==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DiveTime]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveTime = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DiveTime]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DiveTime]%8) == 4)||((AlarmCtr[ALARM_DiveTime]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveTime = true;
        else
            AlarmState.Bit.DiveTime = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DiveTime]==0)
        {
            AlarmOn.Bit.DiveTime = false;
            AlarmState.Bit.DiveTime = false;
        }
    }

    PreAlarmOn.Bit.DiveTime = AlarmOn.Bit.DiveTime;
    //End of AlarmCtr[12]------------------------------------------------------------------------------------



    //AlarmCtr[13]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveDTR || AlarmOn.Bit.DiveDTR)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveDTR = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveDTR==true)&&(PreAlarmOn.Bit.DiveDTR==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DiveDTR]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveDTR = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DiveDTR]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DiveDTR]%8) == 4)||((AlarmCtr[ALARM_DiveDTR]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveDTR = true;
        else
            AlarmState.Bit.DiveDTR = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DiveDTR]==0)
        {
            AlarmOn.Bit.DiveDTR = false;
            AlarmState.Bit.DiveDTR = false;
            //AlarmRepeat.Bit.DiveDTR = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DiveDTR = AlarmOn.Bit.DiveDTR;
    //End of AlarmCtr[13]------------------------------------------------------------------------------------




    //AlarmCtr[14]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.AscRate4 || AlarmOn.Bit.AscRate4)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.AscRate4 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.AscRate4==true)&&(PreAlarmOn.Bit.AscRate4==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_AscRate4]=ALARM_SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.AscRate4 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_AscRate4]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_AscRate4])
        {
        case 15:
        case 13:
        case 11:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_AscRate4]==0)
        {
            AlarmOn.Bit.AscRate4 = false;
            AlarmState.Bit.AscRate4 = false;
            //AlarmRepeat.Bit.AscRate4 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.AscRate4 = AlarmOn.Bit.AscRate4;
    //End of AlarmCtr[14]------------------------------------------------------------------------------------



    //AlarmCtr[15]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDiveT || AlarmOn.Bit.FreeDiveT)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDiveT = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDiveT==true)&&(PreAlarmOn.Bit.FreeDiveT==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeDiveT]=ALARM_SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDiveT = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeDiveT]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeDiveT])
        {
        case 15:
        case 13:
        case 11:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeDiveT]==0)
        {
            AlarmOn.Bit.FreeDiveT = false;
            AlarmState.Bit.FreeDiveT = false;
            AlarmRepeat.Bit.FreeDiveT = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDiveT = AlarmOn.Bit.FreeDiveT;
    //End of AlarmCtr[15]------------------------------------------------------------------------------------




    //AlarmCtr[16]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth1 || AlarmOn.Bit.FreeDepth1)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth1 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth1==true)&&(PreAlarmOn.Bit.FreeDepth1==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeDepth1]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth1 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeDepth1]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeDepth1])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeDepth1]==0)
        {
            AlarmOn.Bit.FreeDepth1 = false;
            AlarmState.Bit.FreeDepth1 = false;
            //AlarmRepeat.Bit.FreeDepth1 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth1 = AlarmOn.Bit.FreeDepth1;
    //End of AlarmCtr[16]------------------------------------------------------------------------------------


    //AlarmCtr[17]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth2 || AlarmOn.Bit.FreeDepth2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth2==true)&&(PreAlarmOn.Bit.FreeDepth2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeDepth2]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeDepth2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeDepth2])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth2 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth2 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeDepth2]==0)
        {
            AlarmOn.Bit.FreeDepth2 = false;
            AlarmState.Bit.FreeDepth2 = false;
            //AlarmRepeat.Bit.FreeDepth2 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth2 = AlarmOn.Bit.FreeDepth2;
    //End of AlarmCtr[17]------------------------------------------------------------------------------------


    //AlarmCtr[18]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth3 || AlarmOn.Bit.FreeDepth3)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth3 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth3==true)&&(PreAlarmOn.Bit.FreeDepth3==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeDepth3]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth3 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeDepth3]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeDepth3])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth3 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth3 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeDepth3]==0)
        {
            AlarmOn.Bit.FreeDepth3 = false;
            AlarmState.Bit.FreeDepth3 = false;
            //AlarmRepeat.Bit.FreeDepth3 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth3 = AlarmOn.Bit.FreeDepth3;
    //End of AlarmCtr[18]------------------------------------------------------------------------------------


    //AlarmCtr[19]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeN2Bar || AlarmOn.Bit.FreeN2Bar)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeN2Bar = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeN2Bar==true)&&(PreAlarmOn.Bit.FreeN2Bar==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeN2Bar]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeN2Bar = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeN2Bar]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeN2Bar])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeN2Bar = true;
            break;

        default:
            AlarmState.Bit.FreeN2Bar = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeN2Bar]==0)
        {
            AlarmOn.Bit.FreeN2Bar = false;
            AlarmState.Bit.FreeN2Bar = false;
            //AlarmRepeat.Bit.FreeN2Bar = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeN2Bar = AlarmOn.Bit.FreeN2Bar;
    //End of AlarmCtr[19]------------------------------------------------------------------------------------


    //AlarmCtr[20]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeCDT || AlarmOn.Bit.FreeCDT)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeCDT = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeCDT==true)&&(PreAlarmOn.Bit.FreeCDT==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeCDT]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeCDT = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeCDT]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeCDT])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeCDT = true;
            break;

        default:
            AlarmState.Bit.FreeCDT = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeCDT]==0)
        {
            AlarmOn.Bit.FreeCDT = false;
            AlarmState.Bit.FreeCDT = false;
            //AlarmRepeat.Bit.FreeCDT = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeCDT = AlarmOn.Bit.FreeCDT;
    //End of AlarmCtr[20]------------------------------------------------------------------------------------


    //AlarmCtr[21]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeViol || AlarmOn.Bit.FreeViol)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeViol = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeViol==true)&&(PreAlarmOn.Bit.FreeViol==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_FreeViol]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeViol = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_FreeViol]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[ALARM_FreeViol])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeViol = true;
            break;

        default:
            AlarmState.Bit.FreeViol = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_FreeViol]==0)
        {
            AlarmOn.Bit.FreeViol = false;
            AlarmState.Bit.FreeViol = false;
        }
    }

    PreAlarmOn.Bit.FreeViol = AlarmOn.Bit.FreeViol;
    //End of AlarmCtr[21]------------------------------------------------------------------------------------


    //AlarmCtr[22]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Depth70 || AlarmOn.Bit.DECO_Depth70)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Depth70 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Depth70==true)&&(PreAlarmOn.Bit.DECO_Depth70==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DECO_Depth70]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Depth70 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DECO_Depth70]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DECO_Depth70]%8) == 4)||((AlarmCtr[ALARM_DECO_Depth70]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Depth70 = true;
        else
            AlarmState.Bit.DECO_Depth70 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DECO_Depth70]==0)
        {
            AlarmOn.Bit.DECO_Depth70 = false;
            AlarmState.Bit.DECO_Depth70 = false;
        }
    }


    PreAlarmOn.Bit.DECO_Depth70 = AlarmOn.Bit.DECO_Depth70;
    //End of AlarmCtr[22]------------------------------------------------------------------------------------


    //AlarmCtr[23]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.SwitchFO2 || AlarmOn.Bit.SwitchFO2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.SwitchFO2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.SwitchFO2==true)&&(PreAlarmOn.Bit.SwitchFO2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_SwitchFO2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.SwitchFO2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_SwitchFO2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_SwitchFO2]%8) == 4)||((AlarmCtr[ALARM_SwitchFO2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.SwitchFO2 = true;
        else
            AlarmState.Bit.SwitchFO2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_SwitchFO2]==0)
        {
            AlarmOn.Bit.SwitchFO2 = false;
            AlarmState.Bit.SwitchFO2 = false;
        }
    }

    PreAlarmOn.Bit.SwitchFO2 = AlarmOn.Bit.SwitchFO2;
    //End of AlarmCtr[23]------------------------------------------------------------------------------------


    //AlarmCtr[24]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.SetupVIOLATION || AlarmOn.Bit.SetupVIOLATION)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.SetupVIOLATION = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.SetupVIOLATION==true)&&(PreAlarmOn.Bit.SetupVIOLATION==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_SetupVIOLATION]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.SetupVIOLATION = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_SetupVIOLATION]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_SetupVIOLATION]%8) == 4)||((AlarmCtr[ALARM_SetupVIOLATION]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.SetupVIOLATION = true;
        else
            AlarmState.Bit.SetupVIOLATION = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_SetupVIOLATION]==0)
        {
            AlarmOn.Bit.SetupVIOLATION = false;
            AlarmState.Bit.SetupVIOLATION = false;
        }
    }

    PreAlarmOn.Bit.SetupVIOLATION = AlarmOn.Bit.SetupVIOLATION;
    //End of AlarmCtr[24]------------------------------------------------------------------------------------


    //AlarmCtr[25]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Warning || AlarmOn.Bit.DECO_Warning)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Warning = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Warning==true)&&(PreAlarmOn.Bit.DECO_Warning==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DECO_Warning]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Warning = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DECO_Warning]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DECO_Warning]%8) == 4)||((AlarmCtr[ALARM_DECO_Warning]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Warning = true;
        else
            AlarmState.Bit.DECO_Warning = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DECO_Warning]==0)
        {
            AlarmOn.Bit.DECO_Warning = false;
            AlarmState.Bit.DECO_Warning = false;
        }
    }

    PreAlarmOn.Bit.DECO_Warning = AlarmOn.Bit.DECO_Warning;
    //End of AlarmCtr[25]------------------------------------------------------------------------------------


    //AlarmCtr[26]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Alarm || AlarmOn.Bit.DECO_Alarm)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Alarm = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Alarm==true)&&(PreAlarmOn.Bit.DECO_Alarm==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_DECO_Alarm]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Alarm = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_DECO_Alarm]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_DECO_Alarm]%8) == 4)||((AlarmCtr[ALARM_DECO_Alarm]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Alarm = true;
        else
            AlarmState.Bit.DECO_Alarm = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_DECO_Alarm]==0)
        {
            AlarmOn.Bit.DECO_Alarm = false;
            AlarmState.Bit.DECO_Alarm = false;
        }
    }

    PreAlarmOn.Bit.DECO_Alarm = AlarmOn.Bit.DECO_Alarm;
    //End of AlarmCtr[26]------------------------------------------------------------------------------------


    //AlarmCtr[27]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.GFBG_Alarm || AlarmOn.Bit.GFBG_Alarm)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.GFBG_Alarm = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.GFBG_Alarm==true)&&(PreAlarmOn.Bit.GFBG_Alarm==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_GFBG_Alarm]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.GFBG_Alarm = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_GFBG_Alarm]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_GFBG_Alarm]%8) == 4)||((AlarmCtr[ALARM_GFBG_Alarm]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.GFBG_Alarm = true;
        else
            AlarmState.Bit.GFBG_Alarm = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_GFBG_Alarm]==0)
        {
            AlarmOn.Bit.GFBG_Alarm = false;
            AlarmState.Bit.GFBG_Alarm = false;
        }
    }

    PreAlarmOn.Bit.GFBG_Alarm = AlarmOn.Bit.GFBG_Alarm;
    //End of AlarmCtr[27]------------------------------------------------------------------------------------


    //For Future AlarmCtr[28]--------------------------------------------------------------------------------


    //AlarmCtr[29]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.NoOpShutdown || AlarmOn.Bit.NoOpShutdown)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.NoOpShutdown = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.NoOpShutdown==true)&&(PreAlarmOn.Bit.NoOpShutdown==false))        // check if time for new alarm cycle
        {
            AlarmCtr[29]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.NoOpShutdown = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[29]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[29]%8) == 4)||((AlarmCtr[29]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.NoOpShutdown = true;
        else
            AlarmState.Bit.NoOpShutdown = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[29]==0)
        {
            AlarmOn.Bit.NoOpShutdown = false;
            AlarmState.Bit.NoOpShutdown = false;
        }
    }

    PreAlarmOn.Bit.LowBattWarning = AlarmOn.Bit.LowBattWarning;
    //End of AlarmCtr[29]------------------------------------------------------------------------------------


    //AlarmCtr[30]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.LowBattWarning || AlarmOn.Bit.LowBattWarning)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.LowBattWarning = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.LowBattWarning==true)&&(PreAlarmOn.Bit.LowBattWarning==false))        // check if time for new alarm cycle
        {
            AlarmCtr[30]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.LowBattWarning = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[30]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[30]%8) == 4)||((AlarmCtr[30]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.LowBattWarning = true;
        else
            AlarmState.Bit.LowBattWarning = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[30]==0)
        {
            AlarmOn.Bit.LowBattWarning = false;
            AlarmState.Bit.LowBattWarning = false;
        }
    }

    PreAlarmOn.Bit.LowBattWarning = AlarmOn.Bit.LowBattWarning;
    //End of AlarmCtr[30]------------------------------------------------------------------------------------



    //AlarmCtr[31]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.LowBattAlarm || AlarmOn.Bit.LowBattAlarm)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.LowBattAlarm = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.LowBattAlarm==true)&&(PreAlarmOn.Bit.LowBattAlarm==false))        // check if time for new alarm cycle
        {
            AlarmCtr[31]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.LowBattAlarm = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[31]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[31]%8) == 4)||((AlarmCtr[31]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.LowBattAlarm = true;
        else
            AlarmState.Bit.LowBattAlarm = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[31]==0)
        {
            AlarmOn.Bit.LowBattAlarm = false;
            AlarmState.Bit.LowBattAlarm = false;
        }
    }

    PreAlarmOn.Bit.LowBattAlarm = AlarmOn.Bit.LowBattAlarm;
    //End of AlarmCtr[31]------------------------------------------------------------------------------------


    if(CC_MODE)
    {
        //AlarmCtr[32]-------------------------------------------------------------------------------------------
        if(ALARM_ON2.Bit.SP_AutoHi || AlarmOn2.Bit.SP_AutoHi)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
        {
            AlarmOn2.Bit.SP_AutoHi = true;      // start the Alarm On cycle to the end

            // Initialize and start this alarm cycle
            if((AlarmOn2.Bit.SP_AutoHi==true)&&(PreAlarmOn2.Bit.SP_AutoHi==false))        // check if time for new alarm cycle
            {
                AlarmCtr[ALARM_SP_AutoHi]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
                ALARM_ON2.Bit.SP_AutoHi = false;    // make if momentary, needs a new trigger to do the same alarm again
            }

            AlarmCtr[ALARM_SP_AutoHi]--;

            //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
            if(((AlarmCtr[ALARM_SP_AutoHi]%8) == 4)||((AlarmCtr[ALARM_SP_AutoHi]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
                AlarmState2.Bit.SP_AutoHi = true;
            else
                AlarmState2.Bit.SP_AutoHi = false;
            //----------------------------------------------------------------------------------------------------

            if(AlarmCtr[ALARM_SP_AutoHi]==0)
            {
                AlarmOn2.Bit.SP_AutoHi = false;
                AlarmState2.Bit.SP_AutoHi = false;
            }
        }

        PreAlarmOn2.Bit.SP_AutoHi = AlarmOn2.Bit.SP_AutoHi;
        //End of AlarmCtr[32]------------------------------------------------------------------------------------



        //AlarmCtr[33]-------------------------------------------------------------------------------------------
        if(ALARM_ON2.Bit.SP_AutoLo || AlarmOn2.Bit.SP_AutoLo)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
        {
            AlarmOn2.Bit.SP_AutoLo = true;      // start the Alarm On cycle to the end

            // Initialize and start this alarm cycle
            if((AlarmOn2.Bit.SP_AutoLo==true)&&(PreAlarmOn2.Bit.SP_AutoLo==false))        // check if time for new alarm cycle
            {
                AlarmCtr[ALARM_SP_AutoLo]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
                ALARM_ON2.Bit.SP_AutoLo = false;    // make if momentary, needs a new trigger to do the same alarm again
            }

            AlarmCtr[ALARM_SP_AutoLo]--;

            //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
            if(((AlarmCtr[ALARM_SP_AutoLo]%8) == 4)||((AlarmCtr[ALARM_SP_AutoLo]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
                AlarmState2.Bit.SP_AutoLo = true;
            else
                AlarmState2.Bit.SP_AutoLo = false;
            //----------------------------------------------------------------------------------------------------

            if(AlarmCtr[ALARM_SP_AutoLo]==0)
            {
                AlarmOn2.Bit.SP_AutoLo = false;
                AlarmState2.Bit.SP_AutoLo = false;
            }
        }

        PreAlarmOn2.Bit.SP_AutoLo = AlarmOn2.Bit.SP_AutoLo;
        //End of AlarmCtr[33]------------------------------------------------------------------------------------
    }

    if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)
    {
        //AlarmCtr[34]-------------------------------------------------------------------------------------------
        if(ALARM_ON2.Bit.TEC_GF_Hi || AlarmOn2.Bit.TEC_GF_Hi)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
        {
            AlarmOn2.Bit.TEC_GF_Hi = true;      // start the Alarm On cycle to the end

            // Initialize and start this alarm cycle
            if((AlarmOn2.Bit.TEC_GF_Hi==true)&&(PreAlarmOn2.Bit.TEC_GF_Hi==false))        // check if time for new alarm cycle
            {
                AlarmCtr[ALARM_TEC_GF_Hi]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
                ALARM_ON2.Bit.TEC_GF_Hi = false;    // make if momentary, needs a new trigger to do the same alarm again
            }

            AlarmCtr[ALARM_TEC_GF_Hi]--;

            //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
            if(((AlarmCtr[ALARM_TEC_GF_Hi]%8) == 4)||((AlarmCtr[ALARM_TEC_GF_Hi]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
                AlarmState2.Bit.TEC_GF_Hi = true;
            else
                AlarmState2.Bit.TEC_GF_Hi = false;
            //----------------------------------------------------------------------------------------------------

            if(AlarmCtr[ALARM_TEC_GF_Hi]==0)
            {
                AlarmOn2.Bit.TEC_GF_Hi = false;
                AlarmState2.Bit.TEC_GF_Hi = false;
            }
        }

        PreAlarmOn2.Bit.TEC_GF_Hi = AlarmOn2.Bit.TEC_GF_Hi;
        //End of AlarmCtr[34]------------------------------------------------------------------------------------



        //AlarmCtr[35]-------------------------------------------------------------------------------------------
        if(ALARM_ON2.Bit.TEC_GF_Lo || AlarmOn2.Bit.TEC_GF_Lo)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
        {
            AlarmOn2.Bit.TEC_GF_Lo = true;      // start the Alarm On cycle to the end

            // Initialize and start this alarm cycle
            if((AlarmOn2.Bit.TEC_GF_Lo==true)&&(PreAlarmOn2.Bit.TEC_GF_Lo==false))        // check if time for new alarm cycle
            {
                AlarmCtr[ALARM_TEC_GF_Lo]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
                ALARM_ON2.Bit.TEC_GF_Lo = false;    // make if momentary, needs a new trigger to do the same alarm again
            }

            AlarmCtr[ALARM_TEC_GF_Lo]--;

            //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
            if(((AlarmCtr[ALARM_TEC_GF_Lo]%8) == 4)||((AlarmCtr[ALARM_TEC_GF_Lo]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
                AlarmState2.Bit.TEC_GF_Lo = true;
            else
                AlarmState2.Bit.TEC_GF_Lo = false;
            //----------------------------------------------------------------------------------------------------

            if(AlarmCtr[ALARM_TEC_GF_Lo]==0)
            {
                AlarmOn2.Bit.TEC_GF_Lo = false;
                AlarmState2.Bit.TEC_GF_Lo = false;
            }
        }

        PreAlarmOn2.Bit.TEC_GF_Lo = AlarmOn2.Bit.TEC_GF_Lo;
        //End of AlarmCtr[35]------------------------------------------------------------------------------------
    }// End if(CC_MODE||OC_MODE||SM_MODE||BO_MODE)



    //AlarmCtr[36]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.TTS_T || AlarmOn2.Bit.TTS_T)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.TTS_T = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.TTS_T==true)&&(PreAlarmOn2.Bit.TTS_T==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_TTS_T]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.TTS_T = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_TTS_T]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_TTS_T]%8) == 4)||((AlarmCtr[ALARM_TTS_T]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.TTS_T = true;
        else
            AlarmState2.Bit.TTS_T = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_TTS_T]==0)
        {
            AlarmOn2.Bit.TTS_T = false;
            AlarmState2.Bit.TTS_T = false;
        }
    }

    PreAlarmOn2.Bit.TTS_T = AlarmOn2.Bit.TTS_T;
    //End of AlarmCtr[36]------------------------------------------------------------------------------------




    //AlarmCtr[37]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.TankP || AlarmOn2.Bit.TankP)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.TankP = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.TankP==true)&&(PreAlarmOn2.Bit.TankP==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_TankP]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.TankP = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_TankP]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_TankP]%8) == 4)||((AlarmCtr[ALARM_TankP]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.TankP = true;
        else
            AlarmState2.Bit.TankP = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_TankP]==0)
        {
            AlarmOn2.Bit.TankP = false;
            AlarmState2.Bit.TankP = false;
        }
    }

    PreAlarmOn2.Bit.TankP = AlarmOn2.Bit.TankP;
    //End of AlarmCtr[37]------------------------------------------------------------------------------------



    //AlarmCtr[38]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.CC6P || AlarmOn2.Bit.CC6P)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.CC6P = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.CC6P==true)&&(PreAlarmOn2.Bit.CC6P==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_CC6P]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.CC6P = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_CC6P]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_CC6P]%8) == 4)||((AlarmCtr[ALARM_CC6P]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.CC6P = true;
        else
            AlarmState2.Bit.CC6P = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_CC6P]==0)
        {
            AlarmOn2.Bit.CC6P = false;
            AlarmState2.Bit.CC6P = false;
        }
    }

    PreAlarmOn2.Bit.CC6P = AlarmOn2.Bit.CC6P;
    //End of AlarmCtr[38]------------------------------------------------------------------------------------



    //AlarmCtr[39]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.TurnP || AlarmOn2.Bit.TurnP)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.TurnP = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.TurnP==true)&&(PreAlarmOn2.Bit.TurnP==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_TurnP]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.TurnP = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_TurnP]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_TurnP]%8) == 4)||((AlarmCtr[ALARM_TurnP]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.TurnP = true;
        else
            AlarmState2.Bit.TurnP = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_TurnP]==0)
        {
            AlarmOn2.Bit.TurnP = false;
            AlarmState2.Bit.TurnP = false;
        }
    }

    PreAlarmOn2.Bit.TurnP = AlarmOn2.Bit.TurnP;
    //End of AlarmCtr[39]------------------------------------------------------------------------------------



    //AlarmCtr[40]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.EndP || AlarmOn2.Bit.EndP)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.EndP = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.EndP==true)&&(PreAlarmOn2.Bit.EndP==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_EndP]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.EndP = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_EndP]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_EndP]%8) == 4)||((AlarmCtr[ALARM_EndP]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.EndP = true;
        else
            AlarmState2.Bit.EndP = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_EndP]==0)
        {
            AlarmOn2.Bit.EndP = false;
            AlarmState2.Bit.EndP = false;
        }
    }

    PreAlarmOn2.Bit.EndP = AlarmOn2.Bit.EndP;
    //End of AlarmCtr[40]------------------------------------------------------------------------------------



    //AlarmCtr[41]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.SwitchP || AlarmOn2.Bit.SwitchP)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.SwitchP = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.SwitchP==true)&&(PreAlarmOn2.Bit.SwitchP==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_SwitchP]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.SwitchP = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_SwitchP]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_SwitchP]%8) == 4)||((AlarmCtr[ALARM_SwitchP]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.SwitchP = true;
        else
            AlarmState2.Bit.SwitchP = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_SwitchP]==0)
        {
            AlarmOn2.Bit.SwitchP = false;
            AlarmState2.Bit.SwitchP = false;
        }
    }

    PreAlarmOn2.Bit.SwitchP = AlarmOn2.Bit.SwitchP;
    //End of AlarmCtr[41]------------------------------------------------------------------------------------



    //AlarmCtr[42]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.GF || AlarmOn2.Bit.GF)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.GF = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.GF==true)&&(PreAlarmOn2.Bit.GF==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_GF]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.GF = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_GF]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_GF]%8) == 4)||((AlarmCtr[ALARM_GF]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.GF = true;
        else
            AlarmState2.Bit.GF = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_GF]==0)
        {
            AlarmOn2.Bit.GF = false;
            AlarmState2.Bit.GF = false;
        }
    }

    PreAlarmOn2.Bit.GF = AlarmOn2.Bit.GF;
    //End of AlarmCtr[42]------------------------------------------------------------------------------------



    //AlarmCtr[43]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.N2 || AlarmOn2.Bit.N2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.N2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.N2==true)&&(PreAlarmOn2.Bit.N2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_N2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.N2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_N2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_N2]%8) == 4)||((AlarmCtr[ALARM_N2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.N2 = true;
        else
            AlarmState2.Bit.N2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_N2]==0)
        {
            AlarmOn2.Bit.N2 = false;
            AlarmState2.Bit.N2 = false;
        }
    }

    PreAlarmOn2.Bit.N2 = AlarmOn2.Bit.N2;
    //End of AlarmCtr[43]------------------------------------------------------------------------------------



    //AlarmCtr[44]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.End || AlarmOn2.Bit.End)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.End = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.End==true)&&(PreAlarmOn2.Bit.End==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_End]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.End = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_End]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_End]%8) == 4)||((AlarmCtr[ALARM_End]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.End = true;
        else
            AlarmState2.Bit.End = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_End]==0)
        {
            AlarmOn2.Bit.End = false;
            AlarmState2.Bit.End = false;
        }
    }

    PreAlarmOn2.Bit.End = AlarmOn2.Bit.End;
    //End of AlarmCtr[44]------------------------------------------------------------------------------------



    //AlarmCtr[45]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.WOB || AlarmOn2.Bit.WOB)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.WOB = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.WOB==true)&&(PreAlarmOn2.Bit.WOB==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_WOB]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.WOB = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_WOB]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_WOB]%8) == 4)||((AlarmCtr[ALARM_WOB]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.WOB = true;
        else
            AlarmState2.Bit.WOB = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_WOB]==0)
        {
            AlarmOn2.Bit.WOB = false;
            AlarmState2.Bit.WOB = false;
        }
    }

    PreAlarmOn2.Bit.WOB = AlarmOn2.Bit.WOB;
    //End of AlarmCtr[45]------------------------------------------------------------------------------------



    //AlarmCtr[46]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.ICD || AlarmOn2.Bit.ICD)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.ICD = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.ICD==true)&&(PreAlarmOn2.Bit.ICD==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_ICD]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.ICD= false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_ICD]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_ICD]%8) == 4)||((AlarmCtr[ALARM_ICD]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.ICD = true;
        else
            AlarmState2.Bit.ICD = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_ICD]==0)
        {
            AlarmOn2.Bit.ICD = false;
            AlarmState2.Bit.ICD = false;
        }
    }

    PreAlarmOn2.Bit.ICD = AlarmOn2.Bit.ICD;
    //End of AlarmCtr[46]------------------------------------------------------------------------------------



    //AlarmCtr[47]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.Narcotic || AlarmOn2.Bit.Narcotic)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.Narcotic = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.Narcotic==true)&&(PreAlarmOn2.Bit.Narcotic==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_Narcotic]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.Narcotic = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_Narcotic]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_Narcotic]%8) == 4)||((AlarmCtr[ALARM_Narcotic]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.Narcotic = true;
        else
            AlarmState2.Bit.Narcotic = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_Narcotic]==0)
        {
            AlarmOn2.Bit.Narcotic = false;
            AlarmState2.Bit.Narcotic = false;
        }
    }

    PreAlarmOn2.Bit.Narcotic = AlarmOn2.Bit.Narcotic;
    //End of AlarmCtr[47]------------------------------------------------------------------------------------



    //AlarmCtr[48]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.GTR5 || AlarmOn2.Bit.GTR5)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.GTR5 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.GTR5==true)&&(PreAlarmOn2.Bit.GTR5==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_GTR5]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.GTR5 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_GTR5]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_GTR5]%8) == 4)||((AlarmCtr[ALARM_GTR5]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.GTR5 = true;
        else
            AlarmState2.Bit.GTR5 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_GTR5]==0)
        {
            AlarmOn2.Bit.GTR5 = false;
            AlarmState2.Bit.GTR5 = false;
        }
    }

    PreAlarmOn2.Bit.GTR5 = AlarmOn2.Bit.GTR5;
    //End of AlarmCtr[48]------------------------------------------------------------------------------------



    //AlarmCtr[49]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.GTR0 || AlarmOn2.Bit.GTR0)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.GTR0 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.GTR0==true)&&(PreAlarmOn2.Bit.GTR0==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_GTR0]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.GTR0 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_GTR0]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_GTR0]%8) == 4)||((AlarmCtr[ALARM_GTR0]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.GTR0 = true;
        else
            AlarmState2.Bit.GTR0 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_GTR0]==0)
        {
            AlarmOn2.Bit.GTR0 = false;
            AlarmState2.Bit.GTR0 = false;
        }
    }

    PreAlarmOn2.Bit.GTR0 = AlarmOn2.Bit.GTR0;
    //End of AlarmCtr[49]------------------------------------------------------------------------------------



    //AlarmCtr[50]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.LostLink || AlarmOn2.Bit.LostLink)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.LostLink = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.LostLink==true)&&(PreAlarmOn2.Bit.LostLink==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_LostLink]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.LostLink = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_LostLink]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_LostLink]%8) == 4)||((AlarmCtr[ALARM_LostLink]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.LostLink = true;
        else
            AlarmState2.Bit.LostLink = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_LostLink]==0)
        {
            AlarmOn2.Bit.LostLink = false;
            AlarmState2.Bit.LostLink = false;
        }
    }

    PreAlarmOn2.Bit.LostLink = AlarmOn2.Bit.LostLink;
    //End of AlarmCtr[50]------------------------------------------------------------------------------------


    //AlarmCtr[51]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.OCSM_MinPO2 || AlarmOn2.Bit.OCSM_MinPO2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.OCSM_MinPO2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.OCSM_MinPO2==true)&&(PreAlarmOn2.Bit.OCSM_MinPO2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_OCSM_MinPO2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.OCSM_MinPO2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_OCSM_MinPO2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_OCSM_MinPO2]%8) == 4)||((AlarmCtr[ALARM_OCSM_MinPO2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.OCSM_MinPO2 = true;
        else
            AlarmState2.Bit.OCSM_MinPO2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_OCSM_MinPO2]==0)
        {
            AlarmOn2.Bit.OCSM_MinPO2 = false;
            AlarmState2.Bit.OCSM_MinPO2 = false;
        }
    }

    PreAlarmOn2.Bit.OCSM_MinPO2 = AlarmOn2.Bit.OCSM_MinPO2;
    //End of AlarmCtr[51]------------------------------------------------------------------------------------



    //AlarmCtr[52]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.OCSM_MaxPO2 || AlarmOn2.Bit.OCSM_MaxPO2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.OCSM_MaxPO2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.OCSM_MaxPO2==true)&&(PreAlarmOn2.Bit.OCSM_MaxPO2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_OCSM_MaxPO2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.OCSM_MaxPO2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_OCSM_MaxPO2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_OCSM_MaxPO2]%8) == 4)||((AlarmCtr[ALARM_OCSM_MaxPO2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.OCSM_MaxPO2 = true;
        else
            AlarmState2.Bit.OCSM_MaxPO2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_OCSM_MaxPO2]==0)
        {
            AlarmOn2.Bit.OCSM_MaxPO2 = false;
            AlarmState2.Bit.OCSM_MaxPO2 = false;
        }
    }

    PreAlarmOn2.Bit.OCSM_MaxPO2 = AlarmOn2.Bit.OCSM_MaxPO2;
    //End of AlarmCtr[52]------------------------------------------------------------------------------------



    //AlarmCtr[53]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.OCSM_DecoPO2 || AlarmOn2.Bit.OCSM_DecoPO2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.OCSM_DecoPO2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.OCSM_DecoPO2==true)&&(PreAlarmOn2.Bit.OCSM_DecoPO2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_OCSM_DecoPO2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.OCSM_DecoPO2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_OCSM_DecoPO2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_OCSM_DecoPO2]%8) == 4)||((AlarmCtr[ALARM_OCSM_DecoPO2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.OCSM_DecoPO2 = true;
        else
            AlarmState2.Bit.OCSM_DecoPO2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_OCSM_DecoPO2]==0)
        {
            AlarmOn2.Bit.OCSM_DecoPO2 = false;
            AlarmState2.Bit.OCSM_DecoPO2 = false;
        }
    }

    PreAlarmOn2.Bit.OCSM_DecoPO2 = AlarmOn2.Bit.OCSM_DecoPO2;
    //End of AlarmCtr[53]------------------------------------------------------------------------------------

    /*
            AlarmRealtime[ALARM_SystemERR]=0;
            AlarmInTicks[ALARM_SystemERR]=0;
            Alarming2.Bit.SystemERR = false;
    */


    //AlarmCtr[61]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.SystemERR || AlarmOn2.Bit.SystemERR)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.SystemERR = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.SystemERR==true)&&(PreAlarmOn2.Bit.SystemERR==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_SystemERR]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.SystemERR = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_SystemERR]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_SystemERR]%8) == 4)||((AlarmCtr[ALARM_SystemERR]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.SystemERR = true;
        else
            AlarmState2.Bit.SystemERR = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_SystemERR]==0)
        {
            AlarmOn2.Bit.SystemERR = false;
            AlarmState2.Bit.SystemERR = false;
        }
    }

    PreAlarmOn2.Bit.SystemERR = AlarmOn2.Bit.SystemERR;
    //End of AlarmCtr[61]------------------------------------------------------------------------------------



    //AlarmCtr[62]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.TMT_LowBattWarning || AlarmOn2.Bit.TMT_LowBattWarning)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.TMT_LowBattWarning = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.TMT_LowBattWarning==true)&&(PreAlarmOn2.Bit.TMT_LowBattWarning==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_TMT_LowBattWarning]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.TMT_LowBattWarning = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_TMT_LowBattWarning]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_TMT_LowBattWarning]%8) == 4)||((AlarmCtr[ALARM_TMT_LowBattWarning]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.TMT_LowBattWarning = true;
        else
            AlarmState2.Bit.TMT_LowBattWarning = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_TMT_LowBattWarning]==0)
        {
            AlarmOn2.Bit.TMT_LowBattWarning = false;
            AlarmState2.Bit.TMT_LowBattWarning = false;
        }
    }

    PreAlarmOn2.Bit.TMT_LowBattWarning = AlarmOn2.Bit.TMT_LowBattWarning;
    //End of AlarmCtr[62]------------------------------------------------------------------------------------



    //AlarmCtr[63]-------------------------------------------------------------------------------------------
    if(ALARM_ON2.Bit.TMT_LowBattAlarm || AlarmOn2.Bit.TMT_LowBattAlarm)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn2.Bit.TMT_LowBattAlarm = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn2.Bit.TMT_LowBattAlarm==true)&&(PreAlarmOn2.Bit.TMT_LowBattAlarm==false))        // check if time for new alarm cycle
        {
            AlarmCtr[ALARM_TMT_LowBattAlarm]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON2.Bit.TMT_LowBattAlarm = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[ALARM_TMT_LowBattAlarm]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[ALARM_TMT_LowBattAlarm]%8) == 4)||((AlarmCtr[ALARM_TMT_LowBattAlarm]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState2.Bit.TMT_LowBattAlarm = true;
        else
            AlarmState2.Bit.TMT_LowBattAlarm = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[ALARM_TMT_LowBattAlarm]==0)
        {
            AlarmOn2.Bit.TMT_LowBattAlarm = false;
            AlarmState2.Bit.TMT_LowBattAlarm = false;
        }
    }

    PreAlarmOn2.Bit.TMT_LowBattAlarm = AlarmOn2.Bit.TMT_LowBattAlarm;
    //End of AlarmCtr[63]------------------------------------------------------------------------------------




    //--Combined Logic---------------------------------------------------------------------------------------
    if((AlarmState.AllBits != 0)||(AlarmState2.AllBits != 0))
    {
        //----------------------------- All following Alarms/Warnings run during Dive Mode -----------------------------------------------
        if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
        {
            if(USER_Set.SwitchSet.Bit.AlarmAudible)
                SystemStatus.buzzer_on_req = true;      //Buzzer_On(); during Dive time, for all alarms

            if(USER_Set.SwitchSet.Bit.AlarmVibeOn)
                SystemStatus.vibe_on_req = true;
        }
        //---------------------------------------------------------------------------------------------------------------------------------

        //----------------------------- All following Alarms/Warnings also run during After-Dive, Surface and NewDay Modes ----------------
        if( ( (Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)||(Dive_Info.Status==AMB_DIVEINFO_SURF)||(Dive_Info.Status==AMB_DIVEINFO_NEWDAY) )
                &&(  (AlarmState.Bit.FreeCDT==true)||(AlarmState.Bit.O2_100Pct==true)
                     ||(AlarmState.Bit.NoOpShutdown==true)||(AlarmState.Bit.LowBattWarning==true)||(AlarmState.Bit.LowBattAlarm ==true)
                     ||(AlarmState2.Bit.GF==true)||(AlarmState2.Bit.N2 ==true)||(AlarmState2.Bit.SystemERR==true) ) )
        {
            if(USER_Set.SwitchSet.Bit.AlarmAudible)
                SystemStatus.buzzer_on_req = true;      //Buzzer_On(); during Surf time, for all alarms

            if(USER_Set.SwitchSet.Bit.AlarmVibeOn)
                SystemStatus.vibe_on_req = true;
        }
        //---------------------------------------------------------------------------------------------------------------------------------

    }  //--Combined Logic---------------------------------------------------------------------------------------

    if((((((Alarming.AllBits & 0x3FFFFFFF)!=0)||((Alarming2.AllBits & 0x3FFFFFFF)!=0))&&(Dive_Info.Status==AMB_DIVEINFO_DIVE))||((Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)))
            &&(SystemStatus.backlight_on==BACKLIGHT_DIM))    // When (Dim at (Dive && Alarming)), or (Dim at After-Dive), request Normal Brightness
        SystemStatus.backlight_on_req = true;    // return to normal brightness if any alarming, only do this during dive mode

}


/*******************************************************************************
    Some Alarm would stop (like straight to its ending)
    as soon as the alarm triggerig condition is out.

    Then the following special restoration treatment (or alarm reset) is needed

*******************************************************************************/
void ImmediateStopAlarmCheck(void)
{
    //===================PO2_Lo Alarm against to the Set Point===================
    if( (Dive_Info.DiveTime_s > 10)     // make sure PO2 alarm triggered during diving
            &&( ((SCUBA_Set.FO2A[CURRENT_TANK_NUM]>=21)&&(100*PO2atDepth < (SCUBA_Set.PO2A[CURRENT_TANK_NUM])))    // for FO2 = 21% to 100%, , Alarm threshold is calculated at PO2A[0]
                ||((SCUBA_Set.FO2A[CURRENT_TANK_NUM]<21)&&(100*PO2atDepth < 160))) )                  // for AIR, Alarm threshold fixed at 1.60
    {
        AlarmCtr[ALARM_PO2_Lo]=0;
        AlarmOn.Bit.PO2_Lo = false;    // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.PO2_Lo = false; // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_PO2_Lo]=0;
        AlarmInTicks[ALARM_PO2_Lo]=0;
        Alarming.Bit.PO2_Lo = false;
    }

    //===================PO2_Hi Alarm against to the Set Point===================
    if( (Dive_Info.DiveTime_s > 10)     // make sure PO2 alarm triggered during diving
            &&( ((SCUBA_Set.FO2A[CURRENT_TANK_NUM]>=21)&&(100*PO2atDepth < (SCUBA_Set.PO2A[CURRENT_TANK_NUM])))    // for FO2 = 21% to 100%, , Alarm threshold is calculated at PO2A[0]
                ||((SCUBA_Set.FO2A[CURRENT_TANK_NUM]<21)&&(100*PO2atDepth < 160))) )                  // for AIR, Alarm threshold fixed at 1.60
    {
        AlarmCtr[ALARM_PO2_Hi]=0;
        AlarmOn.Bit.PO2_Hi = false;    // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.PO2_Hi = false; // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_PO2_Hi]=0;
        AlarmInTicks[ALARM_PO2_Hi]=0;
        Alarming.Bit.PO2_Hi = false;
    }




    //===================CondiVio Alarm against to the Set Point===================
    if((ConditionTime == 0)||((DVSTAT&0xF0)!=0x70))
    {
        AlarmCtr[ALARM_CondiVio]=0;
        AlarmOn.Bit.CondiVio = false;    // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.CondiVio = false; // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_CondiVio]=0;
        AlarmInTicks[ALARM_CondiVio]=0;
        Alarming.Bit.CondiVio = false;
    }




    //===================N2 Bar Alarm against to the Set Point===================
    if(TLBGVal < N2_ALARM_DATA)
    {
        AlarmCtr[ALARM_DiveN2Bar]=0;
        AlarmOn.Bit.DiveN2Bar = false;    // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.DiveN2Bar = false; // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_DiveN2Bar]=0;
        AlarmInTicks[ALARM_DiveN2Bar]=0;
        Alarming.Bit.DiveN2Bar = false;
    }




    //===================Depth Alarm against to the Set Point===================
    if(UNITS==NVD_IMPERIAL)
    {
        if((Dive_Info.WaterDepth_ft < (float)DEPTHAL_FT)&&(DEPTHAL_FT > 0))     // (DEPTHAL_M > 0) is the On/Off switch
        {
            AlarmCtr[ALARM_DepthSet]=0;
            AlarmOn.Bit.DepthSet = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState.Bit.DepthSet = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_DepthSet]=0;
            AlarmInTicks[ALARM_DepthSet]=0;
            Alarming.Bit.DepthSet = false;
        }
    }
    else
    {
        if((Dive_Info.WaterDepth_m < (float)DEPTHAL_M)&&(DEPTHAL_M > 0))     // (DEPTHAL_M > 0) is the On/Off switch
        {
            AlarmCtr[ALARM_DepthSet]=0;
            AlarmOn.Bit.DepthSet = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState.Bit.DepthSet = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_DepthSet]=0;
            AlarmInTicks[ALARM_DepthSet]=0;
            Alarming.Bit.DepthSet = false;
        }
    }

    //===================DiveDTR against to the Set Point===================
    uint16_t DTR;

    if(NDT_Data <= otrTime)
        DTR = NDT_Data;
    else
        DTR = otrTime;

    if(DTR > (int16_t)DTR_AL)
    {
        AlarmCtr[ALARM_DiveDTR]=0;
        AlarmOn.Bit.DiveDTR = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.DiveDTR = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_DiveDTR]=0;
        AlarmInTicks[ALARM_DiveDTR]=0;
        Alarming.Bit.DiveDTR = false;
    }


    //===================TTS Time against to the Set Point===================
    if(TAT_Data < TTS_AL)
    {
        AlarmCtr[ALARM_TTS_T]=0;
        AlarmOn2.Bit.TTS_T = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState2.Bit.TTS_T = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_TTS_T]=0;
        AlarmInTicks[ALARM_TTS_T]=0;
        Alarming2.Bit.TTS_T = false;
    }



    //===================DECO_Entry against to the Set Point===================
    if(DecoTime[1] == 0)
    {
        AlarmCtr[ALARM_DECO_Entry]=0;
        AlarmOn.Bit.DECO_Entry = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.DECO_Entry = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_DECO_Entry]=0;
        AlarmInTicks[ALARM_DECO_Entry]=0;
        Alarming.Bit.DECO_Entry = false;
    }


    //===================DECO_Warning against to the Set Point===================
    if((DVSTAT&0xF0) != 0x70)
    {
        AlarmCtr[ALARM_DECO_Warning]=0;
        AlarmOn.Bit.DECO_Warning = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.DECO_Warning = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_DECO_Warning]=0;
        AlarmInTicks[ALARM_DECO_Warning]=0;
        Alarming.Bit.DECO_Warning = false;
    }

    //===================OCSM_MinPO2 against to the Set Point===================
    if( ((GasSwitchGetPO2A() > OC_SM_MIN_PO2)&&(OC_MODE||SM_MODE))
            ||((GasSwitchGetPO2A() > BO_MIN_PO2)&&(BO_MODE)) )
    {
        AlarmCtr[ALARM_OCSM_MinPO2]=0;
        AlarmOn2.Bit.OCSM_MinPO2 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState2.Bit.OCSM_MinPO2 = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_OCSM_MinPO2]=0;
        AlarmInTicks[ALARM_OCSM_MinPO2]=0;
        Alarming2.Bit.OCSM_MinPO2 = false;
    }

    //===================OCSM_MaxPO2 against to the Set Point===================
    if( ((GasSwitchGetPO2A() < OC_SM_MAX_PO2)&&(OC_MODE||SM_MODE))
            ||((GasSwitchGetPO2A() < BO_MAX_PO2)&&(BO_MODE)) )
    {
        AlarmCtr[ALARM_OCSM_MaxPO2]=0;
        AlarmOn2.Bit.OCSM_MaxPO2 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState2.Bit.OCSM_MaxPO2 = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_OCSM_MaxPO2]=0;
        AlarmInTicks[ALARM_OCSM_MaxPO2]=0;
        Alarming2.Bit.OCSM_MaxPO2 = false;
    }

    //===================OCSM_DecoPO2 against to the Set Point===================
    if( ((GasSwitchGetPO2A() < OC_SM_DECO_PO2)&&(OC_MODE||SM_MODE))
            ||((GasSwitchGetPO2A() < BO_DECO_PO2)&&(BO_MODE)) )
    {
        AlarmCtr[ALARM_OCSM_DecoPO2]=0;
        AlarmOn2.Bit.OCSM_DecoPO2 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState2.Bit.OCSM_DecoPO2 = false;  // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_OCSM_DecoPO2]=0;
        AlarmInTicks[ALARM_OCSM_DecoPO2]=0;
        Alarming2.Bit.OCSM_DecoPO2 = false;
    }

    //===================TurnP stop for alarm conditon removed ===================
    if(UNITS==NVD_IMPERIAL)
    {
        // TurnP
        if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.TurnPressPSI)
        {
            AlarmCtr[ALARM_TurnP]=0;
            AlarmOn2.Bit.TurnP = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState2.Bit.TurnP = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_TurnP]=0;
            AlarmInTicks[ALARM_TurnP]=0;
            Alarming2.Bit.TurnP = false;
        }
    }
    else
    {
        if(GUI_TMT_PressPSI[Current_TMT_Num()]*CONST_PSI_TO_BAR > SCUBA_Set.TurnPressBAR)
        {
            AlarmCtr[ALARM_TurnP]=0;
            AlarmOn2.Bit.TurnP = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState2.Bit.TurnP = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_TurnP]=0;
            AlarmInTicks[ALARM_TurnP]=0;
            Alarming2.Bit.TurnP = false;
        }
    }

    //===================EndP stop for alarm conditon removed ===================
    if(UNITS==NVD_IMPERIAL)
    {
        // TurnP
        if(GUI_TMT_PressPSI[Current_TMT_Num()] > SCUBA_Set.EndPressPSI)
        {
            AlarmCtr[ALARM_EndP]=0;
            AlarmOn2.Bit.EndP = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState2.Bit.EndP = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_EndP]=0;
            AlarmInTicks[ALARM_EndP]=0;
            Alarming2.Bit.EndP = false;
        }
    }
    else
    {
        if(GUI_TMT_PressPSI[Current_TMT_Num()]*CONST_PSI_TO_BAR > SCUBA_Set.EndPressBAR)
        {
            AlarmCtr[ALARM_EndP]=0;
            AlarmOn2.Bit.EndP = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState2.Bit.EndP = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_EndP]=0;
            AlarmInTicks[ALARM_EndP]=0;
            Alarming2.Bit.EndP = false;
        }
    }


    //===================SwitchFO2 stop for alarm conditon removed ===================
    if(!Alarming.Bit.SwitchFO2)
    {
        AlarmCtr[ALARM_SwitchFO2]=0;
        AlarmOn.Bit.SwitchFO2 = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.SwitchFO2 = false;      // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_SwitchFO2]=0;
        AlarmInTicks[ALARM_SwitchFO2]=0;
        Alarming.Bit.SwitchFO2 = false;
    }

    //===================SwitchP stop for alarm conditon removed ===================
    if(!Check_L_R())
    {
        AlarmCtr[ALARM_SwitchP]=0;
        AlarmOn2.Bit.SwitchP = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState2.Bit.SwitchP = false;      // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_SwitchP]=0;
        AlarmInTicks[ALARM_SwitchP]=0;
        Alarming2.Bit.SwitchP = false;
    }

}


/*******************************************************************************
  CDT_Manager is to Start, Stop CDT

  CDT links and is ticked by SystemTimers.CounterDWN1

  uint8_t CDT_Set = 0;          // CDT Setting at Surface Menu  0: OFF, 1: ON,  2: SET
  uint8_t CDT_Run = 0;          // CDT Control underwater (FreeDive Only)       0: stop;     1: run
  uint8_t CDT_Alarm = 0;        // CDT Alarm (FreeDive Only)                    0: No Trigger CDT Alarm;        1: To Trigger CDT Alarm

  #define CDT_TIMER             SystemTimers.CounterDWN1_s                // start counting UP from 0 when dive starts
  #define CDT_TIMER_Reset()     SystemTimers.CounterDWN1_s=60*SCUBA_Set.CountDownMin+SCUBA_Set.CountDownSec   // call to reset Dive Timer or CounterUP1_s
  #define CDT_TIMER_Enable      USER_Set.SwitchSet.Bit.CDT_Enable
  #define CDT_TIMER_Run         CDT_Run
  #define CDT_TIMER_Alarm       CDT_Alarm                               // 0: Not Trigger CDT Alarm     1: To Trigger CDT Alarm
  ---------------------------------------------------------------------------------
  CDT_TIMER_Run |     CDT_TIMER_Reset()     |  in between    |   CDT_TIMER==0      |
  ---------------------------------------------------------------------------------
      false     | CDT_TIMER_Reset(), pause  |     pause      |   stop at 0         |
  ---------------------------------------------------------------------------------
      true      | counting down from Reset  |  counting down | CDT_TIMER_Run=false |
  ---------------------------------------------------------------------------------

*******************************************************************************/
void CDT_Manager(void)
{
    if(CDT_TIMER_Run==true)
    {
        if((CDT_TIMER==0)&&(CDT_TIMER_Alarm==false))        // when running down to 0, trigger CDT_Alarm.....
        {
            CDT_TIMER_Alarm = true;         // to trigger CDT alarm in AlarmManager( )
            // keep this for one second, for AlarmManager( ) to handle CDT alarm
        }
        else if((CDT_TIMER==0)&&(CDT_TIMER_Alarm==true))
        {
            CDT_SET = STAT_OFF;
            CDT_TIMER_Alarm = false;        // stop the trigger one second afterward
            CDT_TIMER_Run = false;          // stop running CDT_TIMER for now
            CDT_TIMER_Reset();              // stops at 0, and trigger CDT_Alarm.....
        }
    }
    else
    {
        CDT_TIMER_Alarm = false;        // stop the trigger one second afterward
        CDT_TIMER_Run = false;          // stop running CDT_TIMER for now
        //CDT_TIMER_Reset();              // stops at 0, and trigger CDT_Alarm.....
    }
}


/*Handle display Bluetooth passcode*/
#define BluetoothDisplayTimeOut 60
/*AppUI call every 2 ticks -> timeout = 60*500ms = 30secs*/
bool CheckTheBluetoothPasscodeDisplay(void)
{
    static uint8_t PasscodeExpiredTime_u8 = BluetoothDisplayTimeOut;
    bool retState = false;
    /*When trigger the Bluetooth passcode*/
    if( (true==SystemStatus.BLE_PsShowReq) && (BLE_AcessInitDone==false) )
    {
        GUI_SetBkColor(GUI_BLACK);          // Added for R1.001.001 2021/04/22
        GUI_Clear();
        //Passcode_Text(DispInitial);
        uint32_t PCode=0;
        for(uint8_t i=0; i<6; i++)
        {
            PCode = (SystemStatus.BLE_PassCode[i]-0x30)+(PCode*10);
        }
        //Passcode_Number(DispInitial, PCode);
        //SystemStatus.BLE_PsShowReq = false; /*Reset the trigger -> Display once*/
        PasscodeExpiredTime_u8 = 0U;
        retState = true;
        /*Reset the value of preOpcode to Initialize the screen after display*/
        DSX_Opcode = DEVICE_BLUETOOTH_PASSCODE;
        BLE_AcessInitDone=true;
        SystemStatus.BLE_PassCodeValidation=BLE_PASSCODE_NOT_CHECKED;
    }
    else
    {
        /*Do nothing*/
    }
    if(PasscodeExpiredTime_u8 < BluetoothDisplayTimeOut)
    {
        /*When waiting the time-out if any Key pressed then get*/
        if(((short_press == Key_L.DataType)||(short_press == Key_M.DataType)||(short_press == Key_R.DataType))||(false==SystemStatus.BLE_PsShowReq))
        {
            retState = false;
            PasscodeExpiredTime_u8 = BluetoothDisplayTimeOut;
            SystemStatus.BLE_PsShowReq = false; /*Reset the trigger -> Display once*/
            BLE_AcessInitDone = false;

            SystemStatus.BLE_PassCodeValidation=BLE_PASSCODE_NOT_CHECKED;
            DSX_Opcode = S2_SURFACE_MAIN;
        }
        else
        {
            retState = true;
            /*Stay in this screen until expired time out*/
            PasscodeExpiredTime_u8++;

            //******************************************************************
            // Modification by YS for fix Minh's App crashing for wrong passcode
            if(SystemStatus.BLE_PassCodeValidation==BLE_PASSCODE_INCORRECT)
            {
                uint32_t PCode=0;
                for(uint8_t i=0; i<6; i++)
                {
                    PCode = (SystemStatus.BLE_PassCode[i]-0x30)+(PCode*10);
                }

                SystemStatus.BLE_PsShowReq = true;		//R1006, for displaying complete message if more-than-one-time display is needed
                BLE_AcessInitDone = false;				//R1006, for displaying complete message if more-than-one-time display is needed
                //Passcode_Number(DispInitial, PCode);

                //PasscodeExpiredTime_u8 = (BluetoothDisplayTimeOut - 3);   // force out in 3 seconds after correct

            }
            else if(SystemStatus.BLE_PassCodeValidation==BLE_PASSCODE_CORRECT)
            {
                uint32_t PCode=0;
                for(uint8_t i=0; i<6; i++)
                {
                    PCode = (SystemStatus.BLE_PassCode[i]-0x30)+(PCode*10);
                }
                BLE_AcessInitDone=true;
                //Passcode_Number(DispInitial, PCode);

                //PasscodeExpiredTime_u8 = (BluetoothDisplayTimeOut - 20);   // force out in 3 seconds after correct

            }
            else
            {
                DSX_Opcode = DEVICE_BLUETOOTH_PASSCODE;
            }

            //******************************************************************
        }
    }
    else
    {
        SystemStatus.BLE_PsShowReq = false; /*Reset the trigger -> Display once*/
        BLE_AcessInitDone = false;
        //DSX_Opcode = S2_SURFACE_MAIN;
    }

    return retState;
}

/*******************************************************************************

    AlarmAcknowledgement( ) to process alarm flag after ACK by user

*******************************************************************************/
void AlarmAcknowledgement(void)
{
    if(Alarming.Bit.SwitchFO2)
    {
        if(SwitchFO2_InFlashing)
        {
            CurrGasNumber = DecoGas[1];

            if(CC_MODE)
                TRIMIX_Set.CurrGasNumber_CC = (TANK_NUM_t)CurrGasNumber;
            else if(OC_MODE)
                TRIMIX_Set.CurrGasNumber_OC = (TANK_NUM_t)CurrGasNumber;
            else if(SM_MODE)
                TRIMIX_Set.CurrGasNumber_SM = (TANK_NUM_t)CurrGasNumber;
            else if(BO_MODE)
                TRIMIX_Set.CurrGasNumber_BO = (TANK_NUM_t)CurrGasNumber;

            Switch_Gas();

            SwitchFO2_InFlashing = false;

            AlarmDueAck.AllBits = 0;
            AlarmDueAck2.AllBits = 0;
        }
        else
        {
            AlarmDueAck.AllBits  &= 0x00800000; // only keep SwitchFO2
            AlarmDueAck2.AllBits &= 0x00000000; // clear all other alarms
        }
    }
    else if(Alarming2.Bit.SwitchP)
    {
        Switch_L_R();
    }
    else
    {
        AlarmDueAck.AllBits = 0;
        AlarmDueAck2.AllBits = 0;
    }

    StopTheBuzzerAndVibrator();
}

/*******************************************************************************

    DoAlarmAck() is to proceed the Alarm Acknoledgement

    1: Proceed the Alarm Ack

    0: No to repond to Alarm

*******************************************************************************/
bool DoAlarmAck(void)
{
    bool state = false;

    if(AlarmID != ALARM_MAX)
    {
        state = true;           // some alarm(s) still in queue
    }
    else if(Alarming.Bit.SwitchFO2||Alarming2.Bit.SwitchP)
    {
        state = true;
    }

    return state;
}

/* the flag to disable other warnings, due to full violation */
bool NoViolation(void)
{
    return !isViolation;
}

void Init_GUI_Variables(void)
{
    GUI_TMT_Status[1] = (NVD_status_t)SCUBA_Set.TMT_On.TMT1;
    GUI_TMT_Status[2] = (NVD_status_t)SCUBA_Set.TMT_On.TMT2;
    GUI_TMT_Status[3] = (NVD_status_t)SCUBA_Set.TMT_On.TMT3;
    GUI_TMT_Status[4] = (NVD_status_t)SCUBA_Set.TMT_On.TMT4;
    GUI_TMT_Status[5] = (NVD_status_t)SCUBA_Set.TMT_On.TMT5;
    GUI_TMT_Status[6] = (NVD_status_t)SCUBA_Set.TMT_On.TMT6;


    for(uint8_t i=1; i<=TOTAL_TANK_NUM; i++)
    {
        GUI_TMT_SerialNum[i][6] = (SCUBA_Set.TMTID[i]%10);
        GUI_TMT_SerialNum[i][5] = (SCUBA_Set.TMTID[i]%100)/10;
        GUI_TMT_SerialNum[i][4] = (SCUBA_Set.TMTID[i]%1000)/100;
        GUI_TMT_SerialNum[i][3] = (SCUBA_Set.TMTID[i]%10000)/1000;
        GUI_TMT_SerialNum[i][2] = (SCUBA_Set.TMTID[i]%100000)/10000;
        GUI_TMT_SerialNum[i][1] = (SCUBA_Set.TMTID[i]%1000000)/100000;
    }
}

/*******************************************************************************

    bool CheckForNoOperation(void) is the handle the conditions need to

          trigger the No Operation and Shut Down

          1. Temp or Sensor malfunction
          2. Low Battery <= 0 Pct of Battery Level
          3. EEPROM CheckSum
          4.
          5.

*******************************************************************************/
L4X9_SystemWarningsName_t CheckForNoOperation(void)
{
    L4X9_SystemWarningsName_t state = SystemErrorWarning_NoErr;

    if(SystemStatus.DiagnosticReq == false)
    {
        if(SystemSupplyMonitor.Battery_Percentage <= BAT_NO_OPERATE_PERCENTAGE)
        {
            if(Alarming.Bit.NoOpShutdown == false)
            {
                SystemStatus.DiagnosticReq = true;
            }
            state = SystemErrorWarning_LowBattery;
        }
        // If Low Batttery then go to Low Battery Deep Sleep only when on surface
        // If Above Extra High Altitude (> 13000Ft), go to ALTITUGE LIMIT Deep Sleep only when at surface
        else if( Dive_Info.AltitudeLevel >= ALT_OVER_LIMIT )
        {
            if(   (Dive_Info.Status == AMB_DIVEINFO_NEWDAY)
                    || ( (Dive_Info.Status == AMB_DIVEINFO_DIVE) && (Dive_Info.DiveTime_s > 10 ) )           //TEMP needs to change to 3600 or so
                    || ( (Dive_Info.Status == AMB_DIVEINFO_SURF) && (Dive_Info.SurfTime_s > (AFTER_DIVE_SURF_INTERVAL_S+10)) )
              )
            {
                SystemStatus.DiagnosticReq = true;      // do system diagnostic for all conditions
                state = SystemErrorWarning_Altitude;
            }
        }
        else if(Dive_Info.Dive10hDetected)          // Check fo 10hr Dive
        {
            // Set 10h warning flag
            DEV_Rec.SystemErrorWarningBits.Dive10h = 1;

            // force to run as the high priority issue
            SystemStatus.DiagnosticRun = false;

            /* For dive data backup prior to emergency Automatic Shutdown */
            SystemStatus.DiagnosticReq = true;  // to do EmergencyEndOfDiveBackupAndShutdown();

            state = SystemErrorWarning_Dive10h;
        }
    }

    return state;
}


void PrepareForBacklightSetAgain(void)
{
    SystemStatus.backlight_on_req = true;           // restore normal Brightness
    SystemStatus.backlight_on = BACKLIGHT_DIM;      // pretending out-of-dim moment to restore normal Brightness
}

/*******************************************************************************

    void RedefineWaterLevel(void)

    This is to redefine water level when condition permits (auto zeroing)

    force mbar to be re-initialized in UpdateDiveInfo( );

*******************************************************************************/
void RedefineWaterLevel(void)
{
    if( (Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE)
            &&( TP_Info.InstantPressure_mbar <= MAX_SEALEVEL_ATMPRESSURE) )
    {
        // To Redefine Water Surface at the current Altitude
        Dive_Info.SurfacePressure_mbar = 0.0;       // force mbar to be re-initialized in UpdateDiveInfo( );
        Dive_Info.WaterEntranceDetected = false;
    }
}

/*******************************************************************************

    void GUI_DISPLAY_Update(void)

    This is to DeInit/Init LCD and GUI after critical setting changes occur

*******************************************************************************/
void GUI_DISPLAY_Update(void)
{
    GUI_LANG_Select = USER_Set.LangSelec;
    GUI_SWITCH_LCD_Flip = (NVD_status_t) USER_Set.SwitchSet.Bit.LCD_Flip;
    //------------------------------------------------------------------------
    AsssignedCoordinated((SWITCH_LCD_Flip) ? 1u : 0u); //1: Rotate 180, 0u: Normal
    Backlight_Set(0);
    //DeInit the STemWin GUI Library
    LCD_DeInit();
    GUI_Exit();
    //Init again
    LCD_Init();
    GUI_Init();
    GUI_LANG_SetMaxNumLang(MAX_LANGUAGE);
    /*Load the string content to RAM*/
    while(GUI_LANG_LoadTextEx(_GetData, (void*)&StrLang_Select[LANGUAGE], LANGUAGE));
    GUI_LANG_SetLang(LANGUAGE);
    GUI_UC_SetEncodeUTF8();
    TTF_CreateFontSequence(FontSize_General);
    //------------------------------------------------------------------------
}
