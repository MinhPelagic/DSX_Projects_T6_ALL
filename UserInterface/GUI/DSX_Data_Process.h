/******************************************************************************/
//File: DSX_Data_Process.h
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Initial
//
/*****************************************************************************/
#ifndef _PROCESS_DSX_H__
#define _PROCESS_DSX_H__
/* Standard includes. */

extern uint8_t in_buf[];

/*Low&High Nibble*/
#define HiNib(X)								(X&0xF0)
#define LoNib(X)								(X&0x0F)
#define HiNibVal(X)                            	(HiNib(X)>>4)
#define LoNibVal(X)                             (LoNib(X))
#define DataIsDiff(x,y)							 (x!=y)
#define DataIsEqual(x,y)						 (x==y)
#define UpdateData(x,y)							 (x=y)

/*LOG graph define*/
#define LOG_GraphData(X,Y)							(rData[(Y*16)+X])
/*
Depth value from exFlash: Y is position of sample
						: X count from 1 to right (16)
*/
//#define LOG_X(X)									(X-1)	//Counting number from left to right
//#define LOG_Y(Y)									(Y-1)	//Number of sample (0,1....)
/*X: number of sample
DEPTH HIGH and LOW*/
#define LOG_GraphDEPTHFraction_Metric(X)              	((float)((ImperialConvert(LoNibVal(LOG_GraphData(2, X))))/(float)16))
#define LOG_GraphDEPTHImperial(X)						(((LOG_GraphData(3, X)<<8) + LOG_GraphData(2, X))>>4)
#define LOG_GraphDEPTH(X)								(Imperial ? LOG_GraphDEPTHImperial(X):(ImperialConvert(LOG_GraphDEPTHImperial(X))+LOG_GraphDEPTHFraction_Metric(X)))
#define LOG_GraphASCBG(X)								LOG_GraphData(0, X)
#define LOG_GraphN2(X)									LOG_GraphData(1, X)
#define LOG_CLKTime(X)									((uint16_t)((LOG_GraphData(1, X)*60)+LOG_GraphData(2, X)))//Surface time in DIVE
//Average Depth
#define AverageDepth                                  ((float)(TotalDepth/TotalDives))
#define PSI_2_BAR(X)                                ((uint16_t)( (X) /14.50377438972831))/* PSI to BAR unit (input PSI and return BAR number)*/

//SURFACE - 1 (S1A, S1B)----------------------------------------------------------------------------------
#define SI_Low                                        (in_buf[16])
#define SI_High                                       (in_buf[17])

#define CDTL                                        (in_buf[44])
#define CDTH                                       	(in_buf[45])
#define Surface_CDT_Mins                            CDTH//((uint16_t)((CDTH<<8) + (uint16_t)CDTL))
#define Surface_CDT_Sec								CDTL//(in_buf[46])
#define CDT_Set_OFF									DataIsEqual(in_buf[46], 0)
#define CDT_Set_ON									(!CDT_Set_OFF)
//3. Tank pressure (PSI or BAR) S1A/S1B
#define Tank_Low                                 ((uint8_t)(in_buf[30]))
#define Tank_High                                ((uint8_t)(in_buf[31]))
/*TANK PRESSURE (PSI or BAR depends on BIT 3 of USRFLG).*/
#define Tank_Pressure_CompareVal            	((uint16_t)(((Tank_High)<<8) + (uint16_t)Tank_Low))//6 Low bits only
#define Tank_PressureValue						1527
#define Tank_Color				 				((uint8_t)(Tank_High&0xC0))//2 bit HIGH
#define Tank_Flashing			 				((Tank_High&BIT_5)==BIT_5)
#define Tank_Available							((uint16_t)0x1FFF)
#define CC6_Low                                 ((uint8_t)(in_buf[44]))
#define CC6_High                                ((uint8_t)(in_buf[45]))
#define CC6_PressValue			            	((uint16_t)(((Tank_High)<<8) + (uint16_t)Tank_Low))
#define DilPO2									(in_buf[36]/(float)100)
//#define DiveNum                  ((uint8_t)(in_buf[27]))
#define GASNum                          (uint8_t)FindGasNumOfDiveMode(DIVE_MODE)        // DSX Current Gas Selected
/*DIVE MODE*/
#define NDCL					((uint8_t)(in_buf[18]))
#define NDCH					((uint8_t)(in_buf[19]))
#define NDC_ValToUpdate			((uint16_t)((NDCH * 256) + (NDCL)))//The value in order to update --> get all bits
#define NDC_Value				((uint16_t)(((NDCH&0x03) * 256) + (NDCL)))//http://prntscr.com/b21lf9
#define DECO_Display			(DataIsEqual(HiNibVal(DVSTAT), DiveMode_DECOMPRESSION)||\
								DataIsEqual(HiNibVal(DVSTAT), DiveMode_CONDITIONAL))//When in DECO then display the top DECO not O2 or No-DECO
