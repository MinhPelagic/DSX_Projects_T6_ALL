/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"
#include "stm32l4xx_hal.h"
//#include "usart.h"
#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include "GpsCmdProtocol.h"
#include "GpsHeaderFile.h"

char Gps_Power_Mode[50];
char GetGpsSingleCordinates=0;
char GpsSingleCordinatesCount=0;

char GpsContineousMode(uint8_t mode,uint16_t interval)
{
	if (mode>1 || interval>600)
		return -1;
	Gps_Power_OnOff(1);
	HAL_Delay(1000);
	SendCommandToGps(GPS_SET_BSSL_GGA);
	HAL_Delay(1000);

	if(mode)
		sprintf(Gps_Power_Mode,"@GSOP %d %d %d\r\n",1,interval*1000,0);
	else
		sprintf(Gps_Power_Mode,"@GSOP %d %d %d\r\n",2,interval*1000,0);

	SendCommandToGps(Gps_Power_Mode);

	HAL_Delay(1000);
	SendCommandToGps(GPS_COLD_START);
	HAL_Delay(1000);
	return 0;
}

char  GpsSingleLock(void)
{
	GetGpsSingleCordinates=1;
	Gps_Power_OnOff(1);
	HAL_Delay(1);   //HAL_Delay(1000);
	SendCommandToGps(GPS_SET_BSSL_GGA);
	HAL_Delay(1);   //HAL_Delay(1000);
	SendCommandToGps(GPS_SET_GSOP);
	HAL_Delay(1);   //HAL_Delay(1000);
	SendCommandToGps(GPS_COLD_START);
	HAL_Delay(1);   //HAL_Delay(1000);
	return 0;
}
uint8_t GetGpsDataAccuracy (void)
{
	return NoOfSatellites_used;
}
    
void GpsMonitor(void)
{
	if(BT_DataRxFlag == 1)
	{
		ProcessInput();
		BT_DataRxFlag = 0;
	}
	if (CurCommandPtr != MaxCommandPtr)
		BTNotificationEvent();
}
