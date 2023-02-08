/*-----------------TEXT DSX HANDLER---------------*/

#include "L4X9_includes.h"
#include "OpcodeHandle\Dive Mode\DiveMode.h"

extern GUI_CONST_STORAGE GUI_BITMAP bmCompass_Circle;
extern DataLOG_ts LOG_Record[];
//extern uint8_t Log_Data[][];
extern uint8_t InclinedCompassFlag;// a flag to disable compass, while incline angle causes up-side-down
extern const char LangStr_EngLish[];
extern const char LangStr_Italian[];
extern const char LangStr_French[];
extern const char LangStr_German[];
extern const char LangStr_Espanol[];
extern const char LangStr_Portugese[];
extern const char LangStr_Czech[];
extern const char LangStr_Polish[];
extern const char LangStr_ChineseSimplified[];
extern const char LangStr_ChineseTraditional[];
extern const GUI_COLOR Color_InfoTitleSetting[];

uint16_t Compass_ref;
uint8_t DisplayFlipping;         // stat of Display flipping or Not flipping, needs to be controlled by compass sensor
PLAN_Data_ts PLAN_Record[18];
uint8_t FlashingState_u8 = FLASHING_STATE_ON;
GUI_FONT FontAaux_1;
GUI_FONT FontAaux_2;
GUI_FONT FontAaux_3;
GUI_FONT FontAaux_4;
GUI_FONT FontAaux_5;
GUI_FONT FontAaux_6;
GUI_FONT FontAaux_7;
GUI_FONT FontAaux_8;

/*Private prototype*/
GUI_MEMDEV_Handle hMemDev_DisplayNum;
const TxtStr_Name_e TxtDef_DSX_MainMode[DIVEMODE_MAX]=
{
    TxtStr_CC,
    TxtStr_OC,
    TxtStr_SM,
    TxtStr_GAUGE_SM,
    TxtStr_GAUGE,
    TxtStr_BO,
};
const TxtStr_Name_e TxtDef_OnOffSet_Context[Setting_MAX] =
{
    TxtStr_OFF,
    TxtStr_ON,
    TxtStr_SET,
};
const TxtStr_Name_e TxtDef_YesNo_Context[SettYesNo_MAX] =
{
    TxtStr_NO,
    TxtStr_YES,
};
const char* TxtDef_Set_DepthStr[SetUnit_MAX]=
{
    "%d FT",
    "%d M",
};
const char* TxtDef_Set_DepthUnit[SetUnit_MAX]=
{
    "FT",
    "M",
};
/*
Small text
    ˦ : FT
    ˥ : M
*/
const char* TxtDef_Set_LowerDepthUnit[SetUnit_MAX]=
{
    "˦",
    "˥",
};
const char* TxtDef_Set_ExLDepthTimeLowerDepthUnit[SetUnit_MAX]=
{
    "ˢ",// FT
    "ˡ",// M
};
const char* TxtDef_Set_TemperatureUnit[SetUnit_MAX]=
{
    "˨", // °F
    "˩", // °C
};
const char* TxtDef_Set_PressActiveUnit[SetUnit_MAX]=
{
    "PSI",
    "mBar",
};
const char* TxtDef_Set_PressUnit[SetUnit_MAX]=
{
    "PSI",
    "BAR",
};
/*DIVE SIMULATOR context*/
/*--------------------------------------------------*/
/*Lines define*/
const GUI_POINT	Hor_Line_1[2]=
{   //Under the Surface time
    {0,0},
    {+290,0},
};

