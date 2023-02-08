/******************************************************************************/
//File: GTR left and right
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

static void Set_MainDisp_3rdRowLeft_Content(char* pStrRet)
{
    sprintf(pStrRet,  "       %s       ", GUI_LANG_GetText(TxtDef_LEFT_RIGHT_Context[GUI_MAINDISPLAY_3RD_ROW_LEFT]));
}
/*Context memdev config to MainDisp_3rdRowLeft*/
const contentDispContext_st Set_MainDisp_3rdRowLeft_Ctx =
{
    &Set_MainDisp_3rdRowLeft_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};

