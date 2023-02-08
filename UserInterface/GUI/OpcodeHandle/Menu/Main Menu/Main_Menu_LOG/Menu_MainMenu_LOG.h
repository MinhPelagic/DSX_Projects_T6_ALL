/******************************************************************************/
//File: LOG
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"

#define LOG01_MAX_HIGHLIGHT         (MAX_ITEM_DISP_PAGE_LOG_01 - 1) //(0~6)

/*LOG 1 Page*/
enum LogData1_RightContent_e
{
    LogData01_Right_MODE_e = 0x00,
    LogData01_Right_MAXDEPTH_e,
    LogData01_Right_DIVETIME_e,
    LogData01_Right_AVDEPTH_e,
    LogData01_Right_LOWTEMP_e,
    LogData01_Right_MAX_e
};
/*
LOG menu display right content
*/
typedef struct
{
    const TxtStr_Name_e LogData1_RightStr;
    pstrHandle_Func LogData1_RighFunc;
} log01DatRight_ts;
/*
LOG menu display left content
xx: #yy - mm/dd/yy
*/
typedef struct
{
    /*Pos in list 0~6 to display (maximu is 7)*/
    unsigned char currPosDisp;
    /*Item status: Select/Unselect -> Color change*/
    ItemStatus_te currStat;
    /*
    Contain LOG data
    - Dive number: #yy
    - Log number: xx
    - EntryMonth/EntryDay/EntryYear : mm/dd/yy
    */
    LOG_Data_t logData;
    /**/
} log01DatLeft_ts;

/*LOG 2 Page*/
void DisplayText_TopBar_LOGTittle(const char* String);
void MainMenuLOG_1_RightSideContent(unsigned int LogNum);
void MainMenuLOG_1_LefSideItemInList(log01DatLeft_ts dataInput_st);
void MainMenuLOG_1_LefScurrDiveideItemInList(unsigned char currPos, unsigned int currLog, ItemStatus_te itemStat);
void DisplayTimeOfLOGatTOP(void);
void LogMenu_DisplayNODIVEYET(void);

void DiveMode_DecoStop_Minute_Text_Context(char* pStrRet);
GUI_COLOR SetColorTissueBar(uint8_t);
/*Extern variables*/
extern const log01DatRight_ts LogData01_RightContent[];
extern const contentDispContext_st MenuLog_01_Titlte;
extern uint8_t GUI_LOG_PageIdx;
extern uint8_t GUI_LOG_NumLast;           // Total LOG number has been saved on EEPROM
extern unsigned int log01HighlightItem_i;
extern const char* TxtDef_Set_PressUnit[];
extern unsigned int log01CountNum_i;
