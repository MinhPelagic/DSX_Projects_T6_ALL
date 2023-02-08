#ifndef _TEXT_DSX_H__
#define _TEXT_DSX_H__

#include "../DsxOCDefine.h"
#include "OC_DSX.h"

#define ARRAY_SIZE(x) 				(sizeof(x) / sizeof(*(x)))
#define ABS(X)  					((X) > 0 ? (X) : -(X))
#define LangMaxLength 				256
#define SetFont_1 		  			GUI_SetFont(&FontAaux_1)
#define SetFont_2 					GUI_SetFont(&FontAaux_2)
#define SetFont_3 					GUI_SetFont(&FontAaux_3)
#define SetFont_4 					GUI_SetFont(&FontAaux_4)
#define SetFont_5 					GUI_SetFont(&FontAaux_5)
#define MaxItemInList		                (7U)//From design only had 7 items max in list
#define MAX_ITEM_DISP_PAGE_LOG_01           (7U)  //Max item in LOG Page 01
#define MaxItemPlan                         (6U)
#define CopyFromMemDevToLCD					GUI_MEMDEV_CopyToLCD(hMemDev_DisplayNum); GUI_MEMDEV_Delete(hMemDev_DisplayNum);
/*
The postions define
- Pos+X|Y+Module+Name
*/
#define PosX_Center					(160)
#define PosY_Center					(120)

#define FPIOVER180 0.01745329251994F	// degrees to radians conversion = pi / 180

#define ENABLE_COLOR_HANDLE  1
#define DISABLE_COLOR_HANDLE 0
#define FLASHING_STATE_ON   (0xFF)                  //Display the item
#define FLASHING_STATE_OFF  (0x00)    //Clear the item
/*
Specify handle the menu display item list
1. Disable
2. Enable
3. Enable but only clear left portion
*/
enum
{
    DISABLE_DISPLAY = 0U,
    ENABLE_DISPLAY,
    ONLYLEFT_DISPLAY
};
/*
When flag_x display is true/enable -> Call the function context
Otherwise -> Do nothing
*/
typedef struct
{
    /*Left Content*/
    const unsigned char flagDispLeft;
    pstrHandle_Func LeftStr;
    /*Center Content*/
    const unsigned char flagDispCenter;
    pstrHandle_Func CenterStr;
    /*Middle 01 Content*/
    const unsigned char flagDispMiddle_01;
    pstrHandle_Func Middle_01_Str;
    /*Middle 02 Content*/
    const unsigned char flagDispMiddle_02;
    pstrHandle_Func Middle_02_Str;
    /*Right Content*/
    const unsigned char flagDispRight;
    pstrHandle_Func RightStr;
    /*Right Color: In menu display settings need handle the color on the right*/
    const unsigned char flagEnableColorHandle;
    /*
    1.Position in each Dive mode CC/OC/SM/GAUG/GAUGSM
    2.Incase the position in 6 modes is the same -> It can custom
        Example: in Switch SP
    */
    /*Function check the condition to display the dot*/
    pCondition_Func conditionCheckDispDot;
    const unsigned char posInMode[DIVEMODE_MAX];
} menuItemContext_ts;

/*Context handle display in menu*/
typedef struct
{
    /*Maximum item in list*/
    const unsigned char maxNumItem;
    /*List of item in*/
    const menuItemContext_ts* menuItemContext[8];
} listItemInMenu_ts;

/*Struct display test without memdev*/
typedef struct
{
    /*String content need to display*/
    pstrHandle_Func contentHandle;
    /*Text color*/
    GUI_COLOR textColor;
    /*Align text*/
    int textAlign;
    /*Font size*/
    GUI_FONT* textFont;
    /*Pointer to position of display text*/
    const GUI_POINT** pointDisp;
} txtDispContext_st;

/*Struct display with memdev*/
typedef struct
{
    /*String content need to display*/
    pstrHandle_Func contentHandle;
    /*Text color*/
    pSetColor_Func colorHandle;
    /*Align text*/
    int textAlign;
    /*Font size*/
    GUI_FONT* textFont;
    /*Pointer to position of display text*/
    const CooGUI_tds** portionDisp;
} contentDispContext_st;

