/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/
#include "L4X9_includes.h"
#include "ContextSPSwitchCfg.h"
/*
Context content progress to SPSwitch
NOTE: These config are generated !!!
*/
/*
----------------------------------

----------------------------------
*/
const menuItemContext_ts Context_SpSwitch_SWITCHTOHIGH=
{
    ENABLE_DISPLAY,
    SpSwitch_SWITCHTOHIGH_Context_Left,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_COLOR_HANDLE,
    &ReturnFalse,
    {0xFF,0u,0u,0u,0xFF,0xFF},
};
/*
----------------------------------
Because this switch is the same as to 5 mode
then only check the status when switch HIGH LOW | LOW CUSTOM
----------------------------------
*/
const menuItemContext_ts Context_SpSwitch_SWITCHTOLOW=
{
    ENABLE_DISPLAY,
    SpSwitch_SWITCHTOLOW_Context_Left,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_COLOR_HANDLE,
    &ReturnFalse,
    {0u,0xFF,1u,0xFF,0u,0u},
};
/*
----------------------------------

----------------------------------
*/
const menuItemContext_ts Context_SpSwitch_SWITCHTOCUSTOM=
{
    ENABLE_DISPLAY,
    SpSwitch_SWITCHTOCUSTOM_Context_Left,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_COLOR_HANDLE,
    &ReturnFalse,
    {1u,1u,0xFF,0xFF,0xFF,1u},
};
