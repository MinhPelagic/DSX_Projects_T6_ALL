#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
static const listItemInMenu_ts DeviceSettings_CC_Context=
{
    7,/*Number of items*/
    {
        &Context_DeviceSett_TRANSMITTERS,
        &Context_DeviceSett_UNITS,
        &Context_DeviceSett_WATERTYPE,
        &Context_DeviceSett_SAMPLERATE,
        &Context_DeviceSett_BLUETOOTH,
        &Context_DeviceSett_RESETSETTINGS,
        &Context_DeviceSett_WELCOMESCREEN,
    }
};
const listItemInMenu_ts* DeviceSettings_ListOfContext[DIVEMODE_MAX] =
{
    &DeviceSettings_CC_Context,/*CC*/
    &DeviceSettings_CC_Context,/*OC*/
    &DeviceSettings_CC_Context,/*SM*/
    &DeviceSettings_CC_Context,/*GAUGE*/
    &DeviceSettings_CC_Context,/*GAUGE SM*/
    &DeviceSettings_CC_Context,/*BO*/
};
/* TRANSMITTERS SETTINGS */
static const listItemInMenu_ts TransmittersDisp_CC_Context=
{
    6,/*Number of items*/
    {
        &Context_Transmitters_TMT_1,
        &Context_Transmitters_TMT_2,
        &Context_Transmitters_TMT_3,
        &Context_Transmitters_TMT_4,
        &Context_Transmitters_TMT_5,
        &Context_Transmitters_TMT_6,
    }
};
const listItemInMenu_ts* Transmiters_ListOfContext[DIVEMODE_MAX] =
{
    &TransmittersDisp_CC_Context,	/*CC*/
    &TransmittersDisp_CC_Context,	/*OC*/
    &TransmittersDisp_CC_Context,	/*SM*/
    &TransmittersDisp_CC_Context,	/*GAUGE*/
    &TransmittersDisp_CC_Context,	/*GAUGE SM*/
    &TransmittersDisp_CC_Context,	/*BO*/
};