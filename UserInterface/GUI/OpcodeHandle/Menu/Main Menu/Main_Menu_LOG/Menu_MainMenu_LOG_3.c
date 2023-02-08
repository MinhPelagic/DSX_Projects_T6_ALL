/******************************************************************************/
//File: LOG 3
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"
extern GUI_POINT LogChartPOINT_X_Y[];     // prepare Profile Chart Data for real-time chart use
//uint16_t Log3_Graph_POINT[100];
void SetSP_UNITSET(char* pStrRet);
/*Parameter display*/
#define DISPLAY_NumLineScaled	        (9u)
#define DISPLAY_Pos_X0			        (35u)
#define DISPLAY_HorizontalWidth	        (235u)
#define DISPLAY_Pos_X1			        (DISPLAY_Pos_X0 + DISPLAY_HorizontalWidth)
/*Grid parameters*/
#define LOG3_GRID_Y0                    (45u)
#define LOG3_GRID_Height                (20u) //Space between 2 line in vertical
#define LOG3_GRID_DEPTHVALUE_X0         (DISPLAY_Pos_X0 - 3U) //Depth value list on the left
#define LOG3_GRID_DEPTHVALUE_Y0         (34u) //Depth value list on the left
#define LOG3_GRID_SURF_TO_DEPTH_MAX     (uint8_t)(7.35*LOG3_GRID_Height)    //Pixel Span "from Surface to MaxDepth" 
#define LOG3_GRID_SURF_OFFSET           (15u)
#define LOG3_GRID_DEPTH_MAX_BLUEDASH    (LOG3_GRID_SURF_TO_DEPTH_MAX+LOG3_GRID_Y0)      // location for the MAX Depth blue dash line 

