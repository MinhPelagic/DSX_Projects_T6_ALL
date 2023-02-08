/******************************************************************************/
//File: SET SP
//
/*****************************************************************************/
#include "L4X9_includes.h"
#define COMODE							(0)//((uint8_t)in_buf[49])
#define Compass_NavigateStatus  		(0)// 1: Left | 0: Right
#define Compass_Selected				(0)//((MORFLG_17&BIT_6)==BIT_6)
#define Compass_NotSelected				(0)//(!Compass_Selected)
#define Compass_Switching				(0)//((MORFLG_17^pre_MORFLG_17)&BIT_6)==BIT_6 //Compass bottom status changing value 0-1 1-0
#define Compass_OnSurface				(0)//(DEPTH<=(float)3)//Check the DIVE or Surface present status
#define Compass_InclinedFlag			(0)//(1==InclinedCompassFlag) // (1: display compass,  0: not display compass)
/*arrow direction defined*/
typedef enum
{
    arrowReferNone = 0,//Center -> No display any arrow
    arrowReferLeft,
    arrowReferRight,
} arrowRef_e;
/*Heading mode*/
enum
{
    ReferenceOff = 0,
    headingReference = 1,
    headingReverse = 2,
};
typedef struct
{
    /* data */
    int referDegree; //Reference data to be calculated
    arrowRef_e arrowReferDirection; //1
} compassReference_ts;

/*Extern variables*/
extern GUI_CONST_STORAGE GUI_BITMAP bmCompass_Circle;
extern uint16_t Compass_vala, Compass_val0, Compass_val1, Compass_val2, Compass_val3;
extern const GUI_POINT CompassRefPoint[];
extern const contentDispContext_st SurfaceMode_SurfTime_TitleText;
extern const contentDispContext_st SurfaceMode_SurfTime_Hour;
extern const contentDispContext_st SurfaceMode_SurfTime_Min;
extern const contentDispContext_st SurfaceMode_SurfTime_Colon;
extern const contentDispContext_st SurfaceMode_Linked_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_LooseLink_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_OffLink_TankPressure_Value;
extern const contentDispContext_st SurfaceMode_TankPressure_Tittle;
extern const contentDispContext_st DiveMode_TankPressure_Tittle;
extern const contentDispContext_st CompassMode_ReferenceHeading_Value;
extern const contentDispContext_st CompassMode_ReverseHeading_Tittle;
extern const contentDispContext_st CompassMode_ReverseHeading_Value;
extern const contentDispContext_st CompassMode_Chrono_Tittle;
extern const contentDispContext_st CompassMode_ReferenceHeading_Tittle;
extern const contentDispContext_st CompassMode_Chrono_Time;
extern const contentDispContext_st CompassMode_DiveTime_Tittle;
extern const contentDispContext_st CompassMode_DiveTime_Time;
extern const contentDispContext_st CompassMode_Depth_Tittle;
extern const contentDispContext_st CompassMode_Depth;
extern const contentDispContext_st CompassMenu_SetDecline_STAT_Ctx;
extern const listItemInMenu_ts* CompassMenu_ListOfContext[DIVEMODE_MAX];
extern const contentDispContext_st CompassMode_CurrentLocation_Tittle;
extern const contentDispContext_st CompassMode_CurrentLocation_Latitude;
extern const contentDispContext_st CompassMode_CurrentLocation_Longitude;
extern const contentDispContext_st CompassMode_TargetLocation_Tittle;
extern const contentDispContext_st CompassMode_TargetLocation_Latitude;
extern const contentDispContext_st CompassMode_TargetLocation_Longitude;
extern const contentDispContext_st CompassMode_Target_Tittle;
extern const contentDispContext_st CompassMode_Target_Value;
extern const contentDispContext_st CompassMode_Distance_Tittle;
extern const contentDispContext_st CompassMode_Distance_Value;
extern int8_t GUI_CompassHeadingStat;
extern int16_t GUI_CompassReferenceHeadingDegree;
extern int16_t GUI_CompassReverseHeadingDegree;

/*Static functions*/
static void _CoDis_Main_NavigateText(int, const char*, const GUI_FONT*);
static void _CoDis_Sub_NavigateText(int, const char*, const GUI_FONT*);
static GUI_COLOR _Codis_Draw_VlineMain_CYAN(int);
static GUI_COLOR _Codis_Draw_VlineSub_CYAN(int);
static GUI_COLOR _Codis_Draw_VlineSub_White(int);

/*Public interface*/
void CoDis_DisplayScaleVerticalLines(int);
void CoDis_DisplayCompassMainValue(int);
int16_t CoDis_VerifyTheCompassValue(void);
void CompassHandle_SetReferenceOrReverse(void);
void Display_NavigateArrows(arrowRef_e navLeftRightStat);
void SurfaceMode_Pressure_TittleContext(char* pStrRet);
void SurfaceMode_TankPressure_Linked_ValueContext(char* pStrRet);
void CompassHandle_DisplayTheDotReferenceAndReverse(int);
GUI_COLOR SurfaceMode_SurfTime_TitleText_Color(void);

