/******************************************************************************/
//File: LOG 1
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"

extern unsigned int Pre_log01CountNum_i;
unsigned char maxDispPage01 = 0;
/**/
static void listInitPageLOG_01(unsigned char maxItemInpage)
{
    /**/
    log01DatLeft_ts dataLog01 = {0}; //Individual item content
    /*Display all the items*/
    for(unsigned char i_u8 = 0; i_u8 < maxItemInpage; i_u8++)
    {
        /*Display pos*/
        dataLog01.currPosDisp = i_u8;
        /*Status base on Page Index*/
        if(i_u8 == log01HighlightItem_i)
        {
            dataLog01.currStat = IteStat_Select;
        }
        else
        {
            dataLog01.currStat = IteStat_UnSelect;
        }
        /*Data input*/
        dataLog01.logData = Log_Data_7[i_u8];
        /*Display the LOG item*/
        MainMenuLOG_1_LefSideItemInList(dataLog01);
    }
}
void IniOrClrScrFunc_S28_LOG_DATA1(void)
{
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
        Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
        /**
        Display the LOG title
        ---------------------------------------------------
        */
        HandleDisplayTextWithMemdev(IteStat_Select, MenuLog_01_Titlte);
        /**
        Display the LOG item in list
        1. The number of Log
        2. The Dive num
        3. The day value
        ---------------------------------------------------
        */
        /**
        1. Draw the line below the title
        2. Vertical line to sepearted content
        */
        GUI_SetPenSize(PenSizeLine_SURFnDIVE);
        GUI_DrawHLine(Pos_LogData01_Title->Y1 - 1, Pos_LogData01_Title->X0 + 10, Pos_LogData01_Title->X1 - 10);
        GUI_DrawVLine(Pos_LogData01_RightContent->X0 - 1, Pos_LogData01_RightContent->Y0, (LogData01_Right_MAX_e * Pos_LogData01_RightContent->Height)+Pos_LogData01_RightContent->Y0);
        /*Calculate the max display in Page LOG 1*/
        /*Check the Maximum display in page*/
        if(GUI_LOG_NumLast<=MAX_ITEM_DISP_PAGE_LOG_01)
        {
            maxDispPage01 = GUI_LOG_NumLast;
        }
        else
        {
            maxDispPage01 = MAX_ITEM_DISP_PAGE_LOG_01;
        }
        /*Init the content of page*/
        listInitPageLOG_01(maxDispPage01);
        /**
        *Display the value of each log on the right
        *1. Mode
        *2. Max depth
        *3. Dive time
        *4. AV Depth
        *5. Low Temperature
        */
        MainMenuLOG_1_RightSideContent(log01HighlightItem_i);//Replace 0 by input of current LOG number be selected
    }
}
void UpdOrFlasFunc_S28_LOG_DATA1(void)
{
    /*When empty list no progress*/
    if(LogMenu_CheckLogIsEmpty())
    {
        /*Do nothing*/
    }
    else
    {
        if(log01CountNum_i != Pre_log01CountNum_i)
        {
            MainMenuLOG_1_RightSideContent(log01HighlightItem_i);//Replace 0 by input of current LOG number be selected
            Pre_log01CountNum_i = log01CountNum_i;
        }
        listInitPageLOG_01(maxDispPage01);
    }
}
