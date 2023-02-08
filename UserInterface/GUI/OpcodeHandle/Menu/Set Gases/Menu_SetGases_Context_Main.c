/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

/*GAS 1*/
void SetGases_Row_01_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_01)));
}
void SetGases_Row_01_Context_Middle_01(char* pStrRet)
{
    /*Input data*/
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_01)]));
}
void SetGases_Row_01_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_01), SetGasGetFHe(SetGASES_Index_01));
}
void SetGases_Row_01_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_01)]));
}
unsigned char SetGases_Row_01_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_01==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*GAS 2*/
void SetGases_Row_02_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_02)));
}
void SetGases_Row_02_Context_Middle_01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_02)]));
}
void SetGases_Row_02_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_02), SetGasGetFHe(SetGASES_Index_02));
}
void SetGases_Row_02_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_02)]));
}
unsigned char SetGases_Row_02_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_02==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*GAS 3*/
void SetGases_Row_03_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_03)));
}
void SetGases_Row_03_Context_Middle_01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_03)]));
}
void SetGases_Row_03_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_03), SetGasGetFHe(SetGASES_Index_03));
}
void SetGases_Row_03_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_03)]));
}
unsigned char SetGases_Row_03_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_03==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*GAS 4*/
void SetGases_Row_04_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_04)));
}
void SetGases_Row_04_Context_Middle_01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_04)]));
}
void SetGases_Row_04_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_04), SetGasGetFHe(SetGASES_Index_04));
}
void SetGases_Row_04_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_04)]));
}
unsigned char SetGases_Row_04_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_04==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*GAS 5*/
void SetGases_Row_05_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_05)));
}
void SetGases_Row_05_Context_Middle_01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_05)]));
}
void SetGases_Row_05_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_05), SetGasGetFHe(SetGASES_Index_05));
}
void SetGases_Row_05_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_05)]));
}
unsigned char SetGases_Row_05_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_05==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*GAS 6*/
void SetGases_Row_06_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(SetGasGetMode(GUI_DIVE_Mode, SetGASES_06)));
}
void SetGases_Row_06_Context_Middle_01(char* pStrRet)
{
    if(NVD_MDCC==GUI_DIVE_Mode)
    {
        /*no display ON/OFF only CC mode*/
        strcpy(pStrRet, " ");
    }
    else
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_06)]));
    }

}
void SetGases_Row_06_Context_Middle_02(char* pStrRet)
{
    sprintf(pStrRet, "%d/%.2d", SetGasGetFO2(SetGASES_Index_06), SetGasGetFHe(SetGASES_Index_06));
}
void SetGases_Row_06_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_06)]));
}
unsigned char SetGases_Row_06_CheckDispTheDot(void)
{
    unsigned char retVal = DISABLE_DISPLAY;
    /*No display the dot in BO mode*/
    if((SetGASES_Index_06==FindGasNumOfDiveMode(DIVE_MODE))&&(DIVE_MODE!=NVD_MDBO))
    {
        retVal = ENABLE_DISPLAY;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*O2 ANALYZER*/
void SetGases_Row_O2_ANALYZER_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2_ANALYZER));
}
void SetGasesMenu_O2Analyzer_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2_ANALYZER));
}
/**
 * @brief
 *
 */
void SetGasesMenu_SetBOGases_Context_Center(char* pStrRet)
{
    if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
    {
        strcpy(pStrRet, (GUI_LANG_GetText(TxtStr_BO)));
        strcat(pStrRet, (GUI_LANG_GetText(TxtStr_SET_GASES)));
    }
    else
        strcpy(pStrRet, "SET BO GASES");
}
void SetGasesMenu_SetCCGases_Context_Center(char* pStrRet)
{
    if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
    {
        strcpy(pStrRet, (GUI_LANG_GetText(TxtStr_CC)));
        strcat(pStrRet, (GUI_LANG_GetText(TxtStr_SET_GASES)));
    }
    else
        strcpy(pStrRet, "SET CC GASES");
}
