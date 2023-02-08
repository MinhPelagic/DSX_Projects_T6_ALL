
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

void IniOrClrScrFunc_SURFACE_GAUGE_ALT1(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateDiveMode();
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*TIME*/
    DiveModeHandle_Display_Clock(IteStat_Initial);
    /*Temperature*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Temperature_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Temperature_Value);
    /*Elev*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Elev_Tittle);
    if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SmallFont_Elev_Value);
    else
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Elev_Value);
}
void UpdOrFlasFunc_SURFACE_GAUGE_ALT1(void)
{
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Run time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Value);
    /*TIME*/
    DiveModeHandle_Display_Clock(IteStat_Update);
    /*Temperature*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Temperature_Value);
    /*Elev*/
    if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SmallFont_Elev_Value);
    else
        HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Elev_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Battery*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}
