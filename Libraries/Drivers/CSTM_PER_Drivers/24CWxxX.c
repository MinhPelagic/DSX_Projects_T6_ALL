/*******************************************************************************
 * @file        : 24CWxxX.c
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

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _24CWXXX_H_

#define EEPROM_I2C      I2C_BUS_A

/******************************************************************************
 * @brief   Writes a single byte (write_data) in EEPROM at given address.
 *
 * @note    Returns true if operation succeeds   
 *
 ******************************************************************************/
bool EE24CWxxX_WriteSingleByte( uint16_t eeprom_addr, uint8_t write_data )
{
  uint8_t I2C_TxBuffer[32];

  /* Write EEPROM address in the I2C TX Buffer */
  I2C_TxBuffer[0] = (uint8_t)(eeprom_addr>>8);
  I2C_TxBuffer[1] = (uint8_t)(eeprom_addr&0x00FF);
  
  /* Write data to Transmit to TX buffer */
  I2C_TxBuffer[2] = write_data;
  
  /* Wait for Memory Ready */
  int32_t retry = 100;  
  do {} while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
  
  if(retry > 0)    
  {
      /* Try to Transmit Data */
      retry = 3;
      do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, 3, 10000) != HAL_OK) && (retry-- > 0) );
      
      if(retry > 0)
        return true;    // Transmit OK
      else
        return false;   // Transmit NOT OK after trying multiple times
  }
  else
      return false; // WriteSingleByte is NOT processed due to communication bus NOT READY YET
}

/******************************************************************************
 * @brief   Reads a single byte in EEPROM at given address.
 *
 * @note    Returns true if operation succeeds  
 *
 ******************************************************************************/
bool EE24CWxxX_ReadSingleByte( uint16_t eeprom_addr, uint8_t *read_data )
{
  uint8_t I2C_TxBuffer[32];
  uint8_t I2C_RxBuffer[32];
  int32_t retry;
    
  /* Write EEPROM address in the I2C TX Buffer */
  I2C_TxBuffer[0] = (uint8_t)(eeprom_addr>>8);
  I2C_TxBuffer[1] = (uint8_t)(eeprom_addr&0x00FF);

  retry = 100;
  /* Check if I2C Bus Ready to Use? */      
  do {} while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) == HAL_OK) && (retry-- > 0) );
  
  if(retry > 0)    
  {
      /* Try to Transmit Address of Data Byte to read and wait for Memory Ready*/
      retry = 3;
      do{  } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, 2, 10000) != HAL_OK) && (retry-- > 0) );
      
      if(retry > 0)
      {
          /* Try to Read Data */
          retry = 3;
          do{  } while ( (HAL_I2C_Master_Receive(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_RxBuffer, 1, 10000)!= HAL_OK) && (retry-- > 0) );
          
          if(retry > 0)
          {
              /* Assign read data from Rx buffer */
              (*read_data) = I2C_RxBuffer[0];
              
              return true;    // Transmit and Receive OK
          }
      }
  }
  return false;         // Transmit or Receive NOT OK
}

/******************************************************************************
 * @brief   Writes a certian number of bytes (size) from data/buffer (write_data) 
 *          in EEPROM starting from eeprom_addr.
 *
 * @note    Returns true if operation succeeds    
 *
 ******************************************************************************/
