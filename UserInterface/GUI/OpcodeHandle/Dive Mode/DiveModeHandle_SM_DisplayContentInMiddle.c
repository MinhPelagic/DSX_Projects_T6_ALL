#include "L4X9_includes.h"
#include "DiveMode.h"

extern void DiveModeHandle_Violation_Display_GTRMiddle(void);

/*
Check display to main and alternate page
There are 2 cases:
- Display 3rd row left/right + PO2 in center
- Display TMT or PO2 on right
*/
void Dive_SM_Handle_CheckDisplayMiddle(void)
{
    /*Display either OC-L or OC-R or Both*/
    if((TRIMIX_Set.CurrGasNumber_SM==TANK_1)||(TRIMIX_Set.CurrGasNumber_SM==TANK_2))
    {
        if(AlarmStatusCheck_FullViolation())
        {
            /*Display OC status when Violation*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeftStatusViolation_Value);
            /*Display GTR in center*/
            DiveModeHandle_Violation_Display_GTRMiddle();
            /*Clear PO2 on right*/
            ClearPortion_3rdContentRight();
        }
        else
        {
            /*PO2 on right*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_PO2_SMMode_Tittle);
            HandleDisplayItemMdev(SurfaceMode_PO2_SMMode_Value);
            /**********************************************************************************************************************
            Keep original color if 
            (1) Current Gas is the Best Gas, BestGasNumber == CurrGasNumber)
            (2) Other tank has the same FO2 to the Best Gase, fFO2[CurrGasNumber]==fFO2[BestGasNumber
            (3) No Best Gas can be found, BestGasNumber == 0
            (4) fDepthFt > Find_BestGas_MOD, beyond the depth that needs to consider BestGasNumber and CurrGasNumber
            (5) If not in Dive Mode, use White color font to display FO2/FHe String
            Otherwise, change font color to YELLOW Product Specifications D4, Display Specification A29, A30, A31
            **********************************************************************************************************************/        
            /*Check if Selected Tank is a Best Gas*/
            if( (fFO2[CurrGasNumber]!=fFO2[BestGasNumber]) && (Dive_Info.Status == AMB_DIVEINFO_DIVE) && (BestGasNumber != 0) )
            {
                /*When Current FO2 is NO LONGER the Best Gas*/
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_NotBestGas_OCLeftStatus_Value);
            }
            else
            {
                /*When default*/
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeftStatus_Value);
            }
            /*Clear tittle of 3rd row right and PO2*/
            ClearPortion_DiveSM_MiddleRowTitte();
        }
    }
    /*Display OC-3, OC-4, OC-5 or OC-6*/
    else
    {
        if(AlarmStatusCheck_FullViolation())
        {
            /*Clear PO2 and 3rd row Left right content to prevent overlap*/
            ClearPortion_CC_PO23rdRowLeftRight();
        }
        else
        {
            /*PO2 in the center*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_PO2_Tittle);
            HandleDisplayItemMdev(DiveMode_PO2_Value);
            /*3rd Row left and right*/
            SurfaceHandle_Display3rRowLeftContent();
            SurfaceHandle_Display3rRowRightContent();
        }
    }
}
