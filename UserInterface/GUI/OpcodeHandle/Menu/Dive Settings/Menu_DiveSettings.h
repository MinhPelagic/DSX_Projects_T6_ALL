/******************************************************************************/
//File: Dive_Settings.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"

/*DIVE SETTINGS handle context*/
extern const listItemInMenu_ts* DiveSettings_ListOfContext[];
extern const menuItemContext_ts* p_Conserv_TEC_Contextt[];
extern const menuItemContext_ts* pFunc_Context_PO2Limit[];
extern const contentDispContext_st Set_BaiOutPO2_DECO_Ctx;
extern const contentDispContext_st Set_BaiOutPO2_MAX_Ctx;
extern const contentDispContext_st Set_BaiOutPO2_MIN_Ctx;
extern const contentDispContext_st Conservative_SPORT_Bottom_Context;
extern const contentDispContext_st Set_DiveSett_Consrv_STAT_Ctx;
extern const contentDispContext_st Set_DiveSett_ConsrvSport_STAT_Ctx;
extern const contentDispContext_st Set_DiveSett_Consrv_TEC_High_Ctx;
extern const contentDispContext_st Set_DiveSett_Consrv_TEC_Low_Ctx;
extern const contentDispContext_st DiveSett_SafetyStopTime_Context;
extern const contentDispContext_st SetSS_UNITSET_Context;
extern const contentDispContext_st DiveSett_SafetyStopDepth_Context;
extern const contentDispContext_st Set_DiveSett_SafetyStop_STAT_Ctx;
extern const contentDispContext_st Set_DiveSett_SetDiveMode_Ctx;
extern const contentDispContext_st SetSS_MIN_Context;
extern const TxtStr_Name_e TxtDef_Set_Conservatism[];


/*Setting DIVE SETTING*/
enum Conservatism_e {
    Conservatism_TEC = 0x00,
    Conservatism_LOW,
    Conservatism_MEDIUM,
    Conservatism_HIGH,
    Conservatism_SPORT,
    Conservatism_MAX,
};
/*Setting BAILOUT PO2 LIMITS*/
enum BailOutPO2Limits_e
{
    BailOutPO2Limits_MINPO2 = 0x00,
    BailOutPO2Limits_MAXPO2,
    BailOutPO2Limits_DECOPO2,
    BailOutPO2Limits_MAX,
};
/*TEC*/
enum Conservatism_GF_e
{
    Conservatism_GF_LOW = 0x00,
    Conservatism_GF_HIGH,
    Conservatism_GF_MAX,
};
