#ifndef _MENU_GAS_SWITCH_CFG
#define _MENU_GAS_SWITCH_CFG
/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"

typedef GUI_COLOR (*pSetColorGasSwFunc)(unsigned char);
typedef void (*pGasSwitchPO2Str)(char*, unsigned char);
/*
When flag_x display is true/enable -> Call the function contextS
Otherwise -> Do nothing
*/
typedef struct
{
    /*Gas ID (1, 2, 3, 4, 5)*/
    unsigned char gasNumId;
    /*Left Content*/
    unsigned char flagDispLeft;
    pstrHandle_Func LeftStr;
    /*Middle 1 Content*/
    unsigned char flagDispMiddle_01;
    pstrHandle_Func Middle_01;
    /*Middle 2 Content*/
    unsigned char flagDispMiddle_02;
    pstrHandle_Func Middle_02;
    /*Right Content*/
    unsigned char flagDispRight;
    pSetColorGasSwFunc colorDispRight; /*Set color of the PO2 (Red, Yellow, Cyan, White)*/
    pGasSwitchPO2Str RightStr;
} gasSwitchItemContext_ts;

void Handle_Context_List_GASSWITCH(ItemStatus_te _Status, int Pos, gasSwitchItemContext_ts gasSwitchContext);
extern const contentDispContext_st GasSwitch_MaxOfDepth;
extern const contentDispContext_st GasSwitchBottom_WarningPO2TooHigh_Line0;
extern const contentDispContext_st GasSwitchBottom_WarningPO2TooHigh_Line1;
extern const contentDispContext_st GasSwitchBottom_PO2Hypoxic;
extern const contentDispContext_st GasSwitchBottom_PO2TooLowLine0;
extern const contentDispContext_st GasSwitchBottom_PO2TooLowLine1;
extern const contentDispContext_st GasSwitch_WarningIsoBaric;
extern const contentDispContext_st GasSwitchBottom_TMTLink;
extern const contentDispContext_st GasSwitchBottom_GasOFF;
extern const contentDispContext_st Depth_In_Menu;
void GasSwitchBottom_TMTLink_Context(char* pStrRet);
void GasSwitchBottom_GasOFF_Context(char* pStrRet);
#endif