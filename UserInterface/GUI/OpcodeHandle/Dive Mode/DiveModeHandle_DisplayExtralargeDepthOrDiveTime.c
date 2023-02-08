#include "L4X9_includes.h"
#include "DiveMode.h"

extern void DiveModeHandle_CC_DispExtraDepthOrSurfTimeAfterDive(void);
extern void DiveModeHandle_GSM_DispExtraDepthOrSurfTimeAfterDive(void);

/*When Violation -> Disable display extra large Depth and Dive Time*/
static uint8_t ValidateTheDisplayExtraDepthOrDiveTime(void)
{
    uint8_t mainDisplayStatus = Setting_ExtraLarge_OFF;
    if(AlarmStatusCheck_FullViolation() || AlarmStatusCheck_AlarmWarningLowBattShutDown())
    {
        /*Keep extra large Depth and Dive time to OFF when full Violation or Alarm/Warning Battery trigger*/
    }
    else
    {
        /*get from user settings*/
        mainDisplayStatus = GUI_MAINDISPLAY_EXTRA_LARGE;
    }
    return mainDisplayStatus;
}
/*Check display base one user set extra large Depth or Dive time*/
void DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime(void)
{
    switch(ValidateTheDisplayExtraDepthOrDiveTime())
    {
    case Setting_ExtraLarge_DEPTH:
        /*Depth or Surface Time*/
        DiveModeHandle_CC_DispExtraDepthOrSurfTimeAfterDive();
        /*Dive Time*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTime_Value);
        break;
    case Setting_ExtraLarge_DIVETIME:
        /*Depth or Surface Time*/
        DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive();
        /*No-Deco, Deco-Stop, Deep-Stop, Safety-Stop, O2-Stop*/
        SurfaceHandle_Deco_NoDeco_DeepStop_SafetyStop();
        /*Dive Time extra*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTimeExtra_Value);
        break;
    default:
        /*Depth or Surface Time*/
        DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive();
        /**/
        DiveModeHandle_10Mins_DispDecoSSStopOrViolation();
        /*Dive Time*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTime_Value);
        break;
    }
}

/*Check display base one user set extra large Depth or Dive time*/
void DiveModeHandle_GSM_SwitchDisplayExtralargeDepthOrDiveTime(void)
{
    switch(ValidateTheDisplayExtraDepthOrDiveTime())
    {
    case Setting_ExtraLarge_DEPTH:
        /*Depth or Surface Time*/
        DiveModeHandle_GSM_DispExtraDepthOrSurfTimeAfterDive();
        /*Dive Time*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTime_Value);
        /*Max depth*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_MaxDepth_TitleTxt);
        HandleDisplayTextWithMemdev(IteStat_Select, Dive_Gauge_MaxDepth_Value);
        break;
    case Setting_ExtraLarge_DIVETIME:
        /*Depth or Surface Time*/
        DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive();
        /*Max Depth*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveModeGSM_MaxDepth_TitleTxt);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, DiveModeGSM_MaxDepth_Value);
        /*Dive Time extra*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTimeExtra_Value);
        break;
    default:
        /*Depth or Surface Time*/
        DiveModeHandle_10Mins_DisplayDepthOrSurfaceTimeAfterDive();
        /*Dive Time*/
        HandleDisplayTextWithMemdev(IteStat_Select, DiveMode_DiveTime_TitleText);
        HandleDisplayItemMdev(DiveMode_DiveTime_Value);
        /*AVG Depth & Max Depth / Violation*/
        DivemodeHandle_GSM_CheckDisplayViolationAboveMiddle();
        break;
    }
}

