/*******************************************************************************
 * @file        : Tick_Handler.c
 * @brief       : This file contains all Tick handler functions.
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "board.h"
#include "OPT3001.h"
// Debug Variable
uint32_t TickCounter[20] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};

#define COUNT_NOT_TO_CALI_COMPASS       2000
int32_t CounterNotToCaliCompass = COUNT_NOT_TO_CALI_COMPASS;
uint32_t CounterCaliCompass = 0;

// Demo Pin Manager
void DemoPinsManager(void);

// Backligth Manager
void BacklightManager(void);

// Light Sensor Reading
float LightSensorLuxReading(void);

// Buzzer and Vibrator Manager
void BuzzerVibeManager(void);

// Handle System Transition from Active to PSM/Sleep
void System2PsmSleep(void);

// Handle System Transition to Active
void System2Active(void);

// Handle System Transition to Any Deep Sleep mode
void System2AnyDeepSleep(void);

/*******************************************************************************
 * @brief   Tick Hanlder Routines
 ******************************************************************************/

/* Hanlde any initilizations for the application to do before the Tick Handler */
void L4X9_App_Init(void)
{
  uint16_t new_crc;
  
  // Initialize volatile System Status Global Structure
  SystemStatus_Init();
  
  // If Fw Update performed then force System Active
  BootRecord_t BootRec;
  GetBootRec_FromApp(&BootRec);
  if(BootRec.FwUpdateStat != FW_RUN_OK)
  {
      SystemStatus.System_ActiveReq = true;
    
      /* HW Initialization Done and Fw is running correctly */
      /* If any update has been done, update BootRecord Status */
      UpdateBootRec_FromApp(FW_RUN_OK);
  }    

  //Set 0 to Configure for EEPROM ERASE only

//#warning To be removed from Release
  if ( (NVD_ExtEEPROM_to_RAM() == false ) || CheckBrandNewEE() || ToManualResetEE() )
  {
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload();
       
      // Initialize or Retreive NVD Data
      UpdateRealTimeDate(&SysTimeDatePST);      // to MFG save Calibration Time
      
      //===== Only do this (MFG_Calib) here, not in any other places of the project =====
      new_crc = Eval_CRC16(&MFG_Calib, sizeof(MFG_Calib)-2);
      MFG_Calib.CRC_MSB = (uint8_t)((new_crc >> 8)&0x00FF);
      MFG_Calib.CRC_LSB = (uint8_t)(new_crc&0x00FF);
      NVD_RAMBLOCK_to_ExtEEPROM(EE_MFGCAL);
      //=================================================================================
      
      DEV_Rec_Init (&DEV_Rec);                  // default Device Setup
      User_Set_Init (&USER_Set);                // default User Setup
      SCUBA_Set_Init (&SCUBA_Set);              // default Scuba Setup
      TRIMIX_Set_Init (&TRIMIX_Set);              // default Scuba Record
      FLASH_Map_Init (&FLASH_Map);              // default Scuba Record
      RetData_Init();
      
      NVD_RAMTOTAL_to_ExtEEPROM();              // Save Default Initialization to EEPROM
      
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload();
  }

#if 0  
  Backlight_Set(100);
  {
    char _DispStringTemp[15];

    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(GUI_FONT_24_ASCII);

    sprintf(_DispStringTemp, "%s", "EEPROM");
    GUI_DispStringHCenterAt(_DispStringTemp, 160 ,90);
    sprintf(_DispStringTemp, "%s", "ERASED");
    GUI_DispStringHCenterAt(_DispStringTemp, 160 ,120);
  }

  while(1)
  {
    L4X9_WatchDogReload();
  }
#endif
  
  // Calibrate RTC with retreived EEPROM Calibration values
  L4X9_CalRtc ( MFG_Calib.LF_Crystal_Cal, MFG_Calib.LF_Crystal_Sign);
  
  // Restore RTC Date and Time from EEPROM DEV_Rec.RTC_PST
  L4X9_SetRtc(DEV_Rec.RTC_PST);
  
  // Update system Date/Time from RTC
  UpdateRealTimeDate(&SysTimeDatePST);  
  
  // Restore MonotonicClock_s from NVD, if any. Otherwise leave default
  MonotonicClock_s = DEV_Rec.MonoClockSec;
  
  bool ShowPorMessage = false;
  
  // Check and update FW version and time
  if(DEV_Rec.FW_Ver != GET_FW_VERSION)
  {
    // Save FW Version Info
    DEV_Rec.OldFW_Ver = DEV_Rec.FW_Ver;
    DEV_Rec.FW_Ver = GET_FW_VERSION;

    // to reset the flag that would redirect to Data Retention
    //  make sure 
    DEV_Rec.RetainIndex = 0;
    DEV_Rec.SystemErrorWarningBits.AllBits = 0;         // Reset all system error bits
    DEV_Rec.DivingOngoing = 0;                          // Reset imcomplete dive error bits
    DEV_Rec.LockForGaugeDive = 0;                       // Reset to release the lockup at Gauge Dive or GSM Dive
    Dive_Info.Dive10hDetected = false;                  // Reset Dive10h error bit
    
    USER_Set.StartDiveDepthFt = 5;      // 5.0 feet    
    USER_Set.EndDiveDepthFt = 3;        // 3.0 feet
    USER_Set.StartDiveDepthdM = 15;     // 1.5 Meter
    USER_Set.EndDiveDepthdM = 9;        // 0.9 Meter
    
    USER_Set.SwitchSet.Bit.BluetoothOn = true;
    
    USER_Set.SwitchSet.Bit.DeepStopOn = false;          // DSX does NOT have Deep Stop feature

    PatchR1005();       // Add new configurations starting from R1005
    
    PatchR1006();       // Add new configurations starting from R1006
    
    // Write to EEPROM    
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);
    NVD_RAMBLOCK_to_ExtEEPROM(EE_USERSET);
    NVD_RAMBLOCK_to_ExtEEPROM(EE_TRIMIXSET);
  }
  // Show Por Message on Reset if no Fw Update Done
  else
    ShowPorMessage = true;

  GUI_DIVE_Mode = DIVE_MODE;    // always starts from the dive mode previously saved on EEPROM

  // Reset to all 0s for the units with brand new ExFLASH
  if(DEV_Rec.SystemErrorWarningBits.AllBits == 0xFFFFFFFF)
      DEV_Rec.SystemErrorWarningBits.AllBits = 0;

  // Set Fuel Gauge with Learned Parameters retrived from EEPROM
  MAX17262_SetLearnedParameters(DEV_Rec.MAX17262_BatteryLearned);

  // Initialize System Supply Monitor
  Init_SystemSupplyMonitor ( &SystemSupplyMonitor );

  // Update System Supply Monitor
  Update_SystemSupplyMonitor ( &SystemSupplyMonitor );

  // Measure Pressure and Temperature
  MS5837_Meas( MS5837_I2C_ADDR, &MS5837_Sensor, MS5837_OSR_8192, MFG_Calib.LP_Sensor_Offset_ubarx10, MFG_Calib.Temp_Sensor_Offset_mCx10 );

  // Update Global TP Info Structure 
  UpdateTPInfo( &TP_Info, (((float)MS5837_Sensor.temp)/100.0f), (((float)MS5837_Sensor.press)/10.0f) );

  // Update Global Dive Info Structure
  UpdateDiveInfo( &Dive_Info, TP_Info.AveragePressure_mbar, TP_Info.AverageTemperature_C, USER_Set);

  // Init Buttons
  InitButtonDefault();

  // Initialize Deco Variables
  ///////////////////////////////////////////////////////////
  IntinalizeGasVariables();   // ALWAYS initialize Anthony's Variables for algorithm to run correctly
  
  Init_GUI_Variables();
  
  CheckForNewDayDataOrRetainedData();	// modified from R1006, due to redundant code found in earlier versions

  // Reset all alarm variable and parameters before each new dive
  AlarmInit();

  // If Battery Changed or Reset occurs Show Message
  if(ShowPorMessage)
  {
    if(USER_Set.BacklightLevel <= 100)
        Backlight_Set(USER_Set.BacklightLevel);
    else
        Backlight_Set(100);
    
    UI_PorMessage();

    int8_t rep = 3;
    while(rep-- > 0)
    {
      ms_delay(1000);
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload();
    }
    SystemStatus.backlight_on = BACKLIGHT_OFF;
    SystemStatus.backlight_off_req = false;       // added by YS, 2021/12/28
    Backlight_Set(0);
  }
  
  // This is to DeInit/Init LCD and GUI after critical setting changes occur
  GUI_DISPLAY_Update();
  
  // Initialize Tick Hanlder
  TickHandler.allow_tick_scheduling = false;    // inhibit tick scheduling
  TickHandler.scheduled_tick = 0;               // Schedule Tick 0 as first to process
  TickHandler.tick_processed[0] = false;        // Tick0 not proccessed
  TickHandler.tick_processed[1] = false;        // Tick1 not proccessed
  TickHandler.tick_processed[2] = false;        // Tick2 not proccessed
  TickHandler.tick_processed[3] = false;        // Tick3 not proccessed
  TickHandler.tick_processed[4] = false;        // Tick4 not proccessed
  TickHandler.tick_processed[5] = false;        // Tick5 not proccessed
  TickHandler.tick_processed[6] = false;        // Tick6 not proccessed
  TickHandler.tick_processed[7] = false;        // Tick7 not proccessed
  
  // Initilize Last User activity timer
  if(SystemStatus.System_ActiveReq)
    SystemStatus.user_act_timestamp = MonotonicClock_s;
  else
    SystemStatus.user_act_timestamp = MonotonicClock_s - PSM_TIMEOUT_S*2;
  
  // Initialize System Power Mode
  SystemStatus.SystemPowerMode = SYS_ACTIVE;
  
  // Signal Reset during Dive
  if(DEV_Rec.DivingOngoing == 1) 
  {
    DEV_Rec.SystemErrorWarningBits.LastDive = 1;
    
    DEV_Rec.DivingOngoing = 0;
    
    // Update Warning flags in EEPROM
    EE_SaveReq(EE_DEVREC);  
  }
  
  SystemStatus.DiagnosticReq = true;
}
   


