
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
/*OC Left color*/
GUI_COLOR SurfaceMode_OCLeftTittleColor(void)
{
    GUI_COLOR retColor = GUI_GRAY;
    if(FindGasNumOfDiveMode(DIVE_MODE)==TANK_1)
    {
        retColor = SurfaceMode_SurfTime_TitleText_Color();
    }
    else
    {
        /*keep initial value*/
    }
    return retColor;
}
GUI_COLOR SurfaceMode_OCLeftValueColor(void)
{
    GUI_COLOR retColor = GUI_GRAY;
    if(FindGasNumOfDiveMode(DIVE_MODE)==TANK_1)
    {
        if(Alarming2.Bit.EndP == true)
            retColor = GUI_RED;
        else if(Alarming2.Bit.TurnP == true)
            retColor = GUI_YELLOW;
        else
            retColor = TxtColor_Select;
    }
    else
    {
        if((Alarming2.Bit.SwitchP == true)&&(L2R_PSI_Diff() < 0))
            retColor = GUI_GREEN;
    }
    return retColor;
}
/*OC Right color*/
GUI_COLOR SurfaceMode_OCRightTittleColor(void)
{
    GUI_COLOR retColor = GUI_GRAY;
    if(FindGasNumOfDiveMode(DIVE_MODE)==TANK_2)
    {
        retColor = SurfaceMode_SurfTime_TitleText_Color();
    }
    else
    {
        /*keep initial value*/
    }
    return retColor;
}
GUI_COLOR SurfaceMode_OCRightValueColor(void)
{
    GUI_COLOR retColor = GUI_GRAY;
    if(FindGasNumOfDiveMode(DIVE_MODE)==TANK_2)
    {
        if(Alarming2.Bit.EndP == true)
            retColor = GUI_RED;
        else if(Alarming2.Bit.TurnP == true)
            retColor = GUI_YELLOW;
        else
            retColor = TxtColor_Select;
    }
    else
    {
        if((Alarming2.Bit.SwitchP == true)&&(L2R_PSI_Diff() > 0))
            retColor = GUI_GREEN;
    }
    return retColor;
}
