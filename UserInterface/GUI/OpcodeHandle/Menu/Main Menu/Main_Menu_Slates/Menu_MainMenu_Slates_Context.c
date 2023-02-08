/******************************************************************************/
//File: MAIN MENU -> Slates
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_MainMenu_Slates.h"
/*Local decalartion*/
static void MainMenu_Slates_DateTittle_Content(char *pStrRet);

/*NO SLATES*/
static void MainMenu_Slates_NoSlate_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_SLATES));
}
const contentDispContext_st MainMenu_Slates_NoSlate =
{
    &MainMenu_Slates_NoSlate_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
/*CONFIRM DELETE*/
// static void MainMenu_Slates_ConfirmDelete_Line_0_Content(char *pStrRet)
// {
//     strcpy(pStrRet, "##.##.## - SLATE #");
// }
const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_0 =
{
    &MainMenu_Slates_DateTittle_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void MainMenu_Slates_ConfirmDelete_Line_1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DELETE_SLATE_2));
}
const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_1 =
{
    &MainMenu_Slates_ConfirmDelete_Line_1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void MainMenu_Slates_ConfirmDelete_Line_2_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DELETE_SLATE_3));
}
const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_2 =
{
    &MainMenu_Slates_ConfirmDelete_Line_2_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*SLATES DELETED*/
const contentDispContext_st MainMenu_Slates_SlateDeleted_Line_0 =
{
    &MainMenu_Slates_DateTittle_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void MainMenu_Slates_SlateDeleted_Line_1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DELETED));
}
const contentDispContext_st MainMenu_Slates_SlateDeleted_Line_1 =
{
    &MainMenu_Slates_SlateDeleted_Line_1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*Slate titles*/
static void MainMenu_Slates_DateTittle_Content(char *pStrRet)
{
    slateDateFormat *dat_s;
    /*get the data from index*/
    dat_s = (slateDateFormat*) &(USER_Set.SLATE_Data[GUI_CurrSlateNum-1]);
    sprintf(pStrRet, "%s_%d.%d.%d_%.2d  ", GUI_LANG_GetText(TxtStr_DELETE_SLATE_1), dat_s->day, dat_s->month, dat_s->year, GUI_CurrSlateNum);
}
const contentDispContext_st MainMenu_Slates_Tittle =
{
    &MainMenu_Slates_DateTittle_Content,
    &Unselect_TxtColor,
    GUI_TA_LEFT,
    &FontAaux_3,
    &Pos_Slates_Tittle,
};
// TODO: handle case flipped screen
// GUI_ClearRect(5,30,320-5,240-30);

// GUI_SetColor(GUI_BLACK);
// GUI_SetTextAlign(GUI_TA_LEFT);
// SetFont_1;
// for (uint8_t u8_i = 0; u8_i < 12; u8_i++) {
//     const int marginTop = 30;
//     const int marginLeft = 15;
//     const int width = 320;
//     const int lineHeight = 15;

//     const int x0 = marginLeft;
//     const int y0 = u8_i * lineHeight + marginTop + (int)(!(bool)u8_i); // first line smaller 1px
//     const int x1 = width - marginLeft;
//     const int y1 = (u8_i + 1) * lineHeight+marginTop;

//     hMemDev_DisplayNum = GUI_MEMDEV_CreateEx(x0, y0, x1 - x0, y1 - y0, GUI_MEMDEV_HASTRANS);
//     GUI_MEMDEV_Select(hMemDev_DisplayNum);

//     GUI_SetBkColor((u8_i%2) ? GUI_LIGHTGRAY : GUI_WHITE);
//     GUI_ClearRect(x0, y0, x1, y1);

//     const int xCol1 = 20;
//     const int xCol2 = 120;
//     const int xCol3 = 260;
//     const int yTitleLine = y0 - 3;
//     const int yContentLine = y0 - 1;

//     // TODO: get data from provider
//     if (u8_i == 0) {
//         GUI_DispStringAt("Depth(ft)", xCol1, yTitleLine);
//         GUI_DispStringAt("Runtime(min)", xCol2, yTitleLine);
//         GUI_DispStringAt("Gas", xCol3, yTitleLine);
//     }
//     else {
//         sprintf(pStrRet, "%d", 5 * u8_i);
//         GUI_DispStringAt(pStrRet, xCol1, yContentLine);
//         sprintf(pStrRet, "%.1f", 5.1 * u8_i);
//         GUI_DispStringAt(pStrRet, xCol2, yContentLine);
//         GUI_DispStringAt("AIR (CC)", xCol3, yContentLine);
//     }
//     CopyFromMemDevToLCD;
// }