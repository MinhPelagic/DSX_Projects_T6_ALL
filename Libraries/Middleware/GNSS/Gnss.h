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

#ifndef _GNSS_H_
#define _GNSS_H_

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

// GNSS chip Commands
#define GPS_SET_BSSL_GGA        "@BSSL 1\r\n"           //GGA
#define GPS_SET_BSSL_GLL        "@BSSL 2\r\n"           //GLL
#define GPS_SET_BSSL_GSA        "@BSSL 4\r\n"           //GSA
#define GPS_SET_BSSL_GSV        "@BSSL 8\r\n"           //GSV
#define GPS_SET_BSSL_GNS        "@BSSL 10\r\n"          //GNS
#define GPS_SET_BSSL_RMC        "@BSSL 20\r\n"          //RMC
#define GPS_SET_BSSL_TVG        "@BSSL 40\r\n"          //VTG
#define GPS_SET_BSSL_ZDA        "@BSSL 80\r\n"          //ZDA

#define GPS_SET_BAUD_RATE       "@CSBR 9600\r\n"

#define GPS_COLD_START          "@GCD\r\n"
#define GPS_SET_GNS             "@GNS 3\r\n"
#define GPS_SET_GSOP            "@GSOP 01 1000 0\r\n"
//#define GPS_SET_GSOP            "@GSOP 01 1000 500 \r\n"

#define GPS_HOT_START           "@GSP\r\n"
#define GPS_HOT_START_TTFF      "@GSR\r\n"
#define GPS_SET_IDLE            "@GSTP\r\n"
#define GPS_WARM_START          "@GSW\r\n"

#define GPS_SET_SLEEP_0         "@SLP 00\r\n"
#define GPS_SET_SLEEP_1         "@SLP 01\r\n"
#define GPS_SET_SLEEP_2         "@SLP 02\r\n"

#define GPS_WUKEUP              "@WUP\r\n"

#define GPS_FER                 "@FER\r\n"
#define GPS_LOADH               "LOADH\r"
#define GPS_LOADC               "LOADC\r"
#define GPS_EXEC                "EXEC\r"

#define GPS_LINE_FEED           "\n"
#define GPS_CR                  "\r"

#define MINIMUM_SATELLITE       4

#define FIRST_FIX_TIMEOUT_S     (5L*60L)
#define FIX_VALID_COUNT         60

typedef struct
{
  uint8_t GNSS_UtcTime_h;
  uint8_t GNSS_UtcTime_m;
  uint8_t GNSS_UtcTime_s;
  uint8_t GNSS_UtcTime_ms;
  
  float Latitude_DD;
  float Longitude_DD;
  
  float Latitude_Target_DD;
  float Longitude_Target_DD;
  char Location_Target_DD;
  char DateTime_Target_DD;
  
  float Target_Direction;
  float Target_Distance;
  
  char NoOfSatellites_used;
  
  uint8_t QualityIdx;
  
  int32_t timestamp;
  
}GnssGGA_struct_t;

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
typedef enum
{
  GNSS_OFF = 0,
  GNSS_WAIT_RESET,
  GNSS_SET_OUTSENT,
  GNSS_SET_OPMODE,
  GNSS_SET_SATSYS,
  GNSS_SET_HOTSTART,
  GNSS_FIRSTFIX,
  GNSS_ON,
  GNSS_IDLE,
  GNSS_WAITSLEEP,
  GNSS_SLEEP,
  GNSS_WAITWAKE,
}GNSS_Status_t;

typedef enum
{
  GNSS_FWU_OFF = 0,
  GNSS_FWU_WAIT_RESET,
  GNSS_FWU_FLASH_ERASE,
  GNSS_FWU_WAIT_FER_DONE,
  GNSS_FWU_WAIT_LOAD_BIN1,
  GNSS_FWU_WAIT_LOAD_BIN2,
  GNSS_FWU_WAIT_LOAD_BIN3,
  GNSS_FWU_WAIT_LOAD_BIN4,
  GNSS_FWU_WAIT_REBOOT,
  GNSS_FWU_DONE,
  GNSS_FWU_ERROR
}GNSS_FwUpdateStatus_t;

extern GNSS_Status_t GnssStatus;
extern GNSS_FwUpdateStatus_t GNSS_FwUpdateStatus;
extern bool GnssReqOn;
extern bool GnssReqOff;
extern bool GnssReqWake;
extern bool GnssReqSleep;
extern GnssGGA_struct_t GnssGGA;

/******************************************************************************
 * @brief   WakeUp Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_WakeUp(void);

/******************************************************************************
 * @brief   Sleep Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_Sleep(void);

/******************************************************************************
 * @brief   Handle Gnss.
 *
 * @note    
 ******************************************************************************/
bool GnssHandler (void);
   
/******************************************************************************
 * @brief   Switch off Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_Off(void);

/******************************************************************************
 * @brief   Activate Gnss.
 *
 * @note    
 ******************************************************************************/
void Gnss_On(void);

/******************************************************************************
 * @brief   Gnss. Standby
 *
 * @note    added by YeuShyr 2022 04 15 for saving power in Surface Mode
 ******************************************************************************/
void Gnss_Standby(void);

/******************************************************************************
 * @brief   Update GNSS Chip firmware with not blocking function
 *
 * @note    
 ******************************************************************************/
void GnssFwUpdate_NotBlocking(void);

/******************************************************************************
 * @brief   Update GNSS Chip firmware with blocking function
 *
 * @note    
 ******************************************************************************/
bool GnssFwUpdate_Blocking(void);


#endif // _GNSS_H_