#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"

static const listItemInMenu_ts DivePlannerMenu_CC_Context=
{
    2,/*Number of items*/
    {
        &Context_DivePlanner_TIMELIMITS,
        &Context_DivePlanner_DIVESIMULATOR,
    }
};
static const listItemInMenu_ts DivePlannerMenu_OC_Context=
{
    3,/*Number of items*/
    {
        &Context_DivePlanner_TIMELIMITS,
        &Context_DivePlanner_DEPTHLIMITS,
        &Context_DivePlanner_DIVESIMULATOR,
    }
};

const listItemInMenu_ts* DivePlannerMenu_ListOfContext[DIVEMODE_MAX] =
{
    &DivePlannerMenu_CC_Context,/*CC*/
    &DivePlannerMenu_OC_Context,/*OC*/
    &DivePlannerMenu_OC_Context,/*SM*/
    &DivePlannerMenu_OC_Context,/*GAUGE*/
    &DivePlannerMenu_OC_Context,/*GAUGE SM*/
    &DivePlannerMenu_CC_Context,/*BO*/
};
/*DIVE SIMULATOR*/
static const listItemInMenu_ts DiveSimulator_CC_Context=
{
    6,/*Number of items*/
    {
        &Context_DiveSimulator_NEWORCONTINUOUS,
        &Context_DiveSimulator_DEPTH,
        &Context_DiveSimulator_TIME,
        &Context_DiveSimulator_SAC,
        &Context_DiveSimulator_SP,
        &Context_DiveSimulator_SIMULATEDIVE,
    }
};
static const listItemInMenu_ts DiveSimulator_OC_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveSimulator_NEWORCONTINUOUS,
        &Context_DiveSimulator_DEPTH,
        &Context_DiveSimulator_TIME,
        &Context_DiveSimulator_SAC,
        &Context_DiveSimulator_SIMULATEDIVE,
    }
};
const listItemInMenu_ts* DiveSimulator_ListOfContext[DIVEMODE_MAX] =
{
    &DiveSimulator_CC_Context,/*CC*/
    &DiveSimulator_OC_Context,/*OC*/
    &DiveSimulator_OC_Context,/*SM*/
    &DiveSimulator_CC_Context,/*GAUGE*/
    &DiveSimulator_CC_Context,/*GAUGE SM*/
    &DiveSimulator_CC_Context,/*BO*/
};