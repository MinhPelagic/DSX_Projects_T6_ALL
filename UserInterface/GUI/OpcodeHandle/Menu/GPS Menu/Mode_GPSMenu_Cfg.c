/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"

static const listItemInMenu_ts GPSMenu_Context=
{
    3,/*Number of items*/
    {
        &Context_GPSMenu_SAVECURRENTLOCATION,
        &Context_GPSMenu_WAYFINDER,
        &Context_GPSMenu_DELETELOCATION,
    }
};
const listItemInMenu_ts* GPSMenuListOfContext[DIVEMODE_MAX] =
{
    &GPSMenu_Context,/*CC*/
    &GPSMenu_Context,/*OC*/
    &GPSMenu_Context,/*SM*/
    &GPSMenu_Context,/*GAUGE*/
    &GPSMenu_Context,/*GAUGE SM*/
    &GPSMenu_Context,/*BO*/
};
