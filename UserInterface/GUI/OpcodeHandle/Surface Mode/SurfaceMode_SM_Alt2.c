
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

/*1. Clear or Initilal screen for  SURFACE_SM_ALT1 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT2(void)
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
    /*Press at activation*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Unit);
    /*Current Press*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Value);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Unit);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*battery*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
}
void UpdOrFlasFunc_SURFACE_SM_ALT2(void)
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
    /*Press at activation*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_PressActivation_Value);
    /*Current Press*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_CurrentPress_Value);
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*battery*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
}
