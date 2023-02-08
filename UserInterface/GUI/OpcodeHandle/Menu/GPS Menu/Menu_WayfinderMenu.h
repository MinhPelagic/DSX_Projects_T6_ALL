/******************************************************************************/
//File: SET MENU -> GPS Menu -> WAYFINDER Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
/*
In spec define is 20 items
but real Maximum item of wayfinder item be stored in exFlash is (SECTOR_SIZE/64U)=64
*/
#define WFINDER_MAX      20
typedef struct
{
    /*position in array of data*/
    int posData;
    /*position dislay in list 0~6*/
    int posDisp;
    /*content*/
    char content[LangMaxLength];
    /*item status highligh/un-highlight*/
    ItemStatus_te dispStat;
} WayfinderDips_ts;
/*control display wayfinder*/
typedef struct
{
    /*trigger update or not*/
    bool dispUpdate;
    /*intial status : trigger display all items/update pair of items (highlight/un-higlight only)*/
    bool dispAllItem;
    /*current position highlight*/
    uint8_t currentHighlight;
    /*start index number -> start display on top of list*/
    uint8_t startIndex;
    /*position un-Highlight*/
    uint8_t posUnhighlight;
    /*store current maximum index*/
    uint8_t maxItemDisp;
} WayFinderCrl_ts;

/*Wayfinder main icon*/
void DisplayIconGPS(GUI_COLOR color);
void WayfinderMenu_LocationContext(char* pStrRet, uint8_t pos);
static uint8_t WayFinder_GetNumberOfItems(void);
static void WayFinder_LimitedNumDisplayItems(uint8_t* dataIn);
extern const listItemInMenu_ts* WayfinderMenuListOfContext[];
extern NVD_DIVEMODE_t GUI_DIVE_Mode;
extern WayFinderCrl_ts WfinderCtrVar;
