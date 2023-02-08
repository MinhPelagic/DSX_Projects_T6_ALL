/******************************************************************************/
//File: Alarms WOB
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_EndWobIcd.h"
#include "../ContextSetAlarmsCfg.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this

/*Context memdev config*/
const contentDispContext_st SetAlarms_EndWobIcd_WOB_Context =
{
    &SetAlarms_EndWobIcd_WOB_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Set Alarms WOB value*/
const contentDispContext_st SetAlarms_WOB_SET_Context =
{
    &EndWobIcd_WOB_SET_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Function to handle*/
void IniOrClrScrFunc_S293_ALARM_WOB_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_WOB_ALARM));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_EndWobIcd_WOB_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S293_ALARM_WOB_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_EndWobIcd_WOB_Context);
}
/*SET*/
void IniOrClrScrFunc_S294_ALARM_WOB_SET(void)
{
    /*Clear the previous portion*/
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarms_EndWobIcd_WOB_Context);
    /*Display FT/M*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_WOB_SET_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S294_ALARM_WOB_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_WOB_SET_Context);
}