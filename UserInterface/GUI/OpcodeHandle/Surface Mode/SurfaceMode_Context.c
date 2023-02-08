#include "SurfaceMode_Context.h"
#include "SurfaceMode.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
#include "Receiver.h"
#include "../Menu/Set Gases/Menu_SetGases.h"
#include "../Menu/Dive Planner/Menu_DivePlanner_DataMap.h"

extern TANK_NUM_t GUI_TankN_Linked;
/*Battery information data*/
const battInfo_st pDataSurfBatt =
{
    /*battery percent from system*/
    &SystemSupplyMonitor.Battery_Percentage,
    /*cable charing from system*/
    BatteryCharging
};
/**/
GUI_COLOR SurfaceMode_SurfTime_TitleText_Color(void)
{
    ColorSel_t colorID = ColorSel_CYAN;
    /*Validate the input color from button handle*/
    if(TITLE_Color<(uint8_t)ColorTitle_MAX)
    {
        colorID = TITLE_Color;
    }
    else
    {
        /*No set*/
    }
    return Color_InfoTitleSetting[colorID];
}
GUI_COLOR SurfaceMode_isViolation_Text_Color(void)
{
    GUI_COLOR ColorRet = GUI_WHITE;
    /*Validate the input color from button handle*/
    if(AlarmStatusCheck_FullViolation())
    {
        ColorRet = GUI_RED;
    }
    else
    {
        /*keep White*/
    }
    return ColorRet;
}
GUI_COLOR SurfaceMode_SwitchP_Text_Color(void)
{
    if(Alarming2.Bit.SwitchP == true)
        return GUI_GREEN;
    else
        return TxtColor_Select;
}
GUI_COLOR SurfaceMode_PressAlarm_Color(void)
{
    GUI_COLOR retColor = TxtColor_Select;
    if((Alarming2.Bit.EndP == true)||((GUI_TMT_PressPSI[Current_TMT_Num()] <= TANKPRESS_LOWEST_PSI)&&((GUI_TMT_PressPSI[Current_TMT_Num()] > 0))))
    {
        retColor = GUI_RED;
    }
    else if(Alarming2.Bit.TurnP == true)
    {
        retColor = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return retColor;
}
GUI_COLOR Unselect_TxtColor(void)
{
    return TxtColor_UnSelect;
}
GUI_COLOR Select_TxtColor(void)
{
    return TxtColor_Select;
}
GUI_COLOR RED_TxtColor(void)
{
    return GUI_RED;
}
GUI_COLOR GREEN_TxtColor(void)
{
    return GUI_GREEN;
}
GUI_COLOR YELLOW_TxtColor(void)
{
    return GUI_YELLOW;
}
GUI_COLOR WHITE_TxtColor(void)
{
    return GUI_WHITE;
}
/* Get current PO2 value at surface mode; when Depth = 0
   PO2 at Depth = FO2 ( Depth + 33 )/33
*/
float GetCurrentPO2Value(void)
{
    float po2Val = 0.0f;

    if(CC_MODE)
        po2Val = 0.01f * TRIMIX_Set.CC_FO2[TRIMIX_Set.CurrGasNumber_CC] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(OC_MODE)
        po2Val = 0.01f * TRIMIX_Set.OC_FO2[TRIMIX_Set.CurrGasNumber_OC] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(SM_MODE)
        po2Val = 0.01f * TRIMIX_Set.SM_FO2[TRIMIX_Set.CurrGasNumber_SM] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(BO_MODE)
        po2Val = 0.01f * TRIMIX_Set.BO_FO2[TRIMIX_Set.CurrGasNumber_BO] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else
        po2Val = 0.0f;

    return po2Val;
}
/* Get current PO2 value at surface mode; when Depth = 0
   PO2 at Depth = FO2 ( Depth + 33 )/33
*/
float GetPO2ValueUponGasNum(uint8_t num)
{
    float po2Val = 0.0f;

    if(CC_MODE)
        po2Val = 0.01f * TRIMIX_Set.CC_FO2[num] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(OC_MODE)
        po2Val = 0.01f * TRIMIX_Set.OC_FO2[num] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(SM_MODE)
        po2Val = 0.01f * TRIMIX_Set.SM_FO2[num] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else if(BO_MODE)
        po2Val = 0.01f * TRIMIX_Set.BO_FO2[num] * (33.0f + Dive_Info.WaterDepth_ft)/33.0f;
    else
        po2Val = 0.0f;

    return po2Val;
}
void SurfaceMode_SurfTime_TitleText_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SURF_T));
}
void SurfaceMode_SurfTime_Hour_Context(char* pStrRet)
{
    if(SURFT_Hour<10U)
    {
        sprintf(pStrRet, "  %d", SURFT_Hour);
    }
    else
    {
        sprintf(pStrRet, "  %.2d", SURFT_Hour);
    }
}
void SurfaceMode_SurfTime_Min_Context(char* pStrRet)
{
    sprintf(pStrRet, "%.2d  ", SURFT_Min);
}
void SurfaceMode_SurfTime_Colon_Context(char* pStrRet)
{
    strcpy(pStrRet, " : ");
}
/*FLY*/
void SurfaceMode_FlyTittle_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_FLY));
}
void SurfaceMode_FlyTittle_Value(char* pStrRet)
{
    if(FLY_Hr<10U)
    {
        // sprintf(pStrRet, " %d:%.2d ", FLY_Hr, FLY_Min);         // 
        sprintf(pStrRet, " %d:%.2d ", (uint16_t)SystemStatus.BLE_status, (uint16_t)GnssStatus );         // 
    }
    else
    {
        // sprintf(pStrRet, " %d:%.2d ", FLY_Hr, FLY_Min);         // 
        sprintf(pStrRet, " %d:%.2d ", (uint16_t)SystemStatus.BLE_status, (uint16_t)GnssStatus );         // 
    }
}
/*Last Dive*/
void SurfaceMode_LastDive_Context(char* pStrRet)
{
    /*Violation*/
    if (AlarmStatusCheck_FullViolation())
    {
        /*Display violation text*/
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_VIOLATION));
    }
    /*Had Dive*/
    else if(CheckHadTheDiveYet())
    {
        /*Display Depth - Dive Time
        ˦ : FT
        ˥ : M
        ˧: MIN
        */
        if(UNITS == NVD_IMPERIAL)
        {
            sprintf(pStrRet, "   %.0f˦-%d:%.02d   ", ((float)0.1*Log_Data.MaxDepthFt10), Log_Data.EDTsec/3600, (Log_Data.EDTsec/60)%60);
        }
        else
        {
            sprintf(pStrRet, "   %.1f˥-%d:%.02d   ", (CONST_FT_TO_M*((float)0.1*Log_Data.MaxDepthFt10)), Log_Data.EDTsec/3600, (Log_Data.EDTsec/60)%60);
        }
    }
    /*No Dive Yet*/
    else
    {
        /*Last dive is empty: NO DIVE YET*/
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_DIVE_YET));
    }

}
void SurfaceMode_LastDive_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LAST_DIVE));
}
/*Runtime*/
void SurfaceMode_Runtime_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_RUNTIME));
}
void SurfaceMode_Runtime_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, "  %d:%.2d  ", Runtime.Run_S/60, Runtime.Run_S%60);
}
/*DESAT*/
void SurfaceMode_Desat_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DESAT));
}
void SurfaceMode_Desat_ValueContext(char* pStrRet)
{
    if(AlarmStatusCheck_FullViolation())
    {
        strcpy(pStrRet, "   -:--   ");
    }
    else if(DESAT_Hr<10U)
    {
        sprintf(pStrRet, " %d:%.2d ", DESAT_Hr, DESAT_Min);
    }
    else
    {
        sprintf(pStrRet, " %.2d:%.2d ", DESAT_Hr, DESAT_Min);
    }
}
/*PO2*/
void SurfaceMode_PO2_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PO2));
}
void SurfaceMode_PO2_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %1.2f ", (0.01*GasSwitchGetPO2A()));
}
/*Main Pressure*/
void SurfaceMode_Pressure_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, TxtDef_Set_PressUnit[UNITS]);
}
void SurfaceMode_TankPressure_Linked_ValueContext(char* pStrRet)
{
    if(GUI_TMT_PressPSI[Current_TMT_Num()]==0)
        strcpy(pStrRet, "  ---  ");
    else
    {
        if(UNITS==NVD_IMPERIAL)
        {
            sprintf(pStrRet, "  %d  ", GUI_TMT_PressPSI[Current_TMT_Num()]);
        }
        else
        {
            sprintf(pStrRet, "  %.0f  ", (float)CONST_PSI_TO_BAR * (float)GUI_TMT_PressPSI[Current_TMT_Num()]);
        }
    }
}
void SurfaceMode_TankPressure_OffLink_ValueContext(char* pStrRet)
{
    strcpy(pStrRet, "  ---  ");
}

