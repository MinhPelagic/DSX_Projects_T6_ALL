/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "ContextCompassMenuCfg.h"
/*CALIBRATION*/
void IniOrClrScrFunc_C7_COMPASS_CALIBRATION(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_COMPASS_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_CompassMenu_CALIBRATE, CompassMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_C7_COMPASS_CALIBRATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_CompassMenu_CALIBRATE);
}
void HandlePreOCFunc_C7_COMPASS_CALIBRATION(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_CompassMenu_CALIBRATE);
}
/*DICLITION*/
void IniOrClrScrFunc_C13_COMPASS_DECLIN_SET(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_COMPASS_MENU));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_CompassMenu_SET_DECLIN, CompassMenu_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_C13_COMPASS_DECLIN_SET(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_CompassMenu_SET_DECLIN);
}
void HandlePreOCFunc_C13_COMPASS_DECLIN_SET(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_CompassMenu_SET_DECLIN);
}
