/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"


static void O2Analyzer_Analyzer_AnalyResultConfirm(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESULT));
}
const contentDispContext_st O2Analyzer_Analyzer_AnalyResConfirm_Ctx =
{
    &O2Analyzer_Analyzer_AnalyResultConfirm,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Analyzer_AnalyResultFO2Value(char* pStrRet)
{
    sprintf(pStrRet, "FO2: %d ", Compensated_Uint8_O2_Pct);
}
const contentDispContext_st O2Analyzer_Analyzer_AnalyFO2Value_Ctx =
{
    &O2Analyzer_Analyzer_AnalyResultFO2Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_00,
};
static void O2Analyzer_Analyzer_ConfirmText(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CONFIRM));
}
const contentDispContext_st O2Analyzer_Analyzer_ConfirmText_Ctx =
{
    &O2Analyzer_Analyzer_ConfirmText,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
static void O2Analyzer_Analyzer_AnalyConfirmStatus(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_YesNo_Context[GUI_O2ANALYZER_FO2_CONFIRM_FLAT]));
}
const contentDispContext_st O2Analyzer_Analyzer_AnalyConfirmStatus_Ctx =
{
    &O2Analyzer_Analyzer_AnalyConfirmStatus,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_02,
};
