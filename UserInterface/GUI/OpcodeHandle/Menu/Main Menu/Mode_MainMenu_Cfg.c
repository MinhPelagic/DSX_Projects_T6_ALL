#include "L4X9_includes.h"
#include "ContextMainMenuCfg.h"
static const listItemInMenu_ts MainMenu_CC_Context=
{
    7,/*Number of items*/
    {
        &Context_MainMenu_SPSWITCH,
        &Context_MainMenu_GASSWITCH,
        &Context_MainMenu_DIVEPLANNER,
        &Context_MainMenu_LOG,
        &Context_MainMenu_SETMENU,
        &Context_MainMenu_INFOR,
        &Context_MainMenu_SLATES,
    }
};
static const listItemInMenu_ts MainMenu_OC_Context=
{
    6,/*Number of items*/
    {
        &Context_MainMenu_GASSWITCH,
        &Context_MainMenu_DIVEPLANNER,
        &Context_MainMenu_LOG,
        &Context_MainMenu_SETMENU,
        &Context_MainMenu_INFOR,
        &Context_MainMenu_SLATES,
    }
};
static const listItemInMenu_ts MainMenu_GAGUE_Context=
{
    6,/*Number of items*/
    {
        &Context_MainMenu_TMTSWITCH,
        &Context_MainMenu_LOG,
        &Context_MainMenu_SETMENU,
        &Context_MainMenu_DIVEMODE,
        &Context_MainMenu_INFOR,
        &Context_MainMenu_SLATES,
    }
};
const listItemInMenu_ts* MainMenu_ListOfContext[DIVEMODE_MAX] =
{
    &MainMenu_CC_Context,/*CC*/
    &MainMenu_OC_Context,/*OC*/
    &MainMenu_OC_Context,/*SM*/
    &MainMenu_GAGUE_Context,/*GAUGE*/
    &MainMenu_GAGUE_Context,/*GAUGE SM*/
    &MainMenu_CC_Context,/*BO*/
};
