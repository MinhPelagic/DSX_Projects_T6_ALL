#include "SurfaceMode.h"
typedef struct
{
    const uint8_t numPoints;
    const GUI_POINT* pPointData;
    const GUI_COLOR colorDrawOutline;
    const GUI_COLOR colorFillIn;
    const int x0;
    const int y0;
} SurfaceGraph_AscentBar_ts;

#define Height_A                22 /*Heigh of each bar*/
#define ASCBAR_POS_OffSet       4 /*Space between 2 level in veritcal*/
#define ASCBAR_POS_OffSet_1     4 /*Space inside 1 level in horizontal*/

#define Width_B1                3
#define Width_B2                Width_B1
#define Width_B3                Width_B2 + ASCBAR_POS_OffSet_1
#define Width_B4                Width_B3
#define Width_B5                Width_B4 + ASCBAR_POS_OffSet_1
#define Width_B6                Width_B5
#define Width_B7                Width_B6 + ASCBAR_POS_OffSet_1
#define Width_B8                Width_B7
#define Width_B9                Width_B8 + ASCBAR_POS_OffSet_1
#define ASCBAR_POS_X0           4
#define ASCBAR_POS_Y0_LEV_5     40
#define ASCBAR_POS_Y0_LEV_4     (ASCBAR_POS_Y0_LEV_5 + ASCBAR_POS_OffSet + Height_A)
#define ASCBAR_POS_Y0_LEV_3     (ASCBAR_POS_Y0_LEV_4 + ASCBAR_POS_OffSet + Height_A)
#define ASCBAR_POS_Y0_LEV_2     (ASCBAR_POS_Y0_LEV_3 + ASCBAR_POS_OffSet + Height_A)
#define ASCBAR_POS_Y0_LEV_1     (ASCBAR_POS_Y0_LEV_2 + ASCBAR_POS_OffSet + Height_A)
#define ASCBAR_NUM_OF_LEVEL     5u // There are 5 segments with 5 levels
#define ASCBR_1ST_LEV_POINTS    3 //Triangle has 3 points
#define ASCBR_2ND_LEV_POINTS    4 //Trapezoid has 4 points
static const GUI_POINT AR_Level_1[ASCBR_1ST_LEV_POINTS]=
{
    /*Triangle level 1*/
    {0u, 0u},
    {Width_B1, 0u},
    {0u, Height_A},
};
static const GUI_POINT AR_Level_2[ASCBR_2ND_LEV_POINTS]=
{
    {0u, 0u},
    {Width_B3, 0u},
    {Width_B2, Height_A},
    {0u, Height_A},
};
static const GUI_POINT AR_Level_3[ASCBR_2ND_LEV_POINTS]=
{
    {0u, 0u},
    {Width_B5, 0u},
    {Width_B4, Height_A},
    {0u, Height_A},
};
static const GUI_POINT AR_Level_4[ASCBR_2ND_LEV_POINTS]=
{
    {0u, 0u},
    {Width_B7, 0u},
    {Width_B6, Height_A},
    {0u, Height_A},
};
static const GUI_POINT AR_Level_5[ASCBR_2ND_LEV_POINTS]=
{
    {0u, 0u},
    {Width_B9, 0u},
    {Width_B8, Height_A},
    {0u, Height_A},
};
SurfaceGraph_AscentBar_ts ascenBarDatArray[ASCBAR_NUM_OF_LEVEL] =
{
    {ASCBR_1ST_LEV_POINTS, AR_Level_1, GUI_DARKGREEN, GUI_GREEN, ASCBAR_POS_X0, ASCBAR_POS_Y0_LEV_1}, /*1st level is triangle*/
    {ASCBR_2ND_LEV_POINTS, AR_Level_2, GUI_DARKGREEN, GUI_GREEN, ASCBAR_POS_X0, ASCBAR_POS_Y0_LEV_2}, //
    {ASCBR_2ND_LEV_POINTS, AR_Level_3, GUI_DARKGREEN, GUI_GREEN, ASCBAR_POS_X0, ASCBAR_POS_Y0_LEV_3},
    {ASCBR_2ND_LEV_POINTS, AR_Level_4, GUI_DARKYELLOW, GUI_YELLOW, ASCBAR_POS_X0, ASCBAR_POS_Y0_LEV_4},
    {ASCBR_2ND_LEV_POINTS, AR_Level_5, GUI_DARKRED, GUI_RED, ASCBAR_POS_X0, ASCBAR_POS_Y0_LEV_5},
};

void Display_AR(int Value)
{
    GUI_MEMDEV_Handle hMemDevLocal;
    /**/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_ARBar->X0, Pos_ARBar->Y0, Pos_ARBar->Width, Pos_ARBar->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_ARBar->X0, Pos_ARBar->Y0, Pos_ARBar->X1, Pos_ARBar->Y1);
    SetFont_2;
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_AR), Pos_ARBar->X, Pos_ARBar->Y);
    /**/
    /*When reached to maximum value -> Flashing*/
    if((LCD_Flash.Bit.ASCBar) && (FLASHING_STATE_ON==FlashingState_u8))
    {
        /*Do nothing -> Cleared already to flashing*/
    }
    else
    {
        for(uint8_t cnt_u8 = 0; cnt_u8 < ASCBAR_NUM_OF_LEVEL; cnt_u8++)
        {
            /*Value is below */
            if(Value <= cnt_u8)
            {
                GUI_SetColor(ascenBarDatArray[cnt_u8].colorDrawOutline);
                GUI_AA_DrawPolyOutline(
                    ascenBarDatArray[cnt_u8].pPointData,
                    ascenBarDatArray[cnt_u8].numPoints,
                    1, /*thickness default is 1*/
                    ascenBarDatArray[cnt_u8].x0,
                    ascenBarDatArray[cnt_u8].y0);
            }
            else
            {
                GUI_SetColor(ascenBarDatArray[cnt_u8].colorFillIn);
                /*Draw the outline to make display better*/
                GUI_AA_DrawPolyOutline(
                    ascenBarDatArray[cnt_u8].pPointData,
                    ascenBarDatArray[cnt_u8].numPoints,
                    1,
                    ascenBarDatArray[cnt_u8].x0,
                    ascenBarDatArray[cnt_u8].y0);
                GUI_AA_FillPolygon(
                    ascenBarDatArray[cnt_u8].pPointData,
                    ascenBarDatArray[cnt_u8].numPoints,
                    ascenBarDatArray[cnt_u8].x0,
                    ascenBarDatArray[cnt_u8].y0);
            }
        }
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
};
