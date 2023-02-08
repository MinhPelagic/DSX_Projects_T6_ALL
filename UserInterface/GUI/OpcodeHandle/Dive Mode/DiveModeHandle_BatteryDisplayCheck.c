#include "L4X9_includes.h"
#include "DiveMode.h"

/*Only display the battery icon when if below 16%
-> Warning/Alarms in this level triggered*/
void DiveModeHandle_BatteryDisplay(void)
{
    if(SystemSupplyMonitor.Battery_Percentage<(16U))
    {
        Display_Battery_Surface((void*) &pDataSurfBatt);
    }
    else
    {
        /*Do nothing*/
    }
}
