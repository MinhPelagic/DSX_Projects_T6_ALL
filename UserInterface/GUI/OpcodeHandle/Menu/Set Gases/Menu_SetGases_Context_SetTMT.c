/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

/*Context memdev config to SetGases_01*/
static void SetGases_SetTMT_01(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_01)]));
}
/*Context memdev config to SetGases_02*/
static void SetGases_SetTMT_02(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_02)]));
}
/*Context memdev config to SetGases_03*/
static void SetGases_SetTMT_03(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_03)]));
}
/*Context memdev config to SetGases_04*/
static void SetGases_SetTMT_04(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_04)]));
}
/*Context memdev config to SetGases_05*/
static void SetGases_SetTMT_05(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_05)]));
}
/*Context memdev config to SetGases_06*/
static void SetGases_SetTMT_06(char* pStrRet)
{
    sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(SetGASES_Index_06)]));
}
const contentDispContext_st Set_SetGases_SetTMT_01_Ctx =
{
    &SetGases_SetTMT_01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
const contentDispContext_st Set_SetGases_SetTMT_02_Ctx =
{
    &SetGases_SetTMT_02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
const contentDispContext_st Set_SetGases_SetTMT_03_Ctx =
{
    &SetGases_SetTMT_03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
const contentDispContext_st Set_SetGases_SetTMT_04_Ctx =
{
    &SetGases_SetTMT_04,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
const contentDispContext_st Set_SetGases_SetTMT_05_Ctx =
{
    &SetGases_SetTMT_05,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
const contentDispContext_st Set_SetGases_SetTMT_06_Ctx =
{
    &SetGases_SetTMT_06,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat,
};
/*TMT status -> Status update*/
/*SEARCHING*/
const contentDispContext_st SETGAS_TMT_SEARCHING_TXT =
{
    &Transmitters_TMT_SearchingTxtContent,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_SetGas_TMTLinkStatus_Center,
};
/*BATT GOOD*/
const contentDispContext_st SETGAS_TMT_BATTGOOD_TXT =
{
    &Transmitters_TMT_BattGood_TxtContent,
    &GREEN_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_SetGas_TMTLinkStatus_Right,
};
/*BATT LOW*/
const contentDispContext_st SETGAS_TMT_BATTLOW_TXT =
{
    &Transmitters_TMT_BattLow_TxtContent,
    &YELLOW_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_SetGas_TMTLinkStatus_Right,
};
/*NOT AVAILABLE*/
const contentDispContext_st SETGAS_TMT_NOTAVAILABE_TXT =
{
    &Transmitters_TMT_NotAvailable_TxtContent,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_SetGas_TMTLinkStatus_Center,
};
/*TANK PRESSURE*/
static void SETGAS_TMT_VALUE_TxtContent(char* pStrRet)
{
    float tankValue = 0.0f;
    if(UNITS==NVD_IMPERIAL)
    {
        tankValue = (float)GUI_TMT_PressPSI[SetGases_TMT_Num((TANK_NUM_t)(DSX_Opcode - S263_CHECKTMTLINKWITHGAS_01 + 1))];
    }
    else
    {
        tankValue = (float)CONST_PSI_TO_BAR * (float)GUI_TMT_PressPSI[SetGases_TMT_Num((TANK_NUM_t)(DSX_Opcode - S263_CHECKTMTLINKWITHGAS_01 + 1))];
    }
    sprintf(pStrRet, "%.0f %s  ", tankValue, TxtDef_Set_PressUnit[UNITS]);
}
const contentDispContext_st SETGAS_TMT_VALUE =
{
    &SETGAS_TMT_VALUE_TxtContent,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_3,
    &Pos_SetGas_TMTLinkStatus_Left,
};

void SetGas_TMTBatteryStatus(TMT_NUM_t n)
{
    /*TMT Battery status*/
    if(n != TMT_OFF)
    {
        switch(GUI_TMT_Battery[n])
        {
        case TMT_SEARCHING:
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SETGAS_TMT_SEARCHING_TXT);
            break;
        case TMT_BATT_LOW:
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SETGAS_TMT_VALUE);
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SETGAS_TMT_BATTLOW_TXT);
            break;
        case TMT_BATT_GOOD:
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SETGAS_TMT_VALUE);
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SETGAS_TMT_BATTGOOD_TXT);
            break;
        default:
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SETGAS_TMT_NOTAVAILABE_TXT);
            break;
        }
    }
}
