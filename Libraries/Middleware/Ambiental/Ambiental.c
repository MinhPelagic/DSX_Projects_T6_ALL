/*******************************************************************************
 * @file        : Ambiental.c
 * @brief       : Middleware for Ambiental
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
#include "L4X9_includes.h"

#ifdef _AMBIENTAL_H_

int32_t LastAmbientUpdate_s = -(60L*60L);
int32_t LastAutoZeroUpdate_s = -(60L*60L);

/******************************************************************************
 * @brief   Altitude Calculation Routine
 *
 * @note    Returns Altitude in meters
 *          Local Function
 *
 ******************************************************************************/
uint16_t CalcAltitude ( float surf_press_mbar )
{
  uint16_t altitude;
  int32_t altitude_fr;
  int32_t surf_press_4_altitude = (int32_t)(surf_press_mbar*1000);
  
  if ( ( SEALEVEL_REF_PRESSURE - surf_press_4_altitude ) <= 0 )
    altitude = 0;
  else 
  {
    if ( (surf_press_4_altitude < SEALEVEL_REF_PRESSURE) && (surf_press_4_altitude >= ALTITUDE_REF_L05) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L05)*1000L) / (SEALEVEL_REF_PRESSURE - ALTITUDE_REF_L05); 
      altitude = ((1000L - altitude_fr)*500L)/1000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L05) && (surf_press_4_altitude >= ALTITUDE_REF_L10) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L10)*1000L) / (ALTITUDE_REF_L05 - ALTITUDE_REF_L10); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L10) && (surf_press_4_altitude >= ALTITUDE_REF_L15) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L15)*1000L) / (ALTITUDE_REF_L10 - ALTITUDE_REF_L15); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 1000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L15) && (surf_press_4_altitude >= ALTITUDE_REF_L20) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L20)*1000L) / (ALTITUDE_REF_L15 - ALTITUDE_REF_L20); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 1500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L20) && (surf_press_4_altitude >= ALTITUDE_REF_L25) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L25)*1000L) / (ALTITUDE_REF_L20 - ALTITUDE_REF_L25); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 2000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L25) && (surf_press_4_altitude >= ALTITUDE_REF_L30) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L30)*1000L) / (ALTITUDE_REF_L25 - ALTITUDE_REF_L30); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 2500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L30) && (surf_press_4_altitude >= ALTITUDE_REF_L35) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L35)*1000L) / (ALTITUDE_REF_L30 - ALTITUDE_REF_L35); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 3000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L35) && (surf_press_4_altitude >= ALTITUDE_REF_L40) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L40)*1000L) / (ALTITUDE_REF_L35 - ALTITUDE_REF_L40); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 3500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L40) && (surf_press_4_altitude >= ALTITUDE_REF_L45) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L45)*1000L) / (ALTITUDE_REF_L40 - ALTITUDE_REF_L45); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 4000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L45) && (surf_press_4_altitude >= ALTITUDE_REF_L50) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L50)*1000L) / (ALTITUDE_REF_L45 - ALTITUDE_REF_L50); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 4500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L50) && (surf_press_4_altitude >= ALTITUDE_REF_L55) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L55)*1000L) / (ALTITUDE_REF_L50 - ALTITUDE_REF_L55); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 5000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L55) && (surf_press_4_altitude >= ALTITUDE_REF_L60) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L60)*1000L) / (ALTITUDE_REF_L55 - ALTITUDE_REF_L60); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 5500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L60) && (surf_press_4_altitude >= ALTITUDE_REF_L65) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L65)*1000L) / (ALTITUDE_REF_L60 - ALTITUDE_REF_L65); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 6000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L65) && (surf_press_4_altitude >= ALTITUDE_REF_L70) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L70)*1000L) / (ALTITUDE_REF_L65 - ALTITUDE_REF_L70); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 6500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L70) && (surf_press_4_altitude >= ALTITUDE_REF_L75) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L75)*1000L) / (ALTITUDE_REF_L70 - ALTITUDE_REF_L75); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 7000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L75) && (surf_press_4_altitude >= ALTITUDE_REF_L80) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L80)*1000L) / (ALTITUDE_REF_L75 - ALTITUDE_REF_L80); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 7500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L80) && (surf_press_4_altitude >= ALTITUDE_REF_L85) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L85)*1000L) / (ALTITUDE_REF_L80 - ALTITUDE_REF_L85); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 8000L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L85) && (surf_press_4_altitude >= ALTITUDE_REF_L90) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L90)*1000L) / (ALTITUDE_REF_L85 - ALTITUDE_REF_L90); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 8500L;
    }
    else if ( (surf_press_4_altitude < ALTITUDE_REF_L90) && (surf_press_4_altitude >= ALTITUDE_REF_L95) )
    {
      altitude_fr = ((surf_press_4_altitude - ALTITUDE_REF_L95)*1000L) / (ALTITUDE_REF_L90 - ALTITUDE_REF_L95); 
      altitude = ((1000L - altitude_fr)*500L)/1000L + 9000L;
    }
    else
      altitude = 9500;
  }
  return altitude;
}

