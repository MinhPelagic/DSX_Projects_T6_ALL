/*******************************************************************************
 * @file        : Ambiental.h
 * @brief       : Middleware for Ambiental
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
   
#ifndef _AMBIENTAL_H_
#define _AMBIENTAL_H_


/*******************************************************************************
 * @brief   Defines
 ******************************************************************************/

/*******************************************************************************

    Anthony's Compensation Equation: DepthFT += (DepthFT + 10.0) * 0.01;

    Depth in Feet = DepthFT + [(DepthFT + 10.0) * 0.01];

    Depth in Feet = DepthFT + [(0.01 * DepthFT + 0.10)];

    Depth in Feet = DepthFT + 0.01 * DepthFT + 0.10;

    Depth in Feet = 1.01 * DepthFT + 0.10;

*******************************************************************************/

#define ANTHONY_OFFSET      0.10f             // DepthFT += (DepthFT + 10.0) * 0.01;  added on 2021/12/23 on Anthony's Request
#define HOANG_SLOPE         1.01f             // DepthFT += (DepthFT + 10.0) * 0.01;  added on 2021/12/23 on Anthony's Request

/* Pressure and Temprature sensor Update Time in seconds in Lp mode (PSM or Sleep) */
#define TP_LP_UPDATE_S          5
/* Pressure and Temprature sensor Update Time in seconds in no any active surface mode */
#define TP_ACT_UPDATE_S         1
/* Pressure and Temprature sensor Update Time in seconds in Dive/AfterDive mode */
#define TP_DIVE_UPDATE_S        1


/* Altitude Automatic Water Type Switch Pressure */
/* Convertion is based on P(ata) = 0.9877^(m/100); P(bar) = [0.9877^(m/100)]*1,01325.*/
#define ALTITUDE_PRESSURE_SWITCH_MBAR   976.00f     // @ 1000 ft / 304 meters

/* Water Detect Depth in mt */
#define WATER_ENTRANCE_DETECT_DEPTH_M   0.3048f

/* After Dive Surface Interval */
/* After this interval of emersion the state machine goes back to normal surface mode */
#define AFTER_DIVE_SURF_INTERVAL_S      (10L*60L)   
#define AFTER_FREE_SURF_INTERVAL_S      (1L*60L)   

/* New Day Surface Interval TimeOut */
/* After this timeout the system will go to a stanby state AMB_DIVEINFO_NEWDAY_SLEEP */
#define NEWDAY_TIMEOUT                  (24L*60L*60L)
#define NEWDAY_NODIVE_TIMEOUT           (2L*60L*60L)
   
/* Short Term Queque Sizes */
#define PRESS_SHORTQUEQUE_SIZE          8
#define TEMP_SHORTQUEQUE_SIZE           4

/* Maximum Atmospheric pressure in mbar @ Sea Level, LAT 45°, 0°C */
#define MAX_SEALEVEL_ATMPRESSURE        1080.00f//1013.25f
   
/* Tollerated Surface Pressure Shift in mbar */
#define SURFPRESS_TOL_SHIFT             6.00f
 
/* Barometric Long Term Queque Size */
#define BAROMETRIC_LONGQUEQUE_SIZE      48

/* Temperature Long Term Queque Size */
#define TEMPERATURE_LONGQUEQUE_SIZE     48
   
/* Demo Depth Up in ft/sec in Shift */
#define DEMO_DEPTH_SHIFT_UP             1.00f
   
/* Demo Depth Down in ft/sec in Shift */
#define DEMO_DEPTH_SHIFT_DOWN           5.00f
   
/* Demo Depth Up in ft/sec */
#define DEMO_DEPTH_UP                   0.50f
   
/* Demo Depth Down in ft/sec */  
#define DEMO_DEPTH_DOWN                 1.00f
 
/* PHANTOM_SEC the time (sec) for checking phamtom dive or not */   
#define PHANTOM_SEC                     5   

