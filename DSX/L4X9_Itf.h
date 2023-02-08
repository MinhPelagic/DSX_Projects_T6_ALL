/*******************************************************************************
 * @file        : DSXtf.h
 * @brief       : Data Structures Interface File
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

   
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef _L4X9_ITF_H_
#define _L4X9_ITF_H_


/******************************************************************************
 * @brief   Link Dive_Info data with *GetDiveInfo()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose Dive Info in read only mode*/
const Dive_Info_struct_t *GetDiveInfo(void);

#define fSurfP_mbar             Dive_Info.SurfacePressure_mbar           /* Surface Pressure Expressed in mbar */
#define fSurfP_inHg             Dive_Info.SurfacePressure_inHg;          /* Surface Pressure Expressed in inHg */
  
#define u16Altitude_m           Dive_Info.Altitude_m                     /* Barometric Altitude in meters */
#define u16Altitude_ft          Dive_Info.Altitude_ft                    /* Barometric Altitude in feets */
  
#define fWaterP_mbar            Dive_Info.WaterPressure_mbar             /* Water Pressure expressed in mbar; is relative Absolut pressure minus Surface Pressure */ 
#define fWaterP_inHg            Dive_Info.WaterPressure_inHg             /* Water Pressure expressed in inHg; is relative Absolut pressure minus Surface Pressure */ 

#define fDepthM                 (Dive_Info.WaterDepth_m+0.0003) 
#define fDepthFt                (Dive_Info.WaterDepth_ft+0.001)    // round up to a integer for 99.99999999 (to become 100.00099999) 

#define fMaxDepthM              (Dive_Info.MaxWaterDepth_m+0.0003)
#define fMaxDepthFt             (Dive_Info.MaxWaterDepth_ft+0.001) // round up to a integer for 99.99999999 (to become 100.00099999) 

#define fAvgDepthM              (Dive_Info.AvgWaterDepth_m+0.0003) 
#define fAvgDepthFt             (Dive_Info.AvgWaterDepth_ft+0.001) // round up to a integer for 99.99999999 (to become 100.00099999) 

#define dDepthM                 (uint16_t)(Dive_Info.WaterDepth_m+0.0003) 
#define dDepthFt                (uint16_t)(Dive_Info.WaterDepth_ft+0.001)    // round up to a integer for 99.99999999 (to become 100.00099999) 

#define dMaxDepthM              (uint16_t)Dive_Info.MaxWaterDepth_m+0.0003)
#define dMaxDepthFt             (uint16_t)(Dive_Info.MaxWaterDepth_ft+0.001) // round up to a integer for 99.99999999 (to become 100.00099999) 

#define dAvgDepthM              (uint16_t)(Dive_Info.AvgWaterDepth_m+0.0003) 
#define dAvgDepthFt             (uint16_t)(Dive_Info.AvgWaterDepth_ft+0.001) // round up to a integer for 99.99999999 (to become 100.00099999) 

#define fDemoDepthFt            Demo_Depth_ft
#define fDemoPmbar              Demo_Pressure_mbar

#define bStatus                 Dive_Info.Status                   // Surf, Dive, After Dvie


#define u32StartDiveTime_s      Dive_Info.StartDiveTime_s          // Start Dive Time in total seconds
#define u32DiveTime_s           Dive_Info.DiveTime_s               // Total Dive Time in total seconds                      
#define u32PrevDiveTime_s       Dive_Info.PrevDiveTime_s           // End Dive Time in total seconds

#define u32DiveTimeHr          (Dive_Info.DiveTime_s/3600)          // Total Dive Time in total hours of XXXX:00:00   
#define u32DiveTimeMin        ((Dive_Info.DiveTime_s/60)%60)             // Total Dive Time in total minutess of 00:XX:00   
#define u32DiveTimeSec         (Dive_Info.DiveTime_s%60)            // Dive Time in sec of 00:00:XX  

#define u16DiveTimeTotalSec     Dive_Info.TotalDiveTime

