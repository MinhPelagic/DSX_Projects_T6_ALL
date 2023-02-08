#include "L4X9_includes.h"
#include "DiveMode.h"

void DepthAndDiveTime_AlarmHandleDisplay2ArrowsUpDown(void)
{
    const AlarmArrowHandle_st dispStatus = DiveMode_AlarmArrowHandleStatus();
    /*Create memory device space*/
    GUI_MEMDEV_Handle hMemDevLocal;
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_DepthDiveTime_AlarmArrowOnRight->X0, Pos_DepthDiveTime_AlarmArrowOnRight->Y0, Pos_DepthDiveTime_AlarmArrowOnRight->Width, Pos_DepthDiveTime_AlarmArrowOnRight->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    /*always clear before display*/
    GUI_ClearRect(Pos_DepthDiveTime_AlarmArrowOnRight->X0, Pos_DepthDiveTime_AlarmArrowOnRight->Y0, Pos_DepthDiveTime_AlarmArrowOnRight->X1, Pos_DepthDiveTime_AlarmArrowOnRight->Y1);
    GUI_SetFont(&FontAaux_3);
    if((IteStat_Flashing == dispStatus.dispStatus)&&(FLASHING_STATE_OFF == FlashingState_u8))
    {
        /*Set color*/
        GUI_SetColor(dispStatus.arrColor);
        /*Display arrow*/
        if(Alarm_2ArrowUp == dispStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˆ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y0);
            GUI_DispStringHCenterAt("ˆ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y + 20);
        }
        else if(Alarm_2ArrowDown == dispStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˇ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y);
            GUI_DispStringHCenterAt("ˇ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y + 20u);
        }
        else if(Alarm_1ArrowDown == dispStatus.arrUpDown)
        {
            GUI_DispStringHCenterAt("ˇ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y);
        }
        else
        {
            GUI_DispStringHCenterAt("ˆ", Pos_DepthDiveTime_AlarmArrowOnRight->X, Pos_DepthDiveTime_AlarmArrowOnRight->Y + 10u);
        }
    }
    else
    {
        /*Clear the portion already*/
    }
    /*send to lcd display*/
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
