/**-------------------------------------------------------------------------
@file	dsx.h

@brief	DSX firmware definitions

This file contains DSX firmware runtime specific

@author	Hoang Nguyen Hoan
@date	May 9, 2021

Copyright (c) 2021 Pelagic, all rights reserved

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------*/
#ifndef __DSX_H__
#define __DSX_H__

#include <stdbool.h>

#include "board.h"
#include "DSX_Version.h"

// System Supply Monitor Structure
typedef struct
{
  uint16_t Battery_mV;                  // Battery voltage in mV;
  uint8_t Battery_Percentage;           // Battery Percentage 0-100%
  uint32_t TimeToFull_s;                // Battery Charge Time
  uint32_t TimeToEmpty_s;               // Battery Autonomy Time
  
  uint16_t Battery_Level;               // Battery Level Lowest 0,1,2,3,4,.... Hightest
  uint16_t ChargingEstimate_mV;         // Charging voltage estimation in mV;
  uint16_t ChargingStart_mV;            // Charging start voltage in mV;
  uint16_t OneWayBattery_mV;            // OneWay Battery's mV (to prevent repeating Low Battery Alarm, do One-Way-Down only)
  int32_t Battery_timestamp;            // Battery voltage measurment timestamp;
  int32_t StartCharge_timestamp;        // Battry Charging Start Time Stamp;
  int32_t EndCharge_timestamp;          // Battry Charging End Time Stamp;
  uint16_t LowBattBrightnessTo;         // Change Brightness Level to (30% or 10%) due to Low Battery 
  
} L4X9_SystemSupplyMonitor_t;

// Low Level System Power Mode States
typedef enum 
{
  SYS_ACTIVE      = 0x00,
  SYS_PSM,
  SYS_SLEEP,
  SYS_DSLEEP,
  SYS_FDSLEEP,
  SYS_LBDSLEEP
}SYS_STATUS_t;

/* System status structure */
typedef struct
{
  bool backlight_on_req;                /* Backlight On Request */
  bool backlight_dim_req;               /* Backlight Dim Request */
  bool backlight_off_req;               /* Backlight Off Request */
  bool backlight_change_req;            /* Backlight Level Change Request */
  bool backlight_dim_change_req;        /* Backlight Dim Level Change Request */
  uint8_t backlight_on;                 /* Backlight Status 2:ON, 1:DIM, 0:OFF */
  int32_t backlight_dim_timestamp;      /* Backlight dim timestamp, (MonotonicClock_s) */
  int32_t backlight_act_timestamp;      /* Backlight activaztion timestamp, (MonotonicClock_s) */
  
  bool buzzer_on_req;                   /* Buzzer On Request */
  bool buzzer_on;                       /* Buzzer Status */
  int32_t buzzer_act_timestamp;         /* Buzzer activaztion timestamp, (MonotonicClock_s) */
  
  bool vibe_on_req;                     /* Vibe On Request */
  bool vibe_on;                         /* Vibe Status */
  int32_t vibe_act_timestamp;           /* Vibe activaztion timestamp, (MonotonicClock_s) */
  
  bool led_on_req;                      /* Led On Request */
  bool led_on;                          /* Led Status */
  int32_t led_act_timestamp;            /* Led activaztion timestamp, (MonotonicClock_s) */
  
  int32_t USB_last_activity_s;          /* Last MonotonicClock_s value when activity on USB */
  uint8_t USB_Connected;                /* 0: detached; 1:attached; 2: Connected */
  bool USB_JustAttached;                /* if true cable has been just attached, will go back to false in one exe cycle */
  bool USB_ForceInit;                   /* if true cable forces Usb Init */
  bool USB_AppConnected;                /* if true when App connected */
  
  int32_t BLE_last_activity_s;          /* Last MonotonicClock_s value when activity on BLE */
  uint8_t BLE_status;                   /* BLE Status see BLE_Handler_t*/
  
  int32_t BLE_PsShowReqTimestamp;       /* TimeStamp of new PassCode Generation */
  bool BLE_PsShowReq;                   /* PassCode Show Request */
  uint8_t BLE_PassCode[6];              /* Ble temporary PassCode */
  uint8_t BLE_PassCodeValidation;       /* Ble Passcode Validation 0: NotChecking, 1: Incorrect,  2: Correct */  
  bool BLE_ShutdownReq;                 /* Ble shutdown request */
    
  uint8_t Notification_type;            /* 0: NO; 1: Phone; 2: SMS */
  int32_t Notification_timestamp;       /* Notification Receive TimeStamp */
  
  /* Variables used to as blink indication */
  uint8_t blink_counter;
  bool blink_0s5;
  bool blink_1s0;
  bool blink_1s5;
  bool blink_2s0;
  
  /* Varible to notify system that UI is watch mode */
  bool watchmode_on;                    /* True if system is in watchmode */
  
  /* Last User activity time */
  int32_t user_act_timestamp;         /* User activity timestamp, (MonotonicClock_s) */
  
  /* System Power Mode State variables */
  SYS_STATUS_t SystemPowerMode;
  bool System_DeepSleepReq;             /* True if system deep sleep is requested */
  bool System_FastDeepSleepReq;         /* True if system fast deep sleep is requested */
  bool System_LowBatDeepSleepReq;       /* True if system Low Bat deep sleep is requested */
  bool System_SleepReq;                 /* True if system sleep mode is requested */
  bool System_LowPwrReq;                /* True if system Lowest Power mode is requested */
  bool System_ActiveReq;                /* True if system active is requested */
  
  /* OpCode Management Variables */
  uint16_t OpCode;                      /* OpCode Command ID */
  uint16_t PreOpCode;                   /* Previous OpCode Command ID */
  uint16_t MnCode;                      /* MnCode = MenuCode D */
  uint16_t PreMnCode;                   /* Previous MnCode = MenuCode D */
  
  
    
  /* Demo Mode Pin Status flag */
  bool Demo_On;
  
  bool Demo_Up;
  bool Demo_Down;
  
  bool Demo_X60;
  bool Demo_Shift;
  
  uint32_t GUI_Pause_timestamp;         /* TimeStamp of GUI Page Pause Time Stamp (automatic, NOT controlled by user) */
    /* Used to handle EE Data Savings */
  uint16_t  NVD_EE_W_flag0;              /* The flag to Write some EE block(s) from 0x0000 to 0x0FFF */
  
  /* Used to handle Data Retention */
  bool NvdUpdateInProgress;   

  bool system_reboot_request;
  
  bool DiagnosticReq;
  bool DiagnosticRun;
  bool ShowDiag;                        /* True if UI must show diagnostic screen*/
  
} L4X9_SysStat_t;




