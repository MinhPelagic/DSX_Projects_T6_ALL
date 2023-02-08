/*******************************************************************************
 * @file        : FwUpdate.c
 * @brief       : 
 *                
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _FWUPDATE_H_

/******************************************************************************
 * @brief   Get Page of Internal Flash memory of specified Address
 *
 * @note    
 ******************************************************************************/
static uint32_t GetPage(uint32_t Addr)
{
  uint32_t page = 0;
  
  if (Addr < (FLASH_BASE + FLASH_BANK_SIZE))
  {
    /* Bank 1 */
    page = (Addr - FLASH_BASE) / FLASH_PAGE_SIZE;
  }
  else
  {
    /* Bank 2 */
    page = (Addr - (FLASH_BASE + FLASH_BANK_SIZE)) / FLASH_PAGE_SIZE;
  }
  
  return page;
}

/******************************************************************************
 * @brief   Get Bank of Internal Flash memory of specified Address
 *
 * @note    
 ******************************************************************************/
/*
static uint32_t GetBank(uint32_t Addr)
{
  uint32_t bank = 0;
  
  if (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE) == 0)
  {
    // No Bank swap
    if (Addr < (FLASH_BASE + FLASH_BANK_SIZE))
    {
      bank = FLASH_BANK_1;
    }
    else
    {
      bank = FLASH_BANK_2;
    }
  }
  else
  {
    //Bank swap
    if (Addr < (FLASH_BASE + FLASH_BANK_SIZE))
    {
      bank = FLASH_BANK_2;
    }
    else
    {
      bank = FLASH_BANK_1;
    }
  }
  
  return bank;
}
*/

/******************************************************************************
 * @brief   Set Vector Table at given address with specified offset
 *
 * @note    
 ******************************************************************************/
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
{ 
  SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
}

/******************************************************************************
 * @brief   Jump to Application Section
 *
 * @note    
 ******************************************************************************/
void StartApplication(void)
{
  volatile uint32_t stackAddr=0;
  volatile uint32_t jumpAddr=0;
  FuncPtr startApp;
    
  stackAddr = *(__IO uint32_t*)APPLICATION_START;
    
  jumpAddr = *(__IO uint32_t*) (APPLICATION_START + 4);
  startApp = (FuncPtr) jumpAddr;
  
  /* Initialize user application's Stack Pointer */
  __set_MSP(stackAddr);
  
  startApp();
}

/******************************************************************************
 * @brief   Reset System to start Bootloader
 *
 * @note    
 ******************************************************************************/
void StartBootloader(void)
{
  HAL_NVIC_SystemReset();
}

/******************************************************************************
 * @brief   Erase Internal Flash Application Section
 *
 * @note    
 ******************************************************************************/
bool IntFlashErase_Application(void)
{
  // Unlock the Flash to enable the flash control register access
  HAL_FLASH_Unlock();
  
  // Clear OPTVERR bit set on virgin samples
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);
  // Clear PEMPTY bit set (as the code is executed from Flash which is not empty)
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_PEMPTY) != 0)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_PEMPTY);
  
  uint32_t FirstPage = 0;
  uint32_t NbOfPages = 0;
  uint32_t PageError = 0;
  
  // Variable used for Erase procedure
  FLASH_EraseInitTypeDef EraseInitStruct;

  // Get the 1st page to erase
  FirstPage = GetPage(APPLICATION_START);
  
  // Get the number of pages to erase from 1st page in Bank1
  NbOfPages = GetPage(0x08100000 - 1) - FirstPage + 1;
  
  // Set EraseInit structure for Bank 1
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.Banks       = FLASH_BANK_1;
  EraseInitStruct.Page        = FirstPage;
  EraseInitStruct.NbPages     = NbOfPages;
  
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)
  {
    HAL_FLASH_Lock();
    return false;
  }

  if(PageError != 0xFFFFFFFF)
    return false;
  
  // Set EraseInit structure for Bank 2
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.Banks       = FLASH_BANK_2;
  EraseInitStruct.Page        = 0x08100000;
  EraseInitStruct.NbPages     = 256;
  
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)
  {
    HAL_FLASH_Lock();
    return false;
  }
  
  // Lock the Flash
  HAL_FLASH_Lock();
  
  if(PageError != 0xFFFFFFFF)
    return false;

  return true;
}


/******************************************************************************
 * @brief   Program Data in Internal Flash Application Section at 
 *          Sepcified Address
 *
 * @note    
 ******************************************************************************/
