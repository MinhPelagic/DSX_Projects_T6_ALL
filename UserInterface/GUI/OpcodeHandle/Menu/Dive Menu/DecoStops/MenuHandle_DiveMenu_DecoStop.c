/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveMenu_DecoStops.h"
void DecoStopHandle_TittleOfList(void)
{
    char pStrRet[100];
    GUI_MEMDEV_Handle hmemlocal;
    /*DEPTH(FT/M)         STOP TIME       GAS*/
    hmemlocal = GUI_MEMDEV_CreateEx(Pos_DiveMenu_DecoStop_List->X0,\
                                    Pos_DiveMenu_DecoStop_List->Y0,\
                                    Pos_DiveMenu_DecoStop_List->Width,\
                                    Pos_DiveMenu_DecoStop_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemlocal);
    GUI_ClearRect(Pos_DiveMenu_DecoStop_List->X0,\
                  Pos_DiveMenu_DecoStop_List->Y0,\
                  Pos_DiveMenu_DecoStop_List->X1,\
                  Pos_DiveMenu_DecoStop_List->Y1);
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetTextAlign(GUI_TA_CENTER);
    /*DEPTH (FT/M)*/
    sprintf(pStrRet, "%s (%s)", GUI_LANG_GetText(TxtStr_DEPTH_Abb), TxtDef_Set_DepthUnit[UNITS]);
    GUI_DispStringAt(pStrRet, Point_DiveMenu_DecoStopList_StopDepth->x, Point_DiveMenu_DecoStopList_StopDepth->y);
    /*STOP TIME*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_STOP_TIME), Point_DiveMenu_DecoStopList_StopTime->x, Point_DiveMenu_DecoStopList_StopTime->y);
    /*GAS*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_GAS), Point_DiveMenu_DecoStopList_Gas->x, Point_DiveMenu_DecoStopList_Gas->y);
    /*Memdev copy*/
    GUI_MEMDEV_CopyToLCD(hmemlocal);
    GUI_MEMDEV_Delete(hmemlocal);
}
/*Display the list from start to end -> when data is 0 -> Dislay nothing*/
void DecoStopHandle_ContentList(unsigned char startRec)
{
    char pStrRet[100];
    /*FT * 0.3 = Metric*/
    for(uint8_t cnt_u8 = 1U; cnt_u8 <= DECOSTOP_MAX_ITEMS_INPAGE; cnt_u8++)
    {
        GUI_MEMDEV_Handle hmemlocal;
        uint8_t currRec = cnt_u8 + startRec - 1U; //Current deco item number
        /*DEPTH(FT/M)         STOP TIME       GAS*/
        hmemlocal = GUI_MEMDEV_CreateEx(Pos_DiveMenu_DecoStop_List->X0,\
                                        (cnt_u8 * Pos_DiveMenu_DecoStop_List->Height) + Pos_DiveMenu_DecoStop_List->Y0, \
                                        Pos_DiveMenu_DecoStop_List->Width,\
                                        Pos_DiveMenu_DecoStop_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemlocal);
        GUI_ClearRect(Pos_DiveMenu_DecoStop_List->X0, \
                      (cnt_u8  * Pos_DiveMenu_DecoStop_List->Height) + Pos_DiveMenu_DecoStop_List->Y0, \
                      Pos_DiveMenu_DecoStop_List->X1, \
                      (cnt_u8  * Pos_DiveMenu_DecoStop_List->Height) + Pos_DiveMenu_DecoStop_List->Y1);
        /*Validate the data*/
        if(0U==DecoStop[currRec]) /*When Deco Stop item is 0 then stop display*/
        {
            /*Do nothing*/
        }
        else
        {
            SetFont_3;
            GUI_SetColor(GUI_WHITE);
            GUI_SetTextAlign(GUI_TA_CENTER);
            /*DEPTH (FT/M)*/
            if(UNITS==NVD_IMPERIAL)
            {
                sprintf(pStrRet, "%d", DecoStop[currRec]);
            }
            else
            {
                sprintf(pStrRet, "%.0f", (float)DecoStop[currRec] * 0.3f);
            }
            GUI_DispStringAt(pStrRet, Point_DiveMenu_DecoStopList_StopDepth->x, cnt_u8  * Pos_DiveMenu_DecoStop_List->Height + Point_DiveMenu_DecoStopList_StopDepth->y);
            /*STOP TIME*/
            GUI_SetTextAlign(GUI_TA_CENTER);
            if(currRec == 1)
                sprintf(pStrRet, "%d", Total_DST);
            else
                sprintf(pStrRet, "%d", DecoTime[currRec]);
            GUI_DispStringAt(pStrRet, Point_DiveMenu_DecoStopList_StopTime->x, cnt_u8  * Pos_DiveMenu_DecoStop_List->Height + Point_DiveMenu_DecoStopList_StopTime->y);
            /*GAS*/
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, "%d/%d", DecoFO2[currRec], DecoFHe[currRec]);
            GUI_DispStringAt(pStrRet, Point_DiveMenu_DecoStopList_Gas->x, cnt_u8  * Pos_DiveMenu_DecoStop_List->Height + Point_DiveMenu_DecoStopList_Gas->y);
        }
        /*Memdev copy*/
        GUI_MEMDEV_CopyToLCD(hmemlocal);
        GUI_MEMDEV_Delete(hmemlocal);
    }
}
unsigned char DecoStop_CheckNoDecoStatus(void)
{
    unsigned char retStat = true; //
    /*NO DECO*/
    if(0U==DecoStop[DECOSTOP_START_RECORD])
    {
        /*Do nothing*/
    }
    else  /*Display the list*/
    {
        retStat = false;
    }
    return retStat;
}
void DecoStopHandle_InitialCheckDecoDisplay(void)
{
    /*If the Deco depth 1 is 0 then -> NO DECO*/
    if(DecoStop_CheckNoDecoStatus())
    {
        GUI_ClearRect(Pos_DiveMenu_DecoStop_PO2_Value->X0, Pos_DiveMenu_DecoStop_PO2_Value->Y1, Pos_BottomContent->X1, Pos_BottomContent->Y0);
        /*Display No Deco*/
        HandleDisplayTextWithMemdev(IteStat_Select, DecoStop_NODECO);
        Display_Icon_Buttons(IconBottDisp_BackHome);
    }
    else
    {
        DecoStop_StartRec_u8 = DECOSTOP_START_RECORD;
        /*Display the list tittle*/
        DecoStopHandle_TittleOfList();
        /*Content*/
        DecoStopHandle_ContentList(DecoStop_StartRec_u8);
        Display_Icon_Buttons(IconBottDisp_BackHomeNext);
    }
}
