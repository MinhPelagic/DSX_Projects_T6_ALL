/******************************************************************************/
//File: Alarms menu.c
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms.h"

/*Initial screen handles*/
void IniOrClrScrFunc_S106_AL_AUDIBLE(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_AUDIBLEnVIBRATION, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S106_AL_AUDIBLE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_AUDIBLEnVIBRATION);
}
void HandlePreOCFunc_S106_AL_AUDIBLE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_AUDIBLEnVIBRATION);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S281_AL_TURN_END_PRESS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_TURNENDPRESS, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S281_AL_TURN_END_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_TURNENDPRESS);
}
void HandlePreOCFunc_S281_AL_TURN_END_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_TURNENDPRESS);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S288_AL_END_WOB_ICD_ALARMS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_ENDWOBICD, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S288_AL_END_WOB_ICD_ALARMS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_ENDWOBICD);
}
void HandlePreOCFunc_S288_AL_END_WOB_ICD_ALARMS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_ENDWOBICD);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S108_AL_DEPTH(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DEPTH, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S108_AL_DEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DEPTH);
}
void HandlePreOCFunc_S108_AL_DEPTH(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DEPTH);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S111_AL_DIVETIME(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DIVETIME, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S111_AL_DIVETIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DIVETIME);
}
void HandlePreOCFunc_S111_AL_DIVETIME(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DIVETIME);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S116_AL_DTR(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DTR, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S116_AL_DTR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DTR);
}
void HandlePreOCFunc_S116_AL_DTR(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DTR);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S116_AL_TANK_PRESS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_TANKPRESS, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S116_AL_TANK_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_TANKPRESS);
}
void HandlePreOCFunc_S116_AL_TANK_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_TANKPRESS);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S119_AL_CC6_PRESS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_CCPRESS, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S119_AL_CC6_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_CCPRESS);
}
void HandlePreOCFunc_S119_AL_CC6_PRESS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_CCPRESS);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S122_AL_GF_N2(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_GFN2, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S122_AL_GF_N2(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_GFN2);
}
void HandlePreOCFunc_S122_AL_GF_N2(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_GFN2);
}
/*----------------------------------------------------------------------*/
void IniOrClrScrFunc_S000_AL_DIVETIME_TTS(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_DIVETIME_TTS, SetAlarm_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S000_AL_DIVETIME_TTS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_DIVETIME_TTS);
}
void HandlePreOCFunc_S000_AL_DIVETIME_TTS(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_DIVETIME_TTS);
}
/*----------------------------------------------------------------------*/

