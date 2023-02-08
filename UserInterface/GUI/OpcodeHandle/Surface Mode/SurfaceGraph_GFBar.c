#include "SurfaceMode.h"
#include "SurfaceGraph_GFN2.h"
#include "..\Dive Mode\DiveMode.h"

void GF_SepColor(uint8_t Value, uint8_t GFBGMaxRange, void (**DrawFunc)(int, int, int, int, int), GUI_COLOR* DrawColor)
{
    GF_LevelDispMode FillLevel;
    if(Value<GFBGMaxRange)
    {
        *DrawFunc = &GUI_AA_FillRoundedRect;
        FillLevel = GF_Fill;
    }
    else
    {
        *DrawFunc = &GUI_AA_DrawRoundedRect;
        FillLevel = GF_Draw;
    }
    /*Base on the value then change the level color seperated*/
    if(Value < CONSER_TEC_GFLOW)
    {
        /*From the bottom segment to the middle segment representing a GF <= GF Low set shall be colored in green*/
        *DrawColor = (FillLevel ? GUI_GREEN : GUI_DARKGREEN);
    }
    else if(Value <= CONSER_TEC_GFHIGH)
    {
        /*The segments representing GFs >= GF Low and <= GF High shall be yellow (deco)*/
        *DrawColor = (FillLevel ? GUI_YELLOW : GUI_DARKYELLOW);
    }
    else
    {
        *DrawColor = (FillLevel ? GUI_DARKRED : GUI_DARKRED);
    }
}
/**
 * @brief Flashing GF
 *
 * @return unsigned char
 */
unsigned char displayGF_CheckFlashing(void)
{
    unsigned char retFlashing = true;
    if((AlarmStatusCheck_CV_GF90()||
            (AlarmStatusCheck_FullViolation() && AlarmStatusCheck_GradientFactor())) &&
            (FLASHING_STATE_ON==FlashingState_u8))
    {
        retFlashing = false;
    }
    else
    {
        /*Do nothing*/
    }
    return retFlashing;
}
unsigned char displayN2_CheckFlashing(void)
{
    /*Flashing N2*/
    unsigned char retFlashing = true;
    if((AlarmStatusCheck_DecoWarning())&&(FLASHING_STATE_ON==FlashingState_u8))
    {
        retFlashing = false;
    }
    else
    {
        /*Do nothing*/
    }
    return retFlashing;
}
void DisplayGF(int Value)
{
    /*Check the flashing*/
    GUI_MEMDEV_Handle hMemDevLocal;
    void (*pFunc)(int, int, int, int, int);
    GUI_COLOR LevelColor;
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->Width, Pos_GFBar->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->X1, Pos_GFBar->Y1);
    if(displayGF_CheckFlashing())
    {
        /*Draw the bar*/
        GUI_SetPenSize(1);
        /*Always draw the bottom big segment is Green*/
        /*Heigh of GF bar is larger 3 times small GF bar*/
        /*draw the outline only with last bar when GF is 0*/
        if(Value>0)
        {
            pFunc = &GUI_AA_FillRoundedRect;
            GUI_SetColor(GUI_GREEN);
        }
        else
        {
            pFunc = &GUI_AA_DrawRoundedRect;
            GUI_SetColor(GUI_DARKGREEN);
        }
        pFunc(X0_GF_Bar, Y0_GF_BotGreSeg, X1_GF_Bar, Y1_GF_BotGreSeg, r_GF_Seg);
        /*The top (big) segment is filled Red when GF > 100% otherwise always draw Red*/
        GUI_SetColor(GUI_DARKRED);
        if(Value>100)
        {
            pFunc = &GUI_AA_FillRoundedRect;
        }
        else
        {
            pFunc = &GUI_AA_DrawRoundedRect;
        }
        pFunc(X0_GF_Bar, Y0_GF_TopRedSeg, X1_GF_Bar, Y1_GF_TopRedSeg, r_GF_Seg);
        /*Calculate the max input range of GFBG value*/
        uint8_t GFBGMaxInRange = 0x00;
        if(Value <= GF_SCALE)
        {
            /*	No calculate -> No fill any segments when below mininum scale
             * The GFBGMaxIrange is 0*/
        }
        else
        {
            GFBGMaxInRange = (uint8_t)((Value-1)/GF_SCALE);
            GFBGMaxInRange = ((GFBGMaxInRange+1)*GF_SCALE);
        }
        for(uint8_t i_u8 = 0; i_u8 <= Max_GF_Level; i_u8++)
        {
            GF_SepColor(((i_u8)*GF_SCALE), GFBGMaxInRange, &pFunc, &LevelColor);
            GUI_SetColor(LevelColor);
            pFunc(X0_GF_Bar, Y0_GF_Seg + ((Max_GF_Level - i_u8)*(HeightOfEachSeg + YSpace_GF_Seg)),\
                  X1_GF_Bar, Y1_GF_Seg + ((Max_GF_Level - i_u8)*(HeightOfEachSeg + YSpace_GF_Seg)),\
                  r_GF_Seg);
        }
    }
    else
    {
        /*Do nothing*/
    }
    /*Display the text GF*/
    SetFont_2;
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_GF), Pos_GFBar->X, Y_GF_Text);
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
