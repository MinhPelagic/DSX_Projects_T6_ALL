/*******************************************************************************
 * @file        : ECompass.c
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
#include "L4X9_includes.h"

#ifdef _ECOMPASS_H_


/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
EcRawData_struct_t EcRawData;
EcData_struct_t EcData;

TIMER_t Chrono;
TIMER_t Runtime;

MMC_Input_t MMC_Input;
MMC_Output_t MMC_Output;

MEC_input_t MEC_input;
MEC_output_t MEC_output;

float RawMagBufferX[2048];
float RawMagBufferY[2048];
float RawMagBufferZ[2048];
float RawAccBufferX[2048];
float RawAccBufferY[2048];
float RawAccBufferZ[2048];

uint32_t RawMagBufferIdx = 0;

float RawMagMax[3];
float RawMagMin[3];
float RawD[3];
float CalMagMax[3];
float CalMagMin[3];
float CalD[3];
float CalDiaAvg;
float CalMagField;

char MotionMC_LoadCalFromNVM(unsigned short int datasize, unsigned int *data)
{
   return 1;
}

char MotionMC_SaveCalInNVM(unsigned short int datasize, unsigned int *data)
{
   return 1;
}

/******************************************************************************
 * @brief   Acquire Calibration Samples.
 *
 * @note    
 ******************************************************************************/
bool EcAcquireSamples (void)
{
  if(LSM303AGR_GetRawData_M(&EcRawData.MagX, &EcRawData.MagY, &EcRawData.MagZ))
  {
    LSM303AGR_GetRawData_A(&EcRawData.AccX, &EcRawData.AccY, &EcRawData.AccZ);
          
    RawMagBufferX[RawMagBufferIdx] = EcRawData.MagX;
    RawMagBufferY[RawMagBufferIdx] = EcRawData.MagY;
    RawMagBufferZ[RawMagBufferIdx] = EcRawData.MagZ;
    
    // LSM303AGR_GetRawData_A(&EcRawData.AccX, &EcRawData.AccY, &EcRawData.AccZ);
      
    RawAccBufferX[RawMagBufferIdx] = EcRawData.AccX;
    RawAccBufferY[RawMagBufferIdx] = EcRawData.AccY;
    RawAccBufferZ[RawMagBufferIdx] = EcRawData.AccZ;
    
    RawMagBufferIdx++;
    
    MMC_Input.Mag[0] = (float)(0.15f * EcRawData.MagX);
    MMC_Input.Mag[1] = (float)((-0.15f) * EcRawData.MagY);
    MMC_Input.Mag[2] = (float)(0.15f * EcRawData.MagZ);
    
    MotionMC_Update(&MMC_Input);        // Runs the magnetometer calibration algorithm
    
    MMC_Input.TimeStamp += MAG_CAL_INTERVAL_MS;
    
    MotionMC_GetCalParams(&MMC_Output);
    
    if(EcRawData.MagX > RawMagMax[0])
      RawMagMax[0] = (float)EcRawData.MagX;
    if(EcRawData.MagY > RawMagMax[1])
      RawMagMax[1] = (float)EcRawData.MagY;
    if(EcRawData.MagZ > RawMagMax[2])
      RawMagMax[2] = (float)EcRawData.MagZ;
    
    if(EcRawData.MagX < RawMagMin[0])
      RawMagMin[0] = (float)EcRawData.MagX;
    if(EcRawData.MagY < RawMagMin[1])
      RawMagMin[1] = (float)EcRawData.MagY;
    if(EcRawData.MagZ < RawMagMin[2])
      RawMagMin[2] = (float)EcRawData.MagZ;
    
    return true;
  }
  else
    return false;
}

/******************************************************************************
 * @brief   Compensate Magnetometer reading for Hard and Soft Iron interference
 *
 * @note    
 ******************************************************************************/
