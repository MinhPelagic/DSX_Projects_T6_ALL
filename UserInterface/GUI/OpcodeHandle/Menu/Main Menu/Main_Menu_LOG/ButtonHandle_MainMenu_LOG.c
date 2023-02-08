/******************************************************************************/
//File: LOG 1
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_LOG.h"
/**
When scroll up button the index increase
    - The display buffer:  Log_Data_7[7]
Data sequence progress
    1. Incase empty LOG -> No progess any index
    2. The Counter always counting
        -> Decrease (M): data ++, if value is 0             -> Counter = 0
        -> Increase (L): data --, if data equal max of LOG  -> Counter = MaxOfLog
    3. Highlight the item
        -> When Decrease (M): Highlight ++, if value is 0 -> HighLight = 0
        -> When Increase (L): Highlight --,
                                        -> Value is 6 -> HighLight = 6
                                        -> Value is exceed MaxOfLog -> Highlight = MaxOfLog
    4. Set the start index:
        -> The index start with 0: the latest LOG
        -> Calculate start index
            --> There are 2 case need to update the page
                + On top of list and still have the data when press Up: Highlight == 0 && Counter != 0
                + In the bottom of list and not the last LOG item: Highlight == 6 && MaxOfLog > Counter
    5. Read the LOG data from EEPROM to buffer
       When move up/down the list changed but only when start index change (that's mean the page update and the list of log changed)
            -> Read the log everytime StartIndex changed
                Ex: When stay in page from 0-6 items (page 1): read log once because when move to 2, 3, 4, 5 the page is the same
                    Only read the log when page move to 1-7 (page 2): 2nd read and so on
    6. The buffer ready in Log_Data_7[7]
    7. Information need to check when have LOGs:
*/
unsigned int log01CountNum_i        = 0; /*Count all number of LOG to display in list*/
unsigned int Pre_log01CountNum_i = 9999;
unsigned int log01HighlightItem_i   = 0; /*Highlight position*/

uint16_t Log4K_Log7_TopNum = 0;         // LogNum at Log4K mapping to Log7_Top
uint16_t Log4K_Log7_BottomNum = 0;      // LogNum at Log4K mapping to Log7_Bottom
uint16_t GUI_LogNum = 0;                // currently pointed to Log Number
uint16_t GUI_LogNumIdx = 0;             // currently pointed to Log Number's index at LOG4K array
uint16_t LogNumToRead = 0;              // the idx for LogRead(idx)

void Log01PageResetCounterDisplay(void)
{
    log01CountNum_i      = 0;
    Pre_log01CountNum_i  = 9999;
    log01HighlightItem_i = 0;
    DEV_Rec.LogNumDisp = 0;

    Log4K_Log7_TopNum = 0;           // LogNum at Log4K mapping to Log7_Top
    Log4K_Log7_BottomNum = (Log4K_Log7_TopNum + MaxItemInList);     // LogNum at Log4K mapping to Log7_Bottom
    GUI_LogNum = (DEV_Rec.LogNumRecorded - DEV_Rec.LogNumDisp);     // currently pointed to Log Number
    GUI_LogNumIdx = DEV_Rec.LogNumDisp;

    // Read EEPROM and FLASH for saved LOG data
    GUI_LOG_NumLast =  DEV_Rec.LogNumLast;

    ReadLog(Log4K_Log7_TopNum);
}
void HandleButtonLOG_1(DSX_OPCODE_t* newOpVal, DSX_OPCODE_t* oldOpVal)
{
    if(LogMenu_CheckLogIsEmpty())
    {
        /*When empty list no progress*/
    }
    else
    {
        switch(*newOpVal)
        {
        case DataInc:
            /*
            Set the data buffer to display in page
            Press up && Highlight == 0 && Counter != 0
            */

            /*Progress Counter*/
            if(GUI_LogNumIdx > 0)
            {
                GUI_LogNumIdx--;
                DEV_Rec.LogNumDisp--;
                GUI_LogNum = (DEV_Rec.LogNumRecorded - GUI_LogNumIdx);         // currently pointed to Log Number

                if(GUI_LogNumIdx < Log4K_Log7_TopNum)
                {
                    // Log4K_Log7_TopNum and Log4K_Log7_BottomNum always move upward or downward together, same direction, same steps
                    Log4K_Log7_TopNum--;
                    Log4K_Log7_BottomNum = (Log4K_Log7_TopNum + MaxItemInList);     // LogNum at Log4K mapping to Log7_Bottom
                    ReadLog(Log4K_Log7_TopNum);
                }
            }
            else
            {
                // Do Nothing, no response at LOG Menu
            }

            if(log01CountNum_i != 0U)
            {
                log01CountNum_i--;
            }
            else
            {
                /*Keep 0 value*/
            }
            /*Check the highlight item*/
            if(log01HighlightItem_i > 0U)
            {
                log01HighlightItem_i--;
            }
            else
            {
                /*Keep LOG01_MAX_HIGHLIGHT value*/
            }
            /*Return the opcode*/
            *newOpVal = *oldOpVal;
            break;
        case DataDec:
            /*
            Set the data buffer to display in page
            Press up && Highlight == 0 && Counter != 0
            */

            /*Progress Counter*/
            if(GUI_LogNumIdx < DEV_Rec.LogNumRecorded - 1)
            {
                GUI_LogNumIdx++;
                DEV_Rec.LogNumDisp++;
                GUI_LogNum = (DEV_Rec.LogNumRecorded - GUI_LogNumIdx);         // currently pointed to Log Number

                if(GUI_LogNumIdx > Log4K_Log7_BottomNum)
                {
                    // Log4K_Log7_TopNum and Log4K_Log7_BottomNum always move upward or downward together, same direction, same steps
                    Log4K_Log7_TopNum++;
                    Log4K_Log7_BottomNum = (Log4K_Log7_TopNum + MaxItemInList);     // LogNum at Log4K mapping to Log7_Bottom
                    ReadLog(Log4K_Log7_TopNum);
                }
            }
            else
            {
                // Do Nothing, no response at LOG Menu
            }


            if(log01CountNum_i < (GUI_LOG_NumLast - 1))
            {
                log01CountNum_i++;
            }
            else
            {
                /*Keep the last of LOG number*/
            }
            /*Check the highlight item*/
            if((log01HighlightItem_i < LOG01_MAX_HIGHLIGHT)&&(log01HighlightItem_i < (GUI_LOG_NumLast - 1)))
            {
                log01HighlightItem_i++;         // [ 0 ~ 6 ]as the index of Log_Data_7 in display
            }
            else
            {
                /*Keep LOG01_MAX_HIGHLIGHT value*/
            }
            /*Return the opcode*/
            *newOpVal = *oldOpVal;
            break;
        default:
            break;
        }
        /*Everytime the counter change -> Update the GUI*/
    }
}