/******************************************************************************
 * @brief   Converts Altitude in Level Information
 *
 * @note    Local Function
 ******************************************************************************/
uint8_t AltitudeToSeaLavelConv(uint16_t ft)
{
    if(ft > 14000.0)
      return ALT_OVER_LIMIT;
    else if(ft > 13000.0)
      return ALT_LVL_7;
    else if(ft > 11000.0)
      return ALT_LVL_6;
    else if(ft >  9000.0)
      return ALT_LVL_5;
    else if(ft >  7000.0)
      return ALT_LVL_4;
    else if(ft >  5000.0)
      return ALT_LVL_3;
    else if(ft >  3000.0)
      return ALT_LVL_2;
    else 
      return ALT_LVL_0;
}

/******************************************************************************
 * @brief   Special Key to enable Diving function.
 *
 * @note    Local Function
 ******************************************************************************/
uint8_t KeyToEnableDiveMode(void)
{
    if((MFG_Calib.SN.KeyToDive == 0x00)||(MFG_Calib.SN.KeyToDive == 0xFF))
      return 1;
    else
      return 0;
}


/******************************************************************************
 * @brief   Update Temperature and Pressure Structure.
 *
 * @note    
 ******************************************************************************/
void UpdateTPInfo(TP_Info_struct_t *Data, float Temp_C, float Press_mbar)
{
  /* If on Initialization */
  if( Data->InstantPressure_mbar == 0 )
  {
    Data->InstantPressure_mbar = Press_mbar;
    Data->AveragePressure_mbar = Press_mbar;
    
    Data->InstantPressure_inHg = F_CONVERT_mbar_TO_inHg(Press_mbar);
    Data->AveragePressure_inHg = Data->InstantPressure_inHg;
    
    for( uint16_t idx = 0; idx < PRESS_SHORTQUEQUE_SIZE; idx++ )
      Data->PressureShortTermQueque[idx] = Press_mbar;
    Data->PressureShortTermQuequeIdx = (PRESS_SHORTQUEQUE_SIZE-1);
    
    Data->InstantTemperature_C = Temp_C;
    Data->AverageTemperature_C = Temp_C;
    //tempC = Data->InstantTemperature_C;
    
    Data->InstantTemperature_F = F_CONVERT_C_TO_F(Temp_C);
    Data->AverageTemperature_F = Data->InstantTemperature_F;

    for( uint16_t idx = 0; idx < TEMP_SHORTQUEQUE_SIZE; idx++ )
      Data->TemperatureShortTermQueque[idx] = Temp_C;
    Data->TemperatureShortTermQuequeIdx = (TEMP_SHORTQUEQUE_SIZE-1);
  }
  else
  {
    /* Store Instant pressure data */
    Data->InstantPressure_mbar = Press_mbar;
    Data->InstantPressure_inHg = F_CONVERT_mbar_TO_inHg(Press_mbar);
    
    /* Update Queque with most recent sample and index index */
    if(++Data->PressureShortTermQuequeIdx >= PRESS_SHORTQUEQUE_SIZE)
      Data->PressureShortTermQuequeIdx = 0;
    Data->PressureShortTermQueque[Data->PressureShortTermQuequeIdx] = Press_mbar;
    
    /* Update average */
    Data->AveragePressure_mbar = 0;
    for( uint16_t idx = 0; idx < PRESS_SHORTQUEQUE_SIZE; idx++ )
      Data->AveragePressure_mbar += Data->PressureShortTermQueque[idx];
    Data->AveragePressure_mbar /= PRESS_SHORTQUEQUE_SIZE;
    Data->AveragePressure_inHg = F_CONVERT_mbar_TO_inHg(Data->AveragePressure_mbar);
    
    /* Store Instant temperature data */
    Data->InstantTemperature_C = Temp_C;
    Data->InstantTemperature_F = F_CONVERT_C_TO_F(Temp_C);
    
    /* Update Queque with most recent sample and index index */
    if(++Data->TemperatureShortTermQuequeIdx >= TEMP_SHORTQUEQUE_SIZE)
      Data->TemperatureShortTermQuequeIdx = 0;
    Data->TemperatureShortTermQueque[Data->TemperatureShortTermQuequeIdx] = Temp_C;
    
    /* Update average */
    Data->AverageTemperature_C = 0;
    for( uint16_t idx = 0; idx < TEMP_SHORTQUEQUE_SIZE; idx++ )
      Data->AverageTemperature_C += Data->TemperatureShortTermQueque[idx];
    Data->AverageTemperature_C /= TEMP_SHORTQUEQUE_SIZE;
    Data->AverageTemperature_F = F_CONVERT_C_TO_F(Data->AverageTemperature_C);
  }
  
  /* Sync Struct Update Time to System MonotonicClcok*/
  Data->UpdateTimeStamp = MonotonicClock_s;
  
  /* Update Device Parameters */
  if(Data->InstantTemperature_F*10 < (float)DEV_Rec.DevLowestTempF10)
  {
    DEV_Rec.DevLowestTempF10 = (int16_t)(Data->InstantTemperature_F*10);  // Device All-Time-Low Record 
  }
  if(Data->InstantTemperature_F*10 > (float)DEV_Rec.DevHighestTempF10)
  {
    DEV_Rec.DevHighestTempF10 = (int16_t)(Data->InstantTemperature_F*10); // Device All-Time-High Record       
  }  
  
  if(Data->InstantTemperature_F*10 < (float)DEV_Rec.DevLowestTempF10)
  {
    DEV_Rec.DevLowestTempF10 = (int16_t)(Data->InstantTemperature_F*10);  // Device All-Time-Low Record 
  }
  if(Data->InstantTemperature_F*10 > (float)DEV_Rec.DevHighestTempF10)
  {
    DEV_Rec.DevHighestTempF10 = (int16_t)(Data->InstantTemperature_F*10); // Device All-Time-High Record       
  }  
  
  if(Press_mbar*10 > (float)DEV_Rec.DevMaxPressureMbar10)
    DEV_Rec.DevMaxPressureMbar10 = (uint16_t)(Press_mbar*10);
}

