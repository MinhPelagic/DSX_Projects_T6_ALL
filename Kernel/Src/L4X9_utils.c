/*******************************************************************************
 * @file        : L4X9_utils.c
 * @brief       : This file contains all high level helper functions
 *
 * @version     0.0.1
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_UTILS_H_

/******************************************************************************
 * @brief   Update Real Time and Date System Structure.
 *
 * @note
 ******************************************************************************/

uint8_t TempBattPct = 80;

void UpdateRealTimeDate(SystemTimeDate_t *TimeDate)
{
    TimeDate->Hour = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_TIME_GetHour(RTC) );
    TimeDate->Minute = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_TIME_GetMinute(RTC) );
    TimeDate->Second = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_TIME_GetSecond(RTC) );

    TimeDate->WeekDay = (uint8_t)LL_RTC_DATE_GetWeekDay(RTC);
    TimeDate->Day = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_DATE_GetDay(RTC) );
    TimeDate->Month = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_DATE_GetMonth(RTC) );
    TimeDate->Year = (uint8_t)BCD2BIN( (uint8_t)LL_RTC_DATE_GetYear(RTC) );
}


/******************************************************************************
 * @brief   Use the newly GUI set Date and Time
 *               to Real Time Date Time System Structure(s).
 * @note    GUI Date/Time --> System Date/Time
 ******************************************************************************/
void Save_GUI_Set_TimeDate(SystemTimeDate_t *TimeDate)
{
    TimeDate->Hour      = GUI_SetDateTime.Hour;
    TimeDate->Minute    = GUI_SetDateTime.Minute;
    TimeDate->Second    = GUI_SetDateTime.Second;

    TimeDate->WeekDay   = GUI_SetDateTime.WeekDay;
    TimeDate->Day       = GUI_SetDateTime.Day;
    TimeDate->Month     = GUI_SetDateTime.Month;
    TimeDate->Year      = GUI_SetDateTime.Year;
}

/*******************************************************************************
 * @brief   Evaluate 8bit CheckSum on a data structure starting from data_addr
 *          byte and for 'length' bytes.
 *
 * @note
 ******************************************************************************/
uint8_t Eval_CheckSum8 ( const void *data_addr, uint16_t length )
{
    uint8_t checksum = 0;

    const uint8_t *ptr =(const uint8_t *) data_addr;   // get pointer

    for(uint16_t i = 0; i<length; i++)
        checksum += (uint8_t)(*ptr++);

    return checksum;
}

/******************************************************************************
 * @brief       CRC16 Calculation on LookUp Table.
 *
 * @note
 *
 * @param[in]
 *
 ******************************************************************************/
uint16_t Eval_CRC16(const void *data_addr, uint32_t length)
{
    /* CRC16 Initial Value */
    uint16_t crc16 = 0xFFFF;

    const uint8_t *ptr =(const uint8_t *) data_addr;   // get pointer

    /* Loop on buffer */
    while (length--)
        crc16 = *(crc16_lookuptable + ((crc16 >> 8) ^ *ptr++)) ^ (crc16 << 8);

    return crc16;
}

/******************************************************************************
 * @brief       CRC8 Calculation on LookUp Table.
 *
 * @note        Provided by Hoan for BLE
 *
 * @param[in]
 *
 ******************************************************************************/
uint8_t crc8_ccitt(uint8_t *pData, int Len, uint8_t SeedVal)
{
    uint8_t e, f, crc;
    crc = SeedVal;
    for (int i = 0; i < Len; i++)
    {
        e = crc ^ pData[i];
        f = e ^ (e >> 4) ^ (e >> 7);
        crc = (f << 1) ^ (f << 4);
    }
    return crc;
}

/******************************************************************************
 * @brief       CRC16 Calculation on LookUp Table with seed specification.
 *
 * @note
 *
 * @param[in]
 *
 ******************************************************************************/
