/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
/*Context memdev config to DispSett_FlipScreen*/
static void DispSett_FLIPSCREEN_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_SWITCH_LCD_Flip]));
}
const contentDispContext_st Set_DispSett_FlipScreen_Ctx =
{
    &DispSett_FLIPSCREEN_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};