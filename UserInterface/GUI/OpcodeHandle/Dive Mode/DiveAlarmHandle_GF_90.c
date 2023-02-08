#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_GF_90_Context(char* pStrRet)
{
    strcpy(pStrRet, "ˇ GF > 90 ˇ");
}
const contentDispContext_st ALARM_CV_GF_90 =
{
    &ALARM_GF_90_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_CV_GF90(void)
{
    unsigned char alarmStatusRet = FALSE;
    /*Get the status from application*/
    if(GFmaxValue > 90)
    {
        alarmStatusRet = TRUE;
    }
    return alarmStatusRet;
}