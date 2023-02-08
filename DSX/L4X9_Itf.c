/*******************************************************************************
 * @file        : L4X9_ITF.c
 * @brief       : Data Structures Interface File
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

#include "L4X9_Includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _DSXTF_H_

/* Includes ------------------------------------------------------------------*/
const Dive_Info_struct_t *GetDiveInfo(void);

/* Linker to expose Dive Info in read only mode*/
const Dive_Info_struct_t *GetDiveInfo(void)
{
    return &Dive_Info;
}

/* Linker to expose TP Info in read only mode*/
const TP_Info_struct_t *GetTPInfo(void)
{
    return &TP_Info;
}

/* Linker to expose System Supply Info in read only mode*/
const L4X9_SystemSupplyMonitor_t *GetSystemSupplyMonitor(void)
{
    return &SystemSupplyMonitor;
}


/* Linker to expose System Time Info in read only mode*/
const SystemTimeDate_t *GetPstTime(void)
{
    return &SysTimeDatePST;
}


/* Linker to expose Home Time Info in read only mode*/
const SystemTimeDate_t *GetHomeTime(void)
{
    SysTimeDateHOME = GetDiffTime(USER_Set.HomeTZhrdiff, USER_Set.HomeTZmindiff);
    
    return &SysTimeDateHOME;     //return &Home;
}



/* Linker to expose Manufactuerer Calibration Record in read only mode*/
const Mfg_Calibration_t *GetMFG_Calib(void)
{
    return &MFG_Calib;
}


/* Linker to expose Device Record in read only mode*/
const Device_Records_t *GetDEV_Rec(void)
{
    return &DEV_Rec;
}


/* Linker to expose Device Record in read only mode*/
const User_Settings_t *GetUSER_Set(void)
{
    return &USER_Set;
}


/* Linker to expose Dive Settings in read only mode*/
const Scuba_Settings_t *GetSCUBA_Set(void)
{
    return &SCUBA_Set;
}


/* Linker to expose TRIMIX Settings in read only mode*/
const TRIMIX_Settings_t *GetTRIMIX_Set(void)
{
    return &TRIMIX_Set;
}



/* Linker to expose Log Data in read only mode*/
const LOG_Data_t *GetLOG_Data(void)
{
    return &Log_Data;
}


/* Linker to expose My Info in read only mode*/
const FLASH_Map_t *GetFLASH_Map(void)
{
    return &FLASH_Map;
}


#endif


