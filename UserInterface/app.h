/*******************************************************************************
 * @file        : app.h
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

#ifndef __APP_H__
#define __APP_H__


#define USB_STAT    BatteryCharging()

void UI_Every125Exec(void);

void UI_App (void);

void UI_PorMessage(void);

void UI_EnterDeepSleep(void);
void UI_WakeFromDeepSleep(void);

void UI_EnterLowBatDeepSleep(void);
void UI_WakeFromLowBatDeepSleep(void);

void UI_EnterFastDeepSleep(void);
void UI_WakeFromFastDeepSleep(void);

void UI_EnterSleep(void);
void UI_WakeFromSleep(void);

void UI_EnterPsm(void);
void UI_WakeFromPsm(void);

void UI_BootToSurfMode(void);

extern char DSX_Opcode_String[];

extern void NewDayInit(void);
extern bool NewDayInitDone;            //YeuShyr 20220308 to complete NewDayInit before Dive
extern bool DataRetainDone;            //YeuShyr 20220308 to complete DataRetain before Dive

typedef enum
{
    OPERATE_Run = 0x00,   // Normal Operation, most of time and initial state
    OPERATE_LowBatt,      // Low Battery State (RED)
    OPERATE_EndDive,      // Force End Dive State (10 Hour Dive)
    OPERATE_DataRetain,   // Data Retention State
    OPERATE_DeepSleep,    // Deep Sleep State
    OPERATE_Shutoff,      // Shutoff State
} OP_Shutdown_t;

typedef struct
{
    OP_Shutdown_t State;
    SystemTimeDate_t OP_Time;
} SHUTDOWN_struct_t;


/* System Failure/Warnings */
typedef enum
{
    SystemErrorWarning_NoErr        = 0x00,
    SystemErrorWarning_SensorPress,
    SystemErrorWarning_Eeprom,
    SystemErrorWarning_Flash,
    SystemErrorWarning_Calibration,
    SystemErrorWarning_CheckSum,
    SystemErrorWarning_Dive10h,
    SystemErrorWarning_LowBattery,
    SystemErrorWarning_Bluetooth,
    SystemErrorWarning_NotYetCali,
    SystemErrorWarning_LastDive,
    SystemErrorWarning_ADC,
    SystemErrorWarning_SensorTemp,
    SystemErrorWarning_SensorVolt,
    SystemErrorWarning_TickTime,
    SystemErrorWarning_Button,

    SystemErrorWarning_Altitude,
    SystemErrorWarning_Compass,
    SystemErrorWarning_FuelGauge,
    SystemErrorWarning_Receiver,
    SystemErrorWarning_Gps,
    SystemErrorWarning_O2Analyzer,
    SystemErrorWarning_Reserved22,
    SystemErrorWarning_Reserved23,
    SystemErrorWarning_Reserved24,
    SystemErrorWarning_Reserved25,
    SystemErrorWarning_Reserved26,
    SystemErrorWarning_Reserved27,
    SystemErrorWarning_Reserved28,
    SystemErrorWarning_Reserved29,
    SystemErrorWarning_Reserved30,
    SystemErrorWarning_Reserved31,
} L4X9_SystemWarningsName_t;

#define TICK_ID_PLUS_1         (TickHandler.scheduled_tick+1)

#define BATT_L0 0
#define BATT_L1 1
#define BATT_L2 2
#define BATT_L3 3
#define BATT_L4 4
#define BATT_L5 5
#define BATT_L6 6
#define BATT_L7 7
#define BATT_L8 8

#define LOW_BATT_WARNING_LEVEL       15      // Warning at 15%
#define LOW_BATT_ALARM_LEVEL         2       // Alarm at 2%

// External Async Recall

extern uint8_t SurfaceFirstPageInitFlag;
extern bool SwitchFO2_InFlashing;      // when AlarmID == SwitchFO2 or MaxAlarm but in turn of flashing GAS SWITCH Message

uint8_t AlarmFIFO_Arrange(uint8_t AlarmID);
void ImmediateStopAlarmCheck(void);

/******************************************************************************
 * @brief   WarningsAlarmsManager
 *
 * @note
 ******************************************************************************/
void WarningsAlarmsManager(void);
bool NoViolation(void);
void Init_GUI_Variables(void);
/**********************************************************************************************

    L4X9_SystemWarningsName_t CheckForNoOperation(void) is the handle the conditions need to

**********************************************************************************************/
L4X9_SystemWarningsName_t CheckForNoOperation(void);

extern uint8_t CurrAlarmID;

extern union AlarmUNION ALARM_ON;      // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
extern union AlarmUNION AlarmOn;       // Current Alarm Buzzing Sound On/Off, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
extern union AlarmUNION AlarmState;    // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
extern union AlarmUNION AlarmRepeat;   // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
extern union AlarmUNION AlarmOccured;  // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
extern union AlarmUNION Alarming;      // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
extern union AlarmUNION AlarmProfileRec; // Alarm and Violation Record buffer for Profile Record recording
extern union AlarmUNION AlarmDueAck;     // Alarms and Violations that need Button Pressing as Acknowledgment

extern union Alarm2UNION ALARM_ON2;      // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
extern union Alarm2UNION AlarmOn2;       // Current Alarm Buzzing Sound On/Off, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
extern union Alarm2UNION AlarmState2;    // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
extern union Alarm2UNION AlarmRepeat2;   // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
extern union Alarm2UNION AlarmOccured2;  // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
extern union Alarm2UNION Alarming2;      // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
extern union Alarm2UNION AlarmProfileRec2; // Alarm and Violation Record buffer for Profile Record recording
extern union Alarm2UNION AlarmDueAck2;     // Alarms and Violations that need Button Pressing as Acknowledgment

extern uint8_t AlarmID;

extern void AlarmInit(void);
extern void StopTheBuzzerAndVibrator(void);
extern void CheckForNewDayDataOrRetainedData(void);
extern bool CheckTheBluetoothPasscodeDisplay(void);
extern bool NewDayInitDone;            //YeuShyr 20220308 to complete NewDayInit before Dive
extern bool DataRetainDone;            //YeuShyr 20220308 to complete DataRetain before Dive

extern void AlarmAcknowledgement(void);
extern bool DoAlarmAck(void);
extern uint8_t GFHighSettingValue;
extern void PrepareForBacklightSetAgain(void);
extern void GUI_DISPLAY_Update(void);
extern bool LogMenu_CheckLogIsEmpty(void);
void CDT_Manager(void);
#endif /* __APP_H__ */
