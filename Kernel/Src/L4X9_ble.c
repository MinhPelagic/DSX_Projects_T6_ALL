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
#include "L4X9_includes.h"

/* Define to prevent recursive inclusion -------------------------------------*/
#ifdef _L4X9_BLE_H_

PCMD_BLENAME BleName;
bool BleNameSetRequest = false;

PCMD_RESP BleRespone;

bool WriteEnable = false;
bool Awake = false;
bool AccessGranted = false;

int32_t g_MemWriteAddr = -1;
int32_t g_MemWriteSize = 0;
int32_t g_MemReadAddr = -1;
int32_t g_MemReadSize = 0;

int32_t g_StCmdSize = 0;

int32_t g_NVDWriteAddr = -1;
int32_t g_NVDWriteSize = 0;
int32_t g_NVDReadAddr = -1;
int32_t g_NVDReadSize = 0;

bool DataCrcError = false;

bool isBleConnected_Pre = false;      // R1006 added for 
bool isBleConnected = false;
/*
int min( int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
*/
bool SendPacket(PPACKET *pPacket)
{
    pPacket->Header.Crc = 0;

    int len = pPacket->Header.PayloadLen + sizeof(PPACKET_HEADER);

    pPacket->Header.Crc = crc8_ccitt((uint8_t*)pPacket, len, 0);

    pPacket->Payload[pPacket->Header.PayloadLen] = 0;

    return UART_FillTxFifoSlip( BT_USART, &BLE_FIFO_Tx, (uint8_t*)pPacket, len ) > 0;
}

bool SendCmd(PFRAME_PKT_TYPE CmdType, uint8_t Cmd, void *pParam, int ParamLen)
{
    uint8_t buf[PELAGIC_PROTOCOL_MTU];
    PPACKET *pkt = (PPACKET*)buf;

    pkt->Header.StartByte = PELAGIC_PROTOCOL_START_BYTE;
    pkt->Header.PktType = CmdType;
    pkt->Header.PktSeqNo = 0;
    pkt->Header.Cont = 0;
    pkt->Header.CmdRsp = Cmd;
    pkt->Header.PayloadLen = ParamLen;

    if (ParamLen > 0)
    {
        memcpy(pkt->Payload, pParam, ParamLen);
    }

    return SendPacket(pkt);
}

bool SendDataRsp(PFRAME_PKT_TYPE Type, uint8_t CmdRsp, void *pData, int DataLen)
{
    uint8_t buf[PELAGIC_PROTOCOL_MTU];
    PPACKET *pkt = (PPACKET*)buf;
    uint8_t *p = (uint8_t*)pData;

    pkt->Header.StartByte = PELAGIC_PROTOCOL_START_BYTE;
    pkt->Header.PktType = Type;
    pkt->Header.PktSeqNo = 0;
    pkt->Header.Cont = 0;
    pkt->Header.CmdRsp = CmdRsp;

    while (DataLen > 0)
    {
        int l = min(DataLen, PELAGIC_PROTOCOL_MAX_PAYLOAD);
        memcpy(pkt->Payload, p, l);

        if (l < DataLen)
        {
            pkt->Header.Cont = 1;
        }
        else
        {
            pkt->Header.Cont = 0;
        }
        pkt->Header.PayloadLen = l;

        if (SendPacket(pkt) == false)
        {
            return false;
        }
        DataLen -= l;
        p += l;
        pkt->Header.PktSeqNo++;
    }

    return true;
}

bool CheckPacket(PPACKET *pPkt)
{
    if (pPkt->Header.StartByte != PELAGIC_PROTOCOL_START_BYTE)
    {
        return false;
    }

    int len = (int)pPkt->Header.PayloadLen + sizeof(PPACKET_HEADER);
    uint8_t crc = pPkt->Header.Crc;

    pPkt->Header.Crc = 0;

    pPkt->Header.Crc = crc8_ccitt((uint8_t*)pPkt, len, 0);

    if (crc != pPkt->Header.Crc)
    {
        // Notify Error to SystemWarnings
        DEV_Rec.SystemErrorWarningBits.CheckSum = 1;

        PCMD_RESP resp = { CMD_RESP_FC };
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    0xFF, &resp, sizeof(PCMD_RESP));

        return false;
    }
    return true;
}

bool CheckAccess(void)
{
    if (AccessGranted == false)
    {
        PCMD_RESP resp;
        resp.RespCode = CMD_RESP_ACCESSDENIED;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    0xFF, &resp, sizeof(PCMD_RESP));

        return false;
    }
    return true;
}

bool CheckAwake(void)
{
    if (Awake == false)
    {
        PCMD_RESP resp;
        resp.RespCode = CMD_RESP_SLEEP;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    0xFF, &resp, sizeof(PCMD_RESP));

        return false;
    }
    return true;
}

bool CheckWriteEnable(void)
{
    if (WriteEnable == false)
    {
        PCMD_RESP resp;
        resp.RespCode = CMD_RESP_NORW;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    0xFF, &resp, sizeof(PCMD_RESP));

        return false;
    }
    return true;
}


bool ProcessPacket(PPACKET *pPkt)
{
    // Check Packet validity
    if (!CheckPacket(pPkt))
        return false;

    // Check Access Grant
    if ( (MFG_Calib.PassCodeEnable == PASSCODE_ON) &&
            ((pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS) &&
             (pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE) )    )
    {
        if(!CheckAccess())
            return false;
    }

    // Check Wake Status
    if ((pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_SEND_AUTHENTICATION) && 
        (pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS) &&
            (pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE)    &&
            (pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_WAKEUP_RDONLY)      &&
            (pPkt->Header.CmdRsp != PELAGIC_PROTOCOL_CMD_WAKEUP_RDWR) )
    {
        if(!CheckAwake())
            return false;
    }

    // We have good packet
    switch (pPkt->Header.PktType)
    {
    case PFRAME_PKT_TYPE_CMDT:
    case PFRAME_PKT_TYPE_CMDA:
        ProcessCmd(pPkt);
        break;

    case PFRAME_PKT_TYPE_DATA:

        ProcessData(pPkt);
        break;

    case PFRAME_PKT_TYPE_RESP:
        ProcessResp(pPkt);
        break;

    }
    return true;
}

