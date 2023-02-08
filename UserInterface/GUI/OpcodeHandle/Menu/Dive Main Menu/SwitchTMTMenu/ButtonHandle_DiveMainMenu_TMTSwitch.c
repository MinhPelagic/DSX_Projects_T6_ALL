/******************************************************************************/
// File: Deco Stops menu
// Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../../Main Menu/Main_Menu_TMT_SWITCH/Menu_MainMenu_TMTSwitch.h"

/*base on the current dive mode -> Switch back to Dive mode accordingly*/
DSX_OPCODE_t DiveMainMenu_SwitchBackValueToDive(void)
{
    DSX_OPCODE_t ocRet = (DSX_OPCODE_t)0U;
    if (GSM_MODE)
    {
        /*Back to Main Dive*/
        ocRet = DIVE_GSM_MAIN;
    }
    else if (GAUGE_MODE)
    {
        ocRet = DIVE_GAUGE_MAIN;
    }
    else if (OC_MODE)
    {
        ocRet = DIVE_OC_MAIN;
    }
    else
    {
        ocRet = DIVE_CC_MAIN;
    }
    return ocRet;
}
/*When button pressed increase/decrease*/
void HandleButton_DiveMainMenu_TMTSwitch(DSX_OPCODE_t *newOpVal, DSX_OPCODE_t *oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
        DIVEMAINMENU_TMTSWITCH /*H_U ~ BACK*/,
        DataDec /*L*/,
        DataInc /*M*/,
        *oldOpVal /*M2*/,
        SaveAndDone /*R*/,
        CheckConditions /*R2*/,
        *oldOpVal,
        *oldOpVal,
        *oldOpVal);
    /*Handle status specific*/
    if (DataInc == (*newOpVal)) // press increase
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*call display update*/
        TMTMenu_UpdatePressDown(&HighLightTMTItem);
    }
    else if (DataDec == (*newOpVal)) // press decrease
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        TMTMenu_UpdatePressUp(&HighLightTMTItem);
    }
    else if (SaveAndDone == (*newOpVal)) // press save
    {
        /*Selected highlight TMT*/
        GUI_ShowTankNum = HighLightTMTItem.TMTNumber + 1;
        if (GSM_MODE)
        {
            CURRENT_TMT_NUM_GSM = (TMT_NUM_t)GUI_ShowTankNum;
        }
        else if (GAUGE_MODE)
        {
            CURRENT_TMT_NUM_GAUGE = (TMT_NUM_t)GUI_ShowTankNum;
        }
        EE_SaveReq(EE_TRIMIXSET);
        /*set opcode back value*/
        *newOpVal = DiveMainMenu_SwitchBackValueToDive();
    }
    else if (CheckConditions == (*newOpVal))
    {
        *newOpVal = DiveMainMenu_SwitchBackValueToDive();
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
