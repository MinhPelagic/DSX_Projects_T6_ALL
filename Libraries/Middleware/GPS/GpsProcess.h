#ifndef __HR_H
#define __HR_H
#define UART_TIMEOUT    1000
#define MAX_PARAMETER   20
#define MINIMUM_SATELLITE	4
#define MINIMUM_VALID_CORDINATES	4
extern short BTNotificationEvent(void);


extern float Latitude;					                        //dd mm.mmmm[min]
extern char Latitude_N_S;				                        //N:north S:South
extern float Longitude;					                    //ddd mm.mmmm[min]
extern char Longitude_E_W;				                        //E:East W:West
extern char NoOfSatellites_used;




#endif

