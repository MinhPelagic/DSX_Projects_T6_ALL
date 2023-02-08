/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"
#include "../../../../ButtonHandle/DSX_ButtonHandle.h"

void SetGasMenu_DispSlash(void)
{
    /*Then display the slash*/
    GUI_SetColor(TxtColor_Select);
    GUI_SetFont(&FontAaux_6);
    GUI_DispStringHCenterAt("/", Point_SetGas_Slash->x, Point_SetGas_Slash->y);
}
/*Check display subtitile in specific mode*/
void checkDispTheTittle(unsigned char gasNumber)
{
    switch(DIVE_MODE)
    {
    case NVD_MDSM:
        /*Specific with SM display, because it not go to ON/OFF page then need to  clear and reinitial display*/
        ClearUnusedInList(0);
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_GASES));
        DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, gasNumber)));
        break;
    default:
        /*only clear the previous setting ON/OFF*/
        HandleDisplayTextWithMemdev(IteStat_Clear, Set_SetGases_01_Ctx);
        break;
    }
    /*Display init slash*/
    SetGasMenu_DispSlash();
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_01(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_01)));
    checkDispTheTittle(SetGASES_01);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_01_Ctx);
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_02(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_02)));
    checkDispTheTittle(SetGASES_02);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_02_Ctx);
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_03(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_03)));
    checkDispTheTittle(SetGASES_03);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_03_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_03_Ctx);
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_04(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_04)));
    checkDispTheTittle(SetGASES_04);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_04_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_04_Ctx);
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_05(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_05)));
    checkDispTheTittle(SetGASES_05);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_05_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_05_Ctx);
}
void IniOrClrScrFunc_S72_SET_GAS_FO2_06(void)
{
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_06)));
    checkDispTheTittle(SetGASES_06);
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_06_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFHe_06_Ctx);
}

/*----------------------------------------------------------------*/
void UpdOrFlasFunc_S72_SET_GAS_FO2_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_01_Ctx);
}
void UpdOrFlasFunc_S72_SET_GAS_FO2_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_02_Ctx);
}
void UpdOrFlasFunc_S72_SET_GAS_FO2_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_03_Ctx);
}
void UpdOrFlasFunc_S72_SET_GAS_FO2_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_04_Ctx);
}
void UpdOrFlasFunc_S72_SET_GAS_FO2_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_05_Ctx);
}
void UpdOrFlasFunc_S72_SET_GAS_FO2_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetGases_SetFO2_06_Ctx);
}
/*----------------------------------------------------------------*/
void HandlePreOCFunc_S72_SET_GAS_FO2_01(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_01_Ctx);
}
void HandlePreOCFunc_S72_SET_GAS_FO2_02(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_02_Ctx);
}
void HandlePreOCFunc_S72_SET_GAS_FO2_03(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_03_Ctx);
}
void HandlePreOCFunc_S72_SET_GAS_FO2_04(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_04_Ctx);
}
void HandlePreOCFunc_S72_SET_GAS_FO2_05(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_05_Ctx);
}
void HandlePreOCFunc_S72_SET_GAS_FO2_06(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetGases_SetFO2_06_Ctx);
}