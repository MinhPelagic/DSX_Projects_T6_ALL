#include "L4X9_includes.h"
#include "..\..\..\..\DSX\DSX_Version.h"
#include "..\Menu\Main Menu\Main_Menu_INFO\MenuHandle_MyInfo_ReadEepromData.h"

#define WELCOME_W                 (320U)                              //Width
#define WELCOME_H                 (190U)                              //Height
#define WELCOME_PIXEL_SIZE        (WELCOMEE_W*WELCOME_H)              //Size of Welcome picture
#define WELCOME_ADDR_HEAD         ((uint32_t)0x11200000)              //Welcome #1
#define WELCOME_DATA_SIZE         ((uint32_t)(SLATE_PIXEL_SIZE*2U))   //Number of bytes (16bits/pixel)
#define WELCOME_ADDR_GAP          ((uint32_t)320*240*2)            //Mobile application defined

extern GUI_CONST_STORAGE GUI_BITMAP bmDSX_WelcomeBMP, bmRegister;
extern STRING_LANG StrLang_Select[];
const bmpInforToDisplay_ts bmpWelcomeScreen1 =
    {
        WELCOME_ADDR_HEAD, /*Address*/
        320,        /*Width of bmp to display*/
        240,        /*Width of bmp to display*/
        0U,         /*x0*/
        0U,         /*y0*/
    };
const bmpInforToDisplay_ts bmpWelcomeScreen2 =
    {
        (WELCOME_ADDR_HEAD+WELCOME_ADDR_GAP), /*Address*/
        320,        /*Width of bmp to display*/
        240,        /*Width of bmp to display*/
        0U,         /*x0*/
        0U,         /*y0*/
    };
const bmpInforToDisplay_ts bmpWelcomeScreen3 =
    {
        (WELCOME_ADDR_HEAD+WELCOME_ADDR_GAP*2), /*Address*/
        320,        /*Width of bmp to display*/
        240,        /*Width of bmp to display*/
        0U,         /*x0*/
        0U,         /*y0*/
    };
void IniOrClrScrFunc_W1_WELCOME(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    unsigned char hString[30];
    /*When default */
    if(!REGISTER_Done())
    {
        GUI_DrawBitmap(&bmRegister, 0, 0);
    }  
    else if ((USER_Set.ScreenSet==0)||((0 == USER_Set.Welcome_Idx[0]) && (0 == USER_Set.Welcome_Idx[1]) && (0 == USER_Set.Welcome_Idx[2])))
    {
        GUI_DrawBitmap(&bmDSX_WelcomeBMP, 0, 0);
    }
    /*If one of them has */
    else
    {
        if((USER_Set.ScreenSet==1)&&(USER_Set.Welcome_Stat[0]==1))
        {
            switch(USER_Set.Welcome_Idx[0])
            {
                case 1:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen1);
                    break;
                case 2:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen2);
                    break;
                case 3:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen3);
                    break;
                default:
                    GUI_DrawBitmap(&bmDSX_WelcomeBMP, 0, 0);
                    break;
            }
        }
        else if((USER_Set.ScreenSet==2)&&(USER_Set.Welcome_Stat[1]==1))
        {
            switch(USER_Set.Welcome_Idx[1])
            {
                case 1:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen1);
                    break;
                case 2:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen2);
                    break;
                case 3:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen3);
                    break;
                default:
                    GUI_DrawBitmap(&bmDSX_WelcomeBMP, 0, 0);
                    break;
            }
        }
        else if((USER_Set.ScreenSet==3)&&(USER_Set.Welcome_Stat[2]==1))
        {
            switch(USER_Set.Welcome_Idx[2])
            {
                case 1:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen1);
                    break;
                case 2:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen2);
                    break;
                case 3:
                    DisplayBmpFromEEPROM(bmpWelcomeScreen3);
                    break;
                default:
                    GUI_DrawBitmap(&bmDSX_WelcomeBMP, 0, 0);
                    break;
            }
        }
        else
            GUI_DrawBitmap(&bmDSX_WelcomeBMP, 0, 0);
    }
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetFont(&GUI_Font8x16_ASCII);
    // GUI_SetFont(&FontAaux_3);
    GUI_SetTextAlign(GUI_TA_CENTER);
    STR_FW_VERSION(hString);
    GUI_DispStringAt(hString, PosX_Center, 220);
    GUI_SetTextMode(GUI_TM_NORMAL);
}
void IniOrClrScrFunc_W2_WAIT_MESSAGE(void)
{
    /*Load the string content to RAM*/
    GUI_LANG_LoadTextEx(_GetData, (void *)&StrLang_Select[LANGUAGE], LANGUAGE);
    GUI_LANG_SetLang(LANGUAGE);
    GUI_UC_SetEncodeUTF8();
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    SetFont_4;
    GUI_SetColor(GUI_CYAN);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_WAITFORBEEP), 160, 75);
    GUI_DispStringHCenterAt(GUI_LANG_GetText(TxtStr_THEN_ACTIVATE), 160, 125);
}