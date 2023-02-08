
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

/*1. Clear or Initilal screen for  SURFACE_SM_ALT2 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT3(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateDiveMode();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Last Dive*/
    SurfaceMode_LastDiveHandle();
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*Content OC-R / OC-L*/
    if( (SuggestedBestGasNumber != 0) && (SuggestedBestGasNumber != (uint8_t)TANK_NumSelected()) )
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_NotBestGas_OCLeftStatus_Value);
    else
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeftStatus_Value);
    /*Main GF*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Value);
    /*O2 Sat*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}
void UpdOrFlasFunc_SURFACE_SM_ALT3(void)
{
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*Content OC-R / OC-L*/
    if( (SuggestedBestGasNumber != 0) && (SuggestedBestGasNumber != (uint8_t)TANK_NumSelected()) )
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_NotBestGas_OCLeftStatus_Value);
    else
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_OCLeftStatus_Value);
    /*Main GF*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Value);
    /*O2 Sat*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}