void ProcessCmd(PPACKET * const pPacket)
{
    volatile bool flag = false;
    PCMD_RESP resp;
    uint8_t buf[PELAGIC_PROTOCOL_MTU];

    switch (pPacket->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_ST:

        break;

    case PELAGIC_PROTOCOL_CMD_RUTHERE:

        SystemStatus.user_act_timestamp = MonotonicClock_s;     // added for O2 Analyzer MFG Calibration Test, to keep GUI stays at same page
        
        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_WAKEUP_RDONLY:

        WriteEnable = false;

        PCMD_WAKE_RESP WakeResp;
        WakeResp.ProductID = PRODUCT_ID;
        WakeResp.FwVersion = GET_FW_VERSION;
        WakeResp.EEpromCapacity = EE24CWxxX_CAP_KBIT;
        WakeResp.Prefix[0] = MFG_Calib.Prefix[0];
        WakeResp.Prefix[1] = MFG_Calib.Prefix[1];

        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &WakeResp, sizeof(WakeResp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;


    case PELAGIC_PROTOCOL_CMD_WAKEUP_RDWR:

        WriteEnable = true;

        PCMD_WAKE_RESP WakeResp1;
        WakeResp1.ProductID = PRODUCT_ID;
        WakeResp1.FwVersion = GET_FW_VERSION;
        WakeResp1.EEpromCapacity = EE24CWxxX_CAP_KBIT;
        
        MFG_Calib.Prefix[0] = 0x47;      // 'G' = 0x47, changed to be hard coded, requested by Minh on 2022 04 13 (changed for BLE Cmd = 34 only)
        MFG_Calib.Prefix[1] = 0x41;      // 'A' = 0x41, changed to be hard coded, requested by Minh on 2022 04 13 (changed for BLE Cmd = 34 only)
        WakeResp1.Prefix[0] = MFG_Calib.Prefix[0];
        WakeResp1.Prefix[1] = MFG_Calib.Prefix[1];

        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &WakeResp1, sizeof(WakeResp1));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;


    case PELAGIC_PROTOCOL_CMD_BACK2SURF:

        // Reset AccessGrant, Awake, WriteEnable Flags
        AccessGranted = false;
        Awake = false;
        WriteEnable = false;

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        
        // downgrade from Connected to Ready (after shutdown)        
        SystemStatus.BLE_ShutdownReq = true;
        Ble_Reset();
          
        break;

    case PELAGIC_PROTOCOL_CMD_ENTER_DEEPSLEEP:

        // Request Deep Sleep Enter
        SystemStatus.System_DeepSleepReq = true;

        // Close Diagnostics if any ongoing
        SystemStatus.DiagnosticReq = false;
        SystemStatus.DiagnosticRun = false;
        SystemStatus.ShowDiag = false;

        // Reset AccessGrant, Awake, WriteEnable Flags
        AccessGranted = false;
        Awake = false;
        WriteEnable = false;

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_ENTER_SLEEP:

        // Request Sleep Enter
        SystemStatus.System_SleepReq = true;

        // Close Diagnostics if any ongoing
        SystemStatus.DiagnosticReq = false;
        SystemStatus.DiagnosticRun = false;
        SystemStatus.ShowDiag = false;

        // Reset AccessGrant, Awake, WriteEnable Flags
        AccessGranted = false;
        Awake = false;
        WriteEnable = false;

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_SETCLOCK:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        resp.RespCode = CMD_RESP_READY;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_READ_A2D:

    {
        PCMD_A2D_RESP A2DResp;
        A2DResp.Altitude_ft = (uint16_t)Dive_Info.Altitude_ft;
        A2DResp.Temperature_mCx10 = (int16_t)MS5837_Sensor.temp;
        A2DResp.Battery_mV = SystemSupplyMonitor.Battery_mV;

        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &A2DResp, sizeof(A2DResp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;

    case PELAGIC_PROTOCOL_CMD_READ_INSTANT_PT:

    {
        MS5837_Meas( MS5837_I2C_ADDR, &MS5837_Sensor, MS5837_OSR_8192, MFG_Calib.LP_Sensor_Offset_ubarx10, MFG_Calib.Temp_Sensor_Offset_mCx10 );

        // To Redefine Water Surface at the current Altitude        
        Dive_Info.SurfacePressure_mbar = 0.0;       // forced mbar re-initialization in UpdateDiveInfo( );
        Dive_Info.WaterEntranceDetected = false;
        
        PCMD_PT_RESP PTResp;
        PTResp.Pressure_ubarx100 = MS5837_Sensor.press;
        PTResp.Temperature_mCx10 = MS5837_Sensor.temp;

        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &PTResp, sizeof(PTResp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;


    case PELAGIC_PROTOCOL_CMD_READ_FLASH:
    case PELAGIC_PROTOCOL_CMD_READ_FLASH_256:
    case PELAGIC_PROTOCOL_CMD_READ_FLASH_1K:
    case PELAGIC_PROTOCOL_CMD_READ_FLASH_2K:

        if( (BLE_IS_USING_FLASH && DEV_Board())
           || (PROD_BLE_IS_USING_FLASH && !DEV_Board())
           )
        {
            resp.RespCode = CMD_RESP_ABORT;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else if(!FlashReadCmd(pPacket))
        {
            resp.RespCode = CMD_RESP_AOFR;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            L4X9_QSPI_Init();

            MT25QL512ABB_PowerDownRelease();

            PPACKET *pkt = (PPACKET*)buf;
            memcpy(pkt, pPacket, sizeof(PPACKET_HEADER));

            pkt->Header.PktSeqNo = 0;
            pkt->Header.Cont = 0;
            pkt->Header.PktType = PFRAME_PKT_TYPE_DATA;

            //volatile bool
            flag = false;

            do
            {
                flag = FlashReadData(pkt);
                SendPacket(pkt);
                pkt->Header.PktSeqNo++;
            } while (flag == false);

            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

            MT25QL512ABB_PowerDownEnter();

            /* DeInitialize SPI module */
            L4X9_QSPI_DeInit();
        }

        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_256:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_1K:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_2K:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        if( (BLE_IS_USING_FLASH && DEV_Board())
           || (PROD_BLE_IS_USING_FLASH && !DEV_Board())
           )
        {
            resp.RespCode = CMD_RESP_ABORT;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            // PowerOn SPI and ExFLash
            L4X9_QSPI_Init();
            MT25QL512ABB_PowerDownRelease();

            if ( !FlashWriteCmd(pPacket) )
            {
                resp.RespCode = CMD_RESP_AOFR;
                SendDataRsp(PFRAME_PKT_TYPE_RESP,
                            pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            }
            else
            {
                resp.RespCode = CMD_RESP_READY;
                SendDataRsp(PFRAME_PKT_TYPE_RESP,
                            pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            }

            // PowerOn SPI and ExFLash
            MT25QL512ABB_PowerDownEnter();
            L4X9_QSPI_DeInit();
        }
        break;

    case PELAGIC_PROTOCOL_CMD_READ_EEPROM:
    case PELAGIC_PROTOCOL_CMD_READ_EEPROM_PAGE:
    case PELAGIC_PROTOCOL_CMD_READ_EEPROM_BLOCK:

        if ( !EEpromReadCmd(pPacket) )
        {
            resp.RespCode = CMD_RESP_AOFR;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            PPACKET *pkt1 = (PPACKET*)buf;
            memcpy(pkt1, pPacket, sizeof(PPACKET_HEADER));

            pkt1->Header.PktSeqNo = 0;
            pkt1->Header.Cont = 0;
            pkt1->Header.PktType = PFRAME_PKT_TYPE_DATA;

            //volatile bool
            flag = false;

            do
            {
                flag = EEpromReadData(pkt1);
                SendPacket(pkt1);
                pkt1->Header.PktSeqNo++;
            } while (flag == false);

            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM:
    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_PAGE:
    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_BLOCK:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        if ( !EEpromWriteCmd(pPacket) )
        {
            resp.RespCode = CMD_RESP_AOFR;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_READY;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }

        break;


    case PELAGIC_PROTOCOL_CMD_READ_MFG_CAL:
    case PELAGIC_PROTOCOL_CMD_READ_USER_SET:
    case PELAGIC_PROTOCOL_CMD_READ_SCUBA_SET:    
    case PELAGIC_PROTOCOL_CMD_READ_FREE_SET:
    case PELAGIC_PROTOCOL_CMD_READ_TRIMIX_SET:
    case PELAGIC_PROTOCOL_CMD_READ_EXFLASH_MAP:
    case PELAGIC_PROTOCOL_CMD_READ_DEV_REC:

        NVDReadCmd(pPacket);

        PPACKET *pkt1 = (PPACKET*)buf;
        memcpy(pkt1, pPacket, sizeof(PPACKET_HEADER));

        pkt1->Header.PktSeqNo = 0;
        pkt1->Header.Cont = 0;
        pkt1->Header.PktType = PFRAME_PKT_TYPE_DATA;

        //volatile bool
        flag = false;

        do
        {
            flag = NVDReadData(pkt1);
            SendPacket(pkt1);
            pkt1->Header.PktSeqNo++;
        } while (flag == false);

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL:
    case PELAGIC_PROTOCOL_CMD_WRITE_USER_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP:
    case PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        NVDWriteCmd(pPacket);
        
        SystemStatus.backlight_change_req = true;       // change backlight level if just modified
        
        resp.RespCode = CMD_RESP_READY;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;


    case PELAGIC_PROTOCOL_CMD_READ_MY_INFO:

        if( (BLE_IS_USING_FLASH && DEV_Board())
           || (PROD_BLE_IS_USING_FLASH && !DEV_Board())
           )
        {
            resp.RespCode = CMD_RESP_ABORT;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else if(!FlashReadCmd(pPacket))
        {
            resp.RespCode = CMD_RESP_AOFR;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            L4X9_QSPI_Init();

            MT25QL512ABB_PowerDownRelease();

            PPACKET *pkt = (PPACKET*)buf;
            memcpy(pkt, pPacket, sizeof(PPACKET_HEADER));

            pkt->Header.PktSeqNo = 0;
            pkt->Header.Cont = 0;
            pkt->Header.PktType = PFRAME_PKT_TYPE_DATA;

            //volatile bool
            flag = false;

            do
            {
                flag = FlashReadData(pkt);
                SendPacket(pkt);
                pkt->Header.PktSeqNo++;
            } while (flag == false);

            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

            MT25QL512ABB_PowerDownEnter();

            /* DeInitialize SPI module */
            L4X9_QSPI_DeInit();
        }
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_MY_INFO:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        if( (BLE_IS_USING_FLASH && DEV_Board())
           || (PROD_BLE_IS_USING_FLASH && !DEV_Board())
           )
        {
            resp.RespCode = CMD_RESP_ABORT;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            // PowerOn SPI and ExFLash
            L4X9_QSPI_Init();
            MT25QL512ABB_PowerDownRelease();

            if ( !FlashWriteCmd(pPacket) )
            {
                resp.RespCode = CMD_RESP_AOFR;
                SendDataRsp(PFRAME_PKT_TYPE_RESP,
                            pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            }
            else
            {
                resp.RespCode = CMD_RESP_READY;
                SendDataRsp(PFRAME_PKT_TYPE_RESP,
                            pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            }

            // PowerOn SPI and ExFLash
            MT25QL512ABB_PowerDownEnter();
            L4X9_QSPI_DeInit();
        }
        break;

    case PELAGIC_PROTOCOL_CMD_SEND_NOTIFICATION:        // 2021 04 13 with Minh
        // wait for future developments from Apps (phone messages, etc)
      break;
      
    case PELAGIC_PROTOCOL_CMD_SEND_AUTHENTICATION:      // 2021 04 13 with Minh

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        if( (pPacket->Payload[0]==0xFF)
          &&(pPacket->Payload[1]==0xFF)
          &&(pPacket->Payload[2]==0xFF)
          &&(pPacket->Payload[3]==0xFF)  )
        { 
          Awake = true;
          resp.RespCode = CMD_RESP_READY;
          SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {          
          // Reset AccessGrant, Awake, WriteEnable Flags
          AccessGranted = false;
          Awake = false;
          WriteEnable = false;

          // Send Response Done
          CheckAccess();        // to return false 
          
          SystemStatus.BLE_status = BLE_HDL_READY;
        }
        
        break;
    
    case PELAGIC_PROTOCOL_CMD_FW_UPDATE:

        // Check if Write Access
        if(!CheckWriteEnable())
            break;

        if( (BLE_IS_USING_FLASH && DEV_Board())
           || (PROD_BLE_IS_USING_FLASH && !DEV_Board())
           )
        {
            resp.RespCode = CMD_RESP_ABORT;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_READY;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        break;

    case PELAGIC_PROTOCOL_CMD_READ_SYSTEM_ERROR:

    {
        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &DEV_Rec.SystemErrorWarningBits, sizeof(L4X9_SystemWarnings_t));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
    
    
    case PELAGIC_PROTOCOL_CMD_RESET_FUELGAUGE:
    {
        int32_t FuelGaugeResetRetry = 0;
        while ( !MAX17262_Reset() && FuelGaugeResetRetry++ < 100) {};
        if(FuelGaugeResetRetry >= 100)
        {
          // Send Response Fuel Gauge Reset Error
          resp.RespCode = CMD_RESP_FGRESET_ERR;
          SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
          
          break;
        }
        else
        {
          // Invalidate previouse Learned Parameters in Ram and EEPROM
          DEV_Rec.MAX17262_BatteryLearned.valid = 0;          
          
          if(NVD_RAMBLOCK_to_ExtEEPROM(EE_DEVREC))
          {
              // EEPROM Read Write NOT GOOD
              resp.RespCode = CMD_RESP_NORW;
          }
          else
          {
              // Send Response Done
              resp.RespCode = CMD_RESP_DONE;
          }
        }
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
   
    
    case PELAGIC_PROTOCOL_CMD_READ_ALS:

    {
        PCMD_ALS_RESP ALS_Resp;
        ALS_Resp.ALS_Data_U32 = Lux_u32;

        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &ALS_Resp, sizeof(ALS_Resp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
    
#if GPS_FW_ATTACHED    
    case PELAGIC_PROTOCOL_CMD_GPS_FW_UPDATE:

    {
        // Send Response Done
        resp.RespCode = CMD_RESP_GPS_FW_STARTED;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        
        // Execute GPS Update
        GnssFwUpdate_Blocking();
    }
    break;
    
    
    case PELAGIC_PROTOCOL_CMD_GPS_FW_UPDATE_CHECK:

    {
      if(GNSS_FwUpdateStatus == GNSS_FWU_DONE)
      {
        // Send Response Done
        resp.RespCode = CMD_RESP_GPS_FW_OK;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
      }
      else if(GNSS_FwUpdateStatus == GNSS_FWU_ERROR)
      {
        // Send Response Done
        resp.RespCode = CMD_RESP_GPS_FW_ERR;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
      }
      else
      {
        // Send Response Done
        resp.RespCode = CMD_RESP_GPS_FW_BUSY;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
      }
    }
    break;
#endif
    case PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS:

        resp.RespCode = CMD_RESP_READY;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE:

        resp.RespCode = CMD_RESP_READY;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        break;

    case PELAGIC_PROTOCOL_CMD_READ_WE1:
    {
        PCMD_O2ANALYZER_RESP O2Resp;
        
        O2Resp.O2_ADC_Offset    = 0;
        O2Resp.O2_ADC_Calib     = 0;
        O2Resp.O2_ADC_Analyze1  = 0;
        O2Resp.O2_ADC_Analyze2  = 0;
        O2Resp.O2_Pct_Calib     = 0;
        O2Resp.O2_Pct_Analyze1  = 0;
        O2Resp.O2_Pct_Analyze2  = 0;
        O2Resp.O2_Analyzer_SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN;
        
        // Do Initialization Stage if not done (will becomes WE1 after done)
        if(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_WE1_DONE)
        {
            O2Resp.O2_ADC_Calib     = ADC_mV_Calib;            
        }
        
        if((SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_WE1)||(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_WE1_DONE))
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_WE1;   // stay at WE1
        else if(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_INIT_DONE)
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_WE1;   // go to WE1
        else
            SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_INIT;  // force to init again
        
        SystemStatus.user_act_timestamp = MonotonicClock_s;
        
        DSX_Opcode = S462_O2ANALYZER_CALIBRATE; // to turn ON ADC and O2 Analyzer            
        
        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &O2Resp, sizeof(O2Resp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
        
    case PELAGIC_PROTOCOL_CMD_READ_WE2:
    {
        PCMD_O2ANALYZER_RESP O2Resp;
        
        O2Resp.O2_ADC_Offset    = 0;
        O2Resp.O2_ADC_Calib     = 0;
        O2Resp.O2_ADC_Analyze1  = 0;
        O2Resp.O2_ADC_Analyze2  = 0;
        O2Resp.O2_Pct_Calib     = 0;
        O2Resp.O2_Pct_Analyze1  = 0;
        O2Resp.O2_Pct_Analyze2  = 0;
        O2Resp.O2_Analyzer_SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN;
        
        if(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_WE2_DONE)
        {            
            O2Resp.O2_ADC_Calib      = ADC_mV_Calib;
            O2Resp.O2_ADC_Analyze1   = ADC_mV_Analyze1;                        
        }

        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_WE2;
        
        SystemStatus.user_act_timestamp = MonotonicClock_s;
            
        DSX_Opcode = S462_O2ANALYZER_CALIBRATE; // to turn ON ADC and O2 Analyzer
        
        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &O2Resp, sizeof(O2Resp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
    
    
    case PELAGIC_PROTOCOL_CMD_READ_WE3:
    {
        PCMD_O2ANALYZER_RESP O2Resp;
        
        O2Resp.O2_ADC_Offset    = 0;
        O2Resp.O2_ADC_Calib     = 0;
        O2Resp.O2_ADC_Analyze1  = 0;
        O2Resp.O2_ADC_Analyze2  = 0;
        O2Resp.O2_Pct_Calib     = 0;
        O2Resp.O2_Pct_Analyze1  = 0;
        O2Resp.O2_Pct_Analyze2  = 0;
        O2Resp.O2_Analyzer_SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN;
        
        if(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_WE3_DONE)
        {            
            O2Resp.O2_ADC_Calib      = ADC_mV_Calib;
            O2Resp.O2_ADC_Analyze1   = ADC_mV_Analyze1;
            O2Resp.O2_ADC_Analyze2   = ADC_mV_Analyze2;                        
        }

        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_WE3;
        
        SystemStatus.user_act_timestamp = MonotonicClock_s;
            
        DSX_Opcode = S462_O2ANALYZER_CALIBRATE; // to turn ON ADC and O2 Analyzer
        
        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &O2Resp, sizeof(O2Resp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
    
    
    case PELAGIC_PROTOCOL_CMD_READ_O2_PERCENT:
    {
        #define CABLE_CALI_FO2_PCT     (float)20.9   // equivalent FO2 % assigned for Cable Calibration use

        PCMD_O2ANALYZER_RESP O2Resp;
        
        O2Resp.O2_ADC_Offset    = 0;
        O2Resp.O2_ADC_Calib     = 0;
        O2Resp.O2_ADC_Analyze1  = 0;
        O2Resp.O2_ADC_Analyze2  = 0;
        O2Resp.O2_Pct_Calib     = 0;
        O2Resp.O2_Pct_Analyze1  = 0;
        O2Resp.O2_Pct_Analyze2  = 0;
        O2Resp.O2_Analyzer_SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN;
        
        if(SystemStatus.O2_Analyzer_Stage == O2_ANALYZER_FO2_CHECK_DONE)
        {
            int8_t retry = NVD_EEPROM_READ_TIMEOUT;
            do{}while( !EE24CWxxX_ReadNBytes(NVD_MFGCAL_LOC1, &EE_Block1, sizeof(MFG_Calib) ) && (retry-- > 0) );
            if(retry <= 0)
            {
                ErrHandle_EE();
            }
            ADC_mV_ZeroOffset = MFG_Calib.O2_Analyzer.O2_ADC_Offset;
            O2_ADC_V_ZeroOffset = (float)0.001* ADC_mV_ZeroOffset;
            
            // Must Redo following three with a new ADC_mV_ZeroOffset sent from Software (newly saved on EEPROM)
            O2_PCT_Calib    = Find_O2_Pct_Analyze(O2_ADC_V_ZeroOffset, O2_ADC_V_Calib, CABLE_CALI_FO2_PCT);
            O2_PCT_Analyze1 = Find_O2_Pct_Analyze(O2_ADC_V_ZeroOffset, O2_ADC_V_Analyze1, CABLE_CALI_FO2_PCT);
            O2_PCT_Analyze2 = Find_O2_Pct_Analyze(O2_ADC_V_ZeroOffset, O2_ADC_V_Analyze2, CABLE_CALI_FO2_PCT);

            ADC_mV_Calib          = (uint16_t)round(O2_ADC_V_Calib * 1000);         // round to uint16_t
            ADC_FO2x10_Calib      = (uint16_t)round(O2_PCT_Calib * 10);             // round to uint16_t
            ADC_mV_Analyze1       = (uint16_t)round(O2_ADC_V_Analyze1 * 1000);      // round to uint16_t
            ADC_FO2x10_Analyze1   = (uint16_t)round(O2_PCT_Analyze1 * 10);          // round to uint16_t
            ADC_mV_Analyze2       = (uint16_t)round(O2_ADC_V_Analyze2 * 1000);      // round to uint16_t
            ADC_FO2x10_Analyze2   = (uint16_t)round(O2_PCT_Analyze2 * 10);          // round to uint16_t
            
            MFG_Calib.O2_Analyzer.O2_Pct_Calib    = ADC_FO2x10_Calib;
            MFG_Calib.O2_Analyzer.O2_Pct_Analyze1 = ADC_FO2x10_Analyze1;
            MFG_Calib.O2_Analyzer.O2_Pct_Analyze2 = ADC_FO2x10_Analyze2;
            
            O2Resp.O2_ADC_Offset    = ADC_mV_ZeroOffset;
            O2Resp.O2_ADC_Calib     = ADC_mV_Calib;
            O2Resp.O2_ADC_Analyze1  = ADC_mV_Analyze1;
            O2Resp.O2_ADC_Analyze2  = ADC_mV_Analyze2;
            O2Resp.O2_Pct_Calib     = ADC_FO2x10_Calib;             // should be same Mfg. as in O2_PCT_Analyze1
            O2Resp.O2_Pct_Analyze1  = ADC_FO2x10_Analyze1;
            O2Resp.O2_Pct_Analyze2  = ADC_FO2x10_Analyze2;
            O2Resp.O2_Analyzer_SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN;            
        }

        SystemStatus.O2_Analyzer_Stage = O2_ANALYZER_FO2_CHECK;                 // move this to the end
        
        SystemStatus.user_act_timestamp = MonotonicClock_s;
        
        DSX_Opcode = S462_O2ANALYZER_CALIBRATE; // to turn ON ADC and O2 Analyzer
                
        // Send Data
        SendDataRsp(PFRAME_PKT_TYPE_DATA,
                    pPacket->Header.CmdRsp, &O2Resp, sizeof(O2Resp));

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
    }
    break;
      
      
    default:
        resp.RespCode = CMD_RESP_NOCMD;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        break;
    }
}

void ProcessData(PPACKET *pPacket)
{
    PCMD_RESP resp;
    int8_t retry;
    
    switch (pPacket->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_ST:

        break;

    case PELAGIC_PROTOCOL_CMD_SETCLOCK:

        // Home Away
        if(pPacket->Payload[0] == 0)
            USER_Set.HomeAway = NVD_HOME;
        else
            USER_Set.HomeAway = NVD_AWAY;

        // Dual Time
        /*
        if(pPacket->Payload[1] == 0)
          USER_Set.HomeAway = NVD_HOME;
        else
          USER_Set.HomeAway = NVD_AWAY;
        */

        SystemTimeDate_t ClockData;
        ClockData.Hour = BCD2BIN(pPacket->Payload[2]);
        ClockData.Minute =BCD2BIN( pPacket->Payload[3]);
        ClockData.Second = BCD2BIN(pPacket->Payload[4]);
        ClockData.WeekDay = pPacket->Payload[5];
        ClockData.Day = BCD2BIN(pPacket->Payload[6]);
        ClockData.Month = BCD2BIN(pPacket->Payload[7]);
        ClockData.Year = BCD2BIN(pPacket->Payload[8]);

        L4X9_SetRtc (ClockData);

        if(NVD_RAMBLOCK_to_ExtEEPROM(EE_USERSET))
        {
            // EEPROM Read Write NOT GOOD
            resp.RespCode = CMD_RESP_NORW;
        }
        else
        {
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
        }

        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_256:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_1K:
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_2K:

        // PowerOn SPI and ExFLash
        L4X9_QSPI_Init();
        MT25QL512ABB_PowerDownRelease();

        if (FlashWriteData(pPacket) == true)
        {
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_DP;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }

        // PowerOff SPI and ExFLash
        MT25QL512ABB_PowerDownEnter();
        L4X9_QSPI_DeInit();

        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM:
    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_PAGE:
    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_BLOCK:

        if (EEpromWriteData(pPacket) == true)
        {
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_DP;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL:
    case PELAGIC_PROTOCOL_CMD_WRITE_USER_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET:
    case PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP:
    case PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC:

        if (NVDWriteData(pPacket) == true)
        {
          if(DataCrcError)
            resp.RespCode = CMD_RESP_CRC_ERR;
          else
            resp.RespCode = CMD_RESP_DONE;
            
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_DP;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        
        SystemStatus.backlight_change_req = true;       // change backlight level if just modified
        break;


    case PELAGIC_PROTOCOL_CMD_WRITE_MY_INFO:

        // PowerOn SPI and ExFLash
        L4X9_QSPI_Init();
        MT25QL512ABB_PowerDownRelease();

        if (FlashWriteData(pPacket) == true)
        {
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        else
        {
            resp.RespCode = CMD_RESP_DP;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }

        // PowerOff SPI and ExFLash
        MT25QL512ABB_PowerDownEnter();
        L4X9_QSPI_DeInit();

        break;

    case PELAGIC_PROTOCOL_CMD_SEND_NOTIFICATION:

        SystemStatus.Notification_type = pPacket->Payload[0];
        SystemStatus.Notification_timestamp = MonotonicClock_s;

        // Send Response Done
        resp.RespCode = CMD_RESP_DONE;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));

        break;

    case PELAGIC_PROTOCOL_CMD_FW_UPDATE:

        L4X9_QSPI_Init();

        MT25QL512ABB_PowerDownRelease();

        BootRecord_t BootRec;

        memcpy( &BootRec, pPacket->Payload,  pPacket->Header.PayloadLen );

        // Verify BootRecord
        volatile uint16_t BootRecordCrc16 = 0xFFFF;
        BootRecordCrc16 = Eval_CRC16(&BootRec, sizeof(BootRecord_t)-2);
        if (BootRecordCrc16 != BootRec.BootRecCrc)
        {
            resp.RespCode = CMD_RESP_BOOTRECBAD;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            
            MT25QL512ABB_PowerDownEnter();

            // DeInitialize SPI module
            L4X9_QSPI_DeInit();
            
            break;
        }

        // Verify FW in ExFlash
        if (!IsFwOnExFlashGood(BootRec))
        {
            resp.RespCode = CMD_RESP_EXFLASHFWBAD;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            
            MT25QL512ABB_PowerDownEnter();

            // DeInitialize SPI module
            L4X9_QSPI_DeInit();
            
            break;
        }

        // Erase InfoData Locations in Exflash

    
        retry = NVD_FLASH_WRITE_TIMEOUT;
        do{} while ((MT25QL512ABB_Erase4kSector(BOOTRECORD_ADDR) != true) && (retry-- > 0));		// Timeout added from R1006        
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }
        
        // Wrtie Data to External Flash
        retry = NVD_FLASH_WRITE_TIMEOUT;    
        do{} while ((MT25QL512ABB_WriteNPage1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), &BootRec )!= true) && (retry-- > 0));		// Timeout added from R1006   
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }        
        
        BootRecord_t BootRecReadBack;
        
        // Read Data From External Flash
        retry = NVD_FLASH_READ_TIMEOUT;
        do{} while ((MT25QL512ABB_Read1I1O( BOOTRECORD_ADDR, sizeof(BootRecord_t), &BootRecReadBack )!= true) && (retry-- > 0));		// Timeout added from R1006   
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }
        
        MT25QL512ABB_PowerDownEnter();

        // DeInitialize SPI module
        L4X9_QSPI_DeInit();

        int32_t BootRecResult = memcmp(&BootRec, &BootRecReadBack, sizeof(BootRecReadBack));
        
        if(BootRecResult == 0)
        {
          // Send Response Done
          resp.RespCode = CMD_RESP_DONE;
          SendDataRsp(PFRAME_PKT_TYPE_RESP,
                      pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
          
          SystemStatus.system_reboot_request = true;
        }
        else
        {
          resp.RespCode = CMD_RESP_BOOTRECBAD;
          SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }

        break;

    case PELAGIC_PROTOCOL_CMD_STM_REQUEST_ACCESS:

        // No PassCode required, notify this to App
        if(MFG_Calib.PassCodeEnable != PASSCODE_ON)
        {
            AccessGranted = true;
            SystemStatus.BLE_PsShowReq = false;

            resp.RespCode = CMD_RESP_NOPASSCODE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        // App send MacId all 0, so generate new PassCode
        else if(IsMacIdAllZero(pPacket->Payload))
        {
            GeneratePassCode();         // comes here after Request Access
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        // MacId is wrong, so generate new PassCode
        else if(!CheckMacId(pPacket->Payload))
        {
            GeneratePassCode();
            BLE_AcessInitDone = false;	//R1006, for displaying complete message if more-than-one-time display is needed
            resp.RespCode = CMD_RESP_INVALIDPASSCODE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }
        // MacId is ok, so allow Access
        else
        {
            AccessGranted = true;       // comes here if passcode is correct
            SystemStatus.BLE_PsShowReq = false;
            BLE_AcessInitDone = false;	//R1006, for displaying complete message if more-than-one-time display is needed
            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        }

        break;

    case PELAGIC_PROTOCOL_CMD_STM_ACCESS_CODE:

        // PassCode is wrong, so generate new one
        if(!PassCodeCheck(pPacket->Payload))
        {
            GeneratePassCode();         // comes here if passcode is wrong

            AccessGranted = false;
            BLE_AcessInitDone = false;
            
            resp.RespCode = CMD_RESP_INVALIDPASSCODE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            SystemStatus.BLE_PassCodeValidation = BLE_PASSCODE_INCORRECT;    // Validation Failed
        }
        // PassCode is ok, so allow Access
        else
        {
            AccessGranted = true;       // comes here if passcode is correct
            SystemStatus.BLE_PsShowReq = false;

            SendDataRsp(PFRAME_PKT_TYPE_DATA,
                        pPacket->Header.CmdRsp, &MFG_Calib.MacId, 16);

            // Send Response Done
            resp.RespCode = CMD_RESP_DONE;
            SendDataRsp(PFRAME_PKT_TYPE_RESP,
                        pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
            SystemStatus.BLE_PassCodeValidation = BLE_PASSCODE_CORRECT;    // Validation Passed
        }
        break;

    default:
        resp.RespCode = CMD_RESP_NOCMD;
        SendDataRsp(PFRAME_PKT_TYPE_RESP,
                    pPacket->Header.CmdRsp, &resp, sizeof(PCMD_RESP));
        break;
    }
}

void ProcessResp(PPACKET *pPacket)
{
    BleRespone.RespReceived = false;

    switch (pPacket->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_BLE_SETNAME:
        BleRespone.RespCode = PELAGIC_PROTOCOL_CMD_BLE_SETNAME;
        BleRespone.RespReceived = true;
        break;

    case PELAGIC_PROTOCOL_CMD_BLE_GETNAME:
        BleRespone.RespCode = PELAGIC_PROTOCOL_CMD_BLE_GETNAME;
        BleRespone.RespReceived = true;

        memcpy(&BleName, pPacket->Payload, pPacket->Header.PayloadLen);
        BleName.NameLength = pPacket->Header.PayloadLen;
        break;

    case PELAGIC_PROTOCOL_CMD_SET_WR_REGION:
        BleRespone.RespCode = PELAGIC_PROTOCOL_CMD_SET_WR_REGION;
        BleRespone.RespReceived = true;
        break;
        
    case PELAGIC_PROTOCOL_CMD_UART_OFF:
        BleRespone.RespCode = PELAGIC_PROTOCOL_CMD_UART_OFF;
        BleRespone.RespReceived = true;

        memcpy(&BleName, pPacket->Payload, pPacket->Header.PayloadLen);
        BleName.NameLength = pPacket->Header.PayloadLen;
        break;

    }
}




bool StRecvCmd(PPACKET * const pPkt)
{
    return false;
}

bool StSendCmd(PPACKET * const pPkt)
{
    return false;
}



bool FlashReadCmd(PPACKET * const pPkt)
{
    PCMD_MEM_RW *cmd = (PCMD_MEM_RW*)pPkt->Payload;

    switch (pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_READ_FLASH:
        g_MemReadAddr = cmd->Addr;
        g_MemReadSize = cmd->Len;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_FLASH_256:
        g_MemReadAddr = cmd->Addr;
        g_MemReadSize = 256;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_FLASH_1K:
        g_MemReadAddr = cmd->Addr;
        g_MemReadSize = 1024;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_FLASH_2K:
        g_MemReadAddr = cmd->Addr;
        g_MemReadSize = 2048;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_MY_INFO:
        g_MemReadAddr = EXFLASH_MYINFO;
        g_MemReadSize = 1024;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;
    }

    if ( (int32_t)g_MemReadAddr > ( (int32_t)MT25QL512ABB_CHIP_END - (int32_t)g_MemReadSize) )
        return false;
    else
        return true;
}

bool FlashReadData(PPACKET * const pPkt)
{
    int8_t retry;
    
    if (g_MemReadAddr != -1)
    {
        int len = min(PACKET_READ_MAX_SIZE, g_MemReadSize);

        pPkt->Header.PayloadLen = len;

        if (len < g_MemReadSize)
            pPkt->Header.Cont = 1;
        else
            pPkt->Header.Cont = 0;

        retry = NVD_FLASH_READ_TIMEOUT;
        do{} while ((MT25QL512ABB_Read1I1O( g_MemReadAddr, len, pPkt->Payload )!= true) && (retry-- > 0));		// Timeout added from R1006   
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }
        
        g_MemReadAddr += len;
        g_MemReadSize -= len;

        if (g_MemReadSize <= 0)
        {
            g_MemReadAddr = -1;
            g_MemReadSize = 0;

            return true;
        }
        return false;
    }
    return true;
}


bool FlashWriteCmd(PPACKET * const pPkt)
{
    PCMD_MEM_RW *cmd = (PCMD_MEM_RW*)pPkt->Payload;
    uint32_t esize = MT25QL512ABB_4KSECTOR_SIZE_BYTE;
    int8_t retry;
    
    if(cmd->Addr < (uint32_t)EXFLASH_LOG )   // to protect BLE writing onto Negative Address NOR Boot Record at ExFLASH
        return false;
    
    switch (pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH:
        g_MemWriteAddr = (int32_t)cmd->Addr;
        g_MemWriteSize = (int32_t)cmd->Len;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_256:
        g_MemWriteAddr = (int32_t)cmd->Addr;
        g_MemWriteSize = (int32_t)256;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_1K:
        g_MemWriteAddr = (int32_t)cmd->Addr;
        g_MemWriteSize = (int32_t)1024;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FLASH_2K:
        g_MemWriteAddr = (int32_t)cmd->Addr;
        g_MemWriteSize = (int32_t)2048;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_MY_INFO:
        g_MemWriteAddr = (int32_t)EXFLASH_MYINFO;
        g_MemWriteSize = (int32_t)1024;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;
    }

    if ( ( (int32_t)g_MemWriteAddr > ( (int32_t)MT25QL512ABB_CHIP_END - (int32_t)g_MemWriteSize) ) || (g_MemWriteAddr < (int32_t)EXFLASH_LOG ) )   // to protect BLE writing onto Negative Address NOR Boot Record at ExFLASH
        return false;

    uint32_t sector = g_MemWriteAddr / esize;
    uint32_t endaddr = (uint32_t)(g_MemWriteAddr + g_MemWriteSize);
    int cnt = endaddr / esize - sector;
    if (endaddr & 0xFFF)
        cnt++;

    for(uint16_t i = 0; i < cnt; i++ )
    {
        retry = NVD_EEPROM_WRITE_TIMEOUT;    
        do{} while((MT25QL512ABB_Erase4kSector( g_MemWriteAddr + esize*i )!= true) && (retry-- > 0));		// Timeout added from R1006   
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }        
    }

    return true;
}


bool FlashWriteData(PPACKET * const pPkt)
{
    int8_t retry;
    
    if (g_MemWriteAddr >= (int32_t)EXFLASH_LOG)   // to protect BLE writing onto Negative Address NOR Boot Record at ExFLASH
    {
        retry = NVD_FLASH_WRITE_TIMEOUT;
        do{} while((MT25QL512ABB_WriteNPage1I1O( (uint32_t)g_MemWriteAddr, pPkt->Header.PayloadLen, pPkt->Payload )!= true) && (retry-- > 0));		// Timeout added from R1006   
        if(retry <= 0)
        {
            ErrHandle_FLASH();
        }
        g_MemWriteAddr += (int32_t)pPkt->Header.PayloadLen;
        g_MemWriteSize -= (int32_t)pPkt->Header.PayloadLen;

        if (g_MemWriteSize <= 0)
        {
            //g_FlashDisk.Flush();
            g_MemWriteAddr = -1;
            g_MemWriteSize = 0;

            return true;
        }
    }

    return false;
}








bool EEpromReadCmd(PPACKET * const pPkt)
{
    PCMD_MEM_RW *cmd = (PCMD_MEM_RW*)pPkt->Payload;

    switch(pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_READ_EEPROM:
        g_MemReadAddr = cmd->Addr;
        g_MemReadSize = cmd->Len;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_EEPROM_PAGE:
        g_MemReadAddr = cmd->Addr*16;
        g_MemReadSize = 16;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_READ_EEPROM_BLOCK:
        g_MemReadAddr = cmd->Addr*16;
        g_MemReadSize = 256;

        if(g_MemReadAddr%g_MemReadSize != 0)
            return false;
        break;

    default:
        return false;
    }

    if ( (int32_t)g_MemReadAddr > ((int32_t)(EE24CWxxX_CAP_BYTE)-(int32_t)(g_MemReadSize)) )
        return false;
    else
        return true;
}

bool EEpromReadData(PPACKET * const pPkt)
{
    if (g_MemReadAddr != -1)
    {
        int len = min(PACKET_READ_MAX_SIZE, g_MemReadSize);

        pPkt->Header.PayloadLen = len;

        if (len < g_MemReadSize)
            pPkt->Header.Cont = 1;
        else
            pPkt->Header.Cont = 0;

        int8_t retry = NVD_EEPROM_READ_TIMEOUT;
        do{}while( !EE24CWxxX_ReadNBytes(g_MemReadAddr, pPkt->Payload, len) && (retry-- > 0) );
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        g_MemReadAddr += len;
        g_MemReadSize -= len;

        if (g_MemReadSize <= 0)
        {
            g_MemReadAddr = -1;
            g_MemReadSize = 0;

            return true;
        }
        return false;
    }
    return true;
}


bool EEpromWriteCmd(PPACKET * const pPkt)
{
    PCMD_MEM_RW *cmd = (PCMD_MEM_RW*)pPkt->Payload;

    switch(pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM:
        g_MemWriteAddr = (int32_t)cmd->Addr;
        g_MemWriteSize = (int32_t)cmd->Len;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_PAGE:
        g_MemWriteAddr = (int32_t)cmd->Addr*16;
        g_MemWriteSize = (int32_t)16;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_EEPROM_BLOCK:
        g_MemWriteAddr = (int32_t)cmd->Addr*16;
        g_MemWriteSize = (int32_t)256;

        if(g_MemWriteAddr%g_MemWriteSize != 0)
            return false;
        break;

    default:
        return false;
    }

    if ( (int32_t)g_MemWriteAddr > ((int32_t)(EE24CWxxX_CAP_BYTE)-(int32_t)(g_MemWriteSize)) )
        return false;
    else
        return true;
}


bool EEpromWriteData(PPACKET * const pPkt)
{
    if (g_MemWriteAddr != -1)
    {
        int8_t retry = NVD_EEPROM_WRITE_TIMEOUT;
        do{}while( !EE24CWxxX_WriteNBytes((uint32_t)g_MemWriteAddr, pPkt->Payload, pPkt->Header.PayloadLen) && (retry-- >0) );
        if(retry <= 0)
        {
            ErrHandle_EE();
        }
        g_MemWriteAddr += (int32_t)pPkt->Header.PayloadLen;
        g_MemWriteSize -= (int32_t)pPkt->Header.PayloadLen;

        if (g_MemWriteSize <= 0)
        {
            g_MemWriteAddr = -1;
            g_MemWriteSize = 0;

            return true;
        }
    }

    return false;
}







bool NVDReadCmd(PPACKET * const pPkt)
{
    switch (pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_READ_MFG_CAL:
        g_NVDReadSize = sizeof(MFG_Calib);
        break;

    case PELAGIC_PROTOCOL_CMD_READ_USER_SET:
        g_NVDReadSize = sizeof(USER_Set);
        break;

    case PELAGIC_PROTOCOL_CMD_READ_SCUBA_SET:
        g_NVDReadSize = sizeof(SCUBA_Set);
        break;

    case PELAGIC_PROTOCOL_CMD_READ_FREE_SET:
        g_NVDReadSize = sizeof(FREE_Set);
        break;
        
    case PELAGIC_PROTOCOL_CMD_READ_TRIMIX_SET:
        g_NVDReadSize = sizeof(TRIMIX_Set);
        break;

    case PELAGIC_PROTOCOL_CMD_READ_EXFLASH_MAP:
        g_NVDReadSize = sizeof(FLASH_Map);
        break;

    case PELAGIC_PROTOCOL_CMD_READ_DEV_REC:
        g_NVDReadSize = sizeof(DEV_Rec);
        break;
    }

    g_NVDReadAddr = 0;

    return true;
}

bool NVDReadData(PPACKET * const pPkt)
{
    if (g_NVDReadSize != -1)
    {
        int len = min(PACKET_READ_MAX_SIZE, g_NVDReadSize);

        pPkt->Header.PayloadLen = len;

        if (len < g_NVDReadSize)
            pPkt->Header.Cont = 1;
        else
            pPkt->Header.Cont = 0;

        uint8_t this_buf [512];

        switch (pPkt->Header.CmdRsp)
        {
        case PELAGIC_PROTOCOL_CMD_READ_MFG_CAL:
            memcpy(this_buf, &MFG_Calib, sizeof(MFG_Calib));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;

        case PELAGIC_PROTOCOL_CMD_READ_USER_SET:
            memcpy(this_buf, &USER_Set, sizeof(USER_Set));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;

        case PELAGIC_PROTOCOL_CMD_READ_SCUBA_SET:
            memcpy(this_buf, &SCUBA_Set, sizeof(SCUBA_Set));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;

        case PELAGIC_PROTOCOL_CMD_READ_FREE_SET:
            memcpy(this_buf, &FREE_Set, sizeof(FREE_Set));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;

        case PELAGIC_PROTOCOL_CMD_READ_TRIMIX_SET:
            memcpy(this_buf, &TRIMIX_Set, sizeof(TRIMIX_Set));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;
            
        case PELAGIC_PROTOCOL_CMD_READ_EXFLASH_MAP:
            memcpy(this_buf, &FLASH_Map, sizeof(FLASH_Map));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;

        case PELAGIC_PROTOCOL_CMD_READ_DEV_REC:
            memcpy(this_buf, &DEV_Rec, sizeof(DEV_Rec));
            memcpy(pPkt->Payload, this_buf+g_NVDReadAddr, len);
            break;
        }

        g_NVDReadAddr += len;
        g_NVDReadSize -= len;

        if (g_NVDReadSize <= 0)
        {
            g_NVDReadAddr = -1;
            g_NVDReadSize = 0;

            return true;
        }
        return false;
    }
    return true;
}





bool NVDWriteCmd(PPACKET * const pPkt)
{
    switch(pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(MFG_Calib);
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_USER_SET:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(USER_Set);
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(SCUBA_Set);
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(FREE_Set);
        break;
    
    case PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(TRIMIX_Set);
        break;
        
    case PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(FLASH_Map);
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC:
        g_NVDWriteAddr = 0;
        g_NVDWriteSize = sizeof(DEV_Rec);
        break;

    default:
        return false;
    }

    return true;
}


bool NVDWriteData(PPACKET * const pPkt)
{
    if (g_NVDWriteAddr != -1)
    {
        static uint8_t this_buf [512];

        memcpy(this_buf+g_NVDWriteAddr, pPkt->Payload, pPkt->Header.PayloadLen);

        g_NVDWriteAddr += (int32_t)pPkt->Header.PayloadLen;
        g_NVDWriteSize -= (int32_t)pPkt->Header.PayloadLen;

        if (g_NVDWriteSize <= 0)
        {
            g_NVDWriteAddr = -1;
            g_NVDWriteSize = 0;

            switch (pPkt->Header.CmdRsp)
            {
              case PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL:
                  if(Eval_CRC16(&this_buf, sizeof(MFG_Calib)) == 0)
                  {
                    memcpy(&MFG_Calib, this_buf, sizeof(MFG_Calib));
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;

              case PELAGIC_PROTOCOL_CMD_WRITE_USER_SET:
                  if(Eval_CRC16(&this_buf, sizeof(USER_Set)) == 0)
                  {
                    memcpy(&USER_Set, this_buf, sizeof(USER_Set));
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;

              case PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET:
                  if(Eval_CRC16(&this_buf, sizeof(SCUBA_Set)) == 0)
                  {
                    memcpy(&SCUBA_Set, this_buf, sizeof(SCUBA_Set));
                    InitializePLAN();
                    Display_PLANGF();
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;

              case PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET:
                  if(Eval_CRC16(&this_buf, sizeof(FREE_Set)) == 0)
                  {
                    memcpy(&FREE_Set, this_buf, sizeof(FREE_Set));
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;

              case PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET:
                  if(Eval_CRC16(&this_buf, sizeof(TRIMIX_Set)) == 0)
                  {
                    memcpy(&TRIMIX_Set, this_buf, sizeof(TRIMIX_Set));
                    InitializePLAN();
                    Display_PLANGF();
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;
                  
              case PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP:
                  if(Eval_CRC16(&this_buf, sizeof(FLASH_Map)) == 0)
                  {
                    memcpy(&FLASH_Map, this_buf, sizeof(FLASH_Map));
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;

              case PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC:
                  if(Eval_CRC16(&this_buf, sizeof(DEV_Rec)) == 0)
                  {
                    memcpy(&DEV_Rec, this_buf, sizeof(DEV_Rec));
                    DataCrcError = false;
                  }
                  else
                    DataCrcError = true;
                  break;
            }
            
            // the following condition output is modified from R1006, to add proper Bluetooth ACK (which was missing before R1006)
            if(!DataCrcError)
            {
                if( !NVDSaveData(pPkt) )
                    return true;        // to ack OK
                
                // all other conditions are consider false (return false at the end of this NVDWriteData( ) function)
            }
        }
    }
    return false;       // to ack NO GOOD
}

bool NVDSaveData(PPACKET * const pPkt)
{
    bool state = true;                 // set default as true (NO GOOD).  Added from R1006
    switch (pPkt->Header.CmdRsp)
    {
    case PELAGIC_PROTOCOL_CMD_WRITE_MFG_CAL:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_MFGCAL);          // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_USER_SET:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_USERSET);         // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        // ToRestoreBrightness();                               // from R1006, moved to the bottom of this function to apply for all other EE blocks saving
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_SCUBA_SET:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_SCUBASET);        // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_FREE_SET:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_FREESET);         // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_TRIMIX_SET:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_TRIMIXSET);       // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_EXFLASH_MAP:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_FLASHMAP);        // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;

    case PELAGIC_PROTOCOL_CMD_WRITE_DEV_REC:
        state = NVD_RAMBLOCK_to_ExtEEPROM (EE_DEVREC);          // from R1006, do EE24CWxxX_ReadNBytes readback checking from inside of NVD_RAMBLOCK_to_ExtEEPROM
        break;
        
    default:
        state = true;   // not supposed to come here, so set true (as Error).  check the definition of NVD_RAMBLOCK_to_ExtEEPROM( )
        break;
    }
    ToRestoreBrightness();        // from R1006, moved to the bottom of this function to apply for all other EE blocks saving
    return state;       // 0 (or false): OK;      1 (or true):  EEPROM Com Error, added from R1006
}




void St2Ble_SetName(PCMD_BLENAME Name)
{
    UART_BLE_On(BT_USART);
    
    BleRespone.RespCode = 0;
    BleRespone.RespReceived = false;
  
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_BLE_SETNAME, Name.NameString, Name.NameLength);

    ms_delay(100);

    UART_BLE_Off(BT_USART);
    
    Ble_Reset();
}

bool St2Ble_GetName(void)
{
    BleRespone.RespCode = 0;
    BleRespone.RespReceived = false;
    
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_BLE_GETNAME, BleName.NameString, 0);

    uint32_t retry = 0;
    while( (BleRespone.RespCode != PELAGIC_PROTOCOL_CMD_BLE_GETNAME) && (BleRespone.RespReceived != true) && (retry++<=10))
    {
        ms_delay(10);

        // Proccess commands
        if(BLE_RxProcessRequest)
        {
            BLE_RxProcessRequest = false;

            PPACKET *pkt = (PPACKET*)BLE_FIFO_Rx.fifo;
            ProcessResp(pkt);

            // Reset Rx Fifo to be ready receiveing new data
            UART_InitFifo(&BLE_FIFO_Rx);
        }
    }
    if(retry>10)
        return false;

    return true;
}

bool St2Ble_UART_Off(void)
{
    BleRespone.RespCode = 0;
    BleRespone.RespReceived = false;
  
    uint8_t data[2];
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_UART_OFF, &data, 0);

    uint32_t retry = 0;
    while( (BleRespone.RespCode != PELAGIC_PROTOCOL_CMD_UART_OFF) && (BleRespone.RespReceived != true) && (retry++<=10))
    {
        ms_delay(10);

        // Proccess commands
        if(BLE_RxProcessRequest)
        {
            BLE_RxProcessRequest = false;

            PPACKET *pkt = (PPACKET*)BLE_FIFO_Rx.fifo;
            ProcessResp(pkt);

            // Reset Rx Fifo to be ready receiveing new data
            UART_InitFifo(&BLE_FIFO_Rx);
        }
    }
        
    if(retry>10)
        return false;

    return true;
}

void St2Ble_SetTxPwr(int8_t dBm)
{
    uint8_t data[2];
    data[0] = dBm;
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_SET_TX_POWER, &data, 1);
}

void St2Ble_SetAdvInterval(uint32_t interval_ms)
{
    uint8_t data[4];
    /*
    data[0] = (uint8_t)(interval_ms>>24);
    data[1] = (uint8_t)(interval_ms>>16);
    data[2] = (uint8_t)(interval_ms>>8);
    data[3] = (uint8_t)(interval_ms);
    */
    data[0] = (uint8_t)(interval_ms);
    data[1] = (uint8_t)(interval_ms>>8);
    data[2] = (uint8_t)(interval_ms>>16);
    data[3] = (uint8_t)(interval_ms>>24);

    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_SET_ADV_INTERVAL, &data, 4);
}

bool St2Ble_SetExFlashWriteableRegions(uint32_t addressR0, uint32_t lengthR0, uint32_t addressR1, uint32_t lengthR1, uint32_t addressR2, uint32_t lengthR2)
{
    uint8_t data[24];

    data[0] = (uint8_t)(addressR0);
    data[1] = (uint8_t)(addressR0>>8);
    data[2] = (uint8_t)(addressR0>>16);
    data[3] = (uint8_t)(addressR0>>24);
    data[4] = (uint8_t)(lengthR0);
    data[5] = (uint8_t)(lengthR0>>8);
    data[6] = (uint8_t)(lengthR0>>16);
    data[7] = (uint8_t)(lengthR0>>24);

    data[8] = (uint8_t)(addressR1);
    data[9] = (uint8_t)(addressR1>>8);
    data[10] = (uint8_t)(addressR1>>16);
    data[11] = (uint8_t)(addressR1>>24);
    data[12] = (uint8_t)(lengthR1);
    data[13] = (uint8_t)(lengthR1>>8);
    data[14] = (uint8_t)(lengthR1>>16);
    data[15] = (uint8_t)(lengthR1>>24);

    data[16] = (uint8_t)(addressR2);
    data[17] = (uint8_t)(addressR2>>8);
    data[18] = (uint8_t)(addressR2>>16);
    data[19] = (uint8_t)(addressR2>>24);
    data[20] = (uint8_t)(lengthR2);
    data[21] = (uint8_t)(lengthR2>>8);
    data[22] = (uint8_t)(lengthR2>>16);
    data[23] = (uint8_t)(lengthR2>>24);

    BleRespone.RespCode = 0;    
    BleRespone.RespReceived = false;
    
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_SET_WR_REGION, &data, 24);

    uint32_t retry = 0;
    while( (BleRespone.RespCode != PELAGIC_PROTOCOL_CMD_SET_WR_REGION) && (BleRespone.RespReceived != true) && (retry++<=10))
    {
        ms_delay(10);

        // Proccess commands
        if(BLE_RxProcessRequest)
        {
            BLE_RxProcessRequest = false;

            PPACKET *pkt = (PPACKET*)BLE_FIFO_Rx.fifo;
            ProcessResp(pkt);

            // Reset Rx Fifo to be ready receiveing new data
            UART_InitFifo(&BLE_FIFO_Rx);
        }
    }
    if(retry>10)
        return false;

    return true;
}


void St2Ble_PowerDown(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;

    GPIO_InitStruct.Pin       = USART_RX_BT_TX_PIN;
    HAL_GPIO_Init(USART_RX_BT_TX_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(USART_RX_BT_TX_PORT, USART_RX_BT_TX_PIN, GPIO_PIN_RESET);
    
    SystemStatus.BLE_status = BLE_HDL_OFF;

    ms_delay(1);
    HAL_GPIO_WritePin(USART_RX_BT_TX_PORT, USART_RX_BT_TX_PIN, GPIO_PIN_SET);

    UART_BLE_On(BT_USART);
    ms_delay(10);

    uint8_t data[2];
    SendCmd(PFRAME_PKT_TYPE_CMDT, PELAGIC_PROTOCOL_CMD_BLE_PWRDWN, &data, 0);

    UART_BLE_Off(BT_USART);
    
    SystemStatus.BLE_ShutdownReq = false;
    
    ms_delay(20);     		// R1006 added for better connection after long SLEEP
}

void St2Ble_PowerOn(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin       = BT_RST_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = 0;
    HAL_GPIO_Init(BT_RST_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_RESET);

    if(DEV_Board())
    {
      GPIO_InitStruct.Pin       = BT_P3_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P3_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(BT_P3_PORT, BT_P3_PIN, GPIO_PIN_RESET);

      GPIO_InitStruct.Pin       = BT_P1_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P1_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = BT_P2_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P2_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = BT_P4_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(BT_P4_PORT, &GPIO_InitStruct);
    }
    else
    {
      GPIO_InitStruct.Pin       = PROD_BT_P3_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P3_PORT, &GPIO_InitStruct);
      HAL_GPIO_WritePin(PROD_BT_P3_PORT, PROD_BT_P3_PIN, GPIO_PIN_RESET);

      GPIO_InitStruct.Pin       = PROD_BT_P1_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P1_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = PROD_BT_P2_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P2_PORT, &GPIO_InitStruct);

      GPIO_InitStruct.Pin       = PROD_BT_P4_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull      = GPIO_NOPULL;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = 0;
      HAL_GPIO_Init(PROD_BT_P4_PORT, &GPIO_InitStruct);
    }
      
    // Reset BLE
    Ble_Reset();
    
    ms_delay(800); 			// R1006, to give BLE chip a sufficient time to handle Ble_Reset()  
        
    //CheckBTname();        // Check if BTname on EE same to BLE chip, otherwise assign valid EE-BTname to BLE chip     // commented out by Minh 20220506
}

void GeneratePassCode (void)
{
    SystemStatus.BLE_PsShowReq = true;
    SystemStatus.BLE_PsShowReqTimestamp = MonotonicClock_s;

    srand(MonotonicClock_s);
    for(uint32_t i = 0; i<6; i++)
    {
        uint32_t Random = (uint32_t)rand();
        SystemStatus.BLE_PassCode[i] = 0x30 + (uint8_t)(Random%10);
    }
}

bool PassCodeCheck(uint8_t *passcode)
{
    uint8_t *ptr = passcode;
    uint16_t sum1to4 = 0; //sum of the first 4 digits of passcode
    uint16_t last2; //combine last 2 digits of passcode to decimal

    last2 = ((uint16_t)*(ptr+4))*10 + (uint16_t)*(ptr+5);
    
    for(uint8_t i = 0; i<4; i++)
    {
        sum1to4 += *(ptr+i);
    }
    if((sum1to4 == last2) && (last2!=0)) return true; //if sum first 4 digits = last 2 digits combined decimal -> bypass passcode
    
    for(uint8_t i = 0; i<6; i++)
    {
        if((SystemStatus.BLE_PassCode[i]%0x30) != *(ptr+i))
            return false;
    }
    return true;
}

bool IsMacIdAllZero(uint8_t *macid)
{
    uint8_t *ptr = macid;

    for(uint8_t i = 0; i<16; i++)
    {
        if(*(ptr+i) != 0 )
            return false;
    }
    return true;
}


bool CheckMacId(uint8_t *macid)
{
    uint8_t *ptr = macid;

    for(uint8_t i = 0; i<16; i++)
    {
        if(MFG_Calib.MacId[i] != *(ptr+i))
            return false;
    }
    return true;
}

/*******************************************************************************
 * @brief   Reset Ble
 *
 * @note
 ******************************************************************************/
void Ble_Reset(void)
{
    ms_delay(1);
    HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_RESET);
    ms_delay(3);
    HAL_GPIO_WritePin(BT_RST_PORT, BT_RST_PIN, GPIO_PIN_SET);
    ms_delay(1);
    
    // Wait For BLE to Reset
    if(DEV_Board())
    {
      while(!BLE_IS_OFF) {};
    }
    else
    {
      while(!PROD_BLE_IS_OFF) {};
    }
}

/*******************************************************************************
 * @brief   Ble Ram Data Initializer function
 *
 * @note
 ******************************************************************************/
#define EXFLASH_R0_ADDRESS      0x00002000      // DO NOT CHANGE, must be 0x00002000
#define EXFLASH_R0_LENGTH       0x007FE400      // from 0x00002000 to 0x008003FF

#define EXFLASH_R1_ADDRESS      0x11000000
#define EXFLASH_R1_LENGTH       0x01000000      // from 0x11000000 to 0x11FFFFFF

#define EXFLASH_R2_ADDRESS      0x11000000
#define EXFLASH_R2_LENGTH       0x01000000      // from 0x11000000 to 0x11FFFFFF

bool Ble_RamInit (void)
{
    bool result = false;
    uint32_t retry = 0;

    // Swtich On ST Uart
    UART_BLE_On(BT_USART);

    // Set Writable Regions
    result = false;
    while( (!result) && (retry++<=10) )
    {
        result = St2Ble_SetExFlashWriteableRegions(  EXFLASH_R0_ADDRESS, EXFLASH_R0_LENGTH,
                                                     EXFLASH_R1_ADDRESS, EXFLASH_R1_LENGTH,
                                                     EXFLASH_R2_ADDRESS, EXFLASH_R2_LENGTH  );

        ms_delay(10);
    }
    if(retry>10)
        return false;

    // First to request BLE Chip to turn Off BLE-ST Uart
    //St2Ble_UART_Off();
  
    // Switch Off ST Uart
    UART_BLE_Off(BT_USART);

    return true;
}


/*******************************************************************************
 * @brief   Ble Name check and Initializer function
 *
 * @note
 ******************************************************************************/
bool Ble_NameInit (void)
{
    char NameString[16] = {0};
    
    //uint32_t serial = MFG_Calib.SN.SerialNum;
    
    NameString[0] = MFG_Calib.Prefix[0];
    NameString[1] = MFG_Calib.Prefix[1]; 
    NameString[2] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF00000) >> 20);
    NameString[3] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF0000) >> 16);
    NameString[4] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF000) >> 12);
    NameString[5] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF00) >> 8);
    NameString[6] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF0) >> 4);
    NameString[7] = 0x30+(char)((MFG_Calib.SN.SerialNum & 0xF));

    // check if 6 digits of SN are all legal (from 000001 to 999999)
    if( (MFG_Calib.SN.SerialNum > 0)
      &&((NameString[2]>=0x30)&&(NameString[2]<=0x39))
      &&((NameString[3]>=0x30)&&(NameString[3]<=0x39))
      &&((NameString[4]>=0x30)&&(NameString[4]<=0x39))
      &&((NameString[5]>=0x30)&&(NameString[5]<=0x39))
      &&((NameString[6]>=0x30)&&(NameString[6]<=0x39))
      &&((NameString[7]>=0x30)&&(NameString[7]<=0x39))
      )
    { 
        // OK, now check name
    }  
    else        // Device not initialized so leave default Ble Name
      return true;
  
    // Swtich On ST Uart
    UART_BLE_On(BT_USART);
    
    // Get Name from Ble
    St2Ble_GetName();
    
    // Check if name matches
    if(   (BleName.NameString[0] == NameString[0])
        &&(BleName.NameString[1] == NameString[1])
        &&(BleName.NameString[2] == NameString[2])           
        &&(BleName.NameString[3] == NameString[3])
        &&(BleName.NameString[4] == NameString[4])
        &&(BleName.NameString[5] == NameString[5])
        &&(BleName.NameString[6] == NameString[6])
        &&(BleName.NameString[7] == NameString[7]) )
    {
      // name matches do nothing
    }
    else
    {
      // BTname SN does NOT match with SN saved on EEPROM
      BleName.NameString[0] = NameString[0];
      BleName.NameString[1] = NameString[1];
      BleName.NameString[2] = NameString[2];
      BleName.NameString[3] = NameString[3];
      BleName.NameString[4] = NameString[4];
      BleName.NameString[5] = NameString[5];
      BleName.NameString[6] = NameString[6];
      BleName.NameString[7] = NameString[7]; 
      BleName.NameString[8] = 0;
      
      BleName.NameLength = 9;
        
      BleNameSetRequest = true;
    }
    
    // First to request BLE Chip to turn Off BLE-ST Uart
    //St2Ble_UART_Off();
  
    // Switch Off ST Uart
    UART_BLE_Off(BT_USART);
    
    return true;
}

/*******************************************************************************
 * @brief   Ble Handler function
 *
 * @note
 ******************************************************************************/
void Ble_Handler (void)
{
    // Switch Off BLE in Sleep Mode
    // Switch Off BLE during Dive and AfterDive
    if(   (SystemStatus.SystemPowerMode == SYS_PSM)
          || (SystemStatus.SystemPowerMode == SYS_SLEEP)
          || (SystemStatus.SystemPowerMode == SYS_DSLEEP)
          || (SystemStatus.SystemPowerMode == SYS_FDSLEEP)
          || (SystemStatus.SystemPowerMode == SYS_LBDSLEEP)
          || (Dive_Info.Status == AMB_DIVEINFO_DIVE)
          || (Dive_Info.Status == AMB_DIVEINFO_AFTERDIVE)
      )
    {
        if( (!BLE_IS_OFF && DEV_Board())
           || (!PROD_BLE_IS_OFF && !DEV_Board())
           )
        {
            SystemStatus.BLE_status = BLE_HDL_OFF;

            St2Ble_PowerDown();
        }

        return;
    }

    // Ble module Name Update Requested
    if(BleNameSetRequest)
    {
        BleNameSetRequest = false;

        if( (BLE_IS_OFF && DEV_Board())
           || (PROD_BLE_IS_OFF && !DEV_Board())
           )
        {
            St2Ble_PowerOn();
            if(DEV_Board())
            {
              while(!BLE_IS_OFF) {};
            }
            else
            {
              while(!PROD_BLE_IS_OFF) {};
            }
        }
        
        // Set BLE Name
        //St2Ble_SetName(BleName);                      // commented out by Minh on 20220506

        // Restart BLE state machine
        //SystemStatus.BLE_status = BLE_HDL_OFF;        // commented out by Minh on 20220506
    }

    /*******************************************************************************************************************************
    //  R1006 Gnss_Sleep or Gnss_Off for better BLE Connection; needs to do Gnss_WakeUp or Gnss_On after BLE Conneciton is formed
    *******************************************************************************************************************************/
    if(PROD_BLE_IS_CONNECTED)
    {
        if( (((MonotonicClock_s - SystemStatus.WakeUpTimestamp) > 8) && (Dive_Info.Status == AMB_DIVEINFO_NEWDAY))       // to avoid noise at P2 and P4 occuring at wakeup time
          ||(((MonotonicClock_s - SystemStatus.WakeUpTimestamp) > 3) && (Dive_Info.Status == AMB_DIVEINFO_SURF)) )       // allow BLE connection only after GUI showing Surface Main GUI
        {
            isBleConnected = true;
            if(isBleConnected_Pre != isBleConnected)
            {
                if(GnssStatus >= GNSS_ON)
                    Gnss_Sleep();
                else
                    Gnss_Off();
            }
            isBleConnected_Pre = isBleConnected;
        }
    }
    else
    {
        isBleConnected = false;
        if(isBleConnected_Pre != isBleConnected)
        {
            if(GnssStatus >= GNSS_SLEEP)
                Gnss_WakeUp();
            else
                Gnss_On();
        }
        isBleConnected_Pre = isBleConnected;
    }
    /*******************************************************************************************************************************
    //  R1006 Gnss_Sleep or Gnss_Off for better BLE Connection; needs to do Gnss_WakeUp or Gnss_On after BLE Conneciton is formed
    *******************************************************************************************************************************/
    
    switch(SystemStatus.BLE_status)
    {
    case BLE_HDL_OFF:

        // Switch On BLE if not already On
        if(DEV_Board())
        {
          if( BLE_IS_OFF && (BLUETOOTH_STAT == NVD_ON) )                
          {
              St2Ble_PowerOn();
          }
          // Switch Off BLE if not used
          if( (!BLE_IS_OFF) && ( (BLUETOOTH_STAT == NVD_OFF) ) )        
              St2Ble_PowerDown();
        }
        else
        {
          if( PROD_BLE_IS_OFF && (BLUETOOTH_STAT == NVD_ON) )           
              St2Ble_PowerOn();
          
          // Switch Off BLE if not used
          if( (!PROD_BLE_IS_OFF) && ( (BLUETOOTH_STAT == NVD_OFF) ) )
              St2Ble_PowerDown();
        }

        if( (BLUETOOTH_STAT == NVD_ON) )
        {
            Gnss_Off();
                
            if( (GnssStatus == GNSS_SLEEP) || (GnssStatus == GNSS_OFF) )      // Do St2Ble_PowerOn (including resetting Bluetooth) only after GnssStaus initialization is done
            {
                St2Ble_PowerOn();
                SystemStatus.BLE_status = BLE_HDL_WAIT_BLE_ON_1;
            }
        }
        break;

    case BLE_HDL_WAIT_BLE_ON_1:

        // Wait BLE to PowerUp
        if( (!BLE_IS_OFF && DEV_Board())
           || (!PROD_BLE_IS_OFF && !DEV_Board())
           )
        {
            SystemStatus.BLE_status = BLE_HDL_NAME_INIT;//BLE_HDL_RAM_INIT;
        }

        break;
        
    case BLE_HDL_NAME_INIT:

        // Execute Ble Name Initialization
        if(!Ble_NameInit())
        {
            DEV_Rec.SystemErrorWarningBits.Bluetooth = 1;
            SystemStatus.BLE_status = BLE_HDL_ERROR;
            
            break;
        }
        
        SystemStatus.BLE_status = BLE_HDL_RAM_INIT;

        break;

    case BLE_HDL_RAM_INIT:

        // Execute Ram Data Initialization
        if(!Ble_RamInit())
        {
            DEV_Rec.SystemErrorWarningBits.Bluetooth = 1;
            SystemStatus.BLE_status = BLE_HDL_ERROR;
        }
        else
            SystemStatus.BLE_status = BLE_HDL_READY;

        St2Ble_UART_Off();
        break;
        
    case BLE_HDL_READY:

        // Check if User Switch off BLE
        if( (BLUETOOTH_STAT == NVD_OFF) )                               // Removed "&& (!SystemStatus.DiagnosticRun)" by YS on 2022/06/24
        {
            // Power Down BLE
            St2Ble_PowerDown();

            SystemStatus.BLE_status = BLE_HDL_OFF;
            
            break;
        }

        // If Connection made go to next state
        if(   (BLE_IS_CONNECTED && DEV_Board())
           || (PROD_BLE_IS_CONNECTED && !DEV_Board())
           )
        {
            // Reset AccessGrant, Awake, WriteEnable Flags
            AccessGranted = false;
            Awake = false;
            WriteEnable = false;

            // Reset Rx Fifo on Rx Timeout
            UART_InitFifo(&BLE_FIFO_Rx);

            // Switch On Usart
            UART_BLE_On(BT_USART);

            SystemStatus.BLE_status = BLE_HDL_CONNECT;

            SystemStatus.System_ActiveReq = true;
            
            DEV_Rec.SystemErrorWarningBits.Bluetooth = 0;       // R1006 Remove any Bluetooth alarm if connection is successful
        }

        break;

    case BLE_HDL_CONNECT:

        // Check if User Switch off BLE
        if( (BLUETOOTH_STAT == NVD_OFF) || (SystemStatus.BLE_ShutdownReq == true) ) //YS20210923 Removed the old code for SystemDiagnostics's result turning OFF BLE
        {
            // Power Down BLE
            St2Ble_PowerDown();

            SystemStatus.BLE_status = BLE_HDL_OFF;

            break;
        }

        // Check if connection valid
        if( (BLE_IS_READY && DEV_Board())
           || (PROD_BLE_IS_READY && !DEV_Board())
           )
        {
            // First to request BLE Chip to turn Off BLE-ST Uart
            St2Ble_UART_Off();
  
            // Switch Off Usart
            UART_BLE_Off(BT_USART);

            SystemStatus.BLE_status = BLE_HDL_READY;

            break;
        }

        // Proccess commands
        if(BLE_RxProcessRequest)
        {
            BLE_RxProcessRequest = false;

            PPACKET *pkt = (PPACKET*)BLE_FIFO_Rx.fifo;
            ProcessPacket(pkt);

            // Reset Rx Fifo to be ready receiveing new data
            UART_InitFifo(&BLE_FIFO_Rx);
        }

        break;

    case BLE_HDL_ERROR:

        break;
    }
}


/******************************************************************************************
 *
 *   @brief   A delay for waiting GPS's initialization before Bluetooth Initialization
 *
 *   bool BluetoothReadyToInit(void)
 *
 *   @note 0: No Go; 1: Start to Init BLE
 *
 ******************************************************************************************/
bool BluetoothReadyToInit(void)
{
    if((DSX_Opcode == W1_WELCOME)||(DSX_Opcode == MANUFACTURE_SCREEN))
        return false;
    else
        return true;
}


#endif //_L4X9_BLE_H_
