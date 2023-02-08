/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/*Context memdev config to BaiOutPO2_MAX*/
static void DiveSett_BAILOUTPO2_MAX_Content(char* pStrRet)
{
    if(OC_MODE||SM_MODE)
        sprintf(pStrRet, " %.2f ", 0.01*GUI_OC_SM_PO2_Max);
    else
        sprintf(pStrRet, " %.2f ", 0.01*GUI_BO_PO2_Max);
}
const contentDispContext_st Set_BaiOutPO2_MAX_Ctx =
{
    &DiveSett_BAILOUTPO2_MAX_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};