const GUI_POINT aPointArrow_2[] =
{
    {0, 30},
    {+(152), 30},
    {+(152+8), 22},
    {+(152+8), 0},
};
const GUI_POINT CompassMainPoint[]= {
    {160,140},{159,140},{158,140},{158,140},{157,140},{156,140},{155,140},{154,140},{154,140},{153,140},{152,140},{151,140},{150,141},{150,141},{149,141},{148,141},{147,141},{146,141},{146,141},{145,141},{144,141},{143,142},{142,142},{142,142},{141,142},{140,142},{139,142},{138,143},{138,143},{137,143},{136,143},{135,144},{134,144},{134,144},{133,144},{132,145},{131,145},{130,145},{130,145},{129,146},{128,146},{127,146},{126,147},{126,147},{125,147},{124,148},{123,148},{122,149},{122,149},{121,149},{120,150},{119,150},{118,151},{118,151},{117,152},{116,152},{115,153},{114,153},{114,154},{113,154},{112,155},{111,155},{110,156},{110,157},{109,157},{108,158},{107,159},{106,159},{106,160},{105,161},{104,162},{103,162},{102,163},{102,164},{101,165},{100,166},{99,167},{98,168},{98,169},{97,170},{96,171},{95,172},{94,174},{94,175},{93,177},{92,178},{91,180},{90,182},{90,184},{89,187},{90,189},{90,191},{91,193},{92,195},{93,197},{94,199},{94,201},{95,203},{96,205},{97,207},{98,209},{98,211},{99,300},{100,300},{101,300},{102,300},{102,300},{103,300},{104,300},{105,300},{106,300},{106,300},{107,300},{108,300},{109,300},{110,300},{110,300},{111,300},{112,300},{113,300},{114,300},{114,300},{115,300},{116,300},{117,300},{118,300},{118,300},{119,300},{120,300},{121,300},{122,300},{122,300},{123,300},{124,300},{125,300},{126,300},{126,300},{127,300},{128,300},{129,300},{130,300},{130,300},{131,300},{132,300},{133,300},{134,300},{134,300},{135,300},{136,300},{137,300},{138,300},{138,300},{139,300},{140,300},{141,300},{142,300},{142,300},{143,300},{144,300},{145,300},{146,300},{146,300},{147,300},{148,300},{149,300},{150,300},{150,300},{151,300},{152,300},{153,300},{154,300},{154,300},{155,300},{156,300},{157,300},{158,300},{158,300},{159,300},{160,300},{161,300},{162,300},{162,300},{163,300},{164,300},{165,300},{166,300},{166,300},{167,300},{168,300},{169,300},{170,300},{170,300},{171,300},{172,300},{173,300},{174,300},{174,300},{175,300},{176,300},{177,300},{178,300},{178,300},{179,300},{180,300},{181,300},{182,300},{182,300},{183,300},{184,300},{185,300},{186,300},{186,300},{187,300},{188,300},{189,300},{190,300},{190,300},{191,300},{192,300},{193,300},{194,300},{194,300},{195,300},{196,300},{197,300},{198,300},{198,300},{199,300},{200,300},{201,300},{202,300},{202,300},{203,300},{204,300},{205,300},{206,300},{206,300},{207,300},{208,300},{209,300},{210,300},{210,300},{211,300},{212,300},{213,300},{214,300},{214,300},{215,300},{216,300},{217,300},{218,300},{218,300},{219,300},{220,300},{221,300},{222,300},{222,300},{223,300},{224,300},{225,300},{226,210},{226,208},{227,206},{228,204},{229,202},{230,200},{230,198},{231,196},{232,194},{233,192},{232,190},{231,187},{230,184},{230,182},{229,180},{228,178},{227,177},{226,175},{226,174},{225,172},{224,171},{223,170},{222,169},{222,168},{221,167},{220,166},{219,165},{218,164},{218,163},{217,162},{216,162},{215,161},{214,160},{214,159},{213,159},{212,158},{211,157},{210,157},{210,156},{209,155},{208,155},{207,154},{206,154},{206,153},{205,153},{204,152},{203,152},{202,151},{202,151},{201,150},{200,150},{199,149},{198,149},{198,149},{197,148},{196,148},{195,147},{194,147},{194,147},{193,146},{192,146},{191,146},{190,145},{190,145},{189,145},{188,145},{187,144},{186,144},{186,144},{185,144},{184,143},{183,143},{182,143},{182,143},{181,142},{180,142},{179,142},{178,142},{178,142},{177,142},{176,141},{175,141},{174,141},{174,141},{173,141},{172,141},{171,141},{170,141},{170,141},{169,140},{168,140},{167,140},{166,140},{166,140},{165,140},{164,140},{163,140},{162,140},{162,140},{161,140},
};

