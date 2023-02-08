
#include "L4X9_includes.h"
#include "DiveMode.h"
#include "..\Surface Mode\SurfaceMode.h"
/*Current pressure display*/
void DepthAndDiveTime_PressureDisplay(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_TankPressRight_Tittle);
    /*Get current TMT*/
    const TMT_NUM_t currentTMT = Current_TMT_Num();
    /*Loose link status*/
    const LOOSE_LINK_t looseLinkStatus = CheckLooseLink_TMT(currentTMT);
    /*Display status*/
    const ItemStatus_te dispPressureStatus = CheckPressureLinkingStatus(CURRENT_TMT_NUM);
    /*Value*/
    if(looseLinkStatus == LooseLink_OK)
    {
        HandleDisplayTextWithMemdev(dispPressureStatus, DepthDiveTimeMode_TankPressRightLinkedValue);
    }
    else if(looseLinkStatus == LooseLink_LOOSE)
    {
        HandleDisplayTextWithMemdev(dispPressureStatus, DepthDiveTimeMode_TankPressureLooseLinkValue);
    }
    else
    {
        HandleDisplayTextWithMemdev(dispPressureStatus, DepthDiveTimeMode_TankPressureOffLinkValue);
    }
}
