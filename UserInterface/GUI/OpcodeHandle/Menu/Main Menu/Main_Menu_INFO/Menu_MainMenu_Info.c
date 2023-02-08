/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"
/*MY INFO*/
void IniOrClrScrFunc_S187_IM_MYINFO(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_INFOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_InfoMenu_MYINFO, MainMenu_Info_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S187_IM_MYINFO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_InfoMenu_MYINFO);
}
void HandlePreOCFunc_S187_IM_MYINFO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_InfoMenu_MYINFO);
}
/*DSX INFO*/
void IniOrClrScrFunc_S190_IM_DSXINFO(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_INFOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_InfoMenu_DSXINFO, MainMenu_Info_ListOfContext);
}
void UpdPorFunc_S190_IM_DSXINFO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_InfoMenu_DSXINFO);
}
void HandlePreOCFunc_S190_IM_DSXINFO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_InfoMenu_DSXINFO);
}
/*HISTORY*/
void IniOrClrScrFunc_S192_IM_HISTORY(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_INFOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_InfoMenu_HISTORY, MainMenu_Info_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S192_IM_HISTORY(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_InfoMenu_HISTORY);
}
void HandlePreOCFunc_S192_IM_HISTORY(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_InfoMenu_HISTORY);
}
/*MANUFACTURER*/
void IniOrClrScrFunc_S224_IM_MANUFACTURER(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_INFOR));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_InfoMenu_MANUFACTURER, MainMenu_Info_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S224_IM_MANUFACTURER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_InfoMenu_MANUFACTURER);
}
void HandlePreOCFunc_S224_IM_MANUFACTURER(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_InfoMenu_MANUFACTURER);
}
