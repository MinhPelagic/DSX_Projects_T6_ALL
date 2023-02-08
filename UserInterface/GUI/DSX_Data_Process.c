/******************************************************************************/
//File: Sepia_Data_Process.c
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2015 Initial
//
/*****************************************************************************/
//-------------------------------Global variables------------------------------------------
#include "L4X9_includes.h"

//--------------------------------------------------------------------------------------

//-------------------------------Extern variables------------------------------------------
extern uint8_t MidNight;
uint8_t in_buf[100];
uint16_t Compass_vala, Compass_val0, Compass_val1, Compass_val2, Compass_val3;

GUI_POINT BarRight_L1[]= {//Bar on the right level 1
    {0,0},
    {-5,0},
    {-6,-28},
    {0,-28},
};
GUI_POINT BarRight_L2[]= {
    {0,0},
    {-6,0},
    {-7,-28},
    {0,-28},
};
GUI_POINT BarRight_L3[]= {
    {0,0},
    {-7,0},
    {-8,-28},
    {0,-28},
};
GUI_POINT BarRight_L4[]= {
    {0,0},
    {-8,0},
    {-9,-28},
    {0,-28},
};
GUI_POINT BarRight_L5[]= {
    {0,0},
    {-9,0},
    {-11,-28},
    {0,-28},
};
GUI_POINT BarLeft_L1[]= {//Bar on the right level 1
    {0,0},
    {+5,0},
    {+6,-28},
    {0,-28},
};
GUI_POINT BarLeft_L2[]= {//Bar on the right level 2
    {0,0},
    {+6,0},
    {+7,-28},
    {0,-28},
};
GUI_POINT BarLeft_L3[]= {//Bar on the right level 3
    {0,0},
    {+7,0},
    {+8,-28},
    {0,-28},
};
GUI_POINT BarLeft_L4[]= {//Bar on the right level 4
    {0,0},
    {+8,0},
    {+9,-28},
    {0,-28},
};
GUI_POINT BarLeft_L5[]= {//Bar on the right level 5
    {0,0},
    {+9,0},
    {+11,-28},
    {0,-28},
};
//--------------------------------------------------------------------------------------
#if 0
void DatProc_CommonItem(ItemName_te ItemNameVar, char* p_String) {
    char StringReturn[5]= {0}; //Need this buffer to use for sprintf fucntion
//    static uint8_t Previous_Temper;
//    static uint8_t Previous_Battery;
//    static uint8_t Previous_DESATTime;
//    static uint8_t Previous_FLYTime;
//    uint8_t Item_Staus;
    /*Clock -> Hour*/
    switch(ItemNameVar) {
    case Item_TopBar_Clock_Hour:
        //StringReturn=HourProcess(Bcd2ToByte(Hour), (HRType != BIT_0));
        break;

    case Item_TopBar_Clock_AMPM:
        //sprintf(StringReturn,"%s",((MidNight==BIT_7) ? "P" : "A"));
        break;
    /*Temperature*/
    default:
        //Do nothing
        break;
    }
    strcpy(p_String, StringReturn);
//    return Item_Staus;
}
#endif
const char* HourProcess(uint8_t HourValue, int ClockFormat, int HourFormat) {
    /*
    ClockFormat:
    12h: FALSE
    24h: TRUE
    MidNightFormat
    AM: TRUE
    PM: FALSE
    */
    static char StringReturn[3];
    if(ClockFormat==TRUE) {
        /*12Hour format*/
        sprintf(StringReturn,"%d",HourValue);
    }
    else {
        /*24Hour format*/
        if(TRUE==HourFormat) {
            /*When the time present is AM*/
            if(12==HourValue) {
                /*When AM and 24h format display 00 otherwise display value hour + 12*/
                sprintf(StringReturn,"0");
            }
            else {
                sprintf(StringReturn,"%d",HourValue);
            }
        }
        else {
            /*When the time present is PM*/
            if(12==HourValue) {
                sprintf(StringReturn,"%d",12);
            }
            else {
                /*Plus 12 to display correct value*/
                sprintf(StringReturn,"%d",HourValue+12);
            }
        }
    }
    return StringReturn;
}
const char* MinsProcess(uint8_t MinsValue) {
    static char StringReturn[3];
    sprintf(StringReturn,"%.2d ", MinsValue);
    return StringReturn;
}
const char* MidnightProcess(int MidnightFlag, int TimeFormatFlg) {
    static char StringReturn[3];
    if(TimeFormatFlg==TRUE) {
        sprintf(StringReturn,"%s", (MidnightFlag==TRUE) ? "PM" : "AM");
    }
    else {
        StringReturn[0]=0;
        StringReturn[1]=0;
    }
    return StringReturn;
}

/*
Data process USB charing
Return the color and percented value of baterry
*/
void DatProc_USBCharging(uint16_t *TxtColor, uint16_t *BGColor) {
    //char StringReturn[200] = {0}; //Need this buffer to use for sprintf fucntion
    //*TxtColor = Black;
    // if(USB_ChargingValue > 15) {
    //     //*BGColor = Green;
    // }
    // else if(USB_ChargingValue < 1) {
    //     //*BGColor= Red;
    // }
    // else {
    //     //*BGColor= Yellow;
    // }
    //sprintf(StringReturn,"%d%%", USB_ChargingValue);
}

uint8_t Bcd2ToByte(uint8_t Value)
{
    uint8_t tmp = 0;
    tmp = ((uint8_t)(Value & (uint8_t)0xF0) >> (uint8_t)0x4) * 10;
    return (tmp + (Value & (uint8_t)0x0F));
}
//http://prntscr.com/am3am4
//Why not send 0, 1, 2, 3, 4, 5, 6, 7?
uint8_t AltitudeProcess(uint8_t X) {
    X++;
    X = X >> 1;
    if((X == 0) || (X== 1)) {
        X = 0;
    }
    if(X>7) {
        X = 7;
    }
    return X;
}

