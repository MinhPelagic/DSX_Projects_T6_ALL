#include "L4X9_includes.h"
#include "DiveMode.h"
#include "../BatteryCharging/BatteryChargingCfg.h"

/*ALARM displayed at bottom*/
static void ALARM_LowBattery_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_BATTERY));
}
const contentDispContext_st ALARM_LowBattWarning =
{
    &ALARM_LowBattery_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
const contentDispContext_st ALARM_LowBattAlarm =
{
    &ALARM_LowBattery_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
const contentDispContext_st ALARM_LowBattNoOp =
{
    &ALARM_LowBattery_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_LowBatteryWarning(void)
{
    unsigned char retStat = 0u;
    /*When battery below batt level LOW */
    if(SystemSupplyMonitor.Battery_Percentage < BATT_LEVEL_WARNING)
    {
        retStat = 1u;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_LowBatteryAlarm(void)
{
    unsigned char retStat = 0u;
    /*When battery below batt level LOW */
    if(SystemSupplyMonitor.Battery_Percentage < BATT_LEVEL_ALARM)
    {
        retStat = 1u;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_LowBatteryShutdown(void)
{
    unsigned char retStat = 0u;
    /*When battery below batt level LOW */
    if(SystemSupplyMonitor.Battery_Percentage <= BATT_LEVEL_SHUTDOWN)
    {
        retStat = 1u;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
};
