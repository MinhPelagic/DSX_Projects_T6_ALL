#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
void ALARM_ConditionalViolation_Context(char* pStrRet)        // added by YS 2021/12/15
{
    strcpy(pStrRet, "  GF > 90 ˇ");
}
const contentDispContext_st ALARM_ConditionalViolation =
{
    &ALARM_ConditionalViolation_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of Conditional Violation in both Dive/Surface*/
unsigned char AlarmStatusCheck_ConditionalViolation(void)
{
    return (unsigned char)Alarming.Bit.CondiVio;
}
/*Return the status of Conditional Violation in both Dive/Surface*/
unsigned char AlarmStatusCheck_DelayedViolation1(void)
{
    return (unsigned char)Alarming.Bit.DelayedVio1; // not recoverable change
}
/*if current depth > deco stop depth -> change the color to yellow*/
unsigned char ColorCheck_DecoStop(void)
{
    unsigned char retStat = FALSE;
    if(fDepthFt > DECOSTOP_Depth + 10) //Current depth larger than deco depth
    {
        retStat = TRUE;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
}
/*Status when alarms*/
ItemStatus_te AlarmStatusHandle_DecoStop(void)
{
    ItemStatus_te retStat = IteStat_ClearThenSelect;
    if(AlarmStatusCheck_DelayedViolation1()
            || AlarmStatusCheck_DecoEntry()
            || AlarmStatusCheck_DecoWarning()
            || AlarmStatusCheck_DecoAlarm())
    {
        retStat = IteStat_ClearThenFlashing;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
}
GUI_COLOR AlarmColorHandle_DecoStop(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DecoWarning()||AlarmStatusCheck_DecoAlarm())
    {
        colorRet = GUI_RED;
    }
    else if(ColorCheck_DecoStop())
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}

