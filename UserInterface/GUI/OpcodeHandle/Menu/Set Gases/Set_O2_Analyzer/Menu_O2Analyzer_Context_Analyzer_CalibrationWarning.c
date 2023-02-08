/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Analyzer_CalibrationWarning_Line_0(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_WARNING_1));
}
static void O2Analyzer_Analyzer_CalibrationWarning_Line_1(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_WARNING_2));
}
static void O2Analyzer_Analyzer_CalibrationWarning_Line_2(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_WARNING_3));
}
const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_0_Ctx =
{
    &O2Analyzer_Analyzer_CalibrationWarning_Line_0,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_1_Ctx =
{
    &O2Analyzer_Analyzer_CalibrationWarning_Line_1,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_2_Ctx =
{
    &O2Analyzer_Analyzer_CalibrationWarning_Line_2,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
