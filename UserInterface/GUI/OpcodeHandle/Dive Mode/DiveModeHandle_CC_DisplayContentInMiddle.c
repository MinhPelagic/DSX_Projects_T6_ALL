#include "L4X9_includes.h"
#include "DiveMode.h"

/**
 * @brief
 * The below middle display (below VIOLATION text) -> Check the display when Violation
 * Check display PO2, 3rd row Left/Right or Violation
 *
 */
void Dive_CC_Handle_CheckDisplayMiddle(void)
{
    if(AlarmStatusCheck_AlarmWarningLowBattShutDown())
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, ALARM_LowBattShutDownLine0);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, ALARM_LowBattShutDownLine1);
    }
    else if(AlarmStatusCheck_FullViolation())
    {
        /*Clear all the portion in middle*/
        ClearPortion_CC_PO23rdRowLeftRight();
    }
    else
    {
        if((Dive_Info.Status != AMB_DIVEINFO_DIVE) && (Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE))             // added by YeuShyr on 2022/07/09 to avoid overlapping with ALARM_LowBattShutDownLine0 messages
        {
            /*DESAT*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);                     // added by YeuShyr on 2022/07/09 to avoid overlapping with ALARM_LowBattShutDownLine0 messages
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);                      // added by YeuShyr on 2022/07/09 to avoid overlapping with ALARM_LowBattShutDownLine0 messages
        }
        /*PO2 in the center*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_PO2_Tittle);
        HandleDisplayItemMdev(DiveMode_PO2_Value);
        /*3rd Row left and right*/
        SurfaceHandle_Display3rRowLeftContent();
        SurfaceHandle_Display3rRowRightContent();
    }
}
