/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"
/*Config data pointer*/
NVD_status_t SetGasGetSetpoint(unsigned char gasNumPos)
{
    /*Set gas only in CC, OC, SM, BO mode only with the others -> change OFF*/
    NVD_status_t retValue = NVD_OFF;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        retValue = GUI_SetPoints_Gas_CC[gasNumPos];
        break;
    case NVD_MDOC:
        retValue = GUI_SetPoints_Gas_OC[gasNumPos];
        break;
    case NVD_MDSM:
        retValue = GUI_SetPoints_Gas_SM[gasNumPos];
        break;
    case NVD_MDBO:
        retValue = GUI_SetPoints_Gas_BO[gasNumPos];
        break;
    default:
        /*Do nothing*/
        break;
    }
    return retValue;
}
unsigned char SetGasGetFO2(unsigned char gasNumPos)
{
    /*Set gas only in CC, OC, SM, BO mode only with the others -> change OFF*/
    unsigned char retValue = 0x00;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        retValue = GUI_FO2_Gas_CC[gasNumPos];
        break;
    case NVD_MDOC:
        retValue = GUI_FO2_Gas_OC[gasNumPos];
        break;
    case NVD_MDSM:
        retValue = GUI_FO2_Gas_SM[gasNumPos];
        break;
    case NVD_MDBO:
        retValue = GUI_FO2_Gas_BO[gasNumPos];
        break;
    default:
        /*Do nothing*/
        break;
    }
    return retValue;
}
unsigned char SetGasGetFHe(unsigned char gasNumPos)
{
    /*Set gas only in CC, OC, SM, BO  mode only with the others -> change OFF*/
    unsigned char retValue = 0x00;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        retValue = GUI_FHe_Gas_CC[gasNumPos];
        break;
    case NVD_MDOC:
        retValue = GUI_FHe_Gas_OC[gasNumPos];
        break;
    case NVD_MDSM:
        retValue = GUI_FHe_Gas_SM[gasNumPos];
        break;
    case NVD_MDBO:
        retValue = GUI_FHe_Gas_BO[gasNumPos];
        break;
    default:
        /*Do nothing*/
        break;
    }
    return retValue;
}
/*Define the titlle of set gas content*/
static const TxtStr_Name_e TxtDefSetGasTittle[SetGases_Mode_MAX][SetGASES_MAX] =
{
    {(TxtStr_Name_e)0, TxtStr_CC_1, TxtStr_CC_2, TxtStr_CC_3, TxtStr_CC_4, TxtStr_CC_5, TxtStr_CC_6, TxtStr_CC_1},      /*CC*/
    {(TxtStr_Name_e)0, TxtStr_OC_1, TxtStr_OC_2, TxtStr_OC_3, TxtStr_OC_4, TxtStr_OC_5, TxtStr_OC_6, (TxtStr_Name_e)0}, /*OC*/
    {(TxtStr_Name_e)0, TxtStr_OC_L, TxtStr_OC_R, TxtStr_OC_3, TxtStr_OC_4, TxtStr_OC_5, TxtStr_OC_6, (TxtStr_Name_e)0}, /*SM*/
    {(TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0}, /*GSM*/
    {(TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0, (TxtStr_Name_e)0}, /*GAUGE*/
    {(TxtStr_Name_e)0, TxtStr_BO_1, TxtStr_BO_2, TxtStr_BO_3, TxtStr_BO_4, TxtStr_BO_5, TxtStr_BO_6, (TxtStr_Name_e)0}, /*BO*/
};
/*Get the gas current gas mode*/
TxtStr_Name_e SetGasGetMode(unsigned char diveModeInput, unsigned char gasNumPos)
{
    /*Set gas only in CC, OC, SM, BO mode only with the others -> change OFF*/
    TxtStr_Name_e retValue = TxtStr_CC_1;
    /*Verify the gas num pos value*/
    if((SetGASES_MAX > gasNumPos)&&(SetGases_Mode_MAX > diveModeInput))
    {
        /*Passed verify*/
        switch(diveModeInput)
        {
        case NVD_MDCC:
            retValue = TxtDefSetGasTittle[SetGases_Mode_CC][gasNumPos];
            break;
        case NVD_MDOC:
            retValue = TxtDefSetGasTittle[SetGases_Mode_OC][gasNumPos];
            break;
        case NVD_MDSM:
            retValue = TxtDefSetGasTittle[SetGases_Mode_SM][gasNumPos];
            break;
        case NVD_MDBO:
            retValue = TxtDefSetGasTittle[SetGases_Mode_BO][gasNumPos];
            break;
        default:
            /*Do nothing*/
            break;
        }
    }
    else
    {
        /*Return default*/
    }
    return retValue;
}
const TxtStr_Name_e TxtDefSetGasTMT[SetGases_TMT_MAX] =
{
    TxtStr_NO_TMT,
    TxtStr_TMT_1,
    TxtStr_TMT_2,
    TxtStr_TMT_3,
    TxtStr_TMT_4,
    TxtStr_TMT_5,
    TxtStr_TMT_6,
};
/*Get the gas current gas mode*/
TMT_NUM_t SetGasGetTMTValue(unsigned char gasNumPos)
{
    /*Set gas only in CC, OC, SM, BO mode only with the others -> change OFF*/
    TMT_NUM_t retValue = TMT_OFF;
    switch(GUI_DIVE_Mode)
    {
    case NVD_MDCC:
        retValue = GUI_NumOfTMT_Gas_CC[gasNumPos];
        break;
    case NVD_MDOC:
        retValue = GUI_NumOfTMT_Gas_OC[gasNumPos];
        break;
    case NVD_MDSM:
        retValue = GUI_NumOfTMT_Gas_SM[gasNumPos];
        break;
    case NVD_MDBO:
        retValue = GUI_NumOfTMT_Gas_BO[gasNumPos];
        break;
    default:
        /*Do nothing*/
        break;
    }
    return retValue;
}
