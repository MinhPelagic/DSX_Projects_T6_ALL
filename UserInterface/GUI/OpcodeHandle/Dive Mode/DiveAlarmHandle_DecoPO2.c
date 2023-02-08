#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_DecoPO2_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DECO_PO2));
}
const contentDispContext_st ALARM_DecoPO2 =
{
    &ALARM_DecoPO2_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of  in both Dive/Surface*/
unsigned char AlarmStatusCheck_DecoPO2(void)
{
    if(CC_MODE)
        return 0;
    else
        return (unsigned char)Alarming2.Bit.OCSM_DecoPO2;
};
/*item status*/
ItemStatus_te DiveMode_DispStat_DecoPO2(void)
{
    ItemStatus_te statRet = IteStat_Select;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn2.Bit.OCSM_DecoPO2)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}
