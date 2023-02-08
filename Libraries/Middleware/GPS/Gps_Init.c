/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "Gps_Init.h"
#include "GpsHeaderFile.h"
//#include "usart.h"
#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

void Gps_Power_Ctrl(void);
void Gps_Reset(void);

char GpsPowerStatus=0;

void InitGps(void)
{
	Gps_Power_Ctrl();
	ms_delay(1000);   //HAL_Delay(1000);
	Gps_Reset();
	ms_delay(2000);   //HAL_Delay(2000);
	SendCommandToGps(GPS_SET_BSSL_GGA);
	ms_delay(1000);   //HAL_Delay(1000);
	SendCommandToGps(GPS_SET_GSOP);
	ms_delay(1000);   //HAL_Delay(1000);
	GpsStartStopContineousLat_Long(1);

}
void Gps_Power_Ctrl(void)
{
	HAL_GPIO_WritePin(GPS_PW_CTRL_GPIO_Port,GPS_PW_CTRL_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPS_PW_CTRL_GPIO_Port,GPS_PW_CTRL_Pin, GPIO_PIN_SET);
}
void Gps_Reset(void)
{
	  HAL_GPIO_WritePin(GPS_RST_2_8_GPIO_Port, GPS_RST_2_8_Pin, GPIO_PIN_RESET);
	  HAL_Delay(1000);
	  HAL_GPIO_WritePin(GPS_RST_2_8_GPIO_Port, GPS_RST_2_8_Pin, GPIO_PIN_SET);
}
uint8_t Gps_Power_OnOff(uint8_t on_off)
{
	if(!on_off)
	{
		HAL_GPIO_WritePin(GPS_PW_CTRL_GPIO_Port,GPS_PW_CTRL_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPS_PW_CTRL_GPIO_Port, GPS_PW_CTRL_Pin, GPIO_PIN_RESET);
		GpsPowerStatus=0;
	}
	if(on_off==1)
	{
		Gps_Power_Ctrl();
		HAL_Delay(1000);
		Gps_Reset();
		HAL_Delay(1000);
		SendCommandToGps(GPS_SET_SLEEP_2);
		GpsPowerStatus=1;
	}
	if(on_off==2)
	{
		Gps_Power_Ctrl();
		HAL_Delay(1000);
		Gps_Reset();
		HAL_Delay(1000);
		SendCommandToGps(GPS_SET_BSSL_GGA);
		HAL_Delay(1000);
		SendCommandToGps(GPS_SET_GSOP);
		HAL_Delay(1000);
		GpsPowerStatus=1;
	}
	return 0;
}
void GpsChangePowerMode(uint8_t mode)
{

}

void GpsStartStopContineousLat_Long(uint8_t Gps_start_stop)
{
	if(Gps_start_stop)
		SendCommandToGps(GPS_COLD_START);
	else
		SendCommandToGps(GPS_SET_STOP_GSTP);
}