const menuItemContext_ts Context_MENU_EMPTY=
{
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_DISPLAY,
    ContextEmpty,
    DISABLE_COLOR_HANDLE,
    &ReturnFalse,
    {0u,0u,0u,0u,0u},
};
/*********************************************************************
*
*       Language texts
*
************DISABLE_DISPLAY**********************************************************
*/
#include "./LangTextString/StringText_ChineseSimp.c"
#include "./LangTextString/StringText_ChineseTrad.c"
#include "./LangTextString/StringText_Czech.c"
#include "./LangTextString/StringText_English.c"
#include "./LangTextString/StringText_Espanol.c"
#include "./LangTextString/StringText_French.c"
#include "./LangTextString/StringText_German.c"
#include "./LangTextString/StringText_Italiano.c"
#include "./LangTextString/StringText_Korean.c"
#include "./LangTextString/StringText_Polish.c"
#include "./LangTextString/StringText_Portugese.c"
#include "./LangTextString/StringText_Russian.c"

STRING_LANG StrLang_Select[MAX_LANGUAGE]=
{
    {LangStr_EngLish, sizeof(LangStr_EngLish)},
    {LangStr_German, sizeof(LangStr_German)},
    {LangStr_French, sizeof(LangStr_French)},
    {LangStr_Italian, sizeof(LangStr_Italian)},
    {LangStr_Espanol, sizeof(LangStr_Espanol)},
    {LangStr_Portugese, sizeof(LangStr_Portugese)},
    {LangStr_Polish, sizeof(LangStr_Polish)},
    {LangStr_Russian, sizeof(LangStr_Russian)},
    {LangStr_Czech, sizeof(LangStr_Czech)},
    {LangStr_ChineseSimplified, sizeof(LangStr_ChineseSimplified)},
    {LangStr_ChineseTraditional, sizeof(LangStr_ChineseTraditional)},
    {LangStr_Korean, sizeof(LangStr_Korean)},
};

uint8_t Language_Present = STRING_LANG_ENGLISH;
/*-----------------------------End The coordinate Home Navigation--------------------------------- */
/*Variable text content*/
GUI_COLOR DiveMode_Color_Compass	 	= GUI_GREEN;

/*Priviate prototype*/

