/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"
void IniOrClrScrFunc_SP_HIGH_SP_SET(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_HIGH_SP));
    /*Display main value of HIGH SP*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_OnOffSet_SetHighSp_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
};
void UpdOrFlasFunc_SP_HIGH_SP_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetSP_OnOffSet_SetHighSp_Ctx);
}