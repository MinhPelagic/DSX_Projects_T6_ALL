/******************************************************************************/
//File:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"

#define NavArrow_aHeight         (5)    //  1/2 triangle height
#define NavArrow_bWidth          (20)   //  triangle width
#define NavArrow_2arrowsSpace    (8)    //  space between 2 arrows
#define NavArrow_Y0              (Pos_Compass_DoubleArrowsLeft->Y0 + NavArrow_aHeight + 5U) //Use the same with 4 arrows
#define NavArrowLeft_01_X0       (Pos_Compass_DoubleArrowsLeft->X0)
#define NavArrowLeft_02_X0       (Pos_Compass_DoubleArrowsLeft->X0 + NavArrow_bWidth + NavArrow_2arrowsSpace)
#define NavArrowRight_01_X0      (Pos_Compass_DoubleArrowsRight->X1)
#define NavArrowRight_02_X0      (Pos_Compass_DoubleArrowsRight->X1 - NavArrow_bWidth - NavArrow_2arrowsSpace)
#define NavArrow_nPoints         (3) //number of points triangle
/*Arrow to left*/
static const GUI_POINT navArrToLeft[NavArrow_nPoints]=
{
    {+0, +0},
    {+NavArrow_bWidth, -NavArrow_aHeight},
    {+NavArrow_bWidth, +NavArrow_aHeight},
};
/*Arrow to right*/
static const GUI_POINT navArrToRight[NavArrow_nPoints]=
{
    {+0, +0},
    {-NavArrow_bWidth, -NavArrow_aHeight},
    {-NavArrow_bWidth, +NavArrow_aHeight},
};
void Display_NavigateArrows(arrowRef_e navLeftRightStat)
{
    GUI_MEMDEV_Handle hMemDevLocal = 0;
    GUI_SetColor(GUI_YELLOW);
    /*When navigate left*/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Compass_DoubleArrowsLeft->X0, Pos_Compass_DoubleArrowsLeft->Y0, Pos_Compass_DoubleArrowsLeft->Width, Pos_Compass_DoubleArrowsLeft->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_Compass_DoubleArrowsLeft->X0, Pos_Compass_DoubleArrowsLeft->Y0, Pos_Compass_DoubleArrowsLeft->X1, Pos_Compass_DoubleArrowsLeft->Y1);
    if(arrowReferLeft == navLeftRightStat)
    {
        /*Draw double triangle*/
        GUI_AA_FillPolygon(navArrToLeft, NavArrow_nPoints, NavArrowLeft_01_X0, NavArrow_Y0);
        GUI_AA_FillPolygon(navArrToLeft, NavArrow_nPoints, NavArrowLeft_02_X0, NavArrow_Y0);
    }
    else
    {
        /*Do nothing*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
    /*When navigate right*/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Compass_DoubleArrowsRight->X0, Pos_Compass_DoubleArrowsRight->Y0, Pos_Compass_DoubleArrowsRight->Width, Pos_Compass_DoubleArrowsRight->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_Compass_DoubleArrowsRight->X0, Pos_Compass_DoubleArrowsRight->Y0, Pos_Compass_DoubleArrowsRight->X1, Pos_Compass_DoubleArrowsRight->Y1);
    if(arrowReferRight == navLeftRightStat)
    {
        /*Draw double triangle*/
        GUI_AA_FillPolygon(navArrToRight, NavArrow_nPoints, NavArrowRight_01_X0, NavArrow_Y0);
        GUI_AA_FillPolygon(navArrToRight, NavArrow_nPoints, NavArrowRight_02_X0, NavArrow_Y0);
    }
    else
    {
        /*Do nothing*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
