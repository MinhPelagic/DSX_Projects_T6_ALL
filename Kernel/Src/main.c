/*******************************************************************************
 * @file        : main.c
 * @brief       : FW main.
 *                The whole project is based on the STMCubeMX L4 v1.13.0 HAL
 *                and LL package, to get advantage of portability on the whole
 *                L4 device range.
 *                To rise Low Power performance some MCU peripherals drivers are
 *                rewritten (CSTM_MCU_Drivers).
 *                Please note that STMCubeMX HAL Drivers are not optimized for
 *                low power performance, so they must be used only if
 *                neccessary.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "Receiver.h"
#include "board.h"
#include "OPT3001.h"
#include "i2c2.h"

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/// This is required for factory firmware flashing using merged hex
#define FACTORY_TAG_ID		0xFACFFACF
#pragma location="BL_DATA"
__root const uint32_t g_FactoryTag = 0;

/* Global Monotonic Clock variables. MonotonicClock_s is expressed in seconds. */
/* To be used only for relative time measures. */
/* Global Monotonic Clock is updated via RTC_WakeUP interupt */
uint8_t wakeup_counter;
volatile int32_t MonotonicClock_s;

/* SystemSupplyMonitor holds updated System Battery Supply data */
L4X9_SystemSupplyMonitor_t SystemSupplyMonitor;

/* Tick Handler global struct */
volatile L4X9_TickHanlder_t TickHandler;

/* System Status global struct */
volatile L4X9_SysStat_t SystemStatus;

/* System Timers */
L4X9_SysTimers_t SystemTimers;

/* System Failure Wanrnings */
L4X9_SystemWarnings_t SystemWarnings;

/* Hardware Button Global Varible */
volatile uint8_t HW_Buttons;

/* Independant watchDog Handling struct */
IWDG_HandleTypeDef   WatchDogHandle;

/* I2C Bus Handling structure */
I2C_HandleTypeDef I2C_BUS_A;
I2C_HandleTypeDef I2C_BUS_B;

/* OSPI2 and SPI3 handle structure and variables*/
SPI_HandleTypeDef SPI3Handle;
OSPI_HandleTypeDef OSPI2Handle;

/* ADC Handling structure */
//ADC_HandleTypeDef hadc1;

/* Pressure and Temperature Sensor Data */
MS5837_struct_t MS5837_Sensor;

// Fuel Gauge Data
MAX17262_Output_t MAX17262_Output;

/* NVD Global Variables */
Mfg_Calibration_t       MFG_Calib;
Device_Records_t        DEV_Rec;
User_Settings_t         USER_Set;
Scuba_Settings_t        SCUBA_Set;
TRIMIX_Settings_t       TRIMIX_Set;
Free_Settings_t         FREE_Set;
Free_Records_t          FREE_Rec;
FLASH_Map_t             FLASH_Map;

RET_Data0_t     RETA_Data0;
RET_Data1_t     RETA_Data1;
RET_Data2_t     RETA_Data2;
RET_Data3_t     RETA_Data3;
RET_Data4_t     RETA_Data4;
RET_Data5_t     RETA_Data5;
RET_Data6_t     RETA_Data6;
RET_Data7_t     RETA_Data7;

RET_Data0_t     RETB_Data0;
RET_Data1_t     RETB_Data1;
RET_Data2_t     RETB_Data2;
RET_Data3_t     RETB_Data3;
RET_Data4_t     RETB_Data4;
RET_Data5_t     RETB_Data5;
RET_Data6_t     RETB_Data6;
RET_Data7_t     RETB_Data7;
EE_Block_t      EE_Block1;
EE_Block_t      EE_Block2;

LOG_Data_t              Log_Data;
LOG_Data_t              Log_Data_7[8];
LOG_Chart_t             Log_Chart;
LOG_Chart_t             Log_Chart_7[8];
// LOG_Data_t              GUI_Log_Data[8];
Profile_Header_t        Profile_Header;
Profile_Data_t          Profile_Data;
Profile_Trailer_t       Profile_Trailer;

GPS_Location_t          CurrDiveLocation;

//LOG_Data_t              Gui_Log_Data;

/* Ambiental Information Data */
TP_Info_struct_t TP_Info;
Dive_Info_struct_t Dive_Info;
Weather_Info_struct_t Weahter_Info;

/*******************************************************************************
 * @brief
 *   FW entry point.
 *
 * @details
 *
 * @note
 *
 * @param[in]
 *
 * @return
 *
 ******************************************************************************/
	extern float lux;


