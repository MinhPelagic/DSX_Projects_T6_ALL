#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_HighPO2_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_HIGH_PO2));
}
GUI_COLOR AlarmColorHandle_PO2(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_HighPO2()||AlarmStatusCheck_LowPO2()||AlarmStatusCheck_OCminPO2()||AlarmStatusCheck_OCmaxPO2()||AlarmStatusCheck_DecoPO2())
    {
        colorRet = GUI_RED;
    }
    else
    {
        /*Do nothing*/
    }
    return colorRet;
}
const contentDispContext_st ALARM_HighPO2 =
{
    &ALARM_HighPO2_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_HighPO2(void)
{
    return (unsigned char)Alarming.Bit.PO2_Hi;
};
unsigned char AlarmStatusCheck_OCSM_MaxPO2(void)
{
    return (unsigned char)Alarming2.Bit.OCSM_MaxPO2;
};
/*item status*/
ItemStatus_te DiveMode_DispStat_CC_PO2(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.PO2_Lo || AlarmOn.Bit.PO2_Hi)       // || AlarmOn2.Bit.OCSM_DecoPO2)
    {
        statRet = IteStat_ClearThenFlashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
/*item status*/
ItemStatus_te DiveMode_DispStat_PO2(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*When alarm occured -> stop update/display*/
    if( AlarmOn.Bit.PO2_Hi || AlarmOn.Bit.PO2_Lo
            || AlarmOn2.Bit.OCSM_MinPO2 || AlarmOn2.Bit.OCSM_MaxPO2 || AlarmOn2.Bit.OCSM_DecoPO2 )
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
