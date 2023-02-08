#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DecoWarning_Context(char* pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_MISSED_DECO));
}
const contentDispContext_st ALARM_DecoWarning =
{
    &ALARM_DecoWarning_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DecoWarning(void)
{
    return (unsigned char)Alarming.Bit.DECO_Warning;
};
GUI_COLOR AlarmColorHandle_DecoWarning(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DecoWarning())
    {
        colorRet = GUI_RED;
    }
    else if(ColorCheck_DecoStop())
    {
        colorRet = GUI_YELLOW;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
/*item status*/
ItemStatus_te DiveMode_DispStat_DecoWarning(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DECO_Warning)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}