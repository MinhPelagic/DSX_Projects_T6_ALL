
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
/*Gauge mode on Surface is the same*/
static void hanldeClearScrSurfaceGaugeSMMainPage(void)
{
    /*Check to clear all the screen or only portion*/
    if((SURFACE_GSM_ALT1==pre_DSX_Opcode)||(SURFACE_GSM_ALT2==pre_DSX_Opcode))
    {
        ClearPortionToUpdateDiveMode();
    }
    else
    {
        GUI_Clear();
    }
}
void IniOrClrScrFunc_SURFACE_GSM_MAIN(void)
{
    /*Clear all the screen*/
    GUI_SetBkColor(GUI_BLACK);
    hanldeClearScrSurfaceGaugeSMMainPage();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Last dive in center*/
    SurfaceMode_GSM_LastDiveHandle();
    /*Run time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Tittle);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Battery*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Bottom display check*/
    SurfaceMode_GSM_MainPage_CheckDisplayBottom();
}
/*3. Flashing or keep update content of items SURFACE_GSM_MAIN */
void UpdOrFlasFunc_SURFACE_GSM_MAIN(void)
{
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Run time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_Runtime_Value);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    Display_Battery_Surface((void*) &pDataSurfBatt);
    /*Bottom display check*/
    SurfaceMode_GSM_MainPage_CheckDisplayBottom();
}
