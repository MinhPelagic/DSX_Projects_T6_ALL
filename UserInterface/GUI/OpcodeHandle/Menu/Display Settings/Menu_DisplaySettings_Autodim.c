/******************************************************************************/
//File: Autodim.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

void IniOrClrScrFunc_DISPLAY_AUTODIM__STAT(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_AUTO_DIM));
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Set_DispSett_Autodim_Stat_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DISPLAY_AUTODIM__STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Autodim_Stat_Ctx);
}
/*Autodim Time*/
void IniOrClrScrFunc_DISPLAY_AUTODIM__TIME(void)
{
    ClearUnusedInList(0);
    /*Clear all the previous content*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_TIME_TO_DIM));
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Set_DispSett_Autodim_BrightTime_Ctx);
}
void UpdOrFlasFunc_DISPLAY_AUTODIM__TIME(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Autodim_BrightTime_Ctx);
}
/*Autodim brightness value*/
void IniOrClrScrFunc_DISPLAY_AUTODIM__PERCENT(void)
{
    ClearUnusedInList(0);
    /*Clear all the previous content*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_DIM_TO_BRIGHTNESS));
    HandleDisplayTextWithMemdev(IteStat_Clear, Set_DispSett_Autodim_BrightTime_Ctx);
    /*Display the char %*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_Brightness_PercentChar_Ctx);
    /*Display the value*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Set_DispSett_Brightness_AutoDim_Ctx);
}
void UpdOrFlasFunc_DISPLAY_AUTODIM__PERCENT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Brightness_AutoDim_Ctx);
}

