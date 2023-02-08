/*******************************************************************************
 * @file        : L4X9_NVData.h
 * @brief       : This file contains all NonVolatile Data Structure
 *                
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 * 
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _L4X9_NVDATA_H_
#define _L4X9_NVDATA_H_

/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/


/*******************************************************************************
 * @brief   Defines for EEPROM Memory Map
 ******************************************************************************/
#define BLOCKS_2_UPDATE 21
   
// block index ((256 Byte in each block)
#define EE_MFGCAL       0x00
#define EE_DEVREC       0x01
#define EE_USERSET      0x02
#define EE_SCUBASET     0x03
#define EE_TRIMIXSET    0x04    // new in DSX
#define EE_FREESET      0x05    // EE reserved NOT USED
#define EE_FREEREC      0x06    // EE reserved NOT USED
#define EE_FLASHMAP     0x07
// 0x9 to 0xF are reserved, 
   
#define EE_RETA_DATA0   0x20       // to retain 256 Bytes SysTime, RTC Time, Setting Data       
#define EE_RETA_DATA1   0x21       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA2   0x22       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA3   0x23       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA4   0x24       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA5   0x25       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA6   0x26       // to retain 256 Bytes real-time algo Data
#define EE_RETA_DATA7   0x27       // to retain 256 Bytes real-time algo Data

#define EE_RETB_DATA0   0x30       // to retain 256 Bytes SysTime, RTC Time, Setting Data       
#define EE_RETB_DATA1   0x31       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA2   0x32       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA3   0x33       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA4   0x34       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA5   0x35       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA6   0x36       // to retain 256 Bytes real-time algo Data
#define EE_RETB_DATA7   0x37       // to retain 256 Bytes real-time algo Data  

#define EE_RETA0   0x08       // to retain 256 Bytes SysTime, RTC Time, Setting Data       
#define EE_RETA1   0x09       // to retain 256 Bytes real-time algo Data
#define EE_RETA2   0x0A       // to retain 256 Bytes real-time algo Data
#define EE_RETA3   0x0B       // to retain 256 Bytes real-time algo Data
#define EE_RETA4   0x0C       // to retain 256 Bytes real-time algo Data
#define EE_RETA5   0x0D       // to retain 256 Bytes real-time algo Data
#define EE_RETA6   0x0E       // to retain 256 Bytes real-time algo Data
#define EE_RETA7   0x0F       // to retain 256 Bytes real-time algo Data

#define EE_RETB0   0x10       // to retain 256 Bytes SysTime, RTC Time, Setting Data       
#define EE_RETB1   0x11       // to retain 256 Bytes real-time algo Data
#define EE_RETB2   0x12       // to retain 256 Bytes real-time algo Data
#define EE_RETB3   0x13       // to retain 256 Bytes real-time algo Data
#define EE_RETB4   0x14       // to retain 256 Bytes real-time algo Data
#define EE_RETB5   0x15       // to retain 256 Bytes real-time algo Data
#define EE_RETB6   0x16       // to retain 256 Bytes real-time algo Data
#define EE_RETB7   0x17       // to retain 256 Bytes real-time algo Data   
   
// for Delayed Proces RAM to EE Block Saving
#define EE_MFGCAL_bit       (0x00000001<<EE_MFGCAL)
#define EE_DEVREC_bit       (0x00000001<<EE_DEVREC)
#define EE_USERSET_bit      (0x00000001<<EE_USERSET)
#define EE_SCUBASET_bit     (0x00000001<<EE_SCUBASET)
#define EE_TRIMIXSET_bit    (0x00000001<<EE_TRIMIXSET)
#define EE_FLASHMAP_bit     (0x00000001<<EE_FLASHMAP)
   
#define EE_RETA0_bit        (0x00000001<<EE_RETA0)
#define EE_RETA1_bit        (0x00000001<<EE_RETA1)
#define EE_RETA2_bit        (0x00000001<<EE_RETA2)
#define EE_RETA3_bit        (0x00000001<<EE_RETA3)
#define EE_RETA4_bit        (0x00000001<<EE_RETA4)
#define EE_RETA5_bit        (0x00000001<<EE_RETA5)
#define EE_RETA6_bit        (0x00000001<<EE_RETA6)
#define EE_RETA7_bit        (0x00000001<<EE_RETA7)
   
#define EE_RETB0_bit        (0x00000001<<EE_RETB0)
#define EE_RETB1_bit        (0x00000001<<EE_RETB1)
#define EE_RETB2_bit        (0x00000001<<EE_RETB2)
#define EE_RETB3_bit        (0x00000001<<EE_RETB3)
#define EE_RETB4_bit        (0x00000001<<EE_RETB4)
#define EE_RETB5_bit        (0x00000001<<EE_RETB5)
#define EE_RETB6_bit        (0x00000001<<EE_RETB6)
#define EE_RETB7_bit        (0x00000001<<EE_RETB7)   
   
/* Address of EE_Data structure in the external EEPROM */
#define NVD_MFGCAL_LOC1         0x0100*EE_MFGCAL        //Manufactuter calibration "Mfg_Calibration_t" EEPROM Address LOC1
#define NVD_DEVREC_LOC1         0x0100*EE_DEVREC        //Device Parameters "device_parameters_t" EEPROM Address LOC1
#define NVD_USERSET_LOC1        0x0100*EE_USERSET       //User Settings "User_Settings_t" EEPROM Address LOC1
#define NVD_SCUBASET_LOC1       0x0100*EE_SCUBASET      //Scuba Mode Settings "Scuba_Settings_t" EEPROM Address LOC1
#define NVD_TRIMIXSET_LOC1      0x0100*EE_TRIMIXSET     //TRIMIXSET Mode Settings 
#define NVD_FREESET_LOC1        0x0100*EE_FREESET       //Free Mode Settings "Free_Settings_t" EEPROM Address LOC1
#define NVD_FREEREC_LOC1        0x0100*EE_FREEREC       //Free Mode Records "Free_Records_t" EEPROM Address LOC1
#define NVD_FLASHMAP_LOC1       0x0100*EE_FLASHMAP      //FLASH MAP "FLASH_Map_t" EEPROM Address LOC1
   
#define NVD_EE_RETA_DATA0_LOC    0x0100*EE_RETA_DATA0   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA1_LOC    0x0100*EE_RETA_DATA1   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA2_LOC    0x0100*EE_RETA_DATA2   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA3_LOC    0x0100*EE_RETA_DATA3   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA4_LOC    0x0100*EE_RETA_DATA4   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA5_LOC    0x0100*EE_RETA_DATA5   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA6_LOC    0x0100*EE_RETA_DATA6   // Data Retaintion Copy A
#define NVD_EE_RETA_DATA7_LOC    0x0100*EE_RETA_DATA7   // Data Retaintion Copy A
   
#define NVD_EE_RETB_DATA0_LOC    0x0100*EE_RETB_DATA0   // Data Retaintion Copy B
#define NVD_EE_RETB_DATA1_LOC    0x0100*EE_RETB_DATA1   // Data Retaintion Copy B
#define NVD_EE_RETB_DATA2_LOC    0x0100*EE_RETB_DATA2   // Data Retaintion Copy B
#define NVD_EE_RETB_DATA3_LOC    0x0100*EE_RETB_DATA3   // Data Retaintion Copy B   
#define NVD_EE_RETB_DATA4_LOC    0x0100*EE_RETB_DATA4   // Data Retaintion Copy B
#define NVD_EE_RETB_DATA5_LOC    0x0100*EE_RETB_DATA5   // Data Retaintion Copy B   
#define NVD_EE_RETB_DATA6_LOC    0x0100*EE_RETB_DATA6   // Data Retaintion Copy B   
#define NVD_EE_RETB_DATA7_LOC    0x0100*EE_RETB_DATA7   // Data Retaintion Copy B
   
#define NVD_EEPROM_TO_RAM_RETRY 5               //Retries in case or Error while reading EEPROM


#define NVD_PROFILE_START       0x3000          //PROFILE BUFFER START address  = 12288
#define NVD_PROFILE_END         0x3FFF          //PROFILE BUFFER END address    = 16383   
   
/*******************************************************************************
 * @brief   Defines for ExFLASH Memory Map (64M Bytes MT25QL512ABB)
 ******************************************************************************/

#define EXFLASH_BOOTREC         0x00000000      // 256B  0x000100
#define EXFLASH_RESERVED0       0x00000100      // 7.75K 0x001F00
#define EXFLASH_FIRMWARE        0x00002000      // 2M or 0x1FE000
#define EXFLASH_RESERVED1       0x00200000      // 6M 

#define EXFLASH_LOG             0x00800000      // 512K Bytes 0x00080000
#define EXFLASH_LOG_END         0x0087FFFF

#define EXFLASH_PROFILE         0x01000000      // 16M Bytes
#define EXFLASH_PROFILE_END     0x01FFFFFF      // End of 16M Bytes

#define EXFLASH_SLATE           0x11000000      // 2M Bytes 
#define EXFLASH_SLATE_END       0x111FFFFF      // End of 2M Bytes

#define EXFLASH_WELCOME         0x11200000      // 1M Bytes 
#define EXFLASH_WELCOME_END     0x112FFFFF      // End of 1M Bytes

#define EXFLASH_MYINFO          0x11300000      // 128K Bytes
#define EXFLASH_MYINFO_END      0x1131FFFF      // End of 128K Bytes

#define EXFLASH_GPS             0x11320000      // 32K Bytes
#define EXFLASH_GPS_END         0x11327FFF      // End of 32K Bytes

/* Defines for Hardware calibration Structures */
#define MODELCODE_LEN           8
#define SRPREFIX_LEN            8

/* Defines for Mix Structure */
#define OC_MIXES                5
#define CC_MIXES                2
#define MIN_PPO2       		700
#define MAX_PPO2       		1600


#define NVD_PAGE_FIRST_LOG      0x10;
#define NVD_PAGE_LAST_LOG       0x10;
#define NVD_ADDR_LAST_IDX       EXFLASH_SCUBAIDX
#define NVD_ADDR_NEXT_IDX       EXFLASH_SCUBAIDX
#define NVD_ADDR_LAST_PRF       EXFLASH_PROFILE
#define NVD_ADDR_NEXT_PRF       EXFLASH_PROFILE

#define START_DIVE_DEPTH_FT     5
#define END_DIVE_DEPTH_FT       3

#define N2COMPNUM               16   

#define BLOCK_SIZE              256
#define SECTOR_SIZE             4096
#define LOG_SIZE                512     // 16 x 32 rows (defined in Excel Sheet)
#define PROFILE_SIZE            32      // 16 x 2 rows (defined in Excel Sheet)
#define PROFILE_HEADER_SIZE     256     // 16 x 16 rows (defined in Excel Sheet)
#define PROFILE_TRAILER_SIZE    64      // 16 x 4 rows (defined in Excel Sheet)
#define PROFILE_CHART_SIZE      200     // size of Frodile Chart Data Buffer
   
#define LOG_NUM_PER_SECTOR      SECTOR_SIZE/LOG_SIZE   
    
#define  PROFILE_HEADER         0
#define  PROFILE_DATA           1
#define  PROFILE_TRAILER        2
#define  PROFILE_HEADER_UPDATE  3

#define INFO_DATA_SIZE          32
   
//#define INDEX_TABLE_SIZE        4096
#define INDEX_PER_DIVE_SIZE       2       // DIVE-In 4 + Exit 4
#define INDEX_NUM_PER_SECTOR    SECTOR_SIZE/(INDEX_PER_DIVE_SIZE*8)

#define PLAN_INDEX      Plan_DEPTH_NDT_OTR_PO2[0][0]    // current PLAN_INDEX
#define PLAN_INDEX_LO   Plan_DEPTH_NDT_OTR_PO2[0][1]    // PLAN_INDEX = always 2
#define PLAN_INDEX_HI   Plan_DEPTH_NDT_OTR_PO2[0][2]    // PLAN_INDEX highest value according to FO2
#define PLAN_INDEX_MAX  Plan_DEPTH_NDT_OTR_PO2[0][3]    // PLAN_INDEX capped by PO2max 

#define AfterDiveGapID_Max              12      // for the Max number of the Gaps between re-entry of the same dive

#define MFG_CALIB_YY    MFG_Calib.Date.Year
#define MFG_CALIB_MM    MFG_Calib.Date.Month
#define MFG_CALIB_DD    MFG_Calib.Date.Day
   
#define GPS_LOCATION_Num        USER_Set.WayFinderLocNum // The number of GPS Locations recorded 
#define GPS_ADDR_Idx            GPS_LOCATION_Num - GUI_GPS_WAYFINDER_id  
#define DUMMY   0

//======================= constants for calculation or unit conversion =======================
#define CONST_PSI_TO_BAR        0.06895f         // 1 PSI = 0.0689475729 BAR
#define CONST_PSI_TO_mBAR        68.95f          // 1 PSI = 68.9475729 mBAR
#define CONST_BAR_TO_PSI        14.50377f        // 1 BAR = 14.503773 PSI
#define CONST_mBAR_TO_PSI       0.01450f         // 1 mBAR = 0.01450 PSI
#define CONST_FT_TO_M           0.3048f          // 1 foot = 0.3048 Meter
#define CONST_M_TO_FT           3.2808f          // 1 Meter = 3.2808 Feet
#define CONST_CUFT_TO_LITER     28.317f          // 1 Cubic Feet = 28.317 Liters
#define CONST_LITER_TO_CUFT     0.0353f          // 1 Liter = 0.0353 Cubic Feet
//======================= constants for calculation or unit conversion =======================
#define ALARM_ENDPRESS_PSI      (300u)          //End Pressure Value Imperial
#define ALARM_ENDPRESS_BAR      (20u)           //End Pressure Value Metric
typedef enum 
{
  NVD_OFF = 0x00,
  NVD_ON =  0x01,
  NVD_SET = 0x02
}NVD_status_t;

typedef enum 
{
  NVD_NO = 0x00,
  NVD_YES =  0x01
}NVD_YesNo_t;

typedef enum 
{
  TANK_OFF = 0x00,
  TANK_1   = 0x01,
  TANK_2   = 0x02,
  TANK_3   = 0x03,
  TANK_4   = 0x04,
  TANK_5   = 0x05,
  TANK_6   = 0x06
}TANK_NUM_t;

typedef enum 
{
  TMT_OFF = 0x00,
  TMT_1   = 0x01,
  TMT_2   = 0x02,
  TMT_3   = 0x03,
  TMT_4   = 0x04,
  TMT_5   = 0x05,
  TMT_6   = 0x06
}TMT_NUM_t;

typedef enum 
{
  TMT_NOT_AVAILABLE = 0x00,
  TMT_SEARCHING     = 0x01,
  TMT_BATT_LOW      = 0x02,
  TMT_BATT_GOOD     = 0x03
}TMT_Connection_t;

typedef enum 
{
  NVD_OFF_CONSERV = 0x00,
  NVD_MORE_CONSERV = 0x01,
  NVD_MOST_CONSERV = 0x02
}NVD_conserv_t;

typedef struct 
{  
  uint8_t  Day;         // DD in HEX
  uint8_t  Month;       // MM in HEX  
  uint8_t Year;         // 20XX, XX in HEX
  uint8_t Resv;         // reserved
}NVD_date_t;


typedef struct
{
  uint32_t  SerialNum  :24;
  uint32_t  KeyToDive  :8;
}Serial_32Byte;


