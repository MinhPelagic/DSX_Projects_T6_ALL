/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

void IniOrClrScrFunc_S74_SET_GAS_TMT_01(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_01)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_01_Ctx);
}
void IniOrClrScrFunc_S74_SET_GAS_TMT_02(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_02)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_02_Ctx);
}
void IniOrClrScrFunc_S74_SET_GAS_TMT_03(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_03)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_03_Ctx);
}
void IniOrClrScrFunc_S74_SET_GAS_TMT_04(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_04)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_04_Ctx);
}
void IniOrClrScrFunc_S74_SET_GAS_TMT_05(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_05)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_05_Ctx);
}
void IniOrClrScrFunc_S74_SET_GAS_TMT_06(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_06)));
    /*Display the level 3 tittle*/
    DisplayText_Setting_SubTitle(GUI_LANG_GetText(TxtStr_LINKED_TMT));
    /*Display TMT number*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_06_Ctx);
}
/*----------------------------------------------------------------*/

void UpdOrFlasFunc_S74_SET_GAS_TMT_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_01_Ctx);
}
void UpdOrFlasFunc_S74_SET_GAS_TMT_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_02_Ctx);
}
void UpdOrFlasFunc_S74_SET_GAS_TMT_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_03_Ctx);
}
void UpdOrFlasFunc_S74_SET_GAS_TMT_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_04_Ctx);
}
void UpdOrFlasFunc_S74_SET_GAS_TMT_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_05_Ctx);
}
void UpdOrFlasFunc_S74_SET_GAS_TMT_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetTMT_06_Ctx);
}
/*----------------------------------------------------------------*/
/*Check TMT status*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_01_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_1));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_01(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_1));
}
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_02_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_2));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_02(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_2));
}
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_03_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_3));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_03(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_3));
}
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_04_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_4));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_04(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_4));
}
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_05_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_5));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_05(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_5));
}
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetTMT_06_Ctx);
    /*Display TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_6));
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_06(void)
{
    /*Update TMT_Linked status (Searching/Pressure&BattStatus/NotAvailable*/
    SetGas_TMTBatteryStatus(SetGases_TMT_Num(TANK_6));
}
