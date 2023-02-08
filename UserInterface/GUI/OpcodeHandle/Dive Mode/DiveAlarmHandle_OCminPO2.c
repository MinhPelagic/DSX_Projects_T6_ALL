#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_OCSM_MinPO2_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_PO2));
}
const contentDispContext_st ALARM_OCSM_MinPO2Alarm =
{
    &ALARM_OCSM_MinPO2_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of  in both Dive/Surface*/
unsigned char AlarmStatusCheck_OCminPO2(void)
{
    if(CC_MODE)
        return 0;
    else
        return (unsigned char)Alarming2.Bit.OCSM_MinPO2;
};