typedef struct
{
    uint8_t Reg_KEY;    // Device Register ENABLED key
    uint8_t Reg_DD;     // Device Register completed year
    uint8_t Reg_MM;     // Device Register completed month
    uint8_t Reg_YY;     // Device Register completed day
}DeviceRegister_t;

/************************** Hardware Calibration Data *************************/

/* Hardware Calibration Data */
// EEPROM Data structure: set at Manufacturer Calibrations and Initializations: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct          
{   
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  NVD_date_t Date;              /* 4-Byte: DD, MM, YY, Resv */
  uint8_t PartNumber[6];        /* 6-Byte Model Code, alpha-numeric format */  
  uint8_t Prefix[2];            /* 2-Byte prefix, saved as ascii format */  
  Serial_32Byte SN;             /* 4-Byte, 123456 saved as ascii 0x56, 0x34, 0x12 */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------
  uint16_t BattWarning_mV;      /* 2-Byte Battery Warning voltage expressed in 3700 mV (3.70 Volt) */
  uint16_t BattCutoff_mV;       /* 2-Byte Battery Cutoff voltage expressed in 3650 mV (3.65 Volt)*/
  int16_t LF_Crystal_Cal;       /* 2-Byte LF 32K Hz Crystal calibration value (-32768 to 32767) */
  uint8_t LF_Crystal_Sign;      /* 1-Byte LF 32K Crystal calibration value Sign 0:(+)  1:(-)*/
  int8_t CalibrationTempF;      /* 1-Byte Calibration Temperature in F, 0 F to 122 F*/
  uint16_t TemperatureCount;    /* 2-Byte Temperature Counting for Calibration */  
  uint16_t Reserved1A;          /* 2-Byte ID for System Data Clear or Re-Initialization */  
  uint16_t Reserved1C;          /* 2-Byte ID for System Data Clear or Re-Initialization */  
  uint16_t ClearID;             /* 2-Byte Abort Code Clear A */   //? move to Device_Records_t?

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------
 
  uint16_t TankOffset;          /* 2-Byte Tank Offset */
  uint16_t TankGain1;           /* 2-Byte Tank Count per PSI 1st session*/
  uint16_t TankCount1;          /* 2-Byte Tank Count Offset 1st session */
  uint16_t TankGain2;           /* 2-Byte Tank Count per PSI 2st session*/
  uint16_t TankCount2;          /* 2-Byte Tank Count Offset 2st session */
  uint16_t TankGain3;           /* 2-Byte Tank Count per PSI 3st session*/
  uint16_t TankCount3;          /* 2-Byte Tank Count Offset 3st session */
  uint8_t  Reserved6;           /* 1-Byte Reserved */
  uint8_t  CKSU7;               /* 1-Byte CKSU7 */

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------
  int32_t LP_Sensor_Offset_ubarx10;    /* 4-Byte Low Pressure Sensor Offset expressed in ubar x 10 */
  int32_t Temp_Sensor_Offset_mCx10;     /* 4-Byte Temperature Sensor Offset expressed in centiCelsius (°mCx10)*/
  uint16_t Reserved38;                  /* 2-Byte Reserved */
  uint16_t Reserved3A;                  /* 2-Byte Reserved */
  uint16_t TankCntPerDeg;               /* 2-Byte Tank Count per PSI 4st session*/
  uint8_t TankGainSign;                 /* 1-Byte Tank Gain Sign or slope */
  uint8_t PassCodeEnable;               /* 1-Byte If this has value 0xEA then PassCOde on BLE is required */
  //-------------------------------------------------------------------------------------------------------
    
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------
  uint8_t MacId[16];                    /* Device MAC ID */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x50 to 0x63
  //-------------------------------------------------------------------------------------------------------
  PCMD_O2ANALYZER_RESP O2_Analyzer;
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x64 to 0xAF
  //-------------------------------------------------------------------------------------------------------
  uint8_t Reserved64[0x50-4];         // to make the whole structure size 16*n in the future
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xB0 to 0xBF
  //-------------------------------------------------------------------------------------------------------
  float ALS_Dark_Lux;           /* 4-Byte float for ALS Dark Level Lux threshold value */
  float ALS_Low_Lux;            /* 4-Byte float for ALS Low Level Lux threshold value */
  float ALS_Med_Lux;            /* 4-Byte float for ALS Med Level Lux threshold value */
  uint8_t Dark_BackLight;       /* 1-Byte uint8 for ALS Dark Level's Brightness value */
  uint8_t Low_BackLight;        /* 1-Byte uint8 for ALS Low Level's Brightness value */
  uint8_t Med_BackLight;        /* 1-Byte uint8 for ALS Med Level's Brightness value */
  uint8_t Bright_BackLight;     /* 1-Byte uint8 for ALS Bright Level's Brightness value */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xC0 to 0xFF
  //-------------------------------------------------------------------------------------------------------  
  uint8_t reserved[0x30 + 12];          // to make the whole structure size 16*n in the future  
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} Mfg_Calibration_t; // only be modified by MFG


/**************************** Device Parameters Data **************************/
/* Device Parameters Data */
//EEPROM Data structure: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct          
{ 
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  uint32_t FW_Ver;                      /* 4-Byte Firmware Version */ 
  uint32_t OldFW_Ver;                   /* 4-Byte Old Firmware Version */ 
  uint32_t FW_Addr;                     /* 4-Byte Firmware Address on ExFLASH */ 
  uint16_t Reserved0C;                  /* 2-Byte Reserved */
  uint8_t Reserved0E;                   /* 1-Byte Reserved */ 
  uint8_t RetainIndex;                  /* 1-Byte Retention Index A or B (0 or 1) */ 
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------
  SystemTimeDate_t FW_PST;        /* 8-Byte Firmware Upgrade PST Date and Time */  
  SystemTimeDate_t RTC_PST;        /* 8-Byte PST System time; this is copy of SysTimeDate that ready to be saved to EEPROM */

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------
  int32_t MonoClockSec;         /* 4-Byte Is the system MonotonicClock expressed in seconds */  
  uint16_t DiveNumOfDay;        /* 2-Byte Dive Number of the NEWDAY */  
  uint16_t LogNumRecorded;      /* 2-Byte Total LOG Number can be saved in Device (a constant) */ 
  uint16_t LogNumLast;          /* 2-Byte Total Number of LOG already saved */ 
  uint16_t LogNumDisp;          /* 2-Byte Current Number of LOG */ 
  int16_t  DevLowestTempF10;    /* 2-Byte Lowest reached device temperature in °F in whole product life */
  int16_t  DevHighestTempF10;   /* 2-Byte Highest reached device temperature in °F in whole product life */  
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t DevMaxDepthFt10;     /* 2-Byte Maximum reached depth in whole product life in Meter */
  uint16_t DevMaxDepthM10;      /* 2-Byte Maximum reached depth in whole product life in Feet */
  uint16_t DevAvgDepthFt;      /* 2-Byte Maximum reached depth in whole product life in Meter */
  uint16_t DevAvgDepthM;       /* 2-Byte Maximum reached depth in whole product life in Feet */
  uint8_t  Max_Elev;            /* 1-Byte Maximum Elevation Lavel recorded in whole product life in Level */
  uint8_t  Min_Elev;            /* 1-Byte Minimum Elevation Lavel recorded in whole product life in Level */
  uint16_t Reserved3A;          /* 2-Byte Maximum reached depth in whole product life in Feet */
  uint16_t DevMaxPressurePSI;   /* 2-Byte Maximum Pressure exposure in mbar in whole product life */
  uint16_t DevMaxPressureMbar10;/* 2-Byte Maximum Pressure exposure in PSI in whole product life */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t TotalHours;          /* 2-Byte Total Device Running Hours */  
  uint8_t TotalMins;            /* 1-Byte Total Device Running Minutes */  
  uint8_t TotalSecs;            /* 1-Byte Total Device Running Seconds */  
  uint32_t TotalDiveTimeSec;    /* 4-Byte Total dive time in seconds in whole product life */
  uint16_t MaxDiveTimeSec;      /* 2-Byte Maximum Dive Time in second among all previous dives */
  uint16_t LogNormNumRecorded;  /* 2-Byte Log Scuba Num Recorded */ 
  uint16_t LogGaugeNumRecorded; /* 2-Byte Log Gauge Num Recorded */ 
  uint16_t LogFreeNumRecorded;  /* 2-Byte Log Free Num Recorded */ 
   
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------  
  uint32_t AddrNewProfileHead;  /* 4-Byte Address of New Profile Header */
  uint32_t AddrNewProfileEnd;   /* 4-Byte Address of New Profile Trailer */
  uint32_t AddrLastProfile;     /* 4-Byte Address of Last Profile Trailer */
  uint32_t AddrNextProfile;     /* 4-Byte Address of Next Profile Header */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t RXCtrl;               /* 1-Byte TMT RX Selection */
  uint8_t GXCtrl;               /* 1-Byte Gas Tank Selection */
  uint16_t DevTotalDiveNum;     /* 2-Byte Total Dive Number */
  uint16_t Reserved64;          /* 2-Byte Reserved */
  uint16_t Reserved66;          /* 2-Byte Reserved */
  uint16_t FreeDiveNumOfDay;    /* 2-Byte Dive Number of the NEWDAY */  
  uint16_t FreeLogNumRecorded;  /* 2-Byte Total LOG Number can be saved in Device (a constant) */ 
  uint16_t FreeLogNumLast;      /* 2-Byte Total Number of LOG already saved */ 
  uint16_t FreeLogNumDisp;      /* 2-Byte Current Number of LOG */ 

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------  
  L4X9_SystemWarnings_t SystemErrorWarningBits;      /* 4-Byte Reserved */ 
  uint16_t BATT_mV;                     /* 2-Byte Reserved */
  uint8_t DivingOngoing;                /* if 1 we are diving, used to catch underwater reset */
  uint8_t LockForGaugeDive;             /* 0: No Lock Dive Mode;  1: Lock Dive Mode (GSM or Gauge) until New Day (return to 0) 2. Lock for Violation (CC, OC, BO -> Lock at Gauge;  SM -> GSM)*/
  uint32_t Reserved78;                  /* 4-Byte Reserved */
  uint16_t MaxAltitudeFt;               /* 2-Byte Max Altitude Feet */ 
  uint16_t MaxAltitudeM;                /* 2-Byte Max Altitude Meter */

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x80 to 0x8F
  //-------------------------------------------------------------------------------------------------------  
  MAX17262_Learned_t MAX17262_BatteryLearned;   /* 12-Byte Data Structure for Fuel Gauge */
    
  uint32_t Reserved8C;                  /* 4-Byte Reserved */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x90 to 0xCF
  //-------------------------------------------------------------------------------------------------------  
  MMC_Output_t  CompassCali;            /* 54-Byte Data Structure for Compass Calibration */

  uint16_t ReservedC6;                  /* 2-Byte Reserved */
  uint32_t ReservedC8;                  /* 4-Byte Reserved */
  uint32_t ReservedCC;                  /* 4-Byte Reserved */

  //-------------------------------------------------------------------------------------------------------
  // Byte 0xD0 to 0xDF
  //------------------------------------------------------------------------------------------------------- 
  uint32_t ReservedD0;                  /* 4-Byte Reserved */
  uint32_t ReservedD4;                  /* 4-Byte Reserved */
  uint32_t ReservedD8;                  /* 4-Byte Reserved */
  uint32_t ReservedDC;                  /* 4-Byte Reserved */  

  //-------------------------------------------------------------------------------------------------------
  // Byte 0xE0 to 0xEF
  //------------------------------------------------------------------------------------------------------- 
  DeviceRegister_t Reg;                 /* 4-Byte Reserved */
  uint32_t ReservedE4;                  /* 4-Byte Reserved */
  uint32_t ReservedE8;                  /* 4-Byte Reserved */
  uint32_t ReservedEC;                  /* 4-Byte Reserved */  
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xF0 to 0xFF
  //------------------------------------------------------------------------------------------------------- 
  float O2_Analyzer_V2Pct_Slope;        /* 4-Byte O2 Analyzer V-to-Pct curve-fitting Slope */
  float O2_Analyzer_V2Pct_Offset;       /* 4-Byte O2 Analyzer V-to-Pct curve-fitting Offset */
  
  uint32_t ReservedF8;                  /* 4-Byte Reserved */
  uint8_t FLASH_ErrCnt;                 /* 1-Byte FLASH Error Cnt */
  uint8_t EE_ErrCnt;                    /* 1-Byte FLASH Error Cnt */
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
 
} Device_Records_t; // only be modified by device mesaured or calculated value, NOT by users


/*************************** General System Settings **************************/

typedef enum 
{
  NVD_12HR = 0x00,
  NVD_24HR = 0x01
}NVD_timeformat_t;

typedef enum 
{
  NVD_MD = 0x00,
  NVD_DM = 0x01
}NVD_dateformat_t;

typedef enum 
{
  NVD_UTC = 0x00,
  NVD_PST = 0x01,
  NVD_HOME = 0x02,
  NVD_AWAY = 0x03
}NVD_HA_t;

typedef enum 
{
  NVD_IMPERIAL = 0x00,
  NVD_METRIC = 0x01
}NVD_UNITS_t;

typedef enum 
{
  NVD_SALT = 0x00,
  NVD_EN13319 = 0x01,
  NVD_FRESH = 0x02,
  NVD_WATERAUTO = 0x03,
  NVD_MAX
}NVD_WATER_t;

typedef enum 
{
  NVD_AUTO = 0x00,
  NVD_MANUAL = 0x01,
}NVD_BKLMD_t;

typedef enum 
{
  NVD_6CLK = 0x00,
  NVD_12CLK = 0x01,
}NVD_DISPOR_t;

typedef enum 
{
  NVD_EAST = 0x00,
  NVD_WEST = 0x01,
}NVD_CMPDIR_t;

typedef enum 
{
  NVD_2SEC = 2,
  NVD_15SEC = 15,
  NVD_30SEC = 30,
  NVD_60SEC = 60,
}NVD_SAMPLETIME_t;

typedef enum 
{
  NVD_MDCC      = 0x00,
  NVD_MDOC      = 0x01,
  NVD_MDSM      = 0x02,
  NVD_MDGSM     = 0x03,
  NVD_MDGAUGE   = 0x04,
  NVD_MDBO      = 0x05,
  NVD_MDSCUBA   = 0x06,
  NVD_MDFREE    = 0x07,
  NVD_MDMAX,
}NVD_DIVEMODE_t;

typedef struct
{  
    uint8_t LongtitudeSign: 4;
    uint8_t LatitudeSign: 4;
    uint8_t LongtitudeDeg;      // (0 - 180)
    uint8_t LongtitudeMin;      // (0 -  59)
    uint8_t LongtitudeSec;      // (0 -  59)
    uint8_t LongtitudeSecDec;   // (0 -  59) decimal part 0.xx
    uint8_t LatitudeDeg;        // (0 - 180)
    uint8_t LatitudeMin;        // (0 -  59)
    uint8_t LatitudeSec;        // (0 -  59)
    uint8_t LatitudeSecDec;     // (0 -  59) decimal part 0.xx									
} GPS_Coordinations_t;

typedef enum {
    Algo_0,
    Algo_1,
    Algo_2,
    Algo_3,
    Algo_4,
    Algo_5,
    Algo_6,
    MAX_Algo
} AlgorithmSelect_t;

