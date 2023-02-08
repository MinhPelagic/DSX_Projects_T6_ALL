/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#include "Compass_Main.h"

static void SubFunc_CompassRefDisplay(uint16_t Val)
{
    /*Display the content in normal*/
    if(headingReference==GUI_CompassHeadingStat)        // to process the Reference Dot's Color
    {
        // Reference Dot's Color
        GUI_SetColor(GUI_GREEN);
        GUI_AA_FillCircle(Pos_CompassMainArrayRotate[Val].x, Pos_CompassMainArrayRotate[Val].y + 82, 6);
    }
    else if(headingReverse==GUI_CompassHeadingStat)     // to process the Reverse and Reference Dots' Colors
    {
        // Reverse Dot's Color
        GUI_SetColor(GUI_RED);
        GUI_AA_FillCircle(Pos_CompassMainArrayRotate[Val].x, Pos_CompassMainArrayRotate[Val].y + 82, 6);
    }
}
static compassReference_ts SubFunc_CompassRefCalculate(int currentValue, int referenceValue)
{
    compassReference_ts valRet;
    //int8_t Direction = 0;       // -1: Arrows point to Right;    0: No Arrow;    1: Arrows point to Left

    /*Update the Aarow Directions with respect to Reference or Reverse direction handled by Display_NavigateArrows( ) */
    if((referenceValue >= 0)&&(referenceValue < 180))
    {
        if((currentValue == referenceValue)||(currentValue == (referenceValue+180)))            // currentValue and referenceValue alighted on the same line
            valRet.arrowReferDirection  = arrowReferNone;
        else if((currentValue > (referenceValue)) && (currentValue < (referenceValue+180)))     // currentValue at referenceValue's right side
        {
            if(currentValue > (referenceValue+10))
                valRet.arrowReferDirection  = arrowReferLeft;
            else
                valRet.arrowReferDirection  = arrowReferNone;
        }
        else                                                                                    // currentValue at referenceValue's left side
        {
            if( (currentValue < (referenceValue-10))
                    ||((currentValue > referenceValue)&&(currentValue < (referenceValue+360-10))) )
                valRet.arrowReferDirection  = arrowReferRight;
            else
                valRet.arrowReferDirection  = arrowReferNone;
        }
    }
    else if((referenceValue >= 180)&&(referenceValue <= 359))
    {
        if((currentValue == referenceValue)||(currentValue == (referenceValue-180)))
            valRet.arrowReferDirection  = arrowReferNone;
        else if((currentValue < referenceValue) && (currentValue > (referenceValue-180)))
        {
            if(currentValue < (referenceValue-10))
                valRet.arrowReferDirection  = arrowReferRight;
            else
                valRet.arrowReferDirection  = arrowReferNone;
        }
        else
        {
            if( (currentValue > (referenceValue+10))
                    ||((currentValue < referenceValue)&&(currentValue > (referenceValue-360+10))) )
                valRet.arrowReferDirection  = arrowReferLeft;
            else
                valRet.arrowReferDirection  = arrowReferNone;
        }
    }


    /* Update the Process for Reference and Reverse Dots in SubFunc_CompassRefDisplay( ) */
    if(currentValue>referenceValue)
    {
        valRet.referDegree          = (currentValue - referenceValue);
    }
    else if(currentValue<referenceValue)
    {
        valRet.referDegree          = 359 + (currentValue - referenceValue);
    }
    else
    {
        valRet.referDegree          = 359;
    }

    return valRet;
}
void CompassHandle_DisplayTheDotReferenceAndReverse(int currentValue)
{
    compassReference_ts retVal = {0, arrowReferNone};
    /*Validate the heading mode*/
    if(GnssStatus!=GNSS_ON)
    {
        if((headingReference==GUI_CompassHeadingStat)||(headingReverse==GUI_CompassHeadingStat))
        {
            if(headingReference==GUI_CompassHeadingStat)
            {
                /*value progress reference/reverse*/
                retVal = SubFunc_CompassRefCalculate(currentValue, GUI_CompassReferenceHeadingDegree);
                /*Display the dot referenc and reverse*/
                SubFunc_CompassRefDisplay(retVal.referDegree);
            }
            else if(headingReverse==GUI_CompassHeadingStat)
            {
                /*value progress reverse*/
                retVal = SubFunc_CompassRefCalculate(currentValue, GUI_CompassReverseHeadingDegree);
                /*Display the dot referenc and reverse*/
                SubFunc_CompassRefDisplay(retVal.referDegree);
            }
        }
    }
    else
    {
        /*value progress reference/reverse*/
        retVal = SubFunc_CompassRefCalculate(currentValue, (uint16_t)GnssGGA.Target_Direction);
        /*Display the dot referenc and reverse*/
        SubFunc_CompassRefDisplay((uint16_t)GnssGGA.Target_Direction);
    }
    /*display/removed the arrow*/
    Display_NavigateArrows(retVal.arrowReferDirection);
}
