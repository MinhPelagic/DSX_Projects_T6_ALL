/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

static const listItemInMenu_ts O2Analyzer_CC_Context=
{
    2,/*Number of items*/
    {
        &Context_SetGases_O2Analyzer_Calibrate,
        &Context_SetGases_O2Analyzer_Analyze,
    }
};
const listItemInMenu_ts* O2Analyzer_ListOfContext[DIVEMODE_MAX] =
{
    &O2Analyzer_CC_Context,/*CC*/
    &O2Analyzer_CC_Context,/*OC*/
    &O2Analyzer_CC_Context,/*SM*/
    &O2Analyzer_CC_Context,/*GAUGE*/
    &O2Analyzer_CC_Context,/*GAUGE SM*/
    &O2Analyzer_CC_Context,/*BO*/
};

