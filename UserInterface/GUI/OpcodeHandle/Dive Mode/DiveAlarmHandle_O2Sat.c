#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_O2Sat_Context(char* pStrRet)
{
    strcpy(pStrRet, "O2 SAT 100%");
}
const contentDispContext_st ALARM_O2Sat =
{
    &ALARM_O2Sat_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_O2Sat(void)
{
    unsigned char retStat = FALSE;
    /*Flashing arrows up only underwater, when on Surface -> no display*/
    if(Alarming.Bit.O2_100Pct)
    {
        retStat = TRUE;
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
};