/*TMT number*/
void SurfaceMode_TMT_ValueContext(char* pStrRet)
{
    const uint8_t tmtData = GSM_MODE ? CURRENT_TMT_NUM_GSM : CURRENT_TMT_NUM_GAUGE;
    sprintf(pStrRet, "TMT-%d", tmtData);
}
/*Time*/
void SurfaceMode_Time_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME));
}
void SurfaceMode_TimeValue_Context(char* pStrRet)
{
    if(NVD_24HR==SWITCH_HR24_Format) /*check the user set*/
    {
        sprintf(pStrRet, " %d:%.2d ", TIME_Hour, TIME_Min);
    }
    else
    {
        unsigned char hour12H = TIME_Hour;
        if(TIME_Hour>12)
        {
            hour12H = TIME_Hour - 12;
            sprintf(pStrRet, " %d:%.2d˫ ", hour12H, TIME_Min); /*Hour:Min PM*/
        }
        else
        {
            /*Keep value*/
            sprintf(pStrRet, " %d:%.2d˪ ", hour12H, TIME_Min); /*Hour:Min AM*/
        }
    }
}
/*O2 SAT*/
void SurfaceMode_O2Sat_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_O2_SAT));
}
void SurfaceMode_O2Sat_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %dˤ ", OTUpercent); //ˤ:%
}
/*OC LEFT*/
static const char* TxtDef_SetTMT_LeftName[TMTName_Max]=
{
    "OC-L",
    "TMT-L",
};
void SurfaceMode_OCLeft_TittleContext(char* pStrRet)
{
    uint8_t tmtDiveName = TMTName_OC;
    if(GSM_MODE)
    {
        tmtDiveName = TMTName_TMT; /*when GSM display "TMT"*/
    }
    else
    {
        /*keep init value */
    }
    sprintf(pStrRet, "  %s %s  ", TxtDef_SetTMT_LeftName[tmtDiveName], TxtDef_Set_PressUnit[UNITS]);
}
void SurfaceMode_OCLeft_ValueContext(char* pStrRet)
{
    uint16_t pressTMT_u16 = 0U;
    if(UNITS==NVD_IMPERIAL)
    {
        if(SM_MODE)
            pressTMT_u16 = GUI_TMT_PressPSI[TRIMIX_Set.SM_GASTMT[1]];
        else if(GSM_MODE)
            pressTMT_u16 = GUI_TMT_PressPSI[1];
    }
    else
    {
        if(SM_MODE)
            pressTMT_u16 = (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[TRIMIX_Set.SM_GASTMT[1]]);
        else if(GSM_MODE)
            pressTMT_u16 = (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[1]);
    }
    sprintf(pStrRet, " %d ", pressTMT_u16);
}
/*OC RIGHT*/
static const char* TxtDef_SetTMT_RightName[TMTName_Max]=
{
    "OC-R",
    "TMT-R",
};
void SurfaceMode_OCRight_TittleContext(char* pStrRet)
{
    uint8_t tmtDiveName = TMTName_OC;
    if(GSM_MODE)
    {
        tmtDiveName = TMTName_TMT; /*when GSM display "TMT"*/
    }
    else
    {
        /*keep init value */
    }
    sprintf(pStrRet, "%s %s", TxtDef_SetTMT_RightName[tmtDiveName], TxtDef_Set_PressUnit[UNITS]);
}
void SurfaceMode_OCRight_ValueContext(char* pStrRet)
{
    uint16_t pressTMT_u16 = 0U;
    if(UNITS==NVD_IMPERIAL)
    {
        if(SM_MODE)
            pressTMT_u16 = GUI_TMT_PressPSI[TRIMIX_Set.SM_GASTMT[2]];
        else if(GSM_MODE)
            pressTMT_u16 = GUI_TMT_PressPSI[2];
    }
    else
    {
        if(SM_MODE)
            pressTMT_u16 = (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[TRIMIX_Set.SM_GASTMT[2]]);
        else if(GSM_MODE)
            pressTMT_u16 = (uint16_t)(CONST_PSI_TO_BAR*GUI_TMT_PressPSI[2]);
    }
    sprintf(pStrRet, " %d ", pressTMT_u16);
}
/*Content OC status*/
void SurfaceMode_OCLeftStatus_ValueContext(char* pStrRet)
{
    if(TRIMIX_Set.CurrGasNumber_SM==1)
    {
        //sprintf(pStrRet, "OC-L %d/%.2d", TRIMIX_Set.SM_FO2[1], TRIMIX_Set.SM_FHe[1]);
        sprintf(pStrRet, "%s %d/%.2d", GUI_LANG_GetText(TxtStr_OC_L),TRIMIX_Set.SM_FO2[1], TRIMIX_Set.SM_FHe[1]);
    }
    else if(TRIMIX_Set.CurrGasNumber_SM==2)
    {
        //sprintf(pStrRet, "OC-R %d/%.2d", TRIMIX_Set.SM_FO2[2], TRIMIX_Set.SM_FHe[2]);
        sprintf(pStrRet, "%s %d/%.2d", GUI_LANG_GetText(TxtStr_OC_R),TRIMIX_Set.SM_FO2[2], TRIMIX_Set.SM_FHe[2]);

    }
    else
    {
        strcpy(pStrRet,  "  ");
    }
}
void SurfaceMode_OCLeftStatusViolation_ValueContext(char* pStrRet)
{
    if(TRIMIX_Set.CurrGasNumber_SM==1)
    {
        //strcpy(pStrRet, "OC-L");
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OC_L));
    }
    else if(TRIMIX_Set.CurrGasNumber_SM==2)
    {
        //strcpy(pStrRet, "OC-R");
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OC_L));

    }
    else
    {
        strcpy(pStrRet,  "  ");
    }
}
/*Fi O2*/
void SurfaceMode_FiO2_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_FIO2));
}
void SurfaceMode_FiO2_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %dˤ ", FiO2);
}
/*Dil PO2*/
void SurfaceMode_DilPO2_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIL_PO2));
}
void SurfaceMode_DilPO2_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %.2f ", Dil_PO2);
}
/*Temperature*/
void SurfaceMode_Temperature_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TEMPERATURE));
}
void SurfaceMode_Temperature_ValueContext(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "  %d˨  ", (int16_t)TemperatureF);
    else
        sprintf(pStrRet, "  %d˩  ", (int16_t)TemperatureC);
}
/*Main GF*/
void SurfaceMode_MainGF_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GF));
}
/*Elev*/
void SurfaceMode_Elev_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ELEV));
}
void SurfaceMode_Elev_ValueContext(char* pStrRet)
{
    if(ELEVATION==0)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SEA));
    else
        sprintf(pStrRet, " %d ", (uint8_t)ELEVATION);
}
/*Press at activation*/
void SurfaceMode_PressActivation_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PRESS_AT_ACTIVE));
}
void SurfaceMode_PressActivation_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %d", GUI_Activation_mBAR);
}
void SurfaceMode_PressActivation_UnitContext(char* pStrRet)
{
    strcpy(pStrRet, TxtDef_Set_PressActiveUnit[NVD_METRIC]);
}
/*Current Press*/
void SurfaceMode_CurrentPress_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CURRENT_PRESS));
}
void SurfaceMode_CurrentPress_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, " %d", (uint16_t)CURRENT_PRESSURE_MBAR);
}
/*Ceiling*/
void SurfaceMode_Ceiling_ValueContext(char* pStrRet)
{
    if(Dive_Info.Status!=AMB_DIVEINFO_DIVE)
    {
        /* New day, or > 10 mins after dive, and others*/
        strcpy(pStrRet, " -- ");
    }
    else
    {
        /*Within 10 mins after dive, or during dive*/
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "%d%s", DecoStop[1], TxtDef_Set_LowerDepthUnit[UNITS]);
        else
            sprintf(pStrRet, "%.1f%s", CONST_FT_TO_M * (float)DecoStop[1], TxtDef_Set_LowerDepthUnit[UNITS]);
    }
}
/*Max depth*/
void SurfaceMode_MaxDepth_ValueContext(char* pStrRet)
{
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
    {
        /*Within 10 mins after dive, or during dive*/
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "%.0f%s", fMaxDepthFt, TxtDef_Set_LowerDepthUnit[UNITS]);
        else
            sprintf(pStrRet, "%.1f%s", CONST_FT_TO_M * fMaxDepthFt, TxtDef_Set_LowerDepthUnit[UNITS]);
    }
    else
    {
        /* New day, or > 10 mins after dive, and others*/
        strcpy(pStrRet, "--");
    }
}
/*Average depth*/
void SurfaceMode_AvgDepth_ValueContext(char* pStrRet)
{
    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
    {
        /*Within 10 mins after dive, or during dive*/
        if(UNITS==NVD_IMPERIAL)
            sprintf(pStrRet, "%.0f%s", fAvgDepthFt, TxtDef_Set_LowerDepthUnit[UNITS]);
        else
            sprintf(pStrRet, "%.1f%s", CONST_FT_TO_M * fAvgDepthFt, TxtDef_Set_LowerDepthUnit[UNITS]);
    }
    else
    {
        /* New day, or > 10 mins after dive, and others*/
        strcpy(pStrRet, " -- ");
    }
}
/*Gauge GTR Title*/
void SurfaceMode_Gauge_GTR_TittleContext(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GTR));
}
/*Gauge GTR Value*/
void SurfaceMode_Gauge_GTR_ValueContext(char* pStrRet)
{
    sprintf(pStrRet, "  %d:%.2d ", (uint8_t)(Find_GTR()/60), (uint8_t)(Find_GTR()%60));
}

