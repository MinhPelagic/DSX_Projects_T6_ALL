/******************************************************************************/
//File: Alarms END
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_EndWobIcd.h"
#include "../ContextSetAlarmsCfg.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this

/*Context memdev config*/
const contentDispContext_st SetAlarms_EndWobIcd_END_Context =
{
    &SetAlarms_EndWobIcd_END_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Set Alarms END value*/
const contentDispContext_st SetAlarms_END_SET_Context =
{
    &EndWobIcd_END_SET_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};
/*Function to handle*/
void IniOrClrScrFunc_S290_ALARM_END_STAT(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_END_ALARM));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_EndWobIcd_END_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S290_ALARM_END_STAT(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_EndWobIcd_END_Context);
}
/*SET*/
void IniOrClrScrFunc_S291_ALARM_END_SET(void)
{
    /*Clear the previous portion*/
    HandleDisplayTextWithMemdev(IteStat_Clear, SetAlarms_EndWobIcd_END_Context);
    /*Display FT/M*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /*Display main value*/
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_END_SET_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S291_ALARM_END_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_END_SET_Context);
}