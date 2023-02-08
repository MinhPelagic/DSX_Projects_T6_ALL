/*******************************************************************************
 * @file        : MT25QL512ABB.c
 * @brief       : 512M-Bit [x1/x2/x4] Serial Flash Memory
 *                
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The MT25QL512ABB is build on the QSPI or SPI system bus.
 *      The MT25QL512ABB is only Software Protected.
 ******************************************************************************/

#include "L4X9_includes.h"

#ifdef _MT25QL512ABB_H_


/*******************************************************************************
 * @brief   Deep Power Down Release
 *
 * @note    
 ******************************************************************************/
bool MT25QL512ABB_PowerDownRelease( void )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  //uint8_t statusregister = 0xFF;
  
  /*
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }*/
  
  if(DEV_Board())
  {  
      uint8_t command = MT25QL512ABB_PWR_DWN_RELEASE;
    
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_PWR_DWN_RELEASE;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
        
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  /* Wait for PowerDown mode enter */
  us_delay(TIME_RDP_US);

  return true; 
}

/*******************************************************************************
 * @brief   Deep Power Down Enter
 *
 * @note    This is a blocking rountine till entire PowerDown enter mode timing,
 *          including tDP.
 *          Before executing PowerDown enter the routine waits completition of 
 *          any ongoing Program/Write/Erase operation.
 ******************************************************************************/
bool MT25QL512ABB_PowerDownEnter( void )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  /* Exit Power down to have device in known state */
  MT25QL512ABB_PowerDownRelease();
  
  if(DEV_Board())
  { 
      uint8_t command = MT25QL512ABB_PWR_DWN_ENTER;
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_PWR_DWN_ENTER;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }      
  
  /* Wait for PowerDown mode enter */
  us_delay(TIME_DP_US);

  return true; 
}


/*******************************************************************************
 * @brief   Read Status register
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_ReadStatusReg( uint8_t *statusregister )
{
  uint8_t statreg = 0;
  
  if(DEV_Board())
  { 
      uint8_t command = MT25QL512ABB_READ_STATUS_REG;
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      if(HAL_SPI_Receive(&SPI3Handle, &statreg, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_READ_STATUS_REG;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
      sCommand.NbData                = 1;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
    
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      uint8_t reg [2];
      
      if(HAL_OSPI_Receive(&OSPI2Handle, reg, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      statreg = reg[0];
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  (*statusregister) = statreg;
  return true;
}

/*******************************************************************************
 * @brief   Enable 4byte address mode
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Enable4bAddress( void )
{
  if(DEV_Board())
  {
      uint8_t command = MT25QL512ABB_4BYTE_ADDR_ENTER;
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4BYTE_ADDR_ENTER;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  return true; 
}

/*******************************************************************************
 * @brief   Disable 4byte address mode
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Disable4bAddress( void )
{
  if(DEV_Board())
  {
      uint8_t command = MT25QL512ABB_4BYTE_ADDR_EXIT;
  
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4BYTE_ADDR_EXIT;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  return true; 
}

/*******************************************************************************
 * @brief   Read ID register
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_ReadID( uint8_t *manufacturerId, uint8_t *type, uint8_t *density )
{
  uint8_t rx_buf[3];
  
  if(DEV_Board())
  {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
      uint8_t command =  MT25QL512ABB_READ_ID;
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      if(HAL_SPI_Receive(&SPI3Handle, rx_buf, 3, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
        
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      OSPI_RegularCmdTypeDef sCommand;

      
      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_READ_ID;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
      sCommand.NbData                = 3;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      if(HAL_OSPI_Receive(&OSPI2Handle, rx_buf, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
        
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);  
  }  
  
  (*manufacturerId) = rx_buf[0];
  (*type) = rx_buf[1];
  (*density) = rx_buf[2];

  return true;
}


/*******************************************************************************
 * @brief   Write Enable
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteEnable( void )
{
  if(DEV_Board())
  {
      uint8_t command = MT25QL512ABB_WRITE_ENABLE;
  
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_WRITE_ENABLE;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  return true; 
}

/*******************************************************************************
 * @brief   Write Disable
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteDisable( void )
{
  if(DEV_Board())
  {
      uint8_t command = MT25QL512ABB_WRITE_DISABLE;
  
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_WRITE_DISABLE;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
  
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
  
  return true; 
}


/*******************************************************************************
 * @brief   Software Reset
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_SoftReset( void )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  if(DEV_Board())
  {  
      uint8_t command = MT25QL512ABB_RESET_EANBLE;
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_RESET_EANBLE;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }
  
  /* Wait tSHSL time */
  us_delay(1);
  
  if(DEV_Board())
  {    
      uint8_t command = MT25QL512ABB_RESET_MEM;  
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_RESET_MEM;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }  
   
  /* Wait Reset Recovery time from instruction mode */
  us_delay(45);
  
  return true; 
}


