/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"

void IniOrClrScrFunc_SP_CUSTOM_SP_STAT(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_CUSTOM_SP));
    /*Display main custom SP ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_OnOffSet_Custom_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
};
void UpdOrFlasFunc_SP_CUSTOM_SP_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_OnOffSet_Custom_Ctx);
}
/*-------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_SP_CUSTOM_SP_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_Custom_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SP_CUSTOM_SP_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_Custom_Ctx);
}