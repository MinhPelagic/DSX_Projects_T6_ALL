/*******************************************************************************
 * @file        : CXD5605GF.h
 * @brief       : Low Level Driver for Sony GNSS.
 *                Driver is implemented on UART 1                 
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *      Reimplementation of Avinash Kumar example code, for Pelagic system integration.
 ******************************************************************************/

#ifndef _CXD5605GF_H_
#define _CXD5605GF_H_

#define CXD5605GF_MAX_COMBUF_MAX        4832    // 8192+640 for rollover extra 640 (512+extra)
#define CXD5605GF_MAX_COMBUF            4192

extern UART_HandleTypeDef GnssUartHandle;

extern char Cxd5605gfComBuf[CXD5605GF_MAX_COMBUF_MAX];
extern uint16_t Cxd5605gfMaxComBuf;

extern bool FwUpdateMode;


// Initialize GPIO. At system start up the GNSS chip is off.
// To be called after system reset in main.c
void CXD5605GF_Init(void);

// Switches On the GNSS chip and configures the UART
void CXD5605GF_On(void);

// Switches OFF the GNSS chip, UART and reinit the GPIO for low power
void CXD5605GF_Off(void);

// Reset the GNSS chip,
void CXD5605GF_Reset(void);

// To be called before StopMode0/1
void CXD5605GF_StopModeEnter (void);

// To be called after StopMode0/1 exit
void CXD5605GF_StopModeExit (void);

#endif // _CXD5605GF_H_