/*******************************************************************************
 * @file        : Tick_Handler_3.c
 * @brief       : This file contains all Tick handler functions.
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

/* Tick 3 Handler */
void L4X9_TickHandler_3(void)
{
  /* Please insert here your code for Tick 3 processing */
  Check_For_Deco();
  // Leave this Tick empty, only for an extention of previous Tick  
  
  /* Moved from Tick0 to here after R1006, because Tick0 is very busy doing many other tasks */
  SystemStatus.NVD_EE_W_flag0 = NVD_Process_RAMBLOCK_to_ExtEEPROM(SystemStatus.NVD_EE_W_flag0);
}