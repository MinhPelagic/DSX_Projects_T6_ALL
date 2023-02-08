#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_SP_AutoHi_Context_Line01(char* pStrRet)
{
    strcpy(pStrRet, "AUTO SWITCHING SP");
}
static void ALARM_SP_AutoHi_Context_Line02(char* pStrRet)
{
    sprintf(pStrRet, "%1.2f ˃ %1.2f", ccSPlow, ccSPhigh);
}
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_SP_AutoHi(void)
{
    return (unsigned char)Alarming2.Bit.SP_AutoHi;
};
GUI_COLOR AlarmColorHandle_SP_AutoHi(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_SP_AutoHi())
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
const contentDispContext_st ALARM_SP_AutoHiAlarm_Line01 =
{
    &ALARM_SP_AutoHi_Context_Line01,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInTwoLines_01,
};
const contentDispContext_st ALARM_SP_AutoHiAlarm_Line02 =
{
    &ALARM_SP_AutoHi_Context_Line02,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInTwoLines_02,
};
/*item status*/
ItemStatus_te DiveMode_DispStat_SP_AutoHi(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if( AlarmOn2.Bit.SP_AutoHi )
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
