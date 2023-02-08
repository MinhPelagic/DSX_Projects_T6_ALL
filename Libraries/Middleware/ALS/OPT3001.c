/*
 * OPT3001.c
 *
 *  Created on: 02-Aug-2021
 *      Author: Arshadev
 */
/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "OPT3001.h"
#include "i2c2.h"
//#include "DEBUG_TX.h"

#include <stdio.h>

/* Private define ------------------------------------------------------------*/
#define OPT3001_I2C             I2C_BUS_A
#define OPT3001_I2C_ADDR        0x8A

#define OPT3001_RESULT_REG 0x00
#define OPT3001_CONFIG_REG 0x01
#define OPT3001_LOWLIMIT_REG 0x02
#define OPT3001_HIGHLIMIT_REG 0x03
#define OPT3001_MANUFACTUREID_REG 0x7E
#define OPT3001_DEVICEID_REG 0x7F


/* Private function prototypes -----------------------------------------------*/
static bool     OPT3001_writeRegister(uint8_t registerName, uint16_t value);
static uint16_t OPT3001_readRegister(uint8_t registerName);
static void 	OPT3001_Error_handler(void);

char Tx_Buffer[50];

/* Private user code ---------------------------------------------------------*/
uint8_t	OPT3001_Test(void)
{
	//Log_Write("OPT3001_Test");
	OPT3001_int(DEFAULT_CONFIG_800);

	//uint16_t ManufacturerId = OPT3001_readManufacturerId();
	//sprintf(Tx_Buffer,"OPT3001 ManufacturerId %x",ManufacturerId);
	//Log_Write(Tx_Buffer);

	//uint16_t DeviceId = OPT3001_readDeviceId();
	//sprintf(Tx_Buffer,"OPT3001 DeviceId %x",DeviceId);
	//Log_Write(Tx_Buffer);

	//uint16_t ConfigReg = OPT3001_readConfigReg();
	//sprintf(Tx_Buffer,"OPT3001 ConfigReg %x",ConfigReg);
	//Log_Write(Tx_Buffer);

	//uint16_t LowLimitReg = OPT3001_readLowLimitReg();
	//sprintf(Tx_Buffer,"OPT3001 LowLimitReg %x",LowLimitReg);
	//Log_Write(Tx_Buffer);

	//uint16_t HighLimitReg = OPT3001_readHighLimitReg();
	//sprintf(Tx_Buffer,"OPT3001 HighLimitReg %x",HighLimitReg);
	//Log_Write(Tx_Buffer);

	//uint16_t Ready = OPT3001_isConversionReady();
	//sprintf(Tx_Buffer,"OPT3001 Ready %x",Ready);
	//Log_Write(Tx_Buffer);

	//float Result = OPT3001_readResult();
	//sprintf(Tx_Buffer,"OPT3001 Result %f",Result);
	//Log_Write(Tx_Buffer);

/*
	while(1)
	{
		//HAL_Delay(500);
		ms_delay(500);
		float Intensity;
		if(GetLightIntensity(&Intensity))
		{
			sprintf(Tx_Buffer,"OPT3001 Intensity %f",Intensity);
			//Log_Write(Tx_Buffer);
		}
	}

*/	
	return(0);
}

uint8_t GetLightIntensity(float* Intensity)
{
	OPT3001_startConversion();
	//ms_delay(10);
	//delay_cnt(0xFFFF);

	//while(!OPT3001_isConversionReady()){

	//}
	//*Intensity = OPT3001_readResult();

	
	//for(int i=0;i<1000;i++)
	for(int i=0;i<100;i++)
	{
		uint8_t Ready = OPT3001_isConversionReady();
		if(Ready==1)
		{
			*Intensity = OPT3001_readResult();
			return(1);
		}
		
		//HAL_Delay(1);
		//ms_delay(5);  
	}
	*Intensity = 999;
	return(0);
}


bool OPT3001_int(int16_t config)
{
	return OPT3001_writeRegister(OPT3001_CONFIG_REG, config);
}

uint16_t OPT3001_readManufacturerId(void)
{
	return(OPT3001_readRegister(OPT3001_MANUFACTUREID_REG));
}

uint16_t OPT3001_readDeviceId(void)
{
	return(OPT3001_readRegister(OPT3001_DEVICEID_REG));
}

uint16_t OPT3001_readConfigReg(void)
{
	return(OPT3001_readRegister(OPT3001_CONFIG_REG));
}

uint16_t OPT3001_readLowLimitReg(void)
{
	return(OPT3001_readRegister(OPT3001_LOWLIMIT_REG));
}

uint16_t OPT3001_readHighLimitReg(void)
{
	return(OPT3001_readRegister(OPT3001_HIGHLIMIT_REG));
}


//range: 0.01 lux to 83 k lux
uint32_t OPT3001_readResult(void)
{
    uint32_t U32_Raw;
    uint16_t raw = OPT3001_readRegister(OPT3001_RESULT_REG);
    
    U32_Raw = (((uint32_t)(raw & 0x0fff)) << ((raw & 0xf000) >> 12));
        
    return U32_Raw;
}

uint8_t  OPT3001_isConversionReady(void)
{
	return (OPT3001_readConfigReg() & OPT3001_CFG_CRF ? 1 : 0);
}

bool  OPT3001_startConversion(void)
{
	return OPT3001_int(DEFAULT_CONFIG_100);
	
}

void OPT3001_shutDown(void)
{
	OPT3001_int(DEFAULT_CONFIG_SHDWN);
}

static bool OPT3001_writeRegister(uint8_t registerName, uint16_t value)
{
    uint8_t reg[2];
    int32_t retry = 10;
    
    reg[0]=(uint8_t)(value >> 8);
    reg[1]=(uint8_t)(value & 0x00FF);

    if(HAL_I2C_IsDeviceReady(&OPT3001_I2C, OPT3001_I2C_ADDR, 1, 10000) == HAL_OK)
    {
        do{} while ( (HAL_I2C_Mem_Write(&OPT3001_I2C, OPT3001_I2C_ADDR, registerName, 1, (uint8_t*)reg, 2, 100) != HAL_OK)  && (retry-- > 0) );
        if(retry <= 0)
        {
            OPT3001_Error_handler();
            return false;
        }
        return true;
    }
    return false;
}
static uint16_t OPT3001_readRegister(uint8_t registerName)
{
    uint8_t reg[2];
    int32_t retry = 3;
    
    if(HAL_I2C_IsDeviceReady(&OPT3001_I2C, OPT3001_I2C_ADDR, 1, 10000) == HAL_OK)
    {
        do{} while ( (HAL_I2C_Mem_Read(&OPT3001_I2C, OPT3001_I2C_ADDR, registerName, 1, (uint8_t*)reg, 2, 100) != HAL_OK)  && (retry-- > 0) );
        if(retry <= 0)
        {
            OPT3001_Error_handler();
            return 0;   // return 0 as a hint that NO NEW Data is obtained this time
        }
        else
            return((uint16_t) (reg[0] << 8 | reg[1]));
    }
    else
    {
        OPT3001_Error_handler();
        return 0;   // return 0 as a hint that NO NEW Data is obtained this time
    }
}

static void OPT3001_Error_handler(void)
{


}
