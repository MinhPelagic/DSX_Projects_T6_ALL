/******************************************************************************/
//File: Dive planner.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
/*Maximum Operation Depth (MOD)*/
static void DivePlanner_DepthLimit_Txt_MOD_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DepthLimits_MOD));
}
const contentDispContext_st DivePlanner_DepthLimit_Txt_MOD =
{
    &DivePlanner_DepthLimit_Txt_MOD_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DivePlan_DepthLimits_TxtLine_00,
};
static void DivePlanner_DepthLimit_Val_MOD_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", FindMOD());
    else
        sprintf(pStrRet, "%.1f M", (FindMOD()*CONST_FT_TO_M));
}
const contentDispContext_st DivePlanner_DepthLimit_Val_MOD =
{
    &DivePlanner_DepthLimit_Val_MOD_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_DivePlan_DepthLimits_ValLine_00,
};
/*Hypoxic Treshold (HT)*/
static void DivePlanner_DepthLimit_Txt_HT_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DepthLimits_HT));
}
const contentDispContext_st DivePlanner_DepthLimit_Txt_HT =
{
    &DivePlanner_DepthLimit_Txt_HT_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DivePlan_DepthLimits_TxtLine_01,
};
static void DivePlanner_DepthLimit_Val_HT_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", FindHT());
    else
        sprintf(pStrRet, "%.1f M", (FindHT()*CONST_FT_TO_M));
}
const contentDispContext_st DivePlanner_DepthLimit_Val_HT =
{
    &DivePlanner_DepthLimit_Val_HT_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_DivePlan_DepthLimits_ValLine_01,
};
/*Equivalent Narcotic Depth (END)*/
static void DivePlanner_DepthLimit_Txt_END_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DepthLimits_END));
}
const contentDispContext_st DivePlanner_DepthLimit_Txt_END =
{
    &DivePlanner_DepthLimit_Txt_END_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DivePlan_DepthLimits_TxtLine_02,
};
static void DivePlanner_DepthLimit_Val_END_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", FindEND());
    else
        sprintf(pStrRet, "%.1f M", (FindEND()*CONST_FT_TO_M));
}
const contentDispContext_st DivePlanner_DepthLimit_Val_END =
{
    &DivePlanner_DepthLimit_Val_END_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_DivePlan_DepthLimits_ValLine_02,
};
/*Work of Breathing (WOB)*/
static void DivePlanner_DepthLimit_Txt_WOB_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DepthLimits_WOB));
}
const contentDispContext_st DivePlanner_DepthLimit_Txt_WOB =
{
    &DivePlanner_DepthLimit_Txt_WOB_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DivePlan_DepthLimits_TxtLine_03,
};
static void DivePlanner_DepthLimit_Val_WOB_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", FindWOB());
    else
        sprintf(pStrRet, "%.1f M", (FindWOB()*CONST_FT_TO_M));
}
const contentDispContext_st DivePlanner_DepthLimit_Val_WOB =
{
    &DivePlanner_DepthLimit_Val_WOB_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_DivePlan_DepthLimits_ValLine_03,
};