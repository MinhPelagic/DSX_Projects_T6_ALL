/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/*BAILOUT PO2 LIMITS*/
const menuItemContext_ts* pFunc_Context_PO2Limit[BailOutPO2Limits_MAX]=
{
    &Context_DiveSett_BAILOUTPO2_MIN,
    &Context_DiveSett_BAILOUTPO2_MAX,
    &Context_DiveSett_BAILOUTPO2_DECO,
};
/*BAILOUT PO2 LIMITS MIN context*/
void DiveSett_BAILOUTPO2_MIN_Context_Left(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OC_MIN_PO2));
    else // CC or BO
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BO_MIN_PO2));
}
void DiveSett_BAILOUTPO2_MIN_Context_Right(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        sprintf(pStrRet, "%.2f", (float)0.01*OC_SM_MIN_PO2);
    else
        sprintf(pStrRet, "%.2f", (float)0.01*BO_MIN_PO2);
}
/*BAILOUT PO2 LIMITS MAX context*/
void DiveSett_BAILOUTPO2_MAX_Context_Left(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OC_MAX_PO2));
    else // CC or BO
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BO_MAX_PO2));
}
void DiveSett_BAILOUTPO2_MAX_Context_Right(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        sprintf(pStrRet, "%.2f", (float)0.01*OC_SM_MAX_PO2);
    else
        sprintf(pStrRet, "%.2f", (float)0.01*BO_MAX_PO2);
}
/*BAILOUT PO2 Limit DECO context*/
void DiveSett_BAILOUTPO2_DECO_Context_Left(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OC_DECO_PO2));
    else // CC or BO
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BO_DECO_PO2));
}
void DiveSett_BAILOUTPO2_DECO_Context_Right(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        sprintf(pStrRet, "%.2f", (float)0.01*OC_SM_DECO_PO2);
    else
        sprintf(pStrRet, "%.2f", (float)0.01*BO_DECO_PO2);
}