#define u32StartSurfTime_s      Dive_Info.StartSurfTime_s          // Start Surf Time in total seconds
#define u32SurfTime_s           Dive_Info.SurfTime_s               // Total Surf Time in total seconds  
#define u32PrevSurfTime_s       Dive_Info.PrevSurfTime_s           // End Surf Time in total seconds        

#define u32SurfTimeHr           (Dive_Info.SurfTime_s/3600)        // Total Surf Time in total hours of XXXX:00:00
#define u32SurfTimeMin         ((Dive_Info.SurfTime_s/60)%60)      // Total Surf Time in total minutess of 00:XX:00
#define u32SurfTimeSec          (Dive_Info.SurfTime_s%60)          // Surf Time in sec of 00:00:XX  

#define u32SleepTime_s          Dive_Info.SleepTime_s              // Total Sleep Time in total seconds  

#define u32NewdayTime_s         Dive_Info.NewdayTime_s                 // Total Sleep Time in total seconds  

#define u32UpdateTimeStamp      UpdateTimeStamp                         // Time Stamp in total seconds      
#define int8AvgTempC            (int8_t)TP_Info.AverageTemperature_C
#define int8AvgTempF            (int8_t)TP_Info.AverageTemperature_F

#define int8InstTempC            (int8_t)TP_Info.InstantTemperature_C
#define int8InstTempF            (int8_t)TP_Info.InstantTemperature_F

#define DecoStatus              ((DecoTime[1]>0)||(DecoTime[2]>0))      // when Dive Mode's Deco Stop is needed

/******************************************************************************
 * @brief   Link Temperature and Pressure data with *GetTPInfo()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose TP Info in read only mode*/
const TP_Info_struct_t *GetTPInfo(void);


/******************************************************************************
 * @brief   Link Battery mV data with *GetSystemSupplyMonitor()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose System Supply Info in read only mode*/
const L4X9_SystemSupplyMonitor_t *GetSystemSupplyMonitor(void);

#define BatteryMv       GetSystemSupplyMonitor()->Battery_mV


/******************************************************************************
 * @brief   Link Time data with *GetPstTime()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose System Time Info in read only mode*/
const SystemTimeDate_t *GetPstTime(void);

#define TimeHr          GetPstTime()->Hour
#define TimeMin         GetPstTime()->Minute
#define TimeSec         GetPstTime()->Second

#define DEPTH_FT        DepthOnFT



/******************************************************************************
 * @brief   Link Temperature and Pressure data with *GetDEV_Rec()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose Device Record in read only mode*/
const Device_Records_t *GetDEV_Rec(void);



/******************************************************************************
 * @brief   Link       data with *GetUSER_Set()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose Device Record in read only mode*/
const User_Settings_t *GetUSER_Set(void);



/******************************************************************************
 * @brief   Link Dive Setting data with *GetSCUBA_Set()
 *
 * @note        
 *              
 ******************************************************************************/
/* Linker to expose Dive Setting     in read only mode*/
const Scuba_Settings_t *GetSCUBA_Set(void);

#define CURRENT_TANK_NUM        Current_Tank_Num()
#define CURRENT_TANK_NUM_CC     TRIMIX_Set.CurrGasNumber_CC
#define CURRENT_TANK_NUM_OC     TRIMIX_Set.CurrGasNumber_OC
#define CURRENT_TANK_NUM_SM     TRIMIX_Set.CurrGasNumber_SM
#define CURRENT_TANK_NUM_BO     TRIMIX_Set.CurrGasNumber_BO
#define CURRENT_TMT_NUM_GSM     TRIMIX_Set.CurrTMT_Number_GSM
#define CURRENT_TMT_NUM_GAUGE   TRIMIX_Set.CurrTMT_Number_GAUGE
#define CURRENT_TMT_NUM         Current_TMT_Num()

