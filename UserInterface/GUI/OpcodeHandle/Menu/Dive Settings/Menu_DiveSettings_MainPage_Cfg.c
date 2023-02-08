/******************************************************************************/
//File: Dive_Settings.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DiveSettings_DataMap.h"
#include "ContextDiveSettingsCfg.h"
#include "Menu_DiveSettings.h"

/*DIVE SETTINGS handle context*/
extern const listItemInMenu_ts* DiveSettings_ListOfContext[DIVEMODE_MAX];

const TxtStr_Name_e TxtDef_Set_Conservatism[Conservatism_MAX]=
{
    TxtStr_TEC,
    TxtStr_LOW,
    TxtStr_MEDIUM,
    TxtStr_HIGH,
    TxtStr_SPORT,
};
/*Handle DIVE SETTINGS context*/
/*DIVE MODE Context*/
void DiveSett_DIVEMODE_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_MODE));
}
void DiveSett_DIVEMODE_Context_Right(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtDef_DSX_MainMode[GUI_DIVE_Mode]));
}
/*BAILOUTPO2 Context*/
void DiveSett_BAILOUTPO2_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_BAILOUT_PO2_LIMITS));
}
/*PO2LIMITS Context*/
void DiveSett_PO2LIMITS_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_PO2_LIMITS));
}
/*CONSERVATISM context*/
void DiveSett_CONSERVATISM_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CONSERVATISM));
}
void DiveSett_CONSERVATISM_Context_Right(char* pStrRet)
{
    if(CONSER_SETPOINTS==CONSV_TEC)
    {
        sprintf(pStrRet, "%d-%d", OONSRV_TecGF_Lo,OONSRV_TecGF_Hi);
    }
    else
        strcpy(pStrRet, GUI_LANG_GetText(TxtDef_Set_Conservatism[CONSRV_SPORT_STAT]));
}
/*SAFETY STOP context*/
void DiveSett_SAFETYSTOP_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_SAFETY_STOP));
}
void DiveSett_SAFETYSTOP_Context_Right(char* pStrRet)
{
    if(SAFETYSTOP_STAT == NVD_OFF)
    {
        strcpy(pStrRet, GUI_LANG_GetText(TxtStr_OFF));
    }
    else
    {
        uint16_t SSDepth_u16 = 0u;
        if(Imperial)
        {
            SSDepth_u16 = SafetyStop_DEPTH_FT;
        }
        else
        {
            SSDepth_u16 = SafetyStop_DEPTH_M;
        }
        sprintf(pStrRet, "%d %s - %d %s", SSDepth_u16, TxtDef_Set_DepthUnit[UNITS], SafetyStop_TIME_Mins, GUI_LANG_GetText(TxtStr_MIN));
    }
}
/*LAST STOP DEPTH context*/
void DiveSett_LASTSTOPDEPTH_Context_Left(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_LAST_STOP_DEPTH));
}
void DiveSett_LASTSTOPDEPTH_Context_Right(char* pStrRet)
{
    if(Imperial)
    {
        sprintf(pStrRet, "%d FT", LastStop_DEPTH_FT);
    }
    else
    {
        sprintf(pStrRet, "%d M", LastStop_DEPTH_M);
    }

}
