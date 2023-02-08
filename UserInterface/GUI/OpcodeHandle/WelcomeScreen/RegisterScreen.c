#include "L4X9_includes.h"
#include "../Surface Mode/SurfaceMode.h"
extern GUI_CONST_STORAGE GUI_BITMAP bmRegister;
extern const battInfo_st pDataSurfBatt;

void IniOrClrScrFunc_REGISTER_SCREEN(void)
{
    /*Clear all the screen*/            // Added from R1006 by YS, to fix the residue around battery icon
    GUI_SetBkColor(GUI_BLACK);          // Added from R1006 by YS, to fix the residue around battery icon
    GUI_Clear();                        // Added from R1006 by YS, to fix the residue around battery icon
    GUI_DrawBitmap(&bmRegister, 0, 0);
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Battery*/
    Display_Battery_Surface((void *)&pDataSurfBatt);
}
void UpdOrFlasFunc_REGISTER_SCREEN(void)
{
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Battery*/
    Display_Battery_Surface((void *)&pDataSurfBatt);
}