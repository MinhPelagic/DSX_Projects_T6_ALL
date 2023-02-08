/*******************************************************************************
 * @file        : LCD_COM24H2P39ULC.c
 * @brief       : Low Level Driver for COM24H2P39ULC Blanview TFT-LCD
 *                Display
 *                Display Controller is Himax HX8347-A01.
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2020 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The COM24H2P39ULC is build on the FMC module.
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _LCD_COM24H2P39ULC_

/******************************************************************************
 * @brief   Write LCD Controller Register
 *
 * @note
 ******************************************************************************/
void LCD_WriteReg(uint16_t Reg)
{
  FMC_BANK1_ADDR->REG = Reg;
}

/******************************************************************************
 * @brief   Write LCD Data on internal GRAM
 *
 * @note
 ******************************************************************************/
void LCD_WriteData(uint16_t Data)
{
  LCD_ADDR->REG = Data;
}

void LCD_WriteDataMultiple(uint8_t *pData, uint32_t Size) 
{  
  uint32_t counter = 0;
  uint16_t regvalue;
  
  regvalue = *pData | (*(pData+1) << 8);

  for (counter = Size; counter != 0; counter--)
  {
    // Write 16-bit Reg
    LCD_ADDR->REG = regvalue;
    counter--;
    pData += 2;
    regvalue = *pData | (*(pData+1) << 8);
  }
}

/******************************************************************************
 * @brief   Read LCD Data on internal GRAM
 *
 * @note
 ******************************************************************************/
uint16_t LCD_ReadData(void)
{
  return (LCD_ADDR->REG);
}

/******************************************************************************
 * @brief   Initlialize LCD Controller
 *
 * @note
 ******************************************************************************/

static GPIO_InitTypeDef GPIO_InitStruct = {0};
static FMC_NORSRAM_TimingTypeDef Timing;
static SRAM_HandleTypeDef LCD_FMC;

