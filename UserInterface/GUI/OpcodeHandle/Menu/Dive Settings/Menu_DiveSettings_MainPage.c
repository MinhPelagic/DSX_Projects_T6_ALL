/******************************************************************************/
//File: Dive_Settings.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

void IniOrClrScrFunc_S99_SET_DIVEMODE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSett_DIVEMODE, DiveSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
};
void IniOrClrScrFunc_S76_SET_BAILOUTPO2LIMITS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSett_BAILOUTPO2, DiveSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S83_SET_CONSERVATISM(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSett_CONSERVATISM, DiveSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S91_SET_SAFETYSTOP(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSett_SAFETYSTOP, DiveSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void IniOrClrScrFunc_S96_SET_LASTSTOPDEPTH(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_SETTING));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_DiveSett_LASTSTOPDEPTH, DiveSettings_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S99_SET_DIVEMODE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_DIVEMODE);
}
void HandlePreOCFunc_S99_SET_DIVEMODE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_DIVEMODE);
}
/*-------------------------------------------------------------------------------*/
void UpdPorFunc_S76_SET_BAILOUTPO2LIMITS(void)
{
    if(NVD_MDCC==DIVE_MODE)
    {
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_BAILOUTPO2);
    }
    else
    {
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_PO2LIMITS);
    }
};
void HandlePreOCFunc_S76_SET_BAILOUTPO2LIMITS(void)
{
    if(NVD_MDCC==DIVE_MODE)
    {
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_BAILOUTPO2);
    }
    else
    {
        Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_PO2LIMITS);
    }
}
/*-------------------------------------------------------------------------------*/
void UpdPorFunc_S83_SET_CONSERVATISM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_CONSERVATISM);
}
void HandlePreOCFunc_S83_SET_CONSERVATISM(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_CONSERVATISM);
}
void UpdPorFunc_S91_SET_SAFETYSTOP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_SAFETYSTOP);
}
void HandlePreOCFunc_S91_SET_SAFETYSTOP(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_SAFETYSTOP);
}
void UpdPorFunc_S96_SET_LASTSTOPDEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_DiveSett_LASTSTOPDEPTH);
}
void HandlePreOCFunc_S96_SET_LASTSTOPDEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_DiveSett_LASTSTOPDEPTH);
}
