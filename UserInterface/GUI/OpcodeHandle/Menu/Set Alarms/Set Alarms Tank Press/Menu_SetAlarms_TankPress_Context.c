/******************************************************************************/
//File: Alarms Tank press
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "../Menu_SetAlarms.h"
#include "Menu_SetAlarms_TankPress.h"
/*Input data*/
#define ALARM_TANKPRESS_PSI                      GUI_TankP_AL_PSI      // TankP in PSI
#define ALARM_TANKPRESS_BAR                      GUI_TankP_AL_BAR      // TankP in BAR

/**/
void SETALARMS_TankPress_Value_Context(char* pStrRet)
{
    /*Tank Press*/
    if(Imperial)
        sprintf(pStrRet, "  %d", ALARM_TANKPRESS_PSI);
    else
        sprintf(pStrRet, "  %d", ALARM_TANKPRESS_BAR);
}
/*Set Alarms Depth value*/
const contentDispContext_st SetAlarm_TankPress_Context =
{
    &SETALARMS_TankPress_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
void TankUnitSet_Context(char* pStrRet)
{
    strcpy(pStrRet, TxtDef_Set_PressUnit[UNITS]);
}
const contentDispContext_st SetAlarm_TankPressUnit_Context =
{
    &TankUnitSet_Context,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_UnitSign, //Unit sign M/FT
};
static void SetAlarms_TANKPRESS_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_TANKPRESS_OOS]));
}
/*Context memdev config to SetAlarm_TankPress_STAT*/
const contentDispContext_st Set_SetAlarm_TankPress_STAT_Ctx =
{
    &SetAlarms_TANKPRESS_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};