/*******************************************************************************
 * @brief   1 x I/O Read number of byte (size) starting from address and saves
 *          in data buffer (read_data)
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Read1I1O( uint32_t address, uint32_t size, void * read_data )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  if(DEV_Board())
  {   
    uint32_t read_size = size;
    uint32_t data_read = 0;
    uint32_t data_to_read = 512;
    uint8_t *ptr = read_data;
    uint32_t current_addr = address;
    uint8_t rx_buf [512];
    uint8_t comm_buf [5];

    if (read_size <= 512)
    {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
        
      comm_buf[0] =  MT25QL512ABB_4B_READ;
      comm_buf[1] = (uint8_t)(current_addr >> 24);
      comm_buf[2] = (uint8_t)(current_addr >> 16);
      comm_buf[3] = (uint8_t)(current_addr >> 8);
      comm_buf[4] = (uint8_t)(current_addr);
      if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }

      if(HAL_SPI_Receive(&SPI3Handle, rx_buf, size, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
        
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

      memcpy ( read_data , rx_buf , size );
    }
    else
    {
      while ( read_size > 0 )
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
          
        comm_buf[0] =  MT25QL512ABB_4B_READ;
        comm_buf[1] = (uint8_t)(current_addr >> 24);
        comm_buf[2] = (uint8_t)(current_addr >> 16);
        comm_buf[3] = (uint8_t)(current_addr >> 8);
        comm_buf[4] = (uint8_t)(current_addr);
        if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }

        if(HAL_SPI_Receive(&SPI3Handle, rx_buf, data_to_read, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }
          
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
      
        /* Assign read data from Rx buffer */
        memcpy(ptr+data_read, rx_buf, data_to_read);
        
        /* Increment address for next iteration */
        current_addr += data_to_read;
        
        data_read += data_to_read;
        
        read_size -= data_to_read;
        
        if( read_size > 512 )
          data_to_read = 512;
        else
          data_to_read = read_size;
      }
    }
  }
  else
  {   
    uint32_t read_size = size;
    uint32_t data_read = 0;
    uint32_t data_to_read = 512;
    uint8_t *ptr = read_data;
    uint32_t current_addr = address;
    uint8_t rx_buf [512];
    //uint8_t comm_buf [5];

    if (read_size <= 512)
    {
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
        
      OSPI_RegularCmdTypeDef sCommand;
      
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_FASTREAD;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = current_addr;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
      sCommand.NbData                = size;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 8;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
        
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }

      if(HAL_OSPI_Receive(&OSPI2Handle, rx_buf, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
        
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);

      memcpy ( read_data , rx_buf , size );
    }
    else
    {
      while ( read_size > 0 )
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
          
        OSPI_RegularCmdTypeDef sCommand;
        sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
        sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
        sCommand.Instruction           = MT25QL512ABB_4B_FASTREAD;
        sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
        sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
        sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
        sCommand.Address               = current_addr;
        sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
        sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
        sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
        sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
        sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
        sCommand.NbData                = data_to_read;
        sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
        sCommand.DummyCycles           = 8;
        sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
        sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
        if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }

        if(HAL_OSPI_Receive(&OSPI2Handle, rx_buf, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }
          
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
      
        /* Assign read data from Rx buffer */
        memcpy(ptr+data_read, rx_buf, data_to_read);
        
        /* Increment address for next iteration */
        current_addr += data_to_read;
        
        data_read += data_to_read;
        
        read_size -= data_to_read;
        
        if( read_size > 512 )
          data_to_read = 512;
        else
          data_to_read = read_size;
      }
    }
  }
  return true;
}


