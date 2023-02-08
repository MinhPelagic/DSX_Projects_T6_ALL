/******************************************************************************/
//File: Dive Simulator Dive
//Description:
//
/*****************************************************************************/
#ifndef _DIVEPLANNER_DIVSIM_H_
#define _DIVEPLANNER_DIVSIM_H_
#include "L4X9_includes.h"
/*Data define*/
#define BAILCONSUMP_FO2         (0U)/*Position in array*/
#define BAILCONSUMP_FHe         (1U)/*Position in array*/
#define BAILCONSUMP_ConSump     (2U)/*Position in array*/
#define PLANCALMAX              (41U) /*Maximum number of records be calculated by algorithm*/

/*This status get from algorithm*/
enum
{
    SIM_NO_MESSAGE = 0U,
    SIM_NO_DECO,
    SIM_NOT_ENOUGH_TIME,
    SIM_CEILING_EXCEED_400,
    SIM_DECOTIME_EXCEED_99,
    SIM_TOOHIGH_PO2,
    SIM_MAX,
};
/*Max page is DecoStop[42] + 1User + ASC -> 44/6 = 8 Pages is maximum*/
enum
{
    SIMDIVE_PAGE_PLAN_1 = 0U,
    SIMDIVE_PAGE_PLAN_2,
    SIMDIVE_PAGE_PLAN_3,
    SIMDIVE_PAGE_PLAN_4,
    SIMDIVE_PAGE_PLAN_5,
    SIMDIVE_PAGE_PLAN_6,
    SIMDIVE_PAGE_PLAN_7,
    SIMDIVE_PAGE_PLAN_8,
};
enum
{
    SIMDIVE_PAGE_BAILOUT_1 = 0U,
    SIMDIVE_PAGE_BAILOUT_2,
    SIMDIVE_PAGE_BAILOUT_3,
    SIMDIVE_PAGE_BAILOUT_4,
    SIMDIVE_PAGE_BAILOUT_5,
    SIMDIVE_PAGE_BAILOUT_6,
    SIMDIVE_PAGE_BAILOUT_7,
    SIMDIVE_PAGE_BAILOUT_8,
};
/*Struct data of Dive Plan and BailOut plan*/
typedef struct
{
    /*Position in list*/
    int Pos;
    /*Depth*/
    char depthString[10];
    /*Run time*/
    int RunTime;
    /*Stop time*/
    int StopTime;
    /*Gas: FO2/FHe*/
    int FO2;
    int FHe;
} planDatDisp_st;
enum DiveSim_Summary_e
{
    DiveSim_Summary_TotalRuntime	= 0x00,
    DiveSim_Summary_TotalDECO,
    DiveSim_Summary_O2SAT,
    DiveSim_Summary_GFSELECTED,
    DiveSim_Summary_MAX,
};
static void DisplayDiveAndBailOutPlanRowContent(planDatDisp_st);
void DisplayHeaderDivePlan(void);
void DisplayDivePlanPage(unsigned char PageId);
void DisplayBailoutPlanPage(unsigned char PageId);
extern const TxtStr_Name_e TxtDef_DiveSim_Summary[DiveSim_Summary_MAX];
extern const pstrHandle_Func pFuncSimDiveSummary[DiveSim_Summary_MAX];

#endif