void Ec_CompensateAccMag(EcRawData_struct_t Input, MEC_input_t *Output, MMC_Output_t CalData)
{
  float mag_in[3];
  float mag_out[3];

  mag_in[0] = ((float)Input.MagX) * 0.15f;
  mag_in[1] = (-1.0f)*((float)Input.MagY) * 0.15f;
  mag_in[2] = ((float)Input.MagZ) * 0.15f;

  for (int i = 0; i < 3; i++)
  {
    mag_out[i] = 0.0f;
    for (int j = 0; j < 3; j++)
    {
      mag_out[i] += (mag_in[j] - CalData.HI_Bias[j]) * CalData.SF_Matrix[i][j];
    }

    //mag_out[i] += (mag_out[i] >= 0.0f) ? 0.5f : -0.5f;
  }

  float AccConv = (4.0f/256.0f);      
  Output->acc[0] = AccConv*(float)Input.AccX;
  Output->acc[1] = (-1.0f)*AccConv*(float)Input.AccY;
  Output->acc[2] = AccConv*(float)Input.AccZ;
  Output->mag[0] = mag_out[0]/50.0f;
  Output->mag[1] = mag_out[1]/50.0f;
  Output->mag[2] = mag_out[2]/50.0f;
  Output->deltatime_s = 0.125f;

}

/******************************************************************************
 * @brief   Activate Ecompass.
 *
 * @note    
 ******************************************************************************/
void Ec_On(void)
{
  EcData.ReqOn = true;
  EcData.ReqOff = false;
}

/******************************************************************************
 * @brief   Switch off Ecompass.
 *
 * @note    
 ******************************************************************************/
void Ec_Off(void)
{
  EcData.ReqOff = true;
  EcData.ReqOn = false;
}

/******************************************************************************
 * @brief   Start Ecompass Calibration
 *
 * @note    
 ******************************************************************************/
void Ec_Calibrate(void)
{
  EcData.ReqCal = true;
  EcData.CalGood = false;
}

/******************************************************************************
 * @brief   Handle Ecompass.
 *
 * @note    
 ******************************************************************************/
