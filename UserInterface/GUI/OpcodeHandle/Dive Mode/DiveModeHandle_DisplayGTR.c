#include "L4X9_includes.h"
#include "DiveMode.h"


extern void ClearPortion_PO2MiddleCenter(void);

/*
Display Gas Time remainning base on the TMT connected status
*/
void DiveModeHandle_Gauge_Display_GTR(ItemStatus_te dispStatus)
{
    /*When NO TMT was assigned no display GTR*/
    if(CheckIfGasToTMT_Assigned())
    {
        /*Display the title once*/
        if(IteStat_Initial == dispStatus)
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_GTR_TitleTxt);
        }
        else
        {
            /*no progress*/
        }
        /* display flashing --:--*/
        if((Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)||(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF))
        {
            HandleDisplayTextWithMemdev(IteStat_Flashing, DiveMode_GTR_Dash);
        }
        /*Display the value*/
        else
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_GTR_Value);
        }
    }
    else
    {
        /*Do nothing*/
    }
}
/*
Display Gas Time remainning base on the TMT connected status
*/
void DiveModeHandle_OC_Display_GTR(void)
{
    /*When NO TMT was assigned no display GTR*/
    if(CheckIfGasToTMT_Assigned())
    {
        /*Display the title*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_OC_GTR_Tittle);
        /* display flashing --:--*/
        if((Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)||(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF))
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, DiveMode_OC_GTR_Dash);
        }
        /*Display the value*/
        else
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_OC_GTR_Value);
        }
    }
    else
    {
        /*keep clear*/
        ClearPortion_GTRDisplay();
    }
}
/*
Display GTR check when Violation
*/
void DiveModeHandle_Violation_Display_GTRBottom(void)
{
    if(AlarmStatusCheck_FullViolation())
    {
        /*When NO TMT was assigned no display GTR*/
        if(CheckIfGasToTMT_Assigned())
        {
            /*Display the title*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Violation_GTRInBottom_Tittle);
            /* display flashing --:--*/
            if((Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)||(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF))
            {
                HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, DiveMode_Violation_GTRInBottom_Dash);
            }
            /*Display the value*/
            else
            {
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Violation_GTRInBottom_Value);
            }
        }
        else
        {
            ClearPortionOCLeftRight();//Keep clear prevent overlap
        }
    }
    else
    {
        /*Do nothing*/
    }
}
/*
Display GTR check when Violation
*/
void DiveModeHandle_Violation_Display_GTRMiddle(void)
{
    /*When NO TMT was assigned no display GTR*/
    if(CheckIfGasToTMT_Assigned())
    {
        /*Display the title*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Violation_GTRInMiddle_Tittle);
        /* display flashing --:--*/
        if((Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)||(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF))
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, DiveMode_Violation_GTRInMiddle_Dash);
        }
        /*Display the value*/
        else
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Violation_GTRInMiddle_Value);
        }
    }
    else
    {
        ClearPortion_PO2MiddleCenter();//Keep clear prevent overlap
    }
}
