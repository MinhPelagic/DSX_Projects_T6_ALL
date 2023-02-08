/******************************************************************************/
//
//      File: Error_Warning_Pages config
//
//      Collections of Errors and Warnings for Axx and Exx GUI Pages
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Error_Warning_Pages.h"

/*DEPTH SENSOR ERROR*/
static void ErrWarning_ErrorDepthSensor_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_DEPTH_SENSOR);
}
const contentDispContext_st ErrWarning_ErrorDepthSensor =
{
    &ErrWarning_ErrorDepthSensor_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error EEPROM*/
static void ErrWarning_ErrorEEPRom_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_EEPROM);
}
const contentDispContext_st ErrWarning_ErrorEEPRom =
{
    &ErrWarning_ErrorEEPRom_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error EEPROM*/
static void ErrWarning_ErrorExtFlash_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_CALIBRATION);
}
const contentDispContext_st ErrWarning_ErrorExternalFlash =
{
    &ErrWarning_ErrorExtFlash_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error Calibration*/
static void ErrWarning_ErrorCalibration_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_CALIBRATION);
}
const contentDispContext_st ErrWarning_ErrorCalibration =
{
    &ErrWarning_ErrorCalibration_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error Check sum*/
static void ErrWarning_ErrorCheckSum_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_CHECKSUM);
}
const contentDispContext_st ErrWarning_ErrorCheckSum =
{
    &ErrWarning_ErrorCheckSum_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error Dive Not Complete*/
static void ErrWarning_ErrorDiveNotComplete_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_LASTDIVE);
}
const contentDispContext_st ErrWarning_ErrorDiveNotComplete =
{
    &ErrWarning_ErrorDiveNotComplete_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error Dive Over 10 Hours*/
static void ErrWarning_ErrorDiveOver10Hours_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_10HR);
}
const contentDispContext_st ErrWarning_ErrorDiveOver10Hours =
{
    &ErrWarning_ErrorDiveOver10Hours_Ctx,
    &WHITE_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Battery too low to operate*/
static void ErrWarning_BattTooLow_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BATTERY_TOO_LOW));
}
const contentDispContext_st ErrWarning_BatteryTooLow_00 =
{
    &ErrWarning_BattTooLow_00_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
static void ErrWarning_BattTooLow_01_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TO_OPERATE));
}
const contentDispContext_st ErrWarning_BatteryTooLow_01 =
{
    &ErrWarning_BattTooLow_01_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Bluetooth failed*/
static void ErrWarning_BluetoothFail_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BLUETOOTH));
}
const contentDispContext_st ErrWarning_BluetoothFail_00 =
{
    &ErrWarning_BluetoothFail_00_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
static void ErrWarning_BluetoothFail_01_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_FAILED));
}
const contentDispContext_st ErrWarning_BluetoothFail_01 =
{
    &ErrWarning_BluetoothFail_01_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error compass failed*/
static void ErrWarning_CompassError_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_COMPASS));
}
const contentDispContext_st ErrWarning_CompassError_00 =
{
    &ErrWarning_CompassError_00_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
static void ErrWarning_CompassError_01_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_FAILED));
}
const contentDispContext_st ErrWarning_CompassError_01 =
{
    &ErrWarning_CompassError_01_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error compass failed*/
static void ErrWarning_GPSFailed_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GPS));
}
const contentDispContext_st ErrWarning_GPSFailed_00 =
{
    &ErrWarning_GPSFailed_00_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
const contentDispContext_st ErrWarning_GPSFailed_01 =
{
    &ErrWarning_CompassError_01_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/*Error Altitude*/
static void ErrWarning_ErrorAltitude_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ErrorAltitude_2)); //"ALTITUDE"
}
const contentDispContext_st ErrWarning_ErrorAltitude_00 =
{
    &ErrWarning_ErrorAltitude_00_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
static void ErrWarning_ErrorAltitude_01_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LIMIT));
}
const contentDispContext_st ErrWarning_ErrorAltitude_01 =
{
    &ErrWarning_ErrorAltitude_01_Ctx,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief SYSTEM ERROR text
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_00_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SYSTEM_ERROR));
}
const contentDispContext_st SystemErrorMsg_00 =
{
    &SystemErrorMsg_00_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_NotYetCalib_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_CALIBRATION);
}
const contentDispContext_st SystemErrorMsg_NotYetCalib =
{
    &SystemErrorMsg_NotYetCalib_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_ADC_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_ADC);
}
const contentDispContext_st SystemErrorMsg_ADC =
{
    &SystemErrorMsg_ADC_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_TempSensor_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_TEMPSENSOR);
}
const contentDispContext_st SystemErrorMsg_TempSensor =
{
    &SystemErrorMsg_TempSensor_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_VoltSensor_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_VOLTSENSOR);
}
const contentDispContext_st SystemErrorMsg_VoltSensor =
{
    &SystemErrorMsg_VoltSensor_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_TickTime_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_TICKTIME);
}
const contentDispContext_st SystemErrorMsg_TickTime =
{
    &SystemErrorMsg_TickTime_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_Button_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_BUTTON);
}
const contentDispContext_st SystemErrorMsg_Button =
{
    &SystemErrorMsg_Button_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_Altitude_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_ALTITUDE);
}
const contentDispContext_st SystemErrorMsg_Altitude =
{
    &SystemErrorMsg_Altitude_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_Compass_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_COMPASS);
}
const contentDispContext_st SystemErrorMsg_Compass =
{
    &SystemErrorMsg_Compass_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_FuelGauge_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_FUELGAUGE);
}
const contentDispContext_st SystemErrorMsg_FuelGauge =
{
    &SystemErrorMsg_FuelGauge_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_Receiver_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_RECEIVER);
}
const contentDispContext_st SystemErrorMsg_Receiver =
{
    &SystemErrorMsg_Receiver_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_GPS_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_GPS);
}
const contentDispContext_st SystemErrorMsg_GPS =
{
    &SystemErrorMsg_GPS_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief 
 * 
 * @param pStrRet 
 */
static void SystemErrorMsg_O2Sensor_Ctx(char *pStrRet)
{
    sprintf(pStrRet, "%d", SYSERR_O2SENSOR);
}
const contentDispContext_st SystemErrorMsg_O2Sensor =
{
    &SystemErrorMsg_O2Sensor_Ctx,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};
/**
 * @brief PLEASE USING APP TO ACTIVATE
 * 
 * @param pStrRet 
 */
static void PopUpWarning_PleaseUseAppToActive01_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MY_INFO_1));
}
const contentDispContext_st PopUpWarning_PleaseUseAppToActive01 =
{
    &PopUpWarning_PleaseUseAppToActive01_Ctx,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0,
};
static void PopUpWarning_PleaseUseAppToActive02_Ctx(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TO_ACTIVATE));
}
const contentDispContext_st PopUpWarning_PleaseUseAppToActive02 =
{
    &PopUpWarning_PleaseUseAppToActive02_Ctx,
    &GREEN_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1,
};