/******************************************************************************/
//File: Dive Simulator
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"
#include "Menu_DiveSim_SimulateDive.h"
void IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS(void)
{
    ClearUnusedInList(0);
    char strRet[LangMaxLength];
    GUI_MEMDEV_Handle hmemLocal;

    if(CC_MODE)
    {
        /*BAILOUT_GAS_CONSUMPTION*/
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_BAILOUT_GAS_CONSUMPTION));
    }
    else if(OC_MODE||SM_MODE)
    {
        /*GAS CONSUMPTIONS*/
        DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_GAS_CONSUMPTIONS));
    }
    /**
    Display tille of coloumn
    */
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_GAS), Point_DiveSim_GasConsum_GAS->x, Point_DiveSim_GasConsum_GAS->y);
    GUI_SetTextAlign(GUI_TA_RIGHT);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_CONSUMPTION), Point_DiveSim_GasConsum_CONSUM->x, Point_DiveSim_GasConsum_CONSUM->y);
    /**
    Display the information in that Log
    */
    GUI_SetColor(GUI_WHITE);
    for(uint8_t i_u8 = 0U; i_u8<6U; i_u8++)
    {
        hmemLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
                                        ((i_u8 + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                                        Pos_Item_Select_List->Width,\
                                        Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemLocal);
        GUI_SetBkColor(GUI_BLACK);
        GUI_ClearRect(Pos_Item_Select_List->X0,\
                      ((i_u8 + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                      Pos_Item_Select_List->X1,\
                      ((i_u8 + 1)*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
        /*Display the value*/
        unsigned int FO2Val = CONS_FO2_FHe_RMV[i_u8 + 1U][BAILCONSUMP_FO2];
        unsigned int FHeVal = CONS_FO2_FHe_RMV[i_u8 + 1U][BAILCONSUMP_FHe];
        if((0U==FO2Val)&&(0U==FHeVal))
        {
            /*No display -> Clear the previous screen only*/
        }
        else
        {
            /*Display FO2/FHe*/
            sprintf(strRet, "%d/%d", FO2Val, FHeVal);
            GUI_SetTextAlign(GUI_TA_CENTER);
            GUI_DispStringAt(strRet, Point_DiveSim_GasConsum_GAS->x, ((i_u8 + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            /*Display CUFT or LM*/
            GUI_SetTextAlign(GUI_TA_RIGHT);
            unsigned int consumpVal = CONS_FO2_FHe_RMV[i_u8 + 1U][BAILCONSUMP_ConSump];
            if(Imperial)
            {
                sprintf(strRet, "%d CUFT", consumpVal);
            }
            else
            {
                sprintf(strRet, "%.0f L", ((float)consumpVal)*CONST_CUFT_TO_LITER);
            }
            GUI_DispStringAt(strRet, Point_DiveSim_GasConsum_CONSUM->x, ((i_u8 + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
        }
        GUI_MEMDEV_CopyToLCD(hmemLocal);
        GUI_MEMDEV_Delete(hmemLocal);
    }
};
void IniOrClrScrFunc_DIVE_SIMDIVE_SUMMARY(void)
{
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SUMMARY));
    SetFont_3;
    GUI_MEMDEV_Handle hmemLocal;
    char strRet[LangMaxLength];
    for(uint8_t i_u8 = 0; i_u8 < DiveSim_Summary_MAX; i_u8++)
    {
        hmemLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemLocal);
        GUI_ClearRect(Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (i_u8*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
        GUI_SetTextAlign(GUI_TA_LEFT);
        GUI_SetColor(TxtColor_UnSelect);
        /*Dipsplay MODEL*/
        GUI_DispStringAt(GUI_LANG_GetText(TxtDef_DiveSim_Summary[i_u8]), Pos_Item_Select_List->X0, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
        GUI_SetTextAlign(GUI_TA_CENTER);
        GUI_DispStringAt(":", Pos_Item_Select_List->X, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
        GUI_SetColor(TxtColor_Select);
        GUI_SetTextAlign(GUI_TA_RIGHT);
        pFuncSimDiveSummary[i_u8]((char*)strRet);
        GUI_DispStringAt(strRet, Pos_Item_Select_List->X1, (i_u8*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
        GUI_MEMDEV_CopyToLCD(hmemLocal);
        GUI_MEMDEV_Delete(hmemLocal);
    }
};
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01(void)
{
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Titles FT/M    RUNTIME     STOP       GAS*/
    DisplayHeaderDivePlan();
    /*Plan content*/
    uint16_t ocHandlePlanPage = 0U;
    switch(DSX_Opcode)
    {
    case DIVE_SIMDIVE_DIVPLAN_PAGE_01:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_1;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_02:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_2;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_03:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_3;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_04:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_4;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_05:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_5;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_06:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_6;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_07:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_7;
        break;
    case DIVE_SIMDIVE_DIVPLAN_PAGE_08:
        ocHandlePlanPage = SIMDIVE_PAGE_PLAN_8;
        break;
    }
    /*Display Plan content*/
    DisplayDivePlanPage(ocHandlePlanPage);
    Display_Icon_Buttons(IconBottDisp_BackHomeNext); //back/home/next
}
void IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01(void)
{
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_BAILOUT_PLAN));
    /*Titles FT/M    RUNTIME     STOP       GAS*/
    DisplayHeaderDivePlan();
    /*Bailout content*/
    uint16_t ocHandleBailoutPage = 0U;
    switch(DSX_Opcode)
    {
    case DIVE_SIMDIVE_BAILOUT_PAGE_01:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_1;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_02:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_2;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_03:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_3;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_04:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_4;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_05:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_5;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_06:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_6;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_07:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_7;
        break;
    case DIVE_SIMDIVE_BAILOUT_PAGE_08:
        ocHandleBailoutPage = SIMDIVE_PAGE_BAILOUT_8;
        break;
    }
    /*Display Bailout plan content*/
    DisplayBailoutPlanPage(ocHandleBailoutPage);

    Display_Icon_Buttons(IconBottDisp_BackHomeNext); //back/home/next

}
/*CALCULATING*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Content*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_Calculating);
    Display_Icon_Buttons(IconBottDisp_CLEAR);
}
/*NO DECO*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NODECO(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*NO DECO*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_NODECO);
    Display_Icon_Buttons(IconBottDisp_BackHomeNext);//back/home/next

}
/*NOT ENOUGH TIME*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_NotEnoughTime_Line0);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_NotEnoughTime_Line1);
    Display_Icon_Buttons(IconBottDisp_BackHome);
}
/*MAX CEILING EXCEED*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_MaxCeilingExceed_Line0);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_MaxCeilingExceed_Line1);
    Display_Icon_Buttons(IconBottDisp_BackHome);
}
/*DECO TIME EXCEED*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DECOTIME_EXCEED(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_DecoTimeExceed_Line0);
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_DecoTimeExceed_Line1);
}
/*TOO HIGH PO2*/
void IniOrClrScrFunc_DIVE_SIMDIVE_TOOHIGH_PO2(void)
{
    /*Clear screen*/
    ClearUnusedInList(0);
    /*Display subtitle level 2*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DIVE_PLAN));
    /*Warning content*/
    HandleDisplayTextWithMemdev(IteStat_Select, DiveSim_PlanPage_TooHighPO2);
}
