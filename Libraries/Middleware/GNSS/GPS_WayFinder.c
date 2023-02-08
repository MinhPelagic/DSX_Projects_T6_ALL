/*******************************************************************************
 * @file        : GPS_WayFinder.c
 * @brief       : Middleware for GPS_WayFinder
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2021-2021.
 * Author: YeuShyr Wu           Pelagic Pressure Systems or Aqualung
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
#include "L4X9_includes.h"

#ifdef _GPS_WAYFINDER_H_


/*******************************************************************************
 * @brief   GLOBAL Variables
 *
 *   typedef struct {
 *     SystemTimeDate_t DateTime;  // 8-Byte uint8 GPS Date and Time Info 
 *     float Latitude;             // 4-Byte float GPS Latitude Data 
 *     float Longitude;            // 4-Byte float GPS Longitude Data 
 *     char LocationName[16];      // 16-Byte char GPS Location Name String 
 *   } GPS_LocationRec_t;
 *
 *   typedef struct {
 *     GPS_LocationRec_t LocationsA[8];      // Locations #1 to #8 (latest)
 *     GPS_LocationRec_t LocationsB[8];      // Locations #9 to #16
 *     GPS_LocationRec_t LocationsC[8];      // Locations #17 to #24 (oldest)
 *   } GPS_WayFinder_t;
 *
*******************************************************************************/

extern uint8_t DelIndex;
GPS_LocationRec_t LocToSave; // The GPS Database to save into ExFLASH
GPS_WayFinder_t GUI_WayFinder;  // The GPS Database read back from ExFLASH
GPS_LocationRec_t Target_Loc;   // The GPS Database for the selected target

GPS_LocationRec_t GPS_LOC_4K[SECTOR_SIZE/64]; 
void Wayfinder_DeleteLocation(uint8_t del_index);
/*******************************************************************************
 * @brief	Save one location to Way Finder Database onto ExFLASH
 *
 * @return	none
*******************************************************************************/
void GPS_SaveCurrentLocation(void)
{
    LocToSave.Latitude  = GnssGGA.Latitude_DD;
    LocToSave.Longitude = GnssGGA.Longitude_DD;
    LocToSave.DateTime = SysTimeDatePST;
    
    Wayfinder_AddOneLocation(LocToSave);
}


void GPS_DeleteLocation(void)
{
	//uint8_t index = WfinderCtrVar.currentHighlight; 
	Wayfinder_DeleteLocation(DelIndex);

}

