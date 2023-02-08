/******************************************************************************/
//File: DSX_Data_Decode.c
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Created
//
/*****************************************************************************/
#include "L4X9_includes.h"
//-------------------------------Global variables------------------------------------------

extern uint8_t InclinedCompassFlag;// a flag to disable compass, while incline angle causes up-side-down
extern STRING_LANG StrLang_Select[];
extern U8 rData[];
extern uint8_t CompassCalibrated;
/*Private function declaration*/
//static void LOG_Record_Handle(uint8_t PosLogRecord);
//static void Handle_OC_USBCharing(ItemStatus_te USBCharging_Status);
//static void RAM_Calculate(void);
/*Extern variables*/
extern GUI_FONT FontAaux_1;
extern GUI_FONT FontAaux_2;
extern GUI_FONT FontAaux_3;
extern GUI_FONT FontAaux_4;
extern GUI_FONT FontAaux_5;
extern GUI_FONT FontAaux_6;
extern GUI_FONT FontAaux_7;
extern GUI_FONT FontAaux_8;
extern PLAN_Data_ts PLAN_Record[];
/*Global variable*/
DataLOG_ts LOG_Record[100];
/*Local variables*/

/*This stored font shall be coppied to detinate font*/
static GUI_TTF_DATA TTF_CustomFontData;
static GUI_TTF_CS CustomFontGenerate_1;
static GUI_TTF_CS CustomFontGenerate_2;
static GUI_TTF_CS CustomFontGenerate_3;
static GUI_TTF_CS CustomFontGenerate_4;
static GUI_TTF_CS CustomFontGenerate_5;
static GUI_TTF_CS CustomFontGenerate_6;
static GUI_TTF_CS CustomFontGenerate_7;
static GUI_TTF_CS CustomFontGenerate_8;
//static GUI_TTF_CS CustomFontGenerate_9;
//static GUI_TTF_CS CustomFontGenerate_10;
//static GUI_TTF_CS CustomFontGenerate_11;


void Text_GUI(void);    // temporary Text version Display before GUI is implemented

uint8_t LOG_TransferErr = FALSE;
extern uint16_t CompassCalibrationTimeOutCnt;
//--------------------------------------------------------------------------------------

uint8_t CheckOverlappedProfiles(void);
uint8_t Err = 0;
uint8_t Check = 0;
//-------------------------------------------------------------------------------/

/*
  same family: = same high nibbles;    different family: =  different high nibbles

    same family:    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A
    same family:    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A

    diff family:    0x10, 0x21, 0x32, 0x43, 0x54, 0x65, 0x76, 0x87, 0x98, 0xA9, 0xBA
    diff family:    0xA2, 0x92, 0x82, 0x72, 0x62, 0x52, 0x42, 0x32, 0x22, 0x12, 0x02
*/

uint8_t DifferentFamily(uint8_t a, uint8_t b)
{
    if((a&0xF0) == (b&0xF0))
        return FALSE; // same family
    else
        return TRUE;  // different family
}


void UpdateOpcodeValue(void)
{
    pre_DSX_Opcode = DSX_Opcode;
}
unsigned char OpcodeChangedState(void)
{
    unsigned char status = 0;
    /*Validate the opcode value and opcode changed value*/
    if((pre_DSX_Opcode != DSX_Opcode)&&(OC_ValueMax > DSX_Opcode)&&(0 <= DSX_Opcode))
    {
        status = 1;
    }
    return status;
}
/*
Base on the flipped screen status assigned the coordinate to screen
*/
void Decode_DSX_Data(void)
{
    /*When opcode is changed*/
    if(OpcodeChangedState())
    {
        /*1. Check condition to clear all screen*/
        if(ConditionCheckFunc[DSX_Opcode]())
        {
            IniFunc_Handle[DSX_Opcode]();
        }
        else
        {
            /*After update new opcode value -> Check preOpcode hanlde*/
            if(CondCheckPreOCFunc[pre_DSX_Opcode]())
            {
                HandlePreOCFunc[pre_DSX_Opcode]();
            }
            else
            {
                /*Do nothing*/
            }
            /*2. Update the portion new OC only*/
            UpdatePortionFunc_Handle[DSX_Opcode]();
        }
    }
    else
    {
        /*3. Keep update the data of items or flashing*/
        UpdateOrFlashFunc[pre_DSX_Opcode]();
    }
    /*Update the opcode value*/
    UpdateOpcodeValue();
}

/*------------------------------------------ End DIVE SIMULATOR handle context ----------------------------------------*/