void LCD_Init (void)
{
  // Enable FMC clock
  __HAL_RCC_FMC_CLK_ENABLE();
  
  // USER CODE BEGIN SysInit 
  memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));
  
  // Configure LCD Pins *******************************************************
  
  GPIO_InitStruct.Pin = LCD_DPVCC_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(LCD_DPVCC_PORT, &GPIO_InitStruct); 
  HAL_GPIO_WritePin( LCD_DPVCC_PORT, LCD_DPVCC_PIN, GPIO_PIN_SET); 
  
  GPIO_InitStruct.Pin = LCD_RST_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(LCD_RST_PORT, &GPIO_InitStruct); 
  HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET);
  
  GPIO_InitStruct.Pin = LCD_IM0_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(LCD_IM0_PORT, &GPIO_InitStruct); 
  HAL_GPIO_WritePin(LCD_IM0_PORT, LCD_IM0_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_IM3_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(LCD_IM3_PORT, &GPIO_InitStruct); 
  HAL_GPIO_WritePin(LCD_IM3_PORT, LCD_IM3_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_PORTD_PINS;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(LCD_PORTD, &GPIO_InitStruct); 
  
  GPIO_InitStruct.Pin = LCD_PORTE_PINS;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(LCD_PORTE, &GPIO_InitStruct); 
  
  __HAL_RCC_FMC_FORCE_RESET();
  __HAL_RCC_FMC_RELEASE_RESET();

 
  LCD_FMC.Instance                      = FMC_NORSRAM_DEVICE;
  LCD_FMC.Extended                      = FMC_NORSRAM_EXTENDED_DEVICE;
  LCD_FMC.Init.NSBank                   = FMC_NORSRAM_BANK1;
  LCD_FMC.Init.DataAddressMux           = FMC_DATA_ADDRESS_MUX_DISABLE;
  LCD_FMC.Init.MemoryType               = FMC_MEMORY_TYPE_SRAM;
  LCD_FMC.Init.MemoryDataWidth          = FMC_NORSRAM_MEM_BUS_WIDTH_16;
  LCD_FMC.Init.BurstAccessMode          = FMC_BURST_ACCESS_MODE_DISABLE;
  LCD_FMC.Init.WaitSignalPolarity       = FMC_WAIT_SIGNAL_POLARITY_LOW;
  LCD_FMC.Init.WaitSignalActive         = FMC_WAIT_TIMING_BEFORE_WS;
  LCD_FMC.Init.WriteOperation           = FMC_WRITE_OPERATION_ENABLE;
  LCD_FMC.Init.ExtendedMode             = FMC_EXTENDED_MODE_DISABLE;
  LCD_FMC.Init.AsynchronousWait         = FMC_ASYNCHRONOUS_WAIT_DISABLE;
  LCD_FMC.Init.WriteBurst               = FMC_WRITE_BURST_DISABLE;
  LCD_FMC.Init.ContinuousClock          = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  LCD_FMC.Init.WriteFifo                = FMC_WRITE_FIFO_ENABLE;
  LCD_FMC.Init.NBLSetupTime             = 0;
  LCD_FMC.Init.PageSize                 = FMC_PAGE_SIZE_NONE;
  
  // Timing
  Timing.AddressSetupTime       = 4;
  Timing.AddressHoldTime        = 15;
  Timing.DataSetupTime          = 4;
  Timing.DataHoldTime           = 0;
  Timing.BusTurnAroundDuration  = 4;
  Timing.CLKDivision            = 16;
  Timing.DataLatency            = 17;
  Timing.AccessMode             = FMC_ACCESS_MODE_A;

  while (HAL_SRAM_Init(&LCD_FMC, &Timing, NULL) != HAL_OK) {};

  /* LCD Reset Sequence */
  HAL_GPIO_WritePin( LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET);
  HAL_Delay(2);
  HAL_GPIO_WritePin( LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_RESET); 
  HAL_Delay(1);
  HAL_GPIO_WritePin( LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET);
  HAL_Delay(120);

  __disable_irq();
  LCD_WriteReg(0x0096);  // TEST 1
  LCD_WriteData(0x0001);

  LCD_WriteReg(0x0019);  // OSC CONTROL 1
  LCD_WriteData(0x0087);
  __enable_irq();

  HAL_Delay(10);
    
  /* Display OFF Settings */
  __disable_irq();
  LCD_WriteReg(0x0026);  // DISPLAY OFF
  LCD_WriteData(0x0080);
  
  LCD_WriteReg(0x001B);  // POWER CONTROL 1
  LCD_WriteData(0x000C);
  
  LCD_WriteReg(0x0043);  // VCOM CONTROL 1
  LCD_WriteData(0x0000);
  
  /* Power Supply Setting Initializing */
  LCD_WriteReg(0x0020);  // POWER CONTROL 6
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x001F);  // POWER CONTROL 5
  LCD_WriteData(0x0007);
  
  LCD_WriteReg(0x0044);  // VCOM CONTROL 2
  LCD_WriteData(0x007F);
  
  LCD_WriteReg(0x0045);  // VCOM CONTROL 3
  LCD_WriteData(0x0014);
  
  LCD_WriteReg(0x001D);  // POWER CONTROL 3
  LCD_WriteData(0x0005);
  
  LCD_WriteReg(0x001E);  // POWER CONTROL 4
  LCD_WriteData(0x0000);
  
  
  /* Power Supply Operation start setting */
  LCD_WriteReg(0x001C);  // POWER CONTROL 2
  LCD_WriteData(0x0004);
  
  LCD_WriteReg(0x001B);  // POWER CONTROL 1
  LCD_WriteData(0x0014);
  __enable_irq();
  
  HAL_Delay(40);
  
  __disable_irq();
  LCD_WriteReg(0x0043);  // VCOM CONTROL 1
  LCD_WriteData(0x0080);
  
  
  /* Power Control Setting */
  LCD_WriteReg(0x0042);  // BGP CONTROL
  LCD_WriteData(0x0008);
  
  LCD_WriteReg(0x0023);  // CYCLE CONTROL 1
  LCD_WriteData(0x0095);
  
  LCD_WriteReg(0x0024);  // CYCLE CONTROL 2
  LCD_WriteData(0x0095);
  
  LCD_WriteReg(0x0025);  // CYCLE CONTROL 3
  LCD_WriteData(0x00FF);
  
  LCD_WriteReg(0x0021);  // POWER CONTROL 7
  LCD_WriteData(0x0010);
  
  LCD_WriteReg(0x002B);  // POWER CONTROL 11
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0095);  // DCCLK SYNC TO CL1
  LCD_WriteData(0x0001);
  
  /* OSC Control Setting */
  LCD_WriteReg(0x001A);  // OSC CONTROL 2
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0093);  // OSC CONTROL 3
  LCD_WriteData(0x000F);
  
  LCD_WriteReg(0x0070);  // INTERNAL USE 28
  LCD_WriteData(0x0066);
  
  LCD_WriteReg(0x0018);  // GATE SCAN CONTROL
  LCD_WriteData(0x0001);
  
  /* R Control Setting */