uint16_t Eval_SeedCRC16(const void *data_addr, uint16_t length, uint16_t seed)
{
    /* CRC16 Initial Value */
    uint16_t crc16 = seed;

    const uint8_t *ptr =(const uint8_t *) data_addr;   // get pointer

    /* Loop on buffer */
    while (length--)
        crc16 = *(crc16_lookuptable + ((crc16 >> 8) ^ *ptr++)) ^ (crc16 << 8);

    return crc16;
}


/*******************************************************************************
 * @brief   Init_SystemSupplyMonitor helper function
 *          This function initialize the System Supply information in the
 *          PRTOS_L4_SystemSupplyMonitor_t structure.
 *
 * @note
 *
 ******************************************************************************/
void Init_SystemSupplyMonitor ( L4X9_SystemSupplyMonitor_t *data )
{
  data->Battery_mV = 0;
  
  data->Battery_Level = 10;
  data->Battery_timestamp = 0;
  data->ChargingEstimate_mV = 0;
  data->OneWayBattery_mV = 0;
  data->StartCharge_timestamp = 0;
  data->LowBattBrightnessTo = 10;
}

/*******************************************************************************
 * @brief   Update_SystemSupplyMonitor helper function
 *          This function measures updates the System Supply information in the
 *          PRTOS_L4_SystemSupplyMonitor_t structure.
 *
 * @note
 *
 ******************************************************************************/
void Update_SystemSupplyMonitor ( L4X9_SystemSupplyMonitor_t *data )
{
  // Get Data from FuelGauge
  MAX17262_GetFgOutput();
  
  // Get Learned Data and save to DevRec
  MAX17262_SaveLearnedParameters(&DEV_Rec.MAX17262_BatteryLearned);
   
  // Copy Battery Data to SystemSupplyMonitor
  SystemSupplyMonitor.Battery_mV = (uint16_t)MAX17262_Output.AvgVoltage_mV;
#if USE_REAL_BATTERY
  SystemSupplyMonitor.Battery_Percentage = (uint8_t)(MAX17262_Output.RepSoc_cx100/100);
#else
  SystemSupplyMonitor.Battery_Percentage = TempBattPct;  // only for debugging, to avoid low brightness
#endif  
  SystemSupplyMonitor.TimeToFull_s = (uint16_t)MAX17262_Output.TTF_s;
  SystemSupplyMonitor.TimeToEmpty_s = (uint16_t)MAX17262_Output.TTE_s;
  
}


/*******************************************************************************
 * @brief   Updates System Timers.
 *
 *
 * @note    Referenced by RTC WakeUp Interrupt
 *
 ******************************************************************************/
void Update_SystemTimers (L4X9_SysTimers_t *timers)
{
    if ( SystemStatus.Demo_X60 )
    {
        /////////////////////////////Wrong!!!!!!!!!!!!!!!TBD
        /* Update Increasing Counters */
        if(DIVE_TIMER_State == TIMER_RUN)
            timers->CounterUP1_s += 59;

        timers->CounterUP2_s += 59;
        timers->CounterUP3_s += 59;

        /* Update Decreasing Counters */
        if(CDT_TIMER_Run == CDT_RUN)
        {
            if(timers->CounterDWN1_s > 60)
                timers->CounterDWN1_s -= 61;
            else
                timers->CounterDWN1_s = 0;
        }

        if( timers->CounterDWN2_s > 60 )
            timers->CounterDWN2_s -= 61;
        else
            timers->CounterDWN2_s = 0;

        if( timers->CounterDWN3_s > 60 )
            timers->CounterDWN3_s -= 61;
        else
            timers->CounterDWN3_s = 0;
    }
    else
    {
        /////////////////////////////Wrong!!!!!!!!!!!!!!!TBD
        /* Update Increasing Counters */
        if(DIVE_TIMER_State == TIMER_RUN)
            timers->CounterUP1_s++;

        timers->CounterUP2_s++;
        timers->CounterUP3_s++;

        /* Update Decreasing Counters */
        if(CDT_TIMER_Run == CDT_RUN)
        {
            if(timers->CounterDWN1_s > 0)
                timers->CounterDWN1_s--;
            else
                timers->CounterDWN1_s = 0;
        }

        if( timers->CounterDWN2_s > 0 )
            timers->CounterDWN2_s--;
        if( timers->CounterDWN3_s > 0 )
            timers->CounterDWN3_s--;
    }
}

