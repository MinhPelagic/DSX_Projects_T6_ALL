#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_GradientFactor_Context(char* pStrRet)
{
    sprintf(pStrRet, "GRADIENT FACTOR %d", SCUBA_Set.GF_Alarm);
}
const contentDispContext_st ALARM_GradientFactor =
{
    &ALARM_GradientFactor_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_GradientFactor(void)
{
    return (unsigned char)AlarmOn2.Bit.GF;
};