/******************************************************************************
 * @brief   Update Dive Info Structure.
 *
 * @note    Surface Pressure is updated only if WetContact is Dry
 ******************************************************************************/
void UpdateDiveInfo(Dive_Info_struct_t *Data, float Press_mbar, float Temp_C, User_Settings_t SystemData)
{
  static float depth_averagesum_m = 0;                  // resetable
  static float depth_NoReset_averagesum_m = 0;          // non-resetable
  static float depth_NoReset_averagesum_ft = 0;         // non-resetable
  static uint32_t depth_average_samples = 0;
  
  static float temperature_averagesum_C = 0;
  static uint32_t  temperature_average_samples = 0;
  
  float fMeasuredMeter = 0.0;
  
  Data->PreStatus = Data->Status;
    
  /* If on POR Initialization */
  if( Data->SurfacePressure_mbar == 0.0 )
  {     
    if(Press_mbar <= MAX_SEALEVEL_ATMPRESSURE)
      Data->SurfacePressure_mbar = Press_mbar;
    else
      Data->SurfacePressure_mbar = MAX_SEALEVEL_ATMPRESSURE;
    
    GUI_Activation_mBAR = (uint16_t)Data->SurfacePressure_mbar;         // Ambient Calibration will refresh GUI_Activation_mBAR again
      
    Data->SurfacePressure_inHg = F_CONVERT_mbar_TO_inHg(Data->SurfacePressure_mbar);
    
    /* Switch Water Type */
    if( Data->SurfacePressure_mbar <= ALTITUDE_PRESSURE_SWITCH_MBAR )
      SystemData.WaterType = NVD_FRESH;
    else
      SystemData.WaterType = NVD_SALT;
  }
  else if( MonotonicClock_s - LastAutoZeroUpdate_s >= 5)
  {
    // TimeStamp this AutoZero
    LastAutoZeroUpdate_s = MonotonicClock_s;
    
    /* Update Surface pressure if:
      - Not diving 
      - Valid Surface Ambient pressure 
      - Pressure difference is lower than allowed threshold
    */
    if(      ((Data->Status != AMB_DIVEINFO_DIVE) && (Data->Status != AMB_DIVEINFO_AFTERDIVE))
          && (Press_mbar <= MAX_SEALEVEL_ATMPRESSURE)
          && (Press_mbar <= (Data->SurfacePressure_mbar + SURFPRESS_TOL_SHIFT))
          && (Press_mbar >= (Data->SurfacePressure_mbar - SURFPRESS_TOL_SHIFT)) 
      )
    {
      Data->SurfacePressure_mbar = Press_mbar;
      Data->SurfacePressure_inHg = F_CONVERT_mbar_TO_inHg(Press_mbar);
      
      /* Switch Water Type */
      if( Data->SurfacePressure_mbar <= ALTITUDE_PRESSURE_SWITCH_MBAR )
        SystemData.WaterType = NVD_FRESH;
      else
        SystemData.WaterType = NVD_SALT;
    }
  }
  
  // Calculate Altitude and level
  Data->Altitude_m = CalcAltitude ( Data->SurfacePressure_mbar );
  Data->Altitude_ft = (uint16_t) ( (((uint32_t)Data->Altitude_m) * 10000UL)/3048UL ) ;
  Data->AltitudeLevel = AltitudeToSeaLavelConv(Data->Altitude_ft);
    
  /* Evaluate Relative Water Pressure */
  Data->WaterPressure_mbar = Press_mbar - Data->SurfacePressure_mbar;
  Data->WaterPressure_inHg = F_CONVERT_mbar_TO_inHg(Data->WaterPressure_mbar);
  
  if( (Data->WaterPressure_mbar > 0) && KeyToEnableDiveMode())
  {
    /* Evaluate Depth */
    if( SystemData.WaterType == NVD_SALT )
    {
      fMeasuredMeter = F_DLTPRESS_mbar_TO_DEPTH_SALT_m(Data->WaterPressure_mbar);      
    }
    else if( SystemData.WaterType == NVD_FRESH )
    {
      fMeasuredMeter = F_DLTPRESS_mbar_TO_DEPTH_FRESH_m(Data->WaterPressure_mbar);      
    }
    else if( SystemData.WaterType == NVD_EN13319 )
    {
      fMeasuredMeter = F_DLTPRESS_mbar_TO_DEPTH_EN13319_m(Data->WaterPressure_mbar);      
    }
    else if( SystemData.WaterType == NVD_WATERAUTO )
    {
      if(Data->SurfacePressure_mbar > ALTITUDE_PRESSURE_SWITCH_MBAR)
        fMeasuredMeter = F_DLTPRESS_mbar_TO_DEPTH_SALT_m(Data->WaterPressure_mbar);
      else
        fMeasuredMeter = F_DLTPRESS_mbar_TO_DEPTH_FRESH_m(Data->WaterPressure_mbar);      
    }
    
    Data->WaterDepth_ft = HOANG_SLOPE * F_CONVERT_m_TO_ft(fMeasuredMeter) + ANTHONY_OFFSET;
    Data->WaterDepth_m = CONST_FT_TO_M * (Data->WaterDepth_ft);        // Anthony said that DO NOT use this constant in his DiveAlgo
  }
  else
  {
    Data->WaterDepth_m = 0.0;
    Data->WaterDepth_ft = 0.0;
  }
  
  Data->WaterTemperature_C = Temp_C;
  Data->WaterTemperature_F = F_CONVERT_C_TO_F(Temp_C);
    
  if(Data->WaterDepth_m > WATER_ENTRANCE_DETECT_DEPTH_M)
    Data->WaterEntranceDetected = true;
  else
    Data->WaterEntranceDetected = false;
  
  bool dive_started = false;
  bool dive_ended = false;
  
  switch (Data->Status)
  {
    case AMB_DIVEINFO_NEWDAY:
    case AMB_DIVEINFO_SURF:
    case AMB_DIVEINFO_NEWDAY_SLEEP:

      if( ( ( NewDayInitDone == true )||(DataRetainDone == true) ) /* && (SystemSupplyMonitor.Battery_Percentage >= BAT_NOOPERATE_PERCENTAGE) */
        &&( ( (UNITS == NVD_METRIC)   && (Data->WaterDepth_m >= 1.50 ) )        // start diving at 1.5 meter
          ||( (UNITS == NVD_IMPERIAL) && (Data->WaterDepth_ft >= 5.00) ) ) )     // start diving at 5.0 feet          
      {
        if(!Data->FirstStartDetected)
          Data->FirstStartDetected = true;
      
        if( ConditionsOKtoDive() )    // check all other conditions all OK to dive
          dive_started = true;

        Data->FirstStartDetected = false;
      }
      else
        Data->FirstStartDetected = false;


      // System Wakeup from NewDay Sleep Mode----------------------------------------------------------------------  
      
      if(   ((Data->Status == AMB_DIVEINFO_NEWDAY_SLEEP) && (SystemStatus.SystemPowerMode == SYS_ACTIVE))
         || ((Data->Status == AMB_DIVEINFO_NEWDAY_SLEEP) && (dive_started)) )
      {
        Data->Status = AMB_DIVEINFO_NEWDAY;
        
        Data->StartSurfTime_s = MonotonicClock_s;
        Data->PrevSurfTime_s = 0;       // for no previous Dive, so = 0
        Data->SurfTime_s = 0;
        Data->AfterDiveGapID = 0;
        
        DEV_Rec.DiveNumOfDay = 0;
        DEV_Rec.FreeDiveNumOfDay = 0;
      }
      
      // System Back to NewDay Sleep Mode if No Dives -------------------------------------------------------------
      if( ((Data->Status == AMB_DIVEINFO_SURF) && (Data->SurfTime_s > NEWDAY_TIMEOUT))          ||
          ((Data->Status == AMB_DIVEINFO_NEWDAY) && (Data->SurfTime_s > NEWDAY_NODIVE_TIMEOUT)) )
      {
        Data->Status = AMB_DIVEINFO_NEWDAY_SLEEP;
        
        // Force LP mode
        SystemStatus.System_LowPwrReq = true;
        
        Data->SurfTime_s = 0;
        
        DEV_Rec.DiveNumOfDay = 0;
        DEV_Rec.FreeDiveNumOfDay = 0;
      }
      
      if( dive_started )
      {        
        /* Signal Start of Dive */
        Data->Status = AMB_DIVEINFO_DIVE;

        /* Make Time Stamp for start of Dive */
        Data->StartDiveTime_s = MonotonicClock_s;
          
        /* Store Previouse Dive Time */
        Data->PrevDiveTime_s = Data->DiveTime_s;
        
        /* Initialize Surface Time */
        //Data->PrevSurfTime_s = Data->SurfTime_s;      // Moved to the moment when NoPhandive is confirmed        // T1.001.010
        
        /* Initialize Dive Time */
        Data->DiveTime_s = 0;           // start the DiveTime
        Data->PartialDiveTime_s = 0;    // start the partial DiveTime
        Data->AfterDiveTime_s = 0;      // reset the AfterDiveTime
        /* Reset Phantom Dive Check Counter and Flag */
        Data->PhantomCheckDone = false;         // needs a phamton check
        Data->NoPhantomCtr = 0;                 
        
        /* Store Previouse Max Dive Depth */
        Data->PrevMaxWaterDepth_m = Data->MaxWaterDepth_m;
        Data->PrevMaxWaterDepth_ft = Data->MaxWaterDepth_ft;
        
        /* Initialize Max Dive Depth */
        Data->MaxWaterDepth_m = Data->WaterDepth_m;
        Data->MaxWaterDepth_ft = Data->WaterDepth_ft;
        
        /* Initialize Average Dive Depth */
        depth_averagesum_m = Data->WaterDepth_m;
        depth_NoReset_averagesum_ft = Data->WaterDepth_ft;      // this average depth is NOT reseable
        depth_NoReset_averagesum_m  = Data->WaterDepth_m;       // this average depth is NOT reseable
          
        depth_average_samples = 0;
        Data->AvgWaterDepth_m = Data->WaterDepth_m;     // this average depth is reseable by (Data->ResetDiveDepthAvg == true)
        Data->AvgWaterDepth_ft = Data->WaterDepth_ft;   // this average depth is reseable by (Data->ResetDiveDepthAvg == true)
        Data->ResetDiveDepthAvg = false;
        
        /* Initialize Max Dive Temperaure */
        Data->MaxTemp_C = Data->WaterTemperature_C;
        Data->MaxTemp_F = Data->WaterTemperature_F;
        
        /* Initialize Min Dive Temperaure */
        Data->MinTemp_C = Data->WaterTemperature_C;
        Data->MinTemp_F = Data->WaterTemperature_F;
        
        /* Initialize Average Temperature */
        temperature_averagesum_C = Data->WaterTemperature_C;
        temperature_average_samples = 1;
        Data->AvgTemp_C = Data->WaterTemperature_C;
        Data->AvgTemp_F = Data->WaterTemperature_F;
        
        ClearProfileChartData();        // clean up profile chart data buffer whenever a new dive starts 
      }
      else
      {
        /* Update Surface Time */
        if(Data->Status != AMB_DIVEINFO_NEWDAY_SLEEP)
          Data->SurfTime_s = MonotonicClock_s - Data->StartSurfTime_s;
      }
      
      break;
   
    case AMB_DIVEINFO_DIVE:
    case AMB_DIVEINFO_10HDIVE:
      
      if( ( (UNITS == NVD_METRIC) && (Data->WaterDepth_m <= 0.90 ) )         // start diving at 0.9 meter
        ||( (UNITS == NVD_IMPERIAL) && (Data->WaterDepth_ft <= 3.00 ) ) )    // start diving at 3.0 feet
      {
        dive_ended = true;
      }     


        /* Update Dive Time */
        Data->DiveTime_s = (MonotonicClock_s - Data->StartDiveTime_s) - Data->AfterDiveTime_s;
        Data->PartialDiveTime_s++;
        
        // Signal 10 Hour Dive
        if(Data->DiveTime_s >= (60L*60L*10L))
        {
          Data->Status = AMB_DIVEINFO_10HDIVE;
          Data->Dive10hDetected = true;         // this should be the ONLY place to address TRUE
        }
        else
        {
          Data->Status = AMB_DIVEINFO_DIVE;
          Data->Dive10hDetected = false;
        }
 
        /* Update Max Dive Depth */
        if(Data->WaterDepth_m > Data->MaxWaterDepth_m)
        {
          Data->MaxWaterDepth_m = Data->WaterDepth_m;
          Data->MaxWaterDepth_ft = Data->WaterDepth_ft;
        }
        
        /****************************************************************************************    
           All Dives Must check following condition to pass Phantom Dive Test

                  Dive Mode upon descent to 5 FT (1.5 M) for 5 seconds

          ----------------------------------------------------------------------------------
                          |       Time < 5 Sec             |      Time >= 5 Sec            |
          ----------------------------------------------------------------------------------  
          Depth < 1.5 M   |                     NoPhantomCtr = 0                           |
             or < 5 feet  |                 PhantomCheckDone = false;                      |
          ----------------------------------------------------------------------------------
          Depth >= 1.5 M  |      NoPhantomCtr++            |       NoPhantomCtr >= 5       |
             or >= 5 feet |                                |                               |
          ----------------------------------------------------------------------------------
        *****************************************************************************************/
        
        // Only do following check if NoPhantom Not Confirmed Yet
        if(Data->NoPhantomCtr < PHANTOM_SEC)
        {
            if(UNITS==NVD_IMPERIAL)
            {
                if((Data->WaterDepth_ft < 5.0))
                  Data->NoPhantomCtr = 0;
                else
                  Data->NoPhantomCtr++;                  
            }
            else
            {
                if(Data->WaterDepth_m < 1.50)
                  Data->NoPhantomCtr = 0;
                else                
                  Data->NoPhantomCtr++;                                  
            }             
        }

        /******************* End of NoPhantomDive Check *****************************************/
        
        //----------------- RESET Avg Depth of the current dive-----------------
        if(Data->ResetDiveDepthAvg)
        {
            depth_average_samples = 0;
            depth_averagesum_m = 0;
            Data->ResetDiveDepthAvg = false;
        }
        //----------------- RESET Avg Depth of the current dive-----------------
        /* Update Average Dive Depth */
        depth_averagesum_m += Data->WaterDepth_m;
        depth_NoReset_averagesum_m += Data->WaterDepth_m;                               // Avg Depth in M (non-resetable)
        depth_NoReset_averagesum_ft = F_CONVERT_m_TO_ft(depth_NoReset_averagesum_m);    // Avg Depth in Ft (non-resetable)
        depth_average_samples++;
        Data->AvgWaterDepth_m = depth_averagesum_m/((float)depth_average_samples);      // Avg Depth in M (resetable)
        Data->AvgWaterDepth_ft = F_CONVERT_m_TO_ft(Data->AvgWaterDepth_m);              // Avg Depth in Ft (resetable)
        
        /* Update Max Dive Temperaure */
        if(Data->WaterTemperature_C > Data->MaxTemp_C)
        {
          Data->MaxTemp_C = Data->WaterTemperature_C;
          Data->MaxTemp_F = Data->WaterTemperature_F;
        }
        
        /* Update Min Dive Temperaure */
        if(Data->WaterTemperature_C < Data->MinTemp_C)
        {
          Data->MinTemp_C = Data->WaterTemperature_C;
          Data->MinTemp_F = Data->WaterTemperature_F;
        }
        
        /* Update Average Temperature */
        temperature_averagesum_C += Data->WaterTemperature_C;
        temperature_average_samples++;
        Data->AvgTemp_C = temperature_averagesum_C/((float)temperature_average_samples);
        Data->AvgTemp_F = F_CONVERT_C_TO_F(Data->AvgTemp_C);
      
      if( dive_ended )
      {
        DSX_Opcode = S2_SURFACE_MAIN;

        if(Data->NoPhantomCtr >= PHANTOM_SEC)      // finishing a typical dive (scuba, gauge or free)
        {
            /* Signal End of Dive */
            Data->Status = AMB_DIVEINFO_AFTERDIVE;      // advance to after-dive mode

            /* Store Previouse Surface Time */
            //Data->PrevSurfTime_s = Data->StartDiveTime_s - Data->StartSurfTime_s;

            /* Make Time Stamp for start of Surface */
            Data->StartSurfTime_s = MonotonicClock_s;

            Data->SurfTime_s = 0;
            if(Data->AfterDiveGapID < (AfterDiveGapID_Max - 1))
                Data->AfterDiveGapID++;           // must limit in the size of AfterDiveGapID_Max

            Data->NoPhantomCtr = 0;
        }
        else
        {                               // finishing a phantom dive (scuba, gauge or free)
            /* Signal End of Dive */
            if(Dive_Info.DiveTime_s > PHANTOM_SEC*2)
                Data->Status = AMB_DIVEINFO_AFTERDIVE;      // occurs after a real dive ===> advance to after-dive mode
            else
            {
                PhamtonDiveDataRestore();
            }
              
            Data->NoPhantomCtr = 0;
        }
        
      }
      
      break;
      
    case AMB_DIVEINFO_AFTERDIVE:
      
      /* Update Surface Time */
      Data->SurfTime_s = MonotonicClock_s - Data->StartSurfTime_s;  
      Data->AfterDiveSec[0] = Data->SurfTime_s;                         // AfterDiveSec[0] always collects the very last After-Dive SurfT
      Data->AfterDiveSec[Data->AfterDiveGapID] = Data->SurfTime_s;      // AfterDiveSec[i] collects the surfT gaps if occurs mutiple times (re-entry in the same dive)
      
      if( ( (UNITS == NVD_METRIC)   && (Data->WaterDepth_m >= 1.50 ) )        // start diving at 1.5 meter
          ||( (UNITS == NVD_IMPERIAL) && (Data->WaterDepth_ft >= 5.00) ) )      // start diving at 5.0 feet
      {
        if( ConditionsOKtoDive() )    // check all other conditions all OK to dive
        {
          /* Signal Re-Start of Dive */
          if(Data->Dive10hDetected)
            Data->Status = AMB_DIVEINFO_10HDIVE;
          else
          {
            Data->Status = AMB_DIVEINFO_DIVE;
          }
        }
      }
      else if( Data->SurfTime_s > AFTER_DIVE_SURF_INTERVAL_S )
      {
        /* Signal End of AfterDive Interval */
        Data->Status = AMB_DIVEINFO_SURF;
        
        /* Update Device Paramenters Total Dive Time of entire product life */
        DEV_Rec.TotalDiveTimeSec += (uint32_t)Data->DiveTime_s;
        
        /* Calculate Device Average Depth in its Total Life Time, disregard user's Dive Depth Reset during some dives */
        CalcTotalAvgDepth(Data, &DEV_Rec, depth_NoReset_averagesum_ft);
        
        // Set in Device Records that Dive ends offically
        DEV_Rec.DivingOngoing = 0;
        EE_SaveReq(EE_DEVREC);
      }
      break;
  }
  
  /* Sync Struct Update Time to System MonotonicClcok*/
  Data->UpdateTimeStamp = MonotonicClock_s;
  
  if((Data->Status == AMB_DIVEINFO_DIVE)||(Data->Status == AMB_DIVEINFO_AFTERDIVE))
      Data->TotalDiveTime = (uint16_t)(Data->UpdateTimeStamp - Data->StartDiveTime_s);
  
  /* Update Device Record */
  if((Data->WaterDepth_ft*10) > (float)DEV_Rec.DevMaxDepthFt10)
  {
    DEV_Rec.DevMaxDepthFt10 = (uint16_t)(Data->WaterDepth_ft*10);
    DEV_Rec.DevMaxDepthM10 = (uint16_t)(Data->WaterDepth_m*10);
  }
  
  if(Data->AltitudeLevel > DEV_Rec.Max_Elev)
    DEV_Rec.Max_Elev = Data->AltitudeLevel;

  if(Data->Altitude_ft > DEV_Rec.MaxAltitudeFt)
    DEV_Rec.MaxAltitudeFt = Data->Altitude_ft;
  
  if(Data->Altitude_m > DEV_Rec.MaxAltitudeM)    
    DEV_Rec.MaxAltitudeM = Data->Altitude_m;
    
  if(Data->DiveTime_s > DEV_Rec.MaxDiveTimeSec)
    DEV_Rec.MaxDiveTimeSec = Data->DiveTime_s;
}

