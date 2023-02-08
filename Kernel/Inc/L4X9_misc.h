/*******************************************************************************
 * @file        : L4X9_misc.h
 * @brief       : MCU initilitation and miscellaneous routines.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _L4X9_MISC_H_
#define _L4X9_MISC_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/* Global variable used in all PRTOS delay functions */
extern volatile bool delay_enabled;

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/
#define SYSTICK_MAX_LOAD                (0x00FFFFFF)

#define RTC_REF_CALIBRATION_PERIOD      2629800 // Average month duration in seconds 365days x 24hrs x 60 min. + 360 min (extra per year) = 525960 min/yr; 25960min./12 mo = 43830min. / month


/******************************************************************************
 * @brief   Initializes the NVIC.
 *
 * @note
 ******************************************************************************/
void L4X9_NVICInit(void);

/******************************************************************************
 * @brief   Initializes the MCU FLASH.
 *
 * @note
 ******************************************************************************/
void L4X9_FlashInit(void);

/******************************************************************************
 * @brief   Initializes the System Clock as defined in the XXX_hal.h.
 *
 * @note    
 ******************************************************************************/
void L4X9_SystemClockInit(void);

/******************************************************************************
 * @brief   Initializes the Independant WatchDog.
 *
 * @note    The WatchDog is feed with LSI clock source and is internally
 *          precaled by 256. This means that it counts 125 ticks per second.
 ******************************************************************************/
void L4X9_WatchDogInit(void);

/******************************************************************************
 * @brief   Reloads the Independant WatchDog.
 *
 * @note
 ******************************************************************************/
void L4X9_WatchDogReload(void);

/******************************************************************************
 * @brief   Initializes the Stop Mode.
 *          Set the SCB->SCR Cortex-M4 to enter deepsleep mode.
 *
 * @note    Call just at upon Reset or PowerOn, or if some of the following 
 *          configuration has been changed during application execution.   
 ******************************************************************************/
void L4X9_StopModeInit(void);

/******************************************************************************
 * @brief   Enter Stop Mode 1 in WFI mode and restores the System clock 
 *          configuration according to XXX_hal.h.
 *
 * @note    
 ******************************************************************************/
void L4X9_StopMode1Enter(void);

/******************************************************************************
 * @brief   Enter Stop Mode 2 in WFI mode and restores the System clock 
 *          configuration according to XXX_hal.h.
 *
 * @note    
 ******************************************************************************/
void L4X9_StopMode2Enter(void);

/******************************************************************************
 * @brief   Initializes the GPIO as defined in the XXX_hal.h 
 *
 * @note    
 ******************************************************************************/
void L4X9_GpioInit(void);

/******************************************************************************
 * @brief   RTC Initilization routine.
 *          Enables the RTC module.
 *          Initilize the RTC module with selected format and Sync/Async 
 *          Prescaler settings.
 *          Sets default time and date.
 *
 * @note    
 *          LSE must be already enabled.
 *          Backup restore not implemented.
 *          RTCSEL, RTCEN, LSEON, LSEBYP in RCC are write protected. (see RM0351 p.272)
 ******************************************************************************/
void L4X9_RTCInit(void);

/******************************************************************************
 * @brief   Calibrate Rtc
 *
 * @note    Requires as input the Seconds per Month to be add/subtract. 
 *          Month duration is 2629800 seconds
 ******************************************************************************/
void L4X9_CalRtc (int16_t SecondsPerMonth, uint8_t sign);

/******************************************************************************
 * @brief   Set Rtc Time
 *
 * @note    
 ******************************************************************************/
void L4X9_SetRtc (SystemTimeDate_t time);

/******************************************************************************
 * @brief   RTC WakeUp Interrupt Initilization routine.
 *
 * @note    Must be called after STM32L4xx_RTCInit(void).
 *          Backup restore not implemented.
 ******************************************************************************/
void L4X9_RTC_WKU_INT_Init(void);

/******************************************************************************
 * @brief   I2C_2 System Bus Initilization
 *
 * @note        
 *              
 ******************************************************************************/
void L4X9_I2C_Init(void);

/******************************************************************************
 * @brief   SPI HW Setup.
 *
 * @note        
 *              
 ******************************************************************************/
