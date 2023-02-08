/*******************************************************************************
 * @file        : Tick_Handler_5.c
 * @brief       : This file contains all Tick handler functions.
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

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"


#define LOG_SECTOR_NUM    128           // in DSX case that Normal 512-Byte LOG uses 64 sectors (512KB = 4KB x 128 sectors)
#define TOTAL_LOG_NUMBER 1024           // total number of DSX LOGs = 1024


void SaveLogAndProfile(uint8_t, uint16_t);
uint8_t SaveLog(uint16_t);
uint8_t ReadLog(uint16_t);
uint8_t SaveProfile(uint16_t);
void ReadNewDiveProfile_ExFLASH(void);
void ReadWelcomeData_ExFLASH(void);
uint32_t CheckAddrForWraping(uint32_t, uint32_t, uint32_t);
void ReverseOrderBuf_4K(void);

void NewDiveInitialization(void);
void EndOfNewDiveDataCollection(void);  // collect dive information at the end of After-Dive, before saving to EEPROM going to sleep
void BackToSurfDataCollection(void);    // collect dive infomration at beginning of After-Dive, not yet saving to EEPROM
void PhamtonDiveDataRestore(void);      // Data Restoration after phantom dive detected, to restore pre-dive condition 
void NoPhamtonDiveDataUpdate(void);     // Data Update after No Phantom Dive confirmed, to continue a Scuba/Gauge/Free dive
uint8_t CheckPhatomDive(void);          // determined if Phantom Dive, and then keep or discard the recorded dive data
void LoadLog4K2Log7(void);              // use uint16_t for up to 65536 LOGs > 256 LOGs

uint8_t Buf_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE]; //, Copy_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];		// Modified for T1.001.001
uint16_t ProfileChartData[PROFILE_CHART_SIZE];          // prepare Profile Chart Data for LOG chart use
uint16_t ProfileChartPointY[PROFILE_CHART_SIZE/2];      // prepare Profile Chart Data for real-time chart use
GUI_POINT LogChartPOINT_X_Y[PROFILE_CHART_SIZE/2];     // prepare Profile Chart Data for real-time chart use
uint8_t ProfileIdx = 0;             // from 0 to PROFILE_CHART_SIZE - 1
uint8_t ProfileIdxScale = 1;        // from 2^ProfileIdxScale, starts from scale = 1

uint8_t TLBGVal_Log = 0;        // a buffer to keep TLBGVal value at the beginning of After-Dive, and then save it to Log at the end of After-Dive
uint8_t MaxOTUpercent = 0;      // Record Max O2% throughout the dive
uint8_t MaxTLBGVal = 0;         // Record Max TLBG throughout the dive
bool NewDiveWhenLowBatt = false;        // the flag to display Low Battery Alarm non-stop, if New Dive Starts from a Red Battery

uint32_t ProfileHeaderAddr =  EXFLASH_PROFILE;        // 4K per step
uint32_t NewSectorStartAddr = EXFLASH_PROFILE;    // start address of each dive 
uint32_t NewSectorEndAddr =   EXFLASH_PROFILE;    // end address of each dive, PROFILE_SIZE per step 
        
uint8_t ProfileBuf_4K[(SECTOR_SIZE/PROFILE_SIZE)+(PROFILE_TRAILER_SIZE/PROFILE_SIZE)][PROFILE_SIZE], *pDst; //, Copy_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];   
uint16_t ProfileBufRowIdx;

float totalSum_TempF = 0.0;
float totalSum_DepthFt = 0.0;
float MaxTempF = -125.0, MinTempF = 125.0;
uint16_t ProfileSampleCnt = 0;
uint16_t PeriodMaxDepth = 0;         // recording Max Depth between sampling period
uint8_t SamplingRateIdx;

uint8_t PreStatus = AMB_DIVEINFO_SURF;
int16_t DiveLogNum = -LOG_SECTOR_NUM;     // negative -> OFF (not the time for LOG)
    
/* Tick 5 Handler */
void L4X9_TickHandler_5(void)
{
  /* Please insert here your code for Tick 5 processing */
  /* Manage NVD Data */
  /* Check if NVD needs to be stored in External EEPROM */
  if( ((MonotonicClock_s % NVD_RAM_TO_EEPROM_PERIOD_S == 0) || (SystemStatus.NvdUpdateInProgress) )
     &&( (Dive_Info.Status != AMB_DIVEINFO_DIVE)&&(Dive_Info.Status != AMB_DIVEINFO_AFTERDIVE))                 // Avoid EEPROM Read/Write during Dive Time, added from R1006
     &&(   (((Dive_Info.SurfTime_s < 600)||(Dive_Info.SurfTime_s > 610))&&(USER_Set.DiveMode!=NVD_MDFREE))
         ||(((Dive_Info.SurfTime_s < 60)||(Dive_Info.SurfTime_s > 70))&&(USER_Set.DiveMode==NVD_MDFREE))  )           // Avoid Data Retention processing at the time of Profile and Log saving to EEPROM
         && (!AppInCommunicating()) )
  {
    if( (SystemStatus.SystemPowerMode == SYS_ACTIVE) || (SystemStatus.SystemPowerMode == SYS_PSM) )     // only update EEPROM when ACTIVE or PSM mode
    {
      if(NVD_DataRetention_RAM_to_ExtEEPROM())
        SystemStatus.NvdUpdateInProgress = false;       // Wait for next Data Retention cycle (NOT in progress)
      else
        SystemStatus.NvdUpdateInProgress = true;        // Data Retention period is currently ON (in progress)
    }
  }
  
  SaveLogAndProfile(Dive_Info.Status, DEV_Rec.LogNumLast);  
  
  Check_For_Deco();
}



