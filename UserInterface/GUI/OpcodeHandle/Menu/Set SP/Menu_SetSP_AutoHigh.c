/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
/*-------------------------------------------------------------------------------------------------------*/
void IniOrClrScrFunc_SP_AUTO_HIGH_STAT(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_AUTO_HIGH));
    /*Display main custom SP ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_OnOffSet_AutoHigh_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SP_AUTO_HIGH_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_OnOffSet_AutoHigh_Ctx);
}
/*SET*/
void IniOrClrScrFunc_SP_AUTO_HIGH_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, SetSP_OnOffSet_AutoHigh_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_AutoHigh_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SP_AUTO_HIGH_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_AutoHigh_Ctx);
}