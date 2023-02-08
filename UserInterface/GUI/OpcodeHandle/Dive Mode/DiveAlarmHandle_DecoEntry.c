#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DecoEntry_Context(char* pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_DECO_ENTRY));
}
const contentDispContext_st ALARM_DecoEntryAlarm =
{
    &ALARM_DecoEntry_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DecoEntry(void)
{
    return (unsigned char)AlarmOn.Bit.DECO_Entry;
};
GUI_COLOR AlarmColorHandle_DecoEntry(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DecoEntry())
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
/*item status*/
ItemStatus_te DiveMode_DispStat_DecoEntry(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DECO_Entry)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