typedef enum {
    Select_ENGLISH = 0,
    Select_GERMAN,		
    Select_FRENCH,
    Select_ITALIAN,
    Select_ESPANOL,
    Select_PORTUGESE,
    Select_POLISH, 
    Select_RUSSIAN,  
    Select_CZECH,
    Select_CHINESE_S,   //Simplified Chinese
    Select_CHINESE_T,   //Traditional Chinese
    Select_KOREAN, 
    MAX_LANGUAGE
} LanguageSelect_t;

typedef enum {

    //----- [10 beeps]--------------------
    ALARM_CondiVio = 0,         // 0
    ALARM_DelayedVio1,
    ALARM_DelayedVio2,
    ALARM_DepthMax,
    ALARM_AscRate5,
    ALARM_PO2_Lo,
    ALARM_PO2_Hi,
    ALARM_DepthSet,
    
    ALARM_DiveN2Bar,            // 8
    ALARM_O2_80Pct,
    ALARM_O2_100Pct,
    ALARM_DECO_Entry,
    ALARM_DiveTime,
    ALARM_DiveDTR,
    //----- [3 short beeps]----------------
    ALARM_AscRate4,
    ALARM_FreeDiveT,            // NOT used in DSX 
    //----- [3 short beeps x 3 times]------
    ALARM_FreeDepth1,           // NOT used in DSX 
    ALARM_FreeDepth2,           // NOT used in DSX 
    ALARM_FreeDepth3,           // NOT used in DSX 
    ALARM_FreeN2Bar,            // NOT used in DSX 
    ALARM_FreeCDT,              // NOT used in DSX 
    ALARM_FreeViol,             // NOT used in DSX 
    //----- [10 beeps]--------------------
    ALARM_DECO_Depth70,    
    ALARM_SwitchFO2,    

    ALARM_SetupVIOLATION,       // 24
    ALARM_DECO_Warning,
    ALARM_DECO_Alarm,
    ALARM_GFBG_Alarm,
    ALARM_Reserved28,
    ALARM_NoOpShutdown,
    ALARM_LowBatteryWarning,
    ALARM_LowBatteryAlarm,
    
    //--- ALARM2    
    //------------------------------- [1 beep per sec for 10 sec]---------------------------------
    ALARM_SP_AutoHi,            // 32
    ALARM_SP_AutoLo,
    ALARM_TEC_GF_Hi,
    ALARM_TEC_GF_Lo,
    ALARM_TTS_T,
    ALARM_TankP,
    ALARM_CC6P,
    ALARM_TurnP,
    
    ALARM_EndP,                 // 40
    ALARM_SwitchP,
    ALARM_GF, 
    ALARM_N2,
    ALARM_End, 
    ALARM_WOB, 
    ALARM_ICD,
    ALARM_Narcotic,
    
    ALARM_GTR5,                 // 48
    ALARM_GTR0,
    ALARM_LostLink, 
    ALARM_OCSM_MinPO2,
    ALARM_OCSM_MaxPO2,
    ALARM_OCSM_DecoPO2,
    ALARM_TMT_LowBatt,
    ALARM_Reserved55,
    
    ALARM_Reserved56,           // 56
    ALARM_Reserved57,
    ALARM_Reserved58,
    ALARM_Reserved59,
    ALARM_MemoryERR,
    ALARM_SystemERR,
    ALARM_TMT_LowBattWarning,
    ALARM_TMT_LowBattAlarm,
    
    ALARM_MAX,                  // 64 as total Alarm Flags
} ALARM_ID_t;

typedef struct   
{
    //------------------------------- [1 beep per sec for 10 sec]---------------------------------
    uint32_t      CondiVio        :1;     // 1-bit      [1 beep per sec for 10 sec] Conditional Violation
    uint32_t      DelayedVio1     :1;     // 1-bit      [1 beep per sec for 10 sec] Delayed Violation 1      // must be Saved to EEPROM
    uint32_t      DelayedVio2     :1;     // 1-bit      [1 beep per sec for 10 sec] Delayed Violation 2  
    uint32_t      DepthMax        :1;     // 1-bit      [1 beep per sec for 10 sec] Depth Out of Range 
    uint32_t      AscRate5        :1;     // 1-bit      [1 beep per sec for 10 sec] Ascent Rate (alarm) too fast - 5 segments    
    uint32_t      PO2_Lo          :1;     // 1-bit      [1 beep per sec for 10 sec] PO2_Lo
    uint32_t      PO2_Hi          :1;     // 1-bit      [1 beep per sec for 10 sec] PO2 > Alarm Set Point 
    uint32_t      DepthSet        :1;     // 1-bit      [1 beep per sec for 10 sec] Depth Alarm 
    
    uint32_t      DiveN2Bar       :1;     // 1-bit      [1 beep per sec for 10 sec] DIVE N2 (N2BG) Alarm      
    uint32_t      O2_80Pct        :1;     // 1-bit      [1 beep per sec for 10 sec] DIVE O2 at 80%
    uint32_t      O2_100Pct       :1;     // 1-bit      [1 beep per sec for 10 sec] DIVE O2 at 100% // must be Saved to EEPROM
    uint32_t      DECO_Entry      :1;     // 1-bit      [1 beep per sec for 10 sec] Entry into Deco
    uint32_t      DiveTime        :1;     // 1-bit      [1 beep per sec for 10 sec] Dive Time EDT Alarm     
    uint32_t      DiveDTR         :1;     // 1-bit      [1 beep per sec for 10 sec] DIVE DTR Alarm          // works with SCUBA_Set.DTR_Alarm
  
    //------------------------------- [3 short beeps]---------------------------------
    uint32_t      AscRate4        :1;     // 1-bit      [3 short beeps for once] DIVE/GAUGE Ascent Rate (warning) - 4 segments [3 short beeps]
    uint32_t      FreeDiveT       :1;     // 1-bit      NOT used in DSX [3 short beeps for once] FREE EDT Alarm
    uint32_t      FreeDepth1      :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] FREE Depth Alarms 1  
    uint32_t      FreeDepth2      :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] FREE Depth Alarms 2  
    uint32_t      FreeDepth3      :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] FREE Depth Alarms 3
    uint32_t      FreeN2Bar       :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] Free N2 (N2BG) Alarm 
    uint32_t      FreeCDT         :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] Free CDT Alarm 
    uint32_t      FreeViol        :1;     // 1-bit      NOT used in DSX [3 short beeps for 3 times] FREE Violation VGM
    
    //------------------------------- [1 beep per sec for 10 sec]---------------------------------
    uint32_t      DECO_Depth70    :1;     // 1-bit      [1 beep per sec for 10 sec] Deco Stop Depth Violation > 70 FT (21 M) required
    uint32_t      SwitchFO2       :1;     // 1-bit      [1 beep per sec for 10 sec] SwitchFO2 0: 1:
    
    uint32_t      SetupVIOLATION  :1;     // 1-bit      Confirm Immediate Violation or Delayed Violation 0: 1:
    uint32_t      DECO_Warning    :1;     // 1-bit      [1 beep per sec for 10 sec] Warning if within 1 min above Deco Stop
    uint32_t      DECO_Alarm      :1;     // 1-bit      [1 beep per sec for 10 sec] Alarm if over 1 min above Deco Stop
    uint32_t      GFBG_Alarm      :1;     // 1-bit      [1 beep per sec for 10 sec] GFBG above threshold
    uint32_t      Reserved28      :1;     // 1-bit reserved 0: 1:
    
    uint32_t      NoOpShutdown    :1;     // 1-bit       Battery Volt < 3.65V CUTOFF_mVOLT    
    uint32_t      LowBattWarning  :1;     // 1-bit       Battery Volt < 3.70V BattWarning_mV
    uint32_t      LowBattAlarm    :1;     // 1-bit       Battery Volt < 3.66V BattCutoff_mV

}AlarmUnion;     // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control

union AlarmUNION
{
    AlarmUnion    Bit;
    uint32_t      AllBits;              // Combination of all above
};

typedef struct   
{
    //------------------------------- [1 beep per sec for 10 sec]---------------------------------
    uint32_t      SP_AutoHi     :1;     // 1-bit SP_AutoHi 0: 1:
    uint32_t      SP_AutoLo     :1;     // 1-bit SP_AutoLo 0: 1:
    uint32_t      TEC_GF_Hi     :1;     // 1-bit TEC_GF_Hi 0: 1:
    uint32_t      TEC_GF_Lo     :1;     // 1-bit TEC_GF_Lo 0: 1:
    uint32_t      TTS_T         :1;     // 1-bit TTS_T 0: 1:
    uint32_t      TankP         :1;     // 1-bit TankPressure 0: 1:
    uint32_t      CC6P          :1;     // 1-bit CC6 Tank Pressure 0: 1:
    uint32_t      TurnP         :1;     // 1-bit Turn Pressure 0: 1:
    
    uint32_t      EndP          :1;     // 1-bit End Pressure 0: 1:
    uint32_t      SwitchP       :1;     // 1-bit Switch Pressure 0: 1:
    uint32_t      GF            :1;     // 1-bit GF Gradient Factor 0: 1:
    uint32_t      N2            :1;     // 1-bit Nitrogen 0: 1:
    uint32_t      End           :1;     // 1-bit Equivalent Nitrox D 0: 1:
    uint32_t      WOB           :1;     // 1-bit WOB 0: 1:  
    uint32_t      ICD           :1;     // 1-bit ICD 0: 1:
    uint32_t      Narcotic      :1;     // 1-bit Narcotic 0: 1:
    
    uint32_t      GTR5          :1;     // 1-bit GTR5 0: 1:
    uint32_t      GTR0          :1;     // 1-bit GTR0 0: 1:
    uint32_t      LostLink      :1;     // 1-bit LostLink 0: 1:
    uint32_t      OCSM_MinPO2   :1;     // 1-bit OCSM_MinPO2 0: 1:
    uint32_t      OCSM_MaxPO2   :1;     // 1-bit OCSM_MaxPO2 0: 1:
    uint32_t      OCSM_DecoPO2  :1;     // 1-bit OCSM_DecoPO2 0: 1:    
    uint32_t      Reserved22    :1;     // 1-bit reserved 0: 1:
    uint32_t      Reserved23    :1;     // 1-bit reserved 0: 1:
    
    uint32_t      Reserved24    :1;     // 1-bit reserved 0: 1:
    uint32_t      Reserved25    :1;     // 1-bit reserved 0: 1:
    uint32_t      Reserved26    :1;     // 1-bit reserved 0: 1:
    uint32_t      Reserved27    :1;     // 1-bit reserved 0: 1:
    uint32_t      MemoryERR     :1;     // 1-bit EEPROM or ExFLASH Memory Error 0: No Memory Error 1: Memory Error
    uint32_t      SystemERR     :1;           // 1-bit       System Error EER1 to EERn alarming flagged by if(SystemStatus.ShowDiag == true)
    uint32_t      TMT_LowBattWarning  :1;     // 1-bit       TMT Low Battery Volt               2.5 V <= TMT Battery Battery < 2.8 V
    uint32_t      TMT_LowBattAlarm    :1;     // 1-bit       TMT Critical Low Battery Volt      TMT Battery Battery < 2.5 V

}Alarm2Union;     // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control


union Alarm2UNION
{
    Alarm2Union    Bit;
    uint32_t      AllBits;              // Combination of all above
};

typedef struct 
{
      uint32_t      AlarmAudible    :1;        // 1-bit Alarm Audible Active   0: OFF (not audible)    1: ON: audible, to follow the rest of bit statuses. 
      uint32_t      AlarmVibeOn     :1;        // 1-bit Alarm Vibration Active 0: OFF (not vibrate)    1: ON: vibrate, to follow the rest of bit statuses. 
      uint32_t      AlarmLED        :1;        // 1-bit Alarm LED is Active    0: OFF (no LED)         1: ON: LED, to follow the rest of bit statuses. 
      uint32_t      BluetoothOn     :1;        // 1-bit Bluetooth Switch ON    0: OFF                  1: ON
      uint32_t      ConservativeOn  :1;        // 1-bit Conservative Factor ON 0: OFF                  1: ON
      uint32_t      DeepStopOn      :1;        // 1-bit DeepStop is Active     0: OFF                  1: ON
      uint32_t      WaterContactOn  :1;        // 1-bit WaterContact is Active 0: OFF                  1: ON 
      uint32_t      ClockAlarm      :1;        // 1-bit ClockAlarm is Active   0: OFF                  1: ON
      
      uint32_t      NoFlyAlarm      :1;        // 1-bit NoFlyAlarm is Active   0: OFF                  1: ON 
      uint32_t      Reserved9       :1;        // 1-bit reserved
      uint32_t      PowerSavingOn   :1;        // 1-bit PowerSavingOn          0: OFF                  1: ON for Power Saving
      uint32_t      HomeAway        :1;        // 1-bit HomeTime or AwayTime   0: Home                 1: Away 
      uint32_t      DDMM_Format     :1;        // 1-bit PowerSaving is Active  0: MMDD                 1: DDMM
      uint32_t      HR24_Format     :1;        // 1-bit PowerSaving is Active  0: 12Hr                 1: 24Hr
      uint32_t      Unit            :1;        // 1-bit PowerSaving is Active  0: Imperial             1: Metric
      uint32_t      CDT_Enable      :1;        // 1-bit CDT_Eanbled            0: CDT Disabled (OFF)   1: CDT Enabled (ON)
      
      uint32_t      Reserved16      :1;        // 1-bit reserved
      uint32_t      Reserved17      :1;        // 1-bit reserved
      uint32_t      Reserved18      :1;        // 1-bit reserved
      uint32_t      Reserved19      :1;        // 1-bit reserved
      uint32_t      Reserved20      :1;        // 1-bit reserved
      uint32_t      Reserved21      :1;        // 1-bit reserved
      uint32_t      Reserved22      :1;        // 1-bit reserved
      uint32_t      LCD_Flip        :1;        // 1-bit reserved               0: LCD No Flip          1: LCD Flip

      uint32_t      O2Narcotic      :1;        // 1-bit Narcotic               0: Normal               1: Narcotic
      uint32_t      ICD_Alarm       :1;        // 1-bit reserved               0: OFF                  1: ON
      uint32_t      GTRforLnR       :1;        // 1-bit reserved               0: OFF                  1: ON
      uint32_t      Reserved27      :1;        // 1-bit reserved               0:                      1: 
      uint32_t      Reserved28      :1;        // 1-bit reserved               0:                      1: 
      uint32_t      Reserved29      :1;        // 1-bit reserved               0:                      1: 
      uint32_t      Reserved30      :1;        // 1-bit reserved               0:                      1: 
      uint32_t      Reserved31      :1;        // 1-bit reserved               0:                      1: 
}SwitchUnion;


union SwitchUNION
{
    SwitchUnion   Bit;
    uint32_t      AllBits;              // Combination of all above
};

typedef enum {
    ColorSel_CYAN = 0x00,
    ColorSele_GREEN,
    ColorSel_WHITE,
    ColorSel_ORANGE,
    ColorSel_MAGENTA,
    ColorSel_MAX
} ColorSel_t;

