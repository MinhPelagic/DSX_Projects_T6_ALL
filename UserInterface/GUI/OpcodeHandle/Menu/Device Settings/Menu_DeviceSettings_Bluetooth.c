/******************************************************************************/
//File: Device settings -> Units
//Description:
//Created by:
//History:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDeviceSettingsCfg.h"
#include "Menu_DeviceSettings.h"

void IniOrClrScrFunc_DEVICE_BLUETOOTH_SET(void)
{
    /*Clear the list of previous content*/
    ClearUnusedInList(0);
    /*Sub title*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_BLUETOOTH));
    /*Display set*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_DeviceSett_Bluetooth_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_DEVICE_BLUETOOTH_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_DeviceSett_Bluetooth_Ctx);
}
/*Passcode Text*/
static void blePasscodeText_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PASSCODE));
}
static const contentDispContext_st blePasscodeText =
{
    &blePasscodeText_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_Bluetooth_PasscodeTxt,
};
/*Passcode Number*/
static void blePasscodeNum_Context(char* pStrRet)
{
    char passcode[6];

    for(uint8_t i=0; i<6; i++)
        passcode[i] = SystemStatus.BLE_PassCode[i];

    sprintf(pStrRet, "%c%c%c%c%c%c", passcode[0], passcode[1], passcode[2],
            passcode[3], passcode[4], passcode[5]);
}
static const contentDispContext_st blePasscodeNum =
{
    &blePasscodeNum_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Bluetooth_PasscodeValue,
};
/*Bluetooth icon display on surface*/
#define X0_BleIcon              140
#define Y0_BleIcon              50
#define X1_BleIcon              X0_BleIcon + 32
#define Y1_BleIcon              Y0_BleIcon + 43
#define X_BleIcon               X0_BleIcon + 7
#define Y_BleIcon               Y0_BleIcon + 13
#define r_BleIcon               15 //radius of icon
#define aH_BleIcon              9 //Adjust width
#define bH_BleIcon              18 //Adjust height
#define bH_BleIconm2            (bH_BleIcon/2)
#define aH_BleIconX2            (aH_BleIcon*2)
#define bH_BleIconX2            (bH_BleIcon*2)
#define bH_BleIcon32            (bH_BleIconm2+bH_BleIcon)
#define nPoints_BleIcon         5
static const GUI_POINT bleMainIcon[nPoints_BleIcon+1]=
{
    {+0, +0},
    {+aH_BleIconX2, +bH_BleIcon},
    {+aH_BleIcon,   +bH_BleIcon32},
    {+aH_BleIcon,   -bH_BleIconm2},
    {+aH_BleIconX2, +0},
    {+0, +bH_BleIcon},
};
void DispBleMainIcon(void)
{
    GUI_SetColor(GUI_CYAN);
    /*Draw the icon*/
    GUI_AA_FillRoundedRect(X0_BleIcon, Y0_BleIcon, X1_BleIcon, Y1_BleIcon, r_BleIcon);
    /*Draw the internal lines*/
    GUI_SetColor(GUI_BLACK);
    GUI_SetPenSize(3);
    for(unsigned char cnt_u8 = 0; cnt_u8 < nPoints_BleIcon; cnt_u8++)
    {
        /*X0 + posX, Y0 + posY*/
        GUI_AA_DrawLine(X_BleIcon + bleMainIcon[cnt_u8].x,
                        Y_BleIcon + bleMainIcon[cnt_u8].y,
                        X_BleIcon + bleMainIcon[cnt_u8+1].x,
                        Y_BleIcon + bleMainIcon[cnt_u8+1].y);
    }
}
void IniOrClrScrFunc_DEVICE_BLUETOOTH_PASSCODE(void)
{
    /*Clear all the screen*/
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    SystemSupplyMonitor.PreBattery_Percentage = 0;      // to turn LCD brighter
    /*Set Brightness*/
    Backlight_Set(70);
    /*Bluetooth icon*/
    DispBleMainIcon();
    /*Passcode text*/
    HandleDisplayTextWithMemdev(IteStat_Select, blePasscodeText);
    /*Passcode value*/
    HandleDisplayTextWithMemdev(IteStat_Select, blePasscodeNum);
}
void UpdOrFlasFunc_DEVICE_BLUETOOTH_PASSCODE(void)
{
    /*Bluetooth icon*/
    DispBleMainIcon();
    /*Passcode text*/
    HandleDisplayTextWithMemdev(IteStat_Select, blePasscodeText);
    /*Passcode value*/
    HandleDisplayTextWithMemdev(IteStat_Select, blePasscodeNum);
}
