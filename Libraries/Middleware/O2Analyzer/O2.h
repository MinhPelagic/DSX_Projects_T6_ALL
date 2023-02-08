#ifndef __O2_H__
#define __O2_H__

#define SEALEVEL_PRESSURE_MBAR          1013.25f
#define CURRENT_PRESSURE_MBAR           fSurfP_mbar     // fSurfP_mbar + 0.1*MFG_Calib.LP_Sensor_Offset_ubarx10
void O2_init(void);
float O2_GetPercentage(void);
void O2_Analyzer_Manager(void);
uint8_t O2_Test(void);
float Find_Primary_Cell_mV(float);
float O2_AmbientPressureCompFactor(void);
float Find_O2_Pct_Analyze(float, float, float);
float Find_USER_O2_Pct_Analyze(float, float, float, float);
float ADC_Sample_Avg(float, uint8_t);
void O2_LineFitting(void);

extern float    O2_Analyzer_Volt;
extern float    O2_Analyzer_Pct;
extern float    O2_Cell_mV;
extern uint16_t O2_Cell_mV_Of_Set_FO2;
extern float O2_Primary_V_ZeroOffset;
extern float O2_ADC_V_ZeroOffset;
extern float O2_ADC_V_ZeroSlope;
extern float O2_ADC_V_Calib;
extern float O2_ADC_V_Analyze1;
extern float O2_ADC_V_Analyze2;
extern float O2_ADC_V_O2CellCalib;
extern float O2_ADC_V_O2CellAnalyze;

extern float O2_PCT_Calib;
extern float O2_PCT_Analyze1;
extern float O2_PCT_Analyze2;
extern float O2_PCT_O2CellCalib;
extern float O2_PCT_O2CellAnalyze;

extern uint16_t ADC_mV_ZeroOffset;      // Collect mV of ZeroOffset and send it to EEPROM and BLE Comm
extern uint16_t ADC_mV_Calib;           // Collect mV of FO2 = 20.9% and send it to EEPROM and BLE Comm
extern uint16_t ADC_mV_Analyze1;        // Collect mV of FO2 = 93.9% and send it to EEPROM and BLE Comm
extern uint16_t ADC_mV_Analyze2;        // Collect mV of FO2 = 93.9% and send it to EEPROM and BLE Comm
extern uint16_t ADC_mV_O2CellCalib;     // Collect mV of User O2 Cell Calibration equivelent mV 
extern uint16_t ADC_mV_O2CellAnalyze;   // Collect mV of User O2 Cell Analyze equivelent mV 

extern uint16_t ADC_FO2x10_Calib;       // Collect FO2 = ~20.9% data and send it to EEPROM and BLE Comm
extern uint16_t ADC_FO2x10_Analyze1;    // Collect FO2 = ~93.9% data and send it to EEPROM and BLE Comm
extern uint16_t ADC_FO2x10_Analyze2;    // Collect FO2 = ~93.9% data and send it to EEPROM and BLE Comm

extern uint8_t Compensated_Uint8_O2_Pct;       // the calculated Pct in uint8_t after compensation of altitude pressure and depleted factor
//extern float Compensated_Tank_O2_Pct;          // the calculated Pct after compensation of altitude pressure and depleted factor

extern uint8_t GUI_O2_AnalyzerFO2Set;
extern uint8_t GUI_O2_AnalyzerFHeSet;

typedef enum
{
    O2_ANALYZER_OFF = 0x00,
    O2_ANALYZER_INIT,
    O2_ANALYZER_INIT_DONE,
    O2_ANALYZER_WE1,
    O2_ANALYZER_WE1_DONE,
    O2_ANALYZER_WE2,
    O2_ANALYZER_WE2_DONE,
    O2_ANALYZER_WE3,
    O2_ANALYZER_WE3_DONE,
    O2_ANALYZER_FO2_CHECK,
    O2_ANALYZER_FO2_CHECK_DONE,
    O2_ANALYZER_CELL_CALIBRATION,
    O2_ANALYZER_CELL_ANALYZE,
    O2_ANALYZER_MAX,
}O2_ANALYZER_Stages_t;
#endif