#define TATL                            (uint8_t)in_buf[42]
#define TATH                            (uint8_t)in_buf[43]
#define TTS                             ((uint16_t)(((TATH) << 8) + (TATL))) //Total Ascent Time to Sutface (TTS)
#define TTS_MIN					TTS%60
#define TTS_HOUR				TTS/60
#define O2Time_Display			((NDCH&BIT_7)==BIT_7)//Display O2 time or NDC
#define NDCnO2_Color			((NDCH&BIT_6)==BIT_6)//Bit_6 is 1 then Red color
//1. GTRL (LSB) and GTRH (MSB) = Gas Time Remaining in binary minutes.  When FFFF, display - - PSI or BAR. No GTR if Gas# = Gas2, 3, or 4.
#define GTR_Low                                        ((uint8_t)(in_buf[18]))//OPCODE = 10H. 
#define GTR_High                                        ((uint8_t)(in_buf[19]))//OPCODE = 10H. 
#define GTR_TimeValCompare                              ((uint16_t)((GTR_High<<8) + (uint16_t)GTR_Low))//Get the value to check value, color and flashing.
#define GTR_Time                                        ((uint16_t)(((GTR_High&0x3F)<<8) + (uint16_t)GTR_Low))
#define GFBG_Value				        SCUBA_Set.GF_High       // DSX GF Set for High Value
#define TLBG_Value										0
#define GFBG_TLBG_BIT									((USRFLG&BIT_6)>>6)
//#define GTR_LostLink									((GTR_High&BIT_7)==BIT_7)//Lost link detected more than 1 min
#define GTR_LostLink									((STDFLG_SurfaceMode&BIT_5)==BIT_5)//Lost link detected more than 1 min
#define GTR_LostLinkEstablish							((GTR_High&BIT_6)==BIT_6)//Lost link detected more than 1 min
#define GTR_AlarmCheck									(GTR_Time==0)
#define GTR_Color_SET									(GTR_AlarmCheck ? GUI_RED : ((GTR_Time > 5) ? GUI_GREEN : GUI_YELLOW))
/* Add GTR_High and GTR_Low to get Gas Time Remaining in binary minutes*/
#define FO2_Surface							SCUBA_Set.FO2A[0]         // DSX FO2 of the selected tank
#define Heli_Surf							SCUBA_Set.FHeA[0]
#define PO2_Val								SCUBA_Set.PO2A[0]
#define SET_GAS_AIR							DataIsEqual(FO2_Surface , AIRVal)
/*PO2 Dive mode*/
#define EDT_Value                       	        LastDiveTime_s/60               // DSX Last Dive Total Time in seconds
#define DiveTimeHour					((uint16_t)(EDT_Value/60))      // DSX Last Dive Time in hours
#define DiveTimeMins				    	((uint16_t)(EDT_Value%60))      // DSX Last Dive Time in minutes of the hour
/*RTM = Run timer in binary minute. GAUGE mode only.*/
#define RTMin_L							(in_buf[44])
#define RTMin_H							(in_buf[45])
#define	RunTimeMins						((uint16_t)(((RTMin_H) * 256) + (RTMin_L)))
#define RunTimeSec						(in_buf[46])
/*Hour and min in dive mode*/

//Check BIT 1,2,3,4
#define SXMIT_GAS_Select_(X)			(DataIsDiff((BIT_0<<X), ((BIT_0<<X)&SXMIT)))//Check the GAS status ON/OFF
/*
FO2 GAS 1: Buffer 22
FO2 GAS 2: Buffer 28
FO2 GAS 3: Buffer 34
FO2 GAS 4: Buffer 40
*/
#define SWGas_PO2_LSB(X)               ((uint8_t)(in_buf[14+(X-1)*6]))
#define SWGas_PO2_MSB(X)               ((uint8_t)(in_buf[15+(X-1)*6]))
#define SWGas_PO2_(X)             		((float)(((SWGas_PO2_MSB(X) * 256) + SWGas_PO2_LSB(X))/(float)100))
//#define SWGas_PO2_(X)				    (float)((in_buf[14+(X-1)*6])/(float)100)//Base on the spec location buffer
#define SWGas_MOD_LSB_(X)               ((uint8_t)(in_buf[16+(X-1)*6]))
#define SWGas_MOD_MSB_(X)               ((uint8_t)(in_buf[17+(X-1)*6]))
#define SWGas_MOD_Value_(X)             ((float)(((SWGas_MOD_MSB_(X) * 256) + SWGas_MOD_LSB_(X)) /16))
//((float)(Imperial? (((SWGas_MOD_MSB_(X) * 256) + SWGas_MOD_LSB_(X)) /16) : ImperialConvert((SWGas_MOD_MSB_(X) * 256) + SWGas_MOD_LSB_(X))))
//TMT SWITCH MENU
#define TMT_Normal			0x00
#define TMT_SearchForTMT	0x01
#define TMT_NotAvailable	0x02
#define TMT_Check_(X)		((SXMIT>>X)&BIT_0)
/*COMPASS Mode*/
#define CRML					(in_buf[24])
#define CRMH					(in_buf[25])
#define CR_MIN				 	((uint16_t)(((CRMH) * 256) + (CRML)))
#define CR_SEC					(in_buf[26])
/*DEEP&SAFETY STOP*/
#define DSTL					(in_buf[50])
#define DSTH					(in_buf[51])
#define DST					 	((uint16_t)(((DSTH) * 256) + (DSTL)))
#define DST_Mins				(DST/60)
#define DST_Sec					(DST%60)
#define DSST					(in_buf[16])
/*MESSAGE CODE*/
#define MsCode_Value				(MSG&0x7F)//Get the 7 bit except BIT_7 due to it is the flashing bit

