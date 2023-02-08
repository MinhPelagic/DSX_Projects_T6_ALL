
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
/*CC and OC mode on Surface is the same*/
static void hanldeClearScrSurfaceMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if((S11_SURFACE_ALT1==pre_DSX_Opcode)||(S15_SURFACE_ALT5==pre_DSX_Opcode))
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_S2_SURFACE_MAIN(void)
{
    /*Clear all the screen*/
    GUI_SetBkColor(GUI_BLACK);
    hanldeClearScrSurfaceMainPage();
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
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Check display in bottom*/
    SurfaceMode_CC_MainPage_CheckDisplayBottom();
}
/*3. Flashing or keep update content of items S2_SURFACE_MAIN */
void UpdOrFlasFunc_S2_SURFACE_MAIN(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Last Dive*/
    SurfaceMode_LastDiveHandle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Check display in bottom*/
    SurfaceMode_CC_MainPage_CheckDisplayBottom();
}

