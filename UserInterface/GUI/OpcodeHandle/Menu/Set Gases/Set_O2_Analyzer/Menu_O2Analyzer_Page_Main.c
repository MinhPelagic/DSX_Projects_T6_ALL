/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "O2.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"
void Warning_O2CableSN_S462_O2ANALYZER_CALIBRATE(void)
{
    uint32_t SN, sn;
    char pStrRet[64];
    uint8_t Stage, PreStage;

    Stage = SystemStatus.O2_Analyzer_Stage;
    PreStage = SystemStatus.O2_Analyzer_PreStage;

    if( Stage != PreStage )
    {
        SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN.SerialNum;
        sn = ( ((SN&0x00F00000)>>20)*100000+((SN&0x000F0000)>>16)*10000+((SN&0x0000F000)>>12)*1000
               +((SN&0x00000F00)>>8)*100+((SN&0x000000F0)>>4)*10+(SN&0x0000000F) );

        /*Initialize screen*/
        GUI_SetColor(GUI_RED);
        /**/
        SetFont_4;
        if((SN==0x00)||(SN==0x00FFFFFF))
        {
            GUI_DispStringHCenterAt("    WARNING    ", PosX_Center, 80);
            GUI_DispStringHCenterAt("        CABLE NOT CALIBRATED        ", PosX_Center, 120);
            strcpy(pStrRet, "    O2-000000    ");
        }
        else
        {
            GUI_DispStringHCenterAt("    WARNING    ", PosX_Center, 80);
            GUI_DispStringHCenterAt("        USE ONLY WITH        ", PosX_Center, 120);
            GUI_SetColor(GUI_WHITE);
            sprintf(pStrRet, "    O2-%.6d    ", sn);
        }
        GUI_DispStringHCenterAt(pStrRet, PosX_Center, 160);

        SystemStatus.O2_Analyzer_PreStage = SystemStatus.O2_Analyzer_Stage;
    }
}
/*CALIBRATE*/
void IniOrClrScrFunc_S462_O2ANALYZER_CALIBRATE(void)
{
    GUI_Clear();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_O2_ANALYZER));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_O2Analyzer_Calibrate, O2Analyzer_ListOfContext);
    Warning_O2CableSN_S462_O2ANALYZER_CALIBRATE();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S462_O2ANALYZER_CALIBRATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_O2Analyzer_Calibrate);
}
void HandlePreOCFunc_S462_O2ANALYZER_CALIBRATE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_O2Analyzer_Calibrate);
}
/*ANALYZER*/
void IniOrClrScrFunc_S470_O2ANALYZER_ANALYZE(void)
{
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_O2_ANALYZER));
    HandleFunc_DisplayInitListOfMenu(GUI_DIVE_Mode, Context_SetGases_O2Analyzer_Analyze, O2Analyzer_ListOfContext);
    Warning_O2CableSN_S462_O2ANALYZER_CALIBRATE();
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdPorFunc_S470_O2ANALYZER_ANALYZE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_Select, Context_SetGases_O2Analyzer_Analyze);
}
void UpdOrFlasFunc_S462_O2ANALYZER_CALIBRATE(void)
{
    uint32_t SN;

    SN = MFG_Calib.O2_Analyzer.O2_Analyzer_SN.SerialNum;
    if((SN!=0x00)&&(SN!=0x00FFFFFF))
        Warning_O2CableSN_S462_O2ANALYZER_CALIBRATE();
}
void HandlePreOCFunc_S470_O2ANALYZER_ANALYZE(void)
{
    Handle_GeneralListMenuContext(GUI_DIVE_Mode, IteStat_UnSelect, Context_SetGases_O2Analyzer_Analyze);
}
