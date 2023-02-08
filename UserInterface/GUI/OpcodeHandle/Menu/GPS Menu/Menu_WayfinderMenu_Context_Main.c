/******************************************************************************/
//File: SET MENU -> GPS Menu -> WAYFINDER Menu
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_WayfinderMenu.h"
/*
pos: position of GPS location in database
*/
void WayfinderMenu_LocationContext(char* pStrRet, uint8_t pos)
{
    if(GPS_LOC_4K_To_GUI_WayFinder(pos)&&(pos < GPS_LOCATION_NUM_MAX))
    {
        if((GUI_WayFinder.GPS_Loc[pos].LocationName[0] == '\0')||(GUI_WayFinder.GPS_Loc[pos].LocationName[0] == 0xFF)) /*check if no location name*/
        {
            sprintf(pStrRet, "\xcb\x84 %.2d/%.2d/20%.2d - %.2d:%.2d",
                    GUI_WayFinder.GPS_Loc[pos].DateTime.Day, /*Day*/
                    GUI_WayFinder.GPS_Loc[pos].DateTime.Month, /*Month*/
                    GUI_WayFinder.GPS_Loc[pos].DateTime.Year, /*Year*/
                    GUI_WayFinder.GPS_Loc[pos].DateTime.Hour, /*Hour*/
                    GUI_WayFinder.GPS_Loc[pos].DateTime.Minute /*Minute*/
                   );
        }
        else
        {
            strcpy(pStrRet, GUI_WayFinder.GPS_Loc[pos].LocationName);
        }
    }
    else
    {
        strcpy(pStrRet, "---"); // Show n/a
    }
}
