/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../../Main Menu/Main_Menu_TMT_SWITCH/Menu_MainMenu_TMTSwitch.h"

/*When button pressed increase/decrease*/
void HandleButton_DiveMenu_ResetAVGDepth(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix
                (
                    DIVEMAINMENU_RESETAVGDEPTH /*H_U ~ BACK*/,
                    *oldOpVal /*L*/,
                    *oldOpVal /*M*/,
                    *oldOpVal /*M2*/,
                    SaveAndDone /*R*/,
                    CheckConditions /*R2*/,
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal
                );
    /*Handle status specific*/
    if(SaveAndDone==(*newOpVal)) //press save
    {
        /*Reset AVG depth value*/
        Dive_Info.ResetDiveDepthAvg = true;
        
        /*set opcode back value*/
        *newOpVal = DiveMainMenu_SwitchBackValueToDive();
    }
    else if(CheckConditions==(*newOpVal))
    {
        *newOpVal = DiveMainMenu_SwitchBackValueToDive();
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
