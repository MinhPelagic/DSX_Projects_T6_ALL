/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

static const listItemInMenu_ts SetGases_CC_Context=
{
    6U,/*Number of items*/
    {
        &Context_SetGases_Row_01,
        &Context_SetGases_Row_02,
        &Context_SetGases_Row_03,
        &Context_SetGases_Row_04,
        &Context_SetGases_Row_05,
        &Context_SetGases_Row_06,
    }
};
static const listItemInMenu_ts SetGases_OC_Context=
{
    7U,/*Number of items*/
    {
        &Context_SetGases_Row_01,
        &Context_SetGases_Row_02,
        &Context_SetGases_Row_03,
        &Context_SetGases_Row_04,
        &Context_SetGases_Row_05,
        &Context_SetGases_Row_06,
        &Context_SetGases_Row_O2_ANALYZER,
    }
};
/**
 * @brief SET GAS Specific to BO mode
 *
 */
static const listItemInMenu_ts SetGasesMenu_CC_Context =
{
    3,/*Number of items*/
    {
        &Context_SetGasesMenu_SetCCGases,
        &Context_SetGasesMenu_SetBOGases,
        &Context_SetGasesMenu_O2Analyzer,
    }
};
const listItemInMenu_ts* SetGasesMenu_ListOfContext[DIVEMODE_MAX] =
{
    &SetGasesMenu_CC_Context,/*CC*/
    &SetGasesMenu_CC_Context,/*OC*/
    &SetGasesMenu_CC_Context,/*SM*/
    &SetGasesMenu_CC_Context,/*GAUGE SM*/
    &SetGasesMenu_CC_Context,/*GAUGE*/
    &SetGasesMenu_CC_Context,/*BO*/
};
const listItemInMenu_ts* SetGases_ListOfContext[DIVEMODE_MAX] =
{
    &SetGases_CC_Context,/*CC*/
    &SetGases_OC_Context,/*OC*/
    &SetGases_OC_Context,/*SM*/
    &SetGases_OC_Context,/*GAUGE SM*/
    &SetGases_OC_Context,/*GAUGE*/
    &SetGases_CC_Context,/*BO*/
};
const listItemInMenu_ts* SetGases_DiveMode_ListOfContext[DIVEMODE_MAX] =
{
    &SetGases_CC_Context,/*CC*/
    &SetGases_CC_Context,/*OC*/
    &SetGases_CC_Context,/*SM*/
    &SetGases_CC_Context,/*GAUGE SM*/
    &SetGases_CC_Context,/*GAUGE*/
    &SetGases_CC_Context,/*BO*/
};
