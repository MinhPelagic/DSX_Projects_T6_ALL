#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_WorkOfBreathing_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_WORK_OF_BREATHING));
}
const contentDispContext_st ALARM_WorkOfBreathing =
{
    &ALARM_WorkOfBreathing_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_WorkOfBreathing(void)
{
    return (unsigned char)Alarming2.Bit.WOB;
};
