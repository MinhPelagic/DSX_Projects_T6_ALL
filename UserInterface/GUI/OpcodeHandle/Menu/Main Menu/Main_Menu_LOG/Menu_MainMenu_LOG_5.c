/******************************************************************************/
//File: LOG 5
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"

void IniOrClrScrFunc_S36_LOG_DATA5(void)
{
    GUI_MEMDEV_Handle hmemDisplay;
    /**/
    GUI_Clear();
    /*When empty list no progress*/
    if(LogMenu_CheckLogIsEmpty())
    {
        /*No dive yet*/
        LogMenu_DisplayNODIVEYET();
    }
    else
    {
        char pStrRet[LangMaxLength];
        uint8_t LogO2Sat, LogHiPO2, LogLoPO2, LogMaxGF, LogDiveType, LogEndDiveType;
        uint16_t LogMaxPO2;
        DisplayTimeOfLOGatTOP();
        /**
        Display the information:
        1. O2 SAT (END)
        2. GF Highest
        3. PO2 Highest
        4. SP HIGH-LOW
        Clear all the portion first then display
        */
        LogO2Sat  = Log_Data_7[log01HighlightItem_i].O2Sat;
        LogMaxPO2 = Log_Data_7[log01HighlightItem_i].MaxPO2;
        LogHiPO2  = Log_Data_7[log01HighlightItem_i].CC_HiPO2;
        LogLoPO2  = Log_Data_7[log01HighlightItem_i].CC_LoPO2;
        LogMaxGF  = Log_Data_7[log01HighlightItem_i].CC_MaxGF;
        LogDiveType     = Log_Data_7[log01HighlightItem_i].DiveType;
        LogEndDiveType  = Log_Data_7[log01HighlightItem_i].EndDiveType;
        /**1. O2 SAT (END)*/
        if(LogDiveType!=NVD_MDGAUGE)
        {
            hmemDisplay = GUI_MEMDEV_CreateEx(Pos_LogData05_RectClear->X0, Pos_LogData05_RectClear->Y0,\
                                              Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Height, GUI_MEMDEV_HASTRANS);
            GUI_MEMDEV_Select(hmemDisplay);
            GUI_ClearRect( Pos_LogData05_RectClear->X0, Pos_LogData05_RectClear->Y0,\
                           Pos_LogData05_RectClear->X1, Pos_LogData05_RectClear->Y1);
            SetFont_3;
            GUI_SetColor(GUI_CYAN);
            GUI_SetTextAlign(GUI_TA_CENTER);
            GUI_DispStringAt(GUI_LANG_GetText(TxtStr_O2_SAT_END), Pos_LogData05_RectClear->X, Pos_LogData05_RectClear->Y0);
            SetFont_5;
            GUI_SetColor(GUI_WHITE);
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, "%d%%",LogO2Sat);
            GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X, Pos_LogData05_RectClear->Y);
            GUI_MEMDEV_CopyToLCD(hmemDisplay);
            GUI_MEMDEV_Delete(hmemDisplay);
            /**2. GF Highest*/
            hmemDisplay = GUI_MEMDEV_CreateEx(Pos_LogData05_RectClear->X0 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0,\
                                              Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Height, GUI_MEMDEV_HASTRANS);
            GUI_MEMDEV_Select(hmemDisplay);
            GUI_ClearRect( Pos_LogData05_RectClear->X0 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0,\
                           Pos_LogData05_RectClear->X1 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y1);
            SetFont_3;
            GUI_SetColor(GUI_CYAN);
            GUI_SetTextAlign(GUI_TA_CENTER);
            GUI_DispStringAt(GUI_LANG_GetText(TxtStr_GF_HIGHEST), Pos_LogData05_RectClear->X + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0);
            SetFont_5;
            GUI_SetColor(GUI_WHITE);
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, "%d", LogMaxGF);
            GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y);
            GUI_MEMDEV_CopyToLCD(hmemDisplay);
            GUI_MEMDEV_Delete(hmemDisplay);
        }
        /**3. PO2 Highest*/
        hmemDisplay = GUI_MEMDEV_CreateEx(Pos_LogData05_RectClear->X0, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height,\
                                          Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemDisplay);
        GUI_ClearRect( Pos_LogData05_RectClear->X0, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height,\
                       Pos_LogData05_RectClear->X1, Pos_LogData05_RectClear->Y1 + Pos_LogData05_RectClear->Height);
        SetFont_3;
        GUI_SetColor(GUI_CYAN);
        GUI_SetTextAlign(GUI_TA_CENTER);
        sprintf(pStrRet, GUI_LANG_GetText(TxtStr_PO2_HIGHEST));
        GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height);
        SetFont_5;
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextAlign(GUI_TA_CENTER);
        sprintf(pStrRet, "%1.2f", 0.01*LogMaxPO2);
        GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X, Pos_LogData05_RectClear->Y + Pos_LogData05_RectClear->Height);
        GUI_MEMDEV_CopyToLCD(hmemDisplay);
        GUI_MEMDEV_Delete(hmemDisplay);
        /**4. SP High-Low*/
        hmemDisplay = GUI_MEMDEV_CreateEx(Pos_LogData05_RectClear->X0 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height,\
                                          Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemDisplay);
        GUI_ClearRect( Pos_LogData05_RectClear->X0 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height,\
                       Pos_LogData05_RectClear->X1 + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y1 + Pos_LogData05_RectClear->Height);
        if((LogDiveType==NVD_MDCC)||(LogEndDiveType==NVD_MDCC))
        {
            SetFont_3;
            GUI_SetColor(GUI_CYAN);
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, GUI_LANG_GetText(TxtStr_SP_HIGH_LOW));
            GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y0 + Pos_LogData05_RectClear->Height);
            SetFont_5;
            GUI_SetColor(GUI_WHITE);
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, "%1.2f-%1.2f", 0.01*LogHiPO2, 0.01*LogLoPO2);
            GUI_DispStringAt(pStrRet, Pos_LogData05_RectClear->X + Pos_LogData05_RectClear->Width, Pos_LogData05_RectClear->Y + Pos_LogData05_RectClear->Height);
            GUI_MEMDEV_CopyToLCD(hmemDisplay);
            GUI_MEMDEV_Delete(hmemDisplay);
        }
        Display_Icon_Buttons(IconBottDisp_BackHomeNext);
    }
}