void Wayfinder_DeleteLocation(uint8_t del_index)
{
	uint8_t index =  (USER_Set.WayFinderLocNum-1)-del_index;
	   
	GPS_LocationRec_t ZeroLocToSave; 
	ZeroLocToSave.Latitude  = 12.34;
	ZeroLocToSave.Longitude = 56.78;
	ZeroLocToSave.DateTime = SysTimeDatePST;
	

    uint8_t LocOfSec;   // the order of the GPS Loc of the Section  (0, 1, 2, .......60, 61, 62, 63. since there are 64 of GPS Loc in one Sector)
    uint16_t Sector;    // the sector number from the Head Address of LOG
    
    uint32_t pFlash;
    uint8_t *pSrc;     
    
    uint8_t *pNewLoc;

    uint16_t NewGPSnum, SizeOfLoc;         // the sequence number of the latest saved GPS location   
    int retry;
    
    pSrc = (uint8_t*)GPS_LOC_4K;    

	
	/*rearrange location*/
	//GPS_LOC_4K_To_GUI_WayFinder();
	//for(uint8_t loop_index = index; loop_index >0; loop_index--)
	for(uint8_t loop_index = index; loop_index <(USER_Set.WayFinderLocNum-1); loop_index++)	
	{

		NewGPSnum = loop_index; 
//		ZeroLocToSave.Latitude  		= GUI_WayFinder.GPS_Loc[loop_index-1].Latitude;
//		ZeroLocToSave.Longitude 		= GUI_WayFinder.GPS_Loc[loop_index-1].Longitude;
//		ZeroLocToSave.DateTime   		= GUI_WayFinder.GPS_Loc[loop_index-1].DateTime;
//		
//		ZeroLocToSave.EndDiveDateTime   = GUI_WayFinder.GPS_Loc[loop_index-1].EndDiveDateTime;
//		ZeroLocToSave.EndDiveLatitude  	= GUI_WayFinder.GPS_Loc[loop_index-1].EndDiveLatitude;	
//		ZeroLocToSave.EndDiveLongitude  = GUI_WayFinder.GPS_Loc[loop_index-1].EndDiveLongitude;	
//
//		memcpy((int *)(ZeroLocToSave.LocationName), (int*)(GUI_WayFinder.GPS_Loc[loop_index-1].LocationName), 20);


		ZeroLocToSave.Latitude  		= GPS_LOC_4K[loop_index+1].Latitude;
		ZeroLocToSave.Longitude 		= GPS_LOC_4K[loop_index+1].Longitude;
		ZeroLocToSave.DateTime   		= GPS_LOC_4K[loop_index+1].DateTime;
		
		ZeroLocToSave.EndDiveDateTime   = GPS_LOC_4K[loop_index+1].EndDiveDateTime;
		ZeroLocToSave.EndDiveLatitude  	= GPS_LOC_4K[loop_index+1].EndDiveLatitude;	
		ZeroLocToSave.EndDiveLongitude  = GPS_LOC_4K[loop_index+1].EndDiveLongitude;	

		memcpy((int *)(ZeroLocToSave.LocationName), (int*)(GPS_LOC_4K[loop_index+1].LocationName), 20);

		

		//ZeroLocToSave.DateTime.Day 		= GUI_WayFinder.GPS_Loc[loop_index+1].DateTime.Day; /*Day*/
		//ZeroLocToSave.DateTime.Month 	= GUI_WayFinder.GPS_Loc[loop_index+1].DateTime.Month; /*Month*/
		//ZeroLocToSave.DateTime.Year 	= GUI_WayFinder.GPS_Loc[loop_index+1].DateTime.Year; /*Year*/
		//ZeroLocToSave.DateTime.Hour 	= GUI_WayFinder.GPS_Loc[loop_index+1].DateTime.Hour; /*Hour*/
		//ZeroLocToSave.DateTime.Minute 	= GUI_WayFinder.GPS_Loc[loop_index+1].DateTime.Minute; /*Minute*/

							
		SizeOfLoc = sizeof(GPS_LocationRec_t);
		
		/*********** Must do this every time before FLASH Erase/Read/Write	***********/
		L4X9_QSPI_Init();
				
		MT25QL512ABB_PowerDownRelease();
		/******************************************************************************/
	  
		Sector	  = NewGPSnum / (SECTOR_SIZE/SizeOfLoc);						// index of each 4K sector (out of total 16K in ExFLASH)
		LocOfSec  = (uint8_t)(NewGPSnum % (SECTOR_SIZE/SizeOfLoc)); 			// index of LOG position within each 4K sector
			
		pFlash = EXFLASH_GPS + (SECTOR_SIZE * Sector);
	
		//----------------------------------------------------------------------------------------------------
		retry = NVD_FLASH_READ_TIMEOUT;    
                do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, (uint8_t*)pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006        // (ExFLASH address to read from,  Read Size in Byte,  Address point of the Array to load read back data)
                        if(retry <= 0)
                {
                    ErrHandle_FLASH();
                }

		ZeroLocToSave.DataCtrl = 0x8000;		   // to make this new Location eabled to display (b1000 0000 0000 0000 to display;   b00000000000000000 to be deleted)
		
		pNewLoc = (uint8_t*) &ZeroLocToSave;
	
		memcpy((pSrc+SizeOfLoc*LocOfSec), pNewLoc, SizeOfLoc);
			
		 // Erase the area about to write one LOG	 
		retry = NVD_FLASH_WRITE_TIMEOUT;    
                do{} while ((MT25QL512ABB_Erase4kSector(pFlash) != true) && (retry-- > 0));		// Timeout added from R1006     	  // Erase 4K space
                if(retry <= 0)
                {
                    ErrHandle_FLASH();
                }
  
		retry = NVD_FLASH_WRITE_TIMEOUT;    
                do{} while ((MT25QL512ABB_WriteNPage1I1O(pFlash, SECTOR_SIZE, pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006     // Write back 4K sector
                        if(retry <= 0)
                {
                    ErrHandle_FLASH();
                }

		retry = NVD_FLASH_READ_TIMEOUT;    
                do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006     // Read 4K sector (for checking only)
                        if(retry <= 0)
                {
                    ErrHandle_FLASH();
                }

		/******** Must do this every time after FLASH Erase/Read/Write is done ********/
		MT25QL512ABB_PowerDownEnter();
		
		L4X9_QSPI_DeInit();

	}

	


	/*update LocNum index*/
    USER_Set.WayFinderLocNum = USER_Set.WayFinderLocNum - 1;  
    EE_SaveReq(EE_USERSET);		        // save to EE
    
}

/*******************************************************************************
 * @brief	Read locations from Way Finder Database from ExFLASH
 *
 * @return	none
*******************************************************************************/
void GPS_ReadLocations(void)
{
#if 0
    GUI_WayFinder.Location[0].Latitude  = GnssGGA.Latitude_DD;
    GUI_WayFinder.Location[0].Longitude = GnssGGA.Longitude_DD;
    WayFinder.DateTime = SysTimeDatePST;
    strcpy(WayFinder.LocationName, "Latest Location");
#endif    
}
/******************************************************************************
 * @brief   Wayfinder Read All Recorded Locations
 *
 * @note    
 ******************************************************************************/
void Wayfinder_ReadAllLocations(uint16_t num)
{  
    // 4K Bytes = 4096 Bytes = 64 Bytes x 64
    //uint8_t LocOfSec;   // the order of the GPS Loc of the Section  (0, 1, 2, .......60, 61, 62, 63. since there are 64 of GPS Loc in one Sector)
    uint16_t Sector;    // the sector number from the Head Address of LOG
      
    GPS_LocationRec_t *pDst;
    uint32_t pFlash;    
    uint16_t SizeOfLoc;         // the sequence number of the latest saved GPS location   
    int8_t retry;
    
    pDst = (GPS_LocationRec_t *)GPS_LOC_4K; 
    
    SizeOfLoc = sizeof(GPS_LocationRec_t);
    
/*********** Must do this every time before FLASH Erase/Read/Write  ***********/
    L4X9_QSPI_Init();
            
    MT25QL512ABB_PowerDownRelease();
/******************************************************************************/
  
    Sector    = num / (SECTOR_SIZE/SizeOfLoc);                  // index of each 4K sector (out of total 16K in ExFLASH)
    //LocOfSec  = (uint8_t)(num % (SECTOR_SIZE/SizeOfLoc));       // index of LOG position within each 4K sector
        
    pFlash = EXFLASH_GPS + (SECTOR_SIZE * Sector);

    //----------------------------------------------------------------------------------------------------
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, (uint8_t*)pDst)!= true)&& (retry-- > 0));		// Timeout added from R1006          // (ExFLASH address to read from,  Read Size in Byte,  Address point of the Array to load read back data)
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

/******** Must do this every time after FLASH Erase/Read/Write is done ********/
    MT25QL512ABB_PowerDownEnter();
    
    L4X9_QSPI_DeInit();
/******************************************************************************/
}

