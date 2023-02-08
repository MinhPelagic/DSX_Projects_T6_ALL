/*******************************************************************************
 * @file        : Gnss.h
 * @brief       : Middleware for Gnss          
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *      Reimplementation of Avinash Kumar example code, for Pelagic system integration.
 ******************************************************************************/
#include "L4X9_includes.h"
#if GPS_FW_ATTACHED
#include "CXD5605GF_Bin1.c"
#include "CXD5605GF_Bin2.c"
#include "CXD5605GF_Bin3.c"
#include "CXD5605GF_Bin4.c"
#endif
#ifdef _GNSS_H_

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
GNSS_Status_t GnssStatus = GNSS_OFF;

GNSS_FwUpdateStatus_t GNSS_FwUpdateStatus = GNSS_FWU_OFF;

GnssGGA_struct_t GnssGGA;

/*******************************************************************************
 * @brief   Local Variables
 ******************************************************************************/
static int32_t GnssTimestamp;
bool GnssReqOn = false;
bool GnssReqOff = false;
bool GnssReqWake = false;
bool GnssReqSleep = false;
static uint8_t PositionFixCounter = 0;
static int32_t PositionFixCounterTimeStampOld;

#define GNSS_MAX_COMMANDS       32

#define GNSS_MAX_PARAMETER      20

static char *GnssCommands[GNSS_MAX_COMMANDS];
//static char *GnssMaxCommandStrPtr;
static short GnssMaxCommandPtr = 0;
static short GnssCurCommandPtr = 0;
static short GnssNextCommandPtr = 0;
static short GnssPtrComBuf = 0;



static char GnssResponeBuffer[GNSS_MAX_PARAMETER][150];

static char gnss_combuffer[150];
static char gnss_content[150];

static char GnssResponeID[10];
static bool GnssResponeOk = false;

uint16_t gnss_retry = 0;
bool gnss_H_received = false;
bool gnss_OK_received = false;
bool gnss_success_received = false;
bool gnss_reboot_received = false;


/*******************************************************************************
 * @brief   Private functions
 ******************************************************************************/
void GnssSendCommand(uint8_t *cmd);
void GnssProcessInput(void);
void GnssProcessInputFwUpdateMode(void);
void GnssNotifyEvent(void);
void GnssProcessCommand(char command[]);

void GnssFindResponseContents(char *gsp__contents);

void GnssSplitArrayFromComma(char *gnss__gpgga);

void GnssGetGPGGAContent(void);

void GnssProcess_GPGGA_Response(char gnss__gpgga[]);
void GnssGetGPGGAContent(void);


/******************************************************************************
 * @brief   Activate Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_On(void)
{
  GnssReqOn = true;
  GnssReqOff = false;
  GnssReqWake = false;
  GnssReqSleep = false;
  if((GnssStatus == GNSS_FIRSTFIX)||(GnssStatus == GNSS_SLEEP))
    GnssStatus = GNSS_ON;
}

/******************************************************************************
 * @brief   Switch off Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_Off(void)
{
  GnssReqOn = false;
  GnssReqOff = true;
  GnssReqWake = false;
  GnssReqSleep = false;
}

/******************************************************************************
 * @brief   WakeUp Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_WakeUp(void)
{
  if(GnssStatus == GNSS_OFF)
    GnssReqOn = true;
  GnssReqWake = true;
  GnssReqSleep = false;
}
  
/******************************************************************************
 * @brief   Sleep Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_Sleep(void)
{
  GnssReqWake = false;
  
  if(GnssStatus != GNSS_OFF)
    GnssReqSleep = true;
}

/******************************************************************************
 * @brief   Gnss. Standby
 *
 * @note    added by YeuShyr 2022 04 15 for saving power in Surface Mode
 ******************************************************************************/
void Gnss_Standby(void)
{
  if(GnssStatus >= GNSS_ON)
      Gnss_Sleep();
}

/******************************************************************************
 * @brief   Handle Gnss.
 *
 * @note    
 ******************************************************************************/
