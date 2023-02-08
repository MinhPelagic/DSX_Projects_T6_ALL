
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
unsigned char CheckHadTheDiveYet(void)
{
    unsigned char retVal = FALSE;
    if(DEV_Rec.DiveNumOfDay > (uint16_t)0U)
    {
        retVal = TRUE;
    }
    else
    {
        /*Do nothing*/
    }
    return retVal;
}
/*
Check the display "NO DIVE YET" or Information of last dive
*/
void SurfaceMode_LastDiveHandle(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_LastDive_Tittle);
    /*Display the information of lastest dive*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_LastDive_OnLeft);
}
/*
Check the display "NO DIVE YET" or Information of last dive
-> Specifict to GSM mode
*/
void SurfaceMode_GSM_LastDiveHandle(void)
{
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_GSM_LastDive_Tittle);
    /*Display the information of lastest dive*/
    HandleDisplayTextWithMemdev(IteStat_Select, SurfaceMode_GSM_LastDiveInCenter);
}