/*******************************************************************************
 * @brief   Convert Integer to Char.
 *
 *
 * @note
 *
 ******************************************************************************/
char ConvertInt2Char (uint8_t data)
{
    char result;
    switch(data)
    {
    case 0:
        result = 0x30;
        break;

    case 1:
        result = 0x31;
        break;

    case 2:
        result = 0x32;
        break;

    case 3:
        result = 0x33;
        break;

    case 4:
        result = 0x34;
        break;

    case 5:
        result = 0x35;
        break;

    case 6:
        result = 0x36;
        break;

    case 7:
        result = 0x37;
        break;

    case 8:
        result = 0x38;
        break;

    case 9:
        result = 0x39;
        break;
    }

    return result;
}



/*******************************************************************************
 * @brief   Execute system Diagnostics
 *
 *
 * @note
 *
 ******************************************************************************/
void SystemDiagnostics (void)
{
    static int32_t DiagStartTimeStamp;

    static bool FatalError = false;
    static bool MaintainanceError = false;
    static bool MinorError = false;

    // Redundancy Check
    if(DEV_Rec.SystemErrorWarningBits.AllBits == 0xFFFFFFFF)
        DEV_Rec.SystemErrorWarningBits.AllBits = 0;

    if(!SystemStatus.DiagnosticRun)
    {
        SystemStatus.DiagnosticRun = true;
        DiagStartTimeStamp = MonotonicClock_s;

        FatalError = false;
        MaintainanceError = false;
        MinorError = false;

        //------------------------------------------------------------------------------
        // System Error 1: Depth/Temperature Sensor
        uint8_t Retry = 0;
        while ( !MS5837_Init(MS5837_I2C_ADDR, &MS5837_Sensor) && Retry++ < 3) {};
        if((Retry >= 3)&&(SystemStatus.Demo_On == false))
        {
            DEV_Rec.SystemErrorWarningBits.SensorPress = 1;
            DEV_Rec.SystemErrorWarningBits.SensorTemp = 1;

            FatalError = true;
        }
        else
        {
            DEV_Rec.SystemErrorWarningBits.SensorPress = 0;
            DEV_Rec.SystemErrorWarningBits.SensorTemp = 0;
        }

        //------------------------------------------------------------------------------
        // System Error 2: EEPROM
        if((Dive_Info.Status!=AMB_DIVEINFO_DIVE)&&(Dive_Info.Status!=AMB_DIVEINFO_AFTERDIVE)) // Do NOT handle Memory Error during dive, Added from R1006 ----------
        {            
            Retry = 0;
            while ( !EE24CWxxX_Test( 0x3F00, 256 ) && Retry++ < 3) {};
            if((Retry >= 3)&&(SystemStatus.Demo_On == false)||(DEV_Rec.SystemErrorWarningBits.Eeprom == true))
            {
                DEV_Rec.SystemErrorWarningBits.Eeprom = 1;

                MinorError = true;
            }
            else
                DEV_Rec.SystemErrorWarningBits.Eeprom = 0;
        }
        //------------------------------------------------------------------------------
        // System Error 3: ExFlash
        if((Dive_Info.Status!=AMB_DIVEINFO_DIVE)&&(Dive_Info.Status!=AMB_DIVEINFO_AFTERDIVE)) // Do NOT handle Memory Error during dive, Added from R1006 ----------
        {
            uint8_t id = 0;
            uint8_t type = 0;
            uint8_t density = 0;
            
            // PowerOn SPI and ExFLash
            L4X9_QSPI_Init();
            MT25QL512ABB_PowerDownRelease();
            Retry = 0;            
            while ( !MT25QL512ABB_ReadID( &id, &type, &density ) && Retry++ < 3) {};
            // PowerOff SPI and ExFLash
            MT25QL512ABB_PowerDownEnter();
            L4X9_QSPI_DeInit();

            /*********** The Below is for both ISSI and Micron FLASH chips ****************/  

            if( (DEV_Rec.SystemErrorWarningBits.Flash == 0) && ( Retry < 3 )            // added time out for error check
             && (  ( (id == MT25QL512ABB_MAN_ID)&&(type == MT25QL512ABB_MEM_TYPE)&&(density == MT25QL512ABB_MEM_DENSITY))
                 ||( (id == IS25LP512M_MAN_ID)&&(type == IS25LP512M_MEM_TYPE)&&(density == IS25LP512M_MEM_DENSITY) ) ) )           
            {
                DEV_Rec.SystemErrorWarningBits.Flash = 0;
            }
            else
            {
                DEV_Rec.SystemErrorWarningBits.Flash = 1;

                MinorError = true;
            }
            /********** The Above is for both ISSI and Micron FLASH chips *****************/          
        }
        
        //------------------------------------------------------------------------------
        // System Error 4: Calibration Data Lost
        if( (MFG_Calib.Date.Year==0xFF) ||(MFG_Calib.Date.Year==0x0)
          ||(MFG_Calib.Date.Month==0xFF)||(MFG_Calib.Date.Month==0x0)
          ||(MFG_Calib.Date.Day==0xFF)  ||(MFG_Calib.Date.Day==0x0) )
          DEV_Rec.SystemErrorWarningBits.NotYetCali = 1;
        else
          DEV_Rec.SystemErrorWarningBits.NotYetCali = 0;

        //------------------------------------------------------------------------------
        // System Error 5: Calibration CheckSum
        if((Eval_CRC16(&MFG_Calib, sizeof(MFG_Calib)) != 0)&&(SystemStatus.Demo_On == false))
        {
            DEV_Rec.SystemErrorWarningBits.Calibration = 1;

            FatalError = true;
        }
        else
            DEV_Rec.SystemErrorWarningBits.Calibration = 0;

        //------------------------------------------------------------------------------
        // System Error 6: System Need to review or maintian
        if( ( Dive_Info.Dive10hDetected || (DEV_Rec.SystemErrorWarningBits.Dive10h == 1))
           &&(SystemStatus.Demo_On == false) )
        {
            DEV_Rec.SystemErrorWarningBits.Dive10h = 1;

            MaintainanceError = true;
        }

        if((DEV_Rec.SystemErrorWarningBits.LastDive == 1)&&(SystemStatus.Demo_On == false))
            MaintainanceError = true;

        /* ------------------------------------------------------------------------------------------------------------------------------------
        
        Batt Pct        > BAT_NO_DIVE_PERCENTAGE                >  BAT_NO_OPERATE_PERCENTAGE                    ==  BAT_NO_OPERATE_PERCENTAGE

        Surf Mode       Yellow Warning, OK to Dive              Red Alarm, CANNOT Dive                          No Op Shutdown

        Dive Mode       Yellow Warning, OK Keep Diving          Red Alarm, OK Keep Diving                       No Op Shutdown
        
        -------------------------------------------------------------------------------------------------------------------------------------- */
        // System Error 7: Battery Monitor
        //===> place BREAKPOINT here to debugging Low Battery Warnings
        Update_SystemSupplyMonitor ( &SystemSupplyMonitor );
        if( ( (SystemSupplyMonitor.Battery_Percentage <= BAT_NO_OPERATE_PERCENTAGE)             // During Dive Mode, shutdown when BattPct <= 0%
            || ( (Dive_Info.Status!=AMB_DIVEINFO_DIVE)&&(Dive_Info.WaterEntranceDetected==true)&&(SystemSupplyMonitor.Battery_Percentage <= BAT_NO_DIVE_PERCENTAGE)) )  // When NOT in Dive Mode, shutdown when BattPct <= 0%
            && (!BatteryCharging()) && (SystemStatus.Demo_On == false) )
        {
            DEV_Rec.SystemErrorWarningBits.LowBattery = 1;
            MaintainanceError = true;
        }
        else
        {
            DEV_Rec.SystemErrorWarningBits.LowBattery = 0;
        }

        //------------------------------------------------------------------------------
        // System Error 8: Bluetooth
        if (SystemStatus.BLE_status == BLE_HDL_ERROR)
        {
            DEV_Rec.SystemErrorWarningBits.Bluetooth = 1;
            MinorError = true;
        }
        else
            DEV_Rec.SystemErrorWarningBits.Bluetooth = 0;

        //------------------------------------------------------------------------------
        // System Error 16: Altitude Limit 
        if (Dive_Info.AltitudeLevel >= ALT_OVER_LIMIT)
        {
            DEV_Rec.SystemErrorWarningBits.Altitude = 1;
            MinorError = true;
        }
        else
            DEV_Rec.SystemErrorWarningBits.Altitude = 0;

        //------------------------------------------------------------------------------
        // System Error 17: ECompass
        uint8_t AccId, MagId;
        LSM303AGR_WhoAmI_A(&AccId);
        LSM303AGR_WhoAmI_M(&MagId);
        if((AccId != LSM303AGR_ID_A) || (MagId != LSM303AGR_ID_M))
        {
          DEV_Rec.SystemErrorWarningBits.Compass = 1;
          MinorError = true;
        }
        else
          DEV_Rec.SystemErrorWarningBits.Compass = 0;
        
#if USE_REAL_BATTERY        
        //------------------------------------------------------------------------------
        // System Error 18: FuelGauge
        uint16_t stat;
        int16_t retry = NVD_EEPROM_WRITE_TIMEOUT;
        while((MAX17262_ReadRegister (MAX17262_STATUS, &stat) == false) && (retry-- > 0))
        {
        }
        
        if((retry <= 0)&&(SystemStatus.Demo_On == false))
        {
          DEV_Rec.SystemErrorWarningBits.FuelGauge = 1;
          MaintainanceError = true;
        }
        else
          DEV_Rec.SystemErrorWarningBits.FuelGauge = 0;
#endif        
        // Save Warning Flags in DeviceRecords
        EE_SaveReq(EE_DEVREC);   // NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC);
    }


    
    if(FatalError || MaintainanceError)
    {
        SystemStatus.ShowDiag = true;

        if(MonotonicClock_s - DiagStartTimeStamp > 30)
        {
            if( (Dive_Info.Status==AMB_DIVEINFO_DIVE) || (Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE) )
            {
                if(MaintainanceError == true)   // R1006 Shutdown during Diving only when (MaintainanceError == true), NOT for FatalError
                {  
                    /* For dive data backup prior to emergency Automatic Shutdown */
                    EmergencyEndOfDiveBackupAndShutdown();
                }
            }
            else
            {
                // R1006 when back to Surface, shutdown system for (FatalError || MaintainanceError) 
                /* For Surface mode emergency Automatic Shutdown */
                EmergencySurfaceShutdown();
            }
            
            // Close Diagnostics
            SystemStatus.DiagnosticReq = false;
            SystemStatus.DiagnosticRun = false;
            SystemStatus.ShowDiag = false;
        }
    }
    else if(MinorError)
    {
        //((DEV_Rec.SystemErrorWarningBits.LowBattery) || DEV_Rec.SystemErrorWarningBits.Altitude) )
      
        SystemStatus.ShowDiag = true;
        
        if(MonotonicClock_s - DiagStartTimeStamp > 10)
        {
            if( (Dive_Info.Status==AMB_DIVEINFO_DIVE) || (Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE) )
            {
                /* For dive data backup prior to emergency Automatic Shutdown */
                // EmergencyEndOfDiveBackupAndShutdown();
            }
            else
            {
                /* For Surface mode emergency Automatic Shutdown */
                // EmergencySurfaceShutdown();
            }

            // Close Diagnostics
            SystemStatus.DiagnosticReq = false;
            SystemStatus.DiagnosticRun = false;
            SystemStatus.ShowDiag = false;
        }
    }
    else
    {
        // Close Diagnostics
        SystemStatus.DiagnosticReq = false;
        SystemStatus.DiagnosticRun = false;
        SystemStatus.ShowDiag = false;
    }
}

#endif //_L4X9_UTILS_H_