bool GnssHandler (void)
{
  // Switch Off Gnss Chip:
  // If System Not Active
  // If System Not in PSM
  // If Off Requested
  if(   ((SystemStatus.SystemPowerMode != SYS_ACTIVE)
        && (SystemStatus.SystemPowerMode != SYS_PSM)
        && (GnssStatus != GNSS_OFF) )
      || (GnssReqOff == true)
    )
  {
    CXD5605GF_Off();
    GnssStatus = GNSS_OFF;
    return true;
  }
  else if(   (SystemStatus.SystemPowerMode == SYS_ACTIVE)
          && (GnssStatus == GNSS_OFF)
          )
  {
    Gnss_On();
  }
    
  // If data received on Uart
  if(SystemStatus.GnssDataRxFlag)
  {
    GnssProcessInput();
    SystemStatus.GnssDataRxFlag = false;
  }
  if (GnssCurCommandPtr != GnssMaxCommandPtr)
    GnssNotifyEvent();  
 
  // Gnss State machine
  switch (GnssStatus)
  {
    case GNSS_OFF:
      if(GnssReqOn)
      {
        CXD5605GF_On();
        CXD5605GF_Reset();

        GnssTimestamp = MonotonicClock_s;
        
        GnssStatus = GNSS_WAIT_RESET;
        GnssReqOn = false;
      }
      break;
    
    case GNSS_WAIT_RESET:
      if(MonotonicClock_s - GnssTimestamp > 1)
      {
        GnssSendCommand(GPS_SET_BSSL_GGA);
  
        GnssTimestamp = MonotonicClock_s;
        
        GnssStatus = GNSS_SET_OUTSENT;
      }
      break;
      
    case GNSS_SET_OUTSENT:
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_SET_BSSL_GGA);
  
        GnssTimestamp = MonotonicClock_s;
      }
      
      if(   (strncmp("[BSSL]",GnssResponeID, 6) == 0)
         && (GnssResponeOk)
        )
      {
        GnssSendCommand(GPS_SET_GSOP);
  
        GnssTimestamp = MonotonicClock_s;
        
        GnssStatus = GNSS_SET_OPMODE;
      }
      break;
      
    case GNSS_SET_OPMODE:
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_SET_GSOP);
  
        GnssTimestamp = MonotonicClock_s;
      }
      
      if(   (strncmp("[GSOP]",GnssResponeID, 6) == 0)
         && (GnssResponeOk)
        )
      {
        GnssSendCommand(GPS_SET_GNS);
  
        GnssTimestamp = MonotonicClock_s;
        
        //GnssStatus = GNSS_SET_COLDSTART;
        GnssStatus = GNSS_SET_SATSYS;
      }
      break;
      
      
    case GNSS_SET_SATSYS:
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_SET_GNS);
  
        GnssTimestamp = MonotonicClock_s;
      }
      
      if(   (strncmp("[GNS]",GnssResponeID, 5) == 0)
         && (GnssResponeOk)
        )
      {
        //GnssSendCommand(GPS_COLD_START);
        GnssSendCommand(GPS_HOT_START_TTFF);
  
        GnssTimestamp = MonotonicClock_s;
        
        //GnssStatus = GNSS_SET_COLDSTART;
        GnssStatus = GNSS_SET_HOTSTART;
      }
      break;
      
    case GNSS_SET_HOTSTART:
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_HOT_START_TTFF);
  
        GnssTimestamp = MonotonicClock_s;
      }
      
      if(   (strncmp("[GSR]",GnssResponeID, 5) == 0)
         && (GnssResponeOk)
        )
      {        
        GnssTimestamp = MonotonicClock_s;
                
        GnssStatus = GNSS_FIRSTFIX;
        
        PositionFixCounter = 0;
      }
      break;
      
    case GNSS_FIRSTFIX:
      if(MonotonicClock_s - GnssTimestamp > FIRST_FIX_TIMEOUT_S)
      {
        // After Timeout for first fix
        GnssSendCommand(GPS_SET_IDLE);
  
        GnssTimestamp = MonotonicClock_s;
        
        GnssStatus = GNSS_IDLE;
      }
      
      // If a wake request has been issued
      if(GnssReqWake)
      {
        GnssReqWake = false;
        GnssStatus = GNSS_ON;
        break;
      }
      
      // First position fix id valid
      if(  (GnssGGA.QualityIdx == 1)
        || (GnssGGA.QualityIdx == 2)
        || (GnssGGA.QualityIdx == 6)
        )
      {
        if(GnssGGA.timestamp != PositionFixCounterTimeStampOld)
        {
          PositionFixCounterTimeStampOld = GnssGGA.timestamp;
          PositionFixCounter++;
        }
        
        if(PositionFixCounter > FIX_VALID_COUNT)
        {
          GnssSendCommand(GPS_SET_IDLE);
    
          GnssTimestamp = MonotonicClock_s;
          
          GnssStatus = GNSS_IDLE;
        }
      }
      break; 
      
      
    case GNSS_ON: 
        
      if (GnssReqSleep)
      {
        GnssReqSleep = false;
        
        GnssSendCommand(GPS_SET_IDLE);
  
        GnssTimestamp = MonotonicClock_s;
        
        GnssStatus = GNSS_IDLE;
      }
      break;
      
      
    case GNSS_IDLE: 
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_SET_IDLE);
  
        GnssTimestamp = MonotonicClock_s;
      }
      
      if(   (strncmp("[GSTP]",GnssResponeID, 6) == 0)
         && (GnssResponeOk)
        )
      {        
        GnssTimestamp = MonotonicClock_s;
                
        GnssSendCommand(GPS_SET_SLEEP_0);
        
        GnssStatus = GNSS_WAITSLEEP;
      }

      break;
      
      
    case GNSS_WAITSLEEP: 
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_SET_SLEEP_0);
  
        GnssTimestamp = MonotonicClock_s;
      }
      if(   (strncmp("[SLP]",GnssResponeID, 5) == 0)
         && (GnssResponeOk)
        )
      {        
        GnssTimestamp = MonotonicClock_s;
                
        GnssStatus = GNSS_SLEEP;
      }

      break;
      
    case GNSS_SLEEP: 
      
      if(GnssReqWake)
      {
        //GnssReqWake = false;
        
        GnssTimestamp = MonotonicClock_s;
                
        GnssSendCommand(GPS_WUKEUP);
        
        GnssStatus = GNSS_WAITWAKE;
      }
      break;
      
    case GNSS_WAITWAKE: 
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_WUKEUP);
  
        GnssTimestamp = MonotonicClock_s;
      }
      if(   (strncmp("[WUP]",GnssResponeID, 5) == 0)
         && (GnssResponeOk)
        )
      {        
        GnssTimestamp = MonotonicClock_s;
            
        GnssSendCommand(GPS_HOT_START_TTFF);
        
        GnssStatus = GNSS_SET_HOTSTART;
      }

      break;
  }
  return true;
}

