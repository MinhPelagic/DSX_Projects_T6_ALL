/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGasSwitchCfg.h"
#include "Menu_GasSwitch.h"



/*
When input current gas -> Check the current display -> before and after display order
Ex: When current gas is 2 -> Handle Gas 1 should be
    -> Current pos display  1
    -> before is            5 -> Up
    -> after is             3 -> Down
*/
const swGasCheckNum_st gasNumCheck_01[GasSwitchNum_MAX]=
{
    /*if current GAS is 1*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
    /*if current GAS is 2 (1, 3, 4, 5)*/
    {posDispGasSwitch_1, GAS_SWITCH_TO_GAS_5, GAS_SWITCH_TO_GAS_3},
    /*if current GAS is 3 (1, 2, 4, 5)*/
    {posDispGasSwitch_1, GAS_SWITCH_TO_GAS_5, GAS_SWITCH_TO_GAS_2},
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {posDispGasSwitch_1, GAS_SWITCH_TO_GAS_5, GAS_SWITCH_TO_GAS_2},
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {posDispGasSwitch_1, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_2},
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/

};
const swGasCheckNum_st gasNumCheck_02[GasSwitchNum_MAX]=
{
    /*if current GAS is 1 (2, 3, 4, 5)*/
    {posDispGasSwitch_1, GAS_SWITCH_TO_GAS_5, GAS_SWITCH_TO_GAS_3},
    /*if current GAS is 2*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
    /*if current GAS is 3 (1, 2, 4, 5)*/
    {posDispGasSwitch_2, GAS_SWITCH_TO_GAS_1, GAS_SWITCH_TO_GAS_4},
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {posDispGasSwitch_2, GAS_SWITCH_TO_GAS_1, GAS_SWITCH_TO_GAS_3},
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {posDispGasSwitch_2, GAS_SWITCH_TO_GAS_1, GAS_SWITCH_TO_GAS_3},
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
};
const swGasCheckNum_st gasNumCheck_03[GasSwitchNum_MAX]=
{
    /*if current GAS is 1 (2, 3, 4, 5)*/
    {posDispGasSwitch_2, GAS_SWITCH_TO_GAS_2, GAS_SWITCH_TO_GAS_4},
    /*if current GAS is 2 (1, 3, 4, 5)*/
    {posDispGasSwitch_2, GAS_SWITCH_TO_GAS_1, GAS_SWITCH_TO_GAS_4},
    /*if current GAS is 3*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {posDispGasSwitch_3, GAS_SWITCH_TO_GAS_2, GAS_SWITCH_TO_GAS_5},
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {posDispGasSwitch_3, GAS_SWITCH_TO_GAS_2, GAS_SWITCH_TO_GAS_4},
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
};
const swGasCheckNum_st gasNumCheck_04[GasSwitchNum_MAX]=
{
    /*if current GAS is 1 (2, 3, 4, 5)*/
    {posDispGasSwitch_3, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_5},
    /*if current GAS is 2 (1, 3, 4, 5)*/
    {posDispGasSwitch_3, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_5},
    /*if current GAS is 3 (1, 2, 4, 5)*/
    {posDispGasSwitch_3, GAS_SWITCH_TO_GAS_2, GAS_SWITCH_TO_GAS_5},
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_1},
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_1},
};
const swGasCheckNum_st gasNumCheck_05[GasSwitchNum_MAX]=
{
    /*if current GAS is 1 (2, 3, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_2},
    /*if current GAS is 2 (1, 3, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 3 (1, 2, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
    /*if current GAS is 6 (1, 2, 3, 4, 5)*/
    {posDispGasSwitch_5, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_1},
};


const swGasCheckNum_st gasNumCheck_06[GasSwitchNum_MAX]=
{
    /*if current GAS is 1 (2, 3, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_2},
    /*if current GAS is 2 (1, 3, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 3 (1, 2, 4, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_4, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 4 (1, 2, 3, 5)*/
    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_1},

    {posDispGasSwitch_4, GAS_SWITCH_TO_GAS_3, GAS_SWITCH_TO_GAS_1},
    /*if current GAS is 5 (1, 2, 3, 4)*/
    {(uint8_t)0, (DSX_OPCODE_t)0, (DSX_OPCODE_t)0}, /*Not check current gas*/
};

uint16_t PreGas, NextGas;

unsigned char CondiCheck_GAS_SWITCH_TO_GAS_1(void)
{
    unsigned char retCond_uc = TRUE;
    //uint8_t PosDisp;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_1(void)
{
    //uint8_t PosDisp;
    //uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = FALSE;
    //if((gasNumCheck_01[CURRGAS].valueGasAfterSelectedGas==DSX_Opcode)||(gasNumCheck_01[CURRGAS].valueGasBeforeSelectedGas==DSX_Opcode))
    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
}
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_2(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    unsigned char retCond_uc = TRUE;
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_2(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    unsigned char retCond_uc = FALSE;
    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
}
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_3(void)
{
    // uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = TRUE;
    //if((gasNumCheck_03[CURRGAS].valueGasAfterSelectedGas==pre_DSX_Opcode)||(gasNumCheck_03[CURRGAS].valueGasBeforeSelectedGas==pre_DSX_Opcode))
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_3(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = FALSE;
    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
}
/*GAS #3*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_4(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = TRUE;
    //if((gasNumCheck_04[CURRGAS].valueGasAfterSelectedGas==pre_DSX_Opcode)||(gasNumCheck_04[CURRGAS].valueGasBeforeSelectedGas==pre_DSX_Opcode))
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }

    retCond_uc = FALSE;
    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_4(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = FALSE;
    // if((gasNumCheck_04[CURRGAS].valueGasAfterSelectedGas==DSX_Opcode)||(gasNumCheck_04[CURRGAS].valueGasBeforeSelectedGas==DSX_Opcode))
    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }

    retCond_uc = TRUE;
    return retCond_uc;
}

//uint16_t PreGas, NextGas;

unsigned char CondiCheck_GAS_SWITCH_TO_GAS_5(void)
{

    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);


    unsigned char retCond_uc = TRUE;
    //if((gasNumCheck_05[CURRGAS].valueGasAfterSelectedGas==pre_DSX_Opcode)||(gasNumCheck_05[CURRGAS].valueGasBeforeSelectedGas==pre_DSX_Opcode))
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }

    //retCond_uc = FALSE;
    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_5(void)
{

    //uint8_t PosDisp;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = FALSE;
    //if((gasNumCheck_05[CURRGAS].valueGasAfterSelectedGas==DSX_Opcode)||(gasNumCheck_05[CURRGAS].valueGasBeforeSelectedGas==DSX_Opcode))
    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }

    return retCond_uc;
}

unsigned char CondiCheck_GAS_SWITCH_TO_GAS_6(void)
{

    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = TRUE;
    if((PreGas==pre_DSX_Opcode)||(NextGas==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }

    return retCond_uc;
}
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_6(void)
{
    //uint8_t PosDisp;
    uint16_t PreGas, NextGas;
    RetPosDisp(CURRGAS_POS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);

    unsigned char retCond_uc = FALSE;

    if((PreGas==DSX_Opcode)||(NextGas==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
}