/*******************************************************************************
 * @brief   1 x I/O Write number of byte (size) starting from address.
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteNPage1I1O( uint32_t address, uint32_t size, void * write_data )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  if(DEV_Board())
  {   
    uint32_t data_to_tx = size;
    uint32_t data_sent = 0;
    uint32_t chunk_size = 0;
    uint32_t current_addr = address;
    uint8_t *ptr = write_data;
    uint8_t tx_buf [512];
    uint8_t comm_buf [5];
    
    /* Check if we are on page boundary */
    if( (address%MT25QL512ABB_PAGE_SIZE_BYTE) == 0 )      // On page boundary use optimized function
    {
      while ( data_to_tx > 0 )
      {
        /* Wait till al programm/erase/write operations are done */
        /* Poll Status Register for WIP bit check */
        statusregister = 0xFF;
        
        while (statusregister & MT25QL512ABB_STS_WIP_MSK)
        {
          if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
            return false;
        }
        
        /* Enable Write operations */
        if(MT25QL512ABB_WriteEnable() != true)
          return false;
      
        /* Write data to Transmit to TX buffer */
        if(data_to_tx >= MT25QL512ABB_PAGE_SIZE_BYTE)
        {
          memcpy(&tx_buf[0], ptr+data_sent, MT25QL512ABB_PAGE_SIZE_BYTE);
          chunk_size = MT25QL512ABB_PAGE_SIZE_BYTE;
          data_sent += MT25QL512ABB_PAGE_SIZE_BYTE;
          data_to_tx -= MT25QL512ABB_PAGE_SIZE_BYTE;
        }
        else
        {
          memcpy(&tx_buf[0], ptr+data_sent, data_to_tx);
          chunk_size = data_to_tx;
          data_sent += data_to_tx;
          data_to_tx = 0;
        }
        
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
          
        comm_buf[0] =  MT25QL512ABB_4B_PROG_PAGE;
        comm_buf[1] = (uint8_t)(current_addr >> 24);
        comm_buf[2] = (uint8_t)(current_addr >> 16);
        comm_buf[3] = (uint8_t)(current_addr >> 8);
        comm_buf[4] = (uint8_t)(current_addr);
        if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }
        
        if(HAL_SPI_Transmit(&SPI3Handle, tx_buf, chunk_size, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }
          
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

        /* Increment address for next iteration */
        current_addr += MT25QL512ABB_PAGE_SIZE_BYTE;
      }
    }
    else  // Not on page boundary
    {
      /* Enable Write operations */
      if(MT25QL512ABB_WriteEnable() != true)
        return false;
        
      /* Get free size on current page */
      uint32_t free_on_currentpage = MT25QL512ABB_PAGE_SIZE_BYTE - (address%MT25QL512ABB_PAGE_SIZE_BYTE);
      
      if( data_to_tx > free_on_currentpage )
        chunk_size = free_on_currentpage;
      else
        chunk_size = data_to_tx;
        
      /* Write data to Transmit to TX buffer */
      memcpy(&tx_buf[0], ptr, chunk_size);

      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
          
      comm_buf[0] =  MT25QL512ABB_4B_PROG_PAGE;
      comm_buf[1] = (uint8_t)(current_addr >> 24);
      comm_buf[2] = (uint8_t)(current_addr >> 16);
      comm_buf[3] = (uint8_t)(current_addr >> 8);
      comm_buf[4] = (uint8_t)(current_addr);
      if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
          
      if(HAL_SPI_Transmit(&SPI3Handle, tx_buf, chunk_size, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

      if(data_to_tx > chunk_size)
        data_to_tx -= chunk_size;
      else
        data_to_tx = 0;
      
      data_sent += chunk_size;
      current_addr += chunk_size;
      
      /* Now we are on page boundary */
      while ( data_to_tx > 0 )
      {
        /* Wait till al programm/erase/write operations are done */
        /* Poll Status Register for WIP bit check */
        statusregister = 0xFF;
        
        while (statusregister & MT25QL512ABB_STS_WIP_MSK)
        {
          if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
            return false;
        }
        
        /* Enable Write operations */
        if(MT25QL512ABB_WriteEnable() != true)
          return false;
        
        /* Write data to Transmit to TX buffer */
        if(data_to_tx >= MT25QL512ABB_PAGE_SIZE_BYTE)
        {
          memcpy(&tx_buf[0], ptr+data_sent, MT25QL512ABB_PAGE_SIZE_BYTE);
          chunk_size = MT25QL512ABB_PAGE_SIZE_BYTE;
          data_sent += MT25QL512ABB_PAGE_SIZE_BYTE;
          data_to_tx -= MT25QL512ABB_PAGE_SIZE_BYTE;
        }
        else
        {
          memcpy(&tx_buf[0], ptr+data_sent, data_to_tx);
          chunk_size = data_to_tx;
          data_sent += data_to_tx;
          data_to_tx = 0;
        }

        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
            
        comm_buf[0] = MT25QL512ABB_4B_PROG_PAGE;
        comm_buf[1] = (uint8_t)(current_addr >> 24);
        comm_buf[2] = (uint8_t)(current_addr >> 16);
        comm_buf[3] = (uint8_t)(current_addr >> 8);
        comm_buf[4] = (uint8_t)(current_addr);
        if(HAL_SPI_Transmit(&SPI3Handle, comm_buf,5, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }
            
        if(HAL_SPI_Transmit(&SPI3Handle, tx_buf, chunk_size, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
          return false;
        }
        
        HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);

        /* Increment address for next iteration */
        current_addr += MT25QL512ABB_PAGE_SIZE_BYTE;
      }
    }
  }
  else
  {
    uint32_t data_to_tx = size;
    uint32_t data_sent = 0;
    uint32_t chunk_size = 0;
    uint32_t current_addr = address;
    uint8_t *ptr = write_data;
    uint8_t tx_buf [512];
    //uint8_t comm_buf [5];
    
    /* Check if we are on page boundary */
    if( (address%MT25QL512ABB_PAGE_SIZE_BYTE) == 0 )      // On page boundary use optimized function
    {
      while ( data_to_tx > 0 )
      {
        /* Wait till al programm/erase/write operations are done */
        /* Poll Status Register for WIP bit check */
        statusregister = 0xFF;
        
        while (statusregister & MT25QL512ABB_STS_WIP_MSK)
        {
          if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
            return false;
        }
        
        /* Enable Write operations */
        if(MT25QL512ABB_WriteEnable() != true)
          return false;
      
        /* Write data to Transmit to TX buffer */
        if(data_to_tx >= MT25QL512ABB_PAGE_SIZE_BYTE)
        {
          memcpy(&tx_buf[0], ptr+data_sent, MT25QL512ABB_PAGE_SIZE_BYTE);
          chunk_size = MT25QL512ABB_PAGE_SIZE_BYTE;
          data_sent += MT25QL512ABB_PAGE_SIZE_BYTE;
          data_to_tx -= MT25QL512ABB_PAGE_SIZE_BYTE;
        }
        else
        {
          memcpy(&tx_buf[0], ptr+data_sent, data_to_tx);
          chunk_size = data_to_tx;
          data_sent += data_to_tx;
          data_to_tx = 0;
        }
        
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
          
        OSPI_RegularCmdTypeDef sCommand;
        sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
        sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
        sCommand.Instruction           = MT25QL512ABB_4B_PROG_PAGE;
        sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
        sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
        sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
        sCommand.Address               = current_addr;
        sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
        sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
        sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
        sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
        sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
        sCommand.NbData                = chunk_size;
        sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
        sCommand.DummyCycles           = 0;
        sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
        sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

        if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }
        
        if(HAL_OSPI_Transmit(&OSPI2Handle, tx_buf, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }
          
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);

        /* Increment address for next iteration */
        current_addr += MT25QL512ABB_PAGE_SIZE_BYTE;
      }
    }
    else  // Not on page boundary
    {
      /* Enable Write operations */
      if(MT25QL512ABB_WriteEnable() != true)
        return false;
        
      /* Get free size on current page */
      uint32_t free_on_currentpage = MT25QL512ABB_PAGE_SIZE_BYTE - (address%MT25QL512ABB_PAGE_SIZE_BYTE);
      
      if( data_to_tx > free_on_currentpage )
        chunk_size = free_on_currentpage;
      else
        chunk_size = data_to_tx;
        
      /* Write data to Transmit to TX buffer */
      memcpy(&tx_buf[0], ptr, chunk_size);

      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
          
      OSPI_RegularCmdTypeDef sCommand;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_PROG_PAGE;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = current_addr;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
      sCommand.NbData                = chunk_size;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
        
      if(HAL_OSPI_Transmit(&OSPI2Handle, tx_buf, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);

      if(data_to_tx > chunk_size)
        data_to_tx -= chunk_size;
      else
        data_to_tx = 0;
      
      data_sent += chunk_size;
      current_addr += chunk_size;
      
      /* Now we are on page boundary */
      while ( data_to_tx > 0 )
      {
        /* Wait till al programm/erase/write operations are done */
        /* Poll Status Register for WIP bit check */
        statusregister = 0xFF;
        
        while (statusregister & MT25QL512ABB_STS_WIP_MSK)
        {
          if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
            return false;
        }
        
        /* Enable Write operations */
        if(MT25QL512ABB_WriteEnable() != true)
          return false;
        
        /* Write data to Transmit to TX buffer */
        if(data_to_tx >= MT25QL512ABB_PAGE_SIZE_BYTE)
        {
          memcpy(&tx_buf[0], ptr+data_sent, MT25QL512ABB_PAGE_SIZE_BYTE);
          chunk_size = MT25QL512ABB_PAGE_SIZE_BYTE;
          data_sent += MT25QL512ABB_PAGE_SIZE_BYTE;
          data_to_tx -= MT25QL512ABB_PAGE_SIZE_BYTE;
        }
        else
        {
          memcpy(&tx_buf[0], ptr+data_sent, data_to_tx);
          chunk_size = data_to_tx;
          data_sent += data_to_tx;
          data_to_tx = 0;
        }

        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
            
        OSPI_RegularCmdTypeDef sCommand;
        sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
        sCommand.Instruction           = MT25QL512ABB_4B_PROG_PAGE;
        sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
        sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
        sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
        sCommand.Address               = current_addr;
        sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
        sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
        sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
        sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
        sCommand.DataMode              = HAL_OSPI_DATA_1_LINE;
        sCommand.NbData                = chunk_size;
        sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
        sCommand.DummyCycles           = 0;
        sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
        sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

        if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }
        
        if(HAL_OSPI_Transmit(&OSPI2Handle, tx_buf, 5000) != HAL_OK)
        {
          HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
          return false;
        }
      
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);

        /* Increment address for next iteration */
        current_addr += MT25QL512ABB_PAGE_SIZE_BYTE;
      }
    }
  }
  return true;
}


