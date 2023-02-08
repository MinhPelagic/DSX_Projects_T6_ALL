/******************************************************************************/
//File: GAS Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextGasSwitchCfg.h"
#include "Menu_GasSwitch.h"


/*Functions handle in CC mode gas switch*/
static void IniOrClrScrFunc_GAS_SWITCH(unsigned char _gasNumHighlight)
{
    unsigned char MaxSW_Gas = 0;
    unsigned char cnt_disp_u8 = 0;
    // ClearUnusedInList(0);
    GUI_Clear();
    /*Display topbar title*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_GAS_SWITCH));
    /*Content*/
    if(CC_MODE) {
        MaxSW_Gas = GasSwitchNum_05+1;	/*List Gas1....Gas5*/
    }
    else {
        MaxSW_Gas = GasSwitchNum_06+1;	/*List Gas1....Gas6*/
    }

    if(CURRGAS == 1) { /*If current GAS = GAS1, mean GAS2 will line 0, offset -1*/
        _gasNumHighlight = _gasNumHighlight-1;
    }
    if(CURRGAS<=MaxSW_Gas)
    {
        for(unsigned char cnt_u8 = 0; cnt_u8 < MaxSW_Gas; cnt_u8++)
        {
            if(CURRGAS_POS!=cnt_u8)
            {
                if(CURRGAS == 1) {
                }
                Handle_Context_List_GASSWITCH((_gasNumHighlight==cnt_disp_u8) ? IteStat_Select : IteStat_UnSelect, cnt_disp_u8, *(GasSwitchListCfg[cnt_u8]));
                cnt_disp_u8++;
            }
            else
            {
                /*Do nothing -> Only display MAXNUMLIST_CC*/
            }
        }
    }
    else
    {
        /*Current gas is not valid -> Display nothing*/
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #1*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_1(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_01);
}
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_1(void)
{
    uint16_t PreGas, NextGas;
    /**/
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_01);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_1(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_01);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_1(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #2*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_2(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_02);
}
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_2(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_02);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_2(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_02);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_2(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #3*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_3(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_03);
}
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_3(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_03);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_3(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_03);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_3(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #4*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_4(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_04);
}
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_4(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_04);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_4(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_04);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_4(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #5*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_5(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_05);
}

void HandlePreOCFunc_GAS_SWITCH_TO_GAS_5(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_05);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_5(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_05);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_5(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
/*GAS #6*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_6(void)
{
    IniOrClrScrFunc_GAS_SWITCH(GasSwitchNum_06);
}
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_6(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp, SwGas_GAS_06);
    GUI_GAS_SWITCH_Step = GAS_SWITCH_MOD;
}
void UpdPorFunc_GAS_SWITCH_TO_GAS_6(void)
{
    uint16_t PreGas, NextGas;
    const uint8_t PosDisp =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp, SwGas_GAS_06);
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_6(void)
{
    uint8_t PosDisp1,PosDisp2,PosDisp3,PosDisp4,PosDisp5,PosDisp6;
    uint16_t PreGas, NextGas;
    PosDisp1 =  RetPosDisp(CURRGAS, GasSwitchNum_01, DIVE_MODE, &PreGas , &NextGas);
    PosDisp2 =  RetPosDisp(CURRGAS, GasSwitchNum_02, DIVE_MODE, &PreGas , &NextGas);
    PosDisp3 =  RetPosDisp(CURRGAS, GasSwitchNum_03, DIVE_MODE, &PreGas , &NextGas);
    PosDisp4 =  RetPosDisp(CURRGAS, GasSwitchNum_04, DIVE_MODE, &PreGas , &NextGas);
    PosDisp5 =  RetPosDisp(CURRGAS, GasSwitchNum_05, DIVE_MODE, &PreGas , &NextGas);
    PosDisp6 =  RetPosDisp(CURRGAS, GasSwitchNum_06, DIVE_MODE, &PreGas , &NextGas);
    /*Top Title displaying current Depth*/
    if(Dive_Info.Status == AMB_DIVEINFO_DIVE)
    {
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp1, SwGas_GAS_01);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp2, SwGas_GAS_02);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp3, SwGas_GAS_03);
        Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp4, SwGas_GAS_04);
        if((!CC_MODE)||((CC_MODE)&&(CURRGAS!=TANK_5)))
            Handle_Context_List_GASSWITCH(IteStat_UnSelect, PosDisp5, SwGas_GAS_05);
        if((CURRGAS!=TANK_6)&&(!CC_MODE))
            Handle_Context_List_GASSWITCH(IteStat_Select, PosDisp6, SwGas_GAS_06);
        HandleDisplayTextWithMemdev(IteStat_Select, Depth_In_Menu);
    }
    /*Bottom content*/
    GasSwitchMenu_HandleDisplayText_Control();
}

