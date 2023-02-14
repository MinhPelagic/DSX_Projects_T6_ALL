/*******************************************************************************
 * @file        : L4X9_ble.h
 * @brief       : Comunication protocol, to be used for BLE comunication.
 *                
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Hoan
 * Modified by: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _L4X9_BLE_H_
#define _L4X9_BLE_H_

#define PELAGIC_PROTOCOL_START_BYTE             0xCD

#define PELAGIC_PROTOCOL_CMD_BLE_RESET          1	//!< Reset BLE device
#define PELAGIC_PROTOCOL_CMD_BLE_SETNAME        2	//!< Set BLE device name
#define PELAGIC_PROTOCOL_CMD_BLE_GETNAME        3	//!< Get BLE device name
#define PELAGIC_PROTOCOL_CMD_BLE_PWRDWN         8	//!< Power Down
#define PELAGIC_PROTOCOL_CMD_BLE_DISC           9	//!< Force disconnect
#define PELAGIC_PROTOCOL_CMD_SET_TX_POWER       10	//!< Set BLE Tx power
#define PELAGIC_PROTOCOL_CMD_BOOT_OTA           11	//!< Boot BLE into OTA DFU
#define PELAGIC_PROTOCOL_CMD_GET_INFO           12	//!< Get device info.

#define PELAGIC_PROTOCOL_CMD_READ_FLASH_DIRECT  13	//!< Read to flash Ble Direct
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH_DIRECT 14	//!< Write to flash Ble Direct
#define PELAGIC_PROTOCOL_CMD_SET_ADV_INTERVAL   15	//!< Set Ble Advertising interval
#define PELAGIC_PROTOCOL_CMD_SET_WR_REGION      16	//!< Sets the writable regions of the ExFlash for direct write

#define PELAGIC_PROTOCOL_CMD_ST                 17	//!< Process ST command	
#define PELAGIC_PROTOCOL_CMD_UART_OFF           18  //!< Turn off BLE UART

#define PELAGIC_PROTOCOL_CMD_READ_EEPROM        20	//!< Read to EEPROM
#define PELAGIC_PROTOCOL_CMD_WRITE_EEPROM       21	//!< Write to EEPROM
#define PELAGIC_PROTOCOL_CMD_READ_EEPROM_PAGE   22	//!< Read to EEPROM Page
#define PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_PAGE  23	//!< Write to EEPROM Page
#define PELAGIC_PROTOCOL_CMD_READ_EEPROM_BLOCK  24	//!< Read to EEPROM Block
#define PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_BLOCK 25	//!< Write to EEPROM Block


#define PELAGIC_PROTOCOL_CMD_READ_FLASH         53	//!< Read to flash
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH        54	//!< Write to flash
#define PELAGIC_PROTOCOL_CMD_READ_FLASH_256     26	//!< Read 256byte from flash
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH_256    27	//!< Write 256byte to flash
#define PELAGIC_PROTOCOL_CMD_READ_FLASH_1K      28	//!< Read 1kbyte from flash
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH_1K     29	//!< Write 1kbyte to flash
#define PELAGIC_PROTOCOL_CMD_READ_FLASH_2K      30	//!< Read 2kbyte from flash
#define PELAGIC_PROTOCOL_CMD_WRITE_FLASH_2K     31	//!< Write 2kbyte to flash

#define PELAGIC_PROTOCOL_CMD_RUTHERE            32
#define PELAGIC_PROTOCOL_CMD_WAKEUP_RDONLY      33
#define PELAGIC_PROTOCOL_CMD_WAKEUP_RDWR        34
#define PELAGIC_PROTOCOL_CMD_BACK2SURF          35
#define PELAGIC_PROTOCOL_CMD_ENTER_DEEPSLEEP    113
#define PELAGIC_PROTOCOL_CMD_ENTER_SLEEP        114


#define PELAGIC_PROTOCOL_CMD_SETCLOCK           36
#define PELAGIC_PROTOCOL_CMD_READ_A2D           37
#define PELAGIC_PROTOCOL_CMD_READ_INSTANT_PT    38


#define PELAGIC_PROTOCOL_CMD_READ_MFG_CAL       39
#define PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL      40
#define PELAGIC_PROTOCOL_CMD_READ_USER_SET      41
#define PELAGIC_PROTOCOL_CMD_WRITE_USER_SET     42
#define PELAGIC_PROTOCOL_CMD_READ_SCUBA_SET     43
#define PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET    44
#define PELAGIC_PROTOCOL_CMD_READ_FREE_SET      45
#define PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET     46
#define PELAGIC_PROTOCOL_CMD_READ_EXFLASH_MAP   47
#define PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP  48
#define PELAGIC_PROTOCOL_CMD_READ_DEV_REC       49
#define PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC      50
#define PELAGIC_PROTOCOL_CMD_READ_MY_INFO       51
#define PELAGIC_PROTOCOL_CMD_WRITE_MY_INFO      52
#define PELAGIC_PROTOCOL_CMD_READ_TRIMIX_SET    55
#define PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET   56

#define PELAGIC_PROTOCOL_CMD_SEND_NOTIFICATION          60
#define PELAGIC_PROTOCOL_CMD_SEND_AUTHENTICATION       151

#define PELAGIC_PROTOCOL_CMD_FW_UPDATE          112

#define PELAGIC_PROTOCOL_CMD_READ_SYSTEM_ERROR  115

#define PELAGIC_PROTOCOL_CMD_RESET_FUELGAUGE    120

#define PELAGIC_PROTOCOL_CMD_READ_ALS           121

#define PELAGIC_PROTOCOL_CMD_GPS_FW_UPDATE              130
#define PELAGIC_PROTOCOL_CMD_GPS_FW_UPDATE_CHECK        131

#define PELAGIC_PROTOCOL_CMD_READ_WE1                  140
#define PELAGIC_PROTOCOL_CMD_READ_WE2                  141
#define PELAGIC_PROTOCOL_CMD_READ_WE3                  142
#define PELAGIC_PROTOCOL_CMD_READ_O2_PERCENT            143

#define PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS 250
#define PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE    251


//Security defines
#define PASSCODE_ON             0xEA

typedef enum
{
  BLE_HDL_OFF = 0x00,
  BLE_HDL_WAIT_BLE_ON_1,
  BLE_HDL_ROM_INIT,
  BLE_HDL_WAIT_BLE_ON_2,
  BLE_HDL_RAM_INIT,
  BLE_HDL_NAME_INIT,
  BLE_HDL_READY,
  BLE_HDL_CONNECT,
  BLE_HDL_ERROR  
}BLE_HANDLER_t;


typedef enum __Pelagic_Frame_Packet_Type 
{
  PFRAME_PKT_TYPE_CMDT = 0,     //!< Command destination to BLE
  PFRAME_PKT_TYPE_CMDA = 1,     //!< Command destination to App processor STM32 or App
  PFRAME_PKT_TYPE_DATA = 2,     //!< Data packet for multiple data packet in response to a command or data to be sent for a command
  PFRAME_PKT_TYPE_RESP = 3      //!< Response to a command. Usually when only 1 single packet data in response to a command
} PFRAME_PKT_TYPE;

typedef struct __Pelagic_Packet_Header 
{
  uint8_t StartByte;            //!< Packet start code : PELAGIC_PROTOCOL_START_BYTE
  union 
  {
    uint8_t FrameType;
    struct 
    {
      uint8_t PktSeqNo:5;	//!< Incremental sequence number
      uint8_t Cont:1;		//!< 0 : no more packet to come, 1 : more packet to come
      uint8_t PktType:2;		//!< PFRAME_TYPE
    };
  };
  uint8_t CmdRsp;               //!< Command/Response code
  uint8_t Crc;                  //!< CRC of the whole packet. Intialize this to 0 before calc crc
  uint8_t PayloadLen;           //!< Payload length in bytes
} PPACKET_HEADER;

#define PELAGIC_PROTOCOL_MAX_PAYLOAD    (255UL)
#define PELAGIC_PROTOCOL_MTU            (PELAGIC_PROTOCOL_MAX_PAYLOAD + sizeof(PPACKET_HEADER))

typedef struct __Pelagic_Packet 
{
  PPACKET_HEADER Header;        //!< packet header
  uint8_t Payload[256];         //!< Variable length payload, can be more than 1 byte
} PPACKET;



/// Paload for response to PELAGIC_PROTOCOL_CMD_GET_INFO command
typedef struct __Pelagic_Cmd_Info_Resp 
{
  uint32_t HwRev;               //!< Hardware revision
  uint16_t FwVers;              //!< Firmware version
  uint32_t FwBuild;             //!< Firmware build number
  uint64_t Uid;
} PCMD_INFO_RESP;

/// Paload for response to Wakeup RD/RDWR command
typedef struct __Pelagic_Cmd_Wake_Resp 
{
  uint32_t ProductID;           //!< Hardware revision
  uint32_t FwVersion;           //!< Firmware version
  uint32_t EEpromCapacity;      //!< EEprom Capacity
  uint8_t Prefix[2];            //!>2-Byte Serial Number prefix, alpha-numeric format 
  uint8_t res0;
  uint8_t res1;
} PCMD_WAKE_RESP;

/// Ble Name struct
typedef struct __Pelagic_Cmd_BleName 
{
  char NameString[16];
  uint8_t NameLength;
  uint8_t res0;
  uint16_t res1;
} PCMD_BLENAME;

/// Payload for response to A2D Conversion command
typedef struct __Pelagic_Cmd_A2D_Resp 
{
  uint16_t Altitude_ft;         //!< Altitude in ft
  int16_t Temperature_mCx10;    //!< Temeprature Reading in milliCelsiusx10
  uint16_t Battery_mV;          //!< Battery Voltage in mV
  uint16_t hp;                  //!< HP Transducer Reading
} PCMD_A2D_RESP;

/// Payload for response to PT command
typedef struct __Pelagic_Cmd_PT_Resp 
{
  int32_t Pressure_ubarx100;    //!< Pressure Reading in ubarx100
  int32_t Temperature_mCx10;    //!< Temeprature Reading in milliCelsiusx10
} PCMD_PT_RESP;

/* System Time and Date structure */
typedef struct __Pelagic_Cmd_SetClock
{
  uint8_t AA;	// Home (0) or Away (1) 
  uint8_t BB;	// Dual time: 0->OFF; 1->ON;
  uint8_t HH;	// Hours (BCD format)
  uint8_t MM;	// Minutes (BCD format)
  uint8_t SS;	// Seconds (BCD format)
  uint8_t WD;	// WEEK DAY 1: Mon; 7: Sun;
  uint8_t DD;	// DAY (BCD format)
  uint8_t MO;	// MONTH (BCD format)
  uint8_t YY;	// YEAR (BCD format)
} PCMD_SETCLOCK_DATA;

