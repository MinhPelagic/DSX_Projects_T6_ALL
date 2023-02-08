/*******************************************************************************
 * @file        : Backlight.h
 * @brief       : Low Level Driver for Backlight Chip TPS61165DBV
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

#ifndef _BACKLIGHT_H_
#define _BACKLIGHT_H_

#define BACKLIGHT_ON    2
#define BACKLIGHT_DIM   1
#define BACKLIGHT_OFF   0

/******************************************************************************
 * @brief   Initialize Backlight Driver
 *
 * @note
 *
 ******************************************************************************/
void Backlight_Init( void );

/******************************************************************************
 * @brief   Set Backlight Level
 *
 * @note
 *
 ******************************************************************************/
void Backlight_Set( uint8_t level );
uint8_t AutoBackLight(float lux);
extern uint8_t Backlight_Val;                  // current Backlight Percentage Level, returned from Backlight_Set()
extern uint8_t ButtonNoResponseCnt;      // 0: no delay;  1: delay Menu /Data for one more button pushing
#endif // _BACKLIGHT_H_