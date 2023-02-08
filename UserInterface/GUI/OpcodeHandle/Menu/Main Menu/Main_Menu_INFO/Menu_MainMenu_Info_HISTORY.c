/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"
static void DSX_HISTORY_TotalDives(char* pStrRet);
static void DSX_HISTORY_TotalDiveHours(char* pStrRet);
static void DSX_HISTORY_MaxDiveTime(char* pStrRet);
static void DSX_HISTORY_MaxDepth(char* pStrRet);
static void DSX_HISTORY_AvgDepth(char* pStrRet);
static void DSX_HISTORY_LowestTemp(char* pStrRet);
static void DSX_HISTORY_MaxElevation(char* pStrRet);

enum HistoryInfo_e
{
    HistoryInfo_TOTALDIVES			= 0x00,
    HistoryInfo_TOTALDIVESHOURS,
    HistoryInfo_MAXDIVETIME,
    HistoryInfo_MAXDEPTH,
    HistoryInfo_AVGDEPTH,
    HistoryInfo_LOWESTTEMP,
    HistoryInfo_MAXELEVATION,
    HistoryInfo_MAX

};
static const TxtStr_Name_e TxtDef_HistoryInfo[HistoryInfo_MAX]=
{
    TxtStr_TOTAL_DIVES,
    TxtStr_HISTORY_TOTAL_DIVE_HOURS,
    TxtStr_HISTORY_MAX_DIVE_TIME,
    TxtStr_HISTORY_MAX_DEPTH,
    TxtStr_HISTORY_AVG_DEPTH,
    TxtStr_HISTORY_LOWEST_TEMP,
    TxtStr_HISTORY_MAX_ELEVATION,
};
static const pstrHandle_Func pFunHandleDSXHistoryRight[HistoryInfo_MAX]=
{
    DSX_HISTORY_TotalDives,
    DSX_HISTORY_TotalDiveHours,
    DSX_HISTORY_MaxDiveTime,
    DSX_HISTORY_MaxDepth,
    DSX_HISTORY_AvgDepth,
    DSX_HISTORY_LowestTemp,
    DSX_HISTORY_MaxElevation,
};
void IniOrClrScrFunc_S192_IM_HISTORY_SET(void)
{
    char strLocal[LangMaxLength];
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_HISTORY));
    if(LogMenu_CheckLogIsEmpty())
    {
        /*No dive yet*/
        ClearUnusedInList(0);
        LogMenu_DisplayNODIVEYET();
    }
    else
    {
        GUI_MEMDEV_Handle hMemLocal;
        SetFont_3;
        for(uint8_t i_u8 = 0; i_u8 < HistoryInfo_MAX; i_u8++)
        {
            hMemLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
            GUI_MEMDEV_Select(hMemLocal);
            GUI_ClearRect(Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (i_u8*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
            GUI_SetTextAlign(GUI_TA_LEFT);
            GUI_SetColor(TxtColor_UnSelect);
            /*Dipsplay History infor*/
            GUI_DispStringAt(GUI_LANG_GetText(TxtDef_HistoryInfo[i_u8]), Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            GUI_SetTextAlign(GUI_TA_CENTER);
            GUI_DispStringAt(":", Pos_Item_Select_List->X, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            GUI_SetColor(TxtColor_Select);
            GUI_SetTextAlign(GUI_TA_RIGHT);
            pFunHandleDSXHistoryRight[i_u8](strLocal);
            GUI_DispStringAt(strLocal, Pos_Item_Select_List->X1, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            GUI_MEMDEV_CopyToLCD(hMemLocal);
            GUI_MEMDEV_Delete(hMemLocal);
        }
    }
}
/*Data display handle*/
static void DSX_HISTORY_TotalDives(char* pStrRet)
{
    sprintf(pStrRet, "%d", DEV_Rec.LogNumRecorded);
}
static void DSX_HISTORY_TotalDiveHours(char* pStrRet)
{
    sprintf(pStrRet, "%d HR", (DEV_Rec.TotalDiveTimeSec/3600));
}
static void DSX_HISTORY_MaxDiveTime(char* pStrRet)
{
    sprintf(pStrRet, "%d MIN", (DEV_Rec.MaxDiveTimeSec/60));
}
static void DSX_HISTORY_MaxDepth(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", ((float)DEV_Rec.DevMaxDepthFt10/10.0));
    else
        sprintf(pStrRet, "%.0f M", CONST_FT_TO_M*DEV_Rec.DevMaxDepthFt10/10.0);
}
static void DSX_HISTORY_AvgDepth(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f FT", ((float)DEV_Rec.DevAvgDepthFt));
    else
        sprintf(pStrRet, "%.0f M", CONST_FT_TO_M*DEV_Rec.DevAvgDepthFt);
}
static void DSX_HISTORY_LowestTemp(char* pStrRet)
{
    if(UNITS==NVD_IMPERIAL)
        sprintf(pStrRet, "%.0f F", ((float)DEV_Rec.DevLowestTempF10/10.0));
    else
        sprintf(pStrRet, "%.0f C", 5.0*((DEV_Rec.DevLowestTempF10/10)-32)/9.0);
}
static void DSX_HISTORY_MaxElevation(char* pStrRet)
{
    if(0U==DEV_Rec.Max_Elev)
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SEA));
    }
    else
    {
        sprintf(pStrRet, "ELEV %d", (uint8_t)DEV_Rec.Max_Elev);
    }
}