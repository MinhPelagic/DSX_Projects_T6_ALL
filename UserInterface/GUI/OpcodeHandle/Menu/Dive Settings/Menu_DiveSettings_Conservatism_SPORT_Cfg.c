/******************************************************************************/
//File: Menu_DiveSettings_PO2Limit.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

extern const TxtStr_Name_e TxtDef_Set_Conservatism[];
/*This was fixed the data in order to user easier understand*/

/*SETCONSERV TEC SPORT context*/
void DiveSett_SETCONSERV_Value_Context(char* pStrRet)
{
    if(GUI_CONSV_Switch == CONSV_TEC)
    {
        sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDef_Set_Conservatism[Conservatism_TEC]));
    }
    else
    {
        sprintf(pStrRet, "  %s  ", GUI_LANG_GetText(TxtDef_Set_Conservatism[Conservatism_SPORT]));
    }
}
/*SETCONSERV SPORT context*/
void SETCONSERV_SPORT_Context(char* pStrRet)
{
    sprintf(pStrRet, "    %s    ", GUI_LANG_GetText(TxtDef_Set_Conservatism[CONSRV_SPORT_STAT]));
}
/*Go to set Conservative SPORT*/
/*Local context*/
static void Conservative_SPORT_Bottom_Value_Context(char* pStrRet)
{
    /*Hanlde content->Display*/
    if(CONSV_SPORT_HI_MED_LO_SET==CONSV_SPORT_LOW)
        sprintf(pStrRet, "%s: 90 - %s: 90", GUI_LANG_GetText(TxtStr_GF_LOW), GUI_LANG_GetText(TxtStr_GF_HIGH));
    else if(CONSV_SPORT_HI_MED_LO_SET==CONSV_SPORT_MED)
        sprintf(pStrRet, "%s: 35 - %s: 80", GUI_LANG_GetText(TxtStr_GF_LOW), GUI_LANG_GetText(TxtStr_GF_HIGH));
    else
        sprintf(pStrRet, "%s: 30 - %s: 70", GUI_LANG_GetText(TxtStr_GF_LOW), GUI_LANG_GetText(TxtStr_GF_HIGH));
}
/*Context memdev config*/
const contentDispContext_st Conservative_SPORT_Bottom_Context =
{
    &Conservative_SPORT_Bottom_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_DiveSett_Conservatism_Sport_BottomContent,
};
/*Context memdev config to DiveSett_Consrv_STAT*/
const contentDispContext_st Set_DiveSett_Consrv_STAT_Ctx =
{
    &DiveSett_SETCONSERV_Value_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
/*Context memdev config to DiveSett_ConsrvSport_STAT*/
const contentDispContext_st Set_DiveSett_ConsrvSport_STAT_Ctx =
{
    &SETCONSERV_SPORT_Context,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};