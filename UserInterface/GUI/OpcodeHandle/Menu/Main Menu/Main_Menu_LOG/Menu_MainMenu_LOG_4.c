/******************************************************************************/
//File: LOG 4
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"

extern const GUI_COLOR Color_InfoTitleSetting[ColorTitle_MAX];
#define Log04_LCD_XSIZE                         320
#define Log04_LCD_YSIZE                         240
#define Log04_Offset_FASTSLOW                   10         //Offset from left/right to FAST/SLOW text
#define Log04_TissBar_Value(X)			        in_buf[X+48]	//Base on the spec then capture the buffer data
#define Log04_TissBar_TLMaxScale		        100		//Depend on the maximum value of input need to modify this base on spec
#define Log04_TissLine_NumBar			        16		//Number of bar
#define Log04_TissLine_H_OffsetLeft	            40      //Offset from Left with horizonal line
#define Log04_TissLine_H_OffsetRight	        20      //Offset from Right with horizonal line
#define Log04_TissLine_H_Width	                Log04_LCD_XSIZE - Log04_TissLine_H_OffsetLeft - Log04_TissLine_H_OffsetRight
#define Log04_TissLine_NumLines			        11		//The maximum horizontal lines -> In spec define 5 lines
#define Log04_TissLine_Space			        12		//Space between 2 horizontal line
#define Log04_TissLine_Bottom			        Pos_SURF_Tissues->Y0 - 3	//Bottom line of graph
#define Log04_TissBar_Width 			        10		//Width of each column bar
#define Log04_TissBar_Space 			        6		//Space between 2 bars
#define Log04_TissBar_X_1stBar	                (Log04_TissLine_H_OffsetLeft + 5) //X0 of 1st bar
#define Log04_TissBar_X0_V_Bar                  (int)(Log04_TissBar_X_1stBar + Position*(Log04_TissBar_Width + Log04_TissBar_Space)) //Position X of Vertical bar	                
#define Log04_TissBar_X1_V_Bar                  (int)(Log04_TissBar_X0_V_Bar + Log04_TissBar_Width) //Position X of Vertical bar                
#define Log04_TissBar_Y0_V_Bar                  (int)(Log04_TissLine_Bottom - ((Value*((Log04_TissLine_NumLines-1)*Log04_TissLine_Space))/Log04_TissBar_TLMaxScale)) //Position Y0 of Vertical bar	                

void Log04_Draw_TissueSingleBar(uint8_t Position, uint8_t Value)
{
    GUI_COLOR colorSet = GUI_GREEN;
    /*Set color base on the value*/
    colorSet = SetColorTissueBar(Value);
    GUI_SetColor(colorSet);
    /*Calculate the Vertical position base on value*/
    GUI_FillRect(Log04_TissBar_X0_V_Bar,
                 Log04_TissBar_Y0_V_Bar,\
                 Log04_TissBar_X1_V_Bar,\
                 Log04_TissLine_Bottom);
};
void IniOrClrScrFunc_S39_LOG_DATA4(void)
{
    char pStrRet[LangMaxLength];
    /**/
    GUI_Clear();
    /*When empty list no progress*/
    if(LogMenu_CheckLogIsEmpty())
    {
        /*No Dive Yet*/
        LogMenu_DisplayNODIVEYET();
    }
    else
    {
        DisplayTimeOfLOGatTOP();
        /*Draw 10 horizontal lines*/
        GUI_SetColor(GUI_GRAY);
        for(uint8_t u8_i = 0; u8_i<Log04_TissLine_NumLines; u8_i++)
        {
            GUI_DrawHLine(Log04_TissLine_Bottom - (u8_i*Log04_TissLine_Space),\
                          Log04_TissLine_H_OffsetLeft,\
                          Log04_LCD_XSIZE - Log04_TissLine_H_OffsetRight);
        }
        /*Draw bar graph*/
        for(uint8_t u8_i = 0; u8_i<Log04_TissLine_NumBar; u8_i++)
        {
            Log04_Draw_TissueSingleBar(u8_i, Log_Data_7[log01HighlightItem_i].TLBGS[u8_i]);
        }
        /*TISSUES/SLOW/FAST TEXT*/
        GUI_SetColor(Color_InfoTitleSetting[ColorTitle_Value]);
        SetFont_3;
        GUI_SetColor(GUI_WHITE);
        sprintf(pStrRet,GUI_LANG_GetText(TxtStr_TISSUE_SATURATIONS));
        //GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_TISSUES), Pos_SURF_Tissues->X, Pos_SURF_Tissues->Y);
        GUI_DispStringHCenterAt(pStrRet, Pos_SURF_Tissues->X, Pos_SURF_Tissues->Y);
        SetFont_2;
        //GUI_SetTextAlign(GUI_TA_RIGHT);
        for(uint8_t i=1; i<=5; i++)
        {
            sprintf(pStrRet, "%d", i*20);
            GUI_DispStringAt(pStrRet, Log04_Offset_FASTSLOW, (Pos_SURF_Tissues->Y - 12 - i*2*Log04_TissLine_Space));
        }
        GUI_SetTextAlign(GUI_TA_LEFT);
        GUI_DispStringAt(GUI_LANG_GetText(TxtStr_SLOW), Log04_Offset_FASTSLOW, Pos_SURF_Tissues->Y);
        GUI_SetTextAlign(GUI_TA_RIGHT);
        GUI_DispStringAt(GUI_LANG_GetText(TxtStr_FAST), Log04_LCD_XSIZE - Log04_Offset_FASTSLOW, Pos_SURF_Tissues->Y);
        /*Bottom bar*/
        Display_Icon_Buttons(IconBottDisp_BackHomeNext);
    }
}
