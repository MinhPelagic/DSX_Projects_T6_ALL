/******************************************************************************/
//File: Device settings -> Units
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"

/*Context memdev config to DeviceSett_Bluetooth*/
void DeviceSett_BLUETOOTH_Content(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_BluetoothState]));
}
const contentDispContext_st Set_DeviceSett_Bluetooth_Ctx =
{
    &DeviceSett_BLUETOOTH_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};