#if GPS_FW_ATTACHED
// This function is not blocking and should be called in a while until while(GNSS_FwUpdateStatus != GNSS_FWU_DONE)
// GUI feedback can be done by monitoring the GNSS_FwUpdateStatus.
void GnssFwUpdate_NotBlocking(void)
{
  L4X9_WatchDogReload();
  
  if(GNSS_FwUpdateStatus == GNSS_FWU_OFF)
    Gnss_On();
  
  // If data received on Uart
  if(SystemStatus.GnssDataRxFlag)
  {
    if(FwUpdateMode == false)
      GnssProcessInput();
    else
      GnssProcessInputFwUpdateMode();
    SystemStatus.GnssDataRxFlag = false;
  }
  if (GnssCurCommandPtr != GnssMaxCommandPtr)
    GnssNotifyEvent();  
  
  
  switch (GNSS_FwUpdateStatus)
  {
    case GNSS_FWU_OFF:
      if(GnssReqOn)
      {
        CXD5605GF_On();
        CXD5605GF_Reset();

        GnssTimestamp = MonotonicClock_s;
        
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
        
        GnssReqOn = false;
      }
      break;
    
    case GNSS_FWU_WAIT_RESET:
      if(MonotonicClock_s - GnssTimestamp > 1)
      {
        GnssSendCommand(GPS_FER);
  
        GnssTimestamp = MonotonicClock_s;
        
        GNSS_FwUpdateStatus = GNSS_FWU_FLASH_ERASE;
        
        gnss_retry = 0;
      }
      break;
      
    case GNSS_FWU_FLASH_ERASE:
      if(MonotonicClock_s - GnssTimestamp > 5)
      {
        // No Positive response from Gns chip, so retry
        GnssSendCommand(GPS_FER);
    
        GnssTimestamp = MonotonicClock_s;
          
        gnss_retry++;
      }
      
      if( ((strncmp("[FER]",GnssResponeID, 5) == 0) && (GnssResponeOk))
         || (gnss_retry > 5)
        )
      {
        GnssTimestamp = MonotonicClock_s;
        
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_FER_DONE;
        
        FwUpdateMode = true;
        
        gnss_H_received = false;
      }
      break;
      
    case GNSS_FWU_WAIT_FER_DONE:
      
      if(gnss_H_received == true)
      {
        GnssSendCommand(GPS_LOADH);
        ms_delay(15);
        
        gnss_H_received = false;
        gnss_OK_received = false;
        
        HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)CXD5605GF_Bin1, CXD5605GF_BIN1_SIZE, 5000);
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN1;
      }
      
      break;
      
    case GNSS_FWU_WAIT_LOAD_BIN1:
      
      if(MonotonicClock_s - GnssTimestamp > 10)
      {
        gnss_H_received = false;
        gnss_OK_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
      }
        
      if( (gnss_OK_received == true) && (gnss_H_received == true) )
      {
        GnssSendCommand(GPS_LOADC);
        ms_delay(15);
        
        gnss_H_received = false;
        gnss_OK_received = false;
        
        uint32_t tx_sent = 0;
        uint16_t tx_chunck = 0;
        
        while(tx_sent < CXD5605GF_BIN2_SIZE)
        {
          L4X9_WatchDogReload();
          
          if(CXD5605GF_BIN2_SIZE - tx_sent > (uint32_t)0x1000)
            tx_chunck = 0x1000;
          else
            tx_chunck = (uint16_t)(CXD5605GF_BIN2_SIZE - tx_sent);
          
          HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)&CXD5605GF_Bin2[tx_sent], tx_chunck, 30000);
          
          tx_sent += (uint32_t)tx_chunck;
        }
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN2;
      }
      
      break;
      
    case GNSS_FWU_WAIT_LOAD_BIN2:
      
      if(MonotonicClock_s - GnssTimestamp > 10)
      {
        gnss_H_received = false;
        gnss_OK_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
      }
        
      if( (gnss_OK_received == true) && (gnss_H_received == true) )
      {
        GnssSendCommand(GPS_LOADH);
        ms_delay(15);
        
        gnss_H_received = false;
        gnss_OK_received = false;
        
        HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)CXD5605GF_Bin3, CXD5605GF_BIN3_SIZE, 5000);
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN3;
      }
      
      break;
      
    case GNSS_FWU_WAIT_LOAD_BIN3:
      
      if(MonotonicClock_s - GnssTimestamp > 10)
      {
        gnss_H_received = false;
        gnss_OK_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
      }
        
      if( (gnss_OK_received == true) && (gnss_H_received == true) )
      {
        GnssSendCommand(GPS_LOADC);
        ms_delay(15);
        
        gnss_H_received = false;
        gnss_OK_received = false;
        
        uint32_t tx_sent = 0;
        uint16_t tx_chunck = 0;
        
        while(tx_sent < CXD5605GF_BIN4_SIZE)
        {
          L4X9_WatchDogReload();
          
          if(CXD5605GF_BIN4_SIZE - tx_sent > (uint32_t)0x1000)
            tx_chunck = 0x1000;
          else
            tx_chunck = (uint16_t)(CXD5605GF_BIN4_SIZE - tx_sent);
          
          HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)&CXD5605GF_Bin4[tx_sent], tx_chunck, 30000);
          
          tx_sent += (uint32_t)tx_chunck;
        }
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN4;
      }
      
      break;
      
    case GNSS_FWU_WAIT_LOAD_BIN4:
      
      if(MonotonicClock_s - GnssTimestamp > 10)
      {
        gnss_H_received = false;
        gnss_OK_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
      }
        
      if( (gnss_OK_received == true) && (gnss_H_received == true) )
      {
        GnssSendCommand(GPS_EXEC);
        
        gnss_success_received = false;
        gnss_reboot_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_REBOOT;
      }
      
      break;
      
      
    case GNSS_FWU_WAIT_REBOOT:
      
      if(MonotonicClock_s - GnssTimestamp > 30)
      {
        gnss_H_received = false;
        gnss_OK_received = false;
        
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
      }
        
      if( (gnss_success_received == true) && (gnss_reboot_received == true) )
      {
        GnssTimestamp = MonotonicClock_s;
        GNSS_FwUpdateStatus = GNSS_FWU_DONE;
      }
      
      break;
      
    case GNSS_FWU_DONE:
      
      FwUpdateMode = false;
      
      break;
      
  }
}

