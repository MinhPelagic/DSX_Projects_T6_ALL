
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
static void hanldeClearScrSurfaceSMMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    // if((S11_SURFACE_ALT1==pre_DSX_Opcode)||(S15_SURFACE_ALT5==pre_DSX_Opcode))
    // {
    //     ClearPortionToUpdateDiveMode();
    // }
    // else
    // {
    GUI_Clear();
    // }
}
void IniOrClrScrFunc_SURFACE_SM_MAIN(void)
{
    /*Clear all the screen*/
    GUI_SetBkColor(GUI_BLACK);
    hanldeClearScrSurfaceSMMainPage();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Last Dive*/
    SurfaceMode_LastDiveHandle();
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Check display in the bottom*/
    SurfaceMode_SM_MainPage_CheckDisplayBottom();
}
/*3. Flashing or keep update content of items */
void UpdOrFlasFunc_SURFACE_SM_MAIN(void)
{
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Check display in the middle*/
    Dive_SM_Handle_CheckDisplayMiddle();
    /*Check display in the bottom*/
    SurfaceMode_SM_MainPage_CheckDisplayBottom();
}