/* General system settings */
#define NVD_SYSSET_SIZE         256
//EEPROM Data structure: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct          
{  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------  
  LanguageSelect_t      LangSelec;      /* 1-Byte Language Selection */      
  ColorSel_t            TitleColor;     /* 1-Byte Title Color Selection */
  uint8_t               Reserved02;     /* 1-Byte Reserved */
  uint8_t               Reserved03;     /* 1-Byte Reserved */
  
  uint8_t       RefTZidx;               /* 1-Byte 8-bit Zoro Reference Point Timezone index respect to PST (can be Pelagic or Greenwitch Time)  */
  NVD_HA_t      HomeAway;               /* 1-Byte "NVD_HOME" home; "NVD_AWAY" away */
    /* Time Zone index for new fashion logic */
  uint8_t       HomeTZidx;              /* 1-Byte 8-bit Home timezone index respect to PST */
  uint8_t       AwayTZidx;              /* 1-Byte 8-bit Away timezone index respect to PST */
    
  /* Time Zone difference to maintain old fashion logic */
  int8_t        HomeTZhrdiff;           /* 1-Byte 8-bit Home timezone hour difference respect to PST */
  int8_t        HomeTZmindiff;          /* 1-Byte 8-bit Home timezone minute difference respect to PST */
  int8_t        AwayTZhrdiff;           /* 1-Byte 8-bit Away timezone hour difference respect to PST */
  int8_t        AwayTZmindiff;          /* 1-Byte 8-bit Away timezone minute difference respect to PST */
 
  uint8_t       PhantomSec;             /* 1-Byte 8-bit Phantom Dive Sec = 5 seconds */
  uint8_t       PTAlarmSec;             /* 1-Byte 8-bit PT?  is this redundant? */
  uint16_t      ChronoCntDwnSec;        /* 2-Byte 16-bit Chrono Count Down Second */
    
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------
  NVD_DIVEMODE_t        DiveMode;       /* 1-Byte 8-bit "NVD_MDOFF" Dive Application not enabled; "NVD_MDSCUBA" ScubaMode; "NVD_MDGAUGE" ScubaMode; "NVD_MDFREE" FreeMode */
  NVD_DIVEMODE_t        ReturnDiveMode; /* 1-Byte 8-bit the Dive Mode setting before entering to Violation Mode Lockup (to return after Violation expires after 24 Hours) */
  NVD_WATER_t           WaterType;      /* 1-Byte 8-bit Water type: "NVD_SALT" Salt; "NVD_FRESH" Fresh; "NVD_EN13319" EN13319; "NVD_WATERAUTO" Altitude Dependant and auto selection */
  uint8_t               Reserved13;     /* 1-Byte 8-bit Reserved */
  NVD_SAMPLETIME_t      SamplingTime;   /* 1-Byte 8-bit 2, 10, 30 or 60 */
  uint8_t               Reserved15;     /* 1-Byte 8-bit Reserved */
  NVD_status_t  BacklightMode;          /* 1-Byte 8-bit "NVD_AUTO"-Auto (switch off after backlight_time_s), "NVD_MANUAL"-Manual */  
  uint8_t       BacklightLevel;         /* 1-Byte 8-bit Backlight level at normal (non-dim) condition */
  NVD_status_t  DimBacklightMode;       /* 1-Byte 8-bit "NVD_AUTO"-Auto (switch off after backlight_time_s), "NVD_MANUAL"-Manual */    
  uint8_t       DimBacklightLevel;      /* 1-Byte 8-bit Dim Backlight Level at dimmed condition */ 
  uint8_t       YellowBacklightLevel;   /* 1-Byte 8-bit Yellow Low Batt Warning Backlight level at normal (non-dim) condition */
  uint8_t       YellowDimBacklightLevel;/* 1-Byte 8-bit Yellow Low Batt Warning Dim Backlight Level at dimmed condition */ 
  union SwitchUNION SwitchSet;          /* 4-Byte Switch Set */  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------  
  /* Compass Settings */
  NVD_CMPDIR_t  CompassDirection;       /* 1-Byte 8-bit Used for direction in compass settings: "NVD_EAST" EAST; "NVD_WEST" WEST */
  uint8_t       COMOD;                  /* 1-Byte 8-bit */
  int16_t       CompassDeclinationDeg;  /* 2-Byte 16-bit Used for decliantion correction in compass settings default 0 in degree */
  uint8_t       COMflag;                /* 1-Byte 8-bit */
  uint8_t       SAC_Rate;               /* 1-Byte 8-bit SAC Rate */
  uint16_t      BacklightOnTimeSec;     /* 2-Byte 16-bit Backlight ON time (used in Auto) in seconds */
  uint16_t      BacklightDimTimeSec;    /* 2-Byte 16-bit Backlight to Dim Wait Time Sec */
  uint8_t       RedBacklightLevel;      /* 1-Byte 8-bit Red Low Batt Warning Backlight level at normal (non-dim) condition */
  uint8_t       RedDimBacklightLevel;   /* 1-Byte 8-bit Red Low Batt Warning Dim Backlight Level at dimmed condition */ 
  uint16_t      Reserved2C;             /* 2-Byte 16-bit Reserved */
  uint8_t       Reserved2E;             /* 1-Byte 8-bit Reserved */
  uint8_t       ScreenSet;              /* 1-Byte 8-bit Reserved */  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------
  /* Power Saving */
  uint16_t AlarmTimeout1;               /* 2-Byte 16-bit alarm timeout in seconds */
  uint16_t AlarmTimeout2;               /* 2-Byte 16-bit alarm timeout in seconds */
  uint32_t AlarmTimeout3;               /* 4-Byte 32-bit alarm timeout in seconds */
  uint16_t SleepTimeoutSec;             /* 2-Byte 16-bit "0" disabled; Dispaly is "ON" in Watch mode, expressed in seconds*/
  uint16_t DeepSleepTimeoutSec;         /* 2-Byte 16-bit "0" disabled; Dispaly is "OFF", expressed in seconds */ 
  
  uint8_t  ClockAlarmHH;                /* 1-Byte 8-bit Alarm for time = HH Hour */
  uint8_t  ClockAlarmMM;                /* 1-Byte 8-bit Alarm for time = MM Minute */
  uint8_t  ClockAlarmSS;                /* 1-Byte 8-bit Alarm for time = SS Second */
  uint8_t  ClockAlarmWD;                /* 1-Byte 8-bit Alarm for time = WD Day of Week */
  
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------
  uint8_t  StartDiveDepthFt;            /* 1-Byte 8-bit The Depth (in feet) to start a Dive or continue the current dive */
  uint8_t  EndDiveDepthFt;              /* 1-Byte 8-bit The Depth (in feet) to end a Dive or to start 10-minute countdown or Surface Time counting */
  uint8_t  StartDiveDepthdM;            /* 1-Byte 8-bit The Depth (in dMeter) to start a Dive or continue the current dive */
  uint8_t  EndDiveDepthdM;              /* 1-Byte 8-bit The Depth (in dMeter) to end a Dive or to start 10-minute countdown or Surface Time counting */

  uint8_t  CC_3RowL;                   /* 1-Byte 8-bit The Surface Main Left  3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, Dl PO2, FO2, (0 t0 9) */
  uint8_t  CC_3RowR;                   /* 1-Byte 8-bit The Surface Main Right 3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, Dl PO2, FO2, (0 t0 9) */
  uint8_t  OC_3RowL;                   /* 1-Byte 8-bit The Surface Main Left  3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8) */
  uint8_t  OC_3RowR;                   /* 1-Byte 8-bit The Surface Main Right 3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8) */
  uint8_t  SM_3RowL;                   /* 1-Byte 8-bit The Surface Main Left  3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8) */
  uint8_t  SM_3RowR;                   /* 1-Byte 8-bit The Surface Main Right 3rd row data to displayh: BLANK, O2 SAT, GF, CEILING, MAX D, AVG D,REAL TIME, GTR, (0 t0 8) */

  uint8_t  GForN2;                      /* 1-Byte 8-bit The GF or N2 BAR (0: GF Bar, 1: N2 Bar) */
  uint8_t  FontSize;                    /* 1-Byte 8-bit The font size */

  uint16_t WayFinderLocNum;             /* 2-Byte Total GPS Location Number */ 
  uint16_t Reserved4E;                  /* 2-Byte 16-bit Reserved */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x50 to 0xFF
  //-------------------------------------------------------------------------------------------------------
  uint8_t  SIM_Mode;                    /* 1-Byte 8-bit SIM Modes, 0: New;  1: Continous; */
  uint8_t  SIM_SP;                      /* 1-Byte 8-bit 0.40- 1.50,  incr.: 0.10, ,  display = data/100*/
  uint16_t  SIM_Time;                   /* 2-Byte 16-bit 5 - 200 min (incr.: 1 min) */
  uint16_t  SIM_DepthFT;                /* 2-Byte 16-bit 10 -  420 FT (3 -  130 M), (incr.: 1 FT, 1 M) */
  uint16_t  SIM_DepthM;                 /* 2-Byte 16-bit 10 -  420 FT (3 -  130 M), (incr.: 1 FT, 1 M) */
  
  uint8_t  SIM_SAC_CuFt;                /* 1-Byte 8-bit 0.40- 1.50 CUFT/MIN, (11 - 42 L/MIN), (incr.: 0.05 CUFT/MIN, 1 L/MIN,  display = data/100  */
  uint8_t  SIM_SAC_Ltr;                 /* 1-Byte 8-bit 0.40- 1.50 CUFT/MIN, (11 - 42 L/MIN), (incr.: 0.05 CUFT/MIN, 1 L/MIN,  display = data/100  */
  uint16_t Reserved5A;                  /* 2-Byte 16-bit Reserved */
  uint16_t Reserved5C;                  /* 2-Byte 16-bit Reserved */
  uint16_t Reserved5E;                  /* 2-Byte 16-bit Reserved */
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------

  uint8_t  SLATE_Idx[16];               /* 1-Byte 8-bit The Index of SLATE assigned by APP mapping to the ExFLASH Locations order */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------

  uint8_t  SLATE_Stat[16];              /* 1-Byte 8-bit The Location of SLATE assigned by mapped with APP */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x80 to 0xBF
  //-------------------------------------------------------------------------------------------------------

  uint32_t  SLATE_Data[16];             /* 4-Byte 32-bit The Data (SS,DD,MM,YY) associated with the SLATE assigned by mapped with APP, Date DD/MM/YY and spare SS for future use */
 
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xC0 to 0xCF
  //-------------------------------------------------------------------------------------------------------

  uint8_t  Welcome_Idx[3];              /* 1-Byte 8-bit The Index of Welcome Pages assigned by APP mapping to the ExFLASH Locations order, index 1 to 7 */
  uint8_t  ReservedC3[4];               /* 1-Byte 8-bit Reserved */
  uint8_t  CurrWelcome_Idx;             /* 1-Byte 8-bit The Index of Currenly Selected Welcome Pages Index to Welcome_Idx[7] */

  uint8_t  MyInfo_Idx;                  /* 1-Byte 8-bit The Index of My Info location Index */
  uint8_t  ReservedC9[7];               /* 1-Byte 8-bit Reserved */
  
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xD0 to 0xDF
  //-------------------------------------------------------------------------------------------------------

  uint8_t  Welcome_Stat[3];             /* 1-Byte 8-bit The Index of Welcome Pages assigned by APP mapping to the ExFLASH Locations order, index 1 to 7 */
  uint8_t  ReservedD3[5];               /* 1-Byte 8-bit Reserved */
  
  uint8_t  MyInfo_Stat;                 /* 1-Byte 8-bit The Index of My Info location Stat */
  uint8_t  ReservedD9[7];               /* 1-Byte 8-bit Reserved */
 
  //-------------------------------------------------------------------------------------------------------
  // Byte 0xE0 to 0xFF
  //-------------------------------------------------------------------------------------------------------

  uint8_t reserved[252 - 0xE0];
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} User_Settings_t; // can be modified by user settings (user's preference about the device)



/***************************** Scuba Mode Settings ****************************/

typedef enum 
{
  NVD_DVS_MIXDISABLED = 0x00,
  NVD_DVS_MIXENABLED = 0x01,
  NVD_DVS_MIXACTIVE = 0x02
}NVD_DVS_MIXSTATUS_t;

typedef enum 
{
  NVD_DVS_DSAT = 0x00,
  NVD_DVS_PZ = 0x01,
  NVD_DVS_BUL16C = 0x02
}NVD_DVS_DECO_ALGORITHM_t;

typedef enum 
{
  NVD_DVS_NF_REALTIME = 0x00,
  NVD_DVS_NF_DAN = 0x01,
}NVD_DVS_NOFLY_ALGORITHM_t;

typedef enum 
{
  NVD_DVS_DS_REALTIME = 0x00,
  NVD_DVS_DS_DAN = 0x01,
}NVD_DVS_DESAT_ALGORITHM_t;

typedef enum 
{
  NVD_DVS_AA_INSTANTCEIL = 0x00,
}NVD_DVS_AA_ALGORITHM_t;

typedef enum 
{
  NVD_DVS_SS_OFF = 0x00,
  NVD_DVS_SS_ON = 0x01,
  NVD_DVS_SS_SET = 0x02,
}NVD_DVS_SSMODE_t;


typedef enum 
{
  NVD_DVS_DPSTP_DISABLED = 0x00,
  NVD_DVS_DPSTP_HPRESSURE = 0x01,
  NVD_DVS_DPSTP_HDEPTH = 0x02,
  NVD_DVS_DPSTP_DAN = 0x03,
  NVD_DVS_DPSTP_PYLE = 0x04  
}NVD_DVS_DEEPSTP_ALGORITHM_t;

typedef enum 
{
  NVD_DVS_SPMODE_MANUAL = 0x00,
  NVD_DVS_SPMODE_AUTO = 0x01,
}NVD_DVS_SETPOINT_MGMODE_t;

/* Mixes for each mix_table struct.*/
typedef struct 
{
  NVD_DVS_MIXSTATUS_t status;   /* "NVD_DVS_MIXDISABLED"-Disabled; "NVD_DVS_MIXENABLED"-Enabled; "NVD_DVS_MIXACTIVE"-Active;*/
  int8_t N2_percent;
  int8_t He_percent;
  uint16_t PpO2_mb;
} mix_t;

typedef struct
{
  mix_t mix[OC_MIXES];
} mix_table_t;

/* Diluent for each dil_table struct.*/
typedef struct 
{
  NVD_DVS_MIXSTATUS_t status;   /* "NVD_DVS_MIXDISABLED"-Disabled; "NVD_DVS_MIXENABLED"-Enabled; "NVD_DVS_MIXACTIVE"-Active;*/
  int8_t N2_percent;
  int8_t He_percent;
} dil_t;

typedef struct
{
  dil_t dil[CC_MIXES];
} dil_table_t;


typedef enum 
{
  CONSV_TEC   = 0x00,
  CONSV_SPORT = 0x04
}CONSV_TecSport_t;

typedef enum 
{
  CONSV_SPORT_LOW   = 0x01,
  CONSV_SPORT_MED,
  CONSV_SPORT_HIGH
}CONSV_Sport_t;

typedef union{
  uint8_t Allbits;
  struct {
     uint8_t   ConservMode             :4;     // 4-bit for TEC or SPORT
     uint8_t   ConservSportMode        :4;     // 4-bit for Consv SPORT Low, Med, or High      
    };
}CONSV_Set_t;    

typedef enum 
{
  CONSV_GF_LOW   = 0x00,
  CONSV_GF_HIGH,
}CONSV_GF_Switch_t;

typedef enum 
{
  HIGH_SP   = 0x00,
  LOW_SP    = 0x01,
  CUSTOM_SP = 0x02
}SP_Switch_t;