bool EE24CWxxX_WriteNBytes( uint16_t eeprom_addr, void * write_data, uint16_t size )
{
  uint8_t I2C_TxBuffer[64];
  
  uint16_t data_to_tx = size;
  uint16_t data_sent = 0;
  uint16_t chunk_size = 0;
  uint16_t current_addr = eeprom_addr;
  uint8_t *ptr = write_data;
  int32_t retry;
  
  /* Check if we are on page boundary */
  if( (((uint32_t)eeprom_addr)%EE24CWxxX_PAGE_SIZE) == 0 )      // On page boundary use optimized function
  {
    while ( data_to_tx > 0 )
    {
      /* Write data to Transmit to TX buffer */
      if(data_to_tx >= (uint16_t)EE24CWxxX_PAGE_SIZE)
      {
        memcpy(&I2C_TxBuffer[2], ptr+data_sent, EE24CWxxX_PAGE_SIZE);
        chunk_size = (uint16_t)EE24CWxxX_PAGE_SIZE;
        data_sent += (uint16_t)EE24CWxxX_PAGE_SIZE;
        data_to_tx -= (uint16_t)EE24CWxxX_PAGE_SIZE;
      }
      else
      {
        memcpy(&I2C_TxBuffer[2], ptr+data_sent, data_to_tx);
        chunk_size = data_to_tx;
        data_sent += data_to_tx;
        data_to_tx = 0;
      }
      
      /* Write EEPROM address in the I2C TX Buffer */
      I2C_TxBuffer[0] = (uint8_t)(current_addr>>8);
      I2C_TxBuffer[1] = (uint8_t)(current_addr&0x00FF);
      
      /* Check if I2C Bus Ready to Use? */
      retry = 1000;
      do {} while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
      
      if(retry > 0)
      {
          /* Try to Transmit Data */
          retry = 3;
          do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, (chunk_size+2), 10000) != HAL_OK) && (retry-- > 0) );
      
          if(retry > 0)
          {
              /* Increment address for next iteration */
              current_addr += (uint16_t)(EE24CWxxX_PAGE_SIZE);              
          }
      }
      
      if(retry <= 0)
      {
          data_to_tx = 0;       // stop the while loop
          return false;         // get out of the subroutine
      }
    }
    
    if(retry > 0)
        return true;
    else
        return false;
  }
  else  // Not on page boundary
  {
    /* Get free size on current page */
    uint16_t free_on_currentpage = (uint16_t)EE24CWxxX_PAGE_SIZE - (uint16_t)(((uint32_t)eeprom_addr)%EE24CWxxX_PAGE_SIZE);
    
    if( data_to_tx > free_on_currentpage )
      chunk_size = free_on_currentpage;
    else
      chunk_size = data_to_tx;
      
    /* Write data to Transmit to TX buffer */
    memcpy(&I2C_TxBuffer[2], ptr, chunk_size);
    
    /* Write EEPROM address in the I2C TX Buffer */
    I2C_TxBuffer[0] = (uint8_t)(current_addr>>8);
    I2C_TxBuffer[1] = (uint8_t)(current_addr&0x00FF);
    
    /* Try to Transmit Data */
    retry = 1000;
    do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
    
    if(retry > 0)    
    {
        /* Try to Transmit Data */
        retry = 3;
        do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, (chunk_size+2), 10000) != HAL_OK) && (retry-- > 0) );
    
        if(retry > 0)
        {
            if(data_to_tx > chunk_size)
              data_to_tx -= chunk_size;
            else
              data_to_tx = 0;
            
            data_sent += chunk_size;
            current_addr += chunk_size;
            
            /* Now we are on page boundary */
            while ( data_to_tx > 0 )
            {
                /* Write data to Transmit to TX buffer */
                if(data_to_tx >= (uint16_t)EE24CWxxX_PAGE_SIZE)
                {
                  memcpy(&I2C_TxBuffer[2], ptr+data_sent, EE24CWxxX_PAGE_SIZE);
                  chunk_size = (uint16_t)EE24CWxxX_PAGE_SIZE;
                  data_sent += (uint16_t)EE24CWxxX_PAGE_SIZE;
                  data_to_tx -= (uint16_t)EE24CWxxX_PAGE_SIZE;
                }
                else
                {
                  memcpy(&I2C_TxBuffer[2], ptr+data_sent, data_to_tx);
                  chunk_size = data_to_tx;
                  data_sent += data_to_tx;
                  data_to_tx = 0;
                }
                
                /* Write EEPROM address in the I2C TX Buffer */
                I2C_TxBuffer[0] = (uint8_t)(current_addr>>8);
                I2C_TxBuffer[1] = (uint8_t)(current_addr&0x00FF);
                
                /* Try to Transmit Data */
                retry = 3;
                do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, (chunk_size+2), 10000) != HAL_OK) && (retry-- > 0) );
                
                if(retry > 0)
                {
                    /* Increment address for next iteration */
                    current_addr += (uint16_t)(EE24CWxxX_PAGE_SIZE);                    
                }
                else
                {
                    data_to_tx = 0;       // stop the while loop
                    return false;         // get out of the subroutine
                }
            }
        }
        else
            return false;
    }
    
    if(retry > 0)
        return true;
    else
        return false;       // get out of the subroutine
  }
}

/******************************************************************************
 * @brief   Reads a certian number of bytes (size) from EEPROM starting from 
 *          eeprom_addr and saves in data buffer (read_data). 
 *
 * @note    Returns true if operation succeeds   
 *
 ******************************************************************************/
