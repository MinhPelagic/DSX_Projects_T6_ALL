/*******************************************************************************
 * @file        : Tick_Handler_0.c
 * @brief       : This file contains Tick_0 manager handling:
 *                - Update SysTimeDatePST;
 *                - Uodate SystemSupplyMonitor;
 *                - Measure Pressure and Temeprature
 *                - Check Wet Contact
 *                - Update TP_Info
 *                - Update Dive_Info
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
#include "O2.h"

float Demo_Pressure_mbar;

/* Tick 0 Handler */
void L4X9_TickHandler_0(void)
{
  /* Please insert here your code for Tick 0 processing */

  /************************* Update System Date/Time **************************/
  UpdateRealTimeDate(&SysTimeDatePST);
  
  /********************** Update System Supply Monitor ************************/
  if( (MonotonicClock_s%SSM_UPDATE_S) == 0 )    // routine check per every minute
  {
    if(SystemStatus.SystemPowerMode != SYS_SLEEP)
      Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
    else if( (MonotonicClock_s%SSM_SLEEPMODE_UPDATE_S) == 0 )
      Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
  }
  
  /*** Measure Pressure and Temperature; Update all related Data Structures ***/ 
  AmbientalManager();
  
  /* Update Pressure in Demo Mode */
  if ( SystemStatus.Demo_On )
  {
    /* In case of initialization */
    if(Demo_Pressure_mbar == 0)
      Demo_Pressure_mbar = 1024;  //temp      //TP_Info.InstantPressure_mbar;
    
    if ( SystemStatus.Demo_Shift )
    {
      if( SystemStatus.Demo_Down )
        Demo_Pressure_mbar += F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_SHIFT_DOWN )));
        
      if( SystemStatus.Demo_Up && ((Demo_Pressure_mbar-Dive_Info.SurfacePressure_mbar) >= F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_SHIFT_UP )))) )
        Demo_Pressure_mbar -= F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_SHIFT_UP )));
      else if( SystemStatus.Demo_Up )
        Demo_Pressure_mbar = Dive_Info.SurfacePressure_mbar;
    }
    else
    {
      if( SystemStatus.Demo_Down )
        Demo_Pressure_mbar += F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_DOWN )));
        
      if( SystemStatus.Demo_Up && ((Demo_Pressure_mbar-Dive_Info.SurfacePressure_mbar) >= F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_UP )))) )
        Demo_Pressure_mbar -= F_DEPTH_m_TO_DLTPRESS_SALT_mbar((F_CONVERT_ft_TO_m( DEMO_DEPTH_UP )));
      else if( SystemStatus.Demo_Up )
        Demo_Pressure_mbar = Dive_Info.SurfacePressure_mbar;
    }
    
    TP_Info.AveragePressure_mbar = Demo_Pressure_mbar;
    TP_Info.InstantPressure_mbar = Demo_Pressure_mbar;
      
    TP_Info.AveragePressure_inHg = F_CONVERT_mbar_TO_inHg(TP_Info.AveragePressure_mbar);
    TP_Info.InstantPressure_inHg = F_CONVERT_mbar_TO_inHg(TP_Info.InstantPressure_mbar);
    
    /* Update MonotonicClock Time */
    if( SystemStatus.Demo_X60 )
      MonotonicClock_s += 59;
  }
  else
    Demo_Pressure_mbar = TP_Info.InstantPressure_mbar;
    
  /********************* Update Global Dive Info Structure ********************/
  if ( SystemStatus.Demo_On )
    UpdateDiveInfo( &Dive_Info, Demo_Pressure_mbar, TP_Info.AverageTemperature_C, USER_Set );
  else
    UpdateDiveInfo( &Dive_Info, TP_Info.InstantPressure_mbar, TP_Info.AverageTemperature_C, USER_Set );

  // Moved to Tick1 after R1006, because Tick0 is very busy doing many other tasks
  //if( ( Dive_Info.Status != AMB_DIVEINFO_DIVE )&&( Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE ) )     // Avoid EEPROM Read/Write underwater, added for R1006
  //{
  //    SystemStatus.NVD_EE_W_flag0 = NVD_Process_RAMBLOCK_to_ExtEEPROM(SystemStatus.NVD_EE_W_flag0);
  //}
  
  O2_Analyzer_Manager();        // Surface Mode only
  
  TMT_Receiver_Manager();       // Surface Mode and Dive Mode, except for PSM and Sleep Mode
  
  Chrono_Manager();
  
  Runtime_Manager();
  
  if( (SystemStatus.SystemPowerMode == SYS_ACTIVE) && (SystemStatus.DiagnosticReq) )
      SystemDiagnostics();
  
  if(SystemStatus.SystemPowerMode != SYS_SLEEP)
  {
    DiveAlgo();
    DiveMode();
  }
  
  // For EE Stress Test
  //if( SystemStatus.NVD_EE_W_flag0 == 0 )
  //    NVD_EE_StressTestReq();              // Do All-EEPROM R/W Stress Test
}