bool IntFlashWrite_Application(uint32_t Address, uint32_t Data)
{
  // Unlock the Flash to enable the flash control register access
  HAL_FLASH_Unlock();
  
  
  
  
  /*
    uint32_t Address = APPLICATION_START;
    
  while (Address < INTERNAL_FLASH_END_ADDR)
  {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, 0x8899AABBCCDDEEFF) == HAL_OK)
      Address = Address + 8;
  }
  */
  
  // Lock the Flash
  HAL_FLASH_Lock();
  
  return true;
}


/******************************************************************************
 * @brief   Update BootRecord with specified Ststus and write back to ExFlash
 *
 * @note    This must be called only form Bootloader
 ******************************************************************************/
void UpdateBootRec_FromBootloader(BootRecord_t *BootRec, uint8_t status)
{
  BootRec->FwUpdateStat = status;
  
  uint16_t NewCrc = 0xFFFF;
  int retry;
    
  NewCrc = Eval_CRC16(BootRec, sizeof(BootRecord_t)-2);
 
  BootRec->BootRecCrc = NewCrc;
  
  retry = NVD_FLASH_WRITE_TIMEOUT;    
  do{} while((MT25QL512ABB_Erase4kSector(BOOTRECORD_ADDR)!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }
        
  retry = NVD_FLASH_WRITE_TIMEOUT;    
  do{} while ((MT25QL512ABB_WriteNPage1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), BootRec )!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }        
}

/******************************************************************************
 * @brief   Get BootRecord
 *
 * @note    This must be called only form Application
 ******************************************************************************/
void GetBootRec_FromApp(BootRecord_t *BootRec)
{
  int8_t retry;
  
  /* PowerOn External Flash */
  L4X9_QSPI_Init();
  MT25QL512ABB_PowerDownRelease();
  
  retry = NVD_FLASH_READ_TIMEOUT;    
  do{} while((MT25QL512ABB_Read1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), BootRec)!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }
  
  /* PowerDown External Flash */
  while (MT25QL512ABB_PowerDownEnter() != true){};
  L4X9_QSPI_DeInit();
}

/******************************************************************************
 * @brief   Update BootRecord with specified Ststus and write back to ExFlash
 *
 * @note    This must be called only form Application
 ******************************************************************************/
void UpdateBootRec_FromApp(uint8_t status)
{
  int8_t retry;
  
  /* PowerOn External Flash */
  L4X9_QSPI_Init();
  MT25QL512ABB_PowerDownRelease();
  
  BootRecord_t BootRec;
  
  retry = NVD_FLASH_READ_TIMEOUT;    
  do{} while((MT25QL512ABB_Read1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), &BootRec)!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }

  BootRec.FwUpdateStat = status;
  
  uint16_t NewCrc = 0xFFFF;
  
  NewCrc = Eval_CRC16(&BootRec, sizeof(BootRecord_t)-2);
 
  BootRec.BootRecCrc = NewCrc;
  
  retry = NVD_FLASH_WRITE_TIMEOUT;    
  do{} while((MT25QL512ABB_Erase4kSector(BOOTRECORD_ADDR)!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }

  retry = NVD_FLASH_WRITE_TIMEOUT;    
  do{} while ((MT25QL512ABB_WriteNPage1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), &BootRec )!= true) && (retry-- > 0));		// Timeout added from R1006        
  if(retry <= 0)
  {
      ErrHandle_FLASH();
  }
  
  /* PowerDown External Flash */
  while (MT25QL512ABB_PowerDownEnter() != true){};
  L4X9_QSPI_DeInit();
}

/******************************************************************************
 * @brief   Check if FW in ExtFlash is good
 *
 * @note
 ******************************************************************************/
bool IsFwOnExFlashGood(BootRecord_t BootRec)
{
  uint16_t ExFlashCrc16 = 0xFFFF;
  uint32_t length = 0;
  uint8_t fwchunk [256];
  int8_t retry;
  
  // Loop on buffer 
  while (length < BootRec.FwLength)
  {
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while((MT25QL512ABB_Read1I1O( BootRec.FwAddress+length, 256, fwchunk)!= true) && (retry-- > 0));		// Timeout added from R1006        
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    ExFlashCrc16 = Eval_SeedCRC16(fwchunk, 256, ExFlashCrc16);
    
    length += 256;
  }
    
  if( ExFlashCrc16 != BootRec.FwCrc )
    return false;
  else
    return true;
}


#endif