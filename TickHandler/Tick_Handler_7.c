/*******************************************************************************
 * @file        : Tick_Handler_7.c
 * @brief       : This file contains Tick_7 manager handling:
 *                - USB related functions
 *                - BT related functions
 *                
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

/* Tick 7 Handler */
void L4X9_TickHandler_7(void)
{
  /* Please insert here your code for Tick 7 processing */
  Check_For_Deco();
  
  BestGasNumber = FindBestGas(fDepthFt, &BestGasPO2);
    
  // Leave this Tick empty, only for an extention of previous Tick
  VariableBoundaryCheck();
  
  // Backlight Manager 
  // BacklightManager();
  //if(SystemStatus.BLE_status < BLE_HDL_CONNECT)
  //  BacklightManager();
}

