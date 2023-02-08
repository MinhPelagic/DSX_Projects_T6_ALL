/******************************************************************************/
//File: TMT Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_TMTSwitch.h"
/*Go to set bottom content*/
static void TMTSwitch_Bottom_Context(char* pStrRet)
{
    char TMTNumStr[10];
    const unsigned char CurrentTMTHighlight = (HighLightTMTItem.TMTNumber + 1u);
    /*set TMT content base on TMT highlight number*/
    GetTextSetTMT(TMTNumStr, CurrentTMTHighlight);
    /*Validate the status*/
    const LOOSE_LINK_t TMTlinkingStatus = GUI_TMT_InLinking[CurrentTMTHighlight];
    /*Get TMT status*/
    if(LooseLink_OK == TMTlinkingStatus)
    {
        float TMTPressureVal_f = 0.0f;
        /**/
        if(UNITS == NVD_IMPERIAL)
        {
            TMTPressureVal_f = GUI_TMT_PressPSI[CurrentTMTHighlight];
        }
        else
        {
            TMTPressureVal_f = PSI_2_BAR(GUI_TMT_PressPSI[CurrentTMTHighlight]);
        }
        sprintf(pStrRet, "%s - %s: %.0f %s", TMTNumStr, GUI_LANG_GetText(TxtStr_PRESSURE), TMTPressureVal_f, TxtDef_Set_PressUnit[UNITS]);
    }
    else if(LooseLink_LOOSE == TMTlinkingStatus)
    {
        sprintf(pStrRet, "%s %s", GUI_LANG_GetText(TxtStr_SEARCHING_FOR_TMT), TMTNumStr);
    }
    else
    {
        const char *Txt_TMTLR[3] = {"N/A", "TMT-L", "TMT-R"};
        if ((SM_MODE || GSM_MODE) && ((CurrentTMTHighlight == 1U) || (CurrentTMTHighlight == 2U)))
        {
            sprintf(pStrRet, "%s %s", Txt_TMTLR[CurrentTMTHighlight], GUI_LANG_GetText(TxtStr_NOT_AVAILABLE));
        }
        else
        {
            sprintf(pStrRet, "TMT-%d %s", CurrentTMTHighlight, GUI_LANG_GetText(TxtStr_NOT_AVAILABLE));
        }        
    }
}
/*Display status flashing/clear then display*/
ItemStatus_te TMTSwitch_DispStat(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*when searching TMT -> flashing item*/
    if(LooseLink_LOOSE == GUI_TMT_InLinking[HighLightTMTItem.TMTNumber + 1u])
    {
        statRet = IteStat_ClearThenFlashing;
    }
    else
    {
        /*do nothing*/
    }
    return statRet;
}
/**/
GUI_COLOR TMTSwitchColor(void)
{
    GUI_COLOR colorRet = TxtColor_UnSelect;
    /*Turn to Yellow if less than End Press Alarm*/
    if(0)
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
const contentWithStateHandle_st TMTSwitch_Bottom_Content =
{
    &TMTSwitch_DispStat,
    &TMTSwitch_Bottom_Context,
    &TMTSwitchColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DiveSett_Conservatism_Sport_BottomContent,
};
/*calculate maximum display*/
MainMenu_TMTDisplayList_st getTheListTMTDisplay(void)
{
    MainMenu_TMTDisplayList_st listTMTInfo = {0};
    /*count display*/
    unsigned char cntDisp   = 0u;
    unsigned char TMTnum_u8 = 0u;
    
    if(GSM_MODE)
        GUI_ShowTankNum = TRIMIX_Set.CurrTMT_Number_GSM;
    else if(GAUGE_MODE)
        GUI_ShowTankNum = TRIMIX_Set.CurrTMT_Number_GAUGE;
    
    /*scan all the possible TMT*/
    for (unsigned char cnt_u8 = MM_TMT_L; cnt_u8 < MM_TMT_MAX; cnt_u8++)
    {
        /*set TMT N*/
        TMTnum_u8 = (cnt_u8 + 1);
        /*
        Check all the TMTs is ON or current tank is selected
        */
        if((NVD_OFF == GUI_TMT_Status[TMTnum_u8])||(GUI_ShowTankNum == TMTnum_u8))
        {
            /*do nothing*/
        }
        else
        {
            /*set the max item in list*/
            listTMTInfo.maxTMT++;
            /*set the TMT number*/
            listTMTInfo.TMTList[cntDisp].TMTNumber = cnt_u8;
            /*set position display*/
            listTMTInfo.TMTList[cntDisp].posDisplay = cntDisp;
            /*set next cnt display*/
            cntDisp++;
        }
    }
    return listTMTInfo;
}
