/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSetSPCfg.h"
#include "Menu_SetSP.h"

/*SP Setting*/
static const listItemInMenu_ts SetSP_CC_Context=
{
    5,/*Number of items*/
    {
        &Context_SetSP_HIGH_SP,
        &Context_SetSP_LOW_SP,
        &Context_SetSP_CUSTOM_SP,
        &Context_SetSP_AUTO_HIGH,
        &Context_SetSP_AUTO_LOW,
    }
};
const listItemInMenu_ts* SetSP_ListOfContext[DIVEMODE_MAX] =
{
    &SetSP_CC_Context,
    &SetSP_CC_Context,
    &SetSP_CC_Context,
    &SetSP_CC_Context,
    &SetSP_CC_Context,
    &SetSP_CC_Context, /*BO mode*/
};
/*SET SP SP HIGH context*/
void SetSP_HIGH_SP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_HIGH_SP));
}
void SetSP_HIGH_SP_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%.2f", ((float)SET_SP_HIGH) / 100.0);
}
/*SET SP SP LOW context*/
void SetSP_LOW_SP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LOW_SP));
}
void SetSP_LOW_SP_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%.2f", ((float)SET_SP_LOW) / 100.0);
}
/*SET SP SP CUSTOM context*/
void SetSP_CUSTOM_SP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CUSTOM_SP));
}
void SetSP_CUSTOM_SP_Context_Right(char* pStrRet)
{
    sprintf(pStrRet, "%.2f", ((float)SET_SP_CUSTOM) / 100.0f);
}
void SetSP_CUSTOM_SP_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_CUSTOM]));
}
/*SET SP SP AUTO HIGH context*/
void SetSP_AUTO_HIGH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUTO_HIGH));
}
void SetSP_AUTO_HIGH_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d FT", SET_SP_AUTO_FT_HIGH);
    else
        sprintf(pStrRet, "%d M", SET_SP_AUTO_M_HIGH);
}
void SetSP_AUTO_HIGH_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_AUTO_HIGH]));
}
/*SET SP SP AUTO LOW context*/
void SetSP_AUTO_LOW_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_AUTO_LOW));
}
void SetSP_AUTO_LOW_Context_Right(char* pStrRet)
{
    if(Imperial)
        sprintf(pStrRet, "%d FT", SET_SP_AUTO_FT_LOW);
    else
        sprintf(pStrRet, "%d M", SET_SP_AUTO_M_LOW);
}
void SetSP_AUTO_LOW_Context_Center(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_AUTO_LOW]));
}
void SetSP_AUTO_HIGH_STAT_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SET_SP_MORFLG_AUTO_HIGH]));
}