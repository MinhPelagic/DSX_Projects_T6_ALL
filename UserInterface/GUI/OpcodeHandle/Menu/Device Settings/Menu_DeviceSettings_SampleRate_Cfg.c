/******************************************************************************/
//File: Device settings -> Sample rate
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"

/*Context memdev config to DeviceSett_SampleRate*/
static void Set_DeviceSett_SampleRate_Unit_Content(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SEC));
}
static void Set_DeviceSett_SampleRate_Value_Content(char* pStrRet)
{
    sprintf(pStrRet, "  %d", GUI_SampleTime);
}
/*Sample rate SEC text*/
const contentDispContext_st Set_DeviceSett_SampleRate_Unit_Ctx =
{
    &Set_DeviceSett_SampleRate_Unit_Content,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_UnitSign, //SEC
};
/*Set Sample Rate value*/
const contentDispContext_st Set_DeviceSett_SampleRate_Value_Ctx =
{
    &Set_DeviceSett_SampleRate_Value_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};