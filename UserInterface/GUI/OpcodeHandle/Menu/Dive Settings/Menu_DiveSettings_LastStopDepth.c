/******************************************************************************/
//File: Last stop depth
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
extern const contentDispContext_st SetSP_UnitSet_Ctx;
/*Last stop depth*/
static void LastStopDepth_Value_Context(char* pStrRet)
{
    /**/
    if(Imperial)
    {
        sprintf(pStrRet, "  %d", GUI_LastStopFt);
    }
    else
    {
        sprintf(pStrRet, "  %d", GUI_LastStopM);
    }
};
/*Context memdev config*/
const contentDispContext_st DiveSett_LastStopDepth_Context =
{
    &LastStopDepth_Value_Context,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_6,
    &Pos_SetLastStopDepth_Value,
};

void IniOrClrScrFunc_LASTSTOPDEPTH_SETPOINTS(void)
{
    /*Clear all the previous content*/
    ClearUnusedInList(0);
    /*Display sub title text*/
    DisplayText_Setting_Title(GUI_LANG_GetText(TxtStr_LAST_STOP_DEPTH));
    HandleDisplayTextWithMemdev(IteStat_Select, SetSP_UnitSet_Ctx);
    /**/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSett_LastStopDepth_Context);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_LASTSTOPDEPTH_SETPOINTS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, DiveSett_LastStopDepth_Context);
}