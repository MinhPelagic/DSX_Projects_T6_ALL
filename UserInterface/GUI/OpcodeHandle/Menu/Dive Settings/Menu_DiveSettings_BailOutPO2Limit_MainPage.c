/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

static void _FuncDisp_BAILOUT(uint8_t posBailoutNum)
{
    ClearUnusedInList(BailOutPO2Limits_MAX);
    if(NVD_MDCC==DIVE_MODE)
    {
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_BAILOUT_PO2_LIMITS));
    }
    else
    {
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_PO2_LIMITS));
    }
    for(uint8_t u8_i = BailOutPO2Limits_MINPO2; u8_i < BailOutPO2Limits_MAX; u8_i++)
    {
        /*Display all the item in list of BAILOUT PO2 LIMITS*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, (posBailoutNum==u8_i) ? IteStat_Select : IteStat_UnSelect, *(pFunc_Context_PO2Limit[u8_i]));
    }
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_BAILOUT_PO2_OC_MIN(void)
{
    _FuncDisp_BAILOUT(BailOutPO2Limits_MINPO2);
}
void IniOrClrScrFunc_BAILOUT_PO2_OC_MAX(void)
{
    _FuncDisp_BAILOUT(BailOutPO2Limits_MAXPO2);
}
void IniOrClrScrFunc_BAILOUT_PO2_OC_DECO(void)
{
    _FuncDisp_BAILOUT(BailOutPO2Limits_DECOPO2);
}
void UpdPorFunc_BAILOUT_PO2_OC_MIN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_BAILOUTPO2_MIN);
}
void HandlePreOCFunc_BAILOUT_PO2_OC_MIN(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_BAILOUTPO2_MIN);
}
void UpdPorFunc_BAILOUT_PO2_OC_MAX(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_BAILOUTPO2_MAX);
}
void HandlePreOCFunc_BAILOUT_PO2_OC_MAX(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_BAILOUTPO2_MAX);
}
void UpdPorFunc_BAILOUT_PO2_OC_DECO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_BAILOUTPO2_DECO);
}
void HandlePreOCFunc_BAILOUT_PO2_OC_DECO(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_BAILOUTPO2_DECO);
}
