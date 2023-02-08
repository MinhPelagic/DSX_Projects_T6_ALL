/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Menu_MainMenu_Info.h"

/*Struct required to get data from EEPROM*/
typedef struct
{
    uint32_t address; /*Address*/
    int width;        /*Width of bmp to display*/
    int height;       /*Width of bmp to display*/
    int x0;           /*x0*/
    int y0;           /*y0*/
} bmpInforToDisplay_ts;
/**/
void DisplayBmpFromEEPROM(bmpInforToDisplay_ts datInfo);
