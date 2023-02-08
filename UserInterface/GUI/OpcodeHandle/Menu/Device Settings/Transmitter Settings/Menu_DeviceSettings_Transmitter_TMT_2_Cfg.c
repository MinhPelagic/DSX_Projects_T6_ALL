/******************************************************************************/
//File: Menu_DeviceSettings_Transmitter_TMT_2_Cfg
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextDeviceSettingsCfg.h"
#include "../Menu_DeviceSettings.h"

/*Context memdev config to DeviceSett_Transmitt_TMT_2*/
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Ctx =
{
    &Transmitters_TMT_2_Context_Center,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_SetDateTime_DateFormat, //Reuse
};

/*DIGIT 1*/
void Transmitters_TMT_2_Digit_1_Content(char* pStrRet)
{
    /*Digit 1*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_1]);
}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_1_Ctx =
{
    &Transmitters_TMT_2_Digit_1_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_1,
};
/*DIGIT 2*/
void Transmitters_TMT_2_Digit_2_Content(char* pStrRet)
{
    /*Digit 2*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_2]);
}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_2_Ctx =
{
    &Transmitters_TMT_2_Digit_2_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_2,
};
/*DIGIT 3*/
void Transmitters_TMT_2_Digit_3_Content(char* pStrRet)
{
    /*Digit 3*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_3]);
}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_3_Ctx =
{
    &Transmitters_TMT_2_Digit_3_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_3,
};
/*DIGIT 4*/
void Transmitters_TMT_2_Digit_4_Content(char* pStrRet)
{
    /*Digit 4*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_4]);
}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_4_Ctx =
{
    &Transmitters_TMT_2_Digit_4_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_4,
};
/*DIGIT 5*/
void Transmitters_TMT_2_Digit_5_Content(char* pStrRet)
{
    /*Digit 5*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_5]);
}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_5_Ctx =
{
    &Transmitters_TMT_2_Digit_5_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_5,
};
/*DIGIT 6*/
void Transmitters_TMT_2_Digit_6_Content(char* pStrRet)
{
    /*Digit 6*/
    sprintf(pStrRet, " %d ", GUI_TMT_SerialNum[TMT_2][setDigit_6]);

}
const contentDispContext_st Set_DeviceSett_Transmitt_TMT_2_Digit_6_Ctx =
{
    &Transmitters_TMT_2_Digit_6_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_6,
    &Pos_DeviceSett_Transmitt_Set_TMT_SN_Digit_6,
};