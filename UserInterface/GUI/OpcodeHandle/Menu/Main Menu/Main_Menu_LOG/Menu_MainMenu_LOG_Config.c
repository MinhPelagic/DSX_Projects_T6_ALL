/******************************************************************************/
//File: LOG
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"

/*!DisplayText_TopBar_Title*/
void DisplayText_TopBar_LOGTittle(const char* String)
{
    GUI_MEMDEV_Handle hmemDevlocal;
    hmemDevlocal = GUI_MEMDEV_CreateEx(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->Width, Pos_TopTitle->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemDevlocal);
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    /*Display the text content*/
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(String, Pos_TopTitle->X0 + 10, Pos_TopTitle->Y0);
    GUI_MEMDEV_CopyToLCD(hmemDevlocal);
    GUI_MEMDEV_Delete(hmemDevlocal);
};
/*Validate the log is empty or not*/
bool LogMenu_CheckLogIsEmpty(void)
{
    bool retStat = false;
    if(DEV_Rec.LogNumRecorded!=0)
    {
        /*do nothing*/
    }
    else
    {
        /*log is empty*/
        retStat = true;
    }
    return retStat;
}
/**
 * @brief Text No Dive Yet
 *
 * @param pStrRet
 */
static void LOG_NoDiveYet_Context_01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NoDiveYet_1));
}
static const contentDispContext_st LOG_NoDiveYet_1 =
{
    &LOG_NoDiveYet_Context_01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_0, /*Reuse*/
};
static void LOG_NoDiveYet_Context_02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NoDiveYet_2));
}
static const contentDispContext_st LOG_NoDiveYet_2 =
{
    &LOG_NoDiveYet_Context_02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_1, /*Reuse*/
};
static void LOG_NoDiveYet_Context_03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NoDiveYet_3));
}
static const contentDispContext_st LOG_NoDiveYet_3 =
{
    &LOG_NoDiveYet_Context_03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_ErrorMsg_Line_2, /*Reuse*/
};
/**
 * @brief LOG Display NO DIVE YET
 *
 */
void LogMenu_DisplayNODIVEYET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, LOG_NoDiveYet_1);
    HandleDisplayTextWithMemdev(IteStat_Select, LOG_NoDiveYet_2);
    HandleDisplayTextWithMemdev(IteStat_Select, LOG_NoDiveYet_3);
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