/******************************************************************************
 * @brief   Wayfinder Add One Location
 *
 * @note    
 ******************************************************************************/
void Wayfinder_AddOneLocation(GPS_LocationRec_t NewLoc)   // The GPS Database for the newly added location
{
    // 4K Bytes = 4096 Bytes = 64 Bytes x 64
    uint8_t LocOfSec;   // the order of the GPS Loc of the Section  (0, 1, 2, .......60, 61, 62, 63. since there are 64 of GPS Loc in one Sector)
    uint16_t Sector;    // the sector number from the Head Address of LOG
    
    uint32_t pFlash;
    uint8_t *pSrc;     
    
    uint8_t *pNewLoc;

    uint16_t NewGPSnum, SizeOfLoc;         // the sequence number of the latest saved GPS location   
    int8_t retry;
    
    pSrc = (uint8_t*)GPS_LOC_4K;    
      
    NewGPSnum = USER_Set.WayFinderLocNum; 
    
    SizeOfLoc = sizeof(GPS_LocationRec_t);
    
/*********** Must do this every time before FLASH Erase/Read/Write  ***********/
    L4X9_QSPI_Init();
            
    MT25QL512ABB_PowerDownRelease();
/******************************************************************************/
  
    Sector    = NewGPSnum / (SECTOR_SIZE/SizeOfLoc);               // index of each 4K sector (out of total 16K in ExFLASH)
    LocOfSec  = (uint8_t)(NewGPSnum % (SECTOR_SIZE/SizeOfLoc)); // index of LOG position within each 4K sector
        
    pFlash = EXFLASH_GPS + (SECTOR_SIZE * Sector);

    //----------------------------------------------------------------------------------------------------
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, (uint8_t*)pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006          // (ExFLASH address to read from,  Read Size in Byte,  Address point of the Array to load read back data)
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    NewLoc.DataCtrl = 0x8000;           // to make this new Location eabled to display (b1000 0000 0000 0000 to display;   b00000000000000000 to be deleted)
    
    pNewLoc = (uint8_t*) &NewLoc;

    memcpy((pSrc+SizeOfLoc*LocOfSec), pNewLoc, SizeOfLoc);
        
     // Erase the area about to write one LOG    
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_Erase4kSector(pFlash) != true) && (retry-- > 0));		// Timeout added from R1006          // Erase 4K space
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O(pFlash, SECTOR_SIZE, pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006           // Write back 4K sector
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O(pFlash, SECTOR_SIZE, pSrc)!= true) && (retry-- > 0));		// Timeout added from R1006        // Read 4K sector (for checking only)
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