/*Struct display with status handle*/
typedef struct
{
    pItem_Func funcStatHandle;
    /*String content need to display*/
    pstrHandle_Func contentHandle;
    /*Text color*/
    pSetColor_Func colorHandle;
    /*Align text*/
    int textAlign;
    /*Font size*/
    GUI_FONT* textFont;
    /*Pointer to position of display text*/
    const CooGUI_tds** portionDisp;
} contentWithStateHandle_st;

enum
{
    STRING_LANG_ENGLISH,
    STRING_LANG_ITALIAN,
    STRING_LANG_FRENCH,
    STRING_LANG_GERMAN,
    STRING_LANG_ESPANOL,
    STRING_LANG_PORTUGESE,
    STRING_LANG_CZECH,
    STRING_LANG_POLISH,
    STRING_LANG_CHINESE_S,//Simplified Chinese
    STRING_LANG_CHINESE_T,//Traditional Chinese
    STRING_LANG_RUSSIAN,
    STRING_LANG_KOREAN,
    STRING_MAX_LANGUAGE,
};
enum IconBottDisp_e
{
    IconBottDisp_UpBackDownSelect = 0U,
    IconBottDisp_UpBackUpHomeSelect,    /**/
    IconBottDisp_UpBackDownHomeSelect,    /**/
    IconBottDisp_LeftHomeRight,    /**/
    IconBottDisp_Back,
    IconBottDisp_BackSelect,
    IconBottDisp_BackNext,
    IconBottDisp_BackHome,
    IconBottDisp_BackHomeNext,
    IconBottDisp_BackHomeSelect,
    IconBottDisp_BackCancelHomeNext,
    IconBottDisp_CancelNext,
    IconBottDisp_CancelHomeSelect,
    IconBottDisp_HomeSelect,
    IconBottDisp_RightOnly_Select,
    IconBottDisp_CLEAR,
};
typedef enum
{
    ColorTitle_CYAN = 0x00,
    ColorTitle_GREEN,
    ColorTitle_WHITE,
    ColorTitle_ORANGE,
    ColorTitle_MAGENTA,
    ColorTitle_MAX
} titleColor_e;
/*Unit setting option*/
enum SetUnit_e
{
    SetUnit_Imperial = 0x00,
    SetUnit_Metric,
    SetUnit_MAX,
};
typedef struct
{
    const char *pData;
    const uint32_t NumBytes;
} STRING_LANG;


extern GUI_FONT FontAaux_1;
extern GUI_FONT FontAaux_2;
extern GUI_FONT FontAaux_3;
extern GUI_FONT FontAaux_4;
extern GUI_FONT FontAaux_5;
extern GUI_FONT FontAaux_6;
extern GUI_FONT FontAaux_7;
extern GUI_FONT FontAaux_8;

