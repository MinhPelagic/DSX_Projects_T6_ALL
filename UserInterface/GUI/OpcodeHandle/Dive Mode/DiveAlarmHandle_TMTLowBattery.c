#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_TMTLowBattery_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TMT_LOW_BATT));
}
const contentDispContext_st ALARM_TMTLowBattery =
{
    &ALARM_TMTLowBattery_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
const contentDispContext_st WARNING_TMTLowBattery =
{
    &ALARM_TMTLowBattery_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_TMTLowBattery(void)
{
    return (unsigned char)0u;
};
