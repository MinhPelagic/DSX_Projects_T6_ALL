#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at middle*/
void ALARM_LowBattLine0_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_BATTERY));
}
const contentDispContext_st ALARM_LowBattShutDownLine0 =
{
    &ALARM_LowBattLine0_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BatteryLine0,
};
void ALARM_LowBattLine1_Context(char* pStrRet)
{
    strcpy(pStrRet, "COMPUTER WILL SHUTDOWN");
}
const contentDispContext_st ALARM_LowBattShutDownLine1 =
{
    &ALARM_LowBattLine1_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BatteryLine1,
};
/*Return the status of Conditional Warning Low battery to shut down device*/
bool AlarmStatusCheck_AlarmWarningLowBattShutDown(void)
{
    /*Get the status from application*/
    return DEV_Rec.SystemErrorWarningBits.LowBattery;
};
