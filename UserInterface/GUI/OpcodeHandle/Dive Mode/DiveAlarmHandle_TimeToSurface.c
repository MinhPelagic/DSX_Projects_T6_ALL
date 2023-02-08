#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_TimeToSurface_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TIME_SURFACE_ALARM));
}
const contentDispContext_st ALARM_TimeToSurface =
{
    &ALARM_TimeToSurface_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,   // reuse
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_TimeToSurface(void)
{
    return (unsigned char)(Alarming2.Bit.TTS_T||Alarming.Bit.DepthMax);
};
unsigned char AlarmColorCheck_TimeToSurface(void)
{
    return (unsigned char)AlarmOn2.Bit.TTS_T;
};
GUI_COLOR AlarmColorHandle_TimeToSurface(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_TimeToSurface())
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
/*item status*/
ItemStatus_te DiveMode_DispStat_TimeToSurface(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmColorCheck_TimeToSurface())
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}