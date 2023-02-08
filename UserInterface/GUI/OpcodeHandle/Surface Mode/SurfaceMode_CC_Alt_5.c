
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

void IniOrClrScrFunc_S15_SURFACE_ALT5(void)
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
    /*Dil PO2*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_DilPO2_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_DilPO2_Value);
    /*Fi O2*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_FiO2_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_FiO2_Value);
    /*GF*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
}
void UpdOrFlasFunc_S15_SURFACE_ALT5(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    Display_Battery_Surface((void*) &pDataSurfBatt);
}