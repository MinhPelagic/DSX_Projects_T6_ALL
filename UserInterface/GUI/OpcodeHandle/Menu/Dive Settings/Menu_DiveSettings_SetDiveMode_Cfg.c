/******************************************************************************/
//File: Dive_Settings.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"

/*Context memdev config to DiveSett_SetDiveMode*/
static void DiveSett_DIVEMODE_Content(char* pStrRet)
{
    /*Padding space to remove overlap*/
    sprintf(pStrRet, "      %s      ", GUI_LANG_GetText(TxtDef_DSX_MainMode[GUI_DIVE_Mode]));
}
const contentDispContext_st Set_DiveSett_SetDiveMode_Ctx =
{
    &DiveSett_DIVEMODE_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};