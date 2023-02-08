/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGasSwitchCfg.h"
#include "Menu_GasSwitch.h"
#include "../Set Gases/Menu_SetGases.h"
#include "../Set Gases/ContextSetGasesCfg.h"
/*
GAS SWITCH context handling
u8_GasValue : 1...6
*/
void Handle_Context_List_GASSWITCH(ItemStatus_te _Status, int Pos, gasSwitchItemContext_ts gasSwitchContext)
{
    char strRet[LangMaxLength];
    /*Set color base on the staus of Status*/
    SetFont_3;
    GUI_SetBkColor(GUI_BLACK);
    hMemDev_DisplayNum = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDev_DisplayNum);
    GUI_ClearRect(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (Pos*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
    GUI_SetColor((IteStat_UnSelect == _Status) ? TxtColor_UnSelect : TxtColor_Select);
    /*Display the MM-#*/
    if(ENABLE_DISPLAY==gasSwitchContext.flagDispLeft)
    {
        GUI_SetTextAlign(GUI_TA_LEFT);
        gasSwitchContext.LeftStr(strRet);
        GUI_DispStringAt(strRet, Pos_Item_Select_List->X0, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    if(ENABLE_DISPLAY==gasSwitchContext.flagDispMiddle_01)
    {
        /*GAS SWITCH - # status ON/OFF/SET*/
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*Get the status of GAS#*/
        gasSwitchContext.Middle_01(strRet);
        GUI_DispStringAt(strRet, Point_MainMenu_GasSwitch_STATUS->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    if(ENABLE_DISPLAY==gasSwitchContext.flagDispMiddle_02)
    {
        /*GAS SWITCH value FO2/PO2*/
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*Get the vlue FO2/PO2*/
        gasSwitchContext.Middle_02(strRet);
        GUI_DispStringAt(strRet, Point_MainMenu_GasSwitch_FO2Val->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    if(ENABLE_DISPLAY==gasSwitchContext.flagDispRight)
    {
        /*PO2 Value*/
        GUI_SetColor(gasSwitchContext.colorDispRight(gasSwitchContext.gasNumId)); //Base on the gas value, set the  color
        GUI_SetTextAlign(GUI_TA_RIGHT);
        gasSwitchContext.RightStr(strRet, gasSwitchContext.gasNumId);
        GUI_DispStringAt(strRet, Pos_Item_Select_List->X1, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    CopyFromMemDevToLCD
}
/*Mode config*/
/*Go to set bottom content*/
const contentDispContext_st GasSwitch_MaxOfDepth =
{
    &GasSwitch_Bottom_MOD_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
/*CANNOT SWITCH GAS bottom content*/
const contentDispContext_st GasSwitchBottom_PO2TooLowLine0 =
{
    &GasSwitch_Bottom_CannotSwitchLine0_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
const contentDispContext_st GasSwitchBottom_PO2TooLowLine1 =
{
    &GasSwitch_Bottom_CannotSwitchLine1_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_2,
};
/*WARNING! PO2>1.60 bottom content*/
const contentDispContext_st GasSwitchBottom_WarningPO2TooHigh_Line0 =
{
    &GasSwitch_Bottom_PO2HigherThan_1p6_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
const contentDispContext_st GasSwitchBottom_WarningPO2TooHigh_Line1 =
{
    &GasSwitch_Bottom_MOD_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_2,
};
/*WARNING! HYPOXIC GAS. bottom content*/
const contentDispContext_st GasSwitchBottom_PO2Hypoxic =
{
    &GasSwitch_Hypoxic_Bottom_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
/*ICD bottom content*/
const contentDispContext_st GasSwitch_WarningIsoBaric =
{
    &GasSwitch_ICD_Bottom_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
/*Link TMT*/
const contentDispContext_st GasSwitchBottom_TMTLink =
{
    &GasSwitchBottom_TMTLink_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};
/*Tank OFF*/
const contentDispContext_st GasSwitchBottom_GasOFF =
{
    &GasSwitchBottom_GasOFF_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_GasSwitch_BottomLine_1,
};

/*Depth Display In Menu*/
const contentDispContext_st Depth_In_Menu =
{
    &Depth_In_Menu_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_Depth_In_Menu,
};

/*Config context switch GAS*/
const gasSwitchItemContext_ts SwGas_GAS_01 =
{
    SetGASES_Index_01,
    ENABLE_DISPLAY,
    &SetGases_Row_01_Context_Left, //Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_01_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_01_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};
const gasSwitchItemContext_ts SwGas_GAS_02 =
{
    SetGASES_Index_02,
    ENABLE_DISPLAY,
    &SetGases_Row_02_Context_Left,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_02_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_02_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};
const gasSwitchItemContext_ts SwGas_GAS_03 =
{
    SetGASES_Index_03,
    ENABLE_DISPLAY,
    &SetGases_Row_03_Context_Left,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_03_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_03_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};
const gasSwitchItemContext_ts SwGas_GAS_04 =
{
    SetGASES_Index_04,
    ENABLE_DISPLAY,
    &SetGases_Row_04_Context_Left,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_04_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_04_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};
const gasSwitchItemContext_ts SwGas_GAS_05 =
{
    SetGASES_Index_05,
    ENABLE_DISPLAY,
    &SetGases_Row_05_Context_Left,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_05_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_05_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};

const gasSwitchItemContext_ts SwGas_GAS_06 =
{
    SetGASES_Index_06,
    ENABLE_DISPLAY,
    &SetGases_Row_06_Context_Left,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_06_Context_Middle_01,//Reuse
    ENABLE_DISPLAY,
    &SetGases_Row_06_Context_Middle_02,//Reuse
    ENABLE_DISPLAY,
    &GasSwitch_ColorDispRight,
    &GasSwitchPO2Str,
};


const gasSwitchItemContext_ts* GasSwitchListCfg[GasSwitchNum_MAX]=
{
    &SwGas_GAS_01, /*CC-1*/
    &SwGas_GAS_02, /*CC-2*/
    &SwGas_GAS_03, /*CC-3*/
    &SwGas_GAS_04, /*CC-4*/
    &SwGas_GAS_05, /*CC-5*/
    &SwGas_GAS_06, /*CC-6*/
};
