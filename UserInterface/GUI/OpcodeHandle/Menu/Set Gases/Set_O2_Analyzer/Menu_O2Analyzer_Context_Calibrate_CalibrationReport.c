/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "O2.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Calibarte_CalibrationReport_Line00(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CALIBRATED_BASE_ON));
}
const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line00_Ctx =
{
    &O2Analyzer_Calibarte_CalibrationReport_Line00,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Calibarte_CalibrationReport_Line01(char* pStrRet)
{
    sprintf(pStrRet, "%s: %d", "FO2",GUI_O2ANALYZER_FO2_SET);
}
const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line01_Ctx =
{
    &O2Analyzer_Calibarte_CalibrationReport_Line01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void O2Analyzer_Calibarte_CalibrationReport_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CELL_VOLTAGE));
}
const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line02_Ctx =
{
    &O2Analyzer_Calibarte_CalibrationReport_Line02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
static void O2Analyzer_Calibarte_CalibrationReport_Line03(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", O2_Cell_mV_Of_Set_FO2, "mV");
    //sprintf(pStrRet, "%d %s", (uint16_t)(O2_Analyzer_Volt*1000), "mV");
}
const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line03_Ctx =
{
    &O2Analyzer_Calibarte_CalibrationReport_Line03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};