#if 0
  LCD_WriteReg(0x0046);  // R CONTROL 1
  LCD_WriteData(0x0083);
  
  LCD_WriteReg(0x0047);  // R CONTROL 2
  LCD_WriteData(0x0031);
  
  LCD_WriteReg(0x0048);  // R CONTROL 3
  LCD_WriteData(0x0001);
  
  LCD_WriteReg(0x0049);  // R CONTROL 4
  LCD_WriteData(0x0056);
  
  LCD_WriteReg(0x004A);  // R CONTROL 5
  LCD_WriteData(0x0024);
  
  LCD_WriteReg(0x004B);  // R CONTROL 6
  LCD_WriteData(0x0005);
  
  LCD_WriteReg(0x004C);  // R CONTROL 7
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x004D);  // R CONTROL 8
  LCD_WriteData(0x0067);
  
  LCD_WriteReg(0x004E);  // R CONTROL 9
  LCD_WriteData(0x0001);
  
  LCD_WriteReg(0x004F);  // R CONTROL 10
  LCD_WriteData(0x001F);
  
  LCD_WriteReg(0x0050);  // R CONTROL 11
  LCD_WriteData(0x000F);
    
  LCD_WriteReg(0x0051);  // R CONTROL 12
  LCD_WriteData(0x000A);
#endif
  
  /* RGB Interface control Setting */
  LCD_WriteReg(0x0038);  // RGB INTERFACE CONTROL 1
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0039);  // RGB INTERFACE CONTROL 2
  LCD_WriteData(0x0000);
  
  
  /* Display control Setting */
  LCD_WriteReg(0x0027);  // DISPLAY CONTROL 2
  LCD_WriteData(0x0002);
  
  LCD_WriteReg(0x0028);  // DISPLAY CONTROL 3
  LCD_WriteData(0x0003);
  
  LCD_WriteReg(0x0029);  // DISPLAY CONTROL 4
  LCD_WriteData(0x0008);
  
  LCD_WriteReg(0x002A);  // DISPLAY CONTROL 5
  LCD_WriteData(0x0008);
  
  LCD_WriteReg(0x002C);  // DISPLAY CONTROL 6
  LCD_WriteData(0x0008);
  
  LCD_WriteReg(0x002D);  // DISPLAY CONTROL 7
  LCD_WriteData(0x0008);
  
  LCD_WriteReg(0x0035);  // DISPLAY CONTROL 9
  LCD_WriteData(0x0009);
  
  LCD_WriteReg(0x0036);  // DISPLAY CONTROL 10
  LCD_WriteData(0x0009);
  
  LCD_WriteReg(0x0091);  // DISPLAY CONTROL 11
  LCD_WriteData(0x0014);
  
  LCD_WriteReg(0x0037);  // DISPLAY CONTROL 12
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0001);  // DISPLAY MODE CONTROL 
  LCD_WriteData(0x0002);
  
  LCD_WriteReg(0x003A);  // CYCLE CONTROL 1
  LCD_WriteData(0x00A1);
  
  LCD_WriteReg(0x003B);  // CYCLE CONTROL 2
  LCD_WriteData(0x00A1);
  
  LCD_WriteReg(0x003C);  // CYCLE CONTROL 3
  LCD_WriteData(0x00A0);
  
  LCD_WriteReg(0x003D);  // CYCLE CONTROL 4
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x003E);  // CYCLE CONTROL 5
  LCD_WriteData(0x002D);
  
  LCD_WriteReg(0x0040);  // CYCLE CONTROL 6
  LCD_WriteData(0x0003);
  
  LCD_WriteReg(0x0041);  // CYCLE CONTROL 7
  LCD_WriteData(0x00CC);
  
  
  /* Partial Immage Display Setting */
  LCD_WriteReg(0x000A);  // PARTIAL AREA START ROW 2
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x000B);  // PARTIAL AREA START ROW 1
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x000C);  // PARTIAL AREA END ROW 2
  LCD_WriteData(0x0001);
  
  LCD_WriteReg(0x000D);  // PARTIAL AREA END ROW 1
  LCD_WriteData(0x003F);
  
  
  /* Vertical Scroll Settings */
  LCD_WriteReg(0x000E);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x000F);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0010);
  LCD_WriteData(0x0001);
  
  LCD_WriteReg(0x0011);
  LCD_WriteData(0x0040);
  
  LCD_WriteReg(0x0012);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0013);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0014);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0015);
  LCD_WriteData(0x0000);
  
  
  /* Window Address Setting */
  LCD_WriteReg(0x0002);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0003);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0004);
  LCD_WriteData(0x0000);//LCD_WriteData(0x0001);
  
  LCD_WriteReg(0x0005);
  LCD_WriteData(0x00EF);//LCD_WriteData(0x003F);
  
  LCD_WriteReg(0x0006);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0007);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0008);
  LCD_WriteData(0x0001);//LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0009);
  LCD_WriteData(0x003F);//LCD_WriteData(0x00EF);
    
  LCD_WriteReg(0x0016);
  LCD_WriteData(0x0008);//LCD_WriteData(0x0008); => BGR
  
  LCD_WriteReg(0x0072);
  LCD_WriteData(0x0000);
  
  LCD_WriteReg(0x0022);
  //LCD_WriteData(0x0000);
  __enable_irq();
  
  HAL_Delay(60);
  
  /* Display On setting */
  __disable_irq();
  LCD_WriteReg(0x0094); // SAP IDLE MODE
  LCD_WriteData(0x000A);
  
  LCD_WriteReg(0x0090); // DISPLAY CONTROL 8
  LCD_WriteData(0x001D); // changed from 0x0017 to 0x001D on 2021 1013 by YeuShyr // changed from 0x007F to 0x0017 on 2021 1012 by YeuShyr
  
  LCD_WriteReg(0x0026); // DISPLAY CONTROL 1
  LCD_WriteData(0x0084);
  __enable_irq();
  
  HAL_Delay(40);
  
  __disable_irq();
  LCD_WriteReg(0x0026); // DISPLAY CONTROL 1
  LCD_WriteData(0x00A4);
  
  LCD_WriteReg(0x0026); // DISPLAY CONTROL 1
  LCD_WriteData(0x00AC);
  __enable_irq();
  
  HAL_Delay(40);
  
  __disable_irq();
  LCD_WriteReg(0x0026); // DISPLAY CONTROL 1
  LCD_WriteData(0x00BC);
  
  LCD_WriteReg(0x0096); // TEST 1
  LCD_WriteData(0x0000);
  
  // WRITE LCD GRAM
  LCD_WriteReg(0x0022); 
  __enable_irq();
  
  
}

