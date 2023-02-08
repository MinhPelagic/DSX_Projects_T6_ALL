/*******************************************************************************
 * @file        : Slates.h
 * @brief       : Middleware for Slates Readback and Display
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2021-2021.
 * Author: YeuShyr - Pelagic Pressure Systems, Aqualung
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
 
#ifndef _SLATES_H_
#define _SLATES_H_

#define SLATE_W                 (320U)                              //Width
#define SLATE_H                 (190U)                              //Height
#define SLATE_PIXEL_SIZE        (SLATE_W*SLATE_H)                   //Size of slate picture
#define SLATE_ADDR_HEAD         ((uint32_t)0x11000000)              //Slate #1
#define SLATE_DATA_SIZE         ((uint32_t)(SLATE_PIXEL_SIZE*2U))   //Number of bytes (16bits/pixel)
#define SLATE_ADDR_GAP          ((uint32_t)(128U*1024U))            //Mobile application defined
/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/



/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/



/******************************************************************************
 * @brief   Handle Ecompass.
 *
 * @note    
 ******************************************************************************/
bool EcHandler (void);

/******************************************************************************
 * @brief   Calculate Heading
 *
 * @note    
 ******************************************************************************/


#endif
