/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

#define GUI_O2ANALYZER_SURF_PRES_mBAR   CURRENT_PRESSURE_MBAR

static GUI_COLOR SelectO2_TxtColor(void)
{
    return GUI_GREEN;
}
static void O2Analyzer_Calibarte_ReadyCalib_Line00(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_READY_CAL_1));
}
const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line00_Ctx =
{
    &O2Analyzer_Calibarte_ReadyCalib_Line00,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void O2Analyzer_Calibarte_ReadyCalib_Line01(char* pStrRet)
{
    sprintf(pStrRet, "%.0f mBar", GUI_O2ANALYZER_SURF_PRES_mBAR);
}
const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line01_Ctx =
{
    &O2Analyzer_Calibarte_ReadyCalib_Line01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void O2Analyzer_Calibarte_ReadyCalib_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_READY_CAL_3));
}
const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line02_Ctx =
{
    &O2Analyzer_Calibarte_ReadyCalib_Line02,
    &SelectO2_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
static void O2Analyzer_Calibarte_ReadyCalib_Line03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_READY_CAL_4));
}
const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line03_Ctx =
{
    &O2Analyzer_Calibarte_ReadyCalib_Line03,
    &SelectO2_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};
