#include "SurfaceMode.h"

#define BATT_FULL_SCALE		33	//The number of pixel height when battery is 100%
#define BATT_END_SCALE		57	//The number of pixel height when battery is 0%
#define BATT_LEVEL_SCALE	(BATT_END_SCALE - BATT_FULL_SCALE)

/*The battery on the right*/
#define battdim_a       12  //Height
#define battdim_b       3   //Middle weight
#define battdim_c       2   //Width
#define battdim_2a      (battdim_a*2)
#define battdim_2c      (battdim_c*2)
#define battdim_3c      (battdim_c*3)
static const GUI_POINT BatteryCharging_Point[]=
{
    {-battdim_3c, battdim_a + battdim_b},
    {-battdim_c, battdim_a + battdim_b},
    {-battdim_2c, battdim_2a + battdim_b},
    {+battdim_c, battdim_a},
    {-battdim_c, battdim_a},
    {0, 0},
};
#define YBatteryGraphic             -25//The Y positon of battery need to display ()

void Display_Battery_Surface(void* pData_st)
{
    /*data struct input*/
    battInfo_st* battDataInput;
    battDataInput = (battInfo_st*) pData_st;
    /*get data*/
    unsigned char _battLevel = *(battDataInput->battValue);
    bool _battChargingStatus = battDataInput->battChargingStatus();
    /*memdev progress*/
    GUI_MEMDEV_Handle hMemDevLocal;
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_SurfaceBattery->X0, Pos_SurfaceBattery->Y0, Pos_SurfaceBattery->Width, Pos_SurfaceBattery->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_SurfaceBattery->X0, Pos_SurfaceBattery->Y0, Pos_SurfaceBattery->X1, Pos_SurfaceBattery->Y1);
    char pStrRet[LangMaxLength];
    /*Draw the level inside*/
    const GUI_COLOR Color_Batt = Battery_SetColorBaseOnValue(_battLevel);    /*Set batt color*/
    GUI_SetColor(Color_Batt);
    /*Display the value of battery*/
    SetFont_1;
    sprintf(pStrRet, "%d%%", _battLevel);
    GUI_DispStringHCenterAt(pStrRet, Pos_SurfaceBattery->X , Pos_SurfaceBattery->Y); // Plus 3 due to not using GUI_DM_TRANS mode instead of GUI_DM_NORMAL
    /*Draw the outline*/
    GUI_DrawRect(((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) - 3, 1, ((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) + 3, 5);
    GUI_DrawRect(((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) - 7, 5, ((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) + 7, 35);
    GUI_FillRect(((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) - 4,  (int)(8 + (((int)(100.0f-_battLevel)/100.0f)*BATT_LEVEL_SCALE)),\
                 ((Pos_SurfaceBattery->X1)-(Pos_SurfaceBattery->Width)/2) + 4, 32);
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
    /*Display the battery charging*/
    hMemDevLocal = GUI_MEMDEV_CreateEx(Pos_SurfaceBattery_Charging->X0, Pos_SurfaceBattery_Charging->Y0, Pos_SurfaceBattery_Charging->Width, Pos_SurfaceBattery_Charging->Height, GUI_MEMDEV_HASTRANS);
    GUI_MEMDEV_Select(hMemDevLocal);
    GUI_ClearRect(Pos_SurfaceBattery_Charging->X0, Pos_SurfaceBattery_Charging->Y0, Pos_SurfaceBattery_Charging->X1, Pos_SurfaceBattery_Charging->Y1);
    /*Batt charging detected*/
    if(_battChargingStatus)
    {
        /*Draw the charging icon*/
        GUI_SetColor(GUI_GREEN);
        GUI_AA_FillPolygon(BatteryCharging_Point, (sizeof(BatteryCharging_Point)/sizeof(GUI_POINT)), Pos_SurfaceBattery_Charging->X, Pos_SurfaceBattery_Charging->Y);
    }
    else
    {
        /*Do nothing*/
    }
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
