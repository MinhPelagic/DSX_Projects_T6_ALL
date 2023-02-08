/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
/*handle control display O2*/
typedef struct
{
    /*Index ID to display*/
    uint8_t Idx;
    /*index current highligh*/
    uint8_t idxHighlight;
    /*index un-highlight*/
    uint8_t idxUnHilight;
    /*Color display -> Select/Unselect*/
    ItemStatus_te dispStat;
    /*Maximum item display in list*/
    uint8_t maxItemDisp;
    /*Check display update */
    bool updateDisp;
} MenuO2AnalyzerCtr_ts;

/*control logic display*/
extern MenuO2AnalyzerCtr_ts ctrO2Analyzer;
/*funciton prototype*/
static void contentFuncO2_GasMode(uint8_t Id, char* content);
static void contentFuncO2_GasStatus(uint8_t Id, char* content);
static void contentFuncO2_FO2Fhe(uint8_t Id, char* content);
static void contentFuncO2_LinkedTMT(uint8_t Id, char* content);
static bool O2Analyzer_CheckDisplayDot(uint8_t gasID);
