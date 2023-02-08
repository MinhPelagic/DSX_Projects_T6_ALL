#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_TankPressure_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TANK_PRESSURE));
}
const contentDispContext_st ALARM_TankPressure =
{
    &ALARM_TankPressure_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_TankPressure(void)
{
    return (unsigned char)0u;
};
