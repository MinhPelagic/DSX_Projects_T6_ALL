/******************************************************************************/
//File: Autodim.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"
#define SET_AUTODIM_LV              GUI_DIM_BRIGHT_LV

/*AUTODIM TIME context*/
void DispSett_Autodim_BrightTime(char* pStrRet)
{
    sprintf(pStrRet, "%.2d:%.2d", (U8)(GUI_BRIGHTNESS_DIM_TIME / 60), GUI_BRIGHTNESS_DIM_TIME % 60);

}
static void Set_DispSett_Brightness_AutoDim_Content(char* pStrRet)
{
    sprintf(pStrRet, "  %d", SET_AUTODIM_LV);
}
/*Context memdev config to DisplaySett_Autodim_Stat*/
static void DispSett_AUTODIM_Content(char* pStrRet)
{
    sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_BRIGHTNESS_DIM_MODE]));
}
const contentDispContext_st Set_DispSett_Autodim_Stat_Ctx =
{
    &DispSett_AUTODIM_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
/*Context memdev config to DisplaySett_Autodim_BrightTime*/
const contentDispContext_st Set_DispSett_Autodim_BrightTime_Ctx =
{
    &DispSett_Autodim_BrightTime,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
/*Set Brightness Autodim value*/
const contentDispContext_st Set_DispSett_Brightness_AutoDim_Ctx =
{
    &Set_DispSett_Brightness_AutoDim_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};;
