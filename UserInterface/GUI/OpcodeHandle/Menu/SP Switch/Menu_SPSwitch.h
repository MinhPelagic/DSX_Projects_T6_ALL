/******************************************************************************/
//File: SP Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextSPSwitchCfg.h"

#define SP_SWITCH_SP_HIGH_VAL            ((float)SCUBA_Set.SP_SetHigh/100.0)
#define SP_SWITCH_SP_LOW_VAL             ((float)SCUBA_Set.SP_SetLow/100.0)
#define SP_SWITCH_SP_CUSTOM_VAL          ((float)SCUBA_Set.SP_SetCustomer/100.0)
#define SP_SWITCH_SP_ACTUAL_VAL                 ((float)find_CC_SP_Current()/100.0)

enum SPSwich_Mode_e
{
    SPSwitchMode_LOW_CUSTOM,     //Current is HIGH
    SPSwitchMode_HIGH_CUSTOM,    //Current is LOW
    SPSwitchMode_HIGH_LOW,       //Current is CUSTOM
    SPSwitchMode_HIGH_ONLY,       //Current is LOW & CUSTOM is OFF
    SPSwitchMode_LOW_ONLY,       //Current is HIGH & CUSTOM is OFF
    SPSwitchMode_MAX
};
enum SPSwitch_Setting_e
{
    SPSwitch_Set_HIGH = 0x00,
    SPSwitch_Set_LOW,
    SPSwitch_Set_CUSTOM,
    SPSwitch_Set_MAX,
};
enum SPSwitch_Line
{
    SPSwitch_Line1= 0x00,
    SPSwitch_Line2,
    SPSwitch_Linet_MAX,
};
unsigned char SPSwitch_Mode(void);
extern const listItemInMenu_ts* SPSwitch_ListOfContext[SPSwitchMode_MAX];
extern const GUI_POINT	Hor_Line_1[];
