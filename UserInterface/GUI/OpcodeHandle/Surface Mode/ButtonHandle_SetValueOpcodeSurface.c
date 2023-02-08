
#include "L4X9_includes.h"

/*
Base on the value of user setting -> Set the Opcode value on Surface
*/
DSX_OPCODE_t SurfButton_GetValueOpcode(void)
{
    DSX_OPCODE_t opCodeRet = S2_SURFACE_MAIN;
    switch (USER_Set.DiveMode)
    {
    case NVD_MDSM: /*SM Mode*/
        opCodeRet = SURFACE_SM_MAIN;
        break;

    default: /*with CC/OC mode*/
        /*Keep the initial value*/
        break;
    }
    return opCodeRet;
}
