/******************************************************************************/
//File: Dive simulator context main page
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"

/*NEW OR CONTINUOUS*/
void DiveSimulator_NEWORCONTINUOUS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NEW_OR_CONTINUOUS));
}
void DiveSimulator_NEWORCONTINUOUS_Context_Right(char* pStrRet)
{
    if(GUI_DIVE_SIMULATOR_NEW_CONT==0)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NEW));
    else
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CONTINUOUS));
}
/*DEPTH*/
void DiveSimulator_DEPTH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEPTH));
}
void DiveSimulator_DEPTH_Context_Right(char* pStrRet)
{
    /*DEPTH VALUE*/
    if(Imperial)
        sprintf(pStrRet, "  %d FT", GUI_DIVE_SIMULATOR_DEPTH_Ft);
    else
        sprintf(pStrRet, "   %d M", GUI_DIVE_SIMULATOR_DEPTH_Mt);
}
/*TIME*/
void DiveSimulator_TIME_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_TIME));
}
void DiveSimulator_TIME_Context_Right(char* pStrRet)
{
    /*Minute value*/
    sprintf(pStrRet, "  %d MIN", GUI_DIVE_SIMULATOR_Time);
}
/*SAC*/
void DiveSimulator_SAC_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAC));
}
void DiveSimulator_SAC_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "  %.2f CUFT/MIN", 0.01*GUI_DIVE_SIMULATOR_SAC_CuFt);
    else
        sprintf(pStrRet, "  %d L/MIN", GUI_DIVE_SIMULATOR_SAC_Ltr);
}
/*SP*/
void DiveSimulator_SP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SP));
}
void DiveSimulator_SP_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "  %.2f ", 0.01*GUI_DIVE_SIMULATOR_SP);
}
/*SIMULATE DIVE*/
void DiveSimulator_SIMULATEDIVE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SIMULATE_DIVE));
}