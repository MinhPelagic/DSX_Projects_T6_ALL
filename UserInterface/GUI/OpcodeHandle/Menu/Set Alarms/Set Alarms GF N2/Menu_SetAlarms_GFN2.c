/******************************************************************************/
//File: Alarms GF N2
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextSetAlarmsCfg.h"
#include "Menu_SetAlarms_GFN2.h"

void IniOrClrScrFunc_ALARM_GFN2_GF_STAT(void)
{
    /*Clear all screen*/
    ClearUnusedInList(0);
    /*Display GF-N2 text*/
    HandleDispTextGeneral(GF_Text_Context);
    HandleDispTextGeneral(N2_Text_Context);
    /*Display GF, N2 Value*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, N2_Status_Context);
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, GF_Status_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_ALARM_GFN2_GF_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GF_Status_Context);
}
void UpdOrFlasFunc_ALARM_GFN2_GF_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GF_Value_Context);
}
void IniOrClrScrFunc_ALARM_GFN2_GF_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GF_Value_Context);
}
/*-------------------------------------------------------------------*/
void IniOrClrScrFunc_ALARM_GFN2_N2_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, N2_Value_Context);
}
void UpdOrFlasFunc_ALARM_GFN2_N2_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, N2_Value_Context);
}
void IniOrClrScrFunc_ALARM_GFN2_N2_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, N2_Status_Context);
}
void UpdOrFlasFunc_ALARM_GFN2_N2_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, N2_Status_Context); //Should flashing right away
}
void UpdPorFunc_ALARM_GFN2_GF_STAT(void)
{
    /*When jump from N2 -> GF : Redraw N2 status*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, N2_Status_Context);
}
void UpdPorFunc_ALARM_GFN2_N2_STAT(void)
{
    /*When jump from GF -> N2 : Redraw GF status*/
    HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, GF_Status_Context);
}