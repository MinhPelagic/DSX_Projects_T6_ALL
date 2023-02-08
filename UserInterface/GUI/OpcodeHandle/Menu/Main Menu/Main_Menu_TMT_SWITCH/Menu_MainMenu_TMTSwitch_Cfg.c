/******************************************************************************/
// File: TMT Switch
// Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_TMTSwitch.h"
static void MainMenuTMT_DisplayItemInList(MenuMainMenu_TMTSwitch itemInfoDisp);
static void TMTMenu_DisplayItemTMT(int PosDisp, ItemStatus_te dispStat, MainMenu_TMTDisplayList_st tmtList);

/*When stay in GSM or SM display TMT-L, TMT-R, otherwise display TMT-1, TMT-2*/
void GetTextSetTMT(char *TMTcontent, unsigned char _TMTnumber)
{
    const char *Txt_TMTLR[3] = {"N/A", "TMT-L", "TMT-R"};
    if ((SM_MODE || GSM_MODE) && ((_TMTnumber == 1U) || (_TMTnumber == 2U)))
    {
        strcpy(TMTcontent, Txt_TMTLR[_TMTnumber]);
    }
    else
    {
        sprintf(TMTcontent, "TMT-%d", (_TMTnumber));
    }
}
/*
GUI_ShowTankNum : Current Tank number was set

When display the list TMT switch
|---> Scan all the current TMT status and only display TMT ON
    |---> If TMT ON but has selected -> ignore
        |---> else: Display TMT item
    |---> When all the TMT Off
        |---> Dislay no TMT selected
*/
void TMTSwitchMenu_DisplayAllThe_PossibleTMT(void)
{
    MenuMainMenu_TMTSwitch TMTitem;
    ItemStatus_te dispStatus = IteStat_Select;
    /*check the list*/
    const MainMenu_TMTDisplayList_st TMTListInfo = getTheListTMTDisplay();
    /*Set the maximum items*/
    const unsigned char lastItemInList = TMTListInfo.maxTMT;
    /*Display the list*/
    for (unsigned char cnt_u8 = 0; cnt_u8 < lastItemInList; cnt_u8++)
    {
        /*get the content of TMT*/
        GetTextSetTMT(TMTitem.content, TMTListInfo.TMTList[cnt_u8].TMTNumber+1);
        /*status display -> 1st item is select*/
        TMTitem.dispStat = dispStatus;
        /*position display continuous*/
        TMTitem.posDispInList = cnt_u8;
        MainMenuTMT_DisplayItemInList(TMTitem);
        /**/
        dispStatus = IteStat_UnSelect; // The rest is unselect
    }
    /*save current hightlight is 1st */
    HighLightTMTItem.posDisplay = 0u;
    /*save current TMT number highlight*/
    HighLightTMTItem.TMTNumber = TMTListInfo.TMTList[HighLightTMTItem.posDisplay].TMTNumber;
}
/*validate the down pressed*/
void TMTMenu_UpdatePressDown(Menu_TMTItems_st *currentHighLight)
{
    /*check the list*/
    const MainMenu_TMTDisplayList_st TMTListInfo = getTheListTMTDisplay();
    /*only proceed when TMT list not empty*/
    if (TMTListInfo.maxTMT > 0u)
    {
        /*validate*/
        if (currentHighLight->posDisplay == (TMTListInfo.maxTMT - 1)) /*end of list*/
        {
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_UnSelect, TMTListInfo);
            /*revert back on top*/
            currentHighLight->posDisplay = 0u;
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_Select, TMTListInfo);
        }
        else if ((currentHighLight->posDisplay) < TMTListInfo.maxTMT)
        {
            /*unselect current highlight*/
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_UnSelect, TMTListInfo);
            (currentHighLight->posDisplay) += 1;
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_Select, TMTListInfo);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }
    /*save current TMT number highlight*/
    HighLightTMTItem.TMTNumber = TMTListInfo.TMTList[HighLightTMTItem.posDisplay].TMTNumber;
}
/*validate the up pressed*/
void TMTMenu_UpdatePressUp(Menu_TMTItems_st *currentHighLight)
{
    /*check the list*/
    const MainMenu_TMTDisplayList_st TMTListInfo = getTheListTMTDisplay();
    /*only proceed when TMT list not empty*/
    if (TMTListInfo.maxTMT > 0)
    {
        /*validate*/
        if (currentHighLight->posDisplay == 0u) /*end of list*/
        {
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_UnSelect, TMTListInfo);
            /*revert back on top*/
            currentHighLight->posDisplay = (TMTListInfo.maxTMT - 1);
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_Select, TMTListInfo);
        }
        else if (currentHighLight->posDisplay <= (TMTListInfo.maxTMT - 1))
        {
            /*unselect current highlight*/
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_UnSelect, TMTListInfo);
            (currentHighLight->posDisplay) -= 1;
            TMTMenu_DisplayItemTMT(currentHighLight->posDisplay, IteStat_Select, TMTListInfo);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }
    /*save current TMT number highlight*/
    HighLightTMTItem.TMTNumber = TMTListInfo.TMTList[HighLightTMTItem.posDisplay].TMTNumber;
}
/*Update display TMT item display*/
static void TMTMenu_DisplayItemTMT(int PosDisp, ItemStatus_te dispStat, MainMenu_TMTDisplayList_st tmtList)
{
    MenuMainMenu_TMTSwitch TMTitem;
    /*status display -> 1st item is select*/
    TMTitem.dispStat = dispStat;
    /*get the content of TMT*/
    GetTextSetTMT(TMTitem.content, tmtList.TMTList[PosDisp].TMTNumber+1);
    /*set display position*/
    TMTitem.posDispInList = PosDisp;
    MainMenuTMT_DisplayItemInList(TMTitem);
}

/*Display item in list TMT*/
static void MainMenuTMT_DisplayItemInList(MenuMainMenu_TMTSwitch itemInfoDisp)
{
    const int _Pos = itemInfoDisp.posDispInList;
    /*Settings*/
    SetFont_3;
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor((IteStat_UnSelect == itemInfoDisp.dispStat) ? TxtColor_UnSelect : TxtColor_Select);
    GUI_SetTextAlign(GUI_TA_LEFT);
    /*Select hmem base on content clear*/
    const GUI_MEMDEV_Handle hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (_Pos * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_Item_Select_List->X0, (_Pos * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (_Pos * Pos_Item_Select_List->Height) + (Pos_Item_Select_List->Y1));
    /*Display content*/
    GUI_DispStringAt(itemInfoDisp.content, Pos_Item_Select_List->X0, (Pos_Item_Select_List->Y0 + (_Pos * Pos_Item_Select_List->Height)));
    /*copy to memdev*/
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
};