int main(void)
{
/*
    //For normal operation, the following 20 lines of memory test Must Be commented out
    // Checking the Sizes of each NVD Data Structures===================
    uint16_t a = sizeof(MFG_Calib);
    uint16_t b = sizeof(DEV_Rec);
    uint16_t c = sizeof(USER_Set);
    uint16_t d = sizeof(SCUBA_Set);
    uint16_t e = sizeof(TRIMIX_Set);
    uint16_t f = sizeof(FREE_Set);
    uint16_t g = sizeof(FREE_Rec);
    uint16_t h = sizeof(FLASH_Map);
    uint16_t i = sizeof(Log_Data);
    uint16_t l = sizeof(Profile_Header);
    uint16_t m = sizeof(Profile_Data);
    uint16_t n = sizeof(Profile_Trailer);


    a = sizeof(RET_Data0_t);
    b = sizeof(RET_Data1_t);
    c = sizeof(RET_Data2_t);
    d = sizeof(RET_Data3_t);
    e = sizeof(RET_Data4_t);
    f = sizeof(RET_Data5_t);
    g = sizeof(RET_Data6_t);
    h = sizeof(RET_Data7_t);
    //====================================================================*/

  #if defined (BUILD_BTL)
    // Move Interurpt Vector
    NVIC_SetVectorTable( APPLICATION_START, 0);
    // Enable Interrupts
    __enable_irq();
  #endif
    
  // Initialize MCU Flash
  L4X9_FlashInit();

  // Initilize System Clock as defined in the XXX_hal.h
  L4X9_SystemClockInit();
      BoardInit();
      
  // Initilize NVIC module
  L4X9_NVICInit();
    
  // Init WatchDog
  L4X9_WatchDogInit();
    
  // Initialize GPIO
  L4X9_GpioInit();

  // Initialize the Stop Mode with power optimizations
  L4X9_StopModeInit();

  //Initilize and start the RTC in Calendar Mode 
  L4X9_RTCInit();

  // Initilize RTC WakeUp Interrupt and set Wakup Interrupt period to 125ms
  L4X9_RTC_WKU_INT_Init();
  
  // Initialize I2C Bus A & B
  L4X9_I2C_Init();
  
  // Initialize HW Buttons
  L4X9_ButtonInit();
  
  // Initialize BLE Module
  UART_BLE_Init(BT_USART);


//test light sensor
//  MX_I2C2_Init();               // should be removed since L4X9_I2C_Init is supposed cover its job

  OPT3001_Test();

  // Initialize Pressure Sensor
  int16_t Retry = 3;
  while(Retry--)
  {
      if( MS5837_Init(MS5837_I2C_ADDR, &MS5837_Sensor) )
          Retry = 0;        // no more retry
  }

  // Initialize ECompass
  Retry = 3;
  while(Retry--)
  {
      if( LSM303AGR_Init() )
          Retry = 0;        // no more retry
  }
  
#if USE_REAL_BATTERY
  // Initialize Fuel Gauge
  Retry = 3;
  while(Retry--)
  {
      if( MAX17262_Init(DEV_Rec.MAX17262_BatteryLearned) )
          Retry = 0;        // no more retry
  }
#endif

  Retry = 10000;
  if(DEV_Board())
    while(BLE_IS_USING_FLASH && (Retry-- > 0)){}        // R1006, added Bluetooth Error
  else
    while(PROD_BLE_IS_USING_FLASH && (Retry-- > 0)){}   // R1006, added Bluetooth Error
  
  if(Retry <= 0)
  {
      DEV_Rec.SystemErrorWarningBits.Bluetooth = true;  // R1006, if got stuck above, then issue an Bluetooth Error
  }  

  // Initialize SPI module
L4X9_QSPI_Init();
  // Initilize External Flash and Power Down
  uint8_t ExFlashInitRetry = 0;
while ( (ExFlashInitRetry++ < 100) && !MT25QL512ABB_Init() ) {};
  // DeInitialize SPI module
L4X9_QSPI_DeInit();

  // O2 Analyzer Initializations (ADC1 init function included inside)
  O2_init(); //may need to move into O2 Analyzer in the future 
  //HAL_ADC_MspInit(&hadc1);
  //HAL_ADC_MspDeInit(&hadc1);
  O2_Test();
  
  // Intitialize Wireless Power Receiver
  MAX77950_Init();

  // Initialize buzzer
  Buzzer_Init( BUZZER_FREQUENCY_HZ, BUZZER_DUTY_PERCENT );
  
  // Initialize vibrator
  Vibrator_Init( VIBRATOR_FREQUENCY_HZ, VIBRATOR_DUTY_PERCENT );
  
  // Initialize GNSS
  CXD5605GF_Init();
  
  // Initialize Backlight
  Backlight_Init();
  
  Backlight_Set(0);
    
  // Initialize LCD Drive
  LCD_Init();
  
  // Init the STemWin GUI Library
  GUI_Init();

  // Pressure receiver init
  ReceiverInit(1);

  // Initilize Global Monotonic variable
  wakeup_counter = 0;
  MonotonicClock_s = 0;

  // Hanlde any initilizations for the application to do before the Tick Handler
  L4X9_App_Init();

  // SystemSelftest();   // NOT USE IN PRODUCT

  // Main TICK Scheduler
  // Please enter your code only in the While loop. DO NOT modify above code.
  while (1)
  {
    // Handle all ticks
    L4X9_TickHandler_ALL();
  }
}


/* 1s update Interupt functions */
/* These function are called from an interrupt routine, so do not use
   any delay function */
__weak void L4X9_UpdateTimers1s_Int1(void)
{
}
__weak void L4X9_UpdateTimers1s_Int2(void)
{
}
__weak void L4X9_UpdateTimers1s_Int3(void)
{
}
__weak void L4X9_UpdateTimers1s_Int4(void)
{
}

/* 125ms update Interupt functions */
/* These function are called from an interrupt routine, so do not use
   any delay function */
__weak void L4X9_UpdateTimers125ms_Int1(void)
{
}
__weak void L4X9_UpdateTimers125ms_Int2(void)
{
}
__weak void L4X9_UpdateTimers125ms_Int3(void)
{
}
__weak void L4X9_UpdateTimers125ms_Int4(void)
{
}

__weak void L4X9_RtcSynchedOperationManager(void)
{
}
