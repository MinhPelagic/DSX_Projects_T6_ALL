/******************************************************************************/
//File: O2 button handle
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include ".\Menu_O2Analyzer_Page_AnalyzerList.h"

MenuO2AnalyzerCtr_ts ctrO2Analyzer = {0};
/*When button pressed increase/decrease*/
void HandleButton_O2AnalyzerList(DSX_OPCODE_t *newOpVal, DSX_OPCODE_t *oldOpVal)
{
    /*Check all the buttons state*/
    *newOpVal = Opcode_Matrix(
                    S476_ANALYZE_SELECT_GAS_LIST_MODE /*L>2s*/,
                    DataDec /*L*/,
                    DataInc /*M*/,
                    *oldOpVal /*M2*/,
                    SaveAndDone /*R*/,
                    ReturnToMainPage(),
                    *oldOpVal,
                    *oldOpVal,
                    *oldOpVal);
    /*Handle status specific*/
    if (DataInc == (*newOpVal)) // press increase
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*control data*/
        if(ctrO2Analyzer.idxHighlight < ctrO2Analyzer.maxItemDisp)
        {
            ctrO2Analyzer.idxHighlight += 1U;
        }
        else
        {
            /*When reach to bottom of list -> highlight on top*/
            ctrO2Analyzer.idxHighlight = 0U;
        }
        /*trigger update display*/
        ctrO2Analyzer.updateDisp = TRUE;
    }
    else if (DataDec == (*newOpVal)) // press decrease
    {
        /*Keep the old value*/
        *newOpVal = *oldOpVal;
        /*control data*/
        if(ctrO2Analyzer.idxHighlight > 0U)
        {
            ctrO2Analyzer.idxHighlight -= 1U;
        }
        else
        {
            /*When reach to top of list -> high light bottom*/
            ctrO2Analyzer.idxHighlight = ctrO2Analyzer.maxItemDisp;
        }
        /*trigger update display*/
        ctrO2Analyzer.updateDisp = TRUE;
    }
    else if (SaveAndDone == (*newOpVal)) // press save
    {
        /*Set current GAS*/
        GAS_ASSIGN_INDEX = ctrO2Analyzer.idxHighlight + 1U;
        /*Jump to page */
        if(NVD_MDSM == GUI_O2ANALYZER_DIVEMODE_ASSIGN)
        {
            *newOpVal = S486_ANALYZE_SET_BOTH_OCL_OCR;
        }
        else
        {
            *newOpVal = S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS;
        }
    }
    else
    {
        /*Do nothing -> Change to new opcode value*/
    }
}
