/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

/*Analyzer warning*/
void IniOrClrScrFunc_S471_ANALYZE_CALIB_WARINING(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_CalibrationWarning_Line_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_CalibrationWarning_Line_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_CalibrationWarning_Line_2_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*Ready for Analyzing*/
void IniOrClrScrFunc_S472_ANALYZE_READY(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line00_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_ReadyForAnalyzing_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*Analyzing*/
void IniOrClrScrFunc_S473_ANALYZE_ANALYZING(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_Analyzing_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S473_ANALYZE_ANALYZING(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Analyzer_Analyzing_Ctx);
}
/*Analyze confirmation*/
void IniOrClrScrFunc_S474_ANALYZE_CONFIRM(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_AnalyResConfirm_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_AnalyFO2Value_Ctx);
    /*Text "CONFIRM"*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_ConfirmText_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyzer_AnalyConfirmStatus_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S474_ANALYZE_CONFIRM(void)
{
    /*Flashing stauts ON/OFF*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Analyzer_AnalyConfirmStatus_Ctx);
}
/*Assigned FO2 confirm list settings S4755*/
void IniOrClrScrFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM(void)
{
    ClearUnusedInList(0);
    ClearWholeScreen();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_Line_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_Line_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_Status_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Analyze_Status_Ctx);
}
/*S476_ANALYZE_SELECT_GAS_LIST_MODE*/
void IniOrClrScrFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_SelectGasList_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_SelectGasList_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_GasList_Status_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_GasList_Status_Ctx);
}
/*S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS*/
void IniOrClrScrFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmAsssignGas_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmAsssignGas_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmAsssignGas_Status_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Analyze_ConfirmAsssignGas_Status_Ctx);
}
/*S479_ANALYZE_ASSIGN_COMPLETE*/
void IniOrClrScrFunc_S479_ANALYZE_ASSIGN_COMPLETE(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_AssignedComplete_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_AssignedComplete_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_AssignedComplete_2_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*S475A_ANALYZE_SET_FHE*/
void IniOrClrScrFunc_S475A_ANALYZE_SET_FHE(void)
{
    displaysubInitialSetGasPage();
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_ANALYZE));
    DisplayText_Setting_Title("SET FHE");
    /*Display FO2 & FHe value*/
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetFHe_FO2_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, Set_SetFHe_FHe_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
}
void UpdOrFlasFunc_S475A_ANALYZE_SET_FHE(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, Set_SetFHe_FHe_Ctx);
}
/*S486*/
void IniOrClrScrFunc_S486_ANALYZE_SET_BOTH_OCL_OCR(void)
{
    GUI_Clear();
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmProceed_Line_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmProceed_Line_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmProceed_Line_2_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Analyze_ConfirmProceed_Line_3_Ctx);
    Display_Icon_Buttons(IconBottDisp_CancelNext);
}
