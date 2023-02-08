/******************************************************************************/
//File: Menu_DivePlanner_Handle_TimeLimitsTittleCheck
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"


void Handle_DivePlanner_TimeLimitsTittle(char* pStrRet)
{
    /*Separate in */
    switch(DIVE_MODE)
    {
    case NVD_MDCC:
        /**
        Top title:
        GAS: MM-GAS# xx/xx     SP: x.xx-x.xx      GF: xx-xx
        */
        sprintf(pStrRet, "%s:%d/%d   %s:%.2f-%.2f   %s:%d-%d",\
                GUI_LANG_GetText(TxtStr_GAS),\
                DiPla_FO2,DiPla_Fhe,\
                GUI_LANG_GetText(TxtStr_SP),\
                DiPla_SPHI,\
                DiPla_SPLO,\
                GUI_LANG_GetText(TxtStr_GF),\
                DiPla_GFLO, DiPla_GFHI);
        break;
    default:
        /**
        Top title:
        GAS: MM-GAS# xx/xx     MOD: FT/M      GF: xx-xx
        */
        if(UNITS==NVD_IMPERIAL)
        {
            sprintf(pStrRet, "%s:%d/%d   %s:%d %s   %s:%d-%d",\
                    GUI_LANG_GetText(TxtStr_GAS),\
                    DiPla_FO2,DiPla_Fhe,\
                    GUI_LANG_GetText(TxtStr_MOD),\
                    DiPla_MOD_FT,\
                    TxtDef_Set_DepthUnit[UNITS],\
                    GUI_LANG_GetText(TxtStr_GF),\
                    DiPla_GFLO, DiPla_GFHI);
        }
        else
        {
            sprintf(pStrRet, "%s:%d/%d   %s:%d %s   %s:%d-%d",\
                    GUI_LANG_GetText(TxtStr_GAS),\
                    DiPla_FO2,DiPla_Fhe,\
                    GUI_LANG_GetText(TxtStr_MOD),\
                    DiPla_MOD_M,\
                    TxtDef_Set_DepthUnit[UNITS],\
                    GUI_LANG_GetText(TxtStr_GF),\
                    DiPla_GFLO, DiPla_GFHI);
        }
        break;
    }
}