/******************************************************************************/
//File: Brightness.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

#define AUTO_BRIGHTNESS_LEV     110
/*When brightness value is 110 -> display Autodim*/
unsigned char AutoDimStatusCheck(void)
{
    unsigned char retStatus = FALSE;
    if(AUTO_BRIGHTNESS_LEV <= GUI_BRIGHTNESS_LV)
    {
        retStatus = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retStatus;
}
void DisplayBrightnessSettings(ItemStatus_te status)
{
    if(AutoDimStatusCheck())
    {
        if(IteStat_Select == status)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Set_DispSett_Brightness_Autodim_Ctx);
        }
        else /*other status : flashing status*/
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, Set_DispSett_Brightness_Autodim_Ctx);
        }
    }
    else
    {
        if(IteStat_Select == status)
        {
            HandleDisplayTextWithMemdev(IteStat_Select, Set_DispSett_Brightness_Value_Ctx);
        }
        else /*->flashing status*/
        {
            HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DispSett_Brightness_Value_Ctx);
        }
        /*Always display the percent character*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, Set_DispSett_Brightness_PercentChar_Ctx);
    }
}
