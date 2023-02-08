#include "Gps_Uart.h"
#include "GpsProcess.h"
#include <stdlib.h>
#include "string.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include "GpsHeaderFile.h"



short BTProcessCommand(char command[]);
uint8_t  Gps_Respone_Uart_Transmit(uint8_t* buffer,uint16_t len);
void Process_Gps_GPGGA_Response(char gsp__gpgga[]);
void Process_Gps_GPGLA_Response(char gsp__gpgla[]);
void Process_Gps_GPGSA_Response(char gsp__gpgsa[]);
void Process_Gps_GPGSV_Response(char gsp__gpgsv[]);
void Process_Gps_GPRMC_Response(char gsp__gprmc[]);
void Process_Gps_GPZDA_Response(char gsp__gpzda[]);
void Process_Gps_GPVTG_Response(char gsp__gpvtg[]);
void SplitArrayFromComma(char *gsp__gpgga);
void GetGPGGAContent(void);
char *GpsParameter[MAX_PARAMETER], *MaxParameterStrPtr;
short MaxParameterPtr=0;

char ResponeBuffer[MAX_PARAMETER][150];
float Latitude=0.0;					                        //dd mm.mmmm[min]
char Latitude_N_S=0;				                        //N:north S:South
float Longitude=0.0;					                    //ddd mm.mmmm[min]
char Longitude_E_W=0;				                        //E:East W:West
char NoOfSatellites_used=0;


char gps_content[150];
void FindGpsResponseContents(char *gsp__contents);
extern char combuffer[];

// BT NotificationEvent Actions
short BTNotificationEvent(void)
{
	short nextPtr;
	while (CurCommandPtr != MaxCommandPtr)
	{
		NextCommandPtr = CurCommandPtr;
		NextCommandPtr++;
		if (NextCommandPtr >= MAX_COMMANDS) 
            NextCommandPtr = 0;
		MaxCommandStrPtr = Commands[NextCommandPtr];
		BTProcessCommand(Commands[CurCommandPtr]);
		CurCommandPtr = NextCommandPtr;
	}
	return 0;
}


short BTProcessCommand(char command[])
{
    if (strncmp("$GPGGA",command, 6) == 0)
    {
        Process_Gps_GPGGA_Response(&command[0]);
    }
    else if(strncmp("$GPGLL",command, 6) == 0)
    {
        Process_Gps_GPGLA_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }
    else if(strncmp("$GPGSA",command, 6) == 0)
    {
        Process_Gps_GPGSA_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }
    else if(strncmp("$GPGSV",command, 6) == 0)
    {
        Process_Gps_GPGSV_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }
    else if(strncmp("$GPRMC",command, 6) == 0)
    {
        Process_Gps_GPRMC_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }
    else if(strncmp("$GPVTG",command, 6) == 0)
    {
        Process_Gps_GPVTG_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }
    else if(strncmp("$GPZDA",command, 6) == 0)
    {
        Process_Gps_GPZDA_Response(&command[0]);
        SendCommandToDebugUart(&command[0]);
    }    
	return 0;
}

void Process_Gps_GPGGA_Response(char gsp__gpgga[])
{
    SplitArrayFromComma(gsp__gpgga);
    GetGPGGAContent();
}
void Process_Gps_GPGLA_Response(char gsp__gpgla[])
{
}
void Process_Gps_GPGSA_Response(char gsp__gpgsa[])
{
}

void Process_Gps_GPGSV_Response(char gsp__gpgsv[])
{
}
void Process_Gps_GPRMC_Response(char gsp__gprmc[])
{
}
void Process_Gps_GPZDA_Response(char gsp__gpzda[])
{
}
void Process_Gps_GPVTG_Response(char gsp__gpvtg[])
{
}

void GetGPGGAContent(void)
{
    char GenString[150];
    FindGpsResponseContents(&ResponeBuffer[2][0]);
    Latitude=atof(gps_content);					                        
    Latitude_N_S=ResponeBuffer[3][0];				                        
    FindGpsResponseContents(&ResponeBuffer[4][0]);
    Longitude=atof(gps_content);
    Longitude_E_W=ResponeBuffer[5][0];
    FindGpsResponseContents(&ResponeBuffer[7][0]);
    NoOfSatellites_used=atof(gps_content);
    sprintf(GenString, "LA %0.4f %c\r\n",Latitude,Latitude_N_S);
    SendCommandToDebugUart(GenString);
    sprintf(GenString, "LO %0.4f %c\r\n",Longitude,Longitude_E_W);
    SendCommandToDebugUart(GenString);
    SendCommandToDebugUart("\r\n");
    if(GetGpsSingleCordinates && (NoOfSatellites_used>=MINIMUM_SATELLITE))
    {
    	GpsSingleCordinatesCount++;
    	if(GpsSingleCordinatesCount>=MINIMUM_VALID_CORDINATES)
    	{
    		SendCommandToGps(GPS_SET_SLEEP_0);
    	}
    }
}
void FindGpsResponseContents(char *gsp__contents)
{
    int i=0;
    int len=strlen(gsp__contents);
    for(    ;i<len;i++)
    {
        gps_content[i]=gsp__contents[i];
    }    
}
void SplitArrayFromComma(char *gsp__gpgga)
{
    int i=0,j=0,k=0;
    int len=strlen(combuffer);
    MaxParameterPtr=0;
    for(    ;i<len-1;i++)
    {
        if(combuffer[i]!=0x2C)
        {
            ResponeBuffer[j][k++]=gsp__gpgga[i];
        }
        else
        {
            k=0;
            j++;
        }
    }
}