// This function is blocking and will attempt 10 retries before returning error.
bool GnssFwUpdate_Blocking(void)
{
  static uint8_t retry = 0;
  
  while( (GNSS_FwUpdateStatus != GNSS_FWU_DONE) && (retry < 10) )
  {
    L4X9_WatchDogReload();
    
    if(GNSS_FwUpdateStatus == GNSS_FWU_OFF)
      Gnss_On();
    
    // If data received on Uart
    if(SystemStatus.GnssDataRxFlag)
    {
      if(FwUpdateMode == false)
        GnssProcessInput();
      else
        GnssProcessInputFwUpdateMode();
      SystemStatus.GnssDataRxFlag = false;
    }
    if (GnssCurCommandPtr != GnssMaxCommandPtr)
      GnssNotifyEvent();  
    
    
    switch (GNSS_FwUpdateStatus)
    {
      case GNSS_FWU_OFF:
        if(GnssReqOn)
        {
          CXD5605GF_On();
          CXD5605GF_Reset();

          GnssTimestamp = MonotonicClock_s;
          
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          
          GnssReqOn = false;
        }
        break;
      
      case GNSS_FWU_WAIT_RESET:
        if(MonotonicClock_s - GnssTimestamp > 1)
        {
          GnssSendCommand(GPS_FER);
    
          GnssTimestamp = MonotonicClock_s;
          
          GNSS_FwUpdateStatus = GNSS_FWU_FLASH_ERASE;
          
          gnss_retry = 0;
        }
        break;
        
      case GNSS_FWU_FLASH_ERASE:
        if(MonotonicClock_s - GnssTimestamp > 5)
        {
          // No Positive response from Gns chip, so retry
          GnssSendCommand(GPS_FER);
      
          GnssTimestamp = MonotonicClock_s;
            
          gnss_retry++;
        }
        
        if( ((strncmp("[FER]",GnssResponeID, 5) == 0) && (GnssResponeOk))
           || (gnss_retry > 5)
          )
        {
          GnssTimestamp = MonotonicClock_s;

          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_FER_DONE;
          
          FwUpdateMode = true;
          
          gnss_H_received = false;
        }
        break;
        
      case GNSS_FWU_WAIT_FER_DONE:
        
        if(gnss_H_received == true)
        {
          GnssSendCommand(GPS_LOADH);
          ms_delay(15);
          
          gnss_H_received = false;
          gnss_OK_received = false;
          
          HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)CXD5605GF_Bin1, CXD5605GF_BIN1_SIZE, 5000);
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN1;
        }
        
        break;
        
      case GNSS_FWU_WAIT_LOAD_BIN1:
        
        if(MonotonicClock_s - GnssTimestamp > 10)
        {
          gnss_H_received = false;
          gnss_OK_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          retry++;
        }
          
        if( (gnss_OK_received == true) && (gnss_H_received == true) )
        {
          GnssSendCommand(GPS_LOADC);
          ms_delay(15);
          
          gnss_H_received = false;
          gnss_OK_received = false;
          
          uint32_t tx_sent = 0;
          uint16_t tx_chunck = 0;
          
          while(tx_sent < CXD5605GF_BIN2_SIZE)
          {
            L4X9_WatchDogReload();
            
            if(CXD5605GF_BIN2_SIZE - tx_sent > (uint32_t)0x1000)
              tx_chunck = 0x1000;
            else
              tx_chunck = (uint16_t)(CXD5605GF_BIN2_SIZE - tx_sent);
            
            HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)&CXD5605GF_Bin2[tx_sent], tx_chunck, 30000);
            
            tx_sent += (uint32_t)tx_chunck;
          }
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN2;
        }
        
        break;
        
      case GNSS_FWU_WAIT_LOAD_BIN2:
        
        if(MonotonicClock_s - GnssTimestamp > 10)
        {
          gnss_H_received = false;
          gnss_OK_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          retry++;
        }
          
        if( (gnss_OK_received == true) && (gnss_H_received == true) )
        {
          GnssSendCommand(GPS_LOADH);
          ms_delay(15);
          
          gnss_H_received = false;
          gnss_OK_received = false;
          
          HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)CXD5605GF_Bin3, CXD5605GF_BIN3_SIZE, 5000);
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN3;
        }
        
        break;
        
      case GNSS_FWU_WAIT_LOAD_BIN3:
        
        if(MonotonicClock_s - GnssTimestamp > 10)
        {
          gnss_H_received = false;
          gnss_OK_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          retry++;
        }
          
        if( (gnss_OK_received == true) && (gnss_H_received == true) )
        {
          GnssSendCommand(GPS_LOADC);
          ms_delay(15);
          
          gnss_H_received = false;
          gnss_OK_received = false;
          
          uint32_t tx_sent = 0;
          uint16_t tx_chunck = 0;
          
          while(tx_sent < CXD5605GF_BIN4_SIZE)
          {
            L4X9_WatchDogReload();
            
            if(CXD5605GF_BIN4_SIZE - tx_sent > (uint32_t)0x1000)
              tx_chunck = 0x1000;
            else
              tx_chunck = (uint16_t)(CXD5605GF_BIN4_SIZE - tx_sent);
            
            HAL_UART_Transmit(&GnssUartHandle, (uint8_t*)&CXD5605GF_Bin4[tx_sent], tx_chunck, 30000);
            
            tx_sent += (uint32_t)tx_chunck;
          }
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_LOAD_BIN4;
        }
        
        break;
        
      case GNSS_FWU_WAIT_LOAD_BIN4:
        
        if(MonotonicClock_s - GnssTimestamp > 10)
        {
          gnss_H_received = false;
          gnss_OK_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          retry++;
        }
          
        if( (gnss_OK_received == true) && (gnss_H_received == true) )
        {
          GnssSendCommand(GPS_EXEC);
          
          gnss_success_received = false;
          gnss_reboot_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_REBOOT;
        }
        
        break;
        
        
      case GNSS_FWU_WAIT_REBOOT:
        
        if(MonotonicClock_s - GnssTimestamp > 30)
        {
          gnss_H_received = false;
          gnss_OK_received = false;
          
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_WAIT_RESET;
          retry++;
        }
          
        if( (gnss_success_received == true) && (gnss_reboot_received == true) )
        {
          GnssTimestamp = MonotonicClock_s;
          GNSS_FwUpdateStatus = GNSS_FWU_DONE;
          FwUpdateMode = false;
          retry = 0;
          return true;
        }
        
        break;
        
      case GNSS_FWU_DONE:
        
        FwUpdateMode = false;
        retry = 0;
        return true;
        break;
    }
  }
  
  // Did try 10 times to load Gps Fww but not successfull so signal Error
  if(retry >= 10)
    GNSS_FwUpdateStatus = GNSS_FWU_ERROR;
  
  return false;
}
#endif
    
