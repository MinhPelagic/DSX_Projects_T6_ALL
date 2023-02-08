/******************************************************************************/
//File: Alarms menu.c
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"

/*Input data define*/
#define ALARMS_DEPTH_OOS                GUI_DEPTHAL_STAT
#define ALARMS_DEPTH_FT                 GUI_DepthAlarmFT
#define ALARMS_DEPTH_M                  GUI_DepthAlarmM
#define ALARMS_DIVETIME_OOS             GUI_DIVE_T_AL_STAT
#define ALARMS_DIVETIME_MIN             GUI_DIVE_T_AL
#define ALARMS_DTR_OOS                  GUI_DTR_AL_STAT
#define ALARMS_DTR_MIN                  GUI_DTR_AL
#define ALARMS_TANKPRESS_OOS            GUI_TankP_AL_STAT
#define ALARMS_TANKPRESS_PSI            GUI_TankP_AL_PSI
#define ALARMS_TANKPRESS_BAR            GUI_TankP_AL_BAR
#define ALARMS_CCPRESS_OOS              GUI_CC6P_AL_STAT
#define ALARMS_CC6P_AL_PSI              GUI_CC6P_AL_PSI;        // GUI settings for CC6P_AL_PSI
#define ALARMS_CC6P_AL_BAR              GUI_CC6P_AL_BAR;        // GUI settings for CC6P_AL_BAR
#define ALARMS_TurnP_AL_OOS             GUI_TurnP_AL_STAT;      // GUI settings for TurnP_AL_STAT (Off, On, Set)
#define ALARMS_TurnP_AL_PSI             GUI_TurnP_AL_PSI;       // GUI settings for TurnP_AL_PSI
#define ALARMS_TurnP_AL_BAR             GUI_TurnP_AL_BAR;       // GUI settings for TurnP_AL_BAR
#define ALARMS_EndP_AL_OOS              GUI_EndP_AL_STAT;       // GUI settings for EndP_AL_STAT (Off, On, Set)
#define ALARMS_EndP_AL_PSI              GUI_EndP_AL_PSI;        // GUI settings for EndP_AL_PSI
#define ALARMS_EndP_AL_BAR              GUI_EndP_AL_BAR;        // GUI settings for EndP_AL_BAR
#define ALARMS_SwitchP_AL_OOS           GUI_SwitchP_AL_STAT;    // GUI settings for Switch_AL_STAT (Off, On, Set)
#define ALARMS_SwitchP_AL_PSI           GUI_SwitchP_AL_PSI;     // GUI settings for Switch_AL_PSI
#define ALARMS_SwitchP_AL_BAR           GUI_SwitchP_AL_BAR;     // GUI settings for Switch_AL_BAR
#define ALARMS_GF_AL_OOS                GUI_GF_AL_STAT;         // GUI settings for GF_AL_STAT(Off, On, Set)
#define ALARMS_GF_AL                    GUI_GF_AL;              // GUI settings for GF_AL
#define ALARMS_N2_AL_OOS                GUI_N2_AL_STAT;         // GUI settings for N2_STAT (Off, On, Set)
#define ALARMS_N2_AL                    GUI_N2_AL;              // GUI settings for N2_AL
#define ALARMS_END_AL_OOS               GUI_END_AL_STAT;        // GUI settings for END_AL_STAT
#define ALARMS_END_AL_FT                GUI_END_AL_FT;          // GUI settings for END_AL_FT
#define ALARMS_END_AL_M                 GUI_END_AL_M;           // GUI settings for END_AL_M
#define ALARMS_WOB_AL_OOS               GUI_WOB_AL_STAT;        // GUI settings for WOB_AL_STAT
#define ALARMS_WOB_AL_FT                GUI_WOB_AL_FT;          // GUI settings for WOB_AL_FT
#define ALARMS_WOB_AL_M                 GUI_WOB_AL_M;           // GUI settings for WOB_AL_M
#define ALARMS_ICD_AL_OOS               GUI_ICD_AL_STAT;        // GUI settings for ICD_AL_STAT
/*Extern variable*/
extern const listItemInMenu_ts* SetAlarm_ListOfContext[DIVEMODE_MAX];
