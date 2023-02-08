/******************************************************************************/
//File: Device settings -> Units
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
extern const TxtStr_Name_e TxtDef_Set_UNIT[SetUnit_MAX];

/*Context memdev config to DeviceSett_UnitSet*/
static void DeviceSett_UNITS_Content(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDef_Set_UNIT[GUI_Unit]));
}
const contentDispContext_st Set_DeviceSett_UnitSet_Ctx =
{
    &DeviceSett_UNITS_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};