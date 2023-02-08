#include "L4X9_includes.h"
#include "DiveMode.h"

void DiveMode_AlarmHandleDisplay2ArrowsUpDown(void)
{
    const AlarmArrowHandle_st dispAlarmStatus = DiveMode_AlarmArrowHandleStatus();
    /*Create memory device space*/
    GUI_MEMDEV_Handle hMemDevLocal;
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_ALARM_DoubleArrowUp->X0, Pos_ALARM_DoubleArrowUp->Y0, Pos_ALARM_DoubleArrowUp->Width, Pos_ALARM_DoubleArrowUp->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    /*always clear before display*/
    GUI_ClearRect(Pos_ALARM_DoubleArrowUp->X0, Pos_ALARM_DoubleArrowUp->Y0, Pos_ALARM_DoubleArrowUp->X1, Pos_ALARM_DoubleArrowUp->Y1);
    GUI_SetFont(&FontAaux_3);
    if((IteStat_Flashing == dispAlarmStatus.dispStatus)&&(FLASHING_STATE_OFF == FlashingState_u8))
    {
        /*Set color*/
        GUI_SetColor(dispAlarmStatus.arrColor);
        /*Display arrow*/
        if(Alarm_2ArrowUp == dispAlarmStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˆ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y0);
            GUI_DispStringHCenterAt("ˆ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y + 20);
        }
        else if(Alarm_2ArrowDown == dispAlarmStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˇ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y);
            GUI_DispStringHCenterAt("ˇ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y + 20u);
        }
        else if(Alarm_1ArrowDown == dispAlarmStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˇ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y);
        }
        else
        {
            GUI_DispStringHCenterAt("ˆ", Pos_ALARM_DoubleArrowUp->X, Pos_ALARM_DoubleArrowUp->Y + 10u);
        }
    }
    else
    {
        /*Clear the portion already*/
    }
    /*send to lcd display*/
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
/*
Flashing the 2 arrows up in the top
*/
AlarmArrowHandle_st DiveMode_AlarmArrowHandleStatus(void)
{
    AlarmArrowHandle_st returnStat = {IteStat_Flashing, GUI_RED, Alarm_2ArrowDown};
    /*Handle flashing*/
    if(AlarmStatusCheck_FullViolation()) //Highest piority!!!
    {
        if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
        {
            /*No alarms need to progress*/
            returnStat.arrUpDown = Alarm_2ArrowUp;
        }
        else
        {
            /*No alarms need to progress*/
            returnStat.dispStatus  = IteStat_Clear;
        }
    }
    else if(AlarmStatusCheck_DecoAlarm() && ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)) )
    {
        returnStat.arrUpDown = Alarm_2ArrowDown;
    }
    else if( AlarmStatusCheck_O2SatWarning_FlashingArrow() && (Dive_Info.Status == AMB_DIVEINFO_DIVE) )
    {
        returnStat.arrUpDown = Alarm_1ArrowUp;
        returnStat.arrColor = GUI_YELLOW;
    }
    else if((AlarmStatusCheck_HighPO2()
             ||AlarmStatusCheck_O2Sat()
             ||AlarmStatusCheck_DepthMaxAlarm()
             ||AlarmStatusCheck_OCmaxPO2())&& Dive_Info.Status == AMB_DIVEINFO_DIVE )
    {
        returnStat.arrUpDown = Alarm_2ArrowUp;
    }
    else if( AlarmStatusCheck_DecoWarning() && ((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)) )
    {
        returnStat.arrUpDown = Alarm_1ArrowDown;
    }
    else
    {
        /*No alarms need to progress*/
        returnStat.dispStatus = IteStat_Clear;
    }
    return returnStat;
}
