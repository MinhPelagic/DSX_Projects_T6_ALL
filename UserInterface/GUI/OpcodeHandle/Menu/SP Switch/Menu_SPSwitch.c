/******************************************************************************/
//File: SP Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSPSwitchCfg.h"
#include "Menu_SPSwitch.h"
/*Static function*/
static void SPSwitchMainTitle(void)
{
    char strRet[LangMaxLength];
    GUI_MEMDEV_Handle hMemDevLocal;
    /*Main title*/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->Width, Pos_TopTitle->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_TopTitle->X0, Pos_TopTitle->Y0, Pos_TopTitle->X1, Pos_TopTitle->Y1);
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetBkColor(GUI_BLACK);
    /*Display the SP SWITCH content*/
    GUI_SetTextAlign(GUI_TA_RIGHT);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_SP_SWITCH), Pos_TopTitle->X, Pos_TopTitle->Y0);
    /*Display the actual value SP SWITCH*/
    SetFont_2;
    sprintf(strRet, "  (%s: %.2f)  ", GUI_LANG_GetText(TxtStr_ACTUAL), SP_SWITCH_SP_ACTUAL_VAL);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt(strRet, Pos_TopTitle->X, Pos_TopTitle->Y + (5U));
    /*Draw the line in the bottom text*/
    GUI_SetColor(GUI_CYAN);
    GUI_SetPenSize(1);
    GUI_DrawPolyLine(&Hor_Line_1[0], 2, Pos_Item_Select_List->X0, Pos_TopTitle->Y1-1);
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
/*HIGH*/
void IniOrClrScrFunc_SP_SWITCH_TO_HIGH(void)
{
    SPSwitchMainTitle();
    HandleFunc_DisplayInitListOfMenu(SPSwitch_Mode(), Context_SpSwitch_SWITCHTOHIGH, SPSwitch_ListOfContext);
}
void UpdPorFunc_SP_SWITCH_TO_HIGH(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_Select, Context_SpSwitch_SWITCHTOHIGH);
}
void HandlePreOCFunc_SP_SWITCH_TO_HIGH(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_UnSelect, Context_SpSwitch_SWITCHTOHIGH);
}
/*LOW*/
void IniOrClrScrFunc_SP_SWITCH_TO_LOW(void)
{
    SPSwitchMainTitle();
    HandleFunc_DisplayInitListOfMenu(SPSwitch_Mode(), Context_SpSwitch_SWITCHTOLOW, SPSwitch_ListOfContext);
}
void UpdPorFunc_SP_SWITCH_TO_LOW(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_Select, Context_SpSwitch_SWITCHTOLOW);
}
void HandlePreOCFunc_SP_SWITCH_TO_LOW(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_UnSelect, Context_SpSwitch_SWITCHTOLOW);
}
/*CUSTOM: */
void IniOrClrScrFunc_SP_SWITCH_TO_CUSTOM(void)
{
    SPSwitchMainTitle();
    HandleFunc_DisplayInitListOfMenu(SPSwitch_Mode(), Context_SpSwitch_SWITCHTOHIGH, SPSwitch_ListOfContext);
}
void UpdPorFunc_SP_SWITCH_TO_CUSTOM(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_Select, Context_SpSwitch_SWITCHTOCUSTOM);
}
void HandlePreOCFunc_SP_SWITCH_TO_CUSTOM(void)
{
    Handle_GeneralListMenuContext(SPSwitch_Mode(), IteStat_UnSelect, Context_SpSwitch_SWITCHTOCUSTOM);
}
