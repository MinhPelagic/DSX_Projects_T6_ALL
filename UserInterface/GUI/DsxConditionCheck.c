/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/
#include"L4X9_includes.h"
/*
*Condition check when update portion screen is On
* Return TRUE-> Clear/Initial all screen
* Return FALSE-> Update portion only -> hanlde in Update portion function
*/

/*Condition check return the result when need to clear all the the screen or one portion only of S18_SP_SWITCH*/
unsigned char CondiCheck_S18_SP_SWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S21_GAS_SWITCH==pre_DSX_Opcode)||(S_SLATE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S21_GAS_SWITCH*/
unsigned char CondiCheck_S21_GAS_SWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S_SLATE==pre_DSX_Opcode)||(S62_DIVE_PLANNER==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S_SLATE==pre_DSX_Opcode)||(S62_DIVE_PLANNER==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S18_SP_SWITCH==pre_DSX_Opcode)||(S62_DIVE_PLANNER==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S62_DIVE_PLANNER*/
unsigned char CondiCheck_S62_DIVE_PLANNER(void)
{
    unsigned char retCond_uc = TRUE;
    if((S21_GAS_SWITCH==pre_DSX_Opcode)||(S27_LOG==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S27_LOG*/
unsigned char CondiCheck_S27_LOG(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S41_SET_MENU==pre_DSX_Opcode)||(S404_TMT_SWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S41_SET_MENU==pre_DSX_Opcode)||(S404_TMT_SWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S62_DIVE_PLANNER==pre_DSX_Opcode)||(S41_SET_MENU ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S41_SET_MENU*/
unsigned char CondiCheck_S41_SET_MENU(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S27_LOG==pre_DSX_Opcode)||(S432_DIVE_MODE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S27_LOG==pre_DSX_Opcode)||(S432_DIVE_MODE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S27_LOG==pre_DSX_Opcode)||(S185_INFO==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S185_INFO*/
unsigned char CondiCheck_S185_INFO(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S432_DIVE_MODE==pre_DSX_Opcode)||(S_SLATE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S432_DIVE_MODE==pre_DSX_Opcode)||(S_SLATE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S41_SET_MENU==pre_DSX_Opcode)||(S_SLATE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S_SLATE*/
unsigned char CondiCheck_S_SLATE(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S21_GAS_SWITCH==pre_DSX_Opcode)||(S185_INFO==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S21_GAS_SWITCH==pre_DSX_Opcode)||(S185_INFO==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((S185_INFO==pre_DSX_Opcode)||(S404_TMT_SWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S185_INFO==pre_DSX_Opcode)||(S404_TMT_SWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S185_INFO==pre_DSX_Opcode)||(S18_SP_SWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S404_TMT_SWITCH*/
unsigned char CondiCheck_S404_TMT_SWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S27_LOG==pre_DSX_Opcode)||(S_SLATE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S432_DIVE_MODE*/
unsigned char CondiCheck_S432_DIVE_MODE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S41_SET_MENU==pre_DSX_Opcode)||(S185_INFO==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S42_SET_GASES*/
unsigned char CondiCheck_S42_SET_GASES(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S_DIVE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S_DIVE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S53_SET_SP==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S53_SET_SP*/
unsigned char CondiCheck_S53_SET_SP(void)
{
    unsigned char retCond_uc = TRUE;
    if((S42_SET_GASES==pre_DSX_Opcode)||(S_DIVE_SETTINGS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S_DIVE_SETTINGS*/
unsigned char CondiCheck_S_DIVE_SETTINGS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S42_SET_GASES==pre_DSX_Opcode)||(S105_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S42_SET_GASES==pre_DSX_Opcode)||(S105_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S53_SET_SP==pre_DSX_Opcode)||(S105_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S105_ALARMS*/
unsigned char CondiCheck_S105_ALARMS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S128_DEVICE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S128_DEVICE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S_DIVE_SETTINGS==pre_DSX_Opcode)||(S128_DEVICE_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_SETTINGS*/
unsigned char CondiCheck_S128_DEVICE_SETTINGS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S105_ALARMS==pre_DSX_Opcode)||(S149_DATE_TIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S105_ALARMS==pre_DSX_Opcode)||(S149_DATE_TIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S105_ALARMS==pre_DSX_Opcode)||(S149_DATE_TIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S149_DATE_TIME*/
unsigned char CondiCheck_S149_DATE_TIME(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S128_DEVICE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S128_DEVICE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S128_DEVICE_SETTINGS==pre_DSX_Opcode)||(S161_DISPLAY_SETTINGS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S161_DISPLAY_SETTINGS*/
unsigned char CondiCheck_S161_DISPLAY_SETTINGS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S105_ALARMS==pre_DSX_Opcode)||(S149_DATE_TIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S105_ALARMS==pre_DSX_Opcode)||(S149_DATE_TIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S149_DATE_TIME==pre_DSX_Opcode)||(S42_SET_GASES==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DATE*/
unsigned char CondiCheck_S154_SET_DATE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S158_SET_TIME==pre_DSX_Opcode)||(S152_SET_TIME_FORMAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_YY*/
unsigned char CondiCheck_S154_SET_YY(void)
{
    unsigned char retCond_uc = TRUE;
    if((S154_SET_MM==pre_DSX_Opcode)||(S154_SET_DD==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_MM*/
unsigned char CondiCheck_S154_SET_MM(void)
{
    unsigned char retCond_uc = TRUE;
    if((S154_SET_YY==pre_DSX_Opcode)||(S154_SET_DD==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DD*/
unsigned char CondiCheck_S154_SET_DD(void)
{
    unsigned char retCond_uc = TRUE;
    if((S154_SET_MM==pre_DSX_Opcode)||(S154_SET_YY==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_TIME*/
unsigned char CondiCheck_S158_SET_TIME(void)
{
    unsigned char retCond_uc = TRUE;
    if((S154_SET_DATE==pre_DSX_Opcode)||(S150_SET_DATE_FORMAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_HH*/
unsigned char CondiCheck_S158_SET_HH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S158_SET_MM==pre_DSX_Opcode)||(S158_SET_AM_PM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_MM*/
unsigned char CondiCheck_S158_SET_MM(void)
{
    unsigned char retCond_uc = TRUE;
    if((S158_SET_HH==pre_DSX_Opcode)||(S158_SET_AM_PM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_AM_PM*/
unsigned char CondiCheck_S158_SET_AM_PM(void)
{
    unsigned char retCond_uc = TRUE;
    if((S158_SET_HH==pre_DSX_Opcode)||(S158_SET_MM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S150_SET_DATE_FORMAT*/
unsigned char CondiCheck_S150_SET_DATE_FORMAT(void)
{
    unsigned char retCond_uc = TRUE;
    if((S158_SET_TIME==pre_DSX_Opcode)||(S152_SET_TIME_FORMAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S152_SET_TIME_FORMAT*/
unsigned char CondiCheck_S152_SET_TIME_FORMAT(void)
{
    unsigned char retCond_uc = TRUE;
    if((S150_SET_DATE_FORMAT==pre_DSX_Opcode)||(S154_SET_DATE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_CC_GASES*/
unsigned char CondiCheck_SETGASES_SET_CC_GASES(void)
{
    unsigned char retCond_uc = TRUE;
    if((SETGASES_SET_BO_GASES==pre_DSX_Opcode)||(SETGASES_O2_ANALYZER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_BO_GASES*/
unsigned char CondiCheck_SETGASES_SET_BO_GASES(void)
{
    unsigned char retCond_uc = TRUE;
    if((SETGASES_SET_CC_GASES==pre_DSX_Opcode)||(SETGASES_O2_ANALYZER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_O2_ANALYZER*/
unsigned char CondiCheck_SETGASES_O2_ANALYZER(void)
{
    unsigned char retCond_uc = TRUE;
    if((SETGASES_SET_CC_GASES==pre_DSX_Opcode)||(SETGASES_SET_BO_GASES==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_01*/
unsigned char CondiCheck_S70_SET_GAS_01(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_02==pre_DSX_Opcode)||(S70_O2_ANALYZER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_02*/
unsigned char CondiCheck_S70_SET_GAS_02(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_01==pre_DSX_Opcode)||(S70_SET_GAS_03==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_03*/
unsigned char CondiCheck_S70_SET_GAS_03(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_02==pre_DSX_Opcode)||(S70_SET_GAS_04==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_04*/
unsigned char CondiCheck_S70_SET_GAS_04(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_03==pre_DSX_Opcode)||(S70_SET_GAS_05==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_05*/
unsigned char CondiCheck_S70_SET_GAS_05(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_04==pre_DSX_Opcode)||(S70_SET_GAS_06==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_06*/
unsigned char CondiCheck_S70_SET_GAS_06(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_05==pre_DSX_Opcode)||(S70_O2_ANALYZER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_O2_ANALYZER*/
unsigned char CondiCheck_S70_O2_ANALYZER(void)
{
    unsigned char retCond_uc = TRUE;
    if((S70_SET_GAS_06==pre_DSX_Opcode)||(S70_SET_GAS_01==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_01*/
unsigned char CondiCheck_S73_SET_GAS_FHe_01(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_01==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_02*/
unsigned char CondiCheck_S73_SET_GAS_FHe_02(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_02==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_03*/
unsigned char CondiCheck_S73_SET_GAS_FHe_03(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_03==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_04*/
unsigned char CondiCheck_S73_SET_GAS_FHe_04(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_04==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_05*/
unsigned char CondiCheck_S73_SET_GAS_FHe_05(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_05==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_06*/
unsigned char CondiCheck_S73_SET_GAS_FHe_06(void)
{
    unsigned char retCond_uc = TRUE;
    if((S72_SET_GAS_FO2_06==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S462_O2ANALYZER_CALIBRATE*/
unsigned char CondiCheck_S462_O2ANALYZER_CALIBRATE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S470_O2ANALYZER_ANALYZE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S470_O2ANALYZER_ANALYZE*/
unsigned char CondiCheck_S470_O2ANALYZER_ANALYZE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S462_O2ANALYZER_CALIBRATE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_HIGH_SP*/
unsigned char CondiCheck_S54_SP_HIGH_SP(void)
{
    unsigned char retCond_uc = TRUE;
    if((S54_SP_LOW_SP==pre_DSX_Opcode)||(S59_SP_AUTO_LOW==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_LOW_SP*/
unsigned char CondiCheck_S54_SP_LOW_SP(void)
{
    unsigned char retCond_uc = TRUE;
    if((S54_SP_HIGH_SP==pre_DSX_Opcode)||(S56_SP_CUSTOM_SP==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S56_SP_CUSTOM_SP*/
unsigned char CondiCheck_S56_SP_CUSTOM_SP(void)
{
    unsigned char retCond_uc = TRUE;
    if((S54_SP_LOW_SP==pre_DSX_Opcode)||(S59_SP_AUTO_HIGH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_HIGH*/
unsigned char CondiCheck_S59_SP_AUTO_HIGH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S56_SP_CUSTOM_SP==pre_DSX_Opcode)||(S59_SP_AUTO_LOW==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_LOW*/
unsigned char CondiCheck_S59_SP_AUTO_LOW(void)
{
    unsigned char retCond_uc = TRUE;
    if((S59_SP_AUTO_HIGH==pre_DSX_Opcode)||(S54_SP_HIGH_SP==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S99_SET_DIVEMODE*/
unsigned char CondiCheck_S99_SET_DIVEMODE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S76_SET_BAILOUTPO2LIMITS==pre_DSX_Opcode)||(S96_SET_LASTSTOPDEPTH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S76_SET_BAILOUTPO2LIMITS*/
unsigned char CondiCheck_S76_SET_BAILOUTPO2LIMITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S99_SET_DIVEMODE==pre_DSX_Opcode)||(S83_SET_CONSERVATISM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S83_SET_CONSERVATISM*/
unsigned char CondiCheck_S83_SET_CONSERVATISM(void)
{
    unsigned char retCond_uc = TRUE;
    if((S91_SET_SAFETYSTOP==pre_DSX_Opcode)||(S76_SET_BAILOUTPO2LIMITS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S91_SET_SAFETYSTOP*/
unsigned char CondiCheck_S91_SET_SAFETYSTOP(void)
{
    unsigned char retCond_uc = TRUE;
    if((S96_SET_LASTSTOPDEPTH==pre_DSX_Opcode)||(S83_SET_CONSERVATISM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S96_SET_LASTSTOPDEPTH*/
unsigned char CondiCheck_S96_SET_LASTSTOPDEPTH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S91_SET_SAFETYSTOP==pre_DSX_Opcode)||(S99_SET_DIVEMODE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S106_AL_AUDIBLE*/
unsigned char CondiCheck_S106_AL_AUDIBLE(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((S108_AL_DEPTH==pre_DSX_Opcode)||(S122_AL_GF_N2==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDOC:
        if((S108_AL_DEPTH==pre_DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S108_AL_DEPTH==pre_DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S108_AL_DEPTH==pre_DSX_Opcode)||(S281_AL_TURN_END_PRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S108_AL_DEPTH*/
unsigned char CondiCheck_S108_AL_DEPTH(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S106_AL_AUDIBLE==pre_DSX_Opcode)||(S111_AL_DIVETIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S106_AL_AUDIBLE==pre_DSX_Opcode)||(S111_AL_DIVETIME==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S106_AL_AUDIBLE==pre_DSX_Opcode)||(S000_AL_DIVETIME_TTS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S111_AL_DIVETIME*/
unsigned char CondiCheck_S111_AL_DIVETIME(void)
{
    unsigned char retCond_uc = TRUE;
    if((S108_AL_DEPTH==pre_DSX_Opcode)||(S281_AL_TURN_END_PRESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_DTR*/
unsigned char CondiCheck_S116_AL_DTR(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S000_AL_DIVETIME_TTS==pre_DSX_Opcode)||(S281_AL_TURN_END_PRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S000_AL_DIVETIME_TTS==pre_DSX_Opcode)||(S281_AL_TURN_END_PRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S000_AL_DIVETIME_TTS==pre_DSX_Opcode)||(S116_AL_TANK_PRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_TANK_PRESS*/
unsigned char CondiCheck_S116_AL_TANK_PRESS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S116_AL_DTR==pre_DSX_Opcode)||(S119_AL_CC6_PRESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S119_AL_CC6_PRESS*/
unsigned char CondiCheck_S119_AL_CC6_PRESS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S116_AL_TANK_PRESS==pre_DSX_Opcode)||(S122_AL_GF_N2==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S122_AL_GF_N2*/
unsigned char CondiCheck_S122_AL_GF_N2(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S281_AL_TURN_END_PRESS==pre_DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((S281_AL_TURN_END_PRESS==pre_DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S281_AL_TURN_END_PRESS==pre_DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S119_AL_CC6_PRESS==pre_DSX_Opcode)||(S106_AL_AUDIBLE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S281_AL_TURN_END_PRESS*/
unsigned char CondiCheck_S281_AL_TURN_END_PRESS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S111_AL_DIVETIME==pre_DSX_Opcode)||(S106_AL_AUDIBLE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S111_AL_DIVETIME==pre_DSX_Opcode)||(S106_AL_AUDIBLE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S116_AL_DTR==pre_DSX_Opcode)||(S122_AL_GF_N2==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S288_AL_END_WOB_ICD_ALARMS*/
unsigned char CondiCheck_S288_AL_END_WOB_ICD_ALARMS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S106_AL_AUDIBLE==pre_DSX_Opcode)||(S122_AL_GF_N2==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S000_AL_DIVETIME_TTS*/
unsigned char CondiCheck_S000_AL_DIVETIME_TTS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S108_AL_DEPTH==pre_DSX_Opcode)||(S116_AL_DTR==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_TRANSMITTERS*/
unsigned char CondiCheck_S128_DEVICE_TRANSMITTERS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S137_DEVICE_UNITS==pre_DSX_Opcode)||(TBD_DEVICE_WELCOMESCREEN==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S137_DEVICE_UNITS*/
unsigned char CondiCheck_S137_DEVICE_UNITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_DEVICE_TRANSMITTERS==pre_DSX_Opcode)||(S139_DEVICE_WATERTYPE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S139_DEVICE_WATERTYPE*/
unsigned char CondiCheck_S139_DEVICE_WATERTYPE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S137_DEVICE_UNITS==pre_DSX_Opcode)||(S141_DEVICE_SAMPLERATE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S141_DEVICE_SAMPLERATE*/
unsigned char CondiCheck_S141_DEVICE_SAMPLERATE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S139_DEVICE_WATERTYPE==pre_DSX_Opcode)||(S143_DEVICE_BLUETOOTH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S143_DEVICE_BLUETOOTH*/
unsigned char CondiCheck_S143_DEVICE_BLUETOOTH(void)
{
    unsigned char retCond_uc = TRUE;
    if((S141_DEVICE_SAMPLERATE==pre_DSX_Opcode)||(TBD_DEVICE_RESETSETTINGS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_RESETSETTINGS*/
unsigned char CondiCheck_TBD_DEVICE_RESETSETTINGS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S143_DEVICE_BLUETOOTH==pre_DSX_Opcode)||(TBD_DEVICE_WELCOMESCREEN==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_WELCOMESCREEN*/
unsigned char CondiCheck_TBD_DEVICE_WELCOMESCREEN(void)
{
    unsigned char retCond_uc = TRUE;
    if((TBD_DEVICE_RESETSETTINGS==pre_DSX_Opcode)||(S128_DEVICE_TRANSMITTERS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S162_DISPLAY_BRIGHTNESS*/
unsigned char CondiCheck_S162_DISPLAY_BRIGHTNESS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((S164_DISPLAY_AUTODIM==pre_DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDOC:
        if((S164_DISPLAY_AUTODIM==pre_DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((S164_DISPLAY_AUTODIM==pre_DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S164_DISPLAY_AUTODIM==pre_DSX_Opcode)||(S372_DISPLAY_GTR==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S164_DISPLAY_AUTODIM*/
unsigned char CondiCheck_S164_DISPLAY_AUTODIM(void)
{
    unsigned char retCond_uc = TRUE;
    if((S162_DISPLAY_BRIGHTNESS==pre_DSX_Opcode)||(S173_DISPLAY_TITLESCOLOR==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S173_DISPLAY_TITLESCOLOR*/
unsigned char CondiCheck_S173_DISPLAY_TITLESCOLOR(void)
{
    unsigned char retCond_uc = TRUE;
    if((S164_DISPLAY_AUTODIM==pre_DSX_Opcode)||(S179_DISPLAY_LANGUAGE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S179_DISPLAY_LANGUAGE*/
unsigned char CondiCheck_S179_DISPLAY_LANGUAGE(void)
{
    unsigned char retCond_uc = TRUE;
    if((S173_DISPLAY_TITLESCOLOR==pre_DSX_Opcode)||(S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S178_DISPLAY_FLIPSCREEN*/
unsigned char CondiCheck_S178_DISPLAY_FLIPSCREEN(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S179_DISPLAY_LANGUAGE==pre_DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S179_DISPLAY_LANGUAGE==pre_DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S179_DISPLAY_LANGUAGE==pre_DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S166_DISPLAY_MAINDISPLAY*/
unsigned char CondiCheck_S166_DISPLAY_MAINDISPLAY(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode)||(S372_DISPLAY_GTR==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S372_DISPLAY_GTR*/
unsigned char CondiCheck_S372_DISPLAY_GTR(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S166_DISPLAY_MAINDISPLAY==pre_DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S162_DISPLAY_BRIGHTNESS==pre_DSX_Opcode)||(S428_DISPLAY_EXTRALARGE ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S428_DISPLAY_EXTRALARGE*/
unsigned char CondiCheck_S428_DISPLAY_EXTRALARGE(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S162_DISPLAY_BRIGHTNESS==pre_DSX_Opcode)||(S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==pre_DSX_Opcode)||(S372_DISPLAY_GTR==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_LEFT*/
unsigned char CondiCheck_MAINDISPLAY_LEFT(void)
{
    unsigned char retCond_uc = TRUE;
    if((MAINDISPLAY_RIGHT==pre_DSX_Opcode)||(MAINDISPLAY_EXTRALARGE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_RIGHT*/
unsigned char CondiCheck_MAINDISPLAY_RIGHT(void)
{
    unsigned char retCond_uc = TRUE;
    if((MAINDISPLAY_LEFT==pre_DSX_Opcode)||(MAINDISPLAY_GFBG==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_GFBG*/
unsigned char CondiCheck_MAINDISPLAY_GFBG(void)
{
    unsigned char retCond_uc = TRUE;
    if((MAINDISPLAY_RIGHT==pre_DSX_Opcode)||(MAINDISPLAY_EXTRALARGE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_EXTRALARGE*/
unsigned char CondiCheck_MAINDISPLAY_EXTRALARGE(void)
{
    unsigned char retCond_uc = TRUE;
    if((MAINDISPLAY_GFBG==pre_DSX_Opcode)||(MAINDISPLAY_LEFT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT1*/
unsigned char CondiCheck_S128_TM_TMT1(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT2==pre_DSX_Opcode)||(S128_TM_TMT6==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT2*/
unsigned char CondiCheck_S128_TM_TMT2(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT1==pre_DSX_Opcode)||(S128_TM_TMT3==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT3*/
unsigned char CondiCheck_S128_TM_TMT3(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT2==pre_DSX_Opcode)||(S128_TM_TMT4==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT4*/
unsigned char CondiCheck_S128_TM_TMT4(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT3==pre_DSX_Opcode)||(S128_TM_TMT5==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT5*/
unsigned char CondiCheck_S128_TM_TMT5(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT4==pre_DSX_Opcode)||(S128_TM_TMT6==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT6*/
unsigned char CondiCheck_S128_TM_TMT6(void)
{
    unsigned char retCond_uc = TRUE;
    if((S128_TM_TMT1==pre_DSX_Opcode)||(S128_TM_TMT5==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S187_IM_MYINFO*/
unsigned char CondiCheck_S187_IM_MYINFO(void)
{
    unsigned char retCond_uc = TRUE;
    if((S190_IM_DSXINFO==pre_DSX_Opcode)||(S224_IM_MANUFACTURER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S190_IM_DSXINFO*/
unsigned char CondiCheck_S190_IM_DSXINFO(void)
{
    unsigned char retCond_uc = TRUE;
    if((S187_IM_MYINFO==pre_DSX_Opcode)||(S192_IM_HISTORY==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S192_IM_HISTORY*/
unsigned char CondiCheck_S192_IM_HISTORY(void)
{
    unsigned char retCond_uc = TRUE;
    if((S190_IM_DSXINFO==pre_DSX_Opcode)||(S224_IM_MANUFACTURER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S224_IM_MANUFACTURER*/
unsigned char CondiCheck_S224_IM_MANUFACTURER(void)
{
    unsigned char retCond_uc = TRUE;
    if((S192_IM_HISTORY==pre_DSX_Opcode)||(S187_IM_MYINFO==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_HIGH*/
unsigned char CondiCheck_SP_SWITCH_TO_HIGH(void)
{
    unsigned char retCond_uc = TRUE;
    if((SP_SWITCH_TO_CUSTOM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_LOW*/
unsigned char CondiCheck_SP_SWITCH_TO_LOW(void)
{
    unsigned char retCond_uc = TRUE;
    if((SP_SWITCH_TO_CUSTOM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_CUSTOM*/
unsigned char CondiCheck_SP_SWITCH_TO_CUSTOM(void)
{
    unsigned char retCond_uc = TRUE;
    if((SP_SWITCH_TO_LOW==pre_DSX_Opcode)||(SP_SWITCH_TO_HIGH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_TIME_LIMITS*/
unsigned char CondiCheck_DIVE_PL_TIME_LIMITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DEPTH_LIMITS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DEPTH_LIMITS*/
unsigned char CondiCheck_DIVE_PL_DEPTH_LIMITS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_TIME_LIMITS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DEPTH_LIMITS==pre_DSX_Opcode)||(DIVE_PL_TIME_LIMITS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_NEWORCONTINUOS*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DIVE_SIM_SIMULATEDIVE==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_DEPTH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_DEPTH*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_DEPTH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_TIME==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_TIME*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_TIME(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DIVE_SIM_DEPTH==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SAC*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SAC(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((DIVE_PL_DIVE_SIM_TIME==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((DIVE_PL_DIVE_SIM_TIME==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((DIVE_PL_DIVE_SIM_TIME==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SP==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SP*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SP(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVE_PL_DIVE_SIM_SAC==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SIMULATEDIVE*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==pre_DSX_Opcode)||(DIVE_PL_DIVE_SIM_SP==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MIN*/
unsigned char CondiCheck_BAILOUT_PO2_OC_MIN(void)
{
    unsigned char retCond_uc = TRUE;
    if((BAILOUT_PO2_OC_MAX==pre_DSX_Opcode)||(BAILOUT_PO2_OC_DECO==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MAX*/
unsigned char CondiCheck_BAILOUT_PO2_OC_MAX(void)
{
    unsigned char retCond_uc = TRUE;
    if((BAILOUT_PO2_OC_MIN==pre_DSX_Opcode)||(BAILOUT_PO2_OC_DECO==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_DECO*/
unsigned char CondiCheck_BAILOUT_PO2_OC_DECO(void)
{
    unsigned char retCond_uc = TRUE;
    if((BAILOUT_PO2_OC_MAX==pre_DSX_Opcode)||(BAILOUT_PO2_OC_MIN==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_LOW*/
unsigned char CondiCheck_CONSERV_TEC_GF_LOW(void)
{
    unsigned char retCond_uc = TRUE;
    if((CONSERV_TEC_GF_HIGH==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_HIGH*/
unsigned char CondiCheck_CONSERV_TEC_GF_HIGH(void)
{
    unsigned char retCond_uc = TRUE;
    if((CONSERV_TEC_GF_LOW==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_AUDIBLE*/
unsigned char CondiCheck_ALARM_AUDIBLE(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_VIBRATION==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_VIBRATION*/
unsigned char CondiCheck_ALARM_VIBRATION(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_AUDIBLE==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DEPTH_SET*/
unsigned char CondiCheck_ALARM_DEPTH_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_DEPTH_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME*/
unsigned char CondiCheck_ALARM_DIVETIME(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_TTS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME_SET*/
unsigned char CondiCheck_ALARM_DIVETIME_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_DIVETIME_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS*/
unsigned char CondiCheck_ALARM_TTS(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_DIVETIME==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS_SET*/
unsigned char CondiCheck_ALARM_TTS_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_TTS_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DTR_SET*/
unsigned char CondiCheck_ALARM_DTR_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_DTR_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TANK_PRESS_SET*/
unsigned char CondiCheck_ALARM_TANK_PRESS_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_TANK_PRESS_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_CC6_PRESS_SET*/
unsigned char CondiCheck_ALARM_CC6_PRESS_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_CC6_PRESS_STAT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_GFN2_GF_STAT*/
unsigned char CondiCheck_ALARM_GFN2_GF_STAT(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_GFN2_N2_STAT==pre_DSX_Opcode)||(ALARM_GFN2_N2_SET==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_GFN2_N2_STAT*/
unsigned char CondiCheck_ALARM_GFN2_N2_STAT(void)
{
    unsigned char retCond_uc = TRUE;
    if((ALARM_GFN2_GF_STAT==pre_DSX_Opcode)||(ALARM_GFN2_GF_SET==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S282_ALARM_TURNPRESS*/
unsigned char CondiCheck_S282_ALARM_TURNPRESS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S285_ALARM_ENDPRESS==pre_DSX_Opcode)||(S353_ALARM_SWITCHPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((S285_ALARM_ENDPRESS==pre_DSX_Opcode)||(S353_ALARM_SWITCHPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S285_ALARM_ENDPRESS==pre_DSX_Opcode)||(S353_ALARM_SWITCHPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S285_ALARM_ENDPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S285_ALARM_ENDPRESS*/
unsigned char CondiCheck_S285_ALARM_ENDPRESS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S353_ALARM_SWITCHPRESS==pre_DSX_Opcode)||(S282_ALARM_TURNPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((S353_ALARM_SWITCHPRESS==pre_DSX_Opcode)||(S282_ALARM_TURNPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((S353_ALARM_SWITCHPRESS==pre_DSX_Opcode)||(S282_ALARM_TURNPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((S282_ALARM_TURNPRESS==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S353_ALARM_SWITCHPRESS*/
unsigned char CondiCheck_S353_ALARM_SWITCHPRESS(void)
{
    unsigned char retCond_uc = TRUE;
    if((S285_ALARM_ENDPRESS==pre_DSX_Opcode)||(S282_ALARM_TURNPRESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S289_ALARM_END*/
unsigned char CondiCheck_S289_ALARM_END(void)
{
    unsigned char retCond_uc = TRUE;
    if((S292_ALARM_WOB==pre_DSX_Opcode)||(S297_ALARM_O2_NARCOTIC==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S292_ALARM_WOB*/
unsigned char CondiCheck_S292_ALARM_WOB(void)
{
    unsigned char retCond_uc = TRUE;
    if((S295_ALARM_ICD==pre_DSX_Opcode)||(S289_ALARM_END==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S295_ALARM_ICD*/
unsigned char CondiCheck_S295_ALARM_ICD(void)
{
    unsigned char retCond_uc = TRUE;
    if((S292_ALARM_WOB==pre_DSX_Opcode)||(S297_ALARM_O2_NARCOTIC==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S297_ALARM_O2_NARCOTIC*/
unsigned char CondiCheck_S297_ALARM_O2_NARCOTIC(void)
{
    unsigned char retCond_uc = TRUE;
    if((S295_ALARM_ICD==pre_DSX_Opcode)||( S289_ALARM_END==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of C7_COMPASS_CALIBRATION*/
unsigned char CondiCheck_C7_COMPASS_CALIBRATION(void)
{
    unsigned char retCond_uc = TRUE;
    if((C13_COMPASS_DECLIN_SET==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of C13_COMPASS_DECLIN_SET*/
unsigned char CondiCheck_C13_COMPASS_DECLIN_SET(void)
{
    unsigned char retCond_uc = TRUE;
    if((C7_COMPASS_CALIBRATION==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S502_GPS_GET_CURRENT_LOCATION*/
unsigned char CondiCheck_S502_GPS_GET_CURRENT_LOCATION(void)
{
    unsigned char retCond_uc = TRUE;
    if((S509_GPS_WAYFINDER==pre_DSX_Opcode)||(S520_GPS_DELETE_LOCATION==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S509_GPS_WAYFINDER*/
unsigned char CondiCheck_S509_GPS_WAYFINDER(void)
{
    unsigned char retCond_uc = TRUE;
    if((S502_GPS_GET_CURRENT_LOCATION==pre_DSX_Opcode)||(S520_GPS_DELETE_LOCATION==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S519_GPS_WAYFINDER_EXIT*/
unsigned char CondiCheck_S519_GPS_WAYFINDER_EXIT(void)
{
    unsigned char retCond_uc = TRUE;
    if((S519a_GPS_WAYFINDER_CHANGE_LOCATION==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S519a_GPS_WAYFINDER_CHANGE_LOCATION*/
unsigned char CondiCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void)
{
    unsigned char retCond_uc = TRUE;
    if((S519_GPS_WAYFINDER_EXIT==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S520_GPS_DELETE_LOCATION*/
unsigned char CondiCheck_S520_GPS_DELETE_LOCATION(void)
{
    unsigned char retCond_uc = TRUE;
    if((S502_GPS_GET_CURRENT_LOCATION==pre_DSX_Opcode)||(S509_GPS_WAYFINDER==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_GASSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_GASSWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SPSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_SWITCHCC2BO==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDBO:
        if((DIVEMAINMENU_SLATES==pre_DSX_Opcode)||(DIVEMAINMENU_SWITCHBO2CC==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_BRIGHTNESS*/
unsigned char CondiCheck_DIVEMAINMENU_BRIGHTNESS(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SWITCHCC2BO==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDSM:
        if((DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((DIVEMAINMENU_RESETAVGDEPTH==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEPROFILE ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((DIVEMAINMENU_RESETAVGDEPTH==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEPROFILE ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDBO:
        if((DIVEMAINMENU_SWITCHBO2CC==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEMENU==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEMENU*/
unsigned char CondiCheck_DIVEMAINMENU_DIVEMENU(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SLATES*/
unsigned char CondiCheck_DIVEMAINMENU_SLATES(void)
{
    unsigned char retCond_uc = TRUE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SPSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_DIVEMENU==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGAUGE:
        if((DIVEMAINMENU_DIVEPROFILE==pre_DSX_Opcode)||(DIVEMAINMENU_TMTSWITCH ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    case NVD_MDGSM:
        if((DIVEMAINMENU_DIVEPROFILE==pre_DSX_Opcode)||(DIVEMAINMENU_TMTSWITCH ==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    default:
        if((DIVEMAINMENU_DIVEMENU==pre_DSX_Opcode)||(DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode))
        {
            retCond_uc = FALSE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_TMTSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_TMTSWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_RESETAVGDEPTH==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_RESETAVGDEPTH*/
unsigned char CondiCheck_DIVEMAINMENU_RESETAVGDEPTH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_TMTSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEPROFILE*/
unsigned char CondiCheck_DIVEMAINMENU_DIVEPROFILE(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SPSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_SPSWITCH(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_SLATES ==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHCC2BO*/
unsigned char CondiCheck_DIVEMAINMENU_SWITCHCC2BO(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHBO2CC*/
unsigned char CondiCheck_DIVEMAINMENU_SWITCHBO2CC(void)
{
    unsigned char retCond_uc = TRUE;
    if((DIVEMAINMENU_GASSWITCH==pre_DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==pre_DSX_Opcode))
    {
        retCond_uc = FALSE;
    }
    return retCond_uc;
};
/*
*Condition check when redraw the portion or not
* Return TRUE-> Redraw that item
* Return FALSE-> Do nothing
*/

/*Condition check return the result when need to clear all the the screen or one portion only of S18_SP_SWITCH*/
unsigned char CondiPreOcCheck_S18_SP_SWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S21_GAS_SWITCH==DSX_Opcode)||(S_SLATE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S21_GAS_SWITCH*/
unsigned char CondiPreOcCheck_S21_GAS_SWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S_SLATE==DSX_Opcode)||(S62_DIVE_PLANNER==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S_SLATE==DSX_Opcode)||(S62_DIVE_PLANNER==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S18_SP_SWITCH==DSX_Opcode)||(S62_DIVE_PLANNER==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S62_DIVE_PLANNER*/
unsigned char CondiPreOcCheck_S62_DIVE_PLANNER(void)
{
    unsigned char retCond_uc = FALSE;
    if((S21_GAS_SWITCH==DSX_Opcode)||(S27_LOG==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S27_LOG*/
unsigned char CondiPreOcCheck_S27_LOG(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S41_SET_MENU==DSX_Opcode)||(S404_TMT_SWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S41_SET_MENU==DSX_Opcode)||(S404_TMT_SWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S62_DIVE_PLANNER==DSX_Opcode)||(S41_SET_MENU ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S41_SET_MENU*/
unsigned char CondiPreOcCheck_S41_SET_MENU(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S27_LOG==DSX_Opcode)||(S432_DIVE_MODE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S27_LOG==DSX_Opcode)||(S432_DIVE_MODE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S27_LOG==DSX_Opcode)||(S185_INFO==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S185_INFO*/
unsigned char CondiPreOcCheck_S185_INFO(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S432_DIVE_MODE==DSX_Opcode)||(S_SLATE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S432_DIVE_MODE==DSX_Opcode)||(S_SLATE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S41_SET_MENU==DSX_Opcode)||(S_SLATE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S_SLATE*/
unsigned char CondiPreOcCheck_S_SLATE(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S21_GAS_SWITCH==DSX_Opcode)||(S185_INFO==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S21_GAS_SWITCH==DSX_Opcode)||(S185_INFO==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((S185_INFO==DSX_Opcode)||(S404_TMT_SWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S185_INFO==DSX_Opcode)||(S404_TMT_SWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S185_INFO==DSX_Opcode)||(S18_SP_SWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S404_TMT_SWITCH*/
unsigned char CondiPreOcCheck_S404_TMT_SWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S27_LOG==DSX_Opcode)||(S_SLATE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S432_DIVE_MODE*/
unsigned char CondiPreOcCheck_S432_DIVE_MODE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S41_SET_MENU==DSX_Opcode)||(S185_INFO==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S42_SET_GASES*/
unsigned char CondiPreOcCheck_S42_SET_GASES(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S_DIVE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S_DIVE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S53_SET_SP==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S53_SET_SP*/
unsigned char CondiPreOcCheck_S53_SET_SP(void)
{
    unsigned char retCond_uc = FALSE;
    if((S42_SET_GASES==DSX_Opcode)||(S_DIVE_SETTINGS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S_DIVE_SETTINGS*/
unsigned char CondiPreOcCheck_S_DIVE_SETTINGS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S42_SET_GASES==DSX_Opcode)||(S105_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S42_SET_GASES==DSX_Opcode)||(S105_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S53_SET_SP==DSX_Opcode)||(S105_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S105_ALARMS*/
unsigned char CondiPreOcCheck_S105_ALARMS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S128_DEVICE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S128_DEVICE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S_DIVE_SETTINGS==DSX_Opcode)||(S128_DEVICE_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_SETTINGS*/
unsigned char CondiPreOcCheck_S128_DEVICE_SETTINGS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S105_ALARMS==DSX_Opcode)||(S149_DATE_TIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S105_ALARMS==DSX_Opcode)||(S149_DATE_TIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S105_ALARMS==DSX_Opcode)||(S149_DATE_TIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S149_DATE_TIME*/
unsigned char CondiPreOcCheck_S149_DATE_TIME(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S128_DEVICE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S128_DEVICE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S128_DEVICE_SETTINGS==DSX_Opcode)||(S161_DISPLAY_SETTINGS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S161_DISPLAY_SETTINGS*/
unsigned char CondiPreOcCheck_S161_DISPLAY_SETTINGS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S105_ALARMS==DSX_Opcode)||(S149_DATE_TIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S105_ALARMS==DSX_Opcode)||(S149_DATE_TIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S149_DATE_TIME==DSX_Opcode)||(S42_SET_GASES==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DATE*/
unsigned char CondiPreOcCheck_S154_SET_DATE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S158_SET_TIME==DSX_Opcode)||(S152_SET_TIME_FORMAT==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_YY*/
unsigned char CondiPreOcCheck_S154_SET_YY(void)
{
    unsigned char retCond_uc = FALSE;
    if((S154_SET_MM==DSX_Opcode)||(S154_SET_DD==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_MM*/
unsigned char CondiPreOcCheck_S154_SET_MM(void)
{
    unsigned char retCond_uc = FALSE;
    if((S154_SET_YY==DSX_Opcode)||(S154_SET_DD==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DD*/
unsigned char CondiPreOcCheck_S154_SET_DD(void)
{
    unsigned char retCond_uc = FALSE;
    if((S154_SET_MM==DSX_Opcode)||(S154_SET_YY==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_TIME*/
unsigned char CondiPreOcCheck_S158_SET_TIME(void)
{
    unsigned char retCond_uc = FALSE;
    if((S154_SET_DATE==DSX_Opcode)||(S150_SET_DATE_FORMAT==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_HH*/
unsigned char CondiPreOcCheck_S158_SET_HH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S158_SET_MM==DSX_Opcode)||(S158_SET_AM_PM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_MM*/
unsigned char CondiPreOcCheck_S158_SET_MM(void)
{
    unsigned char retCond_uc = FALSE;
    if((S158_SET_HH==DSX_Opcode)||(S158_SET_AM_PM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_AM_PM*/
unsigned char CondiPreOcCheck_S158_SET_AM_PM(void)
{
    unsigned char retCond_uc = FALSE;
    if((S158_SET_HH==DSX_Opcode)||(S158_SET_MM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S150_SET_DATE_FORMAT*/
unsigned char CondiPreOcCheck_S150_SET_DATE_FORMAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((S158_SET_TIME==DSX_Opcode)||(S152_SET_TIME_FORMAT==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S152_SET_TIME_FORMAT*/
unsigned char CondiPreOcCheck_S152_SET_TIME_FORMAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((S150_SET_DATE_FORMAT==DSX_Opcode)||(S154_SET_DATE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_CC_GASES*/
unsigned char CondiPreOcCheck_SETGASES_SET_CC_GASES(void)
{
    unsigned char retCond_uc = FALSE;
    if((SETGASES_SET_BO_GASES==DSX_Opcode)||(SETGASES_O2_ANALYZER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_BO_GASES*/
unsigned char CondiPreOcCheck_SETGASES_SET_BO_GASES(void)
{
    unsigned char retCond_uc = FALSE;
    if((SETGASES_SET_CC_GASES==DSX_Opcode)||(SETGASES_O2_ANALYZER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_O2_ANALYZER*/
unsigned char CondiPreOcCheck_SETGASES_O2_ANALYZER(void)
{
    unsigned char retCond_uc = FALSE;
    if((SETGASES_SET_CC_GASES==DSX_Opcode)||(SETGASES_SET_BO_GASES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_01*/
unsigned char CondiPreOcCheck_S70_SET_GAS_01(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_02==DSX_Opcode)||(S70_O2_ANALYZER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_02*/
unsigned char CondiPreOcCheck_S70_SET_GAS_02(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_01==DSX_Opcode)||(S70_SET_GAS_03==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_03*/
unsigned char CondiPreOcCheck_S70_SET_GAS_03(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_02==DSX_Opcode)||(S70_SET_GAS_04==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_04*/
unsigned char CondiPreOcCheck_S70_SET_GAS_04(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_03==DSX_Opcode)||(S70_SET_GAS_05==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_05*/
unsigned char CondiPreOcCheck_S70_SET_GAS_05(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_04==DSX_Opcode)||(S70_SET_GAS_06==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_06*/
unsigned char CondiPreOcCheck_S70_SET_GAS_06(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_05==DSX_Opcode)||(S70_O2_ANALYZER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S70_O2_ANALYZER*/
unsigned char CondiPreOcCheck_S70_O2_ANALYZER(void)
{
    unsigned char retCond_uc = FALSE;
    if((S70_SET_GAS_06==DSX_Opcode)||(S70_SET_GAS_01==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_01*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_01(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_01==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_02*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_02(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_02==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_03*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_03(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_03==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_04*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_04(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_04==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_05*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_05(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_05==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S72_SET_GAS_FO2_06*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_06(void)
{
    unsigned char retCond_uc = FALSE;
    if((S73_SET_GAS_FHe_06==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S462_O2ANALYZER_CALIBRATE*/
unsigned char CondiPreOcCheck_S462_O2ANALYZER_CALIBRATE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S470_O2ANALYZER_ANALYZE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S470_O2ANALYZER_ANALYZE*/
unsigned char CondiPreOcCheck_S470_O2ANALYZER_ANALYZE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S462_O2ANALYZER_CALIBRATE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_HIGH_SP*/
unsigned char CondiPreOcCheck_S54_SP_HIGH_SP(void)
{
    unsigned char retCond_uc = FALSE;
    if((S54_SP_LOW_SP==DSX_Opcode)||(S59_SP_AUTO_LOW==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_LOW_SP*/
unsigned char CondiPreOcCheck_S54_SP_LOW_SP(void)
{
    unsigned char retCond_uc = FALSE;
    if((S54_SP_HIGH_SP==DSX_Opcode)||(S56_SP_CUSTOM_SP==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S56_SP_CUSTOM_SP*/
unsigned char CondiPreOcCheck_S56_SP_CUSTOM_SP(void)
{
    unsigned char retCond_uc = FALSE;
    if((S54_SP_LOW_SP==DSX_Opcode)||(S59_SP_AUTO_HIGH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_HIGH*/
unsigned char CondiPreOcCheck_S59_SP_AUTO_HIGH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S56_SP_CUSTOM_SP==DSX_Opcode)||(S59_SP_AUTO_LOW==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_LOW*/
unsigned char CondiPreOcCheck_S59_SP_AUTO_LOW(void)
{
    unsigned char retCond_uc = FALSE;
    if((S59_SP_AUTO_HIGH==DSX_Opcode)||(S54_SP_HIGH_SP==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S99_SET_DIVEMODE*/
unsigned char CondiPreOcCheck_S99_SET_DIVEMODE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S76_SET_BAILOUTPO2LIMITS==DSX_Opcode)||(S96_SET_LASTSTOPDEPTH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S76_SET_BAILOUTPO2LIMITS*/
unsigned char CondiPreOcCheck_S76_SET_BAILOUTPO2LIMITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S99_SET_DIVEMODE==DSX_Opcode)||(S83_SET_CONSERVATISM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S83_SET_CONSERVATISM*/
unsigned char CondiPreOcCheck_S83_SET_CONSERVATISM(void)
{
    unsigned char retCond_uc = FALSE;
    if((S91_SET_SAFETYSTOP==DSX_Opcode)||(S76_SET_BAILOUTPO2LIMITS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S91_SET_SAFETYSTOP*/
unsigned char CondiPreOcCheck_S91_SET_SAFETYSTOP(void)
{
    unsigned char retCond_uc = FALSE;
    if((S96_SET_LASTSTOPDEPTH==DSX_Opcode)||(S83_SET_CONSERVATISM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S96_SET_LASTSTOPDEPTH*/
unsigned char CondiPreOcCheck_S96_SET_LASTSTOPDEPTH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S91_SET_SAFETYSTOP==DSX_Opcode)||(S99_SET_DIVEMODE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_SAFETYSTOP_DEPTHT*/
unsigned char CondiPreOcCheck_SET_SAFETYSTOP_DEPTHT(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_SAFETYSTOP_TIME==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S106_AL_AUDIBLE*/
unsigned char CondiPreOcCheck_S106_AL_AUDIBLE(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((S108_AL_DEPTH==DSX_Opcode)||(S122_AL_GF_N2==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDOC:
        if((S108_AL_DEPTH==DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S108_AL_DEPTH==DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S108_AL_DEPTH==DSX_Opcode)||(S281_AL_TURN_END_PRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S108_AL_DEPTH*/
unsigned char CondiPreOcCheck_S108_AL_DEPTH(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S106_AL_AUDIBLE==DSX_Opcode)||(S111_AL_DIVETIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S106_AL_AUDIBLE==DSX_Opcode)||(S111_AL_DIVETIME==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S106_AL_AUDIBLE==DSX_Opcode)||(S000_AL_DIVETIME_TTS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S111_AL_DIVETIME*/
unsigned char CondiPreOcCheck_S111_AL_DIVETIME(void)
{
    unsigned char retCond_uc = FALSE;
    if((S108_AL_DEPTH==DSX_Opcode)||(S281_AL_TURN_END_PRESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_DTR*/
unsigned char CondiPreOcCheck_S116_AL_DTR(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S000_AL_DIVETIME_TTS==DSX_Opcode)||(S281_AL_TURN_END_PRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S000_AL_DIVETIME_TTS==DSX_Opcode)||(S281_AL_TURN_END_PRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S000_AL_DIVETIME_TTS==DSX_Opcode)||(S116_AL_TANK_PRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_TANK_PRESS*/
unsigned char CondiPreOcCheck_S116_AL_TANK_PRESS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S116_AL_DTR==DSX_Opcode)||(S119_AL_CC6_PRESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S119_AL_CC6_PRESS*/
unsigned char CondiPreOcCheck_S119_AL_CC6_PRESS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S116_AL_TANK_PRESS==DSX_Opcode)||(S122_AL_GF_N2==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S122_AL_GF_N2*/
unsigned char CondiPreOcCheck_S122_AL_GF_N2(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((S281_AL_TURN_END_PRESS==DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((S281_AL_TURN_END_PRESS==DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S281_AL_TURN_END_PRESS==DSX_Opcode)||(S288_AL_END_WOB_ICD_ALARMS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S119_AL_CC6_PRESS==DSX_Opcode)||(S106_AL_AUDIBLE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S281_AL_TURN_END_PRESS*/
unsigned char CondiPreOcCheck_S281_AL_TURN_END_PRESS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S111_AL_DIVETIME==DSX_Opcode)||(S106_AL_AUDIBLE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S111_AL_DIVETIME==DSX_Opcode)||(S106_AL_AUDIBLE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S116_AL_DTR==DSX_Opcode)||(S122_AL_GF_N2==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S288_AL_END_WOB_ICD_ALARMS*/
unsigned char CondiPreOcCheck_S288_AL_END_WOB_ICD_ALARMS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S106_AL_AUDIBLE==DSX_Opcode)||(S122_AL_GF_N2==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S000_AL_DIVETIME_TTS*/
unsigned char CondiPreOcCheck_S000_AL_DIVETIME_TTS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S108_AL_DEPTH==DSX_Opcode)||(S116_AL_DTR==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_TRANSMITTERS*/
unsigned char CondiPreOcCheck_S128_DEVICE_TRANSMITTERS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S137_DEVICE_UNITS==DSX_Opcode)||(TBD_DEVICE_WELCOMESCREEN==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S137_DEVICE_UNITS*/
unsigned char CondiPreOcCheck_S137_DEVICE_UNITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_DEVICE_TRANSMITTERS==DSX_Opcode)||(S139_DEVICE_WATERTYPE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S139_DEVICE_WATERTYPE*/
unsigned char CondiPreOcCheck_S139_DEVICE_WATERTYPE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S137_DEVICE_UNITS==DSX_Opcode)||(S141_DEVICE_SAMPLERATE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S141_DEVICE_SAMPLERATE*/
unsigned char CondiPreOcCheck_S141_DEVICE_SAMPLERATE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S139_DEVICE_WATERTYPE==DSX_Opcode)||(S143_DEVICE_BLUETOOTH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S143_DEVICE_BLUETOOTH*/
unsigned char CondiPreOcCheck_S143_DEVICE_BLUETOOTH(void)
{
    unsigned char retCond_uc = FALSE;
    if((S141_DEVICE_SAMPLERATE==DSX_Opcode)||(TBD_DEVICE_RESETSETTINGS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_RESETSETTINGS*/
unsigned char CondiPreOcCheck_TBD_DEVICE_RESETSETTINGS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S143_DEVICE_BLUETOOTH==DSX_Opcode)||(TBD_DEVICE_WELCOMESCREEN==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_WELCOMESCREEN*/
unsigned char CondiPreOcCheck_TBD_DEVICE_WELCOMESCREEN(void)
{
    unsigned char retCond_uc = FALSE;
    if((TBD_DEVICE_RESETSETTINGS==DSX_Opcode)||(S128_DEVICE_TRANSMITTERS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S162_DISPLAY_BRIGHTNESS*/
unsigned char CondiPreOcCheck_S162_DISPLAY_BRIGHTNESS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((S164_DISPLAY_AUTODIM==DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDOC:
        if((S164_DISPLAY_AUTODIM==DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((S164_DISPLAY_AUTODIM==DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S164_DISPLAY_AUTODIM==DSX_Opcode)||(S372_DISPLAY_GTR==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S164_DISPLAY_AUTODIM*/
unsigned char CondiPreOcCheck_S164_DISPLAY_AUTODIM(void)
{
    unsigned char retCond_uc = FALSE;
    if((S162_DISPLAY_BRIGHTNESS==DSX_Opcode)||(S173_DISPLAY_TITLESCOLOR==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S173_DISPLAY_TITLESCOLOR*/
unsigned char CondiPreOcCheck_S173_DISPLAY_TITLESCOLOR(void)
{
    unsigned char retCond_uc = FALSE;
    if((S164_DISPLAY_AUTODIM==DSX_Opcode)||(S179_DISPLAY_LANGUAGE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S179_DISPLAY_LANGUAGE*/
unsigned char CondiPreOcCheck_S179_DISPLAY_LANGUAGE(void)
{
    unsigned char retCond_uc = FALSE;
    if((S173_DISPLAY_TITLESCOLOR==DSX_Opcode)||(S178_DISPLAY_FLIPSCREEN==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S178_DISPLAY_FLIPSCREEN*/
unsigned char CondiPreOcCheck_S178_DISPLAY_FLIPSCREEN(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S179_DISPLAY_LANGUAGE==DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S179_DISPLAY_LANGUAGE==DSX_Opcode)||(S428_DISPLAY_EXTRALARGE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S179_DISPLAY_LANGUAGE==DSX_Opcode)||(S166_DISPLAY_MAINDISPLAY==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S166_DISPLAY_MAINDISPLAY*/
unsigned char CondiPreOcCheck_S166_DISPLAY_MAINDISPLAY(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S178_DISPLAY_FLIPSCREEN==DSX_Opcode)||(S372_DISPLAY_GTR==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S372_DISPLAY_GTR*/
unsigned char CondiPreOcCheck_S372_DISPLAY_GTR(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S166_DISPLAY_MAINDISPLAY==DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S162_DISPLAY_BRIGHTNESS==DSX_Opcode)||(S428_DISPLAY_EXTRALARGE ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==DSX_Opcode)||(S162_DISPLAY_BRIGHTNESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S428_DISPLAY_EXTRALARGE*/
unsigned char CondiPreOcCheck_S428_DISPLAY_EXTRALARGE(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDGAUGE:
        if((S162_DISPLAY_BRIGHTNESS==DSX_Opcode)||(S178_DISPLAY_FLIPSCREEN==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S178_DISPLAY_FLIPSCREEN==DSX_Opcode)||(S372_DISPLAY_GTR==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_LEFT*/
unsigned char CondiPreOcCheck_MAINDISPLAY_LEFT(void)
{
    unsigned char retCond_uc = FALSE;
    if((MAINDISPLAY_RIGHT==DSX_Opcode)||(MAINDISPLAY_EXTRALARGE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_RIGHT*/
unsigned char CondiPreOcCheck_MAINDISPLAY_RIGHT(void)
{
    unsigned char retCond_uc = FALSE;
    if((MAINDISPLAY_LEFT==DSX_Opcode)||(MAINDISPLAY_GFBG==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_GFBG*/
unsigned char CondiPreOcCheck_MAINDISPLAY_GFBG(void)
{
    unsigned char retCond_uc = FALSE;
    if((MAINDISPLAY_RIGHT==DSX_Opcode)||(MAINDISPLAY_EXTRALARGE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_EXTRALARGE*/
unsigned char CondiPreOcCheck_MAINDISPLAY_EXTRALARGE(void)
{
    unsigned char retCond_uc = FALSE;
    if((MAINDISPLAY_GFBG==DSX_Opcode)||(MAINDISPLAY_LEFT==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT1*/
unsigned char CondiPreOcCheck_S128_TM_TMT1(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT2==DSX_Opcode)||(S128_TM_TMT6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT2*/
unsigned char CondiPreOcCheck_S128_TM_TMT2(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT1==DSX_Opcode)||(S128_TM_TMT3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT3*/
unsigned char CondiPreOcCheck_S128_TM_TMT3(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT2==DSX_Opcode)||(S128_TM_TMT4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT4*/
unsigned char CondiPreOcCheck_S128_TM_TMT4(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT3==DSX_Opcode)||(S128_TM_TMT5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT5*/
unsigned char CondiPreOcCheck_S128_TM_TMT5(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT4==DSX_Opcode)||(S128_TM_TMT6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT6*/
unsigned char CondiPreOcCheck_S128_TM_TMT6(void)
{
    unsigned char retCond_uc = FALSE;
    if((S128_TM_TMT1==DSX_Opcode)||(S128_TM_TMT5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_2==DSX_Opcode)||(SET_TMT_1_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_1==DSX_Opcode)||(SET_TMT_1_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_2==DSX_Opcode)||(SET_TMT_1_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_3==DSX_Opcode)||(SET_TMT_1_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_4==DSX_Opcode)||(SET_TMT_1_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_1_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_1_DIGIT_5==DSX_Opcode)||(SET_TMT_1_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_2==DSX_Opcode)||(SET_TMT_2_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_1==DSX_Opcode)||(SET_TMT_2_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_2==DSX_Opcode)||(SET_TMT_2_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_3==DSX_Opcode)||(SET_TMT_2_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_4==DSX_Opcode)||(SET_TMT_2_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_2_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_2_DIGIT_5==DSX_Opcode)||(SET_TMT_2_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_2==DSX_Opcode)||(SET_TMT_3_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_1==DSX_Opcode)||(SET_TMT_3_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_2==DSX_Opcode)||(SET_TMT_3_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_3==DSX_Opcode)||(SET_TMT_3_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_4==DSX_Opcode)||(SET_TMT_3_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_3_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_3_DIGIT_5==DSX_Opcode)||(SET_TMT_3_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_2==DSX_Opcode)||(SET_TMT_4_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_1==DSX_Opcode)||(SET_TMT_4_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_2==DSX_Opcode)||(SET_TMT_4_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_3==DSX_Opcode)||(SET_TMT_4_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_4==DSX_Opcode)||(SET_TMT_4_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_4_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_4_DIGIT_5==DSX_Opcode)||(SET_TMT_4_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_2==DSX_Opcode)||(SET_TMT_5_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_1==DSX_Opcode)||(SET_TMT_5_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_2==DSX_Opcode)||(SET_TMT_5_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_3==DSX_Opcode)||(SET_TMT_5_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_4==DSX_Opcode)||(SET_TMT_5_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_5_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_5_DIGIT_5==DSX_Opcode)||(SET_TMT_5_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_1(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_2==DSX_Opcode)||(SET_TMT_6_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_2(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_1==DSX_Opcode)||(SET_TMT_6_DIGIT_3==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_3(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_2==DSX_Opcode)||(SET_TMT_6_DIGIT_4==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_4(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_3==DSX_Opcode)||(SET_TMT_6_DIGIT_5==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_5(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_4==DSX_Opcode)||(SET_TMT_6_DIGIT_6==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SET_TMT_6_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_6(void)
{
    unsigned char retCond_uc = FALSE;
    if((SET_TMT_6_DIGIT_5==DSX_Opcode)||(SET_TMT_6_DIGIT_1==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S187_IM_MYINFO*/
unsigned char CondiPreOcCheck_S187_IM_MYINFO(void)
{
    unsigned char retCond_uc = FALSE;
    if((S190_IM_DSXINFO==DSX_Opcode)||(S224_IM_MANUFACTURER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S190_IM_DSXINFO*/
unsigned char CondiPreOcCheck_S190_IM_DSXINFO(void)
{
    unsigned char retCond_uc = FALSE;
    if((S187_IM_MYINFO==DSX_Opcode)||(S192_IM_HISTORY==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S192_IM_HISTORY*/
unsigned char CondiPreOcCheck_S192_IM_HISTORY(void)
{
    unsigned char retCond_uc = FALSE;
    if((S190_IM_DSXINFO==DSX_Opcode)||(S224_IM_MANUFACTURER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S224_IM_MANUFACTURER*/
unsigned char CondiPreOcCheck_S224_IM_MANUFACTURER(void)
{
    unsigned char retCond_uc = FALSE;
    if((S192_IM_HISTORY==DSX_Opcode)||(S187_IM_MYINFO==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_HIGH*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_HIGH(void)
{
    unsigned char retCond_uc = FALSE;
    if((SP_SWITCH_TO_CUSTOM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_LOW*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_LOW(void)
{
    unsigned char retCond_uc = FALSE;
    if((SP_SWITCH_TO_CUSTOM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_CUSTOM*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_CUSTOM(void)
{
    unsigned char retCond_uc = FALSE;
    if((SP_SWITCH_TO_LOW==DSX_Opcode)||(SP_SWITCH_TO_HIGH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_TIME_LIMITS*/
unsigned char CondiPreOcCheck_DIVE_PL_TIME_LIMITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DEPTH_LIMITS==DSX_Opcode)||(DIVE_PL_DIVE_SIM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DEPTH_LIMITS*/
unsigned char CondiPreOcCheck_DIVE_PL_DEPTH_LIMITS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_TIME_LIMITS==DSX_Opcode)||(DIVE_PL_DIVE_SIM==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DEPTH_LIMITS==DSX_Opcode)||(DIVE_PL_TIME_LIMITS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_NEWORCONTINUOS*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DIVE_SIM_SIMULATEDIVE==DSX_Opcode)||(DIVE_PL_DIVE_SIM_DEPTH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_DEPTH*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_DEPTH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==DSX_Opcode)||(DIVE_PL_DIVE_SIM_TIME==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_TIME*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_TIME(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DIVE_SIM_DEPTH==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SAC*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SAC(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((DIVE_PL_DIVE_SIM_TIME==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((DIVE_PL_DIVE_SIM_TIME==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((DIVE_PL_DIVE_SIM_TIME==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SP==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SP*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SP(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVE_PL_DIVE_SIM_SAC==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SIMULATEDIVE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SIMULATEDIVE*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDOC:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SAC==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((DIVE_PL_DIVE_SIM_NEWORCONTINUOS==DSX_Opcode)||(DIVE_PL_DIVE_SIM_SP==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MIN*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_MIN(void)
{
    unsigned char retCond_uc = FALSE;
    if((BAILOUT_PO2_OC_MAX==DSX_Opcode)||(BAILOUT_PO2_OC_DECO==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MAX*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_MAX(void)
{
    unsigned char retCond_uc = FALSE;
    if((BAILOUT_PO2_OC_MIN==DSX_Opcode)||(BAILOUT_PO2_OC_DECO==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_DECO*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_DECO(void)
{
    unsigned char retCond_uc = FALSE;
    if((BAILOUT_PO2_OC_MAX==DSX_Opcode)||(BAILOUT_PO2_OC_MIN==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_LOW*/
unsigned char CondiPreOcCheck_CONSERV_TEC_GF_LOW(void)
{
    unsigned char retCond_uc = FALSE;
    if((CONSERV_TEC_GF_HIGH==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_HIGH*/
unsigned char CondiPreOcCheck_CONSERV_TEC_GF_HIGH(void)
{
    unsigned char retCond_uc = FALSE;
    if((CONSERV_TEC_GF_LOW==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_AUDIBLE*/
unsigned char CondiPreOcCheck_ALARM_AUDIBLE(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_VIBRATION==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_VIBRATION*/
unsigned char CondiPreOcCheck_ALARM_VIBRATION(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_AUDIBLE==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DEPTH_STAT*/
unsigned char CondiPreOcCheck_ALARM_DEPTH_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_DEPTH_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME*/
unsigned char CondiPreOcCheck_ALARM_DIVETIME(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_TTS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME_STAT*/
unsigned char CondiPreOcCheck_ALARM_DIVETIME_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_DIVETIME_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS*/
unsigned char CondiPreOcCheck_ALARM_TTS(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_DIVETIME==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS_STAT*/
unsigned char CondiPreOcCheck_ALARM_TTS_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_TTS_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DTR_STAT*/
unsigned char CondiPreOcCheck_ALARM_DTR_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_DTR_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TANK_PRESS_STAT*/
unsigned char CondiPreOcCheck_ALARM_TANK_PRESS_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_TANK_PRESS_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_CC6_PRESS_STAT*/
unsigned char CondiPreOcCheck_ALARM_CC6_PRESS_STAT(void)
{
    unsigned char retCond_uc = FALSE;
    if((ALARM_CC6_PRESS_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S282_ALARM_TURNPRESS*/
unsigned char CondiPreOcCheck_S282_ALARM_TURNPRESS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S285_ALARM_ENDPRESS==DSX_Opcode)||(S353_ALARM_SWITCHPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((S285_ALARM_ENDPRESS==DSX_Opcode)||(S353_ALARM_SWITCHPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S285_ALARM_ENDPRESS==DSX_Opcode)||(S353_ALARM_SWITCHPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S285_ALARM_ENDPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S285_ALARM_ENDPRESS*/
unsigned char CondiPreOcCheck_S285_ALARM_ENDPRESS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDSM:
        if((S353_ALARM_SWITCHPRESS==DSX_Opcode)||(S282_ALARM_TURNPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((S353_ALARM_SWITCHPRESS==DSX_Opcode)||(S282_ALARM_TURNPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((S353_ALARM_SWITCHPRESS==DSX_Opcode)||(S282_ALARM_TURNPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((S282_ALARM_TURNPRESS==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S353_ALARM_SWITCHPRESS*/
unsigned char CondiPreOcCheck_S353_ALARM_SWITCHPRESS(void)
{
    unsigned char retCond_uc = FALSE;
    if((S285_ALARM_ENDPRESS==DSX_Opcode)||(S282_ALARM_TURNPRESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S289_ALARM_END*/
unsigned char CondiPreOcCheck_S289_ALARM_END(void)
{
    unsigned char retCond_uc = FALSE;
    if((S292_ALARM_WOB==DSX_Opcode)||(S297_ALARM_O2_NARCOTIC==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S292_ALARM_WOB*/
unsigned char CondiPreOcCheck_S292_ALARM_WOB(void)
{
    unsigned char retCond_uc = FALSE;
    if((S295_ALARM_ICD==DSX_Opcode)||(S289_ALARM_END==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S295_ALARM_ICD*/
unsigned char CondiPreOcCheck_S295_ALARM_ICD(void)
{
    unsigned char retCond_uc = FALSE;
    if((S292_ALARM_WOB==DSX_Opcode)||(S297_ALARM_O2_NARCOTIC==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S297_ALARM_O2_NARCOTIC*/
unsigned char CondiPreOcCheck_S297_ALARM_O2_NARCOTIC(void)
{
    unsigned char retCond_uc = FALSE;
    if((S295_ALARM_ICD==DSX_Opcode)||( S289_ALARM_END==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of C7_COMPASS_CALIBRATION*/
unsigned char CondiPreOcCheck_C7_COMPASS_CALIBRATION(void)
{
    unsigned char retCond_uc = FALSE;
    if((C13_COMPASS_DECLIN_SET==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of C13_COMPASS_DECLIN_SET*/
unsigned char CondiPreOcCheck_C13_COMPASS_DECLIN_SET(void)
{
    unsigned char retCond_uc = FALSE;
    if((C7_COMPASS_CALIBRATION==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S502_GPS_GET_CURRENT_LOCATION*/
unsigned char CondiPreOcCheck_S502_GPS_GET_CURRENT_LOCATION(void)
{
    unsigned char retCond_uc = FALSE;
    if((S509_GPS_WAYFINDER==DSX_Opcode)||(S520_GPS_DELETE_LOCATION==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S509_GPS_WAYFINDER*/
unsigned char CondiPreOcCheck_S509_GPS_WAYFINDER(void)
{
    unsigned char retCond_uc = FALSE;
    if((S502_GPS_GET_CURRENT_LOCATION==DSX_Opcode)||(S520_GPS_DELETE_LOCATION==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S519_GPS_WAYFINDER_EXIT*/
unsigned char CondiPreOcCheck_S519_GPS_WAYFINDER_EXIT(void)
{
    unsigned char retCond_uc = FALSE;
    if((S519a_GPS_WAYFINDER_CHANGE_LOCATION==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S519a_GPS_WAYFINDER_CHANGE_LOCATION*/
unsigned char CondiPreOcCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void)
{
    unsigned char retCond_uc = FALSE;
    if((S519_GPS_WAYFINDER_EXIT==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of S520_GPS_DELETE_LOCATION*/
unsigned char CondiPreOcCheck_S520_GPS_DELETE_LOCATION(void)
{
    unsigned char retCond_uc = FALSE;
    if((S502_GPS_GET_CURRENT_LOCATION==DSX_Opcode)||(S509_GPS_WAYFINDER==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_GASSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_GASSWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SPSWITCH==DSX_Opcode)||(DIVEMAINMENU_SWITCHCC2BO==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((DIVEMAINMENU_BRIGHTNESS==DSX_Opcode)||(DIVEMAINMENU_SLATES ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDBO:
        if((DIVEMAINMENU_SLATES==DSX_Opcode)||(DIVEMAINMENU_SWITCHBO2CC==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((DIVEMAINMENU_BRIGHTNESS==DSX_Opcode)||(DIVEMAINMENU_SLATES==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_BRIGHTNESS*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_BRIGHTNESS(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SWITCHCC2BO==DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDSM:
        if((DIVEMAINMENU_GASSWITCH==DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((DIVEMAINMENU_RESETAVGDEPTH==DSX_Opcode)||(DIVEMAINMENU_DIVEPROFILE ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((DIVEMAINMENU_RESETAVGDEPTH==DSX_Opcode)||(DIVEMAINMENU_DIVEPROFILE ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDBO:
        if((DIVEMAINMENU_SWITCHBO2CC==DSX_Opcode)||(DIVEMAINMENU_DIVEMENU ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((DIVEMAINMENU_GASSWITCH==DSX_Opcode)||(DIVEMAINMENU_DIVEMENU==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEMENU*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_DIVEMENU(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_BRIGHTNESS==DSX_Opcode)||(DIVEMAINMENU_SLATES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SLATES*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SLATES(void)
{
    unsigned char retCond_uc = FALSE;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        if((DIVEMAINMENU_SPSWITCH==DSX_Opcode)||(DIVEMAINMENU_DIVEMENU==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGAUGE:
        if((DIVEMAINMENU_DIVEPROFILE==DSX_Opcode)||(DIVEMAINMENU_TMTSWITCH ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    case NVD_MDGSM:
        if((DIVEMAINMENU_DIVEPROFILE==DSX_Opcode)||(DIVEMAINMENU_TMTSWITCH ==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    default:
        if((DIVEMAINMENU_DIVEMENU==DSX_Opcode)||(DIVEMAINMENU_GASSWITCH==DSX_Opcode))
        {
            retCond_uc = TRUE;
        }
        break;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_TMTSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_TMTSWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_RESETAVGDEPTH==DSX_Opcode)||(DIVEMAINMENU_SLATES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_RESETAVGDEPTH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_RESETAVGDEPTH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_TMTSWITCH==DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEPROFILE*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_DIVEPROFILE(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_BRIGHTNESS==DSX_Opcode)||(DIVEMAINMENU_SLATES==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SPSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SPSWITCH(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_GASSWITCH==DSX_Opcode)||(DIVEMAINMENU_SLATES ==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHCC2BO*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SWITCHCC2BO(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_GASSWITCH==DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHBO2CC*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SWITCHBO2CC(void)
{
    unsigned char retCond_uc = FALSE;
    if((DIVEMAINMENU_GASSWITCH==DSX_Opcode)||(DIVEMAINMENU_BRIGHTNESS==DSX_Opcode))
    {
        retCond_uc = TRUE;
    }
    return retCond_uc;
};