bool EcHandler (void)
{ 
 // static float fHeadingSum = 0; 
    
  if(SystemStatus.SystemPowerMode != SYS_ACTIVE)
     Ec_Off();
  
  switch(EcData.Status)
  {
    // Off
    case COMPASS_OFF:
      
      if(EcData.ReqOn)
      {
        // Enable Ec Module
        if(!LSM303AGR_On())
          return false;
        
        // if MMC_Output.CalQuality not good, then recall parameters from saved ones from DEV_Rec
        if(MMC_Output.CalQuality < MMC_CALQSTATUSGOOD)
          memcpy(&MMC_Output, &DEV_Rec.CompassCali, sizeof(MMC_Output_t));
            
        // If no calibration values are avaialble in EEPROM then notify bad calibration
        if(MMC_Output.CalQuality < MMC_CALQSTATUSOK)
          EcData.CalGood = false;
          
        EcData.Status = COMPASS_ON;
        
        EcData.ReqOn = false;
        
        float freq = 8.0f;
        MotionEC_Initialize(MEC_MCU_STM32, &freq);
        MotionEC_SetFrequency(8.0f);
        MotionEC_SetOrientationEnable(MEC_ENABLE);
      }
      break;
    
    // On
    case COMPASS_ON:
      
      if(EcData.ReqOff)
      {
        // Disable Ec Module
        if(!LSM303AGR_Off())
          return false;
        
        EcData.Status = COMPASS_OFF;
        
        EcData.ReqOff = false;
      }
      else if(EcData.ReqCal)
      {
        // Initialize Calibrarion Library
        MotionMC_Initialize(MAG_CAL_INTERVAL_MS, 1);    // needed before Compass Calibration
        char Ver = 0;
        MotionMC_GetLibVersion(&Ver);
        MMC_Input.TimeStamp = 0;
        
        MotionMC_GetCalParams(&MMC_Output);
        
        for(int i = 0; i <3; i++)
        {
          RawMagMax[i] = -100000.0f;
          RawMagMin[i] = 100000.0f;
        }
        
        RawMagBufferIdx = 0;
        
        // Enable Calibration mode on EC module
        if(!LSM303AGR_MagCalModeOn())
          return false;
        
        EcData.Status = COMPASS_CALIBRATING;
        
        EcData.ReqCal = false;
        
        EcData.CalGood = false;
      }
      else
      {
        // Read Raw Data
        LSM303AGR_GetRawData_A(&EcRawData.AccX, &EcRawData.AccY, &EcRawData.AccZ);
        LSM303AGR_GetRawData_M(&EcRawData.MagX, &EcRawData.MagY, &EcRawData.MagZ);

        Ec_CompensateAccMag(EcRawData, &MEC_input, MMC_Output);
        MotionEC_Run(&MEC_input, &MEC_output);
        EcData.Heading = (int16_t)MEC_output.euler[0];
        EcData.Pitch = (int16_t)MEC_output.euler[1];
        EcData.Roll = (int16_t)MEC_output.euler[2];
        EcData.AvgHeading = (int16_t)MEC_output.euler[0];
      }
      break;
    
    // Calibration
    case COMPASS_CALIBRATING:
      
      if(EcData.ReqOff)
      {
        // Disable Ec Module
        if(!LSM303AGR_Off())
          return false;
        
        EcData.Status = COMPASS_OFF;
        
        EcData.ReqOff = false;
        
        EcData.CalGood = false;
      }
      else
      {
        if(MMC_Input.TimeStamp >= MAG_CAL_DURATION_MS)
        {
          // Disable Calibration mode on EC module
          if(!LSM303AGR_MagCalModeOff())
            return false;

          // Get Calibration data from the ST Library
          MotionMC_GetCalParams(&MMC_Output);
          
          // Calculate Raw Sphere Diameters
          for(int i= 0; i < 3; i++)
            RawD[i] = RawMagMax[i] - RawMagMin[i];

          // Calculate Calibrated Sphere Diameters
          float mag_in[3];
          float mag_out[3];

          for (int i = 0; i < 3; i++)
            mag_in[i] = RawMagMax[i] * 0.15f;
          
          for (int i = 0; i < 3; i++)
          {
            mag_out[i] = 0.0f;
            for (int j = 0; j < 3; j++)
              mag_out[i] += (mag_in[j] - MMC_Output.HI_Bias[j]) * MMC_Output.SF_Matrix[i][j];
          }
          
          for (int i = 0; i < 3; i++)
          {
            CalMagMax[i] = mag_out[i]/0.15f;
            mag_in[i] = RawMagMin[i] * 0.15f;
          }
          
          for (int i = 0; i < 3; i++)
          {
            mag_out[i] = 0.0f;
            for (int j = 0; j < 3; j++)
              mag_out[i] += (mag_in[j] - MMC_Output.HI_Bias[j]) * MMC_Output.SF_Matrix[i][j];
          }
          
          for(int i= 0; i < 3; i++)
          {
            CalMagMin[i] = mag_out[i]/0.15f;
            CalD[i] = CalMagMax[i] - CalMagMin[i];
          }

          // Check ScaleFactor
          if(    (MMC_Output.SF_Matrix[0][0] >= 1.35)
              || (MMC_Output.SF_Matrix[0][0] <= 0.65)
              || (MMC_Output.SF_Matrix[1][1] >= 1.35)
              || (MMC_Output.SF_Matrix[1][1] <= 0.65)
              || (MMC_Output.SF_Matrix[2][2] >= 1.35)
              || (MMC_Output.SF_Matrix[2][2] <= 0.65)
                )
          {
            // If Scale factor is out of allowed range reduce quality indicator
            if(MMC_Output.CalQuality > MMC_CALQSTATUSUNKNOWN)
              MMC_Output.CalQuality--;
          }
          
          // Check Magnetic Field Modulus
          Ec_CompensateAccMag(EcRawData, &MEC_input, MMC_Output);
          CalMagField = (MEC_input.mag[0]*50.0f) *(MEC_input.mag[0]*50.0f) + (MEC_input.mag[1]*50.0f) *(MEC_input.mag[1]*50.0f) +(MEC_input.mag[2]*50.0f) *(MEC_input.mag[2]*50.0f) ;
          CalMagField = sqrt(CalMagField);
          if( (CalMagField < 25.0f) || (CalMagField > 65.0f) )
          {
            // If Magnetic Field Modulus is out of allowed range reduce quality indicator
            if(MMC_Output.CalQuality > MMC_CALQSTATUSUNKNOWN)
              MMC_Output.CalQuality--;
          }
          
          // Check Sphere Axes
          CalDiaAvg = (CalD[0] + CalD[1] + CalD[2])/3;
          if(   (CalD[0] > (CalDiaAvg*1.1f))
             || (CalD[0] < (CalDiaAvg*0.9f))
             || (CalD[1] > (CalDiaAvg*1.1f))
             || (CalD[1] < (CalDiaAvg*0.9f))
             || (CalD[2] > (CalDiaAvg*1.1f))
             || (CalD[2] < (CalDiaAvg*0.9f))
            )
          {
            // If Sphere Axes is out of allowed range reduce quality indicator
            if(MMC_Output.CalQuality > MMC_CALQSTATUSUNKNOWN)
              MMC_Output.CalQuality--;
          }
          
          if(MMC_Output.CalQuality > MMC_CALQSTATUSPOOR)
            EcData.CalGood = true;
          else
            EcData.CalGood = false;
          
          EcData.Status = COMPASS_ON;
          
          // DeInitialize Calibrarion Library
          MotionMC_Initialize(MAG_CAL_INTERVAL_MS, 0);

        }
        else
        {
          LSM303AGR_GetRawData_A(&EcRawData.AccX, &EcRawData.AccY, &EcRawData.AccZ);
          LSM303AGR_GetRawData_M(&EcRawData.MagX, &EcRawData.MagY, &EcRawData.MagZ);
        }
      }
      break;
  }
  
  return true;
}

