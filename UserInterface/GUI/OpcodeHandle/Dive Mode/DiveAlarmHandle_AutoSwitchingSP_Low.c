#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_SP_AutoLo01_Context(char* pStrRet)
{
    strcpy(pStrRet, "AUTO SWITCHING SP");
}
static void ALARM_SP_AutoLo02_Context(char* pStrRet)
{
    sprintf(pStrRet, "%1.2f ˃ %1.2f", ccSPhigh, ccSPlow);
}
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_SP_AutoLo(void)
{
    return (unsigned char)Alarming2.Bit.SP_AutoLo;
};
GUI_COLOR AlarmColorHandle_SP_AutoLo(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_SP_AutoLo())
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
const contentDispContext_st ALARM_SP_AutoLoAlarm_Line01 =
{
    &ALARM_SP_AutoLo01_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInTwoLines_01,
};
const contentDispContext_st ALARM_SP_AutoLoAlarm_Line02 =
{
    &ALARM_SP_AutoLo02_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInTwoLines_02,
};
/*item status*/
ItemStatus_te DiveMode_DispStat_SP_AutoLo(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if( AlarmOn2.Bit.SP_AutoLo )
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
