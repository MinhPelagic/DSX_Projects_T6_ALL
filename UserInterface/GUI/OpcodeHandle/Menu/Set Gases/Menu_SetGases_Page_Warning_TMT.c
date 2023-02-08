

/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

void IniOrClrScrFunc_S75_SET_GAS_TMT_WARNING(void)
{
    char str_ret[LangMaxLength];

    //unsigned char selectTank = 0;
    NVD_DIVEMODE_t DiveMode_Bakup = GUI_DIVE_Mode;
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_YELLOW);
    GUI_Clear();
    /*Set value*/
    //selectTank = GUI_ShowTankNum - 1; /*Current tank on selected*/
    SetFont_3;
    /*TMT-x*/
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(GUI_ShowTankNum)]), PosX_Center, 0);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_IS_ALREADY_LINKED_TO), PosX_Center, 35);
    /*FO2/PO2 value*/
    GUI_DIVE_Mode = TMT_LINKED_MODE;
    sprintf(str_ret, "%s %d/%.2d", GUI_LANG_GetText(SetGasGetMode(TMT_LINKED_MODE, TMT_LINKED_GAS_INDEX)), SetGasGetFO2(TMT_LINKED_GAS_INDEX), SetGasGetFHe(TMT_LINKED_GAS_INDEX));
    GUI_DIVE_Mode = DiveMode_Bakup;
    //
    GUI_DispStringHCenterAt(str_ret, PosX_Center, 70);
    sprintf(str_ret, "%s %s",  GUI_LANG_GetText(TxtStr_IF_YOU_LINK_IT_TO), GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, GUI_ShowTankNum)));
    GUI_DispStringHCenterAt(str_ret, PosX_Center, 105);
    sprintf(str_ret, "%s %s", GUI_LANG_GetText(SetGasGetMode(TMT_LINKED_MODE, TMT_LINKED_GAS_INDEX)), GUI_LANG_GetText(TxtStr_WILL_BE_SET_TO));
    GUI_DispStringHCenterAt(str_ret, PosX_Center, 140);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_NO_TMT), PosX_Center, 175);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}

