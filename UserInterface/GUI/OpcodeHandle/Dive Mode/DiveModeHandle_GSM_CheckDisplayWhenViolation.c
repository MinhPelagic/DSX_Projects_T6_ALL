#include "L4X9_includes.h"
#include "DiveMode.h"
/*
When Violation
-> Display keep flashing without AVG depth/Max Depth
*/
void DivemodeHandle_GSM_CheckDisplayViolationAboveMiddle(void)
{
    /*When inital only display once otherwise -> continue update display*/
    if(AlarmStatusCheck_FullViolation())
    {
        HandleDisplayTextWithMemdev(IteStat_Flashing, ALARM_FullViolation);
    }
    else
    {
        /*AVG Depth*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_AvgDepth_TitleTxt);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_AvgDepth_Value);
        /*Max depth*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_MaxDepth_TitleTxt);
        HandleDisplayTextWithMemdev(IteStat_Select, Dive_Gauge_MaxDepth_Value);
    }
}
void DivemodeHandle_GSM_CheckDisplayViolationMiddle(ItemStatus_te dispStat)
{
    /*When inital only display once otherwise -> continue update display*/
    if(AlarmStatusCheck_FullViolation())
    {
        /*Do nothing*/
    }
    else
    {
        if(IteStat_Initial == dispStat)
        {
            /*Runtime Tittle*/
            HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Tittle);
        }
        else
        {
            /*Do nothing*/
        }
        /*Runtime*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Value);
        /*GTR*/
        DiveModeHandle_Gauge_Display_GTR(dispStat);
    }
}
