#include "SurfaceMode.h"

/*Bluetooth icon display on surface*/
#define rBluetoothIco       8 //radius of icon
#define ofsetBlueIco        1 //Offset to fit in the memdev space
#define aHBlue              4
#define bHBlue              8
#define bHBluem2            (bHBlue/2)
#define aHBlueX2            (aHBlue*2)
#define bHBlueX2            (bHBlue*2)
#define bHBlue32            (bHBluem2+bHBlue)
static const GUI_POINT bluetoothIcon[]=
{
    {+0, +0},
    {+aHBlueX2, +bHBlue},
    {+aHBlue,   +bHBlue32},
    {+aHBlue,   -bHBluem2},
    {+aHBlueX2, +0},
    {+0, +bHBlue},
};
#define numPointsBlueIco    5
void SurfaceMode_BluetoothIcon(unsigned char bluetoothState)
{
    GUI_MEMDEV_Handle hMemDevLocal;
    /**/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_SurfaceBluetooth->X0, Pos_SurfaceBluetooth->Y0, Pos_SurfaceBluetooth->Width, Pos_SurfaceBluetooth->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_SurfaceBluetooth->X0, Pos_SurfaceBluetooth->Y0, Pos_SurfaceBluetooth->X1, Pos_SurfaceBluetooth->Y1);
    /*Hanlde 2 states*/
    if((BLE_HDL_CONNECT==bluetoothState)||(BLE_HDL_READY==bluetoothState))
    {
        if(BLE_HDL_CONNECT==bluetoothState)
        {
            GUI_SetColor(GUI_GREEN);
        }
        else
        {
            GUI_SetColor(GUI_CYAN);
        }
        /*Draw the icon*/
        GUI_AA_FillRoundedRect(Pos_SurfaceBluetooth->X0, Pos_SurfaceBluetooth->Y0, Pos_SurfaceBluetooth->X1 - ofsetBlueIco, Pos_SurfaceBluetooth->Y1 - ofsetBlueIco, rBluetoothIco);
        /*Draw the internal lines*/
        GUI_SetColor(GUI_BLACK);
        GUI_SetPenSize(1);
        for(unsigned char cnt_u8 = 0; cnt_u8 < numPointsBlueIco; cnt_u8++)
        {
            /*X0 + posX, Y0 + posY*/
            GUI_AA_DrawLine(Pos_SurfaceBluetooth->X + bluetoothIcon[cnt_u8].x, \
                            Pos_SurfaceBluetooth->Y + bluetoothIcon[cnt_u8].y, \
                            Pos_SurfaceBluetooth->X + bluetoothIcon[cnt_u8+1].x, \
                            Pos_SurfaceBluetooth->Y + bluetoothIcon[cnt_u8+1].y);
        }
    }
    else
    {
        /*No display buluetooth when OFF*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}