#define SET_GAS0_FO2    SCUBA_Set.FO2A[0]
#define SET_GAS1_FO2    SCUBA_Set.FO2A[1]
#define SET_GAS2_FO2    SCUBA_Set.FO2A[2]
#define SET_GAS3_FO2    SCUBA_Set.FO2A[3]
#define SET_GAS4_FO2    SCUBA_Set.FO2A[4]
#define SET_GAS5_FO2    SCUBA_Set.FO2A[5]
#define SET_GAS6_FO2    SCUBA_Set.FO2A[6]

#define SET_GAS0_PO2_ALARM   SCUBA_Set.PO2A[0]
#define SET_GAS1_PO2_ALARM   SCUBA_Set.PO2A[1]
#define SET_GAS2_PO2_ALARM   SCUBA_Set.PO2A[2]
#define SET_GAS3_PO2_ALARM   SCUBA_Set.PO2A[3]
//#define SET_GAS4_PO2_ALARM   SCUBA_Set.PO2A[4]
//#define SET_GAS5_PO2_ALARM   SCUBA_Set.PO2A[5]
//#define SET_GAS6_PO2_ALARM   SCUBA_Set.PO2A[6]

#define GAS1_MOD SCUBA_Set.MOD[1]
#define GAS2_MOD SCUBA_Set.MOD[2]
#define GAS3_MOD SCUBA_Set.MOD[3]
//#define GAS4_MOD SCUBA_Set.MOD[4]
//#define GAS5_MOD SCUBA_Set.MOD[5]
//#define GAS6_MOD SCUBA_Set.MOD[6]

//==============================================================================
#define CC0_FO2    TRIMIX_Set.CC_FO2[0]
#define CC1_FO2    TRIMIX_Set.CC_FO2[1]
#define CC2_FO2    TRIMIX_Set.CC_FO2[2]
#define CC3_FO2    TRIMIX_Set.CC_FO2[3]
#define CC4_FO2    TRIMIX_Set.CC_FO2[4]
#define CC5_FO2    TRIMIX_Set.CC_FO2[5]
#define CC6_FO2    TRIMIX_Set.CC_FO2[6]

#define CC0_PO2_ALM   TRIMIX_Set.CC_PO2A[0]
#define CC1_PO2_ALM   TRIMIX_Set.CC_PO2A[1]
#define CC2_PO2_ALM   TRIMIX_Set.CC_PO2A[2]
#define CC3_PO2_ALM   TRIMIX_Set.CC_PO2A[3]
#define CC4_PO2_ALM   TRIMIX_Set.CC_PO2A[4]
#define CC5_PO2_ALM   TRIMIX_Set.CC_PO2A[5]
#define CC6_PO2_ALM   TRIMIX_Set.CC_PO2A[6]

#define CC0_FHe TRIMIX_Set.CC_FHe[0]
#define CC1_FHe TRIMIX_Set.CC_FHe[1]
#define CC2_FHe TRIMIX_Set.CC_FHe[2]
#define CC3_FHe TRIMIX_Set.CC_FHe[3]
#define CC4_FHe TRIMIX_Set.CC_FHe[4]
#define CC5_FHe TRIMIX_Set.CC_FHe[5]
#define CC6_FHe TRIMIX_Set.CC_FHe[6]
//==============================================================================
#define OC0_FO2    TRIMIX_Set.OC_FO2[0]
#define OCL_FO2    TRIMIX_Set.OC_FO2[1]
#define OCR_FO2    TRIMIX_Set.OC_FO2[2]
#define OC3_FO2    TRIMIX_Set.OC_FO2[3]
#define OC4_FO2    TRIMIX_Set.OC_FO2[4]
#define OC5_FO2    TRIMIX_Set.OC_FO2[5]
#define OC6_FO2    TRIMIX_Set.OC_FO2[6]

#define OC0_PO2_ALM   TRIMIX_Set.OC_PO2A[0]
#define OCL_PO2_ALM   TRIMIX_Set.OC_PO2A[1]
#define OCR_PO2_ALM   TRIMIX_Set.OC_PO2A[2]
#define OC3_PO2_ALM   TRIMIX_Set.OC_PO2A[3]
#define OC4_PO2_ALM   TRIMIX_Set.CC_PO2A[4]
#define OC5_PO2_ALM   TRIMIX_Set.CC_PO2A[5]
#define OC6_PO2_ALM   TRIMIX_Set.CC_PO2A[6]

