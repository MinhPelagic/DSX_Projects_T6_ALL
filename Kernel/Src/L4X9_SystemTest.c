/*******************************************************************************
 * @file        : L4X9_SystemTest.c
 * @brief       : System and Peripheral Selfcheck routines.
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: YeuShyr Wu - Pelagic Pressure Systems / Aqua Lung
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_SYSTEMTEST_H_

/*
  HW_SelfTestProgress[0], the flag for Button Test

  HW_SelfTestProgress[1], the flag for Buzzer Test

  HW_SelfTestProgress[2], the flag for ExFLASH Test

  HW_SelfTestProgress[3], the flag for EEPROM Test

  HW_SelfTestProgress[4], the flag for USB Connection Test

  HW_SelfTestProgress[5], the flag for BLE Conneciton Test
*/

uint8_t HW_SelfTestProgress[HW_SYS_MAX] = {0};

void SelfTest_Button(uint8_t StIdx, uint8_t* EndIdx)
{
    Buzzer_Off();

    if(StIdx <= 100)
    {
        *EndIdx = StIdx + 50;
    }
    else
    {

    }

    //*EndIdx = 100;
}

void SelfTest_Buzzer(uint8_t StIdx, uint8_t* EndIdx)
{
    static uint8_t toggle = 0;

    if(StIdx < 100)
    {
        if(toggle==0)
        {
            toggle=1;
            Buzzer_On();
            Vibrator_On();
        }
        else
        {
            toggle=0;
            Buzzer_Off();
            Vibrator_Off();
            *EndIdx=StIdx+20;
        }
    }
    else
    {
        toggle = 0;
        Buzzer_Off();
        Vibrator_Off();
        *EndIdx = 101;
        GUI_DispStringAt("Buzzer Check: OK\n", 10, 70);
    }
    
    Buzzer_Off();
    Vibrator_Off();
}

/******************************************************************************
 * @brief   SPI HW Detach.
 *
 * @note
 *
 *      //The following must be implemented to work with BLE
 *
 *          L4X9_QSPI_Init();
 *
 *           MT25QL512ABB_PowerDownRelease();
 *
 *           Do FLASH Read/Erase/Write here  SelfTest_ExFLASH(0, 0); for example
 *
 *           and when you finished :
 *
 *           MT25QL512ABB_PowerDownEnter();
 *
 *           / DeInitialize SPI module /
 *           L4X9_QSPI_DeInit();
 *
 ******************************************************************************/
