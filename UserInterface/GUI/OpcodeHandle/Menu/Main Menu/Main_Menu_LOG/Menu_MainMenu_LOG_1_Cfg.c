/******************************************************************************/
//File: LOG 1
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"

void Log01StrRet_DiveMode(char* buffStr)
{
    unsigned char mMode = 0;
    mMode = Log_Data_7[log01HighlightItem_i].DiveType;
    /*Check the data*/
    if(mMode>DIVEMODE_MAX)
    {
        mMode = DIVEMODE_CC;
    }
    strcpy(buffStr, GUI_LANG_GetText(TxtDef_DSX_MainMode[mMode]));
}
void Log01StrRet_MaxDepth(char* buffStr)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(buffStr, "  %.0f FT  ", 0.1 * Log_Data_7[log01HighlightItem_i].MaxDepthFt10);
    else
        sprintf(buffStr, "  %.1f M  ",  0.1 * CONST_FT_TO_M * Log_Data_7[log01HighlightItem_i].MaxDepthFt10);
}
void Log01StrRet_DiveTime(char* buffStr)
{
    sprintf(buffStr, "%d MIN", (Log_Data_7[log01HighlightItem_i].EDTsec)/60);
}
void Log01StrRet_AvgDepth(char* buffStr)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(buffStr, "  %.0f FT  ", 0.1 * Log_Data_7[log01HighlightItem_i].AvgDepthFt10);
    else
        sprintf(buffStr, "  %.1f M  ",  0.1 * CONST_FT_TO_M * Log_Data_7[log01HighlightItem_i].AvgDepthFt10);
}
void Log01StrRet_LowTemp(char* buffStr)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(buffStr, "  %.0f °F ", 0.1 * Log_Data_7[log01HighlightItem_i].MinTempF10);
    else
        sprintf(buffStr, "  %.1f °C ", 0.1 * 5.0 / 9.0 * (Log_Data_7[log01HighlightItem_i].MinTempF10 - 320));
}
/**/
const log01DatRight_ts LogData01_RightContent[LogData01_Right_MAX_e] =
{
    {TxtStr_MODE, Log01StrRet_DiveMode},
    {TxtStr_MAX_DEPTH, Log01StrRet_MaxDepth},
    {TxtStr_DIVE_TIME, Log01StrRet_DiveTime},
    {TxtStr_AVG_DEPTH, Log01StrRet_AvgDepth},
    {TxtStr_LOW_TEMP, Log01StrRet_LowTemp},
};
/*LOG Tittle*/
void MenuLog_01_Titlte_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOG));
}
const contentDispContext_st MenuLog_01_Titlte =
{
    &MenuLog_01_Titlte_Context,
    &Unselect_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_LogData01_Title,
};
/**
 * @brief LOG-1 Set the color when Violation
 *
 * @param logData
 * @return GUI_COLOR
 */
static GUI_COLOR MainMenuLog1_CheckViolationStatus(LOG_Data_t logData)
{
    GUI_COLOR colorRet = TxtColor_UnSelect;
    if(1u == logData.AlarmOccured.Bit.SetupVIOLATION)
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
/*
Current Position: 0 ~ 6
inputData : Log number 0~...
item Stat: Select/Unselect
logNumber
*/
#define yPosInList 	((currPos*Pos_LogData01_List->Height)+Pos_LogData01_List->Y0)
void MainMenuLOG_1_LefSideItemInList(log01DatLeft_ts dataInput_st)
{
    char strRet[LangMaxLength];
    GUI_MEMDEV_Handle hmemLocal = 0;
    unsigned char currPos = 0;
    currPos = dataInput_st.currPosDisp;
    /*memdev clear*/
    hmemLocal = GUI_MEMDEV_CreateEx(Pos_LogData01_List->X0, yPosInList, Pos_LogData01_List->Width, Pos_LogData01_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemLocal);
    GUI_ClearRect(Pos_LogData01_List->X0, yPosInList, Pos_LogData01_List->X1, ((currPos*Pos_LogData01_List->Height)+Pos_LogData01_List->Y1));
    /*Set font size, color*/
    if(IteStat_Select == dataInput_st.currStat)
    {
        GUI_SetColor(TxtColor_Select);
    }
    else
    {
        GUI_SetColor(MainMenuLog1_CheckViolationStatus(dataInput_st.logData));
    }
    SetFont_3;
    /*Display the Log number*/
    GUI_SetTextAlign(GUI_TA_LEFT);
    sprintf(strRet, "%d:", dataInput_st.logData.LogNum);
    GUI_DispStringAt(strRet, Point_LogMode01_LogNum->x, yPosInList);
    /*Display the Dive number*/
    sprintf(strRet, "#%d", dataInput_st.logData.DiveNum);
    GUI_DispStringAt(strRet, Point_LogMode01_DiveNum->x, yPosInList);
    /*Display the dash*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt("-", Point_LogMode01_Dash->x, yPosInList);
    /*Display the log day*/
    if(SWITCH_DDMM_Format==true)
        sprintf(strRet, "%.2d/%.2d/%d", dataInput_st.logData.EntryDay, dataInput_st.logData.EntryMon, dataInput_st.logData.EntryYear);
    else
        sprintf(strRet, "%.2d/%.2d/%d", dataInput_st.logData.EntryMon, dataInput_st.logData.EntryDay, dataInput_st.logData.EntryYear);
    GUI_DispStringAt(strRet, Point_LogMode01_Logday->x, yPosInList);
    GUI_MEMDEV_CopyToLCD(hmemLocal);
    GUI_MEMDEV_Delete(hmemLocal);
}
/*Display Right side content*/
/**
 * @brief
 *
 * @param LogNum
 */
void MainMenuLOG_1_RightSideContent(unsigned int LogNum)
{
    uint8_t i_u8;
    GUI_MEMDEV_Handle hmemLocal;
    char strBuff[LangMaxLength];
    /**
    *Display the value of each log on the right
    *1. Mode
    *2. Max depth
    *3. Dive time
    *4. AV Depth
    *5. Low Temperature
    *---------------------------------------------------*/
    for(i_u8 = LogData01_Right_MODE_e; i_u8<LogData01_Right_MAX_e; i_u8++)
    {
        hmemLocal = GUI_MEMDEV_CreateEx(Pos_LogData01_RightContent->X0, ((i_u8*Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y0),\
                                        Pos_LogData01_RightContent->Width, Pos_LogData01_RightContent->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemLocal);
        GUI_ClearRect(Pos_LogData01_RightContent->X0,\
                      ((i_u8*Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y0),\
                      Pos_LogData01_RightContent->X1,\
                      ((i_u8*Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y1));
        /*Display the text right*/
        GUI_SetTextAlign(GUI_TA_CENTER);
        SetFont_2;
        GUI_SetColor(TxtColor_UnSelect);
        GUI_DispStringAt(GUI_LANG_GetText(LogData01_RightContent[i_u8].LogData1_RightStr),\
                         Pos_LogData01_RightContent->X, ((i_u8*Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y0));
        /*Display the value*/
        LogData01_RightContent[i_u8].LogData1_RighFunc(strBuff);
        GUI_SetColor(GUI_WHITE);
        SetFont_3;
        GUI_DispStringHCenterAt(strBuff, Pos_LogData01_RightContent->X, ((i_u8*Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y));
        GUI_MEMDEV_CopyToLCD(hmemLocal);
        GUI_MEMDEV_Delete(hmemLocal);
    }
}