/// Payload for Memmory Read/Write command
typedef struct __Pelagic_Cmd_Mem
{
  uint32_t Addr;                //!< Memory address
  uint32_t Len;                 //!< Length in bytes
  uint8_t res;                  //!< Reserved
} PCMD_MEM_RW;

/// Payload for No Parameter command
typedef struct __Pelagic_Cmd_NoPar
{
  uint32_t res0;                //!< Reserved
  uint32_t res1;                //!< Reserved
  uint8_t res2;                 //!< Reserved
} PCMD_NOPAR_RW;

typedef struct
{
  uint32_t  SerialNum   :24;
  uint32_t  Reserved    :8;
}O2_Serial_4Bytes;

/// Payload for response to O2 Analyzer Calibration/Analysis commands
typedef struct __Pelagic_Cmd_O2_Resp 
{
  uint16_t O2_ADC_Offset;        //!< (mV) O2 Analyzer O2_ADC_Offset, the intercept point at Vadc axis
  uint16_t O2_ADC_Calib;         //!< (mV) O2 Analyzer O2_ADC_Calib, the calibration point at Vadc axis
  uint16_t O2_ADC_Analyze1;      //!< (mV) O2 Analyzer O2_ADC_Analyze1, the analyze point at Vadc axis  
  uint16_t O2_ADC_Analyze2;      //!< (mV) O2 Analyzer O2_ADC_Analyze2, the analyze point at Vadc axis
  uint16_t O2_Pct_Calib;         //!< (%) FO2x10 percentage at Calibration point
  uint16_t O2_Pct_Analyze1;      //!< (%) FO2x10 percentage at Analyze1 point
  uint16_t O2_Pct_Analyze2;      //!< (%) FO2x10 percentage at Analyze2 point
  uint16_t res;                  //!< (%) FO2x10 percentage at Analyze2 point
  O2_Serial_4Bytes O2_Analyzer_SN;  /* 4-Byte, 123456 saved as ascii 0x56, 0x34, 0x12 */
} PCMD_O2ANALYZER_RESP;