bool EE24CWxxX_ReadNBytes( uint16_t eeprom_addr, void * read_data, uint16_t size )
{
  uint8_t I2C_TxBuffer[512];
  uint8_t I2C_RxBuffer[512];
  
  uint16_t buffersize = 512;
  uint16_t read_size = size;
  uint16_t data_read = 0;
  uint16_t data_to_read = buffersize;
  uint8_t *ptr = read_data;
  uint16_t current_addr = eeprom_addr;
  uint32_t ErrCnt = 0;
  int32_t retry = 0;
  
  /* Write EEPROM address in the I2C TX Buffer */
  I2C_TxBuffer[0] = (uint8_t)(current_addr>>8);
  I2C_TxBuffer[1] = (uint8_t)(current_addr&0x00FF);
  
  if( read_size <= (uint16_t)buffersize )
  {
      /* Check if I2C Bus Ready to Use? */
      retry = 1000;
      do {} while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
      
      if(retry > 0)
      {
          retry = 3;
          do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, 2, 10000) != HAL_OK) && (retry-- > 0) );
          
          if(retry > 0)
          {
              /* Try to Read Data */
              retry = 100;
              do{ } while ( (HAL_I2C_Master_Receive(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_RxBuffer, size, 10000)!= HAL_OK) && (retry-- > 0) );
              
              if(retry > 0)
              {
                  /* Assign read data from Rx buffer */
                  memcpy(read_data, I2C_RxBuffer, size);
              }
              else
                  return false;
          
          }
          else            
            return false;          
      }
  }
  else
  {
      while ( read_size > 0 )
      {
          /* Check if I2C Bus Ready to Use? */
          retry = 1000;
          do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
          
          if(retry > 0)
          {
              retry = 3;
              do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, 2, 10000) != HAL_OK) && (retry-- > 0) );
              
              if(retry > 0)
              {
                  /* Try to Read Data */
                  retry = 100;
                  do{ } while ( (HAL_I2C_Master_Receive(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_RxBuffer, data_to_read, 10000)!= HAL_OK) && (retry-- > 0) );
                  
                  if(retry > 0)
                  {
                      /* Assign read data from Rx buffer */
                      memcpy(ptr+data_read, I2C_RxBuffer, data_to_read);
                      
                      data_read += data_to_read;
                      
                      current_addr += data_to_read;
                      
                      read_size -= data_to_read;
                      
                      if( read_size > buffersize )
                        data_to_read = buffersize;
                      else
                        data_to_read = read_size;
                      
                      /* Write EEPROM address in the I2C TX Buffer */
                      I2C_TxBuffer[0] = (uint8_t)(current_addr>>8);
                      I2C_TxBuffer[1] = (uint8_t)(current_addr&0x00FF);
                  }
              }
          }
          
          if(retry <= 0)
          {
              return false;
          }
      }     
  }
  
  if(retry > 0)
      return true;
  else
      return false;
}


/******************************************************************************
 * @brief   Erase entire Chip by page size.
 *
 * @note    Erase means that each byte in section is set at 0xFF.
 *          This takes more than 6 seconds with I2C at 100KHz.
 *
 ******************************************************************************/
bool EE24CWxxX_EraseChip( void )
{
  uint8_t I2C_TxBuffer[64];
  
  uint16_t eeprom_addr = 0;
  int32_t retry = 0;
  
  /* Set Tx buffer at Erase Value for one EEPROM Page */
  memset(&I2C_TxBuffer[2], 0xFF, EE24CWxxX_PAGE_SIZE);
         
  for(uint32_t page = 0; page<(EE24CWxxX_CAP_BYTE/EE24CWxxX_PAGE_SIZE); page++)
  {   
    /* Write EEPROM address in the I2C TX Buffer */
    I2C_TxBuffer[0] = (uint8_t)(eeprom_addr>>8);
    I2C_TxBuffer[1] = (uint8_t)(eeprom_addr&0x00FF);
  
    /* Check if I2C Bus Ready to Use? */
    retry = 1000;
    do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
    
    if(retry > 0)
    {
        retry = 3;
        do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, (EE24CWxxX_PAGE_SIZE+2), 10000) != HAL_OK) && (retry-- > 0) );
              
        eeprom_addr += (uint16_t)(EE24CWxxX_PAGE_SIZE);      
    }
    
    if(retry <= 0)
        return false;
  }
  
  if(retry > 0)
    return true;
  else
    return false;
}

/******************************************************************************
 * @brief   Initiliaze entire Chip by page size at init_value.
 *
 * @note    This takes more than 6 seconds with I2C at 100KHz.
 *
 ******************************************************************************/
bool EE24CWxxX_InitChip( uint8_t init_value )
{
  uint8_t I2C_TxBuffer[64];
  
  uint16_t eeprom_addr = 0;
  int32_t retry = 0;
  
  /* Set Tx buffer at Init Value for one EEPROM Page (128byte)*/
  memset(&I2C_TxBuffer[2], init_value, EE24CWxxX_PAGE_SIZE);
         
  for(uint32_t page = 0; page<(EE24CWxxX_CAP_BYTE/EE24CWxxX_PAGE_SIZE); page++)
  {
    /* Write EEPROM address in the I2C TX Buffer */
    I2C_TxBuffer[0] = (uint8_t)(eeprom_addr>>8);
    I2C_TxBuffer[1] = (uint8_t)(eeprom_addr&0x00FF);
  
    /* Check if I2C Bus Ready to Use? */
    retry = 1000;
    do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
    
    if(retry > 0)
    {      
        retry = 3;
        do{ } while ( (HAL_I2C_Master_Transmit(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, (uint8_t*)I2C_TxBuffer, (EE24CWxxX_PAGE_SIZE+2), 10000) != HAL_OK) && (retry-- > 0) );
        
        if(retry <= 0)
            return false;
      
        eeprom_addr += (uint16_t)(EE24CWxxX_PAGE_SIZE);
    }
    else
        return false;
  }
  
  if(retry > 0)
      return true;
  else
      return false;
}