void SaveLogAndProfile(uint8_t stat, uint16_t n)
{
    
    if(  ((PreStatus == AMB_DIVEINFO_SURF)||(PreStatus == AMB_DIVEINFO_NEWDAY)||(PreStatus == AMB_DIVEINFO_NEWDAY_SLEEP))
       &&(stat == AMB_DIVEINFO_DIVE) )            // the moment from Surf to Dive records Profile Header
    {
        NewDiveInitialization();
        
        SaveProfile(PROFILE_HEADER);       // saving to RAM Only, not to EEPROM yet, so still has chance to be corrected at NoPhamtonDiveDataUpdate();
    }
    else if((PreStatus == AMB_DIVEINFO_DIVE) && (stat == AMB_DIVEINFO_DIVE))       // the moment of Dive and Dive records Profile Data
    {
        // need to control the saving frequecy here (2, 15, 30, 60 seconds)
        SaveProfile(PROFILE_DATA);
        
        // Update Patch for Profile Trailer after No Phantom Dive is confirmed 
        if((Dive_Info.NoPhantomCtr >= PHANTOM_SEC)&&(Dive_Info.PhantomCheckDone==false))
        {
            Dive_Info.PhantomCheckDone = true;
            
            NoPhamtonDiveDataUpdate();  // after NoPhantom confirmed, this is to update DiveNum of Profiles and Logs.
            
            SaveProfile(PROFILE_HEADER_UPDATE);         // after NoPhantom confirmed, this is to update DiveNum of Profiles
        }
    }
    else if((PreStatus == AMB_DIVEINFO_AFTERDIVE) && (stat == AMB_DIVEINFO_AFTERDIVE))       // the moment of Dive and Dive records Profile Data
    {
        // need to control the saving frequecy here (2, 15, 30, 60 seconds)
        SaveProfile(PROFILE_DATA);
    }
    else if(((PreStatus == AMB_DIVEINFO_DIVE)||(PreStatus == AMB_DIVEINFO_10HDIVE)||(PreStatus == AMB_DIVEINFO_SURF)) && (stat == AMB_DIVEINFO_AFTERDIVE))  // the moment from Dive to After-Dive, to keep some data
    {
        BackToSurfDataCollection() ;    // temporary buffer, will be re-visited and over-written over here (if go dive again)
    }
    else if((PreStatus == AMB_DIVEINFO_AFTERDIVE) && (stat == AMB_DIVEINFO_SURF))  // the moment from After-Dive to Surf records Profile Trailer
    {
        EndOfNewDiveDataCollection();   // offical end of dive, recording collected dive data for LOG and Profile
 
        SaveProfile(PROFILE_TRAILER);
        
        DiveLogNum = DEV_Rec.LogNumRecorded;    //LOG_SECTOR_NUM;   // reinitialize back 4, for every new dive
        
        ReadNewDiveProfile_ExFLASH();           // self-check for latest dive's provfile properly recorded onto ExFLASH
    }
    else if((PreStatus == AMB_DIVEINFO_DIVE) && (stat == AMB_DIVEINFO_SURF))       // phantom dive detected, start restorations
    {
        DEV_Rec.DivingOngoing=0;

        PhamtonDiveDataRestore();
    }

    if((DiveLogNum < TOTAL_LOG_NUMBER) && (DiveLogNum >= 0))
    {
        SaveLog(DiveLogNum);          // n = 63, 62, .....3, 2, 1, 0 (shifts the oldest 4K (sector 63), (sector 62), ,,,(sector 3), (sector 2), (sector 1) to the newsest 4K (sector 0), 
        DiveLogNum = -LOG_SECTOR_NUM;
        ClearProfileChartData();        // clear Dive Mode real-time dive graphics
    }

    PreStatus = stat;
}


/******************************************************************************
 * @brief   Save Updated Log Data to ExFLASH and updated status to EEPROM
 *
 * @note    
 ******************************************************************************/
uint8_t SaveLog(uint16_t num)
{  
    //uint8_t Buf_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE]; //, Copy_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];
    uint8_t LogOfSec;   // the order of the Log of the Section  (0, 1, 2, .......7, since there are 8 of Log in one Sector)
    uint16_t Sector;    // the sector number from the Head Address of LOG
      
    uint8_t *pDst;
    uint32_t pFlash;    
    
    uint8_t *pNewLog;
    uint16_t *pNewChart;
    uint8_t err = 0;
    int8_t retry;
    
    pDst = *Buf_4K;
    pNewChart = ProfileChartPointY; 
    
/*********** Must do this every time before FLASH Erase/Read/Write  ***********/
    L4X9_QSPI_Init();
            
    MT25QL512ABB_PowerDownRelease();
/******************************************************************************/
    if(num > 0)
        num = num - 1;  // Dive#1 to save at Addr#0;   Dive#2 to save at Addr#1;   Dive#3 to save at Addr#2, etc.
    //--- Do following for all stage: 63, 62, 61, .......3, 2, 1, and 0 sectors, including saving the latest (current) LOG ---
    
    Sector    = num / (SECTOR_SIZE/LOG_SIZE);               // index of each 4K sector (out of total 16K in ExFLASH)
    LogOfSec  = (uint8_t)(num % (SECTOR_SIZE/LOG_SIZE)); // index of LOG position within each 4K sector
        
    pFlash = EXFLASH_LOG + (SECTOR_SIZE * Sector);

    //----------------------------------------------------------------------------------------------------
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006     // (ExFLASH address to read from,  Read Size in Byte,  Address point of the Array to load read back data)
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    //MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst);   // (ExFLASH address to read from,  Read Size in Byte,  Address point of the Array to load read back data)
    
    // Update LOG RAM
    LOG_Data_Update();
    
    pNewLog = (uint8_t*) &Log_Data;
    pNewChart = (uint16_t*) &Log_Chart;
    
    // load the 1st half of LOG (the first 256 Bytes)
    // load the 2nd half of LOG (the second 256 Bytes)
    memcpy((pDst+LOG_SIZE*LogOfSec), pNewLog, (LOG_SIZE/2));
    memcpy((pDst+LOG_SIZE*LogOfSec+LOG_SIZE/2), pNewChart, (LOG_SIZE/2));
        
     // Erase the area about to write one LOG    
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_Erase4kSector(pFlash) != true) && (retry-- > 0));		// Timeout added from R1006     // Erase 4K space
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O(pFlash, SECTOR_SIZE, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006     // Write back 4K sector
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    //MT25QL512ABB_WriteNPage1I1O(pFlash, SECTOR_SIZE, pDst);   // Write back 4K sector
    
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006     // Read 4K sector (for checking only)
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    //MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst);         // Read 4K sector (for checking only)
  
/******** Must do this every time after FLASH Erase/Read/Write is done ********/
    MT25QL512ABB_PowerDownEnter();
    
    L4X9_QSPI_DeInit();
/******************************************************************************/

    // after LOG finishes recording, mark onto EEPROM
    FLASH_Map.NormLogHeadAddr = EXFLASH_LOG;          // the head address of the area for recording all LOGs
    FLASH_Map.NormLogTailAddr = EXFLASH_LOG_END;      // the tail address of the area for recording all LOGs
    FLASH_Map.NormLogFirstDiveAddr = EXFLASH_LOG;     // the first dive LOG always sit at HeadAdd = EXFLASH_LOG
    FLASH_Map.NormLogNextDiveAddr = EXFLASH_LOG+LOG_SIZE*(DEV_Rec.LogNumRecorded); // the head address of the oldest LOG recorded
    
    EE_SaveReq(EE_DEVREC);
    EE_SaveReq(EE_FLASHMAP);

    return err;
}



/*******************************************************************************
 * @brief   Read Updated Log Data from ExFLASH and updated status from/to EEPROM
 *
 * @note    
 ******************************************************************************/
