#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
static const listItemInMenu_ts DisplaySettings_CC_Context=
{
    6,/*Number of items*/
    {
        &Context_DispSett_BRIGHTNESS,
        &Context_DispSett_AUTODIM,
        &Context_DispSett_TITLECOLOR,
        &Context_DispSett_LANGUAGE,
        &Context_DispSett_FLIPSCREEN,
        &Context_DispSett_MAINDISPLAY,
    }
};
static const listItemInMenu_ts DisplaySettings_SM_Context=
{
    7,/*Number of items*/
    {
        &Context_DispSett_BRIGHTNESS,
        &Context_DispSett_AUTODIM,
        &Context_DispSett_TITLECOLOR,
        &Context_DispSett_LANGUAGE,
        &Context_DispSett_FLIPSCREEN,
        &Context_DispSett_MAINDISPLAY,
        &Context_DispSett_GTR_LEF_RIGHT,
    }
};
static const listItemInMenu_ts DisplaySettings_GSM_Context=
{
    7,/*Number of items*/
    {
        &Context_DispSett_BRIGHTNESS,
        &Context_DispSett_AUTODIM,
        &Context_DispSett_TITLECOLOR,
        &Context_DispSett_LANGUAGE,
        &Context_DispSett_FLIPSCREEN,
        &Context_DispSett_EXTRALARGE,
        &Context_DispSett_GTR_LEF_RIGHT,
    }
};
static const listItemInMenu_ts DisplaySettings_GAUGE_Context=
{
    6,/*Number of items*/
    {
        &Context_DispSett_BRIGHTNESS,
        &Context_DispSett_AUTODIM,
        &Context_DispSett_TITLECOLOR,
        &Context_DispSett_LANGUAGE,
        &Context_DispSett_FLIPSCREEN,
        &Context_DispSett_EXTRALARGE,
    }
};
const listItemInMenu_ts* DisplaySettings_ListOfContext[DIVEMODE_MAX] =
{
    &DisplaySettings_CC_Context,/*CC*/
    &DisplaySettings_CC_Context,/*OC*/
    &DisplaySettings_SM_Context,/*SM*/
    &DisplaySettings_GSM_Context,/*GAUGE SM*/
    &DisplaySettings_GAUGE_Context,/*GAUGE*/
    &DisplaySettings_CC_Context,/*BO*/
};

static const listItemInMenu_ts MainDisplay_CC_Context=
{
    4,/*Number of items*/
    {
        &Context_MainDisplay_LEFT,
        &Context_MainDisplay_RIGHT,
        &Context_MainDisplay_GFBG_OR_N2,
        &Context_MainDisplay_EXTRALARGE,
    }
};

const listItemInMenu_ts* MainDisplay_ListOfContext[DIVEMODE_MAX] =
{
    &MainDisplay_CC_Context,	/*CC*/
    &MainDisplay_CC_Context,	/*OC*/
    &MainDisplay_CC_Context,	/*SM*/
    &MainDisplay_CC_Context,	/*GAUGE*/
    &MainDisplay_CC_Context,	/*GAUGE SM*/
    &MainDisplay_CC_Context,	/*BO*/
};






