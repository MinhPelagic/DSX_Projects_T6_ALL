#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_CC6Pressure_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CC6_PRESS_ALARM));
}
const contentDispContext_st ALARM_CC6Pressure =
{
    &ALARM_CC6Pressure_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_CC6Pressure(void)
{
    return (unsigned char)0u;
};