/*******************************************************************************
 * @brief   Erase 4k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase4kSector( uint32_t address )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  /* Enable Write operations */
  if(MT25QL512ABB_WriteEnable() != true)
    return false;
  
  if(DEV_Board())
  {   
    uint8_t comm_buf[5];
    comm_buf[0]  = MT25QL512ABB_4B_ERASE_4K;
    comm_buf[1] = (uint8_t)(address >> 24);
    comm_buf[2] = (uint8_t)(address >> 16);
    comm_buf[3] = (uint8_t)(address >> 8);
    comm_buf[4] = (uint8_t)(address);
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
    if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
    {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
      return false;
    }
    
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_ERASE_4K;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = address;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }
  
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  statusregister = 0xFF;

  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    uint8_t temp;
    if(MT25QL512ABB_ReadStatusReg( &temp ) == true)
      statusregister = temp;
      //return false;
  }
  return true;
}

/*******************************************************************************
 * @brief   Erase 32k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase32kSector( uint32_t address )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  /* Enable Write operations */
  if(MT25QL512ABB_WriteEnable() != true)
    return false;
  
  if(DEV_Board())
  {   
    uint8_t comm_buf[5];
    comm_buf[0]  = MT25QL512ABB_4B_ERASE_32K;
    comm_buf[1] = (uint8_t)(address >> 24);
    comm_buf[2] = (uint8_t)(address >> 16);
    comm_buf[3] = (uint8_t)(address >> 8);
    comm_buf[4] = (uint8_t)(address);
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
    if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
    {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
      return false;
    }
    
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_ERASE_32K;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = address;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }
  
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  statusregister = 0xFF;

  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    uint8_t temp;
    if(MT25QL512ABB_ReadStatusReg( &temp ) == true)
      statusregister = temp;
      //return false;
  }
  return true;
}

