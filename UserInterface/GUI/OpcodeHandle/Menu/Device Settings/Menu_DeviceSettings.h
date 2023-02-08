/******************************************************************************/
//File: Device settings
//Description: handle the Device settings page
//Created by:DucThinh
//History:
//
/*****************************************************************************/
#ifndef _MENU_DEVICE_SETTINGS_H_
#define _MENU_DEVICE_SETTINGS_H_

#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"

/*Water type setting option*/
enum SetWaterType_e
{
    SetWaterType_SALT = 0x00,
    SetWaterType_EN13319,
    SetWaterType_FRESH,
    SetWaterType_MAX,
};
/*Sample rate setting option*/
enum SetSampleRate_e
{
    SetSampleRate_2SEC = 0x00,
    SetSampleRate_15SEC,
    SetSampleRate_30SEC,
    SetSampleRate_60SEC,
    SetSampleRate_MAX,
};
enum WelcomeScr_e
{
    DevSet_Welcome_Standard_e,
    DevSet_Welcome_Upload_1_e,
    DevSet_Welcome_Upload_2_e,
    DevSet_Welcome_Upload_3_e,
    DevSet_Welcome_Upload_MAX_e,
};
/*Transmitters digits*/
enum transmittDigit_e
{
    setDigit_1 = 1u,
    setDigit_2,
    setDigit_3,
    setDigit_4,
    setDigit_5,
    setDigit_6
};
const char* Set_TM_TMT1_STAT_Context_Center(void);
const char* Set_TM_TMT2_STAT_Context_Center(void);
const char* Set_TM_TMT3_STAT_Context_Center(void);
const char* Set_TM_TMT4_STAT_Context_Center(void);
const char* Set_TM_TMT5_STAT_Context_Center(void);
const char* Set_TM_TMT6_STAT_Context_Center(void);
const char* Set_TM_TMT1_Context_Right(void);
const char* Set_TM_TMT2_Context_Right(void);
const char* Set_TM_TMT3_Context_Right(void);
const char* Set_TM_TMT4_Context_Right(void);
const char* Set_TM_TMT5_Context_Right(void);
const char* Set_TM_TMT6_Context_Right(void);

/*Extern variables for set TMT module*/
extern uint8_t GUI_TMT_SerialNum[8][8];
extern const listItemInMenu_ts* DeviceSettings_ListOfContext[DIVEMODE_MAX];
extern const listItemInMenu_ts* Transmiters_ListOfContext[DIVEMODE_MAX];
extern const contentDispContext_st Set_DeviceSett_SampleRate_Unit_Ctx;
extern const contentDispContext_st Set_DeviceSett_SampleRate_Value_Ctx;
extern const contentDispContext_st Set_DeviceSett_UnitSet_Ctx;
extern const contentDispContext_st Set_DeviceSett_Bluetooth_Ctx;
extern const contentDispContext_st Set_DeviceSett_WaterType_Ctx;
extern const contentDispContext_st Set_DeviceSett_WelcomeScr_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_SN_Text_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_1_Digit_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_3_Digit_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_4_Digit_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_5_Digit_6_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_1_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_2_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_3_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_4_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_5_Ctx;
extern const contentDispContext_st Set_DeviceSett_Transmitt_TMT_6_Digit_6_Ctx;
extern void Transmitters_TMT_1_Context_Center(char* pStrRet);
extern void Transmitters_TMT_2_Context_Center(char* pStrRet);
extern void Transmitters_TMT_3_Context_Center(char* pStrRet);
extern void Transmitters_TMT_4_Context_Center(char* pStrRet);
extern void Transmitters_TMT_5_Context_Center(char* pStrRet);
extern void Transmitters_TMT_6_Context_Center(char* pStrRet);
const char* GetTextTransmitter_1_L(void);
const char* GetTextTransmitter_2_R(void);
#endif
