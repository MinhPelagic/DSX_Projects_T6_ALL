/******************************************************************************/
//File: Deco Stops menu
//Description:
//
/*****************************************************************************/
#include "L4X9_includes.h"

#define DECOSTOP_START_RECORD       (1U) //Algorithm start record number ->
#define DECOSTOP_MAX_ITEMS_INPAGE   (5U) //Maximum items in list
#define DECOSTOP_MAX_ITEMS          (42U) //DecoStop[42]

extern const contentDispContext_st DecoStop_PO2_Tittle;
extern const contentDispContext_st DecoStop_PO2_Value;
extern const contentDispContext_st DecoStop_NODECO;
extern unsigned char DecoStop_StartRec_u8;
unsigned char DecoStop_CheckNoDecoStatus(void);
void DecoStopHandle_TittleOfList(void);
void DecoStopHandle_ContentList(unsigned char startRec);
void DecoStopHandle_InitialCheckDecoDisplay(void);
