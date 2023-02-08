/******************************************************************************/
//File: GTR left and right
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_MAINDISPLAY_RIGHT_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text YEAR*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_3rd_ROW_RIGHT));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_MainDisp_3rdRowRight_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_MAINDISPLAY_RIGHT_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_MainDisp_3rdRowRight_Ctx);
}

/*
enum {
    _3rdRowSet_BLANK,
    _3rdRowSet_O2SAT,
    _3rdRowSet_GF,
    _3rdRowSet_CEILING,
    _3rdRowSet_MAXDEPTH,
    _3rdRowSet_AVGDEPTH,
    _3rdRowSet_TIME,
    _3rdRowSet_DIL_PO2,
    _3rdRowSet_FiO2,
    _3rdRowSet_GTR,
    _3rdRowSet_MAX,
};
*/
void Check3rdRowAfterDiveModeSwitch(void)
{
    if(CC_MODE)
    {
        if(MAIN_CC_3RD_ROW_LEFT == _3rdRowSet_GTR)
            MAIN_CC_3RD_ROW_LEFT = _3rdRowSet_BLANK;

        if(MAIN_CC_3RD_ROW_RIGHT == _3rdRowSet_GTR)
            MAIN_CC_3RD_ROW_RIGHT = _3rdRowSet_BLANK;

        GUI_MAINDISPLAY_3RD_ROW_LEFT = MAIN_CC_3RD_ROW_LEFT;
        GUI_MAINDISPLAY_3RD_ROW_RIGHT = MAIN_CC_3RD_ROW_RIGHT;

    }
    else if(OC_MODE)
    {
        if((MAIN_OC_3RD_ROW_LEFT == _3rdRowSet_DIL_PO2)||(MAIN_OC_3RD_ROW_LEFT == _3rdRowSet_FiO2))
            MAIN_OC_3RD_ROW_LEFT = _3rdRowSet_BLANK;

        if((MAIN_OC_3RD_ROW_RIGHT == _3rdRowSet_DIL_PO2)||(MAIN_OC_3RD_ROW_RIGHT == _3rdRowSet_FiO2))
            MAIN_OC_3RD_ROW_RIGHT = _3rdRowSet_BLANK;


        GUI_MAINDISPLAY_3RD_ROW_LEFT = MAIN_OC_3RD_ROW_LEFT;
        GUI_MAINDISPLAY_3RD_ROW_RIGHT = MAIN_OC_3RD_ROW_RIGHT;
    }
    else if(SM_MODE)
    {
        GUI_MAINDISPLAY_3RD_ROW_LEFT = MAIN_SM_3RD_ROW_LEFT;
        GUI_MAINDISPLAY_3RD_ROW_RIGHT = MAIN_SM_3RD_ROW_RIGHT;
    }
}