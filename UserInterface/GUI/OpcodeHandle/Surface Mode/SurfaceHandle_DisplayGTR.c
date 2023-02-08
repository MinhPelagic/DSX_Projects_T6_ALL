#include "L4X9_includes.h"
#include "SurfaceMode.h"

/*
Display Gas Time remainning base on the TMT connected status
*/
void SurfaceHandle_DisplayGTR(ItemStatus_te dispStatus)
{
    /*Display the title once*/
    if(CheckIfGasToTMT_Assigned())
    {
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Gauge_GTR_Tittle);
        /*Showing -:-- and flashing in 10 mins after dive or lost link*/
        if((Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)||(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF))
        {
            HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_Gauge_GTR_Dash);
        }
        else /*Display the value base on current TMT status*/
        {
            HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Gauge_GTR_Value);
        }
    }
    else
    {
        /*No display -> Clear the content*/
        HandleDisplayTextWithMemdev(IteStat_Clear, SurfaceMode_Gauge_GTR_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Clear, SurfaceMode_Gauge_GTR_Value);
    }
}
