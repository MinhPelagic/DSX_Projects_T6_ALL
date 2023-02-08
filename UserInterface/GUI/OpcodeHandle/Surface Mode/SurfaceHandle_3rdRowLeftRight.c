
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "..\Menu\Display Settings\Menu_DisplaySettings.h"
#include "..\Dive Mode\DiveMode.h"

void Check3rdRowAfterDiveModeSwitch(void);

/*Check 3rd Row left display*/
unsigned char checkDisp3rdRowStatus(unsigned char currSetVal)
{
    unsigned char retStat = FALSE;
    /*if setting is valid -> This step verify that the settings is valid*/
    if ((currSetVal < _3rdRowSet_MAX) && (currSetVal > _3rdRowSet_BLANK))
    {
        /*special condition -> No display Fi02 and Dil PO2 in BO mode*/
        if (BO_MODE && ((_3rdRowSet_FiO2 == currSetVal) || (_3rdRowSet_DIL_PO2 == currSetVal)))
        {
            /*do nothing*/
        }
        else
        {
            retStat = TRUE;
        }
    }
    else
    {
        /*Do nothing*/
    }
    return retStat;
}
void SurfaceHandle_Display3rRowLeftContent(void)
{
    Check3rdRowAfterDiveModeSwitch();
    /*validate 3rd row left status*/
    const unsigned char stat3rdRow = checkDisp3rdRowStatus(GUI_MAINDISPLAY_3RD_ROW_LEFT);
    if (TRUE == stat3rdRow)
    {
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowLeft_Tittle);
        /*Display content*/
        SurfMode_3rdContentLeft[GUI_MAINDISPLAY_3RD_ROW_LEFT]();
    }
    else
    {
        /*Clean Up if NOT IN USE*/
        ClearPortion_3rdContentLeft();
    }
}
void SurfaceHandle_Display3rRowRightContent(void)
{
    Check3rdRowAfterDiveModeSwitch();
    /*validate 3rd row right status*/
    const unsigned char stat3rdRow = checkDisp3rdRowStatus(GUI_MAINDISPLAY_3RD_ROW_RIGHT);
    if (TRUE == stat3rdRow)
    {
        /*Tittle*/
        HandleDisplayTextWithMemdev(IteStat_ClearThenSelect, SurfaceMode_3rdRowRight_Tittle);
        /*Display content*/
        SurfMode_3rdContentRight[GUI_MAINDISPLAY_3RD_ROW_RIGHT]();
    }
    else
    {
        /*Clean Up if NOT IN USE*/
        ClearPortion_3rdContentRight();
    }
}
