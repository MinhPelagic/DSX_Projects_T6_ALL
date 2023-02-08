/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"
/*Sub function to initial screen*/
void InitFunc_CONSERV_TEC(uint8_t posNum)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CONSERVATISM_TEC));
    for(uint8_t u8_i = Conservatism_GF_LOW; u8_i < Conservatism_GF_MAX; u8_i++)
    {
        /*Display all the item in list of InitFunc_CONSERV_TEC*/
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, (posNum==u8_i) ? IteStat_Select : IteStat_UnSelect, *(p_Conserv_TEC_Contextt[u8_i]));
    }
}
void IniOrClrScrFunc_CONSERV_TEC_GF_LOW(void)
{
    InitFunc_CONSERV_TEC(Conservatism_GF_LOW);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_CONSERV_TEC_GF_HIGH(void)
{
    InitFunc_CONSERV_TEC(Conservatism_GF_HIGH);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_CONSERV_TEC_GF_LOW(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_CONSERVATISM_TEC_LOW);
}
void HandlePreOCFunc_CONSERV_TEC_GF_LOW(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_CONSERVATISM_TEC_LOW);
}
void UpdPorFunc_CONSERV_TEC_GF_HIGH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_CONSERVATISM_TEC_HIGH);
}
void HandlePreOCFunc_CONSERV_TEC_GF_HIGH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_CONSERVATISM_TEC_HIGH);
}
