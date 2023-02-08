/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Calibarte_Complete_Line01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_COMPLETE_1));
}
const contentDispContext_st O2Analyzer_Calibarte_Complete_Line01_Ctx =
{
    &O2Analyzer_Calibarte_Complete_Line01,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Calibarte_Complete_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_COMPLETE_2));
}
const contentDispContext_st O2Analyzer_Calibarte_Complete_Line02_Ctx =
{
    &O2Analyzer_Calibarte_Complete_Line02,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void O2Analyzer_Calibarte_Complete_Line03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2CELL_CAL_COMPLETE_3));
}
const contentDispContext_st O2Analyzer_Calibarte_Complete_Line03_Ctx =
{
    &O2Analyzer_Calibarte_Complete_Line03,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
