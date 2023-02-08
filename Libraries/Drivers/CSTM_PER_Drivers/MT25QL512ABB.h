/*******************************************************************************
 * @file        : MT25QL512ABB.h
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
 *      This driver has been modified to be compatible with IS25LP512M
 ******************************************************************************/

#ifndef _MT25QL512ABB_H_
#define _MT25QL512ABB_H_

#define MT25QL512ABB_CAP_BIT            (1024UL*1024UL*512UL)
#define MT25QL512ABB_CAP_BYTE           (MT25QL512ABB_CAP_BIT)/8

#define MT25QL512ABB_SEG0_START       0x00000000
#define MT25QL512ABB_SEG0_END         0x00FFFFFF
#define MT25QL512ABB_SEG1_START       0x01000000
#define MT25QL512ABB_SEG1_END         0x01FFFFFF
#define MT25QL512ABB_SEG2_START       0x02000000
#define MT25QL512ABB_SEG2_END         0x02FFFFFF
#define MT25QL512ABB_SEG3_START       0x03000000
#define MT25QL512ABB_SEG3_END         0x03FFFFFF
#define MT25QL512ABB_CHIP_END         MT25QL512ABB_SEG3_END

#define MT25QL512ABB_SIZE               16              // Actual size in bytes is 2^[MT25QL512ABB_SIZE+1]

// for Micron FLASH chip
#define MT25QL512ABB_MAN_ID             0x20
#define MT25QL512ABB_MEM_TYPE           0xBA
#define MT25QL512ABB_MEM_DENSITY        0x20

// for both ISSI FLASH chip
#define IS25LP512M_MAN_ID               0x9D
#define IS25LP512M_MEM_TYPE             0x60
#define IS25LP512M_MEM_DENSITY          0x1A

#define MT25QL512ABB_END_ADDR           MT25QL512ABB_CAP_BYTE-1                                 // Byte Address

#define MT25QL512ABB_PAGE_SIZE_BYTE             256UL                                                   // Page Size in bytes
#define MT25QL512ABB_N_PAGES                    MT25QL512ABB_CAP_BYTE/(MT25QL512ABB_PAGE_SIZE_BYTE)     // Number of Pages in memory

#define MT25QL512ABB_4KSECTOR_SIZE_BYTE         4UL*1024UL                                              // Sector Size in bytes
#define MT25QL512ABB_N_4KSECTORS                MT25QL512ABB_CAP_BYTE/(MT25QL512ABB_4KSECTOR_SIZE_BYTE) // Number of Sectors in memory

#define MT25QL512ABB_32KSECTOR_SIZE_BYTE        32UL*1024UL                                              // Sector Size in bytes
#define MT25QL512ABB_N_32KSECTORS               MT25QL512ABB_CAP_BYTE/(MT25QL512ABB_32KSECTOR_SIZE_BYTE) // Number of Sectors in memory

#define MT25QL512ABB_64KSECTOR_SIZE_BYTE        64UL*1024UL                                              // Sector Size in bytes
#define MT25QL512ABB_N_64KSECTORS               MT25QL512ABB_CAP_BYTE/(MT25QL512ABB_64KSECTOR_SIZE_BYTE) // Number of Sectors in memory

// Command table
typedef enum
{
  // Software Reset
  MT25QL512ABB_RESET_EANBLE             = 0x66,                 // Both Micron and ISSI
  MT25QL512ABB_RESET_MEM                = 0x99,                 // Both Micron and ISSI                 
  
  // Read ID
  MT25QL512ABB_READ_ID                  = 0x9F,			// 0x9E is for Micron    0x9F for ISSI
  MT25QL512ABB_MIO_READ_ID              = 0xAF,                 // Both Micron and ISSI
  MT25QL512ABB_READ_DISC_PARAM          = 0x5A,                 // Both Micron and ISSI

  // Read Operations with 4-Byte Address Mode
  MT25QL512ABB_4B_READ                  = 0x13,                 // Both Micron and ISSI
  MT25QL512ABB_4B_FASTREAD              = 0x0C,                 // Both Micron and ISSI
  MT25QL512ABB_4B_DTR_FASTREAD          = 0x0E,                 // Both Micron and ISSI
  
  // Write Operation
  MT25QL512ABB_WRITE_ENABLE             = 0x06,                 // Both Micron and ISSI
  MT25QL512ABB_WRITE_DISABLE            = 0x04,                 // Both Micron and ISSI

  // Programm Operations with 4-Byte Address Mode
  MT25QL512ABB_4B_PROG_PAGE             = 0x12,
  MT25QL512ABB_4B_FASTPROG_4I           = 0x34,
  MT25QL512ABB_4B_FASTPROG_EXT_4I       = 0x3E,
  
  // Erase Operations with 4-Byte Address Mode
  MT25QL512ABB_4B_ERASE_4K              = 0x21,                 // Both Micron and ISSI
  MT25QL512ABB_4B_ERASE_32K             = 0x5C,                 // Both Micron and ISSI
  MT25QL512ABB_4B_ERASE_64K             = 0xDC,                 // Both Micron and ISSI
  MT25QL512ABB_4B_ERASE_CHIP            = 0xC7,                 // Both Micron and ISSI (can use 0x60 as well)
  
  // 4 Byte Address Mode
  MT25QL512ABB_4BYTE_ADDR_ENTER         = 0xB7,                 // Both Micron and ISSI
  MT25QL512ABB_4BYTE_ADDR_EXIT          = 0xE9,                 // Both Micron
  
  // Quad Protocol
  MT25QL512ABB_4IO_MODE_ENTER           = 0x35,                 // Both Micron and ISSI
  MT25QL512ABB_4IO_MODE_EXIT            = 0xF5,                 // Both Micron and ISSI
  
  // Register Operation
  MT25QL512ABB_READ_STATUS_REG          = 0x05,                 // Both Micron and ISSI                 
  MT25QL512ABB_WRITE_STATUS_REG         = 0x01,                 // Both Micron and ISSI
  
  // Deep Power Down Operation
  MT25QL512ABB_PWR_DWN_ENTER            = 0xB9,                 // Both Micron and ISSI
  MT25QL512ABB_PWR_DWN_RELEASE          = 0xAB,                 // Both Micron and ISSI
  
}MT25QL512ABB_CMD_t;

