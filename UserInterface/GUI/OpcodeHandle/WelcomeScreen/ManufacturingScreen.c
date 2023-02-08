#include "L4X9_includes.h"

extern GUI_CONST_STORAGE GUI_BITMAP bmDSXmanufacturerscreen;

void IniOrClrScrFunc_MANUFACTURE_SCREEN(void)
{
    GUI_DrawBitmap(&bmDSXmanufacturerscreen, 0, 0);
}
