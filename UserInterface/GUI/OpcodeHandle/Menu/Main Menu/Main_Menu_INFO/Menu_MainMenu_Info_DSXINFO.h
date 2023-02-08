#ifndef __MENU_DSX_INFO__
#define __MENU_DSX_INFO__
/******************************************************************************/
//File: My Info
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"

enum DSXInfo_e
{
    DSXInfo_MODEL			= 0x00,
    DSXInfo_SERIALNUM,
    DSXInfo_FIRMWARE,
    DSXInfo_LASTCALIBRATION,
    DSXInfo_BTDIVICENAME,
    DSXInfo_MAX,
};
static void DSXInfo_Model(char* pStrRet);
static void DSXInfo_SerialNum(char* pStrRet);
static void DSXInfo_Firmware(char* pStrRet);
static void DSXInfo_LastCalibarate(char* pStrRet);
static void DSXInfo_BTDeviceName(char* pStrRet);

#endif