// Tick ALL Handler
void L4X9_TickHandler_ALL(void)
{
  int32_t MonotonicClock_s_tmp;
  
  MonotonicClock_s_tmp = MonotonicClock_s;
  /* Please insert here your code for All Ticks */
  TP2_HIGH;
  // Manage System Power Modes
  if(( ( (Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE) ) // if Active and PSM timeout and Not Diving and Not AfterDiving
     &&( SystemStatus.System_LowBatDeepSleepReq || SystemStatus.System_DeepSleepReq || SystemStatus.System_FastDeepSleepReq )
     && !AppInCommunicating() && !SystemStatus.ShowDiag )       // SystemStatus.DiagnosticRun????
    ||( ( Dive_Info.Status == AMB_DIVEINFO_DIVE )&&( DEV_Rec.SystemErrorWarningBits.Dive10h || DEV_Rec.SystemErrorWarningBits.LastDive 
       || SystemStatus.System_LowBatDeepSleepReq || SystemStatus.System_DeepSleepReq || SystemStatus.System_FastDeepSleepReq )
       && !AppInCommunicating() && !BatteryCharging() ) )
  {
    // This mode is Blocking, so no other code will be executed till Any Deepsleep mode is leaved
    //if(!SystemStatus.DiagnosticReq)
    System2AnyDeepSleep();
    
    //After resuiming from any DeepSleep tick0 is the firs one to be executed
  }
  
  if (  ( (SystemStatus.SystemPowerMode == SYS_ACTIVE) && !AppInCommunicating() && !BatteryCharging()
      &&((((MonotonicClock_s_tmp - SystemStatus.user_act_timestamp) > PSM_TIMEOUT_S))&&((MonotonicClock_s_tmp - SystemStatus.user_GUI_timestamp) > 10) )
      &&((Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE)) )     // if Active and PSM timeout and Not Diving and Not AfterDiving
      || ( !AppInCommunicating() && !BatteryCharging() && ( SystemStatus.System_LowPwrReq || SystemStatus.System_SleepReq ) ) ) // if Lp force request OR if Sleep force request                                                                       // 
  {
    // This mode is NON-Blocking, Tick are executed.
    //if(!SystemStatus.DiagnosticReq)   
    System2PsmSleep();
  }
  else if (    ( (SystemStatus.SystemPowerMode != SYS_ACTIVE) && (HW_Buttons != 0) )                        // Wake on Button press 
            || ( (SystemStatus.SystemPowerMode != SYS_ACTIVE) && (SystemStatus.System_ActiveReq) )          // Wake on force
            || ( (SystemStatus.SystemPowerMode != SYS_ACTIVE) && BatteryCharging() )                        // Wake on Usb Cable Insertion or Wireless Charging
            || ( (SystemStatus.SystemPowerMode != SYS_ACTIVE) && (Dive_Info.WaterEntranceDetected) )        // Wake on Water Entrance Detect
            || ( (SystemStatus.SystemPowerMode != SYS_ACTIVE) && ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))) // Wake on dive
          )               
  {
    System2Active();    // All System Wakeup from Sleep Mode starts from here
  }
  else if( ((Dive_Info.Status != AMB_DIVEINFO_DIVE)&&(Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE)&&(Dive_Info.Status != AMB_DIVEINFO_NEWDAY_SLEEP))
          &&( (DSX_Opcode!=C1_COMPASS_MAIN)&&((MonotonicClock_s_tmp - SystemStatus.user_act_timestamp) > SURF_MENU_TIMEOUT_S)
         ||(DSX_Opcode==C1_COMPASS_MAIN)&&((MonotonicClock_s_tmp - SystemStatus.user_act_timestamp) > COMPASS_MAIN_TIMEOUT_S)) 
         ||((Dive_Info.PreStatus != AMB_DIVEINFO_SURF)&&(Dive_Info.Status == AMB_DIVEINFO_SURF)) )
  {
      if((DSX_Opcode!=B1_BATT_CHARGE) && REGISTER_Done() )
      {
          if((CC_MODE) && ((DSX_Opcode!=S2_SURFACE_MAIN)))
              DSX_Opcode = S2_SURFACE_MAIN;
          else if((OC_MODE||BO_MODE) && (DSX_Opcode!=S2_SURFACE_MAIN))
              DSX_Opcode = S2_SURFACE_MAIN;
          else if(SM_MODE && (DSX_Opcode!=SURFACE_SM_MAIN))
              DSX_Opcode = SURFACE_SM_MAIN;
          else if(GSM_MODE && (DSX_Opcode!=SURFACE_GSM_MAIN))
              DSX_Opcode = SURFACE_GSM_MAIN;
          else if( GAUGE_MODE && (DSX_Opcode!=SURFACE_GAUGE_MAIN))
              DSX_Opcode = SURFACE_GAUGE_MAIN;
      }
      
      GUI_DIVE_Mode = DIVE_MODE;        // GUI settings for DIVE_MODE
  }
  else if( ( ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
         &&( ((DSX_Opcode!=C2_COMPASS_MAIN_DIVE)&&(DSX_Opcode!=DIVE_DEPTH_AND_DIVETIME))&&((MonotonicClock_s_tmp - SystemStatus.user_act_timestamp) > DIVE_MENU_TIMEOUT_S)
           ||(DSX_Opcode==C2_COMPASS_MAIN_DIVE)&&((MonotonicClock_s_tmp - SystemStatus.user_act_timestamp) > COMPASS_MAIN_TIMEOUT_S) ) )
          ||((Dive_Info.PreStatus != AMB_DIVEINFO_DIVE)&&(Dive_Info.Status == AMB_DIVEINFO_DIVE))
          ||((Dive_Info.PreStatus != AMB_DIVEINFO_AFTERDIVE)&&(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)) )
  {
      if(CC_MODE && (DSX_Opcode!=DIVE_CC_MAIN))
          DSX_Opcode = DIVE_CC_MAIN;
      else if((OC_MODE||BO_MODE) && (DSX_Opcode!=DIVE_OC_MAIN))
          DSX_Opcode = DIVE_OC_MAIN;
      else if(SM_MODE && (DSX_Opcode!=DIVE_SM_MAIN))
          DSX_Opcode = DIVE_SM_MAIN;
      else if(GSM_MODE && (DSX_Opcode!=DIVE_GSM_MAIN))
          DSX_Opcode = DIVE_GSM_MAIN;
      else if( GAUGE_MODE && (DSX_Opcode!=DIVE_GAUGE_MAIN))
          DSX_Opcode = DIVE_GAUGE_MAIN;
      
      GUI_DIVE_Mode = DIVE_MODE;        // GUI settings for DIVE_MODE
  }  

  /* A button ot other type of interrupts can wake system before 125ms so     */
  /* this check is performed here to be sure to handle button every 125ms.    */
  /* Moved here for convenience. */
  if (TickHandler.wut_125ms_occurred == true)
  {
    TickHandler.wut_125ms_occurred = false;

    // Demo Pins Manager
    DemoPinsManager();
    
    // Backlight Manager
    //if(SystemStatus.BLE_status < BLE_HDL_CONNECT)
    //    BacklightManager();
    BacklightManager();
    
    // UI related callback function
    UI_Every125Exec();
 
    WarningsAlarmsManager();
        
    // Handle flashing variable
    SystemStatus.blink_counter++;
    if(SystemStatus.blink_counter%(4) == 0)
      SystemStatus.blink_0s5 = !SystemStatus.blink_0s5;
    //if(SystemStatus.blink_counter%(8) == 0)
      //SystemStatus.blink_1s0 = !SystemStatus.blink_1s0;
    //if(SystemStatus.blink_counter%(12) == 0)
      //SystemStatus.blink_1s5 = !SystemStatus.blink_1s5;
    //if(SystemStatus.blink_counter%(16) == 0)
      //SystemStatus.blink_2s0 = !SystemStatus.blink_2s0;
    
    // Normal Ecompass Handler
    EcHandler();
    
    // Gnss handler function
    GnssHandler();    
        
    Chrono_Manager();
    
    Runtime_Manager();  
    
  }
  
  // The handler for Compass Calibration
  if(( CounterNotToCaliCompass-- <= 0 )&&(DSX_Opcode == C9_COMPASS_PROCESSING))
  {
      if(LSM303IntHandler())
      {    
          CounterCaliCompass++;
          CounterNotToCaliCompass = COUNT_NOT_TO_CALI_COMPASS;
      }
  }

  // Check Button Reboot Request
  ButtonSystemRebootManager();
  
  // Ble handler function
  ////////////////////////////////////////////////
  Ble_Handler();

  
  if( (  (!SystemStatus.System_DeepSleepReq)
      // && (!SystemStatus.System_LowBatDeepSleepReq)   // removed this on 2022 08 18, to allow Low Batt (= 0) Dive able to comback to Surface (while LCD off)
      && (!SystemStatus.System_FastDeepSleepReq) )
      || AppInCommunicating() )
  {
    // Allow Tick scheduling, we are sure that after POR and DeepSleep exit tick 0 will be the first
    TickHandler.allow_tick_scheduling = true;
    
    switch(TickHandler.scheduled_tick)
    {
      case 0:
        if(TickHandler.tick_processed[0] == false)
        {
	  TP0_HIGH;
	  TickCounter[0]++;		
          L4X9_TickHandler_0();  
          TickCounter[10]++;
          
          TickHandler.tick_processed[0] = true;     // Tick Processed
          TP0_LOW; 
        }
        break;
        
      case 1:
        if(TickHandler.tick_processed[1] == false)
        {
          TP1_HIGH;
          TickCounter[1]++;
          L4X9_TickHandler_1();
          TickCounter[11]++;  

          TickHandler.tick_processed[1] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      case 2:
        if(TickHandler.tick_processed[2] == false)
        {
          TP1_HIGH;
          TickCounter[2]++;
          L4X9_TickHandler_2();
          TickCounter[12]++;    

          TickHandler.tick_processed[2] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      case 3:
        if(TickHandler.tick_processed[3] == false)
        {
          TP1_HIGH;
          TickCounter[3]++;
          L4X9_TickHandler_3();
          TickCounter[13]++;

          TickHandler.tick_processed[3] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      case 4:
        if(TickHandler.tick_processed[4] == false)
        {
          TP2_HIGH;
          TickCounter[4]++;
          L4X9_TickHandler_4();
          TickCounter[14]++;

          TickHandler.tick_processed[4] = true;     // Tick Processed
          TP2_LOW; 
        }
        break;
          
      case 5:
        if(TickHandler.tick_processed[5] == false)
        {
          TP1_HIGH;
          TickCounter[5]++; 
          L4X9_TickHandler_5();
          TickCounter[15]++;

          TickHandler.tick_processed[5] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      case 6:
        if(TickHandler.tick_processed[6] == false)
        {
          TP1_HIGH;
          TickCounter[6]++; 
          L4X9_TickHandler_6();
          TickCounter[16]++;
          
          TickHandler.tick_processed[6] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      case 7:
        if(TickHandler.tick_processed[7] == false)
        {
          TP1_HIGH;
          TickCounter[7]++;
          L4X9_TickHandler_7();
          TickCounter[17]++; 

          TickHandler.tick_processed[7] = true;     // Tick Processed
          TP1_LOW; 
        }
        break;
          
      default:
        break;
    }
    
    // If system reboot request has been issued 
    if(SystemStatus.system_reboot_request)  
    {
      // Store all Ram Data to EEPROM
      NVD_RAMTOTAL_to_ExtEEPROM();      
      
      // Wait to complete any comunication
      ms_delay(2000);
          
      // Reboot 
      HAL_NVIC_SystemReset();
    }  

  TP2_LOW;
  
  #if PSM_ENABLED

    if(  ((LPUART1->CR1 & USART_CR1_UE)||(BLE_IS_CONNECTED))    // for Bluetooth ON
      || (TIM3->CR1 & TIM_CR1_CEN)                              // for Buzzer ON
      || (TIM8->CR1 & TIM_CR1_CEN)                              // for Vibrator ON
      || ((EcData.Status == COMPASS_CALIBRATING)||(DSX_Opcode == C9_COMPASS_PROCESSING))        // for Compass ON
      || ((GnssStatus==GNSS_ON)||(GnssReqOn==true)||(GnssReqWake==true)) )      // for GPS ON
    {
        // Wait to complete any comunication
        // ms_delay(1); // For Debugging Only, DO NOT USE FOR PRODUCT
    }
    else if( USART1->CR1 & USART_CR1_UE )
    {
      // Enter Stop Mode 1 onyl if UART1 is not busy
      if( (__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_BUSY) == RESET) 
            && (__HAL_UART_GET_FLAG(&GnssUartHandle, USART_ISR_IDLE) == SET)
              )
      {
        if(SystemStatus.GnssOn)
          CXD5605GF_StopModeEnter();
             
        L4X9_StopMode1Enter();
          
        if(SystemStatus.GnssOn)
          CXD5605GF_StopModeExit();
      }
    }
    else
      L4X9_StopMode2Enter();

  #endif    
  }
  
  // Reload watchdog previouse routines may be time consuming
  L4X9_WatchDogReload();
}




/* Initialize SystemStatus Global Structure */
void SystemStatus_Init (void)
{
  //memset (&SystemStatus, 0, sizeof(SystemStatus));
  
  SystemStatus.backlight_on_req = false;
  SystemStatus.backlight_dim_req = false;
  SystemStatus.backlight_off_req = false;
  SystemStatus.backlight_on = BACKLIGHT_OFF;
  SystemStatus.backlight_act_timestamp = 0;
  
  SystemStatus.buzzer_on_req = false;
  SystemStatus.buzzer_on = false;
  SystemStatus.buzzer_act_timestamp = 0;
  
  SystemStatus.vibe_on_req = false;
  SystemStatus.vibe_on = false;
  SystemStatus.vibe_act_timestamp = 0;
  
  SystemStatus.BLE_last_activity_s = 0;
  SystemStatus.BLE_status = 0;
  
  SystemStatus.blink_counter = 0;
  SystemStatus.blink_0s5 = false;
  SystemStatus.blink_1s0 = false;
  SystemStatus.blink_1s5 = false;
  SystemStatus.blink_2s0 = false;
  
  SystemStatus.watchmode_on = false;
    
  SystemStatus.Demo_On = false;
  SystemStatus.Demo_Up = false;
  SystemStatus.Demo_Down = false;
  SystemStatus.Demo_X60 = false;
  SystemStatus.Demo_Shift = false;
  
  SystemStatus.NvdUpdateInProgress = false;
  
  SystemStatus.BLE_PassCode[0] = 0x30;
  SystemStatus.BLE_PassCode[1] = 0x30;
  SystemStatus.BLE_PassCode[2] = 0x30;
  SystemStatus.BLE_PassCode[3] = 0x30;
  SystemStatus.BLE_PassCode[4] = 0x30;
  SystemStatus.BLE_PassCode[5] = 0x30;
  
  SystemStatus.SystemPowerMode = SYS_SLEEP;
  
}



void DemoPinsManager (void)
{
  if( DEV_Board() && (HAL_GPIO_ReadPin(USER_SIMULATE_PORT, USER_DEMO_PIN) == 1) )
  {
    SystemStatus.Demo_On = true;
      
    if( HAL_GPIO_ReadPin(USER_SIMULATE_PORT, USER_X60_PIN) == 0 )
      SystemStatus.Demo_X60 = true;
    else
      SystemStatus.Demo_X60 = false;
      
    if( HAL_GPIO_ReadPin(USER_SIMULATE_PORT, USER_SHIFT_PIN) == 0 )
      SystemStatus.Demo_Shift = true;
    else
      SystemStatus.Demo_Shift = false; 
      
    if( HAL_GPIO_ReadPin(USER_SIMULATE_PORT, USER_DOWN_PIN) == 0 )
      SystemStatus.Demo_Down = true;
    else
      SystemStatus.Demo_Down = false; 
      
    if( HAL_GPIO_ReadPin(USER_SIMULATE_PORT, USER_UP_PIN) == 0 )
      SystemStatus.Demo_Up = true;
    else
      SystemStatus.Demo_Up = false; 
  }
  else if( !DEV_Board() && (HAL_GPIO_ReadPin(PROD_USER_SIMULATE_PORT, PROD_USER_DEMO_PIN) == 0) )
  {
    SystemStatus.Demo_On = true;
      
    if( HAL_GPIO_ReadPin(PROD_USER_SIMULATE_PORT, PROD_USER_X60_PIN) == 0 )
      SystemStatus.Demo_X60 = true;
    else
      SystemStatus.Demo_X60 = false;
      
    if( HAL_GPIO_ReadPin(PROD_USER_SIMULATE_PORT, PROD_USER_SHIFT_PIN) == 0 )
      SystemStatus.Demo_Shift = true;
    else
      SystemStatus.Demo_Shift = false; 
      
    if( HAL_GPIO_ReadPin(PROD_USER_SIMULATE_PORT, PROD_USER_DOWN_PIN) == 0 )
      SystemStatus.Demo_Down = true;
    else
      SystemStatus.Demo_Down = false; 
      
    if( HAL_GPIO_ReadPin(PROD_USER_SIMULATE_PORT, PROD_USER_UP_PIN) == 0 )
      SystemStatus.Demo_Up = true;
    else
      SystemStatus.Demo_Up = false; 
  }
  else
    SystemStatus.Demo_On = false;
}


extern uint8_t Backlight_ON_OFF;
extern float lux;
extern uint8_t UnderWaterFlat;
uint8_t ALS_cnt =0;

uint32_t Lux_u32;
float Lux_f;
uint8_t AutoBRIGHTNESS = 10;
uint8_t PreAutoBRIGHTNESS;

uint8_t AutoDim_enable_flat =FALSE;
float SensorReadbackLux = 60.0;
    
void BacklightManager (void)
{   
    int32_t MonotonicClock_s_tmp;  

    MonotonicClock_s_tmp = MonotonicClock_s;  
	/**Zero check here*/

	/////////////////////////////////////////////////////////////////////////
	if(BRIGHTNESS_LV ==0){
		BRIGHTNESS_LV = 30; //default
	}
	

	/////////////////////////////////////////////////////////////////////////
	
    if(HW_Buttons)
    {
      SystemStatus.backlight_on_req = true;
      
      if( (Dive_Info.Status==AMB_DIVEINFO_DIVE)&&(Backlight_Val==DIM_BRIGHT_LV)&&(BRIGHTNESS_LV!=DIM_BRIGHT_LV)/*&&(SystemSupplyMonitor.LowBattBrightnessTo==0)*/)
      {  
          if((DSX_Opcode==DIVE_CC_MAIN)||(DSX_Opcode==DIVE_OC_MAIN)||(DSX_Opcode==DIVE_SM_MAIN)||(DSX_Opcode==DIVE_GSM_MAIN)||(DSX_Opcode==DIVE_GAUGE_MAIN))
              ButtonNoResponseCnt=1;    // delay for one more button pushing, only at Dive Mode, Dim Brightness Time, Not at Brightness Adjustment Time
          else
              ButtonNoResponseCnt=0;    // no delay, works as normal, immdiate response
      }
      else
          ButtonNoResponseCnt=0;        // no delay, works as normal, immdiate response
    }
  
    // Manage Backlight
    if(((MonotonicClock_s_tmp - SystemStatus.backlight_act_timestamp) >= (int32_t)PSM_TIMEOUT_S)
        && ((MonotonicClock_s_tmp - SystemStatus.user_GUI_timestamp) >= 10)
        && ((SystemStatus.backlight_on == BACKLIGHT_ON)||(SystemStatus.backlight_on == BACKLIGHT_DIM))
        && ( (Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE)) 
        && (SystemStatus.BLE_status != BLE_HDL_CONNECT) )
    {  
        SystemStatus.backlight_off_req = true;
    }
    else if(((MonotonicClock_s_tmp - SystemStatus.backlight_act_timestamp) >= (int32_t)USER_Set.BacklightDimTimeSec) 
            && (BRIGHTNESS_DIM_MODE == NVD_ON) && (SystemStatus.backlight_on == BACKLIGHT_ON) && (Dive_Info.Status == AMB_DIVEINFO_DIVE))  
    {
        SystemStatus.backlight_dim_req = true;        
    }
    
    /* DO AUTO SENSOR LIGHT when AUTO Mode is selected */
    if(!((DSX_Opcode == DISPLAY_BRIGHTNESS_SET)||(DSX_Opcode == DISPLAY_AUTODIM__PERCENT)))
    {
        if(((BRIGHTNESS_LV == 110)||(GUI_BRIGHTNESS_LV == 110))&&(DSX_Opcode!=B1_BATT_CHARGE)&&(SystemStatus.BLE_status != BLE_HDL_CONNECT))    // R1006 does NOT run LightSensorLuxReading while BLE Connected
        {
            /*anable auto BR*/        
            // BSL Brightness Control ===========================================================================================================================
            SystemStatus.I2C2_flag = 1;
            
            if(SystemStatus.BLE_status != BLE_HDL_CONNECT)   // R1006 does NOT run LightSensorLuxReading while BLE Connected (just use previous value stored in SensorReadbackLux)
              SensorReadbackLux = LightSensorLuxReading();
            
            AutoBRIGHTNESS = AutoBackLight(SensorReadbackLux);
            
            if(AutoBRIGHTNESS != PreAutoBRIGHTNESS)
                SystemStatus.backlight_on_req = true;
            
            PreAutoBRIGHTNESS = AutoBRIGHTNESS;
            
            if(SystemStatus.SystemPowerMode == SYS_ACTIVE)
            {
                Backlight_Set(AutoBRIGHTNESS);                
            } // End of if(SystemStatus.SystemPowerMode == SYS_ACTIVE) 
            SystemStatus.I2C2_flag = 0;
            // BSL Brightness Control ===========================================================================================================================
            
        }
        else
        {

            if( ((SystemSupplyMonitor.PreBattery_Percentage <= RED_BATT_THRESH)&&(SystemSupplyMonitor.Battery_Percentage > RED_BATT_THRESH))            // charging up
              ||((SystemSupplyMonitor.PreBattery_Percentage <= YELLOW_BATT_THRESH)&&(SystemSupplyMonitor.Battery_Percentage > YELLOW_BATT_THRESH))      // charging up
              ||((SystemSupplyMonitor.PreBattery_Percentage > RED_BATT_THRESH)&&(SystemSupplyMonitor.Battery_Percentage <= RED_BATT_THRESH))            // draining down
              ||((SystemSupplyMonitor.PreBattery_Percentage > YELLOW_BATT_THRESH)&&(SystemSupplyMonitor.Battery_Percentage <= YELLOW_BATT_THRESH)) )    // draining down                 
            {
                SystemStatus.backlight_on_req = true;           // restore normal Brightness
                SystemStatus.backlight_on = BACKLIGHT_DIM;      // pretending out-of-dim moment to restore normal Brightness
            }

          
            if(SystemStatus.SystemPowerMode == SYS_ACTIVE)
            {
                // When backlight_change_req is asserted, the BRIGHTNESS_LV saved on EEPROM is in charge, NOT the adjustable variable GUI_BRIGHTNESS_LV                 
                if( SystemStatus.backlight_on_req )           // Brightness at Brightness
                {
                    if((SystemStatus.backlight_on == BACKLIGHT_DIM)||(SystemStatus.backlight_on == BACKLIGHT_OFF))
                    {
              #if USE_REAL_BATTERY
                        if((SystemSupplyMonitor.Battery_Percentage <= RED_BATT_THRESH)&&(RED_BRIGHTNESS_LV<=BRIGHTNESS_LV))
                          Backlight_Set(RED_BRIGHTNESS_LV);
                        else if((SystemSupplyMonitor.Battery_Percentage <= YELLOW_BATT_THRESH)&&(YELLOW_BRIGHTNESS_LV<=BRIGHTNESS_LV))
                          Backlight_Set(YELLOW_BRIGHTNESS_LV);
                        else
                          Backlight_Set(BRIGHTNESS_LV);
              #else
                    Backlight_Set(BRIGHTNESS_LV);
              #endif
                        SystemStatus.backlight_off_req = false;
                    }    
                    
                    //----------------------------------------------------------------------------------------------------------------------
                    
                    SystemStatus.backlight_off_req = false;
                
                    SystemStatus.backlight_act_timestamp = MonotonicClock_s;  // reset Off Timer
                    SystemStatus.backlight_dim_timestamp = MonotonicClock_s;  // reset Dim Timer
                    SystemStatus.backlight_on = BACKLIGHT_ON;
                    SystemStatus.backlight_on_req = false;
                    SystemStatus.backlight_change_req = false;
                }
                else if( SystemStatus.backlight_dim_req && (SystemStatus.backlight_on == BACKLIGHT_ON))           // Brightness at Dim and Dim Setup
                {
                    SystemStatus.backlight_on = BACKLIGHT_DIM;
                    SystemStatus.backlight_dim_req = false;

                    if((Alarming.AllBits & 0x3FFFFFFF) == 0)     // only allow dim when there is NO alarming (except for Low Batt Alarms (Yellow and Red) )
                    {
              #if USE_REAL_BATTERY     
                        if((SystemSupplyMonitor.Battery_Percentage <= RED_BATT_THRESH)&&(RED_DIM_BRIGHT_LV<=DIM_BRIGHT_LV))
                          Backlight_Set(RED_DIM_BRIGHT_LV);
                        else if((SystemSupplyMonitor.Battery_Percentage <= YELLOW_BATT_THRESH)&&(YELLOW_DIM_BRIGHT_LV<=DIM_BRIGHT_LV))
                          Backlight_Set(YELLOW_DIM_BRIGHT_LV);
                        else
                          Backlight_Set(DIM_BRIGHT_LV);
              #else
                    Backlight_Set(DIM_BRIGHT_LV);
              #endif
                    }

                    //----------------------------------------------------------------------------------------------------------------------
                    
                    SystemStatus.backlight_off_req = false;     
                }
                else if( SystemStatus.backlight_off_req && ((SystemStatus.backlight_on == BACKLIGHT_ON)||(SystemStatus.backlight_on == BACKLIGHT_DIM)))           // Brightness for Sleep Mode
                {
                    SystemStatus.backlight_on = BACKLIGHT_OFF;
                    SystemStatus.backlight_off_req = false;
                    Backlight_Set(0);
                }       
                
                // When backlight_change_req is asserted, adjustable variable GUI_BRIGHTNESS_LV is in charge, NOT the BRIGHTNESS_LV saved on EEPROM
                if( SystemStatus.backlight_change_req && SystemStatus.backlight_on )        // Temporary Brightness during Brightness Setup
                {
            #if USE_REAL_BATTERY      
                    if((SystemSupplyMonitor.Battery_Percentage <= RED_BATT_THRESH)&&(RED_BRIGHTNESS_LV<=GUI_BRIGHTNESS_LV))
                      Backlight_Set(RED_BRIGHTNESS_LV);
                    else if((SystemSupplyMonitor.Battery_Percentage <= YELLOW_BATT_THRESH)&&(YELLOW_BRIGHTNESS_LV<=GUI_BRIGHTNESS_LV))
                      Backlight_Set(YELLOW_BRIGHTNESS_LV);
                    else
                      Backlight_Set(GUI_BRIGHTNESS_LV);
            #else
                    Backlight_Set(GUI_BRIGHTNESS_LV);
            #endif

                    SystemStatus.backlight_act_timestamp = MonotonicClock_s;
                    SystemStatus.backlight_change_req = false;
                }
               
                // When backlight_change_req is asserted, adjustable variable GUI_DIM_BRIGHT_LV is in charge, NOT the DIM_BRIGHT_LV saved on EEPROM
                if( SystemStatus.backlight_dim_change_req )                                 // Temporary Brightness during Brightness Setup
                {
            #if USE_REAL_BATTERY 
                    if((SystemSupplyMonitor.Battery_Percentage <= RED_BATT_THRESH)&&(RED_DIM_BRIGHT_LV<=GUI_DIM_BRIGHT_LV))
                      Backlight_Set(RED_DIM_BRIGHT_LV);
                    else if((SystemSupplyMonitor.Battery_Percentage <= YELLOW_BATT_THRESH)&&(YELLOW_DIM_BRIGHT_LV<=GUI_DIM_BRIGHT_LV))
                      Backlight_Set(YELLOW_DIM_BRIGHT_LV);
                    else
                      Backlight_Set(GUI_DIM_BRIGHT_LV);
            #else
                    Backlight_Set(GUI_DIM_BRIGHT_LV);
            #endif

                    SystemStatus.backlight_act_timestamp = MonotonicClock_s;
                    SystemStatus.backlight_dim_change_req = false;
                }
            } // End if(SystemStatus.SystemPowerMode == SYS_ACTIVE)
        }
    }
    else if((DSX_Opcode == DISPLAY_BRIGHTNESS_SET)&&(GUI_BRIGHTNESS_LV == 110))
    {
        // BSL Brightness Control ===========================================================================================================================
        SystemStatus.I2C2_flag = 1;
        
        if(SystemStatus.BLE_status != BLE_HDL_CONNECT)   // R1006 does NOT run LightSensorLuxReading while BLE Connected (just use previous value stored in SensorReadbackLux)
          SensorReadbackLux = LightSensorLuxReading();
        
        AutoBRIGHTNESS = AutoBackLight(SensorReadbackLux);
        
        if(AutoBRIGHTNESS != PreAutoBRIGHTNESS)
            SystemStatus.backlight_on_req = true;
        
        PreAutoBRIGHTNESS = AutoBRIGHTNESS;
        
        if(SystemStatus.SystemPowerMode == SYS_ACTIVE)
        {
            Backlight_Set(AutoBRIGHTNESS);                
        } // End of if(SystemStatus.SystemPowerMode == SYS_ACTIVE)         
        SystemStatus.I2C2_flag =  0;
        // BSL Brightness Control ===========================================================================================================================        
    }
    
    SystemSupplyMonitor.PreBattery_Percentage = SystemSupplyMonitor.Battery_Percentage;
}    
  
  

float LightSensorLuxReading (void)
{
    static float Lux_f = 0.0;
    ALS_cnt++;
    if(ALS_cnt%2 !=0){
        OPT3001_startConversion();
	//odd ALS_cnt;
    }
    else{
	//even ALS_cnt;
	for(int i=0;i<5;i++)
	{
            if(OPT3001_isConversionReady()==1)
            {
		Lux_u32 = OPT3001_readResult();
                Lux_f = 0.01 * Lux_u32;
                return Lux_f;
            }
	}
    }
    return Lux_f;
}



// Buzzer and Vibrator Manager
void BuzzerVibeManager(void)
{
  // Manage Buzzer
  if( (SystemStatus.buzzer_on_req)  && (SystemStatus.SystemPowerMode == SYS_ACTIVE) )  // Changed By YeuShyr
  {      
    SystemStatus.buzzer_act_timestamp = MonotonicClock_s;
    SystemStatus.buzzer_on = true;
    SystemStatus.buzzer_on_req = false;
    Buzzer_On();
  }
  else if( SystemStatus.buzzer_on )
  {
    SystemStatus.buzzer_on = false;
    Buzzer_Off();
  }
  
  // Manage Vibrator
  if( (SystemStatus.vibe_on_req) && (SystemStatus.SystemPowerMode == SYS_ACTIVE) )  // Changed By YeuShyr
  {     
    SystemStatus.vibe_act_timestamp = MonotonicClock_s;
    SystemStatus.vibe_on = true;
    SystemStatus.vibe_on_req = false;
    Vibrator_On();
  }
  else if( SystemStatus.vibe_on )
  {
    SystemStatus.vibe_on = false;
    Vibrator_Off();
  }  
}


void L4X9_RtcSynchedOperationManager(void)
{
    // Buzzer and Vibrator Manager
    BuzzerVibeManager();
}

// Handle System Transition from Active to PSM/Sleep
void System2PsmSleep(void)
{
  // Force New Day Sleep
  if(SystemStatus.System_SleepReq)
    Dive_Info.Status = AMB_DIVEINFO_NEWDAY_SLEEP;
    
  // Reset Flag
  SystemStatus.System_LowPwrReq = false;
  SystemStatus.System_SleepReq = false;
  SystemStatus.System_ActiveReq = false;        // added by YS, 2021/01/16
    
  SystemStatus.backlight_change_req = false;    // added by YS, 2021/12/28
  SystemStatus.backlight_dim_req = false;       // added by YS, 2021/12/28

  // Switch Off Backlight
  SystemStatus.backlight_on = BACKLIGHT_OFF;    // added by YS, 2021/12/28
  SystemStatus.backlight_off_req = false;       // added by YS, 2021/12/28
  Backlight_Set(0);                             // added by YS, 2021/12/28

  Gnss_Sleep(); // added by YS, 2022/04/13
  Ec_Off();     // added by YS, 2022/04/13

  // Update System Power Mode
  if(Dive_Info.Status == AMB_DIVEINFO_NEWDAY_SLEEP)
  {
    // Set System on Sleep mode
    SystemStatus.SystemPowerMode = SYS_SLEEP;

    // Request Diagnostics
    SystemStatus.DiagnosticReq = true;

    // Turn Off GPS
    Gnss_Off();

    // Callback to UI
    UI_EnterSleep();
  }
  else
  {
    SystemStatus.SystemPowerMode = SYS_PSM;
      
    // Callback to UI
    UI_EnterPsm();
  }
  
  // DeInit the STemWin GUI Library
  GUI_Exit();
      
  // DeInitialize LCD Driver
  LCD_DeInit();

  // Switch Off Receiver
  ReceiverPoweroff();
      
}

// Handle System Transition to Active
void System2Active(void)
{
  // Reset System Active Request 
  SystemStatus.System_ActiveReq = false;   
    
  // Update Last User activity timer
  SystemStatus.user_act_timestamp = MonotonicClock_s;
  
  // Update the moment of when system becomes Active mode
  SystemStatus.WakeUpTimestamp = MonotonicClock_s;
  
  // Initialize LCD Driver
  LCD_Init();

  // Init the STemWin GUI Library
  GUI_Init();
  
  // Request Switch on Backlight
  SystemStatus.backlight_on_req = true;
      
  // Update system Date/Time
  UpdateRealTimeDate(&SysTimeDatePST);
  
  // Get Battery Status
  Update_SystemSupplyMonitor ( &SystemSupplyMonitor );

  // Reset Button
  HW_Buttons = 0;  
    
  // Execute some High Level Code for UI
  switch(SystemStatus.SystemPowerMode)
  {
    case SYS_DSLEEP:
      UI_WakeFromDeepSleep();
      break;
        
    case SYS_LBDSLEEP:
      UI_WakeFromLowBatDeepSleep();
      break;
        
    case SYS_FDSLEEP:
      UI_WakeFromFastDeepSleep();
      break;
        
    case SYS_SLEEP:
      UI_WakeFromSleep();
      break;
        
    case SYS_PSM:
      UI_WakeFromPsm();
      break;
  }
  // Initialize Receiver
  ReceiverInit(1);
    
  // Update System Power Mode
  SystemStatus.SystemPowerMode = SYS_ACTIVE; 
}

// Handle System Transition to Any Deep Sleep mode
void System2AnyDeepSleep(void)
{
  // Callback to UI
  if(SystemStatus.System_LowBatDeepSleepReq)
    UI_EnterLowBatDeepSleep();
  else if(SystemStatus.System_DeepSleepReq)
    UI_EnterDeepSleep();
  else
    UI_EnterFastDeepSleep();
      
  
  // Switch Off Backlight
  
  SystemStatus.backlight_change_req = false;    // added by YS, 2021/12/28
  SystemStatus.backlight_dim_req = false;       // added by YS, 2021/12/28
  
  SystemStatus.backlight_on = BACKLIGHT_OFF;
  SystemStatus.backlight_off_req = false;       // added by YS, 2021/12/28
  Backlight_Set(0);

  // Turn Off GPS
  Gnss_Off();
  // Turn Off Compass
  Ec_Off();     // added by YS, 2022/04/13

  // Switch Off Display
  if (SystemStatus.SystemPowerMode == SYS_ACTIVE)
  {
    // DeInit the STemWin GUI Library
    GUI_Exit();
        
    // DeInitialize LCD Driver
    LCD_DeInit();
  }
    
  // Wait some time to allow background operation to finish
  ms_delay(1000);
    
  // Update System Power Mode
  if(SystemStatus.System_LowBatDeepSleepReq)
    SystemStatus.SystemPowerMode = SYS_LBDSLEEP;
  else if(SystemStatus.System_DeepSleepReq)
    SystemStatus.SystemPowerMode = SYS_DSLEEP;
  else if(SystemStatus.System_FastDeepSleepReq)
    SystemStatus.SystemPowerMode = SYS_FDSLEEP;

  // After DeepSleep start from NewDaySleep
  Dive_Info.Status = AMB_DIVEINFO_NEWDAY_SLEEP;
    
  // Reset Request
  SystemStatus.System_DeepSleepReq = false;
  SystemStatus.System_FastDeepSleepReq = false;
  SystemStatus.System_LowBatDeepSleepReq = false;

  // Switch Off Ble
  Ble_Handler();

  // Switch Off Gnss
  GnssHandler();

  // Switch Off Compass
  EcHandler();

  // Loop while waiting for WakeFromDeepSleep condition
  if(SystemStatus.SystemPowerMode == SYS_LBDSLEEP)
  {
    while( (HW_Buttons == 0) )
    {
      // Wait in StopMode2
      #if PSM_ENABLED  
        L4X9_StopMode2Enter();
      #endif
        
      // Check Button Reboot Request
      ButtonSystemRebootManager();
      
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload(); 
    }
  }
  else if(SystemStatus.SystemPowerMode == SYS_DSLEEP)
  {
    int32_t ButtonTimeStamp = MonotonicClock_s;
      
    while( ( MonotonicClock_s - ButtonTimeStamp < 3 ) )//&& (!UsbCableConnectedDuringSleep) )
    {
      if((HAL_GPIO_ReadPin(BUTTON_TL_PORT, BUTTON_TL_PIN) == 1) || (HAL_GPIO_ReadPin(BUTTON_BL_PORT, BUTTON_BL_PIN) == 1))
        ButtonTimeStamp = MonotonicClock_s;

      // Wait in StopMode2
      #if PSM_ENABLED  
        L4X9_StopMode2Enter();
      #endif
        
      // Check Button Reboot Request
      ButtonSystemRebootManager();
      
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload();
    }
  }
  else
  {
    while( (HW_Buttons == 0) )//&& (!UsbCableConnectedDuringSleep) )
    {
      // Wait in StopMode2
      #if PSM_ENABLED  
        L4X9_StopMode2Enter();
      #endif
        
      // Check Button Reboot Request
      ButtonSystemRebootManager();
          
      // Reload watchdog previouse routines may be time consuming
      L4X9_WatchDogReload();
    }
  }
    
  // Trigger System Active
  SystemStatus.System_ActiveReq = true;
  
  // Initialize Tick Hanlder
  TickHandler.allow_tick_scheduling = false;  // inhibit tick scheduling
  TickHandler.scheduled_tick = 0;             // Schedule Tick 0 as first to process
  TickHandler.tick_processed[0] = false;      // Tick0 not proccessed
  TickHandler.tick_processed[1] = false;      // Tick1 not proccessed
  TickHandler.tick_processed[2] = false;      // Tick2 not proccessed
  TickHandler.tick_processed[3] = false;      // Tick3 not proccessed
  TickHandler.tick_processed[4] = false;      // Tick4 not proccessed
  TickHandler.tick_processed[5] = false;      // Tick5 not proccessed
  TickHandler.tick_processed[6] = false;      // Tick6 not proccessed
  TickHandler.tick_processed[7] = false;      // Tick7 not proccessed
    
  // Reset some Amiental Variables
  memset(&TP_Info, 0, sizeof(TP_Info));
  memset(&Dive_Info, 0, sizeof(Dive_Info));
  TickHandler.wut_125ms_occurred = false;
    
  // After Any DeepSleep start from NewDaySleep
  Dive_Info.Status = AMB_DIVEINFO_NEWDAY_SLEEP;
      
  // Update system Date/Time
  UpdateRealTimeDate(&SysTimeDatePST);
    
  // Update Battery Monitor
  Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
      
  // Request Diagnostics
  SystemStatus.DiagnosticReq = true;
}

/* Button System Reboot Manager */
void ButtonSystemRebootManager(void)
{
  int32_t MonotonicClock_s_tmp;
  
  MonotonicClock_s_tmp = MonotonicClock_s;
  
  if(   (HAL_GPIO_ReadPin(BUTTON_L_PORT, BUTTON_L_PIN) == 0x00)
    &&  (HAL_GPIO_ReadPin(BUTTON_M_PORT, BUTTON_M_PIN) == 0x00)
    &&  (HAL_GPIO_ReadPin(BUTTON_R_PORT, BUTTON_R_PIN) == 0x00)
  )
  {
  }
  else
    SystemStatus.ButtonRebootReqTimestamp = MonotonicClock_s;
  
  /* Execute reboot if button reset combination is held for more than BUTTON_REBOOT_TIMEOUT_S */
  if(MonotonicClock_s_tmp - SystemStatus.ButtonRebootReqTimestamp >= BUTTON_REBOOT_TIMEOUT_S)
  {
    // Store all Ram Data to EEPROM
    NVD_RAMTOTAL_to_ExtEEPROM();      
    
    // Wait to complete any comunication
    ms_delay(2000);
            
    // Reboot 
    HAL_NVIC_SystemReset();
  }
}

/*******************************************************************************

    bool CheckViolationManager(void)

    The routine to assert or release Violation status

*******************************************************************************/
bool CheckViolationManager(void)
{
    bool state = false;
    
    if( VGM_Check() || (AlarmOccured.Bit.SetupVIOLATION == true) || (AlarmOccured.Bit.DepthMax == true) || \
     ( (Dive_Info.SurfTime_s > 300) && ( Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE ) \
      && ( (AlarmOccured.Bit.DelayedVio1 == true) || (AlarmOccured.Bit.DelayedVio2 == true)  \
        || (Alarming.Bit.DECO_Alarm == true)  || (Alarming.Bit.DECO_Warning == true) ) )  )
    {
        isViolation = true;    // this should be the only place to trigger isViolation => true;
        
        if(GAUGE_MODE)
            DVSTAT = 0x90;      // a flag for GAUGE along, needs isViolation to work together to address VIOLATION (when it occurs)
        else if(GSM_MODE)
            DVSTAT = 0xA0;      // a flag for GSM along, needs isViolation to work together to address VIOLATION (when it occurs)
        else        
            DVSTAT = 0x80;      // VIOLATION in CC, OC or SM mode
        
        Alarming.Bit.SetupVIOLATION = true;
        state = true;
        
        /* Check if a temporary Violation Mode change is needed ****************

            during VIOLATION condition:         when out of VIOLATION:
            (mode changes for 24 Hours)         (returns back to ReturnDiveMode)

            CC --> Gauge                        Gauge --> CC
            BO --> Gauge                        Gauge --> CC
            OC --> Gauge                        Gauge --> OC
            SM --> GSM                          GSM --> SM
            GSM = GSM                           GSM = GSM
            Gauge = Gauge                       Gauge = Gauge

        ***********************************************************************/
        if((Dive_Info.SurfTime_s > 600)&&(isViolation == true)&&(isViolationModeChanged == false))
        {
            if(RETURN_DIVE_MODE == DIVE_MODE)
            {
                if(CC_MODE)
                {
                    DIVE_MODE = NVD_MDGAUGE;
                    TRIMIX_Set.CurrTMT_Number_GAUGE = TRIMIX_Set.CC_GASTMT[TRIMIX_Set.CurrGasNumber_CC];
                }
                else if(OC_MODE)
                {
                    DIVE_MODE = NVD_MDGAUGE;
                    TRIMIX_Set.CurrTMT_Number_GAUGE = TRIMIX_Set.OC_GASTMT[TRIMIX_Set.CurrGasNumber_OC];
                }
                else if(SM_MODE)
                {
                    DIVE_MODE = NVD_MDGSM;
                    TRIMIX_Set.CurrTMT_Number_GSM = TRIMIX_Set.SM_GASTMT[TRIMIX_Set.CurrGasNumber_SM];
                }
                else if(BO_MODE)
                {
                    DIVE_MODE = NVD_MDGAUGE;
                    TRIMIX_Set.CurrTMT_Number_GAUGE = TRIMIX_Set.BO_GASTMT[TRIMIX_Set.CurrGasNumber_BO];
                }
                
                EE_SaveReq(EE_USERSET);
                EE_SaveReq(EE_TRIMIXSET);
                
                GUI_DIVE_Mode = DIVE_MODE;
                
                // this should be the only place to trigger isViolationModeChanged => true;
                isViolationModeChanged = true;
                DEV_Rec.LockForGaugeDive = 2;   // Lockup at Gauge Dive (from CC, OC, BO) or GSM (from SM) Dive due to Violation
            }    
        }
    }
    else
    {
        // Do Nothing? 
    }
    
    return state;
}

void RemoveViolationStatus(void)
{
    // Remove all alarm flags    
    isViolation = false;    // this should be the only place to trigger isViolation = true;
    isViolationModeChanged = false;  // added YS on 2022 04 24
    DVSTAT = 0x20;
    AlarmInit();
    
    DEV_Rec.RetainIndex = 0;              // remove the retention flag from EEPROM
    EE_SaveReq(EE_DEVREC);                // save to EE
    DIVE_MODE = RETURN_DIVE_MODE;         // restore ReturnDiveMode back to DiveMode
    EE_SaveReq(EE_USERSET);               // save to EE
    
    GUI_DIVE_Mode = DIVE_MODE;
}
/*******************************************************************************

    EmergencySurfaceShutdown(void) is called when

    (1) before Automatic Shutdown during Surface Mode due to Out-Of-Battery 

******************************************************************************/
void EmergencySurfaceShutdown(void)
{
    Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
    if(SystemSupplyMonitor.Battery_Percentage <= BAT_NO_OPERATE_PERCENTAGE)             // During Dive Mode, shutdown when BattPct <= 0%
    {
        DEV_Rec.SystemErrorWarningBits.LowBattery = true;
        SystemStatus.System_LowBatDeepSleepReq = true;
    }
    else
    {
        DEV_Rec.SystemErrorWarningBits.LowBattery = false;
        SystemStatus.System_FastDeepSleepReq = true;
    }
    
    // Update Warning flags in EEPROM
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);       // Write EEPROM RAM Shadow into  EEPROM chip
}
/*******************************************************************************

    EmergencyEndOfDiveBackupAndShutdown(void) is called for dive data backup when

    (1) before Automatic Shutdown during Dive Mode due to Out-Of-Battery 

    (2) before Automatic Shutdown after 10 Hours of Dive Mode (ERR-6)

******************************************************************************/
void EmergencyEndOfDiveBackupAndShutdown(void)
{
    if(DEV_Rec.DivingOngoing != 0)
    {
        // Set in Device Records That Diving is no more ongoing
        DEV_Rec.DivingOngoing = 0;  // do not do DataRetention
        DEV_Rec.LockForGaugeDive = 0;   // Reset to release the lockup at Gauge Dive or GSM Dive
        DEV_Rec.RetainIndex = 0;    // do not do DataRetention
               
        // to save dive data at the Dive-to-After-Dive transition
        SaveLogAndProfile(AMB_DIVEINFO_AFTERDIVE, DEV_Rec.LogNumLast);
        
        // to save dive data at the After-Dive-to-Surface transition
        SaveLogAndProfile(AMB_DIVEINFO_SURF, DEV_Rec.LogNumLast);
    }
    
    Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
    if(SystemSupplyMonitor.Battery_Percentage <= BAT_NO_OPERATE_PERCENTAGE)             // During Dive Mode, shutdown when BattPct <= 0%
    {
        DEV_Rec.SystemErrorWarningBits.LowBattery = true;
        SystemStatus.System_LowBatDeepSleepReq = true;
    }
    else
    {
        DEV_Rec.SystemErrorWarningBits.LowBattery = false;
        SystemStatus.System_FastDeepSleepReq = true;
    }
    
    // Update Warning flags in EEPROM
    NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);       // Write EEPROM RAM Shadow into  EEPROM chip
}