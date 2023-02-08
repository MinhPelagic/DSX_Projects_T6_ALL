/******************************************************************************/
//File: Dive planner.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"
/**
Text define for DEPTH LIMITS
*/
enum DepthLimits_e
{
    /**Display the information MOD*/
    DepthLimits_MOD,
    /**Display the information HT*/
    DepthLimits_HT,
    /**Display the information END*/
    DepthLimits_END,
    /**Display the information WOB*/
    DepthLimits_WOB,
    DepthLimits_MAX,
};
/**/
static void DivePlanner_DepthLimits_Content(char* pStrRet)
{
    /**
     Top title:
     GAS: MM-GAS# xx/xx	   SP: x.xx-x.xx	  GF: xx-xx
     */
    sprintf(pStrRet, "%s:%d/%d %s.%s:%.2f %s:%d-%d",\
            GUI_LANG_GetText(TxtStr_GAS),\
            DiPla_FO2,DiPla_Fhe,\
            GUI_LANG_GetText(TxtDef_DSX_MainMode[(LoNibVal(MainMode)<DIVEMODE_MAX) ? LoNibVal(MainMode) : DIVEMODE_CC]),\
            GUI_LANG_GetText(TxtStr_MAX_PO2),\
            DiPla_MAX_PO2,\
            GUI_LANG_GetText(TxtStr_GF),\
            DiPla_GFLO, DiPla_GFHI);
}
/*Depth value*/
static const contentDispContext_st DiveSimulator_DepthLimits_Context =
{
    &DivePlanner_DepthLimits_Content,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DepthLimits_TopTittle,
};

void IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS_SET(void)
{
    ClearWholeScreen();
    Display_Icon_Buttons(IconBottDisp_BackSelect);
    /*Display the information*/
    GUI_SetBkColor(GUI_DARKGRAY);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Txt_MOD);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Txt_END);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Val_END);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Val_MOD);
    GUI_SetBkColor(GUI_BLACK);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Txt_HT);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Txt_WOB);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Val_HT);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DivePlanner_DepthLimit_Val_WOB);
    /*Tittle*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSimulator_DepthLimits_Context);
};
