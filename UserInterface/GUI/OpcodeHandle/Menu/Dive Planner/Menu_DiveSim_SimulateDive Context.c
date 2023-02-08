/******************************************************************************/
//File: Dive Simulator
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "ContextDivePlannerCfg.h"
#include "Menu_DivePlanner.h"
#include "Menu_DiveSim_SimulateDive.h"
#include "..\Set Gases\Menu_SetGases.h"

const TxtStr_Name_e TxtDef_DiveSim_Summary[DiveSim_Summary_MAX]=
{
    TxtStr_TOTAL_RUNTIME,
    TxtStr_TOTAL_DECO,
    TxtStr_O2_SAT,
    TxtStr_GF_SELECTED,
};
/*Dive PLAN header*/
void DisplayHeaderDivePlan(void)
{
    GUI_MEMDEV_Handle hmemlocal;
    hmemlocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width,Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hmemlocal);
    GUI_ClearRect(Pos_Item_Select_List->X0, Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, Pos_Item_Select_List->Y1);
    SetFont_3;
    GUI_SetColor(GUI_CYAN);
    /*FT/M		RUNTIME		STOP	GAS*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(TxtDef_Set_DepthUnit[UNITS], Point_DiveSim_DivePlan_DepthUNIT->x, Point_DiveSim_DivePlan_DepthUNIT->y);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_RUNTIME), Point_DiveSim_DivePlan_RUNTIME->x, Point_DiveSim_DivePlan_DepthUNIT->y);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_STOP), Point_DiveSim_DivePlan_STOP->x, Point_DiveSim_DivePlan_STOP->y);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(GUI_LANG_GetText(TxtStr_GAS), Point_DiveSim_DivePlan_GAS->x, Point_DiveSim_DivePlan_STOP->y);
    GUI_MEMDEV_CopyToLCD(hmemlocal);
    GUI_MEMDEV_Delete(hmemlocal);
};
/*
Hanlde Dive Plan / BailOut Plan content
Progress each line of data
*/
static void DisplayDiveAndBailOutPlanRowContent(planDatDisp_st datInput)
{
    GUI_MEMDEV_Handle hmemLocal;
    char pStrRet[LangMaxLength];
    int RunTimeHour_i = 0U;
    int RunTimeMin_i  = 0U;
    int StopTime_i    = 0U;
    int FO2_i         = 0U;
    int FHe_i         = 0U;
    int Pos_i         = 0U;
    int X0_i          = 0U;
    int Y0_i          = 0U;
    int X1_i          = 0U;
    int Y1_i          = 0U;
    int Width_i       = 0U;
    int Height_i      = 0U;
    /*Get the data input*/
    RunTimeHour_i     = (datInput.RunTime)/(int)60U;
    RunTimeMin_i      = (datInput.RunTime)%(int)60U;
    StopTime_i        = (datInput.StopTime);
    FO2_i             = (datInput.FO2);
    FHe_i             = (datInput.FHe);
    /*Hmem locate*/
    Pos_i     = datInput.Pos + 1U;
    X0_i      = Pos_Item_Select_List->X0;
    X1_i      = Pos_Item_Select_List->X1;
    Y0_i      = ((Pos_Item_Select_List->Height)*Pos_i)+Pos_Item_Select_List->Y0;
    Y1_i      = ((Pos_Item_Select_List->Height)*Pos_i)+Pos_Item_Select_List->Y1;
    Width_i   = Pos_Item_Select_List->Width;
    Height_i  = Pos_Item_Select_List->Height;
    hmemLocal = GUI_MEMDEV_CreateEx(X0_i, Y0_i, Width_i, Height_i, GUI_MEMDEV_HASTRANS);
    GUI_ClearRect(X0_i, Y0_i, X1_i, Y1_i);
    GUI_MEMDEV_Select(hmemLocal);
    GUI_SetColor(GUI_WHITE);
    /*DEPTH: FT/M*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(datInput.depthString, Point_DiveSim_DivePlan_DepthUNIT->x, Y0_i);
    /*RUNTIME: hh:mm*/
    if(StopTime_i>99U)
    {
        sprintf(pStrRet, "-:--");
    }
    else
    {
        sprintf(pStrRet, "%d:%.2d", RunTimeHour_i, RunTimeMin_i);
    }
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(pStrRet, Point_DiveSim_DivePlan_RUNTIME->x, Y0_i);
    /*STOP TIME: xxMIN*/
    if(StopTime_i>99U)
    {
        sprintf(pStrRet, ">99 %s", GUI_LANG_GetText(TxtStr_MIN));
    }
    else
    {
        sprintf(pStrRet, "%d %s", StopTime_i, GUI_LANG_GetText(TxtStr_MIN));
    }
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(pStrRet, Point_DiveSim_DivePlan_STOP->x, Y0_i);
    /*GAS: FO2/FHe*/
    sprintf(pStrRet, "%d/%d", FO2_i, FHe_i);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(pStrRet, Point_DiveSim_DivePlan_GAS->x, Y0_i);
    /*Clear memdev*/
    GUI_MEMDEV_CopyToLCD(hmemLocal);
    GUI_MEMDEV_Delete(hmemLocal);
};
/*Return the data of plan index base on the page ID and Row Index*/
#define PLAN_ASC_STOPTIME   ((int)(ceil((GUI_DIVE_SIMULATOR_DEPTH_Ft - (float)DecoStop[1])/30.0f))) //if in Metric devide to 18U
static void PlanPageGetData(planDatDisp_st *dataHandle, unsigned char pageIndex, unsigned char rowIndex)
{
    /*Calculate the ID*/
    int RowID_i = 0;
    char pStrRet[LangMaxLength];
    /*6 row in pages + offset ID*/
    RowID_i = (MaxItemPlan * pageIndex) + rowIndex;
    /*stop Time in ASC*/
    int _stopTime = PLAN_ASC_STOPTIME; //This value use for plan ASC and first bail in
    switch(RowID_i)
    {
    case 0: //1st Row in MainPage user input
        if(Imperial)
        {
            sprintf(pStrRet, "%d", GUI_DIVE_SIMULATOR_DEPTH_Ft);
        }
        else
        {
            sprintf(pStrRet, "%d", GUI_DIVE_SIMULATOR_DEPTH_Mt);
        }
        strcpy(dataHandle->depthString, pStrRet);
        dataHandle->RunTime     =  GUI_DIVE_SIMULATOR_Time;
        dataHandle->StopTime    =  GUI_DIVE_SIMULATOR_Time;
        dataHandle->FO2         =  SetGasGetFO2(CurrGasNumber);
        dataHandle->FHe         =  SetGasGetFHe(CurrGasNumber);
        dataHandle->Pos =  0; //Always in position 0
        break;
    case 1: //ASC row in Plan MainPage
        strcpy(dataHandle->depthString, "ASC");
        dataHandle->StopTime    =  _stopTime;
        dataHandle->RunTime     =  GUI_DIVE_SIMULATOR_Time + _stopTime;
        dataHandle->FO2         =  SetGasGetFO2(CurrGasNumber);
        dataHandle->FHe         =  SetGasGetFHe(CurrGasNumber);
        dataHandle->Pos         =  1; //Always in position 1
        break;
    default://Depth setting from 2..end get the first data from DecoStop[1] -> Depth[2] is DecoStop[1]
        /*Depth*/
        if(Imperial)
        {
            sprintf(pStrRet, "%d", DecoStop[RowID_i - 1]);
        }
        else
        {
            sprintf(pStrRet, "%.0f", (DecoStop[RowID_i - 1])*0.3f);
        }
        strcpy(dataHandle->depthString, pStrRet);
        /*Stop time*/
        dataHandle->StopTime = DecoTime[RowID_i - 1];
        /*Run time*/
        dataHandle->RunTime = GUI_DIVE_SIMULATOR_Time + _stopTime;
        for(unsigned char cnt_i = 1; cnt_i<RowID_i; cnt_i++)
        {
            dataHandle->RunTime  += DecoTime[cnt_i];
        }
        dataHandle->FO2      = DecoFO2[RowID_i - 1];
        dataHandle->FHe      = DecoFHe[RowID_i - 1];
        dataHandle->Pos      = rowIndex; //position display depend on index row
        break;
    }
}
/*Return the data of plan index base on the page ID and Row Index*/
static void BailoutPageGetData(planDatDisp_st *dataHandle, unsigned char pageIndex, unsigned char rowIndex)
{
    /*Calculate the ID*/
    int RowID_i = 0;
    char pStrRet[LangMaxLength];
    /*stop Time in ASC*/
    int _stopTime = PLAN_ASC_STOPTIME; //This value use for plan ASC and first bail in
    /*6 row in pages + offset ID*/
    RowID_i = (MaxItemPlan * pageIndex) + rowIndex;
    /*Depth*/
    if(Imperial)
    {
        sprintf(pStrRet, "%d", BDecoStop[RowID_i + 1]);
    }
    else
    {
        sprintf(pStrRet, "%.0f", (BDecoStop[RowID_i + 1])*0.3f);
    }
    strcpy(dataHandle->depthString, pStrRet);
    /*Stop time*/
    dataHandle->StopTime = BDecoTime[RowID_i + 1];
    /*Run time*/
    dataHandle->RunTime = GUI_DIVE_SIMULATOR_Time + _stopTime;
    for(unsigned char cnt_i = 0; cnt_i<=RowID_i; cnt_i++)
    {
        dataHandle->RunTime += BDecoTime[cnt_i + 1];
    }
    dataHandle->FO2      = BDecoFO2[RowID_i + 1];
    dataHandle->FHe      = BDecoFHe[RowID_i + 1];
    dataHandle->Pos      = rowIndex; //position display depend on index row
}
/*Get the data depend on page index*/
void DisplayDivePlanPage(unsigned char PageId)
{
    /*Plan row content setting*/
    planDatDisp_st DataPlanRowContent;
    for(unsigned char cnt_c = 0; cnt_c < MaxItemPlan; )
    {
        /*Input the data and get the position display in page*/
        PlanPageGetData(&DataPlanRowContent, PageId, cnt_c);
        /*When data is end -> No progress any further*/
        if((0U==DataPlanRowContent.StopTime)||(0U==DataPlanRowContent.RunTime)) //Can use Runtime/StopTime/GAS
            /*NOTE: is there 10FT in the last or not*/
        {
            ClearUnusedInList(cnt_c+1); //Clear unused
            cnt_c = MaxItemPlan;        //stop display
        }
        else
        {
            /*Display the rows in page*/
            DisplayDiveAndBailOutPlanRowContent(DataPlanRowContent);
            /*continue count to display*/
            cnt_c++;
        }
    }
}
/*Get the data depend on page index*/
void DisplayBailoutPlanPage(unsigned char PageId)
{
    /*Plan row content setting*/
    planDatDisp_st DataBailoutRowContent;
    for(unsigned char cnt_c = 0; cnt_c < MaxItemPlan; )
    {
        /*Input the data and get the position display in page*/
        BailoutPageGetData(&DataBailoutRowContent, PageId, cnt_c);
        /*When data is end -> No progress futher*/
        if((0U==DataBailoutRowContent.RunTime)||(0U==DataBailoutRowContent.StopTime)) //Can use Runtime/StopTime/GAS
        {
            ClearUnusedInList(cnt_c+1);//Clear unused
            cnt_c = MaxItemPlan; //stop display
        }
        else
        {
            /*Display the rows in page*/
            DisplayDiveAndBailOutPlanRowContent(DataBailoutRowContent);
            /*continue count to display*/
            cnt_c++;
        }
    }
}
/*NO  DECO*/
static void SimulateDive_NODECO_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_NO_DECO));
}
const contentDispContext_st DiveSim_PlanPage_NODECO =
{
    &SimulateDive_NODECO_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_5,
    &Pos_Setting_Title_Line_1,
};
/*CALCULATING*/
static void SimulateDive_Calculating_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_CALCULATING));
}
const contentDispContext_st DiveSim_PlanPage_Calculating =
{
    &SimulateDive_Calculating_Content,
    &Select_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
/*TOO HIGH PO2*/
static void SimulateDive_TooHighPO2_Content(char *pStrRet)
{
    strcpy(pStrRet, "TOO HIGH PO2");
}
const contentDispContext_st DiveSim_PlanPage_TooHighPO2 =
{
    &SimulateDive_TooHighPO2_Content,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
/*Not engouh time*/
static void SimulateDive_NotEnoughTime_Line0_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVESIM_NOTENOUGH_TIME_1));
}
static void SimulateDive_NotEnoughTime_Line1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVESIM_NOTENOUGH_TIME_2));
}
const contentDispContext_st DiveSim_PlanPage_NotEnoughTime_Line0 =
{
    &SimulateDive_NotEnoughTime_Line0_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st DiveSim_PlanPage_NotEnoughTime_Line1 =
{
    &SimulateDive_NotEnoughTime_Line1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*Max Ceiling exceed 420FT*/
static void SimulateDive_MaxCeilingExceed_Line0_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVESIM_MAX_CELING_1));
}
static void SimulateDive_MaxCeilingExceed_Line1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVESIM_MAX_CELING_2_FT));
}
const contentDispContext_st DiveSim_PlanPage_MaxCeilingExceed_Line0 =
{
    &SimulateDive_MaxCeilingExceed_Line0_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st DiveSim_PlanPage_MaxCeilingExceed_Line1 =
{
    &SimulateDive_MaxCeilingExceed_Line1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*Deco Time exceed 99 Mins*/
static void SimulateDive_DecoTimeExceed_Line0_Content(char *pStrRet)
{
    strcpy(pStrRet,  GUI_LANG_GetText(TxtStr_DIVE_SIM_DECO_1));
}
static void SimulateDive_DecoTimeExceed_Line1_Content(char *pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_DIVE_SIM_DECO_2));
}
const contentDispContext_st DiveSim_PlanPage_DecoTimeExceed_Line0 =
{
    &SimulateDive_DecoTimeExceed_Line0_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_1,
};
const contentDispContext_st DiveSim_PlanPage_DecoTimeExceed_Line1 =
{
    &SimulateDive_DecoTimeExceed_Line1_Content,
    &YELLOW_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_4,
    &Pos_Setting_Title_Line_2,
};
/*SUMMARY*/
static void SimDiveSum_TotalRuntime(char* pStrRet)
{
    int RunTimeHour_i     = 0u;
    int RunTimeMin_i      = 0u;
    /*Get total time of PLAN from User + ASC + Algo calculated*/
    int totalRuntime_i = GUI_DIVE_SIMULATOR_Time + PLAN_ASC_STOPTIME;
    for(unsigned char cnt_u8 = 1; cnt_u8 < PLANCALMAX; cnt_u8++)
    {
        totalRuntime_i += DecoTime[cnt_u8];
    }
    RunTimeHour_i     = (totalRuntime_i)/(int)60U;
    RunTimeMin_i      = (totalRuntime_i)%(int)60U;
    sprintf(pStrRet, "%d:%.2d", RunTimeHour_i, RunTimeMin_i);
}
static void SimDiveSum_TotalDeco(char* pStrRet)
{
    unsigned int totalDeco = 0;
    for(unsigned char cnt_u8 = 1; cnt_u8 <= PLANCALMAX; cnt_u8++)
    {
        totalDeco += DecoTime[cnt_u8];
    }
    sprintf(pStrRet, "%d MIN", totalDeco);
}
static void SimDiveSum_O2Sat(char* pStrRet)
{
    sprintf(pStrRet, "%d %%", (unsigned char)SIMOTUpercent);
}
static void SimDiveSum_GFSelect(char* pStrRet)
{
    sprintf(pStrRet, "%d-%d", Find_Gonsv_Lo(), Find_Gonsv_Hi());
}
const pstrHandle_Func pFuncSimDiveSummary[DiveSim_Summary_MAX] =
{
    SimDiveSum_TotalRuntime,
    SimDiveSum_TotalDeco,
    SimDiveSum_O2Sat,
    SimDiveSum_GFSelect,
};