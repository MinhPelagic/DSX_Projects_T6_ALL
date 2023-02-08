/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_TMTSwitch.h"
/*Highlight TMT item*/
Menu_TMTItems_st HighLightTMTItem = {0u, 0u};
/*When button pressed increase/decrease*/
void HandleButton_TMTSwitch(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
	const MainMenu_TMTDisplayList_st TMTListInfo = getTheListTMTDisplay();

    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix
                (
                    S404_TMT_SWITCH /*H_U ~ BACK*/,
                    DataDec /*L*/,
                    DataInc /*M*/,
                    *oldOpVal /*M2*/,
                    SaveAndDone /*R*/,
                    CheckConditions /*R2*/,
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal
                );
    /*Handle status specific*/
    if(DataInc==(*newOpVal)) //press increase
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*call display update*/
        TMTMenu_UpdatePressDown(&HighLightTMTItem);
    }
    else if(DataDec==(*newOpVal)) //press decrease
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        TMTMenu_UpdatePressUp(&HighLightTMTItem);
    }
    else if(SaveAndDone==(*newOpVal)) //press save
    {
        /*Selected highlight TMT*/
		if(TMTListInfo.maxTMT == 0){
			//GUI_ShowTankNum = 0;
		}
		else{
        	GUI_ShowTankNum = HighLightTMTItem.TMTNumber + 1;
		}
		
        if(GSM_MODE)
        {
            CURRENT_TMT_NUM_GSM = (TMT_NUM_t)GUI_ShowTankNum;
            /*Back to Main Surface*/
        }
        else /*GAUGE mode*/
        {
            CURRENT_TMT_NUM_GAUGE = (TMT_NUM_t)GUI_ShowTankNum;
        }
        EE_SaveReq(EE_TRIMIXSET);
        /*set opcode back value*/
        *newOpVal = ReturnToSurfMain();
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
