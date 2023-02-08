#ifndef _DIVEPLANNER_DATAMAP_
#define _DIVEPLANNER_DATAMAP_

void DivePlanner_TIMELIMIT_Context(uint8_t StartLimitNum);
extern uint8_t FindGasNumOfDiveMode(NVD_DIVEMODE_t);
extern uint8_t FindFO2OfDiveMode(NVD_DIVEMODE_t);
extern uint8_t FindFHeOfDiveMode(NVD_DIVEMODE_t);
extern uint8_t FindPO2OfDiveMode(NVD_DIVEMODE_t);
extern uint8_t FindFO2OfGasNum(uint8_t);
extern float DilPO2Val(void);
/*------------------------------------- DivePlanner_TIMELIMIT_Context --------------------------------------------*/
#define DiPla_MIN(X)	0
#define DiPla_MIN_STOP	0xFFFF	/*When the plan time in the depth is 0xFF then stop display*/
#define DiPla_GASNum	FindGasNumOfDiveMode(DIVE_MODE)
#define DiPla_FO2   	FindFO2OfDiveMode(DIVE_MODE)
#define DiPla_Fhe   	FindFHeOfDiveMode(DIVE_MODE)
#define DiPla_SPHI   	0.01*SCUBA_Set.SP_SetHigh
#define DiPla_SPLO   	0.01*SCUBA_Set.SP_SetLow
#define DiPla_GFLO   	Find_Gonsv_Lo()
#define DiPla_GFHI   	Find_Gonsv_Hi()
#define DiPla_MOD_FT   	(uint16_t)((round)(FindMOD()))
#define DiPla_MOD_M   	(uint16_t)((round)(FindMOD()*CONST_FT_TO_M))
#define DiPla_MAX_PO2   0.01*SCUBA_Set.OCmax

#endif
