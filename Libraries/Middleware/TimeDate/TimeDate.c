/*******************************************************************************
 * @file        : TimeDate.c
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
#include "L4X9_includes.h"

#ifdef _TIMEDATE_H_

/* System Pelagic Time and Date global struct */
SystemTimeDate_t SysTimeDatePST;
SystemTimeDate_t SysTimeDateHOME;

/******************************************************************************
 * @brief       Converts a SystemTimeDate_t structure to the int32_t second 
 *              representation since Epoch
 *
 * @note        The function will consider the  00:00:00 PST, January 1, 2000 
 *              as the "Epoch" time
 *              
 ******************************************************************************/

uint32_t TimeToEpoch(SystemTimeDate_t Time)
{
  int8_t  sec  = (int8_t)Time.Second;          /* seconds after the minute:  0..59   */
  int8_t  min  = (int8_t)Time.Minute;          /* minutes after the hour:    0..59   */
  int8_t  hour = (int8_t)Time.Hour;            /* hours past midnight:       0..23   */
  int8_t  mday = (int8_t)Time.Day;             /* day of the month:          1..31   */
  int8_t  mon  = (int8_t)Time.Month;           /* months since January:      1..12   */
  int16_t year = ((int16_t)Time.Year)+2000;    /* years (> Epoch year):      2000..  */

  uint32_t days;
  int16_t year_diff;
        
  /* Determine the elapsed UTC days from the "Epoch".*/
  year_diff = year - 2000;
  days = (year_diff * 365) + (year_diff / 4) + 1;
    
  for (int8_t i = 0; i < (mon-1); i++) 
    days += (int32_t)DaysPerMonth[i];
   
  if( (mon > 2) && (year & 0x0003) )
  {
  }
  else if( (mon <= 2) && !(year & 0x0003) )
    days--;

  days += (mday - 1);

  /* Determine the elapsed PST seconds from the "Epoch".*/
  return (days*86400L + (uint32_t)hour*3600L + (uint32_t)min*60L + (uint32_t)sec);
}

/******************************************************************************
 * @brief       Converts a int32_t second time representation since Epoch 
 *              expressed reltive to a SystemTimeDate_t structure relative 
 *              to the selected timezone.
 *
 * @note        
 *              
 ******************************************************************************/
void EpochToTime(SystemTimeDate_t *Time, uint32_t SecEpoch, const int8_t HourDiff, const int8_t MinDiff)
{
  /* Determine the local time in seconds */
  SecEpoch += ((uint32_t)HourDiff)*3600L + ((uint32_t)MinDiff)*60L;
  
  int8_t y_offset, days;

  /* Determine the time seconds and total number of minutes */
  Time->Second = (uint8_t)(SecEpoch%60);

  /* Determine the time minutes and total number of hours */
  Time->Minute = (uint8_t)((SecEpoch/60)%60);

  /* Determine the time hours and total number of days */
  Time->Hour = (uint8_t)((SecEpoch/3600)%24);
		
  uint32_t tmp_days = ((SecEpoch/3600)/24);
        
  /* Determine the day of the week */
  Time->WeekDay = (uint8_t)((tmp_days+6)%7); //adjust to RTC module format

  /* Now we have to consider how many days are in a "4 years" interval */
  /* time: 365*4+1 => 1461 (as until 2100 only years/4 are leap years).*/
  /* NOTE: timediv32.quot (total number of days) is < 65536.           */
  uint32_t remaining_days = tmp_days%1461;
  uint32_t included_days = tmp_days/1461;

  /* included_days -> How many "4 years" segments passed since 2008. */
  /* remaining_days-> How many days are in the last "4 year" segment. */
  /* Note: we have 366+365*3-1 days max (1st year is the leap year).  */
  y_offset = 0;
  if (remaining_days >= 366) 
  {
    remaining_days -= 366;
    ++y_offset;
        
    while (remaining_days >= 365) 
    {
      remaining_days -= 365;
      ++y_offset;
    }
  }
  Time->Year = (uint8_t)(((uint16_t)(2000 + ((int16_t)(included_days)*4) + (int16_t)y_offset))-2000);

  /* Now if y_offset == 0 the year is a leap year; also */
  /* remaining_days holds the days in the current year.*/
  /* So, calculate the month and the day of the month. */
  for (int8_t i = 0; i < 12; i++)
  {
    days = DaysPerMonth[i];
    if (i == 1 && y_offset == 0)
      ++days;
    if (remaining_days < (uint32_t)days) 
    {
      Time->Day = (uint8_t)(remaining_days) + 1;
      Time->Month = (uint8_t)(i+1);
      break; //exit loop
    }
    remaining_days -= (uint32_t)days;
  }
}

/******************************************************************************
 * @brief       Converts the PST time struct into the Hoe or away time with 
 *              specified hour and minute offset
 *
 * @note        
 *              
 ******************************************************************************/
SystemTimeDate_t GetDiffTime(const int8_t HourDiff, const int8_t MinDiff)
{
  int32_t SecSinceEpoch = TimeToEpoch(SysTimeDatePST);
  
  SystemTimeDate_t DiffTime;
  
  EpochToTime(&DiffTime, SecSinceEpoch, HourDiff, MinDiff);
  
  return DiffTime;  
}

