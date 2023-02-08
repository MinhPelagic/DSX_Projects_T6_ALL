/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "ContextCompassMenuCfg.h"

void IniOrClrScrFunc_C9_COMPASS_PROCESSING(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_CYAN);
    GUI_Clear();
    /**/
    SetFont_3;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_ROTATE_UNTIL_BEEP_1), PosX_Center, 40);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_ROTATE_UNTIL_BEEP_2), PosX_Center, 80);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_ROTATE_UNTIL_BEEP_3), PosX_Center, 120);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
/*Calibration PASSED*/
void IniOrClrScrFunc_C10_COMPASS_CALIBRATION_PASSED(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_GREEN);
    GUI_Clear();
    /**/
    SetFont_4;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_READY), PosX_Center, 60);
    SetFont_3;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_PASSED_CALIBRATION), PosX_Center, 130);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
/*Calibration FAILED*/
void IniOrClrScrFunc_C11_COMPASS_CALIBRATION_FAILED(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_RED);
    GUI_Clear();
    /**/
    SetFont_4;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_FAILED), PosX_Center, 60);
    SetFont_3;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_CALIBRATE_AGAIN), PosX_Center, 130);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
