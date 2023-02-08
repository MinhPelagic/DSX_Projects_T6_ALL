#ifndef __MENU_MAINMENU_INFO__
#define __MENU_MAINMENU_INFO__
/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
/*List of menu*/
enum
{
    MainMenu_Info_MYINFO,
    MainMenu_Info_DSXINFO,
    MainMenu_Info_HISTORY,
    MainMenu_Info_MAX,
};
extern const listItemInMenu_ts* MainMenu_Info_ListOfContext[DIVEMODE_MAX];
#endif
