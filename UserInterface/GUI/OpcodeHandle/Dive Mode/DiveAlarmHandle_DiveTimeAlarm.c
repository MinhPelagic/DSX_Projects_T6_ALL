#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DiveTimeAlarm_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME_ALARM));
}
const contentDispContext_st ALARM_DiveTimeAlarm =
{
    &ALARM_DiveTimeAlarm_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DiveTimeAlarm(void)
{
    return (unsigned char)Alarming.Bit.DiveTime;
};
unsigned char AlarmColorCheck_DiveTimeAlarm(void)
{
    return (unsigned char)AlarmOn.Bit.DiveTime;
};
GUI_COLOR AlarmColorHandle_DiveTimeAlarm(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmColorCheck_DiveTimeAlarm())
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
/*item status*/
ItemStatus_te DiveMode_DispStat_DiveTimeValue(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DiveTime)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}