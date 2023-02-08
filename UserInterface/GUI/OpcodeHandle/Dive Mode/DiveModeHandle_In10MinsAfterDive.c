#include "L4X9_includes.h"
#include "DiveMode.h"

const contentDispContext_st DiveMode_NoDecoIn10Mins =
{
    &DiveMode_DashDash_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Dive_NoDeco_Value,
};
/*
NOTE: Devide handle display in horizontal
In 10 mins after Dive -> Display Deco stop or Violation CC/OC/SM/
*/
void DiveModeHandle_10Mins_DispDecoSSStopOrViolation(void)
{
    /*When no alarms occurs -> Display DECO STOP, TTS
    -> Note: Violation display already overlap Deep,SSStop and TTS already*/
    if(AlarmStatusCheck_FullViolation())
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, ALARM_FullViolation);
    }
    else
    {
        /*No-Deco, Deco-Stop, Deep-Stop, Safety-Stop, O2-Stop*/
        SurfaceHandle_Deco_NoDeco_DeepStop_SafetyStop();
        /*TTS*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_TTS_Tittle);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_TTS_Content);
    }
}
/*
NOTE: Devide handle display in horizontal
In 10 mins after Dive -> Display Surface GAUGE/GAUGESM
*/
void DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive(void)
{
    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        /*Depth*/
        DiveModeHandle_Display_Depth(IteStat_Initial);
    }
    else
    {
        /*Surface Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_TitleText);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Hour);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Min);
        HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    }
}
/*
Extra large
|--> Display Depth
    |--> Display Dive Time
*/
void DiveModeHandle_CC_DispExtraDepthOrSurfTimeAfterDive(void)
{
    /*Under water to in 10 mins after dive*/
    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        /*Extra Depth*/
        DiveModeHandle_Display_ExtraDepth(IteStat_Initial);
        /*Deco/No - Deco on right*/
        DiveHandleExtrDepth_NoDecoDecoDeepOrSSStopAndViolation();
    }
    else
    {
        /*Surface Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_TitleText);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Hour);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Min);
        HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
        /*Full violation */
        if(AlarmStatusCheck_FullViolation())
        {
            ClearPortion_BelowSurfaceTime(); //Keep clear when switch from Deph -> Surface Time
        }
        else
        {
            SurfaceHandle_Deco_NoDeco_DeepStop_SafetyStop();
            /*TTS on right*/
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_TTS_Tittle);
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_TTS_Content);
        }
    }
}
/*Gauge and GSM mode*/
void DiveModeHandle_GSM_DispExtraDepthOrSurfTimeAfterDive(void)
{
    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        /*Extra Depth*/
        DiveModeHandle_Display_ExtraDepth(IteStat_Initial);
    }
    else
    {
        /*Surface Time*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_TitleText);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Hour);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_SurfTime_Min);
        HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
        /*AVG Depth*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_AvgDepth_TitleTxt);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveMode_AvgDepth_Value);
        /*#OverlapFix : clear portion after 10 mins after dive*/
        ClearPortion_GSM_PortionAVGvsMaxDepth();
    }
}
