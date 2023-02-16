/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2004  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
#include <windows.h>
#include <winnt.h>
#include <winuser.h>
#include "L4X9_includes.h"//Stub
#include "Receiver.h"
#include "..\..\..\..\UserInterface\GUI\OpcodeHandle\Menu\Main Menu\Main_Menu_INFO\MenuHandle_MyInfo_ReadEepromData.h"
/*Compile list*/
/*Font*/
#include "..\..\..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_ASCII_Latin_1.c"
#include "..\..\..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_China_S.c"
#include "..\..\..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_China_T.c"
#include "..\..\..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_Korean.c"
/*Bitmaps*/
extern GUI_CONST_STORAGE GUI_BITMAP bmDSX_WelcomeBMP;
extern STRING_LANG StrLang_Select[];
extern Scuba_Settings_t         SCUBA_Set;

/*Extern these variables from Algorithm*/

int _GetData(void *p, const U8 ** ppData, unsigned NumBytes, U32 Off);
uint8_t in_buf[100];
uint8_t fFO2[100];
uint16_t Compass_vala;
uint16_t GFmaxValue;
LOG_Data_t Log_Data;
int Plan_DEPTH_NDT_OTR_PO2[25][4];
uint8_t CompassCalibrated;
uint8_t OpTestVal_u8;
uint8_t PreOpTestVal_u8;
uint8_t OTUpercent;
bool isSSorDS;
union AlarmUNION Alarming;   
union AlarmUNION Alarming2;
union AlarmUNION AlarmOn2;
union AlarmUNION AlarmOccured;
union AlarmUNION AlarmOn;
union AlarmUNION AlarmDueAck2;
union AlarmUNION AlarmDueAck;
uint8_t SensorReadbackLux;
uint8_t CurrGasNumber;
uint8_t ButtonNoResponseCnt;
uint8_t BestGasNumber;
uint8_t u32DiveTimeHr;
uint8_t GFHighSettingValue;
float PO2atDepth;
TP_Info_struct_t TP_Info;
Dive_Info_struct_t Dive_Info;
uint8_t FLYtime;
uint8_t DSATtime;
uint8_t SwitchFO2_InFlashing;
uint8_t AlarmID;
uint8_t GFvalue;
Scuba_Settings_t        SCUBA_Set;
uint8_t  PO2A[100];
User_Settings_t         USER_Set;
EcData_struct_t EcData;
DSX_OPCODE_t DSX_Opcode = 0x0001;
SystemTimeDate_t SysTimeDatePST;
uint16_t NDT_Data;    
Device_Records_t        DEV_Rec;
Mfg_Calibration_t        MFG_Calib;
L4X9_SysStat_t SystemStatus;
uint8_t HW_Buttons;
uint8_t GUI_CurrGasNum;
DSX_OPCODE_t pre_DSX_Opcode = S_DIVE_SETTINGS;
int32_t MonotonicClock_s;
L4X9_SystemSupplyMonitor_t SystemSupplyMonitor;
GPS_LocationRec_t Target_Loc;
TRIMIX_Settings_t       TRIMIX_Set;
Free_Settings_t          FREE_Set;
Free_Records_t           FREE_Rec;
FLASH_Map_t              FLASH_Map;
uint8_t hadc1;
uint8_t ccSPcurrent;
uint8_t SIM_MESSAGE;
float O2_Analyzer_Volt;
uint8_t O2_Analyzer_Pct;
uint8_t O2_ADC_V_Analyze1;
uint8_t GUI_O2_AnalyzerFO2Set;
float O2_SetForCalib_Pct;
float Pamb;
uint8_t Compensated_Uint8_O2_Pct;
float CellNewToDepletedFactor;
uint8_t CURRENT_PRESSURE_MBAR;
uint16_t O2_Cell_mV_Of_Set_FO2;
float Calculated_Tank_FO2_Pct;
uint8_t GUI_O2_AnalyzerFHeSet;
L4X9_TickHanlder_t TickHandler;
EcRawData_struct_t EcRawData;
unsigned int CONS_FO2_FHe_RMV[7][3];
unsigned char debugBuff[200];
unsigned char TLBG_ARRAY[10];
unsigned char SIMOTUpercent;
int DecoStop[42], DecoTime[42], DecoGas[42], DecoFO2[42], DecoFHe[42];
int BDecoStop[42], BDecoTime[42], BDecoGas[42], BDecoFO2[42], BDecoFHe[42];
unsigned int otrTime, TDT, TAT_Data, Total_DST, EDTtime;
unsigned char TLBGVal, MaxASCBGVal, OTUpercent, DelayFlag;
unsigned char ASCBGVal = 5;
unsigned char isSwitchGas;
unsigned char NeedToSwitchGas;
unsigned char DeclinedGasNumber;
unsigned char SuggestedBestGasNumber;
TMT_NUM_t  GUI_TMT_Num_InSetting;
TMT_NUM_t GUI_TankN_Linked;
TMT_Connection_t GUI_TMT_Battery[10] = {0};
uint8_t isViolation;
uint8_t isGaugeMode;
uint8_t isCCMode;
uint8_t GFBGVal;
float fMaxDepthFt = 45.0f;
uint8_t fMaxDepthM;
uint8_t DS_Counter;
uint8_t fAvgDepthFt;
float fAvgDepthM = 12.3f;
uint8_t FiO2;
uint8_t Dil_PO2;
uint8_t ConditionTime;
uint8_t ATR;
uint8_t DECOSTOP_Depth;
uint8_t DECOSTOP_Min;
uint8_t DecoStatus;
uint8_t ccSPlow;
uint8_t ccSPhigh;
uint8_t AutoSP_High_MaunalOverwrite;
uint8_t AutoSP_Low_MaunalOverwrite;
uint8_t ccSP_ManualChangedToLow;
uint8_t ccSP_ManualChangedToHigh;
TIMER_t Runtime;
TIMER_t Chrono;
uint32_t GUI_TMT_InSetting_PSI;
uint8_t GUI_TMT_Connection_Status;
uint16_t GUI_TMT_PressPSI_ofGAS[8] = {200};
uint16_t GUI_TMT_PressPSI[8] = {0};
uint16_t Pi_iN2[8] = {0};
uint16_t GUI_TMT_TimeStamp[8] = {0};
uint16_t FO2A[8] = {0};
uint16_t FHeA[8] = {0};
uint16_t GUI_TMT_id[8] = {0};
uint16_t CTANK[7] = {0};
uint16_t u32DiveTimeMin = 0;
uint16_t u32DiveTimeSec = 0;
float fDepthFt = 0.0f;
float fDepthM = 0u;
uint16_t GUI_CC6_TimeStamp = 0;
uint16_t GUI_CC6_PressPSI = 0;
TankData_t g_Data = {0};
GnssGGA_struct_t GnssGGA;
uint8_t GnssStatus ;
uint8_t O2_Primary_V_ZeroOffset;
uint8_t O2_ADC_V_ZeroOffset;
uint8_t O2_ADC_V_Calib;
uint8_t CURRENT_TMT_NUM_GSM;
uint8_t CURRENT_TMT_NUM_GAUGE;
unsigned char DVSTAT;
unsigned char isSSdisplayON;
bool isSSflagON;
unsigned char isDSflagON;
unsigned char OC_END_AtDepthFT;
unsigned char OC_WOB_depthFT;
unsigned char SS_Counter;
LOG_Chart_t Log_Chart_7[10];
LOG_Chart_t Log_Chart;
LOOSE_LINK_t GUI_TMT_InLinking[10];
uint8_t AutoBRIGHTNESS = 10;/*Static test variables*/
GUI_FONT FontAaux_1;
GPS_WayFinder_t GUI_WayFinder;  // The GPS Database read back from ExFLASH
uint16_t ProfileChartData[200] = { 0x0013, 0x4014, 0x0015, 0x4016, 0x4017};          // prepare Profile Chart Data for LOG chart use
MMC_Output_t MMC_Output;
uint32_t CounterCaliCompass = 0;
static GUI_TTF_DATA TTF_CustomFontData;
static GUI_TTF_CS CustomFontGenerate_1;
/*     	
uint8_t       LogNum;      
uint8_t       DiveNum;
uint8_t       EntryYear;
uint8_t       EntryMon;
uint8_t       EntryDay;
uint8_t       MaxDepthFt10;
uint8_t       AvgDepthFt10;
uint8_t       EDTsec;
uint8_t       MinTempF10; 
*/
   LOG_Data_t Log_Data_7[MAX_ITEM_DISP_PAGE_LOG_01] = 
   {
	   {1, 15, 9, 2029, 1, 20, 01, 10, 12, 90},
	   {1, 14, 8, 2028, 2, 21, 01, 10, 12, 90},
	   {1, 13, 7, 2027, 3, 22, 01, 10, 12, 90},
	   {1, 12, 6, 2026, 4, 23, 01, 10, 12, 90},
	   {1, 11, 5, 2025, 5, 24, 01, 10, 12, 90},
	   {1, 10, 4, 2024, 6, 25, 01, 10, 12, 90},
	   {1, 9, 3, 2023, 7, 26, 01, 10, 12, 90},
   };

