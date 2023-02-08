
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Gas Switch\Menu_GasSwitch.h"
#include "..\Dive Mode\DiveMode.h"

/*Check TMT off -> When all TMT is OFF -> no display tank pressure*/
bool Check_All_TMTs_Is_Off(void)
{
    if (0 == SCUBA_Set.TMT_On.Allbits)
    {
        /*None of TMT is on*/
        return true;
    }
    else
    {
        /*Some TMT is on*/
        return false;
    }
}
/*Current pressure display*/
void SurfaceHandle_PressureDisplay(void)
{
    /*No display when all TMT OFF*/
    if(Check_All_TMTs_Is_Off())
    {
        /*Clear the portion -> Display empty*/
        ClearPortion_TankPressure();
    }
    else
    {
        /*Titlte*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_TankPressure_Tittle);
        /*Get current TMT*/
        const TMT_NUM_t currentTMT = Current_TMT_Num();
        /*Loose link status*/
        const LOOSE_LINK_t looseLinkStatus = CheckLooseLink_TMT(currentTMT);
        /*Display status*/
        const ItemStatus_te dispPressureStatus = CheckPressureLinkingStatus(CURRENT_TMT_NUM);
        /*Value*/
        if(looseLinkStatus == LooseLink_OK)
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, SurfaceMode_Linked_TankPressure_Value);
        }
        else if(looseLinkStatus == LooseLink_LOOSE)
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, SurfaceMode_LooseLink_TankPressure_Value);
        }
        else
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, SurfaceMode_OffLink_TankPressure_Value);
        }
    }
}

/**
 * @brief Compass specific display
 *
 */
void CompassHandle_PressureDisplay(void)
{
    /*No display when all TMT OFF*/
    if(Check_All_TMTs_Is_Off())
    {
        /*Clear the portion -> Display empty*/
        ClearPortion_CompassMode_TankPressure();
    }
    else
    {
        /*Titlte*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, CompassMode_TankPressure_Tittle);
        /*Get current TMT*/
        const TMT_NUM_t currentTMT = Current_TMT_Num();
        /*Loose link status*/
        const LOOSE_LINK_t looseLinkStatus = CheckLooseLink_TMT(currentTMT);
        /*Display status*/
        const ItemStatus_te dispPressureStatus = CheckPressureLinkingStatus(CURRENT_TMT_NUM);
        /*Value*/
        if(looseLinkStatus == LooseLink_OK)
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, CompassMode_Linked_TankPressure_Value);
        }
        else if(looseLinkStatus == LooseLink_LOOSE)
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, CompassMode_LooseLink_TankPressure_Value);
        }
        else
        {
            HandleDisplayTextWithMemdev(dispPressureStatus, CompassMode_OffLink_TankPressure_Value);
        }
    }
}