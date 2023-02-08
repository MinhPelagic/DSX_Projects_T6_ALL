/******************************************************************************/
//File: Alarms END WOB ICD
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_EndWobIcd.h"

/*END*/
void IniOrClrScrFunc_S289_ALARM_END(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_END_WOB_ICD_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_EndWobIcd_END, SetEndWobIcd_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S289_ALARM_END(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_EndWobIcd_END);
}
void HandlePreOCFunc_S289_ALARM_END(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_EndWobIcd_END);
}
/*WOB*/
void IniOrClrScrFunc_S292_ALARM_WOB(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_END_WOB_ICD_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_EndWobIcd_WOB, SetEndWobIcd_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S292_ALARM_WOB(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_EndWobIcd_WOB);
}
void HandlePreOCFunc_S292_ALARM_WOB(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_EndWobIcd_WOB);
}
/*ICD*/
void IniOrClrScrFunc_S295_ALARM_ICD(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_END_WOB_ICD_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_EndWobIcd_ICD, SetEndWobIcd_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S295_ALARM_ICD(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_EndWobIcd_ICD);
}
void HandlePreOCFunc_S295_ALARM_ICD(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_EndWobIcd_ICD);
}
/*O2 Narcotic*/
void IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC(void)
{
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_END_WOB_ICD_ALARMS));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetAlarms_EndWobIcd_O2NARCOTIC, SetEndWobIcd_ListOfContext);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S297_ALARM_O2_NARCOTIC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetAlarms_EndWobIcd_O2NARCOTIC);
}
void HandlePreOCFunc_S297_ALARM_O2_NARCOTIC(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetAlarms_EndWobIcd_O2NARCOTIC);
}
