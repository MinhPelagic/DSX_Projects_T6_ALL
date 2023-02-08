/******************************************************************************/
//File: TMT Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_TMTSwitch.h"
/*TMT Swich*/
void IniOrClrScrFunc_TMTSWITCH_TMT_SET(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TMT_SWITCH));
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    /*
    Display the dynamic list: The actual TMT and TMTthat are set OFF shall not be listed.
    */
    TMTSwitchMenu_DisplayAllThe_PossibleTMT();
    /*Current TMT status*/
    HandleDisplayItemMdev(TMTSwitch_Bottom_Content);
}
void UpdOrFlasFunc_TMTSWITCH_TMT_SET(void)
{
    /*keep display base on status of current highlight TMT*/
    HandleDisplayItemMdev(TMTSwitch_Bottom_Content);
}
