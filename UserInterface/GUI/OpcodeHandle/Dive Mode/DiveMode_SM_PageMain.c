#include "L4X9_includes.h"
#include "DiveMode.h"
/*
Content in the bottom
Alternate display between OC-L/R and alarm
*/
void Dive_SM_Handle_MainPage_CheckDisplayBottom(void)
{
    /*When no alarms occurs -> Display FO2, Presure*/
    if(DiveModeAlarm_BottomAlarms())
    {
        /*Keep Alarm flashing*/
        ClearPortionToUpdateAlarm();
    }
    else
    {
        /*Display either OC-L or OC-R or Both*/
        if(CheckIfGasToTMT_Assigned())
        {
            /*When TMT left and right has assigned*/
            if(SurfaceCheckTMTLeftRightStatus())
            {
                SurfaceHandle_DisplayTANK_LR();
                /*Alarm Switch tank arrow flashing -> Only when switch TMT between L-R*/
                DiveModeAlarm_SwitchTankArrow();
            }
            else
            {
                /*FO2*/
                DiveModeHandle_DisplayFO2();
                /*Pressure*/
                SurfaceHandle_PressureDisplay();
                /*This option specific when Violation only : display GTR*/
                DiveModeHandle_Violation_Display_GTRBottom();
            }
        }
        else
        {
            /*When TMT left and right has assigned*/
            if(SurfaceCheckTMTLeftRightStatus())
            {
                /*Clear the portion -> Display empty*/
                ClearPortion_BottomAlarmFull();
            }
            else
            {
                /*FO2*/
                DiveModeHandle_DisplayFO2();
                /*Keep clear*/
                ClearPortion_TankPressure();
            }
        }
    }
}
static void hanldeClearScrDiveSMModeMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if((DIVE_SM_ALT_1==pre_DSX_Opcode)||(DIVE_SM_ALT_5==pre_DSX_Opcode))
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_DIVE_SM_MAIN(void)
{
    /*Initialize screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_CYAN);
    hanldeClearScrDiveSMModeMainPage();
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Dive Main Bottom Row*/
    Dive_SM_Handle_MainPage_CheckDisplayBottom();
}
void UpdOrFlasFunc_DIVE_SM_MAIN(void)
{
    /*AR bar*/
    Display_AR(ASCBGVal);
    /*Check display extra large*/
    DiveModeHandle_OC_SwitchDisplayExtralargeDepthOrDiveTime();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Battery*/
    DiveModeHandle_BatteryDisplay();
    /*Check the alarms 2 arrows Up*/
    DiveMode_AlarmHandleDisplay2ArrowsUpDown();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Dive Main Bottom Row*/
    Dive_SM_Handle_MainPage_CheckDisplayBottom();
}
