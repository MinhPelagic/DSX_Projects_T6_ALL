#ifndef __SURFACE_CONTEXT_H__
#define __SURFACE_CONTEXT_H__
#include "L4X9_includes.h"

/*define name of TMT*/
enum
{
    TMTName_OC,
    TMTName_TMT,
    TMTName_Max
};
/**/
#define TANKPRESS_LOWEST_PSI (726U)
//Fly time is in binary minutes, convert them to HH:MM.
#define FLY_Hr                       ((uint16_t)(FLYtime / 60))                 // DSX FLYtime read from DiveAlgo
#define FLY_Min                      ((uint16_t)(FLYtime % 60))                 // DSX FLYtime read from DiveAlgo 
//DESAT time is in binary minutes, convert them to HH:MM.
#define DESAT_Hr                      ((uint16_t)(DSATtime / 60))               // DSX DSAT in hour
#define DESAT_Min                     ((uint16_t)(DSATtime % 60))               // DSX DSAT in minutes of the hour
/*SurfTime total*/
#define SurfTime                Dive_Info.SurfTime_s      // DSX SurfTime is in seconds
#define SURFT_Hour              ((uint16_t)(SurfTime / 3600))
#define SURFT_Min               ((uint16_t)((SurfTime / 60)%60)) /* Surface time / 60 mins --> Surf Hour*/
#define SURFT_Sec		((uint16_t)(SurfTime %60))/* Surface time % 60 mins --> Surf Minutes*/
#define TIME_Year       SysTimeDatePST.Year
#define TIME_Mon        SysTimeDatePST.Month
#define TIME_Day        SysTimeDatePST.Day
#define TIME_WeekDay    SysTimeDatePST.WeekDay
#define TIME_Hour       SysTimeDatePST.Hour
#define TIME_Min        SysTimeDatePST.Minute
#define TIME_Sec        SysTimeDatePST.Second
extern NVD_DIVEMODE_t GUI_DIVE_Mode;
extern const GUI_COLOR Color_InfoTitleSetting[];
extern const char* TxtDef_Set_PressUnit[];
extern const char* TxtDef_Set_DepthUnit[];
void SurfaceHandle_3rdRowRight_GF(void);
void SurfaceHandle_3rdRowRight_TIME(void);
void SurfaceHandle_3rdRowRight_O2Sat(void);
void SurfaceHandle_3rdRowRight_Ceiling(void);
void SurfaceHandle_3rdRowRight_MaxDepth(void);
void SurfaceHandle_3rdRowRight_AvgDepth(void);
void SurfaceHandle_3rdRowRight_FiO2(void);
void SurfaceHandle_3rdRowRight_GTR(void);
void SurfaceHandle_3rdRowRight_DilPO2(void);
void SurfaceHandle_3rdRowLeft_GF(void);
void SurfaceHandle_3rdRowLeft_AvgDepth(void);
void SurfaceHandle_3rdRowLeft_O2Sat(void);
void SurfaceHandle_3rdRowLeft_GTR(void);
void SurfaceHandle_3rdRowLeft_Ceiling(void);
void SurfaceHandle_3rdRowLeft_MaxDepth(void);
void SurfaceHandle_3rdRowLeft_DilPO2(void);
void SurfaceHandle_3rdRowLeft_TIME(void);
void SurfaceHandle_3rdRowLeft_FiO2(void);
extern const p_VoidFunc_t SurfMode_3rdContentLeft[];
extern const p_VoidFunc_t SurfMode_3rdContentRight[];
void HandleItem_SurfaceMode_Main_TISSUES(void);
void SurfaceMode_BluetoothIcon(unsigned char);

#endif
