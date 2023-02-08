
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"

/*Check the set display ASCBG or N2 bar with settings*/
void SurfaceHandle_CheckDispASCBGnN2Bar(void)
{
    if(AlarmStatusCheck_FullViolation())
    {
        StopDisplay_N2_GF_Bars();
    }
    else
    {
        /*Check the settings selected N2Bar or ASCBG Bar*/
        if(((CC_MODE)||(OC_MODE)||(SM_MODE)||(BO_MODE)))
        {
            /*
            MAINDISPLAY_N2_OR_GF_BAR
            1 : N2
            0 : GF
            */
            if((MAINDISPLAY_N2_OR_GF_BAR)||(CONSV_SPORT == GUI_CONSV_Switch)) //When user setting is N2 and  only in Sport conservatism
            {
                DisplayN2(TLBGVal);
            }
            else
            {
                DisplayGF(GFBGVal);
            }
        }
    }
}
