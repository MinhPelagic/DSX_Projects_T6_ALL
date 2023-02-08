/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
/*-------------------------------------------------------------------------------------------------------*/
/*Local context*/
static void SetSP_OnOffSet_AutoHigh_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_AUTO_HIGH]));
}
/*Context memdev config auto High*/
const contentDispContext_st SetSP_OnOffSet_AutoHigh_Ctx =
{
    &SetSP_OnOffSet_AutoHigh_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
/*Set SP Auto High value*/
static void SetSP_AUTO_HIGH_Content(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "    %d", SET_SP_AUTO_FT_HIGH);
    else
        sprintf(pStrRet, "    %d", SET_SP_AUTO_M_HIGH);
}
const contentDispContext_st SetSP_AutoHigh_Ctx =
{
    &SetSP_AUTO_HIGH_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
void SetSP_UNITSET(char* pStrRet)
{
    strcpy(pStrRet, TxtDef_Set_DepthUnit[UNITS]);
}
const contentDispContext_st SetSP_UnitSet_Ctx =
{
    &SetSP_UNITSET,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_UnitSign, //Unit sign M/FT
};
