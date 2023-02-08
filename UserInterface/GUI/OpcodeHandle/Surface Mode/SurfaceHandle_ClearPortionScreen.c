
#include "L4X9_includes.h"
#include "SurfaceMode.h"
#include "SurfaceMode_Context.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"

void ClearPortionToUpdateOnSurface(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_SurfClearToUpdate_1->X0, Pos_SurfClearToUpdate_1->Y0, Pos_SurfClearToUpdate_1->X1, Pos_SurfClearToUpdate_1->Y1);
    GUI_ClearRect(Pos_SurfClearToUpdate_2->X0, Pos_SurfClearToUpdate_2->Y0, Pos_SurfClearToUpdate_2->X1, Pos_SurfClearToUpdate_2->Y1);
}
/*Clear all the part of screen*/
void ClearWholeScreen(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_GFBar->X0, Pos_GFBar->Y0, Pos_GFBar->X1, Pos_GFBar->Y1);
    GUI_ClearRect(Pos_ARBar->X0, Pos_ARBar->Y0, Pos_ARBar->X1, Pos_ARBar->Y1);
    GUI_ClearRect(Pos_SurfaceBattery->X0, Pos_SurfaceBattery->Y0, Pos_SurfaceBattery->X1, Pos_SurfaceBattery->Y1);
    GUI_ClearRect(Pos_SURF_CurrentPress_Value->X0, Pos_SURF_CurrentPress_Value->Y0, Pos_SURF_CurrentPress_Unit->X1, Pos_SURF_CurrentPress_Unit->Y1);
    GUI_ClearRect(Pos_SURF_PressAtActivation_Value->X0, Pos_SURF_PressAtActivation_Value->Y0, Pos_SURF_PressAtActivation_Unit->X1, Pos_SURF_PressAtActivation_Unit->Y1);
}
void ClearGasSwitchBottomLine_2(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_GasSwitch_BottomLine_2->X0, Pos_GasSwitch_BottomLine_2->Y0, Pos_GasSwitch_BottomLine_2->X1, Pos_GasSwitch_BottomLine_2->Y1);
}
/*Clear the portion of rectangle left in Compass mode*/
void ClearCompassReferencePortionOnBottomLeft(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_Compass_ReferenceHeading_Tittle->X0, Pos_Compass_ReferenceHeading_Tittle->Y0, Pos_Compass_ReferenceHeading_Value->X1, Pos_Compass_ReferenceHeading_Value->Y1);
}