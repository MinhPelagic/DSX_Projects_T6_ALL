#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_GasTimeRemaining_Context(char* pStrRet)
{
    strcpy(pStrRet,GUI_LANG_GetText(TxtStr_GAS_TIMEREMAINING));
}
const contentDispContext_st ALARM_GasTimeRemaining =
{
    &ALARM_GasTimeRemaining_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_GasTimeRemaining(void)
{
    return (unsigned char)0u;
};