uint8_t ReadLog(uint16_t BackNum)  // use uint16_t for up to 65536 LOGs > 256 LOGs
{  
    //uint8_t Buf_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE]; //, Copy_4K[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];
    //uint16_t i,j;       // i for matric indexes, 
    uint16_t num;
    uint16_t Sector;    
    uint8_t LogOfSec;          // stage (Cnt of 4K sector of total 16K Exflash), m: index within each 4K
    uint8_t *pDst;
    uint32_t pFlash;
    
    //uint8_t *pLog;
    //uint8_t *pLog8[8];
    uint8_t err = 0;      
    int8_t retry;
    
    num = (DEV_Rec.LogNumRecorded - BackNum);
    
    pDst = *Buf_4K;
    //pLog = (uint8_t*) &Log_Data;
    //for(i=0;i<MAX_ITEM_DISP_PAGE_LOG_01;i++)
    //  pLog8[i] = (uint8_t*) &Log_Data_7[i];

    // Reject LOG Reading during Dive and After-Dive to avoid data Mixing Up between different dives
    if(((Dive_Info.Status!=AMB_DIVEINFO_DIVE)&&(Dive_Info.Status!=AMB_DIVEINFO_AFTERDIVE)&&(Dive_Info.SurfTime_s > 605))  // LOG only available 10 min+5sec after any New Dive
      ||(Dive_Info.Status==AMB_DIVEINFO_NEWDAY))                                                                          // and LOG also available whenever a NewDay
    {

    /*********** Must do this every time before FLASH Erase/Read/Write  ***********/
        L4X9_QSPI_Init();
                
        MT25QL512ABB_PowerDownRelease();
    /******************************************************************************/
        
    Sector    = num / (SECTOR_SIZE/LOG_SIZE);               // index of each 4K sector (out of total 16K in ExFLASH)
    LogOfSec  = (uint8_t)(num % (SECTOR_SIZE/LOG_SIZE)); // index of LOG position within each 4K sector
        
    //--- Do following for all stage-3, 2, 1, and 0 sectors, including saving the latest (current) LOG ---
    //--------- Normal Scuba Dive or Gauge Dive ----------------------

    pFlash = EXFLASH_LOG + SECTOR_SIZE * Sector + LOG_SIZE * LogOfSec - SECTOR_SIZE;
     
    retry = NVD_FLASH_READ_TIMEOUT;
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    //MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pDst); 
        
    /******** Must do this every time after FLASH Erase/Read/Write is done ********/
        MT25QL512ABB_PowerDownEnter();
        
        L4X9_QSPI_DeInit();
    /******************************************************************************/  
        
        ReverseOrderBuf_4K();
        
        LoadLog4K2Log7();       // update newly read data from Buf_4K to Log_Data_7
    }
    
    return err;
}


/*******************************************************************************
 * @brief   Load LOG4K data to Log7 Buffer for LOG display
 *
 * @note    
 ******************************************************************************/
void LoadLog4K2Log7(void)  // use uint16_t for up to 65536 LOGs > 256 LOGs
{  
    uint16_t i;       // i for matric indexes, 
    
    uint8_t *pBuf4K;
    uint8_t *pSrc;
    uint8_t *pDst;
    uint8_t *pLogDst;
    uint16_t *pChartDst;
     
    pBuf4K = *Buf_4K;

    pLogDst = (uint8_t*)Log_Data_7;
    pChartDst = (uint16_t*)Log_Chart_7;
    
    for(i=0;i<MAX_ITEM_DISP_PAGE_LOG_01;i++)
    {
        pSrc = (pBuf4K+(i*LOG_SIZE));
        pDst = (pLogDst+(i*(LOG_SIZE/2)));
        memcpy(pDst, pSrc, (LOG_SIZE/2));
        
        pSrc = (pBuf4K+(i*LOG_SIZE)+LOG_SIZE/2);
        pDst = (uint8_t*)(pChartDst+(i*(LOG_SIZE/4)));
        memcpy(pDst, pSrc, LOG_SIZE/2);
    }    
}


/*******************************************************************************
 * @brief   Sorting Buf_4K buffer 
 *
 * @note    
 ******************************************************************************/
void ReverseOrderBuf_4K(void)
{    
    uint8_t TempLOG[LOG_SIZE];
    uint8_t *pSrc, *pDst, *pTemp;
    uint8_t i, n;
    
    n = ((SECTOR_SIZE/LOG_SIZE) - 1);   // 7   (0,1,2,3,4,5,6,7)
    pTemp = TempLOG;

    for(i=0; i<((SECTOR_SIZE/LOG_SIZE)/2); i++)
    {
        pSrc = *Buf_4K + (LOG_SIZE * i);
        pDst = pTemp;
        memcpy(pDst, pSrc, LOG_SIZE);
        
        pSrc = *Buf_4K + (LOG_SIZE * (n - i));
        pDst = *Buf_4K + (LOG_SIZE * i);
        memcpy(pDst, pSrc, LOG_SIZE);
        
        pSrc = pTemp;
        pDst = *Buf_4K + (LOG_SIZE * (n - i));
        memcpy(pDst, pSrc, LOG_SIZE);
    }
}

/******************************************************************************
 * @brief   Save updated Profile Data to ExFLASH and updated status to EEPROM
 *
 * @note    
 ******************************************************************************/
