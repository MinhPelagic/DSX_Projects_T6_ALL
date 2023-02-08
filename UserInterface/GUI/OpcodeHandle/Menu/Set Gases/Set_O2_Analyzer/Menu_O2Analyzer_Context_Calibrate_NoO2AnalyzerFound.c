/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Calibarte_NoO2AnalyzerFound_Line01(char* pStrRet)
{
    strcpy(pStrRet, "NO O2 ANALYZER FOUND");
    //strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_O2_ANALYZER_FOUND_1));
}
const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line01_Ctx =
{
    &O2Analyzer_Calibarte_NoO2AnalyzerFound_Line01,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Calibarte_NoO2AnalyzerFound_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_O2_CELL_FOUND_2));
}
const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line02_Ctx =
{
    &O2Analyzer_Calibarte_NoO2AnalyzerFound_Line02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
static void O2Analyzer_Calibarte_NoO2AnalyzerFound_Line03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_O2_CELL_FOUND_3));
}
const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line03_Ctx =
{
    &O2Analyzer_Calibarte_NoO2AnalyzerFound_Line03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};