#define OC0_FHe  TRIMIX_Set.OC_FHe[0]
#define OCL_FHe  TRIMIX_Set.OC_FHe[1]
#define OCR_FHe  TRIMIX_Set.OC_FHe[2]
#define OC3_FHe  TRIMIX_Set.OC_FHe[3]
#define OC4_FHe  TRIMIX_Set.OC_FHe[4]
#define OC5_FHe  TRIMIX_Set.OC_FHe[5]
#define OC6_FHe  TRIMIX_Set.OC_FHe[6]
//==============================================================================
#define SM0_FO2    TRIMIX_Set.SM_FO2[0]
#define SM1_FO2    TRIMIX_Set.SM_FO2[1]
#define SM2_FO2    TRIMIX_Set.SM_FO2[2]
#define SM3_FO2    TRIMIX_Set.SM_FO2[3]
#define SM4_FO2    TRIMIX_Set.SM_FO2[4]
#define SM5_FO2    TRIMIX_Set.SM_FO2[5]
#define SM6_FO2    TRIMIX_Set.SM_FO2[6]

#define SM0_PO2_ALM   TRIMIX_Set.SM_PO2A[0]
#define SM1_PO2_ALM   TRIMIX_Set.SM_PO2A[1]
#define SM2_PO2_ALM   TRIMIX_Set.SM_PO2A[2]
#define SM3_PO2_ALM   TRIMIX_Set.SM_PO2A[3]
#define SM4_PO2_ALM   TRIMIX_Set.SM_PO2A[4]
#define SM5_PO2_ALM   TRIMIX_Set.SM_PO2A[5]
#define SM6_PO2_ALM   TRIMIX_Set.SM_PO2A[6]

#define SM0_FHe TRIMIX_Set.SM_FHe[0]
#define SM1_FHe TRIMIX_Set.SM_FHe[1]
#define SM2_FHe TRIMIX_Set.SM_FHe[2]
#define SM3_FHe TRIMIX_Set.SM_FHe[3]
#define SM4_FHe TRIMIX_Set.SM_FHe[4]
#define SM5_FHe TRIMIX_Set.SM_FHe[5]
#define SM6_FHe TRIMIX_Set.SM_FHe[6]
//==============================================================================


#define u8DiveAlgo              SCUBA_Set.DivingAlgo
#define u8TankNum               SCUBA_Set.TankNumber
#define u8ConsvDSAT             SCUBA_Set.ConservDSAT

#define u8TMT [u8TankNum]        SCUBA_Set.TMT[SCUBA_Set.TankNumber]
//#define u8PO2A[u8TankNum]      SCUBA_Set.PO2A[SCUBA_Set.TankNumber]
#define u8FO2A [u8TankNum]       SCUBA_Set.FO2A[SCUBA_Set.TankNumber]
#define u8FN2A [u8TankNum]       SCUBA_Set.FN2A[SCUBA_Set.TankNumber]
#define u8FHeA [u8TankNum]       SCUBA_Set.FHeA[SCUBA_Set.TankNumber]

#define u8PO2A_1                 SCUBA_Set.PO2A[1]
#define u8PO2A [u8TankNum]       SCUBA_Set.PO2A[SCUBA_Set.TankNumber]
// #define u8PO2A [u8TankNum]    SCUBA_Set.PO2A[SCUBA_Set.TankNumber]

#define DECOSTOP_Depth          DecoStop[1]
#define DECOSTOP_Min            Total_DST


/******************************************************************************
 * @brief   Link LOG data with GetLOG_Data()
 *
 * @note
 *
 ******************************************************************************/
/* Linker to expose LOG Data    in read only mode*/
const LOG_Data_t *GetLOG_Data(void);


#endif // _L4X9_ITF_H_