uint8_t SaveProfile(uint16_t stage)
{
  /*
    #define EXFLASH_PROFILE         0x00116000      // 3M Bytes 
    #define EXFLASH_PROFILE_END     0x003FFFFF      // End of 3M Bytes
*/  
    uint8_t err = 0;    

    uint8_t ProfileEndFlag = false;
    uint16_t i,j;
       
    uint8_t *pProfile;
    uint16_t *pU16Profile;
    
    float Depth;
    float TempF;
    int8_t retry;
    
    pDst = *ProfileBuf_4K;      // two-dimension buffer    
    
        
    // Update PROFILE RAM
    Profile_Data_Update(stage);     // good for Profile's Header, Data and Trailer    
    
    switch(stage)
    {
        case PROFILE_HEADER:
          pProfile = (uint8_t*) &Profile_Header;
          
          if(DEV_Rec.AddrNextProfile < EXFLASH_PROFILE)
              DEV_Rec.AddrNextProfile = EXFLASH_PROFILE;      // Bandage in case that DEV_Rec.AddrNextProfile is out-of-range
          
          // read from ExFLASH index table of the Last Dive
          ProfileHeaderAddr = DEV_Rec.AddrNextProfile;          
          NewSectorStartAddr = ProfileHeaderAddr;
          NewSectorEndAddr = NewSectorStartAddr;
          ProfileBufRowIdx = 0;
          
          // to mark the starting address to Index Table
          // to do
          
          // Initialize 4K Profile Buffer to be 0xAA
          for(j=0; j<((SECTOR_SIZE/PROFILE_SIZE)+(PROFILE_TRAILER_SIZE/PROFILE_SIZE)); j++) 
          {
            for(i=0; i<PROFILE_SIZE; i++) 
            {
              ProfileBuf_4K[j][i] = 0xAA; 
            }
          }
                             
          for(i=0; i<PROFILE_SIZE; i++) 
          {
            // must be (PROFILE_HEADER_SIZE/PROFILE_SIZE) rows
            ProfileBuf_4K[ProfileBufRowIdx][i]= *(pProfile+i);  // new dive always saved at the first row
            ProfileBuf_4K[ProfileBufRowIdx+1][i]= *(pProfile+PROFILE_SIZE+i);  // new dive always saved at the first row
            ProfileBuf_4K[ProfileBufRowIdx+2][i]= *(pProfile+PROFILE_SIZE*2+i);  // new dive always saved at the first row
            ProfileBuf_4K[ProfileBufRowIdx+3][i]= *(pProfile+PROFILE_SIZE*3+i);  // new dive always saved at the first row
            ProfileBuf_4K[ProfileBufRowIdx+4][i]= *(pProfile+PROFILE_SIZE*4+i);  // new dive always saved at the first row
          }

          ProfileBufRowIdx += (PROFILE_HEADER_SIZE/PROFILE_SIZE);        
          
          NewSectorEndAddr += PROFILE_HEADER_SIZE; 
          
          SamplingRateIdx = 0;
          PeriodMaxDepth = 0;
          
          break;
          
        case PROFILE_HEADER_UPDATE:
          pProfile = (uint8_t*) &Profile_Header;
          
          for(i=0; i<PROFILE_SIZE; i++) 
          {
            // must be (PROFILE_HEADER_SIZE/PROFILE_SIZE) rows
            ProfileBuf_4K[0][i]= *(pProfile+i);  // update for Profile Trailer Row0
            ProfileBuf_4K[1][i]= *(pProfile+PROFILE_SIZE+i);  // update for Profile Trailer Row1
            ProfileBuf_4K[2][i]= *(pProfile+PROFILE_SIZE*2+i);  // update for Profile Trailer Row1
            ProfileBuf_4K[3][i]= *(pProfile+PROFILE_SIZE*3+i);  // update for Profile Trailer Row1
            ProfileBuf_4K[4][i]= *(pProfile+PROFILE_SIZE*4+i);  // update for Profile Trailer Row1
          }
       
          break;  
          
          
        case PROFILE_DATA:
          
          if(dDepthFt > PeriodMaxDepth)
              PeriodMaxDepth = dDepthFt;           // to assure Max Depth is recorded in Graphic
            
          if((SamplingRateIdx == 0)||(USER_Set.DiveMode==NVD_MDFREE))  // do Sampling Rate adjustment, enter only when Sample Period Time
          {                                                            // Free Dive sampling rate is always 1 sample/sec
          
            pProfile = (uint8_t*) &Profile_Data;          // pointer for 8-bit data
            pU16Profile = (uint16_t*) &Profile_Data;      // pointer for 16-bit data
              
            for(i=0; i<PROFILE_SIZE; i++) 
              ProfileBuf_4K[ProfileBufRowIdx][i]= *(pProfile+i);  // new dive always saved at the first rowProfileBufRowIdx
            
            
            //===============================================================================================
            //    Profile Data analysis
            //===============================================================================================
            
            //=============================== Find Temp Max, min and Average  ===============================
            //TempF = ((float)*(pProfile+10))/10.0;
            TempF = TP_Info.InstantTemperature_F;
            
            if(TempF > MaxTempF)
                MaxTempF = TempF;
              
            if(TempF < MinTempF)
                MinTempF = TempF;

            totalSum_TempF += TempF;       // TempF of the profile Byte-10
            
            //=============================== Find Depth Average  ===============================
            Depth = ((float)*(pU16Profile+1))/10.0; 
            totalSum_DepthFt += Depth;      // DepthFt at profile Byte-2,3:
            
            
            //================================ Collect Profile Chart Data ===================================
            /*
              extern uint16_t ProfileChartData[];
              extern uint8_t ProfileIdx;      // from 0 to PROFILE_CHART_SIZE - 1
            */            
            
            if(ProfileIdx >= (PROFILE_CHART_SIZE - 1))  // to scale down by (1/2)
            {
                ProfileIdx = (PROFILE_CHART_SIZE/2);                    // scaling down by (1/2)
                ProfileIdxScale *= 2;                                   // scaling down by (1/2)
                for(uint8_t n=0; n<PROFILE_CHART_SIZE; n++)
                {
                    if(n<(PROFILE_CHART_SIZE/2))
                    {
                        ProfileChartData[n] = max(ProfileChartData[n*2], ProfileChartData[n*2+1]);    // scaling down by (1/2)
                        ProfileChartPointY[n/2] = max(ProfileChartPointY[n],  ProfileChartPointY[n+1]);// clear the second half to be 0
                    }
                    else
                    {
                        ProfileChartData[n] = 0;                        // clear the second half to be 0
                        ProfileChartPointY[n/2] = 0;                    // clear the second half to be 0
                    }
                }
            }
            
/*********************************************************************************/
// to move into the LOG Data3 Button Response
/*
            float ChartFitScale = ((float)PROFILE_CHART_SIZE/2.0/ProfileIdx);
              
            if(ProfileIdx > (PROFILE_CHART_SIZE/2))
            {
                for(uint8_t n=0; n<(PROFILE_CHART_SIZE/2); n++)
                {
                    LogChartPOINT_Y[(uint8_t)(ChartFitScale*n)].y = max(ProfileChartData[n*2], ProfileChartData[n*2+1]) & 0x0FFF;    // scaling down by (1/2)
                    LogChartPOINT_Y[(uint8_t)(ChartFitScale*n)].x = n;
                }
            }
            else
            {
                for(uint8_t n=0; n<(PROFILE_CHART_SIZE/2); n++)
                {                    
                    LogChartPOINT_Y[n].y = ProfileChartData[n] & 0x0FFF;    // scaling down by (1/2)
                    LogChartPOINT_Y[n].x = n;
                }            
            }  
            
            GUI_DrawPolyLine((GUI_POINT*)(LogChartPOINT_Y), 2, 40, 28); 
*/            
/*********************************************************************************/            
            
            
            ProfileIdx = (uint8_t)(ProfileSampleCnt/ProfileIdxScale);
            
            uint16_t DecoEntryBit = 0x4000;
            
            if(Alarming.Bit.DECO_Entry == true)
            {
                ProfileChartData[ProfileIdx] = PeriodMaxDepth | DecoEntryBit;       // save the current depth (TO DO, should collect the MaxDepth of last sampling period)
            
                ProfileChartPointY[(uint16_t)(ProfileIdx/2)] = PeriodMaxDepth | DecoEntryBit;
            }
            else
            {
                ProfileChartData[ProfileIdx] = PeriodMaxDepth;       // save the current depth (TO DO, should collect the MaxDepth of last sampling period)
            
                ProfileChartPointY[(uint16_t)(ProfileIdx/2)] = PeriodMaxDepth;
            }
            //===============================================================================================
            ProfileSampleCnt++;          // total Profile Data sample counter
            //===============================================================================================              
              
            ProfileBufRowIdx++;
            NewSectorEndAddr += PROFILE_SIZE; 
            
            Profile_Data.Alarming.AllBits  = 0;  // reset to zero, continue to collect current Alarm Stat from App.c          
            Profile_Data.Alarming2.AllBits = 0; // reset to zero, continue to collect current Alarm Stat from App.c          
          }
          
          // passing this point every second
          if(++SamplingRateIdx >= USER_Set.SamplingTime)
          {
              SamplingRateIdx = 0;
              PeriodMaxDepth = 0;       // reset to 0 for new Depth recording in next sampling period
          }
          break;
          
          
        case PROFILE_TRAILER:
          pProfile = (uint8_t*) &Profile_Trailer;
         
          for(i=0; i<PROFILE_SIZE; i++) 
          {
            ProfileBuf_4K[ProfileBufRowIdx][i]= *(pProfile+i);  // new dive always saved at the first rowProfileBufRowIdx
            ProfileBuf_4K[ProfileBufRowIdx+1][i]= *(pProfile+PROFILE_SIZE+i);  // new dive always saved at the first row
            ProfileBuf_4K[ProfileBufRowIdx+2][i]= *(pProfile+PROFILE_SIZE*2+i);  // new dive always saved at the first row     
          }
            // to mark the ending address to Index Table
            // to do
            
            ProfileBufRowIdx += (PROFILE_TRAILER_SIZE/PROFILE_SIZE);
            NewSectorEndAddr += PROFILE_TRAILER_SIZE;

            //------------------------------------------------------------------------------------------------------------
            // to get rid of last 10 minutes of AfterDive from ProfileChartData, assuming ProfileChartData[i]<=3 is already at After-Dive surface
            i=(PROFILE_CHART_SIZE-1);
            while((ProfileChartData[i]<=3)&&(i>0))
            {
                ProfileIdx = i--;
            }
            
            float ChartFitScale = ((float)(ProfileIdx)/(PROFILE_CHART_SIZE/2));

            for(uint8_t n=0; n<(PROFILE_CHART_SIZE/2); n++)
            {
                LogChartPOINT_X_Y[n].x = n*2;
                LogChartPOINT_X_Y[n].y = max(ProfileChartData[(uint8_t)((n*ChartFitScale))], ProfileChartData[((uint8_t)(n*ChartFitScale))+1]);    // scaling down by (1/2)
                Log_Chart.Data[n] = LogChartPOINT_X_Y[n].y;
            }
            
            // Manual data correction (patching) for the very LAST TWO data points --------------------------------------------------------
            LogChartPOINT_X_Y[(PROFILE_CHART_SIZE/2 - 1)].y = 0;        // set the very last two pixels to be at Water Level (Depth = 0)
            Log_Chart.Data[(PROFILE_CHART_SIZE/2 - 1)] = 0;             // set the very last two pixels to be at Water Level (Depth = 0)
            LogChartPOINT_X_Y[(PROFILE_CHART_SIZE/2 - 2)].y = 0;        // set the very last two pixels to be at Water Level (Depth = 0)
            Log_Chart.Data[(PROFILE_CHART_SIZE/2 - 2)] = 0;             // set the very last two pixels to be at Water Level (Depth = 0)
            
            // Manual data correction (patching) for the very FIRST data point -------------------------------------------------------
            LogChartPOINT_X_Y[0].y = 0;        // set the very first pixel to be at Water Level (Depth = 0)
            Log_Chart.Data[0] = 0;             // set the very first pixel to be at Water Level (Depth = 0)
            //------------------------------------------------------------------------------------------------------------------------

            ProfileEndFlag = true;
    
          break;
    }
    
    
    // Check if time to save a new filled-up 4K Buffer to FLASH
    if(ProfileBufRowIdx >= (SECTOR_SIZE/PROFILE_SIZE) || (ProfileEndFlag == true))    // repeat this for every 4K Sector, or End of Dive
    {      
      
      /*********** Must do this every time before FLASH Erase/Read/Write  ***********/
      L4X9_QSPI_Init();
              
      MT25QL512ABB_PowerDownRelease();
      /******************************************************************************/
      // This read is only for checking, can be removed for product
      // MT25QL512ABB_Read1I1O(EXFLASH_PROFILE, SECTOR_SIZE, pDst); 
          
      // Erase the area about to write 4K Bytes of FLASH
      retry = NVD_FLASH_WRITE_TIMEOUT;    
      do{} while ((MT25QL512ABB_Erase4kSector(NewSectorStartAddr) != true) && (retry-- > 0));		// Timeout added from R1006               
      if(retry <= 0)
      {
          ErrHandle_FLASH();
      }

      retry = NVD_FLASH_WRITE_TIMEOUT;    
      do{} while ((MT25QL512ABB_WriteNPage1I1O(NewSectorStartAddr, SECTOR_SIZE, pDst)!= true) && (retry-- > 0));		// Timeout added from R1006    
      if(retry <= 0)
      {
          ErrHandle_FLASH();
      }
      // MT25QL512ABB_WriteNPage1I1O(NewSectorStartAddr, SECTOR_SIZE, pDst);    // to adjust more offsets, each for 4K here
      
      // Re-Initialize 4K Profile Buffer to be 0xAA
      for(j=0; j<((SECTOR_SIZE/PROFILE_SIZE)+(PROFILE_TRAILER_SIZE/PROFILE_SIZE)); j++) 
      {
        for(i=0; i<PROFILE_SIZE; i++) 
        {
          ProfileBuf_4K[j][i] = 0xAA; 
        }
      }
      
      if(ProfileBufRowIdx > (SECTOR_SIZE/PROFILE_SIZE))         // if Trailer has to cross TWO Sectors, then take care of the second sector here
      {   
          NewSectorStartAddr += SECTOR_SIZE;    // shift for another sector size
          NewSectorStartAddr = CheckAddrForWraping(NewSectorStartAddr, EXFLASH_PROFILE, EXFLASH_PROFILE_END);
          
          // Erase the area about to write 4K Bytes of FLASH
          retry = NVD_FLASH_WRITE_TIMEOUT;
          do{} while ((MT25QL512ABB_Erase4kSector(NewSectorStartAddr) != true) && (retry-- > 0));		// Timeout added from R1006              
          if(retry <= 0)
          {
              ErrHandle_FLASH();
          }

          retry = NVD_FLASH_WRITE_TIMEOUT;    
          do{} while ((MT25QL512ABB_WriteNPage1I1O((NewSectorStartAddr), SECTOR_SIZE, (pDst+SECTOR_SIZE))!= true) && (retry-- > 0));		// Timeout added from R1006    
          if(retry <= 0)
          {
              ErrHandle_FLASH();
          }
          //MT25QL512ABB_WriteNPage1I1O((NewSectorStartAddr), SECTOR_SIZE, (pDst+SECTOR_SIZE));    // to adjust more offsets, each for 4K here
          
          // Re-Initialize 4K Profile Buffer to be 0xAA
          for(j=0; j<((SECTOR_SIZE/PROFILE_SIZE)+(PROFILE_TRAILER_SIZE/PROFILE_SIZE)); j++) 
          {
            for(i=0; i<PROFILE_SIZE; i++) 
            {
              ProfileBuf_4K[j][i] = 0xAA; 
            }
          }
      }
      
      //MT25QL512ABB_Read1I1O(NewSectorStartAddr, SECTOR_SIZE, pCopy);         // test only, to remove for product
      
      /******** Must do this every time after FLASH Erase/Read/Write is done ********/
      MT25QL512ABB_PowerDownEnter();
      
      L4X9_QSPI_DeInit();
      /******************************************************************************/
     
        
        
      //----------------------------------------------------------------------------------------------------------------
      // shift by a sector size if cross to the new sector
      
      if(ProfileEndFlag == true)
      {      
          Log_Data.AvgDepthFt10 = (uint16_t)(Dive_Info.AvgWaterDepth_ft*10.0);

          Log_Data.MaxTempF10 = (int16_t)(Dive_Info.MaxTemp_F*10);
          Log_Data.MinTempF10 = (int16_t)(Dive_Info.MinTemp_F*10);
       
          if(USER_Set.DiveMode == NVD_MDFREE) //--------- Free Dive Only --------------------------
            DEV_Rec.LogFreeNumRecorded++;     // synced up with LogFreeNumRecorded in SaveLog( )              
          else                                //--------- Normal Scuba Dive or Gauge Dive ---------
            DEV_Rec.LogNormNumRecorded++;     // synced up with LogNormNumRecorded in SaveLog( )
              
          DEV_Rec.AddrNewProfileHead = ProfileHeaderAddr;
          DEV_Rec.AddrNewProfileEnd = NewSectorEndAddr;  
          DEV_Rec.AddrLastProfile = NewSectorEndAddr;
          
          NewSectorStartAddr += SECTOR_SIZE;                    // Prepare for Next Dive's Profile-----------
          NewSectorStartAddr = CheckAddrForWraping(NewSectorStartAddr, EXFLASH_PROFILE, EXFLASH_PROFILE_END);
          NewSectorEndAddr = NewSectorStartAddr;                // ------------------------------------------
          
          DEV_Rec.AddrNextProfile = NewSectorStartAddr;
          
          
          EE_SaveReq(EE_DEVREC);    // save DEV_Rec.DiveNumOfDay and DEV_Rec.LogNumX to EE    
          
          
          //===============================================================================================================================
          // Copy the latest Profile Head and End Addresses into the Map for App to retrieve
          FLASH_Map.ProfileHeadAddr = EXFLASH_PROFILE;                          // the head address of the area for recording all LOGs
          FLASH_Map.ProfileTailAddr = EXFLASH_PROFILE_END;                      // the tail address of the area for recording all LOGs
          FLASH_Map.ProfileLastDiveHeadAddr = DEV_Rec.AddrNewProfileHead;       // the head address of the oldest LOG recorded
          FLASH_Map.ProfileLastDiveEndAddr =  DEV_Rec.AddrNewProfileEnd;        // the tail address of the oldest LOG recorded
          
          EE_SaveReq(EE_FLASHMAP);                                               
          //===============================================================================================================================
              
          
          // Re-Initialize for next New Dive
          MaxTempF = -125.0;
          MinTempF = 125.0;          
          totalSum_TempF = 0.0;          
          totalSum_DepthFt = 0.0;
          ProfileSampleCnt = 0;
          ProfileIdx = 0;
          ProfileIdxScale = 1;
          SamplingRateIdx = 0;
          
      }
      else
      {        
          // Not profile end yet, only passing through 4K sector boarder line
          NewSectorStartAddr += SECTOR_SIZE;                    // Continue the same at a new Sector --------
          NewSectorStartAddr = CheckAddrForWraping(NewSectorStartAddr, EXFLASH_PROFILE, EXFLASH_PROFILE_END);
          NewSectorEndAddr = NewSectorStartAddr;                // ------------------------------------------         
      }       

      
      ProfileBufRowIdx = 0; 
      
    }
    
    return err;

}


