/******************************************************************************/
//File: Language
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

/*Context memdev config to DispSett_Language*/
static void DispSett_LANGUAGE_Content(char* pStrRet)
{
    sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtStrSetLanguage[GUI_LANG_Select]));
}
const contentDispContext_st Set_DispSett_Language_Ctx =
{
    &DispSett_LANGUAGE_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetLanguage_Language,
};