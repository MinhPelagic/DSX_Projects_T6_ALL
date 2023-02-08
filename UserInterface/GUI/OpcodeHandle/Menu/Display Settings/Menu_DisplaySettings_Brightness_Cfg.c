/******************************************************************************/
//File: Brightness.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"

/*Context memdev config to DispSett_Brightness*/
static void Set_DispSett_Brightness_PercentChar_Content(char* pStrRet)
{
    strcpy(pStrRet, "%");
}
static void Set_DispSett_Brightness_Value_Content(char* pStrRet)
{
    sprintf(pStrRet, "    %d", GUI_BRIGHTNESS_LV);
}
static void Set_DispSett_Brightness_Autodim_Content(char* pStrRet)
{
    sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtStr_AUTO));
}
/*Sample rate % text*/
const contentDispContext_st Set_DispSett_Brightness_PercentChar_Ctx =
{
    &Set_DispSett_Brightness_PercentChar_Content,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_UnitSign, //%
};
/*Set Brightness value*/
const contentDispContext_st Set_DispSett_Brightness_Value_Ctx =
{
    &Set_DispSett_Brightness_Value_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Autodim brightness*/
const contentDispContext_st Set_DispSett_Brightness_Autodim_Ctx =
{
    &Set_DispSett_Brightness_Autodim_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};