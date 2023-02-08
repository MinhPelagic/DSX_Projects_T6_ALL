/*******************************************************************************
 * @file        : main.h
 * @brief       : FW main
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *      Add USE_FULL_LL_DRIVER compilation switch in the compiler preprocessor
 *      to have full access to the low level driver LL STMCube package.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

/* Defines for Hardware Buttons Global Variable */
#define HW_BUTTON_G0            0x01
#define HW_BUTTON_G1            0x02
#define HW_BUTTON_G2            0x04
#define HW_BUTTON_G3            0x08

#define max(a,b) (a >= b) ? a : b
#define min(a,b) (a <= b) ? a : b

/*******************************************************************************
 * @brief   Data Structures
 ******************************************************************************/
// System Supply Monitor Structure
typedef struct
{
  uint16_t Battery_mV;                  // Battery voltage in mV;
  uint8_t Battery_Percentage;           // Battery Percentage 0-100%
  uint8_t PreBattery_Percentage;        // Battery Percentage 0-100%
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
  uint8_t BLE_last_status;              /* BLE Status at last moment*/
  
  int32_t BLE_PsShowReqTimestamp;       /* TimeStamp of new PassCode Generation */
  bool BLE_PsShowReq;                   /* PassCode Show Request */
  char BLE_PassCode[6];                 /* Ble temporary PassCode */
  uint8_t BLE_PassCodeValidation;       /* Ble Passcode Validation 0: NotChecking, 1: Incorrect,  2: Correct */  
  bool BLE_ShutdownReq;                 /* Ble shutdown request */
    
  uint8_t I2C1_flag;                    /* I2C1 communication semaphore, 0: not busy: others: busy in communication */
  uint8_t I2C2_flag;                    /* I2C2 communication semaphore, 0: not busy: others: busy in communication */
  
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
  int32_t user_GUI_timestamp;         /* User GUI timestamp, (MonotonicClock_s) */
  
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
  
  int32_t GUI_Pause_timestamp;         /* TimeStamp of GUI Page Pause Time Stamp (automatic, NOT controlled by user) */
    /* Used to handle EE Data Savings */
  uint32_t  NVD_EE_W_flag0;            /* The flag to Write some EE block(s) from 0x00000000 to 0x00000FFF */
  
  /* Used to handle Data Retention */
  bool NvdUpdateInProgress;   

  int32_t ButtonRebootReqTimestamp;
  bool system_reboot_request;
  
  bool DiagnosticReq;
  bool DiagnosticRun;
  bool ShowDiag;                        /* True if UI must show diagnostic screen*/
  
  bool GnssOn;                          // True when Gps On and working
  bool GnssDataRxFlag;                  // True when Uart data available
  
  bool BatteryInCharging;               // 0: Not in Charging; 1: Battery in Charging
  bool BatteryInChargingShowGUI;        // 0: Not to show Battery Charging GUI Page; 1: to show Battery in Charging GUI Page
  
  uint8_t O2_Analyzer_Stage;            // 0: Normal Operation; 1: Calibration: 2: Analyze1; 3: Analyzie2
  uint8_t O2_Analyzer_PreStage;         // 0: Normal Operation; 1: Calibration: 2: Analyze1; 3: Analyzie2
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
    uint32_t      SensorTemp   :1;        // 1-bit              ERR12     
    uint32_t      SensorVolt   :1;        // 1-bit              ERR13
    uint32_t      TickTime     :1;        // 1-bit              ERR14
    uint32_t      Button       :1;        // 1-bit              ERR15
    
    uint32_t      Altitude     :1;        // 1-bit              ERR16
    uint32_t      Compass      :1;        // 1-bit              ERR17
    uint32_t      FuelGauge    :1;        // 1-bit              ERR18
    uint32_t      Receiver     :1;        // 1-bit              ERR19
    uint32_t      Gps          :1;        // 1-bit              ERR20
    uint32_t      O2Analyzer   :1;        // 1-bit              ERR21
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



/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/* Global Monotonic Clock variables. MonotonicCloc_s is expressed in seconds. */
/* To be used only for relative time measures. */
/* Global Monotonic Clock is updated via RTC_WakeUP interupt */
extern uint8_t wakeup_counter;
extern volatile int32_t MonotonicClock_s;

/* SystemSupplyMonitor holds updated System Battery Supply data */
extern L4X9_SystemSupplyMonitor_t SystemSupplyMonitor;

/* System Status global struct */
extern volatile L4X9_SysStat_t SystemStatus;

/* Hardware Button Global Varible */
extern volatile uint8_t HW_Buttons;

/* Independant watchDog Handling struct */
extern IWDG_HandleTypeDef   WatchDogHandle;

/* I2C Bus Handling structure */
extern I2C_HandleTypeDef I2C_BUS_A;
extern I2C_HandleTypeDef I2C_BUS_B;

/* OSPI 2 and SPI 3 handle structure and variables*/
extern SPI_HandleTypeDef SPI3Handle;
extern OSPI_HandleTypeDef OSPI2Handle;

/* ADC Handling structure */
extern ADC_HandleTypeDef hadc1;

/* Pressure and Temperature Sensor Data */
extern MS5837_struct_t MS5837_Sensor;

// Fuel Gauge Data
extern MAX17262_Output_t MAX17262_Output;

/* System Timers */
extern L4X9_SysTimers_t SystemTimers;

/*******************************************************************************
 * @brief   System Interrupt related Routines
 ******************************************************************************/

/* 1s update Interupt functions */
/* These function are called from an interrupt routine, so do not use 
   any delay function */
void L4X9_UpdateTimers1s_Int1(void);
void L4X9_UpdateTimers1s_Int2(void);
void L4X9_UpdateTimers1s_Int3(void);
void L4X9_UpdateTimers1s_Int4(void);

/* 125ms update Interrupt functions */
/* These function are called from an interrupt routine, so do not use 
   any delay function */
void L4X9_UpdateTimers125ms_Int1(void);
void L4X9_UpdateTimers125ms_Int2(void); 
void L4X9_UpdateTimers125ms_Int3(void);
void L4X9_UpdateTimers125ms_Int4(void);

/* System RTC Sync Operation Manager */
void L4X9_RtcSynchedOperationManager(void);
uint8_t SystemSelftest(void);
#endif /* __MAIN_H */