void GnssSendCommand(uint8_t *cmd)
{
  HAL_UART_Transmit(&GnssUartHandle,cmd,strlen((char *)cmd), 5000);
}

void GnssProcessInput(void)
{
  short i = 0;

  i = GnssPtrComBuf;
  while (i != Cxd5605gfMaxComBuf)       // loop through to catchup with MaxComBuf. 
  {
    if(Cxd5605gfComBuf[i] == 0x24)      // $
      GnssPtrComBuf = i;
    
    if(Cxd5605gfComBuf[i] == 0x5B)      // [
      GnssPtrComBuf = i;
    
    if(   (Cxd5605gfComBuf[i] == '\n')
       && (Cxd5605gfComBuf[i-1] == '\r')
      )
    {
      memcpy(gnss_combuffer, &Cxd5605gfComBuf[GnssPtrComBuf], (i-GnssPtrComBuf));
      GnssPtrComBuf = i;
      GnssCommands[GnssMaxCommandPtr] = &gnss_combuffer[0];
      GnssMaxCommandPtr++;
      
      if (GnssMaxCommandPtr >= GNSS_MAX_COMMANDS) 
        GnssMaxCommandPtr = 0;
    }
    if (i == Cxd5605gfMaxComBuf)
      break;
		
    if (i >= CXD5605GF_MAX_COMBUF)
    {            
      i = 0;											// Roll back when exceeding limit
      GnssPtrComBuf=0;
    }
    if(   (i >= Cxd5605gfMaxComBuf) 
       && (CXD5605GF_MAX_COMBUF-Cxd5605gfMaxComBuf < 200)
      )// saftey measure to prevent accental exceed
    {
      GnssPtrComBuf = Cxd5605gfMaxComBuf=0;
      break;
    }
    i++;
  }
}