/******** Must do this every time after FLASH Erase/Read/Write is done ********/
    MT25QL512ABB_PowerDownEnter();
    
    L4X9_QSPI_DeInit();
/******************************************************************************/
    
    USER_Set.WayFinderLocNum = NewGPSnum + 1;   // increment by 1 
    
    EE_SaveReq(EE_USERSET);		        // save to EE
}

/******************************************************************************
 * @brief   Wayfinder Delete One Location
 *
 * @note     
 ******************************************************************************/
void Wayfinder_DeleteOneLocation(uint8_t idx)           // NOT DONE YET, to do this in a correct way
{
#if 0    
    uint8_t i = 7;
    int8_t retry;
    
    /* PowerOn External Flash */
    L4X9_QSPI_Init();
    MT25QL512ABB_PowerDownRelease();
                                      
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O( WAYFINDER_LOCATION_ADDR,     8*sizeof(GPS_LocationRec_t), &GUI_WayFinder.Location)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
                                  
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O( WAYFINDER_LOCATION_ADDR+256, 8*sizeof(GPS_LocationRec_t), &WayFinder.LocationsB)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
                                  
    retry = NVD_FLASH_READ_TIMEOUT;    
    do{} while((MT25QL512ABB_Read1I1O( WAYFINDER_LOCATION_ADDR+512, 8*sizeof(GPS_LocationRec_t), &WayFinder.LocationsC)!= true) && (retry-- > 0));		// Timeout added from R1006     
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    for(i=7; i>=1; i--)
    {
        WayFinder.LocationsC[i].Latitude      = WayFinder.LocationsC[i-1].Latitude;
        WayFinder.LocationsC[i].Longitude     = WayFinder.LocationsC[i-1].Longitude;
        WayFinder.LocationsC[i].DateTime      = WayFinder.LocationsC[i-1].DateTime;
        strcpy(WayFinder.LocationsC[i].LocationName, WayFinder.LocationsC[i-1].LocationName);
    }
 
    WayFinder.LocationsC[0].Latitude     = WayFinder.LocationsB[7].Latitude;
    WayFinder.LocationsC[0].Longitude    = WayFinder.LocationsB[7].Longitude;
    WayFinder.LocationsC[0].DateTime     = WayFinder.LocationsB[7].DateTime;
    strcpy(WayFinder.LocationsC[0].LocationName, WayFinder.LocationsB[7].LocationName);
    
    for(i=7; i>=1; i--)
    {
        WayFinder.LocationsB[i+1].Latitude      = WayFinder.LocationsB[i-1].Latitude;
        WayFinder.LocationsB[i+1].Longitude     = WayFinder.LocationsB[i-1].Longitude;
        WayFinder.LocationsB[i+1].DateTime      = WayFinder.LocationsB[i-1].DateTime;
        strcpy(WayFinder.LocationsB[i+1].LocationName, WayFinder.LocationsB[i-1].LocationName);
    }
    
    WayFinder.LocationsB[0].Latitude     = GUI_WayFinder.Location[7].Latitude;
    WayFinder.LocationsB[0].Longitude    = GUI_WayFinder.Location[7].Longitude;
    WayFinder.LocationsB[0].DateTime     = GUI_WayFinder.Location[7].DateTime;
    strcpy(WayFinder.LocationsB[0].LocationName, GUI_WayFinder.Location[7].LocationName);
    
    for(i=7; i>=1; i--)
    {
        GUI_WayFinder.Location[i].Latitude      = GUI_WayFinder.Location[i-1].Latitude;
        GUI_WayFinder.Location[i].Longitude     = GUI_WayFinder.Location[i-1].Longitude;
        GUI_WayFinder.Location[i].DateTime      = GUI_WayFinder.Location[i-1].DateTime;
        strcpy(GUI_WayFinder.Location[i].LocationName, GUI_WayFinder.Location[i-1].LocationName);
    }
        
    GUI_WayFinder.Location[0].Latitude  = GnssGGA.Latitude_DD;
    GUI_WayFinder.Location[0].Longitude = GnssGGA.Longitude_DD;
    GUI_WayFinder.Location[0].DateTime = SysTimeDatePST;
    strcpy(GUI_WayFinder.Location[0].LocationName, "Latest Location");
  
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while((MT25QL512ABB_Erase4kSector(WAYFINDER_LOCATION_ADDR)!= true) && (retry-- > 0));		// Timeout added from R1006     // Erase 4K space
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
                                  
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O(WAYFINDER_LOCATION_ADDR,     8*sizeof(GPS_LocationRec_t), &GUI_WayFinder.Location)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O(WAYFINDER_LOCATION_ADDR+256, 8*sizeof(GPS_LocationRec_t), &WayFinder.LocationsB)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }
    
    retry = NVD_FLASH_WRITE_TIMEOUT;    
    do{} while ((MT25QL512ABB_WriteNPage1I1O(WAYFINDER_LOCATION_ADDR+512, 8*sizeof(GPS_LocationRec_t), &WayFinder.LocationsC)!= true) && (retry-- > 0));		// Timeout added from R1006
    if(retry <= 0)
    {
        ErrHandle_FLASH();
    }

    /* PowerDown External Flash */
    while (MT25QL512ABB_PowerDownEnter() != true){};
    L4X9_QSPI_DeInit();