/******************************************************************************
 * @brief   Calculate Chrono in Compass
 *
 * @note    
 ******************************************************************************/
void Chrono_Init(void)
{
  Chrono.Run_S = 0;
  Chrono.TimeStamp_S = 0;
  Chrono.Status = TIMER_Reset;
  Chrono.RunReq = false;                  
  Chrono.PauseReq = false;
  Chrono.ResetReq = false;
}
void Chrono_Manager(void)
{
  //----------------------------------------------------------------------------
  if(Chrono.ResetReq)
  {
    Chrono_Init();      
  }
  if(Chrono.PauseReq)
  { 
    if(Chrono.Status == TIMER_Reset)
    {
      Chrono_Init();    // stays at Reset, not change to Pause
    }
    else
    {
      Chrono.RunReq = false;                  
      Chrono.PauseReq = false;
      Chrono.ResetReq = false;
      Chrono.Status = TIMER_Pause;
    }
  }
  if(Chrono.RunReq)
  {    
    Chrono.RunReq = false;                  
    Chrono.PauseReq = false;
    Chrono.ResetReq = false;
    
    if(Chrono.Status == TIMER_Pause)
      Chrono.TimeStamp_S = MonotonicClock_s - Chrono.Run_S;
    else
      Chrono.TimeStamp_S = MonotonicClock_s;
    
    Chrono.Status = TIMER_Run;
  }
  //----------------------------------------------------------------------------
  if(Chrono.Status == TIMER_Run)
  {    
    Chrono.Run_S = MonotonicClock_s - Chrono.TimeStamp_S;
  }
  else if(Chrono.Status == TIMER_Pause)
  {    
    // Do Nothing here
  }
  else if(Chrono.Status == TIMER_Reset)
  {
    Chrono.TimeStamp_S = 0;
  }
  //----------------------------------------------------------------------------
}
/******************************************************************************
 * @brief   Calculate Runtime in GSM and Gauge Modes
 *
 * @note    
 ******************************************************************************/
