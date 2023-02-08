/*******************************************************************************
 * @file        : TMT_Receiver.h
 * @brief       : Middleware for TMT_Receiver
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2021-2021.
 * Author: YeuShyr Wu           Pelagic Pressure Systems or Aqualung
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/
   
#ifndef _TMT_RECEIVER_H_
#define _TMT_RECEIVER_H_

#define TMT_BUFFER_SIZE MAX_TOTAL_TANK_NUM+2

/*******************************************************************************
 * @brief   Data Structs
 ******************************************************************************/

typedef struct {
  uint32_t TMTID[MAX_TOTAL_TANK_NUM+1]; /* 4-Byte x 7 Transmitter 1 ID */
  TMT_Bit_t TMT_On;
  TMT_Bit_t TMT_Linked;
} TMT_Stat_t;



/*******************************************************************************
    
  CheckLooseLink_TMT( n ) function is to check if TMT_n in linking (NOT lose link)
  
  LooseLink: 
  
  2: ==> Link_OK;    

  1: ==> Link_LOOSE;    Loose Link ( > 20 seconds after lost )

  0: ==> Link_OFF;      OFF Link ( > 60 seconds after lost )
  
  Good for all modes (CC, OC, SM, GSM, Gauge) TMT-n 

********************************************************************************/
typedef enum
{
    LooseLink_OFF,      // TMT OFF Link
    LooseLink_LOOSE,    // TMT Loose Link  
    LooseLink_OK,       // TMT Linking OK
}LOOSE_LINK_t;



/*******************************************************************************
 * @brief	Initialize electromagnetic pulse receiver
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param	pCfg : Pointer to configuration data
 *
 * @return	true - Success
*******************************************************************************/
bool EMPulseRcvrInit(EMPulseRcvrDev_t *pDev, EMPuslseRcvrCfg_t const *pCfg);

/*******************************************************************************
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
*******************************************************************************/
void EMPulseRcvrPoweroff(EMPulseRcvrDev_t *pDev);

/*******************************************************************************
 * @brief	Read decoded tank data
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param 	pData : Pointer to buffer to receive tank data
 *
 * @return	true - Tank data is valid (passed checksum)
 * 			false - Checksum failed
*******************************************************************************/
bool EMPulseRcvrRead(EMPulseRcvrDev_t *pDev, TankData_t *pData);

/*******************************************************************************
 * @brief	Read raw packet
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param 	pPkt : Pointer to buffer to receive raw packet data
 *
 * @return	Time stamp of the return packed
*******************************************************************************/
uint32_t EMPulseRcvrPacket(EMPulseRcvrDev_t *pDev, EMPulsePacket_t *pPkt);



/*******************************************************************************
 * @brief	TMT Receiver Manager 
 *
 * @param	pDev : Pointer to EMPulse device handle to initialize
 * @param 	pPkt : Pointer to buffer to receive raw packet data
 *
 * @return	Time stamp of the return packed
*******************************************************************************/
void TMT_Receiver_Manager(void);

/*******************************************************************************
*   L2R_PSI_Diff() to find the difference between R and L Tank
*
*   Only work for SM or GSM modes
*
*   Positive L > R      Negative L < R;   
*******************************************************************************/
int16_t L2R_PSI_Diff(void);      // Positive when L > R      Negative when L < R

/*******************************************************************************
*   Check_L_R() to check if it is time to switch 
*               from Low PSI tank to High PSI tank (L <-> R)
*
*   Only doing this check when Tank_L or Tank_R is in used at SM mode
*                              TMT_1 or TMT_2 is in used at GSM modes
*******************************************************************************/
bool Check_L_R(void);

/*******************************************************************************
*   Switch_L_R() to switch from a low PSI tank to a high PSI tank (L <-> R)
*
*   Only work for SM or GSM modes
*
*   Allow Diver to do this only when Alarming is triggerred by Check_L_R( )    
*******************************************************************************/
void Switch_L_R(void);

/*******************************************************************************
*   Find_GTR( ) is to output the ATR value after cirtain time after Switch Tank
*
*   No GTR in the first 40 seconds after Switching Tank
*
*   ATR_Tstamp_s starts to increment only > 40 seconds after Switch Tank      
*******************************************************************************/
uint16_t Find_GTR(void);
/*******************************************************************************

    Pre-Violation Mode

    NVD_DIVEMODE_t PreViolationMode(void);

    When No Violation: to find the Current Mode

    When New Dive after Violation: to find the ReturnDiveMode 

    useful for TMT-x tracking, which's mapping is NOT changed before and after Violation

*******************************************************************************/
NVD_DIVEMODE_t PreViolationMode(void);

extern TMT_Connection_t GUI_TMT_Battery[];
extern TANK_NUM_t GUI_TankN_Linked;        // Linked ===> Gas# and TMT# relationship is built, can be #0 to #6
extern uint32_t GUI_ShowTMTid;        
extern uint32_t GUI_TMT_SerialNum_InSetting; // GUI_TMT_SerialNum_InSetting is the TMT-x in setting
extern uint32_t GUI_TMT_InSetting_PSI;
extern uint8_t GUI_TMT_InSetting_Battery;
extern TMT_Connection_t GUI_TMT_Connection_Status;
extern uint32_t GUI_TMT_id[];
extern uint32_t GUI_TMT_TimeStamp[];
extern int32_t GUI_TMT_MonoClock[];
extern uint16_t GUI_TMT_PressPSI[];
extern LOOSE_LINK_t GUI_TMT_InLinking[];
extern uint8_t GUI_GAS_InLinking[];
extern uint16_t GUI_CC6_PressPSI;
extern uint32_t GUI_CC6_TimeStamp;
extern TankData_t g_Data;
extern TankData_t g_TMT_Data[];
extern bool CheckIfGasToTMT_Assigned();
extern TMT_NUM_t FindTMTofGAS(void);
extern TMT_NUM_t FindTMTofGASifViolation(void);
extern bool CheckLinkingOK_GAS(TANK_NUM_t);
extern LOOSE_LINK_t CheckLooseLink_GAS(TANK_NUM_t);
extern LOOSE_LINK_t CheckLooseLink_TMT(TMT_NUM_t);
extern TMT_NUM_t Find_TMT_Num_InLinking(void);     // using GUI_TankN_Linked, 
extern void GasTankPSI_RecorderInit(void);              // GasTankPSI_Recorder Initialization for each new dive
extern void GasTankPSI_RecorderToSave(void);            // GasTankPSI_RecorderToSave to save data to Log and Profile at the end of each new dive
#endif
