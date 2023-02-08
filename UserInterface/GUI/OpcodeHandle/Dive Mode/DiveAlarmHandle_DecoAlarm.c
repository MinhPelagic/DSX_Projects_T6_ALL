#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DecoAlarm_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MISSED_DECO));
}
const contentDispContext_st ALARM_DecoAlarm =
{
    &ALARM_DecoAlarm_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DecoAlarm(void)
{
    return (unsigned char)Alarming.Bit.DECO_Alarm;  // not recoverable change
};
GUI_COLOR AlarmColorHandle_DecoAlarm(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DecoAlarm())
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
ItemStatus_te DiveMode_DispStat_DecoAlarm(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DECO_Alarm)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}