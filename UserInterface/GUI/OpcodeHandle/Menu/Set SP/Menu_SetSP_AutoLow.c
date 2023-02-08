/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
void IniOrClrScrFunc_SP_AUTO_LOW_STAT(void)
{
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_AUTO_LOW));
    /*Display main custom SP ON/OFF/SET*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_OnOffSet_AutoLow_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SP_AUTO_LOW_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_OnOffSet_AutoLow_Ctx);
}
/*SET*/
void IniOrClrScrFunc_SP_AUTO_LOW_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Clear, SetSP_OnOffSet_AutoLow_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_AutoLow_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_SP_AUTO_LOW_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_AutoLow_Ctx);
}