/* Definitions for altitude calculation pressures at differente altitudes expressed in mbar*1000*/
/* Calcuated with P(bar) = [0.9877^(m/100)]*1.01325 */
#define SEALEVEL_REF_PRESSURE	1013250L        // sea level atmospheric pressure
#define ALTITUDE_REF_L05         952449L        // atmospheric pressure at 500m
#define ALTITUDE_REF_L10         895297L        // atmospheric pressure at 1000m
#define ALTITUDE_REF_L15         841574L        // atmospheric pressure at 1500m
#define ALTITUDE_REF_L20         791075L        // atmospheric pressure at 2000m
#define ALTITUDE_REF_L25         743606L        // atmospheric pressure at 2500m
#define ALTITUDE_REF_L30         698986L        // atmospheric pressure at 3000m
#define ALTITUDE_REF_L35         657043L        // atmospheric pressure at 3500m
#define ALTITUDE_REF_L40         617616L        // atmospheric pressure at 4000m
#define ALTITUDE_REF_L45         580556L        // atmospheric pressure at 4500m
#define ALTITUDE_REF_L50         545719L        // atmospheric pressure at 5000m
#define ALTITUDE_REF_L55         512973L        // atmospheric pressure at 5500m
#define ALTITUDE_REF_L60         482192L        // atmospheric pressure at 6000m
#define ALTITUDE_REF_L65         453258L        // atmospheric pressure at 6500m
#define ALTITUDE_REF_L70         426060L        // atmospheric pressure at 7000m
#define ALTITUDE_REF_L75         400494L        // atmospheric pressure at 7500m
#define ALTITUDE_REF_L80         376462L        // atmospheric pressure at 8000m
#define ALTITUDE_REF_L85         353872L        // atmospheric pressure at 8500m
#define ALTITUDE_REF_L90         332638L        // atmospheric pressure at 9000m
#define ALTITUDE_REF_L95         312678L        // atmospheric pressure at 9500m


/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/

typedef struct
{
  float InstantPressure_mbar;                                   /* Instant Pressure Expressed in mbar */
  float AveragePressure_mbar;                                   /* Is the Average Pressure on the PressureShortTermQueque; Expressed in mbar */
  
  float InstantPressure_inHg;                                    /* Instant Pressure Expressed in inHg */
  float AveragePressure_inHg;                                    /* Is the Average Pressure on the PressureShortTermQueque; Expressed in inHg */
    
  float PressureShortTermQueque[PRESS_SHORTQUEQUE_SIZE];        /* Short Term Queque hold data for average calculations; data are in mbar */
  uint8_t PressureShortTermQuequeIdx;                           /* Short Term Queque is the index of the most recent stored value */
    
  float InstantTemperature_C;                                   /* Instant Temperature Expressed in �C */
  float AverageTemperature_C;                                   /* Is the Average Temperature on the TemperatureShortTermQueque; Expressed in �C */
 
  float InstantTemperature_F;                                   /* Instant Temperature Expressed in �F */
  float AverageTemperature_F;                                   /* Is the Average Temperature on the TemperatureShortTermQueque; Expressed in �F */
  
  float TemperatureShortTermQueque[TEMP_SHORTQUEQUE_SIZE];      /* Short Term Queque hold data for average calculations; data are in �C*/
  uint8_t TemperatureShortTermQuequeIdx;                        /* Short Term Queque is the index of the most recent stored value */
    
  int32_t UpdateTimeStamp;                                      /* System MonotonicClock structure upodate time */ 
} TP_Info_struct_t;


typedef enum 
{
  AMB_DIVEINFO_NEWDAY_SLEEP = 0x00,     // 24 hours after Surface Mode waiting for User Activity
  AMB_DIVEINFO_NEWDAY,                  // on POR or after any user action
  AMB_DIVEINFO_SURF,                    // 10 minutes after dive ends 
  AMB_DIVEINFO_DIVE,                    // during the diving
  AMB_DIVEINFO_10HDIVE,                 // during the 10 Hour diving
  AMB_DIVEINFO_AFTERDIVE,               // from 0 to 10 minutes after dive ends
}AMB_DIVEINFO_t;

