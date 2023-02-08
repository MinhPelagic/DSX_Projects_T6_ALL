/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "..\Surface Mode\Surfacemode.h"
#include "..\Dive Mode\DiveMode.h"
/*
When the button pressed, check the heading status
*/
void CompassHandle_SetReferenceOrReverse(void)
{
    /*Reference Heading or Reverse Heading*/
    if(GUI_CompassHeadingStat==1)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_ReferenceHeading_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_ReferenceHeading_Value);
    }
    else if(GUI_CompassHeadingStat==2)
    {
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_ReverseHeading_Tittle);
        HandleDisplayTextWithMemdev(IteStat_Select, CompassMode_ReverseHeading_Value);
    }
    else
    {
        /*No display -> Keep clear portion*/
        ClearCompassReferencePortionOnBottomLeft();
    }
}
