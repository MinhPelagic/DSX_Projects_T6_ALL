
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

/*1. Clear or Initilal screen for operation*/
void IniOrClrScrFunc_SURFACE_GAUGE_ALT2(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateDiveMode();
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Press at activation*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Unit);
    /*Current Press*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Unit);
}
void UpdOrFlasFunc_SURFACE_GAUGE_ALT2(void)
{
    /*Run time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Value);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Press at activation*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Value);
    /*Current Press*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Value);
    /*GF*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Battery*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}
