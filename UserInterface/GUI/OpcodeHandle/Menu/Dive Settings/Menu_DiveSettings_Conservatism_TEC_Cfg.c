/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

const menuItemContext_ts* p_Conserv_TEC_Contextt[Conservatism_GF_MAX] =
{
    &Context_DiveSett_CONSERVATISM_TEC_LOW,
    &Context_DiveSett_CONSERVATISM_TEC_HIGH
};
/*TEC LOW context*/
void DiveSett_CONSERVATISM_TEC_LOW_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GF_LOW));
}
void DiveSett_CONSERVATISM_TEC_LOW_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d", OONSRV_TecGF_Lo);
}
/*TEC HIGH context*/
void DiveSett_CONSERVATISM_TEC_HIGH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GF_HIGH));
}
void DiveSett_CONSERVATISM_TEC_HIGH_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d", OONSRV_TecGF_Hi);
}