uint8_t RetPosDisp(uint8_t CurrentGas, uint8_t DispGas, unsigned char DiveMode, uint16_t *PreGas , uint16_t *NextGas)
{
    uint8_t RetPos          = 0u;
    uint16_t PreGas_tmp     = 0u;
    uint16_t NextGas_tmp    = 0u;

    //DispGas = 1....5
    switch(DiveMode)
    {
    case NVD_MDCC:
        /*calc display pos*/
        if(CurrentGas>DispGas) {
            RetPos = DispGas;
        }
        else {
            RetPos = DispGas-1;
        }

        /*calc pre, next OP for highlight, unhighlight*/
        PreGas_tmp = DispGas - 1;
        if(PreGas_tmp == CurrentGas) {
            PreGas_tmp--;
        }

        NextGas_tmp = DispGas + 1;
        if(NextGas_tmp == CurrentGas) {
            NextGas_tmp++;
        }


        if(NextGas_tmp>GasSwitchNum_05)
        {
            if(CurrentGas == GasSwitchNum_01)
            {
                NextGas_tmp = GasSwitchNum_02;
            }
            else {
                NextGas_tmp = GasSwitchNum_01;
            }
        }

        if(PreGas_tmp>(GasSwitchNum_05+2))//outrange, check if change gas1 to gas 5/6
        {
            if(CurrentGas == GasSwitchNum_05) {
                PreGas_tmp = GasSwitchNum_04;
            }
            else {
                PreGas_tmp = GasSwitchNum_05;
            }
        }

        break;

    case NVD_MDOC:
    case NVD_MDSM:
    case NVD_MDBO:
        /*calc display pos*/
        if(CurrentGas>DispGas) {
            RetPos = DispGas;
        }
        else {
            RetPos = DispGas-1;
        }

        /*calc pre, next OP for highlight, unhighlight*/
        PreGas_tmp = DispGas - 1;
        if(PreGas_tmp == CurrentGas) {
            PreGas_tmp--;
        }

        NextGas_tmp = DispGas + 1;
        if(NextGas_tmp == CurrentGas) {
            NextGas_tmp++;
        }

        if(NextGas_tmp>GasSwitchNum_06)
        {
            if(CurrentGas == GasSwitchNum_01)
            {
                NextGas_tmp = GasSwitchNum_02;
            }
            else {
                NextGas_tmp = GasSwitchNum_01;
            }
        }
        if(PreGas_tmp>(GasSwitchNum_06+2))
        {
            if(CurrentGas == GasSwitchNum_06) {
                PreGas_tmp = GasSwitchNum_05;
            }
            else {
                PreGas_tmp = GasSwitchNum_06;
            }
        }
        break;
    }

    *PreGas = PreGas_tmp+GAS_SWITCH_TO_GAS_1;
    *NextGas = NextGas_tmp+GAS_SWITCH_TO_GAS_1;
    return RetPos;
}
/* GAS SWITCH bottom row message contrls */
void GasSwitchMenu_HandleDisplayText_Control(void)
{
    const bool GasSwitchICD                 = (SCUBA_Set.Alarm2Set.Bit.ICD) && (CurrGasNumber != GUI_TankN_Linked) && ICD_Check(CurrGasNumber, GUI_TankN_Linked)&&(GUI_GAS_SWITCH_Step == GAS_SWITCH_TMT);
    /*Get Gas switch PO2 stat*/
    const GAS_SWITCH_PO2_STAT_t POSwStat    = GasSwitchPO2_Stat();
    //const bool GasSwitchPO2_OK              = (GAS_SWITCH_PO2_OK       == POSwStat) && (GUI_GAS_SWITCH_Step == GAS_SWITCH_MOD);
    const bool GasSwitchPO2_TooHigh         = (GAS_SWITCH_PO2_TOO_HIGH == POSwStat) && (GUI_GAS_SWITCH_Step == GAS_SWITCH_TMT);
    const bool GasSwitchPO2_TooLow          = (GAS_SWITCH_PO2_TOO_LOW  == POSwStat) && (GUI_GAS_SWITCH_Step == GAS_SWITCH_TMT);
    const bool GasSwitchPO2_Hypoxic         = (GAS_SWITCH_PO2_HYPOXIC  == POSwStat) && (GUI_GAS_SWITCH_Step == GAS_SWITCH_TMT);
    /*Display message*/
    switch(GUI_GAS_SWITCH_Step)
    {
    case GAS_SWITCH_MOD:
        /*Display bottom bar*/
        Display_Icon_Buttons(IconBottDisp_UpBackDownHomeSelect);
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, GasSwitch_MaxOfDepth);
        break;
    case GAS_SWITCH_TMT:
    default:
        /*Display bottom bar*/
        Display_Icon_Buttons(IconBottDisp_BackHomeSelect);
        if(GasSwitchICD)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitch_WarningIsoBaric);
        }
        else if (GasSwitchPO2_Hypoxic)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_PO2Hypoxic);
        }
        else if (GasSwitchPO2_TooHigh)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_WarningPO2TooHigh_Line0);
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_WarningPO2TooHigh_Line1);
        }
        else if (GasSwitchPO2_TooLow)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_PO2TooLowLine0);
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_PO2TooLowLine1);
        }
        else if (CheckIfGasEnabled((uint8_t)GUI_TankN_Linked)==NVD_OFF)
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenFlashing, GasSwitchBottom_GasOFF);
        }
        else
        {
            HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, GasSwitchBottom_TMTLink);
        }
        break;
    }
}
