/******************************************************************************/
//File: 
//Description:
//
/*****************************************************************************/
#include "../DiveMainMenu.h"
#include "../../Main Menu/Main_Menu_TMT_SWITCH/Menu_MainMenu_TMTSwitch.h"

/*Context memdev config to DiveMainMenu_TMT_TopRightDepth_Content*/
static void DiveMainMenu_TMT_TopRightDepth_Content(char* pStrRet)
{
    /*Display current depth of TMT receive
    -> Note: HighLightTMTItem.TMTNumber: current TMT highlight*/
    if(UNITS==NVD_IMPERIAL)
    {
        sprintf(pStrRet, "   %.0f %s", fDepthFt, TxtDef_Set_DepthUnit[NVD_IMPERIAL]);
    }
    else
    {
        sprintf(pStrRet, "   %.1f %s", fDepthM, TxtDef_Set_DepthUnit[NVD_METRIC]);
    }
}
const contentDispContext_st DiveMainMenu_TMTDepth_TopRight_Ctx =
{
    &DiveMainMenu_TMT_TopRightDepth_Content,
    &Select_TxtColor,
    GUI_TA_RIGHT,
    &FontAaux_3,
    &Pos_DepthTopOnTheRight, 
};
