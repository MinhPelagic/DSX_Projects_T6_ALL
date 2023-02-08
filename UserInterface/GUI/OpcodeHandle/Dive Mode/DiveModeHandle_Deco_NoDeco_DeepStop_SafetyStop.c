#include "L4X9_includes.h"
#include "DiveMode.h"

/*In default setting (no extra large Depth or Time)
Settings handle: Deco|No-Deco|Deep Stop|Safety Stop
*/
void SurfaceHandle_Deco_NoDeco_DeepStop_SafetyStop(void)
{
    if((DVSTAT == DIVEMODE_DEEPnSAFETYSTOP)&&(isSSdisplayON==true)) /*0x30 Deep Stop or Safety Stop*/
    {
        /* Display Tittle and Depth-Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_DeepOrSSStop_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DeepOrSSStop_DepthAndTime);
    }
    else if(DecoStatus)
    {
        /*DECO STOP*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_DecoStop_Tittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
        {
            HandleDisplayItemMdev(DiveMode_DecoStop_MaxDepth);
        }
        else
        {
            HandleDisplayItemMdev(DiveMode_DecoStop_DepthAndTime);
        }
    }
    else
    {
        /*No Deco / O2 Time tittle*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_NoDecoOrO2TimeTittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
            HandleDisplayItemMdev(DiveMode_DecoStop_MaxDepth);
        else
            HandleDisplayItemMdev(DiveMode_NoDecoOrO2TimeValue);
    }
}

/*Specific to extra large Depth
-> Put all content to right layout*/
void DiveHandleExtrDepth_NoDecoDecoDeepOrSSStopAndViolation(void)
{
    if(AlarmStatusCheck_FullViolation()) /*0x80: Full violation */
    {
        /*Display nothing -> Flashing write over*/
    }
    else if((DVSTAT == DIVEMODE_DEEPnSAFETYSTOP)&&(isSSdisplayON==true)) /*0x30 Deep Stop or Safety Stop*/
    {
        /* Display Tittle and Depth-Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveModeExtrDepth_DeepOrSSStop_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, DiveModeExtrDepth_DeepOrSSStop_DepthAndTime);
    }
    else if(DecoStatus)
    {
        /*DECO STOP*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveModeExtrDepth_DecoStop_Tittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
        {
            HandleDisplayItemMdev(DiveModeExtrDepth_DecoStop_MaxDepth);
        }
        else
        {
            HandleDisplayItemMdev(DiveModeExtrDepth_DecoStop_DepthAndTime);
        }
    }
    else
    {
        /*No Deco / O2 Time tittle*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveModeExtrDepth_NoDecoOrO2TimeTittle);
        /*Value*/
        if(Alarming.Bit.DepthMax == true)
        {
            HandleDisplayItemMdev(DiveModeExtrDepth_DecoStop_MaxDepth);
        }
        else
        {
            HandleDisplayItemMdev(DiveModeExtrDepth_NoDecoOrO2TimeValue);
        }
    }
}
