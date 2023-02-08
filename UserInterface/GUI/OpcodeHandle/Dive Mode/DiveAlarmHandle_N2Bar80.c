#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_N2Bar_Context(char* pStrRet)
{
    sprintf(pStrRet, "N2 BAR %d", N2_ALARM_DATA);
}
const contentDispContext_st ALARM_N2Bar =
{
    &ALARM_N2Bar_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_N2Bar(void)
{
    return (unsigned char)AlarmOn2.Bit.N2;        // show 10 seconds only
};
