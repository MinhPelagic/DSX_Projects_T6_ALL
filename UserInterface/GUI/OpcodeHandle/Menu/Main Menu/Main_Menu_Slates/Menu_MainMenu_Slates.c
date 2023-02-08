/******************************************************************************/
//File: MAIN MENU -> Slates
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_MainMenu_Slates.h"
#include "..\..\..\..\Bitmaps\apeksSmallLogo.c"

extern uint8_t GUI_CurrSlateNum;
/*Slate Main Page*/
void IniOrClrScrFunc_SLATES_MAINPAGE(void)
{
    GUI_Clear();
    GUI_DrawBitmap(&bmapeksSmallLogo, 8, 0);
    /*Display slate title*/
    SetFont_2;
    GUI_SetColor(GUI_CYAN);
    GUI_SetTextAlign(GUI_TA_LEFT);
    /**/
    Display_Icon_Buttons(IconBottDisp_BackCancelHomeNext);
    /* start displaying first Slate saved in SLATE_Idx[0] location*/
    ReadAndDisplaySlates(USER_Set.SLATE_Idx[0]);
    GUI_CurrSlateNum = 1U; //Set Current slate is number 1
    /*Display title slate number*/
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_Tittle);
}
/*NO SLATES*/
void IniOrClrScrFunc_SLATES_NO_SLATE(void)
{
    GUI_Clear();
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_NoSlate);
    Display_Icon_Buttons(IconBottDisp_BackHome);
}
/*CONFIRMM DELETE*/
void IniOrClrScrFunc_SLATES_CONFIRM_DELETE(void)
{
    GUI_Clear();
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ConfirmDelete_Line_0);
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ConfirmDelete_Line_1);
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_ConfirmDelete_Line_2);
    Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
}
/*SLATES DELETED*/
void IniOrClrScrFunc_SLATES_DELETED(void)
{
    GUI_Clear();
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_SlateDeleted_Line_0);
    HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_SlateDeleted_Line_1);
    Display_Icon_Buttons(IconBottDisp_HomeSelect);
    /*Set to first page*/
    GUI_CurrSlateNum = 1U;
}