/* Status Register Bit Definitions and Masks */
#define MT25QL512ABB_STS_WIP_MSK        0x01    // Status Regiter WIP (Write in Progress bit)
#define MT25QL512ABB_STS_WIP_SHT        0       // Status Regiter WIP (Write in Progress bit) position
#define MT25QL512ABB_STS_QE_MSK         0x40    // Status Regiter WIP (Write in Progress bit)
// AC specs
#define TIME_DP_US                      10UL    // CS# High to Deep Power Down Mode
#define TIME_RDP_US                     30UL    // Delay time for Release from Deep Power-Down Mode once entering Deep Power-Down mode

/*******************************************************************************
 * @brief   Functions
 ******************************************************************************/

/*******************************************************************************
 * @brief   Deep Power Down Release
 *
 * @note    
 ******************************************************************************/
bool MT25QL512ABB_PowerDownRelease( void );

/*******************************************************************************
 * @brief   Deep Power Down Enter
 *
 * @note    This is a blocking rountine till entire PowerDown enter mode timing,
 *          including tDP.
 *          Before executing PowerDown enter the routine waits completition of 
 *          any ongoing Program/Write/Erase operation.
 ******************************************************************************/
bool MT25QL512ABB_PowerDownEnter( void );

/*******************************************************************************
 * @brief   Write Status register
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteStatusReg( uint8_t data );

/*******************************************************************************
 * @brief   Read Status register
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_ReadStatusReg( uint8_t* data);

/*******************************************************************************
 * @brief   Enable 4byte address mode
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Enable4bAddress( void );

/*******************************************************************************
 * @brief   Disable 4byte address mode
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Disable4bAddress( void );

/*******************************************************************************
 * @brief   Read ID register
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_ReadID( uint8_t *manufacturerId, uint8_t *type, uint8_t *density );

/*******************************************************************************
 * @brief   Write Enable
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteEnable( void );

/*******************************************************************************
 * @brief   Write Disable
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteDisable( void );

/*******************************************************************************
 * @brief   Software Reset
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_SoftReset( void );

/*******************************************************************************
 * @brief   1 x I/O Read number of byte (size) starting from address and saves
 *          in data buffer (read_data)
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Read1I1O( uint32_t address, uint32_t size, void * read_data );

/*******************************************************************************
 * @brief   1 x I/O Write number of byte (size) starting from address.
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_WriteNPage1I1O( uint32_t address, uint32_t size, void * write_data );

/*******************************************************************************
 * @brief   Erase 4k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase4kSector( uint32_t address );

/*******************************************************************************
 * @brief   Erase 32k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase32kSector( uint32_t address );

/*******************************************************************************
 * @brief   Erase 64k Sector
 *
 * @note    Before calling this command SPI must be configured, enabled and in 
 *          Stanby-mode.
 ******************************************************************************/
bool MT25QL512ABB_Erase64kSector( uint32_t address );

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
bool MT25QL512ABB_Init( void );

/*******************************************************************************
 * @brief   QSPI_Enable
 *
 * @note    Swtich from SPI to QSPI
 * 
 ******************************************************************************/
bool MT25QL512ABB_QSPI_Enable( void );

/*******************************************************************************
 * @brief   QSPI_Disable
 *
 * @note    Swtich from QSPI to SPI
 * 
 ******************************************************************************/
bool MT25QL512ABB_QSPI_Disable( void );
#endif //_MT25QL512ABB_H_