/*******************************************************************************

    Head Address:       HeadAddr
    Working Address:    WorkAddr
    End Address:        EndAddr
    
    This subroutine is to check End Address of the designated area, if out-of-
    boundary is checked, then wrap the Working Address back to Head Address.
  
*******************************************************************************/
uint32_t CheckAddrForWraping(uint32_t WorkAddr, uint32_t HeadAddr, uint32_t EndAddr)
{
    if(WorkAddr > EndAddr)
       WorkAddr = HeadAddr;

    return WorkAddr;
}


void ClearAllDiverLogs(void)
{
      DEV_Rec.DiveNumOfDay   = 0;
      DEV_Rec.LogNumRecorded = 0;
      DEV_Rec.LogNumLast     = 0;
      DEV_Rec.LogNumDisp     = 0;
      
      DEV_Rec.FreeDiveNumOfDay   = 0;
      DEV_Rec.FreeLogNumRecorded = 0;
      DEV_Rec.FreeLogNumLast     = 0;
      DEV_Rec.FreeLogNumDisp     = 0;

      DEV_Rec.LogNormNumRecorded  = 0;
      DEV_Rec.LogGaugeNumRecorded = 0;
      DEV_Rec.LogFreeNumRecorded  = 0;
      
      DEV_Rec.AddrNewProfileHead = EXFLASH_PROFILE;
      DEV_Rec.AddrNewProfileEnd  = EXFLASH_PROFILE;
      DEV_Rec.AddrLastProfile    = EXFLASH_PROFILE;
      DEV_Rec.AddrNextProfile    = EXFLASH_PROFILE;
      
      FLASH_Map.NormLogHeadAddr = EXFLASH_LOG;
      FLASH_Map.NormLogTailAddr = EXFLASH_LOG_END;
      FLASH_Map.NormLogFirstDiveAddr = EXFLASH_LOG_END;
      FLASH_Map.NormLogNextDiveAddr =  EXFLASH_LOG_END;
                       
      FLASH_Map.ProfileHeadAddr = EXFLASH_PROFILE;
      FLASH_Map.ProfileTailAddr = EXFLASH_PROFILE_END;
      FLASH_Map.ProfileLastDiveHeadAddr = EXFLASH_PROFILE_END;
      FLASH_Map.ProfileLastDiveEndAddr =  EXFLASH_PROFILE_END;
      
      EE_SaveReq(EE_DEVREC);
      
      EE_SaveReq(EE_FLASHMAP);
}

