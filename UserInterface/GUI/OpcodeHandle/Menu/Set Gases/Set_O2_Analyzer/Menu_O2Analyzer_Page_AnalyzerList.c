/******************************************************************************/
//File: O2 Analyzer
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_O2Analyzer.h"
#include "..\Menu_SetGase_DataMap.h"
#include "..\Menu_SetGases.h"
#include "..\ContextSetGasesCfg.h"
#include ".\Menu_O2Analyzer_Page_AnalyzerList.h"

/*display one O2 line*/
static void O2Analyzer_DisplayLineContent(MenuO2AnalyzerCtr_ts _CtrO2)
{
    char strRet_pChar[LangMaxLength];
    /*Get the index display*/
    const char Pos = _CtrO2.Idx;
    /*set color select/un-select*/
    const GUI_COLOR colorSet = (IteStat_Select == _CtrO2.dispStat) ? TxtColor_Select : TxtColor_UnSelect;
    GUI_SetColor(colorSet);
    GUI_SetBkColor(GUI_BLACK);
    /*Settings then initial*/
    GUI_MEMDEV_Handle hMemDevLocal = (GUI_MEMDEV_Handle)0;
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
    SetFont_3;
    GUI_MEMDEV_Select(hMemDevLocal);
    /*Select hmem base on content clear*/
    GUI_ClearRect(Pos_Item_Select_List->X0, (Pos*Pos_Item_Select_List->Height)+Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (Pos*Pos_Item_Select_List->Height)+(Pos_Item_Select_List->Y1));
    /*Left context*/
    GUI_SetTextAlign(GUI_TA_LEFT);
    contentFuncO2_GasMode(Pos, strRet_pChar);
    GUI_DispStringAt(strRet_pChar, Pos_Item_Select_List->X0, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    /*Middle 01 context*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    contentFuncO2_GasStatus(Pos, strRet_pChar);
    GUI_DispStringAt(strRet_pChar, Point_MainMenu_GasSwitch_STATUS->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    /*Middle 02 context*/
    GUI_SetTextAlign(GUI_TA_CENTER);
    contentFuncO2_FO2Fhe(Pos, strRet_pChar);
    GUI_DispStringAt(strRet_pChar, Point_MainMenu_GasSwitch_FO2Val->x, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    /*Right context*/
    GUI_SetTextAlign(GUI_TA_RIGHT);
    contentFuncO2_LinkedTMT(Pos, strRet_pChar);
    GUI_DispStringAt(strRet_pChar, Pos_Item_Select_List->X1, (Pos_Item_Select_List->Y0 +(Pos*Pos_Item_Select_List->Height)));
    /*Draw the dot: Specific to Set Gases*/
    if(O2Analyzer_CheckDisplayDot(Pos))
    {
        GUI_AA_FillCircle(Point_SetMenu_SetGas_ActualCircle->x, (Pos*Pos_Item_Select_List->Height) + Point_SetMenu_SetGas_ActualCircle->y, 3);
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
};
/*Check the Dot display in the line*/
static bool O2Analyzer_CheckDisplayDot(uint8_t gasID)
{
    bool status = FALSE;
    if(gasID == (GAS_ASSIGN_INDEX - 1U))
    {
        status = TRUE;
    }
    else
    {
        /*No display*/
    }
    return status;
}
/*
CC/OC-xx
xx: 1..6/L,R,3..6
*/
static void contentFuncO2_GasMode(uint8_t Id, char* content)
{
    if(NVD_MDCC == GUI_O2ANALYZER_DIVEMODE_ASSIGN)
    {
        sprintf(content, "CC-%d", (Id+1U));
    }
    else if(NVD_MDOC == GUI_O2ANALYZER_DIVEMODE_ASSIGN)
    {
        sprintf(content, "OC-%d", (Id+1U));
    }
    else
    {
        /*SM Mode*/
        switch (Id)
        {
        case 0U:
            strcpy(content, "OC-L");
            break;
        case 1U:
            strcpy(content, "OC-R");
            break;
        default:
            sprintf(content, "OC-%d", Id + 1U);
            break;
        }
    }
}
/*ON/OFF*/
static void contentFuncO2_GasStatus(uint8_t Id, char* content)
{
    strcpy(content, GUI_LANG_GetText(TxtDef_OnOffSet_Context[SetGasGetSetpoint(Id+1U)]));
}
/*FO2/FHe*/
static void contentFuncO2_FO2Fhe(uint8_t Id, char* content)
{
    const uint8_t setID = Id + 1U;
    sprintf(content, "%d/%.2d", SetGasGetFO2(setID), SetGasGetFHe(setID));
}
/*Linked TMT*/
static void contentFuncO2_LinkedTMT(uint8_t Id, char* content)
{
    strcpy(content, GUI_LANG_GetText(TxtDefSetGasTMT[SetGasGetTMTValue(Id + 1U)]));
}
/*Number of item display base on the dive mode*/
static uint8_t O2Analyzer_MaxItemDisplay(NVD_DIVEMODE_t diveMode)
{
    uint8_t retValue = 0u;
    if(NVD_MDCC == diveMode)
    {
        retValue = 4U; /*1..5 ~ 0..4*/
    }
    else
    {
        retValue = 5U; /*1..6 | L-R..6*/
    }
    return retValue;
}
/*S477_ANALYZE_SELECT_GAS_TO_ASSIGN*/
void IniOrClrScrFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN(void)
{
    /*Display the list select gas to assign*/
    ClearUnusedInList(0);
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_SELECT_GAS_TO_ASSIGN));
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    /*Initial list*/
    ctrO2Analyzer.dispStat      = IteStat_Select;
    ctrO2Analyzer.maxItemDisp   = O2Analyzer_MaxItemDisplay(GUI_O2ANALYZER_DIVEMODE_ASSIGN);
    ctrO2Analyzer.Idx           = 0U;
    for(uint8_t cnt_u8 = 0; cnt_u8 <= ctrO2Analyzer.maxItemDisp; cnt_u8++)
    {
        O2Analyzer_DisplayLineContent(ctrO2Analyzer);
        ctrO2Analyzer.Idx       += 1u;
        ctrO2Analyzer.dispStat  = IteStat_UnSelect; //highlight 1st item only
    }
    ctrO2Analyzer.updateDisp    = FALSE;    //marked as updated
    ctrO2Analyzer.idxHighlight  = 0U;       //highlight 1s item
    ctrO2Analyzer.idxUnHilight  = 0U;       //unhigh light 1st
}
void UpdOrFlasFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN(void)
{
    if(ctrO2Analyzer.updateDisp)
    {
        /*When need update -> highlight present item and unhighlight previous one*/
        ctrO2Analyzer.dispStat  = IteStat_UnSelect;
        ctrO2Analyzer.Idx       = ctrO2Analyzer.idxUnHilight;
        O2Analyzer_DisplayLineContent(ctrO2Analyzer);
        /*Highlight current item*/
        ctrO2Analyzer.dispStat  = IteStat_Select;
        ctrO2Analyzer.Idx       = ctrO2Analyzer.idxHighlight;
        O2Analyzer_DisplayLineContent(ctrO2Analyzer);
        /*set current highlight will be unhighlight*/
        ctrO2Analyzer.idxUnHilight  = ctrO2Analyzer.idxHighlight;
        ctrO2Analyzer.updateDisp    = FALSE;
    }
    else
    {
        /*Do nothing*/
    }
}
