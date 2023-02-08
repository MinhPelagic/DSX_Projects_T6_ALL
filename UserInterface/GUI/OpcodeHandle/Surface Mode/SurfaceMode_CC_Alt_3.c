
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Dive Mode\DiveMode.h"

/*1. Clear or Initilal screen for  S13_SURFACE_ALT3 operation*/
void IniOrClrScrFunc_S13_SURFACE_ALT3(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateSurfaceMode();
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
    if(NVD_MDCC==DIVE_MODE)
    {
        //CC - 6
        SurfaceMode_CC6TankPressure();
    }
    else
    {
        /*Do nothing*/
    }
}
void UpdOrFlasFunc_S13_SURFACE_ALT3(void)
{
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Main GF*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_MainGF_Value);
    /*O2 Sat*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_O2Sat_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    if(NVD_MDCC==DIVE_MODE)
    {
        SurfaceMode_CC6TankPressure();
    }
    else
    {
        /*Do nothing*/
    }
}
