/******************************************************************************/
//File: Alarms Tank press
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
/*Input data*/
#define ALARM_CC6_PRSESS_OOS                      GUI_CC6P_AL_STAT //ON/OFF/SET flag
#define ALARM_CC6_PRESS_PSI                       GUI_CC6P_AL_PSI //
#define ALARM_CC6_PRESS_BAR                       GUI_CC6P_AL_BAR //

/*Re use the function handle and position define*/
/*Config context*/
static void SETALARMS_CC6PRESS_Value_Context(char* pStrRet)
{
    /*CC6 PRESS VALUE*/
    if(Imperial)
        sprintf(pStrRet, "  %d", ALARM_CC6_PRESS_PSI);
    else
        sprintf(pStrRet, "  %d", ALARM_CC6_PRESS_BAR);

}
/*Set CC6 PRESS Depth value*/
const contentDispContext_st SetAlarm_CC6PRESS_STAT_Ctx =
{
    &SETALARMS_CC6PRESS_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Context memdev config to SetAlarm_CC6Press_SET*/
const contentDispContext_st SetAlarm_CC6PRESS_SET_Ctx =
{
    &SetAlarms_CCPRESS_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};