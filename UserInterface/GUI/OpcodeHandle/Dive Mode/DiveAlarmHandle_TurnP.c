#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_TurnP_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TURN_PRESSURE));
}
const contentDispContext_st ALARM_TurnPressure =
{
    &ALARM_TurnP_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_TurnP(void)
{
    return (unsigned char)Alarming2.Bit.TurnP;
};
