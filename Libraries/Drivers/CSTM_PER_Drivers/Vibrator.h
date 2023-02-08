/*******************************************************************************
 * @file        : Vibrator.h
 * @brief       : Low Level Driver for Vibrator.
 *                Driver is implemented for use with TIM8 Ch-1
 *                (please manage OS to not enter STOP MODE 2 while on)                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

#ifndef _VIBRATOR_H_
#define _VIBRATOR_H_

/******************************************************************************
 * @brief   Initialize Vibrator Driver
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_Init( uint32_t frequencyHz, uint32_t dutyPercent );

/******************************************************************************
 * @brief   Start Vibrator Beep
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_On( void );

/******************************************************************************
 * @brief   Stop Vibrator Beep
 *
 * @note
 *
 ******************************************************************************/
void Vibrator_Off( void );

#endif // _VIBRATOR_H_