/******************************************************************************/
//File: SET MENU -> SET GASES
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

extern const listItemInMenu_ts* O2Analyzer_ListOfContext[DIVEMODE_MAX];
extern const contentDispContext_st O2Analyzer_Calibarte_Line_0_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_Line_1_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_Value_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line00_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadyCalib_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadingO2Cell_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadingO2Cell_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_ReadingO2Cell_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2AnalyzerFound_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2CellFound_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2CellFound_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_NoO2CellFound_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line01_AIR_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_O2CellDepleted_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line00_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_CalibrationReport_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_Complete_Line01_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_Complete_Line02_Ctx;
extern const contentDispContext_st O2Analyzer_Calibarte_Complete_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_1_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_CalibrationWarning_Line_2_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_ReadyForAnalyzing_Line03_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_Analyzing_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_AnalyResConfirm_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_AnalyFO2Value_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_ConfirmText_Ctx;
extern const contentDispContext_st O2Analyzer_Analyzer_AnalyConfirmStatus_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_Status_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_Line_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_Line_1_Ctx;
extern const contentDispContext_st O2Analyzer_GasList_Status_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_SelectGasList_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_SelectGasList_1_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_1_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmAsssignGas_Status_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_1_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_AssignedComplete_2_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_0_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_1_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_2_Ctx;
extern const contentDispContext_st O2Analyzer_Analyze_ConfirmProceed_Line_3_Ctx;
extern const contentDispContext_st Set_SetFHe_FO2_Ctx;
extern const contentDispContext_st Set_SetFHe_FHe_Ctx;
