/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"
static GUI_COLOR Codis_ColorMainCompassValue(int currentValue, int referenceValue);
/**/
void CoDis_DisplayCompassMainValue(int _Value)
{
    char pStrRet[LangMaxLength];
    GUI_MEMDEV_Handle hMemDevLocal;
    GUI_COLOR colorSet = GUI_GREEN;
    GUI_SetFont(&FontAaux_7);
    hMemDevLocal = GUI_MEMDEV_Create(Pos_Compass_MainValue->X0, Pos_Compass_MainValue->Y0, Pos_Compass_MainValue->Width, Pos_Compass_MainValue->Height);
    GUI_MEMDEV_Select(hMemDevLocal);
    /*Set color base on heading Reference/Reseved*/
    if(headingReference==GUI_CompassHeadingStat)
    {
        colorSet = Codis_ColorMainCompassValue(_Value, GUI_CompassReferenceHeadingDegree);
    }
    else if(headingReverse==GUI_CompassHeadingStat)
    {
        colorSet = Codis_ColorMainCompassValue(_Value, GUI_CompassReverseHeadingDegree);
    }
    else
    {
        /*Do nothing -> Keep defaul is GREEN*/
    }
    GUI_SetColor(colorSet);
    /*Display the compass value*/
    sprintf(pStrRet, "  %d°  ", _Value);
    GUI_DispStringHCenterAt(pStrRet, Pos_Compass_MainValue->X, Pos_Compass_MainValue->Y);
    /*send to lcd*/
    GUI_MEMDEV_CopyToLCD(hMemDevLocal);
    GUI_MEMDEV_Delete(hMemDevLocal);
}
/*Verify the compass value base on the LCD flip*/
int16_t CoDis_VerifyTheCompassValue(void)
{
    int16_t CompassDeg = 0;
    /*Display the compass degree value*/
    CompassDeg = EcData.AvgHeading+COMP_PELAGIC_DEG+360;    // needs to add 360 in case that (COMP_DEDLIN_DEG < 0)
    if(360<=CompassDeg)
    {
        CompassDeg %= 360;
    }
    CompassDeg = DirectionCorrection(CompassDeg);   // direction number quick correction for poor original degree alighment at easten and southen directions
    if(SWITCH_LCD_Flip==true)
        CompassDeg = CompassDeg+COMP_DEDLIN_DEG+180;        // if fliping
    else
        CompassDeg = CompassDeg+COMP_DEDLIN_DEG+360;        // if NO fliping, needs to add 360 in case that (COMP_DEDLIN_DEG < 0)
    if(360<=CompassDeg)
    {
        CompassDeg %= 360;
    }
    CompassDeg = SmoothingCompassDeg(CompassDeg);       // direction degree smoothing while DSX is placed at a stationary place and pointing to a fixed direction
    return CompassDeg;
}
/*Handle the color change of main compass value*/
static GUI_COLOR Codis_ColorMainCompassValue(int currentValue, int referenceValue)
{
    GUI_COLOR colorRet = GUI_YELLOW;

    /*When Heading in Reference "-10 to +10" Range -> GREEN*/
    if((referenceValue >= 10)&&(referenceValue <= 350))     // to process referenceValue between 10 to 350 degree, without crossing 360 => 0 overflow line
    {
        if((referenceValue <= 350) && (currentValue >= referenceValue) && (currentValue <= (referenceValue + 10)))        // check currentValue >= referenceValue and is within (referenceValue + 10)
        {
            if(headingReference==GUI_CompassHeadingStat)
                colorRet = GUI_GREEN;
            else if(headingReverse==GUI_CompassHeadingStat)
                colorRet = GUI_RED;
        }
        else if((referenceValue >= 10) && (currentValue <= referenceValue) && (currentValue >= (referenceValue - 10)))    // check currentValue <= referenceValue and is within (referenceValue - 10)
        {
            if(headingReference==GUI_CompassHeadingStat)
                colorRet = GUI_GREEN;
            else if(headingReverse==GUI_CompassHeadingStat)
                colorRet = GUI_RED;
        }
    }
    else if(referenceValue < 10)
    {
        if((currentValue <= referenceValue + 10) || (currentValue >= (referenceValue + 350)))        // check currentValue within referenceValue "-10 to +10" range
        {
            if(headingReference==GUI_CompassHeadingStat)
                colorRet = GUI_GREEN;
            else if(headingReverse==GUI_CompassHeadingStat)
                colorRet = GUI_RED;
        }
    }
    else if(referenceValue > 350)
    {
        if((currentValue <= referenceValue - 350) || (currentValue >= (referenceValue - 10)))        // check currentValue within referenceValue "-10 to +10" range
        {
            if(headingReference==GUI_CompassHeadingStat)
                colorRet = GUI_GREEN;
            else if(headingReverse==GUI_CompassHeadingStat)
                colorRet = GUI_RED;
        }
    }
    return colorRet;
}