void NewDiveInitialization(void)
{  
  DIVE_TIMER = 0;         /* Dive Timer intialially set as Dive Time to start with */ 
                
  // Update system Date/Time
  UpdateRealTimeDate(&SysTimeDatePST);
  
  ProposedCURRENT_TANK_NUM = 2;   // the first Gas Switch always starts from 1 -> 2, 
                             // while CURRENT_TANK_NUM always starts from 1
  
  /* Update Total Dive Numers of Device Parameters */
  Log_Data.DiveType =  USER_Set.DiveMode;       //Dive Type =  CC, OC, SM, GSM, Gauge
  Log_Data.EntryHr =   SysTimeDatePST.Hour;
  Log_Data.EntryMin =  SysTimeDatePST.Minute;
  Log_Data.EntryDay =  SysTimeDatePST.Day;
  Log_Data.EntryMon =  SysTimeDatePST.Month;
  Log_Data.EntryYear = SysTimeDatePST.Year;
  
  Log_Data.SurfInvT_Hr = (uint8_t)(Dive_Info.SurfTime_s/3600);      // Must be recorded at this instant       
  Log_Data.SurfInvT_Min = (uint8_t)((Dive_Info.SurfTime_s/60)%60);  // Must be recorded at this instant
             
  Log_Data.SeaLevel = Dive_Info.AltitudeLevel;
  Log_Data.AlarmOccured.AllBits = 0;   // clear the old memory, to have a fresh start
  Log_Data.AlarmOccured2.AllBits = 0;   // clear the old memory, to have a fresh start
  
  Dive_Info.AfterDiveGapID = 0;      
  for(uint8_t i=0; i< AfterDiveGapID_Max; i++)
  {
      Dive_Info.AfterDiveSec[i] = 0;
      Log_Chart.AfterDiveSec[i] = 0;      
  }
  Profile_Data.Alarming.AllBits = 0;            // Initialize Profile Data AlarmOn Buffer
  Profile_Data.Alarming2.AllBits = 0;            // Initialize Profile Data AlarmOn Buffer
  Profile_Trailer.AlarmFinal.AllBits = 0;       // Initialize Profile Trailer AlarmFinal Buffer
  Profile_Trailer.AlarmOccured.AllBits = 0;     // Initialize Profile Trailier AlarmOccured Buffer
  Profile_Trailer.GasUsed = (0x01 << (CURRENT_TANK_NUM-1));     // Gas Useage recording starts from CURRENT_TANK_NUM's bit
  // Reset all alarm variable and parameters before each new dive
  
  FindBestGasBO_WhenDiveIn(BO_GasFO2Hi2Lo, BO_BestGasNum);
  
  AlarmInit(); 
  
  GasTankPSI_RecorderInit();              // GasTankPSI_Recorder Initialization for each new dive
  
  // Dive Timer setup initinalization
  DIVE_TIMER_Reset();           // call to reset Dive Timer or CounterUP1_s
  DIVE_TIMER_State = 0;         // 0: Stop (back to 0)     1: Pause             2: Run
  DIVE_TIMER_Display = false;   // No Display from the beginning of each dive
    
  SystemStatus.backlight_on_req = true; // start a new dive with Brightness a setup (NOT dim yet)
  
  EE_SaveReq(EE_SCUBASET);
  EE_SaveReq(EE_TRIMIXSET);  
  
  ////////////// This should be managed in the Decompression Core
  MaxASCBGVal = 0;
  MaxTLBGVal = 0;
  GFmaxValue = 0.0;
  MaxOpDepthFT = 0.0;
  MaxOpDepthM = 0.0;
  PO2MAXatDepth = 0.0;
  MaxOTUpercent = 0;
  ccSPcurrent = ((float)SCUBA_Set.SP_Current)/100.0;
  ccSPstart = ccSPcurrent;
  Pre_ccSPcurrent = ccSPstart;                  // start from a value differnt from ccSPcurrent
  CC_MaxPO2_SetofDive = ccSPstart;
  
  AutoSP_Reached_High = 0;
  AutoSP_Reached_Low = 0;
  AutoSP_Switched_High = false;
  AutoSP_Switched_Low = false;
  
  if(SCUBA_Set.SP_Current == SCUBA_Set.SP_SetLow)
  {
    AutoSP_Started_High = false;
    AutoSP_Started_Low = true;
  }
  else if(SCUBA_Set.SP_Current == SCUBA_Set.SP_SetHigh)
  {
    AutoSP_Started_High = true;
    AutoSP_Started_Low = false;
  }
  else
  {
    AutoSP_Started_High = false;
    AutoSP_Started_Low = false;
  }  
  
  AutoSP_High_MaunalOverwrite = false;
  AutoSP_Low_MaunalOverwrite = false;
  ccSP_AutoChangedToHigh = false;
  ccSP_AutoChangedToLow = false;
  ccSP_ManualChangedToHigh = false;
  ccSP_ManualChangedToLow = false;
  
  Dive_Info.ModeSwitchFlag = MODE_SWITCH_NONE;
}

