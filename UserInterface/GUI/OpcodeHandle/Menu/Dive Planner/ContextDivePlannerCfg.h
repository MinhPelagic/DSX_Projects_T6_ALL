#ifndef __CONTEXT_DIVEPLANNER_H__
#define __CONTEXT_DIVEPLANNER_H__
#include <stdint.h>
/*
Context handle to DivePlanner
NOTE: These config are generated !!!
*/
extern const menuItemContext_ts Context_DivePlanner_TIMELIMITS;
void DivePlanner_TIMELIMITS_Context_Center(char*);
extern const menuItemContext_ts Context_DivePlanner_DEPTHLIMITS;
void DivePlanner_DEPTHLIMITS_Context_Center(char*);
extern const menuItemContext_ts Context_DivePlanner_DIVESIMULATOR;
void DivePlanner_DIVESIMULATOR_Context_Center(char*);
extern const menuItemContext_ts Context_DiveSimulator_NEWORCONTINUOUS;
void DiveSimulator_NEWORCONTINUOUS_Context_Left(char*);
void DiveSimulator_NEWORCONTINUOUS_Context_Right(char*);
extern const menuItemContext_ts Context_DiveSimulator_DEPTH;
void DiveSimulator_DEPTH_Context_Left(char*);
void DiveSimulator_DEPTH_Context_Right(char*);
extern const menuItemContext_ts Context_DiveSimulator_TIME;
void DiveSimulator_TIME_Context_Left(char*);
void DiveSimulator_TIME_Context_Right(char*);
extern const menuItemContext_ts Context_DiveSimulator_SAC;
void DiveSimulator_SAC_Context_Left(char*);
void DiveSimulator_SAC_Context_Right(char*);
extern const menuItemContext_ts Context_DiveSimulator_SP;
void DiveSimulator_SP_Context_Left(char*);
void DiveSimulator_SP_Context_Right(char*);
extern const menuItemContext_ts Context_DiveSimulator_SIMULATEDIVE;
void DiveSimulator_SIMULATEDIVE_Context_Left(char*);

#endif
