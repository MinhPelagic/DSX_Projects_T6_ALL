/******************************************************************************/
//File: Alarms ICD
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_EndWobIcd.h"
#include "../ContextSetAlarmsCfg.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this

/*Context memdev config*/
const contentDispContext_st SetAlarms_EndWobIcd_ICD_Context =
{
    &SetAlarms_EndWobIcd_ICD_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Function to handle*/
void IniOrClrScrFunc_S296_ALARM_ICD_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_ICD_ALARM));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_EndWobIcd_ICD_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S296_ALARM_ICD_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, SetAlarms_EndWobIcd_ICD_Context);
}