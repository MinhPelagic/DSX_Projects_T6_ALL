/******************************************************************************/
//File: Dive planner.c
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_DivePlanner_DataMap.h"
#include "Menu_DivePlanner.h"

typedef struct
{
    uint8_t DepthStart;
    uint8_t SetpValue;
} DiPla_DeLi_st;
/*
Step of data should be
IMPERIAL = 30 FT, 40 FT, 50 FT, 60 FT, 70 FT, 80 FT.
METRIC = 9 M, 12 M, 15 M, 18 M, 21 M, 24 M.
*/
DiPla_DeLi_st DiPla_DEPTH_LIMIT[SetUnit_MAX] = {
    {30, 10},//Start at 30FT and step is 10FT
    {9, 3},
};
void DivePlanner_TIMELIMIT_Context(uint8_t StartLimitNum)
{
    char pStrRet[LangMaxLength];
    GUI_MEMDEV_Handle hmemlocal;
    /**
    Top title:
    GAS: MM-GAS# xx/xx     SP/MOD: x.xx-x.xx      GF: xx-xx
    */
    Handle_DivePlanner_TimeLimitsTittle(pStrRet);
    DisplayText_TopBar_Title(pStrRet);
    /*FT 			LIMIT(MIN)*/
    hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
                                    Pos_Item_Select_List->Y0,\
                                    Pos_Item_Select_List->Width,\
                                    Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemlocal);
    GUI_ClearRect(Pos_Item_Select_List->X0,\
                  Pos_Item_Select_List->Y0,\
                  Pos_Item_Select_List->X1,\
                  Pos_Item_Select_List->Y1);
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(TxtDef_Set_DepthUnit[UNITS], Point_DiPla_ToTil_DEPTH->x, Point_DiPla_ToTil_DEPTH->y);
    GUI_SetTextAlign(GUI_TA_CENTER);
    sprintf(pStrRet, "%s (%s)", GUI_LANG_GetText(TxtStr_LIMIT), GUI_LANG_GetText(TxtStr_MIN));
    GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_TIME->x, Point_DiPla_ToTil_TIME->y);
    GUI_MEMDEV_CopyToLCD(hmemlocal);
    GUI_MEMDEV_Delete(hmemlocal);
    /*Value*/
    for(uint8_t u8_i = 0; u8_i<MaxItemPlan; u8_i++) {
        hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
                                        ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                                        Pos_Item_Select_List->Width,\
                                        Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemlocal);
        GUI_SetBkColor((u8_i%2) ? GUI_BLACK : GUI_GRAY);//Set the color alternate
        GUI_ClearRect(Pos_Item_Select_List->X0,\
                      ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
                      Pos_Item_Select_List->X1,\
                      ((u8_i + 1)*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
        if((DiPla_MIN_STOP != DiPla_MIN(u8_i + (StartLimitNum*MaxItemPlan)))&&((1+u8_i+(MaxItemPlan*(GUI_PageIndex-1)))<=GUI_MenuIndexMAX)) {
            GUI_SetColor(GUI_WHITE);
            GUI_SetTextAlign(GUI_TA_CENTER);
            sprintf(pStrRet, "%d", Plan_DEPTH_NDT_OTR_PO2[2+u8_i+(MaxItemPlan*(GUI_PageIndex-1))][0]);
            GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_DEPTH->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
            GUI_SetTextAlign(GUI_TA_CENTER);
            if(Plan_DEPTH_NDT_OTR_PO2[2+u8_i+(MaxItemPlan*(GUI_PageIndex-1))][1]<Plan_DEPTH_NDT_OTR_PO2[2+u8_i+(MaxItemPlan*(GUI_PageIndex-1))][2])
                sprintf(pStrRet, "%d", Plan_DEPTH_NDT_OTR_PO2[2+u8_i+(MaxItemPlan*(GUI_PageIndex-1))][1]);
            else
                sprintf(pStrRet, "%d", Plan_DEPTH_NDT_OTR_PO2[2+u8_i+(MaxItemPlan*(GUI_PageIndex-1))][2]);
            GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_TIME->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
        }
        else {
            /*When the plan time in the depth is not correct then stop display*/
        }
        GUI_MEMDEV_CopyToLCD(hmemlocal);
        GUI_MEMDEV_Delete(hmemlocal);
    }
};
// static void DivePlanner_TIMELIMIT_0(void)
// {
//     /*Page 0*/
//     DivePlanner_TIMELIMIT_Context(DispDivePlanner_0);
// };
// static void DivePlanner_TIMELIMIT_1(void)
// {
//     /*Page 1*/
//     DivePlanner_TIMELIMIT_Context(DispDivePlanner_1);
// };
// static void DivePlanner_TIMELIMIT_2(void)
// {
//     /*Page 2*/
//     DivePlanner_TIMELIMIT_Context(DispDivePlanner_2);
// };

