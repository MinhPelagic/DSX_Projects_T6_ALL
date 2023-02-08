/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "..\..\..\Dive Mode\DiveMode.h"
#include "Menu_DiveMenu_DecoStops.h"

/*DECO STOP PO2*/
const contentDispContext_st DecoStop_PO2_Tittle =
{
    &DiveMode_PO2_Tittle_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_DiveMenu_DecoStop_PO2_Tittle,
};
/*PO2 Value*/
const contentDispContext_st DecoStop_PO2_Value =
{
    &DiveMode_PO2_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_DiveMenu_DecoStop_PO2_Value,
};
/*NO DECO*/
const contentDispContext_st DecoStop_NODECO =
{
    &DiveMode_NoDecoOrO2TimeTittle_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_DiveMenu_DecoStop_NODECO,
};