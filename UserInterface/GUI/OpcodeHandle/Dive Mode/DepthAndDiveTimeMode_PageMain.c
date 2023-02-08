#include "L4X9_includes.h"
#include "DiveMode.h"


void DepthAndDiveTime_PressureDisplay(void);

/*condition check the display Dive time in center*/

static bool DepthDiveTime_CheckDecoStop(void)
{
    return DecoStatus;
}
bool DepthDiveTime_CodDispDiveTimeInCenter(void)
{
    return (Check_All_TMTs_Is_Off()||(!CheckIfGasToTMT_Assigned()));
}
/*Specific to extra large Depth
-> Put all content to right layout*/
void IniOrClrScrFunc_DIVE_DEPTH_AND_DIVETIME(void)
{
    GUI_Clear();
    DepthDiveTimeMode_DisplayDepth(IteStat_Initial);
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    if(AlarmStatusCheck_FullViolation()) /*0x80: Full violation */
    {
        /*Display nothing -> Flashing write over*/
    }
    else if((DVSTAT == DIVEMODE_DEEPnSAFETYSTOP)&&(isSSdisplayON==true)) /*0x30 Deep Stop or Safety Stop*/
    {
        /* Display Tittle and Depth-Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDeepOrSSStopTittle);
        HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_CenterDeepOrSSStopValue);
    }
    else if(DepthDiveTime_CheckDecoStop())
    {
        /*DECO STOP*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDecoStopTittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
        {
            HandleDisplayItemMdev(DepthDiveTimeMode_DecoStop_MaxDepth);
        }
        else
        {
            HandleDisplayItemMdev(DepthDiveTimeMode_DecoStop_DepthAndTime);
        }
    }
    else if(DepthDiveTime_CodDispDiveTimeInCenter())
    {
        /*Extra Dive Time in center*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDivetimeTittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDivetimeValue);
    }
    else
    {
        /*Dive time on left*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_DiveTimeLeft_Tittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_DiveTimeLeft_Value);
        /*Tank pressure on right*/
        DepthAndDiveTime_PressureDisplay();
    }
    /*Arrow alarm on top right*/
    DepthAndDiveTime_AlarmHandleDisplay2ArrowsUpDown();
    /*Alarm in the bottom*/
    HandleDisplayItemMdev(DepthDiveTimeMode_AlarmInBottom);
}

void UpdOrFlasFunc_DIVE_DEPTH_AND_DIVETIME(void)
{
    DepthDiveTimeMode_DisplayDepth(IteStat_Update);
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    if(AlarmStatusCheck_FullViolation()) /*0x80: Full violation */
    {
        /*Display nothing -> Flashing write over*/
    }
    else if((DVSTAT == DIVEMODE_DEEPnSAFETYSTOP)&&(isSSdisplayON==true)) /*0x30 Deep Stop or Safety Stop*/
    {
        /* Display Tittle and Depth-Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDeepOrSSStopTittle);
        HandleDisplayTextWithMemdev(IteStat_Select, DepthDiveTimeMode_CenterDeepOrSSStopValue);
    }
    else if(DepthDiveTime_CheckDecoStop())
    {
        /*DECO STOP*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDecoStopTittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
        {
            HandleDisplayItemMdev(DepthDiveTimeMode_DecoStop_MaxDepth);
        }
        else
        {
            HandleDisplayItemMdev(DepthDiveTimeMode_DecoStop_DepthAndTime);
        }
    }
    else if(DepthDiveTime_CodDispDiveTimeInCenter())
    {
        /*Extra Dive Time in center*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDivetimeTittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_CenterDivetimeValue);
    }
    else
    {
        /*Dive time on left*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_DiveTimeLeft_Tittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DepthDiveTimeMode_DiveTimeLeft_Value);
        /*Tank pressure on right*/
        DepthAndDiveTime_PressureDisplay();
    }
    /*Arrow alarm on top right*/
    DepthAndDiveTime_AlarmHandleDisplay2ArrowsUpDown();
    /*Alarm in the bottom*/
    HandleDisplayItemMdev(DepthDiveTimeMode_AlarmInBottom);
}

