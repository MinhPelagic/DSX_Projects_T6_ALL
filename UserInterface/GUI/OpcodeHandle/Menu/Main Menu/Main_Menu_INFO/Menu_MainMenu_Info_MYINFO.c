/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"
#include "MenuHandle_MyInfo_ReadEepromData.h"

// Temporarily added by YS, needs Duc Thinh's correction please
static void MyINFO_Line01(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MY_INFO_1));
}
const contentDispContext_st MyInfoNoData_Line01_Ctx =
{
    &MyINFO_Line01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_0,
};
static void MyINFO_Line02(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MY_INFO_2));
}
const contentDispContext_st MyInfoNoData_Line02_Ctx =
{
    &MyINFO_Line02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
static void MyINFO_Line03(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MY_INFO_3));
}
const contentDispContext_st MyInfoNoData_Line03_Ctx =
{
    &MyINFO_Line03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};

static void MyINFO_Line04(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_MY_INFO_4));
}
const contentDispContext_st MyInfoNoData_Line04_Ctx =
{
    &MyINFO_Line04,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_3,
};

// Temporarily added by YS, needs Duc Thinh's correction please
const bmpInforToDisplay_ts bmpMyInforDisplay =
{
    0x11300000, /*Address 104*/
    320,        /*Width of bmp to display*/
    240,        /*Width of bmp to display*/
    0U,         /*x0*/
    0U,         /*y0*/
};
void IniOrClrScrFunc_S218_IM_MYINFO_SET(void)
{
    /*When no set MY INFO*/
    if((0U==USER_Set.MyInfo_Idx))
    {
        ClearUnusedInList(0);
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_MY_INFO));
        /*Content*/
        HandleDisplayTextWithMemdev(IteStat_Select, MyInfoNoData_Line01_Ctx);
        HandleDisplayTextWithMemdev(IteStat_Select, MyInfoNoData_Line02_Ctx);
        HandleDisplayTextWithMemdev(IteStat_Select, MyInfoNoData_Line03_Ctx);
        HandleDisplayTextWithMemdev(IteStat_Select, MyInfoNoData_Line04_Ctx);

        Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
    }
    else
    {
        DisplayBmpFromEEPROM(bmpMyInforDisplay);
    }
}