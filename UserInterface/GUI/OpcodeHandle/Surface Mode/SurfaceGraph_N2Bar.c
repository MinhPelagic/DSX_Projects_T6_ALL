#include "SurfaceMode.h"
#include "SurfaceGraph_GFN2.h"
#include "..\Dive Mode\DiveMode.h"

/*Return the step color of N2*/
GUI_COLOR N2ColorReturn(int Value_i)
{
    GUI_COLOR ReturnColor;
    if(100 == Value_i)
    {
        ReturnColor = GUI_RED;
    }
    else if(Value_i>70)
    {
        ReturnColor = GUI_YELLOW;
    }
    else
    {
        ReturnColor = GUI_GREEN;
    }
    return ReturnColor;
}
void DisplayN2(int Value)
{
    /*Validate the value*/
    if(Value > 100U)
    {
        /*Do nothing*/
    }
    else
    {
        GUI_MEMDEV_Handle hMemDevLocal;
        hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->Width, Pos_GFBar->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hMemDevLocal);
        GUI_SetBkColor(GUI_BLACK);
        GUI_ClearRect(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->X1, Pos_GFBar->Y1);
        /*Display the text N2*/
        SetFont_2;
        GUI_SetColor(GUI_WHITE);
        GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_N2), Pos_GFBar->X, Y_GF_Text);
        /*Draw out line*/
        if(displayN2_CheckFlashing())
        {
            GUI_SetPenSize(1);
            GUI_SetColor(LineColor_SURFnDIVE);
            GUI_AA_DrawRoundedRect(Pos_GFBar->X0, Pos_GFBar->Y0 + 5, X1_GF_Bar, Y_GF_Text, N2Bar_BorderLine_r);
            /*Draw the level inside*/
            if(Value>0)
            {
                GUI_SetColor(N2ColorReturn(Value));
                GUI_AA_FillRoundedRect(N2Bar_X0, N2Bar_Y0, N2Bar_X1, N2Bar_Y1, (Value>N2Bar_Fill_r) ? N2Bar_Fill_r*2 : N2Bar_Fill_r);//Too small then need compare the r to display
            }
            else
            {
                /*Display nothing*/
            }
        }
        else
        {
            /*Do nothing to flashing*/
        }
        GUI_MEMDEV_CopyToLCD(hMemDevLocal);
        GUI_MEMDEV_Delete(hMemDevLocal);
    }

}
void StopDisplay_N2_GF_Bars(void)
{
    GUI_ClearRect(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->X1, Pos_GFBar->Y1);
}