#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DepthAlarm_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEPTH_ALARM));
}
const contentDispContext_st ALARM_DepthAlarm =
{
    &ALARM_DepthAlarm_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DepthAlarm(void)
{
    return (unsigned char)(AlarmOn.Bit.DepthSet||Alarming.Bit.DepthMax);
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DepthMaxAlarm(void)                              // added by YeuShyr 2022 02 27
{
    return (unsigned char)Alarming.Bit.DepthMax;
};
GUI_COLOR AlarmColorHandle_DepthAlarm(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DepthAlarm())
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
GUI_COLOR AlarmColorHandle_DepthMaxAlarm(void)                                  // added by YeuShyr 2022 02 27
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DepthMaxAlarm())
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
ItemStatus_te DiveMode_DispStat_DepthValue(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DepthSet)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
