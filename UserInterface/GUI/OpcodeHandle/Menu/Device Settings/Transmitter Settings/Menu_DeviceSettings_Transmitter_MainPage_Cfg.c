
#include "L4X9_includes.h"
#include "../ContextDeviceSettingsCfg.h"
#include "../Menu_DeviceSettings.h"
#include "Menu_DeviceSettings_Transmitter_Cfg.h"

static void Ret_TMT_SN(char* SN_buff, char* pStrRet)
{
    sprintf(pStrRet, "  %d%d%d%d%d%d  ", SN_buff[setDigit_1], SN_buff[setDigit_2], SN_buff[setDigit_3], SN_buff[setDigit_4], SN_buff[setDigit_5], SN_buff[setDigit_6]);
}
/*SET SERIALS*/
static void Transmitters_TMT_SERIAL_TXT(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_SERIAL));

}
const contentDispContext_st Transmitters_TMT_SERIAL_Text =
{
    &Transmitters_TMT_SERIAL_TXT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeTxt,
};
static void Transmitters_TMT_SET_SERIAL_TXT(char* pStrRet)/*Passcode text*/
{
    strcpy(pStrRet,GUI_LANG_GetText(TxtStr_TMT_SET_SERIAL));
}
const contentDispContext_st Transmitters_TMT_SETSERIAL_Text =
{
    &Transmitters_TMT_SET_SERIAL_TXT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeTxt,
};
/*SEARCHING*/
void Transmitters_TMT_SearchingTxtContent(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SEARCHING));
}
const contentDispContext_st Transmitters_TMT_SEARCHING_TXT =
{
    &Transmitters_TMT_SearchingTxtContent,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Status,
};
/*BATT GOOD*/
void Transmitters_TMT_BattGood_TxtContent(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BATT_GOOD));
}
const contentDispContext_st Transmitters_TMT_BATTGOOD_TXT =
{
    &Transmitters_TMT_BattGood_TxtContent,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Status,
};
/*BATT LOW*/
void Transmitters_TMT_BattLow_TxtContent(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BATT_LOW));
}
const contentDispContext_st Transmitters_TMT_BATTLOW_TXT =
{
    &Transmitters_TMT_BattLow_TxtContent,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Status,
};
/*NOT AVAILABLE*/
void Transmitters_TMT_NotAvailable_TxtContent(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NOT_AVAILABLE));
}
const contentDispContext_st Transmitters_TMT_NOTAVAILABE_TXT =
{
    &Transmitters_TMT_NotAvailable_TxtContent,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Status,
};
/*String define*/
const char* TMT_1_Txt = "TMT 1";
const char* TMT_L_Txt = "TMT L";
const char* TMT_2_Txt = "TMT 2";
const char* TMT_R_Txt = "TMT R";
/*get the string TMT base on dive mode*/
const char* GetTextTransmitter_1_L(void)
{
    const char* retdata;
    if(SM_MODE||GSM_MODE)
    {
        retdata = TMT_L_Txt;
    }
    else
    {
        retdata = TMT_1_Txt;
    }
    return retdata;
}
const char* GetTextTransmitter_2_R(void)
{
    const char* retdata;
    if(SM_MODE||GSM_MODE)
    {
        retdata = TMT_R_Txt;
    }
    else
    {
        retdata = TMT_2_Txt;
    }
    return retdata;
}
/*TMT 1*/
void Transmitters_TMT_1_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "%s        %s", GetTextTransmitter_1_L(), GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_1]]));
}
void Transmitters_TMT_1_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_1]]));
}
static void Transmitters_TMT_1_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_1], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_1_PassCodeNumber =
{
    &Transmitters_TMT_1_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_1_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_1_Pressure =
{
    &Transmitters_TMT_1_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
/*TMT 2*/
void Transmitters_TMT_2_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "%s        %s", GetTextTransmitter_2_R(),  GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_2]]));
}
void Transmitters_TMT_2_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_2]]));
}
static void Transmitters_TMT_2_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_2], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_2_PassCodeNumber =
{
    &Transmitters_TMT_2_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_2_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_2_Pressure =
{
    &Transmitters_TMT_2_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
/*TMT 3*/
void Transmitters_TMT_3_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "TMT 3        %s", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_3]]));
}
void Transmitters_TMT_3_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_3]]));
}
static void Transmitters_TMT_3_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_3], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_3_PassCodeNumber =
{
    &Transmitters_TMT_3_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_3_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)((CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting])));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_3_Pressure =
{
    &Transmitters_TMT_3_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
/*TMT 4*/
void Transmitters_TMT_4_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "TMT 4        %s", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_4]]));
}
void Transmitters_TMT_4_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_4]]));
}
static void Transmitters_TMT_4_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_4], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_4_PassCodeNumber =
{
    &Transmitters_TMT_4_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_4_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)((CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting])));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_4_Pressure =
{
    &Transmitters_TMT_4_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
/*TMT 5*/
void Transmitters_TMT_5_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "TMT 5        %s", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_5]]));
}
void Transmitters_TMT_5_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_5]]));
}
static void Transmitters_TMT_5_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_5], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_5_PassCodeNumber =
{
    &Transmitters_TMT_5_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_5_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_5_Pressure =
{
    &Transmitters_TMT_5_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
/*TMT 6*/
void Transmitters_TMT_6_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "TMT 6        %s", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_6]]));
}
void Transmitters_TMT_6_Context_Center(char* pStrRet)
{
    sprintf(pStrRet, " %s ", GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_TMT_Status[TMT_6]]));
}
static void Transmitters_TMT_6_Context_PasscodeNumber(char* pStrRet)
{
    char pTMTSNRet[LangMaxLength];
    Ret_TMT_SN((char*)GUI_TMT_SerialNum[TMT_6], pTMTSNRet);
    strcpy(pStrRet, pTMTSNRet);
}
const contentDispContext_st Transmitters_TMT_6_PassCodeNumber =
{
    &Transmitters_TMT_6_Context_PasscodeNumber,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_PasscodeNumber,
};
static void Transmitters_TMT_6_Pressure_Content(char* pStrRet) //Status
{
    if((GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_OK)||(GUI_TMT_InLinking[GUI_TMT_Num_InSetting]==LooseLink_LOOSE))
    {
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "  %d PSI  ", GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]);
        else
            sprintf(pStrRet, "  %d BAR  ", (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[GUI_TMT_Num_InSetting]));
    }
    else
        strcpy(pStrRet, "            ");
}
const contentDispContext_st Transmitters_TMT_6_Pressure =
{
    &Transmitters_TMT_6_Pressure_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DeviceSett_Transmitt_TMT_Pressure,
};
