#include "L4X9_includes.h"
#include "DiveMode.h"

/*FO2*/
void SurfaceMode_FO2Default_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, "%s  %d/%.2d",
            GUI_LANG_GetText(SetGasGetMode(DIVE_MODE, FindGasNumOfDiveMode(DIVE_MODE))), /*Current gas is not 0*/
            FindFO2OfDiveMode(DIVE_MODE),
            FindFHeOfDiveMode(DIVE_MODE));
}
/*FO2 Violation*/
void SurfaceMode_FO2Violation_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, "%s", GUI_LANG_GetText(SetGasGetMode(DIVE_MODE, FindGasNumOfDiveMode(DIVE_MODE)))); /*Do not show 00/00 if in full violation*/
}
static const contentDispContext_st DiveMode_MainPage_FO2_Value =
{
    &SurfaceMode_FO2Default_ValueContext,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_SURFT_FO2, //Main OC
};
static const contentDispContext_st DiveMode_MainPage_NotBestGas_FO2_Value =
{
    &SurfaceMode_FO2Default_ValueContext,
    &YELLOW_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_SURFT_FO2, //Main OC
};
static const contentDispContext_st DiveMode_MainPageViolation_FO2_Value =
{
    &SurfaceMode_FO2Violation_ValueContext,
    &Select_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_4,
    &Pos_SURFT_FO2, /*Re use*/
};
void DiveModeHandle_DisplayFO2(void)
{
    if(AlarmStatusCheck_FullViolation())
    {
        /*When Violation*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_MainPageViolation_FO2_Value);
    }
    else
    {
        /**********************************************************************************************************************

            When switching from CC to OC or SM the best gas for current depth shall be the actual gas (gas with highest FO2, 
                while PO2 not exceeding OC Max PO2 (OC Deco PO2 after deco entry).

            Keep original color if 
            (1) Current Gas is the Best Gas, BestGasNumber == CurrGasNumber)
            (2) Other tank has the same FO2 to the Best Gase, fFO2[CurrGasNumber]==fFO2[BestGasNumber
            (3) No Best Gas can be found, BestGasNumber == 0
            (4) fDepthFt > Find_BestGas_MOD, beyond the depth that needs to consider BestGasNumber and CurrGasNumber
            (5) If not in Dive Mode, use White color font to display FO2/FHe String
            Otherwise, change font color to YELLOW Product Specifications D4, Display Specification A29, A30, A31
        **********************************************************************************************************************/
        if( (fFO2[CurrGasNumber]!=fFO2[BestGasNumber]) && (Dive_Info.Status == AMB_DIVEINFO_DIVE) && (BestGasNumber != 0) )
        {
            /*When Current FO2 is NO LONGER the Best Gas*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_MainPage_NotBestGas_FO2_Value);       // Color changes for warning
        }
        else
        {
            /*When default*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_MainPage_FO2_Value);                  // No warning, No color change
        }
    }
}
