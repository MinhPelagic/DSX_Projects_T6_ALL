
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

extern const GUI_COLOR Color_InfoTitleSetting[];

/*1. Clear or Initilal screen for  S14_SURFACE_ALT4 operation*/
void IniOrClrScrFunc_S14_SURFACE_ALT4(void)
{
    /*Clear all the screen*/
    ClearPortionToUpdateDiveMode();
    /*Surface Time*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_TitleText);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Colon);
    /*DESAT*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Desat_Value);
    /*Last Dive*/
    SurfaceMode_LastDiveHandle();
    /*FLY TIME*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Tittle);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_Fly_Time);
    /*Tissue bar*/
    HandleItem_SurfaceMode_Main_TISSUES();
    /*GF*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Display all the SURFACE's items*/
    /*PO2, 3rd Row L/R or no display when Violation*/
    Dive_CC_Handle_CheckDisplayMiddle();
    /*GF/N2*/
    SurfaceHandle_CheckDispASCBGnN2Bar();
}
void UpdOrFlasFunc_S14_SURFACE_ALT4(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Hour);
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_SurfTime_Min);
    HandleDisplayTextWithMemdev(IteStat_Flashing, SurfaceMode_SurfTime_Colon);
    /*Tissue bar*/
    HandleItem_SurfaceMode_Main_TISSUES();		// Added by YS on 2021/12/08
    /*Bluetooth*/
    SurfaceMode_BluetoothIcon(SystemStatus.BLE_status);
    /*Charging*/
    Display_Battery_Surface((void*) &pDataSurfBatt);
}

#define XSizeLCD                (240u)
#define YSizeLCD                (320u)
#define TissBar_TLMaxScale		(100u)		//Depend on the maximum value of input need to modify this base on spec
#define TissBar_Width 			(10u)		//Width of each column bar
#define TissBar_Space 			(5u)		//Space between 2 bars
#define TissLine_NumBar			(16u)		//Number of bar
#define TissLine_Width			(240u)		//This value can resize in need
#define TissLine_NumLines		(5u)		//The maximum horizontal lines -> In spec define 5 lines
#define TissLine_Space			(9u)		//Space between 2 horizontal line	

static void Draw_TissueSingleBar(uint8_t Position, uint8_t Value, GUI_COLOR colorSet)
{
    /*Set color base on the value*/
    GUI_SetColor(colorSet);
    /*Calculate the Vertical position base on value*/
    GUI_FillRect((((YSizeLCD - TissLine_Width)/2)+2)   + Position*(TissBar_Width + TissBar_Space),\
                 (int)(XSizeLCD - ((Value*((TissLine_NumLines-1)*TissLine_Space))/TissBar_TLMaxScale)),\
                 (int)((((YSizeLCD - TissLine_Width)/2)+2) + TissBar_Width + Position*(TissBar_Width + TissBar_Space)),\
                 XSizeLCD);
};
/*Set color of bar base on the value */
GUI_COLOR SetColorTissueBar(uint8_t barValue)
{
    GUI_COLOR RetColor = GUI_YELLOW;
    if(100u <= barValue)
    {
        RetColor = GUI_RED;
    }
    else if(70u >= barValue)
    {
        RetColor = GUI_GREEN;
    }
    else
    {
        /*value between 70 and 100 -> keep Yellow value*/
    }
    return RetColor;
}
/*Draw the graph bar for tissue*/
void HandleItem_SurfaceMode_Main_TISSUES(void)
{
    GUI_COLOR colorBarSet = GUI_GREEN;
    uint8_t BarValue_u8 = 0u;
    /*Set background to default*/
    GUI_SetBkColor(GUI_BLACK);
    /*TISSUES/SLOW/FAST TEXT*/
    const GUI_COLOR titleColor = SurfaceMode_SurfTime_TitleText_Color();
    GUI_SetColor(titleColor);
    SetFont_2;
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_TISSUES), Pos_SURF_Tissues->X, Pos_SURF_Tissues->Y);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextAlign(GUI_TA_RIGHT);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_SLOW),\
                     (YSizeLCD - TissLine_Width)/2u - 3u,\
                     (XSizeLCD - (2u*TissLine_Space) - 10u));
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_FAST),\
                     ((YSizeLCD - TissLine_Width)/2u + TissLine_Width) + 3u,\
                     (XSizeLCD - (2u*TissLine_Space) - 10u));
    /*Draw 5 horizontal lines*/
    GUI_SetColor(GUI_GRAY);
    for(uint8_t u8_i = 0; u8_i<TissLine_NumLines; u8_i++)
    {
        GUI_DrawHLine(XSizeLCD - (u8_i*TissLine_Space) - 1u,\
                      (YSizeLCD - TissLine_Width)/2u,\
                      (YSizeLCD - TissLine_Width)/2u + TissLine_Width);
    }
    /*Draw bar graph*/
    for(uint8_t u8_i = 0u; u8_i<TissLine_NumBar; u8_i++)
    {
        /*get the value*/
        BarValue_u8 = (uint8_t)TLBG_ARRAY[TissLine_NumBar-u8_i-1];
        /*base on the value set color of each bar*/
        colorBarSet =  SetColorTissueBar(BarValue_u8);
        Draw_TissueSingleBar(u8_i, BarValue_u8, colorBarSet);
    }
}
