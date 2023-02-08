#ifndef _MENU_GAS_SWITCH
#define _MENU_GAS_SWITCH
/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "ContextGasSwitchCfg.h"
#define  CURRGAS                    (CURRENT_TANK_NUM)          //1~6   //Current gas value
#define  CURRGAS_POS                (CURRGAS - 1)               //0~5   //The Location of Current Gas NOT TO DISPLAY at Menu 

/*--------- GAS SWITCH MENU context handle-----------------------------------------------------------*/
/*GAS SWITCH
GAS 1, 2, 3, 4, 5, Gas 6 is default ON not in list -> Only have 4 gas because not list current in-use gas
If current gas incontrol is 1, then the list of switch gases is: 2,3,4,5. Gas 6 will automatic switch.
If current gas incontrol is 2, then the list of switch gases is: 1,3,4,5. The current gas will not be in the list.
And so on...
*/
enum gasSwitchNum
{
    GasSwitchNum_01 = 0x00,
    GasSwitchNum_02,
    GasSwitchNum_03,
    GasSwitchNum_04,
    GasSwitchNum_05,
    GasSwitchNum_06,
    GasSwitchNum_MAX,
};
/*Maximum display in CC mode = GasSwitchNum_MAX - 1 */
enum gasSwitchDispOrder
{
    posDispGasSwitch_1,
    posDispGasSwitch_2,
    posDispGasSwitch_3,
    posDispGasSwitch_4,
    posDispGasSwitch_5,
    posDispGasSwitch_MAX,
};
/*
Struct to store the position of switch gas in display
Ex: When current gas is 2 -> Handle Gas 1 should be
    -> Current pos display  1
    -> before is            5
    -> after is             3
*/
typedef struct
{
    /*Position of gas switch base on current gas Selected*/
    unsigned char posDisp;
    /*The value before in list of Gas Selected*/
    DSX_OPCODE_t valueGasBeforeSelectedGas;
    /*The value after in list of Gas Selected*/
    DSX_OPCODE_t valueGasAfterSelectedGas;
} swGasCheckNum_st;

//
static uint16_t GasSwitchFindPO2A(uint8_t gasNum);
GUI_COLOR GasSwitch_ColorDispRight(unsigned char);
void GasSwitchPO2Str(char*, unsigned char);
void GasSwitch_Bottom_MOD_Context(char* pStrRet);
void GasSwitch_Bottom_CannotSwitchLine0_Context(char* pStrRet);
void GasSwitch_Bottom_CannotSwitchLine1_Context(char* pStrRet);
void GasSwitch_Bottom_PO2HigherThan_1p6_Context(char* pStrRet);
void GasSwitch_Hypoxic_Bottom_Context(char* pStrRet);
void GasSwitch_ICD_Bottom_Context(char* pStrRet);
void GasSwitchBottom_TMTLink_Context(char* pStrRet);
void GasSwitchBottom_GasOFF_Context(char* pStrRet);
void Depth_In_Menu_Context(char* pStrRet);
/* GAS SWITCH bottom row message contrls */
void GasSwitchMenu_HandleDisplayText_Control(void);

/*Extern variables*/
extern const gasSwitchItemContext_ts SwGas_GAS_01;
extern const gasSwitchItemContext_ts SwGas_GAS_02;
extern const gasSwitchItemContext_ts SwGas_GAS_03;
extern const gasSwitchItemContext_ts SwGas_GAS_04;
extern const gasSwitchItemContext_ts SwGas_GAS_05;
extern const gasSwitchItemContext_ts SwGas_GAS_06;

extern const gasSwitchItemContext_ts* GasSwitchListCfg[];
extern const swGasCheckNum_st gasNumCheck_01[];
extern const swGasCheckNum_st gasNumCheck_02[];
extern const swGasCheckNum_st gasNumCheck_03[];
extern const swGasCheckNum_st gasNumCheck_04[];
extern const swGasCheckNum_st gasNumCheck_05[];
extern const swGasCheckNum_st gasNumCheck_06[];
extern const char* TxtDef_Set_PressUnit[];
extern NVD_DIVEMODE_t GUI_DIVE_Mode;
extern uint8_t GUI_PO2_Gas[];
extern uint8_t GUI_PO2_Gas_OC[];
extern uint8_t GUI_PO2_Gas_SM[];
uint8_t RetPosDisp(uint8_t CurrentGas, uint8_t DispGas, unsigned char DiveMode, uint16_t *PreGas , uint16_t *NextGas);
#endif