#define PACKET_READ_MAX_SIZE		96	// This value is defined based on max BLE notification size

typedef struct __Pelagic_Cmd_Resp 
{
  uint8_t RespCode;
  bool RespReceived;
} PCMD_RESP;

typedef struct __Pelagic_Cmd_Read4ByteData 
{
  uint32_t ALS_Data_U32;
} PCMD_ALS_RESP;

/// Response payload
#define CMD_RESP_READY                  1      //!< Ready to receive data
#define CMD_RESP_DONE                   2      //!< Command/Read/write completed
#define CMD_RESP_AOFR                   3      //!< Address out of Range
#define CMD_RESP_FC                     4      //!< Corrupted Frame Received
#define CMD_RESP_DP                     5      //!< Data Read/Write Processed
#define CMD_RESP_NORW         		6      //!< Data Write Denied
#define CMD_RESP_NOCMD         		7      //!< Command not implemented/available
#define CMD_RESP_BOOTRECBAD             8      //!< BootRecord Bad
#define CMD_RESP_EXFLASHFWBAD           9      //!< ExFlash FW Bad
#define CMD_RESP_ACCESSDENIED           10     //!< Access Denied because no valid passcode received
#define CMD_RESP_SLEEP                  11     //!< Access Denied because no wake command received
#define CMD_RESP_NOPASSCODE             12     //!< No PassCode required
#define CMD_RESP_INVALIDPASSCODE        13     //!< Invalid PassCode