#endif    
}

/******************************************************************************
 * @brief   GPS_LOC_4K_To_GUI_WayFinder(uint16_t n) to stuff Data 
 *            from GPS_LOC_4K buffer to GUI_WayFinder
 * @note     
 ******************************************************************************/
bool GPS_LOC_4K_To_GUI_WayFinder(uint16_t n)
{
    bool state = false;
    uint16_t LOCnum;
    
    LOCnum = USER_Set.WayFinderLocNum;
    
    if(LOCnum > n)
    {  
        GUI_WayFinder.GPS_Loc[n].DateTime   = GPS_LOC_4K[LOCnum - n - 1].DateTime;
        GUI_WayFinder.GPS_Loc[n].Latitude   = GPS_LOC_4K[LOCnum - n - 1].Latitude;
        GUI_WayFinder.GPS_Loc[n].Longitude  = GPS_LOC_4K[LOCnum - n - 1].Longitude;
        for(uint8_t i = 0; i<20; i++)
            GUI_WayFinder.GPS_Loc[n].LocationName[i] = GPS_LOC_4K[LOCnum - n - 1].LocationName[i];
        
        state = true;
    }
    
    return state;
}

/******************************************************************************
 * @brief   void Select_Target_Loc(uint16_t n);
 *            
 * @note    prepare for GO TO LOCATION, place the selected data to Target_Loc
 ******************************************************************************/
void Select_Target_Loc(uint16_t n)
{
    Target_Loc.DateTime = GUI_WayFinder.GPS_Loc[n].DateTime;
    Target_Loc.Latitude = GUI_WayFinder.GPS_Loc[n].Latitude;
    Target_Loc.Longitude = GUI_WayFinder.GPS_Loc[n].Longitude;
    GnssGGA.Latitude_Target_DD  = Target_Loc.Latitude;
    GnssGGA.Longitude_Target_DD = Target_Loc.Longitude;
    strcpy(Target_Loc.LocationName, GUI_WayFinder.GPS_Loc[n].LocationName);
}
#endif