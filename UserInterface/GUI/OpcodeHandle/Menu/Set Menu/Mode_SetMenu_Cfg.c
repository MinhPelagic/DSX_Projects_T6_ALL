#include "L4X9_includes.h"
#include "ContextSetMenuCfg.h"
static const listItemInMenu_ts SetMenu_CC_Context=
{
    7,/*Number of items*/
    {
        &Context_SetMenu_SETGAS,
        &Context_SetMenu_SETSP,
        &Context_SetMenu_DIVESETTINGS,
        &Context_SetMenu_ALARMS,
        &Context_SetMenu_DEVICESETTINGS,
        &Context_SetMenu_DATETIME,
        &Context_SetMenu_DISPLAYSETTINGS,
    }
};
static const listItemInMenu_ts SetMenu_OC_Context=
{
    6,/*Number of items*/
    {
        &Context_SetMenu_SETGAS,
        &Context_SetMenu_DIVESETTINGS,
        &Context_SetMenu_ALARMS,
        &Context_SetMenu_DEVICESETTINGS,
        &Context_SetMenu_DATETIME,
        &Context_SetMenu_DISPLAYSETTINGS,
    }
};
static const listItemInMenu_ts SetMenu_SMG_Context=
{
    4,/*Number of items*/
    {
        &Context_SetMenu_ALARMS,
        &Context_SetMenu_DEVICESETTINGS,
        &Context_SetMenu_DATETIME,
        &Context_SetMenu_DISPLAYSETTINGS,
    }
};

const listItemInMenu_ts* SetMenu_ListOfContext[DIVEMODE_MAX] =
{
    &SetMenu_CC_Context,/*CC*/
    &SetMenu_OC_Context,/*OC*/
    &SetMenu_OC_Context,/*SM*/
    &SetMenu_SMG_Context,/*GAUGE*/
    &SetMenu_SMG_Context,/*GAUGE SM*/
    &SetMenu_CC_Context,/*BO*/
};
