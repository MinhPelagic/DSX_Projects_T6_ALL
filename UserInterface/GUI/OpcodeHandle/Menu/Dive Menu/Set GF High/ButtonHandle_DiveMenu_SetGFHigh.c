/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveMenu_SetGFHigh.h"
uint8_t GFHighSettingValue = 0;
/*When button pressed increase/decrease*/
void HandleButton_DiveMenu_SetGFHigh(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix
                (
                    DIVEMENU_SETGFHIGH /*H_U ~ BACK*/,
                    DataDec /*L*/,
                    DataInc /*M*/,
                    *oldOpVal /*M2*/,
                    DIVEMENU_SETGFHIGH /*R*/,
                    ReturnToMainPage()/*H_R*/,
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal
                );
    /*Calculate max dive pages*/
    if(DataInc==(*newOpVal)) //When press increase
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*When exceed/reach to maximum value*/
        if(SETGFHIGH_MAX_GFHIGH_VALUE <= GFHighSettingValue)
        {
            GFHighSettingValue = SCUBA_Set.TEC_GF_Hi; //Rotate the value to min value
        }
        else
        {
            GFHighSettingValue+=SETGFHIGH_STEP_VALUE;

            GFHighSettingValue-=(GFHighSettingValue%5);

            if(SETGFHIGH_MAX_GFHIGH_VALUE < GFHighSettingValue)        //check and correct if out-of-boundary, added by YS 2022/04/22
                GFHighSettingValue = SETGFHIGH_MAX_GFHIGH_VALUE;
        }
    }
    else if(DataDec==(*newOpVal)) //When press decrease
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*When decreased to minimum value (0)*/
        if(SCUBA_Set.TEC_GF_Hi >= GFHighSettingValue)
        {
            GFHighSettingValue = SETGFHIGH_MAX_GFHIGH_VALUE; //rotate to maximum value
        }
        else
        {
            GFHighSettingValue-=(GFHighSettingValue%5);

            GFHighSettingValue-=SETGFHIGH_STEP_VALUE;

            if(SCUBA_Set.TEC_GF_Hi > GFHighSettingValue)
                GFHighSettingValue = SCUBA_Set.TEC_GF_Hi;        //check and correct if out-of-boundary, added by YS 2022/04/22
        }
    }
    else if(DIVEMENU_SETGFHIGH==(*newOpVal)) //When press R1 to confirm value
    {
        SCUBA_Set.TEC_GF_Hi = GFHighSettingValue;
        UpdateGF();
        EE_SaveReq(EE_SCUBASET);
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
