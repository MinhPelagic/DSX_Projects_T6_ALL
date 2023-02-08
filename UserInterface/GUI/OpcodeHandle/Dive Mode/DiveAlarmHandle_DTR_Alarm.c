#include "L4X9_includes.h"
#include "DiveMode.h"
/*Return the status of in both Dive/Surface*/
unsigned char AlarmStatusCheck_DTR_Alarm(void)
{
    /*used Alarming because DTR need keep this color after flashing*/
    return (unsigned char)Alarming.Bit.DiveDTR;
};
GUI_COLOR AlarmColorHandle_DTR_Alarm(void)
{
    GUI_COLOR colorRet = TxtColor_Select;
    if(AlarmStatusCheck_DTR_Alarm())
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
ItemStatus_te DiveMode_DispStat_DTR_Alarm(void)
{
    ItemStatus_te statRet = IteStat_ClearThenSelect;
    /*When alarm occured -> stop update/display*/
    if(AlarmOn.Bit.DiveDTR)
    {
        statRet = IteStat_Flashing;
    }
    else
    {
        /*Do nothing*/
    }
    return statRet;
}