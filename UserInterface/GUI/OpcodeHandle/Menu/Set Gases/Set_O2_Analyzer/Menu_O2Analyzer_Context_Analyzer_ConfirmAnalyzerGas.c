/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Analyze_Line_0(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_ADD_GAS_1));   // modified by YS on 2021 10 19 (see Op Logic r18, Page-51)
    //sprintf(pStrRet, "TO ASSIGN %2.0d/%2.0d ", (uint8_t)Primary_Tank_FO2_Pct, );
}
static void O2Analyzer_Analyze_Line_1(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_ADD_GAS_2));     // modified by YS on 2021 10 19 (see Op Logic r18, Page-51)
}
static void O2Analyzer_Analyze_Status(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_YesNo_Context[GUI_O2ANALYZER_FO2_ASSIGN_FLAT]));
}
const contentDispContext_st O2Analyzer_Analyze_Line_0_Ctx =
{
    &O2Analyzer_Analyze_Line_0,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyze_Line_1_Ctx =
{
    &O2Analyzer_Analyze_Line_1,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Analyze_Status_Ctx =
{
    &O2Analyzer_Analyze_Status,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_01,
};
