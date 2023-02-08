/******************************************************************************/
//File: Device settings
//Description: handle the Device settings page
//Created by:DucThinh
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"

void UpdPorFunc_S128_DEVICE_TRANSMITTERS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_TRANSMITTERS);
}
void UpdPorFunc_S137_DEVICE_UNITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_UNITS);
}
void UpdPorFunc_S139_DEVICE_WATERTYPE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_WATERTYPE);
}
void UpdPorFunc_S141_DEVICE_SAMPLERATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_SAMPLERATE);
}
void UpdPorFunc_S143_DEVICE_BLUETOOTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_BLUETOOTH);
}
void UpdPorFunc_TBD_DEVICE_RESETSETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_RESETSETTINGS);
}
void UpdPorFunc_TBD_DEVICE_WELCOMESCREEN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DeviceSett_WELCOMESCREEN);
}
void HandlePreOCFunc_S128_DEVICE_TRANSMITTERS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_TRANSMITTERS);
}
void HandlePreOCFunc_S137_DEVICE_UNITS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_UNITS);
}
void HandlePreOCFunc_S139_DEVICE_WATERTYPE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_WATERTYPE);
}
void HandlePreOCFunc_S141_DEVICE_SAMPLERATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_SAMPLERATE);
}
void HandlePreOCFunc_S143_DEVICE_BLUETOOTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_BLUETOOTH);
}
void HandlePreOCFunc_TBD_DEVICE_RESETSETTINGS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_RESETSETTINGS);
}
void HandlePreOCFunc_TBD_DEVICE_WELCOMESCREEN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DeviceSett_WELCOMESCREEN);
}
void IniOrClrScrFunc_S128_DEVICE_TRANSMITTERS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_TRANSMITTERS, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S137_DEVICE_UNITS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_UNITS, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S141_DEVICE_SAMPLERATE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_SAMPLERATE, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S143_DEVICE_BLUETOOTH(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_BLUETOOTH, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_TBD_DEVICE_RESETSETTINGS(void)
{
    ClearPortionToUpdateDiveMode();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_RESETSETTINGS, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_TBD_DEVICE_WELCOMESCREEN(void)
{
    ClearPortionToUpdateDiveMode();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_WELCOMESCREEN, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S139_DEVICE_WATERTYPE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DEVICE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DeviceSett_WATERTYPE, DeviceSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}