typedef enum
{
    MODE_SWITCH_NONE    = 0,  
    MODE_SWITCH_CC2BO,
    MODE_SWITCH_BO2CC,
    MODE_SWITCH_MAX,
} MODE_SWITCH_t;

typedef struct
{
  float SurfacePressure_mbar;           /* Surface Pressure Expressed in mbar */
  float SurfacePressure_inHg;           /* Surface Pressure Expressed in inHg */
  
  uint16_t Altitude_m;                  /* Barometric Altitude in meters */
  uint16_t Altitude_ft;                 /* Barometric Altitude in feets */
  uint8_t AltitudeLevel;                /* Barometric altitude Level */
  
  float WaterPressure_mbar;             /* Water Pressure expressed in mbar; is relative Absolut pressure minus Surface Pressure */ 
  float WaterPressure_inHg;             /* Water Pressure expressed in inHg; is relative Absolut pressure minus Surface Pressure */ 
  
  float WaterDepth_m;                   /* Water Depth expressed in m; calculation is based on salinity level input */ 
  float WaterDepth_ft;                  /* Water Depth expressed in ft; calculation is based on salinity level input */ 
    
  float AvgWaterDepth_m;                /* Average Water Depth expressed in m of entire current Dive; calculation is based on salinity level input */ 
  float AvgWaterDepth_ft;               /* Average Water Depth expressed in ft of entire current Dive; calculation is based on salinity level input */ 
  
  float MaxWaterDepth_m;                /* Max Water Depth expressed in m of entire current Dive; calculation is based on salinity level input */ 
  float MaxWaterDepth_ft;               /* Max Water Depth expressed in ft of entire current Dive; calculation is based on salinity level input */ 
 
  float PrevMaxWaterDepth_m;            /* Max Water Depth expressed in m of entire previouse Dive; calculation is based on salinity level input */ 
  float PrevMaxWaterDepth_ft;           /* Max Water Depth expressed in ft of entire previouse Dive; calculation is based on salinity level input */ 
  
  float WaterTemperature_C;             /* Water Temperature expressed in C */ 
  float WaterTemperature_F;             /* Water Temperature expressed in F */ 
  
  float MaxTemp_C;                      /* Max Temperature expressed in C of entire current Dive */ 
  float MaxTemp_F;                      /* Max Temperature expressed in F of entire current Dive  */ 
  
  float MinTemp_C;                      /* Min Temperature expressed in C of entire current Dive */ 
  float MinTemp_F;                      /* Min Temperature expressed in F of entire current Dive  */ 
  
  float AvgTemp_C;                      /* Average Temperature expressed in C of entire current Dive */
  float AvgTemp_F;                      /* Average Temperature expressed in F of entire current Dive */
  
  AMB_DIVEINFO_t Status;                /* Current Status */
  AMB_DIVEINFO_t PreStatus;             /* Previous Status in last second */

  bool FirstStartDetected;              /* Used to check for phantome dives */
  bool WaterEntranceDetected;           /* True if depth higer than WATER_ENTRANCE_DETECT_DEPTH_M */
  bool Dive10hDetected;                 /* True if a dive longer than 10h occurs */
  
  bool PhantomCheckDone;                /* The flag to confirm NOT a phantom dive */
  bool ResetDiveDepthAvg;               /* The flag to reset the Depth of current dive. Normally false */
  uint32_t NoPhantomCtr;                 /* The counter to check if a phantom dive or NOT*/
    
  int32_t StartDiveTime_s;              /* MonotonicClock TimeStamp of Dive Start */
  int32_t DiveTime_s;                   /* Dive Time in seconds of current Dive*/
  int32_t PrevDiveTime_s;               /* Dive Time in seconds of previouse Dive*/
  int32_t PartialDiveTime_s;            /* Dive Time in seconds of this partial Dive*/
  
  int32_t StartSurfTime_s;              /* MonotonicClock TimeStamp of Surface Start */
  int32_t SurfTime_s;                   /* Surface Time in seconds, is reset each time diver emerges, of current Dive */
  int32_t PrevSurfTime_s;               /* Surface Time in seconds, of current Dive */
  int32_t AfterDiveTime_s;              /* After-Dive Time in seconds, of the current Dive */
  int32_t UpdateTimeStamp;              /* System MonotonicClock structure upodate time */
  uint16_t TotalDiveTime;               /* TotalDiveTime = UpdateTimeStamp - StartDiveTime_s */
  int16_t AfterDiveSec[AfterDiveGapID_Max];             /* The Gap Time (in seconds) between water entries of the same dive */
  uint8_t AfterDiveGapID;               /* The sequential id of Gap Time of dive time(s) if re-entry occurs */
  MODE_SWITCH_t ModeSwitchFlag;         /* The flag to indicate mode has been changed moments agao */
} Dive_Info_struct_t;

