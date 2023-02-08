#include "L4X9_includes.h"
#include "ContextDiveSettingsCfg.h"
static const listItemInMenu_ts DiveSettings_CC_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveSett_DIVEMODE,
        &Context_DiveSett_BAILOUTPO2,
        &Context_DiveSett_CONSERVATISM,
        &Context_DiveSett_SAFETYSTOP,
        &Context_DiveSett_LASTSTOPDEPTH,
    }
};
static const listItemInMenu_ts DiveSettings_OC_Context=
{
    5,/*Number of items*/
    {
        &Context_DiveSett_DIVEMODE,
        &Context_DiveSett_PO2LIMITS,
        &Context_DiveSett_CONSERVATISM,
        &Context_DiveSett_SAFETYSTOP,
        &Context_DiveSett_LASTSTOPDEPTH,
    }
};
const listItemInMenu_ts* DiveSettings_ListOfContext[DIVEMODE_MAX] =
{
    &DiveSettings_CC_Context,/*CC*/
    &DiveSettings_OC_Context,/*OC*/
    &DiveSettings_OC_Context,/*SM*/
    &DiveSettings_OC_Context,/*GAUGE*/
    &DiveSettings_OC_Context,/*GAUGE SM*/
    &DiveSettings_CC_Context,/*BO*/
};
