/*******************************************************************************
 * @file        : MAX77950.h
 * @brief       : Low Level Driver for MAX77950 WPC/PMA Dual Mode Wirless 
 *                Power Receiver
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The MAX77950 driver is build on the I2C system bus.
 *
 ******************************************************************************/

#ifndef _MAX77950_H_
#define _MAX77950_H_

/*******************************************************************************
 * @brief
 *   Initialize Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX77950_Init( void );

   
/*******************************************************************************
 * @brief
 *   Enable Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
void MAX77950_Enable( void );

   /*******************************************************************************
 * @brief
 *   Disable Wireless Power Rx Chip.
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
void MAX77950_Disable( void );

/*******************************************************************************
 * @brief
 *   Check if Wireless Power is beeing received.
 *
 * @note
 *
 * @return
 *	true : if power transfer in progress
 *	false : if no power is transferred
 ******************************************************************************/
bool MAX77950_IsPowerDetected( void );

#endif // _MAX77950_H_