/*!DisplayText_TopBar_Title*/
void DisplayText_TopBar_Title(const char* String)
{
    GUI_MEMDEV_Handle hmemLocal;
    hmemLocal = GUI_MEMDEV_CreateEx(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->Width, Pos_TopTitle->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemLocal);
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    /*Display the text content*/
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringHCenterAt(String, Pos_TopTitle->X, Pos_TopTitle->Y0);
    /*Draw the line in the bottom text*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(1);
    GUI_DrawPolyLine(&Hor_Line_1[0], 2, Pos_Item_Select_List->X0, Pos_TopTitle->Y1-1);
    GUI_MEMDEV_CopyToLCD(hmemLocal);
    GUI_MEMDEV_Delete(hmemLocal);
};
/*Display the setting text below the top title*/
void DisplayText_Setting_Title(const char* String)
{
    GUI_MEMDEV_Handle hmemLocal;
    hmemLocal = GUI_MEMDEV_CreateEx(Pos_Setting_Title_Line_0->X0, Pos_Setting_Title_Line_0->Y0, Pos_Setting_Title_Line_0->Width, Pos_Setting_Title_Line_0->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemLocal);
    /*Display the text content*/
    SetFont_5;
    GUI_SetColor(GUI_CYAN);
    GUI_SetBkColor(GUI_BLACK);
    GUI_DispStringHCenterAt(String, Pos_Setting_Title_Line_0->X, Pos_Setting_Title_Line_0->Y);
    GUI_MEMDEV_CopyToLCD(hmemLocal);
    GUI_MEMDEV_Delete(hmemLocal);
};
/*Display the setting content below the setting title*/
void DisplayText_Setting_SubTitle(const char* String)
{
    GUI_MEMDEV_Handle hmemLocal;
    hmemLocal = GUI_MEMDEV_CreateEx(Pos_Setting_SubTitle->X0, Pos_Setting_SubTitle->Y0, Pos_Setting_SubTitle->Width, Pos_Setting_SubTitle->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemLocal);
    GUI_ClearRect(Pos_Setting_SubTitle->X0, Pos_Setting_SubTitle->Y0, Pos_Setting_SubTitle->X1, Pos_Setting_SubTitle->Y1);
    /*Display the text content*/
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetBkColor(GUI_BLACK);
    GUI_DispStringHCenterAt(String, Pos_Setting_SubTitle->X, Pos_Setting_SubTitle->Y0);
    GUI_MEMDEV_CopyToLCD(hmemLocal);
    GUI_MEMDEV_Delete(hmemLocal);
};

/*!DisplayText_TopBar_Title*/
void Display_Icon_Buttons(uint8_t DispStatus_u8)
{
    GUI_MEMDEV_Handle hmemBottom = 0;
    GUI_SetBkColor(GUI_BLACK);
    hmemBottom = GUI_MEMDEV_CreateEx(Pos_BottomContent->X0, Pos_BottomContent->Y0, Pos_BottomContent->Width, Pos_BottomContent->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemBottom);
    GUI_ClearRect(Pos_BottomContent->X0, Pos_BottomContent->Y0, Pos_BottomContent->X1, Pos_BottomContent->Y1);
    /*Display the text content*/
    switch (DispStatus_u8)
    {
    case IconBottDisp_UpBackDownSelect:
        DispButton_UP(Point_BottomIcon_0);
        DispButton_BACK(Point_BottomIcon_1);
        /*Draw the line*/
        DispButton_DOWN(Point_BottomIcon_2);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_1);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_UpBackUpHomeSelect:
        DispButton_DOWN(Point_BottomIcon_0);
        DispButton_BACK(Point_BottomIcon_1);
        /*Draw the line*/
        DispButton_UP(Point_BottomIcon_2);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_1);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_UpBackDownHomeSelect:
        DispButton_UP(Point_BottomIcon_0);
        DispButton_BACK(Point_BottomIcon_1);
        /*Draw the line*/
        DispButton_DOWN(Point_BottomIcon_2);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_1);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_Back:
        DispButton_BACK(Point_BottomIcon_0);
        break;
    case IconBottDisp_BackNext:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_NEXT(Point_BottomIcon_4);
        break;
    case IconBottDisp_BackSelect:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_SELECT(Point_BottomIcon_4);
        break;
    case IconBottDisp_BackHome:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_HOME(Point_BottomIcon_4);
        break;
    case IconBottDisp_HomeSelect:
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_BackHomeSelect:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_BackHomeNext:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_NEXT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_CancelNext:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_CANCEL(Point_BottomIcon_2);
        DispButton_HOME(Point_BottomIcon_4);
        break;
    case IconBottDisp_BackCancelHomeNext:
        DispButton_BACK(Point_BottomIcon_0);
        DispButton_CANCEL(Point_BottomIcon_2);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_NEXT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_CancelHomeSelect:
        DispButton_CANCEL(Point_BottomIcon_0);
        DispButton_HOME(Point_BottomIcon_3);
        DispButton_SELECT(Point_BottomIcon_4);
        DrawTheSlash(Point_BottomIcon_Slash_2);
        break;
    case IconBottDisp_RightOnly_Select:
        DispButton_SELECT(Point_BottomIcon_4);
        break;
    default:
        break;
    }
    GUI_MEMDEV_CopyToLCD(hmemBottom);
    GUI_MEMDEV_Delete(hmemBottom);
}

