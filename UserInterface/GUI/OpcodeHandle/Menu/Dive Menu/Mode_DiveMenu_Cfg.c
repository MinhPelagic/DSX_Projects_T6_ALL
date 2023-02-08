#include "L4X9_includes.h"
#include "ContextDiveMenuCfg.h"
#include "DiveMenu.h"

/*
Context Menu of Dive Menu
===============================================================================================================

===============================================================================================================
*/
static const listItemInMenu_ts DiveMenu_CC_Context=
{
    6,/*Number of items*/
    {
        &Context_DiveMenu_SETSP,
        &Context_DiveMenu_SETGASES,
        &Context_DiveMenu_DIVEPROFILEGRAPH,
        &Context_DiveMenu_BAILOUTPO2LIMITS,
        &Context_DiveMenu_DECOSTOPS,
        &Context_DiveMenu_SETGFHIGH,
    }
};
/*When set Conservative is Sport -> No display SET GF HIGH item*/
static const listItemInMenu_ts DiveMenu_CC_SetGFHighOff_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveMenu_SETSP,
        &Context_DiveMenu_SETGASES,
        &Context_DiveMenu_DIVEPROFILEGRAPH,
        &Context_DiveMenu_BAILOUTPO2LIMITS,
        &Context_DiveMenu_DECOSTOPS,
    }
};
static const listItemInMenu_ts DiveMenu_OC_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveMenu_SETGASES,
        &Context_DiveMenu_DIVEPROFILEGRAPH,
        &Context_DiveMenu_PO2LIMITS,
        &Context_DiveMenu_DECOSTOPS,
        &Context_DiveMenu_SETGFHIGH,
    }
};
/*When set Conservative is Sport -> No display SET GF HIGH item*/
static const listItemInMenu_ts DiveMenu_OC_SetGFHighOff_Context=
{
    4,/*Number of items*/
    {
        &Context_DiveMenu_SETGASES,
        &Context_DiveMenu_DIVEPROFILEGRAPH,
        &Context_DiveMenu_PO2LIMITS,
        &Context_DiveMenu_DECOSTOPS,
    }
};
const listItemInMenu_ts* DiveMenu_ListOfContext[DiveMenuSetting_Max] =
{
    &DiveMenu_CC_Context,/*Default*/
    &DiveMenu_CC_SetGFHighOff_Context,/*When set GF High is off*/
    &DiveMenu_OC_Context, /*DiveMenuSetting_OC*/
    &DiveMenu_OC_SetGFHighOff_Context, /*DiveMenuSetting_OC_SetGFHighOff*/
};
/*
Base on the Dive mode and current Conservative status (SPORT/TEC) to display correct list
*/
uint8_t DiveMenu_GetTheCurrentDisplayStatus(void)
{
    uint8_t retDispStat = DiveMenuSetting_CC;
    /*GF Alarm is ON*/
    if(CC_MODE)
    {
        if(CONSER_SETPOINTS == CONSV_TEC)
        {
            retDispStat = DiveMenuSetting_CC;
        }
        else
        {
            retDispStat = DiveMenuSetting_CC_SetGFHighOff;
        }
    }
    /*Otherwise*/
    else
    {
        if(CONSER_SETPOINTS == CONSV_TEC)
        {
            retDispStat = DiveMenuSetting_OC; //This applied to OC/SM/GAUGESM/GAUGE
        }
        else
        {
            retDispStat = DiveMenuSetting_OC_SetGFHighOff; //This specific to OC/SM/GAUGESM/GAUGE
        }
    }
    return retDispStat;
}
