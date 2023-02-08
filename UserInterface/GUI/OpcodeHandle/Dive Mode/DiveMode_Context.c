/**/
#include "DiveMode.h"
/*specific this to copy and internal handle*/
#define DEPTH_STRLEN 10

/*Set dot '.' character to zero '\0'*/
static void SetCharDotToZero(char* pString)
{
    unsigned char *charMarkPos_p; //address to mark postion
    /*Find the '.' character*/
    charMarkPos_p = memchr(pString, '.', strlen(pString));
    /*set content to 0*/
    *charMarkPos_p = '\0';
}
/*
Copy content of string from '.' to end
Get content from source string when found '.' then copy content from that to destination
*/
static void CopyContentFromDotChar(char* destString, char* srcString)
{
    char *charMarkPos_p;
    /*set the destination buffer*/
    charMarkPos_p = memchr(srcString, '.', DEPTH_STRLEN);
    strcpy(destString, charMarkPos_p);
}
/*DEPTH*/
void DiveMode_DepthValueNormal_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "   %.0f˦   ", fDepthFt);
}
void DepthAndDiveTime_DepthValueNormal_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "   %.0fˢ   ", fDepthFt);
}
void DiveMode_DepthValue_MetricDecimal_Context(char* pStrRet)
{
    /*handle depth value string*/
    sprintf(pStrRet, "  %.1f", fDepthM);
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_DepthValueNormal_MetricFloat_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    /*handle depth value string*/
    sprintf(strDepthMetric, "%.1f˥ ", fDepthM);
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
/*DIVE TIME*/
void DiveMode_DiveTime_Context(char* pStrRet)
{
    sprintf(pStrRet, " %d:%.2d ", u32DiveTimeHr, u32DiveTimeMin);
}
/*AVG DEPTH*/
void DiveMode_AvgDepth_TitleTxt_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AVG_D));
}
void DiveMode_AvgDepthValue_Context(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
    {
        sprintf(pStrRet, "  %.0f˦  ", fAvgDepthFt);
    }
    else
    {
        sprintf(pStrRet, "  %.1f˥  ", CONST_FT_TO_M * fAvgDepthFt);
    }
}
/*MAX DEPTH*/
void DiveMode_MaxDepth_TitleTxt_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MAX_D));
}
void DiveMode_MaxDepthValue_Context(char* pStrRet)
{
    if(Alarming.Bit.DepthMax ==  true)
        strcpy(pStrRet, "  ---  ");
    else
    {
        if(UNITS == NVD_IMPERIAL)
        {
            sprintf(pStrRet, "  %.0f˦ ", fMaxDepthFt);
        }
        else
        {
            sprintf(pStrRet, "  %.1f˥  ", CONST_FT_TO_M * fMaxDepthFt);
        }
    }
}
/*GTR*/
void DiveMode_GTR_TitleTxt_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GTR));
}
void DiveMode_GTR_Value_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %d:%.2d  ", (uint8_t)(Find_GTR()/60), (uint8_t)(Find_GTR()%60));
}
void DiveMode_DashDash_Context(char* pStrRet)
{
    strcpy(pStrRet, "   -:--  ");
}
/*NO DECO*/
bool Check_NoDecoOrO2Time(void)
{
    /*condition to check No Deco or O2 Time*/
    return (NDT_Data <= otrTime);
}
void DiveMode_NoDecoOrO2TimeTittle_Context(char* pStrRet)
{
    if(Check_NoDecoOrO2Time())
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_DECO));
    }
    else
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2_TIME));
    }
}
void DiveMode_NoDecoOrO2TimeValue_Context(char* pStrRet)
{
    uint16_t DTR;
    if(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)
    {
        strcpy(pStrRet, "  -:--  ");
    }
    else
    {
        if(Check_NoDecoOrO2Time())
            DTR = NDT_Data;
        else
            DTR = otrTime;
        sprintf(pStrRet, "  %d:%.2d  ", (uint8_t)(DTR/60), (uint8_t)(DTR%60));
    }
}
/*TTS*/
void DiveMode_TTS_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TTS));
}
void DiveMode_TTS_Content_Context(char* pStrRet)
{
    /*In 10 mins on Surface or Max depth alarm display -:--*/
    if((Alarming.Bit.DepthMax == true)||(Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE))
    {
        strcpy(pStrRet, "  -:--  ");
    }
    else
    {
        sprintf(pStrRet, " %d:%.2d ", (uint8_t)TAT_Data/60, (uint8_t)TAT_Data%60);   // Total Ascend Time (TAT) =  Time To Surface (TTS)
    }
}
/*PO2*/
void DiveMode_PO2_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PO2));
}
void DiveMode_PO2_Value_Context(char* pStrRet)
{
    sprintf(pStrRet, " %1.2f ", 0.01*GasSwitchGetPO2A());
}
/*Max Depth in OC mode*/
void DiveMode_OC_MaxDepth_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MAX_D));
}
void DiveMode_OC_MaxDepth_Value_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f˦  ", fMaxDepthFt);
}
void DiveMode_OC_MaxDepthValue_MetricDecimal_Context(char* pStrRet)
{
    /*handle depth value string*/
    sprintf(pStrRet, " %.1f", fMaxDepthM);
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_MaxDepthValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    /*handle depth value string*/
    sprintf(strDepthMetric, "%.1f˥ ", fMaxDepthM);
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
void DiveMode_OC_MaxDepthDash_Context(char* pStrRet)
{
    strcpy(pStrRet, "---");
}
/*Avg Depth in OC mode*/
void DiveMode_OC_AvgDepth_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AVG_D));
}
void DiveMode_OC_AvgDepthValue_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f˦  ", fAvgDepthFt);
}
void DiveMode_OC_AvgDepthValue_MetricDecimal_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.1f", fAvgDepthM);
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_AvgDepthValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    sprintf(strDepthMetric, "%.1f˥ ", fAvgDepthM);
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
void DiveMode_OC_AvgDepthDash_Context(char* pStrRet)
{
    strcpy(pStrRet, "  ---  ");
}
/*Ceiling in OC mode*/
void DiveMode_OC_Ceiling_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CEILING));
}
void DiveMode_OC_CeilingValue_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %d˦  ", DecoStop[1]);
}
void DiveMode_OC_CeilingValue_MetricDecimal_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.1f", (float)DecoStop[1]*(float)CONST_FT_TO_M);
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_CeilingValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    sprintf(strDepthMetric, "%.1f˥ ", (float)DecoStop[1]*(float)CONST_FT_TO_M);
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
/*END*/
void DiveMode_OC_ENDDepth_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_END));
}
void DiveMode_OC_ENDDepthValue_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f˦  ", OC_END_AtDepthFT);
}
void DiveMode_OC_ENDDepthValue_MetricDecimal_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.1f", (OC_END_AtDepthFT * CONST_FT_TO_M));
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_ENDDepthValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    sprintf(strDepthMetric, "%.1f˥ ", (OC_END_AtDepthFT * CONST_FT_TO_M));
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
/*WOB*/
void DiveMode_OC_WOBDepth_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WOB));
}
void DiveMode_OC_WOBDepthValue_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f˦  ", OC_WOB_depthFT);
}
void DiveMode_OC_WOBDepthValue_MetricDecimal_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.1f", (OC_WOB_depthFT * CONST_FT_TO_M));
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_WOBDepthValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    sprintf(strDepthMetric, "%.1f˥ ", (OC_WOB_depthFT * CONST_FT_TO_M));
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
/*MOD*/
void DiveMode_OC_MODDepth_Tittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MOD));
}
void DiveMode_OC_MODDepthValue_Imperial_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.0f˦  ", FindMOD());
}
void DiveMode_OC_MODDepthValue_MetricDecimal_Context(char* pStrRet)
{
    sprintf(pStrRet, "  %.1f", (FindMOD() * CONST_FT_TO_M));
    /*set the destination buffer*/
    SetCharDotToZero(pStrRet);
}
void DiveMode_OC_MODDepthValue_MetricFloating_Context(char* pStrRet)
{
    char strDepthMetric[DEPTH_STRLEN];
    sprintf(strDepthMetric, "%.1f˥ ", (FindMOD() * CONST_FT_TO_M));
    /*set the destination buffer*/
    CopyContentFromDotChar(pStrRet, strDepthMetric);
}
/*DECO STOP*/
void DiveMode_DecoStop_DepthAndTime_Context(char* pStrRet)
{
    float decoDepth = 0.0f;
    if(UNITS==NVD_IMPERIAL)
    {
        decoDepth = DECOSTOP_Depth;
    }
    else
    {
        decoDepth = (float)DECOSTOP_Depth*CONST_FT_TO_M;
    }
    /*˧ : MIN*/
    sprintf(pStrRet, "%.0f%s-%d˧", decoDepth, TxtDef_Set_LowerDepthUnit[UNITS], DECOSTOP_Min);
}
void ExtraDepthDiveTime_DecoStop_DepthAndTime_Context(char* pStrRet)
{
    float decoDepth = 0.0f;
    if(UNITS==NVD_IMPERIAL)
    {
        decoDepth = DECOSTOP_Depth;
    }
    else
    {
        decoDepth = (float)DECOSTOP_Depth*CONST_FT_TO_M;
    }
    /* ˣ : MIN*/
    sprintf(pStrRet, "%.0f%s-%dˣ", decoDepth, TxtDef_Set_ExLDepthTimeLowerDepthUnit[UNITS], DECOSTOP_Min);
}
void DiveMode_DecoStop_Minute_Text_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MIN));
}
/*DEEP STOP*/
void DiveMode_DeepOrSSStopTittle_Context(char* pStrRet)
{
    if(isSSorDS)
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DEEP_STOP));
    }
    else
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAFETY_STOP));
    }
}
void DiveMode_DeepOrSSStop_DepthAndTime_Context(char* pStrRet)
{
    float deepOrSSStopDepth = 0.0f;
    if(isSSorDS)
    {
        if(UNITS==NVD_IMPERIAL)
        {
            deepOrSSStopDepth = fMaxDepthFt;
        }
        else
        {
            deepOrSSStopDepth = fMaxDepthM;
        }
        sprintf(pStrRet, "   %.0f%s-%d:%.2d   ", 0.5f*deepOrSSStopDepth, TxtDef_Set_LowerDepthUnit[UNITS], (DS_Counter/60), (DS_Counter%60));
    }
    else
    {
        if(UNITS==NVD_IMPERIAL)
        {
            deepOrSSStopDepth = SAFETYSTOP_DEPTH_FT;
        }
        else
        {
            deepOrSSStopDepth = SAFETYSTOP_DEPTH_M;
        }
        sprintf(pStrRet, "   %.0f%s-%d:%.2d   ", deepOrSSStopDepth, TxtDef_Set_LowerDepthUnit[UNITS], (SS_Counter/60), (SS_Counter%60));
    }
}
void DepthDiveTimeMode_DeepOrSSStop_DepthAndTime_Context(char* pStrRet)
{
    float deepOrSSStopDepth = 0.0f;
    if(isSSorDS)
    {
        if(UNITS==NVD_IMPERIAL)
        {
            deepOrSSStopDepth = fMaxDepthFt;
        }
        else
        {
            deepOrSSStopDepth = fMaxDepthM;
        }
        sprintf(pStrRet, "   %.0f%s-%d:%.2d   ", 0.5f*deepOrSSStopDepth, TxtDef_Set_ExLDepthTimeLowerDepthUnit[UNITS], (DS_Counter/60), (DS_Counter%60));
    }
    else
    {
        if(UNITS==NVD_IMPERIAL)
        {
            deepOrSSStopDepth = SAFETYSTOP_DEPTH_FT;
        }
        else
        {
            deepOrSSStopDepth = SAFETYSTOP_DEPTH_M;
        }
        sprintf(pStrRet, "   %.0f%s-%d:%.2d   ", deepOrSSStopDepth, TxtDef_Set_ExLDepthTimeLowerDepthUnit[UNITS], (SS_Counter/60), (SS_Counter%60));
    }
}
void ALARM_GasSwitch_Context(char* pStrRet)        // added by YS 2021/12/15
{
    sprintf(pStrRet, "    %s %.02d/%.02d    ", GUI_LANG_GetText(TxtStr_SWITCH_TO), DecoFO2[1], DecoFHe[1]);
}
void DiveMode_VGM_DepthDashesContext(char* pStrRet)
{
    sprintf(pStrRet, "   ---%s   ", TxtDef_Set_LowerDepthUnit[UNITS]);
}
void DepthAndDiveTime_DepthDashesContext(char* pStrRet)
{
    sprintf(pStrRet, "   ---%s   ", TxtDef_Set_ExLDepthTimeLowerDepthUnit[UNITS]);
}
