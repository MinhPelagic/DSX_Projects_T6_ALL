/******************************************************************************/
//File: SET GF HIGH menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"

#define SETGFHIGH_MAX_GFHIGH_VALUE   (90U)  //Maximum GF HIGH defined by spec
#define SETGFHIGH_MIN_GFHIGH_VALUE   (60U)  //Minimum GF HIGH 
#define SETGFHIGH_STEP_VALUE         (5U)   //Value increase/decrease every steps
extern const contentDispContext_st Set_GFHigh_Ctx;
extern void UpdateGF(void);                 //To update the GF changes for algorithm
