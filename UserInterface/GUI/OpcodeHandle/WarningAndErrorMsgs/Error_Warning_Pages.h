/******************************************************************************/
//
//      File: Error_Warning_Pages.h
//
//      Collections of Errors and Warnings for Axx and Exx GUI Pages
//
/*****************************************************************************/
#include "L4X9_includes.h"
/**
 * @brief SYSTEM ERROR message ID
 * 
 */
enum    
{
    // Same to the Bit Definition in L4X9_SystemWarnings_t
    SYSERR_DEPTH_SENSOR = 1u,
    SYSERR_EEPROM       = 2u,
    SYSERR_EXFLASH      = 3u,
    SYSERR_CALIBRATION  = 4u,
    SYSERR_CHECKSUM     = 5u,
    SYSERR_10HR         = 6u,
    SYSERR_LOW_BATT     = 7u,
    SYSERR_BLUETOOTH    = 8u,
    SYSERR_NOT_YET_CALI = 9u,    
    SYSERR_LASTDIVE     = 10u,
    SYSERR_ADC          = 11u,
    SYSERR_TEMPSENSOR   = 12u,
    SYSERR_VOLTSENSOR   = 13u,    
    SYSERR_TICKTIME     = 14u,
    SYSERR_BUTTON       = 15u,
    SYSERR_ALTITUDE     = 16u,
    SYSERR_COMPASS      = 17u,
    SYSERR_FUELGAUGE    = 18u,
    SYSERR_RECEIVER     = 19u,
    SYSERR_GPS          = 20u,
    SYSERR_O2SENSOR     = 21u,
};
/**
 * @brief 
 * 
 */
extern const contentDispContext_st ErrWarning_ErrorDepthSensor;
extern const contentDispContext_st ErrWarning_BatteryTooLow_00;
extern const contentDispContext_st ErrWarning_BatteryTooLow_01;
extern const contentDispContext_st ErrWarning_ErrorEEPRom;
extern const contentDispContext_st ErrWarning_ErrorExternalFlash;
extern const contentDispContext_st ErrWarning_ErrorDiveOver10Hours;
extern const contentDispContext_st ErrWarning_ErrorCalibration;
extern const contentDispContext_st ErrWarning_ErrorCheckSum;
extern const contentDispContext_st ErrWarning_ErrorDiveNotComplete;
extern const contentDispContext_st ErrWarning_BluetoothFail_00;
extern const contentDispContext_st ErrWarning_BluetoothFail_01;
extern const contentDispContext_st ErrWarning_CompassError_00;
extern const contentDispContext_st ErrWarning_CompassError_01;
extern const contentDispContext_st ErrWarning_GPSFailed_00;
extern const contentDispContext_st ErrWarning_GPSFailed_01;
extern const contentDispContext_st ErrWarning_ErrorAltitude_00;
extern const contentDispContext_st ErrWarning_ErrorAltitude_01;
extern const contentDispContext_st SystemErrorMsg_00;
extern const contentDispContext_st SystemErrorMsg_NotYetCalib;
extern const contentDispContext_st SystemErrorMsg_ADC;
extern const contentDispContext_st SystemErrorMsg_TempSensor;
extern const contentDispContext_st SystemErrorMsg_VoltSensor;
extern const contentDispContext_st SystemErrorMsg_TickTime;
extern const contentDispContext_st SystemErrorMsg_Button;
extern const contentDispContext_st SystemErrorMsg_Altitude;
extern const contentDispContext_st SystemErrorMsg_Compass;
extern const contentDispContext_st SystemErrorMsg_FuelGauge;
extern const contentDispContext_st SystemErrorMsg_Receiver;
extern const contentDispContext_st SystemErrorMsg_GPS;
extern const contentDispContext_st SystemErrorMsg_O2Sensor;
extern const contentDispContext_st PopUpWarning_PleaseUseAppToActive01;
extern const contentDispContext_st PopUpWarning_PleaseUseAppToActive02;

