/*******************************************************************************
 * @file        : WayFinder.c
 * @brief       : Middleware for WayFinder          
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 ******************************************************************************/
#include "L4X9_includes.h"

#ifdef _WAYFINDER_H_


/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DMS format to DD format
 *
 * @note
 *      Input Coordinate is in DMS format, only degree must have sign.
 *      Output Coordinate is in DD format.
 *
 ******************************************************************************/
float WayFinder_Dms2Dd (float degree, float minutes, float seconds)
{
  float DD;
  if(degree < 0)
    DD = degree - minutes/60.000f - seconds/3600.0000f;
  else
    DD = degree + minutes/60.000f + seconds/3600.0000f;
  
  return DD;
}

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DD format to DMS format
 *
 * @note
 *      Input Coordinate is in DD format.
 *      Output Coordinate is in DMS format. Sign is only on the degree output.
 *
 ******************************************************************************/
void WayFinder_Dd2Dms (float DegreeInput, float *degree, float *minutes, float *seconds)
{
  double IntPart, FractPart;
  
  FractPart = modf((double)DegreeInput, &IntPart);
  
  *degree = (float)IntPart;
  
  FractPart *= (double)60.0f;
  FractPart = (float)modf((double)FractPart, &IntPart);
  
  *minutes = fabs((float)IntPart);
  
  FractPart *= (double)60.0000f;
  //FractPart = modf((double)FractPart, &IntPart);
  
  *seconds = fabs((float)FractPart);
}

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DMM format to DD format
 *
 * @note
 *      Input Coordinate is in DMM format, only degree must have sign.
 *      Output Coordinate is in DD format.
 *
 ******************************************************************************/
float WayFinder_Dmm2Dd (float degree, float minutes)
{
  float DD;
  if(degree < 0)
    DD = degree - minutes/60.000f;
  else
    DD = degree + minutes/60.000f;
  
  return DD;
}

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DD format to DMM format
 *
 * @note
 *      Input Coordinate is in DD format.
 *      Output Coordinate is in DMM format. Sign is only on the degree output.
 *
 ******************************************************************************/
void WayFinder_Dd2Dmm (float DegreeInput, float *degree, float *minutes)
{
  double IntPart, FractPart;
  
  FractPart = (float)modf((double)DegreeInput, &IntPart);
  
  *degree = (float)IntPart;
  
  *minutes = fabs((float)FractPart*60.0000f);
}


/*******************************************************************************
 * @brief
 *   Calculates shotest distance over the earth’s surface between two GNSS 
 *   coordinates using the haversine formula.
 *
 * @note
 *      Input parameters are in degree.
 *      Output distance is in km.
 *
 ******************************************************************************/
float Gnss_Calc_Distance (float curr_lon, float curr_lat, float dest_lon, float dest_lat)
{
  double dest_lat_rad = GNSS_DEG2RAD(dest_lat);
  double curr_lat_rad = GNSS_DEG2RAD(curr_lat);
  double lat_diff_rad = GNSS_DEG2RAD(curr_lat-dest_lat);
  double lon_diff_rad = GNSS_DEG2RAD(curr_lon-dest_lon);
    
  double a = sin(lat_diff_rad/2) * sin(lat_diff_rad/2) + cos(dest_lat_rad) * cos(curr_lat_rad) * sin(lon_diff_rad/2) * sin(lon_diff_rad/2);
  
  double c = atan2(sqrt(a), sqrt(((double)1)-a)) * 2;
  
  double d = GNSS_REARTH * c;
  
  return (float)d;  
}


/*******************************************************************************
 * @brief
 *   Calculates the Initial Bearing (forward azimuth) over the earth’s surface 
 *   between two GNSS coordinates using the Spherical Law of Cosines formula.
 *
 * @note
 *      Input parameters are in degree.
 *      Output Bearing is in deg.
 *
 ******************************************************************************/
float Gnss_WayFinderBrearing (float curr_lon, float curr_lat, float dest_lon, float dest_lat)
{
  double dest_lat_rad = GNSS_DEG2RAD(dest_lat);
  double curr_lat_rad = GNSS_DEG2RAD(curr_lat);
  //double lat_diff_rad = GNSS_DEG2RAD(dest_lat - curr_lat);
  double lon_diff_rad = GNSS_DEG2RAD(dest_lon - curr_lon);
  
  double y = sin(lon_diff_rad) * cos(dest_lat_rad);
  double x = cos(curr_lat_rad) * sin(dest_lat_rad) - sin(curr_lat_rad) * cos(dest_lat_rad) * cos(lon_diff_rad);
  double bearing = atan2(y, x);
  bearing *= ((double)180.0);
  bearing /= GNSS_PI;
  
  if ( bearing < 0 )
    bearing += ((double)360);
  else if( bearing > ((double)359) )
    bearing -= ((double)360);
  
  return (float)bearing;
}

/*******************************************************************************
 * @brief
 *   Calculates the WayFinder forward Offset direction. 
 *
 * @note
 *      Input parameters are in degree.
 *      Output Offset Direction is in deg. Range -180/+180. 
 *             Negative: West, Positive: East
 *
 ******************************************************************************/
int32_t Gnss_WayFinderOffset (float curr_lon, float curr_lat, float dest_lon, float dest_lat, float compass_heading)
{
  float initbearing = Gnss_WayFinderBrearing (curr_lon, curr_lat, dest_lon, dest_lat);
  int32_t Direction = (int32_t)initbearing - (int32_t)compass_heading;
  Direction += 360;
  Direction %= 360;
  
  if(Direction > 180)
    Direction -= 360;
    
  return Direction;
}


#endif // _WAYFINDER_H_