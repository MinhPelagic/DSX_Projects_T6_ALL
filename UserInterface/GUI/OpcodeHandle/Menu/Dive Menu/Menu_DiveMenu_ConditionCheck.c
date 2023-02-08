/******************************************************************************/
//File: Condition check sepecific to Dive menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDiveMenuCfg.h"
#include "DiveMenu.h"

/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETSP*/
unsigned char CondiCheck_DIVEMENU_SETSP(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_SETGASES==pre_DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==pre_DSX_Opcode)||
            (DIVEMENU_DECOSTOPS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGASES*/
unsigned char CondiCheck_DIVEMENU_SETGASES(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_SETSP==pre_DSX_Opcode)||
            (DIVEMENU_DIVEPROFILEGRAPH==pre_DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==pre_DSX_Opcode)||
            (DIVEMENU_DECOSTOPS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DECOSTOPS*/
unsigned char CondiCheck_DIVEMENU_DECOSTOPS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_BAILOUTPO2LIMITS==pre_DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==pre_DSX_Opcode)||
            (DIVEMENU_PO2LIMITS==pre_DSX_Opcode)||
            (DIVEMENU_SETSP==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGFHIGH*/
unsigned char CondiCheck_DIVEMENU_SETGFHIGH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_DECOSTOPS==pre_DSX_Opcode)||
            (DIVEMENU_SETGASES==pre_DSX_Opcode)||
            (DIVEMENU_SETSP==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};

/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DIVEPROFILEGRAPH*/
unsigned char CondiCheck_DIVEMENU_DIVEPROFILEGRAPH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_SETGASES==pre_DSX_Opcode)||
            (DIVEMENU_BAILOUTPO2LIMITS==pre_DSX_Opcode)||
            (DIVEMENU_PO2LIMITS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_BAILOUTPO2LIMITS*/
unsigned char CondiCheck_DIVEMENU_BAILOUTPO2LIMITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_DIVEPROFILEGRAPH==pre_DSX_Opcode)||
            (DIVEMENU_DECOSTOPS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_PO2LIMITS*/
unsigned char CondiCheck_DIVEMENU_PO2LIMITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMENU_DIVEPROFILEGRAPH==pre_DSX_Opcode)||
            (DIVEMENU_DECOSTOPS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETSP*/
unsigned char CondiPreOcCheck_DIVEMENU_SETSP(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_SETGASES==DSX_Opcode)||(DIVEMENU_DECOSTOPS==DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGASES*/
unsigned char CondiPreOcCheck_DIVEMENU_SETGASES(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_SETSP==DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==DSX_Opcode)||
            (DIVEMENU_DECOSTOPS==DSX_Opcode)||
            (DIVEMENU_DIVEPROFILEGRAPH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DECOSTOPS*/
unsigned char CondiPreOcCheck_DIVEMENU_DECOSTOPS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_PO2LIMITS==DSX_Opcode)||
            (DIVEMENU_SETGFHIGH==DSX_Opcode)||
            (DIVEMENU_BAILOUTPO2LIMITS==DSX_Opcode)||
            (DIVEMENU_SETSP==DSX_Opcode)||
            (DIVEMENU_SETGASES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGFHIGH*/
unsigned char CondiPreOcCheck_DIVEMENU_SETGFHIGH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_DECOSTOPS==DSX_Opcode)||
            (DIVEMENU_SETSP==DSX_Opcode)||
            (DIVEMENU_SETGASES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DIVEPROFILEGRAPH */
unsigned char CondiPreOcCheck_DIVEMENU_DIVEPROFILEGRAPH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_SETGASES==DSX_Opcode)||
            (DIVEMENU_PO2LIMITS==DSX_Opcode)||
            (DIVEMENU_BAILOUTPO2LIMITS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_BAILOUTPO2LIMITS*/
unsigned char CondiPreOcCheck_DIVEMENU_BAILOUTPO2LIMITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_DIVEPROFILEGRAPH==DSX_Opcode)||(DIVEMENU_DECOSTOPS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    else
    {
        /*do nothing*/
    }
    return retCond_uc;
}
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_PO2LIMITS*/
unsigned char CondiPreOcCheck_DIVEMENU_PO2LIMITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMENU_DIVEPROFILEGRAPH==DSX_Opcode)||(DIVEMENU_DECOSTOPS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