/******************************************************************************
 * @brief   Erase an EEPROM Section strarting from address start_address(included)
 *          and ending at end_address(included).
 *
 * @note    Erase means that each byte in section is set at 0xFF. 
 *
 ******************************************************************************/
bool EE24CWxxX_EraseSection( uint16_t start_address, uint16_t end_address )
{
  int32_t retry = 0;
  
  if ( start_address > end_address )
    return false;
  
  /* Check if I2C Bus Ready to Use? */
  retry = 1000;
  do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
  
  if(retry > 0)
  {  
      for(uint16_t ee_idx = start_address; ee_idx<=end_address; ee_idx++)
      {
        int8_t retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{} while ( !EE24CWxxX_WriteSingleByte(ee_idx, 0xFF) && (retry-- > 0) );		// modified from R1006 
        
        if(retry <= 0)
            return false;
      }
      
      if(retry > 0)
      {
          return true;
      }
      else
      {
          ErrHandle_EE();	// added from R1006
          return false;
      }
  }
  else
      return false;
}

/******************************************************************************
 * @brief   Initialize an EEPROM Section strarting from address start_address(included)
 *          and ending at end_address(included) with init_value.
 *
 * @note     
 *
 ******************************************************************************/
bool EE24CWxxX_InitSection( uint16_t start_address, uint16_t end_address, uint8_t init_value )
{
  int32_t retry = 0;
  
  if ( start_address > end_address )
    return false;
 
  /* Check if I2C Bus Ready to Use? */
  retry = 1000;
  do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
  
  if(retry > 0)
  {
      for(uint16_t ee_idx = start_address; ee_idx<=end_address; ee_idx++)
      {
        retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{} while ( !EE24CWxxX_WriteSingleByte(ee_idx, init_value) && (retry-- > 0) );		// modified from R1006
        
        if(retry <= 0)
        {
            ErrHandle_EE();	// added from R1006
            return false;
        }
      }
  }
  
  if(retry > 0)
  {
      return true;
  }
  else
  {
      ErrHandle_EE();	// added from R1006
      return false;
  }
}

/******************************************************************************
 * @brief   Makes a Test @ specific location to check proper funcitonality
 *
 * @note    Writes and read back an array of length "length" of random values. 
 *
 ******************************************************************************/
bool EE24CWxxX_Test( uint16_t start_address, uint16_t length )
{
  uint16_t ArrayLength = length;
  int32_t retry = 0;
  
  if(ArrayLength > 256)
    ArrayLength = 256;
  
  uint8_t WriteArray[256];
  uint8_t ReadArray[256];
  
  // Generate an array with random values
  for(uint16_t i = 0; i<ArrayLength; i++)
  {
    WriteArray[i] = (uint8_t)rand();
    ReadArray[i] = 0xAA;
  }
  
  /* Check if I2C Bus Ready to Use? */
  retry = 1000;
  do{ } while ( (HAL_I2C_IsDeviceReady(&EEPROM_I2C, EE24CWxxX_I2C_ADDR, 1, 10000) != HAL_OK) && (retry-- > 0) );
  
  if(retry > 0)
  {
      // Write Array to memory
      retry = NVD_EEPROM_WRITE_TIMEOUT;
      do{} while ( !EE24CWxxX_WriteNBytes( start_address, WriteArray, ArrayLength ) && (retry-- > 0) );		// modified from R1006
      
      if(retry <= 0)
      {
          ErrHandle_EE();	// added from R1006
          return false;
      }
      
      // Read back Array from memory
      retry = NVD_EEPROM_READ_TIMEOUT;
      do{} while ( !EE24CWxxX_ReadNBytes( start_address, ReadArray, ArrayLength ) && (retry-- > 0) );		// modified from R1006
      
      if(retry <= 0)
      {
          ErrHandle_EE();	// added from R1006
          return false;
      }
      
      for(uint16_t i = 0; i<ArrayLength; i++)
      {
        if(WriteArray[i] != ReadArray[i])
          return false;  
      }  
  }
  
  if(retry > 0)
      return true;
  else
      return false;
}

#endif //_24CWXXX_H_