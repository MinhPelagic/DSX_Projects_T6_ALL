#include "L4X9_includes.h"
#include "DiveMode.h"

/*ALARM displayed at bottom*/
static void ALARM_AscentTooFast_Context(char* pStrRet)
{
    strcpy(pStrRet, GUI_LANG_GetText(TxtStr_ASCENT_TOO_FAST));
}
const contentDispContext_st ALARM_AscentTooFast =
{
    &ALARM_AscentTooFast_Context,
    &RED_TxtColor,
    GUI_TA_CENTER,
    &FontAaux_3,
    &Pos_ALARM_BottomInOneLine,
};
/*Return the status of Conditional Violation in both Dive/Surface*/
unsigned char AlarmStatusCheck_AscentTooFast(void)
{
    return (unsigned char)LCD_Flash.Bit.ASCBar;
};
