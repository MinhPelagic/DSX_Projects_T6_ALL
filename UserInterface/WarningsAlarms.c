/*******************************************************************************
 * @file        : I780R_WarningsAlarms.c
 * @brief       : MCU Dive Computer processing Warnings and Alarms.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: YeuShyr Wu - Pelagic Pressure Systems, Aqua Lung
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_WARNINGSALARMS_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
/* Global variable used in all PRTOS delay functions */
union AlarmUNION  AlarmOn;   // 4-Byte of 32 Alarms and Warnings 1-bit flags

/******************************************************************************
 * @brief   WarningsAlarmsTurnOn
 *
 * @note
 ******************************************************************************/
void WarningsAlarmsTurnON(void)
{
    if(AlarmOn.CondiVio)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.DelayedVio1)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.DelayedVio2)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.DelayedVio3)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.AscRate5)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.AscRate4)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.AscRate3)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.N2Bar5)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.N2Bar4)
    {
        SystemStatus.buzzer_on_req =true;
    }

    if(AlarmOn.N2Bar3)
    {
        SystemStatus.buzzer_on_req =true;
    }

    /*
        AlarmOn.CondiVio        :1;     // 1-bit
        AlarmOn.DelayedVio1     :1;     // 1-bit                // must be Saved to EEPROM
        AlarmOn.DelayedVio2     :1;     // 1-bit
        AlarmOn.DelayedVio3     :1;     // 1-bit
        AlarmOn.AscRate5        :1;     // 1-bit
        AlarmOn.AscRate4        :1;     // 1-bit
        AlarmOn.AscRate3        :1;     // 1-bit
        AlarmOn.N2Bar5          :1;     // 1-bit
        AlarmOn.N2Bar4          :1;     // 1-bit
        AlarmOn.N2Bar3          :1;     // 1-bit
        AlarmOn.O2_80Pct        :1;     // 1-bit
        AlarmOn.O2_100Pct       :1;     // 1-bit                // must be Saved to EEPROM
        AlarmOn.DECO_Entry      :1;     // 1-bit
        AlarmOn.DiveTime        :1;     // 1-bit
        AlarmOn.DiveDTR         :1;     // 1-bit                // works with SCUBA_Set.DTR_Alarm
        AlarmOn.Depth           :1;     // 1-bit                // works with SCUBA_Set.DepthAlarmFT and SCUBA_Set.DepthAlarmM

        AlarmOn.PO2NearSetPoint :1;     // 1-bit
        AlarmOn.PO2AtSetPoint   :1;     // 1-bit
        AlarmOn.FreeDiveT       :1;     // 1-bit
        AlarmOn.FreeDepth1      :1;     // 1-bit
        AlarmOn.FreeDepth2      :1;     // 1-bit
        AlarmOn.FreeDepth3      :1;     // 1-bit
        AlarmOn.FreeDiveTime    :1;     // 1-bit
        AlarmOn.FreeVio         :1;     // 1-bit
        AlarmOn.FreeDECO        :1;     // 1-bit
        AlarmOn.DECO_Depth70    :1;     // 1-bit

        AlarmOn.Reserved26      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved27      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved28      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved29      :1;     // 1-bit reserved 0: 1:
        AlarmOn.SetupVio        :1;     // 1-bit reserved 0: 1:
        AlarmOn.LowBattery      :1;     // 1-bit                // must work with BatteryStatus and BattWarning_mV   BattCutoff_mV
    */

}

/******************************************************************************
 * @brief   WarningsAlarmsTurnOFF
 *
 * @note
 ******************************************************************************/
void WarningsAlarmsTurnOFF(void)
{
    if(AlarmOn.CondiVio)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.DelayedVio1)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.DelayedVio2)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.DelayedVio3)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.AscRate5)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.AscRate4)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.AscRate3)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.N2Bar5)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.N2Bar4)
    {
        SystemStatus.buzzer_on_req =false;
    }

    if(AlarmOn.N2Bar3)
    {
        SystemStatus.buzzer_on_req =false;
    }

    /*
        AlarmOn.CondiVio        :1;     // 1-bit
        AlarmOn.DelayedVio1     :1;     // 1-bit                // must be Saved to EEPROM
        AlarmOn.DelayedVio2     :1;     // 1-bit
        AlarmOn.DelayedVio3     :1;     // 1-bit
        AlarmOn.AscRate5        :1;     // 1-bit
        AlarmOn.AscRate4        :1;     // 1-bit
        AlarmOn.AscRate3        :1;     // 1-bit
        AlarmOn.N2Bar5          :1;     // 1-bit
        AlarmOn.N2Bar4          :1;     // 1-bit
        AlarmOn.N2Bar3          :1;     // 1-bit
        AlarmOn.O2_80Pct        :1;     // 1-bit
        AlarmOn.O2_100Pct       :1;     // 1-bit                // must be Saved to EEPROM
        AlarmOn.DECO_Entry      :1;     // 1-bit
        AlarmOn.DiveTime        :1;     // 1-bit
        AlarmOn.DiveDTR         :1;     // 1-bit                // works with SCUBA_Set.DTR_Alarm
        AlarmOn.Depth           :1;     // 1-bit                // works with SCUBA_Set.DepthAlarmFT and SCUBA_Set.DepthAlarmM

        AlarmOn.PO2NearSetPoint :1;     // 1-bit
        AlarmOn.PO2AtSetPoint   :1;     // 1-bit
        AlarmOn.FreeDiveT       :1;     // 1-bit
        AlarmOn.FreeDepth1      :1;     // 1-bit
        AlarmOn.FreeDepth2      :1;     // 1-bit
        AlarmOn.FreeDepth3      :1;     // 1-bit
        AlarmOn.FreeDiveTime    :1;     // 1-bit
        AlarmOn.FreeVio         :1;     // 1-bit
        AlarmOn.FreeDECO        :1;     // 1-bit
        AlarmOn.DECO_Depth70    :1;     // 1-bit

        AlarmOn.Reserved26      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved27      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved28      :1;     // 1-bit reserved 0: 1:
        AlarmOn.Reserved29      :1;     // 1-bit reserved 0: 1:
        AlarmOn.SetupVio        :1;     // 1-bit reserved 0: 1:
        AlarmOn.LowBattery      :1;     // 1-bit                // must work with BatteryStatus and BattWarning_mV   BattCutoff_mV
    */

}


/******************************************************************************
 * @brief
 *
 * @note
 ******************************************************************************/


#endif //_L4X9_WARNINGSALARMS_H_