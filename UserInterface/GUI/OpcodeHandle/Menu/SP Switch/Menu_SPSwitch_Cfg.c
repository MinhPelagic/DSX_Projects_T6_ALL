/******************************************************************************/
//File: SP Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSPSwitchCfg.h"
#include "Menu_SPSwitch.h"

/*Handle SP switch context*/
static const listItemInMenu_ts SPSwitch_LOW_CUSTOM=
{
    2,/*Number of items*/
    {
        &Context_SpSwitch_SWITCHTOLOW,
        &Context_SpSwitch_SWITCHTOCUSTOM,
    }
};
static const listItemInMenu_ts SPSwitch_HIGH_LOW=
{
    2,/*Number of items*/
    {
        &Context_SpSwitch_SWITCHTOHIGH,
        &Context_SpSwitch_SWITCHTOLOW,
    }
};
static const listItemInMenu_ts SPSwitch_HIGH_CUSTOM=
{
    2,/*Number of items*/
    {
        &Context_SpSwitch_SWITCHTOHIGH,
        &Context_SpSwitch_SWITCHTOCUSTOM,
    }
};
static const listItemInMenu_ts SPSwitch_HIGH_ONLY=
{
    1,/*Number of items*/
    {
        &Context_SpSwitch_SWITCHTOHIGH,
    }
};
static const listItemInMenu_ts SPSwitch_LOW_ONLY=
{
    1,/*Number of items*/
    {
        &Context_SpSwitch_SWITCHTOLOW,
    }
};

const listItemInMenu_ts* SPSwitch_ListOfContext[SPSwitchMode_MAX] =
{
    &SPSwitch_LOW_CUSTOM,
    &SPSwitch_HIGH_CUSTOM,
    &SPSwitch_HIGH_LOW,
    &SPSwitch_HIGH_ONLY,
    &SPSwitch_LOW_ONLY,
};

unsigned char SPSwitch_Mode(void)
{
    unsigned char StatusRet = SPSwitchMode_HIGH_LOW;
    /*When Custom Switch is OFF*/
    if(GUI_SP_CustomSwitch == NVD_OFF)
    {
        if(GUI_SP_Switch == LOW_SP)
        {
            StatusRet = SPSwitchMode_HIGH_ONLY;
        }
        else if(GUI_SP_Switch == HIGH_SP)
        {
            StatusRet = SPSwitchMode_LOW_ONLY;
        }
        else
        {
            StatusRet = SPSwitchMode_HIGH_LOW; /*When Custom is OFF -> Either HIGH/LOW enable -> No display anything?*/
        }
    }
    /*When SP Custom is ON*/
    else
    {
        if(GUI_SP_Switch == LOW_SP)
        {
            StatusRet = SPSwitchMode_HIGH_CUSTOM;
        }
        else if(GUI_SP_Switch == HIGH_SP)
        {
            StatusRet = SPSwitchMode_LOW_CUSTOM;
        }
        else
        {
            StatusRet = SPSwitchMode_HIGH_LOW; /*When Custom is ON -> Either HIGH/LOW enable -> Display HIGH LOW*/
        }
    }
    return StatusRet;
};
/*Context handle*/
void SpSwitch_SWITCHTOHIGH_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "%s  %.2f", GUI_LANG_GetText(TxtStr_SWITCH_TO_HIGH), SP_SWITCH_SP_HIGH_VAL);
}
void SpSwitch_SWITCHTOLOW_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "%s  %.2f", GUI_LANG_GetText(TxtStr_SWITCH_TO_LOW), SP_SWITCH_SP_LOW_VAL);
}
void SpSwitch_SWITCHTOCUSTOM_Context_Left(char* pStrRet)
{
    sprintf(pStrRet, "%s  %.2f", GUI_LANG_GetText(TxtStr_SWITCH_TO_CUSTOM), SP_SWITCH_SP_CUSTOM_VAL);
}