/*Context to display*/
const contentDispContext_st logmode3_UnitTextOnLeft =
{
    &SetSP_UNITSET,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_2,
    &Pos_LogData03_UnitTextOnLeft,
};
/*Depth text on right*/
const contentDispContext_st logmode3_UnitTextOnRight =
{
    &SetSP_UNITSET,
    &Unselect_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_LogData03_MaxDepthTextOnRight,
};
/*Minutes*/
const contentDispContext_st logmode3_MINTextOnRight =
{
    &DiveMode_DecoStop_Minute_Text_Context, /*Reuse*/
    &Unselect_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_LogData03_MinTextOnRight,
};
void logmode3_DiveTimeValueOnRight_Context(char* pStrRet)
{
    sprintf(pStrRet, "%d", Log_Data_7[log01HighlightItem_i].EDTsec/60); //Dive time in minutes
}
const contentDispContext_st logmode3_DiveTimeValueOnRight =
{
    &logmode3_DiveTimeValueOnRight_Context,
    &Unselect_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_LogData03_MinValueOnRight,
};
/*max depth*/
void logmode3_MaxDepthOnRightContext(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f", (0.1*Log_Data_7[log01HighlightItem_i].MaxDepthFt10));
    else
        sprintf(pStrRet, "%.0f", (0.03*Log_Data_7[log01HighlightItem_i].MaxDepthFt10));
}
const contentDispContext_st logmode3_DepthValueOnRight =
{
    &logmode3_MaxDepthOnRightContext,
    &Unselect_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_LogData03_MaxDepthValueOnRight, /*Reuse*/
};
/*draw vertial and horizontal lines*/
static void logmode3_DrawTheGrid(void)
{
    /*Draw the lines*/
    GUI_SetColor(GUI_GRAY);
    GUI_DrawVLine(DISPLAY_Pos_X0 + 5, LOG3_GRID_Y0 - 5, 210);
    for(uint8_t i=0; i<DISPLAY_NumLineScaled; i++)
    {
        GUI_DrawHLine(LOG3_GRID_Y0+i*LOG3_GRID_Height, DISPLAY_Pos_X0, DISPLAY_Pos_X1);
    }
}
/*base on the max depth -> display the depth scaled on the left*/
static void logmode3_DisplayDepthScaled(float maxDepthVal)
{
    char strDisp[LangMaxLength];
    float scaleDepthDisp = 0;
    /*scale each space of max depth value*/
    scaleDepthDisp = maxDepthVal/(DISPLAY_NumLineScaled-1);
    /*display the FT/M text*/
    HandleDisplayTextWithMemdev(IteStat_Select, logmode3_UnitTextOnLeft);
    if( ((maxDepthVal >= (float)((DISPLAY_NumLineScaled-1)))&&(UNITS==NVD_IMPERIAL))
            ||((CONST_FT_TO_M*maxDepthVal >= (float)((DISPLAY_NumLineScaled-1)))&&(UNITS==NVD_METRIC)) )
    {
        /*display the list depth base on max depth*/
        for(uint8_t i=0; i<DISPLAY_NumLineScaled; i++)
        {
            GUI_SetTextAlign(GUI_TA_RIGHT);
            /*display the depth scale value*/
            if(UNITS==NVD_IMPERIAL)
                sprintf(strDisp, "%.0f", (scaleDepthDisp*(float)i));
            else
                sprintf(strDisp, "%.0f", CONST_FT_TO_M*(scaleDepthDisp*(float)i));
            /*display value*/
            GUI_DispStringAt(strDisp, LOG3_GRID_DEPTHVALUE_X0, LOG3_GRID_DEPTHVALUE_Y0 + (i*LOG3_GRID_Height));
        }
    }
    else
    {
        /*display the list depth base on max depth*/
        for(uint8_t i=0; i<DISPLAY_NumLineScaled; i++)
        {
            GUI_SetTextAlign(GUI_TA_RIGHT);
            /*display the depth scale value*/
            if(UNITS==NVD_IMPERIAL)
                sprintf(strDisp, "%.1f", (scaleDepthDisp*(float)i));
            else
                sprintf(strDisp, "%.1f", CONST_FT_TO_M*(scaleDepthDisp*(float)i));
            /*display value*/
            GUI_DispStringAt(strDisp, LOG3_GRID_DEPTHVALUE_X0, LOG3_GRID_DEPTHVALUE_Y0 + (i*LOG3_GRID_Height));
        }
    }
}
/*Display dive time (Minute), max depth on the right*/
static void logmode3_displayMinuteAndMaxDepth(void)
{
    /*display dive time*/
    HandleDisplayTextWithMemdev(IteStat_Select, logmode3_DiveTimeValueOnRight);
    /*display MIN text*/
    HandleDisplayTextWithMemdev(IteStat_Select, logmode3_MINTextOnRight);
    /*max depth in the bottom*/
    HandleDisplayTextWithMemdev(IteStat_Select, logmode3_UnitTextOnRight);
    HandleDisplayTextWithMemdev(IteStat_Select, logmode3_DepthValueOnRight);
    /*draw horizontal line max depth (cyan)*/
}
/*Connect graph dot*/
static void logmode3_graphDisplay(void)
{

    float MaxScaler = 1.0;

    GUI_SetColor(GUI_WHITE);
    GUI_SetPenSize(2);

    MaxScaler = (float)LOG3_GRID_SURF_TO_DEPTH_MAX / (0.1*Log_Data_7[log01HighlightItem_i].MaxDepthFt10);

    for(uint8_t n=0; n<(PROFILE_CHART_SIZE/2); n++)
    {
        // X: Time Series
        LogChartPOINT_X_Y[n].x = n*2;

        // Y: Depth Series
        LogChartPOINT_X_Y[n].y = (int16_t)(MaxScaler * (Log_Chart_7[log01HighlightItem_i].Data[n]&0x0FFF))+LOG3_GRID_SURF_OFFSET;    // scaling down by (1/2)
        Log_Chart.Data[n] = LogChartPOINT_X_Y[n].y;
    }

    for(uint8_t i=0; i<((PROFILE_CHART_SIZE/2)-1); i++)
    {
        //Log3_Graph_POINT[i] = i;
        //connect every 2 points
        if((Log_Chart_7[log01HighlightItem_i].Data[i] & 0x4000)==0)
            GUI_SetColor(GUI_WHITE);    // Deco Flag is OFF
        else
            GUI_SetColor(GUI_RED);      // Deco Flag is ON

        GUI_DrawPolyLine((GUI_POINT*)(LogChartPOINT_X_Y + i), 2, DISPLAY_Pos_X0 + 5, 28);
    }
}
void IniOrClrScrFunc_S37_LOG_DATA3(void)
{
    GUI_Clear();
    /*Title*/
    DisplayTimeOfLOGatTOP();
    /*Draw the grid*/
    logmode3_DrawTheGrid();
    /*Display depth scaled*/
    logmode3_DisplayDepthScaled(0.111*Log_Data_7[log01HighlightItem_i].MaxDepthFt10); //Max depth input
    /*Display max depth, total dive time*/
    logmode3_displayMinuteAndMaxDepth();
    /*Display graph*/
    logmode3_graphDisplay();
    /*bottom icons*/
    Display_Icon_Buttons(IconBottDisp_BackHomeNext);
}
