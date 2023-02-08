#ifndef __GPS_H
#define __GPS_H
#include "Gps_Uart.h"
#include "GpsProcess.h"
#include "GpsCmdProtocol.h"
#include "Gps_Init.h"

extern void SendCommandToDebugUart(uint8_t *cmd);
#endif

