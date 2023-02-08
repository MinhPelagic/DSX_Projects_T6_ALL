/******************************************************************************/
//
//      File: Error_Warning_Pages.c
//
//      Collections of Errors and Warnings for Axx and Exx GUI Pages
//
/*****************************************************************************/
#include "Error_Warning_Pages.h"

/*1. Clear or Initilal screen for  ERR1 DEPTH SENSOR operation*/
void IniOrClrScrFunc_E1_ERROR_DEPTH_SENSOR(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorDepthSensor);
}
void UpdOrFlasFunc_E1_ERROR_DEPTH_SENSOR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorDepthSensor);
}
/*1. Clear or Initilal screen for  E2_ERROR_EEPROM operation*/
void IniOrClrScrFunc_E2_ERROR_EEPROM(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorEEPRom);
}
void UpdOrFlasFunc_E2_ERROR_EEPROM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorEEPRom);
}
/*1. Clear or Initilal screen for  E3_ERROR_EXFLASH operation*/
void IniOrClrScrFunc_E3_ERROR_EXFLASH(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorExternalFlash);
}
void UpdOrFlasFunc_E3_ERROR_EXFLASH(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorExternalFlash);
}
/*1. Clear or Initilal screen for  E4_ERROR_CALIBRATION operation*/
void IniOrClrScrFunc_E4_ERROR_CALIBRATION(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorCalibration);
}
void UpdOrFlasFunc_E4_ERROR_CALIBRATION(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorCalibration);
}
/*1. Clear or Initilal screen for 5 EEPROM CHECKSUM operation*/
void IniOrClrScrFunc_E5_ERROR_CHECKSUM(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorCheckSum);
}
void UpdOrFlasFunc_E5_ERROR_CHECKSUM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorCheckSum);
}
/*1. Clear or Initilal screen for  E6_ERROR_DIVE_10HR operation*/
void IniOrClrScrFunc_E6_ERROR_DIVE_10HR(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorDiveNotComplete);
}
void UpdOrFlasFunc_E6_ERROR_DIVE_10HR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorDiveNotComplete);
}
/*1. Clear or Initilal screen for  E7_ERROR_BATTERY_TOO_LOW operation*/
void IniOrClrScrFunc_E7_ERROR_BATTERY_TOO_LOW(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_BatteryTooLow_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_BatteryTooLow_01);
}
void UpdOrFlasFunc_E7_ERROR_BATTERY_TOO_LOW(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_BatteryTooLow_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_BatteryTooLow_01);
}
/*1. Clear or Initilal screen for E8_ERROR_BLUETOOTH operation*/
void IniOrClrScrFunc_E8_ERROR_BLUETOOTH(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_BluetoothFail_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_BluetoothFail_01);
}
void UpdOrFlasFunc_E8_ERROR_BLUETOOTH(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_BluetoothFail_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_BluetoothFail_01);
}
/*1. Clear or Initilal screen for  E9_ERROR_COMPASS operation*/
void IniOrClrScrFunc_E9_ERROR_COMPASS(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_CompassError_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_CompassError_01);
}
void UpdOrFlasFunc_E9_ERROR_COMPASS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_CompassError_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_CompassError_01);
}
/*1. Clear or Initilal screen for  E10_ERROR_GPS operation*/
void IniOrClrScrFunc_E10_ERROR_GPS(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_GPSFailed_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_GPSFailed_01);
}
void UpdOrFlasFunc_E10_ERROR_GPS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_GPSFailed_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_GPSFailed_01);
}
/*1. Clear or Initilal screen for E11_ERROR_O2_SENSOR operation*/
void IniOrClrScrFunc_E11_ERROR_O2_SENSOR(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_GPSFailed_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_GPSFailed_01);
}
void UpdOrFlasFunc_E11_ERROR_O2_SENSOR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_GPSFailed_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_GPSFailed_01);
}
/*1. Clear or Initilal screen for  E12_ERROR_ALTITUDE operation*/
void IniOrClrScrFunc_E12_ERROR_ALTITUDE(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorAltitude_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorAltitude_01);
}
void UpdOrFlasFunc_E12_ERROR_ALTITUDE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorAltitude_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorAltitude_01);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E9_ERROR_NOT_YET_CALI(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_NotYetCalib);
}
void UpdOrFlasFunc_E9_ERROR_NOT_YET_CALI(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_NotYetCalib);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E10_ERROR_DIVE_NOT_COMPLETE(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, ErrWarning_ErrorDiveNotComplete);
}
void UpdOrFlasFunc_E10_ERROR_DIVE_NOT_COMPLETE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, ErrWarning_ErrorDiveNotComplete);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E11_ERROR_ADC(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_ADC);
}
void UpdOrFlasFunc_E11_ERROR_ADC(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_ADC);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E12_ERROR_TEMP_SENSOR(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_TempSensor);
}
void UpdOrFlasFunc_E12_ERROR_TEMP_SENSOR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_TempSensor);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E13_ERROR_VOLT_SENSOR(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_VoltSensor);
}
void UpdOrFlasFunc_E13_ERROR_VOLT_SENSOR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_VoltSensor);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E14_ERROR_TICK_TIME(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_TickTime);
}
void UpdOrFlasFunc_E14_ERROR_TICK_TIME(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_TickTime);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E15_ERROR_BUTTON(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_Button);
}
void UpdOrFlasFunc_E15_ERROR_BUTTON(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_Button);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E16_ERROR_ALTITUDE(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_Altitude);
}
void UpdOrFlasFunc_E16_ERROR_ALTITUDE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_Altitude);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E17_ERROR_COMPASS(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_Compass);
}
void UpdOrFlasFunc_E17_ERROR_COMPASS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_Compass);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E18_ERROR_FUEL_GAUGE(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_FuelGauge);
}
void UpdOrFlasFunc_E18_ERROR_FUEL_GAUGE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_FuelGauge);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E19_ERROR_RECEIVER(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_Receiver);
}
void UpdOrFlasFunc_E19_ERROR_RECEIVER(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_Receiver);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E20_ERROR_GPS(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_GPS);
}
void UpdOrFlasFunc_E20_ERROR_GPS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_GPS);
}
/**
 * @brief
 *
 */
void IniOrClrScrFunc_E21_ERROR_O2_SENSOR(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Select, SystemErrorMsg_O2Sensor);
}
void UpdOrFlasFunc_E21_ERROR_O2_SENSOR(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_00);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SystemErrorMsg_O2Sensor);
}
/**
 * @brief 
 * 
 */
void IniOrClrScrFunc_E22_POPUP_USINGDIVELOGAPP(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, PopUpWarning_PleaseUseAppToActive01);
    HandleDisplayTextWithMemdev(IteStat_Select, PopUpWarning_PleaseUseAppToActive02);
    Display_Icon_Buttons(IconBottDisp_HomeSelect);
}
