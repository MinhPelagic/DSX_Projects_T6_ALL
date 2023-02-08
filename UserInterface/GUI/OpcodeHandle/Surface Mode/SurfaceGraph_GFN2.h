#ifndef _GFN2BAR_H_
#define _GFN2BAR_H_

#include "SurfaceMode.h"

/*Display GF bar on the right side*/
#define X0_GF_Bar			295
#define HeightOfEachSeg		4	//Only choose value 4 because the r minimum is 2
#define YSpace_GF_Seg		2   //Space between 2 bar level
#define r_GF_Seg			2	//Radius of segment
#define Max_GF_Level		19
#define HeightOfBigSeg		2*HeightOfEachSeg
#define Y0_GF_TopRedSeg		52																//Y0 of big top red bar (Move up/down the bar)
#define Y1_GF_TopRedSeg 	Y0_GF_TopRedSeg + HeightOfBigSeg								//Y1 of big bottom green bar
#define Y0_GF_Seg			Y1_GF_TopRedSeg + YSpace_GF_Seg									//Y0 of each level bar
#define Y1_GF_Seg			Y0_GF_Seg + HeightOfEachSeg									//Y1 of each level bar
#define Y0_GF_BotGreSeg		Y0_GF_Seg + ((Max_GF_Level+1)*(HeightOfEachSeg + YSpace_GF_Seg))	//Y0 of big bottom green bar	
#define Y1_GF_BotGreSeg 	Y0_GF_BotGreSeg + HeightOfBigSeg							//Y1 of big bottom green bar
#define Y_GF_Text			Y1_GF_BotGreSeg + 3		//Because don't using display tranparent -> move down 3 pixel
#define GF_SCALE			5 //This value base on spec (0,..5)
/*N2 bar*/
#define X1_GF_Bar			320 - 1 //Due to the antialiasing then need -1
#define N2Bar_BorderLine_r		12 //The maximum of r was tested
#define N2Bar_Fill_r			4
#define N2Bar_X0				((Pos_GFBar->X0) + 4)
#define N2Bar_X1				(X1_GF_Bar 		 - 4)
#define N2Bar_Y0_MAX			((Pos_GFBar->Y0) + 4)
#define N2Bar_Y1				(Y1_GF_BotGreSeg)
#define N2Bar_Scale				(1.3f)//Scale pixel result with each level of N2 value (99 is max value of N2)
#define N2Bar_Y0				(N2Bar_Y1 - (int)((float)(Value)*N2Bar_Scale))//Minumum value of TLBG display + with N2Bar_Fill_r make sure display with this radius

typedef enum
/*When the bar display need fill level or not*/
{
    GF_Draw,
    GF_Fill
} GF_LevelDispMode;
extern uint8_t GUI_TecGF_Hi;
extern uint8_t GUI_TecGF_Lo;
unsigned char displayN2_CheckFlashing(void);
unsigned char displayGF_CheckFlashing(void);
#endif