void SelfTest_ExFLASH(void)     //(uint8_t StIdx, uint8_t* EndIdx)
{
#define FW_INFODATA1_ADDR     0x00000000
#define FW_INFODATA2_ADDR     0x01000000//0x00001000
#define FW_INFODATA3_ADDR     0x02000000//0x00002000
#define FW_INFODATA4_ADDR     0x03000000//0x00003000


#define FLASH_TEST_SIZE        256

    uint8_t FlashTestReadData_1[FLASH_TEST_SIZE] = {0};
    uint8_t FlashTestReadData_2[FLASH_TEST_SIZE] = {0};
    uint8_t FlashTestReadData_3[FLASH_TEST_SIZE] = {0};
    uint8_t FlashTestReadData_4[FLASH_TEST_SIZE] = {0};
    uint8_t FlashTestWriteData[FLASH_TEST_SIZE] = {0};

    uint16_t i = 0;
    int8_t retry = NVD_EEPROM_WRITE_TIMEOUT;
    
    //uint8_t Status = 0;
    
    // Enable ExFlash SPI Interface
    L4X9_QSPI_Init();

    // Power On ExFlash
    MT25QL512ABB_PowerDownRelease();
    
    
    //*****************************************************************************
    // Erase InfoData Locations in Exflash
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;
    do{} while ((MT25QL512ABB_Erase4kSector(FW_INFODATA1_ADDR) != true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;
    do{} while ((MT25QL512ABB_Erase4kSector(FW_INFODATA2_ADDR) != true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;
    do{} while ((MT25QL512ABB_Erase4kSector(FW_INFODATA3_ADDR) != true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;
    do{} while ((MT25QL512ABB_Erase4kSector(FW_INFODATA4_ADDR) != true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    // Wrtie Data to External Flash

    for(i=0; i<FLASH_TEST_SIZE; i++)
        FlashTestWriteData[i]=i*1;
    
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestWriteData )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    for(i=0; i<FLASH_TEST_SIZE; i++)
        FlashTestWriteData[i]=i*2;
    
    retry = NVD_FLASH_WRITE_TIMEOUT;
    do{} while ((MT25QL512ABB_WriteNPage1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestWriteData )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }    
    
    for(i=0; i<FLASH_TEST_SIZE; i++)
        FlashTestWriteData[i]=i*3;

    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestWriteData )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }    
    
    for(i=0; i<FLASH_TEST_SIZE; i++)
        FlashTestWriteData[i]=i*4;

    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestWriteData )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }    
    
    // Read Data From External Flash
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_TEST_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_TEST_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    //*****************************************************************************

    // Power Down ExFlash
    MT25QL512ABB_PowerDownEnter();
    
    // Disable ExFlash SPI Interface
    L4X9_QSPI_DeInit();
}

void SelfTest_EEPROM(uint8_t StIdx, uint8_t* EndIdx)
{

#define EEPROM_TEST_SIZE        256
#define EEPROM_ADDR0            0x0000
#define EEPROM_ADDR1            0x1000
  
    uint8_t EE_ReadData0[EEPROM_TEST_SIZE] = {0};
    uint8_t EE_ReadData1[EEPROM_TEST_SIZE] = {0};
    uint8_t EE_WriteData0[EEPROM_TEST_SIZE] = {0};
    uint8_t EE_WriteData1[EEPROM_TEST_SIZE] = {0};
    uint16_t eei = 0;
    int8_t retry;    
    
    //**EEPROM R/W Test***********************************************************************************************
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR0, &EE_ReadData0, sizeof(EE_ReadData0)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
                    
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR1, &EE_ReadData1, sizeof(EE_ReadData1)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        
        for(eei=0; eei< EEPROM_TEST_SIZE; eei++)
        {
            EE_WriteData0[eei]=(uint8_t)eei*1;
            EE_WriteData1[eei]=(uint8_t)eei*2;
        }

        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( EEPROM_ADDR0, &EE_WriteData0, sizeof(EE_WriteData0)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( EEPROM_ADDR1, &EE_WriteData1, sizeof(EE_WriteData1)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR0, &EE_ReadData0, sizeof(EE_ReadData0)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR1, &EE_ReadData1, sizeof(EE_ReadData1)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        
    for(uint8_t i = 0; i < 10; i++)
    {
        //*************************************************************************************************
        for(eei=0; eei< EEPROM_TEST_SIZE; eei++)
        {
            EE_WriteData0[eei]=(uint8_t)(EE_ReadData0[eei]+1);
            EE_WriteData1[eei]=(uint8_t)(EE_ReadData1[eei]+2);
        }

        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( EEPROM_ADDR0, &EE_WriteData0, sizeof(EE_WriteData0)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes( EEPROM_ADDR1, &EE_WriteData1, sizeof(EE_WriteData1)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR0, &EE_ReadData0, sizeof(EE_ReadData0)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes( EEPROM_ADDR1, &EE_ReadData1, sizeof(EE_ReadData1)) && (retry-- > 0));
        if(retry <= 0)
        {
            ErrHandle_EE();
        }        
        //*************************************************************************************************
    }
}


void SelfTest_USB(uint8_t StIdx, uint8_t* EndIdx)
{
    uint8_t Status;

    Status = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

    if(Status)
    {
        *EndIdx=100;
    }
    else
    {
        *EndIdx = 0;
    }
}


void SelfTest_BLE(uint8_t StIdx, uint8_t* EndIdx)
{
    uint8_t Status;

    Status = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

    if(Status)
    {
        *EndIdx=100;
    }
    else
    {
        *EndIdx = 0;
    }
}


void SelfTest_SPI(uint8_t StIdx, uint8_t* EndIdx)
{
    //uint8_t Status;




    //*EndIdx = 100;
}


void SelfTest_I2C(uint8_t StIdx, uint8_t* EndIdx)
{
    //uint8_t Status;




    //*EndIdx = 100;
}


void SelfTest_UART(uint8_t StIdx, uint8_t* EndIdx)
{
    //uint8_t Status;




    //*EndIdx = 100;
}



/******************************************************************************
 * @brief   ReadOnly_ExFLASH
 *
 * @note
 *
 *      //The following must be implemented to work with BLE
 *
 *          L4X9_QSPI_Init();
 *
 *           MT25QL512ABB_PowerDownRelease();
 *
 *           Do FLASH Read/Erase/Write here  SelfTest_ExFLASH(0, 0); for example
 *
 *           and when you finished :
 *
 *           MT25QL512ABB_PowerDownEnter();
 *
 *           / DeInitialize SPI module /
 *           L4X9_QSPI_DeInit();
 *
 ******************************************************************************/
void ReadOnly_ExFLASH(void)
{
#define FW_INFODATA1_ADDR     0x00000000
#define FW_INFODATA2_ADDR     0x01000000//0x00001000
#define FW_INFODATA3_ADDR     0x02000000//0x00002000
#define FW_INFODATA4_ADDR     0x03000000//0x00003000


#define FLASH_READ_ONLY_SIZE        256

    uint8_t FlashTestReadData_1[FLASH_READ_ONLY_SIZE] = {0};
    uint8_t FlashTestReadData_2[FLASH_READ_ONLY_SIZE] = {0};
    uint8_t FlashTestReadData_3[FLASH_READ_ONLY_SIZE] = {0};
    uint8_t FlashTestReadData_4[FLASH_READ_ONLY_SIZE] = {0};
    int8_t retry;
    
    //uint16_t i = 0;
    //uint8_t Status = 0;
    
    // Enable ExFlash SPI Interface
    L4X9_QSPI_Init();

    // Power On ExFlash
    MT25QL512ABB_PowerDownRelease();    
    
    //*****************************************************************************
    // Erase InfoData Locations in Exflash

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA1_ADDR, FLASH_READ_ONLY_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_READ_ONLY_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA3_ADDR, FLASH_READ_ONLY_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA4_ADDR, FLASH_READ_ONLY_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( FW_INFODATA2_ADDR, FLASH_READ_ONLY_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( (FW_INFODATA2_ADDR + FLASH_READ_ONLY_SIZE), FLASH_READ_ONLY_SIZE, FlashTestReadData_2)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( (FW_INFODATA2_ADDR + FLASH_READ_ONLY_SIZE*2), FLASH_READ_ONLY_SIZE, FlashTestReadData_3)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( (FW_INFODATA2_ADDR + FLASH_READ_ONLY_SIZE*3), FLASH_READ_ONLY_SIZE, FlashTestReadData_4)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    // Power Down ExFlash
    MT25QL512ABB_PowerDownEnter();
    
    // Disable ExFlash SPI Interface
    L4X9_QSPI_DeInit();
}



/******************************************************************************
 * @brief   This function is called in one of Tick, must be shorter < 120 mSec
 *
 * @note
 ******************************************************************************/
uint8_t SystemSelftest(void)    //(uint8_t* flag)
{
    uint8_t Status;

    /*
        HW_SelfTestProgress[0], the flag for ExFLASH Test

        HW_SelfTestProgress[1], the flag for EEPROM Test

        HW_SelfTestProgress[2], the flag for USB Connection Test

        HW_SelfTestProgress[3], the flag for BLE Conneciton Test
    */

    //if(HW_SelfTestProgress[HW_SYS_BUTTON_TEST] <= 100)
    //    SelfTest_Button(HW_SelfTestProgress[HW_SYS_BUTTON_TEST], &HW_SelfTestProgress[HW_SYS_BUTTON_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_BUZZER_TEST] <= 100)
    //SelfTest_Buzzer(HW_SelfTestProgress[HW_SYS_BUZZER_TEST], &HW_SelfTestProgress[HW_SYS_BUZZER_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_EXFLASH_TEST] <= 100)
    //    SelfTest_ExFLASH(HW_SelfTestProgress[HW_SYS_EXFLASH_TEST], &HW_SelfTestProgress[HW_SYS_EXFLASH_TEST]);
    //SelfTest_ExFLASH();
    ReadOnly_ExFLASH();
    
    ReadNewDiveProfile_ExFLASH();
    
    ReadWelcomeData_ExFLASH();
    
    SelfTest_EEPROM(HW_SelfTestProgress[HW_SYS_EEPROM_TEST], &HW_SelfTestProgress[HW_SYS_EEPROM_TEST]);
    
    //else if(HW_SelfTestProgress[HW_SYS_EEPROM_TEST] <= 100)
    //    SelfTest_EEPROM(HW_SelfTestProgress[HW_SYS_EEPROM_TEST], &HW_SelfTestProgress[HW_SYS_EEPROM_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_USB_TEST] <= 100)
    //    SelfTest_USB(HW_SelfTestProgress[HW_SYS_USB_TEST], &HW_SelfTestProgress[HW_SYS_USB_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_BLE_TEST] <= 100)
    //    SelfTest_BLE(HW_SelfTestProgress[HW_SYS_BLE_TEST], &HW_SelfTestProgress[HW_SYS_BLE_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_SPI_TEST] <= 100)
    //    SelfTest_SPI(HW_SelfTestProgress[HW_SYS_SPI_TEST], &HW_SelfTestProgress[HW_SYS_SPI_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_I2C_TEST] <= 100)
    //    SelfTest_I2C(HW_SelfTestProgress[HW_SYS_I2C_TEST], &HW_SelfTestProgress[HW_SYS_I2C_TEST]);
    //else if(HW_SelfTestProgress[HW_SYS_UART_TEST] <= 100)
    //    SelfTest_UART(HW_SelfTestProgress[HW_SYS_UART_TEST], &HW_SelfTestProgress[HW_SYS_UART_TEST]);

    Status = 0;
    return Status;
}

/*
void SystemSelftestReset(uint8_t* flag)
{
    uint8_t i = 0;

    for(i=0; i< HW_SYS_MAX; i++)
        HW_SelfTestProgress[i] = 0;

    //HW_SelfTestProgress[0]=101;   // Button Test is done from the beginning

}
*/

/******************************************************************************
 * @brief   ReadOnly_ExFLASH
 *
 * @note
 *
 *      //The following must be implemented to work with BLE
 *
 *          L4X9_QSPI_Init();
 *
 *           MT25QL512ABB_PowerDownRelease();
 *
 *           Do FLASH Read/Erase/Write here  SelfTest_ExFLASH(0, 0); for example
 *
 *           and when you finished :
 *
 *           MT25QL512ABB_PowerDownEnter();
 *
 *           / DeInitialize SPI module /
 *           L4X9_QSPI_DeInit();
 *
 ******************************************************************************/
void ReadNewDiveProfile_ExFLASH(void)
{

#define FLASH_PROFILE_TEST_SIZE        1024

    uint8_t FlashTestReadData_1[FLASH_PROFILE_TEST_SIZE] = {0};
    uint8_t FlashTestReadData_2[FLASH_PROFILE_TEST_SIZE] = {0};
    
   // uint16_t i = 0;
    //uint8_t Status = 0;
    
    uint32_t HeaderAddr = FLASH_Map.ProfileLastDiveHeadAddr;
    uint32_t TrailerAddr = FLASH_Map.ProfileLastDiveEndAddr;
    uint32_t addr = HeaderAddr;
    int8_t retry;
    
    // Enable ExFlash SPI Interface
    L4X9_QSPI_Init();

    // Power On ExFlash
    MT25QL512ABB_PowerDownRelease();    
    
    //*****************************************************************************
    // Erase InfoData Locations in Exflash

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( addr, FLASH_PROFILE_TEST_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006 
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    for(addr = HeaderAddr; addr < TrailerAddr; addr+= FLASH_PROFILE_TEST_SIZE)
    {        
        retry = NVD_FLASH_READ_TIMEOUT;    
        do{} while ((MT25QL512ABB_Read1I1O( addr, FLASH_PROFILE_TEST_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006 
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }
    }
    // Power Down ExFlash
    MT25QL512ABB_PowerDownEnter();
    
    // Disable ExFlash SPI Interface
    L4X9_QSPI_DeInit();
}

void ReadWelcomeData_ExFLASH(void)
{
    #define FLASH_WELCOME_SIZE        1024
  
    uint8_t FlashTestReadData_1[FLASH_WELCOME_SIZE] = {0};
    uint8_t FlashTestReadData_2[FLASH_WELCOME_SIZE] = {0};
    uint8_t FlashTestReadData_3[FLASH_WELCOME_SIZE] = {0};
    uint8_t FlashTestReadData_4[FLASH_WELCOME_SIZE] = {0};
    int8_t retry = NVD_FLASH_READ_TIMEOUT;
    
    // Enable ExFlash SPI Interface
    L4X9_QSPI_Init();

    // Power On ExFlash
    MT25QL512ABB_PowerDownRelease();    
    
    //*****************************************************************************
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( 0x00000000, FLASH_WELCOME_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006 
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( EXFLASH_SLATE, FLASH_WELCOME_SIZE, FlashTestReadData_1 )!= true) && (retry-- > 0));		// Timeout added from R1006 
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( (EXFLASH_SLATE - 0x11000000), FLASH_WELCOME_SIZE, FlashTestReadData_2 )!= true) && (retry-- > 0));		// Timeout added from R1006 
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( EXFLASH_MYINFO, FLASH_WELCOME_SIZE, FlashTestReadData_3 )!= true) && (retry-- > 0));		// Timeout added from R1006 
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while ((MT25QL512ABB_Read1I1O( (EXFLASH_MYINFO - 0x11000000), FLASH_WELCOME_SIZE, FlashTestReadData_4 )!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    // Power Down ExFlash
    MT25QL512ABB_PowerDownEnter();
    
    // Disable ExFlash SPI Interface
    L4X9_QSPI_DeInit();
}
#endif