#include "L4X9_includes.h"
#include "BatteryChargingCfg.h"

/*The battery on the right*/
#define battdim_a               26  //Height
#define battdim_b               7   //Middle weight
#define battdim_c               6   //Width
#define battdim_2a              (battdim_a*2)
#define battdim_2c              (battdim_c*2)
#define battdim_3c              (battdim_c*3)
#define battdim_x0              (167U)
#define battdim_y0              (67U)
#define battPercentVal_x0       (160U)
#define battPercentVal_y0       (167U)
/**/
static const GUI_POINT BatteryCharging_Point[]=
{
    {-battdim_3c, battdim_a + battdim_b},
    {-battdim_c, battdim_a + battdim_b},
    {-battdim_2c, battdim_2a + battdim_b},
    {+battdim_c, battdim_a},
    {-battdim_c, battdim_a},
    {0, 0},
};
#define battdim_bigRect_width               (60U)
#define battdim_bigRect_height              (120U)
#define battdim_smallRect_width             (22U)
#define battdim_smallRect_height            (16U)
#define battdim_smallRect_y0                (20U)
#define battdim_smallRect_x0                (160U-(battdim_smallRect_width/2U))
#define battdim_smallRect_x1                (battdim_smallRect_x0+battdim_smallRect_width)
#define battdim_smallRect_y1                (battdim_smallRect_y0+battdim_smallRect_height)
#define battdim_bigRect_x0                  (160U-(battdim_bigRect_width/2U))
#define battdim_bigRect_y0                  (battdim_smallRect_y1)
#define battdim_bigRect_x1                  (battdim_bigRect_x0+battdim_bigRect_width)
#define battdim_bigRect_y1                  (battdim_bigRect_y0+battdim_bigRect_height)
#define battdim_Rect_R                      (3U)
#define battdim_Pensize                     (6U)
#define battdim_fillRect_x0                 (battdim_bigRect_x0+10u)
#define battdim_fillRect_y0                 (battdim_bigRect_y0+10u)
#define battdim_fillRect_x1                 (battdim_bigRect_x1-10u)
#define battdim_fillRect_y1                 (battdim_bigRect_y1-10u)
/**/
static void dispBattValue(void)
{
    char strRet[50];
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    sprintf(strRet, "   %d%%   ", SystemSupplyMonitor.Battery_Percentage);
    GUI_SetFont(&FontAaux_5);
    GUI_SetTextAlign(GUI_TA_CENTER);
    GUI_DispStringAt(strRet, battPercentVal_x0, battPercentVal_y0);
}
/*Set color battery base on the value*/
GUI_COLOR Battery_SetColorBaseOnValue(uint8_t battVal)
{
    GUI_COLOR Color_Batt;
    /*Draw the level inside*/
    if(battVal<=BATT_LEVEL_ALARM) // changed from '<' to '<=' to be consistent with Backlight_Set control, by YS 2022/04/12
    {
        Color_Batt = GUI_RED;
    }
    else if(battVal>BATT_LEVEL_WARNING)
    {
        Color_Batt = GUI_GREEN;
    }
    else
    {
        Color_Batt = GUI_YELLOW;
    }
    return Color_Batt;
}
static void fillBattColor(void)
{
    /*memdev progress*/
    GUI_MEMDEV_Handle hMemDevLocal;
    hMemDevLocal = GUI_MEMDEV_CreateEx(battdim_fillRect_x0, battdim_fillRect_y0, battdim_fillRect_x1-battdim_fillRect_x0, battdim_fillRect_y1-battdim_fillRect_y0, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    /*set battery color*/
    const GUI_COLOR battBkColor = Battery_SetColorBaseOnValue(SystemSupplyMonitor.Battery_Percentage);
    GUI_SetBkColor(battBkColor);
    GUI_ClearRect(battdim_fillRect_x0, battdim_fillRect_y0, battdim_fillRect_x1, battdim_fillRect_y1);
    /*Draw the charging symbol*/
    GUI_SetColor(GUI_BLACK);
    GUI_AA_FillPolygon(BatteryCharging_Point, (sizeof(BatteryCharging_Point)/sizeof(GUI_POINT)), battdim_x0, battdim_y0);
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
void IniOrClrScrFunc_B1_BATT_CHARGE(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    /*Draw the outline*/
    GUI_SetColor(GUI_WHITE);
    GUI_SetPenSize(battdim_Pensize);
    GUI_AA_DrawRoundedRect(battdim_smallRect_x0, battdim_smallRect_y0, battdim_smallRect_x1, battdim_smallRect_y1, battdim_Rect_R);
    GUI_AA_DrawRoundedRect(battdim_bigRect_x0, battdim_bigRect_y0, battdim_bigRect_x1, battdim_bigRect_y1, battdim_Rect_R);
    /*Display the value*/
    dispBattValue();
    /*Fill the level*/
    fillBattColor();
}
void UpdOrFlasFunc_B1_BATT_CHARGE(void)
{
    /*Display the value*/
    dispBattValue();
    /*Fill the level*/
    fillBattColor();
}