void L4X9_QSPI_Init(void);

/******************************************************************************
 * @brief   SPI HW Detach.
 *
 * @note        
 *              
 ******************************************************************************/
void L4X9_QSPI_DeInit(void);

/******************************************************************************
 * @brief   Button Initilization routine.
 *          Initilize Port Pins as Input and Pull-Up.
 *          Activates the Interrupt on the EXTI Lines, on falling edge.
 *
 * @note    
 *          
 ******************************************************************************/
void L4X9_ButtonInit(void);

/******************************************************************************
 * @brief Low Power Millisecond Delay Blocking Function 
 *        This function is build up on the RTC Alarm A module.
 *        This function enters Stop mode, so do not use it if HF peripherals 
 *        must be on.
 *
 * @note
 *
 * @param[in]
 *      uint32_t count : number of milliseconds to wait. Max Value: 999
 *
 ******************************************************************************/
void ms_LP_delay (uint32_t count);

/******************************************************************************
 * @brief Millisecond Delay Blocking Function
 *
 * @note
 *  Uses the SysTick of Cortex-M4 module.
 *  For very low Clock speed may have less accuracy.
 *  Max value of ticks to be load in LOAD register is 0x00FFFFFF.
 *
 * @param[in]
 *      uint32_t count : number of milliseconds to wait. Max Value: 0xFFFFFFFF
 *
 ******************************************************************************/
void ms_delay (int32_t count);

/******************************************************************************
 * @brief Microsecond Delay Blocking Function
 *
 * @note
 *  Uses the SysTick of Cortex-M4 module.
 *  For very low Clock speed may have less accuracy.
 *
 * @param[in]
 *      uint32_t count : number of microseconds to wait. Max Value depends on 
 *                       SystemCoreClock. However if too high will be rounded to
 *                       SYSTICK_MAX_LOAD.
 *
 ******************************************************************************/
void us_delay (uint32_t count);

/******************************************************************************
 * @brief A test logic to switch system between Dev Board or Production Board
 *
 * @note
 * 
 *      0: Production Board
 *
 *      1: Development Board
 * 
 ******************************************************************************/
bool DEV_Board(void);

/******************************************************************************
 * @brief A test logic to check if system in charging by cable
 *
 * @note
 * 
 *      0: Charging Cable NOT connected
 *
 *      1: Charging Cable connected
 * 
 ******************************************************************************/
bool CableCharging(void);

/******************************************************************************************
 * @brief A test logic to check if system in charging either by cable or wireless charging
 *
 * @note
 * 
 *      0: Battery NOT in Charging: Both Charging Cable and Wireless Charging are OFF
 *
 *      1: Battery in Charging: Either Charging Cable or Wireless Charging is ON
 * 
 ******************************************************************************************/
bool BatteryCharging(void);

/******************************************************************************************
 *
 * @brief       bool ShowChargingAfterNSec(int32_t n)
 * 
 * @note        0: User action time still NOT elapes long enough
 *
 *              1: User action elapes time long enough
 * 
 ******************************************************************************************/
bool ShowChargingAfterNSec(int32_t);

/******************************************************************************************
 *
 * @brief       bool ShowChargingDelayedForNSec(int32_t n)
 * 
 * @note        0: No more delay, nor waiting 
 *
 *              1: User action time in delay, keep waiting 
 * 
 ******************************************************************************************/
bool ShowChargingDelayedForNSec(int32_t);

/******************************************************************************************
 * @brief A routine check on all around variables to assure values not out of range
 *
 * @note     VariableBoundaryCheck(void)           
 * 
 ******************************************************************************************/
void VariableBoundaryCheck(void);

/******************************************************************************************
 * @brief The routines to set TPn High or Low
 *
 * @note     void TPn_High(uint8_t n) and void TPn_Low(uint8_t n)           
 * 
 ******************************************************************************************/
void TPn_High(uint8_t n);
void TPn_Low(uint8_t n);

/*******************************************************************************

    Generic data swapping subroutine

    SwapUint8(uint8_t *x, uint8_t *y);

*******************************************************************************/
void SwapUint8(uint8_t *x, uint8_t *y);

#endif //_L4X9_MISC_H_