typedef struct
{
  float BarometricLongTermQueque[BAROMETRIC_LONGQUEQUE_SIZE];   /* Barometric Long Term Queque; data are in mbar */
  uint8_t BarometricLongTermQuequeIdx;                          /* Barometric Long Term Queque is the index of the most recent stored value */
  
  float TemperatureLongTermQueque[TEMPERATURE_LONGQUEQUE_SIZE]; /* Temperature Long Term Queque; data are in �C) */
  uint8_t TemperatureLongTermQuequeIdx;                         /* Temperature Long Term Queque is the index of the most recent stored value */
  
  int32_t UpdateTimeStamp;                                      /* System MonotonicClock structure upodate time */ 
    
} Weather_Info_struct_t;

typedef enum
{
  ALT_LVL_0 = 0,
  ALT_LVL_1,
  ALT_LVL_2,
  ALT_LVL_3,
  ALT_LVL_4,
  ALT_LVL_5,
  ALT_LVL_6,
  ALT_LVL_7,
  ALT_OVER_LIMIT,
} AltitudeLevel_t;

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/

/* Ambiental Information Data */
extern TP_Info_struct_t TP_Info;
extern Dive_Info_struct_t Dive_Info;
extern Weather_Info_struct_t Weahter_Info;

extern int32_t LastAmbientUpdate_s;
extern int32_t LastAutoZeroUpdate_s;

/******************************************************************************
 * @brief   Update Temperature and Pressure Structure.
 *
 * @note    
 ******************************************************************************/
void UpdateTPInfo(TP_Info_struct_t *Data, float Temp_C, float Press_mbar);

/******************************************************************************
 * @brief   Update Dive Info Structure.
 *
 * @note    Surface PRessure is updated only if WetContact is Dry
 ******************************************************************************/
void UpdateDiveInfo(Dive_Info_struct_t *Data, float Press_mbar, float Temp_C, User_Settings_t SystemData);

/******************************************************************************
 * @brief   Reset Weather Info Structure.
 *
 * @note    
 ******************************************************************************/
void ResetWeatherInfo(Weather_Info_struct_t *Data, float Temp_F, float Press_mbar);

/******************************************************************************
 * @brief   Update Weather Info Structure.
 *
 * @note    
 ******************************************************************************/
void UpdateWeatherInfo(Weather_Info_struct_t *Data, float Temp_F, float Press_mbar);

/******************************************************************************
 * @brief   Ambiental Library Manager
 *
 * @note    
 ******************************************************************************/
void AmbientalManager( void );

/******************************************************************************
 * @brief   bool ConditionsOKtoDive(void)
 *
 * @note    Checking All Conditions too see if OK to Dive
 ******************************************************************************/
bool ConditionsOKtoDive(void);

/******************************************************************************
 * @brief   void CalcTotalAvgDepth( Dive_Info_struct_t *Data, Device_Records_t *Dev, float DepthSum )
 *
 * @note    Calculate Device's Average Dive Depth in its Life Time
 ******************************************************************************/
void CalcTotalAvgDepth( Dive_Info_struct_t *Data, Device_Records_t *Dev, float DepthSum );

#endif //_AMBIENTAL_H_