/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
/*
* Parameters of compass display (CODIS)
*/
#define CODIS_NUMLINE_SCALE_VERTICAL	37
#define CODIS_VLINE_WHITE_Y0			Pos_Compass_MainGraphic->Y0 + 40
#define CODIS_VLINE_WHITE_Y1			Pos_Compass_MainGraphic->Y1 - 25
#define CODIS_VLINE_CYAN_Y0			    Pos_Compass_MainGraphic->Y0 + 35
#define CODIS_VLINE_CYAN_Y1			    Pos_Compass_MainGraphic->Y1 - 20
#define CODIS_VLINE_WHITE_WIDTH		    1
#define CODIS_VLINE_CYAN_SUB_WIDTH		2
#define CODIS_VLINE_CYAN_WIDTH			3
#define CODIS_SPACEBETWEENVLINE			(7U)    // (float)((Pos_Compass_MainGraphic->Width)/(float)(CODIS_NUMLINE_SCALE_VERTICAL-1)) = 245/(37-1) = 7U
#define CODIS_WHITECOLOR_SCALE			0x070707
#define CODIS_BLUECOLOR_SCALE			0x3030FF
/*Green rectangle in center*/
#define CODIS_GRRECT_X0                 160
#define CODIS_GRRECT_Y0                 112
#define CODIS_GRRECT_HEIGHT             36
#define CODIS_GRRECT_WIDTH              5

void CoDis_DisplayScaleVerticalLines(int _Value)
{
    uint16_t _i_u16;
    GUI_MEMDEV_Handle hmemCompass;
    hmemCompass = GUI_MEMDEV_Create(Pos_Compass_MainGraphic->X0, Pos_Compass_MainGraphic->Y0, Pos_Compass_MainGraphic->Width, Pos_Compass_MainGraphic->Height);
    GUI_MEMDEV_Select(hmemCompass);
    GUI_SetColor(GUI_BLACK);
    GUI_FillRect(Pos_Compass_MainGraphic->X0, Pos_Compass_MainGraphic->Y0, Pos_Compass_MainGraphic->X1, Pos_Compass_MainGraphic->Y1);
    /*Display the scale vertical line*/
    for(_i_u16=5; _i_u16 < 360; _i_u16+=5)
    {
        _Codis_Draw_VlineSub_White((_Value + _i_u16)%360);
    }
    /*
    Display the S/N/W/E head
    */
    /*NORTH*/
    _CoDis_Main_NavigateText(_Value, "N", &FontAaux_4);
    /*NORTH EAST*/
    _CoDis_Sub_NavigateText((_Value + 45)%360, "NW", &FontAaux_3);
    /*EAST*/
    _CoDis_Main_NavigateText((_Value + 90)%360, "W", &FontAaux_4);
    /*SOUTH WEST*/
    _CoDis_Sub_NavigateText((_Value + 135)%360, "SW", &FontAaux_3);
    /*SOUTH*/
    _CoDis_Main_NavigateText((_Value + 180)%360, "S", &FontAaux_4);
    /*SOUTH EAST*/
    _CoDis_Sub_NavigateText((_Value + 225)%360, "SE", &FontAaux_3);
    /*WEST*/
    _CoDis_Main_NavigateText((_Value + 270)%360, "E", &FontAaux_4);
    /*NORTH EAST*/
    _CoDis_Sub_NavigateText((_Value + 315)%360, "NE", &FontAaux_3);
    /*Draw the Green rectangle center*/
    GUI_SetColor(GUI_GREEN);
    GUI_DrawRect(CODIS_GRRECT_X0 - CODIS_GRRECT_WIDTH, CODIS_GRRECT_Y0, CODIS_GRRECT_X0 + CODIS_GRRECT_WIDTH, CODIS_GRRECT_Y0 + CODIS_GRRECT_HEIGHT);
    GUI_DrawLine(CODIS_GRRECT_X0, CODIS_GRRECT_Y0, CODIS_GRRECT_X0, CODIS_GRRECT_Y0 + CODIS_GRRECT_HEIGHT);
    /*Reference point*/
    CompassHandle_DisplayTheDotReferenceAndReverse(_Value);
    /*Copy memdev*/
    GUI_MEMDEV_CopyToLCD(hmemCompass);
    GUI_MEMDEV_Delete(hmemCompass);
}

