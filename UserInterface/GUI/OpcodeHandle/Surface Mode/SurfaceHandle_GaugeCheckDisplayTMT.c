
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Gas Switch\Menu_GasSwitch.h"

/*Check GSM/SM TMT Left Right be assigned -> TMT1-2*/
unsigned char SurfaceCheckTMTLeftRightStatus(void)
{
    unsigned char retStatus = FALSE;
    if (SM_MODE && ((CURRENT_TANK_NUM_SM == TANK_1) ||
                    (CURRENT_TANK_NUM_SM == TANK_2)) ||
            (GSM_MODE && ((CURRENT_TMT_NUM_GSM == TMT_1) ||
                          (CURRENT_TMT_NUM_GSM == TMT_2))))
    {
        retStatus = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retStatus;
}
/*Base on the current mode -> get the correct response TMT num*/
static bool CheckTMT_ON(TMT_NUM_t tankNum)
{
    bool statRet = FALSE;
    /*When TMT is On and Tank linked with TMT*/
    if (NVD_ON == GUI_TMT_Status[tankNum])
    {
        statRet = TRUE;
    }
    else
    {
        /*Set FALSE*/
    }
    return statRet;
}
/*Display TANK-L and TANK-R this support to SM mode*/
void SurfaceHandle_DisplayTANK_LR(void) // for SM only
{
    ItemStatus_te dispStatus = (ItemStatus_te)0U;
    contentDispContext_st dispContext = {0U};
    TMT_NUM_t TMT_Left; // TMT is linked with TANK 1
    TMT_NUM_t TMT_Right;
    /*Status of GAS*/
    uint8_t GasStat_Left;
    uint8_t GasStat_Right;
    if(SM_MODE)
    {
        TMT_Left  = TRIMIX_Set.SM_GASTMT[TANK_1]; // TMT is linked with TANK 1 to 6
        TMT_Right = TRIMIX_Set.SM_GASTMT[TANK_2];
        /*Status of GAS*/
        GasStat_Left  = TRIMIX_Set.SM_Active.Gas1;
        GasStat_Right = TRIMIX_Set.SM_Active.Gas2;
    }
    else // applied to GSM Mode
    {
        TMT_Left  = TMT_1; // TMT is linked with TMT 1 to 6
        TMT_Right = TMT_2;
        /*Status of GAS*/
        GasStat_Left  = SCUBA_Set.TMT_On.TMT1;
        GasStat_Right = SCUBA_Set.TMT_On.TMT2;
    }
    /*Check User set*/
    if (CheckTMT_ON(TMT_Left) && (1U == GasStat_Left))
    {
        /*LEFT*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeft_Tittle);
        /*TMT link status check*/
        const LOOSE_LINK_t linkStatus = CheckLooseLink_TMT(TMT_Left);
        switch (linkStatus)
        {
        case LooseLink_OK:
            dispStatus = IteStat_ClearThenSelect;
            dispContext = SurfaceMode_TMTLeft_Value;
            break;
        case LooseLink_LOOSE:
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_TMTLeft_Value;
            break;
        default: /*OFF*/
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_OffLink_OCLeft_Value;
            break;
        }
        HandleDisplayTextWithMemdev(dispStatus, dispContext);
    }
    else
    {
        /*Display nothing due to OFF already*/
    }
    if (CheckTMT_ON(TMT_Right) && (1U == GasStat_Right))
    {
        /*RIGHT*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCRight_Tittle);
        /*TMT link status check*/
        const LOOSE_LINK_t linkStatus = CheckLooseLink_TMT(TMT_Right);
        switch (linkStatus)
        {
        case LooseLink_OK:
            dispStatus = IteStat_ClearThenSelect;
            dispContext = SurfaceMode_TMTRight_Value;
            break;
        case LooseLink_LOOSE:
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_TMTRight_Value;
            break;
        default: /*OFF*/
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_OffLink_OCRight_Value;
            break;
        }
        HandleDisplayTextWithMemdev(dispStatus, dispContext);
    }
    else
    {
        /*Display nothing due to OFF already*/
    }
}
/*Display TMT-L and TMT-R this support to SM/GSM mode*/
void SurfaceHandle_DisplayTMT_LR(void) // for GSM only
{
    ItemStatus_te dispStatus = (ItemStatus_te)0U;
    contentDispContext_st dispContext = {0U};
    TMT_NUM_t TMT_Left; // TMT is linked with TANK 1
    TMT_NUM_t TMT_Right;
    /*Status of GAS*/
    uint8_t GasStat_Left;
    uint8_t GasStat_Right;
    if(SM_MODE)
    {
        TMT_Left  = TRIMIX_Set.SM_GASTMT[TANK_1]; // TMT is linked with TANK 1 to 6
        TMT_Right = TRIMIX_Set.SM_GASTMT[TANK_2];
        /*Status of GAS*/
        GasStat_Left  = TRIMIX_Set.SM_Active.Gas1;
        GasStat_Right = TRIMIX_Set.SM_Active.Gas2;
    }
    else // applied to GSM Mode
    {
        TMT_Left  = TMT_1; // TMT is linked with TMT 1 to 6
        TMT_Right = TMT_2;
        /*Status of GAS*/
        GasStat_Left  = SCUBA_Set.TMT_On.TMT1;
        GasStat_Right = SCUBA_Set.TMT_On.TMT2;
    }
    /*Check User set*/
    if (CheckTMT_ON(TMT_Left) && (1U == GasStat_Left))
    {
        /*LEFT*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeft_Tittle);
        /*TMT link status check*/
        const LOOSE_LINK_t linkStatus = CheckLooseLink_TMT(TMT_Left);
        switch (linkStatus)
        {
        case LooseLink_OK:
            dispStatus = IteStat_ClearThenSelect;
            dispContext = SurfaceMode_TMTLeft_Value;
            break;
        case LooseLink_LOOSE:
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_TMTLeft_Value;
            break;
        default: /*OFF*/
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_OffLink_OCLeft_Value;
            break;
        }
        HandleDisplayTextWithMemdev(dispStatus, dispContext);
    }
    else
    {
        /*Display nothing due to OFF already*/
    }
    if (CheckTMT_ON(TMT_Right) && (1U == GasStat_Right))
    {
        /*RIGHT*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCRight_Tittle);
        /*TMT link status check*/
        const LOOSE_LINK_t linkStatus = CheckLooseLink_TMT(TMT_Right);
        switch (linkStatus)
        {
        case LooseLink_OK:
            dispStatus = IteStat_ClearThenSelect;
            dispContext = SurfaceMode_TMTRight_Value;
            break;
        case LooseLink_LOOSE:
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_TMTRight_Value;
            break;
        default: /*OFF*/
            dispStatus = IteStat_ClearThenFlashing;
            dispContext = SurfaceMode_OffLink_OCRight_Value;
            break;
        }
        HandleDisplayTextWithMemdev(dispStatus, dispContext);
    }
    else
    {
        /*Display nothing due to OFF already*/
    }
}
