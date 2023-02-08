/*******************************************************************************
 * @file        : 24CWxxX.h
 * @brief       : Low Level Driver for 24CWxxX EEPROM on I2C System BUS.
 *                This driver uses the HAL I2C driver of STMCUBE MX.
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 * 	The 24CWxxX is build on the I2C system bus.
 *
 ******************************************************************************/

#ifndef _24CWXXX_H_
#define _24CWXXX_H_

#if defined(EE24CW16X) && ( EE24CW16X == 1 )            //16kbit

  #define EE24CWxxX_CAP_KBIT            16UL
  #define EE24CWxxX_CAP_BIT             (EE24CWxxX_CAP_KBIT*1024UL)
  #define EE24CWxxX_CAP_BYTE            (EE24CWxxX_CAP_BIT/8)
  #define EE24CWxxX_PAGE_SIZE           32UL
  #define EE24CWxxX_I2C_ADDR            0x00A0

#elif defined(EE24CW32X) && ( EE24CW32X == 1 )          //32kbit

  #define EE24CWxxX_CAP_KBIT            32UL
  #define EE24CWxxX_CAP_BIT             (EE24CWxxX_CAP_KBIT*1024UL)
  #define EE24CWxxX_CAP_BYTE            (EE24CWxxX_CAP_BIT/8)
  #define EE24CWxxX_PAGE_SIZE           32UL
  #define EE24CWxxX_I2C_ADDR            0x00A0

#elif defined(EE24CW64X) && ( EE24CW64X == 1 )          //64kbit

  #define EE24CWxxX_CAP_KBIT            64UL
  #define EE24CWxxX_CAP_BIT             (EE24CWxxX_CAP_KBIT*1024UL)
  #define EE24CWxxX_CAP_BYTE            (EE24CWxxX_CAP_BIT/8)
  #define EE24CWxxX_PAGE_SIZE           32UL
  #define EE24CWxxX_I2C_ADDR            0x00A0

#elif defined(EE24CW128X) && ( EE24CW128X == 1 )        //128kbit

  #define EE24CWxxX_CAP_KBIT            128UL
  #define EE24CWxxX_CAP_BIT             (EE24CWxxX_CAP_KBIT*1024UL)
  #define EE24CWxxX_CAP_BYTE            (EE24CWxxX_CAP_BIT/8)
  #define EE24CWxxX_PAGE_SIZE           32UL
  #define EE24CWxxX_I2C_ADDR            0x00A0  

#endif

/******************************************************************************
 * @brief   Writes a single byte (write_data) in EEPROM at given address.
 *
 * @note    Returns true if operation succeeds   
 *
 ******************************************************************************/
bool EE24CWxxX_WriteSingleByte( uint16_t eeprom_addr, uint8_t write_data );

/******************************************************************************
 * @brief   Reads a single byte in EEPROM at given address.
 *
 * @note    Returns true if operation succeeds  
 *
 ******************************************************************************/
bool EE24CWxxX_ReadSingleByte( uint16_t eeprom_addr, uint8_t *read_data );

/******************************************************************************
 * @brief   Writes a certian number of bytes (size) from data/buffer (write_data) 
 *          in EEPROM starting from eeprom_addr.
 *
 * @note    Returns true if operation succeeds    
 *
 ******************************************************************************/
bool EE24CWxxX_WriteNBytes( uint16_t eeprom_addr, void * write_data, uint16_t size );

/******************************************************************************
 * @brief   Reads a certian number of bytes (size) from EEPROM starting from 
 *          eeprom_addr and saves in data buffer (read_data). 
 *
 * @note    Returns true if operation succeeds   
 *
 ******************************************************************************/
bool EE24CWxxX_ReadNBytes( uint16_t eeprom_addr, void * read_data , uint16_t size );

/******************************************************************************
 * @brief   Erase entire Chip by page size.
 *
 * @note    Erase means that each byte in section is set at 0xFF.
 *          This takes more than 6 seconds with I2C at 100KHz.
 *
 ******************************************************************************/
bool EE24CWxxX_EraseChip( void );

/******************************************************************************
 * @brief   Initiliaze entire Chip by page size at init_value.
 *
 * @note    This takes more than 6 seconds with I2C at 100KHz.
 *
 ******************************************************************************/
bool EE24CWxxX_InitChip( uint8_t init_value );

/******************************************************************************
 * @brief   Erase an EEPROM Section strarting from address start_address(included)
 *          and ending at end_address(included).
 *
 * @note    Erase means that each byte in section is set at 0xFF. 
 *
 ******************************************************************************/
bool EE24CWxxX_EraseSection( uint16_t start_address, uint16_t end_address );

/******************************************************************************
 * @brief   Initialize an EEPROM Section strarting from address start_address(included)
 *          and ending at end_address(included) with init_value.
 *
 * @note     
 *
 ******************************************************************************/
bool EE24CWxxX_InitSection( uint16_t start_address, uint16_t end_address, uint8_t init_value );

/******************************************************************************
 * @brief   Makes a Test @ specific location to check proper funcitonality
 *
 * @note    Writes and read back an array of length "length" of random values. 
 *
 ******************************************************************************/
bool EE24CWxxX_Test( uint16_t start_address, uint16_t length );

#endif //_24CWXXX_H_