// collect dive information at the end of After-Dive, before saving to EEPROM going to sleep
void EndOfNewDiveDataCollection(void)
{
  uint32_t TotalDiveSec;
  
  TotalDiveSec = 3600*DEV_Rec.TotalHours+60*DEV_Rec.TotalMins+DEV_Rec.TotalSecs+Dive_Info.DiveTime_s;
  
  DEV_Rec.TotalHours = TotalDiveSec/3600;
  DEV_Rec.TotalMins = (uint8_t)((TotalDiveSec/60)%60);
  DEV_Rec.TotalSecs = (uint8_t)(TotalDiveSec%60);
  DEV_Rec.RetainIndex = 1;              // to assure Data Retention begin now (no need to wait)
  
  // Clear Device Records That Diving is ongoing
  DEV_Rec.DivingOngoing = 0;
    
  NewDiveWhenLowBatt = false; // will check again in every NewDiveInitialization( ) of new dive
  
  Dive_Info.PrevDiveTime_s       = Dive_Info.DiveTime_s;
  Dive_Info.PrevMaxWaterDepth_m  = Dive_Info.MaxWaterDepth_m;
  Dive_Info.PrevMaxWaterDepth_ft = Dive_Info.MaxWaterDepth_ft;
  
  Log_Data.MaxDepthFt10 = (uint16_t)(Dive_Info.MaxWaterDepth_ft*10);
  Log_Data.EDTsec       = (uint16_t)Dive_Info.DiveTime_s;   // DiveTime under water
  Log_Data.TotalDiveSec = (uint16_t)Dive_Info.TotalDiveTime;    // Total Time of underwater plus the surface time between re-entries of the same dive
  
  Log_Data.MaxTempF10 = (int16_t)(Dive_Info.MaxTemp_F*10);      // record highest Temp-F during the dive
  Log_Data.MinTempF10 = (int16_t)(Dive_Info.MinTemp_F*10);      // record lowest Temp-F during the dive
  Log_Data.EndDiveType = USER_Set.DiveMode;       //Dive Type =  CC, OC, SM, GSM, Gauge       
  for(uint8_t i=0;i<=TLBG_Line_NumBar;i++)
      Log_Data.TLBGS[i] = TLBG_ARRAY[TLBG_Line_NumBar - i - 1]; // value should be same to TissLine_NumBar 
  for(uint8_t i=0; i< AfterDiveGapID_Max; i++)
      Log_Chart.AfterDiveSec[i] = Dive_Info.AfterDiveSec[i];
  
  GasTankPSI_RecorderToSave();  // Collect TMT's Start and End of dive's PSI information for LOG Data1
      
  // Dive Timer setup Re-Initinalization, prepare for next dive with Dive Timer OFF
  DIVE_TIMER_Reset();           // call to reset Dive Timer or CounterUP1_s
  DIVE_TIMER_State = 0;         // 0: Stop (back to 0)     1: Pause             2: Run
  DIVE_TIMER_Display = false;   // No Display from the beginning of each dive
  
  if(NVD_MDBO==DIVE_MODE)       // All BO dives must return back to CC at the end of each dive
  {
      DIVE_MODE = NVD_MDCC;
      RETURN_DIVE_MODE = NVD_MDCC;
      GUI_DIVE_Mode = NVD_MDCC;   // switch back to CC mode before go diving or other surface settings
  }
  
  EE_SaveReq(EE_DEVREC);            // save to EE
  EE_SaveReq(EE_USERSET);            // save to EE
}

