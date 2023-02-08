
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
/*item status*/
static ItemStatus_te SurfaceMode_DispStat_CC6(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*When alarm occured -> stop update/display*/
    if(CheckLooseLink_GAS(TANK_6)==LooseLink_OFF)
    {
        statRet = IteStat_ClearThenFlashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
/*CC Press*/
static void SurfaceMode_CC6_Press_TittleContext(char* pStrRet)
{
    sprintf(pStrRet, "CC-6 %s", TxtDef_Set_PressUnit[UNITS]);
}
static void SurfaceMode_CC6_Press_ValueContext(char* pStrRet)
{
    const LOOSE_LINK_t linkStatTank6 = CheckLooseLink_GAS(TANK_6);
    if(linkStatTank6==LooseLink_OK)
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, " %d ", GUI_CC6_PressPSI);
        else
            sprintf(pStrRet, " %d ", (uint16_t)(CONST_PSI_TO_BAR*GUI_CC6_PressPSI));
    }
    else
    {
        strcpy(pStrRet, "  ---  ");
    }
}
/*CC Press*/
static const contentDispContext_st SurfaceMode_CC6_Press_Tittle =
{
    &SurfaceMode_CC6_Press_TittleContext,
    &SurfaceMode_SurfTime_TitleText_Color,
    GUI_TA_CENTER,
    &FontAaux_2,
    &Pos_SURF_Time_TxtTittle,
};
/*CC-6 Value*/
static const contentWithStateHandle_st SurfaceMode_CC6_Press_Value =
{
    &SurfaceMode_DispStat_CC6,
    &SurfaceMode_CC6_Press_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_SURF_Time_Value,
};
/*
Display CC-6 Tank pressure
*/
void SurfaceMode_CC6TankPressure(void)
{
    if(TRIMIX_Set.CC_GASTMT[TANK_6]!= TMT_OFF)
    {   /*CC Press*/
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CC6_Press_Tittle);
        HandleDisplayItemMdev(SurfaceMode_CC6_Press_Value);
    }
    else
    {
        /*Do nothing*/
    }
}
