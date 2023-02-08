/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveMenu_DecoStops.h"

void IniOrClrScrFunc_DIVEMENU_DECOSTOPS_ENTER(void)
{
    /*PO2 center content*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DecoStop_PO2_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DecoStop_PO2_Value);
    /*Decompress content */
    DecoStopHandle_InitialCheckDecoDisplay();
}
void UpdOrFlasFunc_DIVEMENU_DECOSTOPS_ENTER(void)
{
    /*Update in real time*/
    HandleDisplayTextWithMemdev(IteStat_Select, DecoStop_PO2_Value);
    /*Update the list in real time*/
    if(DecoStop_CheckNoDecoStatus())
    {
        /*Do nothing -> No update*/
    }
    else
    {
        /*Update Content*/
        DecoStopHandle_ContentList(DecoStop_StartRec_u8);
    }
}