void GnssProcessInputFwUpdateMode(void)
{
  short i = 0;

  i = GnssPtrComBuf;
  while (i != Cxd5605gfMaxComBuf)       // loop through to catchup with MaxComBuf. 
  {
    // Search for "H> " this is different from what on datasheet
    if( (Cxd5605gfComBuf[i] == 0x20) 
       && (Cxd5605gfComBuf[i-1] == 0x3E)
       && (Cxd5605gfComBuf[i-2] == 0x48)
      )
    {
      gnss_H_received = true;
      GnssPtrComBuf = i+1;
    }
    // Search for "OK<LF> "
    else if( (Cxd5605gfComBuf[i] == 0x0A) 
       && (Cxd5605gfComBuf[i-1] == 0x4B)
       && (Cxd5605gfComBuf[i-2] == 0x4F)
      )
    {
      gnss_OK_received = true;
      GnssPtrComBuf = i+1;
    }
    // Search for "success<LF> "
    else if( (Cxd5605gfComBuf[i] == 0x0A) 
       && (Cxd5605gfComBuf[i-1] == 0x73)
       && (Cxd5605gfComBuf[i-2] == 0x73)
       && (Cxd5605gfComBuf[i-3] == 0x65)
       && (Cxd5605gfComBuf[i-4] == 0x63)
       && (Cxd5605gfComBuf[i-5] == 0x63)
       && (Cxd5605gfComBuf[i-6] == 0x75)
       && (Cxd5605gfComBuf[i-7] == 0x73)
      )
    {
      gnss_success_received = true;
      GnssPtrComBuf = i+1;
    }
    // Search for "reboot...<LF> " this is different from what on datasheet
    else if( (Cxd5605gfComBuf[i] == 0x0A) 
       && (Cxd5605gfComBuf[i-1] == 0x2E)
       && (Cxd5605gfComBuf[i-2] == 0x2E)
       && (Cxd5605gfComBuf[i-3] == 0x2E)
       && (Cxd5605gfComBuf[i-4] == 0x74)
       && (Cxd5605gfComBuf[i-5] == 0x6F)
       && (Cxd5605gfComBuf[i-6] == 0x6F)
       && (Cxd5605gfComBuf[i-7] == 0x62)
       && (Cxd5605gfComBuf[i-8] == 0x65)
       && (Cxd5605gfComBuf[i-9] == 0x72)
      )
    {
      gnss_reboot_received = true;
      GnssPtrComBuf = i+1;
    }

    if (i >= CXD5605GF_MAX_COMBUF)         
    {            
      i = 0;
      GnssPtrComBuf = 0;
    }
    
    i++;
  }
}

