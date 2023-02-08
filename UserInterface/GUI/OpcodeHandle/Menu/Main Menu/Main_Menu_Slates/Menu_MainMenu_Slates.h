/******************************************************************************/
//File: MAIN MENU -> Slates
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
/*Maximum of Slates*/
#define LIMIT_OF_MAX_SLATE      16      // Max number of SLATE allowed to save on ExFLASH 
typedef struct
{
    uint32_t day:       8; //Day
    uint32_t month:     8; //Month
    uint32_t year:      8; //Year
    uint32_t reserve:   8; //resever
} slateDateFormat;

//
extern uint8_t GUI_MaxSlateNum;           // Total number Slates saved on ExFLASH
extern uint8_t GUI_CurrSlateNum;          // Current Slates saved on ExFLASH
extern const contentDispContext_st MainMenu_Slates_NoSlate;
extern const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_0;
extern const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_1;
extern const contentDispContext_st MainMenu_Slates_ConfirmDelete_Line_2;
extern const contentDispContext_st MainMenu_Slates_SlateDeleted_Line_0;
extern const contentDispContext_st MainMenu_Slates_SlateDeleted_Line_1;
extern const contentDispContext_st MainMenu_Slates_Tittle;
