/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"
void displaysubInitialSetGasPage(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
    SetGasMenu_DispSlash();
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_01(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_01)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_01_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_02(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_02)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_02_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_03(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_03)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_03_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_04(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_04)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_04_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_04_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_05(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_05)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_05_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_05_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S73_SET_GAS_FHe_06(void)
{
    displaysubInitialSetGasPage();
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_06)));
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_06_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_06_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S73_SET_GAS_FHe_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_01_Ctx);
}
void UpdPorFunc_S73_SET_GAS_FHe_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_02_Ctx);
}
void UpdPorFunc_S73_SET_GAS_FHe_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_03_Ctx);
}
void UpdPorFunc_S73_SET_GAS_FHe_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_04_Ctx);
}
void UpdPorFunc_S73_SET_GAS_FHe_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_05_Ctx);
}
void UpdPorFunc_S73_SET_GAS_FHe_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_06_Ctx);
}
/**/
void UpdOrFlasFunc_S73_SET_GAS_FHe_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_01_Ctx);
}
void UpdOrFlasFunc_S73_SET_GAS_FHe_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_02_Ctx);
}
void UpdOrFlasFunc_S73_SET_GAS_FHe_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_03_Ctx);
}
void UpdOrFlasFunc_S73_SET_GAS_FHe_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_04_Ctx);
}
void UpdOrFlasFunc_S73_SET_GAS_FHe_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_05_Ctx);
}
void UpdOrFlasFunc_S73_SET_GAS_FHe_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFHe_06_Ctx);
}
/**/
