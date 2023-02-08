/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDisplaySettingsCfg.h"
#include "Menu_DisplaySettings.h"

extern unsigned char AutoDimStatusCheck(void);

/**/
const TxtStr_Name_e TxtDef_ExtraLarge_Context[Setting_MAX] =
{
    TxtStr_OFF,
    TxtStr_DEPTH,
    TxtStr_DIVE_TIME,
};
/**/
static const TxtStr_Name_e TxtDef_Set_N2_or_GF[2] =
{
    TxtStr_GFBG,
    TxtStr_N2_BAR,
};
const TxtStr_Name_e TxtDef_LEFT_RIGHT_Context[_3rdRowSet_MAX] =
{
    TxtStr_BLANK,
    TxtStr_O2_SAT,
    TxtStr_GF,
    TxtStr_CEILING,
    TxtStr_MAX_DEPTH,
    TxtStr_AVG_DEPTH,
    TxtStr_TIME,
    TxtStr_DIL_PO2,
    TxtStr_FIO2,
    TxtStr_GTR,
};
const TxtStr_Name_e TxtDef_Set_TitleColor[ColorTitle_MAX]=
{
    TxtStr_CYAN,
    TxtStr_GREEN,
    TxtStr_WHITE,
    TxtStr_ORANGE,
    TxtStr_MAGENTA,
};



const char* TxtDef_Set_Language[MAX_LANGUAGE]=
{
    "ENGLISH",
    "GERMAN",
    "FRENCH",
    "ITALIAN",
    "ESPANOL",
    "PORTUGESE",
    "POLISH",
    "RUSSIAN",
    "CZECH",
    "CHINESE_S",
    "CHINESE_T",
    "KOREAN",
};

const TxtStr_Name_e TxtStrSetLanguage[MAX_LANGUAGE] =
{
    TxtStr_LANG_ENGLISH,
    TxtStr_LANG_GERMAN,
    TxtStr_LANG_FRENCH,
    TxtStr_LANG_ITALIAN,
    TxtStr_LANG_SPANISH, //ESPAÑOL
    TxtStr_LANG_PORTUGUESE,
    TxtStr_LANG_POLISH,
    TxtStr_LANG_RUSSIAN,
    TxtStr_LANG_CZECH,
    TxtStr_LANG_CHINESE_S,
    TxtStr_LANG_CHINESE_T,
    TxtStr_LANG_KOREAN,
};
/*BRIGHTNESS context*/
void DispSett_BRIGHTNESS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BRIGHTNESS));
}
void DispSett_BRIGHTNESS_Context_Right(char* pStrRet)
{
    if(AutoDimStatusCheck())
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUTO));
    }
    else
    {
        sprintf(pStrRet, "%d%%", GUI_BRIGHTNESS_LV);
    }

}
/*LANGUAGE SET context*/
void DispSett_LANGUAGE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LANGUAGE));
}
void DispSett_LANGUAGE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStrSetLanguage[GUI_LANG_Select]));
}

/*COLOR SET context*/
void DispSett_TITLECOLOR_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_TITLES_COLOR));
}
void DispSett_TITLECOLOR_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_Set_TitleColor[TITLE_Color]));
}
/*AUTODIM SET context*/
void DispSett_AUTODIM_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUTO_DIM));
}
void DispSett_AUTODIM_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_BRIGHTNESS_DIM_MODE]));
}
/*FLIPSCREEN SET context*/
void DispSett_FLIPSCREEN_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_FLIP_SCREEN));
}
void DispSett_FLIPSCREEN_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[GUI_SWITCH_LCD_Flip]));
}
/*MAIN DISPLAY context*/
void DispSett_MAINDISPLAY_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MAIN_DISPLAY));
}
/*GTR for Left and Right*/
void DispSett_GTR_LEF_RIGHT_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GTR_FOR_LR));
}
void DispSett_GTR_LEF_RIGHT_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_YesNo_Context[GUI_SWITCH_LCD_GTR_L_R]));
}
/*GF or N2 bar*/
void MainDisplay_GFBG_OR_N2_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_GFBG_OR_N2_BAR));
}
void MainDisplay_GFBG_OR_N2_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_Set_N2_or_GF[GUI_MAINDISPLAY_N2_OR_GF_BAR]));
}
void MainDisplay_LEFT_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_3rd_ROW_LEFT));
}
void MainDisplay_LEFT_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_LEFT_RIGHT_Context[GUI_MAINDISPLAY_3RD_ROW_LEFT]));
}
void MainDisplay_RIGHT_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_3rd_ROW_RIGHT));
}
void MainDisplay_RIGHT_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_LEFT_RIGHT_Context[GUI_MAINDISPLAY_3RD_ROW_RIGHT]));
}
/*EXTRA LARGE context*/
void DispSett_EXTRALARGE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_EXTRA_LARGE));
}
void DispSett_EXTRALARGE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_ExtraLarge_Context[GUI_MAINDISPLAY_EXTRA_LARGE]));
}
