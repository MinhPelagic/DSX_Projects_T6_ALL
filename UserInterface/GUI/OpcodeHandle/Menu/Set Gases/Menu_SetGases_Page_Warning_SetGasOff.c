/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

void IniOrClrScrFunc_S77_ACTUAL_GAS_WARNING(void)
{
    /*Clear the screen*/
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    ClearUnusedInList(0);
    /**/
    SetFont_4;
    GUI_SetColor(GUI_RED);
    if(BO_MODE)
    {
        GUI_DispStringHCenterAt("BO-1 GAS", PosX_Center, 50);
    }
    else
        GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_THE_ACTUAL_GAS), PosX_Center, 50);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_CANNOT_BE_SET), PosX_Center, 85);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_OFF), PosX_Center, 120);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_D41_ACTUAL_GAS_WARNING(void)
{
    /*Clear the screen*/
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    ClearUnusedInList(0);
    /**/
    SetFont_4;
    GUI_SetColor(GUI_RED);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_THE_ACTUAL_GAS), PosX_Center, 50);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_CANNOT_BE_SET), PosX_Center, 85);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_UNDERWATER_1), PosX_Center, 120);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_UNDERWATER_2), PosX_Center, 155);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
