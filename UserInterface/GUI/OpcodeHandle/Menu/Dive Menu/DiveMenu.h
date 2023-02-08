#include "L4X9_includes.h"
#include "ContextDiveMenuCfg.h"
/*There are 4 display different of Dive menu settings base on settings of Conservative -> SPORT
-> when this setting is on then no display SET GF HIGH in Dive menu*/
typedef enum
{
    DiveMenuSetting_CC = 0x00,
    DiveMenuSetting_CC_SetGFHighOff,
    DiveMenuSetting_OC,
    DiveMenuSetting_OC_SetGFHighOff,
    DiveMenuSetting_Max
} DiveMenuSettting_e;

extern NVD_DIVEMODE_t GUI_DIVE_Mode;                   // GUI settings for DIVE_MODE
extern const listItemInMenu_ts* DiveMenu_ListOfContext[DiveMenuSetting_Max];
uint8_t DiveMenu_GetTheCurrentDisplayStatus(void);
