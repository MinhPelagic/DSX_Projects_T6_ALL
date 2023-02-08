
#include "L4X9_includes.h"
#include "..\..\..\ButtonHandle\DSX_ButtonHandle.h"
#include "DiveMode.h"
void ClearPortionToUpdateDiveMode(void)
{
    GUI_SetBkColor(GUI_BLACK);
    GUI_ClearRect(Pos_DiveClearToUpdate_1->X0, Pos_DiveClearToUpdate_1->Y0, Pos_DiveClearToUpdate_1->X1, Pos_DiveClearToUpdate_1->Y1);
    GUI_ClearRect(Pos_DiveClearToUpdate_2->X0, Pos_DiveClearToUpdate_2->Y0, Pos_DiveClearToUpdate_2->X1, Pos_DiveClearToUpdate_2->Y1);
    GUI_ClearRect(Pos_DiveClearToUpdate_3_onTheBottomLeft->X0, Pos_DiveClearToUpdate_3_onTheBottomLeft->Y0, Pos_DiveClearToUpdate_3_onTheBottomLeft->X1, Pos_DiveClearToUpdate_3_onTheBottomLeft->Y1);
}
void ClearPortionToUpdateAlarm(void)
{
    GUI_ClearRect(Pos_DiveClearToUpdate_3_onTheBottomLeft->X0, Pos_DiveClearToUpdate_3_onTheBottomLeft->Y0, Pos_DiveClearToUpdate_3_onTheBottomLeft->X1, Pos_DiveClearToUpdate_3_onTheBottomLeft->Y1);
    GUI_ClearRect(Pos_DiveClearToUpdate_4_onTheBottomRight->X0, Pos_DiveClearToUpdate_4_onTheBottomRight->Y0, Pos_DiveClearToUpdate_4_onTheBottomRight->X1, Pos_DiveClearToUpdate_4_onTheBottomRight->Y1);
}
void ClearPortionOCLeftRight(void)
{
    GUI_ClearRect(Pos_SURF_Temperature_TxtTitle->X0, Pos_SURF_Temperature_TxtTitle->Y0, Pos_SURF_Temperature_Value->X1, Pos_SURF_Temperature_Value->Y1);
}
void ClearPortionCCLeftRight(void)
{
    GUI_ClearRect(Pos_SURFT_FO2->X1, Pos_SURFT_FO2->Y0, Pos_SURFT_Pressure_Value->X0, Pos_SURFT_Pressure_Value->Y1);
}
/*Clear middle row of 3rd row right and center*/
void ClearPortion_DiveSM_MiddleRowTitte(void)
{
    GUI_ClearRect(Pos_SURFT_3rdRowLeft_TxtTittle->X0, Pos_SURFT_3rdRowLeft_TxtTittle->Y0, Pos_SURFT_3rdRowLeft_TxtTittle->X1, Pos_SURFT_3rdRowLeft_TxtTittle->Y1);
    GUI_ClearRect(Pos_SURFT_PO2_TxtTittle->X0, Pos_SURFT_PO2_TxtTittle->Y0, Pos_SURFT_PO2_TxtTittle->X1, Pos_SURFT_PO2_TxtTittle->Y1);
}
/*gas time remaining -> clear after flashing alarm in the bottom*/
void ClearPortion_GTRDisplay(void)
{
    GUI_ClearRect(Pos_SURF_Time_TxtTittle->X0, Pos_SURF_Time_TxtTittle->Y0, Pos_SURF_Time_TxtTittle->X1, Pos_SURF_Time_TxtTittle->Y1);
    GUI_ClearRect(Pos_Dive_OC_GTR_Value->X0, Pos_Dive_OC_GTR_Value->Y0, Pos_Dive_OC_GTR_Value->X1, Pos_Dive_OC_GTR_Value->Y1);
}
/*Clear portion display CC when Violation*/
void ClearPortion_CC_PO23rdRowLeftRight(void)
{
    GUI_ClearRect(Pos_SURFT_3rdRowLeft_TxtTittle->X0, Pos_SURFT_3rdRowLeft_TxtTittle->Y0, Pos_SURFT_3rdRowRight_Value->X1, Pos_SURFT_3rdRowRight_Value->Y1);
}
void ClearPortion_3rdContentRight(void)
{
    /*3rd Row Right*/
    GUI_ClearRect(Pos_SURFT_3rdRowRight_TxtTittle->X0, Pos_SURFT_3rdRowRight_TxtTittle->Y0, Pos_SURFT_3rdRowRight_Value->X1, Pos_SURFT_3rdRowRight_Value->Y1);
}
void ClearPortion_3rdContentLeft(void)
{
    /*3rd Row Left*/
    GUI_ClearRect(Pos_SURFT_3rdRowLeft_TxtTittle->X0, Pos_SURFT_3rdRowLeft_TxtTittle->Y0, Pos_SURFT_3rdRowLeft_Value->X1, Pos_SURFT_3rdRowLeft_Value->Y1);
}
void ClearPortion_PO2MiddleCenter(void)
{
    GUI_ClearRect(Pos_SURFT_PO2_TxtTittle->X0, Pos_SURFT_PO2_TxtTittle->Y0, Pos_SURFT_PO2_Value->X1, Pos_SURFT_PO2_Value->Y1);
}
/*clear the portion when Violation extra large depth*/
void ClearPortion_BelowSurfaceTime(void)
{
    GUI_ClearRect(Pos_SURFT_LastDive_TxtTitle->X0, Pos_SURFT_LastDive_TxtTitle->Y0, Pos_SURFT_LastDive_Content->X1, Pos_SURFT_LastDive_Content->Y1);
}
/*Clear tank pressure*/
void ClearPortion_TankPressure(void)
{
    GUI_ClearRect(Pos_SURFT_Pressure_TxtTittle->X0, Pos_SURFT_Pressure_TxtTittle->Y0, Pos_SURFT_Pressure_Value->X1, Pos_SURFT_Pressure_Value->Y1);
}
/*Clear content when next to Pos_SURFT_TMT */
void ClearPortion_NextToBottomSurfTMT(void)
{
    GUI_ClearRect(Pos_SURFT_TMT->X1, Pos_SURFT_TMT->Y0, Pos_SURF_Temperature_TxtTitle->X1, Pos_SURF_Temperature_Value->Y1);
}
/*Clear content when next to Pos_SURFT_TMT */
void ClearPortion_GSM_PortionAVGvsMaxDepth(void)
{
    GUI_ClearRect(Pos_SURFT_AVGDepth_TxtTittle->X1, Pos_SURFT_AVGDepth_TxtTittle->Y0, Pos_SURFT_DESAT_Content->X0, Pos_SURFT_DESAT_Content->Y1);
}
/**
 * @brief
 *
 */