/******************************************************************************
 * @brief   Update Weather Info Structure.
 *
 * @note    
 ******************************************************************************/
void ResetWeatherInfo(Weather_Info_struct_t *Data, float Temp_F, float Press_mbar)
{
  for(uint8_t idx = 0; idx < BAROMETRIC_LONGQUEQUE_SIZE; idx++)
    Data->BarometricLongTermQueque[idx] = Press_mbar;
  
  Data->BarometricLongTermQuequeIdx = BAROMETRIC_LONGQUEQUE_SIZE-1;
  
  for(uint8_t idx = 0; idx < TEMPERATURE_LONGQUEQUE_SIZE; idx++)
    Data->TemperatureLongTermQueque[idx] = Temp_F;
  
  Data->BarometricLongTermQuequeIdx = TEMPERATURE_LONGQUEQUE_SIZE-1;
  
  /* Sync Struct Update Time to System MonotonicClcok*/
  Data->UpdateTimeStamp = MonotonicClock_s;
}

/******************************************************************************
 * @brief   Update Weather Info Structure.
 *
 * @note    
 ******************************************************************************/
void UpdateWeatherInfo(Weather_Info_struct_t *Data, float Temp_F, float Press_mbar)
{
  if(++Data->BarometricLongTermQuequeIdx >= BAROMETRIC_LONGQUEQUE_SIZE)
    Data->BarometricLongTermQuequeIdx = 0;
  
  Data->BarometricLongTermQueque[Data->BarometricLongTermQuequeIdx] = Press_mbar;
  
  if(++Data->TemperatureLongTermQuequeIdx >= TEMPERATURE_LONGQUEQUE_SIZE)
    Data->TemperatureLongTermQuequeIdx = 0;
  
  Data->TemperatureLongTermQueque[Data->TemperatureLongTermQuequeIdx] = Temp_F;
  
  /* Sync Struct Update Time to System MonotonicClcok*/
  Data->UpdateTimeStamp = MonotonicClock_s;
}


