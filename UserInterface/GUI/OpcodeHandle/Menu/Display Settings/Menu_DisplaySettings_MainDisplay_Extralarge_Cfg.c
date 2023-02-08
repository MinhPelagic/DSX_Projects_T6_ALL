/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void MainDisplay_EXTRALARGE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_EXTRA_LARGE));
}
void MainDisplay_EXTRALARGE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_ExtraLarge_Context[GUI_MAINDISPLAY_EXTRA_LARGE]));
}
/*Context memdev config to DispSett_Extralarge*/
const contentDispContext_st Set_DispSett_Extralarge_Ctx =
{
    &MainDisplay_EXTRALARGE_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};