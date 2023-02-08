/* Standard Includes ---------------------------------------------------------*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* MCU HAL Driver Includes ---------------------------------------------------*/
/* Uncomment Module HAL Driver Defines in stm32l4xx_hal_conf.h */
#include "stm32l4xx_hal.h"

/* MCU LL Driver Includes ----------------------------------------------------*/
#include "stm32l4xx.h"
#include "stm32l4xx_ll_rcc.h"
#include "stm32l4xx_ll_gpio.h"
#include "stm32l4xx_ll_exti.h"
#include "stm32l4xx_ll_pwr.h"
#include "stm32l4xx_ll_rtc.h"
#include "stm32l4xx_ll_fmc.h"
#include "stm32l4xx_ll_dma.h"
#include "stm32l4xx_ll_usart.h"
#include "stm32l4xx_ll_lpuart.h"

/* Board HAL Includes --------------------------------------------------------*/
#if defined ( BUILD_DSX )
  #include "L4X9_hal.h"
  #include "L4X9_Device.h"
  #include "DSX_Version.h"
  #include "L4X9_SystemTest.h"
#else
  #error No Build defined
#endif

/* MCU CSTM Driver Includes --------------------------------------------------*/
#include "STM32L4_MCU_LPUART.h"

/* Peripherals CSTM Driver Includes ------------------------------------------*/

#include "Backlight.h"
#include "Buzzer.h"
#include "Vibrator.h"

#if defined ( USE_MT25QL512ABB ) && ( USE_MT25QL512ABB )
  #include "MT25QL512ABB.h"
#endif

#if defined ( USE_EE24CWxxX ) && ( USE_EE24CWxxX )
  #include "24CWxxX.h"
#endif

#if defined ( USE_MS5837_30BA ) && ( USE_MS5837_30BA )
  #include "MS5837_30BA.h"
#endif

#if defined ( USE_LSM303AGR ) && ( USE_LSM303AGR )
  #include "LSM303AGR.h"
#endif

#if defined ( USE_MAX77950 ) && ( USE_MAX77950 )
  #include "MAX77950.h"
#endif

#if defined ( USE_MAX17262 ) && ( USE_MAX17262 )
  #include "MAX17262.h"
#endif

#if defined ( USE_LCD_COM24H2P39ULC ) && ( USE_LCD_COM24H2P39ULC )
  #include "LCD_COM24H2P39ULC.h"
#endif

#if defined ( USE_CXD5605GF ) && ( USE_CXD5605GF )
  #include "CXD5605GF.h"
#endif

/* Test Routines Includes ----------------------------------------------------*/

/* RTOS and MCU support Includes ---------------------------------------------*/
#include "main.h"
#include "FwUpdate.h"
#include "TimeDate.h"
#include "motion_mc.h"
#include "motion_ec.h"
#include "ECompass.h"
#include "L4X9_misc.h"
#include "L4X9_ble.h"
#include "L4X9_utils.h"
#include "L4X9_NVData.h"
#include "Ambiental.h"
#include "Tick_Handler.h"
#include "app.h"
#include "Gnss.h"
#include "WayFinder.h"
#include "GPS_WayFinder.h"

#if defined ( BUILD_DSX )
  #include "L4X9_Itf.h"
  #include "DsxOCDefine.h"
  #include "DSX_ButtonHandle.h"
  #include "DSX_Data_Process.h"
  #include "CCOC_DiveAlgo.h"
  #include "DSX_WarnsAlarms.h"
#else
  #error No Build defined
#endif

/* Middlewares Includes ------------------------------------------------------*/
#include "GUI.h"
#include "WM.h"
#include "Icon_DSX.h"
#include "TxtStr_Order_DSX.h"
#include "DSX_Data_Decode.h"
#include "ShapeDSX.h"
#include "DSX_Coordinate.h"
#include "DSX_Data_Process.h"
#include "DSX_FontStruct.h"
#include "Text_DSX.h"
#include "OC_DSX.h"
#include "DsxOCDefine.h"
#include "DsxOcConfig.h"
#include "O2.h"
#include "Receiver.h"
#include "TMT_Receiver.h"
#include "Slates.h"
