/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
/*-------------------------------------------------------------------------------------------------------*/
/*Local context*/
static void _SetSP_OnOffSet_Custom_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_CUSTOM]));
}
static void SetSP_CUSTOM_SP_Content(char* pStrRet)
{
    sprintf(pStrRet, " %.2f ", ((float)SET_SP_CUSTOM) / 100.0f);
}
/*Context memdev config auto Custom*/
const contentDispContext_st SetSP_OnOffSet_Custom_Ctx =
{
    &_SetSP_OnOffSet_Custom_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
/*Context memdev config */
const contentDispContext_st SetSP_Custom_Ctx =
{
    &SetSP_CUSTOM_SP_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};