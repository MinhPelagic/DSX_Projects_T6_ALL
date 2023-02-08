/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
static const listItemInMenu_ts MainMenu_Info_MenuList_CC=
{
    4,/*Number of items*/
    {
        &Context_InfoMenu_MYINFO,
        &Context_InfoMenu_DSXINFO,
        &Context_InfoMenu_HISTORY,
        &Context_InfoMenu_MANUFACTURER,
    }
};
const listItemInMenu_ts* MainMenu_Info_ListOfContext[DIVEMODE_MAX] =
{
    &MainMenu_Info_MenuList_CC,
    &MainMenu_Info_MenuList_CC,
    &MainMenu_Info_MenuList_CC,
    &MainMenu_Info_MenuList_CC,
    &MainMenu_Info_MenuList_CC,
    &MainMenu_Info_MenuList_CC,/*BO*/
};
