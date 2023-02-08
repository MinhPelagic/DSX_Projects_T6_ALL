/******************************************************************************/
//File: DSX_Data_Decode.h
//Description:Operation code for DSX from TI to ST
//Created by:DucThinh
//History: 11/29/2018 Created
//
/*****************************************************************************/
#ifndef _DECODE_DSX_H__
#define _DECODE_DSX_H__
#include "../DsxOCDefine.h"
/* Standard includes. */

/*Define the part should be clean before update data*/



#define BIT_(X) (0x01 << X)
#define BIT_0 	(0x01 << 0)
#define BIT_1 	(0x01 << 1)
#define BIT_2 	(0x01 << 2)
#define BIT_3 	(0x01 << 3)
#define BIT_4 	(0x01 << 4)
#define BIT_5 	(0x01 << 5)
#define BIT_6 	(0x01 << 6)
#define BIT_7 	(0x01 << 7)

typedef void (*p_SurfaceItemHandle)(ItemStatus_te);
typedef void (*p_VoidFunc_t)(void);
typedef void (*pstrHandle_Func)(char*);
typedef ItemStatus_te (*pItem_Func)(void);
typedef GUI_COLOR (*pSetColor_Func)(void);
typedef unsigned char (*pCondition_Func)(void);
typedef void (*p_HandleUpdateListContext)(TxtStr_Name_e);

/*Public prototype function*/
void Decode_DSX_Data(void);
void ContextEmpty(char*);
int _GetData(void *p, const U8 ** ppData, unsigned NumBytes, U32 Off);
DSX_OPCODE_t Opcode_Matrix(DSX_OPCODE_t L2_resp, DSX_OPCODE_t L_resp, DSX_OPCODE_t M_resp, DSX_OPCODE_t M2_resp, DSX_OPCODE_t R_resp, DSX_OPCODE_t R2_resp, DSX_OPCODE_t LR_resp, DSX_OPCODE_t LM2_resp, DSX_OPCODE_t Same_resp);


TANK_NUM_t TANK_NumSelected(void);
void Dive_SM_Handle_CheckDisplayMiddle(void);
bool AlarmStatusCheck_FullViolation(void);
unsigned char CheckHadTheDiveYet(void);
void Dive_CC_Handle_CheckDisplayMiddle(void);
unsigned char SurfaceModeAlarm_BottomAlarms(void);
void displaysubInitialSetGasPage(void);
void GetTextSetTMT(char *TMTcontent, unsigned char _TMTnumber);
bool ReadAndDisplaySlates(uint8_t Idx);
bool AlarmStatusCheck_AlarmWarningLowBattShutDown(void);
void GPS_DeleteLocation(void);

#endif