/******************************************************************************
 * @brief       Set PST time: Hours 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_HR(int8_t hours)
{
  if (hours > 23)
    hours = 23;
  if (hours < -23)
    hours = - 23;
    
  int32_t SecSinceEpoch = TimeToEpoch(SysTimeDatePST);
  
  SecSinceEpoch += ((int32_t)hours)*60L*60L;

  // Increasing or decreasing hours the Day will remain the same.
  if( ((int8_t)SysTimeDatePST.Hour + hours > 23) && (hours > 0) )
    SecSinceEpoch = SecSinceEpoch - (60L*60L*24L);
  else if( ((int8_t)SysTimeDatePST.Hour + hours < 0) && (hours < 0) )
    SecSinceEpoch = SecSinceEpoch + (60L*60L*24L);
  
  // Reset Seconds

    
  SystemTimeDate_t NewTime;
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
}

/******************************************************************************
 * @brief       Set PST time: Minutes 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_MIN(int8_t minutes)
{
  if (minutes > 59)
    minutes = 59;
  if (minutes < -59)
    minutes = - 59;
      
  int32_t SecSinceEpoch = TimeToEpoch(SysTimeDatePST);
  
  SecSinceEpoch += ((int32_t)minutes)*60L;

  // Increasing or decreasing hours the Hour will remain the same.
  if( ((int8_t)SysTimeDatePST.Minute + minutes > 59) && (minutes > 0) )
    SecSinceEpoch = SecSinceEpoch - (60L*60L*1L);
  else   if( ((int8_t)SysTimeDatePST.Minute + minutes < 0) && (minutes < 0) )
    SecSinceEpoch = SecSinceEpoch + (60L*60L*1L);
  
  // Reset Seconds

  SystemTimeDate_t NewTime;
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
}

/******************************************************************************
 * @brief       Set PST time: Seconds 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_SEC(int8_t seconds)
{
  if (seconds > 59)
    seconds = 59;
  if (seconds < -59)
    seconds = - 59;
    
  int32_t SecSinceEpoch = TimeToEpoch(SysTimeDatePST);
  
  SecSinceEpoch += ((int32_t)seconds);
  
  // Increasing or decreasing Seconds the Minute will remain the same.
  if( ((int8_t)SysTimeDatePST.Second + seconds > 59) && (seconds > 0) )
    SecSinceEpoch = SecSinceEpoch - (60L*1L);
  else   if( ((int8_t)SysTimeDatePST.Second + seconds < 0) && (seconds < 0) )
    SecSinceEpoch = SecSinceEpoch + (60L*1L);
  
  SystemTimeDate_t NewTime;
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
}

/******************************************************************************
 * @brief       Set PST time: Days 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_DAYS(int8_t days)
{
  uint8_t DaysOfMon;
  
  SystemTimeDate_t NewTime = SysTimeDatePST;
  
  switch(NewTime.Month)
  {
      case 1: 
      case 3: 
      case 5:  
      case 7:
      case 8:
      case 10:
      case 12:
          DaysOfMon = 31;
        break;
    
      case 4: 
      case 6:  
      case 9:
      case 11:
          DaysOfMon = 30;
        break;
        
      case 2: 
          if((NewTime.Year%4)==0)
            DaysOfMon = 29;     // leap years
          else
            DaysOfMon = 28;     // normal years
        break;
  }
  
  if (days > DaysOfMon)
    days = DaysOfMon;
  if (days < -DaysOfMon)
    days = - DaysOfMon;
  
  // Day change does NOT effect on Month nor Year, (stays at the same Mon and Year)
  if ((days < 0) && ((int8_t)NewTime.Day + days == 0))
    NewTime.Day = DaysOfMon;
  else if ((days < 0) && ((int8_t)NewTime.Day + days < 0))
    NewTime.Day = (uint8_t)(DaysOfMon + ((int8_t)NewTime.Day + days + 1));
  else if ((days > 0) && (NewTime.Day + days > DaysOfMon))
    NewTime.Day = NewTime.Day + (uint8_t)days - DaysOfMon;
  else
    NewTime.Day += (uint8_t)days;

  int32_t SecSinceEpoch = TimeToEpoch(NewTime);
  
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
  
}

/******************************************************************************
 * @brief       Set PST time: Months 
 *
 * @note        
 *              
 ******************************************************************************/
void SetPstTime_MONTHS(int8_t months)
{
  if (months > 12)
    months = 12;
  if (months < -12)
    months = - 12;
    
  SystemTimeDate_t NewTime = SysTimeDatePST;
  
  // Month change does NOT effect on Day nor Year, (stays at the same Day and Year)
  if ((months < 0) && ((int8_t)NewTime.Month + months == 0))
    NewTime.Month = 12;
  else if ((months < 0) && ((int8_t)NewTime.Month + months < 0))
    NewTime.Month = (uint8_t)(12 + ((int8_t)NewTime.Month + months + 1));
  else if ((months > 0) && (NewTime.Month + months > 12))
    NewTime.Month = NewTime.Month + (uint8_t)months - 12;
  else
    NewTime.Month += (uint8_t)months;
  
  int32_t SecSinceEpoch = TimeToEpoch(NewTime);
  
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
}

/******************************************************************************
 * @brief       Set PST time: Years 
 *
 * @note        
 *              
 ******************************************************************************/

void SetPstTime_YEARS(int8_t years)
{
  
  SystemTimeDate_t NewTime;
  
  NewTime = SysTimeDatePST;	
  
  // Yaer change does NOT effect on Day nor Month, (stays at the same Day and Month)
  if ((years < 0) && ((int8_t)NewTime.Year + years == 19))
    NewTime.Year = 70;
  else if ((years < 0) && ((int8_t)NewTime.Year + years < 20))
    NewTime.Year = (uint8_t)(70 + ((int16_t)NewTime.Year + (int16_t)years + 1));
  else if ((years > 0) && (NewTime.Year + years > 70))
    NewTime.Year = NewTime.Year + (uint8_t)years - (70-20+1);
  else
    NewTime.Year += (uint8_t)years;
  
  uint32_t SecSinceEpoch = TimeToEpoch(NewTime);
  
  EpochToTime(&NewTime, SecSinceEpoch, 0, 0);
  
  L4X9_SetRtc (NewTime);
}


#endif