void MainTask(void) 
{
	GUI_LANG_Select = Select_GERMAN;
	GUI_Init();
	GUI_LANG_SetMaxNumLang(MAX_LANGUAGE);
	/*Load the string content to RAM*/
	GUI_LANG_LoadTextEx(_GetData, (void*)&StrLang_Select[LANGUAGE], LANGUAGE);
	GUI_LANG_SetLang(LANGUAGE);
	GUI_UC_SetEncodeUTF8();
	AsssignedCoordinated(1);
	TTF_CreateFontSequence(FontSize_General); /*Initlal the font engine -> Surface*/
	/*Set var button to simulate*/
	Key_M.Timer = KEYPRESS_TIMOUT;
	Key_M.DataType = short_press;
	Key_U.Timer = KEYPRESS_TIMOUT;
	Key_U.DataType = short_press;	
	Key_L.Timer = KEYPRESS_TIMOUT;
	Key_L.DataType = short_press;
	Key_R.Timer = KEYPRESS_TIMOUT;
	Key_R.DataType = short_press;
	/*Set Dive Mode*/
	USER_Set.DiveMode = NVD_MDGSM;
	// USER_Set.DiveMode = NVD_MDGAUGE;
	GUI_DIVE_Mode	  = USER_Set.DiveMode;
	/**/
	isViolation = 0;  //IS VIOLATION
	TLBGVal = 80;
	GUI_DIVE_T_AL_STAT = NVD_SET;
    Dive_Info.Status = AMB_DIVEINFO_DIVE;
	FlashingState_u8 = 0;
	DECOSTOP_Min = 8;
	DECOSTOP_Depth = 12;
	fDepthFt = 444.0;
	fDepthM = 123.8;
	SystemSupplyMonitor.Battery_Percentage = 15;
	// USER_Set.SwitchSet.Bit.Unit = NVD_METRIC;
	USER_Set.SwitchSet.Bit.Unit = NVD_IMPERIAL;
	AlarmID = ALARM_AscRate5;
	GUI_MAINDISPLAY_EXTRA_LARGE = Setting_ExtraLarge_DEPTH;
	NDT_Data = 19000;
	otrTime = 7000;
	GnssGGA.Target_Direction = 360;
	SysTimeDatePST.Hour = 15;
	SysTimeDatePST.Minute = 52;
	USER_Set.SwitchSet.Bit.HR24_Format = 1;
	TMT_LINKED_MODE = 4;
	GUI_ShowTankNum = 2;
	TMT_LINKED_GAS_INDEX = 1;
	DecoStatus = 1;
  	/*Set to button save state SET in next cycle*/
	/*Now go to Decode*/
	/*
	***************************************************************************************************************************
	DSX: WELCOME SCREENs
	***************************************************************************************************************************
	*/
	Decode_DSX_Data();
	GUI_Delay(2000);
	/*
	----------------------------------------------------------------------------------------------------------------------------
	AD_PV_01 << End of test scenario >>
	----------------------------------------------------------------------------------------------------------------------------
	*/

	/*
	***************************************************************************************************************************
	AD_PV_01: OC SURFACE
	***************************************************************************************************************************
	*/
	//{
	//	/*Switch between the Surace alternate screens*/
	//	0x04, /*Alternate SURFACE*/
	//	0x01, 0x02, 0x03, 0x04, 0x05, 0x00, /*Test R<2sec*/
	//	0x00, 0x05, 0x04, 0x03, 0x02, 0x01,  /*Test L<2sec*/
	//	/*SURFACE*/
	//	/*MAIN MENU*/
	//	/*GAS SWITCH*/
	//	/*MODE CHANGE*/
	//	/*O2 Analyzer*/
	//};
	/*
	----------------------------------------------------------------------------------------------------------------------------
	*/



	/*Run the test*/
	//uint16_t count_u16 = 0;
	//while (count_u16 < (sizeof(TestMenstat) / sizeof(uint8_t)))
	//{
	//	/*Assign value to test MENSTAT*/
	//	i330_MENSTAT = TestMenstat[count_u16];
	//	/*This used test the DVSTAT as well to DIVE MODE*/
	//	DVSTAT = TestMenstat[count_u16];
	//	pre_DiveModePresent_uc = TestMenstat[count_u16];


	//	/*Define a transaction layer*/
	//	//(transaction.h)


	//	UI_App();
	//	//History_Handle_Page01();
	//	TimeChangeScr
	//	count_u16++;
	//}
	
	/*Test the OC SET LOG*/
	while (1)
	{
		if (DSX_OPCODE != pre_DSX_Opcode)
		{
			Decode_DSX_Data();		
		}
	};
}

