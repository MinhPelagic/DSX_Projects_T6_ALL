#include "L4X9_includes.h"
#include "DiveMode.h"


#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_GasSwitch_Context(char* pStrRet)
{
    uint8_t GasNumToSwitch;
    uint8_t FO2_to_Switch;
    uint8_t FHe_to_Switch;

    GasNumToSwitch = (uint8_t)DecoGas[1];

    if(CC_MODE)
    {
        FO2_to_Switch = TRIMIX_Set.CC_FO2[GasNumToSwitch];
        FHe_to_Switch = TRIMIX_Set.CC_FHe[GasNumToSwitch];
    }
    else if(OC_MODE)
    {
        FO2_to_Switch = TRIMIX_Set.OC_FO2[GasNumToSwitch];
        FHe_to_Switch = TRIMIX_Set.OC_FHe[GasNumToSwitch];
    }
    else if(SM_MODE)
    {
        FO2_to_Switch = TRIMIX_Set.SM_FO2[GasNumToSwitch];
        FHe_to_Switch = TRIMIX_Set.SM_FHe[GasNumToSwitch];
    }
    else if(BO_MODE)
    {
        FO2_to_Switch = TRIMIX_Set.BO_FO2[GasNumToSwitch];
        FHe_to_Switch = TRIMIX_Set.BO_FHe[GasNumToSwitch];
    }
    sprintf(pStrRet, "%s %2.d/%.2d",  GUI_LANG_GetText(TxtStr_SWITCH_TO), FO2_to_Switch, FHe_to_Switch);
}
const contentDispContext_st ALARM_GasSwitch =
{
    &ALARM_GasSwitch_Context,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of Gas switch in both Dive/Surface*/
unsigned char AlarmStatusCheck_GasSwitch(void)
{
    /*This status handle by algorithm*/
    return (unsigned char)Alarming.Bit.SwitchFO2;
};