/******************************************************************************
 * @brief   Ambiental Library Manager
 *
 * @note    
 ******************************************************************************/
void AmbientalManager( void )
{
  /* Measure Pressure and Temperature; Update all related Data Structures */
  /* 1) On Surface if no dive has started and out of the surface interval time 
    update pressure and temeprature at TP_SURF_UPDATE_S rate in active mode and
    TP_LP_UPDATE_S at in any low power mode (PSM or Sleep)                    */
  /* 2) During Dive and the surface interval time after dive
    update pressure and temeprature at TP_DIVE_UPDATE_S rate                  */
  if(    ( ( (Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE) ) && (MonotonicClock_s - LastAmbientUpdate_s >= TP_ACT_UPDATE_S) && (SystemStatus.SystemPowerMode == SYS_ACTIVE) )  
      || ( ( (Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE) ) && (MonotonicClock_s - LastAmbientUpdate_s >= TP_LP_UPDATE_S) && ((SystemStatus.SystemPowerMode == SYS_PSM) || (SystemStatus.SystemPowerMode == SYS_SLEEP)) )
      || ( ( (Dive_Info.Status == AMB_DIVEINFO_DIVE) || (Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE) ) && (MonotonicClock_s - LastAmbientUpdate_s >= TP_DIVE_UPDATE_S) )
      || ( (Dive_Info.FirstStartDetected) && (MonotonicClock_s - LastAmbientUpdate_s >= TP_DIVE_UPDATE_S) )
      || ( (SystemStatus.Demo_On) && (MonotonicClock_s - LastAmbientUpdate_s >= TP_DIVE_UPDATE_S) )                                                            
     )
  {
    // Timestamp this update
    LastAmbientUpdate_s = MonotonicClock_s;
    
    /* Measure Pressure and Temperature with specific OSR */
    if (Dive_Info.Status == AMB_DIVEINFO_DIVE)
      MS5837_Meas( MS5837_I2C_ADDR, &MS5837_Sensor, MS5837_30BA_OSR_DIVE, MFG_Calib.LP_Sensor_Offset_ubarx10, MFG_Calib.Temp_Sensor_Offset_mCx10 );
    else
      MS5837_Meas( MS5837_I2C_ADDR, &MS5837_Sensor, MS5837_30BA_OSR_SURF, MFG_Calib.LP_Sensor_Offset_ubarx10, MFG_Calib.Temp_Sensor_Offset_mCx10 );
    
    // RealTime Lp Diagnostic report
    if(MS5837_Sensor.sensor_failure)
    {
        DEV_Rec.SystemErrorWarningBits.SensorPress = 1;
        DEV_Rec.SystemErrorWarningBits.SensorTemp = 1;
        SystemStatus.DiagnosticReq = true;
    }
    /* Update Global TP Info Structure */
    UpdateTPInfo( &TP_Info, (((float)MS5837_Sensor.temp)/100.0f), (((float)MS5837_Sensor.press)/10.0f) );
  }
}

