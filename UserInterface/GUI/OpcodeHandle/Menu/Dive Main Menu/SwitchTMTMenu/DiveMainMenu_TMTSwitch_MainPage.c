/******************************************************************************/
// File: TMT Switch
// Description:
//
/*****************************************************************************/
#include "../DiveMainMenu.h"
#include "../../Main Menu/Main_Menu_TMT_SWITCH/Menu_MainMenu_TMTSwitch.h"

/*TMT Swich*/
void IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH_SET(void)
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
    /*Top Right Depth*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveMainMenu_TMTDepth_TopRight_Ctx);
}
void UpdOrFlasFunc_DIVEMAINMENU_TMTSWITCH_SET(void)
{
    /*keep display base on status of current highlight TMT*/
    HandleDisplayItemMdev(TMTSwitch_Bottom_Content);
    /*Top Right Depth*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveMainMenu_TMTDepth_TopRight_Ctx);
}
