/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "..\Set SP\Menu_SetSP.h"

/*Local context*/
static void DiveSett_SafetyStopDepth_Value_Context(char* pStrRet)
{
    /**/
    if(Imperial)
    {
        sprintf(pStrRet, " %d ", SafetyStop_DEPTH_FT);
    }
    else
    {
        sprintf(pStrRet, " %d ", SafetyStop_DEPTH_M);
    }
}
/*Context memdev config*/
const contentDispContext_st DiveSett_SafetyStopDepth_Context =
{
    &DiveSett_SafetyStopDepth_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetSS_Depth_Value,
};
/*Local context Safety stop time*/
static void DiveSett_SafetyStopTime_Value_Context(char* pStrRet)
{
    /**/
    sprintf(pStrRet, " %d ", SafetyStop_TIME_Mins);
}
/*Context memdev config*/
const contentDispContext_st DiveSett_SafetyStopTime_Context =
{
    &DiveSett_SafetyStopTime_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetSS_Time_Value,
};
/*SAFETY STOP STATE context*/
void DIVESETT_SAFETYSTOP_STATE_Context(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[SAFETY_STOP_SET_POINTS_STAT]));
}
/*------------------------------------------------------------------*/
void SetSS_MINUnit(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MIN));
}
const contentDispContext_st SetSS_MIN_Context =
{
    &SetSS_MINUnit,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetSS_Time_UnitSign, //MIN
};
const contentDispContext_st SetSS_UNITSET_Context =
{
    &SetSP_UNITSET,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetSS_Depth_UnitSign, //Unit sign M/FT
};
/*Context memdev config to DiveSett_SafetyStop_STAT*/
const contentDispContext_st Set_DiveSett_SafetyStop_STAT_Ctx =
{
    &DIVESETT_SAFETYSTOP_STATE_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
