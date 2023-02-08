/******************************************************************************/
//File: SET MENU -> GPS Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGPSMenuCfg.h"

static const listItemInMenu_ts WayFinder_Context=
{
    2,/*Number of items*/
    {
        &Context_WayFinder_EXITFROMWAYFINDER,
        &Context_WayFinder_CHANGETARGETLOCATION,
    }
};
const listItemInMenu_ts* WayFinderListOfContext[DIVEMODE_MAX] =
{
    &WayFinder_Context,/*CC*/
    &WayFinder_Context,/*OC*/
    &WayFinder_Context,/*SM*/
    &WayFinder_Context,/*GAUGE*/
    &WayFinder_Context,/*GAUGE SM*/
    &WayFinder_Context,/*BO*/
};
