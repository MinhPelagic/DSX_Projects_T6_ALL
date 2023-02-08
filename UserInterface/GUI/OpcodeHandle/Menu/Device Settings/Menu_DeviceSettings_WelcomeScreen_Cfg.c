/******************************************************************************/
//File: Device settings -> Units
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
extern const TxtStr_Name_e TxtDef_WelcomeScr[];

/*Context memdev config to DeviceSett_WelcomeScr*/
static void DeviceSett_WELCOMESCREEN_Content(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDef_WelcomeScr[GUI_Welcome_Screen]));
}
const contentDispContext_st Set_DeviceSett_WelcomeScr_Ctx =
{
    &DeviceSett_WELCOMESCREEN_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};