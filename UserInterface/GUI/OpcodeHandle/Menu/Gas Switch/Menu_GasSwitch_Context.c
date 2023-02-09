/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGasSwitchCfg.h"
#include "Menu_GasSwitch.h"
#include "../Set Gases/Menu_SetGases.h"
/*Gas num ID from 1,2,3,4,5,6*/
uint16_t GasSwitchGetPO2A(void)
{
    /*Set gas only in CC, OC, SM mode only*/
    uint16_t retValue = 0;

    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        if(CC_MODE)
        {
            if((AUTO_HIGH_SP_STAT == true)||(AUTO_LOW_SP_STAT == true))
                retValue = (uint16_t)round(100.0 * ccSPcurrent);
            else
                retValue = (uint16_t)SP_CURRENT_Val;
        }
        else if(OC_MODE || SM_MODE || BO_MODE)
        {
            if(PO2atDepth == 0.0)
                PO2atDepth = 0.21;      // if PO2atDepth not initialized, initialize it here as a bandage (normally occuring at the very first dive after power cycle only)

            retValue = (uint16_t)round(100.0 * PO2atDepth);
        }
    }
    else
    {
        if(CC_MODE)
        {
            if((AUTO_HIGH_SP_STAT == true)||(AUTO_LOW_SP_STAT == true))
                retValue = (uint16_t)round(100.0 * ccSPcurrent);
            else
                retValue = (uint16_t)SP_CURRENT_Val;
        }
        else if(OC_MODE)
            retValue = (uint16_t)TRIMIX_Set.OC_FO2[TRIMIX_Set.CurrGasNumber_OC];
        else if(SM_MODE)
            retValue = (uint16_t)TRIMIX_Set.SM_FO2[TRIMIX_Set.CurrGasNumber_SM];
        else if(BO_MODE)
            retValue = (uint16_t)TRIMIX_Set.BO_FO2[TRIMIX_Set.CurrGasNumber_BO];
    }

    return retValue;
};
/*Handle PO2 content*/
void GasSwitchPO2Str(char* pStrHandle, unsigned char gasNum)
{
    float PO2GetValue = 0.0f;
    /*PO2 value*/
    PO2GetValue = 0.01f * (float)GasSwitchFindPO2A(gasNum);
    /*Content*/
    sprintf(pStrHandle,"%s: %.2f", GUI_LANG_GetText(TxtStr_PO2), PO2GetValue);
}
static uint16_t GasSwitchFindPO2A(uint8_t gasNum)
{
    /*Set gas only in CC, OC, SM, BO mode only*/
    uint16_t retValue = 0u;

    if((Dive_Info.Status == AMB_DIVEINFO_DIVE)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
    {
        if(CC_MODE)
            retValue = (uint16_t)(((Pamb + fDepthFt * SaltEqDensityFactor()) * (float)TRIMIX_Set.CC_FO2[gasNum]) / 33.0f);
        else if(OC_MODE)
            retValue = (uint16_t)(((Pamb + fDepthFt * SaltEqDensityFactor()) * (float)TRIMIX_Set.OC_FO2[gasNum]) / 33.0f);
        else if(SM_MODE)
            retValue = (uint16_t)(((Pamb + fDepthFt * SaltEqDensityFactor()) * (float)TRIMIX_Set.SM_FO2[gasNum]) / 33.0f);
        else if(BO_MODE)
            retValue = (uint16_t)(((Pamb + fDepthFt * SaltEqDensityFactor()) * (float)TRIMIX_Set.BO_FO2[gasNum]) / 33.0f);
    }
    else
    {
        if(CC_MODE)
            retValue = (uint16_t)(Pamb * TRIMIX_Set.CC_FO2[gasNum] / 33.0f);
        else if(OC_MODE)
            retValue = (uint16_t)(Pamb * TRIMIX_Set.OC_FO2[gasNum] / 33.0f);
        else if(SM_MODE)
            retValue = (uint16_t)(Pamb * TRIMIX_Set.SM_FO2[gasNum] / 33.0f);
        else if(BO_MODE)
            retValue = (uint16_t)(Pamb * TRIMIX_Set.BO_FO2[gasNum] / 33.0f);
    }

    return retValue;
};
/*PO2 color*/
GUI_COLOR GasSwitch_ColorDispRight(unsigned char gasNum)
{
    GUI_COLOR retColor = GUI_YELLOW;
    /*Get the PO2 value*/
    const uint16_t PO2Value = GasSwitchFindPO2A(gasNum);
    uint16_t MaxLimit, MinLimit, DecoLimit;
    if(CC_MODE)
    {
        MaxLimit = 105;
        MinLimit = 17;
        DecoLimit = SCUBA_Set.BOdeco;
    }
    else if (BO_MODE)
    {
        MaxLimit = SCUBA_Set.BOmax;
        MinLimit = SCUBA_Set.BOmin;
        DecoLimit = SCUBA_Set.BOdeco;
    }
    else
    {
        MaxLimit = SCUBA_Set.OCmax;
        MinLimit = SCUBA_Set.OCmin;
        DecoLimit = SCUBA_Set.OCdeco;
    }
    /*Base on the value of GAS -> Set the color*/
    if(DecoStatus)
    {
        if((PO2Value > DecoLimit)||((PO2Value>=MinLimit)&&(PO2Value<=20U)))
        {
            retColor = GUI_YELLOW;
        }
        else if(PO2Value < MinLimit)
        {
            retColor = GUI_RED;
        }
        else
        {
            retColor = GUI_CYAN;
        }
    }
    else
    {
        if((PO2Value > MaxLimit)||((PO2Value>=MinLimit)&&(PO2Value<=20U)))
        {
            retColor = GUI_YELLOW;
        }
        else if(PO2Value < MinLimit)
        {
            retColor = GUI_RED;
        }
        else
        {
            retColor = GUI_CYAN;
        }
    }
    return retColor;
}
/**/
void GasSwitch_Bottom_MOD_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
    {
        sprintf(pStrRet, "MOD: %.0f FT", Find_GUI_MOD());
    }
    else
    {
        sprintf(pStrRet, "MOD: %.1f M", CONST_FT_TO_M*Find_GUI_MOD());
    }
}
/**/
void GasSwitch_Bottom_CannotSwitchLine0_Context(char* pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_PO2_CANNOT_SW_1));
}
void GasSwitch_Bottom_CannotSwitchLine1_Context(char* pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_PO2_CANNOT_SW_2));
}
/**/
void GasSwitch_Bottom_PO2HigherThan_1p6_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WARNING_PO2_160));
}
/**/
void GasSwitch_Hypoxic_Bottom_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WARNING_HYPOXIC));
}
/**/
void GasSwitch_ICD_Bottom_Context(char* pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_ISOBARIC_COUNTER));
}
/**/
void Depth_In_Menu_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
    {
        sprintf(pStrRet, "   %.0f FT ", fDepthFt);
    }
    else
    {
        sprintf(pStrRet, "   %.1f M ", CONST_FT_TO_M*fDepthFt);
    }
}
void GasSwitchBottom_TMTLink_Context(char* pStrRet)
{
    if(CheckLooseLink_GAS(GUI_TankN_Linked)!=LooseLink_OFF)
    {
        float pressVal = 0.0f;
        if(UNITS==NVD_IMPERIAL)
        {
            pressVal = GUI_TMT_PressPSI[GUI_TMT_Num_InSetting];
        }
        else
        {
            pressVal = CONST_PSI_TO_BAR * GUI_TMT_PressPSI[GUI_TMT_Num_InSetting];
        }
        /*YS code sprintf(pStrRet, "TMT %d - %s %.0f %s", GUI_TMT_Num_InSetting, GUI_LANG_GetText(TxtStr_PRESSURE), pressVal, TxtDef_Set_PressUnit[UNITS]);*/

        sprintf(pStrRet, "%s %d - %s %.0f %s", GUI_LANG_GetText(TxtStr_TMT),GUI_TMT_Num_InSetting, GUI_LANG_GetText(TxtStr_PRESSURE), pressVal, TxtDef_Set_PressUnit[UNITS]);
    }
    else if(GUI_TMT_Num_InSetting!=TMT_OFF)
    {
        //sprintf(pStrRet, "SEARCHING FOR TMT %d", GUI_TMT_Num_InSetting);
        sprintf(pStrRet, GUI_LANG_GetText(TxtStr_SEARCHING_FOR_TMT));

    }
    else
    {
        strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_TMT_NOT_AVAILABLE));
    }
}
void GasSwitchBottom_GasOFF_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GAS));
    strcat(pStrRet, " ");
    strcat(pStrRet, GUI_LANG_GetText(TxtStr_OFF));
}
