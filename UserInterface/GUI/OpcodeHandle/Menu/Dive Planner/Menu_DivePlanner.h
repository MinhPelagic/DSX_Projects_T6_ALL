#include "L4X9_includes.h"
/*Define the setting Dive planner -> New or continuous*/
enum
{
    SettDivePlanner_NEW = 0U,
    SettDivePlanner_CONTINUOUS,
    SettDivePlanner_MAX,
};
extern const contentDispContext_st SetSP_UnitSet_Ctx;
extern const listItemInMenu_ts* DivePlannerMenu_ListOfContext[];
extern const contentDispContext_st DivePlanner_DepthLimit_Txt_MOD;
extern const contentDispContext_st DivePlanner_DepthLimit_Txt_HT;
extern const contentDispContext_st DivePlanner_DepthLimit_Txt_END;
extern const contentDispContext_st DivePlanner_DepthLimit_Txt_WOB;
extern const contentDispContext_st DivePlanner_DepthLimit_Val_MOD;
extern const contentDispContext_st DivePlanner_DepthLimit_Val_HT;
extern const contentDispContext_st DivePlanner_DepthLimit_Val_END;
extern const contentDispContext_st DivePlanner_DepthLimit_Val_WOB;
/*Dive simulator*/
extern const listItemInMenu_ts* DiveSimulator_ListOfContext[DIVEMODE_MAX];
extern const menuItemContext_ts Context_DiveSimulator_NEWORCONTINUOUS;
extern const menuItemContext_ts Context_DiveSimulator_DEPTH;
extern const menuItemContext_ts Context_DiveSimulator_TIME;
extern const menuItemContext_ts Context_DiveSimulator_SAC;
extern const menuItemContext_ts Context_DiveSimulator_SP;
extern const menuItemContext_ts Context_DiveSimulator_SIMULATEDIVE;
extern const contentDispContext_st DiveSimulator_NewOrContinous_Context;
extern const contentDispContext_st DiveSim_PlanPage_NODECO;
extern const contentDispContext_st DiveSim_PlanPage_Calculating;
extern const contentDispContext_st DiveSim_PlanPage_NotEnoughTime_Line0;
extern const contentDispContext_st DiveSim_PlanPage_NotEnoughTime_Line1;
extern const contentDispContext_st DiveSim_PlanPage_DecoTimeExceed_Line0;
extern const contentDispContext_st DiveSim_PlanPage_DecoTimeExceed_Line1;
extern const contentDispContext_st DiveSim_PlanPage_MaxCeilingExceed_Line0;
extern const contentDispContext_st DiveSim_PlanPage_MaxCeilingExceed_Line1;
extern const contentDispContext_st DiveSim_PlanPage_TooHighPO2;
extern const contentDispContext_st SetAlarms_MIN_Context;
extern const contentDispContext_st DiveSimulator_SetDepth_Context;
extern const contentDispContext_st DiveSimulator_SetTime_Context;
extern const contentDispContext_st SetDivePlanner_CuftMin_Context;
extern const contentDispContext_st DiveSimulator_SetSAC_Context;
extern const contentDispContext_st DiveSimulator_SP_Context;
extern NVD_DIVEMODE_t GUI_DIVE_Mode;                   // GUI settings for DIVE_MODE
extern const char* TxtDef_Set_DepthUnit[SetUnit_MAX];
void Handle_DivePlanner_TimeLimitsTittle(char* pStrRet);
