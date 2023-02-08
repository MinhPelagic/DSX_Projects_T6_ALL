#include "L4X9_includes.h"
#include "ContextDiveMainMenuCfg.h"

/*
Context Menu of MAIN MENU under water
===============================================================================================================

===============================================================================================================
*/
static const listItemInMenu_ts DiveMainMenu_CC_Context=
{
    6,/*Number of items*/
    {
        &Context_DiveMainMenu_SPSWITCH,
        &Context_DiveMainMenu_GASSWITCH,
        &Context_DiveMainMenu_SWITCH_CC_TO_BO,
        &Context_DiveMainMenu_BRIGHTNESS,
        &Context_DiveMainMenu_DIVEMENU,
        &Context_DiveMainMenu_SLATES,
    }
};
static const listItemInMenu_ts DiveMainMenu_BO_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveMainMenu_GASSWITCH,
        &Context_DiveMainMenu_SWITCH_BO_TO_CC,
        &Context_DiveMainMenu_BRIGHTNESS,
        &Context_DiveMainMenu_DIVEMENU,
        &Context_DiveMainMenu_SLATES,
    }
};
static const listItemInMenu_ts DiveMainMenu_OC_Context=
{
    4,/*Number of items*/
    {
        &Context_DiveMainMenu_GASSWITCH,
        &Context_DiveMainMenu_BRIGHTNESS,
        &Context_DiveMainMenu_DIVEMENU,
        &Context_DiveMainMenu_SLATES,
    }
};
static const listItemInMenu_ts DiveMainMenu_GAUGE_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveMainMenu_TMTSWITCH,
        &Context_DiveMainMenu_RESETAVGDEPTH,
        &Context_DiveMainMenu_BRIGHTNESS,
        &Context_DiveMainMenu_DIVEPROFILEGRAPH,
        &Context_DiveMainMenu_SLATES,
    }
};
const listItemInMenu_ts* DiveMainMenu_ListOfContext[DIVEMODE_MAX] =
{
    &DiveMainMenu_CC_Context,/*CC*/
    &DiveMainMenu_OC_Context,/*OC*/
    &DiveMainMenu_OC_Context,/*SM*/
    &DiveMainMenu_GAUGE_Context,/*GAUGE*/
    &DiveMainMenu_GAUGE_Context,/*GAUGE SM*/
    &DiveMainMenu_BO_Context,/*BO*/
};
