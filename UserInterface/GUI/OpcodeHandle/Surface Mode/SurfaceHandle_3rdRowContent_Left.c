
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"

/*GF*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_GF =
{
    &SurfaceMode_MainGF_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_GF(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_GF);
}
/*TIME*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_TIME =
{
    &SurfaceMode_TimeValue_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_TIME(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_TIME);
}
/*DilO2*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_DilO2 =
{
    &SurfaceMode_DilPO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_DilPO2(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_DilO2);
}
/*FiO2*/
const contentDispContext_st SurfaceMode_3rdRowLeft_FiO2 =
{
    &SurfaceMode_FiO2_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_FiO2(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_FiO2);
}
/*GTR*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_GTR =
{
    &SurfaceMode_Gauge_GTR_ValueContext,
    &GTR_ColorHanlde,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
static const contentDispContext_st SurfaceMode_3rdRowLeft_GTR_LostLink =
{
    &DiveMode_DashDash_Context, /*Reused -:--*/
    &GTR_ColorHanlde,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_GTR(void)
{
    if(CheckIfGasToTMT_Assigned())
    {
        /*Display the content*/
        if(CheckLooseLink_TMT(Current_TMT_Num())==LooseLink_OFF)
        {
            /*Lost link: -:--*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_GTR_LostLink);
        }
        else
        {
            /*Display GTR value*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_GTR);
        }
    }
    else
    {
        /*Clear the content when no TMT be assigned*/
        HandleDisplayTextWithMemdev(IteStat_Clear, SurfaceMode_3rdRowLeft_GTR);
    }
}
/*O2 SAT*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_O2SAT =
{
    &SurfaceMode_O2Sat_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_O2Sat(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_O2SAT);
}
/*Ceiling*/
const contentDispContext_st SurfaceMode_3rdRowLeft_CEILING =
{
    &SurfaceMode_Ceiling_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_Ceiling(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_CEILING);
}
/*Max Depth*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_MAXDEPTH =
{
    &SurfaceMode_MaxDepth_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_MaxDepth(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_MAXDEPTH);
}
/*AGV depth*/
static const contentDispContext_st SurfaceMode_3rdRowLeft_AVGDEPTH =
{
    &SurfaceMode_AvgDepth_ValueContext,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_SURFT_3rdRowLeft_Value,
};
void SurfaceHandle_3rdRowLeft_AvgDepth(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_AVGDEPTH);
}