/*Clear these no used in list from StartIteClear
This will prevent the flashing whole screen after using clear all screen*/
void ClearUnusedInList(uint8_t StartIteClear)
{
    GUI_MEMDEV_Handle hmemlocal;
    for(uint8_t u8_i = StartIteClear; u8_i < MaxItemInList; u8_i++)
    {
        hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (u8_i*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemlocal);
        GUI_ClearRect(Pos_Item_Select_List->X0, (u8_i*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (u8_i*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
        GUI_MEMDEV_CopyToLCD(hmemlocal);
        GUI_MEMDEV_Delete(hmemlocal);
    }
    ClearPortionAfterUpdateMenuInList();
};

void Handle_InfoMenu_Display_BatteryInfo(void)
{
    char pStrRet[LangMaxLength];
    SetFont_5;
    GUI_SetColor(GUI_GREEN);
//    sprintf(pStrRet, "%d%%", *(pDataSurfBatt.battValue));
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(pStrRet, Point_InfoMenu_Battery->x, Point_InfoMenu_Battery->y);
};
/*
@brief:
@arg
_Status: Select/Unselect
_SwitchModeInput: the orderation list to swich mode -> Divemode / Custom
_Context: Left/Center/Right: if leave it blank is no display
*/
void Handle_GeneralListMenuContext(uint8_t _SwitchModeInput, ItemStatus_te _Status, menuItemContext_ts _Context)
{
    char strRet_pChar[LangMaxLength];
    unsigned char Pos = 0;
    GUI_MEMDEV_Handle hMemDevLocal;
    /*Settings then initial*/
    SetFont_3;
    GUI_SetBkColor(GUI_BLACK);
    Pos = _Context.posInMode[_SwitchModeInput]; //Position determine in each mode
    /*Select hmem base on content clear*/
    if(ONLYLEFT_DISPLAY==_Context.flagDispLeft)
    {
        hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List_OnlyLeft->X0, (Pos*Pos_Item_Select_List_OnlyLeft->Height)+Pos_Item_Select_List_OnlyLeft->Y0, Pos_Item_Select_List_OnlyLeft->Width, Pos_Item_Select_List_OnlyLeft->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hMemDevLocal);
        GUI_ClearRect(Pos_Item_Select_List_OnlyLeft->X0, (Pos*Pos_Item_Select_List_OnlyLeft->Height)+Pos_Item_Select_List_OnlyLeft->Y0, Pos_Item_Select_List_OnlyLeft->X1, (Pos*Pos_Item_Select_List_OnlyLeft->Height)+(Pos_Item_Select_List_OnlyLeft->Y1));
    }
    else
    {
        hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hMemDevLocal);
        GUI_ClearRect(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (Pos*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
    }
    GUI_SetColor((IteStat_UnSelect == _Status) ? TxtColor_UnSelect : TxtColor_Select);
    /*Left context*/
    if((ENABLE_DISPLAY==_Context.flagDispLeft)||(ONLYLEFT_DISPLAY==_Context.flagDispLeft))
    {
        GUI_SetTextAlign(GUI_TA_LEFT);
        /*String content progress*/
        _Context.LeftStr(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, Pos_Item_Select_List->X0, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    /*Right context*/
    if(ENABLE_DISPLAY==_Context.flagDispRight)
    {
        /* Specific change Setting Tittle color*/
        if(ENABLE_COLOR_HANDLE==_Context.flagEnableColorHandle)
        {
            GUI_SetColor(Color_InfoTitleSetting[TITLE_Color]);
        }
        else
        {
            /*Do nothing -> keep the same setting color on the top*/
        }
        GUI_SetTextAlign(GUI_TA_RIGHT);
        /*String content progress*/
        _Context.RightStr(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, Pos_Item_Select_List->X1, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    /*Center context*/
    if(ENABLE_DISPLAY==_Context.flagDispCenter)
    {
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*String content progress*/
        _Context.CenterStr(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, PosX_Center, (Pos_Item_Select_List->Y0 + (Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    /*Middle 01 context*/
    if(ENABLE_DISPLAY==_Context.flagDispMiddle_01)
    {
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*String content progress*/
        _Context.Middle_01_Str(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, Point_MainMenu_GasSwitch_STATUS->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    /*Middle 02 context*/
    if(ENABLE_DISPLAY==_Context.flagDispMiddle_02)
    {
        GUI_SetTextAlign(GUI_TA_CENTER);
        /*String content progress*/
        _Context.Middle_02_Str(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, Point_MainMenu_GasSwitch_FO2Val->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    }
    else
    {
        /*Do nothing*/
    }
    /*Draw the dot: Specific to Set Gases*/
    if(ENABLE_DISPLAY==_Context.conditionCheckDispDot())
    {
        GUI_AA_FillCircle(Point_SetMenu_SetGas_ActualCircle->x, (Pos*Pos_Item_Select_List->Height) + Point_SetMenu_SetGas_ActualCircle->y, 3);
    }
    else
    {
        /*Do nothing*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
};
/*
_SwitchModeInput: the orderation list to swich mode -> Divemode/Custom
*/
void HandleFunc_DisplayInitListOfMenu(uint8_t switchModeInput, const menuItemContext_ts _ItemContext, const listItemInMenu_ts** _ListInfo)
{
    unsigned char MaxItemNum = 0;
    unsigned char posHighlight = 0;
    const menuItemContext_ts* _ContextContent;
    /*Display all the item of main mode in list*/
    MaxItemNum = _ListInfo[switchModeInput]->maxNumItem;
    /*Clear the list -> Only clear the rest*/
    ClearUnusedInList(MaxItemNum);
    /*Position in mode*/
    posHighlight = _ItemContext.posInMode[switchModeInput];
    for(unsigned char _i = 0; _i < MaxItemNum; _i++)
    {
        /*Context of each item in list*/
        _ContextContent = _ListInfo[switchModeInput]->menuItemContext[_i];
        Handle_GeneralListMenuContext(switchModeInput, (posHighlight==_i) ? IteStat_Select : IteStat_UnSelect, *_ContextContent);
    }
}
/*Display text general with out memdev*/
void HandleDispTextGeneral(txtDispContext_st contextContent)
{
    char strRet_pChar[LangMaxLength];
    GUI_SetColor(contextContent.textColor);
    /*Set text alignment*/
    GUI_SetTextAlign(contextContent.textAlign);
    /*Set font*/
    GUI_SetFont(contextContent.textFont);
    /*Text display*/
    contextContent.contentHandle(strRet_pChar);
    GUI_DispStringAt(strRet_pChar, (*(contextContent.pointDisp))->x, (*(contextContent.pointDisp))->y);
}
/*Display item with memdev
Hanlde status from outside*/
void HandleDisplayTextWithMemdev(ItemStatus_te itemStatus, contentDispContext_st _DispContext)
{
    /*Create memory device space*/
    GUI_MEMDEV_Handle hMemDevLocal;
    hMemDevLocal = GUI_MEMDEV_CreateEx((*(_DispContext.portionDisp))->X0, (*(_DispContext.portionDisp))->Y0, (*(_DispContext.portionDisp))->Width, (*(_DispContext.portionDisp))->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    char strRet_pChar[LangMaxLength];
    if(((IteStat_Flashing==itemStatus) && (FLASHING_STATE_ON==FlashingState_u8))||(IteStat_Clear==itemStatus) || (IteStat_ClearThenSelect==itemStatus)||(IteStat_ClearThenFlashing==itemStatus))
    {
        GUI_ClearRect((*(_DispContext.portionDisp))->X0, (*(_DispContext.portionDisp))->Y0, (*(_DispContext.portionDisp))->X1, (*(_DispContext.portionDisp))->Y1);
    }
    else
    {
        /*Do nothing*/
    }
    if(((IteStat_Flashing==itemStatus) && (FLASHING_STATE_OFF==FlashingState_u8))||
            ((IteStat_ClearThenFlashing==itemStatus) && (FLASHING_STATE_OFF==FlashingState_u8))||
            (IteStat_Select==itemStatus) ||
            (IteStat_UnSelect==itemStatus) ||
            (IteStat_ClearThenSelect==itemStatus))
    {
        /*Set color*/
        GUI_SetColor(_DispContext.colorHandle());
        /*Set font number*/
        GUI_SetFont(_DispContext.textFont);
        /*Set text alignment*/
        GUI_SetTextAlign(_DispContext.textAlign);
        /*String display*/
        _DispContext.contentHandle(strRet_pChar);
        GUI_DispStringAt(strRet_pChar, (*(_DispContext.portionDisp))->X, (*(_DispContext.portionDisp))->Y);
    }
    else
    {
        /*Do nothing*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
};
/*Display Item*/
void HandleDisplayItemMdev(contentWithStateHandle_st _DispContext)
{
    ItemStatus_te itemStatus;
    /*Get the status*/
    itemStatus = _DispContext.funcStatHandle();
    /*progress status*/
    if(itemStatus!=IteStat_DoNothing)
    {
        /*Create memory device space*/
        GUI_MEMDEV_Handle hMemDevLocal;
        hMemDevLocal = GUI_MEMDEV_CreateEx((*(_DispContext.portionDisp))->X0, (*(_DispContext.portionDisp))->Y0, (*(_DispContext.portionDisp))->Width, (*(_DispContext.portionDisp))->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hMemDevLocal);
        char strRet_pChar[LangMaxLength];
        if(((IteStat_Flashing==itemStatus) && (FLASHING_STATE_ON==FlashingState_u8))||
                (IteStat_Clear==itemStatus) ||
                (IteStat_ClearThenSelect==itemStatus)||
                (IteStat_ClearThenFlashing==itemStatus))
        {
            GUI_ClearRect((*(_DispContext.portionDisp))->X0, (*(_DispContext.portionDisp))->Y0, (*(_DispContext.portionDisp))->X1, (*(_DispContext.portionDisp))->Y1);
        }
        else
        {
            /*Do nothing*/
        }
        if(((IteStat_Flashing==itemStatus) && (FLASHING_STATE_OFF==FlashingState_u8))||
                ((IteStat_ClearThenFlashing==itemStatus) && (FLASHING_STATE_OFF==FlashingState_u8))||
                (IteStat_Select==itemStatus) ||
                (IteStat_UnSelect==itemStatus) ||
                (IteStat_ClearThenSelect==itemStatus))
        {
            /*Set color*/
            GUI_SetColor(_DispContext.colorHandle());
            /*Set font number*/
            GUI_SetFont(_DispContext.textFont);
            /*Set text alignment*/
            GUI_SetTextAlign(_DispContext.textAlign);
            /*String display*/
            _DispContext.contentHandle(strRet_pChar);
            GUI_DispStringAt(strRet_pChar, (*(_DispContext.portionDisp))->X, (*(_DispContext.portionDisp))->Y);
        }
        else
        {
            /*Do nothing*/
        }
        GUI_MEMDEV_CopyToLCD(hMemDevLocal);
        GUI_MEMDEV_Delete(hMemDevLocal);
    }
    else
    {
        /*Do nothing*/
    }
};
