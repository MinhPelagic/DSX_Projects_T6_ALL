/******************************************************************************/
//File:
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
/*Context memdev config to DispSett_GTRLeftRight*/
const contentDispContext_st Set_DispSett_GTRLeftRight_Ctx =
{
    &DispSett_GTR_LEF_RIGHT_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};