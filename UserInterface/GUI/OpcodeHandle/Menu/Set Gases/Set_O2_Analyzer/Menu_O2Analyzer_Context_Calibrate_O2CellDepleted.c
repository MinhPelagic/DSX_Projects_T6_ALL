/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Calibarte_O2CellDepleted_Line01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_CAL_DEPLETED_1));

}
const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line01_Ctx =
{
    &O2Analyzer_Calibarte_O2CellDepleted_Line01,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line01_AIR_Ctx =
{
    &O2Analyzer_Calibarte_O2CellDepleted_Line01,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Calibarte_O2CellDepleted_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_CAL_DEPLETED_2));
}
const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line02_Ctx =
{
    &O2Analyzer_Calibarte_O2CellDepleted_Line02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
static void O2Analyzer_Calibarte_O2CellDepleted_Line03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_CAL_DEPLETED_3));
}
const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line03_Ctx =
{
    &O2Analyzer_Calibarte_O2CellDepleted_Line03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};
