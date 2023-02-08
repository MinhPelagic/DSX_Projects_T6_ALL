#include "L4X9_includes.h"
#include "DiveMode.h"
/*
Flashing arrow left/right
*/
void DiveModeAlarm_SwitchTankArrow(void)
{
    ItemStatus_te dispStatus = IteStat_Clear;
    /*Handle flashing*/
    if(AlarmStatusCheck_FullViolation())
    {
        /*No alarms need to progress*/
    }
    else
    {
        if(ALARM_SwitchP==AlarmID)
        {
            dispStatus = IteStat_ClearThenFlashing; //Flashing the arrow left/right
            AlarmDueAck2.Bit.SwitchP = 1;           //This from application
        }
        else
        {
            /*keep clear the portion*/
        }
        HandleDisplayTextWithMemdev(dispStatus, ALARM_SwitchTank);
    }
}
