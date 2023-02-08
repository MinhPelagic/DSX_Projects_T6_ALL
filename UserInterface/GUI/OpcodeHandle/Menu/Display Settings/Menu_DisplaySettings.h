/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
/*3rd ROWs define*/
//typedef enum
enum {
    _3rdRowSet_BLANK,
    _3rdRowSet_O2SAT,
    _3rdRowSet_GF,
    _3rdRowSet_CEILING,
    _3rdRowSet_MAXDEPTH,
    _3rdRowSet_AVGDEPTH,
    _3rdRowSet_TIME,
    _3rdRowSet_DIL_PO2,
    _3rdRowSet_FiO2,
    _3rdRowSet_GTR,
    _3rdRowSet_MAX,
};
GUI_COLOR SurfaceMode_SurfTime_TitleText_Color(void);
void DisplayBrightnessSettings(ItemStatus_te status);
extern const listItemInMenu_ts* DisplaySettings_ListOfContext[];
extern const listItemInMenu_ts* MainDisplay_ListOfContext[];
extern const TxtStr_Name_e TxtDef_ExtraLarge_Context[];
extern const contentDispContext_st Set_DispSett_Autodim_Stat_Ctx;
extern const contentDispContext_st Set_DispSett_Autodim_BrightTime_Ctx;
extern const contentDispContext_st Set_DispSett_Brightness_AutoDim_Ctx;
extern const contentDispContext_st Set_DispSett_Brightness_PercentChar_Ctx;
extern const contentDispContext_st Set_DispSett_Brightness_Value_Ctx;
extern const contentDispContext_st Set_DispSett_Brightness_Autodim_Ctx;
extern const contentDispContext_st Set_DispSett_Extralarge_Ctx;
extern const contentDispContext_st Set_DispSett_FlipScreen_Ctx;
extern const contentDispContext_st Set_DispSett_GTRLeftRight_Ctx;
extern const contentDispContext_st Set_MainDisp_3rdRowLeft_Ctx;
extern const contentDispContext_st Set_MainDisp_3rdRowRight_Ctx;
extern const contentDispContext_st Set_MainDisp_GFBGorN2bar_Ctx;
extern const contentDispContext_st Set_DispSett_TittleColor_Ctx;
extern const contentDispContext_st Set_DispSett_Language_Ctx;
extern const TxtStr_Name_e TxtDef_Set_TitleColor[ColorTitle_MAX];
extern const char* TxtDef_Set_Language[MAX_LANGUAGE];
extern const TxtStr_Name_e TxtDef_LEFT_RIGHT_Context[];
extern uint8_t  GUI_MAINDISPLAY_3RD_ROW_RIGHT;
extern uint8_t  GUI_MAINDISPLAY_3RD_ROW_LEFT;
extern const TxtStr_Name_e TxtStrSetLanguage[MAX_LANGUAGE];
extern LanguageSelect_t GUI_LANG_Select;
extern void Check3rdRowAfterDiveModeSwitch(void);