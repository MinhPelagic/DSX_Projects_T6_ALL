/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"

/*Set point*/
void IniOrClrScrFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Tittle content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Line_0_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Line_1_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Value_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Calibarte_Value_Ctx);
}
/*Ready Calibartion*/
void IniOrClrScrFunc_S464_O2ANALYZER_CALIBRATE_READY(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line00_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadyCalib_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*Reading O2 voltage*/
void IniOrClrScrFunc_S465_O2ANALYZER_CALIBRATE_READ_O2(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadingO2Cell_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadingO2Cell_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_ReadingO2Cell_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*No O2 cell found*/
void IniOrClrScrFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2(void)
{
    // HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Calibarte_NoO2CellFound_Line01_Ctx);
}

/*No O2 Analyzer connected*/
void IniOrClrScrFunc_S466_O2ANALYZER_CALIBRATE_NO_ANALYZER_O2(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2CellFound_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*No O2 Analyzer Connected*/
void IniOrClrScrFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2AnalyzerFound_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2AnalyzerFound_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_NoO2AnalyzerFound_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER(void)
{
    // HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Calibarte_NoO2CellFound_Line01_Ctx);
}
/*O2 Cell depleted*/
void IniOrClrScrFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Calibarte_O2CellDepleted_Line01_Ctx);

    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_O2CellDepleted_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_O2CellDepleted_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
void UpdOrFlasFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP(void)
{
    HandleDisplayTextWithMemdev(IteStat_Flashing, O2Analyzer_Calibarte_O2CellDepleted_Line01_Ctx);
}
/*O2 Cell Calibration Report*/
void IniOrClrScrFunc_S468_O2ANALYZER_CALIBRATE_CELL_V(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_CalibrationReport_Line00_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_CalibrationReport_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_CalibrationReport_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_CalibrationReport_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
/*O2 cell calibration complete*/
void IniOrClrScrFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_CALIBRATE));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Complete_Line01_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Complete_Line02_Ctx);
    HandleDisplayTextWithMemdev(IteStat_Select, O2Analyzer_Calibarte_Complete_Line03_Ctx);
    Display_Icon_Buttons(IconBottDisp_UpBackUpHomeSelect);
}
