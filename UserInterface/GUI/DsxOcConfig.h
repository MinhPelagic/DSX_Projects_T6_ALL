/*CODE GENERATED PLEASE NOT MODIFY BY HAND*/
#ifndef _DSXOCCFG_H
#define _DSXOCCFG_H
/*Declare the function using to handle Opcode value*/
extern const p_VoidFunc_t IniFunc_Handle[];
extern const p_VoidFunc_t UpdatePortionFunc_Handle[];
extern const pCondition_Func ConditionCheckFunc[];
extern const pCondition_Func CondCheckPreOCFunc[];
extern const p_VoidFunc_t UpdateOrFlashFunc[];
extern const p_VoidFunc_t HandlePreOCFunc[];
/*Declare the needed function support to display -> This shall be manual implement*/
void FuncDoNothing(void);
unsigned char ReturnTrue(void);
unsigned char ReturnFalse(void);
/*1. Clear or Initilal screen for  W1_WELCOME operation*/
void IniOrClrScrFunc_W1_WELCOME(void);
/*1. Clear or Initilal screen for  W2_WAIT_MESSAGE operation*/
void IniOrClrScrFunc_W2_WAIT_MESSAGE(void);
/*1. Clear or Initilal screen for  MANUFACTURE_SCREEN operation*/
void IniOrClrScrFunc_MANUFACTURE_SCREEN(void);
/*1. Clear or Initilal screen for  B1_BATT_CHARGE operation*/
void IniOrClrScrFunc_B1_BATT_CHARGE(void);
/*1.3 Flashing or keep update content of items B1_BATT_CHARGE */
void UpdOrFlasFunc_B1_BATT_CHARGE(void);
/*1. Clear or Initilal screen for  REGISTER_SCREEN operation*/
void IniOrClrScrFunc_REGISTER_SCREEN(void);
/*1.3 Flashing or keep update content of items REGISTER_SCREEN */
void UpdOrFlasFunc_REGISTER_SCREEN(void);
/*1. Clear or Initilal screen for  S18_SP_SWITCH operation*/
void IniOrClrScrFunc_S18_SP_SWITCH(void);
/*1.2 Update the porition screen when the opcode changed for S18_SP_SWITCH operation*/
void UpdPorFunc_S18_SP_SWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S18_SP_SWITCH*/
unsigned char CondiCheck_S18_SP_SWITCH(void);
/*2. Process preOpcode after change to S18_SP_SWITCH */
void HandlePreOCFunc_S18_SP_SWITCH(void);
/*Condition check to progress preOC valueS18_SP_SWITCH*/
unsigned char CondiPreOcCheck_S18_SP_SWITCH(void);
/*1. Clear or Initilal screen for  S21_GAS_SWITCH operation*/
void IniOrClrScrFunc_S21_GAS_SWITCH(void);
/*1.2 Update the porition screen when the opcode changed for S21_GAS_SWITCH operation*/
void UpdPorFunc_S21_GAS_SWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S21_GAS_SWITCH*/
unsigned char CondiCheck_S21_GAS_SWITCH(void);
/*2. Process preOpcode after change to S21_GAS_SWITCH */
void HandlePreOCFunc_S21_GAS_SWITCH(void);
/*Condition check to progress preOC valueS21_GAS_SWITCH*/
unsigned char CondiPreOcCheck_S21_GAS_SWITCH(void);
/*1. Clear or Initilal screen for  S62_DIVE_PLANNER operation*/
void IniOrClrScrFunc_S62_DIVE_PLANNER(void);
/*1.2 Update the porition screen when the opcode changed for S62_DIVE_PLANNER operation*/
void UpdPorFunc_S62_DIVE_PLANNER(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S62_DIVE_PLANNER*/
unsigned char CondiCheck_S62_DIVE_PLANNER(void);
/*2. Process preOpcode after change to S62_DIVE_PLANNER */
void HandlePreOCFunc_S62_DIVE_PLANNER(void);
/*Condition check to progress preOC valueS62_DIVE_PLANNER*/
unsigned char CondiPreOcCheck_S62_DIVE_PLANNER(void);
/*1. Clear or Initilal screen for  S27_LOG operation*/
void IniOrClrScrFunc_S27_LOG(void);
/*1.2 Update the porition screen when the opcode changed for S27_LOG operation*/
void UpdPorFunc_S27_LOG(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S27_LOG*/
unsigned char CondiCheck_S27_LOG(void);
/*2. Process preOpcode after change to S27_LOG */
void HandlePreOCFunc_S27_LOG(void);
/*Condition check to progress preOC valueS27_LOG*/
unsigned char CondiPreOcCheck_S27_LOG(void);
/*1. Clear or Initilal screen for  S41_SET_MENU operation*/
void IniOrClrScrFunc_S41_SET_MENU(void);
/*1.2 Update the porition screen when the opcode changed for S41_SET_MENU operation*/
void UpdPorFunc_S41_SET_MENU(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S41_SET_MENU*/
unsigned char CondiCheck_S41_SET_MENU(void);
/*2. Process preOpcode after change to S41_SET_MENU */
void HandlePreOCFunc_S41_SET_MENU(void);
/*Condition check to progress preOC valueS41_SET_MENU*/
unsigned char CondiPreOcCheck_S41_SET_MENU(void);
/*1. Clear or Initilal screen for  S185_INFO operation*/
void IniOrClrScrFunc_S185_INFO(void);
/*1.2 Update the porition screen when the opcode changed for S185_INFO operation*/
void UpdPorFunc_S185_INFO(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S185_INFO*/
unsigned char CondiCheck_S185_INFO(void);
/*2. Process preOpcode after change to S185_INFO */
void HandlePreOCFunc_S185_INFO(void);
/*Condition check to progress preOC valueS185_INFO*/
unsigned char CondiPreOcCheck_S185_INFO(void);
/*1. Clear or Initilal screen for  S_SLATE operation*/
void IniOrClrScrFunc_S_SLATE(void);
/*1.2 Update the porition screen when the opcode changed for S_SLATE operation*/
void UpdPorFunc_S_SLATE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S_SLATE*/
unsigned char CondiCheck_S_SLATE(void);
/*2. Process preOpcode after change to S_SLATE */
void HandlePreOCFunc_S_SLATE(void);
/*Condition check to progress preOC valueS_SLATE*/
unsigned char CondiPreOcCheck_S_SLATE(void);
/*1. Clear or Initilal screen for  S404_TMT_SWITCH operation*/
void IniOrClrScrFunc_S404_TMT_SWITCH(void);
/*1.2 Update the porition screen when the opcode changed for S404_TMT_SWITCH operation*/
void UpdPorFunc_S404_TMT_SWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S404_TMT_SWITCH*/
unsigned char CondiCheck_S404_TMT_SWITCH(void);
/*2. Process preOpcode after change to S404_TMT_SWITCH */
void HandlePreOCFunc_S404_TMT_SWITCH(void);
/*Condition check to progress preOC valueS404_TMT_SWITCH*/
unsigned char CondiPreOcCheck_S404_TMT_SWITCH(void);
/*1. Clear or Initilal screen for  S432_DIVE_MODE operation*/
void IniOrClrScrFunc_S432_DIVE_MODE(void);
/*1.2 Update the porition screen when the opcode changed for S432_DIVE_MODE operation*/
void UpdPorFunc_S432_DIVE_MODE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S432_DIVE_MODE*/
unsigned char CondiCheck_S432_DIVE_MODE(void);
/*2. Process preOpcode after change to S432_DIVE_MODE */
void HandlePreOCFunc_S432_DIVE_MODE(void);
/*Condition check to progress preOC valueS432_DIVE_MODE*/
unsigned char CondiPreOcCheck_S432_DIVE_MODE(void);
/*1. Clear or Initilal screen for  SLATES_MAINPAGE operation*/
void IniOrClrScrFunc_SLATES_MAINPAGE(void);
/*1. Clear or Initilal screen for  SLATES_NO_SLATE operation*/
void IniOrClrScrFunc_SLATES_NO_SLATE(void);
/*1. Clear or Initilal screen for  SLATES_CONFIRM_DELETE operation*/
void IniOrClrScrFunc_SLATES_CONFIRM_DELETE(void);
/*1. Clear or Initilal screen for  SLATES_DELETED operation*/
void IniOrClrScrFunc_SLATES_DELETED(void);
/*1. Clear or Initilal screen for  S28_LOG_DATA1 operation*/
void IniOrClrScrFunc_S28_LOG_DATA1(void);
/*1.3 Flashing or keep update content of items S28_LOG_DATA1 */
void UpdOrFlasFunc_S28_LOG_DATA1(void);
/*1. Clear or Initilal screen for  S29_LOG_DATA2 operation*/
void IniOrClrScrFunc_S29_LOG_DATA2(void);
/*1. Clear or Initilal screen for  S37_LOG_DATA3 operation*/
void IniOrClrScrFunc_S37_LOG_DATA3(void);
/*1. Clear or Initilal screen for  S39_LOG_DATA4 operation*/
void IniOrClrScrFunc_S39_LOG_DATA4(void);
/*1. Clear or Initilal screen for  S36_LOG_DATA5 operation*/
void IniOrClrScrFunc_S36_LOG_DATA5(void);
/*1. Clear or Initilal screen for  S42_SET_GASES operation*/
void IniOrClrScrFunc_S42_SET_GASES(void);
/*1.2 Update the porition screen when the opcode changed for S42_SET_GASES operation*/
void UpdPorFunc_S42_SET_GASES(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S42_SET_GASES*/
unsigned char CondiCheck_S42_SET_GASES(void);
/*2. Process preOpcode after change to S42_SET_GASES */
void HandlePreOCFunc_S42_SET_GASES(void);
/*Condition check to progress preOC valueS42_SET_GASES*/
unsigned char CondiPreOcCheck_S42_SET_GASES(void);
/*1. Clear or Initilal screen for  S53_SET_SP operation*/
void IniOrClrScrFunc_S53_SET_SP(void);
/*1.2 Update the porition screen when the opcode changed for S53_SET_SP operation*/
void UpdPorFunc_S53_SET_SP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S53_SET_SP*/
unsigned char CondiCheck_S53_SET_SP(void);
/*2. Process preOpcode after change to S53_SET_SP */
void HandlePreOCFunc_S53_SET_SP(void);
/*Condition check to progress preOC valueS53_SET_SP*/
unsigned char CondiPreOcCheck_S53_SET_SP(void);
/*1. Clear or Initilal screen for  S_DIVE_SETTINGS operation*/
void IniOrClrScrFunc_S_DIVE_SETTINGS(void);
/*1.2 Update the porition screen when the opcode changed for S_DIVE_SETTINGS operation*/
void UpdPorFunc_S_DIVE_SETTINGS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S_DIVE_SETTINGS*/
unsigned char CondiCheck_S_DIVE_SETTINGS(void);
/*2. Process preOpcode after change to S_DIVE_SETTINGS */
void HandlePreOCFunc_S_DIVE_SETTINGS(void);
/*Condition check to progress preOC valueS_DIVE_SETTINGS*/
unsigned char CondiPreOcCheck_S_DIVE_SETTINGS(void);
/*1. Clear or Initilal screen for  S105_ALARMS operation*/
void IniOrClrScrFunc_S105_ALARMS(void);
/*1.2 Update the porition screen when the opcode changed for S105_ALARMS operation*/
void UpdPorFunc_S105_ALARMS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S105_ALARMS*/
unsigned char CondiCheck_S105_ALARMS(void);
/*2. Process preOpcode after change to S105_ALARMS */
void HandlePreOCFunc_S105_ALARMS(void);
/*Condition check to progress preOC valueS105_ALARMS*/
unsigned char CondiPreOcCheck_S105_ALARMS(void);
/*1. Clear or Initilal screen for  S128_DEVICE_SETTINGS operation*/
void IniOrClrScrFunc_S128_DEVICE_SETTINGS(void);
/*1.2 Update the porition screen when the opcode changed for S128_DEVICE_SETTINGS operation*/
void UpdPorFunc_S128_DEVICE_SETTINGS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_SETTINGS*/
unsigned char CondiCheck_S128_DEVICE_SETTINGS(void);
/*2. Process preOpcode after change to S128_DEVICE_SETTINGS */
void HandlePreOCFunc_S128_DEVICE_SETTINGS(void);
/*Condition check to progress preOC valueS128_DEVICE_SETTINGS*/
unsigned char CondiPreOcCheck_S128_DEVICE_SETTINGS(void);
/*1. Clear or Initilal screen for  S149_DATE_TIME operation*/
void IniOrClrScrFunc_S149_DATE_TIME(void);
/*1.2 Update the porition screen when the opcode changed for S149_DATE_TIME operation*/
void UpdPorFunc_S149_DATE_TIME(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S149_DATE_TIME*/
unsigned char CondiCheck_S149_DATE_TIME(void);
/*2. Process preOpcode after change to S149_DATE_TIME */
void HandlePreOCFunc_S149_DATE_TIME(void);
/*Condition check to progress preOC valueS149_DATE_TIME*/
unsigned char CondiPreOcCheck_S149_DATE_TIME(void);
/*1. Clear or Initilal screen for  S161_DISPLAY_SETTINGS operation*/
void IniOrClrScrFunc_S161_DISPLAY_SETTINGS(void);
/*1.2 Update the porition screen when the opcode changed for S161_DISPLAY_SETTINGS operation*/
void UpdPorFunc_S161_DISPLAY_SETTINGS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S161_DISPLAY_SETTINGS*/
unsigned char CondiCheck_S161_DISPLAY_SETTINGS(void);
/*2. Process preOpcode after change to S161_DISPLAY_SETTINGS */
void HandlePreOCFunc_S161_DISPLAY_SETTINGS(void);
/*Condition check to progress preOC valueS161_DISPLAY_SETTINGS*/
unsigned char CondiPreOcCheck_S161_DISPLAY_SETTINGS(void);
/*1. Clear or Initilal screen for  S154_SET_DATE operation*/
void IniOrClrScrFunc_S154_SET_DATE(void);
/*1.2 Update the porition screen when the opcode changed for S154_SET_DATE operation*/
void UpdPorFunc_S154_SET_DATE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DATE*/
unsigned char CondiCheck_S154_SET_DATE(void);
/*2. Process preOpcode after change to S154_SET_DATE */
void HandlePreOCFunc_S154_SET_DATE(void);
/*Condition check to progress preOC valueS154_SET_DATE*/
unsigned char CondiPreOcCheck_S154_SET_DATE(void);
/*1. Clear or Initilal screen for  S154_SET_YY operation*/
void IniOrClrScrFunc_S154_SET_YY(void);
/*1.2 Update the porition screen when the opcode changed for S154_SET_YY operation*/
void UpdPorFunc_S154_SET_YY(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_YY*/
unsigned char CondiCheck_S154_SET_YY(void);
/*1.3 Flashing or keep update content of items S154_SET_YY */
void UpdOrFlasFunc_S154_SET_YY(void);
/*2. Process preOpcode after change to S154_SET_YY */
void HandlePreOCFunc_S154_SET_YY(void);
/*Condition check to progress preOC valueS154_SET_YY*/
unsigned char CondiPreOcCheck_S154_SET_YY(void);
/*1.2 Update the porition screen when the opcode changed for S154_SET_MM operation*/
void UpdPorFunc_S154_SET_MM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_MM*/
unsigned char CondiCheck_S154_SET_MM(void);
/*1.3 Flashing or keep update content of items S154_SET_MM */
void UpdOrFlasFunc_S154_SET_MM(void);
/*2. Process preOpcode after change to S154_SET_MM */
void HandlePreOCFunc_S154_SET_MM(void);
/*Condition check to progress preOC valueS154_SET_MM*/
unsigned char CondiPreOcCheck_S154_SET_MM(void);
/*1.2 Update the porition screen when the opcode changed for S154_SET_DD operation*/
void UpdPorFunc_S154_SET_DD(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S154_SET_DD*/
unsigned char CondiCheck_S154_SET_DD(void);
/*1.3 Flashing or keep update content of items S154_SET_DD */
void UpdOrFlasFunc_S154_SET_DD(void);
/*2. Process preOpcode after change to S154_SET_DD */
void HandlePreOCFunc_S154_SET_DD(void);
/*Condition check to progress preOC valueS154_SET_DD*/
unsigned char CondiPreOcCheck_S154_SET_DD(void);
/*1. Clear or Initilal screen for  S158_SET_TIME operation*/
void IniOrClrScrFunc_S158_SET_TIME(void);
/*1.2 Update the porition screen when the opcode changed for S158_SET_TIME operation*/
void UpdPorFunc_S158_SET_TIME(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_TIME*/
unsigned char CondiCheck_S158_SET_TIME(void);
/*2. Process preOpcode after change to S158_SET_TIME */
void HandlePreOCFunc_S158_SET_TIME(void);
/*Condition check to progress preOC valueS158_SET_TIME*/
unsigned char CondiPreOcCheck_S158_SET_TIME(void);
/*1. Clear or Initilal screen for  S158_SET_HH operation*/
void IniOrClrScrFunc_S158_SET_HH(void);
/*1.2 Update the porition screen when the opcode changed for S158_SET_HH operation*/
void UpdPorFunc_S158_SET_HH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_HH*/
unsigned char CondiCheck_S158_SET_HH(void);
/*1.3 Flashing or keep update content of items S158_SET_HH */
void UpdOrFlasFunc_S158_SET_HH(void);
/*2. Process preOpcode after change to S158_SET_HH */
void HandlePreOCFunc_S158_SET_HH(void);
/*Condition check to progress preOC valueS158_SET_HH*/
unsigned char CondiPreOcCheck_S158_SET_HH(void);
/*1.2 Update the porition screen when the opcode changed for S158_SET_MM operation*/
void UpdPorFunc_S158_SET_MM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_MM*/
unsigned char CondiCheck_S158_SET_MM(void);
/*1.3 Flashing or keep update content of items S158_SET_MM */
void UpdOrFlasFunc_S158_SET_MM(void);
/*2. Process preOpcode after change to S158_SET_MM */
void HandlePreOCFunc_S158_SET_MM(void);
/*Condition check to progress preOC valueS158_SET_MM*/
unsigned char CondiPreOcCheck_S158_SET_MM(void);
/*1.2 Update the porition screen when the opcode changed for S158_SET_AM_PM operation*/
void UpdPorFunc_S158_SET_AM_PM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S158_SET_AM_PM*/
unsigned char CondiCheck_S158_SET_AM_PM(void);
/*1.3 Flashing or keep update content of items S158_SET_AM_PM */
void UpdOrFlasFunc_S158_SET_AM_PM(void);
/*2. Process preOpcode after change to S158_SET_AM_PM */
void HandlePreOCFunc_S158_SET_AM_PM(void);
/*Condition check to progress preOC valueS158_SET_AM_PM*/
unsigned char CondiPreOcCheck_S158_SET_AM_PM(void);
/*1. Clear or Initilal screen for  S150_SET_DATE_FORMAT operation*/
void IniOrClrScrFunc_S150_SET_DATE_FORMAT(void);
/*1.2 Update the porition screen when the opcode changed for S150_SET_DATE_FORMAT operation*/
void UpdPorFunc_S150_SET_DATE_FORMAT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S150_SET_DATE_FORMAT*/
unsigned char CondiCheck_S150_SET_DATE_FORMAT(void);
/*2. Process preOpcode after change to S150_SET_DATE_FORMAT */
void HandlePreOCFunc_S150_SET_DATE_FORMAT(void);
/*Condition check to progress preOC valueS150_SET_DATE_FORMAT*/
unsigned char CondiPreOcCheck_S150_SET_DATE_FORMAT(void);
/*1. Clear or Initilal screen for  S150_SET_DATE_FORMAT_SET operation*/
void IniOrClrScrFunc_S150_SET_DATE_FORMAT_SET(void);
/*1.3 Flashing or keep update content of items S150_SET_DATE_FORMAT_SET */
void UpdOrFlasFunc_S150_SET_DATE_FORMAT_SET(void);
/*1. Clear or Initilal screen for  S152_SET_TIME_FORMAT operation*/
void IniOrClrScrFunc_S152_SET_TIME_FORMAT(void);
/*1.2 Update the porition screen when the opcode changed for S152_SET_TIME_FORMAT operation*/
void UpdPorFunc_S152_SET_TIME_FORMAT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S152_SET_TIME_FORMAT*/
unsigned char CondiCheck_S152_SET_TIME_FORMAT(void);
/*2. Process preOpcode after change to S152_SET_TIME_FORMAT */
void HandlePreOCFunc_S152_SET_TIME_FORMAT(void);
/*Condition check to progress preOC valueS152_SET_TIME_FORMAT*/
unsigned char CondiPreOcCheck_S152_SET_TIME_FORMAT(void);
/*1. Clear or Initilal screen for  S152_SET_TIME_FORMAT_SET operation*/
void IniOrClrScrFunc_S152_SET_TIME_FORMAT_SET(void);
/*1.3 Flashing or keep update content of items S152_SET_TIME_FORMAT_SET */
void UpdOrFlasFunc_S152_SET_TIME_FORMAT_SET(void);
/*1. Clear or Initilal screen for  SETGASES_SET_CC_GASES operation*/
void IniOrClrScrFunc_SETGASES_SET_CC_GASES(void);
/*1.2 Update the porition screen when the opcode changed for SETGASES_SET_CC_GASES operation*/
void UpdPorFunc_SETGASES_SET_CC_GASES(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_CC_GASES*/
unsigned char CondiCheck_SETGASES_SET_CC_GASES(void);
/*2. Process preOpcode after change to SETGASES_SET_CC_GASES */
void HandlePreOCFunc_SETGASES_SET_CC_GASES(void);
/*Condition check to progress preOC valueSETGASES_SET_CC_GASES*/
unsigned char CondiPreOcCheck_SETGASES_SET_CC_GASES(void);
/*1. Clear or Initilal screen for  SETGASES_SET_BO_GASES operation*/
void IniOrClrScrFunc_SETGASES_SET_BO_GASES(void);
/*1.2 Update the porition screen when the opcode changed for SETGASES_SET_BO_GASES operation*/
void UpdPorFunc_SETGASES_SET_BO_GASES(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_SET_BO_GASES*/
unsigned char CondiCheck_SETGASES_SET_BO_GASES(void);
/*2. Process preOpcode after change to SETGASES_SET_BO_GASES */
void HandlePreOCFunc_SETGASES_SET_BO_GASES(void);
/*Condition check to progress preOC valueSETGASES_SET_BO_GASES*/
unsigned char CondiPreOcCheck_SETGASES_SET_BO_GASES(void);
/*1. Clear or Initilal screen for  SETGASES_O2_ANALYZER operation*/
void IniOrClrScrFunc_SETGASES_O2_ANALYZER(void);
/*1.2 Update the porition screen when the opcode changed for SETGASES_O2_ANALYZER operation*/
void UpdPorFunc_SETGASES_O2_ANALYZER(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SETGASES_O2_ANALYZER*/
unsigned char CondiCheck_SETGASES_O2_ANALYZER(void);
/*2. Process preOpcode after change to SETGASES_O2_ANALYZER */
void HandlePreOCFunc_SETGASES_O2_ANALYZER(void);
/*Condition check to progress preOC valueSETGASES_O2_ANALYZER*/
unsigned char CondiPreOcCheck_SETGASES_O2_ANALYZER(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_01 operation*/
void IniOrClrScrFunc_S70_SET_GAS_01(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_01 operation*/
void UpdPorFunc_S70_SET_GAS_01(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_01*/
unsigned char CondiCheck_S70_SET_GAS_01(void);
/*2. Process preOpcode after change to S70_SET_GAS_01 */
void HandlePreOCFunc_S70_SET_GAS_01(void);
/*Condition check to progress preOC valueS70_SET_GAS_01*/
unsigned char CondiPreOcCheck_S70_SET_GAS_01(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_02 operation*/
void IniOrClrScrFunc_S70_SET_GAS_02(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_02 operation*/
void UpdPorFunc_S70_SET_GAS_02(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_02*/
unsigned char CondiCheck_S70_SET_GAS_02(void);
/*2. Process preOpcode after change to S70_SET_GAS_02 */
void HandlePreOCFunc_S70_SET_GAS_02(void);
/*Condition check to progress preOC valueS70_SET_GAS_02*/
unsigned char CondiPreOcCheck_S70_SET_GAS_02(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_03 operation*/
void IniOrClrScrFunc_S70_SET_GAS_03(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_03 operation*/
void UpdPorFunc_S70_SET_GAS_03(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_03*/
unsigned char CondiCheck_S70_SET_GAS_03(void);
/*2. Process preOpcode after change to S70_SET_GAS_03 */
void HandlePreOCFunc_S70_SET_GAS_03(void);
/*Condition check to progress preOC valueS70_SET_GAS_03*/
unsigned char CondiPreOcCheck_S70_SET_GAS_03(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_04 operation*/
void IniOrClrScrFunc_S70_SET_GAS_04(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_04 operation*/
void UpdPorFunc_S70_SET_GAS_04(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_04*/
unsigned char CondiCheck_S70_SET_GAS_04(void);
/*2. Process preOpcode after change to S70_SET_GAS_04 */
void HandlePreOCFunc_S70_SET_GAS_04(void);
/*Condition check to progress preOC valueS70_SET_GAS_04*/
unsigned char CondiPreOcCheck_S70_SET_GAS_04(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_05 operation*/
void IniOrClrScrFunc_S70_SET_GAS_05(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_05 operation*/
void UpdPorFunc_S70_SET_GAS_05(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_05*/
unsigned char CondiCheck_S70_SET_GAS_05(void);
/*2. Process preOpcode after change to S70_SET_GAS_05 */
void HandlePreOCFunc_S70_SET_GAS_05(void);
/*Condition check to progress preOC valueS70_SET_GAS_05*/
unsigned char CondiPreOcCheck_S70_SET_GAS_05(void);
/*1. Clear or Initilal screen for  S70_SET_GAS_06 operation*/
void IniOrClrScrFunc_S70_SET_GAS_06(void);
/*1.2 Update the porition screen when the opcode changed for S70_SET_GAS_06 operation*/
void UpdPorFunc_S70_SET_GAS_06(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_SET_GAS_06*/
unsigned char CondiCheck_S70_SET_GAS_06(void);
/*2. Process preOpcode after change to S70_SET_GAS_06 */
void HandlePreOCFunc_S70_SET_GAS_06(void);
/*Condition check to progress preOC valueS70_SET_GAS_06*/
unsigned char CondiPreOcCheck_S70_SET_GAS_06(void);
/*1. Clear or Initilal screen for  S70_O2_ANALYZER operation*/
void IniOrClrScrFunc_S70_O2_ANALYZER(void);
/*1.2 Update the porition screen when the opcode changed for S70_O2_ANALYZER operation*/
void UpdPorFunc_S70_O2_ANALYZER(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S70_O2_ANALYZER*/
unsigned char CondiCheck_S70_O2_ANALYZER(void);
/*2. Process preOpcode after change to S70_O2_ANALYZER */
void HandlePreOCFunc_S70_O2_ANALYZER(void);
/*Condition check to progress preOC valueS70_O2_ANALYZER*/
unsigned char CondiPreOcCheck_S70_O2_ANALYZER(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_01 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_01(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_01 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_01(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_02 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_02(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_02 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_02(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_03 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_03(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_03 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_03(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_04 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_04(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_04 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_04(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_05 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_05(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_05 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_05(void);
/*1. Clear or Initilal screen for  S263_CHECKTMTLINKWITHGAS_06 operation*/
void IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_06(void);
/*1.3 Flashing or keep update content of items S263_CHECKTMTLINKWITHGAS_06 */
void UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_06(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_01 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_01(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_01 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_01(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_02 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_02(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_02 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_02(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_03 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_03(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_03 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_03(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_04 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_04(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_04 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_04(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_05 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_05(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_05 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_05(void);
/*1. Clear or Initilal screen for  S71_SET_GAS_STAT_06 operation*/
void IniOrClrScrFunc_S71_SET_GAS_STAT_06(void);
/*1.3 Flashing or keep update content of items S71_SET_GAS_STAT_06 */
void UpdOrFlasFunc_S71_SET_GAS_STAT_06(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_01 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_01(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_01 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_01(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_01 */
void HandlePreOCFunc_S72_SET_GAS_FO2_01(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_01*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_01(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_02 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_02(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_02 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_02(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_02 */
void HandlePreOCFunc_S72_SET_GAS_FO2_02(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_02*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_02(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_03 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_03(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_03 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_03(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_03 */
void HandlePreOCFunc_S72_SET_GAS_FO2_03(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_03*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_03(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_04 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_04(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_04 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_04(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_04 */
void HandlePreOCFunc_S72_SET_GAS_FO2_04(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_04*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_04(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_05 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_05(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_05 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_05(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_05 */
void HandlePreOCFunc_S72_SET_GAS_FO2_05(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_05*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_05(void);
/*1. Clear or Initilal screen for  S72_SET_GAS_FO2_06 operation*/
void IniOrClrScrFunc_S72_SET_GAS_FO2_06(void);
/*1.3 Flashing or keep update content of items S72_SET_GAS_FO2_06 */
void UpdOrFlasFunc_S72_SET_GAS_FO2_06(void);
/*2. Process preOpcode after change to S72_SET_GAS_FO2_06 */
void HandlePreOCFunc_S72_SET_GAS_FO2_06(void);
/*Condition check to progress preOC valueS72_SET_GAS_FO2_06*/
unsigned char CondiPreOcCheck_S72_SET_GAS_FO2_06(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_01 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_01(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_01 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_01(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_01*/
unsigned char CondiCheck_S73_SET_GAS_FHe_01(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_01 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_01(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_02 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_02(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_02 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_02(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_02*/
unsigned char CondiCheck_S73_SET_GAS_FHe_02(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_02 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_02(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_03 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_03(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_03 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_03(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_03*/
unsigned char CondiCheck_S73_SET_GAS_FHe_03(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_03 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_03(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_04 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_04(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_04 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_04(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_04*/
unsigned char CondiCheck_S73_SET_GAS_FHe_04(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_04 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_04(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_05 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_05(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_05 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_05(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_05*/
unsigned char CondiCheck_S73_SET_GAS_FHe_05(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_05 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_05(void);
/*1. Clear or Initilal screen for  S73_SET_GAS_FHe_06 operation*/
void IniOrClrScrFunc_S73_SET_GAS_FHe_06(void);
/*1.2 Update the porition screen when the opcode changed for S73_SET_GAS_FHe_06 operation*/
void UpdPorFunc_S73_SET_GAS_FHe_06(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S73_SET_GAS_FHe_06*/
unsigned char CondiCheck_S73_SET_GAS_FHe_06(void);
/*1.3 Flashing or keep update content of items S73_SET_GAS_FHe_06 */
void UpdOrFlasFunc_S73_SET_GAS_FHe_06(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_01 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_01(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_01 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_01(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_02 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_02(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_02 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_02(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_03 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_03(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_03 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_03(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_04 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_04(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_04 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_04(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_05 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_05(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_05 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_05(void);
/*1. Clear or Initilal screen for  S74_SET_GAS_TMT_06 operation*/
void IniOrClrScrFunc_S74_SET_GAS_TMT_06(void);
/*1.3 Flashing or keep update content of items S74_SET_GAS_TMT_06 */
void UpdOrFlasFunc_S74_SET_GAS_TMT_06(void);
/*1. Clear or Initilal screen for  S75_SET_GAS_TMT_WARNING operation*/
void IniOrClrScrFunc_S75_SET_GAS_TMT_WARNING(void);
/*1. Clear or Initilal screen for  S79_SET_GAS_FHE_WARNING operation*/
void IniOrClrScrFunc_S79_SET_GAS_FHE_WARNING(void);
/*1. Clear or Initilal screen for  TMTSWITCH_TMT_SET operation*/
void IniOrClrScrFunc_TMTSWITCH_TMT_SET(void);
/*1.3 Flashing or keep update content of items TMTSWITCH_TMT_SET */
void UpdOrFlasFunc_TMTSWITCH_TMT_SET(void);
/*1. Clear or Initilal screen for  S462_O2ANALYZER_CALIBRATE operation*/
void IniOrClrScrFunc_S462_O2ANALYZER_CALIBRATE(void);
/*1.2 Update the porition screen when the opcode changed for S462_O2ANALYZER_CALIBRATE operation*/
void UpdPorFunc_S462_O2ANALYZER_CALIBRATE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S462_O2ANALYZER_CALIBRATE*/
unsigned char CondiCheck_S462_O2ANALYZER_CALIBRATE(void);
/*1.3 Flashing or keep update content of items S462_O2ANALYZER_CALIBRATE */
void UpdOrFlasFunc_S462_O2ANALYZER_CALIBRATE(void);
/*2. Process preOpcode after change to S462_O2ANALYZER_CALIBRATE */
void HandlePreOCFunc_S462_O2ANALYZER_CALIBRATE(void);
/*Condition check to progress preOC valueS462_O2ANALYZER_CALIBRATE*/
unsigned char CondiPreOcCheck_S462_O2ANALYZER_CALIBRATE(void);
/*1. Clear or Initilal screen for  S463_O2ANALYZER_CALIBRATE_SET_GAS operation*/
void IniOrClrScrFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS(void);
/*1.3 Flashing or keep update content of items S463_O2ANALYZER_CALIBRATE_SET_GAS */
void UpdOrFlasFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS(void);
/*1. Clear or Initilal screen for  S464_O2ANALYZER_CALIBRATE_READY operation*/
void IniOrClrScrFunc_S464_O2ANALYZER_CALIBRATE_READY(void);
/*1. Clear or Initilal screen for  S465_O2ANALYZER_CALIBRATE_READ_O2 operation*/
void IniOrClrScrFunc_S465_O2ANALYZER_CALIBRATE_READ_O2(void);
/*1. Clear or Initilal screen for  S466_O2ANALYZER_CALIBRATE_NO_CELL_O2 operation*/
void IniOrClrScrFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2(void);
/*1. Clear or Initilal screen for  S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER operation*/
void IniOrClrScrFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER(void);
/*1. Clear or Initilal screen for  S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP operation*/
void IniOrClrScrFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP(void);
/*1.3 Flashing or keep update content of items S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP */
void UpdOrFlasFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP(void);
/*1. Clear or Initilal screen for  S468_O2ANALYZER_CALIBRATE_CELL_V operation*/
void IniOrClrScrFunc_S468_O2ANALYZER_CALIBRATE_CELL_V(void);
/*1. Clear or Initilal screen for  S469_O2ANALYZER_CALIBRATE_COMPLETE operation*/
void IniOrClrScrFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE(void);
/*1. Clear or Initilal screen for  S470_O2ANALYZER_ANALYZE operation*/
void IniOrClrScrFunc_S470_O2ANALYZER_ANALYZE(void);
/*1.2 Update the porition screen when the opcode changed for S470_O2ANALYZER_ANALYZE operation*/
void UpdPorFunc_S470_O2ANALYZER_ANALYZE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S470_O2ANALYZER_ANALYZE*/
unsigned char CondiCheck_S470_O2ANALYZER_ANALYZE(void);
/*2. Process preOpcode after change to S470_O2ANALYZER_ANALYZE */
void HandlePreOCFunc_S470_O2ANALYZER_ANALYZE(void);
/*Condition check to progress preOC valueS470_O2ANALYZER_ANALYZE*/
unsigned char CondiPreOcCheck_S470_O2ANALYZER_ANALYZE(void);
/*1. Clear or Initilal screen for  S471_ANALYZE_CALIB_WARINING operation*/
void IniOrClrScrFunc_S471_ANALYZE_CALIB_WARINING(void);
/*1. Clear or Initilal screen for  S472_ANALYZE_READY operation*/
void IniOrClrScrFunc_S472_ANALYZE_READY(void);
/*1. Clear or Initilal screen for  S473_ANALYZE_ANALYZING operation*/
void IniOrClrScrFunc_S473_ANALYZE_ANALYZING(void);
/*1.3 Flashing or keep update content of items S473_ANALYZE_ANALYZING */
void UpdOrFlasFunc_S473_ANALYZE_ANALYZING(void);
/*1. Clear or Initilal screen for  S474_ANALYZE_CONFIRM operation*/
void IniOrClrScrFunc_S474_ANALYZE_CONFIRM(void);
/*1.3 Flashing or keep update content of items S474_ANALYZE_CONFIRM */
void UpdOrFlasFunc_S474_ANALYZE_CONFIRM(void);
/*1. Clear or Initilal screen for  S475_ANALYZE_ASSIGN_FO2_CONFIRM operation*/
void IniOrClrScrFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM(void);
/*1.3 Flashing or keep update content of items S475_ANALYZE_ASSIGN_FO2_CONFIRM */
void UpdOrFlasFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM(void);
/*1. Clear or Initilal screen for  S475A_ANALYZE_SET_FHE operation*/
void IniOrClrScrFunc_S475A_ANALYZE_SET_FHE(void);
/*1.3 Flashing or keep update content of items S475A_ANALYZE_SET_FHE */
void UpdOrFlasFunc_S475A_ANALYZE_SET_FHE(void);
/*1. Clear or Initilal screen for  S476_ANALYZE_SELECT_GAS_LIST_MODE operation*/
void IniOrClrScrFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE(void);
/*1.3 Flashing or keep update content of items S476_ANALYZE_SELECT_GAS_LIST_MODE */
void UpdOrFlasFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE(void);
/*1. Clear or Initilal screen for  S477_ANALYZE_SELECT_GAS_TO_ASSIGN operation*/
void IniOrClrScrFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN(void);
/*1.3 Flashing or keep update content of items S477_ANALYZE_SELECT_GAS_TO_ASSIGN */
void UpdOrFlasFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN(void);
/*1. Clear or Initilal screen for  S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS operation*/
void IniOrClrScrFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS(void);
/*1.3 Flashing or keep update content of items S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS */
void UpdOrFlasFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS(void);
/*1. Clear or Initilal screen for  S479_ANALYZE_ASSIGN_COMPLETE operation*/
void IniOrClrScrFunc_S479_ANALYZE_ASSIGN_COMPLETE(void);
/*1. Clear or Initilal screen for  S486_ANALYZE_SET_BOTH_OCL_OCR operation*/
void IniOrClrScrFunc_S486_ANALYZE_SET_BOTH_OCL_OCR(void);
/*1. Clear or Initilal screen for  S54_SP_HIGH_SP operation*/
void IniOrClrScrFunc_S54_SP_HIGH_SP(void);
/*1.2 Update the porition screen when the opcode changed for S54_SP_HIGH_SP operation*/
void UpdPorFunc_S54_SP_HIGH_SP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_HIGH_SP*/
unsigned char CondiCheck_S54_SP_HIGH_SP(void);
/*2. Process preOpcode after change to S54_SP_HIGH_SP */
void HandlePreOCFunc_S54_SP_HIGH_SP(void);
/*Condition check to progress preOC valueS54_SP_HIGH_SP*/
unsigned char CondiPreOcCheck_S54_SP_HIGH_SP(void);
/*1. Clear or Initilal screen for  S54_SP_LOW_SP operation*/
void IniOrClrScrFunc_S54_SP_LOW_SP(void);
/*1.2 Update the porition screen when the opcode changed for S54_SP_LOW_SP operation*/
void UpdPorFunc_S54_SP_LOW_SP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S54_SP_LOW_SP*/
unsigned char CondiCheck_S54_SP_LOW_SP(void);
/*2. Process preOpcode after change to S54_SP_LOW_SP */
void HandlePreOCFunc_S54_SP_LOW_SP(void);
/*Condition check to progress preOC valueS54_SP_LOW_SP*/
unsigned char CondiPreOcCheck_S54_SP_LOW_SP(void);
/*1. Clear or Initilal screen for  S56_SP_CUSTOM_SP operation*/
void IniOrClrScrFunc_S56_SP_CUSTOM_SP(void);
/*1.2 Update the porition screen when the opcode changed for S56_SP_CUSTOM_SP operation*/
void UpdPorFunc_S56_SP_CUSTOM_SP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S56_SP_CUSTOM_SP*/
unsigned char CondiCheck_S56_SP_CUSTOM_SP(void);
/*2. Process preOpcode after change to S56_SP_CUSTOM_SP */
void HandlePreOCFunc_S56_SP_CUSTOM_SP(void);
/*Condition check to progress preOC valueS56_SP_CUSTOM_SP*/
unsigned char CondiPreOcCheck_S56_SP_CUSTOM_SP(void);
/*1. Clear or Initilal screen for  S59_SP_AUTO_HIGH operation*/
void IniOrClrScrFunc_S59_SP_AUTO_HIGH(void);
/*1.2 Update the porition screen when the opcode changed for S59_SP_AUTO_HIGH operation*/
void UpdPorFunc_S59_SP_AUTO_HIGH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_HIGH*/
unsigned char CondiCheck_S59_SP_AUTO_HIGH(void);
/*2. Process preOpcode after change to S59_SP_AUTO_HIGH */
void HandlePreOCFunc_S59_SP_AUTO_HIGH(void);
/*Condition check to progress preOC valueS59_SP_AUTO_HIGH*/
unsigned char CondiPreOcCheck_S59_SP_AUTO_HIGH(void);
/*1. Clear or Initilal screen for  S59_SP_AUTO_LOW operation*/
void IniOrClrScrFunc_S59_SP_AUTO_LOW(void);
/*1.2 Update the porition screen when the opcode changed for S59_SP_AUTO_LOW operation*/
void UpdPorFunc_S59_SP_AUTO_LOW(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S59_SP_AUTO_LOW*/
unsigned char CondiCheck_S59_SP_AUTO_LOW(void);
/*2. Process preOpcode after change to S59_SP_AUTO_LOW */
void HandlePreOCFunc_S59_SP_AUTO_LOW(void);
/*Condition check to progress preOC valueS59_SP_AUTO_LOW*/
unsigned char CondiPreOcCheck_S59_SP_AUTO_LOW(void);
/*1. Clear or Initilal screen for  SP_HIGH_SP_SET operation*/
void IniOrClrScrFunc_SP_HIGH_SP_SET(void);
/*1.3 Flashing or keep update content of items SP_HIGH_SP_SET */
void UpdOrFlasFunc_SP_HIGH_SP_SET(void);
/*1. Clear or Initilal screen for  SP_LOW_SP_SET operation*/
void IniOrClrScrFunc_SP_LOW_SP_SET(void);
/*1.3 Flashing or keep update content of items SP_LOW_SP_SET */
void UpdOrFlasFunc_SP_LOW_SP_SET(void);
/*1. Clear or Initilal screen for  SP_CUSTOM_SP_STAT operation*/
void IniOrClrScrFunc_SP_CUSTOM_SP_STAT(void);
/*1.3 Flashing or keep update content of items SP_CUSTOM_SP_STAT */
void UpdOrFlasFunc_SP_CUSTOM_SP_STAT(void);
/*1. Clear or Initilal screen for  SP_CUSTOM_SP_SET operation*/
void IniOrClrScrFunc_SP_CUSTOM_SP_SET(void);
/*1.3 Flashing or keep update content of items SP_CUSTOM_SP_SET */
void UpdOrFlasFunc_SP_CUSTOM_SP_SET(void);
/*1. Clear or Initilal screen for  SP_AUTO_HIGH_STAT operation*/
void IniOrClrScrFunc_SP_AUTO_HIGH_STAT(void);
/*1.3 Flashing or keep update content of items SP_AUTO_HIGH_STAT */
void UpdOrFlasFunc_SP_AUTO_HIGH_STAT(void);
/*1. Clear or Initilal screen for  SP_AUTO_HIGH_SET operation*/
void IniOrClrScrFunc_SP_AUTO_HIGH_SET(void);
/*1.3 Flashing or keep update content of items SP_AUTO_HIGH_SET */
void UpdOrFlasFunc_SP_AUTO_HIGH_SET(void);
/*1. Clear or Initilal screen for  SP_AUTO_LOW_STAT operation*/
void IniOrClrScrFunc_SP_AUTO_LOW_STAT(void);
/*1.3 Flashing or keep update content of items SP_AUTO_LOW_STAT */
void UpdOrFlasFunc_SP_AUTO_LOW_STAT(void);
/*1. Clear or Initilal screen for  SP_AUTO_LOW_SET operation*/
void IniOrClrScrFunc_SP_AUTO_LOW_SET(void);
/*1.3 Flashing or keep update content of items SP_AUTO_LOW_SET */
void UpdOrFlasFunc_SP_AUTO_LOW_SET(void);
/*1. Clear or Initilal screen for  S99_SET_DIVEMODE operation*/
void IniOrClrScrFunc_S99_SET_DIVEMODE(void);
/*1.2 Update the porition screen when the opcode changed for S99_SET_DIVEMODE operation*/
void UpdPorFunc_S99_SET_DIVEMODE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S99_SET_DIVEMODE*/
unsigned char CondiCheck_S99_SET_DIVEMODE(void);
/*2. Process preOpcode after change to S99_SET_DIVEMODE */
void HandlePreOCFunc_S99_SET_DIVEMODE(void);
/*Condition check to progress preOC valueS99_SET_DIVEMODE*/
unsigned char CondiPreOcCheck_S99_SET_DIVEMODE(void);
/*1. Clear or Initilal screen for  S76_SET_BAILOUTPO2LIMITS operation*/
void IniOrClrScrFunc_S76_SET_BAILOUTPO2LIMITS(void);
/*1.2 Update the porition screen when the opcode changed for S76_SET_BAILOUTPO2LIMITS operation*/
void UpdPorFunc_S76_SET_BAILOUTPO2LIMITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S76_SET_BAILOUTPO2LIMITS*/
unsigned char CondiCheck_S76_SET_BAILOUTPO2LIMITS(void);
/*2. Process preOpcode after change to S76_SET_BAILOUTPO2LIMITS */
void HandlePreOCFunc_S76_SET_BAILOUTPO2LIMITS(void);
/*Condition check to progress preOC valueS76_SET_BAILOUTPO2LIMITS*/
unsigned char CondiPreOcCheck_S76_SET_BAILOUTPO2LIMITS(void);
/*1. Clear or Initilal screen for  S83_SET_CONSERVATISM operation*/
void IniOrClrScrFunc_S83_SET_CONSERVATISM(void);
/*1.2 Update the porition screen when the opcode changed for S83_SET_CONSERVATISM operation*/
void UpdPorFunc_S83_SET_CONSERVATISM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S83_SET_CONSERVATISM*/
unsigned char CondiCheck_S83_SET_CONSERVATISM(void);
/*2. Process preOpcode after change to S83_SET_CONSERVATISM */
void HandlePreOCFunc_S83_SET_CONSERVATISM(void);
/*Condition check to progress preOC valueS83_SET_CONSERVATISM*/
unsigned char CondiPreOcCheck_S83_SET_CONSERVATISM(void);
/*1. Clear or Initilal screen for  S91_SET_SAFETYSTOP operation*/
void IniOrClrScrFunc_S91_SET_SAFETYSTOP(void);
/*1.2 Update the porition screen when the opcode changed for S91_SET_SAFETYSTOP operation*/
void UpdPorFunc_S91_SET_SAFETYSTOP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S91_SET_SAFETYSTOP*/
unsigned char CondiCheck_S91_SET_SAFETYSTOP(void);
/*2. Process preOpcode after change to S91_SET_SAFETYSTOP */
void HandlePreOCFunc_S91_SET_SAFETYSTOP(void);
/*Condition check to progress preOC valueS91_SET_SAFETYSTOP*/
unsigned char CondiPreOcCheck_S91_SET_SAFETYSTOP(void);
/*1. Clear or Initilal screen for  S96_SET_LASTSTOPDEPTH operation*/
void IniOrClrScrFunc_S96_SET_LASTSTOPDEPTH(void);
/*1.2 Update the porition screen when the opcode changed for S96_SET_LASTSTOPDEPTH operation*/
void UpdPorFunc_S96_SET_LASTSTOPDEPTH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S96_SET_LASTSTOPDEPTH*/
unsigned char CondiCheck_S96_SET_LASTSTOPDEPTH(void);
/*2. Process preOpcode after change to S96_SET_LASTSTOPDEPTH */
void HandlePreOCFunc_S96_SET_LASTSTOPDEPTH(void);
/*Condition check to progress preOC valueS96_SET_LASTSTOPDEPTH*/
unsigned char CondiPreOcCheck_S96_SET_LASTSTOPDEPTH(void);
/*1. Clear or Initilal screen for  DIVEMODE_SETPOINTS operation*/
void IniOrClrScrFunc_DIVEMODE_SETPOINTS(void);
/*1.3 Flashing or keep update content of items DIVEMODE_SETPOINTS */
void UpdOrFlasFunc_DIVEMODE_SETPOINTS(void);
/*1. Clear or Initilal screen for  SET_SAFETYSTOP_STAT operation*/
void IniOrClrScrFunc_SET_SAFETYSTOP_STAT(void);
/*1.3 Flashing or keep update content of items SET_SAFETYSTOP_STAT */
void UpdOrFlasFunc_SET_SAFETYSTOP_STAT(void);
/*1. Clear or Initilal screen for  SET_SAFETYSTOP_DEPTHT operation*/
void IniOrClrScrFunc_SET_SAFETYSTOP_DEPTHT(void);
/*1.3 Flashing or keep update content of items SET_SAFETYSTOP_DEPTHT */
void UpdOrFlasFunc_SET_SAFETYSTOP_DEPTHT(void);
/*2. Process preOpcode after change to SET_SAFETYSTOP_DEPTHT */
void HandlePreOCFunc_SET_SAFETYSTOP_DEPTHT(void);
/*Condition check to progress preOC valueSET_SAFETYSTOP_DEPTHT*/
unsigned char CondiPreOcCheck_SET_SAFETYSTOP_DEPTHT(void);
/*1.3 Flashing or keep update content of items SET_SAFETYSTOP_TIME */
void UpdOrFlasFunc_SET_SAFETYSTOP_TIME(void);
/*1. Clear or Initilal screen for  LASTSTOPDEPTH_SETPOINTS operation*/
void IniOrClrScrFunc_LASTSTOPDEPTH_SETPOINTS(void);
/*1.3 Flashing or keep update content of items LASTSTOPDEPTH_SETPOINTS */
void UpdOrFlasFunc_LASTSTOPDEPTH_SETPOINTS(void);
/*1. Clear or Initilal screen for  S106_AL_AUDIBLE operation*/
void IniOrClrScrFunc_S106_AL_AUDIBLE(void);
/*1.2 Update the porition screen when the opcode changed for S106_AL_AUDIBLE operation*/
void UpdPorFunc_S106_AL_AUDIBLE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S106_AL_AUDIBLE*/
unsigned char CondiCheck_S106_AL_AUDIBLE(void);
/*2. Process preOpcode after change to S106_AL_AUDIBLE */
void HandlePreOCFunc_S106_AL_AUDIBLE(void);
/*Condition check to progress preOC valueS106_AL_AUDIBLE*/
unsigned char CondiPreOcCheck_S106_AL_AUDIBLE(void);
/*1. Clear or Initilal screen for  S108_AL_DEPTH operation*/
void IniOrClrScrFunc_S108_AL_DEPTH(void);
/*1.2 Update the porition screen when the opcode changed for S108_AL_DEPTH operation*/
void UpdPorFunc_S108_AL_DEPTH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S108_AL_DEPTH*/
unsigned char CondiCheck_S108_AL_DEPTH(void);
/*2. Process preOpcode after change to S108_AL_DEPTH */
void HandlePreOCFunc_S108_AL_DEPTH(void);
/*Condition check to progress preOC valueS108_AL_DEPTH*/
unsigned char CondiPreOcCheck_S108_AL_DEPTH(void);
/*1. Clear or Initilal screen for  S111_AL_DIVETIME operation*/
void IniOrClrScrFunc_S111_AL_DIVETIME(void);
/*1.2 Update the porition screen when the opcode changed for S111_AL_DIVETIME operation*/
void UpdPorFunc_S111_AL_DIVETIME(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S111_AL_DIVETIME*/
unsigned char CondiCheck_S111_AL_DIVETIME(void);
/*2. Process preOpcode after change to S111_AL_DIVETIME */
void HandlePreOCFunc_S111_AL_DIVETIME(void);
/*Condition check to progress preOC valueS111_AL_DIVETIME*/
unsigned char CondiPreOcCheck_S111_AL_DIVETIME(void);
/*1. Clear or Initilal screen for  S116_AL_DTR operation*/
void IniOrClrScrFunc_S116_AL_DTR(void);
/*1.2 Update the porition screen when the opcode changed for S116_AL_DTR operation*/
void UpdPorFunc_S116_AL_DTR(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_DTR*/
unsigned char CondiCheck_S116_AL_DTR(void);
/*2. Process preOpcode after change to S116_AL_DTR */
void HandlePreOCFunc_S116_AL_DTR(void);
/*Condition check to progress preOC valueS116_AL_DTR*/
unsigned char CondiPreOcCheck_S116_AL_DTR(void);
/*1. Clear or Initilal screen for  S116_AL_TANK_PRESS operation*/
void IniOrClrScrFunc_S116_AL_TANK_PRESS(void);
/*1.2 Update the porition screen when the opcode changed for S116_AL_TANK_PRESS operation*/
void UpdPorFunc_S116_AL_TANK_PRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S116_AL_TANK_PRESS*/
unsigned char CondiCheck_S116_AL_TANK_PRESS(void);
/*2. Process preOpcode after change to S116_AL_TANK_PRESS */
void HandlePreOCFunc_S116_AL_TANK_PRESS(void);
/*Condition check to progress preOC valueS116_AL_TANK_PRESS*/
unsigned char CondiPreOcCheck_S116_AL_TANK_PRESS(void);
/*1. Clear or Initilal screen for  S119_AL_CC6_PRESS operation*/
void IniOrClrScrFunc_S119_AL_CC6_PRESS(void);
/*1.2 Update the porition screen when the opcode changed for S119_AL_CC6_PRESS operation*/
void UpdPorFunc_S119_AL_CC6_PRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S119_AL_CC6_PRESS*/
unsigned char CondiCheck_S119_AL_CC6_PRESS(void);
/*2. Process preOpcode after change to S119_AL_CC6_PRESS */
void HandlePreOCFunc_S119_AL_CC6_PRESS(void);
/*Condition check to progress preOC valueS119_AL_CC6_PRESS*/
unsigned char CondiPreOcCheck_S119_AL_CC6_PRESS(void);
/*1. Clear or Initilal screen for  S122_AL_GF_N2 operation*/
void IniOrClrScrFunc_S122_AL_GF_N2(void);
/*1.2 Update the porition screen when the opcode changed for S122_AL_GF_N2 operation*/
void UpdPorFunc_S122_AL_GF_N2(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S122_AL_GF_N2*/
unsigned char CondiCheck_S122_AL_GF_N2(void);
/*2. Process preOpcode after change to S122_AL_GF_N2 */
void HandlePreOCFunc_S122_AL_GF_N2(void);
/*Condition check to progress preOC valueS122_AL_GF_N2*/
unsigned char CondiPreOcCheck_S122_AL_GF_N2(void);
/*1. Clear or Initilal screen for  S281_AL_TURN_END_PRESS operation*/
void IniOrClrScrFunc_S281_AL_TURN_END_PRESS(void);
/*1.2 Update the porition screen when the opcode changed for S281_AL_TURN_END_PRESS operation*/
void UpdPorFunc_S281_AL_TURN_END_PRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S281_AL_TURN_END_PRESS*/
unsigned char CondiCheck_S281_AL_TURN_END_PRESS(void);
/*2. Process preOpcode after change to S281_AL_TURN_END_PRESS */
void HandlePreOCFunc_S281_AL_TURN_END_PRESS(void);
/*Condition check to progress preOC valueS281_AL_TURN_END_PRESS*/
unsigned char CondiPreOcCheck_S281_AL_TURN_END_PRESS(void);
/*1. Clear or Initilal screen for  S288_AL_END_WOB_ICD_ALARMS operation*/
void IniOrClrScrFunc_S288_AL_END_WOB_ICD_ALARMS(void);
/*1.2 Update the porition screen when the opcode changed for S288_AL_END_WOB_ICD_ALARMS operation*/
void UpdPorFunc_S288_AL_END_WOB_ICD_ALARMS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S288_AL_END_WOB_ICD_ALARMS*/
unsigned char CondiCheck_S288_AL_END_WOB_ICD_ALARMS(void);
/*2. Process preOpcode after change to S288_AL_END_WOB_ICD_ALARMS */
void HandlePreOCFunc_S288_AL_END_WOB_ICD_ALARMS(void);
/*Condition check to progress preOC valueS288_AL_END_WOB_ICD_ALARMS*/
unsigned char CondiPreOcCheck_S288_AL_END_WOB_ICD_ALARMS(void);
/*1. Clear or Initilal screen for  S000_AL_DIVETIME_TTS operation*/
void IniOrClrScrFunc_S000_AL_DIVETIME_TTS(void);
/*1.2 Update the porition screen when the opcode changed for S000_AL_DIVETIME_TTS operation*/
void UpdPorFunc_S000_AL_DIVETIME_TTS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S000_AL_DIVETIME_TTS*/
unsigned char CondiCheck_S000_AL_DIVETIME_TTS(void);
/*2. Process preOpcode after change to S000_AL_DIVETIME_TTS */
void HandlePreOCFunc_S000_AL_DIVETIME_TTS(void);
/*Condition check to progress preOC valueS000_AL_DIVETIME_TTS*/
unsigned char CondiPreOcCheck_S000_AL_DIVETIME_TTS(void);
/*1. Clear or Initilal screen for  S128_DEVICE_TRANSMITTERS operation*/
void IniOrClrScrFunc_S128_DEVICE_TRANSMITTERS(void);
/*1.2 Update the porition screen when the opcode changed for S128_DEVICE_TRANSMITTERS operation*/
void UpdPorFunc_S128_DEVICE_TRANSMITTERS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_DEVICE_TRANSMITTERS*/
unsigned char CondiCheck_S128_DEVICE_TRANSMITTERS(void);
/*2. Process preOpcode after change to S128_DEVICE_TRANSMITTERS */
void HandlePreOCFunc_S128_DEVICE_TRANSMITTERS(void);
/*Condition check to progress preOC valueS128_DEVICE_TRANSMITTERS*/
unsigned char CondiPreOcCheck_S128_DEVICE_TRANSMITTERS(void);
/*1. Clear or Initilal screen for  S137_DEVICE_UNITS operation*/
void IniOrClrScrFunc_S137_DEVICE_UNITS(void);
/*1.2 Update the porition screen when the opcode changed for S137_DEVICE_UNITS operation*/
void UpdPorFunc_S137_DEVICE_UNITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S137_DEVICE_UNITS*/
unsigned char CondiCheck_S137_DEVICE_UNITS(void);
/*2. Process preOpcode after change to S137_DEVICE_UNITS */
void HandlePreOCFunc_S137_DEVICE_UNITS(void);
/*Condition check to progress preOC valueS137_DEVICE_UNITS*/
unsigned char CondiPreOcCheck_S137_DEVICE_UNITS(void);
/*1. Clear or Initilal screen for  S139_DEVICE_WATERTYPE operation*/
void IniOrClrScrFunc_S139_DEVICE_WATERTYPE(void);
/*1.2 Update the porition screen when the opcode changed for S139_DEVICE_WATERTYPE operation*/
void UpdPorFunc_S139_DEVICE_WATERTYPE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S139_DEVICE_WATERTYPE*/
unsigned char CondiCheck_S139_DEVICE_WATERTYPE(void);
/*2. Process preOpcode after change to S139_DEVICE_WATERTYPE */
void HandlePreOCFunc_S139_DEVICE_WATERTYPE(void);
/*Condition check to progress preOC valueS139_DEVICE_WATERTYPE*/
unsigned char CondiPreOcCheck_S139_DEVICE_WATERTYPE(void);
/*1. Clear or Initilal screen for  S141_DEVICE_SAMPLERATE operation*/
void IniOrClrScrFunc_S141_DEVICE_SAMPLERATE(void);
/*1.2 Update the porition screen when the opcode changed for S141_DEVICE_SAMPLERATE operation*/
void UpdPorFunc_S141_DEVICE_SAMPLERATE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S141_DEVICE_SAMPLERATE*/
unsigned char CondiCheck_S141_DEVICE_SAMPLERATE(void);
/*2. Process preOpcode after change to S141_DEVICE_SAMPLERATE */
void HandlePreOCFunc_S141_DEVICE_SAMPLERATE(void);
/*Condition check to progress preOC valueS141_DEVICE_SAMPLERATE*/
unsigned char CondiPreOcCheck_S141_DEVICE_SAMPLERATE(void);
/*1. Clear or Initilal screen for  S143_DEVICE_BLUETOOTH operation*/
void IniOrClrScrFunc_S143_DEVICE_BLUETOOTH(void);
/*1.2 Update the porition screen when the opcode changed for S143_DEVICE_BLUETOOTH operation*/
void UpdPorFunc_S143_DEVICE_BLUETOOTH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S143_DEVICE_BLUETOOTH*/
unsigned char CondiCheck_S143_DEVICE_BLUETOOTH(void);
/*2. Process preOpcode after change to S143_DEVICE_BLUETOOTH */
void HandlePreOCFunc_S143_DEVICE_BLUETOOTH(void);
/*Condition check to progress preOC valueS143_DEVICE_BLUETOOTH*/
unsigned char CondiPreOcCheck_S143_DEVICE_BLUETOOTH(void);
/*1. Clear or Initilal screen for  TBD_DEVICE_RESETSETTINGS operation*/
void IniOrClrScrFunc_TBD_DEVICE_RESETSETTINGS(void);
/*1.2 Update the porition screen when the opcode changed for TBD_DEVICE_RESETSETTINGS operation*/
void UpdPorFunc_TBD_DEVICE_RESETSETTINGS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_RESETSETTINGS*/
unsigned char CondiCheck_TBD_DEVICE_RESETSETTINGS(void);
/*2. Process preOpcode after change to TBD_DEVICE_RESETSETTINGS */
void HandlePreOCFunc_TBD_DEVICE_RESETSETTINGS(void);
/*Condition check to progress preOC valueTBD_DEVICE_RESETSETTINGS*/
unsigned char CondiPreOcCheck_TBD_DEVICE_RESETSETTINGS(void);
/*1. Clear or Initilal screen for  TBD_DEVICE_WELCOMESCREEN operation*/
void IniOrClrScrFunc_TBD_DEVICE_WELCOMESCREEN(void);
/*1.2 Update the porition screen when the opcode changed for TBD_DEVICE_WELCOMESCREEN operation*/
void UpdPorFunc_TBD_DEVICE_WELCOMESCREEN(void);
/*Condition check return the result when need to clear all the the screen or one portion only of TBD_DEVICE_WELCOMESCREEN*/
unsigned char CondiCheck_TBD_DEVICE_WELCOMESCREEN(void);
/*2. Process preOpcode after change to TBD_DEVICE_WELCOMESCREEN */
void HandlePreOCFunc_TBD_DEVICE_WELCOMESCREEN(void);
/*Condition check to progress preOC valueTBD_DEVICE_WELCOMESCREEN*/
unsigned char CondiPreOcCheck_TBD_DEVICE_WELCOMESCREEN(void);
/*1. Clear or Initilal screen for  DEVICE_UNITS_SET operation*/
void IniOrClrScrFunc_DEVICE_UNITS_SET(void);
/*1.3 Flashing or keep update content of items DEVICE_UNITS_SET */
void UpdOrFlasFunc_DEVICE_UNITS_SET(void);
/*1. Clear or Initilal screen for  DEVICE_WATERTYPE_SET operation*/
void IniOrClrScrFunc_DEVICE_WATERTYPE_SET(void);
/*1.3 Flashing or keep update content of items DEVICE_WATERTYPE_SET */
void UpdOrFlasFunc_DEVICE_WATERTYPE_SET(void);
/*1. Clear or Initilal screen for  DEVICE_SAMPLERATE_SET operation*/
void IniOrClrScrFunc_DEVICE_SAMPLERATE_SET(void);
/*1.3 Flashing or keep update content of items DEVICE_SAMPLERATE_SET */
void UpdOrFlasFunc_DEVICE_SAMPLERATE_SET(void);
/*1. Clear or Initilal screen for  DEVICE_BLUETOOTH_SET operation*/
void IniOrClrScrFunc_DEVICE_BLUETOOTH_SET(void);
/*1.3 Flashing or keep update content of items DEVICE_BLUETOOTH_SET */
void UpdOrFlasFunc_DEVICE_BLUETOOTH_SET(void);
/*1. Clear or Initilal screen for  DEVICE_BLUETOOTH_PASSCODE operation*/
void IniOrClrScrFunc_DEVICE_BLUETOOTH_PASSCODE(void);
/*1.3 Flashing or keep update content of items DEVICE_BLUETOOTH_PASSCODE */
void UpdOrFlasFunc_DEVICE_BLUETOOTH_PASSCODE(void);
/*1. Clear or Initilal screen for  DEVICE_BLUETOOTH_DOWNLOAD_DATA operation*/
void IniOrClrScrFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA(void);
/*1.3 Flashing or keep update content of items DEVICE_BLUETOOTH_DOWNLOAD_DATA */
void UpdOrFlasFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA(void);
/*1. Clear or Initilal screen for  RESETSETTINGS_S1 operation*/
void IniOrClrScrFunc_RESETSETTINGS_S1(void);
/*1. Clear or Initilal screen for  RESETSETTINGS_S2 operation*/
void IniOrClrScrFunc_RESETSETTINGS_S2(void);
/*1. Clear or Initilal screen for  WELCOMESCREEN_SET operation*/
void IniOrClrScrFunc_WELCOMESCREEN_SET(void);
/*1.3 Flashing or keep update content of items WELCOMESCREEN_SET */
void UpdOrFlasFunc_WELCOMESCREEN_SET(void);
/*1. Clear or Initilal screen for  S162_DISPLAY_BRIGHTNESS operation*/
void IniOrClrScrFunc_S162_DISPLAY_BRIGHTNESS(void);
/*1.2 Update the porition screen when the opcode changed for S162_DISPLAY_BRIGHTNESS operation*/
void UpdPorFunc_S162_DISPLAY_BRIGHTNESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S162_DISPLAY_BRIGHTNESS*/
unsigned char CondiCheck_S162_DISPLAY_BRIGHTNESS(void);
/*2. Process preOpcode after change to S162_DISPLAY_BRIGHTNESS */
void HandlePreOCFunc_S162_DISPLAY_BRIGHTNESS(void);
/*Condition check to progress preOC valueS162_DISPLAY_BRIGHTNESS*/
unsigned char CondiPreOcCheck_S162_DISPLAY_BRIGHTNESS(void);
/*1. Clear or Initilal screen for  S164_DISPLAY_AUTODIM operation*/
void IniOrClrScrFunc_S164_DISPLAY_AUTODIM(void);
/*1.2 Update the porition screen when the opcode changed for S164_DISPLAY_AUTODIM operation*/
void UpdPorFunc_S164_DISPLAY_AUTODIM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S164_DISPLAY_AUTODIM*/
unsigned char CondiCheck_S164_DISPLAY_AUTODIM(void);
/*2. Process preOpcode after change to S164_DISPLAY_AUTODIM */
void HandlePreOCFunc_S164_DISPLAY_AUTODIM(void);
/*Condition check to progress preOC valueS164_DISPLAY_AUTODIM*/
unsigned char CondiPreOcCheck_S164_DISPLAY_AUTODIM(void);
/*1. Clear or Initilal screen for  S173_DISPLAY_TITLESCOLOR operation*/
void IniOrClrScrFunc_S173_DISPLAY_TITLESCOLOR(void);
/*1.2 Update the porition screen when the opcode changed for S173_DISPLAY_TITLESCOLOR operation*/
void UpdPorFunc_S173_DISPLAY_TITLESCOLOR(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S173_DISPLAY_TITLESCOLOR*/
unsigned char CondiCheck_S173_DISPLAY_TITLESCOLOR(void);
/*2. Process preOpcode after change to S173_DISPLAY_TITLESCOLOR */
void HandlePreOCFunc_S173_DISPLAY_TITLESCOLOR(void);
/*Condition check to progress preOC valueS173_DISPLAY_TITLESCOLOR*/
unsigned char CondiPreOcCheck_S173_DISPLAY_TITLESCOLOR(void);
/*1. Clear or Initilal screen for  S179_DISPLAY_LANGUAGE operation*/
void IniOrClrScrFunc_S179_DISPLAY_LANGUAGE(void);
/*1.2 Update the porition screen when the opcode changed for S179_DISPLAY_LANGUAGE operation*/
void UpdPorFunc_S179_DISPLAY_LANGUAGE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S179_DISPLAY_LANGUAGE*/
unsigned char CondiCheck_S179_DISPLAY_LANGUAGE(void);
/*2. Process preOpcode after change to S179_DISPLAY_LANGUAGE */
void HandlePreOCFunc_S179_DISPLAY_LANGUAGE(void);
/*Condition check to progress preOC valueS179_DISPLAY_LANGUAGE*/
unsigned char CondiPreOcCheck_S179_DISPLAY_LANGUAGE(void);
/*1. Clear or Initilal screen for  S178_DISPLAY_FLIPSCREEN operation*/
void IniOrClrScrFunc_S178_DISPLAY_FLIPSCREEN(void);
/*1.2 Update the porition screen when the opcode changed for S178_DISPLAY_FLIPSCREEN operation*/
void UpdPorFunc_S178_DISPLAY_FLIPSCREEN(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S178_DISPLAY_FLIPSCREEN*/
unsigned char CondiCheck_S178_DISPLAY_FLIPSCREEN(void);
/*2. Process preOpcode after change to S178_DISPLAY_FLIPSCREEN */
void HandlePreOCFunc_S178_DISPLAY_FLIPSCREEN(void);
/*Condition check to progress preOC valueS178_DISPLAY_FLIPSCREEN*/
unsigned char CondiPreOcCheck_S178_DISPLAY_FLIPSCREEN(void);
/*1. Clear or Initilal screen for  S166_DISPLAY_MAINDISPLAY operation*/
void IniOrClrScrFunc_S166_DISPLAY_MAINDISPLAY(void);
/*1.2 Update the porition screen when the opcode changed for S166_DISPLAY_MAINDISPLAY operation*/
void UpdPorFunc_S166_DISPLAY_MAINDISPLAY(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S166_DISPLAY_MAINDISPLAY*/
unsigned char CondiCheck_S166_DISPLAY_MAINDISPLAY(void);
/*2. Process preOpcode after change to S166_DISPLAY_MAINDISPLAY */
void HandlePreOCFunc_S166_DISPLAY_MAINDISPLAY(void);
/*Condition check to progress preOC valueS166_DISPLAY_MAINDISPLAY*/
unsigned char CondiPreOcCheck_S166_DISPLAY_MAINDISPLAY(void);
/*1. Clear or Initilal screen for  S372_DISPLAY_GTR operation*/
void IniOrClrScrFunc_S372_DISPLAY_GTR(void);
/*1.2 Update the porition screen when the opcode changed for S372_DISPLAY_GTR operation*/
void UpdPorFunc_S372_DISPLAY_GTR(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S372_DISPLAY_GTR*/
unsigned char CondiCheck_S372_DISPLAY_GTR(void);
/*2. Process preOpcode after change to S372_DISPLAY_GTR */
void HandlePreOCFunc_S372_DISPLAY_GTR(void);
/*Condition check to progress preOC valueS372_DISPLAY_GTR*/
unsigned char CondiPreOcCheck_S372_DISPLAY_GTR(void);
/*1. Clear or Initilal screen for  S428_DISPLAY_EXTRALARGE operation*/
void IniOrClrScrFunc_S428_DISPLAY_EXTRALARGE(void);
/*1.2 Update the porition screen when the opcode changed for S428_DISPLAY_EXTRALARGE operation*/
void UpdPorFunc_S428_DISPLAY_EXTRALARGE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S428_DISPLAY_EXTRALARGE*/
unsigned char CondiCheck_S428_DISPLAY_EXTRALARGE(void);
/*2. Process preOpcode after change to S428_DISPLAY_EXTRALARGE */
void HandlePreOCFunc_S428_DISPLAY_EXTRALARGE(void);
/*Condition check to progress preOC valueS428_DISPLAY_EXTRALARGE*/
unsigned char CondiPreOcCheck_S428_DISPLAY_EXTRALARGE(void);
/*1. Clear or Initilal screen for  DISPLAY_BRIGHTNESS_SET operation*/
void IniOrClrScrFunc_DISPLAY_BRIGHTNESS_SET(void);
/*1.3 Flashing or keep update content of items DISPLAY_BRIGHTNESS_SET */
void UpdOrFlasFunc_DISPLAY_BRIGHTNESS_SET(void);
/*1. Clear or Initilal screen for  DISPLAY_TITLESCOLOR_SET operation*/
void IniOrClrScrFunc_DISPLAY_TITLESCOLOR_SET(void);
/*1.3 Flashing or keep update content of items DISPLAY_TITLESCOLOR_SET */
void UpdOrFlasFunc_DISPLAY_TITLESCOLOR_SET(void);
/*1. Clear or Initilal screen for  DISPLAY_LANGUAGE_SET operation*/
void IniOrClrScrFunc_DISPLAY_LANGUAGE_SET(void);
/*1.3 Flashing or keep update content of items DISPLAY_LANGUAGE_SET */
void UpdOrFlasFunc_DISPLAY_LANGUAGE_SET(void);
/*1. Clear or Initilal screen for  DISPLAY_FLIPSCREEN_SET operation*/
void IniOrClrScrFunc_DISPLAY_FLIPSCREEN_SET(void);
/*1.3 Flashing or keep update content of items DISPLAY_FLIPSCREEN_SET */
void UpdOrFlasFunc_DISPLAY_FLIPSCREEN_SET(void);
/*1. Clear or Initilal screen for  S373_DISPLAY_GTR_SET operation*/
void IniOrClrScrFunc_S373_DISPLAY_GTR_SET(void);
/*1.3 Flashing or keep update content of items S373_DISPLAY_GTR_SET */
void UpdOrFlasFunc_S373_DISPLAY_GTR_SET(void);
/*1. Clear or Initilal screen for  DISPLAY_AUTODIM__STAT operation*/
void IniOrClrScrFunc_DISPLAY_AUTODIM__STAT(void);
/*1.3 Flashing or keep update content of items DISPLAY_AUTODIM__STAT */
void UpdOrFlasFunc_DISPLAY_AUTODIM__STAT(void);
/*1. Clear or Initilal screen for  DISPLAY_AUTODIM__TIME operation*/
void IniOrClrScrFunc_DISPLAY_AUTODIM__TIME(void);
/*1.3 Flashing or keep update content of items DISPLAY_AUTODIM__TIME */
void UpdOrFlasFunc_DISPLAY_AUTODIM__TIME(void);
/*1. Clear or Initilal screen for  DISPLAY_AUTODIM__PERCENT operation*/
void IniOrClrScrFunc_DISPLAY_AUTODIM__PERCENT(void);
/*1.3 Flashing or keep update content of items DISPLAY_AUTODIM__PERCENT */
void UpdOrFlasFunc_DISPLAY_AUTODIM__PERCENT(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_LEFT operation*/
void IniOrClrScrFunc_MAINDISPLAY_LEFT(void);
/*1.2 Update the porition screen when the opcode changed for MAINDISPLAY_LEFT operation*/
void UpdPorFunc_MAINDISPLAY_LEFT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_LEFT*/
unsigned char CondiCheck_MAINDISPLAY_LEFT(void);
/*2. Process preOpcode after change to MAINDISPLAY_LEFT */
void HandlePreOCFunc_MAINDISPLAY_LEFT(void);
/*Condition check to progress preOC valueMAINDISPLAY_LEFT*/
unsigned char CondiPreOcCheck_MAINDISPLAY_LEFT(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_LEFT_SET operation*/
void IniOrClrScrFunc_MAINDISPLAY_LEFT_SET(void);
/*1.3 Flashing or keep update content of items MAINDISPLAY_LEFT_SET */
void UpdOrFlasFunc_MAINDISPLAY_LEFT_SET(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_RIGHT operation*/
void IniOrClrScrFunc_MAINDISPLAY_RIGHT(void);
/*1.2 Update the porition screen when the opcode changed for MAINDISPLAY_RIGHT operation*/
void UpdPorFunc_MAINDISPLAY_RIGHT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_RIGHT*/
unsigned char CondiCheck_MAINDISPLAY_RIGHT(void);
/*2. Process preOpcode after change to MAINDISPLAY_RIGHT */
void HandlePreOCFunc_MAINDISPLAY_RIGHT(void);
/*Condition check to progress preOC valueMAINDISPLAY_RIGHT*/
unsigned char CondiPreOcCheck_MAINDISPLAY_RIGHT(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_RIGHT_SET operation*/
void IniOrClrScrFunc_MAINDISPLAY_RIGHT_SET(void);
/*1.3 Flashing or keep update content of items MAINDISPLAY_RIGHT_SET */
void UpdOrFlasFunc_MAINDISPLAY_RIGHT_SET(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_GFBG operation*/
void IniOrClrScrFunc_MAINDISPLAY_GFBG(void);
/*1.2 Update the porition screen when the opcode changed for MAINDISPLAY_GFBG operation*/
void UpdPorFunc_MAINDISPLAY_GFBG(void);
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_GFBG*/
unsigned char CondiCheck_MAINDISPLAY_GFBG(void);
/*2. Process preOpcode after change to MAINDISPLAY_GFBG */
void HandlePreOCFunc_MAINDISPLAY_GFBG(void);
/*Condition check to progress preOC valueMAINDISPLAY_GFBG*/
unsigned char CondiPreOcCheck_MAINDISPLAY_GFBG(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_GFBG_SET operation*/
void IniOrClrScrFunc_MAINDISPLAY_GFBG_SET(void);
/*1.3 Flashing or keep update content of items MAINDISPLAY_GFBG_SET */
void UpdOrFlasFunc_MAINDISPLAY_GFBG_SET(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_EXTRALARGE operation*/
void IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE(void);
/*1.2 Update the porition screen when the opcode changed for MAINDISPLAY_EXTRALARGE operation*/
void UpdPorFunc_MAINDISPLAY_EXTRALARGE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of MAINDISPLAY_EXTRALARGE*/
unsigned char CondiCheck_MAINDISPLAY_EXTRALARGE(void);
/*2. Process preOpcode after change to MAINDISPLAY_EXTRALARGE */
void HandlePreOCFunc_MAINDISPLAY_EXTRALARGE(void);
/*Condition check to progress preOC valueMAINDISPLAY_EXTRALARGE*/
unsigned char CondiPreOcCheck_MAINDISPLAY_EXTRALARGE(void);
/*1. Clear or Initilal screen for  MAINDISPLAY_EXTRALARGE_SET operation*/
void IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE_SET(void);
/*1.3 Flashing or keep update content of items MAINDISPLAY_EXTRALARGE_SET */
void UpdOrFlasFunc_MAINDISPLAY_EXTRALARGE_SET(void);
/*1. Clear or Initilal screen for  S128_TM_TMT1 operation*/
void IniOrClrScrFunc_S128_TM_TMT1(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT1 operation*/
void UpdPorFunc_S128_TM_TMT1(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT1*/
unsigned char CondiCheck_S128_TM_TMT1(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT1 */
void UpdOrFlasFunc_S128_TM_TMT1(void);
/*2. Process preOpcode after change to S128_TM_TMT1 */
void HandlePreOCFunc_S128_TM_TMT1(void);
/*Condition check to progress preOC valueS128_TM_TMT1*/
unsigned char CondiPreOcCheck_S128_TM_TMT1(void);
/*1. Clear or Initilal screen for  S128_TM_TMT2 operation*/
void IniOrClrScrFunc_S128_TM_TMT2(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT2 operation*/
void UpdPorFunc_S128_TM_TMT2(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT2*/
unsigned char CondiCheck_S128_TM_TMT2(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT2 */
void UpdOrFlasFunc_S128_TM_TMT2(void);
/*2. Process preOpcode after change to S128_TM_TMT2 */
void HandlePreOCFunc_S128_TM_TMT2(void);
/*Condition check to progress preOC valueS128_TM_TMT2*/
unsigned char CondiPreOcCheck_S128_TM_TMT2(void);
/*1. Clear or Initilal screen for  S128_TM_TMT3 operation*/
void IniOrClrScrFunc_S128_TM_TMT3(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT3 operation*/
void UpdPorFunc_S128_TM_TMT3(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT3*/
unsigned char CondiCheck_S128_TM_TMT3(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT3 */
void UpdOrFlasFunc_S128_TM_TMT3(void);
/*2. Process preOpcode after change to S128_TM_TMT3 */
void HandlePreOCFunc_S128_TM_TMT3(void);
/*Condition check to progress preOC valueS128_TM_TMT3*/
unsigned char CondiPreOcCheck_S128_TM_TMT3(void);
/*1. Clear or Initilal screen for  S128_TM_TMT4 operation*/
void IniOrClrScrFunc_S128_TM_TMT4(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT4 operation*/
void UpdPorFunc_S128_TM_TMT4(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT4*/
unsigned char CondiCheck_S128_TM_TMT4(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT4 */
void UpdOrFlasFunc_S128_TM_TMT4(void);
/*2. Process preOpcode after change to S128_TM_TMT4 */
void HandlePreOCFunc_S128_TM_TMT4(void);
/*Condition check to progress preOC valueS128_TM_TMT4*/
unsigned char CondiPreOcCheck_S128_TM_TMT4(void);
/*1. Clear or Initilal screen for  S128_TM_TMT5 operation*/
void IniOrClrScrFunc_S128_TM_TMT5(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT5 operation*/
void UpdPorFunc_S128_TM_TMT5(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT5*/
unsigned char CondiCheck_S128_TM_TMT5(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT5 */
void UpdOrFlasFunc_S128_TM_TMT5(void);
/*2. Process preOpcode after change to S128_TM_TMT5 */
void HandlePreOCFunc_S128_TM_TMT5(void);
/*Condition check to progress preOC valueS128_TM_TMT5*/
unsigned char CondiPreOcCheck_S128_TM_TMT5(void);
/*1. Clear or Initilal screen for  S128_TM_TMT6 operation*/
void IniOrClrScrFunc_S128_TM_TMT6(void);
/*1.2 Update the porition screen when the opcode changed for S128_TM_TMT6 operation*/
void UpdPorFunc_S128_TM_TMT6(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S128_TM_TMT6*/
unsigned char CondiCheck_S128_TM_TMT6(void);
/*1.3 Flashing or keep update content of items S128_TM_TMT6 */
void UpdOrFlasFunc_S128_TM_TMT6(void);
/*2. Process preOpcode after change to S128_TM_TMT6 */
void HandlePreOCFunc_S128_TM_TMT6(void);
/*Condition check to progress preOC valueS128_TM_TMT6*/
unsigned char CondiPreOcCheck_S128_TM_TMT6(void);
/*1. Clear or Initilal screen for  TMT_1_SET operation*/
void IniOrClrScrFunc_TMT_1_SET(void);
/*1.3 Flashing or keep update content of items TMT_1_SET */
void UpdOrFlasFunc_TMT_1_SET(void);
/*1. Clear or Initilal screen for  TMT_2_SET operation*/
void IniOrClrScrFunc_TMT_2_SET(void);
/*1.3 Flashing or keep update content of items TMT_2_SET */
void UpdOrFlasFunc_TMT_2_SET(void);
/*1. Clear or Initilal screen for  TMT_3_SET operation*/
void IniOrClrScrFunc_TMT_3_SET(void);
/*1.3 Flashing or keep update content of items TMT_3_SET */
void UpdOrFlasFunc_TMT_3_SET(void);
/*1. Clear or Initilal screen for  TMT_4_SET operation*/
void IniOrClrScrFunc_TMT_4_SET(void);
/*1.3 Flashing or keep update content of items TMT_4_SET */
void UpdOrFlasFunc_TMT_4_SET(void);
/*1. Clear or Initilal screen for  TMT_5_SET operation*/
void IniOrClrScrFunc_TMT_5_SET(void);
/*1.3 Flashing or keep update content of items TMT_5_SET */
void UpdOrFlasFunc_TMT_5_SET(void);
/*1. Clear or Initilal screen for  TMT_6_SET operation*/
void IniOrClrScrFunc_TMT_6_SET(void);
/*1.3 Flashing or keep update content of items TMT_6_SET */
void UpdOrFlasFunc_TMT_6_SET(void);
/*1. Clear or Initilal screen for  SET_TMT_1_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_1_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_1_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_1_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_1_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_1_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_1_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_1_DIGIT_6(void);
/*1. Clear or Initilal screen for  SET_TMT_2_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_2_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_2_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_2_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_2_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_2_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_2_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_2_DIGIT_6(void);
/*1. Clear or Initilal screen for  SET_TMT_3_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_3_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_3_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_3_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_3_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_3_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_3_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_3_DIGIT_6(void);
/*1. Clear or Initilal screen for  SET_TMT_4_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_4_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_4_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_4_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_4_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_4_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_4_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_4_DIGIT_6(void);
/*1. Clear or Initilal screen for  SET_TMT_5_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_5_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_5_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_5_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_5_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_5_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_5_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_5_DIGIT_6(void);
/*1. Clear or Initilal screen for  SET_TMT_6_DIGIT_1 operation*/
void IniOrClrScrFunc_SET_TMT_6_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_1 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_1(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_1 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_1(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_1*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_1(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_2 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_2(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_2 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_2(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_2*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_2(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_3 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_3(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_3 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_3(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_3*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_3(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_4 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_4(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_4 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_4(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_4*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_4(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_5 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_5(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_5 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_5(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_5*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_5(void);
/*1.3 Flashing or keep update content of items SET_TMT_6_DIGIT_6 */
void UpdOrFlasFunc_SET_TMT_6_DIGIT_6(void);
/*2. Process preOpcode after change to SET_TMT_6_DIGIT_6 */
void HandlePreOCFunc_SET_TMT_6_DIGIT_6(void);
/*Condition check to progress preOC valueSET_TMT_6_DIGIT_6*/
unsigned char CondiPreOcCheck_SET_TMT_6_DIGIT_6(void);
/*1. Clear or Initilal screen for  S187_IM_MYINFO operation*/
void IniOrClrScrFunc_S187_IM_MYINFO(void);
/*1.2 Update the porition screen when the opcode changed for S187_IM_MYINFO operation*/
void UpdPorFunc_S187_IM_MYINFO(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S187_IM_MYINFO*/
unsigned char CondiCheck_S187_IM_MYINFO(void);
/*2. Process preOpcode after change to S187_IM_MYINFO */
void HandlePreOCFunc_S187_IM_MYINFO(void);
/*Condition check to progress preOC valueS187_IM_MYINFO*/
unsigned char CondiPreOcCheck_S187_IM_MYINFO(void);
/*1. Clear or Initilal screen for  S190_IM_DSXINFO operation*/
void IniOrClrScrFunc_S190_IM_DSXINFO(void);
/*1.2 Update the porition screen when the opcode changed for S190_IM_DSXINFO operation*/
void UpdPorFunc_S190_IM_DSXINFO(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S190_IM_DSXINFO*/
unsigned char CondiCheck_S190_IM_DSXINFO(void);
/*2. Process preOpcode after change to S190_IM_DSXINFO */
void HandlePreOCFunc_S190_IM_DSXINFO(void);
/*Condition check to progress preOC valueS190_IM_DSXINFO*/
unsigned char CondiPreOcCheck_S190_IM_DSXINFO(void);
/*1. Clear or Initilal screen for  S192_IM_HISTORY operation*/
void IniOrClrScrFunc_S192_IM_HISTORY(void);
/*1.2 Update the porition screen when the opcode changed for S192_IM_HISTORY operation*/
void UpdPorFunc_S192_IM_HISTORY(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S192_IM_HISTORY*/
unsigned char CondiCheck_S192_IM_HISTORY(void);
/*2. Process preOpcode after change to S192_IM_HISTORY */
void HandlePreOCFunc_S192_IM_HISTORY(void);
/*Condition check to progress preOC valueS192_IM_HISTORY*/
unsigned char CondiPreOcCheck_S192_IM_HISTORY(void);
/*1. Clear or Initilal screen for  S224_IM_MANUFACTURER operation*/
void IniOrClrScrFunc_S224_IM_MANUFACTURER(void);
/*1.2 Update the porition screen when the opcode changed for S224_IM_MANUFACTURER operation*/
void UpdPorFunc_S224_IM_MANUFACTURER(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S224_IM_MANUFACTURER*/
unsigned char CondiCheck_S224_IM_MANUFACTURER(void);
/*2. Process preOpcode after change to S224_IM_MANUFACTURER */
void HandlePreOCFunc_S224_IM_MANUFACTURER(void);
/*Condition check to progress preOC valueS224_IM_MANUFACTURER*/
unsigned char CondiPreOcCheck_S224_IM_MANUFACTURER(void);
/*1. Clear or Initilal screen for  S218_IM_MYINFO_SET operation*/
void IniOrClrScrFunc_S218_IM_MYINFO_SET(void);
/*1. Clear or Initilal screen for  S190_IM_DSXINFO_SET operation*/
void IniOrClrScrFunc_S190_IM_DSXINFO_SET(void);
/*1. Clear or Initilal screen for  S192_IM_HISTORY_SET operation*/
void IniOrClrScrFunc_S192_IM_HISTORY_SET(void);
/*1. Clear or Initilal screen for  S2_SURFACE_MAIN operation*/
void IniOrClrScrFunc_S2_SURFACE_MAIN(void);
/*1.3 Flashing or keep update content of items S2_SURFACE_MAIN */
void UpdOrFlasFunc_S2_SURFACE_MAIN(void);
/*1. Clear or Initilal screen for  S11_SURFACE_ALT1 operation*/
void IniOrClrScrFunc_S11_SURFACE_ALT1(void);
/*1.3 Flashing or keep update content of items S11_SURFACE_ALT1 */
void UpdOrFlasFunc_S11_SURFACE_ALT1(void);
/*1. Clear or Initilal screen for  S12_SURFACE_ALT2 operation*/
void IniOrClrScrFunc_S12_SURFACE_ALT2(void);
/*1.3 Flashing or keep update content of items S12_SURFACE_ALT2 */
void UpdOrFlasFunc_S12_SURFACE_ALT2(void);
/*1. Clear or Initilal screen for  S13_SURFACE_ALT3 operation*/
void IniOrClrScrFunc_S13_SURFACE_ALT3(void);
/*1.3 Flashing or keep update content of items S13_SURFACE_ALT3 */
void UpdOrFlasFunc_S13_SURFACE_ALT3(void);
/*1. Clear or Initilal screen for  S14_SURFACE_ALT4 operation*/
void IniOrClrScrFunc_S14_SURFACE_ALT4(void);
/*1.3 Flashing or keep update content of items S14_SURFACE_ALT4 */
void UpdOrFlasFunc_S14_SURFACE_ALT4(void);
/*1. Clear or Initilal screen for  S15_SURFACE_ALT5 operation*/
void IniOrClrScrFunc_S15_SURFACE_ALT5(void);
/*1.3 Flashing or keep update content of items S15_SURFACE_ALT5 */
void UpdOrFlasFunc_S15_SURFACE_ALT5(void);
/*1. Clear or Initilal screen for  SURFACE_SM_MAIN operation*/
void IniOrClrScrFunc_SURFACE_SM_MAIN(void);
/*1.3 Flashing or keep update content of items SURFACE_SM_MAIN */
void UpdOrFlasFunc_SURFACE_SM_MAIN(void);
/*1. Clear or Initilal screen for  SURFACE_SM_ALT1 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT1(void);
/*1.3 Flashing or keep update content of items SURFACE_SM_ALT1 */
void UpdOrFlasFunc_SURFACE_SM_ALT1(void);
/*1. Clear or Initilal screen for  SURFACE_SM_ALT2 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT2(void);
/*1.3 Flashing or keep update content of items SURFACE_SM_ALT2 */
void UpdOrFlasFunc_SURFACE_SM_ALT2(void);
/*1. Clear or Initilal screen for  SURFACE_SM_ALT3 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT3(void);
/*1.3 Flashing or keep update content of items SURFACE_SM_ALT3 */
void UpdOrFlasFunc_SURFACE_SM_ALT3(void);
/*1. Clear or Initilal screen for  SURFACE_SM_ALT4 operation*/
void IniOrClrScrFunc_SURFACE_SM_ALT4(void);
/*1.3 Flashing or keep update content of items SURFACE_SM_ALT4 */
void UpdOrFlasFunc_SURFACE_SM_ALT4(void);
/*1. Clear or Initilal screen for  SURFACE_GAUGE_MAIN operation*/
void IniOrClrScrFunc_SURFACE_GAUGE_MAIN(void);
/*1.3 Flashing or keep update content of items SURFACE_GAUGE_MAIN */
void UpdOrFlasFunc_SURFACE_GAUGE_MAIN(void);
/*1. Clear or Initilal screen for  SURFACE_GAUGE_ALT1 operation*/
void IniOrClrScrFunc_SURFACE_GAUGE_ALT1(void);
/*1.3 Flashing or keep update content of items SURFACE_GAUGE_ALT1 */
void UpdOrFlasFunc_SURFACE_GAUGE_ALT1(void);
/*1. Clear or Initilal screen for  SURFACE_GAUGE_ALT2 operation*/
void IniOrClrScrFunc_SURFACE_GAUGE_ALT2(void);
/*1.3 Flashing or keep update content of items SURFACE_GAUGE_ALT2 */
void UpdOrFlasFunc_SURFACE_GAUGE_ALT2(void);
/*1. Clear or Initilal screen for  SURFACE_GSM_MAIN operation*/
void IniOrClrScrFunc_SURFACE_GSM_MAIN(void);
/*1.3 Flashing or keep update content of items SURFACE_GSM_MAIN */
void UpdOrFlasFunc_SURFACE_GSM_MAIN(void);
/*1. Clear or Initilal screen for  SP_SWITCH_TO_HIGH operation*/
void IniOrClrScrFunc_SP_SWITCH_TO_HIGH(void);
/*1.2 Update the porition screen when the opcode changed for SP_SWITCH_TO_HIGH operation*/
void UpdPorFunc_SP_SWITCH_TO_HIGH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_HIGH*/
unsigned char CondiCheck_SP_SWITCH_TO_HIGH(void);
/*2. Process preOpcode after change to SP_SWITCH_TO_HIGH */
void HandlePreOCFunc_SP_SWITCH_TO_HIGH(void);
/*Condition check to progress preOC valueSP_SWITCH_TO_HIGH*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_HIGH(void);
/*1. Clear or Initilal screen for  SP_SWITCH_TO_LOW operation*/
void IniOrClrScrFunc_SP_SWITCH_TO_LOW(void);
/*1.2 Update the porition screen when the opcode changed for SP_SWITCH_TO_LOW operation*/
void UpdPorFunc_SP_SWITCH_TO_LOW(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_LOW*/
unsigned char CondiCheck_SP_SWITCH_TO_LOW(void);
/*2. Process preOpcode after change to SP_SWITCH_TO_LOW */
void HandlePreOCFunc_SP_SWITCH_TO_LOW(void);
/*Condition check to progress preOC valueSP_SWITCH_TO_LOW*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_LOW(void);
/*1. Clear or Initilal screen for  SP_SWITCH_TO_CUSTOM operation*/
void IniOrClrScrFunc_SP_SWITCH_TO_CUSTOM(void);
/*1.2 Update the porition screen when the opcode changed for SP_SWITCH_TO_CUSTOM operation*/
void UpdPorFunc_SP_SWITCH_TO_CUSTOM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of SP_SWITCH_TO_CUSTOM*/
unsigned char CondiCheck_SP_SWITCH_TO_CUSTOM(void);
/*2. Process preOpcode after change to SP_SWITCH_TO_CUSTOM */
void HandlePreOCFunc_SP_SWITCH_TO_CUSTOM(void);
/*Condition check to progress preOC valueSP_SWITCH_TO_CUSTOM*/
unsigned char CondiPreOcCheck_SP_SWITCH_TO_CUSTOM(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_1 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_1(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_1 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_1(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_1*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_1(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_1 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_1(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_1 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_1(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_1*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_1(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_2 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_2(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_2 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_2(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_2*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_2(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_2 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_2(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_2 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_2(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_2*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_2(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_3 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_3(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_3 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_3(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_3*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_3(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_3 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_3(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_3 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_3(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_3*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_3(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_4 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_4(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_4 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_4(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_4*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_4(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_4 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_4(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_4 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_4(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_4*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_4(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_5 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_5(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_5 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_5(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_5*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_5(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_5 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_5(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_5 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_5(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_5*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_5(void);
/*1. Clear or Initilal screen for  GAS_SWITCH_TO_GAS_6 operation*/
void IniOrClrScrFunc_GAS_SWITCH_TO_GAS_6(void);
/*1.2 Update the porition screen when the opcode changed for GAS_SWITCH_TO_GAS_6 operation*/
void UpdPorFunc_GAS_SWITCH_TO_GAS_6(void);
/*Condition check return the result when need to clear all the the screen or one portion only of GAS_SWITCH_TO_GAS_6*/
unsigned char CondiCheck_GAS_SWITCH_TO_GAS_6(void);
/*1.3 Flashing or keep update content of items GAS_SWITCH_TO_GAS_6 */
void UpdOrFlasFunc_GAS_SWITCH_TO_GAS_6(void);
/*2. Process preOpcode after change to GAS_SWITCH_TO_GAS_6 */
void HandlePreOCFunc_GAS_SWITCH_TO_GAS_6(void);
/*Condition check to progress preOC valueGAS_SWITCH_TO_GAS_6*/
unsigned char CondiPreOcCheck_GAS_SWITCH_TO_GAS_6(void);
/*1. Clear or Initilal screen for  S77_ACTUAL_GAS_WARNING  operation*/
void IniOrClrScrFunc_S77_ACTUAL_GAS_WARNING (void);
/*1. Clear or Initilal screen for  D41_ACTUAL_GAS_WARNING operation*/
void IniOrClrScrFunc_D41_ACTUAL_GAS_WARNING(void);
/*1. Clear or Initilal screen for  DIVE_PL_TIME_LIMITS operation*/
void IniOrClrScrFunc_DIVE_PL_TIME_LIMITS(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_TIME_LIMITS operation*/
void UpdPorFunc_DIVE_PL_TIME_LIMITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_TIME_LIMITS*/
unsigned char CondiCheck_DIVE_PL_TIME_LIMITS(void);
/*2. Process preOpcode after change to DIVE_PL_TIME_LIMITS */
void HandlePreOCFunc_DIVE_PL_TIME_LIMITS(void);
/*Condition check to progress preOC valueDIVE_PL_TIME_LIMITS*/
unsigned char CondiPreOcCheck_DIVE_PL_TIME_LIMITS(void);
/*1. Clear or Initilal screen for  DIVE_PL_DEPTH_LIMITS operation*/
void IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DEPTH_LIMITS operation*/
void UpdPorFunc_DIVE_PL_DEPTH_LIMITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DEPTH_LIMITS*/
unsigned char CondiCheck_DIVE_PL_DEPTH_LIMITS(void);
/*2. Process preOpcode after change to DIVE_PL_DEPTH_LIMITS */
void HandlePreOCFunc_DIVE_PL_DEPTH_LIMITS(void);
/*Condition check to progress preOC valueDIVE_PL_DEPTH_LIMITS*/
unsigned char CondiPreOcCheck_DIVE_PL_DEPTH_LIMITS(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_NEWORCONTINUOS operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_NEWORCONTINUOS operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_NEWORCONTINUOS*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_NEWORCONTINUOS */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_NEWORCONTINUOS*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_DEPTH operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_DEPTH operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_DEPTH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_DEPTH*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_DEPTH(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_DEPTH */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_DEPTH(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_DEPTH*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_DEPTH(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_TIME operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_TIME operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_TIME(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_TIME*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_TIME(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_TIME */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_TIME(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_TIME*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_TIME(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_SAC operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_SAC operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_SAC(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SAC*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SAC(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_SAC */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SAC(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_SAC*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SAC(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_SP operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_SP operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_SP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SP*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SP(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_SP */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SP(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_SP*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SP(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_SIMULATEDIVE operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void);
/*1.2 Update the porition screen when the opcode changed for DIVE_PL_DIVE_SIM_SIMULATEDIVE operation*/
void UpdPorFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVE_PL_DIVE_SIM_SIMULATEDIVE*/
unsigned char CondiCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void);
/*2. Process preOpcode after change to DIVE_PL_DIVE_SIM_SIMULATEDIVE */
void HandlePreOCFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void);
/*Condition check to progress preOC valueDIVE_PL_DIVE_SIM_SIMULATEDIVE*/
unsigned char CondiPreOcCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET */
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_DEPTH_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_DIVE_SIM_DEPTH_SET */
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_DEPTH_SET(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_TIME_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_DIVE_SIM_TIME_SET */
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_TIME_SET(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_SAC_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_DIVE_SIM_SAC_SET */
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SAC_SET(void);
/*1. Clear or Initilal screen for  DIVE_PL_DIVE_SIM_SP_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_DIVE_SIM_SP_SET */
void UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SP_SET(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DIVPLAN_NODECO operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NODECO(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DIVPLAN_NOTENTIM operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DECOTIME_EXCEED operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DECOTIME_EXCEED(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_TOOHIGH_PO2 operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_TOOHIGH_PO2(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DIVPLAN_CALCULATING operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_DIVPLAN_PAGE_01 operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_BAILOUT_PAGE_01 operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS(void);
/*1. Clear or Initilal screen for  DIVE_SIMDIVE_SUMMARY operation*/
void IniOrClrScrFunc_DIVE_SIMDIVE_SUMMARY(void);
/*1. Clear or Initilal screen for  DIVE_PL_TIME_LIMITS_SET operation*/
void IniOrClrScrFunc_DIVE_PL_TIME_LIMITS_SET(void);
/*1.3 Flashing or keep update content of items DIVE_PL_TIME_LIMITS_SET */
void UpdOrFlasFunc_DIVE_PL_TIME_LIMITS_SET(void);
/*1. Clear or Initilal screen for  DIVE_PL_DEPTH_LIMITS_SET operation*/
void IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS_SET(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_MIN operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_MIN(void);
/*1.2 Update the porition screen when the opcode changed for BAILOUT_PO2_OC_MIN operation*/
void UpdPorFunc_BAILOUT_PO2_OC_MIN(void);
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MIN*/
unsigned char CondiCheck_BAILOUT_PO2_OC_MIN(void);
/*2. Process preOpcode after change to BAILOUT_PO2_OC_MIN */
void HandlePreOCFunc_BAILOUT_PO2_OC_MIN(void);
/*Condition check to progress preOC valueBAILOUT_PO2_OC_MIN*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_MIN(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_MIN_SET operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_MIN_SET(void);
/*1.3 Flashing or keep update content of items BAILOUT_PO2_OC_MIN_SET */
void UpdOrFlasFunc_BAILOUT_PO2_OC_MIN_SET(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_MAX operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_MAX(void);
/*1.2 Update the porition screen when the opcode changed for BAILOUT_PO2_OC_MAX operation*/
void UpdPorFunc_BAILOUT_PO2_OC_MAX(void);
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_MAX*/
unsigned char CondiCheck_BAILOUT_PO2_OC_MAX(void);
/*2. Process preOpcode after change to BAILOUT_PO2_OC_MAX */
void HandlePreOCFunc_BAILOUT_PO2_OC_MAX(void);
/*Condition check to progress preOC valueBAILOUT_PO2_OC_MAX*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_MAX(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_MAX_SET operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_MAX_SET(void);
/*1.3 Flashing or keep update content of items BAILOUT_PO2_OC_MAX_SET */
void UpdOrFlasFunc_BAILOUT_PO2_OC_MAX_SET(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_DECO operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_DECO(void);
/*1.2 Update the porition screen when the opcode changed for BAILOUT_PO2_OC_DECO operation*/
void UpdPorFunc_BAILOUT_PO2_OC_DECO(void);
/*Condition check return the result when need to clear all the the screen or one portion only of BAILOUT_PO2_OC_DECO*/
unsigned char CondiCheck_BAILOUT_PO2_OC_DECO(void);
/*2. Process preOpcode after change to BAILOUT_PO2_OC_DECO */
void HandlePreOCFunc_BAILOUT_PO2_OC_DECO(void);
/*Condition check to progress preOC valueBAILOUT_PO2_OC_DECO*/
unsigned char CondiPreOcCheck_BAILOUT_PO2_OC_DECO(void);
/*1. Clear or Initilal screen for  BAILOUT_PO2_OC_DECO_SET operation*/
void IniOrClrScrFunc_BAILOUT_PO2_OC_DECO_SET(void);
/*1.3 Flashing or keep update content of items BAILOUT_PO2_OC_DECO_SET */
void UpdOrFlasFunc_BAILOUT_PO2_OC_DECO_SET(void);
/*1. Clear or Initilal screen for  S105_SET_CONSERV_TEC_SPORT operation*/
void IniOrClrScrFunc_S105_SET_CONSERV_TEC_SPORT(void);
/*1.3 Flashing or keep update content of items S105_SET_CONSERV_TEC_SPORT */
void UpdOrFlasFunc_S105_SET_CONSERV_TEC_SPORT(void);
/*1. Clear or Initilal screen for  S106_SET_CONSERV_SPORT operation*/
void IniOrClrScrFunc_S106_SET_CONSERV_SPORT(void);
/*1.3 Flashing or keep update content of items S106_SET_CONSERV_SPORT */
void UpdOrFlasFunc_S106_SET_CONSERV_SPORT(void);
/*1. Clear or Initilal screen for  CONSERV_TEC_GF_LOW operation*/
void IniOrClrScrFunc_CONSERV_TEC_GF_LOW(void);
/*1.2 Update the porition screen when the opcode changed for CONSERV_TEC_GF_LOW operation*/
void UpdPorFunc_CONSERV_TEC_GF_LOW(void);
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_LOW*/
unsigned char CondiCheck_CONSERV_TEC_GF_LOW(void);
/*2. Process preOpcode after change to CONSERV_TEC_GF_LOW */
void HandlePreOCFunc_CONSERV_TEC_GF_LOW(void);
/*Condition check to progress preOC valueCONSERV_TEC_GF_LOW*/
unsigned char CondiPreOcCheck_CONSERV_TEC_GF_LOW(void);
/*1. Clear or Initilal screen for  CONSERV_TEC_GF_LOW_SET operation*/
void IniOrClrScrFunc_CONSERV_TEC_GF_LOW_SET(void);
/*1.3 Flashing or keep update content of items CONSERV_TEC_GF_LOW_SET */
void UpdOrFlasFunc_CONSERV_TEC_GF_LOW_SET(void);
/*1. Clear or Initilal screen for  CONSERV_TEC_GF_HIGH operation*/
void IniOrClrScrFunc_CONSERV_TEC_GF_HIGH(void);
/*1.2 Update the porition screen when the opcode changed for CONSERV_TEC_GF_HIGH operation*/
void UpdPorFunc_CONSERV_TEC_GF_HIGH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of CONSERV_TEC_GF_HIGH*/
unsigned char CondiCheck_CONSERV_TEC_GF_HIGH(void);
/*2. Process preOpcode after change to CONSERV_TEC_GF_HIGH */
void HandlePreOCFunc_CONSERV_TEC_GF_HIGH(void);
/*Condition check to progress preOC valueCONSERV_TEC_GF_HIGH*/
unsigned char CondiPreOcCheck_CONSERV_TEC_GF_HIGH(void);
/*1. Clear or Initilal screen for  CONSERV_TEC_GF_HIGH_SET operation*/
void IniOrClrScrFunc_CONSERV_TEC_GF_HIGH_SET(void);
/*1.3 Flashing or keep update content of items CONSERV_TEC_GF_HIGH_SET */
void UpdOrFlasFunc_CONSERV_TEC_GF_HIGH_SET(void);
/*1. Clear or Initilal screen for  ALARM_AUDIBLE operation*/
void IniOrClrScrFunc_ALARM_AUDIBLE(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_AUDIBLE operation*/
void UpdPorFunc_ALARM_AUDIBLE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_AUDIBLE*/
unsigned char CondiCheck_ALARM_AUDIBLE(void);
/*2. Process preOpcode after change to ALARM_AUDIBLE */
void HandlePreOCFunc_ALARM_AUDIBLE(void);
/*Condition check to progress preOC valueALARM_AUDIBLE*/
unsigned char CondiPreOcCheck_ALARM_AUDIBLE(void);
/*1. Clear or Initilal screen for  ALARM_AUDIBLE_SET operation*/
void IniOrClrScrFunc_ALARM_AUDIBLE_SET(void);
/*1.3 Flashing or keep update content of items ALARM_AUDIBLE_SET */
void UpdOrFlasFunc_ALARM_AUDIBLE_SET(void);
/*1. Clear or Initilal screen for  ALARM_VIBRATION operation*/
void IniOrClrScrFunc_ALARM_VIBRATION(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_VIBRATION operation*/
void UpdPorFunc_ALARM_VIBRATION(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_VIBRATION*/
unsigned char CondiCheck_ALARM_VIBRATION(void);
/*2. Process preOpcode after change to ALARM_VIBRATION */
void HandlePreOCFunc_ALARM_VIBRATION(void);
/*Condition check to progress preOC valueALARM_VIBRATION*/
unsigned char CondiPreOcCheck_ALARM_VIBRATION(void);
/*1. Clear or Initilal screen for  ALARM_VIBRATION_SET operation*/
void IniOrClrScrFunc_ALARM_VIBRATION_SET(void);
/*1.3 Flashing or keep update content of items ALARM_VIBRATION_SET */
void UpdOrFlasFunc_ALARM_VIBRATION_SET(void);
/*1. Clear or Initilal screen for  ALARM_DEPTH_STAT operation*/
void IniOrClrScrFunc_ALARM_DEPTH_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_DEPTH_STAT */
void UpdOrFlasFunc_ALARM_DEPTH_STAT(void);
/*2. Process preOpcode after change to ALARM_DEPTH_STAT */
void HandlePreOCFunc_ALARM_DEPTH_STAT(void);
/*Condition check to progress preOC valueALARM_DEPTH_STAT*/
unsigned char CondiPreOcCheck_ALARM_DEPTH_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_DEPTH_SET operation*/
void UpdPorFunc_ALARM_DEPTH_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DEPTH_SET*/
unsigned char CondiCheck_ALARM_DEPTH_SET(void);
/*1.3 Flashing or keep update content of items ALARM_DEPTH_SET */
void UpdOrFlasFunc_ALARM_DEPTH_SET(void);
/*1. Clear or Initilal screen for  ALARM_DIVETIME operation*/
void IniOrClrScrFunc_ALARM_DIVETIME(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_DIVETIME operation*/
void UpdPorFunc_ALARM_DIVETIME(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME*/
unsigned char CondiCheck_ALARM_DIVETIME(void);
/*2. Process preOpcode after change to ALARM_DIVETIME */
void HandlePreOCFunc_ALARM_DIVETIME(void);
/*Condition check to progress preOC valueALARM_DIVETIME*/
unsigned char CondiPreOcCheck_ALARM_DIVETIME(void);
/*1. Clear or Initilal screen for  ALARM_DIVETIME_STAT operation*/
void IniOrClrScrFunc_ALARM_DIVETIME_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_DIVETIME_STAT */
void UpdOrFlasFunc_ALARM_DIVETIME_STAT(void);
/*2. Process preOpcode after change to ALARM_DIVETIME_STAT */
void HandlePreOCFunc_ALARM_DIVETIME_STAT(void);
/*Condition check to progress preOC valueALARM_DIVETIME_STAT*/
unsigned char CondiPreOcCheck_ALARM_DIVETIME_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_DIVETIME_SET operation*/
void UpdPorFunc_ALARM_DIVETIME_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DIVETIME_SET*/
unsigned char CondiCheck_ALARM_DIVETIME_SET(void);
/*1.3 Flashing or keep update content of items ALARM_DIVETIME_SET */
void UpdOrFlasFunc_ALARM_DIVETIME_SET(void);
/*1. Clear or Initilal screen for  ALARM_TTS operation*/
void IniOrClrScrFunc_ALARM_TTS(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_TTS operation*/
void UpdPorFunc_ALARM_TTS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS*/
unsigned char CondiCheck_ALARM_TTS(void);
/*2. Process preOpcode after change to ALARM_TTS */
void HandlePreOCFunc_ALARM_TTS(void);
/*Condition check to progress preOC valueALARM_TTS*/
unsigned char CondiPreOcCheck_ALARM_TTS(void);
/*1. Clear or Initilal screen for  ALARM_TTS_STAT operation*/
void IniOrClrScrFunc_ALARM_TTS_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_TTS_STAT */
void UpdOrFlasFunc_ALARM_TTS_STAT(void);
/*2. Process preOpcode after change to ALARM_TTS_STAT */
void HandlePreOCFunc_ALARM_TTS_STAT(void);
/*Condition check to progress preOC valueALARM_TTS_STAT*/
unsigned char CondiPreOcCheck_ALARM_TTS_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_TTS_SET operation*/
void UpdPorFunc_ALARM_TTS_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TTS_SET*/
unsigned char CondiCheck_ALARM_TTS_SET(void);
/*1.3 Flashing or keep update content of items ALARM_TTS_SET */
void UpdOrFlasFunc_ALARM_TTS_SET(void);
/*1. Clear or Initilal screen for  ALARM_DTR_STAT operation*/
void IniOrClrScrFunc_ALARM_DTR_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_DTR_STAT */
void UpdOrFlasFunc_ALARM_DTR_STAT(void);
/*2. Process preOpcode after change to ALARM_DTR_STAT */
void HandlePreOCFunc_ALARM_DTR_STAT(void);
/*Condition check to progress preOC valueALARM_DTR_STAT*/
unsigned char CondiPreOcCheck_ALARM_DTR_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_DTR_SET operation*/
void UpdPorFunc_ALARM_DTR_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_DTR_SET*/
unsigned char CondiCheck_ALARM_DTR_SET(void);
/*1.3 Flashing or keep update content of items ALARM_DTR_SET */
void UpdOrFlasFunc_ALARM_DTR_SET(void);
/*1. Clear or Initilal screen for  ALARM_TANK_PRESS_STAT operation*/
void IniOrClrScrFunc_ALARM_TANK_PRESS_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_TANK_PRESS_STAT */
void UpdOrFlasFunc_ALARM_TANK_PRESS_STAT(void);
/*2. Process preOpcode after change to ALARM_TANK_PRESS_STAT */
void HandlePreOCFunc_ALARM_TANK_PRESS_STAT(void);
/*Condition check to progress preOC valueALARM_TANK_PRESS_STAT*/
unsigned char CondiPreOcCheck_ALARM_TANK_PRESS_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_TANK_PRESS_SET operation*/
void UpdPorFunc_ALARM_TANK_PRESS_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_TANK_PRESS_SET*/
unsigned char CondiCheck_ALARM_TANK_PRESS_SET(void);
/*1.3 Flashing or keep update content of items ALARM_TANK_PRESS_SET */
void UpdOrFlasFunc_ALARM_TANK_PRESS_SET(void);
/*1. Clear or Initilal screen for  ALARM_CC6_PRESS_STAT operation*/
void IniOrClrScrFunc_ALARM_CC6_PRESS_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_CC6_PRESS_STAT */
void UpdOrFlasFunc_ALARM_CC6_PRESS_STAT(void);
/*2. Process preOpcode after change to ALARM_CC6_PRESS_STAT */
void HandlePreOCFunc_ALARM_CC6_PRESS_STAT(void);
/*Condition check to progress preOC valueALARM_CC6_PRESS_STAT*/
unsigned char CondiPreOcCheck_ALARM_CC6_PRESS_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_CC6_PRESS_SET operation*/
void UpdPorFunc_ALARM_CC6_PRESS_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_CC6_PRESS_SET*/
unsigned char CondiCheck_ALARM_CC6_PRESS_SET(void);
/*1.3 Flashing or keep update content of items ALARM_CC6_PRESS_SET */
void UpdOrFlasFunc_ALARM_CC6_PRESS_SET(void);
/*1. Clear or Initilal screen for  ALARM_GFN2_GF_STAT operation*/
void IniOrClrScrFunc_ALARM_GFN2_GF_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_GFN2_GF_STAT operation*/
void UpdPorFunc_ALARM_GFN2_GF_STAT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_GFN2_GF_STAT*/
unsigned char CondiCheck_ALARM_GFN2_GF_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_GFN2_GF_STAT */
void UpdOrFlasFunc_ALARM_GFN2_GF_STAT(void);
/*1. Clear or Initilal screen for  ALARM_GFN2_GF_SET operation*/
void IniOrClrScrFunc_ALARM_GFN2_GF_SET(void);
/*1.3 Flashing or keep update content of items ALARM_GFN2_GF_SET */
void UpdOrFlasFunc_ALARM_GFN2_GF_SET(void);
/*1. Clear or Initilal screen for  ALARM_GFN2_N2_STAT operation*/
void IniOrClrScrFunc_ALARM_GFN2_N2_STAT(void);
/*1.2 Update the porition screen when the opcode changed for ALARM_GFN2_N2_STAT operation*/
void UpdPorFunc_ALARM_GFN2_N2_STAT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of ALARM_GFN2_N2_STAT*/
unsigned char CondiCheck_ALARM_GFN2_N2_STAT(void);
/*1.3 Flashing or keep update content of items ALARM_GFN2_N2_STAT */
void UpdOrFlasFunc_ALARM_GFN2_N2_STAT(void);
/*1. Clear or Initilal screen for  ALARM_GFN2_N2_SET operation*/
void IniOrClrScrFunc_ALARM_GFN2_N2_SET(void);
/*1.3 Flashing or keep update content of items ALARM_GFN2_N2_SET */
void UpdOrFlasFunc_ALARM_GFN2_N2_SET(void);
/*1. Clear or Initilal screen for  S282_ALARM_TURNPRESS operation*/
void IniOrClrScrFunc_S282_ALARM_TURNPRESS(void);
/*1.2 Update the porition screen when the opcode changed for S282_ALARM_TURNPRESS operation*/
void UpdPorFunc_S282_ALARM_TURNPRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S282_ALARM_TURNPRESS*/
unsigned char CondiCheck_S282_ALARM_TURNPRESS(void);
/*2. Process preOpcode after change to S282_ALARM_TURNPRESS */
void HandlePreOCFunc_S282_ALARM_TURNPRESS(void);
/*Condition check to progress preOC valueS282_ALARM_TURNPRESS*/
unsigned char CondiPreOcCheck_S282_ALARM_TURNPRESS(void);
/*1. Clear or Initilal screen for  S283_ALARM_TURNPRESS_STAT operation*/
void IniOrClrScrFunc_S283_ALARM_TURNPRESS_STAT(void);
/*1.3 Flashing or keep update content of items S283_ALARM_TURNPRESS_STAT */
void UpdOrFlasFunc_S283_ALARM_TURNPRESS_STAT(void);
/*1. Clear or Initilal screen for  S284_ALARM_TURNPRESS_SET operation*/
void IniOrClrScrFunc_S284_ALARM_TURNPRESS_SET(void);
/*1.3 Flashing or keep update content of items S284_ALARM_TURNPRESS_SET */
void UpdOrFlasFunc_S284_ALARM_TURNPRESS_SET(void);
/*1. Clear or Initilal screen for  S285_ALARM_ENDPRESS operation*/
void IniOrClrScrFunc_S285_ALARM_ENDPRESS(void);
/*1.2 Update the porition screen when the opcode changed for S285_ALARM_ENDPRESS operation*/
void UpdPorFunc_S285_ALARM_ENDPRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S285_ALARM_ENDPRESS*/
unsigned char CondiCheck_S285_ALARM_ENDPRESS(void);
/*2. Process preOpcode after change to S285_ALARM_ENDPRESS */
void HandlePreOCFunc_S285_ALARM_ENDPRESS(void);
/*Condition check to progress preOC valueS285_ALARM_ENDPRESS*/
unsigned char CondiPreOcCheck_S285_ALARM_ENDPRESS(void);
/*1. Clear or Initilal screen for  S286_ALARM_ENDPRESS_SET operation*/
void IniOrClrScrFunc_S286_ALARM_ENDPRESS_SET(void);
/*1.3 Flashing or keep update content of items S286_ALARM_ENDPRESS_SET */
void UpdOrFlasFunc_S286_ALARM_ENDPRESS_SET(void);
/*1. Clear or Initilal screen for  S353_ALARM_SWITCHPRESS operation*/
void IniOrClrScrFunc_S353_ALARM_SWITCHPRESS(void);
/*1.2 Update the porition screen when the opcode changed for S353_ALARM_SWITCHPRESS operation*/
void UpdPorFunc_S353_ALARM_SWITCHPRESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S353_ALARM_SWITCHPRESS*/
unsigned char CondiCheck_S353_ALARM_SWITCHPRESS(void);
/*2. Process preOpcode after change to S353_ALARM_SWITCHPRESS */
void HandlePreOCFunc_S353_ALARM_SWITCHPRESS(void);
/*Condition check to progress preOC valueS353_ALARM_SWITCHPRESS*/
unsigned char CondiPreOcCheck_S353_ALARM_SWITCHPRESS(void);
/*1. Clear or Initilal screen for  S354_ALARM_SWITCHPRESS_STAT operation*/
void IniOrClrScrFunc_S354_ALARM_SWITCHPRESS_STAT(void);
/*1.3 Flashing or keep update content of items S354_ALARM_SWITCHPRESS_STAT */
void UpdOrFlasFunc_S354_ALARM_SWITCHPRESS_STAT(void);
/*1. Clear or Initilal screen for  S355_ALARM_SWITCHPRESS_SET operation*/
void IniOrClrScrFunc_S355_ALARM_SWITCHPRESS_SET(void);
/*1.3 Flashing or keep update content of items S355_ALARM_SWITCHPRESS_SET */
void UpdOrFlasFunc_S355_ALARM_SWITCHPRESS_SET(void);
/*1. Clear or Initilal screen for  S289_ALARM_END operation*/
void IniOrClrScrFunc_S289_ALARM_END(void);
/*1.2 Update the porition screen when the opcode changed for S289_ALARM_END operation*/
void UpdPorFunc_S289_ALARM_END(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S289_ALARM_END*/
unsigned char CondiCheck_S289_ALARM_END(void);
/*2. Process preOpcode after change to S289_ALARM_END */
void HandlePreOCFunc_S289_ALARM_END(void);
/*Condition check to progress preOC valueS289_ALARM_END*/
unsigned char CondiPreOcCheck_S289_ALARM_END(void);
/*1. Clear or Initilal screen for  S290_ALARM_END_STAT operation*/
void IniOrClrScrFunc_S290_ALARM_END_STAT(void);
/*1.3 Flashing or keep update content of items S290_ALARM_END_STAT */
void UpdOrFlasFunc_S290_ALARM_END_STAT(void);
/*1. Clear or Initilal screen for  S291_ALARM_END_SET operation*/
void IniOrClrScrFunc_S291_ALARM_END_SET(void);
/*1.3 Flashing or keep update content of items S291_ALARM_END_SET */
void UpdOrFlasFunc_S291_ALARM_END_SET(void);
/*1. Clear or Initilal screen for  S292_ALARM_WOB operation*/
void IniOrClrScrFunc_S292_ALARM_WOB(void);
/*1.2 Update the porition screen when the opcode changed for S292_ALARM_WOB operation*/
void UpdPorFunc_S292_ALARM_WOB(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S292_ALARM_WOB*/
unsigned char CondiCheck_S292_ALARM_WOB(void);
/*2. Process preOpcode after change to S292_ALARM_WOB */
void HandlePreOCFunc_S292_ALARM_WOB(void);
/*Condition check to progress preOC valueS292_ALARM_WOB*/
unsigned char CondiPreOcCheck_S292_ALARM_WOB(void);
/*1. Clear or Initilal screen for  S293_ALARM_WOB_STAT operation*/
void IniOrClrScrFunc_S293_ALARM_WOB_STAT(void);
/*1.3 Flashing or keep update content of items S293_ALARM_WOB_STAT */
void UpdOrFlasFunc_S293_ALARM_WOB_STAT(void);
/*1. Clear or Initilal screen for  S294_ALARM_WOB_SET operation*/
void IniOrClrScrFunc_S294_ALARM_WOB_SET(void);
/*1.3 Flashing or keep update content of items S294_ALARM_WOB_SET */
void UpdOrFlasFunc_S294_ALARM_WOB_SET(void);
/*1. Clear or Initilal screen for  S295_ALARM_ICD operation*/
void IniOrClrScrFunc_S295_ALARM_ICD(void);
/*1.2 Update the porition screen when the opcode changed for S295_ALARM_ICD operation*/
void UpdPorFunc_S295_ALARM_ICD(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S295_ALARM_ICD*/
unsigned char CondiCheck_S295_ALARM_ICD(void);
/*2. Process preOpcode after change to S295_ALARM_ICD */
void HandlePreOCFunc_S295_ALARM_ICD(void);
/*Condition check to progress preOC valueS295_ALARM_ICD*/
unsigned char CondiPreOcCheck_S295_ALARM_ICD(void);
/*1. Clear or Initilal screen for  S296_ALARM_ICD_SET operation*/
void IniOrClrScrFunc_S296_ALARM_ICD_SET(void);
/*1.3 Flashing or keep update content of items S296_ALARM_ICD_SET */
void UpdOrFlasFunc_S296_ALARM_ICD_SET(void);
/*1. Clear or Initilal screen for  S297_ALARM_O2_NARCOTIC operation*/
void IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC(void);
/*1.2 Update the porition screen when the opcode changed for S297_ALARM_O2_NARCOTIC operation*/
void UpdPorFunc_S297_ALARM_O2_NARCOTIC(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S297_ALARM_O2_NARCOTIC*/
unsigned char CondiCheck_S297_ALARM_O2_NARCOTIC(void);
/*2. Process preOpcode after change to S297_ALARM_O2_NARCOTIC */
void HandlePreOCFunc_S297_ALARM_O2_NARCOTIC(void);
/*Condition check to progress preOC valueS297_ALARM_O2_NARCOTIC*/
unsigned char CondiPreOcCheck_S297_ALARM_O2_NARCOTIC(void);
/*1. Clear or Initilal screen for  S297_ALARM_O2_NARCOTIC_SET operation*/
void IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC_SET(void);
/*1.3 Flashing or keep update content of items S297_ALARM_O2_NARCOTIC_SET */
void UpdOrFlasFunc_S297_ALARM_O2_NARCOTIC_SET(void);
/*1. Clear or Initilal screen for  C1_COMPASS_MAIN operation*/
void IniOrClrScrFunc_C1_COMPASS_MAIN(void);
/*1.3 Flashing or keep update content of items C1_COMPASS_MAIN */
void UpdOrFlasFunc_C1_COMPASS_MAIN(void);
/*1. Clear or Initilal screen for  C2_COMPASS_MAIN_DIVE operation*/
void IniOrClrScrFunc_C2_COMPASS_MAIN_DIVE(void);
/*1.3 Flashing or keep update content of items C2_COMPASS_MAIN_DIVE */
void UpdOrFlasFunc_C2_COMPASS_MAIN_DIVE(void);
/*1. Clear or Initilal screen for  C7_COMPASS_CALIBRATION operation*/
void IniOrClrScrFunc_C7_COMPASS_CALIBRATION(void);
/*1.2 Update the porition screen when the opcode changed for C7_COMPASS_CALIBRATION operation*/
void UpdPorFunc_C7_COMPASS_CALIBRATION(void);
/*Condition check return the result when need to clear all the the screen or one portion only of C7_COMPASS_CALIBRATION*/
unsigned char CondiCheck_C7_COMPASS_CALIBRATION(void);
/*2. Process preOpcode after change to C7_COMPASS_CALIBRATION */
void HandlePreOCFunc_C7_COMPASS_CALIBRATION(void);
/*Condition check to progress preOC valueC7_COMPASS_CALIBRATION*/
unsigned char CondiPreOcCheck_C7_COMPASS_CALIBRATION(void);
/*1. Clear or Initilal screen for  C13_COMPASS_DECLIN_SET operation*/
void IniOrClrScrFunc_C13_COMPASS_DECLIN_SET(void);
/*1.2 Update the porition screen when the opcode changed for C13_COMPASS_DECLIN_SET operation*/
void UpdPorFunc_C13_COMPASS_DECLIN_SET(void);
/*Condition check return the result when need to clear all the the screen or one portion only of C13_COMPASS_DECLIN_SET*/
unsigned char CondiCheck_C13_COMPASS_DECLIN_SET(void);
/*2. Process preOpcode after change to C13_COMPASS_DECLIN_SET */
void HandlePreOCFunc_C13_COMPASS_DECLIN_SET(void);
/*Condition check to progress preOC valueC13_COMPASS_DECLIN_SET*/
unsigned char CondiPreOcCheck_C13_COMPASS_DECLIN_SET(void);
/*1. Clear or Initilal screen for  C9_COMPASS_PROCESSING operation*/
void IniOrClrScrFunc_C9_COMPASS_PROCESSING(void);
/*1. Clear or Initilal screen for  C10_COMPASS_CALIBRATION_PASSED operation*/
void IniOrClrScrFunc_C10_COMPASS_CALIBRATION_PASSED(void);
/*1. Clear or Initilal screen for  C11_COMPASS_CALIBRATION_FAILED operation*/
void IniOrClrScrFunc_C11_COMPASS_CALIBRATION_FAILED(void);
/*1. Clear or Initilal screen for  C14_COMPASS_DECLIN_SETTING operation*/
void IniOrClrScrFunc_C14_COMPASS_DECLIN_SETTING(void);
/*1.3 Flashing or keep update content of items C14_COMPASS_DECLIN_SETTING */
void UpdOrFlasFunc_C14_COMPASS_DECLIN_SETTING(void);
/*1. Clear or Initilal screen for  S502_GPS_GET_CURRENT_LOCATION operation*/
void IniOrClrScrFunc_S502_GPS_GET_CURRENT_LOCATION(void);
/*1.2 Update the porition screen when the opcode changed for S502_GPS_GET_CURRENT_LOCATION operation*/
void UpdPorFunc_S502_GPS_GET_CURRENT_LOCATION(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S502_GPS_GET_CURRENT_LOCATION*/
unsigned char CondiCheck_S502_GPS_GET_CURRENT_LOCATION(void);
/*2. Process preOpcode after change to S502_GPS_GET_CURRENT_LOCATION */
void HandlePreOCFunc_S502_GPS_GET_CURRENT_LOCATION(void);
/*Condition check to progress preOC valueS502_GPS_GET_CURRENT_LOCATION*/
unsigned char CondiPreOcCheck_S502_GPS_GET_CURRENT_LOCATION(void);
/*1. Clear or Initilal screen for  S503_GPS_20DATA_DELETE_TO_SAVE operation*/
void IniOrClrScrFunc_S503_GPS_20DATA_DELETE_TO_SAVE(void);
/*1. Clear or Initilal screen for  S504_GPS_INIT operation*/
void IniOrClrScrFunc_S504_GPS_INIT(void);
/*1. Clear or Initilal screen for  S505_GPS_WAIT_SIGNAL operation*/
void IniOrClrScrFunc_S505_GPS_WAIT_SIGNAL(void);
/*1.3 Flashing or keep update content of items S505_GPS_WAIT_SIGNAL */
void UpdOrFlasFunc_S505_GPS_WAIT_SIGNAL(void);
/*1. Clear or Initilal screen for  S506_GPS_NO_SIGNAL operation*/
void IniOrClrScrFunc_S506_GPS_NO_SIGNAL(void);
/*1. Clear or Initilal screen for  S507_GPS_SAVE_LOCATION_STAT operation*/
void IniOrClrScrFunc_S507_GPS_SAVE_LOCATION_STAT(void);
/*1.3 Flashing or keep update content of items S507_GPS_SAVE_LOCATION_STAT */
void UpdOrFlasFunc_S507_GPS_SAVE_LOCATION_STAT(void);
/*1. Clear or Initilal screen for  S508_GPS_LOCATION_SAVED operation*/
void IniOrClrScrFunc_S508_GPS_LOCATION_SAVED(void);
/*1. Clear or Initilal screen for  S509_GPS_WAYFINDER operation*/
void IniOrClrScrFunc_S509_GPS_WAYFINDER(void);
/*1.2 Update the porition screen when the opcode changed for S509_GPS_WAYFINDER operation*/
void UpdPorFunc_S509_GPS_WAYFINDER(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S509_GPS_WAYFINDER*/
unsigned char CondiCheck_S509_GPS_WAYFINDER(void);
/*2. Process preOpcode after change to S509_GPS_WAYFINDER */
void HandlePreOCFunc_S509_GPS_WAYFINDER(void);
/*Condition check to progress preOC valueS509_GPS_WAYFINDER*/
unsigned char CondiPreOcCheck_S509_GPS_WAYFINDER(void);
/*1. Clear or Initilal screen for  S510_GPS_WAYFINDER_LIST operation*/
void IniOrClrScrFunc_S510_GPS_WAYFINDER_LIST(void);
/*1.3 Flashing or keep update content of items S510_GPS_WAYFINDER_LIST */
void UpdOrFlasFunc_S510_GPS_WAYFINDER_LIST(void);
/*1. Clear or Initilal screen for  S511_GPS_WAYFINDER_GOTO operation*/
void IniOrClrScrFunc_S511_GPS_WAYFINDER_GOTO(void);
/*1. Clear or Initilal screen for  S519_GPS_WAYFINDER_EXIT operation*/
void IniOrClrScrFunc_S519_GPS_WAYFINDER_EXIT(void);
/*1.2 Update the porition screen when the opcode changed for S519_GPS_WAYFINDER_EXIT operation*/
void UpdPorFunc_S519_GPS_WAYFINDER_EXIT(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S519_GPS_WAYFINDER_EXIT*/
unsigned char CondiCheck_S519_GPS_WAYFINDER_EXIT(void);
/*2. Process preOpcode after change to S519_GPS_WAYFINDER_EXIT */
void HandlePreOCFunc_S519_GPS_WAYFINDER_EXIT(void);
/*Condition check to progress preOC valueS519_GPS_WAYFINDER_EXIT*/
unsigned char CondiPreOcCheck_S519_GPS_WAYFINDER_EXIT(void);
/*1. Clear or Initilal screen for  S519a_GPS_WAYFINDER_CHANGE_LOCATION operation*/
void IniOrClrScrFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void);
/*1.2 Update the porition screen when the opcode changed for S519a_GPS_WAYFINDER_CHANGE_LOCATION operation*/
void UpdPorFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S519a_GPS_WAYFINDER_CHANGE_LOCATION*/
unsigned char CondiCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void);
/*2. Process preOpcode after change to S519a_GPS_WAYFINDER_CHANGE_LOCATION */
void HandlePreOCFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void);
/*Condition check to progress preOC valueS519a_GPS_WAYFINDER_CHANGE_LOCATION*/
unsigned char CondiPreOcCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION(void);
/*1. Clear or Initilal screen for  S518_GPS_WAYFINDERLOCATION_REACHED operation*/
void IniOrClrScrFunc_S518_GPS_WAYFINDERLOCATION_REACHED(void);
/*1. Clear or Initilal screen for  S520_GPS_DELETE_LOCATION operation*/
void IniOrClrScrFunc_S520_GPS_DELETE_LOCATION(void);
/*1.2 Update the porition screen when the opcode changed for S520_GPS_DELETE_LOCATION operation*/
void UpdPorFunc_S520_GPS_DELETE_LOCATION(void);
/*Condition check return the result when need to clear all the the screen or one portion only of S520_GPS_DELETE_LOCATION*/
unsigned char CondiCheck_S520_GPS_DELETE_LOCATION(void);
/*2. Process preOpcode after change to S520_GPS_DELETE_LOCATION */
void HandlePreOCFunc_S520_GPS_DELETE_LOCATION(void);
/*Condition check to progress preOC valueS520_GPS_DELETE_LOCATION*/
unsigned char CondiPreOcCheck_S520_GPS_DELETE_LOCATION(void);
/*1. Clear or Initilal screen for  S522_GPS_DELETE_LOCATION operation*/
void IniOrClrScrFunc_S522_GPS_DELETE_LOCATION(void);
/*1. Clear or Initilal screen for  S523_GPS_LOCATION_DELETED operation*/
void IniOrClrScrFunc_S523_GPS_LOCATION_DELETED(void);
/*1. Clear or Initilal screen for  DIVE_GAUGE_MAIN operation*/
void IniOrClrScrFunc_DIVE_GAUGE_MAIN(void);
/*1.3 Flashing or keep update content of items DIVE_GAUGE_MAIN */
void UpdOrFlasFunc_DIVE_GAUGE_MAIN(void);
/*1. Clear or Initilal screen for  DIVE_GAUGE_ALT operation*/
void IniOrClrScrFunc_DIVE_GAUGE_ALT(void);
/*1.3 Flashing or keep update content of items DIVE_GAUGE_ALT */
void UpdOrFlasFunc_DIVE_GAUGE_ALT(void);
/*1. Clear or Initilal screen for  DIVE_DEPTH_AND_DIVETIME operation*/
void IniOrClrScrFunc_DIVE_DEPTH_AND_DIVETIME(void);
/*1.3 Flashing or keep update content of items DIVE_DEPTH_AND_DIVETIME */
void UpdOrFlasFunc_DIVE_DEPTH_AND_DIVETIME(void);
/*1. Clear or Initilal screen for  DIVE_CC_MAIN operation*/
void IniOrClrScrFunc_DIVE_CC_MAIN(void);
/*1.3 Flashing or keep update content of items DIVE_CC_MAIN */
void UpdOrFlasFunc_DIVE_CC_MAIN(void);
/*1. Clear or Initilal screen for  DIVE_CC_ALT_3 operation*/
void IniOrClrScrFunc_DIVE_CC_ALT_3(void);
/*1.3 Flashing or keep update content of items DIVE_CC_ALT_3 */
void UpdOrFlasFunc_DIVE_CC_ALT_3(void);
/*1. Clear or Initilal screen for  DIVE_CC_ALT_5 operation*/
void IniOrClrScrFunc_DIVE_CC_ALT_5(void);
/*1.3 Flashing or keep update content of items DIVE_CC_ALT_5 */
void UpdOrFlasFunc_DIVE_CC_ALT_5(void);
/*1. Clear or Initilal screen for  DIVE_OC_MAIN operation*/
void IniOrClrScrFunc_DIVE_OC_MAIN(void);
/*1.3 Flashing or keep update content of items DIVE_OC_MAIN */
void UpdOrFlasFunc_DIVE_OC_MAIN(void);
/*1. Clear or Initilal screen for  DIVE_OC_ALT_1 operation*/
void IniOrClrScrFunc_DIVE_OC_ALT_1(void);
/*1.3 Flashing or keep update content of items DIVE_OC_ALT_1 */
void UpdOrFlasFunc_DIVE_OC_ALT_1(void);
/*1. Clear or Initilal screen for  DIVE_OC_ALT_2 operation*/
void IniOrClrScrFunc_DIVE_OC_ALT_2(void);
/*1.3 Flashing or keep update content of items DIVE_OC_ALT_2 */
void UpdOrFlasFunc_DIVE_OC_ALT_2(void);
/*1. Clear or Initilal screen for  DIVE_OC_ALT_3 operation*/
void IniOrClrScrFunc_DIVE_OC_ALT_3(void);
/*1.3 Flashing or keep update content of items DIVE_OC_ALT_3 */
void UpdOrFlasFunc_DIVE_OC_ALT_3(void);
/*1. Clear or Initilal screen for  DIVE_OC_ALT_4 operation*/
void IniOrClrScrFunc_DIVE_OC_ALT_4(void);
/*1.3 Flashing or keep update content of items DIVE_OC_ALT_4 */
void UpdOrFlasFunc_DIVE_OC_ALT_4(void);
/*1. Clear or Initilal screen for  DIVE_OC_ALT_5 operation*/
void IniOrClrScrFunc_DIVE_OC_ALT_5(void);
/*1.3 Flashing or keep update content of items DIVE_OC_ALT_5 */
void UpdOrFlasFunc_DIVE_OC_ALT_5(void);
/*1. Clear or Initilal screen for  DIVE_SM_MAIN operation*/
void IniOrClrScrFunc_DIVE_SM_MAIN(void);
/*1.3 Flashing or keep update content of items DIVE_SM_MAIN */
void UpdOrFlasFunc_DIVE_SM_MAIN(void);
/*1. Clear or Initilal screen for  DIVE_SM_ALT_1 operation*/
void IniOrClrScrFunc_DIVE_SM_ALT_1(void);
/*1.3 Flashing or keep update content of items DIVE_SM_ALT_1 */
void UpdOrFlasFunc_DIVE_SM_ALT_1(void);
/*1. Clear or Initilal screen for  DIVE_SM_ALT_2 operation*/
void IniOrClrScrFunc_DIVE_SM_ALT_2(void);
/*1.3 Flashing or keep update content of items DIVE_SM_ALT_2 */
void UpdOrFlasFunc_DIVE_SM_ALT_2(void);
/*1. Clear or Initilal screen for  DIVE_SM_ALT_3 operation*/
void IniOrClrScrFunc_DIVE_SM_ALT_3(void);
/*1.3 Flashing or keep update content of items DIVE_SM_ALT_3 */
void UpdOrFlasFunc_DIVE_SM_ALT_3(void);
/*1. Clear or Initilal screen for  DIVE_SM_ALT_4 operation*/
void IniOrClrScrFunc_DIVE_SM_ALT_4(void);
/*1.3 Flashing or keep update content of items DIVE_SM_ALT_4 */
void UpdOrFlasFunc_DIVE_SM_ALT_4(void);
/*1. Clear or Initilal screen for  DIVE_SM_ALT_5 operation*/
void IniOrClrScrFunc_DIVE_SM_ALT_5(void);
/*1.3 Flashing or keep update content of items DIVE_SM_ALT_5 */
void UpdOrFlasFunc_DIVE_SM_ALT_5(void);
/*1. Clear or Initilal screen for  DIVE_GSM_MAIN operation*/
void IniOrClrScrFunc_DIVE_GSM_MAIN(void);
/*1.3 Flashing or keep update content of items DIVE_GSM_MAIN */
void UpdOrFlasFunc_DIVE_GSM_MAIN(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_GASSWITCH operation*/
void IniOrClrScrFunc_DIVEMAINMENU_GASSWITCH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_GASSWITCH operation*/
void UpdPorFunc_DIVEMAINMENU_GASSWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_GASSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_GASSWITCH(void);
/*2. Process preOpcode after change to DIVEMAINMENU_GASSWITCH */
void HandlePreOCFunc_DIVEMAINMENU_GASSWITCH(void);
/*Condition check to progress preOC valueDIVEMAINMENU_GASSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_GASSWITCH(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_BRIGHTNESS operation*/
void IniOrClrScrFunc_DIVEMAINMENU_BRIGHTNESS(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_BRIGHTNESS operation*/
void UpdPorFunc_DIVEMAINMENU_BRIGHTNESS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_BRIGHTNESS*/
unsigned char CondiCheck_DIVEMAINMENU_BRIGHTNESS(void);
/*2. Process preOpcode after change to DIVEMAINMENU_BRIGHTNESS */
void HandlePreOCFunc_DIVEMAINMENU_BRIGHTNESS(void);
/*Condition check to progress preOC valueDIVEMAINMENU_BRIGHTNESS*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_BRIGHTNESS(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_DIVEMENU operation*/
void IniOrClrScrFunc_DIVEMAINMENU_DIVEMENU(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_DIVEMENU operation*/
void UpdPorFunc_DIVEMAINMENU_DIVEMENU(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEMENU*/
unsigned char CondiCheck_DIVEMAINMENU_DIVEMENU(void);
/*2. Process preOpcode after change to DIVEMAINMENU_DIVEMENU */
void HandlePreOCFunc_DIVEMAINMENU_DIVEMENU(void);
/*Condition check to progress preOC valueDIVEMAINMENU_DIVEMENU*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_DIVEMENU(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_SLATES operation*/
void IniOrClrScrFunc_DIVEMAINMENU_SLATES(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_SLATES operation*/
void UpdPorFunc_DIVEMAINMENU_SLATES(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SLATES*/
unsigned char CondiCheck_DIVEMAINMENU_SLATES(void);
/*2. Process preOpcode after change to DIVEMAINMENU_SLATES */
void HandlePreOCFunc_DIVEMAINMENU_SLATES(void);
/*Condition check to progress preOC valueDIVEMAINMENU_SLATES*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SLATES(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_TMTSWITCH operation*/
void IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_TMTSWITCH operation*/
void UpdPorFunc_DIVEMAINMENU_TMTSWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_TMTSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_TMTSWITCH(void);
/*2. Process preOpcode after change to DIVEMAINMENU_TMTSWITCH */
void HandlePreOCFunc_DIVEMAINMENU_TMTSWITCH(void);
/*Condition check to progress preOC valueDIVEMAINMENU_TMTSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_TMTSWITCH(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_RESETAVGDEPTH operation*/
void IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_RESETAVGDEPTH operation*/
void UpdPorFunc_DIVEMAINMENU_RESETAVGDEPTH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_RESETAVGDEPTH*/
unsigned char CondiCheck_DIVEMAINMENU_RESETAVGDEPTH(void);
/*2. Process preOpcode after change to DIVEMAINMENU_RESETAVGDEPTH */
void HandlePreOCFunc_DIVEMAINMENU_RESETAVGDEPTH(void);
/*Condition check to progress preOC valueDIVEMAINMENU_RESETAVGDEPTH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_RESETAVGDEPTH(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_DIVEPROFILE operation*/
void IniOrClrScrFunc_DIVEMAINMENU_DIVEPROFILE(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_DIVEPROFILE operation*/
void UpdPorFunc_DIVEMAINMENU_DIVEPROFILE(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_DIVEPROFILE*/
unsigned char CondiCheck_DIVEMAINMENU_DIVEPROFILE(void);
/*2. Process preOpcode after change to DIVEMAINMENU_DIVEPROFILE */
void HandlePreOCFunc_DIVEMAINMENU_DIVEPROFILE(void);
/*Condition check to progress preOC valueDIVEMAINMENU_DIVEPROFILE*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_DIVEPROFILE(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_SPSWITCH operation*/
void IniOrClrScrFunc_DIVEMAINMENU_SPSWITCH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_SPSWITCH operation*/
void UpdPorFunc_DIVEMAINMENU_SPSWITCH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SPSWITCH*/
unsigned char CondiCheck_DIVEMAINMENU_SPSWITCH(void);
/*2. Process preOpcode after change to DIVEMAINMENU_SPSWITCH */
void HandlePreOCFunc_DIVEMAINMENU_SPSWITCH(void);
/*Condition check to progress preOC valueDIVEMAINMENU_SPSWITCH*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SPSWITCH(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_SWITCHCC2BO operation*/
void IniOrClrScrFunc_DIVEMAINMENU_SWITCHCC2BO(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_SWITCHCC2BO operation*/
void UpdPorFunc_DIVEMAINMENU_SWITCHCC2BO(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHCC2BO*/
unsigned char CondiCheck_DIVEMAINMENU_SWITCHCC2BO(void);
/*2. Process preOpcode after change to DIVEMAINMENU_SWITCHCC2BO */
void HandlePreOCFunc_DIVEMAINMENU_SWITCHCC2BO(void);
/*Condition check to progress preOC valueDIVEMAINMENU_SWITCHCC2BO*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SWITCHCC2BO(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_SWITCHBO2CC operation*/
void IniOrClrScrFunc_DIVEMAINMENU_SWITCHBO2CC(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMAINMENU_SWITCHBO2CC operation*/
void UpdPorFunc_DIVEMAINMENU_SWITCHBO2CC(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMAINMENU_SWITCHBO2CC*/
unsigned char CondiCheck_DIVEMAINMENU_SWITCHBO2CC(void);
/*2. Process preOpcode after change to DIVEMAINMENU_SWITCHBO2CC */
void HandlePreOCFunc_DIVEMAINMENU_SWITCHBO2CC(void);
/*Condition check to progress preOC valueDIVEMAINMENU_SWITCHBO2CC*/
unsigned char CondiPreOcCheck_DIVEMAINMENU_SWITCHBO2CC(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_TMTSWITCH_SET operation*/
void IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH_SET(void);
/*1.3 Flashing or keep update content of items DIVEMAINMENU_TMTSWITCH_SET */
void UpdOrFlasFunc_DIVEMAINMENU_TMTSWITCH_SET(void);
/*1. Clear or Initilal screen for  DIVEMAINMENU_RESETAVGDEPTH_SET operation*/
void IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH_SET(void);
/*1. Clear or Initilal screen for  DIVEMENU_SETSP operation*/
void IniOrClrScrFunc_DIVEMENU_SETSP(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_SETSP operation*/
void UpdPorFunc_DIVEMENU_SETSP(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETSP*/
unsigned char CondiCheck_DIVEMENU_SETSP(void);
/*2. Process preOpcode after change to DIVEMENU_SETSP */
void HandlePreOCFunc_DIVEMENU_SETSP(void);
/*Condition check to progress preOC valueDIVEMENU_SETSP*/
unsigned char CondiPreOcCheck_DIVEMENU_SETSP(void);
/*1. Clear or Initilal screen for  DIVEMENU_SETGASES operation*/
void IniOrClrScrFunc_DIVEMENU_SETGASES(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_SETGASES operation*/
void UpdPorFunc_DIVEMENU_SETGASES(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGASES*/
unsigned char CondiCheck_DIVEMENU_SETGASES(void);
/*2. Process preOpcode after change to DIVEMENU_SETGASES */
void HandlePreOCFunc_DIVEMENU_SETGASES(void);
/*Condition check to progress preOC valueDIVEMENU_SETGASES*/
unsigned char CondiPreOcCheck_DIVEMENU_SETGASES(void);
/*1. Clear or Initilal screen for  DIVEMENU_DIVEPROFILEGRAPH operation*/
void IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_DIVEPROFILEGRAPH operation*/
void UpdPorFunc_DIVEMENU_DIVEPROFILEGRAPH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DIVEPROFILEGRAPH*/
unsigned char CondiCheck_DIVEMENU_DIVEPROFILEGRAPH(void);
/*2. Process preOpcode after change to DIVEMENU_DIVEPROFILEGRAPH */
void HandlePreOCFunc_DIVEMENU_DIVEPROFILEGRAPH(void);
/*Condition check to progress preOC valueDIVEMENU_DIVEPROFILEGRAPH*/
unsigned char CondiPreOcCheck_DIVEMENU_DIVEPROFILEGRAPH(void);
/*1. Clear or Initilal screen for  DIVEMENU_BAILOUTPO2LIMITS operation*/
void IniOrClrScrFunc_DIVEMENU_BAILOUTPO2LIMITS(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_BAILOUTPO2LIMITS operation*/
void UpdPorFunc_DIVEMENU_BAILOUTPO2LIMITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_BAILOUTPO2LIMITS*/
unsigned char CondiCheck_DIVEMENU_BAILOUTPO2LIMITS(void);
/*2. Process preOpcode after change to DIVEMENU_BAILOUTPO2LIMITS */
void HandlePreOCFunc_DIVEMENU_BAILOUTPO2LIMITS(void);
/*Condition check to progress preOC valueDIVEMENU_BAILOUTPO2LIMITS*/
unsigned char CondiPreOcCheck_DIVEMENU_BAILOUTPO2LIMITS(void);
/*1. Clear or Initilal screen for  DIVEMENU_DECOSTOPS operation*/
void IniOrClrScrFunc_DIVEMENU_DECOSTOPS(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_DECOSTOPS operation*/
void UpdPorFunc_DIVEMENU_DECOSTOPS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_DECOSTOPS*/
unsigned char CondiCheck_DIVEMENU_DECOSTOPS(void);
/*2. Process preOpcode after change to DIVEMENU_DECOSTOPS */
void HandlePreOCFunc_DIVEMENU_DECOSTOPS(void);
/*Condition check to progress preOC valueDIVEMENU_DECOSTOPS*/
unsigned char CondiPreOcCheck_DIVEMENU_DECOSTOPS(void);
/*1. Clear or Initilal screen for  DIVEMENU_SETGFHIGH operation*/
void IniOrClrScrFunc_DIVEMENU_SETGFHIGH(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_SETGFHIGH operation*/
void UpdPorFunc_DIVEMENU_SETGFHIGH(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_SETGFHIGH*/
unsigned char CondiCheck_DIVEMENU_SETGFHIGH(void);
/*2. Process preOpcode after change to DIVEMENU_SETGFHIGH */
void HandlePreOCFunc_DIVEMENU_SETGFHIGH(void);
/*Condition check to progress preOC valueDIVEMENU_SETGFHIGH*/
unsigned char CondiPreOcCheck_DIVEMENU_SETGFHIGH(void);
/*1. Clear or Initilal screen for  DIVEMENU_PO2LIMITS operation*/
void IniOrClrScrFunc_DIVEMENU_PO2LIMITS(void);
/*1.2 Update the porition screen when the opcode changed for DIVEMENU_PO2LIMITS operation*/
void UpdPorFunc_DIVEMENU_PO2LIMITS(void);
/*Condition check return the result when need to clear all the the screen or one portion only of DIVEMENU_PO2LIMITS*/
unsigned char CondiCheck_DIVEMENU_PO2LIMITS(void);
/*2. Process preOpcode after change to DIVEMENU_PO2LIMITS */
void HandlePreOCFunc_DIVEMENU_PO2LIMITS(void);
/*Condition check to progress preOC valueDIVEMENU_PO2LIMITS*/
unsigned char CondiPreOcCheck_DIVEMENU_PO2LIMITS(void);
/*1. Clear or Initilal screen for  DIVEMENU_DIVEPROFILEGRAPH_ENTER operation*/
void IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER(void);
/*1.3 Flashing or keep update content of items DIVEMENU_DIVEPROFILEGRAPH_ENTER */
void UpdOrFlasFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER(void);
/*1. Clear or Initilal screen for  DIVEMENU_DECOSTOPS_ENTER operation*/
void IniOrClrScrFunc_DIVEMENU_DECOSTOPS_ENTER(void);
/*1.3 Flashing or keep update content of items DIVEMENU_DECOSTOPS_ENTER */
void UpdOrFlasFunc_DIVEMENU_DECOSTOPS_ENTER(void);
/*1. Clear or Initilal screen for  DIVEMENU_SET_GF_HIGH_ENTER operation*/
void IniOrClrScrFunc_DIVEMENU_SET_GF_HIGH_ENTER(void);
/*1.3 Flashing or keep update content of items DIVEMENU_SET_GF_HIGH_ENTER */
void UpdOrFlasFunc_DIVEMENU_SET_GF_HIGH_ENTER(void);
/*1. Clear or Initilal screen for  E1_ERROR_DEPTH_SENSOR operation*/
void IniOrClrScrFunc_E1_ERROR_DEPTH_SENSOR(void);
/*1.3 Flashing or keep update content of items E1_ERROR_DEPTH_SENSOR */
void UpdOrFlasFunc_E1_ERROR_DEPTH_SENSOR(void);
/*1. Clear or Initilal screen for  E2_ERROR_EEPROM operation*/
void IniOrClrScrFunc_E2_ERROR_EEPROM(void);
/*1.3 Flashing or keep update content of items E2_ERROR_EEPROM */
void UpdOrFlasFunc_E2_ERROR_EEPROM(void);
/*1. Clear or Initilal screen for  E3_ERROR_EXFLASH operation*/
void IniOrClrScrFunc_E3_ERROR_EXFLASH(void);
/*1.3 Flashing or keep update content of items E3_ERROR_EXFLASH */
void UpdOrFlasFunc_E3_ERROR_EXFLASH(void);
/*1. Clear or Initilal screen for  E4_ERROR_CALIBRATION operation*/
void IniOrClrScrFunc_E4_ERROR_CALIBRATION(void);
/*1.3 Flashing or keep update content of items E4_ERROR_CALIBRATION */
void UpdOrFlasFunc_E4_ERROR_CALIBRATION(void);
/*1. Clear or Initilal screen for  E5_ERROR_CHECKSUM operation*/
void IniOrClrScrFunc_E5_ERROR_CHECKSUM(void);
/*1.3 Flashing or keep update content of items E5_ERROR_CHECKSUM */
void UpdOrFlasFunc_E5_ERROR_CHECKSUM(void);
/*1. Clear or Initilal screen for  E6_ERROR_DIVE_10HR operation*/
void IniOrClrScrFunc_E6_ERROR_DIVE_10HR(void);
/*1.3 Flashing or keep update content of items E6_ERROR_DIVE_10HR */
void UpdOrFlasFunc_E6_ERROR_DIVE_10HR(void);
/*1. Clear or Initilal screen for  E7_ERROR_BATTERY_TOO_LOW operation*/
void IniOrClrScrFunc_E7_ERROR_BATTERY_TOO_LOW(void);
/*1.3 Flashing or keep update content of items E7_ERROR_BATTERY_TOO_LOW */
void UpdOrFlasFunc_E7_ERROR_BATTERY_TOO_LOW(void);
/*1. Clear or Initilal screen for  E8_ERROR_BLUETOOTH operation*/
void IniOrClrScrFunc_E8_ERROR_BLUETOOTH(void);
/*1.3 Flashing or keep update content of items E8_ERROR_BLUETOOTH */
void UpdOrFlasFunc_E8_ERROR_BLUETOOTH(void);
/*1. Clear or Initilal screen for  E9_ERROR_COMPASS operation*/
void IniOrClrScrFunc_E9_ERROR_COMPASS(void);
/*1.3 Flashing or keep update content of items E9_ERROR_COMPASS */
void UpdOrFlasFunc_E9_ERROR_COMPASS(void);
/*1. Clear or Initilal screen for  E10_ERROR_GPS operation*/
void IniOrClrScrFunc_E10_ERROR_GPS(void);
/*1.3 Flashing or keep update content of items E10_ERROR_GPS */
void UpdOrFlasFunc_E10_ERROR_GPS(void);
/*1. Clear or Initilal screen for  E11_ERROR_O2_SENSOR operation*/
void IniOrClrScrFunc_E11_ERROR_O2_SENSOR(void);
/*1.3 Flashing or keep update content of items E11_ERROR_O2_SENSOR */
void UpdOrFlasFunc_E11_ERROR_O2_SENSOR(void);
/*1. Clear or Initilal screen for  E12_ERROR_ALTITUDE operation*/
void IniOrClrScrFunc_E12_ERROR_ALTITUDE(void);
/*1.3 Flashing or keep update content of items E12_ERROR_ALTITUDE */
void UpdOrFlasFunc_E12_ERROR_ALTITUDE(void);
/*1. Clear or Initilal screen for  E9_ERROR_NOT_YET_CALI  operation*/
void IniOrClrScrFunc_E9_ERROR_NOT_YET_CALI (void);
/*1.3 Flashing or keep update content of items E9_ERROR_NOT_YET_CALI  */
void UpdOrFlasFunc_E9_ERROR_NOT_YET_CALI (void);
/*1. Clear or Initilal screen for  E10_ERROR_DIVE_NOT_COMPLETE operation*/
void IniOrClrScrFunc_E10_ERROR_DIVE_NOT_COMPLETE(void);
/*1.3 Flashing or keep update content of items E10_ERROR_DIVE_NOT_COMPLETE */
void UpdOrFlasFunc_E10_ERROR_DIVE_NOT_COMPLETE(void);
/*1. Clear or Initilal screen for  E11_ERROR_ADC  operation*/
void IniOrClrScrFunc_E11_ERROR_ADC (void);
/*1.3 Flashing or keep update content of items E11_ERROR_ADC  */
void UpdOrFlasFunc_E11_ERROR_ADC (void);
/*1. Clear or Initilal screen for  E12_ERROR_TEMP_SENSOR  operation*/
void IniOrClrScrFunc_E12_ERROR_TEMP_SENSOR (void);
/*1.3 Flashing or keep update content of items E12_ERROR_TEMP_SENSOR  */
void UpdOrFlasFunc_E12_ERROR_TEMP_SENSOR (void);
/*1. Clear or Initilal screen for  E13_ERROR_VOLT_SENSOR  operation*/
void IniOrClrScrFunc_E13_ERROR_VOLT_SENSOR (void);
/*1.3 Flashing or keep update content of items E13_ERROR_VOLT_SENSOR  */
void UpdOrFlasFunc_E13_ERROR_VOLT_SENSOR (void);
/*1. Clear or Initilal screen for  E14_ERROR_TICK_TIME  operation*/
void IniOrClrScrFunc_E14_ERROR_TICK_TIME (void);
/*1.3 Flashing or keep update content of items E14_ERROR_TICK_TIME  */
void UpdOrFlasFunc_E14_ERROR_TICK_TIME (void);
/*1. Clear or Initilal screen for  E15_ERROR_BUTTON  operation*/
void IniOrClrScrFunc_E15_ERROR_BUTTON (void);
/*1.3 Flashing or keep update content of items E15_ERROR_BUTTON  */
void UpdOrFlasFunc_E15_ERROR_BUTTON (void);
/*1. Clear or Initilal screen for  E16_ERROR_ALTITUDE  operation*/
void IniOrClrScrFunc_E16_ERROR_ALTITUDE (void);
/*1.3 Flashing or keep update content of items E16_ERROR_ALTITUDE  */
void UpdOrFlasFunc_E16_ERROR_ALTITUDE (void);
/*1. Clear or Initilal screen for  E17_ERROR_COMPASS  operation*/
void IniOrClrScrFunc_E17_ERROR_COMPASS (void);
/*1.3 Flashing or keep update content of items E17_ERROR_COMPASS  */
void UpdOrFlasFunc_E17_ERROR_COMPASS (void);
/*1. Clear or Initilal screen for  E18_ERROR_FUEL_GAUGE  operation*/
void IniOrClrScrFunc_E18_ERROR_FUEL_GAUGE (void);
/*1.3 Flashing or keep update content of items E18_ERROR_FUEL_GAUGE  */
void UpdOrFlasFunc_E18_ERROR_FUEL_GAUGE (void);
/*1. Clear or Initilal screen for  E19_ERROR_RECEIVER  operation*/
void IniOrClrScrFunc_E19_ERROR_RECEIVER (void);
/*1.3 Flashing or keep update content of items E19_ERROR_RECEIVER  */
void UpdOrFlasFunc_E19_ERROR_RECEIVER (void);
/*1. Clear or Initilal screen for  E20_ERROR_GPS  operation*/
void IniOrClrScrFunc_E20_ERROR_GPS (void);
/*1.3 Flashing or keep update content of items E20_ERROR_GPS  */
void UpdOrFlasFunc_E20_ERROR_GPS (void);
/*1. Clear or Initilal screen for  E21_ERROR_O2_SENSOR  operation*/
void IniOrClrScrFunc_E21_ERROR_O2_SENSOR (void);
/*1.3 Flashing or keep update content of items E21_ERROR_O2_SENSOR  */
void UpdOrFlasFunc_E21_ERROR_O2_SENSOR (void);
/*1. Clear or Initilal screen for  E22_POPUP_USINGDIVELOGAPP operation*/
void IniOrClrScrFunc_E22_POPUP_USINGDIVELOGAPP(void);
#define Call_InitFunc_W1_WELCOME	IniOrClrScrFunc_W1_WELCOME
#define Call_CondiCheckFunc_W1_WELCOME ReturnTrue
#define Call_UpdPortionFunc_W1_WELCOME	FuncDoNothing
#define Call_UpdOrFlashFunc_W1_WELCOME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_W1_WELCOME	ReturnFalse
#define Call_HandlePreOCFunc_W1_WELCOME	FuncDoNothing
#define Call_InitFunc_W2_WAIT_MESSAGE	IniOrClrScrFunc_W2_WAIT_MESSAGE
#define Call_CondiCheckFunc_W2_WAIT_MESSAGE ReturnTrue
#define Call_UpdPortionFunc_W2_WAIT_MESSAGE	FuncDoNothing
#define Call_UpdOrFlashFunc_W2_WAIT_MESSAGE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_W2_WAIT_MESSAGE	ReturnFalse
#define Call_HandlePreOCFunc_W2_WAIT_MESSAGE	FuncDoNothing
#define Call_InitFunc_MANUFACTURE_SCREEN	IniOrClrScrFunc_MANUFACTURE_SCREEN
#define Call_CondiCheckFunc_MANUFACTURE_SCREEN ReturnTrue
#define Call_UpdPortionFunc_MANUFACTURE_SCREEN	FuncDoNothing
#define Call_UpdOrFlashFunc_MANUFACTURE_SCREEN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_MANUFACTURE_SCREEN	ReturnFalse
#define Call_HandlePreOCFunc_MANUFACTURE_SCREEN	FuncDoNothing
#define Call_InitFunc_B1_BATT_CHARGE	IniOrClrScrFunc_B1_BATT_CHARGE
#define Call_CondiCheckFunc_B1_BATT_CHARGE ReturnTrue
#define Call_UpdPortionFunc_B1_BATT_CHARGE	FuncDoNothing
#define Call_UpdOrFlashFunc_B1_BATT_CHARGE	UpdOrFlasFunc_B1_BATT_CHARGE
#define Call_CondiCheckPreOCFunc_B1_BATT_CHARGE	ReturnFalse
#define Call_HandlePreOCFunc_B1_BATT_CHARGE	FuncDoNothing
#define Call_InitFunc_REGISTER_SCREEN	IniOrClrScrFunc_REGISTER_SCREEN
#define Call_CondiCheckFunc_REGISTER_SCREEN ReturnTrue
#define Call_UpdPortionFunc_REGISTER_SCREEN	FuncDoNothing
#define Call_UpdOrFlashFunc_REGISTER_SCREEN	UpdOrFlasFunc_REGISTER_SCREEN
#define Call_CondiCheckPreOCFunc_REGISTER_SCREEN	ReturnFalse
#define Call_HandlePreOCFunc_REGISTER_SCREEN	FuncDoNothing
#define Call_InitFunc_S18_SP_SWITCH	IniOrClrScrFunc_S18_SP_SWITCH
#define Call_CondiCheckFunc_S18_SP_SWITCH	CondiCheck_S18_SP_SWITCH
#define Call_UpdPortionFunc_S18_SP_SWITCH	UpdPorFunc_S18_SP_SWITCH
#define Call_UpdOrFlashFunc_S18_SP_SWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S18_SP_SWITCH	CondiPreOcCheck_S18_SP_SWITCH
#define Call_HandlePreOCFunc_S18_SP_SWITCH	HandlePreOCFunc_S18_SP_SWITCH
#define Call_InitFunc_S21_GAS_SWITCH	IniOrClrScrFunc_S21_GAS_SWITCH
#define Call_CondiCheckFunc_S21_GAS_SWITCH	CondiCheck_S21_GAS_SWITCH
#define Call_UpdPortionFunc_S21_GAS_SWITCH	UpdPorFunc_S21_GAS_SWITCH
#define Call_UpdOrFlashFunc_S21_GAS_SWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S21_GAS_SWITCH	CondiPreOcCheck_S21_GAS_SWITCH
#define Call_HandlePreOCFunc_S21_GAS_SWITCH	HandlePreOCFunc_S21_GAS_SWITCH
#define Call_InitFunc_S62_DIVE_PLANNER	IniOrClrScrFunc_S62_DIVE_PLANNER
#define Call_CondiCheckFunc_S62_DIVE_PLANNER	CondiCheck_S62_DIVE_PLANNER
#define Call_UpdPortionFunc_S62_DIVE_PLANNER	UpdPorFunc_S62_DIVE_PLANNER
#define Call_UpdOrFlashFunc_S62_DIVE_PLANNER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S62_DIVE_PLANNER	CondiPreOcCheck_S62_DIVE_PLANNER
#define Call_HandlePreOCFunc_S62_DIVE_PLANNER	HandlePreOCFunc_S62_DIVE_PLANNER
#define Call_InitFunc_S27_LOG	IniOrClrScrFunc_S27_LOG
#define Call_CondiCheckFunc_S27_LOG	CondiCheck_S27_LOG
#define Call_UpdPortionFunc_S27_LOG	UpdPorFunc_S27_LOG
#define Call_UpdOrFlashFunc_S27_LOG	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S27_LOG	CondiPreOcCheck_S27_LOG
#define Call_HandlePreOCFunc_S27_LOG	HandlePreOCFunc_S27_LOG
#define Call_InitFunc_S41_SET_MENU	IniOrClrScrFunc_S41_SET_MENU
#define Call_CondiCheckFunc_S41_SET_MENU	CondiCheck_S41_SET_MENU
#define Call_UpdPortionFunc_S41_SET_MENU	UpdPorFunc_S41_SET_MENU
#define Call_UpdOrFlashFunc_S41_SET_MENU	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S41_SET_MENU	CondiPreOcCheck_S41_SET_MENU
#define Call_HandlePreOCFunc_S41_SET_MENU	HandlePreOCFunc_S41_SET_MENU
#define Call_InitFunc_S185_INFO	IniOrClrScrFunc_S185_INFO
#define Call_CondiCheckFunc_S185_INFO	CondiCheck_S185_INFO
#define Call_UpdPortionFunc_S185_INFO	UpdPorFunc_S185_INFO
#define Call_UpdOrFlashFunc_S185_INFO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S185_INFO	CondiPreOcCheck_S185_INFO
#define Call_HandlePreOCFunc_S185_INFO	HandlePreOCFunc_S185_INFO
#define Call_InitFunc_S_SLATE	IniOrClrScrFunc_S_SLATE
#define Call_CondiCheckFunc_S_SLATE	CondiCheck_S_SLATE
#define Call_UpdPortionFunc_S_SLATE	UpdPorFunc_S_SLATE
#define Call_UpdOrFlashFunc_S_SLATE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S_SLATE	CondiPreOcCheck_S_SLATE
#define Call_HandlePreOCFunc_S_SLATE	HandlePreOCFunc_S_SLATE
#define Call_InitFunc_S404_TMT_SWITCH	IniOrClrScrFunc_S404_TMT_SWITCH
#define Call_CondiCheckFunc_S404_TMT_SWITCH	CondiCheck_S404_TMT_SWITCH
#define Call_UpdPortionFunc_S404_TMT_SWITCH	UpdPorFunc_S404_TMT_SWITCH
#define Call_UpdOrFlashFunc_S404_TMT_SWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S404_TMT_SWITCH	CondiPreOcCheck_S404_TMT_SWITCH
#define Call_HandlePreOCFunc_S404_TMT_SWITCH	HandlePreOCFunc_S404_TMT_SWITCH
#define Call_InitFunc_S432_DIVE_MODE	IniOrClrScrFunc_S432_DIVE_MODE
#define Call_CondiCheckFunc_S432_DIVE_MODE	CondiCheck_S432_DIVE_MODE
#define Call_UpdPortionFunc_S432_DIVE_MODE	UpdPorFunc_S432_DIVE_MODE
#define Call_UpdOrFlashFunc_S432_DIVE_MODE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S432_DIVE_MODE	CondiPreOcCheck_S432_DIVE_MODE
#define Call_HandlePreOCFunc_S432_DIVE_MODE	HandlePreOCFunc_S432_DIVE_MODE
#define Call_InitFunc_SLATES_MAINPAGE	IniOrClrScrFunc_SLATES_MAINPAGE
#define Call_CondiCheckFunc_SLATES_MAINPAGE ReturnTrue
#define Call_UpdPortionFunc_SLATES_MAINPAGE	FuncDoNothing
#define Call_UpdOrFlashFunc_SLATES_MAINPAGE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SLATES_MAINPAGE	ReturnFalse
#define Call_HandlePreOCFunc_SLATES_MAINPAGE	FuncDoNothing
#define Call_InitFunc_SLATES_NO_SLATE	IniOrClrScrFunc_SLATES_NO_SLATE
#define Call_CondiCheckFunc_SLATES_NO_SLATE ReturnTrue
#define Call_UpdPortionFunc_SLATES_NO_SLATE	FuncDoNothing
#define Call_UpdOrFlashFunc_SLATES_NO_SLATE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SLATES_NO_SLATE	ReturnFalse
#define Call_HandlePreOCFunc_SLATES_NO_SLATE	FuncDoNothing
#define Call_InitFunc_SLATES_CONFIRM_DELETE	IniOrClrScrFunc_SLATES_CONFIRM_DELETE
#define Call_CondiCheckFunc_SLATES_CONFIRM_DELETE ReturnTrue
#define Call_UpdPortionFunc_SLATES_CONFIRM_DELETE	FuncDoNothing
#define Call_UpdOrFlashFunc_SLATES_CONFIRM_DELETE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SLATES_CONFIRM_DELETE	ReturnFalse
#define Call_HandlePreOCFunc_SLATES_CONFIRM_DELETE	FuncDoNothing
#define Call_InitFunc_SLATES_DELETED	IniOrClrScrFunc_SLATES_DELETED
#define Call_CondiCheckFunc_SLATES_DELETED ReturnTrue
#define Call_UpdPortionFunc_SLATES_DELETED	FuncDoNothing
#define Call_UpdOrFlashFunc_SLATES_DELETED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SLATES_DELETED	ReturnFalse
#define Call_HandlePreOCFunc_SLATES_DELETED	FuncDoNothing
#define Call_InitFunc_S28_LOG_DATA1	IniOrClrScrFunc_S28_LOG_DATA1
#define Call_CondiCheckFunc_S28_LOG_DATA1 ReturnTrue
#define Call_UpdPortionFunc_S28_LOG_DATA1	FuncDoNothing
#define Call_UpdOrFlashFunc_S28_LOG_DATA1	UpdOrFlasFunc_S28_LOG_DATA1
#define Call_CondiCheckPreOCFunc_S28_LOG_DATA1	ReturnFalse
#define Call_HandlePreOCFunc_S28_LOG_DATA1	FuncDoNothing
#define Call_InitFunc_S29_LOG_DATA2	IniOrClrScrFunc_S29_LOG_DATA2
#define Call_CondiCheckFunc_S29_LOG_DATA2 ReturnTrue
#define Call_UpdPortionFunc_S29_LOG_DATA2	FuncDoNothing
#define Call_UpdOrFlashFunc_S29_LOG_DATA2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S29_LOG_DATA2	ReturnFalse
#define Call_HandlePreOCFunc_S29_LOG_DATA2	FuncDoNothing
#define Call_InitFunc_S37_LOG_DATA3	IniOrClrScrFunc_S37_LOG_DATA3
#define Call_CondiCheckFunc_S37_LOG_DATA3 ReturnTrue
#define Call_UpdPortionFunc_S37_LOG_DATA3	FuncDoNothing
#define Call_UpdOrFlashFunc_S37_LOG_DATA3	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S37_LOG_DATA3	ReturnFalse
#define Call_HandlePreOCFunc_S37_LOG_DATA3	FuncDoNothing
#define Call_InitFunc_S39_LOG_DATA4	IniOrClrScrFunc_S39_LOG_DATA4
#define Call_CondiCheckFunc_S39_LOG_DATA4 ReturnTrue
#define Call_UpdPortionFunc_S39_LOG_DATA4	FuncDoNothing
#define Call_UpdOrFlashFunc_S39_LOG_DATA4	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S39_LOG_DATA4	ReturnFalse
#define Call_HandlePreOCFunc_S39_LOG_DATA4	FuncDoNothing
#define Call_InitFunc_S36_LOG_DATA5	IniOrClrScrFunc_S36_LOG_DATA5
#define Call_CondiCheckFunc_S36_LOG_DATA5 ReturnTrue
#define Call_UpdPortionFunc_S36_LOG_DATA5	FuncDoNothing
#define Call_UpdOrFlashFunc_S36_LOG_DATA5	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S36_LOG_DATA5	ReturnFalse
#define Call_HandlePreOCFunc_S36_LOG_DATA5	FuncDoNothing
#define Call_InitFunc_S42_SET_GASES	IniOrClrScrFunc_S42_SET_GASES
#define Call_CondiCheckFunc_S42_SET_GASES	CondiCheck_S42_SET_GASES
#define Call_UpdPortionFunc_S42_SET_GASES	UpdPorFunc_S42_SET_GASES
#define Call_UpdOrFlashFunc_S42_SET_GASES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S42_SET_GASES	CondiPreOcCheck_S42_SET_GASES
#define Call_HandlePreOCFunc_S42_SET_GASES	HandlePreOCFunc_S42_SET_GASES
#define Call_InitFunc_S53_SET_SP	IniOrClrScrFunc_S53_SET_SP
#define Call_CondiCheckFunc_S53_SET_SP	CondiCheck_S53_SET_SP
#define Call_UpdPortionFunc_S53_SET_SP	UpdPorFunc_S53_SET_SP
#define Call_UpdOrFlashFunc_S53_SET_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S53_SET_SP	CondiPreOcCheck_S53_SET_SP
#define Call_HandlePreOCFunc_S53_SET_SP	HandlePreOCFunc_S53_SET_SP
#define Call_InitFunc_S_DIVE_SETTINGS	IniOrClrScrFunc_S_DIVE_SETTINGS
#define Call_CondiCheckFunc_S_DIVE_SETTINGS	CondiCheck_S_DIVE_SETTINGS
#define Call_UpdPortionFunc_S_DIVE_SETTINGS	UpdPorFunc_S_DIVE_SETTINGS
#define Call_UpdOrFlashFunc_S_DIVE_SETTINGS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S_DIVE_SETTINGS	CondiPreOcCheck_S_DIVE_SETTINGS
#define Call_HandlePreOCFunc_S_DIVE_SETTINGS	HandlePreOCFunc_S_DIVE_SETTINGS
#define Call_InitFunc_S105_ALARMS	IniOrClrScrFunc_S105_ALARMS
#define Call_CondiCheckFunc_S105_ALARMS	CondiCheck_S105_ALARMS
#define Call_UpdPortionFunc_S105_ALARMS	UpdPorFunc_S105_ALARMS
#define Call_UpdOrFlashFunc_S105_ALARMS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S105_ALARMS	CondiPreOcCheck_S105_ALARMS
#define Call_HandlePreOCFunc_S105_ALARMS	HandlePreOCFunc_S105_ALARMS
#define Call_InitFunc_S128_DEVICE_SETTINGS	IniOrClrScrFunc_S128_DEVICE_SETTINGS
#define Call_CondiCheckFunc_S128_DEVICE_SETTINGS	CondiCheck_S128_DEVICE_SETTINGS
#define Call_UpdPortionFunc_S128_DEVICE_SETTINGS	UpdPorFunc_S128_DEVICE_SETTINGS
#define Call_UpdOrFlashFunc_S128_DEVICE_SETTINGS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S128_DEVICE_SETTINGS	CondiPreOcCheck_S128_DEVICE_SETTINGS
#define Call_HandlePreOCFunc_S128_DEVICE_SETTINGS	HandlePreOCFunc_S128_DEVICE_SETTINGS
#define Call_InitFunc_S149_DATE_TIME	IniOrClrScrFunc_S149_DATE_TIME
#define Call_CondiCheckFunc_S149_DATE_TIME	CondiCheck_S149_DATE_TIME
#define Call_UpdPortionFunc_S149_DATE_TIME	UpdPorFunc_S149_DATE_TIME
#define Call_UpdOrFlashFunc_S149_DATE_TIME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S149_DATE_TIME	CondiPreOcCheck_S149_DATE_TIME
#define Call_HandlePreOCFunc_S149_DATE_TIME	HandlePreOCFunc_S149_DATE_TIME
#define Call_InitFunc_S161_DISPLAY_SETTINGS	IniOrClrScrFunc_S161_DISPLAY_SETTINGS
#define Call_CondiCheckFunc_S161_DISPLAY_SETTINGS	CondiCheck_S161_DISPLAY_SETTINGS
#define Call_UpdPortionFunc_S161_DISPLAY_SETTINGS	UpdPorFunc_S161_DISPLAY_SETTINGS
#define Call_UpdOrFlashFunc_S161_DISPLAY_SETTINGS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S161_DISPLAY_SETTINGS	CondiPreOcCheck_S161_DISPLAY_SETTINGS
#define Call_HandlePreOCFunc_S161_DISPLAY_SETTINGS	HandlePreOCFunc_S161_DISPLAY_SETTINGS
#define Call_InitFunc_S154_SET_DATE	IniOrClrScrFunc_S154_SET_DATE
#define Call_CondiCheckFunc_S154_SET_DATE	CondiCheck_S154_SET_DATE
#define Call_UpdPortionFunc_S154_SET_DATE	UpdPorFunc_S154_SET_DATE
#define Call_UpdOrFlashFunc_S154_SET_DATE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S154_SET_DATE	CondiPreOcCheck_S154_SET_DATE
#define Call_HandlePreOCFunc_S154_SET_DATE	HandlePreOCFunc_S154_SET_DATE
#define Call_InitFunc_S154_SET_YY	IniOrClrScrFunc_S154_SET_YY
#define Call_CondiCheckFunc_S154_SET_YY	CondiCheck_S154_SET_YY
#define Call_UpdPortionFunc_S154_SET_YY	UpdPorFunc_S154_SET_YY
#define Call_UpdOrFlashFunc_S154_SET_YY	UpdOrFlasFunc_S154_SET_YY
#define Call_CondiCheckPreOCFunc_S154_SET_YY	CondiPreOcCheck_S154_SET_YY
#define Call_HandlePreOCFunc_S154_SET_YY	HandlePreOCFunc_S154_SET_YY
#define Call_InitFunc_S154_SET_MM	FuncDoNothing
#define Call_CondiCheckFunc_S154_SET_MM	CondiCheck_S154_SET_MM
#define Call_UpdPortionFunc_S154_SET_MM	UpdPorFunc_S154_SET_MM
#define Call_UpdOrFlashFunc_S154_SET_MM	UpdOrFlasFunc_S154_SET_MM
#define Call_CondiCheckPreOCFunc_S154_SET_MM	CondiPreOcCheck_S154_SET_MM
#define Call_HandlePreOCFunc_S154_SET_MM	HandlePreOCFunc_S154_SET_MM
#define Call_InitFunc_S154_SET_DD	FuncDoNothing
#define Call_CondiCheckFunc_S154_SET_DD	CondiCheck_S154_SET_DD
#define Call_UpdPortionFunc_S154_SET_DD	UpdPorFunc_S154_SET_DD
#define Call_UpdOrFlashFunc_S154_SET_DD	UpdOrFlasFunc_S154_SET_DD
#define Call_CondiCheckPreOCFunc_S154_SET_DD	CondiPreOcCheck_S154_SET_DD
#define Call_HandlePreOCFunc_S154_SET_DD	HandlePreOCFunc_S154_SET_DD
#define Call_InitFunc_S158_SET_TIME	IniOrClrScrFunc_S158_SET_TIME
#define Call_CondiCheckFunc_S158_SET_TIME	CondiCheck_S158_SET_TIME
#define Call_UpdPortionFunc_S158_SET_TIME	UpdPorFunc_S158_SET_TIME
#define Call_UpdOrFlashFunc_S158_SET_TIME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S158_SET_TIME	CondiPreOcCheck_S158_SET_TIME
#define Call_HandlePreOCFunc_S158_SET_TIME	HandlePreOCFunc_S158_SET_TIME
#define Call_InitFunc_S158_SET_HH	IniOrClrScrFunc_S158_SET_HH
#define Call_CondiCheckFunc_S158_SET_HH	CondiCheck_S158_SET_HH
#define Call_UpdPortionFunc_S158_SET_HH	UpdPorFunc_S158_SET_HH
#define Call_UpdOrFlashFunc_S158_SET_HH	UpdOrFlasFunc_S158_SET_HH
#define Call_CondiCheckPreOCFunc_S158_SET_HH	CondiPreOcCheck_S158_SET_HH
#define Call_HandlePreOCFunc_S158_SET_HH	HandlePreOCFunc_S158_SET_HH
#define Call_InitFunc_S158_SET_MM	FuncDoNothing
#define Call_CondiCheckFunc_S158_SET_MM	CondiCheck_S158_SET_MM
#define Call_UpdPortionFunc_S158_SET_MM	UpdPorFunc_S158_SET_MM
#define Call_UpdOrFlashFunc_S158_SET_MM	UpdOrFlasFunc_S158_SET_MM
#define Call_CondiCheckPreOCFunc_S158_SET_MM	CondiPreOcCheck_S158_SET_MM
#define Call_HandlePreOCFunc_S158_SET_MM	HandlePreOCFunc_S158_SET_MM
#define Call_InitFunc_S158_SET_AM_PM	FuncDoNothing
#define Call_CondiCheckFunc_S158_SET_AM_PM	CondiCheck_S158_SET_AM_PM
#define Call_UpdPortionFunc_S158_SET_AM_PM	UpdPorFunc_S158_SET_AM_PM
#define Call_UpdOrFlashFunc_S158_SET_AM_PM	UpdOrFlasFunc_S158_SET_AM_PM
#define Call_CondiCheckPreOCFunc_S158_SET_AM_PM	CondiPreOcCheck_S158_SET_AM_PM
#define Call_HandlePreOCFunc_S158_SET_AM_PM	HandlePreOCFunc_S158_SET_AM_PM
#define Call_InitFunc_S150_SET_DATE_FORMAT	IniOrClrScrFunc_S150_SET_DATE_FORMAT
#define Call_CondiCheckFunc_S150_SET_DATE_FORMAT	CondiCheck_S150_SET_DATE_FORMAT
#define Call_UpdPortionFunc_S150_SET_DATE_FORMAT	UpdPorFunc_S150_SET_DATE_FORMAT
#define Call_UpdOrFlashFunc_S150_SET_DATE_FORMAT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S150_SET_DATE_FORMAT	CondiPreOcCheck_S150_SET_DATE_FORMAT
#define Call_HandlePreOCFunc_S150_SET_DATE_FORMAT	HandlePreOCFunc_S150_SET_DATE_FORMAT
#define Call_InitFunc_S150_SET_DATE_FORMAT_SET	IniOrClrScrFunc_S150_SET_DATE_FORMAT_SET
#define Call_CondiCheckFunc_S150_SET_DATE_FORMAT_SET ReturnTrue
#define Call_UpdPortionFunc_S150_SET_DATE_FORMAT_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S150_SET_DATE_FORMAT_SET	UpdOrFlasFunc_S150_SET_DATE_FORMAT_SET
#define Call_CondiCheckPreOCFunc_S150_SET_DATE_FORMAT_SET	ReturnFalse
#define Call_HandlePreOCFunc_S150_SET_DATE_FORMAT_SET	FuncDoNothing
#define Call_InitFunc_S152_SET_TIME_FORMAT	IniOrClrScrFunc_S152_SET_TIME_FORMAT
#define Call_CondiCheckFunc_S152_SET_TIME_FORMAT	CondiCheck_S152_SET_TIME_FORMAT
#define Call_UpdPortionFunc_S152_SET_TIME_FORMAT	UpdPorFunc_S152_SET_TIME_FORMAT
#define Call_UpdOrFlashFunc_S152_SET_TIME_FORMAT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S152_SET_TIME_FORMAT	CondiPreOcCheck_S152_SET_TIME_FORMAT
#define Call_HandlePreOCFunc_S152_SET_TIME_FORMAT	HandlePreOCFunc_S152_SET_TIME_FORMAT
#define Call_InitFunc_S152_SET_TIME_FORMAT_SET	IniOrClrScrFunc_S152_SET_TIME_FORMAT_SET
#define Call_CondiCheckFunc_S152_SET_TIME_FORMAT_SET ReturnTrue
#define Call_UpdPortionFunc_S152_SET_TIME_FORMAT_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S152_SET_TIME_FORMAT_SET	UpdOrFlasFunc_S152_SET_TIME_FORMAT_SET
#define Call_CondiCheckPreOCFunc_S152_SET_TIME_FORMAT_SET	ReturnFalse
#define Call_HandlePreOCFunc_S152_SET_TIME_FORMAT_SET	FuncDoNothing
#define Call_InitFunc_SETGASES_SET_CC_GASES	IniOrClrScrFunc_SETGASES_SET_CC_GASES
#define Call_CondiCheckFunc_SETGASES_SET_CC_GASES	CondiCheck_SETGASES_SET_CC_GASES
#define Call_UpdPortionFunc_SETGASES_SET_CC_GASES	UpdPorFunc_SETGASES_SET_CC_GASES
#define Call_UpdOrFlashFunc_SETGASES_SET_CC_GASES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SETGASES_SET_CC_GASES	CondiPreOcCheck_SETGASES_SET_CC_GASES
#define Call_HandlePreOCFunc_SETGASES_SET_CC_GASES	HandlePreOCFunc_SETGASES_SET_CC_GASES
#define Call_InitFunc_SETGASES_SET_BO_GASES	IniOrClrScrFunc_SETGASES_SET_BO_GASES
#define Call_CondiCheckFunc_SETGASES_SET_BO_GASES	CondiCheck_SETGASES_SET_BO_GASES
#define Call_UpdPortionFunc_SETGASES_SET_BO_GASES	UpdPorFunc_SETGASES_SET_BO_GASES
#define Call_UpdOrFlashFunc_SETGASES_SET_BO_GASES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SETGASES_SET_BO_GASES	CondiPreOcCheck_SETGASES_SET_BO_GASES
#define Call_HandlePreOCFunc_SETGASES_SET_BO_GASES	HandlePreOCFunc_SETGASES_SET_BO_GASES
#define Call_InitFunc_SETGASES_O2_ANALYZER	IniOrClrScrFunc_SETGASES_O2_ANALYZER
#define Call_CondiCheckFunc_SETGASES_O2_ANALYZER	CondiCheck_SETGASES_O2_ANALYZER
#define Call_UpdPortionFunc_SETGASES_O2_ANALYZER	UpdPorFunc_SETGASES_O2_ANALYZER
#define Call_UpdOrFlashFunc_SETGASES_O2_ANALYZER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SETGASES_O2_ANALYZER	CondiPreOcCheck_SETGASES_O2_ANALYZER
#define Call_HandlePreOCFunc_SETGASES_O2_ANALYZER	HandlePreOCFunc_SETGASES_O2_ANALYZER
#define Call_InitFunc_S70_SET_GAS_01	IniOrClrScrFunc_S70_SET_GAS_01
#define Call_CondiCheckFunc_S70_SET_GAS_01	CondiCheck_S70_SET_GAS_01
#define Call_UpdPortionFunc_S70_SET_GAS_01	UpdPorFunc_S70_SET_GAS_01
#define Call_UpdOrFlashFunc_S70_SET_GAS_01	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_01	CondiPreOcCheck_S70_SET_GAS_01
#define Call_HandlePreOCFunc_S70_SET_GAS_01	HandlePreOCFunc_S70_SET_GAS_01
#define Call_InitFunc_S70_SET_GAS_02	IniOrClrScrFunc_S70_SET_GAS_02
#define Call_CondiCheckFunc_S70_SET_GAS_02	CondiCheck_S70_SET_GAS_02
#define Call_UpdPortionFunc_S70_SET_GAS_02	UpdPorFunc_S70_SET_GAS_02
#define Call_UpdOrFlashFunc_S70_SET_GAS_02	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_02	CondiPreOcCheck_S70_SET_GAS_02
#define Call_HandlePreOCFunc_S70_SET_GAS_02	HandlePreOCFunc_S70_SET_GAS_02
#define Call_InitFunc_S70_SET_GAS_03	IniOrClrScrFunc_S70_SET_GAS_03
#define Call_CondiCheckFunc_S70_SET_GAS_03	CondiCheck_S70_SET_GAS_03
#define Call_UpdPortionFunc_S70_SET_GAS_03	UpdPorFunc_S70_SET_GAS_03
#define Call_UpdOrFlashFunc_S70_SET_GAS_03	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_03	CondiPreOcCheck_S70_SET_GAS_03
#define Call_HandlePreOCFunc_S70_SET_GAS_03	HandlePreOCFunc_S70_SET_GAS_03
#define Call_InitFunc_S70_SET_GAS_04	IniOrClrScrFunc_S70_SET_GAS_04
#define Call_CondiCheckFunc_S70_SET_GAS_04	CondiCheck_S70_SET_GAS_04
#define Call_UpdPortionFunc_S70_SET_GAS_04	UpdPorFunc_S70_SET_GAS_04
#define Call_UpdOrFlashFunc_S70_SET_GAS_04	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_04	CondiPreOcCheck_S70_SET_GAS_04
#define Call_HandlePreOCFunc_S70_SET_GAS_04	HandlePreOCFunc_S70_SET_GAS_04
#define Call_InitFunc_S70_SET_GAS_05	IniOrClrScrFunc_S70_SET_GAS_05
#define Call_CondiCheckFunc_S70_SET_GAS_05	CondiCheck_S70_SET_GAS_05
#define Call_UpdPortionFunc_S70_SET_GAS_05	UpdPorFunc_S70_SET_GAS_05
#define Call_UpdOrFlashFunc_S70_SET_GAS_05	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_05	CondiPreOcCheck_S70_SET_GAS_05
#define Call_HandlePreOCFunc_S70_SET_GAS_05	HandlePreOCFunc_S70_SET_GAS_05
#define Call_InitFunc_S70_SET_GAS_06	IniOrClrScrFunc_S70_SET_GAS_06
#define Call_CondiCheckFunc_S70_SET_GAS_06	CondiCheck_S70_SET_GAS_06
#define Call_UpdPortionFunc_S70_SET_GAS_06	UpdPorFunc_S70_SET_GAS_06
#define Call_UpdOrFlashFunc_S70_SET_GAS_06	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_SET_GAS_06	CondiPreOcCheck_S70_SET_GAS_06
#define Call_HandlePreOCFunc_S70_SET_GAS_06	HandlePreOCFunc_S70_SET_GAS_06
#define Call_InitFunc_S70_O2_ANALYZER	IniOrClrScrFunc_S70_O2_ANALYZER
#define Call_CondiCheckFunc_S70_O2_ANALYZER	CondiCheck_S70_O2_ANALYZER
#define Call_UpdPortionFunc_S70_O2_ANALYZER	UpdPorFunc_S70_O2_ANALYZER
#define Call_UpdOrFlashFunc_S70_O2_ANALYZER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S70_O2_ANALYZER	CondiPreOcCheck_S70_O2_ANALYZER
#define Call_HandlePreOCFunc_S70_O2_ANALYZER	HandlePreOCFunc_S70_O2_ANALYZER
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_01	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_01
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_01 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_01	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_01	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_01
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_01	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_01	FuncDoNothing
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_02	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_02
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_02 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_02	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_02	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_02
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_02	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_02	FuncDoNothing
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_03	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_03
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_03 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_03	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_03	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_03
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_03	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_03	FuncDoNothing
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_04	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_04
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_04 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_04	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_04	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_04
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_04	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_04	FuncDoNothing
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_05	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_05
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_05 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_05	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_05	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_05
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_05	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_05	FuncDoNothing
#define Call_InitFunc_S263_CHECKTMTLINKWITHGAS_06	IniOrClrScrFunc_S263_CHECKTMTLINKWITHGAS_06
#define Call_CondiCheckFunc_S263_CHECKTMTLINKWITHGAS_06 ReturnTrue
#define Call_UpdPortionFunc_S263_CHECKTMTLINKWITHGAS_06	FuncDoNothing
#define Call_UpdOrFlashFunc_S263_CHECKTMTLINKWITHGAS_06	UpdOrFlasFunc_S263_CHECKTMTLINKWITHGAS_06
#define Call_CondiCheckPreOCFunc_S263_CHECKTMTLINKWITHGAS_06	ReturnFalse
#define Call_HandlePreOCFunc_S263_CHECKTMTLINKWITHGAS_06	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_01	IniOrClrScrFunc_S71_SET_GAS_STAT_01
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_01 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_01	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_01	UpdOrFlasFunc_S71_SET_GAS_STAT_01
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_01	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_01	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_02	IniOrClrScrFunc_S71_SET_GAS_STAT_02
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_02 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_02	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_02	UpdOrFlasFunc_S71_SET_GAS_STAT_02
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_02	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_02	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_03	IniOrClrScrFunc_S71_SET_GAS_STAT_03
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_03 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_03	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_03	UpdOrFlasFunc_S71_SET_GAS_STAT_03
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_03	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_03	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_04	IniOrClrScrFunc_S71_SET_GAS_STAT_04
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_04 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_04	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_04	UpdOrFlasFunc_S71_SET_GAS_STAT_04
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_04	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_04	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_05	IniOrClrScrFunc_S71_SET_GAS_STAT_05
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_05 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_05	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_05	UpdOrFlasFunc_S71_SET_GAS_STAT_05
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_05	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_05	FuncDoNothing
#define Call_InitFunc_S71_SET_GAS_STAT_06	IniOrClrScrFunc_S71_SET_GAS_STAT_06
#define Call_CondiCheckFunc_S71_SET_GAS_STAT_06 ReturnTrue
#define Call_UpdPortionFunc_S71_SET_GAS_STAT_06	FuncDoNothing
#define Call_UpdOrFlashFunc_S71_SET_GAS_STAT_06	UpdOrFlasFunc_S71_SET_GAS_STAT_06
#define Call_CondiCheckPreOCFunc_S71_SET_GAS_STAT_06	ReturnFalse
#define Call_HandlePreOCFunc_S71_SET_GAS_STAT_06	FuncDoNothing
#define Call_InitFunc_S72_SET_GAS_FO2_01	IniOrClrScrFunc_S72_SET_GAS_FO2_01
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_01 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_01	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_01	UpdOrFlasFunc_S72_SET_GAS_FO2_01
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_01	CondiPreOcCheck_S72_SET_GAS_FO2_01
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_01	HandlePreOCFunc_S72_SET_GAS_FO2_01
#define Call_InitFunc_S72_SET_GAS_FO2_02	IniOrClrScrFunc_S72_SET_GAS_FO2_02
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_02 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_02	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_02	UpdOrFlasFunc_S72_SET_GAS_FO2_02
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_02	CondiPreOcCheck_S72_SET_GAS_FO2_02
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_02	HandlePreOCFunc_S72_SET_GAS_FO2_02
#define Call_InitFunc_S72_SET_GAS_FO2_03	IniOrClrScrFunc_S72_SET_GAS_FO2_03
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_03 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_03	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_03	UpdOrFlasFunc_S72_SET_GAS_FO2_03
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_03	CondiPreOcCheck_S72_SET_GAS_FO2_03
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_03	HandlePreOCFunc_S72_SET_GAS_FO2_03
#define Call_InitFunc_S72_SET_GAS_FO2_04	IniOrClrScrFunc_S72_SET_GAS_FO2_04
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_04 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_04	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_04	UpdOrFlasFunc_S72_SET_GAS_FO2_04
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_04	CondiPreOcCheck_S72_SET_GAS_FO2_04
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_04	HandlePreOCFunc_S72_SET_GAS_FO2_04
#define Call_InitFunc_S72_SET_GAS_FO2_05	IniOrClrScrFunc_S72_SET_GAS_FO2_05
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_05 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_05	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_05	UpdOrFlasFunc_S72_SET_GAS_FO2_05
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_05	CondiPreOcCheck_S72_SET_GAS_FO2_05
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_05	HandlePreOCFunc_S72_SET_GAS_FO2_05
#define Call_InitFunc_S72_SET_GAS_FO2_06	IniOrClrScrFunc_S72_SET_GAS_FO2_06
#define Call_CondiCheckFunc_S72_SET_GAS_FO2_06 ReturnTrue
#define Call_UpdPortionFunc_S72_SET_GAS_FO2_06	FuncDoNothing
#define Call_UpdOrFlashFunc_S72_SET_GAS_FO2_06	UpdOrFlasFunc_S72_SET_GAS_FO2_06
#define Call_CondiCheckPreOCFunc_S72_SET_GAS_FO2_06	CondiPreOcCheck_S72_SET_GAS_FO2_06
#define Call_HandlePreOCFunc_S72_SET_GAS_FO2_06	HandlePreOCFunc_S72_SET_GAS_FO2_06
#define Call_InitFunc_S73_SET_GAS_FHe_01	IniOrClrScrFunc_S73_SET_GAS_FHe_01
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_01	CondiCheck_S73_SET_GAS_FHe_01
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_01	UpdPorFunc_S73_SET_GAS_FHe_01
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_01	UpdOrFlasFunc_S73_SET_GAS_FHe_01
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_01	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_01	FuncDoNothing
#define Call_InitFunc_S73_SET_GAS_FHe_02	IniOrClrScrFunc_S73_SET_GAS_FHe_02
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_02	CondiCheck_S73_SET_GAS_FHe_02
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_02	UpdPorFunc_S73_SET_GAS_FHe_02
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_02	UpdOrFlasFunc_S73_SET_GAS_FHe_02
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_02	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_02	FuncDoNothing
#define Call_InitFunc_S73_SET_GAS_FHe_03	IniOrClrScrFunc_S73_SET_GAS_FHe_03
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_03	CondiCheck_S73_SET_GAS_FHe_03
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_03	UpdPorFunc_S73_SET_GAS_FHe_03
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_03	UpdOrFlasFunc_S73_SET_GAS_FHe_03
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_03	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_03	FuncDoNothing
#define Call_InitFunc_S73_SET_GAS_FHe_04	IniOrClrScrFunc_S73_SET_GAS_FHe_04
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_04	CondiCheck_S73_SET_GAS_FHe_04
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_04	UpdPorFunc_S73_SET_GAS_FHe_04
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_04	UpdOrFlasFunc_S73_SET_GAS_FHe_04
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_04	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_04	FuncDoNothing
#define Call_InitFunc_S73_SET_GAS_FHe_05	IniOrClrScrFunc_S73_SET_GAS_FHe_05
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_05	CondiCheck_S73_SET_GAS_FHe_05
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_05	UpdPorFunc_S73_SET_GAS_FHe_05
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_05	UpdOrFlasFunc_S73_SET_GAS_FHe_05
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_05	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_05	FuncDoNothing
#define Call_InitFunc_S73_SET_GAS_FHe_06	IniOrClrScrFunc_S73_SET_GAS_FHe_06
#define Call_CondiCheckFunc_S73_SET_GAS_FHe_06	CondiCheck_S73_SET_GAS_FHe_06
#define Call_UpdPortionFunc_S73_SET_GAS_FHe_06	UpdPorFunc_S73_SET_GAS_FHe_06
#define Call_UpdOrFlashFunc_S73_SET_GAS_FHe_06	UpdOrFlasFunc_S73_SET_GAS_FHe_06
#define Call_CondiCheckPreOCFunc_S73_SET_GAS_FHe_06	ReturnFalse
#define Call_HandlePreOCFunc_S73_SET_GAS_FHe_06	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_01	IniOrClrScrFunc_S74_SET_GAS_TMT_01
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_01 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_01	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_01	UpdOrFlasFunc_S74_SET_GAS_TMT_01
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_01	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_01	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_02	IniOrClrScrFunc_S74_SET_GAS_TMT_02
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_02 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_02	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_02	UpdOrFlasFunc_S74_SET_GAS_TMT_02
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_02	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_02	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_03	IniOrClrScrFunc_S74_SET_GAS_TMT_03
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_03 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_03	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_03	UpdOrFlasFunc_S74_SET_GAS_TMT_03
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_03	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_03	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_04	IniOrClrScrFunc_S74_SET_GAS_TMT_04
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_04 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_04	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_04	UpdOrFlasFunc_S74_SET_GAS_TMT_04
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_04	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_04	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_05	IniOrClrScrFunc_S74_SET_GAS_TMT_05
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_05 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_05	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_05	UpdOrFlasFunc_S74_SET_GAS_TMT_05
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_05	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_05	FuncDoNothing
#define Call_InitFunc_S74_SET_GAS_TMT_06	IniOrClrScrFunc_S74_SET_GAS_TMT_06
#define Call_CondiCheckFunc_S74_SET_GAS_TMT_06 ReturnTrue
#define Call_UpdPortionFunc_S74_SET_GAS_TMT_06	FuncDoNothing
#define Call_UpdOrFlashFunc_S74_SET_GAS_TMT_06	UpdOrFlasFunc_S74_SET_GAS_TMT_06
#define Call_CondiCheckPreOCFunc_S74_SET_GAS_TMT_06	ReturnFalse
#define Call_HandlePreOCFunc_S74_SET_GAS_TMT_06	FuncDoNothing
#define Call_InitFunc_S75_SET_GAS_TMT_WARNING	IniOrClrScrFunc_S75_SET_GAS_TMT_WARNING
#define Call_CondiCheckFunc_S75_SET_GAS_TMT_WARNING ReturnTrue
#define Call_UpdPortionFunc_S75_SET_GAS_TMT_WARNING	FuncDoNothing
#define Call_UpdOrFlashFunc_S75_SET_GAS_TMT_WARNING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S75_SET_GAS_TMT_WARNING	ReturnFalse
#define Call_HandlePreOCFunc_S75_SET_GAS_TMT_WARNING	FuncDoNothing
#define Call_InitFunc_S79_SET_GAS_FHE_WARNING	IniOrClrScrFunc_S79_SET_GAS_FHE_WARNING
#define Call_CondiCheckFunc_S79_SET_GAS_FHE_WARNING ReturnTrue
#define Call_UpdPortionFunc_S79_SET_GAS_FHE_WARNING	FuncDoNothing
#define Call_UpdOrFlashFunc_S79_SET_GAS_FHE_WARNING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S79_SET_GAS_FHE_WARNING	ReturnFalse
#define Call_HandlePreOCFunc_S79_SET_GAS_FHE_WARNING	FuncDoNothing
#define Call_InitFunc_TMTSWITCH_TMT_SET	IniOrClrScrFunc_TMTSWITCH_TMT_SET
#define Call_CondiCheckFunc_TMTSWITCH_TMT_SET ReturnTrue
#define Call_UpdPortionFunc_TMTSWITCH_TMT_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMTSWITCH_TMT_SET	UpdOrFlasFunc_TMTSWITCH_TMT_SET
#define Call_CondiCheckPreOCFunc_TMTSWITCH_TMT_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMTSWITCH_TMT_SET	FuncDoNothing
#define Call_InitFunc_S462_O2ANALYZER_CALIBRATE	IniOrClrScrFunc_S462_O2ANALYZER_CALIBRATE
#define Call_CondiCheckFunc_S462_O2ANALYZER_CALIBRATE	CondiCheck_S462_O2ANALYZER_CALIBRATE
#define Call_UpdPortionFunc_S462_O2ANALYZER_CALIBRATE	UpdPorFunc_S462_O2ANALYZER_CALIBRATE
#define Call_UpdOrFlashFunc_S462_O2ANALYZER_CALIBRATE	UpdOrFlasFunc_S462_O2ANALYZER_CALIBRATE
#define Call_CondiCheckPreOCFunc_S462_O2ANALYZER_CALIBRATE	CondiPreOcCheck_S462_O2ANALYZER_CALIBRATE
#define Call_HandlePreOCFunc_S462_O2ANALYZER_CALIBRATE	HandlePreOCFunc_S462_O2ANALYZER_CALIBRATE
#define Call_InitFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS	IniOrClrScrFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS
#define Call_CondiCheckFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS ReturnTrue
#define Call_UpdPortionFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS	FuncDoNothing
#define Call_UpdOrFlashFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS	UpdOrFlasFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS
#define Call_CondiCheckPreOCFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS	ReturnFalse
#define Call_HandlePreOCFunc_S463_O2ANALYZER_CALIBRATE_SET_GAS	FuncDoNothing
#define Call_InitFunc_S464_O2ANALYZER_CALIBRATE_READY	IniOrClrScrFunc_S464_O2ANALYZER_CALIBRATE_READY
#define Call_CondiCheckFunc_S464_O2ANALYZER_CALIBRATE_READY ReturnTrue
#define Call_UpdPortionFunc_S464_O2ANALYZER_CALIBRATE_READY	FuncDoNothing
#define Call_UpdOrFlashFunc_S464_O2ANALYZER_CALIBRATE_READY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S464_O2ANALYZER_CALIBRATE_READY	ReturnFalse
#define Call_HandlePreOCFunc_S464_O2ANALYZER_CALIBRATE_READY	FuncDoNothing
#define Call_InitFunc_S465_O2ANALYZER_CALIBRATE_READ_O2	IniOrClrScrFunc_S465_O2ANALYZER_CALIBRATE_READ_O2
#define Call_CondiCheckFunc_S465_O2ANALYZER_CALIBRATE_READ_O2 ReturnTrue
#define Call_UpdPortionFunc_S465_O2ANALYZER_CALIBRATE_READ_O2	FuncDoNothing
#define Call_UpdOrFlashFunc_S465_O2ANALYZER_CALIBRATE_READ_O2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S465_O2ANALYZER_CALIBRATE_READ_O2	ReturnFalse
#define Call_HandlePreOCFunc_S465_O2ANALYZER_CALIBRATE_READ_O2	FuncDoNothing
#define Call_InitFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2	IniOrClrScrFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2
#define Call_CondiCheckFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2 ReturnTrue
#define Call_UpdPortionFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2	FuncDoNothing
#define Call_UpdOrFlashFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2	ReturnFalse
#define Call_HandlePreOCFunc_S466_O2ANALYZER_CALIBRATE_NO_CELL_O2	FuncDoNothing
#define Call_InitFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER	IniOrClrScrFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER
#define Call_CondiCheckFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER ReturnTrue
#define Call_UpdPortionFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER	FuncDoNothing
#define Call_UpdOrFlashFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER	ReturnFalse
#define Call_HandlePreOCFunc_S466A_O2ANALYZER_CALIBRATE_NO_O2_ANALYZER	FuncDoNothing
#define Call_InitFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP	IniOrClrScrFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP
#define Call_CondiCheckFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP ReturnTrue
#define Call_UpdPortionFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP	FuncDoNothing
#define Call_UpdOrFlashFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP	UpdOrFlasFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP
#define Call_CondiCheckPreOCFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP	ReturnFalse
#define Call_HandlePreOCFunc_S467_O2ANALYZER_CALIBRATE_CELL_O2_DEP	FuncDoNothing
#define Call_InitFunc_S468_O2ANALYZER_CALIBRATE_CELL_V	IniOrClrScrFunc_S468_O2ANALYZER_CALIBRATE_CELL_V
#define Call_CondiCheckFunc_S468_O2ANALYZER_CALIBRATE_CELL_V ReturnTrue
#define Call_UpdPortionFunc_S468_O2ANALYZER_CALIBRATE_CELL_V	FuncDoNothing
#define Call_UpdOrFlashFunc_S468_O2ANALYZER_CALIBRATE_CELL_V	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S468_O2ANALYZER_CALIBRATE_CELL_V	ReturnFalse
#define Call_HandlePreOCFunc_S468_O2ANALYZER_CALIBRATE_CELL_V	FuncDoNothing
#define Call_InitFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE	IniOrClrScrFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE
#define Call_CondiCheckFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE ReturnTrue
#define Call_UpdPortionFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE	FuncDoNothing
#define Call_UpdOrFlashFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE	ReturnFalse
#define Call_HandlePreOCFunc_S469_O2ANALYZER_CALIBRATE_COMPLETE	FuncDoNothing
#define Call_InitFunc_S470_O2ANALYZER_ANALYZE	IniOrClrScrFunc_S470_O2ANALYZER_ANALYZE
#define Call_CondiCheckFunc_S470_O2ANALYZER_ANALYZE	CondiCheck_S470_O2ANALYZER_ANALYZE
#define Call_UpdPortionFunc_S470_O2ANALYZER_ANALYZE	UpdPorFunc_S470_O2ANALYZER_ANALYZE
#define Call_UpdOrFlashFunc_S470_O2ANALYZER_ANALYZE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S470_O2ANALYZER_ANALYZE	CondiPreOcCheck_S470_O2ANALYZER_ANALYZE
#define Call_HandlePreOCFunc_S470_O2ANALYZER_ANALYZE	HandlePreOCFunc_S470_O2ANALYZER_ANALYZE
#define Call_InitFunc_S471_ANALYZE_CALIB_WARINING	IniOrClrScrFunc_S471_ANALYZE_CALIB_WARINING
#define Call_CondiCheckFunc_S471_ANALYZE_CALIB_WARINING ReturnTrue
#define Call_UpdPortionFunc_S471_ANALYZE_CALIB_WARINING	FuncDoNothing
#define Call_UpdOrFlashFunc_S471_ANALYZE_CALIB_WARINING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S471_ANALYZE_CALIB_WARINING	ReturnFalse
#define Call_HandlePreOCFunc_S471_ANALYZE_CALIB_WARINING	FuncDoNothing
#define Call_InitFunc_S472_ANALYZE_READY	IniOrClrScrFunc_S472_ANALYZE_READY
#define Call_CondiCheckFunc_S472_ANALYZE_READY ReturnTrue
#define Call_UpdPortionFunc_S472_ANALYZE_READY	FuncDoNothing
#define Call_UpdOrFlashFunc_S472_ANALYZE_READY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S472_ANALYZE_READY	ReturnFalse
#define Call_HandlePreOCFunc_S472_ANALYZE_READY	FuncDoNothing
#define Call_InitFunc_S473_ANALYZE_ANALYZING	IniOrClrScrFunc_S473_ANALYZE_ANALYZING
#define Call_CondiCheckFunc_S473_ANALYZE_ANALYZING ReturnTrue
#define Call_UpdPortionFunc_S473_ANALYZE_ANALYZING	FuncDoNothing
#define Call_UpdOrFlashFunc_S473_ANALYZE_ANALYZING	UpdOrFlasFunc_S473_ANALYZE_ANALYZING
#define Call_CondiCheckPreOCFunc_S473_ANALYZE_ANALYZING	ReturnFalse
#define Call_HandlePreOCFunc_S473_ANALYZE_ANALYZING	FuncDoNothing
#define Call_InitFunc_S474_ANALYZE_CONFIRM	IniOrClrScrFunc_S474_ANALYZE_CONFIRM
#define Call_CondiCheckFunc_S474_ANALYZE_CONFIRM ReturnTrue
#define Call_UpdPortionFunc_S474_ANALYZE_CONFIRM	FuncDoNothing
#define Call_UpdOrFlashFunc_S474_ANALYZE_CONFIRM	UpdOrFlasFunc_S474_ANALYZE_CONFIRM
#define Call_CondiCheckPreOCFunc_S474_ANALYZE_CONFIRM	ReturnFalse
#define Call_HandlePreOCFunc_S474_ANALYZE_CONFIRM	FuncDoNothing
#define Call_InitFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM	IniOrClrScrFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM
#define Call_CondiCheckFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM ReturnTrue
#define Call_UpdPortionFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM	FuncDoNothing
#define Call_UpdOrFlashFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM	UpdOrFlasFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM
#define Call_CondiCheckPreOCFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM	ReturnFalse
#define Call_HandlePreOCFunc_S475_ANALYZE_ASSIGN_FO2_CONFIRM	FuncDoNothing
#define Call_InitFunc_S475A_ANALYZE_SET_FHE	IniOrClrScrFunc_S475A_ANALYZE_SET_FHE
#define Call_CondiCheckFunc_S475A_ANALYZE_SET_FHE ReturnTrue
#define Call_UpdPortionFunc_S475A_ANALYZE_SET_FHE	FuncDoNothing
#define Call_UpdOrFlashFunc_S475A_ANALYZE_SET_FHE	UpdOrFlasFunc_S475A_ANALYZE_SET_FHE
#define Call_CondiCheckPreOCFunc_S475A_ANALYZE_SET_FHE	ReturnFalse
#define Call_HandlePreOCFunc_S475A_ANALYZE_SET_FHE	FuncDoNothing
#define Call_InitFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE	IniOrClrScrFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE
#define Call_CondiCheckFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE ReturnTrue
#define Call_UpdPortionFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE	FuncDoNothing
#define Call_UpdOrFlashFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE	UpdOrFlasFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE
#define Call_CondiCheckPreOCFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE	ReturnFalse
#define Call_HandlePreOCFunc_S476_ANALYZE_SELECT_GAS_LIST_MODE	FuncDoNothing
#define Call_InitFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN	IniOrClrScrFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN
#define Call_CondiCheckFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN ReturnTrue
#define Call_UpdPortionFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN	FuncDoNothing
#define Call_UpdOrFlashFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN	UpdOrFlasFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN
#define Call_CondiCheckPreOCFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN	ReturnFalse
#define Call_HandlePreOCFunc_S477_ANALYZE_SELECT_GAS_TO_ASSIGN	FuncDoNothing
#define Call_InitFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS	IniOrClrScrFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS
#define Call_CondiCheckFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS ReturnTrue
#define Call_UpdPortionFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS	FuncDoNothing
#define Call_UpdOrFlashFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS	UpdOrFlasFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS
#define Call_CondiCheckPreOCFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS	ReturnFalse
#define Call_HandlePreOCFunc_S478_ANALYZE_CONFIRM_ASSIGN_TO_GAS	FuncDoNothing
#define Call_InitFunc_S479_ANALYZE_ASSIGN_COMPLETE	IniOrClrScrFunc_S479_ANALYZE_ASSIGN_COMPLETE
#define Call_CondiCheckFunc_S479_ANALYZE_ASSIGN_COMPLETE ReturnTrue
#define Call_UpdPortionFunc_S479_ANALYZE_ASSIGN_COMPLETE	FuncDoNothing
#define Call_UpdOrFlashFunc_S479_ANALYZE_ASSIGN_COMPLETE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S479_ANALYZE_ASSIGN_COMPLETE	ReturnFalse
#define Call_HandlePreOCFunc_S479_ANALYZE_ASSIGN_COMPLETE	FuncDoNothing
#define Call_InitFunc_S486_ANALYZE_SET_BOTH_OCL_OCR	IniOrClrScrFunc_S486_ANALYZE_SET_BOTH_OCL_OCR
#define Call_CondiCheckFunc_S486_ANALYZE_SET_BOTH_OCL_OCR ReturnTrue
#define Call_UpdPortionFunc_S486_ANALYZE_SET_BOTH_OCL_OCR	FuncDoNothing
#define Call_UpdOrFlashFunc_S486_ANALYZE_SET_BOTH_OCL_OCR	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S486_ANALYZE_SET_BOTH_OCL_OCR	ReturnFalse
#define Call_HandlePreOCFunc_S486_ANALYZE_SET_BOTH_OCL_OCR	FuncDoNothing
#define Call_InitFunc_S54_SP_HIGH_SP	IniOrClrScrFunc_S54_SP_HIGH_SP
#define Call_CondiCheckFunc_S54_SP_HIGH_SP	CondiCheck_S54_SP_HIGH_SP
#define Call_UpdPortionFunc_S54_SP_HIGH_SP	UpdPorFunc_S54_SP_HIGH_SP
#define Call_UpdOrFlashFunc_S54_SP_HIGH_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S54_SP_HIGH_SP	CondiPreOcCheck_S54_SP_HIGH_SP
#define Call_HandlePreOCFunc_S54_SP_HIGH_SP	HandlePreOCFunc_S54_SP_HIGH_SP
#define Call_InitFunc_S54_SP_LOW_SP	IniOrClrScrFunc_S54_SP_LOW_SP
#define Call_CondiCheckFunc_S54_SP_LOW_SP	CondiCheck_S54_SP_LOW_SP
#define Call_UpdPortionFunc_S54_SP_LOW_SP	UpdPorFunc_S54_SP_LOW_SP
#define Call_UpdOrFlashFunc_S54_SP_LOW_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S54_SP_LOW_SP	CondiPreOcCheck_S54_SP_LOW_SP
#define Call_HandlePreOCFunc_S54_SP_LOW_SP	HandlePreOCFunc_S54_SP_LOW_SP
#define Call_InitFunc_S56_SP_CUSTOM_SP	IniOrClrScrFunc_S56_SP_CUSTOM_SP
#define Call_CondiCheckFunc_S56_SP_CUSTOM_SP	CondiCheck_S56_SP_CUSTOM_SP
#define Call_UpdPortionFunc_S56_SP_CUSTOM_SP	UpdPorFunc_S56_SP_CUSTOM_SP
#define Call_UpdOrFlashFunc_S56_SP_CUSTOM_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S56_SP_CUSTOM_SP	CondiPreOcCheck_S56_SP_CUSTOM_SP
#define Call_HandlePreOCFunc_S56_SP_CUSTOM_SP	HandlePreOCFunc_S56_SP_CUSTOM_SP
#define Call_InitFunc_S59_SP_AUTO_HIGH	IniOrClrScrFunc_S59_SP_AUTO_HIGH
#define Call_CondiCheckFunc_S59_SP_AUTO_HIGH	CondiCheck_S59_SP_AUTO_HIGH
#define Call_UpdPortionFunc_S59_SP_AUTO_HIGH	UpdPorFunc_S59_SP_AUTO_HIGH
#define Call_UpdOrFlashFunc_S59_SP_AUTO_HIGH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S59_SP_AUTO_HIGH	CondiPreOcCheck_S59_SP_AUTO_HIGH
#define Call_HandlePreOCFunc_S59_SP_AUTO_HIGH	HandlePreOCFunc_S59_SP_AUTO_HIGH
#define Call_InitFunc_S59_SP_AUTO_LOW	IniOrClrScrFunc_S59_SP_AUTO_LOW
#define Call_CondiCheckFunc_S59_SP_AUTO_LOW	CondiCheck_S59_SP_AUTO_LOW
#define Call_UpdPortionFunc_S59_SP_AUTO_LOW	UpdPorFunc_S59_SP_AUTO_LOW
#define Call_UpdOrFlashFunc_S59_SP_AUTO_LOW	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S59_SP_AUTO_LOW	CondiPreOcCheck_S59_SP_AUTO_LOW
#define Call_HandlePreOCFunc_S59_SP_AUTO_LOW	HandlePreOCFunc_S59_SP_AUTO_LOW
#define Call_InitFunc_SP_HIGH_SP_SET	IniOrClrScrFunc_SP_HIGH_SP_SET
#define Call_CondiCheckFunc_SP_HIGH_SP_SET ReturnTrue
#define Call_UpdPortionFunc_SP_HIGH_SP_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_HIGH_SP_SET	UpdOrFlasFunc_SP_HIGH_SP_SET
#define Call_CondiCheckPreOCFunc_SP_HIGH_SP_SET	ReturnFalse
#define Call_HandlePreOCFunc_SP_HIGH_SP_SET	FuncDoNothing
#define Call_InitFunc_SP_LOW_SP_SET	IniOrClrScrFunc_SP_LOW_SP_SET
#define Call_CondiCheckFunc_SP_LOW_SP_SET ReturnTrue
#define Call_UpdPortionFunc_SP_LOW_SP_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_LOW_SP_SET	UpdOrFlasFunc_SP_LOW_SP_SET
#define Call_CondiCheckPreOCFunc_SP_LOW_SP_SET	ReturnFalse
#define Call_HandlePreOCFunc_SP_LOW_SP_SET	FuncDoNothing
#define Call_InitFunc_SP_CUSTOM_SP_STAT	IniOrClrScrFunc_SP_CUSTOM_SP_STAT
#define Call_CondiCheckFunc_SP_CUSTOM_SP_STAT ReturnTrue
#define Call_UpdPortionFunc_SP_CUSTOM_SP_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_CUSTOM_SP_STAT	UpdOrFlasFunc_SP_CUSTOM_SP_STAT
#define Call_CondiCheckPreOCFunc_SP_CUSTOM_SP_STAT	ReturnFalse
#define Call_HandlePreOCFunc_SP_CUSTOM_SP_STAT	FuncDoNothing
#define Call_InitFunc_SP_CUSTOM_SP_SET	IniOrClrScrFunc_SP_CUSTOM_SP_SET
#define Call_CondiCheckFunc_SP_CUSTOM_SP_SET ReturnTrue
#define Call_UpdPortionFunc_SP_CUSTOM_SP_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_CUSTOM_SP_SET	UpdOrFlasFunc_SP_CUSTOM_SP_SET
#define Call_CondiCheckPreOCFunc_SP_CUSTOM_SP_SET	ReturnFalse
#define Call_HandlePreOCFunc_SP_CUSTOM_SP_SET	FuncDoNothing
#define Call_InitFunc_SP_AUTO_HIGH_STAT	IniOrClrScrFunc_SP_AUTO_HIGH_STAT
#define Call_CondiCheckFunc_SP_AUTO_HIGH_STAT ReturnTrue
#define Call_UpdPortionFunc_SP_AUTO_HIGH_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_AUTO_HIGH_STAT	UpdOrFlasFunc_SP_AUTO_HIGH_STAT
#define Call_CondiCheckPreOCFunc_SP_AUTO_HIGH_STAT	ReturnFalse
#define Call_HandlePreOCFunc_SP_AUTO_HIGH_STAT	FuncDoNothing
#define Call_InitFunc_SP_AUTO_HIGH_SET	IniOrClrScrFunc_SP_AUTO_HIGH_SET
#define Call_CondiCheckFunc_SP_AUTO_HIGH_SET ReturnTrue
#define Call_UpdPortionFunc_SP_AUTO_HIGH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_AUTO_HIGH_SET	UpdOrFlasFunc_SP_AUTO_HIGH_SET
#define Call_CondiCheckPreOCFunc_SP_AUTO_HIGH_SET	ReturnFalse
#define Call_HandlePreOCFunc_SP_AUTO_HIGH_SET	FuncDoNothing
#define Call_InitFunc_SP_AUTO_LOW_STAT	IniOrClrScrFunc_SP_AUTO_LOW_STAT
#define Call_CondiCheckFunc_SP_AUTO_LOW_STAT ReturnTrue
#define Call_UpdPortionFunc_SP_AUTO_LOW_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_AUTO_LOW_STAT	UpdOrFlasFunc_SP_AUTO_LOW_STAT
#define Call_CondiCheckPreOCFunc_SP_AUTO_LOW_STAT	ReturnFalse
#define Call_HandlePreOCFunc_SP_AUTO_LOW_STAT	FuncDoNothing
#define Call_InitFunc_SP_AUTO_LOW_SET	IniOrClrScrFunc_SP_AUTO_LOW_SET
#define Call_CondiCheckFunc_SP_AUTO_LOW_SET ReturnTrue
#define Call_UpdPortionFunc_SP_AUTO_LOW_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_SP_AUTO_LOW_SET	UpdOrFlasFunc_SP_AUTO_LOW_SET
#define Call_CondiCheckPreOCFunc_SP_AUTO_LOW_SET	ReturnFalse
#define Call_HandlePreOCFunc_SP_AUTO_LOW_SET	FuncDoNothing
#define Call_InitFunc_S99_SET_DIVEMODE	IniOrClrScrFunc_S99_SET_DIVEMODE
#define Call_CondiCheckFunc_S99_SET_DIVEMODE	CondiCheck_S99_SET_DIVEMODE
#define Call_UpdPortionFunc_S99_SET_DIVEMODE	UpdPorFunc_S99_SET_DIVEMODE
#define Call_UpdOrFlashFunc_S99_SET_DIVEMODE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S99_SET_DIVEMODE	CondiPreOcCheck_S99_SET_DIVEMODE
#define Call_HandlePreOCFunc_S99_SET_DIVEMODE	HandlePreOCFunc_S99_SET_DIVEMODE
#define Call_InitFunc_S76_SET_BAILOUTPO2LIMITS	IniOrClrScrFunc_S76_SET_BAILOUTPO2LIMITS
#define Call_CondiCheckFunc_S76_SET_BAILOUTPO2LIMITS	CondiCheck_S76_SET_BAILOUTPO2LIMITS
#define Call_UpdPortionFunc_S76_SET_BAILOUTPO2LIMITS	UpdPorFunc_S76_SET_BAILOUTPO2LIMITS
#define Call_UpdOrFlashFunc_S76_SET_BAILOUTPO2LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S76_SET_BAILOUTPO2LIMITS	CondiPreOcCheck_S76_SET_BAILOUTPO2LIMITS
#define Call_HandlePreOCFunc_S76_SET_BAILOUTPO2LIMITS	HandlePreOCFunc_S76_SET_BAILOUTPO2LIMITS
#define Call_InitFunc_S83_SET_CONSERVATISM	IniOrClrScrFunc_S83_SET_CONSERVATISM
#define Call_CondiCheckFunc_S83_SET_CONSERVATISM	CondiCheck_S83_SET_CONSERVATISM
#define Call_UpdPortionFunc_S83_SET_CONSERVATISM	UpdPorFunc_S83_SET_CONSERVATISM
#define Call_UpdOrFlashFunc_S83_SET_CONSERVATISM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S83_SET_CONSERVATISM	CondiPreOcCheck_S83_SET_CONSERVATISM
#define Call_HandlePreOCFunc_S83_SET_CONSERVATISM	HandlePreOCFunc_S83_SET_CONSERVATISM
#define Call_InitFunc_S91_SET_SAFETYSTOP	IniOrClrScrFunc_S91_SET_SAFETYSTOP
#define Call_CondiCheckFunc_S91_SET_SAFETYSTOP	CondiCheck_S91_SET_SAFETYSTOP
#define Call_UpdPortionFunc_S91_SET_SAFETYSTOP	UpdPorFunc_S91_SET_SAFETYSTOP
#define Call_UpdOrFlashFunc_S91_SET_SAFETYSTOP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S91_SET_SAFETYSTOP	CondiPreOcCheck_S91_SET_SAFETYSTOP
#define Call_HandlePreOCFunc_S91_SET_SAFETYSTOP	HandlePreOCFunc_S91_SET_SAFETYSTOP
#define Call_InitFunc_S96_SET_LASTSTOPDEPTH	IniOrClrScrFunc_S96_SET_LASTSTOPDEPTH
#define Call_CondiCheckFunc_S96_SET_LASTSTOPDEPTH	CondiCheck_S96_SET_LASTSTOPDEPTH
#define Call_UpdPortionFunc_S96_SET_LASTSTOPDEPTH	UpdPorFunc_S96_SET_LASTSTOPDEPTH
#define Call_UpdOrFlashFunc_S96_SET_LASTSTOPDEPTH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S96_SET_LASTSTOPDEPTH	CondiPreOcCheck_S96_SET_LASTSTOPDEPTH
#define Call_HandlePreOCFunc_S96_SET_LASTSTOPDEPTH	HandlePreOCFunc_S96_SET_LASTSTOPDEPTH
#define Call_InitFunc_DIVEMODE_SETPOINTS	IniOrClrScrFunc_DIVEMODE_SETPOINTS
#define Call_CondiCheckFunc_DIVEMODE_SETPOINTS ReturnTrue
#define Call_UpdPortionFunc_DIVEMODE_SETPOINTS	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMODE_SETPOINTS	UpdOrFlasFunc_DIVEMODE_SETPOINTS
#define Call_CondiCheckPreOCFunc_DIVEMODE_SETPOINTS	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMODE_SETPOINTS	FuncDoNothing
#define Call_InitFunc_SET_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_CondiCheckFunc_SET_BAILOUT_PO2_LIMITS ReturnFalse
#define Call_UpdPortionFunc_SET_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SET_BAILOUT_PO2_LIMITS	ReturnFalse
#define Call_HandlePreOCFunc_SET_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_InitFunc_SET_CONSERVATISM	FuncDoNothing
#define Call_CondiCheckFunc_SET_CONSERVATISM ReturnFalse
#define Call_UpdPortionFunc_SET_CONSERVATISM	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_CONSERVATISM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SET_CONSERVATISM	ReturnFalse
#define Call_HandlePreOCFunc_SET_CONSERVATISM	FuncDoNothing
#define Call_InitFunc_SET_SAFETYSTOP_STAT	IniOrClrScrFunc_SET_SAFETYSTOP_STAT
#define Call_CondiCheckFunc_SET_SAFETYSTOP_STAT ReturnTrue
#define Call_UpdPortionFunc_SET_SAFETYSTOP_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_SAFETYSTOP_STAT	UpdOrFlasFunc_SET_SAFETYSTOP_STAT
#define Call_CondiCheckPreOCFunc_SET_SAFETYSTOP_STAT	ReturnFalse
#define Call_HandlePreOCFunc_SET_SAFETYSTOP_STAT	FuncDoNothing
#define Call_InitFunc_SET_SAFETYSTOP_DEPTHT	IniOrClrScrFunc_SET_SAFETYSTOP_DEPTHT
#define Call_CondiCheckFunc_SET_SAFETYSTOP_DEPTHT ReturnTrue
#define Call_UpdPortionFunc_SET_SAFETYSTOP_DEPTHT	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_SAFETYSTOP_DEPTHT	UpdOrFlasFunc_SET_SAFETYSTOP_DEPTHT
#define Call_CondiCheckPreOCFunc_SET_SAFETYSTOP_DEPTHT	CondiPreOcCheck_SET_SAFETYSTOP_DEPTHT
#define Call_HandlePreOCFunc_SET_SAFETYSTOP_DEPTHT	HandlePreOCFunc_SET_SAFETYSTOP_DEPTHT
#define Call_InitFunc_SET_SAFETYSTOP_TIME	FuncDoNothing
#define Call_CondiCheckFunc_SET_SAFETYSTOP_TIME ReturnFalse
#define Call_UpdPortionFunc_SET_SAFETYSTOP_TIME	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_SAFETYSTOP_TIME	UpdOrFlasFunc_SET_SAFETYSTOP_TIME
#define Call_CondiCheckPreOCFunc_SET_SAFETYSTOP_TIME	ReturnFalse
#define Call_HandlePreOCFunc_SET_SAFETYSTOP_TIME	FuncDoNothing
#define Call_InitFunc_LASTSTOPDEPTH_SETPOINTS	IniOrClrScrFunc_LASTSTOPDEPTH_SETPOINTS
#define Call_CondiCheckFunc_LASTSTOPDEPTH_SETPOINTS ReturnTrue
#define Call_UpdPortionFunc_LASTSTOPDEPTH_SETPOINTS	FuncDoNothing
#define Call_UpdOrFlashFunc_LASTSTOPDEPTH_SETPOINTS	UpdOrFlasFunc_LASTSTOPDEPTH_SETPOINTS
#define Call_CondiCheckPreOCFunc_LASTSTOPDEPTH_SETPOINTS	ReturnFalse
#define Call_HandlePreOCFunc_LASTSTOPDEPTH_SETPOINTS	FuncDoNothing
#define Call_InitFunc_S106_AL_AUDIBLE	IniOrClrScrFunc_S106_AL_AUDIBLE
#define Call_CondiCheckFunc_S106_AL_AUDIBLE	CondiCheck_S106_AL_AUDIBLE
#define Call_UpdPortionFunc_S106_AL_AUDIBLE	UpdPorFunc_S106_AL_AUDIBLE
#define Call_UpdOrFlashFunc_S106_AL_AUDIBLE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S106_AL_AUDIBLE	CondiPreOcCheck_S106_AL_AUDIBLE
#define Call_HandlePreOCFunc_S106_AL_AUDIBLE	HandlePreOCFunc_S106_AL_AUDIBLE
#define Call_InitFunc_S108_AL_DEPTH	IniOrClrScrFunc_S108_AL_DEPTH
#define Call_CondiCheckFunc_S108_AL_DEPTH	CondiCheck_S108_AL_DEPTH
#define Call_UpdPortionFunc_S108_AL_DEPTH	UpdPorFunc_S108_AL_DEPTH
#define Call_UpdOrFlashFunc_S108_AL_DEPTH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S108_AL_DEPTH	CondiPreOcCheck_S108_AL_DEPTH
#define Call_HandlePreOCFunc_S108_AL_DEPTH	HandlePreOCFunc_S108_AL_DEPTH
#define Call_InitFunc_S111_AL_DIVETIME	IniOrClrScrFunc_S111_AL_DIVETIME
#define Call_CondiCheckFunc_S111_AL_DIVETIME	CondiCheck_S111_AL_DIVETIME
#define Call_UpdPortionFunc_S111_AL_DIVETIME	UpdPorFunc_S111_AL_DIVETIME
#define Call_UpdOrFlashFunc_S111_AL_DIVETIME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S111_AL_DIVETIME	CondiPreOcCheck_S111_AL_DIVETIME
#define Call_HandlePreOCFunc_S111_AL_DIVETIME	HandlePreOCFunc_S111_AL_DIVETIME
#define Call_InitFunc_S116_AL_DTR	IniOrClrScrFunc_S116_AL_DTR
#define Call_CondiCheckFunc_S116_AL_DTR	CondiCheck_S116_AL_DTR
#define Call_UpdPortionFunc_S116_AL_DTR	UpdPorFunc_S116_AL_DTR
#define Call_UpdOrFlashFunc_S116_AL_DTR	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S116_AL_DTR	CondiPreOcCheck_S116_AL_DTR
#define Call_HandlePreOCFunc_S116_AL_DTR	HandlePreOCFunc_S116_AL_DTR
#define Call_InitFunc_S116_AL_TANK_PRESS	IniOrClrScrFunc_S116_AL_TANK_PRESS
#define Call_CondiCheckFunc_S116_AL_TANK_PRESS	CondiCheck_S116_AL_TANK_PRESS
#define Call_UpdPortionFunc_S116_AL_TANK_PRESS	UpdPorFunc_S116_AL_TANK_PRESS
#define Call_UpdOrFlashFunc_S116_AL_TANK_PRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S116_AL_TANK_PRESS	CondiPreOcCheck_S116_AL_TANK_PRESS
#define Call_HandlePreOCFunc_S116_AL_TANK_PRESS	HandlePreOCFunc_S116_AL_TANK_PRESS
#define Call_InitFunc_S119_AL_CC6_PRESS	IniOrClrScrFunc_S119_AL_CC6_PRESS
#define Call_CondiCheckFunc_S119_AL_CC6_PRESS	CondiCheck_S119_AL_CC6_PRESS
#define Call_UpdPortionFunc_S119_AL_CC6_PRESS	UpdPorFunc_S119_AL_CC6_PRESS
#define Call_UpdOrFlashFunc_S119_AL_CC6_PRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S119_AL_CC6_PRESS	CondiPreOcCheck_S119_AL_CC6_PRESS
#define Call_HandlePreOCFunc_S119_AL_CC6_PRESS	HandlePreOCFunc_S119_AL_CC6_PRESS
#define Call_InitFunc_S122_AL_GF_N2	IniOrClrScrFunc_S122_AL_GF_N2
#define Call_CondiCheckFunc_S122_AL_GF_N2	CondiCheck_S122_AL_GF_N2
#define Call_UpdPortionFunc_S122_AL_GF_N2	UpdPorFunc_S122_AL_GF_N2
#define Call_UpdOrFlashFunc_S122_AL_GF_N2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S122_AL_GF_N2	CondiPreOcCheck_S122_AL_GF_N2
#define Call_HandlePreOCFunc_S122_AL_GF_N2	HandlePreOCFunc_S122_AL_GF_N2
#define Call_InitFunc_S281_AL_TURN_END_PRESS	IniOrClrScrFunc_S281_AL_TURN_END_PRESS
#define Call_CondiCheckFunc_S281_AL_TURN_END_PRESS	CondiCheck_S281_AL_TURN_END_PRESS
#define Call_UpdPortionFunc_S281_AL_TURN_END_PRESS	UpdPorFunc_S281_AL_TURN_END_PRESS
#define Call_UpdOrFlashFunc_S281_AL_TURN_END_PRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S281_AL_TURN_END_PRESS	CondiPreOcCheck_S281_AL_TURN_END_PRESS
#define Call_HandlePreOCFunc_S281_AL_TURN_END_PRESS	HandlePreOCFunc_S281_AL_TURN_END_PRESS
#define Call_InitFunc_S288_AL_END_WOB_ICD_ALARMS	IniOrClrScrFunc_S288_AL_END_WOB_ICD_ALARMS
#define Call_CondiCheckFunc_S288_AL_END_WOB_ICD_ALARMS	CondiCheck_S288_AL_END_WOB_ICD_ALARMS
#define Call_UpdPortionFunc_S288_AL_END_WOB_ICD_ALARMS	UpdPorFunc_S288_AL_END_WOB_ICD_ALARMS
#define Call_UpdOrFlashFunc_S288_AL_END_WOB_ICD_ALARMS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S288_AL_END_WOB_ICD_ALARMS	CondiPreOcCheck_S288_AL_END_WOB_ICD_ALARMS
#define Call_HandlePreOCFunc_S288_AL_END_WOB_ICD_ALARMS	HandlePreOCFunc_S288_AL_END_WOB_ICD_ALARMS
#define Call_InitFunc_S000_AL_DIVETIME_TTS	IniOrClrScrFunc_S000_AL_DIVETIME_TTS
#define Call_CondiCheckFunc_S000_AL_DIVETIME_TTS	CondiCheck_S000_AL_DIVETIME_TTS
#define Call_UpdPortionFunc_S000_AL_DIVETIME_TTS	UpdPorFunc_S000_AL_DIVETIME_TTS
#define Call_UpdOrFlashFunc_S000_AL_DIVETIME_TTS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S000_AL_DIVETIME_TTS	CondiPreOcCheck_S000_AL_DIVETIME_TTS
#define Call_HandlePreOCFunc_S000_AL_DIVETIME_TTS	HandlePreOCFunc_S000_AL_DIVETIME_TTS
#define Call_InitFunc_S128_DEVICE_TRANSMITTERS	IniOrClrScrFunc_S128_DEVICE_TRANSMITTERS
#define Call_CondiCheckFunc_S128_DEVICE_TRANSMITTERS	CondiCheck_S128_DEVICE_TRANSMITTERS
#define Call_UpdPortionFunc_S128_DEVICE_TRANSMITTERS	UpdPorFunc_S128_DEVICE_TRANSMITTERS
#define Call_UpdOrFlashFunc_S128_DEVICE_TRANSMITTERS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S128_DEVICE_TRANSMITTERS	CondiPreOcCheck_S128_DEVICE_TRANSMITTERS
#define Call_HandlePreOCFunc_S128_DEVICE_TRANSMITTERS	HandlePreOCFunc_S128_DEVICE_TRANSMITTERS
#define Call_InitFunc_S137_DEVICE_UNITS	IniOrClrScrFunc_S137_DEVICE_UNITS
#define Call_CondiCheckFunc_S137_DEVICE_UNITS	CondiCheck_S137_DEVICE_UNITS
#define Call_UpdPortionFunc_S137_DEVICE_UNITS	UpdPorFunc_S137_DEVICE_UNITS
#define Call_UpdOrFlashFunc_S137_DEVICE_UNITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S137_DEVICE_UNITS	CondiPreOcCheck_S137_DEVICE_UNITS
#define Call_HandlePreOCFunc_S137_DEVICE_UNITS	HandlePreOCFunc_S137_DEVICE_UNITS
#define Call_InitFunc_S139_DEVICE_WATERTYPE	IniOrClrScrFunc_S139_DEVICE_WATERTYPE
#define Call_CondiCheckFunc_S139_DEVICE_WATERTYPE	CondiCheck_S139_DEVICE_WATERTYPE
#define Call_UpdPortionFunc_S139_DEVICE_WATERTYPE	UpdPorFunc_S139_DEVICE_WATERTYPE
#define Call_UpdOrFlashFunc_S139_DEVICE_WATERTYPE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S139_DEVICE_WATERTYPE	CondiPreOcCheck_S139_DEVICE_WATERTYPE
#define Call_HandlePreOCFunc_S139_DEVICE_WATERTYPE	HandlePreOCFunc_S139_DEVICE_WATERTYPE
#define Call_InitFunc_S141_DEVICE_SAMPLERATE	IniOrClrScrFunc_S141_DEVICE_SAMPLERATE
#define Call_CondiCheckFunc_S141_DEVICE_SAMPLERATE	CondiCheck_S141_DEVICE_SAMPLERATE
#define Call_UpdPortionFunc_S141_DEVICE_SAMPLERATE	UpdPorFunc_S141_DEVICE_SAMPLERATE
#define Call_UpdOrFlashFunc_S141_DEVICE_SAMPLERATE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S141_DEVICE_SAMPLERATE	CondiPreOcCheck_S141_DEVICE_SAMPLERATE
#define Call_HandlePreOCFunc_S141_DEVICE_SAMPLERATE	HandlePreOCFunc_S141_DEVICE_SAMPLERATE
#define Call_InitFunc_S143_DEVICE_BLUETOOTH	IniOrClrScrFunc_S143_DEVICE_BLUETOOTH
#define Call_CondiCheckFunc_S143_DEVICE_BLUETOOTH	CondiCheck_S143_DEVICE_BLUETOOTH
#define Call_UpdPortionFunc_S143_DEVICE_BLUETOOTH	UpdPorFunc_S143_DEVICE_BLUETOOTH
#define Call_UpdOrFlashFunc_S143_DEVICE_BLUETOOTH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S143_DEVICE_BLUETOOTH	CondiPreOcCheck_S143_DEVICE_BLUETOOTH
#define Call_HandlePreOCFunc_S143_DEVICE_BLUETOOTH	HandlePreOCFunc_S143_DEVICE_BLUETOOTH
#define Call_InitFunc_TBD_DEVICE_RESETSETTINGS	IniOrClrScrFunc_TBD_DEVICE_RESETSETTINGS
#define Call_CondiCheckFunc_TBD_DEVICE_RESETSETTINGS	CondiCheck_TBD_DEVICE_RESETSETTINGS
#define Call_UpdPortionFunc_TBD_DEVICE_RESETSETTINGS	UpdPorFunc_TBD_DEVICE_RESETSETTINGS
#define Call_UpdOrFlashFunc_TBD_DEVICE_RESETSETTINGS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_TBD_DEVICE_RESETSETTINGS	CondiPreOcCheck_TBD_DEVICE_RESETSETTINGS
#define Call_HandlePreOCFunc_TBD_DEVICE_RESETSETTINGS	HandlePreOCFunc_TBD_DEVICE_RESETSETTINGS
#define Call_InitFunc_TBD_DEVICE_WELCOMESCREEN	IniOrClrScrFunc_TBD_DEVICE_WELCOMESCREEN
#define Call_CondiCheckFunc_TBD_DEVICE_WELCOMESCREEN	CondiCheck_TBD_DEVICE_WELCOMESCREEN
#define Call_UpdPortionFunc_TBD_DEVICE_WELCOMESCREEN	UpdPorFunc_TBD_DEVICE_WELCOMESCREEN
#define Call_UpdOrFlashFunc_TBD_DEVICE_WELCOMESCREEN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_TBD_DEVICE_WELCOMESCREEN	CondiPreOcCheck_TBD_DEVICE_WELCOMESCREEN
#define Call_HandlePreOCFunc_TBD_DEVICE_WELCOMESCREEN	HandlePreOCFunc_TBD_DEVICE_WELCOMESCREEN
#define Call_InitFunc_DEVICE_UNITS_SET	IniOrClrScrFunc_DEVICE_UNITS_SET
#define Call_CondiCheckFunc_DEVICE_UNITS_SET ReturnTrue
#define Call_UpdPortionFunc_DEVICE_UNITS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_UNITS_SET	UpdOrFlasFunc_DEVICE_UNITS_SET
#define Call_CondiCheckPreOCFunc_DEVICE_UNITS_SET	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_UNITS_SET	FuncDoNothing
#define Call_InitFunc_DEVICE_WATERTYPE_SET	IniOrClrScrFunc_DEVICE_WATERTYPE_SET
#define Call_CondiCheckFunc_DEVICE_WATERTYPE_SET ReturnTrue
#define Call_UpdPortionFunc_DEVICE_WATERTYPE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_WATERTYPE_SET	UpdOrFlasFunc_DEVICE_WATERTYPE_SET
#define Call_CondiCheckPreOCFunc_DEVICE_WATERTYPE_SET	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_WATERTYPE_SET	FuncDoNothing
#define Call_InitFunc_DEVICE_SAMPLERATE_SET	IniOrClrScrFunc_DEVICE_SAMPLERATE_SET
#define Call_CondiCheckFunc_DEVICE_SAMPLERATE_SET ReturnTrue
#define Call_UpdPortionFunc_DEVICE_SAMPLERATE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_SAMPLERATE_SET	UpdOrFlasFunc_DEVICE_SAMPLERATE_SET
#define Call_CondiCheckPreOCFunc_DEVICE_SAMPLERATE_SET	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_SAMPLERATE_SET	FuncDoNothing
#define Call_InitFunc_DEVICE_BLUETOOTH_SET	IniOrClrScrFunc_DEVICE_BLUETOOTH_SET
#define Call_CondiCheckFunc_DEVICE_BLUETOOTH_SET ReturnTrue
#define Call_UpdPortionFunc_DEVICE_BLUETOOTH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_BLUETOOTH_SET	UpdOrFlasFunc_DEVICE_BLUETOOTH_SET
#define Call_CondiCheckPreOCFunc_DEVICE_BLUETOOTH_SET	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_BLUETOOTH_SET	FuncDoNothing
#define Call_InitFunc_DEVICE_BLUETOOTH_PASSCODE	IniOrClrScrFunc_DEVICE_BLUETOOTH_PASSCODE
#define Call_CondiCheckFunc_DEVICE_BLUETOOTH_PASSCODE ReturnTrue
#define Call_UpdPortionFunc_DEVICE_BLUETOOTH_PASSCODE	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_BLUETOOTH_PASSCODE	UpdOrFlasFunc_DEVICE_BLUETOOTH_PASSCODE
#define Call_CondiCheckPreOCFunc_DEVICE_BLUETOOTH_PASSCODE	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_BLUETOOTH_PASSCODE	FuncDoNothing
#define Call_InitFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA	IniOrClrScrFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA
#define Call_CondiCheckFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA ReturnTrue
#define Call_UpdPortionFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA	FuncDoNothing
#define Call_UpdOrFlashFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA	UpdOrFlasFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA
#define Call_CondiCheckPreOCFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA	ReturnFalse
#define Call_HandlePreOCFunc_DEVICE_BLUETOOTH_DOWNLOAD_DATA	FuncDoNothing
#define Call_InitFunc_RESETSETTINGS_S1	IniOrClrScrFunc_RESETSETTINGS_S1
#define Call_CondiCheckFunc_RESETSETTINGS_S1 ReturnTrue
#define Call_UpdPortionFunc_RESETSETTINGS_S1	FuncDoNothing
#define Call_UpdOrFlashFunc_RESETSETTINGS_S1	FuncDoNothing
#define Call_CondiCheckPreOCFunc_RESETSETTINGS_S1	ReturnFalse
#define Call_HandlePreOCFunc_RESETSETTINGS_S1	FuncDoNothing
#define Call_InitFunc_RESETSETTINGS_S2	IniOrClrScrFunc_RESETSETTINGS_S2
#define Call_CondiCheckFunc_RESETSETTINGS_S2 ReturnTrue
#define Call_UpdPortionFunc_RESETSETTINGS_S2	FuncDoNothing
#define Call_UpdOrFlashFunc_RESETSETTINGS_S2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_RESETSETTINGS_S2	ReturnFalse
#define Call_HandlePreOCFunc_RESETSETTINGS_S2	FuncDoNothing
#define Call_InitFunc_WELCOMESCREEN_SET	IniOrClrScrFunc_WELCOMESCREEN_SET
#define Call_CondiCheckFunc_WELCOMESCREEN_SET ReturnTrue
#define Call_UpdPortionFunc_WELCOMESCREEN_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_WELCOMESCREEN_SET	UpdOrFlasFunc_WELCOMESCREEN_SET
#define Call_CondiCheckPreOCFunc_WELCOMESCREEN_SET	ReturnFalse
#define Call_HandlePreOCFunc_WELCOMESCREEN_SET	FuncDoNothing
#define Call_InitFunc_S162_DISPLAY_BRIGHTNESS	IniOrClrScrFunc_S162_DISPLAY_BRIGHTNESS
#define Call_CondiCheckFunc_S162_DISPLAY_BRIGHTNESS	CondiCheck_S162_DISPLAY_BRIGHTNESS
#define Call_UpdPortionFunc_S162_DISPLAY_BRIGHTNESS	UpdPorFunc_S162_DISPLAY_BRIGHTNESS
#define Call_UpdOrFlashFunc_S162_DISPLAY_BRIGHTNESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S162_DISPLAY_BRIGHTNESS	CondiPreOcCheck_S162_DISPLAY_BRIGHTNESS
#define Call_HandlePreOCFunc_S162_DISPLAY_BRIGHTNESS	HandlePreOCFunc_S162_DISPLAY_BRIGHTNESS
#define Call_InitFunc_S164_DISPLAY_AUTODIM	IniOrClrScrFunc_S164_DISPLAY_AUTODIM
#define Call_CondiCheckFunc_S164_DISPLAY_AUTODIM	CondiCheck_S164_DISPLAY_AUTODIM
#define Call_UpdPortionFunc_S164_DISPLAY_AUTODIM	UpdPorFunc_S164_DISPLAY_AUTODIM
#define Call_UpdOrFlashFunc_S164_DISPLAY_AUTODIM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S164_DISPLAY_AUTODIM	CondiPreOcCheck_S164_DISPLAY_AUTODIM
#define Call_HandlePreOCFunc_S164_DISPLAY_AUTODIM	HandlePreOCFunc_S164_DISPLAY_AUTODIM
#define Call_InitFunc_S173_DISPLAY_TITLESCOLOR	IniOrClrScrFunc_S173_DISPLAY_TITLESCOLOR
#define Call_CondiCheckFunc_S173_DISPLAY_TITLESCOLOR	CondiCheck_S173_DISPLAY_TITLESCOLOR
#define Call_UpdPortionFunc_S173_DISPLAY_TITLESCOLOR	UpdPorFunc_S173_DISPLAY_TITLESCOLOR
#define Call_UpdOrFlashFunc_S173_DISPLAY_TITLESCOLOR	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S173_DISPLAY_TITLESCOLOR	CondiPreOcCheck_S173_DISPLAY_TITLESCOLOR
#define Call_HandlePreOCFunc_S173_DISPLAY_TITLESCOLOR	HandlePreOCFunc_S173_DISPLAY_TITLESCOLOR
#define Call_InitFunc_S179_DISPLAY_LANGUAGE	IniOrClrScrFunc_S179_DISPLAY_LANGUAGE
#define Call_CondiCheckFunc_S179_DISPLAY_LANGUAGE	CondiCheck_S179_DISPLAY_LANGUAGE
#define Call_UpdPortionFunc_S179_DISPLAY_LANGUAGE	UpdPorFunc_S179_DISPLAY_LANGUAGE
#define Call_UpdOrFlashFunc_S179_DISPLAY_LANGUAGE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S179_DISPLAY_LANGUAGE	CondiPreOcCheck_S179_DISPLAY_LANGUAGE
#define Call_HandlePreOCFunc_S179_DISPLAY_LANGUAGE	HandlePreOCFunc_S179_DISPLAY_LANGUAGE
#define Call_InitFunc_S178_DISPLAY_FLIPSCREEN	IniOrClrScrFunc_S178_DISPLAY_FLIPSCREEN
#define Call_CondiCheckFunc_S178_DISPLAY_FLIPSCREEN	CondiCheck_S178_DISPLAY_FLIPSCREEN
#define Call_UpdPortionFunc_S178_DISPLAY_FLIPSCREEN	UpdPorFunc_S178_DISPLAY_FLIPSCREEN
#define Call_UpdOrFlashFunc_S178_DISPLAY_FLIPSCREEN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S178_DISPLAY_FLIPSCREEN	CondiPreOcCheck_S178_DISPLAY_FLIPSCREEN
#define Call_HandlePreOCFunc_S178_DISPLAY_FLIPSCREEN	HandlePreOCFunc_S178_DISPLAY_FLIPSCREEN
#define Call_InitFunc_S166_DISPLAY_MAINDISPLAY	IniOrClrScrFunc_S166_DISPLAY_MAINDISPLAY
#define Call_CondiCheckFunc_S166_DISPLAY_MAINDISPLAY	CondiCheck_S166_DISPLAY_MAINDISPLAY
#define Call_UpdPortionFunc_S166_DISPLAY_MAINDISPLAY	UpdPorFunc_S166_DISPLAY_MAINDISPLAY
#define Call_UpdOrFlashFunc_S166_DISPLAY_MAINDISPLAY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S166_DISPLAY_MAINDISPLAY	CondiPreOcCheck_S166_DISPLAY_MAINDISPLAY
#define Call_HandlePreOCFunc_S166_DISPLAY_MAINDISPLAY	HandlePreOCFunc_S166_DISPLAY_MAINDISPLAY
#define Call_InitFunc_S372_DISPLAY_GTR	IniOrClrScrFunc_S372_DISPLAY_GTR
#define Call_CondiCheckFunc_S372_DISPLAY_GTR	CondiCheck_S372_DISPLAY_GTR
#define Call_UpdPortionFunc_S372_DISPLAY_GTR	UpdPorFunc_S372_DISPLAY_GTR
#define Call_UpdOrFlashFunc_S372_DISPLAY_GTR	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S372_DISPLAY_GTR	CondiPreOcCheck_S372_DISPLAY_GTR
#define Call_HandlePreOCFunc_S372_DISPLAY_GTR	HandlePreOCFunc_S372_DISPLAY_GTR
#define Call_InitFunc_S428_DISPLAY_EXTRALARGE	IniOrClrScrFunc_S428_DISPLAY_EXTRALARGE
#define Call_CondiCheckFunc_S428_DISPLAY_EXTRALARGE	CondiCheck_S428_DISPLAY_EXTRALARGE
#define Call_UpdPortionFunc_S428_DISPLAY_EXTRALARGE	UpdPorFunc_S428_DISPLAY_EXTRALARGE
#define Call_UpdOrFlashFunc_S428_DISPLAY_EXTRALARGE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S428_DISPLAY_EXTRALARGE	CondiPreOcCheck_S428_DISPLAY_EXTRALARGE
#define Call_HandlePreOCFunc_S428_DISPLAY_EXTRALARGE	HandlePreOCFunc_S428_DISPLAY_EXTRALARGE
#define Call_InitFunc_DISPLAY_BRIGHTNESS_SET	IniOrClrScrFunc_DISPLAY_BRIGHTNESS_SET
#define Call_CondiCheckFunc_DISPLAY_BRIGHTNESS_SET ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_BRIGHTNESS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_BRIGHTNESS_SET	UpdOrFlasFunc_DISPLAY_BRIGHTNESS_SET
#define Call_CondiCheckPreOCFunc_DISPLAY_BRIGHTNESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_BRIGHTNESS_SET	FuncDoNothing
#define Call_InitFunc_DISPLAY_TITLESCOLOR_SET	IniOrClrScrFunc_DISPLAY_TITLESCOLOR_SET
#define Call_CondiCheckFunc_DISPLAY_TITLESCOLOR_SET ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_TITLESCOLOR_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_TITLESCOLOR_SET	UpdOrFlasFunc_DISPLAY_TITLESCOLOR_SET
#define Call_CondiCheckPreOCFunc_DISPLAY_TITLESCOLOR_SET	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_TITLESCOLOR_SET	FuncDoNothing
#define Call_InitFunc_DISPLAY_LANGUAGE_SET	IniOrClrScrFunc_DISPLAY_LANGUAGE_SET
#define Call_CondiCheckFunc_DISPLAY_LANGUAGE_SET ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_LANGUAGE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_LANGUAGE_SET	UpdOrFlasFunc_DISPLAY_LANGUAGE_SET
#define Call_CondiCheckPreOCFunc_DISPLAY_LANGUAGE_SET	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_LANGUAGE_SET	FuncDoNothing
#define Call_InitFunc_DISPLAY_FLIPSCREEN_SET	IniOrClrScrFunc_DISPLAY_FLIPSCREEN_SET
#define Call_CondiCheckFunc_DISPLAY_FLIPSCREEN_SET ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_FLIPSCREEN_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_FLIPSCREEN_SET	UpdOrFlasFunc_DISPLAY_FLIPSCREEN_SET
#define Call_CondiCheckPreOCFunc_DISPLAY_FLIPSCREEN_SET	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_FLIPSCREEN_SET	FuncDoNothing
#define Call_InitFunc_S373_DISPLAY_GTR_SET	IniOrClrScrFunc_S373_DISPLAY_GTR_SET
#define Call_CondiCheckFunc_S373_DISPLAY_GTR_SET ReturnTrue
#define Call_UpdPortionFunc_S373_DISPLAY_GTR_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S373_DISPLAY_GTR_SET	UpdOrFlasFunc_S373_DISPLAY_GTR_SET
#define Call_CondiCheckPreOCFunc_S373_DISPLAY_GTR_SET	ReturnFalse
#define Call_HandlePreOCFunc_S373_DISPLAY_GTR_SET	FuncDoNothing
#define Call_InitFunc_S428_DISPLAY_EXTRALARGE_SET	IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE_SET /*Re-map*/
#define Call_CondiCheckFunc_S428_DISPLAY_EXTRALARGE_SET ReturnTrue
#define Call_UpdPortionFunc_S428_DISPLAY_EXTRALARGE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S428_DISPLAY_EXTRALARGE_SET	UpdOrFlasFunc_MAINDISPLAY_EXTRALARGE_SET /*Re-map*/
#define Call_CondiCheckPreOCFunc_S428_DISPLAY_EXTRALARGE_SET	ReturnFalse
#define Call_HandlePreOCFunc_S428_DISPLAY_EXTRALARGE_SET	FuncDoNothing
#define Call_InitFunc_DISPLAY_AUTODIM_ITEM	FuncDoNothing
#define Call_CondiCheckFunc_DISPLAY_AUTODIM_ITEM ReturnFalse
#define Call_UpdPortionFunc_DISPLAY_AUTODIM_ITEM	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_AUTODIM_ITEM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DISPLAY_AUTODIM_ITEM	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_AUTODIM_ITEM	FuncDoNothing
#define Call_InitFunc_DISPLAY_AUTODIM__STAT	IniOrClrScrFunc_DISPLAY_AUTODIM__STAT
#define Call_CondiCheckFunc_DISPLAY_AUTODIM__STAT ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_AUTODIM__STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_AUTODIM__STAT	UpdOrFlasFunc_DISPLAY_AUTODIM__STAT
#define Call_CondiCheckPreOCFunc_DISPLAY_AUTODIM__STAT	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_AUTODIM__STAT	FuncDoNothing
#define Call_InitFunc_DISPLAY_AUTODIM__TIME	IniOrClrScrFunc_DISPLAY_AUTODIM__TIME
#define Call_CondiCheckFunc_DISPLAY_AUTODIM__TIME ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_AUTODIM__TIME	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_AUTODIM__TIME	UpdOrFlasFunc_DISPLAY_AUTODIM__TIME
#define Call_CondiCheckPreOCFunc_DISPLAY_AUTODIM__TIME	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_AUTODIM__TIME	FuncDoNothing
#define Call_InitFunc_DISPLAY_AUTODIM__PERCENT	IniOrClrScrFunc_DISPLAY_AUTODIM__PERCENT
#define Call_CondiCheckFunc_DISPLAY_AUTODIM__PERCENT ReturnTrue
#define Call_UpdPortionFunc_DISPLAY_AUTODIM__PERCENT	FuncDoNothing
#define Call_UpdOrFlashFunc_DISPLAY_AUTODIM__PERCENT	UpdOrFlasFunc_DISPLAY_AUTODIM__PERCENT
#define Call_CondiCheckPreOCFunc_DISPLAY_AUTODIM__PERCENT	ReturnFalse
#define Call_HandlePreOCFunc_DISPLAY_AUTODIM__PERCENT	FuncDoNothing
#define Call_InitFunc_MAINDISPLAY_LEFT	IniOrClrScrFunc_MAINDISPLAY_LEFT
#define Call_CondiCheckFunc_MAINDISPLAY_LEFT	CondiCheck_MAINDISPLAY_LEFT
#define Call_UpdPortionFunc_MAINDISPLAY_LEFT	UpdPorFunc_MAINDISPLAY_LEFT
#define Call_UpdOrFlashFunc_MAINDISPLAY_LEFT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_LEFT	CondiPreOcCheck_MAINDISPLAY_LEFT
#define Call_HandlePreOCFunc_MAINDISPLAY_LEFT	HandlePreOCFunc_MAINDISPLAY_LEFT
#define Call_InitFunc_MAINDISPLAY_LEFT_SET	IniOrClrScrFunc_MAINDISPLAY_LEFT_SET
#define Call_CondiCheckFunc_MAINDISPLAY_LEFT_SET ReturnTrue
#define Call_UpdPortionFunc_MAINDISPLAY_LEFT_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_MAINDISPLAY_LEFT_SET	UpdOrFlasFunc_MAINDISPLAY_LEFT_SET
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_LEFT_SET	ReturnFalse
#define Call_HandlePreOCFunc_MAINDISPLAY_LEFT_SET	FuncDoNothing
#define Call_InitFunc_MAINDISPLAY_RIGHT	IniOrClrScrFunc_MAINDISPLAY_RIGHT
#define Call_CondiCheckFunc_MAINDISPLAY_RIGHT	CondiCheck_MAINDISPLAY_RIGHT
#define Call_UpdPortionFunc_MAINDISPLAY_RIGHT	UpdPorFunc_MAINDISPLAY_RIGHT
#define Call_UpdOrFlashFunc_MAINDISPLAY_RIGHT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_RIGHT	CondiPreOcCheck_MAINDISPLAY_RIGHT
#define Call_HandlePreOCFunc_MAINDISPLAY_RIGHT	HandlePreOCFunc_MAINDISPLAY_RIGHT
#define Call_InitFunc_MAINDISPLAY_RIGHT_SET	IniOrClrScrFunc_MAINDISPLAY_RIGHT_SET
#define Call_CondiCheckFunc_MAINDISPLAY_RIGHT_SET ReturnTrue
#define Call_UpdPortionFunc_MAINDISPLAY_RIGHT_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_MAINDISPLAY_RIGHT_SET	UpdOrFlasFunc_MAINDISPLAY_RIGHT_SET
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_RIGHT_SET	ReturnFalse
#define Call_HandlePreOCFunc_MAINDISPLAY_RIGHT_SET	FuncDoNothing
#define Call_InitFunc_MAINDISPLAY_GFBG	IniOrClrScrFunc_MAINDISPLAY_GFBG
#define Call_CondiCheckFunc_MAINDISPLAY_GFBG	CondiCheck_MAINDISPLAY_GFBG
#define Call_UpdPortionFunc_MAINDISPLAY_GFBG	UpdPorFunc_MAINDISPLAY_GFBG
#define Call_UpdOrFlashFunc_MAINDISPLAY_GFBG	FuncDoNothing
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_GFBG	CondiPreOcCheck_MAINDISPLAY_GFBG
#define Call_HandlePreOCFunc_MAINDISPLAY_GFBG	HandlePreOCFunc_MAINDISPLAY_GFBG
#define Call_InitFunc_MAINDISPLAY_GFBG_SET	IniOrClrScrFunc_MAINDISPLAY_GFBG_SET
#define Call_CondiCheckFunc_MAINDISPLAY_GFBG_SET ReturnTrue
#define Call_UpdPortionFunc_MAINDISPLAY_GFBG_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_MAINDISPLAY_GFBG_SET	UpdOrFlasFunc_MAINDISPLAY_GFBG_SET
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_GFBG_SET	ReturnFalse
#define Call_HandlePreOCFunc_MAINDISPLAY_GFBG_SET	FuncDoNothing
#define Call_InitFunc_MAINDISPLAY_EXTRALARGE	IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE
#define Call_CondiCheckFunc_MAINDISPLAY_EXTRALARGE	CondiCheck_MAINDISPLAY_EXTRALARGE
#define Call_UpdPortionFunc_MAINDISPLAY_EXTRALARGE	UpdPorFunc_MAINDISPLAY_EXTRALARGE
#define Call_UpdOrFlashFunc_MAINDISPLAY_EXTRALARGE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_EXTRALARGE	CondiPreOcCheck_MAINDISPLAY_EXTRALARGE
#define Call_HandlePreOCFunc_MAINDISPLAY_EXTRALARGE	HandlePreOCFunc_MAINDISPLAY_EXTRALARGE
#define Call_InitFunc_MAINDISPLAY_EXTRALARGE_SET	IniOrClrScrFunc_MAINDISPLAY_EXTRALARGE_SET
#define Call_CondiCheckFunc_MAINDISPLAY_EXTRALARGE_SET ReturnTrue
#define Call_UpdPortionFunc_MAINDISPLAY_EXTRALARGE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_MAINDISPLAY_EXTRALARGE_SET	UpdOrFlasFunc_MAINDISPLAY_EXTRALARGE_SET
#define Call_CondiCheckPreOCFunc_MAINDISPLAY_EXTRALARGE_SET	ReturnFalse
#define Call_HandlePreOCFunc_MAINDISPLAY_EXTRALARGE_SET	FuncDoNothing
#define Call_InitFunc_S128_TM_TMT1	IniOrClrScrFunc_S128_TM_TMT1
#define Call_CondiCheckFunc_S128_TM_TMT1	CondiCheck_S128_TM_TMT1
#define Call_UpdPortionFunc_S128_TM_TMT1	UpdPorFunc_S128_TM_TMT1
#define Call_UpdOrFlashFunc_S128_TM_TMT1	UpdOrFlasFunc_S128_TM_TMT1
#define Call_CondiCheckPreOCFunc_S128_TM_TMT1	CondiPreOcCheck_S128_TM_TMT1
#define Call_HandlePreOCFunc_S128_TM_TMT1	HandlePreOCFunc_S128_TM_TMT1
#define Call_InitFunc_S128_TM_TMT2	IniOrClrScrFunc_S128_TM_TMT2
#define Call_CondiCheckFunc_S128_TM_TMT2	CondiCheck_S128_TM_TMT2
#define Call_UpdPortionFunc_S128_TM_TMT2	UpdPorFunc_S128_TM_TMT2
#define Call_UpdOrFlashFunc_S128_TM_TMT2	UpdOrFlasFunc_S128_TM_TMT2
#define Call_CondiCheckPreOCFunc_S128_TM_TMT2	CondiPreOcCheck_S128_TM_TMT2
#define Call_HandlePreOCFunc_S128_TM_TMT2	HandlePreOCFunc_S128_TM_TMT2
#define Call_InitFunc_S128_TM_TMT3	IniOrClrScrFunc_S128_TM_TMT3
#define Call_CondiCheckFunc_S128_TM_TMT3	CondiCheck_S128_TM_TMT3
#define Call_UpdPortionFunc_S128_TM_TMT3	UpdPorFunc_S128_TM_TMT3
#define Call_UpdOrFlashFunc_S128_TM_TMT3	UpdOrFlasFunc_S128_TM_TMT3
#define Call_CondiCheckPreOCFunc_S128_TM_TMT3	CondiPreOcCheck_S128_TM_TMT3
#define Call_HandlePreOCFunc_S128_TM_TMT3	HandlePreOCFunc_S128_TM_TMT3
#define Call_InitFunc_S128_TM_TMT4	IniOrClrScrFunc_S128_TM_TMT4
#define Call_CondiCheckFunc_S128_TM_TMT4	CondiCheck_S128_TM_TMT4
#define Call_UpdPortionFunc_S128_TM_TMT4	UpdPorFunc_S128_TM_TMT4
#define Call_UpdOrFlashFunc_S128_TM_TMT4	UpdOrFlasFunc_S128_TM_TMT4
#define Call_CondiCheckPreOCFunc_S128_TM_TMT4	CondiPreOcCheck_S128_TM_TMT4
#define Call_HandlePreOCFunc_S128_TM_TMT4	HandlePreOCFunc_S128_TM_TMT4
#define Call_InitFunc_S128_TM_TMT5	IniOrClrScrFunc_S128_TM_TMT5
#define Call_CondiCheckFunc_S128_TM_TMT5	CondiCheck_S128_TM_TMT5
#define Call_UpdPortionFunc_S128_TM_TMT5	UpdPorFunc_S128_TM_TMT5
#define Call_UpdOrFlashFunc_S128_TM_TMT5	UpdOrFlasFunc_S128_TM_TMT5
#define Call_CondiCheckPreOCFunc_S128_TM_TMT5	CondiPreOcCheck_S128_TM_TMT5
#define Call_HandlePreOCFunc_S128_TM_TMT5	HandlePreOCFunc_S128_TM_TMT5
#define Call_InitFunc_S128_TM_TMT6	IniOrClrScrFunc_S128_TM_TMT6
#define Call_CondiCheckFunc_S128_TM_TMT6	CondiCheck_S128_TM_TMT6
#define Call_UpdPortionFunc_S128_TM_TMT6	UpdPorFunc_S128_TM_TMT6
#define Call_UpdOrFlashFunc_S128_TM_TMT6	UpdOrFlasFunc_S128_TM_TMT6
#define Call_CondiCheckPreOCFunc_S128_TM_TMT6	CondiPreOcCheck_S128_TM_TMT6
#define Call_HandlePreOCFunc_S128_TM_TMT6	HandlePreOCFunc_S128_TM_TMT6
#define Call_InitFunc_TMT_1_SET	IniOrClrScrFunc_TMT_1_SET
#define Call_CondiCheckFunc_TMT_1_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_1_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_1_SET	UpdOrFlasFunc_TMT_1_SET
#define Call_CondiCheckPreOCFunc_TMT_1_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_1_SET	FuncDoNothing
#define Call_InitFunc_TMT_2_SET	IniOrClrScrFunc_TMT_2_SET
#define Call_CondiCheckFunc_TMT_2_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_2_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_2_SET	UpdOrFlasFunc_TMT_2_SET
#define Call_CondiCheckPreOCFunc_TMT_2_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_2_SET	FuncDoNothing
#define Call_InitFunc_TMT_3_SET	IniOrClrScrFunc_TMT_3_SET
#define Call_CondiCheckFunc_TMT_3_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_3_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_3_SET	UpdOrFlasFunc_TMT_3_SET
#define Call_CondiCheckPreOCFunc_TMT_3_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_3_SET	FuncDoNothing
#define Call_InitFunc_TMT_4_SET	IniOrClrScrFunc_TMT_4_SET
#define Call_CondiCheckFunc_TMT_4_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_4_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_4_SET	UpdOrFlasFunc_TMT_4_SET
#define Call_CondiCheckPreOCFunc_TMT_4_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_4_SET	FuncDoNothing
#define Call_InitFunc_TMT_5_SET	IniOrClrScrFunc_TMT_5_SET
#define Call_CondiCheckFunc_TMT_5_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_5_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_5_SET	UpdOrFlasFunc_TMT_5_SET
#define Call_CondiCheckPreOCFunc_TMT_5_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_5_SET	FuncDoNothing
#define Call_InitFunc_TMT_6_SET	IniOrClrScrFunc_TMT_6_SET
#define Call_CondiCheckFunc_TMT_6_SET ReturnTrue
#define Call_UpdPortionFunc_TMT_6_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_TMT_6_SET	UpdOrFlasFunc_TMT_6_SET
#define Call_CondiCheckPreOCFunc_TMT_6_SET	ReturnFalse
#define Call_HandlePreOCFunc_TMT_6_SET	FuncDoNothing
#define Call_InitFunc_SET_TMT_1_DIGIT_1	IniOrClrScrFunc_SET_TMT_1_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_1	UpdOrFlasFunc_SET_TMT_1_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_1	CondiPreOcCheck_SET_TMT_1_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_1	HandlePreOCFunc_SET_TMT_1_DIGIT_1
#define Call_InitFunc_SET_TMT_1_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_2	UpdOrFlasFunc_SET_TMT_1_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_2	CondiPreOcCheck_SET_TMT_1_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_2	HandlePreOCFunc_SET_TMT_1_DIGIT_2
#define Call_InitFunc_SET_TMT_1_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_3	UpdOrFlasFunc_SET_TMT_1_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_3	CondiPreOcCheck_SET_TMT_1_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_3	HandlePreOCFunc_SET_TMT_1_DIGIT_3
#define Call_InitFunc_SET_TMT_1_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_4	UpdOrFlasFunc_SET_TMT_1_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_4	CondiPreOcCheck_SET_TMT_1_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_4	HandlePreOCFunc_SET_TMT_1_DIGIT_4
#define Call_InitFunc_SET_TMT_1_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_5	UpdOrFlasFunc_SET_TMT_1_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_5	CondiPreOcCheck_SET_TMT_1_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_5	HandlePreOCFunc_SET_TMT_1_DIGIT_5
#define Call_InitFunc_SET_TMT_1_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_1_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_1_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_1_DIGIT_6	UpdOrFlasFunc_SET_TMT_1_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_1_DIGIT_6	CondiPreOcCheck_SET_TMT_1_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_1_DIGIT_6	HandlePreOCFunc_SET_TMT_1_DIGIT_6
#define Call_InitFunc_SET_TMT_2_DIGIT_1	IniOrClrScrFunc_SET_TMT_2_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_1	UpdOrFlasFunc_SET_TMT_2_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_1	CondiPreOcCheck_SET_TMT_2_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_1	HandlePreOCFunc_SET_TMT_2_DIGIT_1
#define Call_InitFunc_SET_TMT_2_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_2	UpdOrFlasFunc_SET_TMT_2_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_2	CondiPreOcCheck_SET_TMT_2_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_2	HandlePreOCFunc_SET_TMT_2_DIGIT_2
#define Call_InitFunc_SET_TMT_2_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_3	UpdOrFlasFunc_SET_TMT_2_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_3	CondiPreOcCheck_SET_TMT_2_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_3	HandlePreOCFunc_SET_TMT_2_DIGIT_3
#define Call_InitFunc_SET_TMT_2_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_4	UpdOrFlasFunc_SET_TMT_2_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_4	CondiPreOcCheck_SET_TMT_2_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_4	HandlePreOCFunc_SET_TMT_2_DIGIT_4
#define Call_InitFunc_SET_TMT_2_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_5	UpdOrFlasFunc_SET_TMT_2_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_5	CondiPreOcCheck_SET_TMT_2_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_5	HandlePreOCFunc_SET_TMT_2_DIGIT_5
#define Call_InitFunc_SET_TMT_2_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_2_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_2_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_2_DIGIT_6	UpdOrFlasFunc_SET_TMT_2_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_2_DIGIT_6	CondiPreOcCheck_SET_TMT_2_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_2_DIGIT_6	HandlePreOCFunc_SET_TMT_2_DIGIT_6
#define Call_InitFunc_SET_TMT_3_DIGIT_1	IniOrClrScrFunc_SET_TMT_3_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_1	UpdOrFlasFunc_SET_TMT_3_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_1	CondiPreOcCheck_SET_TMT_3_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_1	HandlePreOCFunc_SET_TMT_3_DIGIT_1
#define Call_InitFunc_SET_TMT_3_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_2	UpdOrFlasFunc_SET_TMT_3_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_2	CondiPreOcCheck_SET_TMT_3_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_2	HandlePreOCFunc_SET_TMT_3_DIGIT_2
#define Call_InitFunc_SET_TMT_3_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_3	UpdOrFlasFunc_SET_TMT_3_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_3	CondiPreOcCheck_SET_TMT_3_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_3	HandlePreOCFunc_SET_TMT_3_DIGIT_3
#define Call_InitFunc_SET_TMT_3_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_4	UpdOrFlasFunc_SET_TMT_3_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_4	CondiPreOcCheck_SET_TMT_3_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_4	HandlePreOCFunc_SET_TMT_3_DIGIT_4
#define Call_InitFunc_SET_TMT_3_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_5	UpdOrFlasFunc_SET_TMT_3_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_5	CondiPreOcCheck_SET_TMT_3_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_5	HandlePreOCFunc_SET_TMT_3_DIGIT_5
#define Call_InitFunc_SET_TMT_3_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_3_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_3_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_3_DIGIT_6	UpdOrFlasFunc_SET_TMT_3_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_3_DIGIT_6	CondiPreOcCheck_SET_TMT_3_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_3_DIGIT_6	HandlePreOCFunc_SET_TMT_3_DIGIT_6
#define Call_InitFunc_SET_TMT_4_DIGIT_1	IniOrClrScrFunc_SET_TMT_4_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_1	UpdOrFlasFunc_SET_TMT_4_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_1	CondiPreOcCheck_SET_TMT_4_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_1	HandlePreOCFunc_SET_TMT_4_DIGIT_1
#define Call_InitFunc_SET_TMT_4_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_2	UpdOrFlasFunc_SET_TMT_4_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_2	CondiPreOcCheck_SET_TMT_4_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_2	HandlePreOCFunc_SET_TMT_4_DIGIT_2
#define Call_InitFunc_SET_TMT_4_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_3	UpdOrFlasFunc_SET_TMT_4_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_3	CondiPreOcCheck_SET_TMT_4_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_3	HandlePreOCFunc_SET_TMT_4_DIGIT_3
#define Call_InitFunc_SET_TMT_4_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_4	UpdOrFlasFunc_SET_TMT_4_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_4	CondiPreOcCheck_SET_TMT_4_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_4	HandlePreOCFunc_SET_TMT_4_DIGIT_4
#define Call_InitFunc_SET_TMT_4_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_5	UpdOrFlasFunc_SET_TMT_4_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_5	CondiPreOcCheck_SET_TMT_4_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_5	HandlePreOCFunc_SET_TMT_4_DIGIT_5
#define Call_InitFunc_SET_TMT_4_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_4_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_4_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_4_DIGIT_6	UpdOrFlasFunc_SET_TMT_4_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_4_DIGIT_6	CondiPreOcCheck_SET_TMT_4_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_4_DIGIT_6	HandlePreOCFunc_SET_TMT_4_DIGIT_6
#define Call_InitFunc_SET_TMT_5_DIGIT_1	IniOrClrScrFunc_SET_TMT_5_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_1	UpdOrFlasFunc_SET_TMT_5_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_1	CondiPreOcCheck_SET_TMT_5_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_1	HandlePreOCFunc_SET_TMT_5_DIGIT_1
#define Call_InitFunc_SET_TMT_5_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_2	UpdOrFlasFunc_SET_TMT_5_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_2	CondiPreOcCheck_SET_TMT_5_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_2	HandlePreOCFunc_SET_TMT_5_DIGIT_2
#define Call_InitFunc_SET_TMT_5_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_3	UpdOrFlasFunc_SET_TMT_5_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_3	CondiPreOcCheck_SET_TMT_5_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_3	HandlePreOCFunc_SET_TMT_5_DIGIT_3
#define Call_InitFunc_SET_TMT_5_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_4	UpdOrFlasFunc_SET_TMT_5_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_4	CondiPreOcCheck_SET_TMT_5_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_4	HandlePreOCFunc_SET_TMT_5_DIGIT_4
#define Call_InitFunc_SET_TMT_5_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_5	UpdOrFlasFunc_SET_TMT_5_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_5	CondiPreOcCheck_SET_TMT_5_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_5	HandlePreOCFunc_SET_TMT_5_DIGIT_5
#define Call_InitFunc_SET_TMT_5_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_5_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_5_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_5_DIGIT_6	UpdOrFlasFunc_SET_TMT_5_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_5_DIGIT_6	CondiPreOcCheck_SET_TMT_5_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_5_DIGIT_6	HandlePreOCFunc_SET_TMT_5_DIGIT_6
#define Call_InitFunc_SET_TMT_6_DIGIT_1	IniOrClrScrFunc_SET_TMT_6_DIGIT_1
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_1 ReturnTrue
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_1	UpdOrFlasFunc_SET_TMT_6_DIGIT_1
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_1	CondiPreOcCheck_SET_TMT_6_DIGIT_1
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_1	HandlePreOCFunc_SET_TMT_6_DIGIT_1
#define Call_InitFunc_SET_TMT_6_DIGIT_2	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_2 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_2	UpdOrFlasFunc_SET_TMT_6_DIGIT_2
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_2	CondiPreOcCheck_SET_TMT_6_DIGIT_2
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_2	HandlePreOCFunc_SET_TMT_6_DIGIT_2
#define Call_InitFunc_SET_TMT_6_DIGIT_3	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_3 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_3	UpdOrFlasFunc_SET_TMT_6_DIGIT_3
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_3	CondiPreOcCheck_SET_TMT_6_DIGIT_3
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_3	HandlePreOCFunc_SET_TMT_6_DIGIT_3
#define Call_InitFunc_SET_TMT_6_DIGIT_4	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_4 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_4	UpdOrFlasFunc_SET_TMT_6_DIGIT_4
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_4	CondiPreOcCheck_SET_TMT_6_DIGIT_4
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_4	HandlePreOCFunc_SET_TMT_6_DIGIT_4
#define Call_InitFunc_SET_TMT_6_DIGIT_5	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_5 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_5	UpdOrFlasFunc_SET_TMT_6_DIGIT_5
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_5	CondiPreOcCheck_SET_TMT_6_DIGIT_5
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_5	HandlePreOCFunc_SET_TMT_6_DIGIT_5
#define Call_InitFunc_SET_TMT_6_DIGIT_6	FuncDoNothing
#define Call_CondiCheckFunc_SET_TMT_6_DIGIT_6 ReturnFalse
#define Call_UpdPortionFunc_SET_TMT_6_DIGIT_6	FuncDoNothing
#define Call_UpdOrFlashFunc_SET_TMT_6_DIGIT_6	UpdOrFlasFunc_SET_TMT_6_DIGIT_6
#define Call_CondiCheckPreOCFunc_SET_TMT_6_DIGIT_6	CondiPreOcCheck_SET_TMT_6_DIGIT_6
#define Call_HandlePreOCFunc_SET_TMT_6_DIGIT_6	HandlePreOCFunc_SET_TMT_6_DIGIT_6
#define Call_InitFunc_S187_IM_MYINFO	IniOrClrScrFunc_S187_IM_MYINFO
#define Call_CondiCheckFunc_S187_IM_MYINFO	CondiCheck_S187_IM_MYINFO
#define Call_UpdPortionFunc_S187_IM_MYINFO	UpdPorFunc_S187_IM_MYINFO
#define Call_UpdOrFlashFunc_S187_IM_MYINFO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S187_IM_MYINFO	CondiPreOcCheck_S187_IM_MYINFO
#define Call_HandlePreOCFunc_S187_IM_MYINFO	HandlePreOCFunc_S187_IM_MYINFO
#define Call_InitFunc_S190_IM_DSXINFO	IniOrClrScrFunc_S190_IM_DSXINFO
#define Call_CondiCheckFunc_S190_IM_DSXINFO	CondiCheck_S190_IM_DSXINFO
#define Call_UpdPortionFunc_S190_IM_DSXINFO	UpdPorFunc_S190_IM_DSXINFO
#define Call_UpdOrFlashFunc_S190_IM_DSXINFO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S190_IM_DSXINFO	CondiPreOcCheck_S190_IM_DSXINFO
#define Call_HandlePreOCFunc_S190_IM_DSXINFO	HandlePreOCFunc_S190_IM_DSXINFO
#define Call_InitFunc_S192_IM_HISTORY	IniOrClrScrFunc_S192_IM_HISTORY
#define Call_CondiCheckFunc_S192_IM_HISTORY	CondiCheck_S192_IM_HISTORY
#define Call_UpdPortionFunc_S192_IM_HISTORY	UpdPorFunc_S192_IM_HISTORY
#define Call_UpdOrFlashFunc_S192_IM_HISTORY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S192_IM_HISTORY	CondiPreOcCheck_S192_IM_HISTORY
#define Call_HandlePreOCFunc_S192_IM_HISTORY	HandlePreOCFunc_S192_IM_HISTORY
#define Call_InitFunc_S224_IM_MANUFACTURER	IniOrClrScrFunc_S224_IM_MANUFACTURER
#define Call_CondiCheckFunc_S224_IM_MANUFACTURER	CondiCheck_S224_IM_MANUFACTURER
#define Call_UpdPortionFunc_S224_IM_MANUFACTURER	UpdPorFunc_S224_IM_MANUFACTURER
#define Call_UpdOrFlashFunc_S224_IM_MANUFACTURER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S224_IM_MANUFACTURER	CondiPreOcCheck_S224_IM_MANUFACTURER
#define Call_HandlePreOCFunc_S224_IM_MANUFACTURER	HandlePreOCFunc_S224_IM_MANUFACTURER
#define Call_InitFunc_S218_IM_MYINFO_SET	IniOrClrScrFunc_S218_IM_MYINFO_SET
#define Call_CondiCheckFunc_S218_IM_MYINFO_SET ReturnTrue
#define Call_UpdPortionFunc_S218_IM_MYINFO_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S218_IM_MYINFO_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S218_IM_MYINFO_SET	ReturnFalse
#define Call_HandlePreOCFunc_S218_IM_MYINFO_SET	FuncDoNothing
#define Call_InitFunc_S190_IM_DSXINFO_SET	IniOrClrScrFunc_S190_IM_DSXINFO_SET
#define Call_CondiCheckFunc_S190_IM_DSXINFO_SET ReturnTrue
#define Call_UpdPortionFunc_S190_IM_DSXINFO_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S190_IM_DSXINFO_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S190_IM_DSXINFO_SET	ReturnFalse
#define Call_HandlePreOCFunc_S190_IM_DSXINFO_SET	FuncDoNothing
#define Call_InitFunc_S192_IM_HISTORY_SET	IniOrClrScrFunc_S192_IM_HISTORY_SET
#define Call_CondiCheckFunc_S192_IM_HISTORY_SET ReturnTrue
#define Call_UpdPortionFunc_S192_IM_HISTORY_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S192_IM_HISTORY_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S192_IM_HISTORY_SET	ReturnFalse
#define Call_HandlePreOCFunc_S192_IM_HISTORY_SET	FuncDoNothing
#define Call_InitFunc_S224_IM_MANUFACTURER_SET	IniOrClrScrFunc_MANUFACTURE_SCREEN /*Re-map*/
#define Call_CondiCheckFunc_S224_IM_MANUFACTURER_SET ReturnTrue
#define Call_UpdPortionFunc_S224_IM_MANUFACTURER_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S224_IM_MANUFACTURER_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S224_IM_MANUFACTURER_SET	ReturnFalse
#define Call_HandlePreOCFunc_S224_IM_MANUFACTURER_SET	FuncDoNothing
#define Call_InitFunc_S2_SURFACE_MAIN	IniOrClrScrFunc_S2_SURFACE_MAIN
#define Call_CondiCheckFunc_S2_SURFACE_MAIN ReturnTrue
#define Call_UpdPortionFunc_S2_SURFACE_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_S2_SURFACE_MAIN	UpdOrFlasFunc_S2_SURFACE_MAIN
#define Call_CondiCheckPreOCFunc_S2_SURFACE_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_S2_SURFACE_MAIN	FuncDoNothing
#define Call_InitFunc_S11_SURFACE_ALT1	IniOrClrScrFunc_S11_SURFACE_ALT1
#define Call_CondiCheckFunc_S11_SURFACE_ALT1 ReturnTrue
#define Call_UpdPortionFunc_S11_SURFACE_ALT1	FuncDoNothing
#define Call_UpdOrFlashFunc_S11_SURFACE_ALT1	UpdOrFlasFunc_S11_SURFACE_ALT1
#define Call_CondiCheckPreOCFunc_S11_SURFACE_ALT1	ReturnFalse
#define Call_HandlePreOCFunc_S11_SURFACE_ALT1	FuncDoNothing
#define Call_InitFunc_S12_SURFACE_ALT2	IniOrClrScrFunc_S12_SURFACE_ALT2
#define Call_CondiCheckFunc_S12_SURFACE_ALT2 ReturnTrue
#define Call_UpdPortionFunc_S12_SURFACE_ALT2	FuncDoNothing
#define Call_UpdOrFlashFunc_S12_SURFACE_ALT2	UpdOrFlasFunc_S12_SURFACE_ALT2
#define Call_CondiCheckPreOCFunc_S12_SURFACE_ALT2	ReturnFalse
#define Call_HandlePreOCFunc_S12_SURFACE_ALT2	FuncDoNothing
#define Call_InitFunc_S13_SURFACE_ALT3	IniOrClrScrFunc_S13_SURFACE_ALT3
#define Call_CondiCheckFunc_S13_SURFACE_ALT3 ReturnTrue
#define Call_UpdPortionFunc_S13_SURFACE_ALT3	FuncDoNothing
#define Call_UpdOrFlashFunc_S13_SURFACE_ALT3	UpdOrFlasFunc_S13_SURFACE_ALT3
#define Call_CondiCheckPreOCFunc_S13_SURFACE_ALT3	ReturnFalse
#define Call_HandlePreOCFunc_S13_SURFACE_ALT3	FuncDoNothing
#define Call_InitFunc_S14_SURFACE_ALT4	IniOrClrScrFunc_S14_SURFACE_ALT4
#define Call_CondiCheckFunc_S14_SURFACE_ALT4 ReturnTrue
#define Call_UpdPortionFunc_S14_SURFACE_ALT4	FuncDoNothing
#define Call_UpdOrFlashFunc_S14_SURFACE_ALT4	UpdOrFlasFunc_S14_SURFACE_ALT4
#define Call_CondiCheckPreOCFunc_S14_SURFACE_ALT4	ReturnFalse
#define Call_HandlePreOCFunc_S14_SURFACE_ALT4	FuncDoNothing
#define Call_InitFunc_S15_SURFACE_ALT5	IniOrClrScrFunc_S15_SURFACE_ALT5
#define Call_CondiCheckFunc_S15_SURFACE_ALT5 ReturnTrue
#define Call_UpdPortionFunc_S15_SURFACE_ALT5	FuncDoNothing
#define Call_UpdOrFlashFunc_S15_SURFACE_ALT5	UpdOrFlasFunc_S15_SURFACE_ALT5
#define Call_CondiCheckPreOCFunc_S15_SURFACE_ALT5	ReturnFalse
#define Call_HandlePreOCFunc_S15_SURFACE_ALT5	FuncDoNothing
#define Call_InitFunc_SURFACE_SM_MAIN	IniOrClrScrFunc_SURFACE_SM_MAIN
#define Call_CondiCheckFunc_SURFACE_SM_MAIN ReturnTrue
#define Call_UpdPortionFunc_SURFACE_SM_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_SM_MAIN	UpdOrFlasFunc_SURFACE_SM_MAIN
#define Call_CondiCheckPreOCFunc_SURFACE_SM_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_SM_MAIN	FuncDoNothing
#define Call_InitFunc_SURFACE_SM_ALT1	IniOrClrScrFunc_SURFACE_SM_ALT1
#define Call_CondiCheckFunc_SURFACE_SM_ALT1 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_SM_ALT1	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_SM_ALT1	UpdOrFlasFunc_SURFACE_SM_ALT1
#define Call_CondiCheckPreOCFunc_SURFACE_SM_ALT1	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_SM_ALT1	FuncDoNothing
#define Call_InitFunc_SURFACE_SM_ALT2	IniOrClrScrFunc_SURFACE_SM_ALT2
#define Call_CondiCheckFunc_SURFACE_SM_ALT2 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_SM_ALT2	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_SM_ALT2	UpdOrFlasFunc_SURFACE_SM_ALT2
#define Call_CondiCheckPreOCFunc_SURFACE_SM_ALT2	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_SM_ALT2	FuncDoNothing
#define Call_InitFunc_SURFACE_SM_ALT3	IniOrClrScrFunc_SURFACE_SM_ALT3
#define Call_CondiCheckFunc_SURFACE_SM_ALT3 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_SM_ALT3	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_SM_ALT3	UpdOrFlasFunc_SURFACE_SM_ALT3
#define Call_CondiCheckPreOCFunc_SURFACE_SM_ALT3	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_SM_ALT3	FuncDoNothing
#define Call_InitFunc_SURFACE_SM_ALT4	IniOrClrScrFunc_SURFACE_SM_ALT4
#define Call_CondiCheckFunc_SURFACE_SM_ALT4 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_SM_ALT4	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_SM_ALT4	UpdOrFlasFunc_SURFACE_SM_ALT4
#define Call_CondiCheckPreOCFunc_SURFACE_SM_ALT4	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_SM_ALT4	FuncDoNothing
#define Call_InitFunc_SURFACE_GAUGE_MAIN	IniOrClrScrFunc_SURFACE_GAUGE_MAIN
#define Call_CondiCheckFunc_SURFACE_GAUGE_MAIN ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GAUGE_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GAUGE_MAIN	UpdOrFlasFunc_SURFACE_GAUGE_MAIN
#define Call_CondiCheckPreOCFunc_SURFACE_GAUGE_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GAUGE_MAIN	FuncDoNothing
#define Call_InitFunc_SURFACE_GAUGE_ALT1	IniOrClrScrFunc_SURFACE_GAUGE_ALT1
#define Call_CondiCheckFunc_SURFACE_GAUGE_ALT1 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GAUGE_ALT1	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GAUGE_ALT1	UpdOrFlasFunc_SURFACE_GAUGE_ALT1
#define Call_CondiCheckPreOCFunc_SURFACE_GAUGE_ALT1	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GAUGE_ALT1	FuncDoNothing
#define Call_InitFunc_SURFACE_GAUGE_ALT2	IniOrClrScrFunc_SURFACE_GAUGE_ALT2
#define Call_CondiCheckFunc_SURFACE_GAUGE_ALT2 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GAUGE_ALT2	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GAUGE_ALT2	UpdOrFlasFunc_SURFACE_GAUGE_ALT2
#define Call_CondiCheckPreOCFunc_SURFACE_GAUGE_ALT2	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GAUGE_ALT2	FuncDoNothing
#define Call_InitFunc_SURFACE_GSM_MAIN	IniOrClrScrFunc_SURFACE_GSM_MAIN
#define Call_CondiCheckFunc_SURFACE_GSM_MAIN ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GSM_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GSM_MAIN	UpdOrFlasFunc_SURFACE_GSM_MAIN
#define Call_CondiCheckPreOCFunc_SURFACE_GSM_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GSM_MAIN	FuncDoNothing
#define Call_InitFunc_SURFACE_GSM_ALT1	IniOrClrScrFunc_SURFACE_GAUGE_ALT1 /*Re-map*/
#define Call_CondiCheckFunc_SURFACE_GSM_ALT1 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GSM_ALT1	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GSM_ALT1	UpdOrFlasFunc_SURFACE_GAUGE_ALT1 /*Re-map*/
#define Call_CondiCheckPreOCFunc_SURFACE_GSM_ALT1	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GSM_ALT1	FuncDoNothing
#define Call_InitFunc_SURFACE_GSM_ALT2	IniOrClrScrFunc_SURFACE_GAUGE_ALT2 /*Re-map*/
#define Call_CondiCheckFunc_SURFACE_GSM_ALT2 ReturnTrue
#define Call_UpdPortionFunc_SURFACE_GSM_ALT2	FuncDoNothing
#define Call_UpdOrFlashFunc_SURFACE_GSM_ALT2	UpdOrFlasFunc_SURFACE_GAUGE_ALT2 /*Re-map*/
#define Call_CondiCheckPreOCFunc_SURFACE_GSM_ALT2	ReturnFalse
#define Call_HandlePreOCFunc_SURFACE_GSM_ALT2	FuncDoNothing
#define Call_InitFunc_SP_SWITCH_TO_HIGH	IniOrClrScrFunc_SP_SWITCH_TO_HIGH
#define Call_CondiCheckFunc_SP_SWITCH_TO_HIGH	CondiCheck_SP_SWITCH_TO_HIGH
#define Call_UpdPortionFunc_SP_SWITCH_TO_HIGH	UpdPorFunc_SP_SWITCH_TO_HIGH
#define Call_UpdOrFlashFunc_SP_SWITCH_TO_HIGH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SP_SWITCH_TO_HIGH	CondiPreOcCheck_SP_SWITCH_TO_HIGH
#define Call_HandlePreOCFunc_SP_SWITCH_TO_HIGH	HandlePreOCFunc_SP_SWITCH_TO_HIGH
#define Call_InitFunc_SP_SWITCH_TO_LOW	IniOrClrScrFunc_SP_SWITCH_TO_LOW
#define Call_CondiCheckFunc_SP_SWITCH_TO_LOW	CondiCheck_SP_SWITCH_TO_LOW
#define Call_UpdPortionFunc_SP_SWITCH_TO_LOW	UpdPorFunc_SP_SWITCH_TO_LOW
#define Call_UpdOrFlashFunc_SP_SWITCH_TO_LOW	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SP_SWITCH_TO_LOW	CondiPreOcCheck_SP_SWITCH_TO_LOW
#define Call_HandlePreOCFunc_SP_SWITCH_TO_LOW	HandlePreOCFunc_SP_SWITCH_TO_LOW
#define Call_InitFunc_SP_SWITCH_TO_CUSTOM	IniOrClrScrFunc_SP_SWITCH_TO_CUSTOM
#define Call_CondiCheckFunc_SP_SWITCH_TO_CUSTOM	CondiCheck_SP_SWITCH_TO_CUSTOM
#define Call_UpdPortionFunc_SP_SWITCH_TO_CUSTOM	UpdPorFunc_SP_SWITCH_TO_CUSTOM
#define Call_UpdOrFlashFunc_SP_SWITCH_TO_CUSTOM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SP_SWITCH_TO_CUSTOM	CondiPreOcCheck_SP_SWITCH_TO_CUSTOM
#define Call_HandlePreOCFunc_SP_SWITCH_TO_CUSTOM	HandlePreOCFunc_SP_SWITCH_TO_CUSTOM
#define Call_InitFunc_GAS_SWITCH_TO_GAS_0	FuncDoNothing
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_0 ReturnFalse
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_0	FuncDoNothing
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_0	FuncDoNothing
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_0	ReturnFalse
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_0	FuncDoNothing
#define Call_InitFunc_GAS_SWITCH_TO_GAS_1	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_1
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_1	CondiCheck_GAS_SWITCH_TO_GAS_1
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_1	UpdPorFunc_GAS_SWITCH_TO_GAS_1
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_1	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_1
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_1	CondiPreOcCheck_GAS_SWITCH_TO_GAS_1
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_1	HandlePreOCFunc_GAS_SWITCH_TO_GAS_1
#define Call_InitFunc_GAS_SWITCH_TO_GAS_2	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_2
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_2	CondiCheck_GAS_SWITCH_TO_GAS_2
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_2	UpdPorFunc_GAS_SWITCH_TO_GAS_2
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_2	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_2
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_2	CondiPreOcCheck_GAS_SWITCH_TO_GAS_2
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_2	HandlePreOCFunc_GAS_SWITCH_TO_GAS_2
#define Call_InitFunc_GAS_SWITCH_TO_GAS_3	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_3
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_3	CondiCheck_GAS_SWITCH_TO_GAS_3
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_3	UpdPorFunc_GAS_SWITCH_TO_GAS_3
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_3	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_3
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_3	CondiPreOcCheck_GAS_SWITCH_TO_GAS_3
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_3	HandlePreOCFunc_GAS_SWITCH_TO_GAS_3
#define Call_InitFunc_GAS_SWITCH_TO_GAS_4	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_4
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_4	CondiCheck_GAS_SWITCH_TO_GAS_4
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_4	UpdPorFunc_GAS_SWITCH_TO_GAS_4
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_4	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_4
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_4	CondiPreOcCheck_GAS_SWITCH_TO_GAS_4
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_4	HandlePreOCFunc_GAS_SWITCH_TO_GAS_4
#define Call_InitFunc_GAS_SWITCH_TO_GAS_5	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_5
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_5	CondiCheck_GAS_SWITCH_TO_GAS_5
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_5	UpdPorFunc_GAS_SWITCH_TO_GAS_5
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_5	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_5
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_5	CondiPreOcCheck_GAS_SWITCH_TO_GAS_5
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_5	HandlePreOCFunc_GAS_SWITCH_TO_GAS_5
#define Call_InitFunc_GAS_SWITCH_TO_GAS_6	IniOrClrScrFunc_GAS_SWITCH_TO_GAS_6
#define Call_CondiCheckFunc_GAS_SWITCH_TO_GAS_6	CondiCheck_GAS_SWITCH_TO_GAS_6
#define Call_UpdPortionFunc_GAS_SWITCH_TO_GAS_6	UpdPorFunc_GAS_SWITCH_TO_GAS_6
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_GAS_6	UpdOrFlasFunc_GAS_SWITCH_TO_GAS_6
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_GAS_6	CondiPreOcCheck_GAS_SWITCH_TO_GAS_6
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_GAS_6	HandlePreOCFunc_GAS_SWITCH_TO_GAS_6
#define Call_InitFunc_GAS_SWITCH_TO_MOD	FuncDoNothing
#define Call_CondiCheckFunc_GAS_SWITCH_TO_MOD ReturnFalse
#define Call_UpdPortionFunc_GAS_SWITCH_TO_MOD	FuncDoNothing
#define Call_UpdOrFlashFunc_GAS_SWITCH_TO_MOD	FuncDoNothing
#define Call_CondiCheckPreOCFunc_GAS_SWITCH_TO_MOD	ReturnFalse
#define Call_HandlePreOCFunc_GAS_SWITCH_TO_MOD	FuncDoNothing
#define Call_InitFunc_S77_ACTUAL_GAS_WARNING 	IniOrClrScrFunc_S77_ACTUAL_GAS_WARNING
#define Call_CondiCheckFunc_S77_ACTUAL_GAS_WARNING  ReturnTrue
#define Call_UpdPortionFunc_S77_ACTUAL_GAS_WARNING 	FuncDoNothing
#define Call_UpdOrFlashFunc_S77_ACTUAL_GAS_WARNING 	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S77_ACTUAL_GAS_WARNING 	ReturnFalse
#define Call_HandlePreOCFunc_S77_ACTUAL_GAS_WARNING 	FuncDoNothing
#define Call_InitFunc_D41_ACTUAL_GAS_WARNING	IniOrClrScrFunc_D41_ACTUAL_GAS_WARNING
#define Call_CondiCheckFunc_D41_ACTUAL_GAS_WARNING ReturnTrue
#define Call_UpdPortionFunc_D41_ACTUAL_GAS_WARNING	FuncDoNothing
#define Call_UpdOrFlashFunc_D41_ACTUAL_GAS_WARNING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D41_ACTUAL_GAS_WARNING	ReturnFalse
#define Call_HandlePreOCFunc_D41_ACTUAL_GAS_WARNING	FuncDoNothing
#define Call_InitFunc_DIVE_PL_TIME_LIMITS	IniOrClrScrFunc_DIVE_PL_TIME_LIMITS
#define Call_CondiCheckFunc_DIVE_PL_TIME_LIMITS	CondiCheck_DIVE_PL_TIME_LIMITS
#define Call_UpdPortionFunc_DIVE_PL_TIME_LIMITS	UpdPorFunc_DIVE_PL_TIME_LIMITS
#define Call_UpdOrFlashFunc_DIVE_PL_TIME_LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_TIME_LIMITS	CondiPreOcCheck_DIVE_PL_TIME_LIMITS
#define Call_HandlePreOCFunc_DIVE_PL_TIME_LIMITS	HandlePreOCFunc_DIVE_PL_TIME_LIMITS
#define Call_InitFunc_DIVE_PL_DEPTH_LIMITS	IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS
#define Call_CondiCheckFunc_DIVE_PL_DEPTH_LIMITS	CondiCheck_DIVE_PL_DEPTH_LIMITS
#define Call_UpdPortionFunc_DIVE_PL_DEPTH_LIMITS	UpdPorFunc_DIVE_PL_DEPTH_LIMITS
#define Call_UpdOrFlashFunc_DIVE_PL_DEPTH_LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DEPTH_LIMITS	CondiPreOcCheck_DIVE_PL_DEPTH_LIMITS
#define Call_HandlePreOCFunc_DIVE_PL_DEPTH_LIMITS	HandlePreOCFunc_DIVE_PL_DEPTH_LIMITS
#define Call_InitFunc_DIVE_PL_DIVE_SIM	IniOrClrScrFunc_DIVE_PL_DIVE_SIM
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM	CondiCheck_DIVE_PL_DIVE_SIM
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM	UpdPorFunc_DIVE_PL_DIVE_SIM
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM	CondiPreOcCheck_DIVE_PL_DIVE_SIM
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM	HandlePreOCFunc_DIVE_PL_DIVE_SIM
#define Call_InitFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	CondiCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	UpdPorFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	CondiPreOcCheck_DIVE_PL_DIVE_SIM_NEWORCONTINUOS
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS	HandlePreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS
#define Call_InitFunc_DIVE_PL_DIVE_SIM_DEPTH	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_DEPTH	CondiCheck_DIVE_PL_DIVE_SIM_DEPTH
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_DEPTH	UpdPorFunc_DIVE_PL_DIVE_SIM_DEPTH
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_DEPTH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_DEPTH	CondiPreOcCheck_DIVE_PL_DIVE_SIM_DEPTH
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_DEPTH	HandlePreOCFunc_DIVE_PL_DIVE_SIM_DEPTH
#define Call_InitFunc_DIVE_PL_DIVE_SIM_TIME	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_TIME	CondiCheck_DIVE_PL_DIVE_SIM_TIME
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_TIME	UpdPorFunc_DIVE_PL_DIVE_SIM_TIME
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_TIME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_TIME	CondiPreOcCheck_DIVE_PL_DIVE_SIM_TIME
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_TIME	HandlePreOCFunc_DIVE_PL_DIVE_SIM_TIME
#define Call_InitFunc_DIVE_PL_DIVE_SIM_SAC	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_SAC	CondiCheck_DIVE_PL_DIVE_SIM_SAC
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_SAC	UpdPorFunc_DIVE_PL_DIVE_SIM_SAC
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_SAC	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_SAC	CondiPreOcCheck_DIVE_PL_DIVE_SIM_SAC
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_SAC	HandlePreOCFunc_DIVE_PL_DIVE_SIM_SAC
#define Call_InitFunc_DIVE_PL_DIVE_SIM_SP	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_SP	CondiCheck_DIVE_PL_DIVE_SIM_SP
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_SP	UpdPorFunc_DIVE_PL_DIVE_SIM_SP
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_SP	CondiPreOcCheck_DIVE_PL_DIVE_SIM_SP
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_SP	HandlePreOCFunc_DIVE_PL_DIVE_SIM_SP
#define Call_InitFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	CondiCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	UpdPorFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	CondiPreOcCheck_DIVE_PL_DIVE_SIM_SIMULATEDIVE
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE	HandlePreOCFunc_DIVE_PL_DIVE_SIM_SIMULATEDIVE
#define Call_InitFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET	UpdOrFlasFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_NEWORCONTINUOS_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_DIVE_SIM_DEPTH_SET	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_DEPTH_SET
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_DEPTH_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_DEPTH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_DEPTH_SET	UpdOrFlasFunc_DIVE_PL_DIVE_SIM_DEPTH_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_DEPTH_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_DEPTH_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_DIVE_SIM_TIME_SET	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_TIME_SET
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_TIME_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_TIME_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_TIME_SET	UpdOrFlasFunc_DIVE_PL_DIVE_SIM_TIME_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_TIME_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_TIME_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_DIVE_SIM_SAC_SET	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SAC_SET
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_SAC_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_SAC_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_SAC_SET	UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SAC_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_SAC_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_SAC_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_DIVE_SIM_SP_SET	IniOrClrScrFunc_DIVE_PL_DIVE_SIM_SP_SET
#define Call_CondiCheckFunc_DIVE_PL_DIVE_SIM_SP_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DIVE_SIM_SP_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DIVE_SIM_SP_SET	UpdOrFlasFunc_DIVE_PL_DIVE_SIM_SP_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_DIVE_SIM_SP_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DIVE_SIM_SP_SET	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_NODECO	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NODECO
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_NODECO ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_NODECO	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_NODECO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_NODECO	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_NODECO	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_NOTENTIM	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_MAXCELEXCEED	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DECOTIME_EXCEED	IniOrClrScrFunc_DIVE_SIMDIVE_DECOTIME_EXCEED
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DECOTIME_EXCEED ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DECOTIME_EXCEED	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DECOTIME_EXCEED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DECOTIME_EXCEED	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DECOTIME_EXCEED	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_TOOHIGH_PO2	IniOrClrScrFunc_DIVE_SIMDIVE_TOOHIGH_PO2
#define Call_CondiCheckFunc_DIVE_SIMDIVE_TOOHIGH_PO2 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_TOOHIGH_PO2	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_TOOHIGH_PO2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_TOOHIGH_PO2	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_TOOHIGH_PO2	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_CALCULATING	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_02	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_03	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_04	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_05	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_06	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_07	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08	IniOrClrScrFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_DIVPLAN_PAGE_08	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_02	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_03	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_04	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_05	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_06	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_07	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_PAGE_01 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_PAGE_08	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS	IniOrClrScrFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS
#define Call_CondiCheckFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_BAILOUT_CONSUMPTIONS	FuncDoNothing
#define Call_InitFunc_DIVE_SIMDIVE_SUMMARY	IniOrClrScrFunc_DIVE_SIMDIVE_SUMMARY
#define Call_CondiCheckFunc_DIVE_SIMDIVE_SUMMARY ReturnTrue
#define Call_UpdPortionFunc_DIVE_SIMDIVE_SUMMARY	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SIMDIVE_SUMMARY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_SIMDIVE_SUMMARY	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SIMDIVE_SUMMARY	FuncDoNothing
#define Call_InitFunc_DIVE_PL_SIM_DIVE	FuncDoNothing
#define Call_CondiCheckFunc_DIVE_PL_SIM_DIVE ReturnFalse
#define Call_UpdPortionFunc_DIVE_PL_SIM_DIVE	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_SIM_DIVE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_SIM_DIVE	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_SIM_DIVE	FuncDoNothing
#define Call_InitFunc_DIVE_PL_TIME_LIMITS_SET	IniOrClrScrFunc_DIVE_PL_TIME_LIMITS_SET
#define Call_CondiCheckFunc_DIVE_PL_TIME_LIMITS_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_TIME_LIMITS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_TIME_LIMITS_SET	UpdOrFlasFunc_DIVE_PL_TIME_LIMITS_SET
#define Call_CondiCheckPreOCFunc_DIVE_PL_TIME_LIMITS_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_TIME_LIMITS_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_DEPTH_LIMITS_SET	IniOrClrScrFunc_DIVE_PL_DEPTH_LIMITS_SET
#define Call_CondiCheckFunc_DIVE_PL_DEPTH_LIMITS_SET ReturnTrue
#define Call_UpdPortionFunc_DIVE_PL_DEPTH_LIMITS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_DEPTH_LIMITS_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_DEPTH_LIMITS_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_DEPTH_LIMITS_SET	FuncDoNothing
#define Call_InitFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN	FuncDoNothing
#define Call_CondiCheckFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN ReturnFalse
#define Call_UpdPortionFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_SIM_DIVE_DIVE_PLAN	FuncDoNothing
#define Call_InitFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN	FuncDoNothing
#define Call_CondiCheckFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN ReturnFalse
#define Call_UpdPortionFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_SIM_DIVE_BAILOUT_PLAN	FuncDoNothing
#define Call_InitFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP	FuncDoNothing
#define Call_CondiCheckFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP ReturnFalse
#define Call_UpdPortionFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_SIM_DIVE_BAILOUTGASCONSUMP	FuncDoNothing
#define Call_InitFunc_DIVE_PL_SIM_DIVE_SUMMARY	FuncDoNothing
#define Call_CondiCheckFunc_DIVE_PL_SIM_DIVE_SUMMARY ReturnFalse
#define Call_UpdPortionFunc_DIVE_PL_SIM_DIVE_SUMMARY	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_PL_SIM_DIVE_SUMMARY	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVE_PL_SIM_DIVE_SUMMARY	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_PL_SIM_DIVE_SUMMARY	FuncDoNothing
#define Call_InitFunc_BAILOUT_PO2_OC_MIN	IniOrClrScrFunc_BAILOUT_PO2_OC_MIN
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_MIN	CondiCheck_BAILOUT_PO2_OC_MIN
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_MIN	UpdPorFunc_BAILOUT_PO2_OC_MIN
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_MIN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_MIN	CondiPreOcCheck_BAILOUT_PO2_OC_MIN
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_MIN	HandlePreOCFunc_BAILOUT_PO2_OC_MIN
#define Call_InitFunc_BAILOUT_PO2_OC_MIN_SET	IniOrClrScrFunc_BAILOUT_PO2_OC_MIN_SET
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_MIN_SET ReturnTrue
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_MIN_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_MIN_SET	UpdOrFlasFunc_BAILOUT_PO2_OC_MIN_SET
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_MIN_SET	ReturnFalse
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_MIN_SET	FuncDoNothing
#define Call_InitFunc_BAILOUT_PO2_OC_MAX	IniOrClrScrFunc_BAILOUT_PO2_OC_MAX
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_MAX	CondiCheck_BAILOUT_PO2_OC_MAX
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_MAX	UpdPorFunc_BAILOUT_PO2_OC_MAX
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_MAX	FuncDoNothing
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_MAX	CondiPreOcCheck_BAILOUT_PO2_OC_MAX
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_MAX	HandlePreOCFunc_BAILOUT_PO2_OC_MAX
#define Call_InitFunc_BAILOUT_PO2_OC_MAX_SET	IniOrClrScrFunc_BAILOUT_PO2_OC_MAX_SET
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_MAX_SET ReturnTrue
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_MAX_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_MAX_SET	UpdOrFlasFunc_BAILOUT_PO2_OC_MAX_SET
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_MAX_SET	ReturnFalse
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_MAX_SET	FuncDoNothing
#define Call_InitFunc_BAILOUT_PO2_OC_DECO	IniOrClrScrFunc_BAILOUT_PO2_OC_DECO
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_DECO	CondiCheck_BAILOUT_PO2_OC_DECO
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_DECO	UpdPorFunc_BAILOUT_PO2_OC_DECO
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_DECO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_DECO	CondiPreOcCheck_BAILOUT_PO2_OC_DECO
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_DECO	HandlePreOCFunc_BAILOUT_PO2_OC_DECO
#define Call_InitFunc_BAILOUT_PO2_OC_DECO_SET	IniOrClrScrFunc_BAILOUT_PO2_OC_DECO_SET
#define Call_CondiCheckFunc_BAILOUT_PO2_OC_DECO_SET ReturnTrue
#define Call_UpdPortionFunc_BAILOUT_PO2_OC_DECO_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_BAILOUT_PO2_OC_DECO_SET	UpdOrFlasFunc_BAILOUT_PO2_OC_DECO_SET
#define Call_CondiCheckPreOCFunc_BAILOUT_PO2_OC_DECO_SET	ReturnFalse
#define Call_HandlePreOCFunc_BAILOUT_PO2_OC_DECO_SET	FuncDoNothing
#define Call_InitFunc_S105_SET_CONSERV_TEC_SPORT	IniOrClrScrFunc_S105_SET_CONSERV_TEC_SPORT
#define Call_CondiCheckFunc_S105_SET_CONSERV_TEC_SPORT ReturnTrue
#define Call_UpdPortionFunc_S105_SET_CONSERV_TEC_SPORT	FuncDoNothing
#define Call_UpdOrFlashFunc_S105_SET_CONSERV_TEC_SPORT	UpdOrFlasFunc_S105_SET_CONSERV_TEC_SPORT
#define Call_CondiCheckPreOCFunc_S105_SET_CONSERV_TEC_SPORT	ReturnFalse
#define Call_HandlePreOCFunc_S105_SET_CONSERV_TEC_SPORT	FuncDoNothing
#define Call_InitFunc_S106_SET_CONSERV_SPORT	IniOrClrScrFunc_S106_SET_CONSERV_SPORT
#define Call_CondiCheckFunc_S106_SET_CONSERV_SPORT ReturnTrue
#define Call_UpdPortionFunc_S106_SET_CONSERV_SPORT	FuncDoNothing
#define Call_UpdOrFlashFunc_S106_SET_CONSERV_SPORT	UpdOrFlasFunc_S106_SET_CONSERV_SPORT
#define Call_CondiCheckPreOCFunc_S106_SET_CONSERV_SPORT	ReturnFalse
#define Call_HandlePreOCFunc_S106_SET_CONSERV_SPORT	FuncDoNothing
#define Call_InitFunc_CONSERV_TEC_GF_LOW	IniOrClrScrFunc_CONSERV_TEC_GF_LOW
#define Call_CondiCheckFunc_CONSERV_TEC_GF_LOW	CondiCheck_CONSERV_TEC_GF_LOW
#define Call_UpdPortionFunc_CONSERV_TEC_GF_LOW	UpdPorFunc_CONSERV_TEC_GF_LOW
#define Call_UpdOrFlashFunc_CONSERV_TEC_GF_LOW	FuncDoNothing
#define Call_CondiCheckPreOCFunc_CONSERV_TEC_GF_LOW	CondiPreOcCheck_CONSERV_TEC_GF_LOW
#define Call_HandlePreOCFunc_CONSERV_TEC_GF_LOW	HandlePreOCFunc_CONSERV_TEC_GF_LOW
#define Call_InitFunc_CONSERV_TEC_GF_LOW_SET	IniOrClrScrFunc_CONSERV_TEC_GF_LOW_SET
#define Call_CondiCheckFunc_CONSERV_TEC_GF_LOW_SET ReturnTrue
#define Call_UpdPortionFunc_CONSERV_TEC_GF_LOW_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_CONSERV_TEC_GF_LOW_SET	UpdOrFlasFunc_CONSERV_TEC_GF_LOW_SET
#define Call_CondiCheckPreOCFunc_CONSERV_TEC_GF_LOW_SET	ReturnFalse
#define Call_HandlePreOCFunc_CONSERV_TEC_GF_LOW_SET	FuncDoNothing
#define Call_InitFunc_CONSERV_TEC_GF_HIGH	IniOrClrScrFunc_CONSERV_TEC_GF_HIGH
#define Call_CondiCheckFunc_CONSERV_TEC_GF_HIGH	CondiCheck_CONSERV_TEC_GF_HIGH
#define Call_UpdPortionFunc_CONSERV_TEC_GF_HIGH	UpdPorFunc_CONSERV_TEC_GF_HIGH
#define Call_UpdOrFlashFunc_CONSERV_TEC_GF_HIGH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_CONSERV_TEC_GF_HIGH	CondiPreOcCheck_CONSERV_TEC_GF_HIGH
#define Call_HandlePreOCFunc_CONSERV_TEC_GF_HIGH	HandlePreOCFunc_CONSERV_TEC_GF_HIGH
#define Call_InitFunc_CONSERV_TEC_GF_HIGH_SET	IniOrClrScrFunc_CONSERV_TEC_GF_HIGH_SET
#define Call_CondiCheckFunc_CONSERV_TEC_GF_HIGH_SET ReturnTrue
#define Call_UpdPortionFunc_CONSERV_TEC_GF_HIGH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_CONSERV_TEC_GF_HIGH_SET	UpdOrFlasFunc_CONSERV_TEC_GF_HIGH_SET
#define Call_CondiCheckPreOCFunc_CONSERV_TEC_GF_HIGH_SET	ReturnFalse
#define Call_HandlePreOCFunc_CONSERV_TEC_GF_HIGH_SET	FuncDoNothing
#define Call_InitFunc_ALARM_AUDIBLE	IniOrClrScrFunc_ALARM_AUDIBLE
#define Call_CondiCheckFunc_ALARM_AUDIBLE	CondiCheck_ALARM_AUDIBLE
#define Call_UpdPortionFunc_ALARM_AUDIBLE	UpdPorFunc_ALARM_AUDIBLE
#define Call_UpdOrFlashFunc_ALARM_AUDIBLE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ALARM_AUDIBLE	CondiPreOcCheck_ALARM_AUDIBLE
#define Call_HandlePreOCFunc_ALARM_AUDIBLE	HandlePreOCFunc_ALARM_AUDIBLE
#define Call_InitFunc_ALARM_AUDIBLE_SET	IniOrClrScrFunc_ALARM_AUDIBLE_SET
#define Call_CondiCheckFunc_ALARM_AUDIBLE_SET ReturnTrue
#define Call_UpdPortionFunc_ALARM_AUDIBLE_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_AUDIBLE_SET	UpdOrFlasFunc_ALARM_AUDIBLE_SET
#define Call_CondiCheckPreOCFunc_ALARM_AUDIBLE_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_AUDIBLE_SET	FuncDoNothing
#define Call_InitFunc_ALARM_VIBRATION	IniOrClrScrFunc_ALARM_VIBRATION
#define Call_CondiCheckFunc_ALARM_VIBRATION	CondiCheck_ALARM_VIBRATION
#define Call_UpdPortionFunc_ALARM_VIBRATION	UpdPorFunc_ALARM_VIBRATION
#define Call_UpdOrFlashFunc_ALARM_VIBRATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ALARM_VIBRATION	CondiPreOcCheck_ALARM_VIBRATION
#define Call_HandlePreOCFunc_ALARM_VIBRATION	HandlePreOCFunc_ALARM_VIBRATION
#define Call_InitFunc_ALARM_VIBRATION_SET	IniOrClrScrFunc_ALARM_VIBRATION_SET
#define Call_CondiCheckFunc_ALARM_VIBRATION_SET ReturnTrue
#define Call_UpdPortionFunc_ALARM_VIBRATION_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_VIBRATION_SET	UpdOrFlasFunc_ALARM_VIBRATION_SET
#define Call_CondiCheckPreOCFunc_ALARM_VIBRATION_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_VIBRATION_SET	FuncDoNothing
#define Call_InitFunc_ALARM_DEPTH_STAT	IniOrClrScrFunc_ALARM_DEPTH_STAT
#define Call_CondiCheckFunc_ALARM_DEPTH_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_DEPTH_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_DEPTH_STAT	UpdOrFlasFunc_ALARM_DEPTH_STAT
#define Call_CondiCheckPreOCFunc_ALARM_DEPTH_STAT	CondiPreOcCheck_ALARM_DEPTH_STAT
#define Call_HandlePreOCFunc_ALARM_DEPTH_STAT	HandlePreOCFunc_ALARM_DEPTH_STAT
#define Call_InitFunc_ALARM_DEPTH_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_DEPTH_SET	CondiCheck_ALARM_DEPTH_SET
#define Call_UpdPortionFunc_ALARM_DEPTH_SET	UpdPorFunc_ALARM_DEPTH_SET
#define Call_UpdOrFlashFunc_ALARM_DEPTH_SET	UpdOrFlasFunc_ALARM_DEPTH_SET
#define Call_CondiCheckPreOCFunc_ALARM_DEPTH_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_DEPTH_SET	FuncDoNothing
#define Call_InitFunc_ALARM_DIVETIME	IniOrClrScrFunc_ALARM_DIVETIME
#define Call_CondiCheckFunc_ALARM_DIVETIME	CondiCheck_ALARM_DIVETIME
#define Call_UpdPortionFunc_ALARM_DIVETIME	UpdPorFunc_ALARM_DIVETIME
#define Call_UpdOrFlashFunc_ALARM_DIVETIME	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ALARM_DIVETIME	CondiPreOcCheck_ALARM_DIVETIME
#define Call_HandlePreOCFunc_ALARM_DIVETIME	HandlePreOCFunc_ALARM_DIVETIME
#define Call_InitFunc_ALARM_DIVETIME_STAT	IniOrClrScrFunc_ALARM_DIVETIME_STAT
#define Call_CondiCheckFunc_ALARM_DIVETIME_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_DIVETIME_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_DIVETIME_STAT	UpdOrFlasFunc_ALARM_DIVETIME_STAT
#define Call_CondiCheckPreOCFunc_ALARM_DIVETIME_STAT	CondiPreOcCheck_ALARM_DIVETIME_STAT
#define Call_HandlePreOCFunc_ALARM_DIVETIME_STAT	HandlePreOCFunc_ALARM_DIVETIME_STAT
#define Call_InitFunc_ALARM_DIVETIME_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_DIVETIME_SET	CondiCheck_ALARM_DIVETIME_SET
#define Call_UpdPortionFunc_ALARM_DIVETIME_SET	UpdPorFunc_ALARM_DIVETIME_SET
#define Call_UpdOrFlashFunc_ALARM_DIVETIME_SET	UpdOrFlasFunc_ALARM_DIVETIME_SET
#define Call_CondiCheckPreOCFunc_ALARM_DIVETIME_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_DIVETIME_SET	FuncDoNothing
#define Call_InitFunc_ALARM_TTS	IniOrClrScrFunc_ALARM_TTS
#define Call_CondiCheckFunc_ALARM_TTS	CondiCheck_ALARM_TTS
#define Call_UpdPortionFunc_ALARM_TTS	UpdPorFunc_ALARM_TTS
#define Call_UpdOrFlashFunc_ALARM_TTS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ALARM_TTS	CondiPreOcCheck_ALARM_TTS
#define Call_HandlePreOCFunc_ALARM_TTS	HandlePreOCFunc_ALARM_TTS
#define Call_InitFunc_ALARM_TTS_STAT	IniOrClrScrFunc_ALARM_TTS_STAT
#define Call_CondiCheckFunc_ALARM_TTS_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_TTS_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_TTS_STAT	UpdOrFlasFunc_ALARM_TTS_STAT
#define Call_CondiCheckPreOCFunc_ALARM_TTS_STAT	CondiPreOcCheck_ALARM_TTS_STAT
#define Call_HandlePreOCFunc_ALARM_TTS_STAT	HandlePreOCFunc_ALARM_TTS_STAT
#define Call_InitFunc_ALARM_TTS_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_TTS_SET	CondiCheck_ALARM_TTS_SET
#define Call_UpdPortionFunc_ALARM_TTS_SET	UpdPorFunc_ALARM_TTS_SET
#define Call_UpdOrFlashFunc_ALARM_TTS_SET	UpdOrFlasFunc_ALARM_TTS_SET
#define Call_CondiCheckPreOCFunc_ALARM_TTS_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_TTS_SET	FuncDoNothing
#define Call_InitFunc_ALARM_DTR_STAT	IniOrClrScrFunc_ALARM_DTR_STAT
#define Call_CondiCheckFunc_ALARM_DTR_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_DTR_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_DTR_STAT	UpdOrFlasFunc_ALARM_DTR_STAT
#define Call_CondiCheckPreOCFunc_ALARM_DTR_STAT	CondiPreOcCheck_ALARM_DTR_STAT
#define Call_HandlePreOCFunc_ALARM_DTR_STAT	HandlePreOCFunc_ALARM_DTR_STAT
#define Call_InitFunc_ALARM_DTR_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_DTR_SET	CondiCheck_ALARM_DTR_SET
#define Call_UpdPortionFunc_ALARM_DTR_SET	UpdPorFunc_ALARM_DTR_SET
#define Call_UpdOrFlashFunc_ALARM_DTR_SET	UpdOrFlasFunc_ALARM_DTR_SET
#define Call_CondiCheckPreOCFunc_ALARM_DTR_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_DTR_SET	FuncDoNothing
#define Call_InitFunc_ALARM_TANK_PRESS_STAT	IniOrClrScrFunc_ALARM_TANK_PRESS_STAT
#define Call_CondiCheckFunc_ALARM_TANK_PRESS_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_TANK_PRESS_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_TANK_PRESS_STAT	UpdOrFlasFunc_ALARM_TANK_PRESS_STAT
#define Call_CondiCheckPreOCFunc_ALARM_TANK_PRESS_STAT	CondiPreOcCheck_ALARM_TANK_PRESS_STAT
#define Call_HandlePreOCFunc_ALARM_TANK_PRESS_STAT	HandlePreOCFunc_ALARM_TANK_PRESS_STAT
#define Call_InitFunc_ALARM_TANK_PRESS_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_TANK_PRESS_SET	CondiCheck_ALARM_TANK_PRESS_SET
#define Call_UpdPortionFunc_ALARM_TANK_PRESS_SET	UpdPorFunc_ALARM_TANK_PRESS_SET
#define Call_UpdOrFlashFunc_ALARM_TANK_PRESS_SET	UpdOrFlasFunc_ALARM_TANK_PRESS_SET
#define Call_CondiCheckPreOCFunc_ALARM_TANK_PRESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_TANK_PRESS_SET	FuncDoNothing
#define Call_InitFunc_ALARM_CC6_PRESS_STAT	IniOrClrScrFunc_ALARM_CC6_PRESS_STAT
#define Call_CondiCheckFunc_ALARM_CC6_PRESS_STAT ReturnTrue
#define Call_UpdPortionFunc_ALARM_CC6_PRESS_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_CC6_PRESS_STAT	UpdOrFlasFunc_ALARM_CC6_PRESS_STAT
#define Call_CondiCheckPreOCFunc_ALARM_CC6_PRESS_STAT	CondiPreOcCheck_ALARM_CC6_PRESS_STAT
#define Call_HandlePreOCFunc_ALARM_CC6_PRESS_STAT	HandlePreOCFunc_ALARM_CC6_PRESS_STAT
#define Call_InitFunc_ALARM_CC6_PRESS_SET	FuncDoNothing
#define Call_CondiCheckFunc_ALARM_CC6_PRESS_SET	CondiCheck_ALARM_CC6_PRESS_SET
#define Call_UpdPortionFunc_ALARM_CC6_PRESS_SET	UpdPorFunc_ALARM_CC6_PRESS_SET
#define Call_UpdOrFlashFunc_ALARM_CC6_PRESS_SET	UpdOrFlasFunc_ALARM_CC6_PRESS_SET
#define Call_CondiCheckPreOCFunc_ALARM_CC6_PRESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_CC6_PRESS_SET	FuncDoNothing
#define Call_InitFunc_ALARM_GFN2_GF_STAT	IniOrClrScrFunc_ALARM_GFN2_GF_STAT
#define Call_CondiCheckFunc_ALARM_GFN2_GF_STAT	CondiCheck_ALARM_GFN2_GF_STAT
#define Call_UpdPortionFunc_ALARM_GFN2_GF_STAT	UpdPorFunc_ALARM_GFN2_GF_STAT
#define Call_UpdOrFlashFunc_ALARM_GFN2_GF_STAT	UpdOrFlasFunc_ALARM_GFN2_GF_STAT
#define Call_CondiCheckPreOCFunc_ALARM_GFN2_GF_STAT	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_GFN2_GF_STAT	FuncDoNothing
#define Call_InitFunc_ALARM_GFN2_GF_SET	IniOrClrScrFunc_ALARM_GFN2_GF_SET
#define Call_CondiCheckFunc_ALARM_GFN2_GF_SET ReturnTrue
#define Call_UpdPortionFunc_ALARM_GFN2_GF_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_GFN2_GF_SET	UpdOrFlasFunc_ALARM_GFN2_GF_SET
#define Call_CondiCheckPreOCFunc_ALARM_GFN2_GF_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_GFN2_GF_SET	FuncDoNothing
#define Call_InitFunc_ALARM_GFN2_N2_STAT	IniOrClrScrFunc_ALARM_GFN2_N2_STAT
#define Call_CondiCheckFunc_ALARM_GFN2_N2_STAT	CondiCheck_ALARM_GFN2_N2_STAT
#define Call_UpdPortionFunc_ALARM_GFN2_N2_STAT	UpdPorFunc_ALARM_GFN2_N2_STAT
#define Call_UpdOrFlashFunc_ALARM_GFN2_N2_STAT	UpdOrFlasFunc_ALARM_GFN2_N2_STAT
#define Call_CondiCheckPreOCFunc_ALARM_GFN2_N2_STAT	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_GFN2_N2_STAT	FuncDoNothing
#define Call_InitFunc_ALARM_GFN2_N2_SET	IniOrClrScrFunc_ALARM_GFN2_N2_SET
#define Call_CondiCheckFunc_ALARM_GFN2_N2_SET ReturnTrue
#define Call_UpdPortionFunc_ALARM_GFN2_N2_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_ALARM_GFN2_N2_SET	UpdOrFlasFunc_ALARM_GFN2_N2_SET
#define Call_CondiCheckPreOCFunc_ALARM_GFN2_N2_SET	ReturnFalse
#define Call_HandlePreOCFunc_ALARM_GFN2_N2_SET	FuncDoNothing
#define Call_InitFunc_S282_ALARM_TURNPRESS	IniOrClrScrFunc_S282_ALARM_TURNPRESS
#define Call_CondiCheckFunc_S282_ALARM_TURNPRESS	CondiCheck_S282_ALARM_TURNPRESS
#define Call_UpdPortionFunc_S282_ALARM_TURNPRESS	UpdPorFunc_S282_ALARM_TURNPRESS
#define Call_UpdOrFlashFunc_S282_ALARM_TURNPRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S282_ALARM_TURNPRESS	CondiPreOcCheck_S282_ALARM_TURNPRESS
#define Call_HandlePreOCFunc_S282_ALARM_TURNPRESS	HandlePreOCFunc_S282_ALARM_TURNPRESS
#define Call_InitFunc_S283_ALARM_TURNPRESS_STAT	IniOrClrScrFunc_S283_ALARM_TURNPRESS_STAT
#define Call_CondiCheckFunc_S283_ALARM_TURNPRESS_STAT ReturnTrue
#define Call_UpdPortionFunc_S283_ALARM_TURNPRESS_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_S283_ALARM_TURNPRESS_STAT	UpdOrFlasFunc_S283_ALARM_TURNPRESS_STAT
#define Call_CondiCheckPreOCFunc_S283_ALARM_TURNPRESS_STAT	ReturnFalse
#define Call_HandlePreOCFunc_S283_ALARM_TURNPRESS_STAT	FuncDoNothing
#define Call_InitFunc_S284_ALARM_TURNPRESS_SET	IniOrClrScrFunc_S284_ALARM_TURNPRESS_SET
#define Call_CondiCheckFunc_S284_ALARM_TURNPRESS_SET ReturnTrue
#define Call_UpdPortionFunc_S284_ALARM_TURNPRESS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S284_ALARM_TURNPRESS_SET	UpdOrFlasFunc_S284_ALARM_TURNPRESS_SET
#define Call_CondiCheckPreOCFunc_S284_ALARM_TURNPRESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_S284_ALARM_TURNPRESS_SET	FuncDoNothing
#define Call_InitFunc_S285_ALARM_ENDPRESS	IniOrClrScrFunc_S285_ALARM_ENDPRESS
#define Call_CondiCheckFunc_S285_ALARM_ENDPRESS	CondiCheck_S285_ALARM_ENDPRESS
#define Call_UpdPortionFunc_S285_ALARM_ENDPRESS	UpdPorFunc_S285_ALARM_ENDPRESS
#define Call_UpdOrFlashFunc_S285_ALARM_ENDPRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S285_ALARM_ENDPRESS	CondiPreOcCheck_S285_ALARM_ENDPRESS
#define Call_HandlePreOCFunc_S285_ALARM_ENDPRESS	HandlePreOCFunc_S285_ALARM_ENDPRESS
#define Call_InitFunc_S286_ALARM_ENDPRESS_SET	IniOrClrScrFunc_S286_ALARM_ENDPRESS_SET
#define Call_CondiCheckFunc_S286_ALARM_ENDPRESS_SET ReturnTrue
#define Call_UpdPortionFunc_S286_ALARM_ENDPRESS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S286_ALARM_ENDPRESS_SET	UpdOrFlasFunc_S286_ALARM_ENDPRESS_SET
#define Call_CondiCheckPreOCFunc_S286_ALARM_ENDPRESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_S286_ALARM_ENDPRESS_SET	FuncDoNothing
#define Call_InitFunc_S353_ALARM_SWITCHPRESS	IniOrClrScrFunc_S353_ALARM_SWITCHPRESS
#define Call_CondiCheckFunc_S353_ALARM_SWITCHPRESS	CondiCheck_S353_ALARM_SWITCHPRESS
#define Call_UpdPortionFunc_S353_ALARM_SWITCHPRESS	UpdPorFunc_S353_ALARM_SWITCHPRESS
#define Call_UpdOrFlashFunc_S353_ALARM_SWITCHPRESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S353_ALARM_SWITCHPRESS	CondiPreOcCheck_S353_ALARM_SWITCHPRESS
#define Call_HandlePreOCFunc_S353_ALARM_SWITCHPRESS	HandlePreOCFunc_S353_ALARM_SWITCHPRESS
#define Call_InitFunc_S354_ALARM_SWITCHPRESS_STAT	IniOrClrScrFunc_S354_ALARM_SWITCHPRESS_STAT
#define Call_CondiCheckFunc_S354_ALARM_SWITCHPRESS_STAT ReturnTrue
#define Call_UpdPortionFunc_S354_ALARM_SWITCHPRESS_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_S354_ALARM_SWITCHPRESS_STAT	UpdOrFlasFunc_S354_ALARM_SWITCHPRESS_STAT
#define Call_CondiCheckPreOCFunc_S354_ALARM_SWITCHPRESS_STAT	ReturnFalse
#define Call_HandlePreOCFunc_S354_ALARM_SWITCHPRESS_STAT	FuncDoNothing
#define Call_InitFunc_S355_ALARM_SWITCHPRESS_SET	IniOrClrScrFunc_S355_ALARM_SWITCHPRESS_SET
#define Call_CondiCheckFunc_S355_ALARM_SWITCHPRESS_SET ReturnTrue
#define Call_UpdPortionFunc_S355_ALARM_SWITCHPRESS_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S355_ALARM_SWITCHPRESS_SET	UpdOrFlasFunc_S355_ALARM_SWITCHPRESS_SET
#define Call_CondiCheckPreOCFunc_S355_ALARM_SWITCHPRESS_SET	ReturnFalse
#define Call_HandlePreOCFunc_S355_ALARM_SWITCHPRESS_SET	FuncDoNothing
#define Call_InitFunc_S289_ALARM_END	IniOrClrScrFunc_S289_ALARM_END
#define Call_CondiCheckFunc_S289_ALARM_END	CondiCheck_S289_ALARM_END
#define Call_UpdPortionFunc_S289_ALARM_END	UpdPorFunc_S289_ALARM_END
#define Call_UpdOrFlashFunc_S289_ALARM_END	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S289_ALARM_END	CondiPreOcCheck_S289_ALARM_END
#define Call_HandlePreOCFunc_S289_ALARM_END	HandlePreOCFunc_S289_ALARM_END
#define Call_InitFunc_S290_ALARM_END_STAT	IniOrClrScrFunc_S290_ALARM_END_STAT
#define Call_CondiCheckFunc_S290_ALARM_END_STAT ReturnTrue
#define Call_UpdPortionFunc_S290_ALARM_END_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_S290_ALARM_END_STAT	UpdOrFlasFunc_S290_ALARM_END_STAT
#define Call_CondiCheckPreOCFunc_S290_ALARM_END_STAT	ReturnFalse
#define Call_HandlePreOCFunc_S290_ALARM_END_STAT	FuncDoNothing
#define Call_InitFunc_S291_ALARM_END_SET	IniOrClrScrFunc_S291_ALARM_END_SET
#define Call_CondiCheckFunc_S291_ALARM_END_SET ReturnTrue
#define Call_UpdPortionFunc_S291_ALARM_END_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S291_ALARM_END_SET	UpdOrFlasFunc_S291_ALARM_END_SET
#define Call_CondiCheckPreOCFunc_S291_ALARM_END_SET	ReturnFalse
#define Call_HandlePreOCFunc_S291_ALARM_END_SET	FuncDoNothing
#define Call_InitFunc_S292_ALARM_WOB	IniOrClrScrFunc_S292_ALARM_WOB
#define Call_CondiCheckFunc_S292_ALARM_WOB	CondiCheck_S292_ALARM_WOB
#define Call_UpdPortionFunc_S292_ALARM_WOB	UpdPorFunc_S292_ALARM_WOB
#define Call_UpdOrFlashFunc_S292_ALARM_WOB	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S292_ALARM_WOB	CondiPreOcCheck_S292_ALARM_WOB
#define Call_HandlePreOCFunc_S292_ALARM_WOB	HandlePreOCFunc_S292_ALARM_WOB
#define Call_InitFunc_S293_ALARM_WOB_STAT	IniOrClrScrFunc_S293_ALARM_WOB_STAT
#define Call_CondiCheckFunc_S293_ALARM_WOB_STAT ReturnTrue
#define Call_UpdPortionFunc_S293_ALARM_WOB_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_S293_ALARM_WOB_STAT	UpdOrFlasFunc_S293_ALARM_WOB_STAT
#define Call_CondiCheckPreOCFunc_S293_ALARM_WOB_STAT	ReturnFalse
#define Call_HandlePreOCFunc_S293_ALARM_WOB_STAT	FuncDoNothing
#define Call_InitFunc_S294_ALARM_WOB_SET	IniOrClrScrFunc_S294_ALARM_WOB_SET
#define Call_CondiCheckFunc_S294_ALARM_WOB_SET ReturnTrue
#define Call_UpdPortionFunc_S294_ALARM_WOB_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S294_ALARM_WOB_SET	UpdOrFlasFunc_S294_ALARM_WOB_SET
#define Call_CondiCheckPreOCFunc_S294_ALARM_WOB_SET	ReturnFalse
#define Call_HandlePreOCFunc_S294_ALARM_WOB_SET	FuncDoNothing
#define Call_InitFunc_S295_ALARM_ICD	IniOrClrScrFunc_S295_ALARM_ICD
#define Call_CondiCheckFunc_S295_ALARM_ICD	CondiCheck_S295_ALARM_ICD
#define Call_UpdPortionFunc_S295_ALARM_ICD	UpdPorFunc_S295_ALARM_ICD
#define Call_UpdOrFlashFunc_S295_ALARM_ICD	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S295_ALARM_ICD	CondiPreOcCheck_S295_ALARM_ICD
#define Call_HandlePreOCFunc_S295_ALARM_ICD	HandlePreOCFunc_S295_ALARM_ICD
#define Call_InitFunc_S296_ALARM_ICD_SET	IniOrClrScrFunc_S296_ALARM_ICD_SET
#define Call_CondiCheckFunc_S296_ALARM_ICD_SET ReturnTrue
#define Call_UpdPortionFunc_S296_ALARM_ICD_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S296_ALARM_ICD_SET	UpdOrFlasFunc_S296_ALARM_ICD_SET
#define Call_CondiCheckPreOCFunc_S296_ALARM_ICD_SET	ReturnFalse
#define Call_HandlePreOCFunc_S296_ALARM_ICD_SET	FuncDoNothing
#define Call_InitFunc_S297_ALARM_O2_NARCOTIC	IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC
#define Call_CondiCheckFunc_S297_ALARM_O2_NARCOTIC	CondiCheck_S297_ALARM_O2_NARCOTIC
#define Call_UpdPortionFunc_S297_ALARM_O2_NARCOTIC	UpdPorFunc_S297_ALARM_O2_NARCOTIC
#define Call_UpdOrFlashFunc_S297_ALARM_O2_NARCOTIC	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S297_ALARM_O2_NARCOTIC	CondiPreOcCheck_S297_ALARM_O2_NARCOTIC
#define Call_HandlePreOCFunc_S297_ALARM_O2_NARCOTIC	HandlePreOCFunc_S297_ALARM_O2_NARCOTIC
#define Call_InitFunc_S297_ALARM_O2_NARCOTIC_SET	IniOrClrScrFunc_S297_ALARM_O2_NARCOTIC_SET
#define Call_CondiCheckFunc_S297_ALARM_O2_NARCOTIC_SET ReturnTrue
#define Call_UpdPortionFunc_S297_ALARM_O2_NARCOTIC_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_S297_ALARM_O2_NARCOTIC_SET	UpdOrFlasFunc_S297_ALARM_O2_NARCOTIC_SET
#define Call_CondiCheckPreOCFunc_S297_ALARM_O2_NARCOTIC_SET	ReturnFalse
#define Call_HandlePreOCFunc_S297_ALARM_O2_NARCOTIC_SET	FuncDoNothing
#define Call_InitFunc_C1_COMPASS_MAIN	IniOrClrScrFunc_C1_COMPASS_MAIN
#define Call_CondiCheckFunc_C1_COMPASS_MAIN ReturnTrue
#define Call_UpdPortionFunc_C1_COMPASS_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_C1_COMPASS_MAIN	UpdOrFlasFunc_C1_COMPASS_MAIN
#define Call_CondiCheckPreOCFunc_C1_COMPASS_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_C1_COMPASS_MAIN	FuncDoNothing
#define Call_InitFunc_C2_COMPASS_MAIN_DIVE	IniOrClrScrFunc_C2_COMPASS_MAIN_DIVE
#define Call_CondiCheckFunc_C2_COMPASS_MAIN_DIVE ReturnTrue
#define Call_UpdPortionFunc_C2_COMPASS_MAIN_DIVE	FuncDoNothing
#define Call_UpdOrFlashFunc_C2_COMPASS_MAIN_DIVE	UpdOrFlasFunc_C2_COMPASS_MAIN_DIVE
#define Call_CondiCheckPreOCFunc_C2_COMPASS_MAIN_DIVE	ReturnFalse
#define Call_HandlePreOCFunc_C2_COMPASS_MAIN_DIVE	FuncDoNothing
#define Call_InitFunc_C3_COMPASS_MAIN_HEADING	FuncDoNothing
#define Call_CondiCheckFunc_C3_COMPASS_MAIN_HEADING ReturnFalse
#define Call_UpdPortionFunc_C3_COMPASS_MAIN_HEADING	FuncDoNothing
#define Call_UpdOrFlashFunc_C3_COMPASS_MAIN_HEADING	UpdOrFlasFunc_C1_COMPASS_MAIN     /*Re-map*/
#define Call_CondiCheckPreOCFunc_C3_COMPASS_MAIN_HEADING	ReturnFalse
#define Call_HandlePreOCFunc_C3_COMPASS_MAIN_HEADING	FuncDoNothing
#define Call_InitFunc_C4_COMPASS_MAIN_HEADING_SET	FuncDoNothing
#define Call_CondiCheckFunc_C4_COMPASS_MAIN_HEADING_SET ReturnFalse
#define Call_UpdPortionFunc_C4_COMPASS_MAIN_HEADING_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_C4_COMPASS_MAIN_HEADING_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C4_COMPASS_MAIN_HEADING_SET	ReturnFalse
#define Call_HandlePreOCFunc_C4_COMPASS_MAIN_HEADING_SET	FuncDoNothing
#define Call_InitFunc_C5_COMPASS_MAIN_HEADING_REV	FuncDoNothing
#define Call_CondiCheckFunc_C5_COMPASS_MAIN_HEADING_REV ReturnFalse
#define Call_UpdPortionFunc_C5_COMPASS_MAIN_HEADING_REV	FuncDoNothing
#define Call_UpdOrFlashFunc_C5_COMPASS_MAIN_HEADING_REV	UpdOrFlasFunc_C1_COMPASS_MAIN   /*Re-map*/
#define Call_CondiCheckPreOCFunc_C5_COMPASS_MAIN_HEADING_REV	ReturnFalse
#define Call_HandlePreOCFunc_C5_COMPASS_MAIN_HEADING_REV	FuncDoNothing
#define Call_InitFunc_C6_COMPASS_MAIN_HEADING_REV_SET	FuncDoNothing
#define Call_CondiCheckFunc_C6_COMPASS_MAIN_HEADING_REV_SET ReturnFalse
#define Call_UpdPortionFunc_C6_COMPASS_MAIN_HEADING_REV_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_C6_COMPASS_MAIN_HEADING_REV_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C6_COMPASS_MAIN_HEADING_REV_SET	ReturnFalse
#define Call_HandlePreOCFunc_C6_COMPASS_MAIN_HEADING_REV_SET	FuncDoNothing
#define Call_InitFunc_C7_COMPASS_CALIBRATION	IniOrClrScrFunc_C7_COMPASS_CALIBRATION
#define Call_CondiCheckFunc_C7_COMPASS_CALIBRATION	CondiCheck_C7_COMPASS_CALIBRATION
#define Call_UpdPortionFunc_C7_COMPASS_CALIBRATION	UpdPorFunc_C7_COMPASS_CALIBRATION
#define Call_UpdOrFlashFunc_C7_COMPASS_CALIBRATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C7_COMPASS_CALIBRATION	CondiPreOcCheck_C7_COMPASS_CALIBRATION
#define Call_HandlePreOCFunc_C7_COMPASS_CALIBRATION	HandlePreOCFunc_C7_COMPASS_CALIBRATION
#define Call_InitFunc_C13_COMPASS_DECLIN_SET	IniOrClrScrFunc_C13_COMPASS_DECLIN_SET
#define Call_CondiCheckFunc_C13_COMPASS_DECLIN_SET	CondiCheck_C13_COMPASS_DECLIN_SET
#define Call_UpdPortionFunc_C13_COMPASS_DECLIN_SET	UpdPorFunc_C13_COMPASS_DECLIN_SET
#define Call_UpdOrFlashFunc_C13_COMPASS_DECLIN_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C13_COMPASS_DECLIN_SET	CondiPreOcCheck_C13_COMPASS_DECLIN_SET
#define Call_HandlePreOCFunc_C13_COMPASS_DECLIN_SET	HandlePreOCFunc_C13_COMPASS_DECLIN_SET
#define Call_InitFunc_C9_COMPASS_PROCESSING	IniOrClrScrFunc_C9_COMPASS_PROCESSING
#define Call_CondiCheckFunc_C9_COMPASS_PROCESSING ReturnTrue
#define Call_UpdPortionFunc_C9_COMPASS_PROCESSING	FuncDoNothing
#define Call_UpdOrFlashFunc_C9_COMPASS_PROCESSING	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C9_COMPASS_PROCESSING	ReturnFalse
#define Call_HandlePreOCFunc_C9_COMPASS_PROCESSING	FuncDoNothing
#define Call_InitFunc_C10_COMPASS_CALIBRATION_PASSED	IniOrClrScrFunc_C10_COMPASS_CALIBRATION_PASSED
#define Call_CondiCheckFunc_C10_COMPASS_CALIBRATION_PASSED ReturnTrue
#define Call_UpdPortionFunc_C10_COMPASS_CALIBRATION_PASSED	FuncDoNothing
#define Call_UpdOrFlashFunc_C10_COMPASS_CALIBRATION_PASSED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C10_COMPASS_CALIBRATION_PASSED	ReturnFalse
#define Call_HandlePreOCFunc_C10_COMPASS_CALIBRATION_PASSED	FuncDoNothing
#define Call_InitFunc_C11_COMPASS_CALIBRATION_FAILED	IniOrClrScrFunc_C11_COMPASS_CALIBRATION_FAILED
#define Call_CondiCheckFunc_C11_COMPASS_CALIBRATION_FAILED ReturnTrue
#define Call_UpdPortionFunc_C11_COMPASS_CALIBRATION_FAILED	FuncDoNothing
#define Call_UpdOrFlashFunc_C11_COMPASS_CALIBRATION_FAILED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_C11_COMPASS_CALIBRATION_FAILED	ReturnFalse
#define Call_HandlePreOCFunc_C11_COMPASS_CALIBRATION_FAILED	FuncDoNothing
#define Call_InitFunc_C14_COMPASS_DECLIN_SETTING	IniOrClrScrFunc_C14_COMPASS_DECLIN_SETTING
#define Call_CondiCheckFunc_C14_COMPASS_DECLIN_SETTING ReturnTrue
#define Call_UpdPortionFunc_C14_COMPASS_DECLIN_SETTING	FuncDoNothing
#define Call_UpdOrFlashFunc_C14_COMPASS_DECLIN_SETTING	UpdOrFlasFunc_C14_COMPASS_DECLIN_SETTING
#define Call_CondiCheckPreOCFunc_C14_COMPASS_DECLIN_SETTING	ReturnFalse
#define Call_HandlePreOCFunc_C14_COMPASS_DECLIN_SETTING	FuncDoNothing
#define Call_InitFunc_S502_GPS_GET_CURRENT_LOCATION	IniOrClrScrFunc_S502_GPS_GET_CURRENT_LOCATION
#define Call_CondiCheckFunc_S502_GPS_GET_CURRENT_LOCATION	CondiCheck_S502_GPS_GET_CURRENT_LOCATION
#define Call_UpdPortionFunc_S502_GPS_GET_CURRENT_LOCATION	UpdPorFunc_S502_GPS_GET_CURRENT_LOCATION
#define Call_UpdOrFlashFunc_S502_GPS_GET_CURRENT_LOCATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S502_GPS_GET_CURRENT_LOCATION	CondiPreOcCheck_S502_GPS_GET_CURRENT_LOCATION
#define Call_HandlePreOCFunc_S502_GPS_GET_CURRENT_LOCATION	HandlePreOCFunc_S502_GPS_GET_CURRENT_LOCATION
#define Call_InitFunc_S503_GPS_20DATA_DELETE_TO_SAVE	IniOrClrScrFunc_S503_GPS_20DATA_DELETE_TO_SAVE
#define Call_CondiCheckFunc_S503_GPS_20DATA_DELETE_TO_SAVE ReturnTrue
#define Call_UpdPortionFunc_S503_GPS_20DATA_DELETE_TO_SAVE	FuncDoNothing
#define Call_UpdOrFlashFunc_S503_GPS_20DATA_DELETE_TO_SAVE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S503_GPS_20DATA_DELETE_TO_SAVE	ReturnFalse
#define Call_HandlePreOCFunc_S503_GPS_20DATA_DELETE_TO_SAVE	FuncDoNothing
#define Call_InitFunc_S504_GPS_INIT	IniOrClrScrFunc_S504_GPS_INIT
#define Call_CondiCheckFunc_S504_GPS_INIT ReturnTrue
#define Call_UpdPortionFunc_S504_GPS_INIT	FuncDoNothing
#define Call_UpdOrFlashFunc_S504_GPS_INIT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S504_GPS_INIT	ReturnFalse
#define Call_HandlePreOCFunc_S504_GPS_INIT	FuncDoNothing
#define Call_InitFunc_S505_GPS_WAIT_SIGNAL	IniOrClrScrFunc_S505_GPS_WAIT_SIGNAL
#define Call_CondiCheckFunc_S505_GPS_WAIT_SIGNAL ReturnTrue
#define Call_UpdPortionFunc_S505_GPS_WAIT_SIGNAL	FuncDoNothing
#define Call_UpdOrFlashFunc_S505_GPS_WAIT_SIGNAL	UpdOrFlasFunc_S505_GPS_WAIT_SIGNAL
#define Call_CondiCheckPreOCFunc_S505_GPS_WAIT_SIGNAL	ReturnFalse
#define Call_HandlePreOCFunc_S505_GPS_WAIT_SIGNAL	FuncDoNothing
#define Call_InitFunc_S506_GPS_NO_SIGNAL	IniOrClrScrFunc_S506_GPS_NO_SIGNAL
#define Call_CondiCheckFunc_S506_GPS_NO_SIGNAL ReturnTrue
#define Call_UpdPortionFunc_S506_GPS_NO_SIGNAL	FuncDoNothing
#define Call_UpdOrFlashFunc_S506_GPS_NO_SIGNAL	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S506_GPS_NO_SIGNAL	ReturnFalse
#define Call_HandlePreOCFunc_S506_GPS_NO_SIGNAL	FuncDoNothing
#define Call_InitFunc_S507_GPS_SAVE_LOCATION_STAT	IniOrClrScrFunc_S507_GPS_SAVE_LOCATION_STAT
#define Call_CondiCheckFunc_S507_GPS_SAVE_LOCATION_STAT ReturnTrue
#define Call_UpdPortionFunc_S507_GPS_SAVE_LOCATION_STAT	FuncDoNothing
#define Call_UpdOrFlashFunc_S507_GPS_SAVE_LOCATION_STAT	UpdOrFlasFunc_S507_GPS_SAVE_LOCATION_STAT
#define Call_CondiCheckPreOCFunc_S507_GPS_SAVE_LOCATION_STAT	ReturnFalse
#define Call_HandlePreOCFunc_S507_GPS_SAVE_LOCATION_STAT	FuncDoNothing
#define Call_InitFunc_S508_GPS_LOCATION_SAVED	IniOrClrScrFunc_S508_GPS_LOCATION_SAVED
#define Call_CondiCheckFunc_S508_GPS_LOCATION_SAVED ReturnTrue
#define Call_UpdPortionFunc_S508_GPS_LOCATION_SAVED	FuncDoNothing
#define Call_UpdOrFlashFunc_S508_GPS_LOCATION_SAVED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S508_GPS_LOCATION_SAVED	ReturnFalse
#define Call_HandlePreOCFunc_S508_GPS_LOCATION_SAVED	FuncDoNothing
#define Call_InitFunc_S509_GPS_WAYFINDER	IniOrClrScrFunc_S509_GPS_WAYFINDER
#define Call_CondiCheckFunc_S509_GPS_WAYFINDER	CondiCheck_S509_GPS_WAYFINDER
#define Call_UpdPortionFunc_S509_GPS_WAYFINDER	UpdPorFunc_S509_GPS_WAYFINDER
#define Call_UpdOrFlashFunc_S509_GPS_WAYFINDER	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S509_GPS_WAYFINDER	CondiPreOcCheck_S509_GPS_WAYFINDER
#define Call_HandlePreOCFunc_S509_GPS_WAYFINDER	HandlePreOCFunc_S509_GPS_WAYFINDER
#define Call_InitFunc_S510_GPS_WAYFINDER_LIST	IniOrClrScrFunc_S510_GPS_WAYFINDER_LIST
#define Call_CondiCheckFunc_S510_GPS_WAYFINDER_LIST ReturnTrue
#define Call_UpdPortionFunc_S510_GPS_WAYFINDER_LIST	FuncDoNothing
#define Call_UpdOrFlashFunc_S510_GPS_WAYFINDER_LIST	UpdOrFlasFunc_S510_GPS_WAYFINDER_LIST
#define Call_CondiCheckPreOCFunc_S510_GPS_WAYFINDER_LIST	ReturnFalse
#define Call_HandlePreOCFunc_S510_GPS_WAYFINDER_LIST	FuncDoNothing
#define Call_InitFunc_S511_GPS_WAYFINDER_GOTO	IniOrClrScrFunc_S511_GPS_WAYFINDER_GOTO
#define Call_CondiCheckFunc_S511_GPS_WAYFINDER_GOTO ReturnTrue
#define Call_UpdPortionFunc_S511_GPS_WAYFINDER_GOTO	FuncDoNothing
#define Call_UpdOrFlashFunc_S511_GPS_WAYFINDER_GOTO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S511_GPS_WAYFINDER_GOTO	ReturnFalse
#define Call_HandlePreOCFunc_S511_GPS_WAYFINDER_GOTO	FuncDoNothing
#define Call_InitFunc_S516_GPS_WAYFINDER_MAIN	FuncDoNothing
#define Call_CondiCheckFunc_S516_GPS_WAYFINDER_MAIN ReturnFalse
#define Call_UpdPortionFunc_S516_GPS_WAYFINDER_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_S516_GPS_WAYFINDER_MAIN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S516_GPS_WAYFINDER_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_S516_GPS_WAYFINDER_MAIN	FuncDoNothing
#define Call_InitFunc_S519_GPS_WAYFINDER_EXIT	IniOrClrScrFunc_S519_GPS_WAYFINDER_EXIT
#define Call_CondiCheckFunc_S519_GPS_WAYFINDER_EXIT	CondiCheck_S519_GPS_WAYFINDER_EXIT
#define Call_UpdPortionFunc_S519_GPS_WAYFINDER_EXIT	UpdPorFunc_S519_GPS_WAYFINDER_EXIT
#define Call_UpdOrFlashFunc_S519_GPS_WAYFINDER_EXIT	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S519_GPS_WAYFINDER_EXIT	CondiPreOcCheck_S519_GPS_WAYFINDER_EXIT
#define Call_HandlePreOCFunc_S519_GPS_WAYFINDER_EXIT	HandlePreOCFunc_S519_GPS_WAYFINDER_EXIT
#define Call_InitFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	IniOrClrScrFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION
#define Call_CondiCheckFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	CondiCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION
#define Call_UpdPortionFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	UpdPorFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION
#define Call_UpdOrFlashFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	CondiPreOcCheck_S519a_GPS_WAYFINDER_CHANGE_LOCATION
#define Call_HandlePreOCFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION	HandlePreOCFunc_S519a_GPS_WAYFINDER_CHANGE_LOCATION
#define Call_InitFunc_S518_GPS_WAYFINDERLOCATION_REACHED	IniOrClrScrFunc_S518_GPS_WAYFINDERLOCATION_REACHED
#define Call_CondiCheckFunc_S518_GPS_WAYFINDERLOCATION_REACHED ReturnTrue
#define Call_UpdPortionFunc_S518_GPS_WAYFINDERLOCATION_REACHED	FuncDoNothing
#define Call_UpdOrFlashFunc_S518_GPS_WAYFINDERLOCATION_REACHED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S518_GPS_WAYFINDERLOCATION_REACHED	ReturnFalse
#define Call_HandlePreOCFunc_S518_GPS_WAYFINDERLOCATION_REACHED	FuncDoNothing
#define Call_InitFunc_S520_GPS_DELETE_LOCATION	IniOrClrScrFunc_S520_GPS_DELETE_LOCATION
#define Call_CondiCheckFunc_S520_GPS_DELETE_LOCATION	CondiCheck_S520_GPS_DELETE_LOCATION
#define Call_UpdPortionFunc_S520_GPS_DELETE_LOCATION	UpdPorFunc_S520_GPS_DELETE_LOCATION
#define Call_UpdOrFlashFunc_S520_GPS_DELETE_LOCATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S520_GPS_DELETE_LOCATION	CondiPreOcCheck_S520_GPS_DELETE_LOCATION
#define Call_HandlePreOCFunc_S520_GPS_DELETE_LOCATION	HandlePreOCFunc_S520_GPS_DELETE_LOCATION
#define Call_InitFunc_S521_GPS_WAYFINDER_LIST	IniOrClrScrFunc_S510_GPS_WAYFINDER_LIST /*Re-map*/
#define Call_CondiCheckFunc_S521_GPS_WAYFINDER_LIST ReturnTrue
#define Call_UpdPortionFunc_S521_GPS_WAYFINDER_LIST	FuncDoNothing
#define Call_UpdOrFlashFunc_S521_GPS_WAYFINDER_LIST	UpdOrFlasFunc_S510_GPS_WAYFINDER_LIST /*Re-map*/
#define Call_CondiCheckPreOCFunc_S521_GPS_WAYFINDER_LIST	ReturnFalse
#define Call_HandlePreOCFunc_S521_GPS_WAYFINDER_LIST	FuncDoNothing
#define Call_InitFunc_S522_GPS_DELETE_LOCATION	IniOrClrScrFunc_S522_GPS_DELETE_LOCATION
#define Call_CondiCheckFunc_S522_GPS_DELETE_LOCATION ReturnTrue
#define Call_UpdPortionFunc_S522_GPS_DELETE_LOCATION	FuncDoNothing
#define Call_UpdOrFlashFunc_S522_GPS_DELETE_LOCATION	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S522_GPS_DELETE_LOCATION	ReturnFalse
#define Call_HandlePreOCFunc_S522_GPS_DELETE_LOCATION	FuncDoNothing
#define Call_InitFunc_S523_GPS_LOCATION_DELETED	IniOrClrScrFunc_S523_GPS_LOCATION_DELETED
#define Call_CondiCheckFunc_S523_GPS_LOCATION_DELETED ReturnTrue
#define Call_UpdPortionFunc_S523_GPS_LOCATION_DELETED	FuncDoNothing
#define Call_UpdOrFlashFunc_S523_GPS_LOCATION_DELETED	FuncDoNothing
#define Call_CondiCheckPreOCFunc_S523_GPS_LOCATION_DELETED	ReturnFalse
#define Call_HandlePreOCFunc_S523_GPS_LOCATION_DELETED	FuncDoNothing
#define Call_InitFunc_DIVE_GAUGE_MAIN	IniOrClrScrFunc_DIVE_GAUGE_MAIN
#define Call_CondiCheckFunc_DIVE_GAUGE_MAIN ReturnTrue
#define Call_UpdPortionFunc_DIVE_GAUGE_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_GAUGE_MAIN	UpdOrFlasFunc_DIVE_GAUGE_MAIN
#define Call_CondiCheckPreOCFunc_DIVE_GAUGE_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_GAUGE_MAIN	FuncDoNothing
#define Call_InitFunc_DIVE_GAUGE_ALT	IniOrClrScrFunc_DIVE_GAUGE_ALT
#define Call_CondiCheckFunc_DIVE_GAUGE_ALT ReturnTrue
#define Call_UpdPortionFunc_DIVE_GAUGE_ALT	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_GAUGE_ALT	UpdOrFlasFunc_DIVE_GAUGE_ALT
#define Call_CondiCheckPreOCFunc_DIVE_GAUGE_ALT	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_GAUGE_ALT	FuncDoNothing
#define Call_InitFunc_DIVE_DEPTH_AND_DIVETIME	IniOrClrScrFunc_DIVE_DEPTH_AND_DIVETIME
#define Call_CondiCheckFunc_DIVE_DEPTH_AND_DIVETIME ReturnTrue
#define Call_UpdPortionFunc_DIVE_DEPTH_AND_DIVETIME	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_DEPTH_AND_DIVETIME	UpdOrFlasFunc_DIVE_DEPTH_AND_DIVETIME
#define Call_CondiCheckPreOCFunc_DIVE_DEPTH_AND_DIVETIME	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_DEPTH_AND_DIVETIME	FuncDoNothing
#define Call_InitFunc_DIVE_CC_MAIN	IniOrClrScrFunc_DIVE_CC_MAIN
#define Call_CondiCheckFunc_DIVE_CC_MAIN ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_MAIN	UpdOrFlasFunc_DIVE_CC_MAIN
#define Call_CondiCheckPreOCFunc_DIVE_CC_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_MAIN	FuncDoNothing
#define Call_InitFunc_DIVE_CC_ALT_1	IniOrClrScrFunc_DIVE_OC_ALT_1 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_CC_ALT_1 ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_ALT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_ALT_1	UpdOrFlasFunc_DIVE_OC_ALT_1 /*Re-map*/
#define Call_CondiCheckPreOCFunc_DIVE_CC_ALT_1	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_ALT_1	FuncDoNothing
#define Call_InitFunc_DIVE_CC_ALT_2	IniOrClrScrFunc_DIVE_OC_ALT_2 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_CC_ALT_2 ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_ALT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_ALT_2	UpdOrFlasFunc_DIVE_OC_ALT_2 /*Re-map*/
#define Call_CondiCheckPreOCFunc_DIVE_CC_ALT_2	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_ALT_2	FuncDoNothing
#define Call_InitFunc_DIVE_CC_ALT_3	IniOrClrScrFunc_DIVE_CC_ALT_3
#define Call_CondiCheckFunc_DIVE_CC_ALT_3 ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_ALT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_ALT_3	UpdOrFlasFunc_DIVE_CC_ALT_3
#define Call_CondiCheckPreOCFunc_DIVE_CC_ALT_3	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_ALT_3	FuncDoNothing
#define Call_InitFunc_DIVE_CC_ALT_4	IniOrClrScrFunc_DIVE_OC_ALT_4 /*Re-map*/
#define Call_CondiCheckFunc_DIVE_CC_ALT_4 ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_ALT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_ALT_4	UpdOrFlasFunc_DIVE_OC_ALT_4 /*Re-map*/
#define Call_CondiCheckPreOCFunc_DIVE_CC_ALT_4	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_ALT_4	FuncDoNothing
#define Call_InitFunc_DIVE_CC_ALT_5	IniOrClrScrFunc_DIVE_CC_ALT_5
#define Call_CondiCheckFunc_DIVE_CC_ALT_5 ReturnTrue
#define Call_UpdPortionFunc_DIVE_CC_ALT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_CC_ALT_5	UpdOrFlasFunc_DIVE_CC_ALT_5
#define Call_CondiCheckPreOCFunc_DIVE_CC_ALT_5	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_CC_ALT_5	FuncDoNothing
#define Call_InitFunc_DIVE_OC_MAIN	IniOrClrScrFunc_DIVE_OC_MAIN
#define Call_CondiCheckFunc_DIVE_OC_MAIN ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_MAIN	UpdOrFlasFunc_DIVE_OC_MAIN
#define Call_CondiCheckPreOCFunc_DIVE_OC_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_MAIN	FuncDoNothing
#define Call_InitFunc_DIVE_OC_ALT_1	IniOrClrScrFunc_DIVE_OC_ALT_1
#define Call_CondiCheckFunc_DIVE_OC_ALT_1 ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_ALT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_ALT_1	UpdOrFlasFunc_DIVE_OC_ALT_1
#define Call_CondiCheckPreOCFunc_DIVE_OC_ALT_1	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_ALT_1	FuncDoNothing
#define Call_InitFunc_DIVE_OC_ALT_2	IniOrClrScrFunc_DIVE_OC_ALT_2
#define Call_CondiCheckFunc_DIVE_OC_ALT_2 ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_ALT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_ALT_2	UpdOrFlasFunc_DIVE_OC_ALT_2
#define Call_CondiCheckPreOCFunc_DIVE_OC_ALT_2	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_ALT_2	FuncDoNothing
#define Call_InitFunc_DIVE_OC_ALT_3	IniOrClrScrFunc_DIVE_OC_ALT_3
#define Call_CondiCheckFunc_DIVE_OC_ALT_3 ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_ALT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_ALT_3	UpdOrFlasFunc_DIVE_OC_ALT_3
#define Call_CondiCheckPreOCFunc_DIVE_OC_ALT_3	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_ALT_3	FuncDoNothing
#define Call_InitFunc_DIVE_OC_ALT_4	IniOrClrScrFunc_DIVE_OC_ALT_4
#define Call_CondiCheckFunc_DIVE_OC_ALT_4 ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_ALT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_ALT_4	UpdOrFlasFunc_DIVE_OC_ALT_4
#define Call_CondiCheckPreOCFunc_DIVE_OC_ALT_4	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_ALT_4	FuncDoNothing
#define Call_InitFunc_DIVE_OC_ALT_5	IniOrClrScrFunc_DIVE_OC_ALT_5
#define Call_CondiCheckFunc_DIVE_OC_ALT_5 ReturnTrue
#define Call_UpdPortionFunc_DIVE_OC_ALT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_OC_ALT_5	UpdOrFlasFunc_DIVE_OC_ALT_5
#define Call_CondiCheckPreOCFunc_DIVE_OC_ALT_5	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_OC_ALT_5	FuncDoNothing
#define Call_InitFunc_DIVE_SM_MAIN	IniOrClrScrFunc_DIVE_SM_MAIN
#define Call_CondiCheckFunc_DIVE_SM_MAIN ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_MAIN	UpdOrFlasFunc_DIVE_SM_MAIN
#define Call_CondiCheckPreOCFunc_DIVE_SM_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_MAIN	FuncDoNothing
#define Call_InitFunc_DIVE_SM_ALT_1	IniOrClrScrFunc_DIVE_SM_ALT_1
#define Call_CondiCheckFunc_DIVE_SM_ALT_1 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_ALT_1	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_ALT_1	UpdOrFlasFunc_DIVE_SM_ALT_1
#define Call_CondiCheckPreOCFunc_DIVE_SM_ALT_1	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_ALT_1	FuncDoNothing
#define Call_InitFunc_DIVE_SM_ALT_2	IniOrClrScrFunc_DIVE_SM_ALT_2
#define Call_CondiCheckFunc_DIVE_SM_ALT_2 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_ALT_2	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_ALT_2	UpdOrFlasFunc_DIVE_SM_ALT_2
#define Call_CondiCheckPreOCFunc_DIVE_SM_ALT_2	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_ALT_2	FuncDoNothing
#define Call_InitFunc_DIVE_SM_ALT_3	IniOrClrScrFunc_DIVE_SM_ALT_3
#define Call_CondiCheckFunc_DIVE_SM_ALT_3 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_ALT_3	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_ALT_3	UpdOrFlasFunc_DIVE_SM_ALT_3
#define Call_CondiCheckPreOCFunc_DIVE_SM_ALT_3	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_ALT_3	FuncDoNothing
#define Call_InitFunc_DIVE_SM_ALT_4	IniOrClrScrFunc_DIVE_SM_ALT_4
#define Call_CondiCheckFunc_DIVE_SM_ALT_4 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_ALT_4	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_ALT_4	UpdOrFlasFunc_DIVE_SM_ALT_4
#define Call_CondiCheckPreOCFunc_DIVE_SM_ALT_4	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_ALT_4	FuncDoNothing
#define Call_InitFunc_DIVE_SM_ALT_5	IniOrClrScrFunc_DIVE_SM_ALT_5
#define Call_CondiCheckFunc_DIVE_SM_ALT_5 ReturnTrue
#define Call_UpdPortionFunc_DIVE_SM_ALT_5	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_SM_ALT_5	UpdOrFlasFunc_DIVE_SM_ALT_5
#define Call_CondiCheckPreOCFunc_DIVE_SM_ALT_5	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_SM_ALT_5	FuncDoNothing
#define Call_InitFunc_DIVE_GSM_MAIN	IniOrClrScrFunc_DIVE_GSM_MAIN
#define Call_CondiCheckFunc_DIVE_GSM_MAIN ReturnTrue
#define Call_UpdPortionFunc_DIVE_GSM_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_GSM_MAIN	UpdOrFlasFunc_DIVE_GSM_MAIN
#define Call_CondiCheckPreOCFunc_DIVE_GSM_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_GSM_MAIN	FuncDoNothing
#define Call_InitFunc_DIVE_GSM_ALT	IniOrClrScrFunc_DIVE_GAUGE_ALT /*Re-map*/
#define Call_CondiCheckFunc_DIVE_GSM_ALT ReturnTrue
#define Call_UpdPortionFunc_DIVE_GSM_ALT	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVE_GSM_ALT	UpdOrFlasFunc_DIVE_GAUGE_ALT /*Re-map*/
#define Call_CondiCheckPreOCFunc_DIVE_GSM_ALT	ReturnFalse
#define Call_HandlePreOCFunc_DIVE_GSM_ALT	FuncDoNothing
#define Call_InitFunc_DIVEMAINMENU_GASSWITCH	IniOrClrScrFunc_DIVEMAINMENU_GASSWITCH
#define Call_CondiCheckFunc_DIVEMAINMENU_GASSWITCH	CondiCheck_DIVEMAINMENU_GASSWITCH
#define Call_UpdPortionFunc_DIVEMAINMENU_GASSWITCH	UpdPorFunc_DIVEMAINMENU_GASSWITCH
#define Call_UpdOrFlashFunc_DIVEMAINMENU_GASSWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_GASSWITCH	CondiPreOcCheck_DIVEMAINMENU_GASSWITCH
#define Call_HandlePreOCFunc_DIVEMAINMENU_GASSWITCH	HandlePreOCFunc_DIVEMAINMENU_GASSWITCH
#define Call_InitFunc_DIVEMAINMENU_BRIGHTNESS	IniOrClrScrFunc_DIVEMAINMENU_BRIGHTNESS
#define Call_CondiCheckFunc_DIVEMAINMENU_BRIGHTNESS	CondiCheck_DIVEMAINMENU_BRIGHTNESS
#define Call_UpdPortionFunc_DIVEMAINMENU_BRIGHTNESS	UpdPorFunc_DIVEMAINMENU_BRIGHTNESS
#define Call_UpdOrFlashFunc_DIVEMAINMENU_BRIGHTNESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_BRIGHTNESS	CondiPreOcCheck_DIVEMAINMENU_BRIGHTNESS
#define Call_HandlePreOCFunc_DIVEMAINMENU_BRIGHTNESS	HandlePreOCFunc_DIVEMAINMENU_BRIGHTNESS
#define Call_InitFunc_DIVEMAINMENU_DIVEMENU	IniOrClrScrFunc_DIVEMAINMENU_DIVEMENU
#define Call_CondiCheckFunc_DIVEMAINMENU_DIVEMENU	CondiCheck_DIVEMAINMENU_DIVEMENU
#define Call_UpdPortionFunc_DIVEMAINMENU_DIVEMENU	UpdPorFunc_DIVEMAINMENU_DIVEMENU
#define Call_UpdOrFlashFunc_DIVEMAINMENU_DIVEMENU	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_DIVEMENU	CondiPreOcCheck_DIVEMAINMENU_DIVEMENU
#define Call_HandlePreOCFunc_DIVEMAINMENU_DIVEMENU	HandlePreOCFunc_DIVEMAINMENU_DIVEMENU
#define Call_InitFunc_DIVEMAINMENU_SLATES	IniOrClrScrFunc_DIVEMAINMENU_SLATES
#define Call_CondiCheckFunc_DIVEMAINMENU_SLATES	CondiCheck_DIVEMAINMENU_SLATES
#define Call_UpdPortionFunc_DIVEMAINMENU_SLATES	UpdPorFunc_DIVEMAINMENU_SLATES
#define Call_UpdOrFlashFunc_DIVEMAINMENU_SLATES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_SLATES	CondiPreOcCheck_DIVEMAINMENU_SLATES
#define Call_HandlePreOCFunc_DIVEMAINMENU_SLATES	HandlePreOCFunc_DIVEMAINMENU_SLATES
#define Call_InitFunc_DIVEMAINMENU_TMTSWITCH	IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH
#define Call_CondiCheckFunc_DIVEMAINMENU_TMTSWITCH	CondiCheck_DIVEMAINMENU_TMTSWITCH
#define Call_UpdPortionFunc_DIVEMAINMENU_TMTSWITCH	UpdPorFunc_DIVEMAINMENU_TMTSWITCH
#define Call_UpdOrFlashFunc_DIVEMAINMENU_TMTSWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_TMTSWITCH	CondiPreOcCheck_DIVEMAINMENU_TMTSWITCH
#define Call_HandlePreOCFunc_DIVEMAINMENU_TMTSWITCH	HandlePreOCFunc_DIVEMAINMENU_TMTSWITCH
#define Call_InitFunc_DIVEMAINMENU_RESETAVGDEPTH	IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH
#define Call_CondiCheckFunc_DIVEMAINMENU_RESETAVGDEPTH	CondiCheck_DIVEMAINMENU_RESETAVGDEPTH
#define Call_UpdPortionFunc_DIVEMAINMENU_RESETAVGDEPTH	UpdPorFunc_DIVEMAINMENU_RESETAVGDEPTH
#define Call_UpdOrFlashFunc_DIVEMAINMENU_RESETAVGDEPTH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_RESETAVGDEPTH	CondiPreOcCheck_DIVEMAINMENU_RESETAVGDEPTH
#define Call_HandlePreOCFunc_DIVEMAINMENU_RESETAVGDEPTH	HandlePreOCFunc_DIVEMAINMENU_RESETAVGDEPTH
#define Call_InitFunc_DIVEMAINMENU_DIVEPROFILE	IniOrClrScrFunc_DIVEMAINMENU_DIVEPROFILE
#define Call_CondiCheckFunc_DIVEMAINMENU_DIVEPROFILE	CondiCheck_DIVEMAINMENU_DIVEPROFILE
#define Call_UpdPortionFunc_DIVEMAINMENU_DIVEPROFILE	UpdPorFunc_DIVEMAINMENU_DIVEPROFILE
#define Call_UpdOrFlashFunc_DIVEMAINMENU_DIVEPROFILE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_DIVEPROFILE	CondiPreOcCheck_DIVEMAINMENU_DIVEPROFILE
#define Call_HandlePreOCFunc_DIVEMAINMENU_DIVEPROFILE	HandlePreOCFunc_DIVEMAINMENU_DIVEPROFILE
#define Call_InitFunc_DIVEMAINMENU_SPSWITCH	IniOrClrScrFunc_DIVEMAINMENU_SPSWITCH
#define Call_CondiCheckFunc_DIVEMAINMENU_SPSWITCH	CondiCheck_DIVEMAINMENU_SPSWITCH
#define Call_UpdPortionFunc_DIVEMAINMENU_SPSWITCH	UpdPorFunc_DIVEMAINMENU_SPSWITCH
#define Call_UpdOrFlashFunc_DIVEMAINMENU_SPSWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_SPSWITCH	CondiPreOcCheck_DIVEMAINMENU_SPSWITCH
#define Call_HandlePreOCFunc_DIVEMAINMENU_SPSWITCH	HandlePreOCFunc_DIVEMAINMENU_SPSWITCH
#define Call_InitFunc_DIVEMAINMENU_SWITCHCC2BO	IniOrClrScrFunc_DIVEMAINMENU_SWITCHCC2BO
#define Call_CondiCheckFunc_DIVEMAINMENU_SWITCHCC2BO	CondiCheck_DIVEMAINMENU_SWITCHCC2BO
#define Call_UpdPortionFunc_DIVEMAINMENU_SWITCHCC2BO	UpdPorFunc_DIVEMAINMENU_SWITCHCC2BO
#define Call_UpdOrFlashFunc_DIVEMAINMENU_SWITCHCC2BO	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_SWITCHCC2BO	CondiPreOcCheck_DIVEMAINMENU_SWITCHCC2BO
#define Call_HandlePreOCFunc_DIVEMAINMENU_SWITCHCC2BO	HandlePreOCFunc_DIVEMAINMENU_SWITCHCC2BO
#define Call_InitFunc_DIVEMAINMENU_SWITCHBO2CC	IniOrClrScrFunc_DIVEMAINMENU_SWITCHBO2CC
#define Call_CondiCheckFunc_DIVEMAINMENU_SWITCHBO2CC	CondiCheck_DIVEMAINMENU_SWITCHBO2CC
#define Call_UpdPortionFunc_DIVEMAINMENU_SWITCHBO2CC	UpdPorFunc_DIVEMAINMENU_SWITCHBO2CC
#define Call_UpdOrFlashFunc_DIVEMAINMENU_SWITCHBO2CC	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_SWITCHBO2CC	CondiPreOcCheck_DIVEMAINMENU_SWITCHBO2CC
#define Call_HandlePreOCFunc_DIVEMAINMENU_SWITCHBO2CC	HandlePreOCFunc_DIVEMAINMENU_SWITCHBO2CC
#define Call_InitFunc_DIVEMAINMENU_TMTSWITCH_SET	IniOrClrScrFunc_DIVEMAINMENU_TMTSWITCH_SET
#define Call_CondiCheckFunc_DIVEMAINMENU_TMTSWITCH_SET ReturnTrue
#define Call_UpdPortionFunc_DIVEMAINMENU_TMTSWITCH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMAINMENU_TMTSWITCH_SET	UpdOrFlasFunc_DIVEMAINMENU_TMTSWITCH_SET
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_TMTSWITCH_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMAINMENU_TMTSWITCH_SET	FuncDoNothing
#define Call_InitFunc_DIVEMAINMENU_RESETAVGDEPTH_SET	IniOrClrScrFunc_DIVEMAINMENU_RESETAVGDEPTH_SET
#define Call_CondiCheckFunc_DIVEMAINMENU_RESETAVGDEPTH_SET ReturnTrue
#define Call_UpdPortionFunc_DIVEMAINMENU_RESETAVGDEPTH_SET	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMAINMENU_RESETAVGDEPTH_SET	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_RESETAVGDEPTH_SET	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMAINMENU_RESETAVGDEPTH_SET	FuncDoNothing
#define Call_InitFunc_DIVEMENU_SETSP	IniOrClrScrFunc_DIVEMENU_SETSP
#define Call_CondiCheckFunc_DIVEMENU_SETSP	CondiCheck_DIVEMENU_SETSP
#define Call_UpdPortionFunc_DIVEMENU_SETSP	UpdPorFunc_DIVEMENU_SETSP
#define Call_UpdOrFlashFunc_DIVEMENU_SETSP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_SETSP	CondiPreOcCheck_DIVEMENU_SETSP
#define Call_HandlePreOCFunc_DIVEMENU_SETSP	HandlePreOCFunc_DIVEMENU_SETSP
#define Call_InitFunc_DIVEMENU_SETGASES	IniOrClrScrFunc_DIVEMENU_SETGASES
#define Call_CondiCheckFunc_DIVEMENU_SETGASES	CondiCheck_DIVEMENU_SETGASES
#define Call_UpdPortionFunc_DIVEMENU_SETGASES	UpdPorFunc_DIVEMENU_SETGASES
#define Call_UpdOrFlashFunc_DIVEMENU_SETGASES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_SETGASES	CondiPreOcCheck_DIVEMENU_SETGASES
#define Call_HandlePreOCFunc_DIVEMENU_SETGASES	HandlePreOCFunc_DIVEMENU_SETGASES
#define Call_InitFunc_DIVEMENU_DIVEPROFILEGRAPH	IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH
#define Call_CondiCheckFunc_DIVEMENU_DIVEPROFILEGRAPH	CondiCheck_DIVEMENU_DIVEPROFILEGRAPH
#define Call_UpdPortionFunc_DIVEMENU_DIVEPROFILEGRAPH	UpdPorFunc_DIVEMENU_DIVEPROFILEGRAPH
#define Call_UpdOrFlashFunc_DIVEMENU_DIVEPROFILEGRAPH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_DIVEPROFILEGRAPH	CondiPreOcCheck_DIVEMENU_DIVEPROFILEGRAPH
#define Call_HandlePreOCFunc_DIVEMENU_DIVEPROFILEGRAPH	HandlePreOCFunc_DIVEMENU_DIVEPROFILEGRAPH
#define Call_InitFunc_DIVEMENU_BAILOUTPO2LIMITS	IniOrClrScrFunc_DIVEMENU_BAILOUTPO2LIMITS
#define Call_CondiCheckFunc_DIVEMENU_BAILOUTPO2LIMITS	CondiCheck_DIVEMENU_BAILOUTPO2LIMITS
#define Call_UpdPortionFunc_DIVEMENU_BAILOUTPO2LIMITS	UpdPorFunc_DIVEMENU_BAILOUTPO2LIMITS
#define Call_UpdOrFlashFunc_DIVEMENU_BAILOUTPO2LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_BAILOUTPO2LIMITS	CondiPreOcCheck_DIVEMENU_BAILOUTPO2LIMITS
#define Call_HandlePreOCFunc_DIVEMENU_BAILOUTPO2LIMITS	HandlePreOCFunc_DIVEMENU_BAILOUTPO2LIMITS
#define Call_InitFunc_DIVEMENU_DECOSTOPS	IniOrClrScrFunc_DIVEMENU_DECOSTOPS
#define Call_CondiCheckFunc_DIVEMENU_DECOSTOPS	CondiCheck_DIVEMENU_DECOSTOPS
#define Call_UpdPortionFunc_DIVEMENU_DECOSTOPS	UpdPorFunc_DIVEMENU_DECOSTOPS
#define Call_UpdOrFlashFunc_DIVEMENU_DECOSTOPS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_DECOSTOPS	CondiPreOcCheck_DIVEMENU_DECOSTOPS
#define Call_HandlePreOCFunc_DIVEMENU_DECOSTOPS	HandlePreOCFunc_DIVEMENU_DECOSTOPS
#define Call_InitFunc_DIVEMENU_SETGFHIGH	IniOrClrScrFunc_DIVEMENU_SETGFHIGH
#define Call_CondiCheckFunc_DIVEMENU_SETGFHIGH	CondiCheck_DIVEMENU_SETGFHIGH
#define Call_UpdPortionFunc_DIVEMENU_SETGFHIGH	UpdPorFunc_DIVEMENU_SETGFHIGH
#define Call_UpdOrFlashFunc_DIVEMENU_SETGFHIGH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_SETGFHIGH	CondiPreOcCheck_DIVEMENU_SETGFHIGH
#define Call_HandlePreOCFunc_DIVEMENU_SETGFHIGH	HandlePreOCFunc_DIVEMENU_SETGFHIGH
#define Call_InitFunc_DIVEMENU_PO2LIMITS	IniOrClrScrFunc_DIVEMENU_PO2LIMITS
#define Call_CondiCheckFunc_DIVEMENU_PO2LIMITS	CondiCheck_DIVEMENU_PO2LIMITS
#define Call_UpdPortionFunc_DIVEMENU_PO2LIMITS	UpdPorFunc_DIVEMENU_PO2LIMITS
#define Call_UpdOrFlashFunc_DIVEMENU_PO2LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DIVEMENU_PO2LIMITS	CondiPreOcCheck_DIVEMENU_PO2LIMITS
#define Call_HandlePreOCFunc_DIVEMENU_PO2LIMITS	HandlePreOCFunc_DIVEMENU_PO2LIMITS
#define Call_InitFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER	IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER
#define Call_CondiCheckFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER ReturnTrue
#define Call_UpdPortionFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER	UpdOrFlasFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER
#define Call_CondiCheckPreOCFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER	FuncDoNothing
#define Call_InitFunc_DIVEMAINMENU_DIVEPROFILE_ENTER	IniOrClrScrFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER /*Re-map*/
#define Call_CondiCheckFunc_DIVEMAINMENU_DIVEPROFILE_ENTER ReturnTrue
#define Call_UpdPortionFunc_DIVEMAINMENU_DIVEPROFILE_ENTER	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMAINMENU_DIVEPROFILE_ENTER	UpdOrFlasFunc_DIVEMENU_DIVEPROFILEGRAPH_ENTER /*Re-map*/
#define Call_CondiCheckPreOCFunc_DIVEMAINMENU_DIVEPROFILE_ENTER	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMAINMENU_DIVEPROFILE_ENTER	FuncDoNothing
#define Call_InitFunc_DIVEMENU_DECOSTOPS_ENTER	IniOrClrScrFunc_DIVEMENU_DECOSTOPS_ENTER
#define Call_CondiCheckFunc_DIVEMENU_DECOSTOPS_ENTER ReturnTrue
#define Call_UpdPortionFunc_DIVEMENU_DECOSTOPS_ENTER	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMENU_DECOSTOPS_ENTER	UpdOrFlasFunc_DIVEMENU_DECOSTOPS_ENTER
#define Call_CondiCheckPreOCFunc_DIVEMENU_DECOSTOPS_ENTER	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMENU_DECOSTOPS_ENTER	FuncDoNothing
#define Call_InitFunc_DIVEMENU_SET_GF_HIGH_ENTER	IniOrClrScrFunc_DIVEMENU_SET_GF_HIGH_ENTER
#define Call_CondiCheckFunc_DIVEMENU_SET_GF_HIGH_ENTER ReturnTrue
#define Call_UpdPortionFunc_DIVEMENU_SET_GF_HIGH_ENTER	FuncDoNothing
#define Call_UpdOrFlashFunc_DIVEMENU_SET_GF_HIGH_ENTER	UpdOrFlasFunc_DIVEMENU_SET_GF_HIGH_ENTER
#define Call_CondiCheckPreOCFunc_DIVEMENU_SET_GF_HIGH_ENTER	ReturnFalse
#define Call_HandlePreOCFunc_DIVEMENU_SET_GF_HIGH_ENTER	FuncDoNothing
#define Call_InitFunc_D1_DIVE_MAIN	FuncDoNothing
#define Call_CondiCheckFunc_D1_DIVE_MAIN ReturnFalse
#define Call_UpdPortionFunc_D1_DIVE_MAIN	FuncDoNothing
#define Call_UpdOrFlashFunc_D1_DIVE_MAIN	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D1_DIVE_MAIN	ReturnFalse
#define Call_HandlePreOCFunc_D1_DIVE_MAIN	FuncDoNothing
#define Call_InitFunc_D22_SP_SWITCH	FuncDoNothing
#define Call_CondiCheckFunc_D22_SP_SWITCH ReturnFalse
#define Call_UpdPortionFunc_D22_SP_SWITCH	FuncDoNothing
#define Call_UpdOrFlashFunc_D22_SP_SWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D22_SP_SWITCH	ReturnFalse
#define Call_HandlePreOCFunc_D22_SP_SWITCH	FuncDoNothing
#define Call_InitFunc_D28_GAS_SWITCH	FuncDoNothing
#define Call_CondiCheckFunc_D28_GAS_SWITCH ReturnFalse
#define Call_UpdPortionFunc_D28_GAS_SWITCH	FuncDoNothing
#define Call_UpdOrFlashFunc_D28_GAS_SWITCH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D28_GAS_SWITCH	ReturnFalse
#define Call_HandlePreOCFunc_D28_GAS_SWITCH	FuncDoNothing
#define Call_InitFunc_D32_SWITCH_MODE	FuncDoNothing
#define Call_CondiCheckFunc_D32_SWITCH_MODE ReturnFalse
#define Call_UpdPortionFunc_D32_SWITCH_MODE	FuncDoNothing
#define Call_UpdOrFlashFunc_D32_SWITCH_MODE	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D32_SWITCH_MODE	ReturnFalse
#define Call_HandlePreOCFunc_D32_SWITCH_MODE	FuncDoNothing
#define Call_InitFunc_D33_BRIGHTNESS	FuncDoNothing
#define Call_CondiCheckFunc_D33_BRIGHTNESS ReturnFalse
#define Call_UpdPortionFunc_D33_BRIGHTNESS	FuncDoNothing
#define Call_UpdOrFlashFunc_D33_BRIGHTNESS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D33_BRIGHTNESS	ReturnFalse
#define Call_HandlePreOCFunc_D33_BRIGHTNESS	FuncDoNothing
#define Call_InitFunc_D35_DIVE_MENU	FuncDoNothing
#define Call_CondiCheckFunc_D35_DIVE_MENU ReturnFalse
#define Call_UpdPortionFunc_D35_DIVE_MENU	FuncDoNothing
#define Call_UpdOrFlashFunc_D35_DIVE_MENU	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D35_DIVE_MENU	ReturnFalse
#define Call_HandlePreOCFunc_D35_DIVE_MENU	FuncDoNothing
#define Call_InitFunc_D53_SLATES	FuncDoNothing
#define Call_CondiCheckFunc_D53_SLATES ReturnFalse
#define Call_UpdPortionFunc_D53_SLATES	FuncDoNothing
#define Call_UpdOrFlashFunc_D53_SLATES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D53_SLATES	ReturnFalse
#define Call_HandlePreOCFunc_D53_SLATES	FuncDoNothing
#define Call_InitFunc_D36_SET_SP	FuncDoNothing
#define Call_CondiCheckFunc_D36_SET_SP ReturnFalse
#define Call_UpdPortionFunc_D36_SET_SP	FuncDoNothing
#define Call_UpdOrFlashFunc_D36_SET_SP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D36_SET_SP	ReturnFalse
#define Call_HandlePreOCFunc_D36_SET_SP	FuncDoNothing
#define Call_InitFunc_D37_SET_GASES	FuncDoNothing
#define Call_CondiCheckFunc_D37_SET_GASES ReturnFalse
#define Call_UpdPortionFunc_D37_SET_GASES	FuncDoNothing
#define Call_UpdOrFlashFunc_D37_SET_GASES	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D37_SET_GASES	ReturnFalse
#define Call_HandlePreOCFunc_D37_SET_GASES	FuncDoNothing
#define Call_InitFunc_D42_DIVE_PROFILE_GRAPH	FuncDoNothing
#define Call_CondiCheckFunc_D42_DIVE_PROFILE_GRAPH ReturnFalse
#define Call_UpdPortionFunc_D42_DIVE_PROFILE_GRAPH	FuncDoNothing
#define Call_UpdOrFlashFunc_D42_DIVE_PROFILE_GRAPH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D42_DIVE_PROFILE_GRAPH	ReturnFalse
#define Call_HandlePreOCFunc_D42_DIVE_PROFILE_GRAPH	FuncDoNothing
#define Call_InitFunc_D44_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_CondiCheckFunc_D44_BAILOUT_PO2_LIMITS ReturnFalse
#define Call_UpdPortionFunc_D44_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_UpdOrFlashFunc_D44_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D44_BAILOUT_PO2_LIMITS	ReturnFalse
#define Call_HandlePreOCFunc_D44_BAILOUT_PO2_LIMITS	FuncDoNothing
#define Call_InitFunc_D45_DECO_STOPS	FuncDoNothing
#define Call_CondiCheckFunc_D45_DECO_STOPS ReturnFalse
#define Call_UpdPortionFunc_D45_DECO_STOPS	FuncDoNothing
#define Call_UpdOrFlashFunc_D45_DECO_STOPS	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D45_DECO_STOPS	ReturnFalse
#define Call_HandlePreOCFunc_D45_DECO_STOPS	FuncDoNothing
#define Call_InitFunc_D49_SET_GF_HIGH	FuncDoNothing
#define Call_CondiCheckFunc_D49_SET_GF_HIGH ReturnFalse
#define Call_UpdPortionFunc_D49_SET_GF_HIGH	FuncDoNothing
#define Call_UpdOrFlashFunc_D49_SET_GF_HIGH	FuncDoNothing
#define Call_CondiCheckPreOCFunc_D49_SET_GF_HIGH	ReturnFalse
#define Call_HandlePreOCFunc_D49_SET_GF_HIGH	FuncDoNothing
#define Call_InitFunc_E1_ERROR_DEPTH_SENSOR	IniOrClrScrFunc_E1_ERROR_DEPTH_SENSOR
#define Call_CondiCheckFunc_E1_ERROR_DEPTH_SENSOR ReturnTrue
#define Call_UpdPortionFunc_E1_ERROR_DEPTH_SENSOR	FuncDoNothing
#define Call_UpdOrFlashFunc_E1_ERROR_DEPTH_SENSOR	UpdOrFlasFunc_E1_ERROR_DEPTH_SENSOR
#define Call_CondiCheckPreOCFunc_E1_ERROR_DEPTH_SENSOR	ReturnFalse
#define Call_HandlePreOCFunc_E1_ERROR_DEPTH_SENSOR	FuncDoNothing
#define Call_InitFunc_E2_ERROR_EEPROM	IniOrClrScrFunc_E2_ERROR_EEPROM
#define Call_CondiCheckFunc_E2_ERROR_EEPROM ReturnTrue
#define Call_UpdPortionFunc_E2_ERROR_EEPROM	FuncDoNothing
#define Call_UpdOrFlashFunc_E2_ERROR_EEPROM	UpdOrFlasFunc_E2_ERROR_EEPROM
#define Call_CondiCheckPreOCFunc_E2_ERROR_EEPROM	ReturnFalse
#define Call_HandlePreOCFunc_E2_ERROR_EEPROM	FuncDoNothing
#define Call_InitFunc_E3_ERROR_EXFLASH	IniOrClrScrFunc_E3_ERROR_EXFLASH
#define Call_CondiCheckFunc_E3_ERROR_EXFLASH ReturnTrue
#define Call_UpdPortionFunc_E3_ERROR_EXFLASH	FuncDoNothing
#define Call_UpdOrFlashFunc_E3_ERROR_EXFLASH	UpdOrFlasFunc_E3_ERROR_EXFLASH
#define Call_CondiCheckPreOCFunc_E3_ERROR_EXFLASH	ReturnFalse
#define Call_HandlePreOCFunc_E3_ERROR_EXFLASH	FuncDoNothing
#define Call_InitFunc_E4_ERROR_CALIBRATION	IniOrClrScrFunc_E4_ERROR_CALIBRATION
#define Call_CondiCheckFunc_E4_ERROR_CALIBRATION ReturnTrue
#define Call_UpdPortionFunc_E4_ERROR_CALIBRATION	FuncDoNothing
#define Call_UpdOrFlashFunc_E4_ERROR_CALIBRATION	UpdOrFlasFunc_E4_ERROR_CALIBRATION
#define Call_CondiCheckPreOCFunc_E4_ERROR_CALIBRATION	ReturnFalse
#define Call_HandlePreOCFunc_E4_ERROR_CALIBRATION	FuncDoNothing
#define Call_InitFunc_E5_ERROR_CHECKSUM	IniOrClrScrFunc_E5_ERROR_CHECKSUM
#define Call_CondiCheckFunc_E5_ERROR_CHECKSUM ReturnTrue
#define Call_UpdPortionFunc_E5_ERROR_CHECKSUM	FuncDoNothing
#define Call_UpdOrFlashFunc_E5_ERROR_CHECKSUM	UpdOrFlasFunc_E5_ERROR_CHECKSUM
#define Call_CondiCheckPreOCFunc_E5_ERROR_CHECKSUM	ReturnFalse
#define Call_HandlePreOCFunc_E5_ERROR_CHECKSUM	FuncDoNothing
#define Call_InitFunc_E6_ERROR_DIVE_10HR	IniOrClrScrFunc_E6_ERROR_DIVE_10HR
#define Call_CondiCheckFunc_E6_ERROR_DIVE_10HR ReturnTrue
#define Call_UpdPortionFunc_E6_ERROR_DIVE_10HR	FuncDoNothing
#define Call_UpdOrFlashFunc_E6_ERROR_DIVE_10HR	UpdOrFlasFunc_E6_ERROR_DIVE_10HR
#define Call_CondiCheckPreOCFunc_E6_ERROR_DIVE_10HR	ReturnFalse
#define Call_HandlePreOCFunc_E6_ERROR_DIVE_10HR	FuncDoNothing
#define Call_InitFunc_E7_ERROR_BATTERY_TOO_LOW	IniOrClrScrFunc_E7_ERROR_BATTERY_TOO_LOW
#define Call_CondiCheckFunc_E7_ERROR_BATTERY_TOO_LOW ReturnTrue
#define Call_UpdPortionFunc_E7_ERROR_BATTERY_TOO_LOW	FuncDoNothing
#define Call_UpdOrFlashFunc_E7_ERROR_BATTERY_TOO_LOW	UpdOrFlasFunc_E7_ERROR_BATTERY_TOO_LOW
#define Call_CondiCheckPreOCFunc_E7_ERROR_BATTERY_TOO_LOW	ReturnFalse
#define Call_HandlePreOCFunc_E7_ERROR_BATTERY_TOO_LOW	FuncDoNothing
#define Call_InitFunc_E8_ERROR_BLUETOOTH	IniOrClrScrFunc_E8_ERROR_BLUETOOTH
#define Call_CondiCheckFunc_E8_ERROR_BLUETOOTH ReturnTrue
#define Call_UpdPortionFunc_E8_ERROR_BLUETOOTH	FuncDoNothing
#define Call_UpdOrFlashFunc_E8_ERROR_BLUETOOTH	UpdOrFlasFunc_E8_ERROR_BLUETOOTH
#define Call_CondiCheckPreOCFunc_E8_ERROR_BLUETOOTH	ReturnFalse
#define Call_HandlePreOCFunc_E8_ERROR_BLUETOOTH	FuncDoNothing
#define Call_InitFunc_E9_ERROR_COMPASS	IniOrClrScrFunc_E9_ERROR_COMPASS
#define Call_CondiCheckFunc_E9_ERROR_COMPASS ReturnTrue
#define Call_UpdPortionFunc_E9_ERROR_COMPASS	FuncDoNothing
#define Call_UpdOrFlashFunc_E9_ERROR_COMPASS	UpdOrFlasFunc_E9_ERROR_COMPASS
#define Call_CondiCheckPreOCFunc_E9_ERROR_COMPASS	ReturnFalse
#define Call_HandlePreOCFunc_E9_ERROR_COMPASS	FuncDoNothing
#define Call_InitFunc_E10_ERROR_GPS	IniOrClrScrFunc_E10_ERROR_GPS
#define Call_CondiCheckFunc_E10_ERROR_GPS ReturnTrue
#define Call_UpdPortionFunc_E10_ERROR_GPS	FuncDoNothing
#define Call_UpdOrFlashFunc_E10_ERROR_GPS	UpdOrFlasFunc_E10_ERROR_GPS
#define Call_CondiCheckPreOCFunc_E10_ERROR_GPS	ReturnFalse
#define Call_HandlePreOCFunc_E10_ERROR_GPS	FuncDoNothing
#define Call_InitFunc_E11_ERROR_O2_SENSOR	IniOrClrScrFunc_E11_ERROR_O2_SENSOR
#define Call_CondiCheckFunc_E11_ERROR_O2_SENSOR ReturnTrue
#define Call_UpdPortionFunc_E11_ERROR_O2_SENSOR	FuncDoNothing
#define Call_UpdOrFlashFunc_E11_ERROR_O2_SENSOR	UpdOrFlasFunc_E11_ERROR_O2_SENSOR
#define Call_CondiCheckPreOCFunc_E11_ERROR_O2_SENSOR	ReturnFalse
#define Call_HandlePreOCFunc_E11_ERROR_O2_SENSOR	FuncDoNothing
#define Call_InitFunc_E12_ERROR_ALTITUDE	IniOrClrScrFunc_E12_ERROR_ALTITUDE
#define Call_CondiCheckFunc_E12_ERROR_ALTITUDE ReturnTrue
#define Call_UpdPortionFunc_E12_ERROR_ALTITUDE	FuncDoNothing
#define Call_UpdOrFlashFunc_E12_ERROR_ALTITUDE	UpdOrFlasFunc_E12_ERROR_ALTITUDE
#define Call_CondiCheckPreOCFunc_E12_ERROR_ALTITUDE	ReturnFalse
#define Call_HandlePreOCFunc_E12_ERROR_ALTITUDE	FuncDoNothing
#define Call_InitFunc_E9_ERROR_NOT_YET_CALI 	IniOrClrScrFunc_E9_ERROR_NOT_YET_CALI
#define Call_CondiCheckFunc_E9_ERROR_NOT_YET_CALI  ReturnTrue
#define Call_UpdPortionFunc_E9_ERROR_NOT_YET_CALI 	FuncDoNothing
#define Call_UpdOrFlashFunc_E9_ERROR_NOT_YET_CALI 	UpdOrFlasFunc_E9_ERROR_NOT_YET_CALI
#define Call_CondiCheckPreOCFunc_E9_ERROR_NOT_YET_CALI 	ReturnFalse
#define Call_HandlePreOCFunc_E9_ERROR_NOT_YET_CALI 	FuncDoNothing
#define Call_InitFunc_E10_ERROR_DIVE_NOT_COMPLETE	IniOrClrScrFunc_E10_ERROR_DIVE_NOT_COMPLETE
#define Call_CondiCheckFunc_E10_ERROR_DIVE_NOT_COMPLETE ReturnTrue
#define Call_UpdPortionFunc_E10_ERROR_DIVE_NOT_COMPLETE	FuncDoNothing
#define Call_UpdOrFlashFunc_E10_ERROR_DIVE_NOT_COMPLETE	UpdOrFlasFunc_E10_ERROR_DIVE_NOT_COMPLETE
#define Call_CondiCheckPreOCFunc_E10_ERROR_DIVE_NOT_COMPLETE	ReturnFalse
#define Call_HandlePreOCFunc_E10_ERROR_DIVE_NOT_COMPLETE	FuncDoNothing
#define Call_InitFunc_E11_ERROR_ADC 	IniOrClrScrFunc_E11_ERROR_ADC
#define Call_CondiCheckFunc_E11_ERROR_ADC  ReturnTrue
#define Call_UpdPortionFunc_E11_ERROR_ADC 	FuncDoNothing
#define Call_UpdOrFlashFunc_E11_ERROR_ADC 	UpdOrFlasFunc_E11_ERROR_ADC
#define Call_CondiCheckPreOCFunc_E11_ERROR_ADC 	ReturnFalse
#define Call_HandlePreOCFunc_E11_ERROR_ADC 	FuncDoNothing
#define Call_InitFunc_E12_ERROR_TEMP_SENSOR 	IniOrClrScrFunc_E12_ERROR_TEMP_SENSOR
#define Call_CondiCheckFunc_E12_ERROR_TEMP_SENSOR  ReturnTrue
#define Call_UpdPortionFunc_E12_ERROR_TEMP_SENSOR 	FuncDoNothing
#define Call_UpdOrFlashFunc_E12_ERROR_TEMP_SENSOR 	UpdOrFlasFunc_E12_ERROR_TEMP_SENSOR
#define Call_CondiCheckPreOCFunc_E12_ERROR_TEMP_SENSOR 	ReturnFalse
#define Call_HandlePreOCFunc_E12_ERROR_TEMP_SENSOR 	FuncDoNothing
#define Call_InitFunc_E13_ERROR_VOLT_SENSOR 	IniOrClrScrFunc_E13_ERROR_VOLT_SENSOR
#define Call_CondiCheckFunc_E13_ERROR_VOLT_SENSOR  ReturnTrue
#define Call_UpdPortionFunc_E13_ERROR_VOLT_SENSOR 	FuncDoNothing
#define Call_UpdOrFlashFunc_E13_ERROR_VOLT_SENSOR 	UpdOrFlasFunc_E13_ERROR_VOLT_SENSOR
#define Call_CondiCheckPreOCFunc_E13_ERROR_VOLT_SENSOR 	ReturnFalse
#define Call_HandlePreOCFunc_E13_ERROR_VOLT_SENSOR 	FuncDoNothing
#define Call_InitFunc_E14_ERROR_TICK_TIME 	IniOrClrScrFunc_E14_ERROR_TICK_TIME
#define Call_CondiCheckFunc_E14_ERROR_TICK_TIME  ReturnTrue
#define Call_UpdPortionFunc_E14_ERROR_TICK_TIME 	FuncDoNothing
#define Call_UpdOrFlashFunc_E14_ERROR_TICK_TIME 	UpdOrFlasFunc_E14_ERROR_TICK_TIME
#define Call_CondiCheckPreOCFunc_E14_ERROR_TICK_TIME 	ReturnFalse
#define Call_HandlePreOCFunc_E14_ERROR_TICK_TIME 	FuncDoNothing
#define Call_InitFunc_E15_ERROR_BUTTON 	IniOrClrScrFunc_E15_ERROR_BUTTON
#define Call_CondiCheckFunc_E15_ERROR_BUTTON  ReturnTrue
#define Call_UpdPortionFunc_E15_ERROR_BUTTON 	FuncDoNothing
#define Call_UpdOrFlashFunc_E15_ERROR_BUTTON 	UpdOrFlasFunc_E15_ERROR_BUTTON
#define Call_CondiCheckPreOCFunc_E15_ERROR_BUTTON 	ReturnFalse
#define Call_HandlePreOCFunc_E15_ERROR_BUTTON 	FuncDoNothing
#define Call_InitFunc_E16_ERROR_ALTITUDE 	IniOrClrScrFunc_E16_ERROR_ALTITUDE
#define Call_CondiCheckFunc_E16_ERROR_ALTITUDE  ReturnTrue
#define Call_UpdPortionFunc_E16_ERROR_ALTITUDE 	FuncDoNothing
#define Call_UpdOrFlashFunc_E16_ERROR_ALTITUDE 	UpdOrFlasFunc_E16_ERROR_ALTITUDE
#define Call_CondiCheckPreOCFunc_E16_ERROR_ALTITUDE 	ReturnFalse
#define Call_HandlePreOCFunc_E16_ERROR_ALTITUDE 	FuncDoNothing
#define Call_InitFunc_E17_ERROR_COMPASS 	IniOrClrScrFunc_E17_ERROR_COMPASS
#define Call_CondiCheckFunc_E17_ERROR_COMPASS  ReturnTrue
#define Call_UpdPortionFunc_E17_ERROR_COMPASS 	FuncDoNothing
#define Call_UpdOrFlashFunc_E17_ERROR_COMPASS 	UpdOrFlasFunc_E17_ERROR_COMPASS
#define Call_CondiCheckPreOCFunc_E17_ERROR_COMPASS 	ReturnFalse
#define Call_HandlePreOCFunc_E17_ERROR_COMPASS 	FuncDoNothing
#define Call_InitFunc_E18_ERROR_FUEL_GAUGE 	IniOrClrScrFunc_E18_ERROR_FUEL_GAUGE
#define Call_CondiCheckFunc_E18_ERROR_FUEL_GAUGE  ReturnTrue
#define Call_UpdPortionFunc_E18_ERROR_FUEL_GAUGE 	FuncDoNothing
#define Call_UpdOrFlashFunc_E18_ERROR_FUEL_GAUGE 	UpdOrFlasFunc_E18_ERROR_FUEL_GAUGE
#define Call_CondiCheckPreOCFunc_E18_ERROR_FUEL_GAUGE 	ReturnFalse
#define Call_HandlePreOCFunc_E18_ERROR_FUEL_GAUGE 	FuncDoNothing
#define Call_InitFunc_E19_ERROR_RECEIVER 	IniOrClrScrFunc_E19_ERROR_RECEIVER
#define Call_CondiCheckFunc_E19_ERROR_RECEIVER  ReturnTrue
#define Call_UpdPortionFunc_E19_ERROR_RECEIVER 	FuncDoNothing
#define Call_UpdOrFlashFunc_E19_ERROR_RECEIVER 	UpdOrFlasFunc_E19_ERROR_RECEIVER
#define Call_CondiCheckPreOCFunc_E19_ERROR_RECEIVER 	ReturnFalse
#define Call_HandlePreOCFunc_E19_ERROR_RECEIVER 	FuncDoNothing
#define Call_InitFunc_E20_ERROR_GPS 	IniOrClrScrFunc_E20_ERROR_GPS
#define Call_CondiCheckFunc_E20_ERROR_GPS  ReturnTrue
#define Call_UpdPortionFunc_E20_ERROR_GPS 	FuncDoNothing
#define Call_UpdOrFlashFunc_E20_ERROR_GPS 	UpdOrFlasFunc_E20_ERROR_GPS
#define Call_CondiCheckPreOCFunc_E20_ERROR_GPS 	ReturnFalse
#define Call_HandlePreOCFunc_E20_ERROR_GPS 	FuncDoNothing
#define Call_InitFunc_E21_ERROR_O2_SENSOR 	IniOrClrScrFunc_E21_ERROR_O2_SENSOR
#define Call_CondiCheckFunc_E21_ERROR_O2_SENSOR  ReturnTrue
#define Call_UpdPortionFunc_E21_ERROR_O2_SENSOR 	FuncDoNothing
#define Call_UpdOrFlashFunc_E21_ERROR_O2_SENSOR 	UpdOrFlasFunc_E21_ERROR_O2_SENSOR
#define Call_CondiCheckPreOCFunc_E21_ERROR_O2_SENSOR 	ReturnFalse
#define Call_HandlePreOCFunc_E21_ERROR_O2_SENSOR 	FuncDoNothing
#define Call_InitFunc_E22_POPUP_USINGDIVELOGAPP	IniOrClrScrFunc_E22_POPUP_USINGDIVELOGAPP
#define Call_CondiCheckFunc_E22_POPUP_USINGDIVELOGAPP ReturnTrue
#define Call_UpdPortionFunc_E22_POPUP_USINGDIVELOGAPP	FuncDoNothing
#define Call_UpdOrFlashFunc_E22_POPUP_USINGDIVELOGAPP	FuncDoNothing
#define Call_CondiCheckPreOCFunc_E22_POPUP_USINGDIVELOGAPP	ReturnFalse
#define Call_HandlePreOCFunc_E22_POPUP_USINGDIVELOGAPP	FuncDoNothing
#define Call_InitFunc_DataDec	FuncDoNothing
#define Call_CondiCheckFunc_DataDec ReturnFalse
#define Call_UpdPortionFunc_DataDec	FuncDoNothing
#define Call_UpdOrFlashFunc_DataDec	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DataDec	ReturnFalse
#define Call_HandlePreOCFunc_DataDec	FuncDoNothing
#define Call_InitFunc_DataInc	FuncDoNothing
#define Call_CondiCheckFunc_DataInc ReturnFalse
#define Call_UpdPortionFunc_DataInc	FuncDoNothing
#define Call_UpdOrFlashFunc_DataInc	FuncDoNothing
#define Call_CondiCheckPreOCFunc_DataInc	ReturnFalse
#define Call_HandlePreOCFunc_DataInc	FuncDoNothing
#define Call_InitFunc_ScrollDec	FuncDoNothing
#define Call_CondiCheckFunc_ScrollDec ReturnFalse
#define Call_UpdPortionFunc_ScrollDec	FuncDoNothing
#define Call_UpdOrFlashFunc_ScrollDec	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ScrollDec	ReturnFalse
#define Call_HandlePreOCFunc_ScrollDec	FuncDoNothing
#define Call_InitFunc_ScrollInc	FuncDoNothing
#define Call_CondiCheckFunc_ScrollInc ReturnFalse
#define Call_UpdPortionFunc_ScrollInc	FuncDoNothing
#define Call_UpdOrFlashFunc_ScrollInc	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ScrollInc	ReturnFalse
#define Call_HandlePreOCFunc_ScrollInc	FuncDoNothing
#define Call_InitFunc_SaveAndDone	FuncDoNothing
#define Call_CondiCheckFunc_SaveAndDone ReturnFalse
#define Call_UpdPortionFunc_SaveAndDone	FuncDoNothing
#define Call_UpdOrFlashFunc_SaveAndDone	FuncDoNothing
#define Call_CondiCheckPreOCFunc_SaveAndDone	ReturnFalse
#define Call_HandlePreOCFunc_SaveAndDone	FuncDoNothing
#define Call_InitFunc_CheckConditions	FuncDoNothing
#define Call_CondiCheckFunc_CheckConditions ReturnFalse
#define Call_UpdPortionFunc_CheckConditions	FuncDoNothing
#define Call_UpdOrFlashFunc_CheckConditions	FuncDoNothing
#define Call_CondiCheckPreOCFunc_CheckConditions	ReturnFalse
#define Call_HandlePreOCFunc_CheckConditions	FuncDoNothing
#define Call_InitFunc_ButtonL1	FuncDoNothing
#define Call_CondiCheckFunc_ButtonL1 ReturnFalse
#define Call_UpdPortionFunc_ButtonL1	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonL1	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonL1	ReturnFalse
#define Call_HandlePreOCFunc_ButtonL1	FuncDoNothing
#define Call_InitFunc_ButtonL2	FuncDoNothing
#define Call_CondiCheckFunc_ButtonL2 ReturnFalse
#define Call_UpdPortionFunc_ButtonL2	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonL2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonL2	ReturnFalse
#define Call_HandlePreOCFunc_ButtonL2	FuncDoNothing
#define Call_InitFunc_ButtonM1	FuncDoNothing
#define Call_CondiCheckFunc_ButtonM1 ReturnFalse
#define Call_UpdPortionFunc_ButtonM1	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonM1	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonM1	ReturnFalse
#define Call_HandlePreOCFunc_ButtonM1	FuncDoNothing
#define Call_InitFunc_ButtonM2	FuncDoNothing
#define Call_CondiCheckFunc_ButtonM2 ReturnFalse
#define Call_UpdPortionFunc_ButtonM2	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonM2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonM2	ReturnFalse
#define Call_HandlePreOCFunc_ButtonM2	FuncDoNothing
#define Call_InitFunc_ButtonR1	FuncDoNothing
#define Call_CondiCheckFunc_ButtonR1 ReturnFalse
#define Call_UpdPortionFunc_ButtonR1	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonR1	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonR1	ReturnFalse
#define Call_HandlePreOCFunc_ButtonR1	FuncDoNothing
#define Call_InitFunc_ButtonR2	FuncDoNothing
#define Call_CondiCheckFunc_ButtonR2 ReturnFalse
#define Call_UpdPortionFunc_ButtonR2	FuncDoNothing
#define Call_UpdOrFlashFunc_ButtonR2	FuncDoNothing
#define Call_CondiCheckPreOCFunc_ButtonR2	ReturnFalse
#define Call_HandlePreOCFunc_ButtonR2	FuncDoNothing
#endif