typedef union{
    uint8_t Allbits;
    struct {
        uint8_t      TMT1     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      TMT2     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      TMT3     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      TMT4     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      TMT5     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      TMT6     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Resv7    :1;     
        uint8_t      Resv8    :1;
    };
}TMT_Bit_t;


typedef union{
    uint8_t Allbits;
    struct {
        uint8_t      Gas1     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Gas2     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Gas3     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Gas4     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Gas5     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Gas6     :1;     // 1-bit #1 --> 0: OFF, 1: ON:
        uint8_t      Resv7    :1;
        uint8_t      Resv8    :1;
    };
}Gas_Bit_t;

/*
typedef union {
	uint64_t Val;
	struct {
		uint64_t CheckSum:8;
		uint64_t BatCond:2;
		uint64_t Extra:2;
		uint64_t TankPres:12;
		uint64_t ID6:4;
		uint64_t ID5:4;
		uint64_t ID4:4;
		uint64_t ID3:4;
		uint64_t ID2:4;
		uint64_t ID1:4;
		uint64_t Sync:8;
	};
} EMPulsePacket_t;
*/



typedef struct 
{
  uint8_t      Tank1    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Tank2    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Tank3    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Tank4    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Tank5    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Tank6    :1;     // 1-bit #1 --> 0: OFF, 1: ON:
  uint8_t      Resv7    :1;
  uint8_t      Resv8    :1;
}Tank_Bit_t;

//======================================================================================
/* Scuba Mode Settings */
#define TOTAL_TANK_NUM              6       // 6 for DSX; 3 for i330R, 
#define MAX_TOTAL_TANK_NUM          6       // 6 for Max possible Tank Number