/* System Timers */
typedef struct
{
  int32_t CounterUP1_s;         // Increasing Counter 1 second resolution (R/W)
  int32_t CounterUP2_s;         // Increasing Counter 2 second resolution (R/W)
  int32_t CounterUP3_s;         // Increasing Counter 3 second resolution (R/W)
  
  int32_t CounterDWN1_s;         // Decreasing Counter 1 second resolution (R/W)
  int32_t CounterDWN2_s;         // Decreasing Counter 2 second resolution (R/W)
  int32_t CounterDWN3_s;         // Decreasing Counter 3 second resolution (R/W)
  
} L4X9_SysTimers_t;


/* System Failure/Warnings */
typedef struct 
{
  union
  {
    uint32_t AllBits;
    struct 
    {
    uint32_t      NoErr        :1;        // 1-bit              N/A
    uint32_t      SensorPress  :1;        // 1-bit              ERR1
    uint32_t      Eeprom       :1;        // 1-bit (Page-A73)   ERR2
    uint32_t      Flash        :1;        // 1-bit              ERR3
    uint32_t      Calibration  :1;        // 1-bit (Page-A74)   ERR4
    uint32_t      CheckSum     :1;        // 1-bit (Page-A75)   ERR5
    uint32_t      Dive10h      :1;        // 1-bit              ERR6
    uint32_t      LowBattery   :1;        // 1-bit              ERR7
    uint32_t      Bluetooth    :1;        // 1-bit              ERR8
    uint32_t      NotYetCali   :1;        // 1-bit (Page-A80)   ERR9
    uint32_t      LastDive     :1;        // 1-bit (Page-A78)   ERR10
    uint32_t      ADC          :1;        // 1-bit (Page-A76)   ERR11    
    uint32_t      SensorTemp   :1;        // 1-bit              
    uint32_t      SensorVolt   :1;        // 1-bit 
    uint32_t      TickTime     :1;        // 1-bit  
    uint32_t      Button       :1;        // 1-bit     
    
    uint32_t      Altitude     :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved17   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved18   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved19   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved20   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved21   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved22   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved23   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved24   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved25   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved26   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved27   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved28   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved29   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved30   :1;        // 1-bit reserved               0:                      1: 
    uint32_t      Reserved31   :1;        // 1-bit reserved               0:                      1: 
    };
  };
} L4X9_SystemWarnings_t;


// public function prototypes
#ifdef __cplusplus
extern "C" {
#endif

bool BleComInit();
void BleComHandler();
bool CmdBlePowerDown();
bool FlashEnable();
void FlashDisable();
int FlashRead(uint32_t Addr, uint8_t *pBuff, int BuffLen);
int FlashWrite(uint32_t Addr, uint8_t *pData, int DataLen);
bool FlashReadId(uint8_t *pMan, uint8_t *pType, uint8_t *pDensity);
void FlashErase(uint32_t Block, int NbBlock);
void ButIntHandler(int IntNo);

#ifdef __cplusplus
}
#endif

// TODO: to be removed
#define BT_USART                LPUART1

// public globals
extern volatile L4X9_SysStat_t SystemStatus;
extern volatile int32_t MonotonicClock_s;
extern L4X9_SystemSupplyMonitor_t SystemSupplyMonitor;
extern L4X9_SysTimers_t SystemTimers;

#endif // __DSX_H__

