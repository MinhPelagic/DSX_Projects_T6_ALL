#ifndef __CONTEXT_DIVEMENU_H__
#define __CONTEXT_DIVEMENU_H__
#include <stdint.h>
/*
Context handle to DiveMenu
NOTE: These config are generated !!!
*/
extern const menuItemContext_ts Context_DiveMenu_SETSP;
void DiveMenu_SETSP_Context_Left(char*);
extern const menuItemContext_ts Context_DiveMenu_SETGASES;
void DiveMenu_SETGASES_Context_Left(char*);
extern const menuItemContext_ts Context_DiveMenu_DIVEPROFILEGRAPH;
void DiveMenu_DIVEPROFILEGRAPH_Context_Left(char*);
extern const menuItemContext_ts Context_DiveMenu_BAILOUTPO2LIMITS;
void DiveMenu_BAILOUTPO2LIMITS_Context_Left(char*);
extern const menuItemContext_ts Context_DiveMenu_DECOSTOPS;
void DiveMenu_DECOSTOPS_Context_Left(char*);
extern const menuItemContext_ts Context_DiveMenu_SETGFHIGH;
void DiveMenu_SETGFHIGH_Context_Left(char*);
void DiveMenu_SETGFHIGH_Context_Right(char*);
extern const menuItemContext_ts Context_DiveMenu_PO2LIMITS;
void DiveMenu_PO2LIMITS_Context_Left(char*);

#endif