int _GetData(void *p, const U8 ** ppData, unsigned NumBytes, U32 Off) {
    uint8_t *pDest = (uint8_t *)*ppData;
    const STRING_LANG *current_lang = p;
    int bytes_read = (NumBytes > current_lang->NumBytes) ? current_lang->NumBytes : NumBytes;
    memcpy(pDest, current_lang->pData + Off, bytes_read);
    return bytes_read;
}
/*Pointer to data source font*/

//static void RAM_Calculate(void) {
//    GUI_SetColor(GUI_RED);
//    GUI_SetBkColor(GUI_BLACK);
//    uint32_t used_int13 = UsageIntRAM(0xEE);
//    GUI_SetFont(&GUI_Font20_1);
//    GUI_DispStringAt("OC: 0x", 240, 200);
//    GUI_DispHexAt((int32_t)OpCode, 295, 200, 2);
//    GUI_DispDecAt((int32_t)(used_int13/1024), 240, 220, 4);
//}
#include "..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_ASCII_Latin_1.c"
//#include "..\..\Libraries\Drivers\TTF_Fonts\Korean_Latin.c"
//#include "..\..\Libraries\Drivers\TTF_Fonts\QiHei_Simp256.c"
//#include "..\..\Libraries\Drivers\TTF_Fonts\QiHei_AlphNumTrad_261.c"
#include "..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_China_S.c"
#include "..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_Korean.c"
#include "..\..\Libraries\Drivers\TTF_Fonts\AauxProBlack_China_T.c"




void TTF_CreateFontSequence(const FontSize_ts _FontSize)
{
    GUI_TTF_Done();
    // GUI_TTF_SetCacheSize(1, 8, 300);//Set max 8 fonts and 300kb
    /*Get the data font*/
    /* Set creation parameters of font */

    if(USER_Set.LangSelec==Select_CHINESE_S) {
        TTF_CustomFontData.pData = _acAauxProBlack_China_S;
        TTF_CustomFontData.NumBytes = sizeof(_acAauxProBlack_China_S);
    }

    else if(USER_Set.LangSelec==Select_CHINESE_T) {
        TTF_CustomFontData.pData = _acAauxProBlack_China_T;
        TTF_CustomFontData.NumBytes = sizeof(_acAauxProBlack_China_T);
    }
//    else if(LANGUAGE==STRING_LANG_RUSSIAN) {
//        TTF_CustomFontData.pData = _acASCII_Russian;
//        TTF_CustomFontData.NumBytes = sizeof(_acASCII_Russian);
//    }

    else if(USER_Set.LangSelec==Select_KOREAN) {
        TTF_CustomFontData.pData = _acAauxProBlack_Korean;
        TTF_CustomFontData.NumBytes = sizeof(_acAauxProBlack_Korean);
    }

    else {
        TTF_CustomFontData.pData = _acAauxProBlack_ASCII_Latin_1;
        TTF_CustomFontData.NumBytes = sizeof(_acAauxProBlack_ASCII_Latin_1);
    }
    //Font parameters 1
    CustomFontGenerate_1.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_1.PixelHeight = _FontSize.Size_1;
    CustomFontGenerate_1.FaceIndex = 0;
    //Font parameters 2
    CustomFontGenerate_2.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_2.PixelHeight = _FontSize.Size_2;
    CustomFontGenerate_2.FaceIndex = 0;
    //Font parameters 3
    CustomFontGenerate_3.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_3.PixelHeight = _FontSize.Size_3;
    CustomFontGenerate_3.FaceIndex = 0;
    //Font parameters 4
    CustomFontGenerate_4.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_4.PixelHeight = _FontSize.Size_4;
    CustomFontGenerate_4.FaceIndex = 0;
    //Font parameters 5
    CustomFontGenerate_5.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_5.PixelHeight = _FontSize.Size_5;
    CustomFontGenerate_5.FaceIndex = 0;
    //Font parameters 6
    CustomFontGenerate_6.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_6.PixelHeight = _FontSize.Size_6;
    CustomFontGenerate_6.FaceIndex = 0;
    //Font parameters 7
    CustomFontGenerate_7.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_7.PixelHeight = _FontSize.Size_7;
    CustomFontGenerate_7.FaceIndex = 0;
    //Font parameters 8
    CustomFontGenerate_8.pTTF = &TTF_CustomFontData;
    CustomFontGenerate_8.PixelHeight = _FontSize.Size_8;
    CustomFontGenerate_8.FaceIndex = 0;
#if 1
    /*Using Antialiasing*/
    while(GUI_TTF_CreateFontAA(&FontAaux_1, &CustomFontGenerate_1)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_2, &CustomFontGenerate_2)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_3, &CustomFontGenerate_3)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_4, &CustomFontGenerate_4)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_5, &CustomFontGenerate_5)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_6, &CustomFontGenerate_6)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_7, &CustomFontGenerate_7)) {};
    while(GUI_TTF_CreateFontAA(&FontAaux_8, &CustomFontGenerate_8)) {};