#define CMD_RESP_ST_READY               14     //!< Ready to receive ST packet data
#define CMD_RESP_ST_DONE                15     //!< ST packet process completed
#define CMD_RESP_FGRESET_ERR            16     //!< FuelGauge Reset Error
#define CMD_RESP_CRC_ERR                17     //!< Data Struct Crc Error
#define CMD_RESP_GPS_FW_STARTED         30     //!< Gps FwUpdate Started
#define CMD_RESP_GPS_FW_OK              31     //!< Gps FwUpdate Successfull
#define CMD_RESP_GPS_FW_BUSY            32     //!< Gps FwUpdate Loading
#define CMD_RESP_GPS_FW_ERR             33     //!< Gps FwUpdate Not Successfull
#define CMD_RESP_ABORT                  0xFF   //!< Resource in use, Cmd aborted

#define BLE_PASSCODE_NOT_CHECKED        0
#define BLE_PASSCODE_INCORRECT          1
#define BLE_PASSCODE_CORRECT            2

// BLE Status Lines Macros

//------------------------------------------------------------------------------------------------------------------------------
// Set P3 Line to High during ST using Flash
#define ST_FLASH_USE            HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_SET)
// Set P3 Line to Low when ST NOT using Flash
#define ST_FLASH_RELASE         HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_RESET)

// If 1 BLE is using Flash; If 0 BLE not using Flash
#define BLE_IS_USING_FLASH      (HAL_GPIO_ReadPin(BT_P1_PORT, BT_P1_PIN) == 1)

// If 1 BLE is ready and advertising
#define BLE_IS_READY            ((HAL_GPIO_ReadPin(BT_P2_PORT, BT_P2_PIN)==0) && (HAL_GPIO_ReadPin(BT_P4_PORT, BT_P4_PIN)==1))

// If 1 BLE is connected to App
#define BLE_IS_CONNECTED        ((HAL_GPIO_ReadPin(BT_P2_PORT, BT_P2_PIN)==1) && (HAL_GPIO_ReadPin(BT_P4_PORT, BT_P4_PIN)==1))

// If 1 BLE is Off
#define BLE_IS_OFF              ((HAL_GPIO_ReadPin(BT_P2_PORT, BT_P2_PIN)==0) && (HAL_GPIO_ReadPin(BT_P4_PORT, BT_P4_PIN)==0))

//------------------------------------------------------------------------------------------------------------------------------
// Set P3 Line to High during ST using Flash
#define PROD_ST_FLASH_USE       HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_SET)
// Set P3 Line to Low when ST NOT using Flash
#define PROD_ST_FLASH_RELASE    HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_RESET)

