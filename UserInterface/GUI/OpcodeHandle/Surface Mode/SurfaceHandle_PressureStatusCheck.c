
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Gas Switch\Menu_GasSwitch.h"
#include "..\Dive Mode\DiveMode.h"


/*Pressue check link on Surface and Dive*/
ItemStatus_te CheckPressureLinkingStatus(TMT_NUM_t n)
{
    ItemStatus_te retStatus = IteStat_ClearThenSelect;
    /* Check the current status connect or not
    END/TURN pressure should be flashing */
    if((CheckLooseLink_TMT(n)!=LooseLink_OK)||(AlarmStatusCheck_EndP())||(AlarmStatusCheck_TurnP()))
    {
        /*Lost link*/
        retStatus = IteStat_ClearThenFlashing;
    }
    else
    {
        /*Do nothing*/
    }
    return retStatus;
}

// /*Pressue check link on Surface and Dive*/
// ItemStatus_te CheckPressureLinkingStatus_GAS_N(TANK_NUM_t set, TANK_NUM_t n)
// {
//     ItemStatus_te retStatus = IteStat_ClearThenSelect;
//     /*Check the current status connect or not*/
//     if(CheckLooseLink_GAS(n)!=LooseLink_OFF)
//     {
//         /*Do nothing*/
//     }
//     else
//     {
//         /*Lost link*/
//         retStatus = IteStat_Flashing;
//     }
//     return retStatus;
// }

/*Pressue check link on Surface and Dive*/
// ItemStatus_te DispPressFlashingCheck(TMT_NUM_t n)
// {
//     ItemStatus_te retStatus = IteStat_ClearThenSelect;
//     /*Check the current status connect or not*/
//     if(CheckLooseLink_TMT(n)==LooseLink_OK)
//     {
//         /*Do nothing*/
//     }
//     else
//     {
//         /*Lost link*/
//         retStatus = IteStat_ClearThenFlashing;
//     }
//     return retStatus;
// }
