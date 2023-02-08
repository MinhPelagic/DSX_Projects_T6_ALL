/*******************************************************************************
 * @file        : L4X9_SystemTest.h
 * @brief       : MCU initilitation and miscellaneous RTOS routines.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: YeuShyr Wu - Pelagic Pressure Systems / Aqua Lung
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _L4X9_SYSTEMTEST_H_
#define _L4X9_SYSTEMTEST_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/* Global variable used in all PRTOS delay functions */


/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

typedef enum 
{
  HW_SYS_BUTTON_TEST = 0,
  HW_SYS_BUZZER_TEST,
  HW_SYS_EXFLASH_TEST,
  HW_SYS_EEPROM_TEST,
  HW_SYS_USB_TEST,
  HW_SYS_BLE_TEST,
  HW_SYS_SPI_TEST,
  HW_SYS_I2C_TEST,
  HW_SYS_UART_TEST,
  HW_SYS_MAX
} HW_SYS_t;


/******************************************************************************
 * @brief   Initializes the NVIC.
 *
 * @note
 ******************************************************************************/

extern uint8_t HW_SelfTestProgress[];



#endif //_L4X9_SYSTEMTEST_H_