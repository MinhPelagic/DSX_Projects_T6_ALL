/******************************************************************************/
//File: S476
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static void O2Analyzer_Analyze_SelectGasList_0(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_SELECT_GAS_LIST_1));
}
static void O2Analyzer_Analyze_SelectGasList_1(char* pStrRet)
{
    sprintf(pStrRet, "%s %2.0d/%0.2d ", GUI_LANG_GetText(TxtStr_O2ANALYZER_SELECT_GAS_LIST_2), (uint8_t)GUI_O2_AnalyzerFO2Set, GUI_O2_AnalyzerFHeSet);
}
static void O2Analyzer_GasList_Status(char* pStrRet)
{
    sprintf(pStrRet, "    %s    ", GUI_LANG_GetText(TxtDef_DSX_MainMode[GUI_O2ANALYZER_DIVEMODE_ASSIGN]));
}
/*S476*/
const contentDispContext_st O2Analyzer_Analyze_SelectGasList_0_Ctx =
{
    &O2Analyzer_Analyze_SelectGasList_0,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyze_SelectGasList_1_Ctx =
{
    &O2Analyzer_Analyze_SelectGasList_1,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_GasList_Status_Ctx =
{
    &O2Analyzer_GasList_Status,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_01,
};
/*S478*/
static void O2Analyzer_Analyze_ConfirmAsssignGas_0(char* pStrRet)
{
    if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDSM)
        sprintf(pStrRet, "SET SM-%1.0d", GAS_ASSIGN_INDEX);
    else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDOC)
        sprintf(pStrRet, "SET OC-%1.0d", GAS_ASSIGN_INDEX);
    else
        sprintf(pStrRet, "SET CC-%1.0d", GAS_ASSIGN_INDEX);
}
static void O2Analyzer_Analyze_ConfirmAsssignGas_1(char* pStrRet)
{
    sprintf(pStrRet, "%.2d/%.2d ", (uint8_t)GUI_O2_AnalyzerFO2Set, GUI_O2_AnalyzerFHeSet);
}
static void O2Analyzer_Analyze_ConfirmAsssignGas_Status(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_YesNo_Context[GUI_O2ANALYZER_FO2_ASSIGN_FLAT]));
}
const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_0_Ctx =
{
    &O2Analyzer_Analyze_ConfirmAsssignGas_0,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_1_Ctx =
{
    &O2Analyzer_Analyze_ConfirmAsssignGas_1,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_Status_Ctx =
{
    &O2Analyzer_Analyze_ConfirmAsssignGas_Status,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_Setting_Value_BelowLine_01,
};
/*S479*/
static void O2Analyzer_Analyze_AssignedComplete_0(char* pStrRet)
{
    if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDCC)
        sprintf(pStrRet, "CC-%d", GAS_ASSIGN_INDEX);
    else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDOC)
        sprintf(pStrRet, "OC-%d", GAS_ASSIGN_INDEX);
    else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDSM)
        sprintf(pStrRet, "SM-%d", GAS_ASSIGN_INDEX);
    else if(GUI_O2ANALYZER_DIVEMODE_ASSIGN==NVD_MDGSM)
        sprintf(pStrRet, "GSM-%d", GAS_ASSIGN_INDEX);
    else
        sprintf(pStrRet, "GAUGE-%d", GAS_ASSIGN_INDEX);
}
static void O2Analyzer_Analyze_AssignedComplete_1(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_IS_SET_TO));
}
static void O2Analyzer_Analyze_AssignedComplete_2(char* pStrRet)
{
    sprintf(pStrRet, "%.2d/%.2d ", (uint8_t)GUI_O2_AnalyzerFO2Set, GUI_O2_AnalyzerFHeSet);
}
const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_0_Ctx =
{
    &O2Analyzer_Analyze_AssignedComplete_0,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_1_Ctx =
{
    &O2Analyzer_Analyze_AssignedComplete_1,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_2_Ctx =
{
    &O2Analyzer_Analyze_AssignedComplete_2,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*S486 Proceed ?*/
static void O2Analyzer_Analyze_ConfirmProceed_Line_0(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_SELECT_GAS_1));
}
static void O2Analyzer_Analyze_ConfirmProceed_Line_1(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_SELECT_GAS_2));
}
static void O2Analyzer_Analyze_ConfirmProceed_Line_2(char* pStrRet)
{
    sprintf(pStrRet, "%.2d/%.2d ", 25, 45);
}
static void O2Analyzer_Analyze_ConfirmProceed_Line_3(char* pStrRet)
{
    sprintf(pStrRet, GUI_LANG_GetText(TxtStr_O2ANALYZER_SELECT_GAS_4));
}
const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_0_Ctx =
{
    &O2Analyzer_Analyze_ConfirmProceed_Line_0,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_1_Ctx =
{
    &O2Analyzer_Analyze_ConfirmProceed_Line_1,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_2_Ctx =
{
    &O2Analyzer_Analyze_ConfirmProceed_Line_2,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_3_Ctx =
{
    &O2Analyzer_Analyze_ConfirmProceed_Line_3,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};