void Runtime_Init(void)
{
  Runtime.Run_S = 0;
  Runtime.TimeStamp_S = 0;
  Runtime.Status = TIMER_Reset;
  Runtime.RunReq = false;                  
  Runtime.PauseReq = false;
  Runtime.ResetReq = false;
}
//------------------------------------------------------------------------------
void Runtime_Manager(void)
{
  //----------------------------------------------------------------------------
  if(Runtime.ResetReq)
  {
    Runtime_Init();      
  }
  if(Runtime.PauseReq)
  { 
    if(Runtime.Status == TIMER_Reset)
    {
      Runtime_Init();    // stays at Reset, not change to Pause
    }
    else
    {
      Runtime.RunReq = false;                  
      Runtime.PauseReq = false;
      Runtime.ResetReq = false;
      Runtime.Status = TIMER_Pause;
    }
  }
  if(Runtime.RunReq)
  {    
    Runtime.RunReq = false;                  
    Runtime.PauseReq = false;
    Runtime.ResetReq = false;
    
    if(Runtime.Status == TIMER_Pause)
      Runtime.TimeStamp_S = MonotonicClock_s - Runtime.Run_S;
    else
      Runtime.TimeStamp_S = MonotonicClock_s;
    
    Runtime.Status = TIMER_Run;
  }
  //----------------------------------------------------------------------------
  if(Runtime.Status == TIMER_Run)
  {    
    Runtime.Run_S = MonotonicClock_s - Runtime.TimeStamp_S;
  }
  else if(Runtime.Status == TIMER_Pause)
  {    
    // Do Nothing here
  }
  else if(Runtime.Status == TIMER_Reset)
  {
    Runtime.TimeStamp_S = 0;
  }
  //----------------------------------------------------------------------------
}

/******************************************************************************
 * @brief   Provide Low Pass Filter for Compass Header direction
 *
 * @note    
 ******************************************************************************/
int16_t SmoothingCompassDeg(int16_t Deg)
{
    #define DEG_ARRAY_SIZE 8
    static uint8_t DegArrayIdx = 0;
    static int16_t DegArray[DEG_ARRAY_SIZE];
    int16_t DegArraySum;
    int16_t MaxDeg, MinDeg;
      
    DegArray[DegArrayIdx] = Deg;
    
    DegArraySum = 0;                    // Sum reset to 0 before calculating the sum again 
    MaxDeg = 0;
    MinDeg = 360;
    
    for(uint8_t i = 0; i<DEG_ARRAY_SIZE; i++)
    {
        DegArraySum += DegArray[i];
        
        if(Deg > MaxDeg)
            MaxDeg = Deg;       // the Max of the all data currently sitting in DegArray
        
        if(Deg < MinDeg)
            MinDeg = Deg;       // the min of the all data currently sitting in DegArray
    }
    
    DegArrayIdx++;
    
    if(DegArrayIdx == DEG_ARRAY_SIZE)
        DegArrayIdx = 0;
    // do smoothing only for (1) narrow ranged data with small variance
    //                       (2) ranged from 10 deg to 350 deg, use raw data when Deg > 350 or Deg < 10
    
    if((MaxDeg < MinDeg + 6) && ((Deg <= 350) && (Deg >= 10)))
    {
        DegArraySum = DegArraySum >> 3;         // divided by 8 equivelent to (X >> 3)
        
        return DegArraySum;
    }
    else
    {
        return Deg;                             // use raw Deg
    }
}

/******************************************************************************
 * @brief   Degree Alignment Correction for Eastern and Southern Directions
 *
 * @note    
 ******************************************************************************/