/*Stub functions*/
void LED_Backlight_CTRL(uint8_t percent)
{

}
void LED_Backlight_ON(void)
{
}
void sendACK(uint8_t ackCode)
{
}
void sendACK_Stat(uint8_t ackCode, uint8_t stat)
{
}
void LED_Backlight_OFF(void)
{
}
int readFromFlashLOG(uint8_t shift)
{
}
int writeToFlashLOG(uint8_t shift)
{
}
int resetFlashLOG(uint8_t shift)
{
}
void CalibData_Retrieve(void)
{
}
void UpdateRealTimeDate(SystemTimeDate_t *TimeDate)
{
}
void UI_App(void)
{
}
void Gnss_Standby(void)
{
}
void EE_SaveReq(uint8_t blk)
{
}
void Save_GUI_Set_TimeDate(SystemTimeDate_t *TimeDate)
{
}
void L4X9_SetRtc(SystemTimeDate_t time)
{
}
uint8_t HAL_GPIO_ReadPin(uint8_t GPIOPort, uint16_t GPIO_Pin)
{
}
void Ec_Off(void)
{
}
void Ec_On(void)
{
}
void Ec_Calibrate(void)
{
}
void InitializePLAN(void)
{
}
void Display_PLANGF(void)
{
}
void BrowsePLAN(void)
{
}
uint8_t FindMOD(void)
{
	return 1;
}
uint8_t FindHT(void)
{
	return 1;
}
uint8_t FindEND(void)
{
	return 1;
}
uint8_t FindWOB(void)
{
	return 1;
}
TANK_NUM_t TANK_NumSelected(void)
{
	return 1;
}
uint8_t CheckLinkingOK_GAS(void)
{
	return 1;
}
uint8_t CheckLinkingOK_TMT(void)
{
	return 1;
}
uint8_t DEV_Board(void)
{
	return 1;
}
uint8_t ReadLog(uint16_t var)
{
	return 0;
}
bool ReceiverRead(TankData_t *pData)
{
	return 0;
}
void Backlight_Set(uint8_t level)
{

}
bool CableCharging(void)
{
	return 1;
}
void HW_Cal_Init(Mfg_Calibration_t *Data)
{

}
void DEV_Rec_Init(Device_Records_t *Data)
{

}
void User_Set_Init(User_Settings_t *Data)
{

}
void SCUBA_Set_Init(Scuba_Settings_t *Data)
{

}
void TRIMIX_Set_Init(TRIMIX_Settings_t *Data)
{

}
void FREE_Set_Init(Free_Settings_t *Data)
{

}
void FREE_Rec_Init(Free_Records_t *Data)
{

}
void FLASH_Map_Init(FLASH_Map_t *Data)
{

}
void RetData_Init(void)
{

}
void NVD_RAMTOTAL_to_ExtEEPROM(void)
{

}
void CheckLooseLink_GAS(void)
{

}
void HAL_ADC_MspInit(void *pContent)
{

}
bool BatteryCharging(void)
{
	
}
void Predict_Deco_List(void)
{

}
void Switch_To_SPlow(void)
{

}
void Switch_To_SPhigh(void)
{

}
void Switch_To_SPcustom(void)
{

}
bool ReadAndDisplaySlates(uint8_t Idx)
{
	
}
TMT_NUM_t Find_TMT_Num_InSetting(void)
{
	return 0U;
}
TMT_NUM_t Find_TMT_Num_InLinking(void)
{
	return 0U;
}
NVD_status_t FindSCUBA_TMT_Status(NVD_DIVEMODE_t var, uint8_t varu8)
{
	return 0;
}
bool CheckLinkedOK_GAS(TANK_NUM_t n)
{
	return 0;
}
bool CheckIfGasToTMT_Assigned(void)
{
	return 1;
}
void Switch_Mode(void)
{

}
void Switch_Gas(void)
{

}
void Gnss_Off(void)
{

}
void Gnss_Sleep(void)
{

}
void Gnss_WakeUp(void)
{

}
void Gnss_On(void)
{

}
void CheckLooseLink_TMT(void)
{

}
void GPS_SaveLocations(void)
{

}
void Gnss_Calc_Distance(void)
{

}
void Gnss_WayFinderBrearing(void)
{
	
}
void GPS_SaveCurrentLocation(void)
{
	
}
void Wayfinder_ReadAllLocations(void)
{
	
}
void Update_Algo(void)
{
	
}
void Find_Gonsv_Lo(void)
{
	
}
void UpdateGF(void)
{
	
}
void Find_Gonsv_Hi(void)
{
	
}
void Find_GUI_MOD(void)
{
	
}
void AlarmAcknowledgement(void)
{
	
}
void Find_FiO2_DilPO2_Values(void)
{
	
}
void ReceiverInit(void)
{
	
}
void Check_SPcurrent(void)
{
	
}
void LogChartPOINT_X_Y(void)
{
	
}
void DisplayBmpFromEEPROM(bmpInforToDisplay_ts datInfo)
{

}
void Select_Target_Loc(void)
{

}
void IntinalizeGasVariables(void)
{

}
void AlarmInit(void)
{

}
bool Check_L_R(void)
{

}
int16_t L2R_PSI_Diff(void)
{

}
int16_t Find_SM_GSM_GTR(void)
{

}
bool GPS_LOC_4K_To_GUI_WayFinder(uint16_t data)
{
	return 1;
}
bool NVD_RAMBLOCK_to_ExtEEPROM (uint16_t block)
{
	return 1;
}
bool NoAlarmsWatingInQueue(void)
{
	return 1;
}
void HAL_Delay (uint32_t count)
{
	
}
uint16_t Find_GTR(void)
{
	return 1;
}
bool ICD_Check(uint8_t data, uint8_t dat1)
{
	return 1;
}
bool EE24CWxxX_ReadNBytes( uint16_t eeprom_addr, void * read_data, uint16_t size )
{
	return 0;
}
bool DoAlarmAck(void)
{

}
float SaltEqDensityFactor(void)
{

}
int16_t SmoothingCompassDeg(int16_t Deg)
{

}
void GPS_DeleteLocation(void)
{
	
}
int16_t DirectionCorrection(int16_t Deg)
{

}
void LCD_DeInit(void)
{
	
}
void LCD_Init(void)
{
	
}
void PrepareForBacklightSetAgain(void)
{

}
bool CheckTheBluetoothPasscodeDisplay(void)
{

}
void GUI_DISPLAY_Update(void)
{

}
void ErrHandle_EE(void)
{

}
void St2Ble_PowerDown(void)
{

}
/*************************** End of file ****************************/
