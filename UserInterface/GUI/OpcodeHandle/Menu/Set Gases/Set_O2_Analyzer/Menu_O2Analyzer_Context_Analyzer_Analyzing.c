/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"


static void O2Analyzer_Analyzer_Analyzing(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ANALYZING));
}

const contentDispContext_st O2Analyzer_Analyzer_Analyzing_Ctx =
{
    &O2Analyzer_Analyzer_Analyzing,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
