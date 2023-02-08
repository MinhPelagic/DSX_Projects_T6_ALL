#ifndef _DIVESETTINGS_DATAMAP_
#define _DIVESETTINGS_DATAMAP_

/*Conservatism define*/
#define DIVESETT_MAINMODE                       GUI_DIVE_Mode           // Dive main mode CC/OC/GAUGE/GAUGSM
#define CONSRV_SPORT_STAT			GUI_CONSV_Sport_Switch  // switching among SPORT (low, medium, high)
#define CONSRV_STAT				CONSER_SETPOINTS        //		              GUI_CONSV_Switch        // CONSV SET POINT: TEC, SPORT
#define SAFETY_STOP_SET_POINTS_STAT             GUI_SafetyStopMode      // OFF, ON, OFF for SET POINTS Stat
#define SafetyStop_DEPTH_M						          GUI_SS_DepthM
#define SafetyStop_DEPTH_FT						          GUI_SS_DepthFt
#define SafetyStop_TIME_Mins					          GUI_SafetyStopMin
#define LastStop_DEPTH_FT						            GUI_LastStopFt
#define LastStop_DEPTH_M						            GUI_LastStopM
/*TEC : GF HIGH and LOW value*/
#define OONSRV_TecGF_Lo                         GUI_TecGF_Lo
#define OONSRV_TecGF_Hi                         GUI_TecGF_Hi

#define CONSV_TEC_GF_LO_SET                           0.0f
#define CONSV_TEC_GF_HI_SET                           0.0f
#define CONSV_TEC_SPORT_SET                           GUI_CONSV_Switch
#define CONSV_SPORT_HI_MED_LO_SET                     GUI_CONSV_Sport_Switch
#define PO2_DECO_SET_VALUE                            0

#endif