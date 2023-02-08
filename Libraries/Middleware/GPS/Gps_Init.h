
#ifndef __GPS_INIT_H
#define __GPS_INIT_H
/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "usart.h"

extern char GpsPowerStatus;
void InitGps(void);
uint8_t Gps_Power_OnOff(uint8_t on_off);
void GpsChangePowerMode(uint8_t mode);
void Get_Lat_Long(void);
void GpsStartStopContineousLat_Long(uint8_t Gps_start_stop);

#define GPS_PW_CTRL_Pin GPIO_PIN_2
#define GPS_PW_CTRL_GPIO_Port GPIOI
#define GPS_RST_2_8_Pin GPIO_PIN_1
#define GPS_RST_2_8_GPIO_Port GPIOI
#define TP9_DEBUG_TX_Pin GPIO_PIN_10
#define TP9_DEBUG_TX_GPIO_Port GPIOC
#define GPS_TX_USART1_RX_2_8V_Pin GPIO_PIN_10
#define GPS_TX_USART1_RX_2_8V_GPIO_Port GPIOA
#define TP16_DEBUG_RX_Pin GPIO_PIN_11
#define TP16_DEBUG_RX_GPIO_Port GPIOC
#define GPS_RX_USART1_TX_2_8V_Pin GPIO_PIN_9
#define GPS_RX_USART1_TX_2_8V_GPIO_Port GPIOA

#endif
