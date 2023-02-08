/******************************************************************************/
//File: Alarms DEPTH
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "../Menu_SetAlarms.h"

/*DEPTH ALARM*/
#define SETALARM_DEPTH_FT                       GUI_DepthAlarmFT
#define SETALARM_DEPTH_M                        GUI_DepthAlarmM
#define USR_UNIT_SET                            0 // User setting
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*OOS Flag : ON/OFF/SET flag*/
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this

/**/
static void SETALARMS_Depth_Value_Context(char* pStrRet)
{
    /*ALARM DEPTH VALUE*/
    if(Imperial)
        sprintf(pStrRet, "  %d", SETALARM_DEPTH_FT);
    else
        sprintf(pStrRet, "  %d", SETALARM_DEPTH_M);
}
static void SetAlarms_DEPTH_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[ALARMS_DEPTH_OOS]));
}
/*Set Alarms Depth value*/
const contentDispContext_st SetAlarm_DEPTH_Context =
{
    &SETALARMS_Depth_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Set Alarms Depth Stat*/
const contentDispContext_st SetAlarm_DEPTH_Stat_Context =
{
    &SetAlarms_DEPTH_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
