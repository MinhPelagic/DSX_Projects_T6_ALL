
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
/*GF*/
static const contentDispContext_st SurfaceMode_3rdRowRight_GF =
{
    &SurfaceMode_MainGF_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_GF(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_GF);
}
/*TIME*/
static const contentDispContext_st SurfaceMode_3rdRowRight_TIME =
{
    &SurfaceMode_TimeValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_TIME(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_TIME);
}
/*DilO2*/
static const contentDispContext_st SurfaceMode_3rdRowRight_DilO2 =
{
    &SurfaceMode_DilPO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_DilPO2(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_DilO2);
}
/*FiO2*/
const contentDispContext_st SurfaceMode_3rdRowRight_FiO2 =
{
    &SurfaceMode_FiO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_FiO2(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_FiO2);
}
/*GTR*/
static const contentDispContext_st SurfaceMode_3rdRowRight_GTR =
{
    &SurfaceMode_Gauge_GTR_ValueContext,
    &GTR_ColorHanlde,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
static const contentDispContext_st SurfaceMode_3rdRowRight_GTR_LostLink =
{
    &DiveMode_DashDash_Context, /*Reused -:--*/
    &GTR_ColorHanlde,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_GTR(void)
{
    if(CheckIfGasToTMT_Assigned())
    {
        /*Display the content*/
        if(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF)
        {
            /*Lost link: -:--*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_GTR_LostLink);
        }
        else
        {
            /*Display GTR value*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_GTR);
        }
    }
    else
    {
        /*Clear the content when no TMT be assigned*/
        HandleDisplayTextWithMemdev(IteStat_Clear, SurfaceMode_3rdRowRight_GTR);
    }
}
/*O2 SAT*/
static const contentDispContext_st SurfaceMode_3rdRowRight_O2SAT =
{
    &SurfaceMode_O2Sat_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_O2Sat(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_O2SAT);
}
/*Ceiling*/
const contentDispContext_st SurfaceMode_3rdRowRight_CEILING =
{
    &SurfaceMode_Ceiling_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_Ceiling(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_CEILING);
}
/*Max Depth*/
static const contentDispContext_st SurfaceMode_3rdRowRight_MAXDEPTH =
{
    &SurfaceMode_MaxDepth_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_MaxDepth(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_MAXDEPTH);
}
/*AGV depth*/
static const contentDispContext_st SurfaceMode_3rdRowRight_AVGDEPTH =
{
    &SurfaceMode_AvgDepth_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowRight_Value,
};
void SurfaceHandle_3rdRowRight_AvgDepth(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_AVGDEPTH);
}