/******************************************************************************
 * @brief   DeInitlialize LCD Controller
 *
 * @note
 ******************************************************************************/
void LCD_DeInit(void)
{
  /* USER CODE BEGIN FMC_MspInit 1 */
  __HAL_RCC_FMC_FORCE_RESET();
  __HAL_RCC_FMC_RELEASE_RESET();
  
  /* Peripheral clock enable */
  __HAL_RCC_FMC_CLK_DISABLE();
  
  // Switch Off LCD Power
  memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));
  GPIO_InitStruct.Pin = LCD_DPVCC_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(LCD_DPVCC_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_DPVCC_PORT, LCD_DPVCC_PIN, GPIO_PIN_RESET); 
  
  // Deinitialize all LCD Pins
  HAL_GPIO_DeInit(LCD_PORTE, LCD_PORTE_PINS);
  HAL_GPIO_DeInit(LCD_PORTD, LCD_PORTD_PINS);
  
  HAL_GPIO_DeInit(LCD_RS_PORT, LCD_RS_PIN);
  HAL_GPIO_DeInit(LCD_OE_PORT, LCD_OE_PIN);
  HAL_GPIO_DeInit(LCD_WE_PORT, LCD_WE_PIN);
  HAL_GPIO_DeInit(LCD_CS_PORT, LCD_CS_PIN);
  HAL_GPIO_DeInit(LCD_IM3_PORT, LCD_IM3_PIN);
  HAL_GPIO_DeInit(LCD_IM0_PORT, LCD_IM0_PIN);
  HAL_GPIO_DeInit(LCD_RST_PORT, LCD_RST_PIN);
  
  GPIO_InitStruct.Pin = LCD_PORTE_PINS;
  HAL_GPIO_Init(LCD_PORTE, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_PORTE, LCD_PORTE_PINS, GPIO_PIN_RESET); 
  
  GPIO_InitStruct.Pin = LCD_PORTD_PINS;
  HAL_GPIO_Init(LCD_PORTD, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_PORTD, LCD_PORTD_PINS, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_RS_PIN;
  HAL_GPIO_Init(LCD_RS_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_OE_PIN;
  HAL_GPIO_Init(LCD_OE_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_OE_PORT, LCD_OE_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_WE_PIN;
  HAL_GPIO_Init(LCD_WE_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_WE_PORT, LCD_WE_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_CS_PIN;
  HAL_GPIO_Init(LCD_CS_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_IM3_PIN;
  HAL_GPIO_Init(LCD_IM3_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_IM3_PORT, LCD_IM3_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_IM0_PIN;
  HAL_GPIO_Init(LCD_IM0_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_IM0_PORT, LCD_IM0_PIN, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = LCD_RST_PIN;
  HAL_GPIO_Init(LCD_RST_PORT, &GPIO_InitStruct);  
  HAL_GPIO_WritePin( LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_RESET);
  
}

#endif //_LCD_COM24H2P39ULC_