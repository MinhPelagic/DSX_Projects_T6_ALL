/******************************************************************************/
//File: SET MENU -> GPS Menu -> Wayfinder Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_WayfinderMenu.h"

/*Display item in list wayfinder*/
static void WayFinder_DisplayItemInList(WayfinderDips_ts itemInfoDisp)
{
    const int _Pos = itemInfoDisp.posDisp;
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

/*
Display all the item in list
Always highlight the 1st item
*/
static void WayFinder_DisplayInitialPage(uint8_t startIdx, uint8_t maxIDx, uint8_t highlightPos)
{
    /**/
    WayfinderDips_ts contentWayfinder;
    for(uint8_t cnt_u8 = 0; cnt_u8 < maxIDx; cnt_u8++)
    {
        /*position*/
        contentWayfinder.posDisp = cnt_u8;
        /*highlight*/
        contentWayfinder.dispStat = (highlightPos == cnt_u8) ? IteStat_Select : IteStat_UnSelect;
        /*content*/
        WayfinderMenu_LocationContext(contentWayfinder.content, (cnt_u8 + startIdx));
        /*display item*/
        WayFinder_DisplayItemInList(contentWayfinder);
    }
}
/*S521_GPS_WAYFINDER_LIST*/
void IniOrClrScrFunc_S510_GPS_WAYFINDER_LIST(void)
{
    GUI_Clear();
    /*Tittle*/
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_WAYFINDER));
    Display_Icon_Buttons(IconBottDisp_UpBackDownSelect);
    /*get the max item display*/
    uint8_t numberItems = WayFinder_GetNumberOfItems();
    /*control stored*/
    WfinderCtrVar.maxItemDisp = numberItems;
    if(0U == numberItems)
    {
        /*Empty list -> Do nothing*/
    }
    else
    {
        WayFinder_LimitedNumDisplayItems(&numberItems);
        /*
        Display the list initial
        - start from 0 and highlight 1st item
        */
        WayFinder_DisplayInitialPage(0, numberItems, 0);
    }
    /*set control state*/
    WfinderCtrVar.currentHighlight    = 0;
    WfinderCtrVar.dispUpdate          = FALSE;
    WfinderCtrVar.dispAllItem         = FALSE;
    WfinderCtrVar.startIndex          = 0;
    WfinderCtrVar.posUnhighlight      = 0;
}
void UpdOrFlasFunc_S510_GPS_WAYFINDER_LIST(void)
{
    if(0 == WfinderCtrVar.maxItemDisp)
    {
        /*Empty list -> No progress*/
    }
    else
    {
        if(WfinderCtrVar.dispUpdate)
        {
            /*Highlight/Un-highlight pair items when moving up/down*/
            if(WfinderCtrVar.dispAllItem)
            {
                /*otherwise display all the item when scroll up/down exceed
                - start wayfinder Index (ID 0 to 20)*/
                WayFinder_DisplayInitialPage(WfinderCtrVar.startIndex, MaxItemInList, WfinderCtrVar.currentHighlight);
            }
            else
            {
                WayfinderDips_ts wayfinderDisp;
                /*higlight*/
                wayfinderDisp.posDisp = WfinderCtrVar.currentHighlight;
                wayfinderDisp.dispStat = IteStat_Select;
                WayfinderMenu_LocationContext(wayfinderDisp.content, (WfinderCtrVar.currentHighlight + WfinderCtrVar.startIndex));
                WayFinder_DisplayItemInList(wayfinderDisp);
                /*Un highlight*/
                wayfinderDisp.posDisp = WfinderCtrVar.posUnhighlight;
                wayfinderDisp.dispStat = IteStat_UnSelect;
                WayfinderMenu_LocationContext(wayfinderDisp.content, (WfinderCtrVar.posUnhighlight + WfinderCtrVar.startIndex));
                WayFinder_DisplayItemInList(wayfinderDisp);
            }
            /*Marked already display*/
            WfinderCtrVar.dispUpdate = FALSE;
        }
        else
        {
            /*Do nothing*/
        }
    }
}
/*Check how many Wayfinder item need to display in list*/
static uint8_t WayFinder_GetNumberOfItems(void)
{
    /*
    Check to how many wayfinder item be stored only display
    */
    return USER_Set.WayFinderLocNum;
    // 20 -> 1 = 21
}
/*
Validate number of item to display when exceed maximum lines
*/
static void WayFinder_LimitedNumDisplayItems(uint8_t* dataIn)
{
    /*
    Check to how many wayfinder item bestored only display maximum 7 items
    */
    if(*dataIn > MaxItemInList)
    {
        *dataIn = MaxItemInList;
    }
    else
    {
        /*keep that value*/
    }
}
