/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

void IniOrClrScrFunc_S71_SET_GAS_STAT_01(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_01)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_01_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void IniOrClrScrFunc_S71_SET_GAS_STAT_02(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_02)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_02_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void IniOrClrScrFunc_S71_SET_GAS_STAT_03(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_03)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void IniOrClrScrFunc_S71_SET_GAS_STAT_04(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_04)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_04_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void IniOrClrScrFunc_S71_SET_GAS_STAT_05(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_05)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_05_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void IniOrClrScrFunc_S71_SET_GAS_STAT_06(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_06)));
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_06_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*----------------------------------------------------------------*/
void UpdOrFlasFunc_S71_SET_GAS_STAT_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_01_Ctx);
}
void UpdOrFlasFunc_S71_SET_GAS_STAT_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_02_Ctx);
}
void UpdOrFlasFunc_S71_SET_GAS_STAT_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_03_Ctx);
}
void UpdOrFlasFunc_S71_SET_GAS_STAT_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_04_Ctx);
}
void UpdOrFlasFunc_S71_SET_GAS_STAT_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_05_Ctx);
}
void UpdOrFlasFunc_S71_SET_GAS_STAT_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_06_Ctx);
}
