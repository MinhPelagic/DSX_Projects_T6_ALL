#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
void InitGps(void);


#define GPS_UART_TIMEOUT				1000

#define GPS_SET_BSSL_GGA					"@BSSL 01\r\n"				//GGA
#define GPS_SET_BSSL_GLL					"@BSSL 02\r\n"				//GLL
#define GPS_SET_BSSL_GSA					"@BSSL 04\r\n"				//GSA
#define GPS_SET_BSSL_GSV					"@BSSL 08\r\n"				//GSV
#define GPS_SET_BSSL_GNS					"@BSSL 10\r\n"				//GNS
#define GPS_SET_BSSL_RMC					"@BSSL 20\r\n"				//RMC
#define GPS_SET_BSSL_TVG					"@BSSL 40\r\n"				//VTG
#define GPS_SET_BSSL_ZDA					"@BSSL 80\r\n"				//ZDA
#define GPS_SET_GALG						"@GALG\r\n"
#define GPS_SET_GALS						"@GALS\r\n"
#define GPS_COLD_START					   	"@GCD\r\n"
#define GPS_SET_GEMG						"@GEMG\r\n"
#define GPS_SET_GEMS						"@GEMS\r\n"
#define GPS_SET_GNS							"@GNS\r\n"
#define GPS_SET_GSOP						"@GSOP 01 1000 0\r\n"
#define GPS_HOT_START						"@GSP\r\n"
#define GPS_HOT_START_TTFF					"@GSR\r\n"
#define GPS_SET_STOP_GSTP					"@GSTP\r\n"
#define GPS_WARM_START						"@GSW\r\n"

#define GPS_SET_SLEEP_0						"@SLP 00\r\n"
#define GPS_SET_SLEEP_1						"@SLP 01\r\n"
#define GPS_SET_SLEEP_2						"@SLP 02\r\n"


#define GPS_SET_IDLE					"@GSTP\r\n"
#define GPS_SET_PPS						"@GPPS 01"
#define GPS_TEST_START					"@GTS\r\n"
#define GPS_UPDATE_TIME_DATE			"@GTIM 2020 07 04 13 30 30\r\n"
#define GPS_GET_VER						"@VER\r\n"
#define GPS_WUKEUP						"@WUP\r\n"
#define GPS_GPS_DATA					"@GNS 03"
#define GPS_BAUD_RATE_CHANGE			"@CSBR 9600\r\n"
#define CR_LINE_FEED					"\r\n"



extern char GetGpsSingleCordinates;
extern char GpsSingleCordinatesCount;
void GpsMonitor(void);
char GpsContineousMode(uint8_t mode,uint16_t interval);
char GpsSingleLock(void);
uint8_t GetGpsDataAccuracy (void);
