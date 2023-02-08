/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

void IniOrClrScrFunc_BAILOUT_PO2_OC_MIN_SET(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    if(OC_MODE||SM_MODE)
        DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_OC_MIN_PO2));
    else // CC or BO
        DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_BO_MIN_PO2));
    /*Display the value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_BaiOutPO2_MIN_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_BAILOUT_PO2_OC_MIN_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_BaiOutPO2_MIN_Ctx);
}