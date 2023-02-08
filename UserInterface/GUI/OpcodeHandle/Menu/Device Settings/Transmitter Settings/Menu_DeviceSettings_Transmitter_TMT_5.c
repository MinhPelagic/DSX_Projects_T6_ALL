/******************************************************************************/
//File: Menu_DeviceSettings_Transmitter_TMT_5
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextDeviceSettingsCfg.h"
#include "../Menu_DeviceSettings.h"

void IniOrClrScrFunc_TMT_5_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title("TMT 5");
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_TMT_5_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Ctx);
}
/*Set Serial number TMT_5*/
void IniOrClrScrFunc_SET_TMT_5_DIGIT_1(void)
{
    ClearUnusedInList(3);
    /*Display the SN Text*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_SN_Text_Ctx);
    /*Digits number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_2_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_3_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_4_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_5_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_6_Ctx);
}
/*Digit 1*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_1(void)
{
    /*Flashing the SN 1 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_1_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_1(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_1_Ctx);
}
/*Digit 2*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_2(void)
{
    /*Flashing the SN 2 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_2_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_2(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_2_Ctx);
}
/*Digit 3*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_3(void)
{
    /*Flashing the SN 3 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_3_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_3(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_3_Ctx);
}
/*Digit 4*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_4(void)
{
    /*Flashing the SN 4 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_4_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_4(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_4_Ctx);
}
/*Digit 5*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_5(void)
{
    /*Flashing the SN 5 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_5_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_5(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_5_Ctx);
}
/*Digit 6*/
void UpdOrFlasFunc_SET_TMT_5_DIGIT_6(void)
{
    /*Flashing the SN 6 digit*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Transmitt_TMT_5_Digit_6_Ctx);
}
void HandlePreOCFunc_SET_TMT_5_DIGIT_6(void)
{
    /*Every time flashing next digit -> Redraw this digit because it will disappear when flashing*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Transmitt_TMT_5_Digit_6_Ctx);
}
