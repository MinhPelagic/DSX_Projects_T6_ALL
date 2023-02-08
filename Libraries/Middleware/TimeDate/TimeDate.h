/*******************************************************************************
 * @file        : TimeDate.h
 * @brief       : Middleware for Time and Date
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
   
#ifndef _TIMEDATE_H_
#define _TIMEDATE_H_

/*******************************************************************************
 * @brief   Constants
 ******************************************************************************/

/* Day in each month */
static const int8_t DaysPerMonth[12] = 
{
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/

/* System Time and Date structure */
typedef struct
{
  uint8_t Hour;                 // in Bin format
  uint8_t Minute;               // in Bin format
  uint8_t Second;               // in Bin format        
  uint8_t Day;                  // in Bin format
  uint8_t WeekDay;              // 1: Monday; 7: Sunday
  uint8_t Month;                // in Bin format
  uint8_t Year;                 // in Bin format
  uint8_t res;                  // reserved
} SystemTimeDate_t;


/* System Pelagic Time and Date global struct */
extern SystemTimeDate_t SysTimeDatePST;
extern SystemTimeDate_t SysTimeDateHOME;

/******************************************************************************
 * @brief       Converts a SystemTimeDate_t structure to the int32_t second 
 *              representation since Epoch
 *
 * @note        The function will consider the  00:00:00 PST, January 1, 2000 
 *              as the "Epoch" time
 *              
 ******************************************************************************/
uint32_t TimeToEpoch(SystemTimeDate_t Time);

/******************************************************************************
 * @brief       Converts a int32_t second time representation since Epoch 
 *              expressed reltive to a SystemTimeDate_t structure relative 
 *              to the selected timezone.
 *
 * @note        
 *              
 ******************************************************************************/
void EpochToTime(SystemTimeDate_t *Time, uint32_t SecEpoch, const int8_t HourDiff, const int8_t MinDiff);


/******************************************************************************
 * @brief       Converts the PST time struct into the Hoe or away time with 
 *              specified hour and minute offset
 *
 * @note        
 *              
 ******************************************************************************/
SystemTimeDate_t GetDiffTime(const int8_t HourDiff, const int8_t MinDiff);


/******************************************************************************
 * @brief       Set PST time: Hours 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_HR(int8_t hours);

/******************************************************************************
 * @brief       Set PST time: Minutes 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_MIN(int8_t minutes);

/******************************************************************************
 * @brief       Set PST time: Seconds 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_SEC(int8_t seconds);

/******************************************************************************
 * @brief       Set PST time: Days 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_DAYS(int8_t days);

/******************************************************************************
 * @brief       Set PST time: Months 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_MONTHS(int8_t months);

/******************************************************************************
 * @brief       Set PST time: Years 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_YEARS(int8_t years);

#endif //_TIMEDATE_H_