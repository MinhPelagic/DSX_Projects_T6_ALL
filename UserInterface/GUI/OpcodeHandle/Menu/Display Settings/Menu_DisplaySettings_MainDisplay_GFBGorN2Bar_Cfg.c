/******************************************************************************/
//File: N2_or_GF left and right
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"

/*Context memdev config to MainDisp_GFBGorN2bar*/
const contentDispContext_st Set_MainDisp_GFBGorN2bar_Ctx =
{
    &MainDisplay_GFBG_OR_N2_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