int16_t DirectionCorrection(int16_t Deg)
{
    #define OLD_DEG1    30
    #define NEW_DEG1            30
    #define OLD_DEG2    53
    #define NEW_DEG2            60
    #define OLD_DEG3    75
    #define NEW_DEG3            90
    #define OLD_DEG4    96
    #define NEW_DEG4            120
    #define OLD_DEG5    120
    #define NEW_DEG5            150
    #define OLD_DEG6    151
    #define NEW_DEG6            180
    #define OLD_DEG7    190
    #define NEW_DEG7            210
    #define OLD_DEG8    230
    #define NEW_DEG8            240
    #define OLD_DEG9    265
    #define NEW_DEG9            270
    #define OLD_DEG10   297
    #define NEW_DEG10           300
    #define OLD_DEG11   330
    #define NEW_DEG11           330
 
    int16_t CorrectedDeg = 0;
    if((OLD_DEG1 < Deg) && ((Deg <= OLD_DEG2)))
    {
        CorrectedDeg = NEW_DEG1 + (int16_t)((float)(Deg - OLD_DEG1) * (float)(NEW_DEG2 - NEW_DEG1)/(float)(OLD_DEG2 - OLD_DEG1));
    }
    else if((OLD_DEG2 < Deg) && ((Deg <= OLD_DEG3)))
    {
        CorrectedDeg = NEW_DEG2 + (int16_t)((float)(Deg - OLD_DEG2) * (float)(NEW_DEG3 - NEW_DEG2)/(float)(OLD_DEG3 - OLD_DEG2));
    }
    else if((OLD_DEG3 < Deg) && ((Deg <= OLD_DEG4)))
    {
        CorrectedDeg = NEW_DEG3 + (int16_t)((float)(Deg - OLD_DEG3) * (float)(NEW_DEG4 - NEW_DEG3)/(float)(OLD_DEG4 - OLD_DEG3));
    }
    else if((OLD_DEG4 < Deg) && ((Deg <= OLD_DEG5)))
    {
        CorrectedDeg = NEW_DEG4 + (int16_t)((float)(Deg - OLD_DEG4) * (float)(NEW_DEG5 - NEW_DEG4)/(float)(OLD_DEG5 - OLD_DEG4));
    }
    else if((OLD_DEG5 < Deg) && ((Deg <= OLD_DEG6)))
    {
        CorrectedDeg = NEW_DEG5 + (int16_t)((float)(Deg - OLD_DEG5) * (float)(NEW_DEG6 - NEW_DEG5)/(float)(OLD_DEG6 - OLD_DEG5));
    }
    else if((OLD_DEG6 < Deg) && ((Deg <= OLD_DEG7)))
    {
        CorrectedDeg = NEW_DEG6 + (int16_t)((float)(Deg - OLD_DEG6) * (float)(NEW_DEG7 - NEW_DEG6)/(float)(OLD_DEG7 - OLD_DEG6));
    }
    else if((OLD_DEG7 < Deg) && ((Deg <= OLD_DEG8)))
    {
        CorrectedDeg = NEW_DEG7 + (int16_t)((float)(Deg - OLD_DEG7) * (float)(NEW_DEG8 - NEW_DEG7)/(float)(OLD_DEG8 - OLD_DEG7));
    }
    else if((OLD_DEG8 < Deg) && ((Deg <= OLD_DEG9)))
    {
        CorrectedDeg = NEW_DEG8 + (int16_t)((float)(Deg - OLD_DEG8) * (float)(NEW_DEG9 - NEW_DEG8)/(float)(OLD_DEG9 - OLD_DEG8));
    }
    else if((OLD_DEG9 < Deg) && ((Deg <= OLD_DEG10)))
    {
        CorrectedDeg = NEW_DEG9 + (int16_t)((float)(Deg - OLD_DEG9) * (float)(NEW_DEG10 - NEW_DEG9)/(float)(OLD_DEG10 - OLD_DEG9));
    }
    else if((OLD_DEG10 < Deg) && ((Deg <= OLD_DEG11)))
    {
        CorrectedDeg = NEW_DEG10 + (int16_t)((float)(Deg - OLD_DEG10) * (float)(NEW_DEG11 - NEW_DEG10)/(float)(OLD_DEG11 - OLD_DEG10));
    }
    else
    {
        CorrectedDeg = Deg;     // NO CORRECTIONs for (1) 0 <= Deg <= 30 (2) 300 <= Deg <= 359
    }
    return CorrectedDeg;
}
#endif