extern GUI_COLOR DiveMode_Color_Compass;
extern uint8_t Language_Present;
extern uint16_t Compass_ref;
extern uint8_t DisplayFlipping;
extern uint8_t FlashingState_u8;
extern const TxtStr_Name_e TxtDef_MONTH_Setting[];
extern GUI_MEMDEV_Handle hMemDev_DisplayNum;
extern const TxtStr_Name_e TxtDef_DSX_MainMode[];
extern const TxtStr_Name_e TxtDef_OnOffSet_Context[];
extern const TxtStr_Name_e TxtDef_YesNo_Context[];
extern const char* TxtDef_Set_DepthStr[];
extern const char* TxtDef_Set_DepthUnit[];
extern const char* TxtDef_Set_TemperatureUnit[];
extern const menuItemContext_ts Context_MENU_EMPTY;
extern NVD_status_t  GUI_SWITCH_LCD_Flip;    // GUI settings for LCD_Flip
/*Global prototype*/
/********************* Text Display ***************************************/
void DisplayGF(int Value);
void DisplayN2(int Value);
void StopDisplay_N2_GF_Bars(void);
void DivePlanner_DEPTHLIMIT_Context(void);
/*Private macro*/
/*
This macro set font whenever Display Text (DT)
*/
void Log01PageResetCounterDisplay(void);
void HandleButtonLOG_1(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButtonDiveSimulator_SET(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButtonDiveSimulator_DIVEPLAN(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButtonDiveSimulator_BAILOUTPLAN(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButtonDiveSimulator_Calculating(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_DiveMenu_DecoStop(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_DiveMenu_SetGFHigh(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_TMTSwitch(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_DiveMainMenu_TMTSwitch(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_DiveMenu_ResetAVGDepth(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_MainMenu_SLATES(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_MainMenu_SlateMainPage(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_MainMenu_SlateDelete(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_MainMenu_DeletedSlate(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_GPSMenu_Wayfinder(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_GPSMenu_DeleteLocation(DSX_OPCODE_t*, DSX_OPCODE_t*);
void HandleButton_O2AnalyzerList(DSX_OPCODE_t*, DSX_OPCODE_t*);
void DisplayText_TopBar_Title(const char* String);
void DisplayText_Setting_Title(const char* String);
void DisplayText_Setting_SubTitle(const char* String);
// void DisplayText_TopBar_Info(const char* String, GUI_COLOR _TxtColor, GUI_COLOR _BGColor);
void DecodeLogData(void);
void ClearUnusedInList(uint8_t);
void ClearWholeScreen(void);
void ClearGasSwitchBottomLine_2(void);
void ClearCompassReferencePortionOnBottomLeft(void);
void ClearPortionToUpdateOnSurface(void);
void ClearPortionToUpdateDiveMode(void);
void ClearPortionToUpdateAlarm(void);
void ClearPortionOCLeftRight(void);
void ClearPortionCCLeftRight(void);
void Display_Icon_Buttons(uint8_t);
void Handle_InfoMenu_Display_BatteryInfo(void);
void TTF_CreateFontSequence(const FontSize_ts _FontSize);
/*Extern functions*/
void Handle_GeneralListMenuContext(uint8_t _SwitchModeInput, ItemStatus_te _Status, menuItemContext_ts _Context);
void HandleFunc_DisplayInitListOfMenu(uint8_t switchModeInput, const menuItemContext_ts _ItemContext, const listItemInMenu_ts** _ListInfo);
void HandleDisplayTextWithMemdev(ItemStatus_te itemStatus, contentDispContext_st _DispContext);
void HandleDisplayItemMdev(contentWithStateHandle_st _DispContext);
void HandleDispTextGeneral(txtDispContext_st contextContent);
GUI_COLOR Select_TxtColor(void);
GUI_COLOR Unselect_TxtColor(void);
GUI_COLOR RED_TxtColor(void);
GUI_COLOR GREEN_TxtColor(void);
GUI_COLOR YELLOW_TxtColor(void);
GUI_COLOR WHITE_TxtColor(void);
GUI_COLOR AlarmColorHandle_DecoStop(void);
GUI_COLOR AlarmColorHandle_PO2(void);
GUI_COLOR SurfaceMode_SurfTime_TitleText_Color(void);
GUI_COLOR SurfaceMode_isViolation_Text_Color(void);     // added by YS to change color during VIOLATION
GUI_COLOR SurfaceMode_SwitchP_Text_Color(void);         // added by YS to change color during SwitchP
GUI_COLOR SurfaceMode_PressAlarm_Color(void);           // added by YS to change color during TurnP, EndP alarming
GUI_COLOR AlarmColorHandle_DepthMaxAlarm(void);         // added by YS to change color during over Max Depth
GUI_COLOR SurfaceMode_OCLeftTittleColor(void);
GUI_COLOR SurfaceMode_OCRightTittleColor(void);
GUI_COLOR SurfaceMode_OCRightValueColor(void);
GUI_COLOR SurfaceMode_OCLeftValueColor(void);
void Transmitters_TMT_SearchingTxtContent(char* pStrRet);
void Transmitters_TMT_BattGood_TxtContent(char* pStrRet);
void Transmitters_TMT_BattLow_TxtContent(char* pStrRet);
void Transmitters_TMT_NotAvailable_TxtContent(char* pStrRet);

#endif
