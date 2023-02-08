/*******************************************************************************
 * @file        : WayFinder.h
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

#ifndef _WAYFINDER_H_
#define _WAYFINDER_H_


#define GNSS_PI                 (double)3.14159265
#define GNSS_REARTH             (double)6371.00
#define GNSS_DEG2RAD(a)         ((((double)(a)) * GNSS_PI )/((double)180))

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DMS format to DD format
 *
 * @note
 *      Input Coordinate is in DMS format, only degree must have sign.
 *      Output Coordinate is in DD format.
 *
 ******************************************************************************/
float WayFinder_Dms2Dd (float degree, float minutes, float seconds);

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DD format to DMS format
 *
 * @note
 *      Input Coordinate is in DD format.
 *      Output Coordinate is in DMS format. Sign is only on the degree output.
 *
 ******************************************************************************/
void WayFinder_Dd2Dms (float DegreeInput, float *degree, float *minutes, float *seconds);

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DMM format to DD format
 *
 * @note
 *      Input Coordinate is in DMM format, only degree must have sign.
 *      Output Coordinate is in DD format.
 *
 ******************************************************************************/
float WayFinder_Dmm2Dd (float degree, float minutes);

/*******************************************************************************
 * @brief
 *   Convert GNSS coordinates from DD format to DMM format
 *
 * @note
 *      Input Coordinate is in DD format.
 *      Output Coordinate is in DMM format. Sign is only on the degree output.
 *
 ******************************************************************************/
void WayFinder_Dd2Dmm (float DegreeInput, float *degree, float *minutes);

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
float Gnss_Calc_Distance (float curr_lon, float curr_lat, float dest_lon, float dest_lat);

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
float Gnss_WayFinderBrearing (float curr_lon, float curr_lat, float dest_lon, float dest_lat);

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
int32_t Gnss_WayFinderOffset (float curr_lon, float curr_lat, float dest_lon, float dest_lat, float compass_heading);


#endif // _WAYFINDER_H_