/*Struct data for LOG, each LOG have one node data*/
typedef struct {
    uint8_t LOG_DiveNum;
    uint8_t LOG_MONTH;
    uint8_t LOG_DAY;
    uint8_t LOG_YEAR;
    uint8_t LOG_Minutes;
    uint8_t LOG_Hour;
    uint8_t LOG_SurfaceTime_LSB;
    uint8_t LOG_SurfaceTime_MSB;
    uint8_t LOG_MaxDepth_LSB;
    uint8_t LOG_MaxDepth_MSB;
    uint8_t LOG_EDT_LSB;
    uint8_t LOG_EDT_MSB;
    uint8_t LOG_DiveMode;	//Low nibble 0 = NORM, 1 = GAUGE. Bit7 = 1 then VIOL. Bit 5 = 1 then PZ+.
    uint8_t LOG_SeaLevel;
    uint8_t LOG_Max_NDC;
    uint8_t LOG_Max_ASCBG;
    uint8_t LOG_CurrentDive;
    uint8_t LOG_MinTemp;
    uint8_t LOG_StartTank_LSB;
    uint8_t LOG_StartTank_MSB;
    uint8_t LOG_EndTank_LSB;
    uint8_t LOG_EndTank_MSB;
    uint8_t LOG_O2Sat;
    uint8_t LOG_FO2_Gas1;
    uint8_t LOG_PO2_Gas1;
    uint8_t LOG_AverageTemp;
    uint8_t LOG_AverageDepth_LSB;
    uint8_t LOG_AverageDepth_MSB;
    uint8_t LOG_MaxPO2_LSB;
    uint8_t LOG_MaxPO2_MSB;
    uint8_t LOG_ExitTime_Mins;
    uint8_t LOG_ExitTime_Hour;

    uint8_t LOG_StartBlockDiveProfile_L;
    uint8_t LOG_StartBlockDiveProfile_H;
    uint8_t LOG_EndBlockDiveProfile_L;
    uint8_t LOG_EndBlockDiveProfile_H;
    uint8_t LOG_LastGAS_Num;
    uint8_t LOG_ProfileSamplingRate;
    uint8_t LOG_TrailAdd_L;
    uint8_t LOG_TrailAdd_H;
    uint8_t LOG_LongLatSigns;
    uint8_t LOG_LongtitudeDeg;
    uint8_t LOG_LongtitudeMin;
    uint8_t LOG_LongtitudeSec;
    uint8_t LOG_LongtitudeSecDec;
    uint8_t LOG_LatitudeDeg;
    uint8_t LOG_LatitudeMin;
    uint8_t LOG_LatitudeSec;
    uint8_t LOG_LatitudeSecDec;
    uint8_t LOG_Rev49;
    uint8_t LOG_Rev50;
    uint8_t LOG_Rev51;
    uint8_t LOG_Rev52;
    uint8_t LOG_Rev53;
    uint8_t LOG_Rev54;
    uint8_t LOG_Rev55;
    uint8_t LOG_Rev56;
    uint8_t LOG_Rev57;
    uint8_t LOG_Rev58;
    uint8_t LOG_Rev59;
    uint8_t LOG_Rev60;
    uint8_t LOG_Rev61;
    uint8_t LOG_Rev62;
    uint8_t LOG_Rev63;
} DataLOG_ts;

typedef struct {
    uint8_t PM_PDEPL;
    uint8_t PM_PDEPH;
    uint8_t TIME_L;
    uint8_t TIME_H;
} PLAN_Data_ts;
/**/
#if 0
typedef struct {
    GUI_POINT *PortionPart;
    GUI_COLOR Color;
} BAR_ts;
#endif
/*SETTINGS -->SET GAS*/
uint8_t Num2Str(uint16_t num, char* str, uint8_t maxlen);
void DatProc_USBCharging(uint16_t *TxtColor, uint16_t *BGColor);
uint8_t AltitudeProcess(uint8_t X);
uint8_t Bcd2ToByte(uint8_t);
const char* HourProcess(uint8_t HourValue, int ClockFormat, int HourFormat);
const char* MinsProcess(uint8_t MinsValue);
const char* MidnightProcess(int MidnightFlag, int TimeFormatFlg);
/*Private define*/
#endif
