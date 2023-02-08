/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
#include "ContextCompassMenuCfg.h"
void CompassMenu_SetDecline_STAT(char* pStrRet)
{
    if(GUI_COMP_DEDLIN_DEG==0)
        strcpy(pStrRet, "        OFF        ");
    else if(GUI_COMP_DEDLIN_DEG > 0)
        sprintf(pStrRet, "   +%d EAST   ", GUI_COMP_DEDLIN_DEG);
    else
        sprintf(pStrRet, "   %d WEST   ", GUI_COMP_DEDLIN_DEG);
}
/*Context memdev config to Set Decline*/
const contentDispContext_st CompassMenu_SetDecline_STAT_Ctx =
{
    &CompassMenu_SetDecline_STAT,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};