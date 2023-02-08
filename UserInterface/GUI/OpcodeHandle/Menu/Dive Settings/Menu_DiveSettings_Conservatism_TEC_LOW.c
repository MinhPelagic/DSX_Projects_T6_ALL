/******************************************************************************/
//File: TEC.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/*LOW SET*/
void IniOrClrScrFunc_CONSERV_TEC_GF_LOW_SET(void)
{
    /*Clear previous screen*/
    ClearUnusedInList(0);
    /*Display sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_GF_LOW));
    /*Initial the GF LOW value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DiveSett_Consrv_TEC_Low_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_CONSERV_TEC_GF_LOW_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DiveSett_Consrv_TEC_Low_Ctx);
}
