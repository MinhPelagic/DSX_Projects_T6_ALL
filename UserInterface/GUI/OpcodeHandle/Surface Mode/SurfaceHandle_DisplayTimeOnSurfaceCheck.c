
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"

void DiveModeHandle_Display_Clock(ItemStatus_te dispStat)
{
    /*only display one time whenever called*/
    if(IteStat_Initial == dispStat)
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Time_Tittle);
    }
    else
    {
        /*no progress*/
    }
    /*Display HH:MM*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_TimeValue);
}
