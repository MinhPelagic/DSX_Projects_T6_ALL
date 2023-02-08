/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx;
/*-------------------------------------------------------------------------------------------------------*/
/*Local context*/
static void _SetSP_OnOffSet_AutoLow_Content(char* pStrRet)
{
    /**/
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_AUTO_LOW]));
}
/*Context memdev config auto LOW*/
const contentDispContext_st SetSP_OnOffSet_AutoLow_Ctx =
{
    &_SetSP_OnOffSet_AutoLow_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
/*-------------------------------------------------------------------------------------------------------*/
static void SetSP_AUTO_LOW_Content(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "    %d", SET_SP_AUTO_FT_LOW);
    else
        sprintf(pStrRet, "    %d", SET_SP_AUTO_M_LOW);
}
const contentDispContext_st SetSP_AutoLow_Ctx =
{
    &SetSP_AUTO_LOW_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};