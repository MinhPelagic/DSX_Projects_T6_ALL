/******************************************************************************/
//File: Dive Simulator
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"
#include "Menu_DiveSim_SimulateDive.h"
#include "..\Dive Planner\Menu_DiveSim_SimulateDive.h"

/*
@brief: This sepcify to Dive simulator because the page base on the number display of dive
GENERAL:
    There are these state of pages
    1. No Deco                 : DIVE_SIMDIVE_DIVPLAN_NODECO
    2. Not enough time         : DIVE_SIMDIVE_DIVPLAN_NOTENTIM
    3. Calculating             : DIVE_SIMDIVE_DIVPLAN_CALCULATING
    4. Max Ceiling exceed      : DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED
        Note:
            - There are maximum 400 FT in plan then max page is 40 pages
            - 2 first items in DIVE PLAN
                + User Setting
                + ASC
                => Total 40+2 = 42 lines => 42:6 = 7 pages maximum
    5. Plan Page 01            :
        5.1: Line 01: User plan settings
        5.2: Line 02: ASC (GUI calculate)
        5.3: Data[01] from algorithm (Depth, RunTime, Stop, FO2/Fhe)
    6. Plan Page 02 (optional)
    ...
    11. Plan Page 07 (optional)
    12. Baiout Page 01 -> Familiar with Plan Page 01
    13. Baiout Page 02 (optional)
    ...
    18. Baiout Page 07 (optional)
    19. Baiout Gas Consumption
    20. Summary
*/
/*
Hanlde the 1st page when coming from DIVE_PL_DIVE_SIM_SIMULATEDIVE
*/
void HandleButtonDiveSimulator_SET(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    /*Check all the buttons state*/

    if(CC_MODE) {
        *newOpVal = Opcode_Matrix(
                        DIVE_PL_DIVE_SIM /*H_U ~ BACK*/,
                        DIVE_PL_DIVE_SIM_SP /*U*/,
                        DIVE_PL_DIVE_SIM_NEWORCONTINUOS /*D*/,
                        *oldOpVal /*H_D*/,
                        CheckConditions /*R*/, /*Progress next step*/
                        ReturnToMainPage()/*H_R*/,
                        *oldOpVal,
                        *oldOpVal,
                        *oldOpVal);
    }
    else if(OC_MODE||SM_MODE) {
        *newOpVal = Opcode_Matrix(
                        DIVE_PL_DIVE_SIM /*H_U ~ BACK*/,
                        DIVE_PL_DIVE_SIM_SAC /*U*/,
                        DIVE_PL_DIVE_SIM_NEWORCONTINUOS /*D*/,
                        *oldOpVal /*H_D*/,
                        CheckConditions /*R*/, /*Progress next step*/
                        ReturnToMainPage()/*H_R*/,
                        *oldOpVal,
                        *oldOpVal,
                        *oldOpVal);
    }



    /*In case press L button then check the current status*/
    if (CheckConditions == *newOpVal)
    {
        *newOpVal = DIVE_SIMDIVE_DIVPLAN_CALCULATING;
    }
    else
    {
        /*Do nothing -> Keep the previous value changed*/
    }
}
/*
When the page 1: DIVE PLAN display
->  Check whenever page need display by calculate the number of page need to handle
*/
#define PlanMode_MaxDepth     DecoStop[1]//Input the value of 1st DecoDepth from algorithm
/*
Number of pages need display = (numOfPages + 1)
2U: first 2 rows (user setings + ASC)
6U: num of row/pages
*/
void HandleButtonDiveSimulator_DIVEPLAN(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    uint16_t PlanModeTotalOfPage    = (uint16_t)(((PlanMode_MaxDepth/10.0f)+2.0f)/6.1f); //2.0f is Max depth & ASC items in list
    uint16_t minOCSPlanPage         = DIVE_SIMDIVE_DIVPLAN_PAGE_01;
    uint16_t maxOCSPlanPage         = DIVE_SIMDIVE_DIVPLAN_PAGE_01 + PlanModeTotalOfPage;
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
                    DataDec /*H_U ~ BACK*/,
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
        if((minOCSPlanPage<=(*oldOpVal))&&(maxOCSPlanPage>(*oldOpVal)))//get data from position
        {
            *newOpVal = (DSX_OPCODE_t)(*oldOpVal + 1);//Increse the opcode
        }
        else
        {
            /*In CC mode have the Bailout Planner, with other mode -> go to Summary */
            if(NVD_MDCC==GUI_DIVE_Mode)
            {
                *newOpVal = DIVE_SIMDIVE_BAILOUT_PAGE_01; //Move to 1st page BAILOUT
            }
            else
            {
                *newOpVal = DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS; //OC/SM
            }
        }
    }
    else if(DataDec==(*newOpVal)) //When press decrease
    {
        if((maxOCSPlanPage>=(*oldOpVal))&&(minOCSPlanPage<(*oldOpVal)))
        {
            *newOpVal = (DSX_OPCODE_t)(*oldOpVal - 1);//decrease the opcode value
        }
        else
        {
            *newOpVal = DIVE_PL_DIVE_SIM_SIMULATEDIVE; //Do nothing keepp old value
        }
    }
    else
    {
        /*Do nothing*/
    }
}

