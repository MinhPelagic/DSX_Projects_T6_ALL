#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_LowPO2_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_PO2));
}
const contentDispContext_st ALARM_LowPO2 =
{
    &ALARM_LowPO2_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of  in both Dive/Surface*/
unsigned char AlarmStatusCheck_LowPO2(void)
{
    return (unsigned char)Alarming.Bit.PO2_Lo;
};
