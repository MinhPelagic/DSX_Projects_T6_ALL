
#include "L4X9_includes.h"
#include "../ContextDeviceSettingsCfg.h"
#include "../Menu_DeviceSettings.h"
#include "Menu_DeviceSettings_Transmitter_Cfg.h"
static void TMTBatteryStatus(TMT_NUM_t n)
{
    /*TMT Battery status*/
    switch(GUI_TMT_Battery[n])
    {
    case TMT_SEARCHING:
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SEARCHING_TXT);
        break;
    case TMT_BATT_LOW:
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_BATTLOW_TXT);
        break;
    case TMT_BATT_GOOD:
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_BATTGOOD_TXT);
        break;
    default:
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_NOTAVAILABE_TXT);
        break;
    }
}
/*TMT 1 SET*/
void IniOrClrScrFunc_S128_TM_TMT1(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_1, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT1();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT1(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_1);
    UpdOrFlasFunc_S128_TM_TMT1();
}
void HandlePreOCFunc_S128_TM_TMT1(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_1);
}
void UpdOrFlasFunc_S128_TM_TMT1(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_1_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_1_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_1_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
/*TMT 2 SET*/
void IniOrClrScrFunc_S128_TM_TMT2(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_2, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT1();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT2(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_2);
    UpdOrFlasFunc_S128_TM_TMT2();
}
void HandlePreOCFunc_S128_TM_TMT2(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_2);
}
void UpdOrFlasFunc_S128_TM_TMT2(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_2_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_2_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_2_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
/*TMT 3 SET*/
void IniOrClrScrFunc_S128_TM_TMT3(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_3, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT3();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT3(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_3);
    UpdOrFlasFunc_S128_TM_TMT3();
}
void HandlePreOCFunc_S128_TM_TMT3(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_3);
}
void UpdOrFlasFunc_S128_TM_TMT3(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_3_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_3_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_3_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
/*TMT 4 SET*/
void IniOrClrScrFunc_S128_TM_TMT4(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_4, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT4();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT4(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_4);
    UpdOrFlasFunc_S128_TM_TMT4();
}
void HandlePreOCFunc_S128_TM_TMT4(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_4);
}
void UpdOrFlasFunc_S128_TM_TMT4(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_4_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_4_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_4_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
/*TMT 5 SET*/
void IniOrClrScrFunc_S128_TM_TMT5(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_5, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT5();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT5(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_5);
    UpdOrFlasFunc_S128_TM_TMT5();
}
void HandlePreOCFunc_S128_TM_TMT5(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_5);
}
void UpdOrFlasFunc_S128_TM_TMT5(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_5_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_5_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_5_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
/*TMT 6 SET*/
void IniOrClrScrFunc_S128_TM_TMT6(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_TRANSMITTERS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_Transmitters_TMT_6, Transmiters_ListOfContext);
    UpdOrFlasFunc_S128_TM_TMT6();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S128_TM_TMT6(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_Transmitters_TMT_6);
    UpdOrFlasFunc_S128_TM_TMT6();
}
void HandlePreOCFunc_S128_TM_TMT6(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_Transmitters_TMT_6);
}
void UpdOrFlasFunc_S128_TM_TMT6(void)
{
    /*Passcode number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_6_PassCodeNumber);
    /*TMT Pressure*/
    if(GUI_TMT_Status[GUI_TMT_Num_InSetting]==NVD_ON)
    {
        /*Passcode text*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Transmitters_TMT_SERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Select, Transmitters_TMT_6_Pressure);
    }
    else
    {
        /*Passcode text flashing*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Transmitters_TMT_SETSERIAL_Text);
        /*Pressure*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Transmitters_TMT_6_Pressure);
    }
    /*TMT Battery status*/
    TMTBatteryStatus(GUI_TMT_Num_InSetting);
}
