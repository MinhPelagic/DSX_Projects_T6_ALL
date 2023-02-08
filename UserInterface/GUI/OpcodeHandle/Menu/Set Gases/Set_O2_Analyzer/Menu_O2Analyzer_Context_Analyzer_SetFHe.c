/******************************************************************************/
//File: S476
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

/*Context memdev config to O2 analyzer FO2*/
static void O2Analyzer_FO2(char* pStrRet)
{
    sprintf(pStrRet, "  %d  ", GUI_O2_AnalyzerFO2Set);
}
const contentDispContext_st Set_SetFHe_FO2_Ctx =
{
    &O2Analyzer_FO2,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_FO2,
};
/*Context memdev config to O2 analyzer FHe*/
static void O2Analyzer_FHe(char* pStrRet)
{
    sprintf(pStrRet, "  %.2d  ", GUI_O2_AnalyzerFHeSet);
}
const contentDispContext_st Set_SetFHe_FHe_Ctx =
{
    &O2Analyzer_FHe,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
