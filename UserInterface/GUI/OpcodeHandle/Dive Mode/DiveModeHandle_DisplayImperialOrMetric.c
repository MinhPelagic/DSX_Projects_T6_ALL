#include "L4X9_includes.h"
#include "DiveMode.h"

/*Display depth in Metric/Imperial*/
void DiveModeHandle_Display_Depth(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Depth_TitleText);
    }
    else
    {
        /*Do nothing*/
    }
    if(Alarming.Bit.DepthMax)
    {
        HandleDisplayItemMdev(DiveMode_VGM_DepthDashes);
    }
    else
    {
        /*Metric*/
        if (UNITS == NVD_METRIC)
        {
            HandleDisplayItemMdev(DiveMode_Depth_DepthValue_Metric_Decimal);
            HandleDisplayItemMdev(DiveMode_Depth_DepthValue_Metric_Floating);
        }
        /*Imperial*/
        else
        {
            HandleDisplayItemMdev(DiveMode_Depth_DepthValue_Imperial);
        }
    }
}
/*Display extra depth in Metric/Imperial*/
void DiveModeHandle_Display_ExtraDepth(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_Depth_TitleText);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayItemMdev(DiveMode_ExtralargeDepth_DepthValue_Metric_Decimal);
        HandleDisplayItemMdev(DiveMode_ExtralargeDepth_DepthValue_Metric_Floating);
    }
    /*Imperial*/
    else
    {
        HandleDisplayItemMdev(DiveMode_ExtralargeDepth_DepthValue_Imperial);
    }
}
/*Display Max depth in Metric/Imperial*/
void DiveModeHandle_Display_OC_MaxDepth(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MaxDepth_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    if(AlarmOccured.Bit.DepthMax == true)
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_OC_MaxDepthDash);
    }
    else
    {
        /*Metric*/
        if (UNITS == NVD_METRIC)
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MaxDepthValue_Metric_Decimal);
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MaxDepthValue_Metric_Floating);
        }
        /*Imperial*/
        else
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MaxDepthValue_Imperial);
        }
    }
}
/*Display AVG depth in Metric/Imperial*/
void DiveModeHandle_Display_OC_AvgDepth(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_AvgDepth_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_AvgDepthValue_Metric_Floating);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_AvgDepthValue_Metric_Decimal);
    }
    /*Imperial*/
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_AvgDepthValue_Imperial);
    }
}
/*Display Ceiling in Metric/Imperial*/
void DiveModeHandle_Display_OC_Ceiling(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_Ceiling_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_CeilingValue_Metric_Floating);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_CeilingValue_Metric_Decimal);
    }
    /*Imperial*/
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_CeilingValue_Imperial);
    }
}
/*Display END in Metric/Imperial*/
void DiveModeHandle_Display_OC_END(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_ENDDepth_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_ENDDepthValue_Metric_Decimal);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_ENDDepthValue_Metric_Floating);
    }
    /*Imperial*/
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_ENDDepthValue_Imperial);
    }
}
/*Display WOB in Metric/Imperial*/
void DiveModeHandle_Display_OC_WOB(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_WOBDepth_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_WOBDepthValue_Metric_Floating);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_WOBDepthValue_Metric_Decimal);
    }
    /*Imperial*/
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_WOBDepthValue_Imperial);
    }
}
/*Display MOD in Metric/Imperial*/
void DiveModeHandle_Display_OC_MOD(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MODDepth_Tittle);
    }
    else
    {
        /*Do nothing*/
    }
    /*Metric*/
    if (UNITS == NVD_METRIC)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MODDepthValue_Metric_Floating);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MODDepthValue_Metric_Decimal);
    }
    /*Imperial*/
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_OC_MODDepthValue_Imperial);
    }
}
/*Depth in Depth&DiveTime mode*/
void DepthDiveTimeMode_DisplayDepth(ItemStatus_te dispStatus)
{
    /*Initial display is Tittle and Unit text*/
    if(IteStat_Initial==dispStatus)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_DepthTittle);
    }
    else
    {
        /*Do nothing*/
    }
    if(Alarming.Bit.DepthMax)
    {
        HandleDisplayTextWithMemdev(IteStat_Select,DepthDiveTimeMode_MaxDepthAlarm);
    }
    else
    {
        /*Metric*/
        if (UNITS == NVD_METRIC)
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_DepthMetric_Decimal);
            HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_DepthMetric_Floating);
        }
        /*Imperial*/
        else
        {
            HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_DepthImperial);
        }
    }
}
