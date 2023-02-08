/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"

/*Context memdev config to DiveSett_Consrv_TEC_High*/
static void DiveSett_CONSERVATISM_TEC_HIGH_Content(char* pStrRet)
{
    sprintf(pStrRet, " %d ", OONSRV_TecGF_Hi);
}
const contentDispContext_st Set_DiveSett_Consrv_TEC_High_Ctx =
{
    &DiveSett_CONSERVATISM_TEC_HIGH_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
