/******************************************************************************/
//File: Device settings -> Water type
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
extern const TxtStr_Name_e TxtDef_Set_WaterType[];

/*Context memdev config to DeviceSett_WaterType*/
void DeviceSett_WATERTYPE_Content(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDef_Set_WaterType[GUI_WaterType]));
}
const contentDispContext_st Set_DeviceSett_WaterType_Ctx =
{
    &DeviceSett_WATERTYPE_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};