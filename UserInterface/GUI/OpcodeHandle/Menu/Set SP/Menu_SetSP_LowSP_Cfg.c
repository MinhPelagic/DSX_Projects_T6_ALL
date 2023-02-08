/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
/*-------------------------------------------------------------------------------------------------------*/
/*Context memdev config to On/Off/Set SET_LOW_SP*/
const contentDispContext_st SetSP_OnOffSet_SetLowSp_Ctx =
{
    &SetSP_LOW_SP_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};