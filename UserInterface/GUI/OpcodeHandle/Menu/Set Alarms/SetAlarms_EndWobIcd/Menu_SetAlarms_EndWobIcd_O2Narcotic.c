/******************************************************************************/
//File: Alarms O2 NARCOTIC
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetAlarms_EndWobIcd.h"
#include "../ContextSetAlarmsCfg.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx; //Reuse this

/*Context memdev config*/
const contentDispContext_st SetAlarms_EndWobIcd_O2NARCOTIC_Context =
{
    &SetAlarms_EndWobIcd_O2NARCOTIC_Context_Right,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Re use this
};
/*Function to handle*/
void IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC_SET(void)
{
    /*Clear all contents*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_O2_NARCOTIC));
    HandleDisplayTextWithMemdev(IteStat_Select, SetAlarms_EndWobIcd_O2NARCOTIC_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S297_ALARM_O2_NARCOTIC_SET(void)
{
    HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, SetAlarms_EndWobIcd_O2NARCOTIC_Context);
}