#else
    while(GUI_TTF_CreateFont(&FontAaux_1, &CustomFontGenerate_1)) {};
    while(GUI_TTF_CreateFont(&FontAaux_2, &CustomFontGenerate_2)) {};
    while(GUI_TTF_CreateFont(&FontAaux_3, &CustomFontGenerate_3)) {};
    while(GUI_TTF_CreateFont(&FontAaux_4, &CustomFontGenerate_4)) {};
    while(GUI_TTF_CreateFont(&FontAaux_5, &CustomFontGenerate_5)) {};
    while(GUI_TTF_CreateFont(&FontAaux_6, &CustomFontGenerate_6)) {};
    while(GUI_TTF_CreateFont(&FontAaux_7, &CustomFontGenerate_7)) {};
    while(GUI_TTF_CreateFont(&FontAaux_8, &CustomFontGenerate_8)) {};
    while(GUI_TTF_CreateFont(&FontAaux_9, &CustomFontGenerate_9)) {};
    while(GUI_TTF_CreateFont(&FontAaux_10, &CustomFontGenerate_10)) {};
    while(GUI_TTF_CreateFont(&FontAaux_11, &CustomFontGenerate_11)) {};
#endif
}


//***************************************************************************
// ATH modified date October 22, 2021
void Text_GUI(void)
{
    char _DispStringTemp[100], I, N, X, Y;
    int Z;


    GUI_SetBkColor(GUI_BLUE);
    GUI_Clear();
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(GUI_FONT_20_ASCII);     // Choices of 32, 24, 20, 16, 13, 10, 8


    if((DSX_Opcode >= S154_SET_DATE)&&(DSX_Opcode <= S158_SET_AM_PM))
        sprintf(_DispStringTemp, "Time: %02d:%02d:%02d  %02d/%02d/%02d", GUI_SetDateTime.Hour, GUI_SetDateTime.Minute, GUI_SetDateTime.Second, GUI_SetDateTime.Day, GUI_SetDateTime.Month, GUI_SetDateTime.Year);
    else
    {
        if(SWITCH_DDMM_Format==true)
        {
            sprintf(_DispStringTemp, "Time: %02d:%02d:%02d  %02d/%02d/%02d", SysTimeDatePST.Hour, SysTimeDatePST.Minute, SysTimeDatePST.Second, SysTimeDatePST.Day, SysTimeDatePST.Month, SysTimeDatePST.Year);
        }
        else
        {
            sprintf(_DispStringTemp, "Time: %02d:%02d:%02d  %02d/%02d/%02d", SysTimeDatePST.Hour, SysTimeDatePST.Minute, SysTimeDatePST.Second, SysTimeDatePST.Month, SysTimeDatePST.Day, SysTimeDatePST.Year);
        }
    }

    // GUI_DispStringAt(_DispStringTemp, 0, 0);

    //sprintf(_DispStringTemp, "%.1f mbar", TP_Info.InstantPressure_mbar);
    //GUI_DispStringAt(_DispStringTemp, 0, 25);

    //sprintf(_DispStringTemp, "%.1f F", TP_Info.InstantTemperature_F);
    //GUI_DispStringAt(_DispStringTemp, 160, 25);

    //sprintf(_DispStringTemp, "%.1f C", TP_Info.InstantTemperature_C);
    //GUI_DispStringAt(_DispStringTemp, 240, 25);

    if (UNITS == NVD_IMPERIAL)
        sprintf(_DispStringTemp, "Depth: %.1f ft", Dive_Info.WaterDepth_ft);
    else
        sprintf(_DispStringTemp, "Depth: %.1f m", Dive_Info.WaterDepth_m);

    GUI_DispStringAt(_DispStringTemp, 0, 0);

    //sprintf(_DispStringTemp, "SurfT: %d Sec", Dive_Info.SurfTime_s);
    //GUI_DispStringAt(_DispStringTemp, 0, 75);

    sprintf(_DispStringTemp, "DiveT: %d Sec", Dive_Info.DiveTime_s);
    GUI_DispStringAt(_DispStringTemp, 0, 25);

    if (isViolation == true)
    {
        sprintf(_DispStringTemp, "Violation Dive");
        GUI_DispStringAt(_DispStringTemp, 0, 75);
        sprintf(_DispStringTemp, "ATR=%d", ATR);
        GUI_DispStringAt(_DispStringTemp, 0, 100);

        if(DIVE_MODE==NVD_MDOC)
            sprintf(_DispStringTemp, "OC-%d", TRIMIX_Set.CurrGasNumber_OC);
        else if(DIVE_MODE==NVD_MDCC)
            sprintf(_DispStringTemp, "CC-%d", TRIMIX_Set.CurrGasNumber_CC);
        else if(DIVE_MODE==NVD_MDSM)
            sprintf(_DispStringTemp, "SM-%d", TRIMIX_Set.CurrGasNumber_SM);
        else if(DIVE_MODE==NVD_MDGSM)
            sprintf(_DispStringTemp, "GSM-%d", TRIMIX_Set.CurrTMT_Number_GSM);
        else
            sprintf(_DispStringTemp, "GSM-%d", TRIMIX_Set.CurrTMT_Number_GAUGE);

        GUI_DispStringAt(_DispStringTemp, 160, 0);

        sprintf(_DispStringTemp, "ASC=%d", ASCBGVal);
        GUI_DispStringAt(_DispStringTemp, 160, 50);
    }
    else if (isGaugeMode == true)
    {
        sprintf(_DispStringTemp, "Gauge Dive");
        GUI_DispStringAt(_DispStringTemp, 0, 75);
        // sprintf(_DispStringTemp, "ATR=%d", ATR);
        // GUI_DispStringAt(_DispStringTemp, 0, 100);
        sprintf(_DispStringTemp, "ASC=%d", ASCBGVal);
        GUI_DispStringAt(_DispStringTemp, 160, 50);

    }
    else
    {
        if (isCCMode == true)
        {
            sprintf(_DispStringTemp, "Dil_PO2=%1.2f", Dil_PO2);
        }
        else
        {
            sprintf(_DispStringTemp, "PO2=%1.2f", PO2atDepth);
        }
        GUI_DispStringAt(_DispStringTemp,  0, 50);

        sprintf(_DispStringTemp, "O2Sat=%d%", OTUpercent);
        GUI_DispStringAt(_DispStringTemp, 0, 75);

        sprintf(_DispStringTemp, "NDT=%d", NDT_Data);
        GUI_DispStringAt(_DispStringTemp, 0, 100);

        sprintf(_DispStringTemp, "DecoD-T=%d-%d", DecoStop[1], Total_DST);
        GUI_DispStringAt(_DispStringTemp, 0, 125);

        sprintf(_DispStringTemp, "TAT = %d", TAT_Data);
        GUI_DispStringAt(_DispStringTemp, 0, 150);

        sprintf(_DispStringTemp, "Cond = %d", ConditionTime);
        GUI_DispStringAt(_DispStringTemp, 0, 175);

        if (isCCMode == true)
        {
            sprintf(_DispStringTemp, "FiO2=%d%", FiO2);
            GUI_DispStringAt(_DispStringTemp,  0, 200);
        }
        else
        {
            sprintf(_DispStringTemp, "FO2=%2d%", (FO2A[0]));
            GUI_DispStringAt(_DispStringTemp, 0, 200);
        }


        if (DecoTime[1] != 0)
        {
            if (SCUBA_Set.LastStopFt == 10)
                N = DecoStop[1] / 10;
            else
                N = (DecoStop[1] / 10) - 1;

            if (N < 10 )
            {
                if (UNITS == NVD_IMPERIAL)
                {
                    for (I = 1; I <= N; ++I)
                    {
                        if (I == 1)
                            sprintf(_DispStringTemp, "%d - %d", DecoStop[I], Total_DST);
                        else
                            sprintf(_DispStringTemp, "%d - %d", DecoStop[I], DecoTime[I]);
                        Y = (I - 1) * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }
                }
                else
                {
                    for (I = 1; I <= N; ++I)
                    {
                        Z = (int) (DecoStop[I] * 0.3);
                        if (I == 1)
                            sprintf(_DispStringTemp, "%d - %d", Z, Total_DST);
                        else
                            sprintf(_DispStringTemp, "%d - %d", Z, DecoTime[I]);
                        Y = (I - 1) * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }
                }
            }
            else if (N < 19)
            {
                if (UNITS == NVD_IMPERIAL)
                {
                    for (I = 1; I <= 9; ++I)
                    {
                        if (I == 1)
                            sprintf(_DispStringTemp, "%d - %d", DecoStop[I], Total_DST);
                        else
                            sprintf(_DispStringTemp, "%d - %d", DecoStop[I], DecoTime[I]);

                        Y = (I - 1) * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }

                    for (I = 10; I <= N; ++I)
                    {
                        sprintf(_DispStringTemp, "%d - %d", DecoStop[I], DecoTime[I]);
                        Y = (I - 10) * 25;
                        GUI_DispStringAt(_DispStringTemp,  240,Y);
                    }
                }
                else
                {
                    for (I = 1; I <= 9; ++I)
                    {
                        Z = (int) (DecoStop[I] * 0.3);
                        if (I == 1)
                            sprintf(_DispStringTemp, "%d - %d", Z, Total_DST);
                        else
                            sprintf(_DispStringTemp, "%d - %d", Z, DecoTime[I]);

                        Y = (I - 1) * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }
                    for (I = 10; I <= N; ++I)
                    {
                        Z = (int) (DecoStop[I] * 0.3);
                        sprintf(_DispStringTemp, "%d - %d", Z, DecoTime[I]);
                        Y = (I - 10) * 25;
                        GUI_DispStringAt(_DispStringTemp,  240,Y);
                    }
                }
            }
            else // N > 18 ceiling
            {
                X = 0;

                if (UNITS == NVD_IMPERIAL)
                {
                    for (I = (N-17); I <= (N-9); ++I)
                    {
                        sprintf(_DispStringTemp, "%d - %d", DecoStop[I], DecoTime[I]);
                        Y = X++ * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }

                    X = 0;
                    for (I = (N-8); I <= N; ++I)
                    {
                        sprintf(_DispStringTemp, "%d - %d", DecoStop[I], DecoTime[I]);
                        Y = X++ * 25;
                        GUI_DispStringAt(_DispStringTemp,  240,Y);
                    }
                }
                else
                {
                    for (I = (N-17); I <= (N-9); ++I)
                    {
                        Z = (int) (DecoStop[I] * 0.3);
                        sprintf(_DispStringTemp, "%d - %d", Z, DecoTime[I]);
                        Y = X++ * 25;
                        GUI_DispStringAt(_DispStringTemp,  150,Y);
                    }

                    X = 0;
                    for (I = (N-8); I <= N; ++I)
                    {
                        Z = (int) (DecoStop[I] * 0.3);
                        sprintf(_DispStringTemp, "%d - %d", Z, DecoTime[I]);
                        Y = X++ * 25;
                        GUI_DispStringAt(_DispStringTemp,  240,Y);
                    }
                }
            }
        }
        else
        {
            if(DIVE_MODE==NVD_MDOC)
                sprintf(_DispStringTemp, "OC-%d", TRIMIX_Set.CurrGasNumber_OC);
            else if(DIVE_MODE==NVD_MDCC)
                sprintf(_DispStringTemp, "CC-%d", TRIMIX_Set.CurrGasNumber_CC);
            else if(DIVE_MODE==NVD_MDSM)
                sprintf(_DispStringTemp, "SM-%d", TRIMIX_Set.CurrGasNumber_SM);
            else if(DIVE_MODE==NVD_MDGSM)
                sprintf(_DispStringTemp, "GSM-%d", TRIMIX_Set.CurrTMT_Number_GSM);
            else
                sprintf(_DispStringTemp, "GSM-%d", TRIMIX_Set.CurrTMT_Number_GAUGE);


            GUI_DispStringAt(_DispStringTemp, 160, 0);

            sprintf(_DispStringTemp, "ATR=%d", ATR);
            GUI_DispStringAt(_DispStringTemp, 160, 25);

            sprintf(_DispStringTemp, "ASC=%d", ASCBGVal);
            GUI_DispStringAt(_DispStringTemp, 160, 50);

            sprintf(_DispStringTemp, "TLBG=%d", TLBGVal);
            GUI_DispStringAt(_DispStringTemp, 160, 75);

            sprintf(_DispStringTemp, "GF=%d", GFBGVal);
            GUI_DispStringAt(_DispStringTemp, 160, 100);

        }


    }

}
void FuncDoNothing(void)
{
    /*Nope do nothing*/
}
unsigned char ReturnTrue(void)
{
    return TRUE;
}
unsigned char ReturnFalse(void)
{
    return FALSE;
}
void ContextEmpty(char* pStrRet)
{
    strcpy(pStrRet, " ");
}

