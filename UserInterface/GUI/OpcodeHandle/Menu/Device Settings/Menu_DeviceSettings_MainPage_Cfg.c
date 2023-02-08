/******************************************************************************/
//File: Device settings
//Description: handle the Device settings page
//Created by:DucThinh
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"
const TxtStr_Name_e TxtDef_Set_UNIT[SetUnit_MAX]=
{
    TxtStr_IMPERIAL,
    TxtStr_METRIC,
};
const TxtStr_Name_e TxtDef_Set_WaterType[SetWaterType_MAX]=
{
    TxtStr_SALT,
    TxtStr_EN_13319,
    TxtStr_FRESH,
};
//static const uint8_t TxtDef_Set_SampleRate[SetSampleRate_MAX]=
//{
//    2,
//    15,
//    30,
//    60,
//};

const TxtStr_Name_e TxtDef_WelcomeScr[DevSet_Welcome_Upload_MAX_e]=
{
    TxtStr_STANDARD,
    TxtStr_UPLOAD_1,
    TxtStr_UPLOAD_2,
    TxtStr_UPLOAD_3,
};
/*TRANSMITTER context handle*/
void DeviceSett_TRANSMITTERS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TRANSMITTERS));
}
/*UNITS context handle*/
void DeviceSett_UNITS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_UNITS));
}
void DeviceSett_UNITS_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_Set_UNIT[GUI_Unit]));
}
/*WATER TYPE context handle*/
void DeviceSett_WATERTYPE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WATER_TYPE));
}
void DeviceSett_WATERTYPE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_Set_WaterType[GUI_WaterType]));
}
/*SAMPLERATE context handle*/
void DeviceSett_SAMPLERATE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAMPLE_RATE));
}
void DeviceSett_SAMPLERATE_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%d %s", GUI_SampleTime, GUI_LANG_GetText(TxtStr_SEC));
}
/*BLUETOOTH context*/
void DeviceSett_BLUETOOTH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BLUETOOTH));
}
void DeviceSett_BLUETOOTH_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_BluetoothState]));
}
/*RESET SETTINGS context*/
void DeviceSett_RESETSETTINGS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESET_SETTINGS));
}
/*WELCOME Screen context*/
void DeviceSett_WELCOMESCREEN_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WELCOME_SCREEN));
}
void DeviceSett_WELCOMESCREEN_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_WelcomeScr[GUI_Welcome_Screen]));
}