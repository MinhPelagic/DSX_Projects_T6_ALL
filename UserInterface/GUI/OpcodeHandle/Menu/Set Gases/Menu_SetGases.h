/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#ifndef __MENU_SETGASES_H__
#define __MENU_SETGASES_H__

#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"

#define Pos_SetGAS_OnOff Pos_SetDateTime_DateFormat //Re used Date and Time setting	

extern const TxtStr_Name_e TxtDef_OnOffSet_Context[];
/*Set GASES*/
enum SetGASES
{
    SetGASES_01 = 0x1,
    SetGASES_02,
    SetGASES_03,
    SetGASES_04,
    SetGASES_05,
    SetGASES_06,
    SetGASES_O2_ANALYZER,
    SetGASES_MAX,
};
/*Set GASES index + 1*/
enum SetGASESIndex
{
    SetGASES_Index_01 = 0x01,
    SetGASES_Index_02,
    SetGASES_Index_03,
    SetGASES_Index_04,
    SetGASES_Index_05,
    SetGASES_Index_06,
    SetGASES_Index_O2_Analyzer,
    SetGASES_Index_Max,
};
/*
Set gas mode support
CC, OC, SM
*/
enum SetGasesMode
{
    SetGases_Mode_CC = 0x00,
    SetGases_Mode_OC,
    SetGases_Mode_SM,
    SetGases_Mode_GSM,          // not used, but keep it for memory location matching
    SetGases_Mode_GAUGE,        // not used, but keep it for memory location matching
    SetGases_Mode_BO, /*Bailout mode*/
    SetGases_Mode_MAX,
};
enum SetGasTMT
{
    SetGases_NoTMT = 0x00,
    SetGases_TMT_1,
    SetGases_TMT_2,
    SetGases_TMT_3,
    SetGases_TMT_4,
    SetGases_TMT_5,
    SetGases_TMT_6,
    SetGases_TMT_MAX,
};
void SetGasMenu_DispSlash(void);
void SetGas_TMTBatteryStatus(TMT_NUM_t n);
TxtStr_Name_e SetGasGetMode(unsigned char diveModeInput, unsigned char gasNumPos);
unsigned char SetGasGetFO2(unsigned char gasNumPos);
unsigned char SetGasGetFHe(unsigned char gasNumPos);
NVD_status_t SetGasGetSetpoint(unsigned char gasNumPos);
unsigned char SetGasGetFO2(unsigned char gasNumPos);
unsigned char SetGasGetFHe(unsigned char gasNumPos);
TMT_NUM_t SetGasGetTMTValue(unsigned char gasNumPos);
extern const TxtStr_Name_e TxtDefSetGasTMT[];
extern const TxtStr_Name_e TxtDef_OnOffSet_Context[Setting_MAX];
extern NVD_status_t GUI_SetPoints_Gas_CC[];
extern NVD_status_t GUI_SetPoints_Gas_OC[];
extern NVD_status_t GUI_SetPoints_Gas_SM[];
extern uint8_t GUI_FO2_Gas_CC[];
extern uint8_t GUI_FO2_Gas_OC[];
extern uint8_t GUI_FO2_Gas_SM[];
extern uint8_t GUI_FHe_Gas_CC[];
extern uint8_t GUI_FHe_Gas_OC[];
extern TMT_NUM_t GUI_NumOfTMT_Gas_CC[];
extern TMT_NUM_t GUI_NumOfTMT_Gas_OC[];
extern TMT_NUM_t GUI_NumOfTMT_Gas_SM[];
extern NVD_DIVEMODE_t GUI_DIVE_Mode;
extern NVD_DIVEMODE_t TMT_LINKED_MODE;
extern uint8_t TMT_LINKED_GAS_INDEX;
extern uint8_t GUI_ShowTankNum;
extern const char* TxtDef_Set_PressUnit[SetUnit_MAX];
extern const listItemInMenu_ts* SetGases_ListOfContext[DIVEMODE_MAX];
extern const listItemInMenu_ts* SetGases_DiveMode_ListOfContext[DIVEMODE_MAX];
extern const listItemInMenu_ts* SetGasesMenu_ListOfContext[DIVEMODE_MAX];
extern const contentDispContext_st Set_SetGases_01_Ctx;
extern const contentDispContext_st Set_SetGases_02_Ctx;
extern const contentDispContext_st Set_SetGases_03_Ctx;
extern const contentDispContext_st Set_SetGases_04_Ctx;
extern const contentDispContext_st Set_SetGases_05_Ctx;
extern const contentDispContext_st Set_SetGases_06_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_01_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_02_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_03_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_04_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_05_Ctx;
extern const contentDispContext_st Set_SetGases_SetFO2_06_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_01_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_02_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_03_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_04_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_05_Ctx;
extern const contentDispContext_st Set_SetGases_SetFHe_06_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_01_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_02_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_03_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_04_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_05_Ctx;
extern const contentDispContext_st Set_SetGases_SetTMT_06_Ctx;

#endif
