#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
void ALARM_FullViolation_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_VIOLATION));
}
const contentDispContext_st ALARM_FullViolation =
{
    &ALARM_FullViolation_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ALARM_FullViolation,
};
/*Return the status of Conditional Violation in both Dive/Surface*/
bool AlarmStatusCheck_FullViolation(void)
{
    /*Get the status from application*/
    return isViolation;
};
