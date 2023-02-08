#include "L4X9_includes.h"
#include "DiveMode.h"
/*item status*/
static ItemStatus_te DepthAndDiveTimeAlarm_DispStat(void)
{
    ItemStatus_te statRet = IteStat_Clear;
    /*When alarm occured -> stop update/display*/
    switch(AlarmID)
    {
    case ALARM_AscRate5:
    case ALARM_DECO_Entry:
    case ALARM_CondiVio:
    case ALARM_DelayedVio1:
    case ALARM_SwitchFO2:
    case ALARM_PO2_Hi:
    case ALARM_PO2_Lo:
    case ALARM_OCSM_MaxPO2:
    case ALARM_OCSM_MinPO2:
    case ALARM_OCSM_DecoPO2:
    case ALARM_DECO_Warning:
    case ALARM_O2_100Pct:
    case ALARM_O2_80Pct:
    case ALARM_DiveN2Bar:
    case ALARM_DepthSet:
    case ALARM_DiveTime:
    case ALARM_TTS_T:
    case ALARM_GF:
    case ALARM_End:
    case ALARM_WOB:
    case ALARM_LostLink:
    case ALARM_GTR0:
    case ALARM_GTR5:
    case ALARM_TMT_LowBattWarning:
    case ALARM_TMT_LowBattAlarm:
    case ALARM_DiveDTR:
        statRet = IteStat_Flashing;
        break;
    default:
        /*Special cases*/
        if(AlarmStatusCheck_EndP()||AlarmStatusCheck_TurnP())
        {
            statRet = IteStat_Flashing;
        }
        else
        {
            /*Do nothing*/
        }
        break;
    }
    return statRet;
}
static GUI_COLOR AlarmColorHandle_DepthAndDiveTimeAlarmInBottom(void)
{
    GUI_COLOR colorRet = GUI_RED;
    switch(AlarmID)
    {
    case ALARM_SwitchFO2:
    case ALARM_O2_80Pct:
    case ALARM_LowBatteryWarning:
        colorRet = GUI_YELLOW;
        break;
    default:
        /*Special cases*/
        if(AlarmStatusCheck_TurnP())
        {
            colorRet = GUI_YELLOW;
        }
        else
        {
            /*Do nothing*/
        }
        break;
    }
    return colorRet;
}
/*ALARM displayed at bottom*/
static void DepthAndDiveTimeAlarm_Context(char* pStrRet)
{
    switch(AlarmID)
    {
    case ALARM_CondiVio:
        strcpy(pStrRet, "  GF > 90 ˇ");
        AlarmDueAck.Bit.CondiVio = 1;
        break;
    case ALARM_DelayedVio1:
        strcpy(pStrRet, "ˇ GF > 90 ˇ");
        AlarmDueAck.Bit.DelayedVio1 = 1;
        break;
    case ALARM_AscRate5:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ASCENT_TOO_FAST));
        AlarmDueAck.Bit.AscRate5 = 1;
        break;
    case ALARM_PO2_Hi:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_HIGH_PO2));
        AlarmDueAck.Bit.PO2_Hi = 1;
        break;
    case ALARM_PO2_Lo:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_PO2));
        AlarmDueAck.Bit.PO2_Lo = 1;
        break;
    case ALARM_OCSM_MaxPO2:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_HIGH_PO2));
        AlarmDueAck2.Bit.OCSM_MaxPO2 = 1;
        break;
    case ALARM_OCSM_MinPO2:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_PO2));
        AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
        break;
    case ALARM_OCSM_DecoPO2:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DECO_PO2));
        AlarmDueAck2.Bit.OCSM_DecoPO2 = 1;
        break;
    case ALARM_DECO_Entry:
        strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_DECO_ENTRY));
        AlarmDueAck.Bit.O2_100Pct = 1;
        break;
    case ALARM_DECO_Warning:
        strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_MISSED_DECO));
        AlarmDueAck.Bit.DECO_Warning = 1;
        break;
    case ALARM_O2_100Pct:
        strcpy(pStrRet, "O2 SAT 100%");
        AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
        break;
    case ALARM_O2_80Pct:
        strcpy(pStrRet, "O2 SAT 80%");
        AlarmDueAck2.Bit.OCSM_MinPO2 = 1;
        break;
    case ALARM_DiveN2Bar:
        sprintf(pStrRet, "N2 BAR %d", N2_ALARM_DATA);
        AlarmDueAck2.Bit.N2 = 1;
        break;
    case ALARM_DepthSet:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEPTH_ALARM));
        AlarmDueAck.Bit.DepthSet = 1;
        break;
    case ALARM_DiveTime:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME_ALARM));
        AlarmDueAck.Bit.DiveTime = 1;
        break;
    case ALARM_SP_AutoHi:
        sprintf(pStrRet, "AUTO SWITCHING SP %f1.2 -> %f1.2", ccSPlow, ccSPhigh);
        AlarmDueAck2.Bit.SP_AutoHi = 1;
        break;
    case ALARM_SP_AutoLo:
        sprintf(pStrRet, "AUTO SWITCHING SP %f1.2 -> %f1.2", ccSPhigh, ccSPlow);
        AlarmDueAck2.Bit.SP_AutoLo = 1;
        break;
    case ALARM_TTS_T:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME_SURFACE_ALARM));
        AlarmDueAck2.Bit.TTS_T = 1;
        break;
    case ALARM_GF:
        sprintf(pStrRet, "GRADIENT FACTOR %d", SCUBA_Set.GF_Alarm);
        AlarmDueAck2.Bit.GF = 1;
        break;
    case ALARM_End:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_EQUI_NAR_DEPTH));
        AlarmDueAck2.Bit.End = 1;
        break;
    case ALARM_WOB:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WORK_OF_BREATHING));
        AlarmDueAck2.Bit.WOB = 1;
        break;
    case ALARM_LostLink:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOST_TMT));
        AlarmDueAck2.Bit.LostLink = 1;
        break;
    case ALARM_GTR0:
        strcpy(pStrRet,GUI_LANG_GetText(TxtStr_GAS_TIMEREMAINING));
        AlarmDueAck2.Bit.GTR0 = 1;
        break;
    case ALARM_GTR5:
        strcpy(pStrRet,GUI_LANG_GetText(TxtStr_GAS_TIMEREMAINING));
        AlarmDueAck2.Bit.GTR5 = 1;
        break;
    case ALARM_TMT_LowBattWarning:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_LOW_BATT));
        AlarmDueAck2.Bit.TMT_LowBattWarning = 1;
        break;
    case ALARM_TMT_LowBattAlarm:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_LOW_BATT));
        AlarmDueAck2.Bit.TMT_LowBattAlarm = 1;
        break;
    case ALARM_LowBatteryWarning:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_BATTERY));
        AlarmDueAck.Bit.LowBattWarning = 1;
        break;
    case ALARM_LowBatteryAlarm:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_BATTERY));
        AlarmDueAck.Bit.LowBattAlarm = 1;
        break;
    case ALARM_NoOpShutdown:
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_BATTERY));
        AlarmDueAck.Bit.NoOpShutdown = 1;
        break;
    case ALARM_DiveDTR:
        strcpy(pStrRet, "DIVE TIME REMAINING");
        AlarmDueAck.Bit.DiveDTR = true;
        break;
    default:
        if(AlarmStatusCheck_EndP())
        {
            strcpy(pStrRet, GUI_LANG_GetText(TxtStr_END_PRESS));
        }
        else if(AlarmStatusCheck_TurnP())
        {
            strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TURN_PRESS));
        }
        else
        {
            strcpy(pStrRet, " "); //Default is empty
        }
        break;
    }
}
/*Alarm in the bottom*/
const contentWithStateHandle_st DepthDiveTimeMode_AlarmInBottom =
{
    &DepthAndDiveTimeAlarm_DispStat,
    &DepthAndDiveTimeAlarm_Context,
    &AlarmColorHandle_DepthAndDiveTimeAlarmInBottom,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthDiveTime_AlarmInBottom,
};