#define BailoutMode_MaxDepth    BDecoStop[1]//Input the value of 1st DecoDepth from algorithm
void HandleButtonDiveSimulator_BAILOUTPLAN(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    uint16_t BailoutModeTotalOfRows     = (uint16_t)((BailoutMode_MaxDepth/10.0f)/6.1);
    uint16_t PlanModeTotalOfPage        = (uint16_t)(((PlanMode_MaxDepth/10.0f)+2.0f)/6.1f);
    uint16_t maxOCSPlanPage             = DIVE_SIMDIVE_DIVPLAN_PAGE_01 + PlanModeTotalOfPage;
    uint16_t minOCBailOutPage           = DIVE_SIMDIVE_BAILOUT_PAGE_01;
    uint16_t maxOCBailOutPage           = DIVE_SIMDIVE_BAILOUT_PAGE_01 + BailoutModeTotalOfRows;
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
                    DataDec /*H_U ~ BACK*/,
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
        if((minOCBailOutPage<=(*oldOpVal))&&(maxOCBailOutPage>(*oldOpVal))) /*Increase in range 1..8*/
        {
            *newOpVal = (DSX_OPCODE_t)(*oldOpVal + 1);//Increse the opcode
        }
        else if(maxOCBailOutPage==(*oldOpVal)) /*then move to Consumption*/
        {
            *newOpVal = DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS;
        }
        else if(DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS==(*oldOpVal)) /*And summary*/
        {
            *newOpVal = DIVE_SIMDIVE_SUMMARY;
        }
        else
        {
            *newOpVal = DIVE_SIMDIVE_DIVPLAN_PAGE_01; //Rotate to 1st page of Dive Plan
        }
    }
    else if(DataDec==(*newOpVal)) //When press decrease
    {
        if((maxOCBailOutPage>=(*oldOpVal))&&(minOCBailOutPage<(*oldOpVal)))
        {
            *newOpVal = (DSX_OPCODE_t)(*oldOpVal - 1);//decrease the opcode value
        }
        else if(DIVE_SIMDIVE_SUMMARY==(*oldOpVal)) /*when decrease from Consumptions*/
        {
            *newOpVal = DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS; /*jump to BailoutSummary*/
        }
        else if(DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS==(*oldOpVal)) /*when decrease from Consumptions*/
        {
            /*In CC mode have the Bailout Planner, with other mode */
            if(NVD_MDCC==GUI_DIVE_Mode)
            {
                *newOpVal = (DSX_OPCODE_t)maxOCBailOutPage; /*jump to maxOCBailOutPage*/
            }
            else
            {
                *newOpVal = (DSX_OPCODE_t)maxOCSPlanPage; //Move to last page maxOCSPlanPage
            }
        }
        else
        {
            *newOpVal = (DSX_OPCODE_t)maxOCSPlanPage; //Return to latest plan page
        }
    }
    else
    {
        /*Do nothing*/
    }
}
void HandleButtonDiveSimulator_Calculating(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    if((DIVE_SIMDIVE_DIVPLAN_CALCULATING==*newOpVal)&&((0==TickHandler.scheduled_tick)||(6==TickHandler.scheduled_tick)))
    {
        Predict_Deco_List();
        switch(SIM_MESSAGE)
        {
        case SIM_NO_DECO:   /*Check NO DECO*/
            *newOpVal = DIVE_SIMDIVE_DIVPLAN_NODECO;
            break;
        case SIM_NOT_ENOUGH_TIME:/*Not enough time to decent*/
            *newOpVal = DIVE_SIMDIVE_DIVPLAN_NOTENTIM;
            break;
        case SIM_CEILING_EXCEED_400:/*Exceed maximum depth*/
            *newOpVal = DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED;
            break;
        case SIM_DECOTIME_EXCEED_99:/*Exceed Deco time 99 Mins*/
            *newOpVal = DIVE_SIMDIVE_DECOTIME_EXCEED;
            break;
        case SIM_TOOHIGH_PO2:/*TOO HIGH PO2*/
            *newOpVal = DIVE_SIMDIVE_TOOHIGH_PO2;
            break;
        default:
            /*Otherwise -> Display 1st Page in DIVE PLAN*/
            *newOpVal = DIVE_SIMDIVE_DIVPLAN_PAGE_01;
            break;
        }
    }
    else
    {
        *newOpVal = *oldOpVal;
    }

}

