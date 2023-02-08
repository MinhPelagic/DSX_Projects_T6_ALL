
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#define GTR_WARNING_LEVEL       (5U)
#define GTR_ALARM_LEVEL         (0U)
GUI_COLOR GTR_ColorHanlde(void)
{
    GUI_COLOR colorRet = GUI_WHITE;
    /*Empty : Red*/
    if(ATR == GTR_ALARM_LEVEL)
    {
        colorRet = GUI_RED;
    }
    /*below 5 Mins : Yellow*/
    else if(ATR <= GTR_WARNING_LEVEL)
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing -> Set default*/
    }
    return colorRet;
}
