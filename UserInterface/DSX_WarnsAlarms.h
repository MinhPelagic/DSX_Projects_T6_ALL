/*******************************************************************************
 * @file        : DSX_WarningsAndAlarms.h
 * @brief       : ........
 *
 * @version     XX.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2021
 * Author: YeuShyr Wu, Aqualung
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DSX_WARNINGSANDALARMS_H__
#define __DSX_WARNINGSANDALARMS_H__

#define FULL_CHARGED_mVOLT  4250 // 4250mV or 4.250 Volts       // raised from 4150 to 4250 on 2021 0108 after T195, for new battery
#define NO_OPERATE_mVOLT    3550 // 3600mV or 3.550 Volts       // lower from 3650 to 3550 on 2021 0115 after T196, for new battery
#define CUTOFF_mVOLT        (NO_OPERATE_mVOLT - 50) // 3580mV or 3.500 Volts       // lower from 3640 to 3500 on 2021 0115 after T196, for new battery
#define TICK_ID_PLUS_1         (TickHandler.scheduled_tick+1)

// External Async Recall

extern uint8_t SurfaceFirstPageInitFlag;

uint8_t AlarmFIFO_Arrange(uint8_t AlarmID);

/******************************************************************************
 * @brief   WarningsAlarmsManager
 *
 * @note
 ******************************************************************************/
void WarningsAlarmsManager(void);
extern uint8_t CurrAlarmID;
extern union AlarmUNION ALARM_ON;      // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
extern union AlarmUNION AlarmOn;       // Current Alarm Buzzing Sound On/Off, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
extern union AlarmUNION AlarmState;    // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
extern union AlarmUNION AlarmRepeat;   // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
extern union AlarmUNION AlarmOccured;  // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
extern union AlarmUNION Alarming;      // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
extern union AlarmUNION AlarmProfileRec; // Alarm and Violation Record buffer for Profile Record recording

extern union Alarm2UNION ALARM_ON2;      // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
extern union Alarm2UNION AlarmOn2;       // Current Alarm Buzzing Sound On/Off, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
extern union Alarm2UNION AlarmState2;    // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
extern union Alarm2UNION AlarmRepeat2;   // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
extern union Alarm2UNION AlarmOccured2;  // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
extern union Alarm2UNION Alarming2;      // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
extern union Alarm2UNION AlarmProfileRec2; // Alarm and Violation Record buffer for Profile Record recording

extern void AlarmInit(void);
extern void StopTheBuzzerAndVibrator(void);
extern void CheckForNewDayDataOrRetainedData(void);

void CDT_Manager(void);

#endif /* __DSX_WARNINGSANDALARMS_H__ */
