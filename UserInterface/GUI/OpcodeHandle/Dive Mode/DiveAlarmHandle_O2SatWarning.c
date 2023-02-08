#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_O2SatWarning_Context(char* pStrRet)
{
    strcpy(pStrRet, "O2 SAT 80%");
}
const contentDispContext_st ALARM_O2SatWarning =
{
    &ALARM_O2SatWarning_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_O2SatWarning(void)
{
    return (unsigned char)Alarming.Bit.O2_80Pct;
};
unsigned char AlarmStatusCheck_O2SatWarning_FlashingArrow(void)
{
    return (unsigned char)AlarmOn.Bit.O2_80Pct;
};
