#include "L4X9_includes.h"

/*Line 0*/
static void MainMenu_Slates_ResetAvgDepth_Line_0_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESET_AVG_DEPTH_0));
}
const contentDispContext_st MainMenu_Slates_ResetAvgDepth_Line_0 =
{
    &MainMenu_Slates_ResetAvgDepth_Line_0_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
/*Line 1*/
static void MainMenu_Slates_ResetAvgDepth_Line_1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESET_AVG_DEPTH_1));
}
const contentDispContext_st MainMenu_Slates_ResetAvgDepth_Line_1 =
{
    &MainMenu_Slates_ResetAvgDepth_Line_1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
/*Line 2*/
static void MainMenu_Slates_ResetAvgDepth_Line_2_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RESET_SETTING_4));
}
const contentDispContext_st MainMenu_Slates_ResetAvgDepth_Line_2 =
{
    &MainMenu_Slates_ResetAvgDepth_Line_2_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};

void IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH_SET(void)
{
    GUI_Clear();
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ResetAvgDepth_Line_0);
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ResetAvgDepth_Line_1);
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ResetAvgDepth_Line_2);
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
