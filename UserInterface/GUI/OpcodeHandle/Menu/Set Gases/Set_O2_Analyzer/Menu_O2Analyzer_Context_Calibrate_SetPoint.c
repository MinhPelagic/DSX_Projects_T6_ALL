/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Calibarte_Line_0(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_CALIBRATION_FO2_1));
}
static void O2Analyzer_Calibarte_Line_1(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_CALIBRATION_FO2_2));
}
static void O2Analyzer_Calibarte_Value(char* pStrRet)
{
    sprintf(pStrRet, " %d ", GUI_O2ANALYZER_FO2_SET);
}
const contentDispContext_st O2Analyzer_Calibarte_Line_0_Ctx =
{
    &O2Analyzer_Calibarte_Line_0,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Calibarte_Line_1_Ctx =
{
    &O2Analyzer_Calibarte_Line_1,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Calibarte_Value_Ctx =
{
    &O2Analyzer_Calibarte_Value,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_01,
};
