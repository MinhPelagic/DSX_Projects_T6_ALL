#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "..\Dive Mode\DiveMode.h"
/*
It will handle all the alarm in the bottom
-> Checking and display alarms base on piority
-> Return the status of display
*/

unsigned char SurfaceModeAlarm_BottomAlarms(void)
{
    unsigned char retStatus = TRUE;
    /*Check Battery Low*/
    switch(AlarmID)
    {
    /*
        case ALARM_CondiVio:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_ConditionalViolation);
            AlarmDueAck.Bit.CondiVio = 1;
            break;
        case ALARM_DelayedVio1:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_CV_GF_90);
            AlarmDueAck.Bit.DelayedVio1 = 1;
            break;
        case ALARM_AscRate5:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_AscentTooFast);
            AlarmDueAck.Bit.AscRate5 = 1;
            break;
        case ALARM_PO2_Hi:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_HighPO2);
            AlarmDueAck.Bit.PO2_Hi = 1;
            break;
        case ALARM_PO2_Lo:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_LowPO2);
            AlarmDueAck.Bit.PO2_Lo = 1;
            break;
        case ALARM_OCSM_MaxPO2:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_OCSM_MaxPO2Alarm);
            AlarmDueAck2.Bit.OCSM_MaxPO2 = 1;
            break;
        case ALARM_OCSM_MinPO2:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_OCSM_MinPO2Alarm);
            AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
            break;
        case ALARM_OCSM_DecoPO2:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_DecoPO2);
            AlarmDueAck2.Bit.OCSM_DecoPO2 = 1;
            break;
        case ALARM_DECO_Entry:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_DecoEntryAlarm);
            AlarmDueAck.Bit.O2_100Pct = 1;
            break;
        case ALARM_DECO_Warning:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_DecoWarning);
            AlarmDueAck.Bit.DECO_Warning = 1;
            break;
        case ALARM_O2_100Pct:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_O2Sat);
            AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
            break;
        case ALARM_O2_80Pct:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_O2SatWarning);
            AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
            break;
        case ALARM_DiveN2Bar:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_N2Bar);
            AlarmDueAck2.Bit.N2 = 1;
            break;
        case ALARM_DepthSet:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_DepthAlarm);
            AlarmDueAck.Bit.DepthSet = 1;
            break;
        case ALARM_DiveTime:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_DiveTimeAlarm);
            AlarmDueAck.Bit.DiveTime = 1;
            break;
        case ALARM_TTS_T:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_TimeToSurface);
            AlarmDueAck2.Bit.TTS_T = 1;
            break;
        case ALARM_GF:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_GradientFactor);
            AlarmDueAck2.Bit.GF = 1;
            break;
        case ALARM_End:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_EquivalentNarcoticDepth);
            AlarmDueAck2.Bit.End = 1;
            break;
        case ALARM_WOB:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_WorkOfBreathing);
            AlarmDueAck2.Bit.WOB = 1;
            break;
        case ALARM_LostLink:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_LostTMT);
            AlarmDueAck2.Bit.LostLink = 1;
            break;
        case ALARM_GTR0:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_GasTimeRemaining);
            AlarmDueAck2.Bit.GTR0 = 1;
            break;
        case ALARM_GTR5:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_GasTimeRemaining);
            AlarmDueAck2.Bit.GTR5 = 1;
            break;
        case ALARM_TMT_LowBattWarning:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, WARNING_TMTLowBattery);
            AlarmDueAck2.Bit.TMT_LowBattWarning = 1;
            break;
        case ALARM_TMT_LowBattAlarm:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_TMTLowBattery);
            AlarmDueAck2.Bit.TMT_LowBattAlarm = 1;
            break;
    */
    case ALARM_LowBatteryWarning:
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_LowBattWarning);
        AlarmDueAck.Bit.LowBattWarning  = 1;
        break;
    case ALARM_LowBatteryAlarm:
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_LowBattAlarm);
        AlarmDueAck.Bit.LowBattAlarm  = 1;
        break;
    //case ALARM_NoOpShutdown:
    //    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_LowBattNoOp);
    //    AlarmDueAck.Bit.NoOpShutdown  = 1;
    //    break;
    default:    /*No AlarmON.xxxx in progress, BUT need to take care of Alarming.xxxx */
        if(AlarmStatusCheck_O2Sat())
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_O2Sat);
        }
        else
        {
            /*No alarms need to progress*/
            retStatus = FALSE;
        }
        break;
    }
    return retStatus;
}
