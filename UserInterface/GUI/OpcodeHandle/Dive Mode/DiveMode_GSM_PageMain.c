#include "L4X9_includes.h"
#include "DiveMode.h"

static void Dive_GSM_Handle_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*When have TMT assigned -> Display TMT-L/R or TMT-#2/3/4*/
        if(CheckIfGasToTMT_Assigned())
        {
            /*When TMT left and right has assigned*/
            if(SurfaceCheckTMTLeftRightStatus())
            {
                SurfaceHandle_DisplayTMT_LR();
                /*Alarm Switch tank arrow flashing -> Only when switch TMT between L-R*/
                DiveModeAlarm_SwitchTankArrow();
            }
            /*Otherwise display selections (TMT-3,4,5,6)*/
            else
            {
                /*TMT number*/
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_TMT_Value);
                /*#OverlapFix : Clear the portion on right*/
                ClearPortion_NextToBottomSurfTMT();
                /*Pressure*/
                SurfaceHandle_PressureDisplay();
                HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_TMT_Value);
            }
        }
        else
        {
            /*Do nothing/clear bottom*/
        }
    }
}
static void hanldeClearScrDiveGSMMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if(DIVE_GSM_ALT==pre_DSX_Opcode)
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_DIVE_GSM_MAIN(void)
{
    /*Initialize screen*/
    hanldeClearScrDiveGSMMainPage();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_GSM_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Runtime & GTR*/
    DivemodeHandle_GSM_CheckDisplayViolationMiddle(IteStat_Initial);
    /*Check display with alarms*/
    Dive_GSM_Handle_MainPage_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
}
void UpdOrFlasFunc_DIVE_GSM_MAIN(void)
{
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_GSM_SwitchDisplayExtralargeDepthOrDiveTime();
    /*Runtime & GTR*/
    DivemodeHandle_GSM_CheckDisplayViolationMiddle(IteStat_Update);
    /*Check display with alarms*/
    Dive_GSM_Handle_MainPage_CheckDisplayBottom();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
}
