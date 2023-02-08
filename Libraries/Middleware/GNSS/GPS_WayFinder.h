/*******************************************************************************
 * @file        : GPS_WayFinder.h
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
   
#ifndef _GPS_WAYFINDER_H_
#define _GPS_WAYFINDER_H_

#define GPS_LOCATION_NUM_MAX    20
/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/

typedef struct {
    SystemTimeDate_t DateTime;  /* 8-Byte uint8 GPS Date and Time Info */
    float Latitude;             /* 4-Byte float GPS Latitude Data */
    float Longitude;            /* 4-Byte float GPS Longitude Data */
    char LocationName[20];      /* 20-Byte char GPS Location Name String */
    char Reserved[10];          /* 10-Byte Reserved */
    uint16_t DataCtrl;          /* 2-Byte Data Control bits */
    SystemTimeDate_t EndDiveDateTime;   /* 8-Byte uint8 GPS Date and Time Info */    
    float EndDiveLatitude;              /* 4-Byte float GPS Latitude Data for End of Dive */
    float EndDiveLongitude;             /* 4-Byte float GPS Longitude Data for End of Dive */
} GPS_LocationRec_t;


typedef struct {
  GPS_LocationRec_t GPS_Loc[GPS_LOCATION_NUM_MAX];      // Make sure Locations #1 to #20 (latest)
} GPS_WayFinder_t;



/*******************************************************************************
 * @brief	Save one location to Way Finder Database onto ExFLASH
 *
 * @return	none
*******************************************************************************/
void GPS_SaveCurrentLocation(void);

/*******************************************************************************
 * @brief	Read locations from Way Finder Database from ExFLASH
 *
 * @return	none
*******************************************************************************/
void GPS_ReadLocations(void);

/******************************************************************************
 * @brief   Wayfinder Read All Recorded Locations
 *
 * @note    
 ******************************************************************************/
void Wayfinder_ReadAllLocations(uint16_t);

/******************************************************************************
 * @brief   Wayfinder Add One Location
 *
 * @note    
 ******************************************************************************/
void Wayfinder_AddOneLocation(GPS_LocationRec_t);   // The GPS Database for the newly added location

/******************************************************************************
 * @brief   Wayfinder Delete One Location
 *
 * @note    
 ******************************************************************************/
void Wayfinder_DeleteOneLocation(uint8_t);   // The GPS Database for the newly added location

/******************************************************************************
 * @brief   GPS_LOC_4K_To_GUI_WayFinder(uint16_t n) to stuff Data 
 *            from GPS_LOC_4K buffer to GUI_WayFinder
 * @note     
 ******************************************************************************/
bool GPS_LOC_4K_To_GUI_WayFinder(uint16_t);

/******************************************************************************
 * @brief   void Select_Target_Loc(uint16_t)
 *            
 * @note    prepare for GO TO LOCATION, place the selected data to Target_Loc
 ******************************************************************************/
void Select_Target_Loc(uint16_t);

//extern GPS_WayFinder_t WayFinder;      // The GPS Database to save into ExFLASH
extern GPS_WayFinder_t GUI_WayFinder;  // The GPS Database read back from ExFLASH
extern GPS_LocationRec_t Target_Loc;   // The GPS Database for the selected target
#endif
