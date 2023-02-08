/******************************************************************************/
// File: GPS Menu
// Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_WayfinderMenu.h"

uint8_t DelIndex;

/*When button pressed increase/decrease*/
void HandleButton_GPSMenu_DeleteLocation(DSX_OPCODE_t *newOpVal, DSX_OPCODE_t *oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
                    S520_GPS_DELETE_LOCATION /*H_U ~ BACK*/,
                    DataDec /*L*/,
                    DataInc /*M*/,
                    *oldOpVal /*M2*/,
                    SaveAndDone /*R*/,
                    CheckConditions,
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal);
    /*Handle status specific*/
    if (DataInc == (*newOpVal)) // press increase
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*When reach to bottom of list*/
        if(WfinderCtrVar.currentHighlight == (MaxItemInList - 1u))
        {
            /*when reach to bottom but still have more data -> display all*/
            if((WfinderCtrVar.startIndex + WfinderCtrVar.currentHighlight)<WfinderCtrVar.maxItemDisp)
            {
                WfinderCtrVar.dispAllItem = TRUE;
                WfinderCtrVar.startIndex += 1u;
            }
            else
            {
                /*Do nothing*/
            }
        }
        else if(WfinderCtrVar.currentHighlight == (WfinderCtrVar.maxItemDisp - 1))
        {
            /*Do nothing*/
        }
        else
        {
            WfinderCtrVar.posUnhighlight = WfinderCtrVar.currentHighlight;
            WfinderCtrVar.currentHighlight += 1u;
        }
        /*trigger update display*/
        WfinderCtrVar.dispUpdate = TRUE;
    }
    else if (DataDec == (*newOpVal)) // press decrease
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*when reach to top of page*/
        if(WfinderCtrVar.currentHighlight==0)
        {
            if(WfinderCtrVar.startIndex==0)
            {
                /*Do nothing*/
            }
            else
            {
                WfinderCtrVar.dispAllItem = TRUE;
                WfinderCtrVar.startIndex -= 1u;
            }
        }
        else
        {
            /*Decrease*/
            WfinderCtrVar.posUnhighlight = WfinderCtrVar.currentHighlight;
            WfinderCtrVar.currentHighlight -= 1u;
        }
        /*trigger update display*/
        WfinderCtrVar.dispUpdate = TRUE;
    }
    else if (SaveAndDone == (*newOpVal)) // press save
    {

        uint8_t Loc = WfinderCtrVar.currentHighlight+WfinderCtrVar.startIndex;
        /*Set and save current target*/
        Select_Target_Loc(Loc);
        GnssGGA.Latitude_Target_DD  = GUI_WayFinder.GPS_Loc[Loc].Latitude;
        GnssGGA.Longitude_Target_DD = GUI_WayFinder.GPS_Loc[Loc].Longitude;

        if(WfinderCtrVar.maxItemDisp==0)
        {
            NewOpcode = S520_GPS_DELETE_LOCATION;
        }
        else
        {
            /*Jump to page confirm Delete location*/
            *newOpVal = S522_GPS_DELETE_LOCATION;
            DelIndex =	WfinderCtrVar.currentHighlight;
        }
        /*Delete current location*/


    }
    else if(CheckConditions==(*newOpVal))
    {
        *newOpVal = ReturnToSurfMain();
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
