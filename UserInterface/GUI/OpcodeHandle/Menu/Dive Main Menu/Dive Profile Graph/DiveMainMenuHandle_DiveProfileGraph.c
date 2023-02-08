#include "L4X9_includes.h"
/*extern prototype*/
extern bool AlarmStatusCheck_FullViolation(void);
extern const contentDispContext_st DecoStop_PO2_Tittle;
void DiveMode_PO2_Value_Context(char *pStrRet);
void DiveMode_DecoStop_Minute_Text_Context(char *pStrRet);
void SetSP_UNITSET(char *pStrRet);
#define BIT_DECO            (0x01 << 14)    // Refer the design of algo
#define DECOBITMASK         (0x3FFF)        // Mask bit 15 and 16
/*Parameter display*/
#define DISPLAY_NumLineScaled (9u)
#define DISPLAY_Pos_X0 (35u)
#define DISPLAY_HorizontalWidth (235u)
#define DISPLAY_Pos_X1 (DISPLAY_Pos_X0 + DISPLAY_HorizontalWidth)
/*Grid parameters*/
#define DIVEGRAPH_GRID_Y0 (70u)
#define DIVEGRAPH_GRID_Height (20u)                                              // Space between 2 line in vertical
#define DIVEGRAPH_GRID_DEPTHVALUE_X0 (DISPLAY_Pos_X0 - 3U)                       // Depth value list on the left
#define DIVEGRAPH_GRID_DEPTHVALUE_Y0 (55U)                                       // Depth value list on the left
#define DIVEGRAPH_GRID_SURF_TO_DEPTH_MAX (uint8_t)(7.35 * DIVEGRAPH_GRID_Height) // Pixel Span "from Surface to MaxDepth"
#define DIVEGRAPH_GRID_SURF_OFFSET (15u)
#define DIVEGRAPH_GRID_DEPTH_MAX_BLUEDASH (DIVEGRAPH_GRID_SURF_TO_DEPTH_MAX + DIVEGRAPH_GRID_Y0) // location for the MAX Depth blue dash line
/*PO2 Value*/
const contentDispContext_st DiveGraph_PO2_Value =
    {
        &DiveMode_PO2_Value_Context,
        &Select_TxtColor,
        GUI_TA_CENTER,
        &FontAaux_5,
        &Pos_DiveGraph_PO2Value,
};
/*Context to display*/
const contentDispContext_st DiveGraph_UnitTextOnLeft =
    {
        &SetSP_UNITSET,
        &Select_TxtColor,
        GUI_TA_RIGHT,
        &FontAaux_2,
        &Pos_DiveGraph_UnitTextOnLeft,
};
/*Depth text on right*/
const contentDispContext_st DiveGraph_UnitTextOnRight =
    {
        &SetSP_UNITSET,
        &Unselect_TxtColor,
        GUI_TA_LEFT,
        &FontAaux_3,
        &Pos_DiveGraph_MaxDepthTextOnRight,
};
void DiveGraph_MaxDepthOnRightContext(char *pStrRet)
{
    float maxDepth_f = 0.0f;
    if (UNITS == NVD_IMPERIAL)
    {
        maxDepth_f = fMaxDepthFt;
    }
    else
    {
        maxDepth_f = CONST_FT_TO_M * fMaxDepthFt;
    }
    sprintf(pStrRet, "%.0f", maxDepth_f);
}
const contentDispContext_st DiveGraph_DepthValueOnRight =
    {
        &DiveGraph_MaxDepthOnRightContext,
        &Unselect_TxtColor,
        GUI_TA_LEFT,
        &FontAaux_3,
        &Pos_DiveGraph_MaxDepthValueOnRight,
};
/*Minutes*/
const contentDispContext_st DiveGraph_MINTextOnRight =
    {
        &DiveMode_DecoStop_Minute_Text_Context, /*Reuse*/
        &Unselect_TxtColor,
        GUI_TA_LEFT,
        &FontAaux_3,
        &Pos_DiveGraph_MinTextOnRight,
};
void DiveGraph_DiveTimeValueOnRight_Context(char *pStrRet)
{
    sprintf(pStrRet, "%d", (uint16_t)(u16DiveTimeTotalSec/60)); // Dive time in minutes
}
const contentDispContext_st DiveGraph_DiveTimeValueOnRight =
    {
        &DiveGraph_DiveTimeValueOnRight_Context,
        &Unselect_TxtColor,
        GUI_TA_LEFT,
        &FontAaux_3,
        &Pos_DiveGraph_MinValueOnRight,
};
/*draw vertial and horizontal lines*/
static void DiveMenuDiveGraph_DrawTheGrid(void)
{
    /*Draw the lines*/
    GUI_SetColor(GUI_GRAY);
    GUI_DrawVLine(DISPLAY_Pos_X0 + 5, DIVEGRAPH_GRID_Y0 - 5, 230);
    for (uint8_t i = 0; i < DISPLAY_NumLineScaled; i++)
    {
        GUI_DrawHLine(DIVEGRAPH_GRID_Y0 + i * DIVEGRAPH_GRID_Height, DISPLAY_Pos_X0, DISPLAY_Pos_X1);
    }
}
/*base on the max depth -> display the depth scaled on the left*/
static void DiveMenuDiveGraph_DisplayDepthScaled(float maxDepthVal)
{
    char strDisp[LangMaxLength];
    float depthScaled_f = 0.0f; // Depth each scaled
    float scaleDepthDisp = 0;   // scaled value
    /*scale each space of max depth value*/
    scaleDepthDisp = maxDepthVal / (DISPLAY_NumLineScaled - 1);
    /*display the FT/M text*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_UnitTextOnLeft);
    if( ((maxDepthVal >= (float)((DISPLAY_NumLineScaled-1)))&&(UNITS==NVD_IMPERIAL))
      ||((CONST_FT_TO_M*maxDepthVal >= (float)((DISPLAY_NumLineScaled-1)))&&(UNITS==NVD_METRIC)) )
    {
        /*display the list depth base on max depth*/
        for (uint8_t i = 0; i < DISPLAY_NumLineScaled; i++)
        {
            GUI_SetTextAlign(GUI_TA_RIGHT);
            /*display the depth scale value*/
            if (UNITS == NVD_IMPERIAL)
            {
                depthScaled_f = scaleDepthDisp;
            }
            else
            {
                depthScaled_f = CONST_FT_TO_M * scaleDepthDisp;
            }
            sprintf(strDisp, "%.0f", (depthScaled_f * (float)i));
            /*display value*/
            GUI_DispStringAt(strDisp, DIVEGRAPH_GRID_DEPTHVALUE_X0, DIVEGRAPH_GRID_DEPTHVALUE_Y0 + (i * DIVEGRAPH_GRID_Height));
        }
    }
    else
    {
        /*display the list depth base on max depth*/
        for (uint8_t i = 0; i < DISPLAY_NumLineScaled; i++)
        {
            GUI_SetTextAlign(GUI_TA_RIGHT);
            /*display the depth scale value*/
            if (UNITS == NVD_IMPERIAL)
            {
                depthScaled_f = scaleDepthDisp;
            }
            else
            {
                depthScaled_f = CONST_FT_TO_M * scaleDepthDisp;
            }
            sprintf(strDisp, "%.1f", (depthScaled_f * (float)i));
            /*display value*/
            GUI_DispStringAt(strDisp, DIVEGRAPH_GRID_DEPTHVALUE_X0, DIVEGRAPH_GRID_DEPTHVALUE_Y0 + (i * DIVEGRAPH_GRID_Height));
        }
    }
}
/*Display dive time (Minute), max depth on the right*/
static void DiveMenuDiveGraph_MinutesAndMaxDepth(void)
{
    /*display dive time*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_MINTextOnRight);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_DiveTimeValueOnRight);
    /*max depth in the bottom*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_UnitTextOnRight);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_DepthValueOnRight);
}
/*
Connect graph dot
*/
/*get the maximum current number of graph buffer*/
static uint16_t DiveGraph_GetMaxValidNumberInBuffer(uint16_t *buffAddr)
{
    int16_t cnt;
    for (cnt = (PROFILE_CHART_SIZE - 1); cnt >= 0; cnt--)
    {
        if (0U != *(buffAddr + cnt))
        {
            break; // not count any more when data is 0
        }
        else
        {
            
        }
    }
    return cnt;
}
/*Check the DECO depth status*/
GUI_COLOR DiveGraph_DecoColorCheck(uint16_t currDepth)
{
    GUI_COLOR colorGraph;
    /*Validate the deco*/
    if (BIT_DECO == (currDepth & BIT_DECO))
    {
        colorGraph = GUI_RED;
    }
    else
    {
        colorGraph = GUI_WHITE;
    }
    return colorGraph;
}
static void DiveGraph_graphDisplay(void)
{
    GUI_COLOR colorGraphDot;
    /*get the max valid item in buffer*/
    const uint16_t ItemInBuff_u16 = DiveGraph_GetMaxValidNumberInBuffer((uint16_t *)ProfileChartData);
    /*scale value in vertical*/
    const float scaleDisp_V = 160.0f / fMaxDepthFt; // 160px is the height of vertical
    /*scale value horizontal*/
    const float scaleDisp_H = 225.0f / ItemInBuff_u16; // 225px is the height of vertical
    GUI_POINT pointGraph[PROFILE_CHART_SIZE] = {0};    /*connect display each 2 dots*/
    /*set pen size*/
    GUI_SetPenSize(2);
    /*scan all the item in list*/
    for (uint16_t cnt_u16 = 0; cnt_u16 < ItemInBuff_u16; cnt_u16++)
    {
        /*set color base on depth status (DECO/NO-DECO)*/
        colorGraphDot = DiveGraph_DecoColorCheck(ProfileChartData[cnt_u16]);
        GUI_SetColor(colorGraphDot);
        /**/
        pointGraph[cnt_u16 + 1].x = (int16_t)((float)(cnt_u16 + 1) * scaleDisp_H);
        pointGraph[cnt_u16 + 1].y = (int16_t)((float)(ProfileChartData[cnt_u16] & DECOBITMASK) * scaleDisp_V);
        /*Draw the graph line*/
        GUI_DrawPolyLine(&pointGraph[cnt_u16], 2, DISPLAY_Pos_X0 + 5U, DIVEGRAPH_GRID_Y0);
    }
}
/*No display PO2 value condition check*/
static bool ConditionDisplayGraph(void)
{
    bool condition = false;
    if (GSM_MODE || GAUGE_MODE || AlarmStatusCheck_FullViolation())
    {
        condition = true;
    }
    else
    {
        /*do nothing*/
    }
    return condition;
}
void IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER(void)
{
    GUI_Clear();
    /*PO2 center content ->  Only disp*/
    if (ConditionDisplayGraph())
    {
        /*No display PO2 value*/
    }
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DecoStop_PO2_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_PO2_Value);
    }
    /*Draw the grid*/
    DiveMenuDiveGraph_DrawTheGrid();
    /*Display depth scaled*/
    DiveMenuDiveGraph_DisplayDepthScaled(fMaxDepthFt); // Max depth input
    /*Display max depth, total dive time*/
    DiveMenuDiveGraph_MinutesAndMaxDepth();
    /*display the graph line*/
    DiveGraph_graphDisplay();
}
void UpdOrFlasFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER(void)
{
    if (ConditionDisplayGraph())
    {
        /*No display PO2 value*/
    }
    else
    {
        HandleDisplayTextWithMemdev(IteStat_Select, DiveGraph_PO2_Value);
    }
}