//EEPROM Data structure: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct
{
  /****************************** Scuba, Gauge, and Free Mode Settings ******************************************/
  
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------   
  NVD_DVS_DECO_ALGORITHM_t DivingAlgo;          /* 1-Byte 8-bit DIVING ALGORITHM: "NVD_DVS_DSAT"-DSAT, "NVD_DVS_PZ"-PZ+, "NVD_DVS_BUL16C"-BUL */
  uint8_t TotalActiveGases;                     /* 1-Byte Number of Active Tanks */  
  uint8_t CurrGasNumber;                        /* 1-Byte Current Tank Number */
  Tank_Bit_t TankActive;                        /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  Gas_Bit_t GasActive;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
  CONSV_Set_t Consv;                            /* 1-Byte 4-bit Set TEC GF = 0 or SPORT GF = 4*/
                                                /* 1-Byte 4-bit Set SPORT GF = Low, Medium and High */
  uint8_t GF_Low;                               /* 1-Byte 8-bit BUHLMANN Gradient Factor Low */
  uint8_t GF_High;                              /* 1-Byte 8-bit BUHLMANN Gradient Factor High */

  NVD_status_t SafetyStopMode;                  /* 1-Byte 8-bit NVD_OFF: disabled;
                                                NVD_DVS_SS_NORMAL: Standard SS behaviour, start countdown of SafetyStopMin at SafetyStopDepthXX
                                                NVD_DVS_SS_TIMER: Timer Mode */
  uint8_t SafetyStopMin;                        /* 1-Byte 8-bit Time for safety stop in min @ safety stop depth (used in NON DECOMPRESSION ZONE). */
  uint8_t SS_DepthFt;                           /* 1-Byte 8-bit Safety stop in ft       0: 10Ft,  1: 15Ft,    2: 20Ft         */
  uint8_t SS_DepthM;                            /* 1-Byte 8-bit Safety stop in meter    0: 3Mt,  1: 4Mt,   2: 5Mt,  3: 6Mt    */
  uint16_t DepthAlarmFT;                        /* 2-Byte Depth Alarm in feet */
  uint16_t DepthAlarmM;                         /* 2-Byte Depth Alarm in Meter */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------   
  union AlarmUNION  AlarmSet;   /* 4-Byte Alarm Set */
  uint8_t TLBG_Alarm;           /* 1-Byte Tissue Loading Alarm Level */
  uint8_t ASCBG_Alarm;          /* 1-Byte ASC BG Alarm Level */
  uint8_t DTR_Alarm;            /* 1-Byte Dive Time Remaining Level */
  uint8_t EDT_Alarm;            /* 1-Byte Dive Time Level */
  uint16_t  Reserved18;         /* 2-Byte Reserved */
  uint16_t  Reserved1A;         /* 2-Byte Reserved */
  uint16_t  Reserved1C;         /* 2-Byte Reserved */
  uint8_t  LastStopFt;          /* 1-Byte Last Stop Depth (before back to surface) in feet */  
  uint8_t  LastStopM;           /* 1-Byte Last Stop Depth (before back to sruface) in meter */
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  PO2A[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7   Pressure of O2 */
  uint8_t  Reserved27;                  /* 1-Byte 8-bit Reserved */ 
  uint8_t  FO2A[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7   Fractional of O2 */
  uint8_t  Reserved2F;                  /* 1-Byte 8-bit Reserved */ 
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------   
  
  uint8_t  FN2A[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7   Fractional of N2 */
  uint8_t  Reserved37;                  /* 1-Byte 8-bit Reserved */ 
  uint8_t  FHeA[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved3F;                  /* 1-Byte 8-bit Reserved */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  SP_Current;                  /* 1-Byte SP Current Set Value (40 to 150) */
  uint8_t  SP_SetLow;                   /* 1-Byte SP Set Point Low (40 to 150) */
  uint8_t  SP_SetHigh;                  /* 1-Byte SP Set Point High (40 to 150) */
  uint8_t  SP_SetCustomer;              /* 1-Byte SP Set Point Customer (40 to 150) */
  SP_Switch_t SP_Switch;                /* 1-Byte SP Set Point Set Switches */
  NVD_status_t  SP_CustomSW;            /* 1-Byte Customer SP Set Switches */
  
  uint8_t  SP_AutoHighM;                /* 1-Byte SP Auto Set Point High (6 to 130) */
  uint8_t  SP_AutoLowM;                 /* 1-Byte SP Auto Set Point High (2 to 130) */
  uint16_t SP_AutoHighFT;               /* 2-Byte SP Auto Set Point High (20 to 420) */
  uint16_t SP_AutoLowFT;                /* 2-Byte SP Auto Set Point High (10 to 420) */
  uint8_t  OCmin;       /* 1-Byte OCmin */
  uint8_t  OCmax;       /* 1-Byte OCmax */
  uint8_t  OCdeco;      /* 1-Byte OCdeco */
  uint8_t  CONS;        /* 1-Byte CONS */

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------  
  NVD_status_t TankPressState;  /* 1-Byte Tank Pressure State */ 
  uint8_t      TankPressBAR;    /* 1-Byte Tank Pressure in BAR */
  uint16_t     TankPressPSI;    /* 2-Byte Tank Pressure in PSI */ 
  NVD_status_t CC6PressState;  /* 1-Byte CC6 Pressure State */ 
  uint8_t      CC6PressBAR;    /* 1-Byte CC6 Pressure in BAR */
  uint16_t     CC6PressPSI;    /* 2-Byte CC6 Pressure in PSI */ 
  
  NVD_status_t TurnPressState;  /* 1-Byte Turn Pressure State */ 
  uint8_t      TurnPressBAR;    /* 1-Byte Turn Pressure in BAR */
  uint16_t     TurnPressPSI;    /* 2-Byte Turn Pressure in PSI */  
  NVD_status_t EndPressState;  /* 1-Byte End Pressure State */ 
  uint8_t      EndPressBAR;    /* 1-Byte End Pressure in BAR */
  uint16_t     EndPressPSI;    /* 2-Byte End Pressure in PSI */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------   
  union Alarm2UNION  Alarm2Set; /* 4-Byte Alarm Set */  
  uint8_t TEC_GF_Lo;            /* 1-Byte TEC_GF_Lo */
  uint8_t TEC_GF_Hi;            /* 1-Byte TEC_GF_Hi */
  uint8_t TTS_min;              /* 1-Byte Reserved */ 
  uint8_t  Reserved67;          /* 1-Byte Reserved */
  uint8_t  Reserved68;          /* 1-Byte Reserved */
  uint8_t  GF_Alarm;            /* 1-Byte GF Value Alarm */
  uint8_t  Reserved6A;          /* 1-Byte Reserved */
  uint8_t  N2_Alarm;            /* 1-Byte N2 Value Alarm */
  uint8_t  BOmin;               /* 1-Byte BOmin */
  uint8_t  BOmax;               /* 1-Byte BOmax */
  uint8_t  BOdeco;              /* 1-Byte BOdeco */
  uint8_t  Reserved6F;          /* 1-Byte Reserved */ 
 
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x70 to 0x8F
  //-------------------------------------------------------------------------------------------------------  
  uint32_t TMTID[MAX_TOTAL_TANK_NUM+1]; /* 4-Byte x 7 Transmitter 1 ID */
  TMT_Bit_t TMT_On;                     /* TMT On/Off bits of each TMT */
  uint8_t  Reserved8D;                  /* 1-Byte Reserved */ 
  uint16_t Reserved8E;                  /* 2-Byte Reserved */        
 
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x90 to 0x9F
  //-------------------------------------------------------------------------------------------------------   
  TMT_NUM_t  GASTMT[MAX_TOTAL_TANK_NUM+1];/* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  uint8_t  Reserved97;                  /* 1-Byte Resered */  
  uint8_t  MOD[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  MOD of each Gas Tank 1 to 6 */
  uint8_t  Reserved9F;                  /* 1-Byte Reserved */

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xA0 to 0xAF
  //-------------------------------------------------------------------------------------------------------   
  uint16_t      Wob_AL_Ft;      /* 2-Byte WOB AL in Ft, Work of Breathing (WOB) */ 
  uint16_t      Wob_AL_dM;      /* 2-Byte WOB AL in dM, Work of Breathing (WOB) */ 
  uint16_t      End_AL_Ft;      /* 2-Byte END AL in Ft, Equivalent Narcotic Depth (END) */
  uint16_t      End_AL_dM;      /* 2-Byte End AL in dM, Equivalent Narcotic Depth (END) */   
  uint16_t      SwitchP_PSI;    /* 2-Byte SwitchP_PSI */ 
  uint16_t      SwitchP_BAR;    /* 2-Byte SwitchP_BAR */  
  uint16_t      ReservedAC;     /* 2-Byte Reserved */
  uint16_t      ReservedAE;     /* 2-Byte Reserved */
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xB0 to 0xBF
  //-------------------------------------------------------------------------------------------------------   
  uint16_t      ReservedB0;     /* 2-Byte Reserved */ 
  uint16_t      ReservedB2;     /* 2-Byte Reserved */  
  uint16_t      ReservedB4;     /* 2-Byte Reserved */ 
  uint16_t      ReservedB6;     /* 2-Byte Reserved */   
  uint16_t      ReservedB8;     /* 2-Byte Reserved */ 
  uint16_t      ReservedBA;     /* 2-Byte Reserved */ 
  uint16_t      ReservedBC;     /* 2-Byte Reserved */ 
  uint16_t      ReservedBE;     /* 2-Byte Reserved */  
   
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xC0 to 0xCF  80 Bytes
  //-------------------------------------------------------------------------------------------------------   
  
  uint8_t reserved[256  - 16*13 - 4]; // to make the whole structure size 16*n in the future
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
    
  uint16_t      FreeDiveEDT_S;          /* 2-Byte Free Dive Time in Second */ 
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xF0 to 0xFF  16 Bytes
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      FreeDiveAlarm1_Ft;       /* 2-Byte Free Dive Alarm1 in Ft */ 
  uint16_t      FreeDiveAlarm2_Ft;       /* 2-Byte Free Dive Alarm2 in Ft */ 
  uint16_t      FreeDiveAlarm3_Ft;       /* 2-Byte Free Dive Alarm3 in Ft */ 
  uint16_t      FreeDiveAlarm1_M;        /* 2-Byte Free Dive Alarm1 in dM */ 
  uint16_t      FreeDiveAlarm2_M;        /* 2-Byte Free Dive Alarm2 in dM */ 
  uint16_t      FreeDiveAlarm3_M;        /* 2-Byte Free Dive Alarm3 in dM */
  uint8_t       CountDownMin;           /* 1-Byte Free Dive Count Down Minutes */
  uint8_t       CountDownSec;           /* 1-Byte Free Dive Count Down Seconds */

  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;   
  
} Scuba_Settings_t;  // can be modified by user settings about diving activities)
//======================================================================================




//======================================================================================
typedef struct
{
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  CC_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_CC;                  /* 1-Byte currently selected Gas number  1 to 6 */
  uint8_t  CC_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t CC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  OC_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_OC;                  /* 1-Byte currently selected Gas number  1 to 6 */
  uint8_t  OC_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t OC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  SM_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_SM;                  /* 1-Byte currently selected Gas number  1 to 6 */  
  uint8_t  SM_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t SM_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 
   
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  GSM_PO2A[MAX_TOTAL_TANK_NUM+1];      /* 1-Byte x 7   Pressure of O2 */
  TMT_NUM_t CurrTMT_Number_GSM;                 /* 1-Byte currently selected TMT number  1 to 6 */  
  uint8_t  GSM_FO2[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Fractional of O2 */
  TMT_Bit_t GSM_TMT_Active;                     /* 1-Byte Activated TMTs by 6 bits = b000111, ex. gas 3,2,1 activated */ 
   
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  GAUGE_PO2A[MAX_TOTAL_TANK_NUM+1];    /* 1-Byte x 7   Pressure of O2 */
  TMT_NUM_t CurrTMT_Number_GAUGE;               /* 1-Byte currently selected TMT number  1 to 6 */  
  uint8_t  GAUGE_FO2[MAX_TOTAL_TANK_NUM+1];     /* 1-Byte x 7   Fractional of O2 */
  TMT_Bit_t GAUGE_TMT_Active;                   /* 1-Byte Activated TMTs by 6 bits = b000111, ex. gas 3,2,1 activated */ 
   
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------     
  TMT_NUM_t  CC_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t CC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  CC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved5F; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------     
  TMT_NUM_t  OC_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t OC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  OC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved6F; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------     
  TMT_NUM_t  SM_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t SM_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  SM_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved7F; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x80 to 0x8F
  //-------------------------------------------------------------------------------------------------------     
  TMT_NUM_t  GSM_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t GSM_Select;                        /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  GSM_FHe[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved8F; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x90 to 0x9F
  //-------------------------------------------------------------------------------------------------------     
  TMT_NUM_t  GAUGE_GASTMT[MAX_TOTAL_TANK_NUM+1];/* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t GAUGE_Select;                      /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  GAUGE_FHe[MAX_TOTAL_TANK_NUM+1];     /* 1-Byte x 7   Fractional of He */
  uint8_t  Reserved9F; 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xA0 to 0xAF
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  BO_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_BO;                  /* 1-Byte currently selected TMT number  1 to 6 */  
  uint8_t  BO_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t BO_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xB0 to 0xBF
  //-------------------------------------------------------------------------------------------------------   
  TMT_NUM_t  BO_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t BO_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  BO_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedBF;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xC0 to 0xFF
  //-------------------------------------------------------------------------------------------------------      
 
  uint8_t reserved[256  - 16*12 - 2]; // to make the whole structure size 16*n in the future
  
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
}TRIMIX_Settings_t; 


//========================================================================================================
//========================================================================================================


/* Free Mode Settings */
//EEPROM Data structure: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct
{  
  uint8_t reserved[256- 4];       // to make the whole structure size 16*n in the future
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;  
  
} Free_Settings_t;  // can be modified by user settings about diving activities)
//======================================================================================

/* Free Mode Settings */
//EEPROM Data structure: PLEASE DO NOT CHANGE VARIABLE ORDER !!! 
typedef struct
{ 
  uint8_t reserved[256- 4];       // to make the whole structure size 16*n in the future
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;  
  
} Free_Records_t;  // can be modified by user settings about diving activities)


//======================================================================================

typedef struct
{
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t BootloaderHeadAddr;
  uint32_t BootloaderTailAddr;
  uint32_t Reserved08;
  uint32_t Reserved0C;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t FirmwareHeadAddr;
  uint32_t FirmwareTailAddr;
  uint32_t Reserved18;
  uint32_t Reserved1C;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t GPS_HeadAddr;
  uint32_t GPS_TailAddr;
  uint32_t GPS_FirstPointAddr;
  uint32_t GPS_LastPointAddr;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t MyInfoHeadAddr;
  uint32_t MyInfoTailAddr;
  uint32_t Reserved38;
  uint32_t Reserved3C;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t Reserved40;
  uint32_t Reserved44;
  uint32_t Reserved48;
  uint32_t Reserved4C;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t NormLogHeadAddr;
  uint32_t NormLogTailAddr;
  uint32_t NormLogFirstDiveAddr;
  uint32_t NormLogNextDiveAddr;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t FreeLogHeadAddr;
  uint32_t FreeLogTailAddr;
  uint32_t FreeLogFirstDiveAddr;
  uint32_t FreeLogLastDiveAddr; 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t ProfileHeadAddr;
  uint32_t ProfileTailAddr;
  uint32_t ProfileLastDiveHeadAddr;
  uint32_t ProfileLastDiveEndAddr;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x80 to 0x8F
  //-------------------------------------------------------------------------------------------------------       
  uint32_t SlateHeadAddr;
  uint32_t SlateTailAddr;
  uint32_t SlateFirstPageAddr;
  uint32_t SlateLastPageAddr;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x90 to 0xDF
  //-------------------------------------------------------------------------------------------------------       
  uint8_t reserved90[80];
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xE0 to 0xEF
  //-------------------------------------------------------------------------------------------------------       
  uint32_t BLE_Record0;
  uint32_t BLE_Record1;
  uint32_t BLE_Record2;
  uint32_t BLE_Record3;
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xF0 to 0xFF
  //-------------------------------------------------------------------------------------------------------       
  uint8_t reservedF0[12];
    
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
    /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;  
  
}FLASH_Map_t;
//========================================================================================================
//========================================================================================================



/*******************************************************************************
 * @brief   Initialize Hardware Calibration Global Structure
 ******************************************************************************/

void HW_Cal_Init( Mfg_Calibration_t *Data );

/*******************************************************************************
 * @brief   Initialize Device Parameters Global Structure
 ******************************************************************************/

void DEV_Rec_Init( Device_Records_t *Data );

/*******************************************************************************
 * @brief   Initialize General System Settings Global Structure
 ******************************************************************************/

void User_Set_Init( User_Settings_t *Data );

/*******************************************************************************
 * @brief   Initialize Scuba Mode Settings Global Structure
 ******************************************************************************/

void SCUBA_Set_Init( Scuba_Settings_t *Data );


/*******************************************************************************
 * @brief   Initialize Scuba Mode Record Global Structure
 ******************************************************************************/

void TRIMIX_Set_Init( TRIMIX_Settings_t *Data );

/*******************************************************************************
 * @brief   Initialize Free Mode Settings Global Structure
 ******************************************************************************/

void FREE_Set_Init( Free_Settings_t *Data );

/*******************************************************************************
 * @brief   Initialize Free Mode Record Global Structure
 ******************************************************************************/

void FREE_Rec_Init( Free_Records_t *Data );

/*******************************************************************************
 * @brief   Initialize My Info Settings Global Structure
 ******************************************************************************/

void FLASH_Map_Init( FLASH_Map_t *Data );

/*******************************************************************************
 * @brief   Initialize Algorithm rentined Data Structs
 ******************************************************************************/

void RetData_Init( void );

/*******************************************************************************
 * @brief   Initialize LOG Data Global Structure
 ******************************************************************************/

//void LOG_Data_Init(LOG_Data_t *Data);

/*******************************************************************************
 * @brief   Initialize Profile Header Global Structure
 ******************************************************************************/

//void Profile_Header_Set_Init(Profile_Header_t *Data);

/*******************************************************************************
 * @brief   Initialize Profile Data Global Structure
 ******************************************************************************/

//void Profile_Data_Set_Init(Profile_Data_t *Data);

/*******************************************************************************
 * @brief   Initialize Profile Trailer Global Structure
 ******************************************************************************/

//void Profile_Trailer_Set_Init(Profile_Trailer_t *Data);
/*******************************************************************************
    Data Structure for Data Retention
*******************************************************************************/

/*******************************************************************************
    Data Structure for Time Retention
*******************************************************************************/
typedef struct
{
    SystemTimeDate_t PST;
    SystemTimeDate_t HomeT;
    SystemTimeDate_t AwayT;
    SystemTimeDate_t Reserved3;
    SystemTimeDate_t Reserved2;
    SystemTimeDate_t Reserved1;  
} DateTimeRetained_t; //256 byte data structure

typedef struct
{
    DateTimeRetained_t  Retained;  
    uint8_t reserved[BLOCK_SIZE - sizeof(DateTimeRetained_t) - 2];       // to make the whole structure size 16*n in the future  
    /* CRC Block Data */
    /* Updated only befroe storing on External Falsh memory */
    uint8_t CRC_MSB;
    uint8_t CRC_LSB;
} RetainedBlk_t; //256 byte data structure


//==============================================================================
 

/******************************************************************************
 * @brief   Dive LOG Data Structure
 *
 * @note
 *
 ******************************************************************************/
typedef struct    // bit1-bit0 (00  = NORM, 01 = GAUGE. 10=FREE, 11=NA),  
{                   // bit4-bit6 (b000 to b111= 0 to 7) 0 to 7 levels of Conservative GF, bit-7 = VIOLATION
  uint8_t      DiveMode :2;         // 2-bit 
  uint8_t      Res2     :2;         // 2-bit  
  uint8_t      ConsGF   :3;         // 3-bit  
  uint8_t      Violation:1;         // 1-bit 
}ModesCONSV;  

typedef struct     
{                   
  uint8_t      TopNDCBG :4;         // 4-bit, 0 to 15
  uint8_t      MaxNDCBG :4;         // 4-bit, 0 to 15  
}NDCBG;

typedef struct      
{                   
  uint8_t      TopASCBG :4;         // 4-bit, 0 to 15 
  uint8_t      MaxASCBG :4;         // 4-bit, 0 to 15  
}ASCBG; 

typedef struct     
{                   
  uint8_t      Nib0  :4;          // 4-bit, 0 to 15
  uint8_t      Nib1  :4;          // 4-bit, 0 to 15
  uint8_t      Nib2  :4;          // 4-bit, 0 to 15
  uint8_t      Nib3  :4;          // 4-bit, 0 to 15
  uint8_t      Nib4  :4;          // 4-bit, 0 to 15
  uint8_t      Nib5  :4;          // 4-bit, 0 to 15
  uint8_t      Nib6  :4;          // 4-bit, 0 to 15
  uint8_t      Nib7  :4;          // 4-bit, 0 to 15
  uint8_t      Nib8  :4;          // 4-bit, 0 to 15
  uint8_t      Nib9  :4;          // 4-bit, 0 to 15
  uint8_t      Nib10 :4;          // 4-bit, 0 to 15
  uint8_t      Nib11 :4;          // 4-bit, 0 to 15
  uint8_t      Nib12 :4;          // 4-bit, 0 to 15
  uint8_t      Nib13 :4;          // 4-bit, 0 to 15
  uint8_t      Nib14 :4;          // 4-bit, 0 to 15
  uint8_t      Nib15 :4;          // 4-bit, 0 to 15
}N2_Nibble_t;

/* Dive LOG Data Structure */
typedef struct
{
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------       
  uint16_t      LogNum;         // Byte-0:      Log Number good from 1 up to 65535
  uint8_t       DiveNum;        // Byte-2:      Dive Number (0 to 255 in DSX)
  
  uint8_t       EntryHr;        // Byte-3:      Hr 0 to 23       
  uint8_t       EntryMin;       // Byte-4:      Min 0 to 59
  uint8_t       EntryDay;       // Byte-5:      Day 1 to 31
  uint8_t       EntryMon;       // Byte-6:      Month 1 to 12
  uint8_t       EntryYear;      // Byte-7:      Year 0 to 255 (2000 to 2255)
  
  uint32_t      ProfileHeadAddr;// Byte-8 to 11  Profile Header Address
  uint32_t      ProfileTailAddr;// Byte-12 to 15 Profile Trailer Address        
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------       
  uint16_t      MaxDepthFt10;   // Byte-16,17:  Byte, Max Depth Ft 0 to 65535 feet
  uint16_t      AvgDepthFt10;   // Byte-18,19:  Byte, Avg Depth Ft 0 to 65535 feet
  uint16_t      EDTsec;         // Byte-20,21:  Dive Time, 0 to 36000 seconds = 600 minutes = 10 Hrs
  uint16_t      MaxPO2;         // Byte-22,23:  Max PO2 of the Dive
  
  uint8_t       SurfInvT_Hr;    // Byte-24:     Surf Interval Time Hour 0 to 255
  uint8_t       SurfInvT_Min;   // Byte-25:     Surf Interval Time Min 0 to 59
  
  uint8_t       ExitMin;        // Byte-26:     The Min of Exit Time   
  uint8_t       ExitHr;         // Byte-27:     The Hour of Exit Time

  int16_t       MinTempF10;     // Byte-28,29:  Min Temperature in F
  int16_t       MaxTempF10;     // Byte-30,31:  Max Temperature in F
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------       
  uint8_t       ModesConsv;     // Byte-32:     Dive Modes, Level of Consv., Violation flag
  uint8_t       SeaLevel;       // Byte-33:     Sea Level 0 to 7  
  uint8_t       EndTLBG;        // Byte-34:     End Deco Bar Graph Level, ranged from 0 to 15
  uint8_t       MaxASCBG;       // Byte-35:     Max Ascend Rate Bar Graph Level, ranged from 0 to 15
  
  uint8_t       GasNum;         // Byte-36      Gas Num and Gas # the Dive  
  uint8_t       MaxTLBG;        // Byte-37      Max Deco Bar Graph Level, ranged from 0 to 15  
  uint8_t       O2Sat;          // Byte-38:     O2 Saturation Toxic   
  uint8_t       FO2;            // Byte-39:     FO2 at End of Dive 
  
  uint8_t       CC_HiPO2;       // Byte-40:     CC High PO2
  uint8_t       CC_LoPO2;       // Byte-41:     CC Low PO2
  uint8_t       CC_MaxGF;       // Byte-42:     Max GF Value
  uint8_t       TLBG_Threshold; // Byte-43:     TLBG Threshold to alarm
  uint8_t       DiveType;       // Byte-44:     Dive Type =  CC, OC, SM, GSM, Gauge
  uint8_t       EndDiveType;    // Byte-45:     Dive Type =  CC, OC, SM, GSM, Gauge
  uint16_t      TotalDiveSec;   // Byte-46,47:  TotalDiveSec = EDTsec + SurfaceTime between Re-Entry Dives (if any)
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------  
  union SwitchUNION SwitchSet;  // Byte-48 to 51-Byte switches of the system and dive
  uint8_t       Reserved34[4];  // Byte-52 to 55: for 4 Bytes Reserved
  
  union Alarm2UNION AlarmOccured2;   // Byte-56,57,58,59:  4-Byte Alarms and Warnings of the system and dive  
  union AlarmUNION  AlarmOccured;    // Byte-60,61,62,63:  4-Byte Alarms and Warnings of the system and dive
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      Start_PSI[7];           // Byte-64 to 77: for 14 Bytes 
  uint16_t      Reserved4E;             // Byte-78 to 79: for 2 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      End_PSI[7];             // Byte-80 to 93: for 14 Bytes
  uint16_t      Reserved5E;             // Byte-94 to 95: for 2 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      TankTimeMin[7];         // Byte-96 to 109: for 14 Bytes
  Gas_Bit_t     Tank_Active;            // Byte-110: for 1 Byte to record CC_Active
  uint8_t       Reserved6F;             // Byte-111: for 1 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------  
  uint8_t       TLBGS[16];              // Byte-112 to 127: for 16 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x80 to 0x8F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      Bailout_Start_PSI[7]; // Byte-128 to 141: for 14 Bytes 
  uint16_t      Reserved8E;             // Byte-142 to 143: for 2 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x90 to 0x9F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      Bailout_End_PSI[7];   // Byte-144 to 157: for 14 Bytes
  uint16_t      Reserved9E;             // Byte-158 to 159: for 2 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xA0 to 0xAF
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      Bailout_TankTimeMin[7];  // Byte-160 to 173: for 14 Bytes
  Gas_Bit_t     Bailout_Active;         // Byte-174: for 1 Byte to record OC_Active
  uint8_t       ReservedAF;             // Byte-175: for 2 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xB0 to 0xBF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  CC_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t CC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  CC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedBF;

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xC0 to 0xCF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  OC_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t OC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  OC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedCF;

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xD0 to 0xDF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  SM_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t SM_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  SM_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  TMT_Bit_t  TMT_On_Bits;                       /* 8-bits to record TMT On/Off status of the dive */

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xE0 to 0xEF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  BO_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t BO_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  BO_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedEF;

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xF0 to 0xFF
  //-------------------------------------------------------------------------------------------------------  
  uint8_t      Reserved[16];                    // Byte-224 to 255: for 32 Bytes Reserved

  //----------------------------------------------------------------------------

}LOG_Data_t; //256 bytes data structure  



typedef struct
{
    int16_t Data[100];          // 200 Bytes for Dive Chart Data
    int16_t AfterDiveSec[AfterDiveGapID_Max];   //  24 Bytes for SurfTime between DiveTime, if re-entering water < 10 minutes
    uint8_t Reserved[32];       //  32 Bytes
}LOG_Chart_t;   //256 bytes data structure 
/******************************************************************************
 * @brief   Dive Profile Header Structure
 *
 * @note
 *
 ******************************************************************************/
typedef struct         // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control
{
  uint8_t       TLBG   :4;      // 4-bit (0 to 5, up to 7 for other products) 
  uint8_t       ASCBG  :4;      // 4-bit (0 to 5, up to 7 for other products)       
}TLBG_ASCBG;

typedef struct           // used to map individual flag defined for individual alarm warnings, work with UsrFlg Alarm bit, Alarm in general control
{
  uint16_t       Type :4;       // H 4-bit (bit 15,14,13,12) b to 5, up to 7 for other products) 
  uint16_t       Min  :12;      // L 12-bit (bit 11,10,...3,2,1,0) ranged from 0 to 4095 minutes
}Type_dtr;

union TYPE_DTR
{
    Type_dtr    Bit;
    uint16_t    AllBits;    
};

typedef struct
{
  uint16_t       GasNum :4;     // H 4-bit (for 1,2,3,4,5,6, Tank Num)
  uint16_t         GTR  :12;     // L 12-bit  (bit 11,10,...3,2,1,0) ranged from 0 to 4095 minutes  
}GASNUM_GTR;



/* Dive Profile Header Structure */
typedef struct
{  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------  
  uint16_t      LogNum;         // Byte-0,1:    LOG Number (0 to 65535 Log Numbers in DSX)
  uint8_t       DiveNum;        // Byte-2:      Dive Number (0 to 255 in DSX)
  
  uint8_t       EntryHr;        // Byte-3:      Hr 0 to 23       

  uint8_t       EntryMin;       // Byte-4:      Min 0 to 59
  uint8_t       EntryDay;       // Byte-5:      Day 1 to 31
  uint8_t       EntryMon;       // Byte-6:      Month 1 to 12
  uint8_t       EntryYear;      // Byte-7:      Year 0 to 255 (2000 to 2255) 

  uint8_t       StartGasNum;    // Byte-8:      Start Gas (Tank) Num and Gas # the Dive    
  uint8_t       SeaLevel;       // Byte-9:      Sea Level 0 to 7
  uint8_t       SurfInvT_Hr;    // Byte-10:     Surf Interval Time Hour 0 to 255
  uint8_t       SurfInvT_Min;   // Byte-11:     Surf Interval Time Min 0 to 59
  union SwitchUNION SwitchSet;  // Byte-12,13,14,15  4-Byte switches of the system and dive

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------  
  
  /* 1-Byte x 6   Fractional of O2 */
  uint8_t  FO21;                // Byte-16:
  uint8_t  FO22;                // Byte-17:
  uint8_t  FO23;                // Byte-18:
  uint8_t  FO24;                // Byte-19:
  uint8_t  FO25;                // Byte-20:
  uint8_t  FO26;                // Byte-21:
  
/* 1-Byte x 6   Pressure of O2 */
  uint8_t  PO21;                // Byte-22:
  uint8_t  PO22;                // Byte-23:
  uint8_t  PO23;                // Byte-24:        
  uint8_t  PO24;                // Byte-25:
  uint8_t  PO25;                // Byte-26:
  uint8_t  PO26;                // Byte-27:
  
  uint8_t  DiveType;            // Byte-28:     Dive Type (when dive in), 0: CC, 1: OC, 2: SM, 3: GSM, 4: Gauge  
  uint8_t  Reserved29;          // Byte-29:     Reserved
  uint8_t  Reserved30;          // Byte-30:     Reserved
  uint8_t  Reserved31;          // Byte-31:     Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------  
  uint8_t TLBG_Alarm;           /* 1-Byte Tissue Loading Alarm Level */
  uint8_t ASCBG_Alarm;          /* 1-Byte ASC BG Alarm Level */
  uint8_t DTR_Alarm;            /* 1-Byte Dive Time Remaining Level */
  uint8_t EDT_Alarm;            /* 1-Byte Dive Time Level */
  
  NVD_SAMPLETIME_t SamplingTime;/* 1-Byte 8-bit 2, 10, 30 or 60 */
  NVD_conserv_t ConservDSAT;    /* 1-Byte 8-bit Set the DSAT on conservative if ON */
  uint8_t GF_Low;               /* 1-Byte 8-bit BUHLMANN Gradient Factor Low */
  uint8_t GF_High;              /* 1-Byte 8-bit BUHLMANN Gradient Factor High */

  NVD_status_t SafetyStopMode;      /* 1-Byte 8-bit NVD_OFF: disabled;
                                        NVD_DVS_SS_NORMAL: Standard SS behaviour, start countdown of SafetyStopMin at SafetyStopDepthXX
                                        NVD_DVS_SS_TIMER: Timer Mode */
  uint8_t SafetyStopMin;                /* 1-Byte 8-bit Time for safety stop in min @ safety stop depth (used in NON DECOMPRESSION ZONE). */
  uint8_t SS_DepthFt;                   /* 1-Byte 8-bit Safety stop in ft       0: 10Ft,  1: 15Ft,    2: 20Ft         */
  uint8_t SS_DepthM;                    /* 1-Byte 8-bit Safety stop in meter    0: 3Mt,  1: 4Mt,   2: 5Mt,  3: 6Mt    */
  
  uint16_t DepthAlarmFT;                /* 2-Byte Depth Alarm in feet */
  uint16_t DepthAlarmM;                 /* 2-Byte Depth Alarm in Meter */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t       TLBGS[16];              // Byte-48 to 63: for 16 Bytes Reserved
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x40 to 0x4F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  SP_Current;                  /* 1-Byte SP Current Set Value (40 to 150) */
  uint8_t  SP_SetLow;                   /* 1-Byte SP Set Point Low (40 to 150) */
  uint8_t  SP_SetHigh;                  /* 1-Byte SP Set Point High (40 to 150) */
  uint8_t  SP_SetCustomer;              /* 1-Byte SP Set Point Customer (40 to 150) */
  SP_Switch_t SP_Switch;                /* 1-Byte SP Set Point Set Switches */
  NVD_status_t  SP_CustomSW;            /* 1-Byte Customer SP Set Switches */
  
  uint8_t  SP_AutoHighM;                /* 1-Byte SP Auto Set Point High (6 to 130) */
  uint8_t  SP_AutoLowM;                 /* 1-Byte SP Auto Set Point High (2 to 130) */
  uint16_t SP_AutoHighFT;               /* 2-Byte SP Auto Set Point High (20 to 420) */
  uint16_t SP_AutoLowFT;                /* 2-Byte SP Auto Set Point High (10 to 420) */
  uint8_t  OCmin;       /* 1-Byte OCmin */
  uint8_t  OCmax;       /* 1-Byte OCmax */
  uint8_t  OCdeco;      /* 1-Byte OCdeco */
  uint8_t  CONS;        /* 1-Byte CONS */

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x50 to 0x5F
  //-------------------------------------------------------------------------------------------------------   
  uint16_t      Wob_AL_Ft;      /* 2-Byte WOB AL in Ft, Work of Breathing (WOB) */ 
  uint16_t      Wob_AL_dM;      /* 2-Byte WOB AL in dM, Work of Breathing (WOB) */ 
  uint16_t      End_AL_Ft;      /* 2-Byte END AL in Ft, Equivalent Narcotic Depth (END) */
  uint16_t      End_AL_dM;      /* 2-Byte End AL in dM, Equivalent Narcotic Depth (END) */   
  uint16_t      SwitchP_PSI;    /* 2-Byte SwitchP_PSI */ 
  uint16_t      SwitchP_BAR;    /* 2-Byte SwitchP_BAR */  
  uint16_t      ReservedAC;     /* 2-Byte Reserved */
  uint16_t      ReservedAE;     /* 2-Byte Reserved */
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x60 to 0x6F
  //-------------------------------------------------------------------------------------------------------  
  NVD_status_t TankPressState;  /* 1-Byte Tank Pressure State */ 
  uint8_t      TankPressBAR;    /* 1-Byte Tank Pressure in BAR */
  uint16_t     TankPressPSI;    /* 2-Byte Tank Pressure in PSI */ 
  NVD_status_t CC6PressState;  /* 1-Byte CC6 Pressure State */ 
  uint8_t      CC6PressBAR;    /* 1-Byte CC6 Pressure in BAR */
  uint16_t     CC6PressPSI;    /* 2-Byte CC6 Pressure in PSI */ 
  
  NVD_status_t TurnPressState;  /* 1-Byte Turn Pressure State */ 
  uint8_t      TurnPressBAR;    /* 1-Byte Turn Pressure in BAR */
  uint16_t     TurnPressPSI;    /* 2-Byte Turn Pressure in PSI */  
  NVD_status_t EndPressState;  /* 1-Byte End Pressure State */ 
  uint8_t      EndPressBAR;    /* 1-Byte End Pressure in BAR */
  uint16_t     EndPressPSI;    /* 2-Byte End Pressure in PSI */ 
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x70 to 0x7F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t TEC_GF_Lo;            /* 1-Byte TEC_GF_Lo */
  uint8_t TEC_GF_Hi;            /* 1-Byte TEC_GF_Hi */
  uint8_t TTS_min;              /* 1-Byte Reserved */ 
  uint8_t  Reserved67;          /* 1-Byte Reserved */
  uint8_t  Reserved68;          /* 1-Byte Reserved */
  uint8_t  GF_Alarm;            /* 1-Byte GF Value Alarm */
  uint8_t  Reserved6A;          /* 1-Byte Reserved */
  uint8_t  N2_Alarm;            /* 1-Byte N2 Value Alarm */
  union Alarm2UNION Alarm2Set;  // Byte-72 to 75:  4-Byte Alarms and Warnings of the system and dive
  union AlarmUNION  AlarmSet; /* 4-Byte Alarm Set */
 
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x80 to 0x8F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  CC_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_CC;                     /* 1-Byte currently selected Gas number  1 to 6 */
  uint8_t  CC_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t CC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */
  
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x90 to 0x9F
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  OC_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_OC;                     /* 1-Byte currently selected Gas number  1 to 6 */
  uint8_t  OC_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t OC_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xA0 to 0xAF
  //-------------------------------------------------------------------------------------------------------   
  uint8_t  SM_PO2A[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Pressure of O2 */
  TANK_NUM_t CurrGasNumber_SM;                     /* 1-Byte currently selected Gas number  1 to 6 */  
  uint8_t  SM_FO2[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of O2 */
  Gas_Bit_t SM_Active;                          /* 1-Byte Activated Gases by 6 bits = b000111, ex. gas 3,2,1 activated */ 
   
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xB0 to 0xBF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  CC_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t CC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  CC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedBF; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xC0 to 0xCF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  OC_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t OC_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/  
  uint8_t  OC_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedCF; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xD0 to 0xDF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  SM_GASTMT[MAX_TOTAL_TANK_NUM+1];   /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t SM_Select;                         /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  SM_FHe[MAX_TOTAL_TANK_NUM+1];        /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedDF; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xE0 to 0xEF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  GSM_GASTMT[MAX_TOTAL_TANK_NUM+1];  /* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t GSM_Select;                        /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  GSM_FHe[MAX_TOTAL_TANK_NUM+1];       /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedEF; 

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0xF0 to 0xFF
  //-------------------------------------------------------------------------------------------------------     
  TANK_NUM_t  GAUGE_GASTMT[MAX_TOTAL_TANK_NUM+1];/* 1-Byte x 7  TMT Address of each Gas Tank 1 to 6 */
  Tank_Bit_t GAUGE_Select;                      /* 1-Byte Activated Tanks by 6 bits = b000011, ex. tank 2,1 activated*/
  uint8_t  GAUGE_FHe[MAX_TOTAL_TANK_NUM+1];     /* 1-Byte x 7   Fractional of He */
  uint8_t  ReservedFF; 
    
  //---------- The Data collected in Profile Header-----------------------------
  
}Profile_Header_t;

/******************************************************************************
 * @brief   Dive Profile Data Structure
 *
 * @note
 *
 ******************************************************************************/

typedef struct
{
  uint8_t      DiveMode :4;     // 4-bit
  uint8_t      GASn     :4;     // 4-bit
} Modes_GasNum_t;

typedef struct
{
  uint8_t      ASC      :4;     // 4-bit
  uint8_t      TMTn     :4;     // 4-bit
} ASC_TMTnum_t;

/* Dive Profile Data Structure */
typedef struct
{
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------    
  Modes_GasNum_t    ModeGas;        // Byte-0:      DiceMode / Gas Number (Gas #)
  ASC_TMTnum_t      ASC_TMT;        // Byte-1:
  uint16_t          DepthFt10;      // Byte-2,3:    Depth Ft
  uint16_t          NoDecoTime;     // Byte-4,5;    No Deco Time in min
  uint16_t          DecoTime;       // Byte-6,7;    Deco Time in min
  uint16_t          DecoDepthFt;    // Byte-8,9;    Max at 400 ft, min at 20 ft
  int16_t           TempF10;        // Byte-10,11:  Temperature in F 0x0000 to 0xFFFF (65535), offset to -128 to 127, we use -40 C to 125 C
  uint16_t          PO2x100;        // Byte-12,13:  PO2 x 100
  uint16_t          TankPSI;        // Byte-14,15:  Current Tank PSI
  
  uint8_t           O2Pct;          // Byte-16;     Toxic O2 Percent
  uint8_t           TLBGBar;        // Byte-17;     N2 Saturation
  uint16_t          TLBGBits;       // Byte-18,19:  TLBG 16 bits to address the bit over TLBG Alarm threshold
  uint16_t          GTR;            // Byte-20,21:  Gas Time Remaining in min
  uint16_t          Tank6PSI;       // Byte-22,23:  Current Tank 6 PSI
  union Alarm2UNION Alarming2;      // Byte-24,25,26,27:  Alarms and Warnings of the system and dive
  union AlarmUNION  Alarming;       // Byte-28,29,30,31:  Alarms and Warnings of the system and dive
  /*  Depth
  
  DTR = NDT or OTR which ever is less in NO DECO	

  in deco DTR = DET

  if the dive computer connect to a tank by a hose then we calculate the ATR thru this tank. Then we have ATR.

  If a computer receive transmit tank pressure then we have number of gas = number of tank so when we swtich the tank, we recalculate the ATR of that tank.

  i330R is a Dive Calculator (based on pre-dive input FO2[1,2,3]), without true PO2 or FO2 measurements

  Because i330R doesnot have any hose or receiver circuit then NO ATR.							

  ATR values are direct Tank measurement results, by hose or transmitters, not applicable in i330R

 */
}Profile_Data_t;

/******************************************************************************
 * @brief   Dive Profile Trailer Structure
 *
 * @note
 *
 ******************************************************************************/
/* Dive Profile Trailer Structure */
typedef struct
{
  //---------- The Data collected in Profile Trailer----------------------------
  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------    
  uint16_t      LogNum;         // 2-Byte Byte-0,1:     LOG Number (0 to 65535 Log Numbers in DSX)
  uint8_t       DiveNum;        // 1-Byte Byte-2:       Dive Number (0 to 255 in DSX)
  
  uint8_t       GasUsed;        // 1-Byte Byte-3        Gas Num and Gas # the Dive
  uint8_t       ExitHr;         // 1-Byte Byte-4:       The Hour of Exit Time
  uint8_t       ExitMin;        // 1-Byte Byte-5:       The Min of Exit Time
  TLBG_ASCBG    MaxBG;          // 1-Byte Byte-6:       MaxTLBG and MaxAscBG
  uint8_t       Reserved7;      // 1-Byte Byte-7:       Reserved
  
  uint16_t      EDTsec;         // 2-Byte Byte-8, 9:    Elapsed Dive Time in minutes
  uint16_t      MaxDepthFt10;   // 2-Byte Byte-10,11:   Maximum Depth in feet
  uint16_t      AvgDepthFt10;   // 2-Byte Byte-12,13:   Byte, Avg Depth Ft 0 to 65535 feet
  uint8_t       O2Sat;          // 1-Byte Byte-14:      O2 Saturation Toxic
  uint8_t       EndDiveType;    // 1-Byte Byte-15:      End Dive Type (when back to surface), 0: CC, 1: OC, 2: SM, 3: GSM, 4: Gauge

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x10 to 0x1F
  //-------------------------------------------------------------------------------------------------------
  int16_t       MinTempF10;     // 2-Byte Byte-16:      Min Temperature in F
  int16_t       MaxTempF10;     // 2-Byte Byte-18:      Max Temperature in F
  uint16_t      TotalDiveSec;   // 2-Byte Byte-20,21:   TotalDiveSec = Record Dive Time + After Dive Time
  uint16_t      MaxPO2x100;     // 2-Byte Byte-22,23:   MaxPO2 x 100 (from 0.00 to 655.35)
  uint32_t      Reserved18;     // 4-Byte Byte-24,25,26,27:  Reserved
  uint32_t      Reserved1C;     // 4-Byte Byte-28,29,30,31:  Reserved

  //-------------------------------------------------------------------------------------------------------
  // Byte 0x20 to 0x2F
  //-------------------------------------------------------------------------------------------------------
  union AlarmUNION  AlarmFinal;     // 4-Byte Byte-32 to 35:  Alarms and Warnings of the system and dive
  union AlarmUNION  AlarmOccured;   // 4-Byte Byte-36 to 39:  Alarms and Warnings of the system and dive
  union AlarmUNION  AlarmFinal2;    // 4-Byte Byte-40 to 43:  Alarms and Warnings of the system and dive
  union AlarmUNION  AlarmOccured2;  // 4-Byte Byte-44 to 47:  Alarms and Warnings of the system and dive

  //-------------------------------------------------------------------------------------------------------  
  // Byte 0x30 to 0x3F
  //-------------------------------------------------------------------------------------------------------      
  uint32_t      Reserved30;     // 4-Byte Byte-48 to 51:  Reserved
  uint32_t      Reserved34;     // 4-Byte Byte-52 to 55:  Reserved
  uint32_t      Reserved38;     // 4-Byte Byte-56 to 59:  Reserved
  uint32_t      Reserved3C;     // 4-Byte Byte-60 to 63:  Reserved

  //---------- The Data collected in Profile Trailer---------------------------- 
}Profile_Trailer_t;


/**************************** Data Retention Data **************************/
typedef struct 
{
      uint32_t      b0    :1;        // 1-bit
      uint32_t      b1    :1;        // 1-bit
      uint32_t      b2    :1;        // 1-bit
      uint32_t      b3    :1;        // 1-bit
      uint32_t      b4    :1;        // 1-bit
      uint32_t      b5    :1;        // 1-bit
      uint32_t      b6    :1;        // 1-bit
      uint32_t      b7    :1;        // 1-bit
      
      uint32_t      b8    :1;        // 1-bit
      uint32_t      b9    :1;        // 1-bit
      uint32_t      b10   :1;        // 1-bit
      uint32_t      b11   :1;        // 1-bit
      uint32_t      b12   :1;        // 1-bit
      uint32_t      b13   :1;        // 1-bit
      uint32_t      b14   :1;        // 1-bit
      uint32_t      b15   :1;        // 1-bit
      
      uint32_t      b16    :1;        // 1-bit
      uint32_t      b17    :1;        // 1-bit
      uint32_t      b18    :1;        // 1-bit
      uint32_t      b19    :1;        // 1-bit
      uint32_t      b20    :1;        // 1-bit
      uint32_t      b21    :1;        // 1-bit
      uint32_t      b22    :1;        // 1-bit
      uint32_t      b23    :1;        // 1-bit
      
      uint32_t      b24    :1;        // 1-bit
      uint32_t      b25    :1;        // 1-bit
      uint32_t      b26    :1;        // 1-bit
      uint32_t      b27    :1;        // 1-bit
      uint32_t      b28    :1;        // 1-bit
      uint32_t      b29    :1;        // 1-bit
      uint32_t      b30    :1;        // 1-bit
      uint32_t      b31    :1;        // 1-bit
}AlgoBoolUnion;

union AlgoBoolUNION
{
    AlgoBoolUnion   Bit;
    uint32_t        AllBits;              // Combination of all above
};

/* Data Retention Copy-A */
typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
    DateTimeRetained_t  Retained;  
    uint8_t reserved[BLOCK_SIZE - sizeof(DateTimeRetained_t) - 4];       // to make the whole structure size 16*n in the future 
    uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
    /* CRC Block Data */
    /* Updated only befroe storing on External Falsh memory */
    uint8_t CRC_MSB;
    uint8_t CRC_LSB;
  
} RET_Data0_t; 

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------  
  SystemTimeDate_t PST;         /* 8-Byte Date and Time Retention */
  union AlgoBoolUNION AlgoBool; /* 4-Byte AlgoBool bits */  
  uint32_t Reserved12;          /* 4-Byte Reserved */ 
  
  uint8_t RetByte[0x30];        // up to 0x30 Bytes (48 Bytes)
  
  uint16_t RetWord[14];         // up to 14 of Words (2 x 14 = 28 Bytes)
  
  float RetFloat[40];           // 40 x 4 == 160
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data1_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  uint8_t RetByte[20];        // up to 20 Bytes
  float RetFloat[58];         

  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data2_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0xFF
  //-------------------------------------------------------------------------------------------------------
  float RetFloat[63];

  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data3_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0xFF
  //-------------------------------------------------------------------------------------------------------
  float RetFloat[63];

  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data4_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  int32_t Reserved0;         /* 4-Byte Reserved */  
  int32_t Reserved4;         /* 4-Byte Reserved */  
  uint32_t Reserved8;        /* 4-Byte Reserved */  
  uint32_t Reserved12;       /* 4-Byte Reserved */ 
    
  uint8_t reserved[252-0x10];
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data5_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  int32_t Reserved0;         /* 4-Byte Reserved */  
  int32_t Reserved4;         /* 4-Byte Reserved */  
  uint32_t Reserved8;        /* 4-Byte Reserved */  
  uint32_t Reserved12;       /* 4-Byte Reserved */ 
    
  uint8_t reserved[252-0x10];
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data6_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  int32_t Reserved0;         /* 4-Byte Reserved */  
  int32_t Reserved4;         /* 4-Byte Reserved */  
  uint32_t Reserved8;        /* 4-Byte Reserved */  
  uint32_t Reserved12;       /* 4-Byte Reserved */ 
    
  uint8_t reserved[252-0x10];
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} RET_Data7_t;


typedef struct
{
    //-------------------------------------------------------------------------------------------------------
    // Byte 0x00 to 0x0F
    //-------------------------------------------------------------------------------------------------------
    float Start_Latitude;               // 4-Byte Dive Start Location Latitude 
    float Start_Longitude;              // 4-Byte Dive Start Location Longitude 
    SystemTimeDate_t StartDateTime;     // 8-Byte Dive Start Date Time
    //-------------------------------------------------------------------------------------------------------
    // Byte 0x10 to 0x1F
    //-------------------------------------------------------------------------------------------------------
    float End_Latitude;                 // 4-Byte Dive End Location Latitude 
    float End_Longitude;                // 4-Byte Dive End Location Longitude 
    SystemTimeDate_t EndDateTime;       // 8-Byte Dive End Date Time 
    //-------------------------------------------------------------------------------------------------------
    // Byte 0x20 to 0x3F
    //-------------------------------------------------------------------------------------------------------
    char LocationInfo[20];              // 20-Byte GPS Location Info
    uint8_t Reserved[12];               // 12-Byte Reserved for future use
} GPS_Location_t;

typedef struct          
{
  //-------------------------------------------------------------------------------------------------------
  // Byte 0x00 to 0x0F
  //-------------------------------------------------------------------------------------------------------
  int32_t Reserved0;         /* 4-Byte Reserved */  
  int32_t Reserved4;         /* 4-Byte Reserved */  
  uint32_t Reserved8;        /* 4-Byte Reserved */  
  uint32_t Reserved12;       /* 4-Byte Reserved */ 
    
  uint8_t reserved[252-0x10];
  
  uint16_t ErrCnt;      // EE Write/Read Com Error (mismatch) Count
  /* CRC Block Data */
  /* Updated only befroe storing on External Falsh memory */
  uint8_t CRC_MSB;
  uint8_t CRC_LSB;
  
} EE_Block_t;
/*******************************************************************************
 * @brief   Store all NVD Data in RAM to ExtEEPROM at once. 
 *          To be Used only before Reboot, sicne long processing time.
 ******************************************************************************/
void NVD_RAMTOTAL_to_ExtEEPROM (void);

/*******************************************************************************
 * @brief   Store all Retained Data in RAM to ExtEEPROM at once. 
 *          
 ******************************************************************************/
void NVD_SaveRetainedData_to_ExtEEPROM (void);

/*******************************************************************************
 * @brief   Request to Save all or partial NVD Data in RAM to ExtEEPROM
 ******************************************************************************/
void EE_SaveReq (uint8_t);

/*******************************************************************************
 * @brief   Request to Save all NVD Data in RAM to ExtEEPROM
 ******************************************************************************/
void NVD_RAM_TOTAL_EE_SaveReq (void);

/*******************************************************************************
 * @brief   Request to EE Stress Test
 ******************************************************************************/
void NVD_EE_StressTestReq (void);

/*******************************************************************************
 * @brief   Store one NVD Data Block in RAM to ExtEEPROM
 ******************************************************************************/
bool NVD_RAMBLOCK_to_ExtEEPROM (uint16_t);

/*******************************************************************************
 * @brief   Delayed Process for flagged NVD Data in RAM to ExtEEPROM in Tick-0
 ******************************************************************************/
uint32_t NVD_Process_RAMBLOCK_to_ExtEEPROM (uint32_t);

/*******************************************************************************
 * @brief   Stores only the NVD Data Blocks that are different in ExtEEPROM.
 *          This routnine is wxecuted over more calls.
 *          Returns true when all blocks have been updated.
 ******************************************************************************/
bool NVD_DataRetention_RAM_to_ExtEEPROM (void);

/*******************************************************************************
 * @brief   UseRETAorB, to find which one is the newer copy RET_A or RET_B
            based on the time they were being recorded
 ******************************************************************************/
uint8_t UseRETAorB(void);

/*******************************************************************************
 * @brief   Retreive NVD data on ExtEEPROM and copy to RAM
 ******************************************************************************/
bool NVD_ExtEEPROM_to_RAM (void);

/*******************************************************************************
 * @brief   CheckBrandNewEE is to detect brand new EE with 0xFF on first page
 ******************************************************************************/
bool CheckBrandNewEE (void);

/************************************************************************************************
 * @brief   ToManualResetEE is to detect if manual EE Reset is needed (by two buttons)
 ***********************************************************************************************/
bool ToManualResetEE (void);

/*******************************************************************************
 * @brief   AppInCommunicating to check if USB or BLE in communicating 
 ******************************************************************************/
bool AppInCommunicating(void);

/*******************************************************************************
 * @brief   CheckBTname to // Check if BTname on EE same to BLE chip, 
 *          otherwise assign valid EE-BTname to BLE chip
 ******************************************************************************/
uint8_t CheckBTname(void);

/*******************************************************************************
 * @brief   Initialize for Display_PLANGF
 ******************************************************************************/
void InitializePLAN(void);
void BrowsePLAN(void);

/*******************************************************************************
 * @brief   Collect all variables to update the LOG Data 
 ******************************************************************************/
void LOG_Data_Update(void);

/*******************************************************************************
 * @brief   Collect all variables to update the Profile Header, Data and Trailer
 ******************************************************************************/
void Profile_Data_Update(uint8_t n);

/*******************************************************************************
   @brief   NewDiveProfileAndLogRecorded(void) is for confirming 
      Profile and Log have been recorded after the new dive
      Wait until 10min:10sec for Scuba Dives and Gauge Dives
      Wait until 1min:10sec for Free Dives 
*******************************************************************************/
uint8_t NewDiveProfileAndLogRecorded(void);

/*******************************************************************************
 * @brief   Read My Info From ExFLASH      
 ******************************************************************************/
void ReadMyInfo(void);

/*******************************************************************************
 * @brief   Find TMT status according to Gas Num of current mode      
 ******************************************************************************/
NVD_status_t FindSCUBA_TMT_Status(NVD_DIVEMODE_t, uint8_t);

/*******************************************************************************

    Add new configurations only starting from R1005

*******************************************************************************/
void PatchR1005(void);

/*******************************************************************************

    Add new configurations only starting from R1006

*******************************************************************************/
void PatchR1006(void);

/*******************************************************************************

    Error Handle for EEPROM Error

*******************************************************************************/
void ErrHandle_EE(void);

/*******************************************************************************

    Error Handle for ExFLASH Error

*******************************************************************************/
void ErrHandle_FLASH(void);

/*******************************************************************************
 * @brief   GLOBAL Variables
*******************************************************************************/

extern Mfg_Calibration_t        MFG_Calib;
extern Device_Records_t         DEV_Rec;
extern User_Settings_t          USER_Set;
extern Scuba_Settings_t         SCUBA_Set;
extern TRIMIX_Settings_t        TRIMIX_Set;////////////////////////////
extern Free_Settings_t          FREE_Set;
extern Free_Records_t           FREE_Rec;/////////////////////////////////
extern FLASH_Map_t              FLASH_Map;

extern Profile_Header_t         Profile_Header;
extern Profile_Data_t           Profile_Data;
extern Profile_Trailer_t        Profile_Trailer;

extern RET_Data0_t     RETA_Data0;
extern RET_Data1_t     RETA_Data1;
extern RET_Data2_t     RETA_Data2;
extern RET_Data3_t     RETA_Data3;
extern RET_Data4_t     RETA_Data4;
extern RET_Data5_t     RETA_Data5;
extern RET_Data6_t     RETA_Data6;
extern RET_Data7_t     RETA_Data7;

extern RET_Data0_t     RETB_Data0;
extern RET_Data1_t     RETB_Data1;
extern RET_Data2_t     RETB_Data2;
extern RET_Data3_t     RETB_Data3;
extern RET_Data4_t     RETB_Data4;
extern RET_Data5_t     RETB_Data5;
extern RET_Data6_t     RETB_Data6;
extern RET_Data7_t     RETB_Data7;

extern EE_Block_t      EE_Block1;
extern EE_Block_t      EE_Block2;

extern LOG_Data_t Log_Data;
extern LOG_Data_t Log_Data_7[];
extern LOG_Chart_t Log_Chart;
extern LOG_Chart_t Log_Chart_7[];
// extern LOG_Data_t GUI_Log_Data[];

extern uint8_t MyInfoBuff[BLOCK_SIZE/INFO_DATA_SIZE][INFO_DATA_SIZE]; // RAM For Reading MyInfo[SECTOR_SIZE/LOG_SIZE][LOG_SIZE];
//extern uint8_t *sInfoName, *sInfoAddr, *sInfoPhone, *sInfoEmail, *sInfoBlood, *sInfoContact;
#define  sInfoName      &MyInfoBuff[0][0]
#define  sInfoAddr      &MyInfoBuff[1][0]
#define  sInfoPhone     &MyInfoBuff[2][0]
#define  sInfoEmail     &MyInfoBuff[3][0]
#define  sInfoBlood     &MyInfoBuff[4][0]
#define  sInfoContact   &MyInfoBuff[5][0]

#define TLBG_Line_NumBar        16 //Number of bars
/*******************************************************************************
    A Readback CRC Check after EEPROM Write for 256 Bytes (a block)
    bool CompEE256( void *write_data, void *read_data ) 
*******************************************************************************/
bool CompEE256( void*, void* );

#endif //_L4X9_NVDATA_H_