/******************************************************************************/
//File: Device settings -> Reset settings
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"

void IniOrClrScrFunc_RESETSETTINGS_S1(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_YELLOW);
    GUI_Clear();
    SetFont_4;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_RESET_SETTING_1), PosX_Center, 20);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_RESET_SETTING_2), PosX_Center, 55);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_RESET_SETTING_4), PosX_Center, 175);
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_RESET_SETTING_3), PosX_Center, 90);
    Display_Icon_Buttons(IconBottDisp_CancelHomeSelect);
}
void IniOrClrScrFunc_RESETSETTINGS_S2(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_YELLOW);
    GUI_Clear();
    SetFont_4;
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_SETTING_RESET_1), PosX_Center, (PosY_Center-35));
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_SETTING_RESET_2), PosX_Center, (PosY_Center-0));
    Display_Icon_Buttons(IconBottDisp_HomeSelect);
}