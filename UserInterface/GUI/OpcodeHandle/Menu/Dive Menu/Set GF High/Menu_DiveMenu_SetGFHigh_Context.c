/******************************************************************************/
//File: SET GF HIGH menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "..\..\..\Dive Mode\DiveMode.h"
#include "Menu_DiveMenu_SetGFHigh.h"
extern uint8_t GFHighSettingValue;

/*Context memdev config to DispSett_Language*/
static void Set_GFHigh_Content(char* pStrRet)
{
    sprintf(pStrRet, "   %d   ", GFHighSettingValue);
}
const contentDispContext_st Set_GFHigh_Ctx =
{
    &Set_GFHigh_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