void GnssNotifyEvent(void)
{
  while (GnssCurCommandPtr != GnssMaxCommandPtr)
  {
    GnssNextCommandPtr = GnssCurCommandPtr;
    GnssNextCommandPtr++;
    
    if (GnssNextCommandPtr >= GNSS_MAX_COMMANDS) 
      GnssNextCommandPtr = 0;
    
    //GnssMaxCommandStrPtr = GnssCommands[GnssNextCommandPtr];
    
    GnssProcessCommand(GnssCommands[GnssCurCommandPtr]);
    
    GnssCurCommandPtr = GnssNextCommandPtr;
  }
}


void GnssFindResponseContents(char *gnss__contents)
{
  int32_t len = strlen(gnss__contents);
  
  for(int32_t i = 0; i<len; i++)
    gnss_content[i] = gnss__contents[i];

  gnss_content[len] = 0;
}

void GnssSplitArrayFromComma(char *gnss__gpgga)
{
  int32_t i = 0, j = 0, k = 0;
  int32_t len = strlen(gnss_combuffer);
  for(    ; i < len-1; i++)
  {
    if(gnss_combuffer[i] != 0x2C)
    {
      GnssResponeBuffer[j][k++] = gnss__gpgga[i];
    }
    else
    {
      k = 0;
      j++;
    }
  }
}