// If 1 BLE is using Flash; If 0 BLE not using Flash
#define PROD_BLE_IS_USING_FLASH (HAL_GPIO_ReadPin(PROD_BT_P1_PORT, PROD_BT_P1_PIN) == 1)

// If 1 BLE is ready and advertising
#define PROD_BLE_IS_READY       ((HAL_GPIO_ReadPin(PROD_BT_P2_PORT, PROD_BT_P2_PIN)==0) && (HAL_GPIO_ReadPin(PROD_BT_P4_PORT, PROD_BT_P4_PIN)==1))

// If 1 BLE is connected to App
#define PROD_BLE_IS_CONNECTED   ((HAL_GPIO_ReadPin(PROD_BT_P2_PORT, PROD_BT_P2_PIN)==1) && (HAL_GPIO_ReadPin(PROD_BT_P4_PORT, PROD_BT_P4_PIN)==1))

// If 1 BLE is Off
#define PROD_BLE_IS_OFF         ((HAL_GPIO_ReadPin(PROD_BT_P2_PORT, PROD_BT_P2_PIN)==0) && (HAL_GPIO_ReadPin(PROD_BT_P4_PORT, PROD_BT_P4_PIN)==0))
//------------------------------------------------------------------------------------------------------------------------------

bool ProcessPacket(PPACKET *pPkt);
bool SendPacket(PPACKET *pPacket);
bool SendCmd(PFRAME_PKT_TYPE CmdType, uint8_t CmdRsp, void *pParam, int ParamLen);
bool SendDataRsp(PFRAME_PKT_TYPE Type, uint8_t CmdRsp, void *pData, int DataLen);

void ProcessCmd(PPACKET *pPkt);
void ProcessData(PPACKET *pPkt);
void ProcessResp(PPACKET *pPkt);

bool CheckPacket(PPACKET *pPkt);
bool CheckAccess(void);
bool CheckAwake(void);
bool CheckWriteEnable(void);

bool FlashReadCmd(PPACKET * const pPk);
bool FlashReadData(PPACKET * const pPk);
bool FlashWriteCmd(PPACKET * const pPkt);
bool FlashWriteData(PPACKET * const pPk);


bool EEpromReadCmd(PPACKET * const pPk);
bool EEpromReadData(PPACKET * const pPk);
bool EEpromWriteCmd(PPACKET * const pPkt);
bool EEpromWriteData(PPACKET * const pPk);


bool StRecvCmd(PPACKET * const pPkt);
bool StSendCmd(PPACKET * const pPkt);


bool NVDReadCmd(PPACKET * const pPkt);
bool NVDReadData(PPACKET * const pPk);
bool NVDWriteCmd(PPACKET * const pPkt);
bool NVDWriteData(PPACKET * const pPk);
bool NVDSaveData(PPACKET * const pPk);


void St2Ble_SetName(PCMD_BLENAME Name);
bool St2Ble_GetName(void);
bool St2Ble_UART_Off(void);
void St2Ble_SetTxPwr(int8_t dBm);
void St2Ble_SetAdvInterval(uint32_t interval_ms);
bool St2Ble_SetExFlashWriteableRegions(uint32_t addressR0, uint32_t lengthR0, uint32_t addressR1, uint32_t lengthR1, uint32_t addressR2, uint32_t lengthR2);
void St2Ble_PowerOn(void);
void St2Ble_PowerDown(void);

void GeneratePassCode (void);
bool PassCodeCheck(uint8_t *passcode);

bool IsMacIdAllZero(uint8_t *macid);
bool CheckMacId(uint8_t *macid);

extern PCMD_BLENAME BleName;
extern bool BleNameSetRequest;
extern bool BLE_AcessInitDone;	//YeuShyr 20210914 for BLE Passcode to work correctly
/*******************************************************************************
 * @brief   Reset Ble
 *
 * @note        
 ******************************************************************************/
void Ble_Reset(void);

/*******************************************************************************
 * @brief   Ble Ram Data Initializer function
 *
 * @note        
 ******************************************************************************/
bool Ble_RamInit (void);

/*******************************************************************************
 * @brief   Ble Handler function
 *
 * @note         
 ******************************************************************************/
void Ble_Handler (void);

#endif //_L4X9_BLE_H_