/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveMenu_DecoStops.h"

/*When button pressed increase/decrease -> Updated the list content*/
unsigned char DecoStop_StartRec_u8 = 1U;
void HandleButton_DiveMenu_DecoStop(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
                    DIVEMENU_DECOSTOPS /*H_U ~ BACK*/,
                    DataDec /*U*/,
                    *oldOpVal /*D*/,
                    *oldOpVal /*H_D*/,
                    DataInc /*R*/,
                    ReturnToMainPage()/*H_R*/,
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal);
    /*Calculate max dive plan pages*/
    if(DataInc==(*newOpVal)) //When press increase
    {
        /*if exceed number of records -> revert to 1st page*/
        if(DecoStop_StartRec_u8 + DECOSTOP_MAX_ITEMS_INPAGE < DECOSTOP_MAX_ITEMS)
        {
            /*And the next page Deco stop value is not 0*/
            if(DecoStop[DecoStop_StartRec_u8 + DECOSTOP_MAX_ITEMS_INPAGE] != 0U)
            {
                /*Increase the page*/
                DecoStop_StartRec_u8 += DECOSTOP_MAX_ITEMS_INPAGE;
            }
            else
            {
                DecoStop_StartRec_u8 = DECOSTOP_START_RECORD;
            }
        }
        else
        {
            DecoStop_StartRec_u8 = DECOSTOP_START_RECORD;
        }
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
    }
    else if(DataDec==(*newOpVal)) //When press decrease
    {
        if(DecoStop_StartRec_u8 >= DECOSTOP_MAX_ITEMS_INPAGE)
        {
            /*decrese the start item in list*/
            DecoStop_StartRec_u8 -= DECOSTOP_MAX_ITEMS_INPAGE;
        }
        else
        {
            /*Do nothing*/
        }
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
