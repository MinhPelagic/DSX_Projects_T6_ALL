/******************************************************************************/
//File: Titile color
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"
const GUI_COLOR Color_InfoTitleSetting[ColorTitle_MAX]=
{
    GUI_CYAN,
    GUI_GREEN,
    GUI_WHITE,
    GUI_ORANGE,
    GUI_MAGENTA
};
static void DispSett_TITLECOLOR_Content(char* pStrRet)
{
    sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtDef_Set_TitleColor[TITLE_Color]));
}
/*Context memdev config to DispSett_TittleColor*/
const contentDispContext_st Set_DispSett_TittleColor_Ctx =
{
    &DispSett_TITLECOLOR_Content,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};