void ClearPortion_BottomAlarmFull(void)
{
    GUI_ClearRect(Pos_SURFT_FO2->X0, Pos_SURFT_FO2->Y0, Pos_DiveClearToUpdate_1->X1, Pos_DiveClearToUpdate_2->Y1);
}
/**
 * @brief
 *
 */
void ClearPortionToUpdateSurfaceMode(void)
{
    GUI_ClearRect(Pos_DiveClearToUpdate_3_onTheBottomLeft->X0, Pos_DiveClearToUpdate_1->Y0, Pos_GFBar->X0, Pos_DiveClearToUpdate_2->Y1);
}
/**
 * @brief Clear 02 vertical parts left and right in menu
 * to prevent screen not clear after back menu
 */
void ClearPortionAfterUpdateMenuInList(void)
{
    const int16_t Y0 = Pos_Item_Select_List->Y0 + (MaxItemInList * Pos_Item_Select_List->Height);
    GUI_ClearRect(0, Pos_Item_Select_List->Y0, Pos_Item_Select_List->X0, Y0);
    GUI_ClearRect(Pos_Item_Select_List->X1, Pos_Item_Select_List->Y0, Pos_GFBar->X1, Y0);
}
/**
 * @brief Clear porition to tank pressure display in Compass
 *
 */
void ClearPortion_CompassMode_TankPressure(void)
{
    GUI_ClearRect(Pos_Compass_TankPressure_Tittle->X0, Pos_Compass_TankPressure_Tittle->Y0, Pos_Compass_TankPressure_Value->X1, Pos_Compass_TankPressure_Value->Y1);
}