/******************************************************************************
 * @brief   bool ConditionsOKtoDive(void)
 *
 * @note    Checking All Conditions too see if OK to Dive
 ******************************************************************************/
bool ConditionsOKtoDive(void)
{
    bool state = false;
    
    if( SystemSupplyMonitor.Battery_Percentage <= BAT_NO_DIVE_PERCENTAGE)
    {
        SystemStatus.DiagnosticReq = true;                      // Not Allow to Dive if Very Low Battery
        state = false;
    }  
    else if(!REGISTER_Done())                 // Not Allow to Dive if PASSCODE not matched
        state = false;
    else if( (NewDayInitDone == true )||(DataRetainDone == true) )
        state = true;                                           // Allow to Dive either NewDayInitDone or DataRetainDone
    
    return state;
}

/******************************************************************************
 * @brief   void CalcTotalAvgDepth( Dive_Info_struct_t *Data, Device_Records_t *Dev, float DepthSum )
 *
 * @note    Calculate Device's Average Dive Depth in its Life Time
 ******************************************************************************/
void CalcTotalAvgDepth( Dive_Info_struct_t *Data, Device_Records_t *Dev, float DepthSum )
{
    float AvgDepthTimesDiveTime = DepthSum + (((float)(Dev->TotalDiveTimeSec - Data->DiveTime_s)) * Dev->DevAvgDepthFt);
    
    if((Dev->TotalDiveTimeSec) > 0.0)
      Dev->DevAvgDepthFt = (uint16_t)(AvgDepthTimesDiveTime /(Dev->TotalDiveTimeSec));
    else
      Dev->DevAvgDepthFt = (uint16_t)0;
    
    Dev->DevAvgDepthM = (uint16_t)(CONST_FT_TO_M * Dev->DevAvgDepthFt);
}
#endif // _AMBIENTAL_H_