/******************************************************************************/
// File: My Info
// Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "../ContextMainMenuCfg.h"
#include "Menu_MainMenu_Info.h"
#include "Menu_MainMenu_Info_DSXINFO.h"
#include "../../../../../../DSX/DSX_Version.h"

static const TxtStr_Name_e TxtDef_DSXInfo[DSXInfo_MAX] =
{
    TxtStr_MODEL,
    TxtStr_SERIAL,
    TxtStr_FIRMWARE,
    TxtStr_LAST_CAL,
    TxtStr_BLUETOOTH_NAME,
};
// Input data
static const pstrHandle_Func pFunHandleDSXInforRight[DSXInfo_MAX] =
{
    DSXInfo_Model,
    DSXInfo_SerialNum,
    DSXInfo_Firmware,
    DSXInfo_LastCalibarate,
    DSXInfo_BTDeviceName,
};
void IniOrClrScrFunc_S190_IM_DSXINFO_SET(void)
{
    GUI_MEMDEV_Handle hmemLocal;
    char strLocal[LangMaxLength];
    DisplayText_TopBar_Title(GUI_LANG_GetText(TxtStr_DSX_INFO));
    /*MODEL*/
    SetFont_3;
    for (uint8_t i_u8 = 0; i_u8 < DSXInfo_MAX; i_u8++)
    {
        hmemLocal = GUI_MEMDEV_CreateEx(Pos_Item_Select_List->X0, (i_u8 * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0, Pos_Item_Select_List->Width, Pos_Item_Select_List->Height, GUI_MEMDEV_HASTRANS);
        GUI_MEMDEV_Select(hmemLocal);
        GUI_ClearRect(Pos_Item_Select_List->X0, (i_u8 * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0, Pos_Item_Select_List->X1, (i_u8 * Pos_Item_Select_List->Height) + (Pos_Item_Select_List->Y1));
        GUI_SetTextAlign(GUI_TA_LEFT);
        GUI_SetColor(TxtColor_UnSelect);
        /*Dipsplay MODEL*/
        GUI_DispStringAt(GUI_LANG_GetText(TxtDef_DSXInfo[i_u8]), Pos_Item_Select_List->X0, (i_u8 * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0);
        GUI_SetTextAlign(GUI_TA_CENTER);
        GUI_DispStringAt(":", Pos_Item_Select_List->X, (i_u8 * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0);
        GUI_SetColor(TxtColor_Select);
        GUI_SetTextAlign(GUI_TA_RIGHT);
        pFunHandleDSXInforRight[i_u8](strLocal);
        GUI_DispStringAt(strLocal, Pos_Item_Select_List->X1, (i_u8 * Pos_Item_Select_List->Height) + Pos_Item_Select_List->Y0);
        GUI_MEMDEV_CopyToLCD(hmemLocal);
        GUI_MEMDEV_Delete(hmemLocal);
    }
}
/*Data display handle*/
static void DSXInfo_Model(char *pStrRet)
{
    strcpy(pStrRet, "DSX");
}
static void DSXInfo_SerialNum(char *pStrRet)
{
    sprintf(pStrRet, "%06x", MFG_Calib.SN.SerialNum);
}
static void DSXInfo_Firmware(char *pStrRet)
{
    STR_FW_VERSION(pStrRet);
}
static void DSXInfo_LastCalibarate(char *pStrRet)
{
    if (NVD_MD == GUI_MMDD_Format)
    {
        sprintf(pStrRet, "%d/%.2d/20%.2d",
                MFG_Calib.Date.Month,      /*Month*/
                MFG_Calib.Date.Day, /*Day*/
                MFG_Calib.Date.Year /*Year*/
               );
    }
    else
    {
        sprintf(pStrRet, "%.2d/%d/20%.2d",
                MFG_Calib.Date.Day, /*Day*/
                MFG_Calib.Date.Month,      /*Month*/
                MFG_Calib.Date.Year /*Year*/
               );
    }
}
static void DSXInfo_BTDeviceName(char *pStrRet)
{
    sprintf(pStrRet, "%c%c%06X", MFG_Calib.Prefix[0], MFG_Calib.Prefix[1], MFG_Calib.SN.SerialNum);
}
