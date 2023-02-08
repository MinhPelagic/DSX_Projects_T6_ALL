/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

/*Context memdev config to SetGases_01*/
static void SetGases_01_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_01)]));
}
/*Context memdev config to SetGases_02*/
static void SetGases_02_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_02)]));
}
/*Context memdev config to SetGases_03*/
static void SetGases_03_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_03)]));
}
/*Context memdev config to SetGases_04*/
static void SetGases_04_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_04)]));
}
/*Context memdev config to SetGases_05*/
static void SetGases_05_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_05)]));
}
/*Context memdev config to SetGases_06*/
static void SetGases_06_STAT(char* pStrRet)
{
    sprintf(pStrRet, " %s ",GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(SetGASES_Index_06)]));
}
const contentDispContext_st Set_SetGases_01_Ctx =
{
    &SetGases_01_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
const contentDispContext_st Set_SetGases_02_Ctx =
{
    &SetGases_02_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
const contentDispContext_st Set_SetGases_03_Ctx =
{
    &SetGases_03_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
const contentDispContext_st Set_SetGases_04_Ctx =
{
    &SetGases_04_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
const contentDispContext_st Set_SetGases_05_Ctx =
{
    &SetGases_05_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};
const contentDispContext_st Set_SetGases_06_Ctx =
{
    &SetGases_06_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};