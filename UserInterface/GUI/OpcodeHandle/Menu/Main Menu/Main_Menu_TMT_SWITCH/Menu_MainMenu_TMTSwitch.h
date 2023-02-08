/******************************************************************************/
//File: TMT Switch
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"

/*Main Menu set TMT*/
enum
{
    MM_TMT_L,       //~TMT 1
    MM_TMT_R,       //~TMT 2
    MM_TMT_3,
    MM_TMT_4,
    MM_TMT_5,
    MM_TMT_6,
    MM_TMT_MAX,
};
/*information to display TMT item*/
typedef struct
{
    /* TMT number */
    unsigned char TMTNumber;
    /*position display in list 0 ~ MM_TMT_MAX*/
    int posDisplay;
} Menu_TMTItems_st;

/*list TMT information*/
typedef struct
{
    /*Maximum item*/
    unsigned char maxTMT;
    /*TMT list status*/
    Menu_TMTItems_st TMTList[MM_TMT_MAX];
} MainMenu_TMTDisplayList_st;

/*data structure to display each item TMT in list*/
typedef struct
{
    /*content*/
    char content[10]; /*TMT L, TMT R*/
    /*Highlight or not -> color change base on status*/
    ItemStatus_te dispStat;
    /*postion display in list from 0 ~ 6*/
    unsigned int posDispInList;
} MenuMainMenu_TMTSwitch;

extern uint8_t GUI_ShowTankNum;
extern NVD_status_t    GUI_TMT_Status[];      // On/Off/State of TMT#1~#6
extern const contentWithStateHandle_st TMTSwitch_Bottom_Content;
extern Menu_TMTItems_st HighLightTMTItem;
extern const char* TxtDef_Set_PressUnit[SetUnit_MAX];
extern const char *TxtDef_MainMenuSetTMT[MM_TMT_MAX];
void TMTMenu_UpdatePressDown(Menu_TMTItems_st*);
void TMTMenu_UpdatePressUp(Menu_TMTItems_st*);
void TMTSwitchMenu_DisplayAllThe_PossibleTMT(void);
DSX_OPCODE_t DiveMainMenu_SwitchBackValueToDive(void);
MainMenu_TMTDisplayList_st getTheListTMTDisplay(void);
