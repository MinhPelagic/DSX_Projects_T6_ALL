/******************************************************************************/
//File: IconSEPIA.c
//Description:Icon for DSX
//Created by:DucThinh
//History: 6/15/2019 Created
//
/*****************************************************************************/
#include "L4X9_includes.h"

/*--Private define--*/
#define PenSize_Default		2
#define r_MainCircle		10//13
#define r_SubCircle			7//10
#define StartAngle			0
#define EndAngle			360
//Resize the arrow
#define ArrowVal_1			5//8
#define ArrowVal_2			2//3
/*Intenal variables*/
static const GUI_POINT Arrow_BACK[]= {
    {-ArrowVal_1,0},
    {+0,-ArrowVal_1},
    {+0,-ArrowVal_2},
    {+ArrowVal_1,-ArrowVal_2},
    {+ArrowVal_1,+ArrowVal_2},
    {+0,+ArrowVal_2},
    {+0,+ArrowVal_1},
    {-ArrowVal_1,0},
};
#define SizeOfArrowBack	(sizeof(Arrow_BACK)/sizeof(GUI_POINT))
static const GUI_POINT Arrow_UP[]= {
    {+0,-ArrowVal_1},
    {+ArrowVal_1,+0},
    {+ArrowVal_2,+0},
    {+ArrowVal_2,+ArrowVal_1},
    {-ArrowVal_2,+ArrowVal_1},
    {-ArrowVal_2,+0},
    {-ArrowVal_1,+0},
    {+0,-ArrowVal_1},
};
#define SizeOfArrowUP	(sizeof(Arrow_UP)/sizeof(GUI_POINT))
static const GUI_POINT Arrow_NEXT[]=
{
    {+ArrowVal_1, 0},
    {0,+ArrowVal_1},
    {0,+ArrowVal_2},
    {-ArrowVal_1,+ArrowVal_2},
    {-ArrowVal_1,-ArrowVal_2},
    {+0,-ArrowVal_2},
    {0,-ArrowVal_1},
    {+ArrowVal_1,0},
};

#define SizeOfArrowNEXT	(sizeof(Arrow_NEXT)/sizeof(GUI_POINT))
static const GUI_POINT Arrow_DOWN[]=
{
    {+0,+ArrowVal_1},
    {-ArrowVal_1,+0},
    {-ArrowVal_2,+0},
    {-ArrowVal_2,-ArrowVal_1},
    {+ArrowVal_2,-ArrowVal_1},
    {+ArrowVal_2,+0},
    {+ArrowVal_1,+0},
    {+0,+ArrowVal_1},
};
#define SizeOfArrowDown	(sizeof(Arrow_DOWN)/sizeof(GUI_POINT))
static const GUI_POINT SelectButton[]= {
    {+5,-7},
    {+7,-3},
    {-2,+8},
    {-8,+1},
    {-5,-3},
    {-2,+1},
};

#define SizeOfSelectButton	(sizeof(SelectButton)/sizeof(GUI_POINT))
#define home_dim_a      (5)
#define home_dim_b      (3)
#define home_dim_c      (1)
static const GUI_POINT HomeButton[]=
{
    {-home_dim_a,+0},
    {+0,-home_dim_a},
    {+home_dim_a,+0},
    {+home_dim_b,+0},
    {+home_dim_b,+home_dim_a},
    {+home_dim_c,+home_dim_a},
    {+home_dim_c,+home_dim_c},
    {-home_dim_c,+home_dim_c},
    {-home_dim_c,+home_dim_a},
    {-home_dim_b,+home_dim_a},
    {-home_dim_b,+0},
};
#define SizeOfHomeButton	(sizeof(HomeButton)/sizeof(GUI_POINT))
/*External variables*/
extern uint16_t BackColor;
extern uint16_t TextColor;

/*-------END ICON DSX HANDLER----------*/
/*NPTHINH start*/

/*
Diplay the BACK button
*/
void DispButton_BACK(const GUI_POINT* Pos)
{
    /*Draw the outline circle*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_SubCircle, r_SubCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
    GUI_AA_FillPolygon(Arrow_BACK, SizeOfArrowBack, Pos->x, Pos->y);
}
void DispButton_NEXT(const GUI_POINT* Pos)
{
    /*Draw the outline circle*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
    GUI_AA_FillPolygon(Arrow_NEXT, SizeOfArrowNEXT, Pos->x, Pos->y);
}

void DispButton_UP(const GUI_POINT* Pos)
{
    /*Draw the outline circle*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
//    GUI_RotatePolygon(Arrow_roate, Arrow_UP, SizeOfArrowUP, (float)90);
    GUI_AA_FillPolygon(Arrow_UP, SizeOfArrowUP, Pos->x, Pos->y);
}
void DispButton_DOWN(const GUI_POINT* Pos) {
    /*Draw the outline circle*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
    GUI_AA_FillPolygon(Arrow_DOWN, SizeOfArrowDown, Pos->x, Pos->y);
};
void DispButton_SELECT(const GUI_POINT* Pos)
{
    /*Draw the outline circle*/
    GUI_SetColor(GUI_GREEN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
    GUI_AA_FillPolygon(SelectButton, SizeOfSelectButton, Pos->x, Pos->y);
};
void DispButton_HOME(const GUI_POINT* Pos)
{
    /*Draw the outline circle*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(PenSize_Default);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_SubCircle, r_SubCircle, StartAngle, EndAngle);
    /*Draw the arrow*/
    GUI_AA_FillPolygon(HomeButton, SizeOfHomeButton, Pos->x, Pos->y);
};
void DrawTheSlash(const GUI_POINT* Pos)
{
    /*Draw the SLASH symbol*/
    GUI_SetColor(GUI_CYAN);
    GUI_AA_DrawLine(Pos->x, Pos->y, Pos->x - 5, Pos->y + 20);
};
/*Cancel icon*/
#define aCancelWidth       10 //Width of cancel icon
#define aCancelWidthdiv2   5//= aCancelWidth/2
static const GUI_POINT cancelIcon[]=
{
    {+0, +0},
    {+aCancelWidth, +aCancelWidth},
    {+aCancelWidth, +0},
    {+0, +aCancelWidth},
};
void DispButton_CANCEL(const GUI_POINT* Pos)
{
    GUI_SetColor(GUI_RED);
    GUI_AA_DrawArc(Pos->x, Pos->y, r_MainCircle, r_MainCircle, StartAngle, EndAngle);
    /*Draw the lines*/
    GUI_SetPenSize(3);
    /*recenter*/
    int _posX = Pos->x - aCancelWidthdiv2;
    int _posY = Pos->y - aCancelWidthdiv2;
    GUI_AA_DrawLine(_posX + cancelIcon[0].x, _posY + cancelIcon[0].y, _posX + cancelIcon[1].x, _posY + cancelIcon[1].y);
    GUI_AA_DrawLine(_posX + cancelIcon[2].x, _posY + cancelIcon[2].y, _posX + cancelIcon[3].x, _posY + cancelIcon[3].y);
}