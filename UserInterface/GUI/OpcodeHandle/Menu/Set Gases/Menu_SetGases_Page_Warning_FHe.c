/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

void IniOrClrScrFunc_S79_SET_GAS_FHE_WARNING(void)
{
    /*Clear the screen*/
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    ClearUnusedInList(0);
    /**/
    GUI_SetColor(GUI_RED);
    SetFont_4;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_FHE_WARNING_1), PosX_Center, 50);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_FHE_WARNING_2), PosX_Center, 85);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_FHE_WARNING_3), PosX_Center, 120);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
