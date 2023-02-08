/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
/*-------------------------------------------------------------------------------------------------------*/
/*Context memdev config to On/Off/Set SP_HIGH_SP*/
static void SetSP_HIGH_SP_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, " %.2f ", ((float)SET_SP_HIGH) / 100.0);
}
const contentDispContext_st SetSP_OnOffSet_SetHighSp_Ctx =
{
    &SetSP_HIGH_SP_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