// collect dive infomration at beginning of After-Dive, not yet saving to EEPROM
void BackToSurfDataCollection(void)    
{
    TLBGVal_Log = TLBGVal;      // save TLBGVal at the moment of exiting dive
    Log_Data.SurfInvT_Hr = (uint8_t)(Dive_Info.PrevSurfTime_s/3600);
    Log_Data.SurfInvT_Min = (uint8_t)((Dive_Info.PrevSurfTime_s/60)%60);
    
    if(USER_Set.DiveMode == NVD_MDFREE) //--------- Free Dive Only --------------------------
    {
        Log_Data.DiveNum = DEV_Rec.FreeDiveNumOfDay;  // 2-Byte Dive Number++  of the Same Day, incremented at the moment from Surf to Dive        
                                                      // no worry about divning again during 10-minute After-Dive period, no change  
        
        SystemStatus.user_act_timestamp = (MonotonicClock_s - (60 * 9));    // to assure PSM kicks in one minutes after Surface Time (End of After-Free-Dive)
    }
    else
    {
        Log_Data.DiveNum = DEV_Rec.DiveNumOfDay;      // 2-Byte Dive Number++  of the Same Day, incremented at the moment from Surf to Dive        
                                                      // no worry about divning again during 10-minute After-Dive period, no change  
        
        SystemStatus.user_act_timestamp = MonotonicClock_s;              // to assure PSM kicks in 10 minutes after Surface Time (End of After-Dive)
    }

    Log_Data.MaxDepthFt10 = (uint16_t)(Dive_Info.MaxWaterDepth_ft*10);
    Log_Data.EDTsec       = (uint16_t)Dive_Info.DiveTime_s;   // DiveTime under water
    Log_Data.ExitHr =   SysTimeDatePST.Hour;
    Log_Data.ExitMin =  SysTimeDatePST.Minute;    
    Log_Data.SeaLevel = Dive_Info.AltitudeLevel;  
    Log_Data.MaxPO2 = (uint16_t)(100 * PO2MAXatDepth);
    Log_Data.O2Sat = MaxOTUpercent;
    Log_Data.MaxTLBG = MaxTLBGVal;  // Record Max O2% throughout the dive.  
}


// Data Restoration after phantom dive detected, to restore pre-dive condition 
void PhamtonDiveDataRestore(void)
{ 
  
    SystemStatus.backlight_on_req = true; // start a new dive with Brightness a setup (NOT dim yet)
        
    // Set in Device Records That Diving is ongoing
    DEV_Rec.DivingOngoing = 0;
    EE_SaveReq(EE_DEVREC);  
   
    /* Reset Phantom Dive Check Counter and Flag */
    Dive_Info.PhantomCheckDone = false;
    Dive_Info.NoPhantomCtr = 0;
    Dive_Info.Dive10hDetected = false;
    
    if((DEV_Rec.DiveNumOfDay==0)&&(DEV_Rec.FreeDiveNumOfDay==0))
    {
        Dive_Info.Status = AMB_DIVEINFO_NEWDAY;
    }
    else
    {
        Dive_Info.Status = AMB_DIVEINFO_SURF;
    }  
    
}


// Data Update after No Phantom Dive confirmed, to continue a Scuba/Gauge/Free dive 
void NoPhamtonDiveDataUpdate(void)
{ 
  
    /* Initialize Surface Time */
    Dive_Info.PrevSurfTime_s = Dive_Info.SurfTime_s;    // Moved to the moment when NoPhandive is confirmed        // T1.001.010
        
    Dive_Info.SurfTime_s = 0;                           // clear the SurfTime when a real dive is confirmed

    DEV_Rec.LogNumRecorded++;
    DEV_Rec.DiveNumOfDay++;     // 2-Byte Dive Number++  of the Same Day
    DEV_Rec.LogNumLast++; 
    DEV_Rec.DevTotalDiveNum++;      // DevTotalDiveNum records completed dives and unfinihsed dives
    
    if(((USER_Set.DiveMode == NVD_MDGSM)||(USER_Set.DiveMode == NVD_MDGAUGE))&&(DEV_Rec.LockForGaugeDive == 0))
        DEV_Rec.LockForGaugeDive = 1;   // Reset to release the lockup at Gauge Dive or GSM Dive (CC, OC, BO, SM not allowed after diving at Gauge or GSM mode)
    
    Log_Data.LogNum = DEV_Rec.LogNumRecorded;     
    Log_Data.DiveNum = DEV_Rec.DiveNumOfDay;      // 2-Byte Dive Number++  of the Same Day, incremented at the moment from Surf to Dive        
                                                      // no worry about divning again during 10-minute After-Dive period, no change  
    
    Profile_Header.LogNum   = Log_Data.LogNum;  
    Profile_Header.DiveNum  = Log_Data.DiveNum;    
    Profile_Trailer.LogNum  = Log_Data.LogNum;   
    Profile_Trailer.DiveNum = Log_Data.DiveNum;    
   
    // Set in Device Records That Diving is ongoing
    DEV_Rec.DivingOngoing = 1;

    // save all setups from NewDiveInitialization() and here
    EE_SaveReq(EE_DEVREC);       // modified for R1006 to record the "DEV_Rec.DivingOngoing" bit for a new dive confirmation, without further delay
}

void ClearProfileChartData(void)
{
    for(uint16_t i=0; i<PROFILE_CHART_SIZE; i++)
    {
        *(ProfileChartData+i) = 0;    
    }  
}
