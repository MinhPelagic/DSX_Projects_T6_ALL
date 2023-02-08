/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_SetGase_DataMap.h"
#include "Menu_SetGases.h"
#include "ContextSetGasesCfg.h"

/*Context memdev config to SetGases_01*/
static void SetGases_SetFHe_01(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_01));
}
/*Context memdev config to SetGases_02*/
static void SetGases_SetFHe_02(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_02));
}
/*Context memdev config to SetGases_03*/
static void SetGases_SetFHe_03(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_03));
}
/*Context memdev config to SetGases_04*/
static void SetGases_SetFHe_04(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_04));
}
/*Context memdev config to SetGases_05*/
static void SetGases_SetFHe_05(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_05));
}
/*Context memdev config to SetGases_06*/
static void SetGases_SetFHe_06(char* pStrRet)
{
    sprintf(pStrRet, " %.2d ", SetGasGetFHe(SetGASES_Index_06));
}
const contentDispContext_st Set_SetGases_SetFHe_01_Ctx =
{
    &SetGases_SetFHe_01,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
const contentDispContext_st Set_SetGases_SetFHe_02_Ctx =
{
    &SetGases_SetFHe_02,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
const contentDispContext_st Set_SetGases_SetFHe_03_Ctx =
{
    &SetGases_SetFHe_03,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
const contentDispContext_st Set_SetGases_SetFHe_04_Ctx =
{
    &SetGases_SetFHe_04,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
const contentDispContext_st Set_SetGases_SetFHe_05_Ctx =
{
    &SetGases_SetFHe_05,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};
const contentDispContext_st Set_SetGases_SetFHe_06_Ctx =
{
    &SetGases_SetFHe_06,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetGas_Fhe,
};