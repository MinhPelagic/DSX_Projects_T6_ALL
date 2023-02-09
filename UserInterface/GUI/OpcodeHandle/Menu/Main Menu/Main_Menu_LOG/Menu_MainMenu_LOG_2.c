/******************************************************************************/
//File: LOG 2
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"
void DisplayTimeOfLOGatTOP(void)
{
    char pStrRet[LangMaxLength];
    uint16_t LogNumOfDive;
    //uint16_t LogNumToDisp;
    uint16_t LogNumOfDay;
    uint8_t LogMonth, LogDay, LogYear, LogHour, LogMinute;
    /*
    Display title with information format
    #LOG: #Dive - Date - Time
    */
    LogNumOfDive    = Log_Data_7[log01HighlightItem_i].LogNum;
    //LogNumToDisp    = DEV_Rec.LogNumDisp;
    LogNumOfDay     = Log_Data_7[log01HighlightItem_i].DiveNum;
    LogMonth   = Log_Data_7[log01HighlightItem_i].EntryMon;
    LogDay     = Log_Data_7[log01HighlightItem_i].EntryDay;
    LogYear    = Log_Data_7[log01HighlightItem_i].EntryYear;
    LogHour    = Log_Data_7[log01HighlightItem_i].EntryHr;
    LogMinute  = Log_Data_7[log01HighlightItem_i].EntryMin;

    if(NVD_24HR == SWITCH_HR24_Format)
    {
        if(SWITCH_DDMM_Format==true)
            sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02d", LogNumOfDive, LogNumOfDay, LogDay, LogMonth, LogYear, LogHour, LogMinute);
        else
            sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02d", LogNumOfDive, LogNumOfDay, LogMonth, LogDay, LogYear, LogHour, LogMinute);
    }
    else
    {
        if(LogHour == 12)           // for 12PM
        {
            if(SWITCH_DDMM_Format==true)
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dP", LogNumOfDive, LogNumOfDay, LogDay, LogMonth, LogYear, LogHour, LogMinute);
            else
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dP", LogNumOfDive, LogNumOfDay, LogMonth, LogDay, LogYear, LogHour, LogMinute);
        }
        else if(LogHour > 12)       // for 1PM to 11PM
        {
            LogHour -= 12;
            if(SWITCH_DDMM_Format==true)
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dP", LogNumOfDive, LogNumOfDay, LogDay, LogMonth, LogYear, LogHour, LogMinute);
            else
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dP", LogNumOfDive, LogNumOfDay, LogMonth, LogDay, LogYear, LogHour, LogMinute);
        }
        else if(LogHour == 0)       // for 12AM
        {
            LogHour = 12;
            if(SWITCH_DDMM_Format==true)
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dA", LogNumOfDive, LogNumOfDay, LogDay, LogMonth, LogYear, LogHour, LogMinute);
            else
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dA", LogNumOfDive, LogNumOfDay, LogMonth, LogDay, LogYear, LogHour, LogMinute);
        }
        else                        // for 1AM to 11AM
        {
            if(SWITCH_DDMM_Format==true)
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dA", LogNumOfDive, LogNumOfDay, LogDay, LogMonth, LogYear, LogHour, LogMinute);
            else
                sprintf(pStrRet, "%d: #%d - %02d/%02d/%02d - %02d:%02dA", LogNumOfDive, LogNumOfDay, LogMonth, LogDay, LogYear, LogHour, LogMinute);
        }
    }
    DisplayText_TopBar_LOGTittle(pStrRet);
}
void IniOrClrScrFunc_S29_LOG_DATA2(void)
{
    uint16_t StartPSI, EndPSI, GasMin;
    GUI_MEMDEV_Handle hmemDevlocal;
    int16_t AvgConsumpRate = 0;
    char pStrRet[LangMaxLength];

    GUI_Clear();
    if(LogMenu_CheckLogIsEmpty())
    {
        /*No dive yet*/
        LogMenu_DisplayNODIVEYET();
    }
    else
    {
        DisplayTimeOfLOGatTOP();
        Display_Icon_Buttons(IconBottDisp_BackHomeNext);
        /**
        Display tille of coloumn
        START PSI	END PSI		AVFSAC
        */
        hmemDevlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, Pos_Item_Select_List->Y0, (320U - Pos_Item_Select_List->X0),Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemDevlocal);
        GUI_ClearRect(Pos_Item_Select_List->X0, Pos_Item_Select_List->Y0, 320U, Pos_Item_Select_List->Y1);
        GUI_SetFont(&FontAaux_2);
        GUI_SetColor(GUI_CYAN);
        GUI_SetTextAlign(GUI_TA_CENTER);
        if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
            sprintf(pStrRet, "%s%s", GUI_LANG_GetText(TxtStr_START), TxtDef_Set_PressUnit[UNITS]);
        else
            sprintf(pStrRet, "%s %s", GUI_LANG_GetText(TxtStr_START), TxtDef_Set_PressUnit[UNITS]);
        GUI_DispStringAt(pStrRet, Point_LogMode02_StartPSI->x, Point_LogMode02_StartPSI->y);
        GUI_SetTextAlign(GUI_TA_CENTER);
        if((LANGUAGE==Select_CHINESE_T)||(LANGUAGE==Select_CHINESE_S))
            sprintf(pStrRet, "%s%s", GUI_LANG_GetText(TxtStr_END), TxtDef_Set_PressUnit[UNITS]);
        else
            sprintf(pStrRet, "%s %s", GUI_LANG_GetText(TxtStr_END), TxtDef_Set_PressUnit[UNITS]);
        GUI_DispStringAt(pStrRet, Point_LogMode02_EndPSI->x, Point_LogMode02_EndPSI->y);
        GUI_SetTextAlign(GUI_TA_CENTER);
        sprintf(pStrRet,GUI_LANG_GetText(TxtStr_AVG_CONSUMP));
        GUI_DispStringAt(pStrRet, Point_LogMode02_AvgSAC->x, Point_LogMode02_AvgSAC->y);
        GUI_MEMDEV_CopyToLCD(hmemDevlocal);
        GUI_MEMDEV_Delete(hmemDevlocal);
        /**
        Display the information in that Log
        */
        GUI_SetColor(GUI_WHITE);
        GUI_SetFont(&FontAaux_3);
        for(uint8_t i_u8 = 1; i_u8<=MaxItemPlan; i_u8++)
        {
            bool TMT_On = false;

            StartPSI = Log_Data_7[log01HighlightItem_i].Start_PSI[i_u8];
            EndPSI   = Log_Data_7[log01HighlightItem_i].End_PSI[i_u8];
            GasMin  = Log_Data_7[log01HighlightItem_i].TankTimeMin[i_u8];

            if(Log_Data_7[log01HighlightItem_i].EndDiveType != Log_Data_7[log01HighlightItem_i].DiveType)       // No Bailout in CC, OC, SM, GSM, Gauge
            {
                //BailoutStartPSI = Log_Data_7[log01HighlightItem_i].Bailout_Start_PSI[i_u8];
                //BailoutEndPSI   = Log_Data_7[log01HighlightItem_i].Bailout_End_PSI[i_u8];
                //BailoutGasMin  = Log_Data_7[log01HighlightItem_i].Bailout_TankTimeMin[i_u8];
            }

            hmemDevlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
                                               ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                                               (320U - Pos_Item_Select_List->X0),\
                                               Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
            GUI_MEMDEV_Select(hmemDevlocal);
            GUI_SetBkColor(GUI_BLACK);
            GUI_ClearRect(Pos_Item_Select_List->X0,\
                          ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                          320U,\
                          ((i_u8)*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
            /**
            Display the CC mode
            Start pressure
            End pressure
            AVG SAC
            */
            /* Dive Mode and Tank Number of the LOG in display */
            GUI_SetTextAlign(GUI_TA_LEFT);
            if(Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDCC)
            {
                sprintf(pStrRet, "CC-%d", (i_u8));
                if( (Log_Data_7[log01HighlightItem_i].CC_GASTMT[(i_u8)] != TANK_OFF)
                        &&((Log_Data_7[log01HighlightItem_i].TMT_On_Bits.Allbits >> (Log_Data_7[log01HighlightItem_i].CC_GASTMT[(i_u8)] - 1)) & 0x01) )
                    TMT_On = true;
            }
            else if(Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDOC)
            {
                sprintf(pStrRet, "OC-%d", (i_u8));
                if( (Log_Data_7[log01HighlightItem_i].OC_GASTMT[(i_u8)] != TANK_OFF)
                        &&((Log_Data_7[log01HighlightItem_i].TMT_On_Bits.Allbits >> (Log_Data_7[log01HighlightItem_i].OC_GASTMT[(i_u8)] - 1)) & 0x01) )
                    TMT_On = true;
            }
            else if(Log_Data_7[log01HighlightItem_i].DiveType==NVD_MDSM)
            {
                if(i_u8 == TANK_1)
                    sprintf(pStrRet, "OC-L");
                else if(i_u8 == TANK_2)
                    sprintf(pStrRet, "OC-R");
                else
                    sprintf(pStrRet, "OC-%d", (i_u8));
                if( (Log_Data_7[log01HighlightItem_i].SM_GASTMT[(i_u8)] != TANK_OFF)
                        &&((Log_Data_7[log01HighlightItem_i].TMT_On_Bits.Allbits >> (Log_Data_7[log01HighlightItem_i].SM_GASTMT[(i_u8)] - 1)) & 0x01) )
                    TMT_On = true;
            }
            else
            {
                if(GAUGE_MODE)
                    sprintf(pStrRet, "TMT-%d", (i_u8));
                else
                {
                    if(i_u8 == TMT_1)
                        sprintf(pStrRet, "TMT-L");
                    else if(i_u8 == TMT_2)
                        sprintf(pStrRet, "TMT-R");
                    else
                        sprintf(pStrRet, "TMT-%d", (i_u8));
                    if((Log_Data_7[log01HighlightItem_i].TMT_On_Bits.Allbits >> (i_u8 - 1)) & 0x01)
                        TMT_On = true;
                }
            }

            if(TMT_On)
            {
                GUI_SetColor(GUI_WHITE);
                GUI_DispStringAt(pStrRet, Pos_Item_Select_List->X0, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
                /* START PSI of the Tank in display */
                GUI_SetTextAlign(GUI_TA_CENTER);
                if(StartPSI != 0)
                {
                    if(UNITS==NVD_IMPERIAL)
                        sprintf(pStrRet, "%d", StartPSI);
                    else
                        sprintf(pStrRet, "%.0f", CONST_PSI_TO_BAR*StartPSI);
                }
                else
                    strcpy(pStrRet, " --- ");
                GUI_DispStringAt(pStrRet, Point_LogMode02_StartPSI->x, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
                /* End PSI of the Tank in display */
                GUI_SetTextAlign(GUI_TA_CENTER);
                if(EndPSI != 0)
                {
                    if(UNITS==NVD_IMPERIAL)
                        sprintf(pStrRet, "%d", EndPSI);
                    else
                        sprintf(pStrRet, "%.0f", CONST_PSI_TO_BAR*EndPSI);
                }
                else
                    strcpy(pStrRet, " --- ");
                GUI_DispStringAt(pStrRet, Point_LogMode02_EndPSI->x, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
                /* AVG SAC of the Tank in display */
                GUI_SetTextAlign(GUI_TA_RIGHT);
                if( EndPSI > StartPSI )
                {
                    AvgConsumpRate = -1;  // show -1 for negative gas consumption
                }
                else if(GasMin==0)        // to avoid divid by 0, use 1 min for 0 min
                {
                    AvgConsumpRate = (StartPSI - EndPSI);
                }
                else
                {
                    AvgConsumpRate = (StartPSI - EndPSI)/GasMin;          // Use a Negative Sign because it is for GAS CONSUMPTION
                }
                if(AvgConsumpRate < 0)
                    sprintf(pStrRet, "%d", -1);         // show -1 for negative gas consumption
                else
                {
                    if(UNITS==NVD_IMPERIAL)
                        sprintf(pStrRet, "%d", AvgConsumpRate);
                    else
                        sprintf(pStrRet, "%.0f", (float)CONST_PSI_TO_BAR*AvgConsumpRate);
                }
                GUI_DispStringAt(pStrRet, Point_LogMode02_AvgSAC->x, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
                /*PSI/M (BAR/M)*/
                GUI_SetFont(&FontAaux_2);
                GUI_SetTextAlign(GUI_TA_LEFT);
                sprintf(pStrRet, "%s/%s", TxtDef_Set_PressUnit[UNITS], GUI_LANG_GetText(TxtStr_MIN));
                GUI_DispStringAt(pStrRet, Point_LogMode02_AvgSAC->x + 2u, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0 + 5u);
                GUI_SetFont(&FontAaux_3);
            }
            else
            {
                GUI_SetColor(GUI_CYAN);
                GUI_DispStringAt(pStrRet, Pos_Item_Select_List->X0, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
                /* Display OFF when TMT is not connected or not turned ON */
                GUI_SetTextAlign(GUI_TA_CENTER);
                strcpy(pStrRet, "OFF");
                GUI_DispStringAt(pStrRet, Point_LogMode02_StartPSI->x, ((i_u8)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            }
            GUI_MEMDEV_CopyToLCD(hmemDevlocal);
            GUI_MEMDEV_Delete(hmemDevlocal);
        }
    }
}
