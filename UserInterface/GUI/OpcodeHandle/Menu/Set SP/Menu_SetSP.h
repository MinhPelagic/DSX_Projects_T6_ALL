/******************************************************************************/
//File: SET SP.h
//
/*****************************************************************************/
#ifndef _MENU_SET_SP_
#define _MENU_SET_SP_
#include "L4X9_includes.h"
// Set SP Values
#define SET_SP_HIGH	            GUI_SP_HighVal    //SET SP High SP (0 ~ 160) => (0.00 ~ 1.60)
#define SET_SP_LOW                  GUI_SP_LowVal    //SET SP Low SP (0 ~ 160) => (0.00 ~ 1.60)
#define SET_SP_CUSTOM               GUI_SP_CustomVal    //SET SP CUSTOM SP (0 ~ 160) => (0.00 ~ 1.60)
#define SET_SP_AUTO_M_HIGH          GUI_SP_AutoHighMtVal        //GUI_SP_AutoHighMtVal
#define SET_SP_AUTO_FT_HIGH         GUI_SP_AutoHighFtVal        //GUI_SP_AutoHighFtVal
#define SET_SP_AUTO_M_LOW           GUI_SP_AutoLowMtVal         //GUI_SP_AutoLowMtVal
#define SET_SP_AUTO_FT_LOW          GUI_SP_AutoLowFtVal         //GUI_SP_AutoLowFtVal

#define SET_SP_MORFLG_CUSTOM        GUI_SP_CustomSwitch
#define SET_SP_MORFLG_AUTO_HIGH     GUI_SP_AutoHighSwitch
#define SET_SP_MORFLG_AUTO_LOW      GUI_SP_AutoLowSwitch
/*Setting SP SWITCH*/
enum Setting_SP_e
{
    Setting_SP_HIGHSP = 0x00,
    Setting_SP_LOWSP,
    Setting_SP_CUSTOMSP,
    Setting_SP_AUTOHIGH,
    Setting_SP_AUTOLOW,
    Setting_SP_MAX,
};
/*Extern variables for SET SP module*/
extern const listItemInMenu_ts* SetSP_ListOfContext[DIVEMODE_MAX];
extern const contentDispContext_st SetSP_UnitSet_Ctx;
//
extern const contentDispContext_st SetSP_OnOffSet_SetLowSp_Ctx;
extern const contentDispContext_st SetSP_OnOffSet_SetHighSp_Ctx;
//
extern const contentDispContext_st SetSP_Custom_Ctx;
extern const contentDispContext_st SetSP_OnOffSet_Custom_Ctx;
//
extern const contentDispContext_st SetSP_AutoHigh_Ctx;
extern const contentDispContext_st SetSP_OnOffSet_AutoHigh_Ctx;
//
extern const contentDispContext_st SetSP_AutoLow_Ctx;
extern const contentDispContext_st SetSP_OnOffSet_AutoLow_Ctx;
extern NVD_DIVEMODE_t GUI_DIVE_Mode;                   // GUI settings for DIVE_MODE
void SetSP_UNITSET(char* pStrRet);
#endif