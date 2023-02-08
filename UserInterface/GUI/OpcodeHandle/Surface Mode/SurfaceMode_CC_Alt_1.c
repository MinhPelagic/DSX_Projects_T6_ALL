
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

void IniOrClrScrFunc_S11_SURFACE_ALT1(void)
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
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
}
void UpdOrFlasFunc_S11_SURFACE_ALT1(void)
{
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*TIME*/
    DiveModeHandle_Display_Clock(IteStat_Update);
}