/*******************************************************************************
 * @brief   Erase 64k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase64kSector( uint32_t address )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  // Enable Write operations
  if(MT25QL512ABB_WriteEnable() != true)
    return false;

  if(DEV_Board())
  {   
    uint8_t comm_buf[5];
    comm_buf[0]  = MT25QL512ABB_4B_ERASE_64K;
    comm_buf[1] = (uint8_t)(address >> 24);
    comm_buf[2] = (uint8_t)(address >> 16);
    comm_buf[3] = (uint8_t)(address >> 8);
    comm_buf[4] = (uint8_t)(address);
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
    if(HAL_SPI_Transmit(&SPI3Handle, comm_buf, 5, 5000) != HAL_OK)
    {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
      return false;
    }
    
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_ERASE_64K;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = address;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_1_LINE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;

      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }
  
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  statusregister = 0xFF;

  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    uint8_t temp;
    if(MT25QL512ABB_ReadStatusReg( &temp ) == true)
      statusregister = temp;
      //return false;
  }
  return true;
}

/*******************************************************************************
 * @brief   Erase Chip
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_EraseChip( void )
{
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  uint8_t statusregister = 0xFF;
  
  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
  
  /* Enable Write operations */
  if(MT25QL512ABB_WriteEnable() != true)
    return false;
  
  if(DEV_Board())
  {   
    uint8_t command = MT25QL512ABB_4B_ERASE_CHIP;
    
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_RESET);
    
    if(HAL_SPI_Transmit(&SPI3Handle, &command, 1, 5000) != HAL_OK)
    {
      HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
      return false;
    }
    
    HAL_GPIO_WritePin(SPI3_CS_PORT, SPI3_CS_PIN, GPIO_PIN_SET);
  }
  else
  {
      OSPI_RegularCmdTypeDef sCommand;

      /* Initialize the erase command */
      sCommand.OperationType         = HAL_OSPI_OPTYPE_COMMON_CFG;
      sCommand.FlashId               = HAL_OSPI_FLASH_ID_1;
      sCommand.Instruction           = MT25QL512ABB_4B_ERASE_CHIP;
      sCommand.InstructionMode       = HAL_OSPI_INSTRUCTION_1_LINE;
      sCommand.InstructionSize       = HAL_OSPI_INSTRUCTION_8_BITS;
      sCommand.InstructionDtrMode    = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
      sCommand.Address               = 0;
      sCommand.AddressMode           = HAL_OSPI_ADDRESS_NONE;
      sCommand.AddressSize           = HAL_OSPI_ADDRESS_32_BITS;
      sCommand.AddressDtrMode        = HAL_OSPI_ADDRESS_DTR_DISABLE;
      sCommand.AlternateBytesMode    = HAL_OSPI_ALTERNATE_BYTES_NONE;
      sCommand.DataMode              = HAL_OSPI_DATA_NONE;
      sCommand.NbData                = 0;
      sCommand.DataDtrMode           = HAL_OSPI_DATA_DTR_DISABLE;
      sCommand.DummyCycles           = 0;
      sCommand.DQSMode               = HAL_OSPI_DQS_DISABLE;
      sCommand.SIOOMode              = HAL_OSPI_SIOO_INST_EVERY_CMD;
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_RESET);
      
      if(HAL_OSPI_Command(&OSPI2Handle, &sCommand, 5000) != HAL_OK)
      {
        HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
        return false;
      }
      
      HAL_GPIO_WritePin(PROD_OSPI2_CS_PORT, PROD_OSPI2_CS_PIN, GPIO_PIN_SET);
  }

