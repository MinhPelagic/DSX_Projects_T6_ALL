/*******************************************************************************
 * @file        : FwUpdate.h
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
   
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _FWUPDATE_H_
#define _FWUPDATE_H_

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

// BootRecord address in ExtFlash
#define BOOTRECORD_ADDR               0x00000000

// Bootloader Section Start Address in Internal Flash 
#define BOOTLOADER_START                0x08000000

// Application Section Start Address in Internal Flash 
#define APPLICATION_START		0x08008000

// Internal Flash end address
#define INTERNAL_FLASH_END_ADDR         ADDR_FLASH_PAGE_511 + FLASH_PAGE_SIZE - 1   /* End @ of user Flash area */

// BootRecord address in ExtFlash
#define WAYFINDER_LOCATION_ADDR         0x11320000


/*******************************************************************************
 * @brief   Data structures
 ******************************************************************************/

#define NO_FW                   0x00    // ExFlash has NO firmware on it (Same as 0xFF)
#define NONE_FW                 0xFF    // ExFlash has NO firmware on it (Same as 0x00)
#define IFLASH_TO_UPDATE        0x01    // Bootloader has started IFlash update
#define IFLASH_DONE             0x02    // Bootloader has finished IFlash update
#define FW_RUN_OK               0x03    // New FW runs 1st time OK
#define FW_EXTFLASH_ERR         0x10    // ExFlash Firmware Corrupted (redo firmware loading from BLE or USB)
#define FW_INFLASH_ERR          0x11    // Internal Flash Firmware Corrupted (redo firmware programming from ExFLASH)
#define OTHER_ERR               0x12    // Other Errors
   
/* Boot Record Structure */
typedef struct
{
  uint32_t FwAddress;           // FW Flash Address
  uint32_t FwLength;            // FW Length in bytes
  uint16_t FwCrc;               // FW CRC value
  uint8_t FwUpdateStat;         // BootRecord Update Status
  uint8_t UpdateRetries;        // Number of times Bootloader has tried to update
  uint32_t reserved1;
  uint32_t reserved2;
  uint32_t reserved3;
  uint16_t reserved4;
  uint16_t BootRecCrc;          // BootRecord CRC
} BootRecord_t;

/* Pointer to Function */
typedef  void (*FuncPtr)(void);


/*******************************************************************************
 * @brief   Functions
 ******************************************************************************/

/******************************************************************************
 * @brief   Set Vector Table at given address with specified offset
 *
 * @note    
 ******************************************************************************/
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);

/******************************************************************************
 * @brief   Jump to Application Section
 *
 * @note    
 ******************************************************************************/
void StartApplication(void);

/******************************************************************************
 * @brief   Reset System to start Bootloader
 *
 * @note    
 ******************************************************************************/
void StartBootloader(void);

/******************************************************************************
 * @brief   Erase Internal Flash Application Section
 *
 * @note    
 ******************************************************************************/
bool IntFlashErase_Application(void);

/******************************************************************************
 * @brief   Program Data in Internal Flash Application Section at 
 *          Sepcified Address
 *
 * @note    
 ******************************************************************************/
bool IntFlashWrite_Application(uint32_t Address, uint32_t Data);


/******************************************************************************
 * @brief   Update BootRecord with specified Ststus and write back to ExFlash
 *
 * @note    This must be called only form Bootloader
 ******************************************************************************/
void UpdateBootRec_FromBootloader(BootRecord_t *BootRec, uint8_t status);

/******************************************************************************
 * @brief   Get BootRecord
 *
 * @note    This must be called only form Application
 ******************************************************************************/
void GetBootRec_FromApp(BootRecord_t *BootRec);

/******************************************************************************
 * @brief   Update BootRecord with specified Ststus and write back to ExFlash
 *
 * @note    This must be called only form Application
 ******************************************************************************/
void UpdateBootRec_FromApp(uint8_t status);


/******************************************************************************
 * @brief   Check if FW in ExtFlash is good
 *
 * @note
 ******************************************************************************/
bool IsFwOnExFlashGood(BootRecord_t BootRec);


#endif // _FWUPDATE_H_