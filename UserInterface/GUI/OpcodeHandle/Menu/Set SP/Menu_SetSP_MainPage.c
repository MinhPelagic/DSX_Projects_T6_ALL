/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"

/*--------SP SWITCH context handle-------------------------------*/
void IniOrClrScrFunc_S54_SP_HIGH_SP(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_SP));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetSP_HIGH_SP, SetSP_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
};
void IniOrClrScrFunc_S54_SP_LOW_SP(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SET_SP));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetSP_LOW_SP, SetSP_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S56_SP_CUSTOM_SP(void)
{
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetSP_CUSTOM_SP, SetSP_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S59_SP_AUTO_HIGH(void)
{
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetSP_AUTO_HIGH, SetSP_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S59_SP_AUTO_LOW(void)
{
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetSP_AUTO_LOW, SetSP_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
/*-------------------------------------------------------------------------------------------------------*/
void UpdPorFunc_S54_SP_HIGH_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetSP_HIGH_SP);
};
void HandlePreOCFunc_S54_SP_HIGH_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetSP_HIGH_SP);
};
/*-------------------------------------------------------------------------------------------------------*/
void UpdPorFunc_S54_SP_LOW_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetSP_LOW_SP);
}
void HandlePreOCFunc_S54_SP_LOW_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetSP_LOW_SP);
}
/*-------------------------------------------------------------------------------------------------------*/
void UpdPorFunc_S56_SP_CUSTOM_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetSP_CUSTOM_SP);
}
void HandlePreOCFunc_S56_SP_CUSTOM_SP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetSP_CUSTOM_SP);
}
/*-------------------------------------------------------------------------------------------------------*/
void UpdPorFunc_S59_SP_AUTO_HIGH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetSP_AUTO_HIGH);
}
void HandlePreOCFunc_S59_SP_AUTO_HIGH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetSP_AUTO_HIGH);
}
/*-------------------------------------------------------------------------------------------------------*/
void UpdPorFunc_S59_SP_AUTO_LOW(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetSP_AUTO_LOW);
}
void HandlePreOCFunc_S59_SP_AUTO_LOW(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetSP_AUTO_LOW);
}
/*-------------------------------------------------------------------------------------------------------*/