/*Display the main Head text N/W/S/E*/
static void _CoDis_Main_NavigateText(int _Value, const char* _pHeadStr, const GUI_FONT* _TxtFontSize)
{
    //GUI_COLOR _CyanColorTranparent = GUI_CYAN;
    // if(0!=Pos_CompassMainArrayRotate[_Value].y)
    // {
    GUI_COLOR _SetColorReturn;
    GUI_SetPenSize(CODIS_VLINE_CYAN_WIDTH);
    GUI_SetFont(_TxtFontSize);
    /*Only when y value is differ 0 then continue processing, with 0 value then no need to display*/
    _SetColorReturn = _Codis_Draw_VlineMain_CYAN(_Value);
    GUI_SetColor(_SetColorReturn);
    GUI_DispStringHCenterAt(_pHeadStr, Pos_CompassMainArrayRotate[_Value].x, Pos_CompassMainArrayRotate[_Value].y);
    GUI_DrawLine(Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y0,Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y1);
    // }
    // else
    // {
    //     /*Do nothing*/
    // }
}
/*Display the sub Head text NW/WS/SE/NE*/
#define SUBHEADTEXTOFFSET		10U	/*Move the sub text NW/WS/SE/NE offset with Main head text*/
static void _CoDis_Sub_NavigateText(int _Value, const char* _pHeadStr, const GUI_FONT* _TxtFontSize)
{
    if(0!=Pos_CompassMainArrayRotate[_Value].y)
    {
        /*Only when y value is differ 0 then continue processing, with 0 value then no need to display*/
        GUI_COLOR _SetColorReturn = GUI_CYAN;
        GUI_SetPenSize(CODIS_VLINE_WHITE_WIDTH);
        GUI_SetFont(_TxtFontSize);
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*Draw the Vertical line then return extracly the color to display text*/
        _SetColorReturn = _Codis_Draw_VlineSub_CYAN(_Value);
        GUI_SetColor(_SetColorReturn);
        GUI_DispStringHCenterAt(_pHeadStr, Pos_CompassMainArrayRotate[_Value].x, SUBHEADTEXTOFFSET + Pos_CompassMainArrayRotate[_Value].y);
    }
    else
    {
        /*Do nothing*/
    }
}
/*
Return the color of Vertical Cyan Main line tranparent
Line weight is large
*/
#define CYAN_SCALE	1.5f	/*This value define the cyan level effect when moving the vertical line*/
static GUI_COLOR _Codis_Draw_VlineMain_CYAN(int _Value)
{
    GUI_COLOR _CyanColorTranparent = GUI_CYAN;
    //int _CyanColorScale;
    /*Set the width of line*/
    GUI_SetPenSize(CODIS_VLINE_CYAN_WIDTH);
    /*Set the cyan tranparent by calculate from center (160) absolute value with current display X*/
    // _CyanColorScale = (int)(CYAN_SCALE * ABS(Pos_CompassMainArrayRotate[_Value].x-(YSIZE_PHYS/2)));
    // _CyanColorTranparent = GUI_CYAN - (((uint32_t)(_CyanColorScale&0xFF)<<16)|((uint32_t)(_CyanColorScale&0xFF)<<8)|(uint32_t)0xFF);
    GUI_SetColor(_CyanColorTranparent);
    /*Draw the vertical scaled lines*/
    GUI_DrawLine(Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y0, Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y1);
    return _CyanColorTranparent;
}

/*
Return the color of Vertical Cyan sub line tranparent
Line weight is small
*/
static GUI_COLOR _Codis_Draw_VlineSub_CYAN(int _Value)
{
    GUI_COLOR _CyanColorTranparent = GUI_CYAN;
    //int _CyanColorScale;
    /*Set the width of line*/
    GUI_SetPenSize(CODIS_VLINE_CYAN_SUB_WIDTH);
    /*Set the cyan tranparent by calculate from center (160) absolute value with current display X*/
    // _CyanColorScale = (int)(CYAN_SCALE * ABS(Pos_CompassMainArrayRotate[_Value].x-(YSIZE_PHYS/2)));
    // _CyanColorTranparent = GUI_CYAN - (((uint32_t)(_CyanColorScale&0xFF)<<16)|((uint32_t)(_CyanColorScale&0xFF)<<8)|(uint32_t)0xFF);
    GUI_SetColor(_CyanColorTranparent);
    /*Draw the vertical scaled lines*/
    GUI_DrawLine(Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y0 + 5,Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_CYAN_Y1);
    return _CyanColorTranparent;
}
/*
Return the color of Vertical White
*/
static GUI_COLOR _Codis_Draw_VlineSub_White(int _Value)
{
    GUI_COLOR _WhiteColorTranparent = GUI_WHITE;
    //int _WhiteColorScale;
    /*Set the width of line*/
    GUI_SetPenSize(CODIS_VLINE_WHITE_WIDTH);
    /*Set the white tranparent by calculate from center (160) absolute value with current display X*/
    // _WhiteColorScale = (int)(CYAN_SCALE * ABS(Pos_CompassMainArrayRotate[_Value].x-(YSIZE_PHYS/2)));
    // _WhiteColorTranparent = GUI_WHITE - (((uint32_t)(_WhiteColorScale&0xFF)<<16)|((uint32_t)(_WhiteColorScale&0xFF)<<8)|(uint32_t)(_WhiteColorScale&0xFF));
    GUI_SetColor(_WhiteColorTranparent);
    /*Draw the vertical scaled lines*/
    GUI_DrawLine(Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_WHITE_Y0 + 5,Pos_CompassMainArrayRotate[_Value].x, CODIS_VLINE_WHITE_Y1);
    return _WhiteColorTranparent;
}
