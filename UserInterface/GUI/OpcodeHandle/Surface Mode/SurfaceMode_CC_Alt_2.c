
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

/*1. Clear or Initilal screen for  S12_SURFACE_ALT2 operation*/
void IniOrClrScrFunc_S12_SURFACE_ALT2(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateDiveMode();
    /*Display all the SURFACE's items*/
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*Last Dive*/
    SurfaceMode_LastDiveHandle();
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
    /*Press at activation*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Unit);
    /*Current Press*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Unit);
    /*GF*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
}
void UpdOrFlasFunc_S12_SURFACE_ALT2(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}