#if 0
  /* Wait till al programm/erase/write operations are done */
  /* Poll Status Register for WIP bit check */
  statusregister = 0xFF;

  while (statusregister & MT25QL512ABB_STS_WIP_MSK)
  {
    if(MT25QL512ABB_ReadStatusReg( &statusregister ) != true)
      return false;
  }
#endif
  
  return true;
}


/*******************************************************************************
 * @brief   MT25QL512ABB Initialization routine
 *
 * @note    Before calling this command SPI must be configured and enabled.
 *          -Device is put in Standby mode by relesing PowerDown mode.
 *          -It performs a Software reset.
 *          -Enables 4 byte addres mode
 *          -Disable Write operations.
 *          -Put device in PowerDown mode.
 ******************************************************************************/
bool MT25QL512ABB_Init( void )
{
  /* Relase Power Down */
  MT25QL512ABB_PowerDownRelease();
  
  /* Issue Software Reset */
  if (MT25QL512ABB_SoftReset() != true)
    return false;
    
  /* Enable Write Operations */
  if (MT25QL512ABB_WriteEnable() != true) 
    return false;
  
  /* Enable 4 Byte Address Mode */
  if (MT25QL512ABB_Enable4bAddress() != true) 
    return false;

  /* Check ID, Type and Density to see if the Flash works properly */
  uint8_t id = 0;
  uint8_t type = 0;
  uint8_t density = 0;
  
  if (MT25QL512ABB_ReadID( &id, &type, &density )!= true)
    return false;
  
  if( (id != MT25QL512ABB_MAN_ID)               ||
      (type != MT25QL512ABB_MEM_TYPE)           ||
      (density != MT25QL512ABB_MEM_DENSITY)     
    )
    return false;
  
  /* Enter  Power down mode */
  if (MT25QL512ABB_PowerDownEnter() != true)
    return false;

  return true;
}

#endif //_MT25QL512ABB_H_