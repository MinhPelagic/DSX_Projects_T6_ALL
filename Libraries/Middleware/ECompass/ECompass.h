/*******************************************************************************
 * @file        : ECompass.h
 * @brief       : Middleware for ECompass
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
   
#ifndef _ECOMPASS_H_
#define _ECOMPASS_H_

#define MAG_CAL_DURATION_SEC    (20L)
#define MAG_CAL_DURATION_MS     (1000L * MAG_CAL_DURATION_SEC)
#define MAG_CAL_INTERVAL_MS     (20L)

#define EC_BUF_SIZE             8

/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/

typedef struct
{
  // Raw EC Sensor Data
  int16_t AccX;
  int16_t AccY;
  int16_t AccZ;
  int16_t MagX;
  int16_t MagY;
  int16_t MagZ;
    
}EcRawData_struct_t;

typedef struct
{
  // Compensated EC Sensor Data
  int16_t AccX;
  int16_t AccY;
  int16_t AccZ;
  float MagX;
  float MagY;
  float MagZ;
}EcCompData_struct_t;

typedef struct
{
  bool ReqOn;
  bool ReqOff;
  bool ReqCal;
  bool CalGood;

  int16_t Heading;                      /* Current Heading */
  int16_t Roll;                         /* Current Roll Angle */
  int16_t Pitch;                        /* Current Pitch */
  int16_t AvgHeading;                   /* Average Heading */
  int16_t HeadingBuf[EC_BUF_SIZE];      /* Heading Buffer */ 
  
  int16_t RefHeadingSet;                /* Reference Heading Set */
  int16_t RevHeadingSet;                /* Reverse Heading Set */
  
  int8_t HeadingBufIdx;                 /* Heading Buffer index */ 
  
  // EC Status register
  uint8_t Status;
    
}EcData_struct_t;

enum COMPASS_Status
{
  COMPASS_OFF = 0,
  COMPASS_ON,
  COMPASS_CALIBRATING,  
};

typedef enum Timer_Status
{
  TIMER_Reset = 0,
  TIMER_Pause,
  TIMER_Run,
}Timer_t;

typedef struct
{
  uint32_t Run_S;              // Run time of timer
  uint32_t TimeStamp_S;        // Time stamp from monotonic_clock
  Timer_t Status;               // 0: Reset;  1: Pause;  2: Run
  bool RunReq;                  
  bool PauseReq;
  bool ResetReq;
}TIMER_t;

/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
extern EcRawData_struct_t EcRawData;
extern EcData_struct_t EcData;
extern TIMER_t Chrono;
extern TIMER_t Runtime;

extern MMC_Input_t MMC_Input;
extern MMC_Output_t MMC_Output;

extern MEC_input_t MEC_input;
extern MEC_output_t MEC_output;

extern float RawMagBufferX[2048];
extern float RawMagBufferY[2048];
extern float RawMagBufferZ[2048];
extern float RawAccBufferX[2048];
extern float RawAccBufferY[2048];
extern float RawAccBufferZ[2048];

extern uint32_t RawMagBufferIdx;


extern float RawMagMax[3];
extern float RawMagMin[3];
extern float RawD[3];

extern float CalMagMax[3];
extern float CalMagMin[3];
extern float CalD[3];

extern float CalDiaAvg;
extern float CalMagField;

/******************************************************************************
 * @brief   Activate Ecompass.
 *
 * @note    
 ******************************************************************************/
void Ec_On(void);

/******************************************************************************
 * @brief   Switch off Ecompass.
 *
 * @note    
 ******************************************************************************/
void Ec_Off(void);

/******************************************************************************
 * @brief   Start Ecompass Calibration
 *
 * @note    
 ******************************************************************************/
void Ec_Calibrate(void);

/******************************************************************************
 * @brief   Acquire Calibration Samples.
 *
 * @note    
 ******************************************************************************/
bool EcAcquireSamples (void);
   
/******************************************************************************
 * @brief   Handle Ecompass.
 *
 * @note    
 ******************************************************************************/
bool EcHandler (void);

/******************************************************************************
 * @brief   Calculate Heading
 *
 * @note    
 ******************************************************************************/
void Ec_calc (int16_t Ax, int16_t Ay, int16_t Az, int32_t Mx, int32_t My, int32_t Mz);

/******************************************************************************
 * @brief   Calculate Chrono in Compass
 *
 * @note    
 ******************************************************************************/
void Chrono_Manager(void);

/******************************************************************************
 * @brief   Calculate Runtime in GSM and Gauge Modes
 *
 * @note    
 ******************************************************************************/
void Runtime_Manager(void);

/******************************************************************************
 * @brief   Provide Low Pass Filter for Compass Header direction
 *
 * @note    
 ******************************************************************************/
int16_t SmoothingCompassDeg(int16_t Deg);

/******************************************************************************
 * @brief   Degree Alignment Correction for Eastern and Southern Directions
 *
 * @note    
 ******************************************************************************/
int16_t DirectionCorrection(int16_t Deg);
#endif
