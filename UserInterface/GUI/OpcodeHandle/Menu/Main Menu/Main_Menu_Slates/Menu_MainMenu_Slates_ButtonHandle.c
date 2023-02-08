/******************************************************************************/
//File: MAIN MENU -> Slates button handle
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_MainMenu_Slates.h"

void CheckSlateMainPageStatus(DSX_OPCODE_t *opNewVal);

void HandleButton_MainMenu_SLATES(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    /*Base on the Dive mode -> Return the item in menu*/
    if(CC_MODE)
    {
        *newOpVal = Opcode_Matrix( ReturnToMainPage(), S185_INFO, S18_SP_SWITCH, *oldOpVal, CheckConditions, ReturnToMainPage(), *oldOpVal, *oldOpVal, *oldOpVal);
    }
    else if(OC_MODE||SM_MODE||BO_MODE)
    {
        *newOpVal = Opcode_Matrix( ReturnToMainPage(), S185_INFO, S21_GAS_SWITCH, *oldOpVal,CheckConditions, ReturnToMainPage(), *oldOpVal, *oldOpVal, *oldOpVal);
    }
    else
    {
        *newOpVal = Opcode_Matrix( ReturnToMainPage(), S185_INFO, S404_TMT_SWITCH, *oldOpVal, CheckConditions, ReturnToMainPage(), *oldOpVal, *oldOpVal, *oldOpVal);
    }
    /*
    When enter to Slate display -> Check the index of all Slates
    - If no index of slates retrieve index from exFlash: Display No slates
    - Otherwise: Display the last exit #Slate ()
    */
    CheckSlateMainPageStatus(newOpVal);
}
/*Handle go to Slate Main Page*/
void HandleButton_MainMenu_SlateMainPage(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    uint8_t currIdxSlates = 1U;
    /*Check the button  logic*/
    *newOpVal = Opcode_Matrix(BackupOpcode, DataDec, SLATES_CONFIRM_DELETE, *oldOpVal, DataInc, OpcodeForR2s, *oldOpVal, *oldOpVal, *oldOpVal);
    /*Display next slates*/
    switch (*newOpVal)
    {
    case DataInc:
        /* Note: GUI_MaxSlateNum is from 1 to GUI_MaxSlateNum (which is up to LIMIT_OF_MAX_SLATE) */
        if(GUI_CurrSlateNum < LIMIT_OF_MAX_SLATE)
        {
            GUI_CurrSlateNum++;
            /*Get the current index slates*/
            currIdxSlates = USER_Set.SLATE_Idx[GUI_CurrSlateNum - 1];
            /*Check value of index*/
            if(0U==currIdxSlates)
            {
                /*Rollback display to slate #1*/
                currIdxSlates = USER_Set.SLATE_Idx[0];
                /*Reset current slate number*/
                GUI_CurrSlateNum = 1U;
            }
            else
            {
                /*Do nothing*/
            }
        }
        else
        {
            /*Reset*/
            GUI_CurrSlateNum = 1U;
            currIdxSlates = USER_Set.SLATE_Idx[0];
        }
        /*Display the slates content*/
        ReadAndDisplaySlates(currIdxSlates); // displaying the Slate saved in SLATE_Idx location
        /*Display title slate number*/
        HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_Tittle);
        /*Keep Slate mainpage -> Only update the slate bitmap and titlle*/
        *newOpVal = SLATES_MAINPAGE;
        break;
    case DataDec:
        /*Reduce current slates*/
        GUI_CurrSlateNum--;
        if(0U==GUI_CurrSlateNum)
        {
            /*When reduce to 0 then do nothing keep slate #1*/
            GUI_CurrSlateNum = 1U;
        }
        else
        {
            currIdxSlates = USER_Set.SLATE_Idx[GUI_CurrSlateNum - 1U];
            /*Display the slates content*/
            ReadAndDisplaySlates(currIdxSlates); // displaying the Slate saved in SLATE_Idx location
            /*Display title slate number*/
            HandleDisplayTextWithMemdev(IteStat_Select, MainMenu_Slates_Tittle);
        }
        *newOpVal = SLATES_MAINPAGE;
        break;
    default:
        /*Do nothing*/
        break;
    }
}
/*Slate delete*/
void HandleButton_MainMenu_SlateDelete(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    *newOpVal = Opcode_Matrix(SLATES_MAINPAGE, *oldOpVal, *oldOpVal, *oldOpVal, SLATES_DELETED, ReturnToMainPage(), *oldOpVal, *oldOpVal, *oldOpVal);
    /*When confirm delete*/
    if(*newOpVal == SLATES_DELETED)
    {
        /* Note: i = 0 to (GUI_MaxSlateNum - 1)  on the other hand, GUI_MaxSlateNum is from 1 to GUI_MaxSlateNum (which is up to LIMIT_OF_MAX_SLATE) */
        /*clear SLATE_Stat to be 0 when the Slate is deleted*/
        USER_Set.SLATE_Stat[(USER_Set.SLATE_Idx[GUI_CurrSlateNum - 1] - 1)] = 0;
        /*Move the index data backward*/
        for(uint8_t i_u8 = GUI_CurrSlateNum; i_u8 <= LIMIT_OF_MAX_SLATE; i_u8++)
        {
            USER_Set.SLATE_Idx[i_u8 - 1] = USER_Set.SLATE_Idx[i_u8];
        }
        /*Save user setting to EE*/
        EE_SaveReq(EE_USERSET);
        /*Display Slate Deleted*/
        *newOpVal = SLATES_DELETED;
    }
    else
    {
        /*Do nothing*/
    }
}
void HandleButton_MainMenu_DeletedSlate(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    *newOpVal = Opcode_Matrix(*oldOpVal, *oldOpVal, *oldOpVal, *oldOpVal, CheckConditions, ReturnToMainPage(), *oldOpVal, *oldOpVal, *oldOpVal);
    /*Check the slate status after deleted*/
    CheckSlateMainPageStatus(newOpVal);
}
/**/
/*
When enter to Slate display -> Check the index of all Slates
- If no index of slates retrieve index from exFlash: Display No slates
- Otherwise: Display the last exit #Slate ()
*/
void CheckSlateMainPageStatus(DSX_OPCODE_t *opNewVal)
{
    /*
    When enter to Slate display -> Check the index of all Slates
    - If no index of slates retrieve index from exFlash: Display No slates
    - Otherwise: Display the last exit #Slate ()
    */
    if(*opNewVal==CheckConditions)
    {
        /*If 1st Slates is empty -> No slate in list -> Display No slated*/
        if(USER_Set.SLATE_Idx[0]==0U)
        {
            *opNewVal = SLATES_NO_SLATE;     /*No slates*/
        }
        else
        {
            /*Display 1st Slate*/
            *opNewVal = SLATES_MAINPAGE;
        }
    }
    else
    {
        /*Do nothing*/
    }
}