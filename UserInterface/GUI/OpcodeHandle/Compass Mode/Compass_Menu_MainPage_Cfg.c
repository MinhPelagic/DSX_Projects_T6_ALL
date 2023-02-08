/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "ContextCompassMenuCfg.h"
static const listItemInMenu_ts CompassMenu_CC_Context=
{
    2,/*Number of items*/
    {
        &Context_CompassMenu_CALIBRATE,
        &Context_CompassMenu_SET_DECLIN,
    }
};

const listItemInMenu_ts* CompassMenu_ListOfContext[DIVEMODE_MAX] =
{
    &CompassMenu_CC_Context,	/*CC*/
    &CompassMenu_CC_Context,	/*OC*/
    &CompassMenu_CC_Context,	/*SM*/
    &CompassMenu_CC_Context,	/*GAUGE*/
    &CompassMenu_CC_Context,	/*GAUGE SM*/
    &CompassMenu_CC_Context,	/*BO*/
};

void CompassMenu_CALIBRATE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CALIBRATE));
}
void CompassMenu_SET_DECLIN_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SET_DECLIN));
}
void CompassMenu_SET_DECLIN_Context_Right(char* pStrRet)
{
    if(COMP_DEDLIN_DEG==0)
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OFF));
    else if(GUI_COMP_DEDLIN_DEG > 0)
        sprintf(pStrRet, "+%d EAST", COMP_DEDLIN_DEG);
    else
        sprintf(pStrRet, "%d WEST", COMP_DEDLIN_DEG);
}