void IniOrClrScrFunc_DIVE_PL_TIME_LIMITS_SET(void)
{
    DivePlanner_TIMELIMIT_Context(1);
}
void UpdOrFlasFunc_DIVE_PL_TIME_LIMITS_SET(void)
{
    DivePlanner_TIMELIMIT_Context(1);
}

// void DiveSimulator_TIMELIMIT_Context(uint8_t StartLimitNum)
// {
//     char pStrRet[LangMaxLength];
//     /**
//     Top title:
//     GAS: MM-GAS# xx/xx     SP: x.xx-x.xx      GF: xx-xx
//     */
//     sprintf(pStrRet, "%s: %s-%d %d/%d   %s: %.2f-%.2f   %s: %d-%d",\
//             GUI_LANG_GetText(TxtStr_GAS),\
//             GUI_LANG_GetText(TxtDef_DSX_MainMode[(LoNibVal(MainMode)<DIVEMODE_MAX) ? LoNibVal(MainMode) : DIVEMODE_CC]),\
//             DiPla_GASNum,\
//             DiPla_FO2,DiPla_Fhe,\
//             GUI_LANG_GetText(TxtStr_SP),\
//             DiPla_SPHI,DiPla_SPLO,\
//             GUI_LANG_GetText(TxtStr_GF),\
//             DiPla_GFLO, DiPla_GFHI);
//     DisplayText_TopBar_Title(pStrRet);
//     /*FT 			LIMIT(MIN)*/
//     hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
//                          Pos_Item_Select_List->Y0,\
//                          Pos_Item_Select_List->Width,\
//                          Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
//     GUI_MEMDEV_Select(hmemlocal);
//     GUI_ClearRect(Pos_Item_Select_List->X0,\
//                   Pos_Item_Select_List->Y0,\
//                   Pos_Item_Select_List->X1,\
//                   Pos_Item_Select_List->Y1);
//     SetFont_3;
//     GUI_SetColor(GUI_CYAN);
//     GUI_SetTextAlign(GUI_TA_CENTER);
//     GUI_DispStringAt(TxtDef_Set_DepthUnit[UNITS], Point_DiPla_ToTil_SIM_DEPTH->x, Point_DiPla_ToTil_SIM_DEPTH->y);
//     GUI_SetTextAlign(GUI_TA_CENTER);
//     sprintf(pStrRet, "%s(%s)", GUI_LANG_GetText(TxtStr_LIMIT), GUI_LANG_GetText(TxtStr_MIN));
//     GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_TIME->x, Point_DiPla_ToTil_SIM_TIME->y);
//     GUI_SetTextAlign(GUI_TA_CENTER);
//     sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtStr_FO2));
//     GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_FO2->x, Point_DiPla_ToTil_SIM_FO2->y);
//     GUI_SetTextAlign(GUI_TA_CENTER);
//     sprintf(pStrRet, "%s", GUI_LANG_GetText(TxtStr_FO2));
//     GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_FHE->x, Point_DiPla_ToTil_SIM_FHE->y);
//     CopyFromMemDevToLCD
//     /*Value*/
//     for(uint8_t u8_i = 0; u8_i<MaxItemPlan; u8_i++) {
//         hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0,\
//                              ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
//                              Pos_Item_Select_List->Width,\
//                              Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
//         GUI_MEMDEV_Select(hmemlocal);
//         GUI_SetBkColor((u8_i%2) ? GUI_BLACK : GUI_GRAY);//Set the color alternate
//         GUI_ClearRect(Pos_Item_Select_List->X0,\
//                       ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0,\
//                       Pos_Item_Select_List->X1,\
//                       ((u8_i + 1)*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
//         if((DiPla_MIN_STOP != DiPla_MIN(u8_i + (StartLimitNum*MaxItemPlan)))&&((u8_i+(MaxItemPlan*(GUI_PageIndex-1)))<=GUI_MenuIndexMAX)) {
//             GUI_SetColor(GUI_WHITE);
//             GUI_SetTextAlign(GUI_TA_CENTER);
//             sprintf(pStrRet, "%d", DecoStop[1+u8_i+(MaxItemPlan*(GUI_PageIndex-1))]);
//             GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_DEPTH->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
//             GUI_SetTextAlign(GUI_TA_CENTER);
//             sprintf(pStrRet, "%d", DecoTime[1+u8_i+(MaxItemPlan*(GUI_PageIndex-1))]);
//             GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_TIME->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
//             GUI_SetTextAlign(GUI_TA_CENTER);
//             sprintf(pStrRet, "%d", DecoFO2[1+u8_i+(MaxItemPlan*(GUI_PageIndex-1))]);
//             GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_FO2->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
//             GUI_SetTextAlign(GUI_TA_CENTER);
//             sprintf(pStrRet, "%d", DecoFHe[1+u8_i+(MaxItemPlan*(GUI_PageIndex-1))]);
//             GUI_DispStringAt(pStrRet, Point_DiPla_ToTil_SIM_FHE->x, ((u8_i + 1)*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0);
//         }
//         else {
//             /*When the plan time in the depth is not correct then stop display*/
//         }
//         CopyFromMemDevToLCD
//     }
// };