void GnssProcessCommand(char command[])
{
  if (strncmp("$GPGGA",command, 6) == 0)
  {
    GnssProcess_GPGGA_Response(&command[0]);
  }
  
  // Command Responses----------------------------------------------

  if (strncmp("[BSSL]", command, 6) == 0)
  {
    strncpy(GnssResponeID, command, 6);
    
    if(strncmp("Done",&command[7], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[CSBR]", command, 6) == 0)
  {
    strncpy(GnssResponeID, command, 6);
    
    if(strncmp("Done",&command[7], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }

  if (strncmp("[GCD]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GNS]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSOP]",command, 6) == 0)
  {
    strncpy(GnssResponeID, command, 6);
    
    if(strncmp("Done",&command[7], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSP]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSR]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSTP]",command, 6) == 0)
  {
    strncpy(GnssResponeID, command, 6);
    
    if(strncmp("Done",&command[7], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSTP]",command, 6) == 0)
  {
    strncpy(GnssResponeID, command, 6);
    
    if(strncmp("Done",&command[7], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[GSW]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }

  if (strncmp("[SLP]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[WUP]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
  
  if (strncmp("[FER]",command, 5) == 0)
  {
    strncpy(GnssResponeID, command, 5);
    
    if(strncmp("Done",&command[6], 4) == 0)
      GnssResponeOk = true;
    else
      GnssResponeOk = false;
  }
}

void GnssProcess_GPGGA_Response(char gnss__gpgga[])
{
  GnssSplitArrayFromComma(gnss__gpgga);
  GnssGetGPGGAContent();
}

void GnssGetGPGGAContent(void)
{
  GnssFindResponseContents(&GnssResponeBuffer[1][0]);
  GnssGGA.GNSS_UtcTime_h = (gnss_content[0]-0x30)*10 + (gnss_content[1]-0x30);
  GnssGGA.GNSS_UtcTime_m = (gnss_content[2]-0x30)*10 + (gnss_content[3]-0x30);
  GnssGGA.GNSS_UtcTime_s = (gnss_content[4]-0x30)*10 + (gnss_content[5]-0x30);
  GnssGGA.GNSS_UtcTime_ms = (gnss_content[7]-0x30)*10 + (gnss_content[8]-0x30);
    
  double Raw, Degree, Minutes;
  
  // Get Latitude from response frame in DMM format
  GnssFindResponseContents(&GnssResponeBuffer[2][0]);
  // Convert to Raw float
  Raw = atof(gnss_content);
  // Get Degree Value of the DMM data
  Degree = Raw/100;
  modf((double)Degree, &Degree);
  char sign = GnssResponeBuffer[3][0];
  //if(sign == 'S' )
  //  Degree *= (-1.0f);
  // Get Minute Value of the DMM data
  Minutes = (Raw - Degree*100); 
  // Convert from DMM to DD
  if(sign == 'S' )
    GnssGGA.Latitude_DD = -1.0*WayFinder_Dmm2Dd((float)Degree, (float)Minutes);
  else
    GnssGGA.Latitude_DD = WayFinder_Dmm2Dd((float)Degree, (float)Minutes);
  // Get Latitude from response frame in DMM format
  GnssFindResponseContents(&GnssResponeBuffer[4][0]);
  // Convert to Raw float
  Raw = atof(gnss_content);
  // Get Degree Value of the DMM data
  Degree = Raw/100;
  modf((double)Degree, &Degree);
  sign = GnssResponeBuffer[5][0];
  //if(sign == 'W' )
  //  Degree *= (-1.0f);
  // Get Minute Value of the DMM data
  Minutes = Raw - Degree*100; 
  // Convert from DMM to DD
  if(sign == 'W' )
    GnssGGA.Longitude_DD = -1.0*WayFinder_Dmm2Dd((float)Degree, (float)Minutes);
  else
    GnssGGA.Longitude_DD = WayFinder_Dmm2Dd((float)Degree, (float)Minutes);  
/*
  GnssGGA.Latitude=atof(gnss_content);					                        
  GnssGGA.Latitude_N_S = GnssResponeBuffer[3][0];
  
    
  GnssFindResponseContents(&GnssResponeBuffer[4][0]);
  GnssGGA.Longitude = atof(gnss_content);
  GnssGGA.Longitude_E_W = GnssResponeBuffer[5][0];
*/
    
  GnssFindResponseContents(&GnssResponeBuffer[6][0]);
  GnssGGA.QualityIdx = (uint8_t)atoi(gnss_content);
  
  GnssFindResponseContents(&GnssResponeBuffer[7][0]);
  GnssGGA.NoOfSatellites_used = atoi(gnss_content);

  GnssGGA.timestamp = MonotonicClock_s;
}

#endif // _GNSS_H_