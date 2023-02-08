#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_SwitchP_Context(char* pStrRet)
{
    if(L2R_PSI_Diff() > (int16_t)0)
    {
        strcpy(pStrRet, "˂");//Arrow Left
    }
    else
    {
        strcpy(pStrRet, "˃");//Arrow Right
    }
}
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_SwitchP(void)
{
    return (unsigned char)Alarming2.Bit.SwitchP;
};
const contentDispContext_st ALARM_SwitchTank =
{
    &ALARM_SwitchP_Context,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ALARM_SwitchTankArrow,
};
