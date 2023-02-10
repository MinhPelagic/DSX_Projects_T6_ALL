/*******************************************************************************
 * @file        : DSXersion.h
 * @brief       : Fw Version definition file and revision History
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/


/*******************************************************************************
 * @brief   Fw Version
 *
 * @note
 ******************************************************************************/

/* FW Version 
Updated from R-1002 to R-1003 on 2002 10 12 by YeuShyr
*/
#define FW_REV                  0x000000001
#define FW_VERSION_MAJ          (uint32_t)1
#define FW_VERSION_MIN          (uint32_t)6
#define FW_VERSION_BATCH        (uint32_t)15
/* Verion Build */
#if defined ( BUILD_BTL )
    #define GET_FW_VERSION          /* (FW_VERSION_MAJ*1000+FW_VERSION_MIN) */ (FW_VERSION_MAJ*1000000+FW_VERSION_MIN*1000+FW_VERSION_BATCH)
    #define STR_FW_VERSION(x)       sprintf(##x##, "T-%d", (int)GET_FW_VERSION)
#else
    #define GET_FW_VERSION          (FW_VERSION_MAJ*1000000+FW_VERSION_MIN*1000+FW_VERSION_BATCH)
    #define STR_FW_VERSION(x)       sprintf(##x##, "T-%d", (int)GET_FW_VERSION)
#endif
/* Firmware Revision
    T: Test
    R: Release
*/
#define STR_FW_VERSION(x)       sprintf(##x##, "T-%d", (int)GET_FW_VERSION)


/*******************************************************************************************************************************************************************************************
 * @brief   Fw Revision History
 *
 *      R-1.001.000: 2022/09/09 15:52 Initial Firmware Release for production
 *
 *      R-1.002: 2022/10/10 12:00 Firmware Update for production
 *              1. Improvements in GUI 12-Languages strings and their locations and overlapping issues
 *              2. Added new opening Registration GUI page and new PassCodeCheck()
 *              3. Improvements in SysErrorWarning messages and responses
 *              4. Locked CC mode away from this release. Only OC, SM, GSM and Gauge modes work in this release (use TemporaryBypassCC_Flag == true)
 *              5. Added RedefineWaterLevel() to handle WaterLevel Auto-Zeroing while entering Sleep mode
 *              6. Removed the bug that showed 00/00/00 in the first blind Dive from New Day Sleep mode
 *              7. Improvements in DiveAlgo for CC Auto SP Hi/Lo and removed unstable fluctuation of NDT
 *              8. Added PSI initialization GasTankPSI_RecorderInit
 *              9. Fine tuning Compass N-E-S-W degree accuracy by new DirectionCorrection() function
 *              10. Added Registration in ConditionsOKtoDive()
 *              11. Added while(!EE24CWxxX_ReadNBytes) ExFLASH readback immediately after some of NVD_RAMBLOCK_to_ExtEEPROM() ExFLASH Writes
 *              12. Reset all TMTs to be OFF after user chooses RESET SETTINGS to reset configurations
 *              13. Added O2 Cable Serial Number field on EEPROM and allow MFG APP's access to it
 *              14. Added BO data structure in EEPROM, although not using it in this version
 *              15. Added some new BO Opcodes, although not using it in this version
 *
 *      R-1.003: 2022/10/10 12:00 Firmware Update for production
 *              1. Get rid of CellNewToDepletedFactor from the calculation of Compensated_Tank_O2_Pct
 *              2. Use O2_Analyzer_Volt (instead of O2_ADC_V_Calib) for O2_Cell_mV calculation 
 *
 *      R-1.004: 2022/10/21 10:20 Firmware Update for production
 *              1. To Reset Bluetooth Chip from all UI_Wakeup functions, by calling St2Ble_PowerDown( ), instead of St2Ble_PowerOn( ) (in app.c)
 *              2. Removed some Bluetooth controls (related SLEEP Modes) from Ble_Handler( ), and only call St2Ble_PowerOn( ) from there, no longer from app.c. 
 *              3. Removed low-pass filter (by assigning O2_ANALYZER_LP_FACTOR = 1.0) for ADC measurement (O2.c)
 *              4. Shorter CABLE_CALI_OUTPUT_STARTTIME and CABLE_CALI_OUTPUT_ENDTIME to speed up O2 Cable Calibration process (O2.c and O2.h)
 *              5. Use O2_ANALYZER_Init_DONE, O2_ANALYZER_WE1_DONE, O2_ANALYZER_WE2_DONE, O2_ANALYZER_WE3_DONE, O2_ANALYZER_FO2_CHECK_DONE to coordinate O2.c and Ble.c working together better (L4X9_ble.c, O2.c and O2.h)
 *              6. Enlarge font size for warning message for O2 Cable SN and the SN turns from red to white after Cable Calibration is done properly (Menu_O2Analyzer_Page_Main.c)
 *              7. Fixed the mixup of Safety Stop Depth displayed in Dive Settings menu (Menu_DiveSettings_MainPage_cfg.c)
 *              8. Some corrections on Traditional Chinese language strings (StringText_ChineseTrad.c)
 *              9. Correction on button control at O2ANALYZER_CALIBRATE to return back to menu (DSX_ButtonHandle.c)
 *              
 *      R-1.005: 2022/12/19 09:50 Firmware Update for production
 *              1. CC->BO mode switch calculates and picks the Best Gas tank 10/23
 *              2. Removed Compiler Warnings from 300+ down to 95. The rest are from STMwin libraries or so. 10/23 to 11/15
 *              3. Completed the Bailout PO2 Min/Max/Deco settings, controls and GUI pages 10/26
 *              4. Removed the SWITCH TO XX/YY SwitchFO2 false alarm 10/27
 *              5. Improved code to avoid Dive Mode lockup 10/28
 *              6. Update Bottom display when move up/down. Removed N2Bar overlap with 3rd row right, Removed BO Switch Gas selection dot  10/30
 *              7. Corrections on LOG5, CC BO[6], LOG PO2 in CC mode, CC_MaxPO2_SetofDive 10/31
 *              8. Changed LOOSE_LINK_t CheckLooseLink_GAS(TMT_NUM_t); to LOOSE_LINK_t  10/31
 *              9. Better DecoTime DecoStop controls and accuracy. The improvements for DecoStop[ ] and DecoTime[ ] to work more correctly. 11/1
 *              10. CC-6 Start PSI and End PSI always posting for CC-6 in LOG Data2 11/1
 *              11. Corrected the lots of the mix-up of "(float)PO2 with 0.01*(integer)PO2. Fixed LOG Data2's AVE.CONSUMP. from Negative Sign to Positive Sign.11/2
 *              12. LOG Data2's AVE.CONSUMP. from Negative Sign to Positive Sign. 11/3
 *              13. Simulator > Bailout Plan Deco should NOT display 100% Gas for 9M 11/3
 *              14. Fixed numerical error displayed at the Dive Main and Surf Main pages' PO2 11/6
 *              15. Improved the DSX response to DiverLog+ after Flip Screen, Dive Mode Change and Language Change 11/6
 *              16. Corrections on Chinese-T and Chinese-S 11/15
 *              17. Output SwitchSet.AllBits to Profile Header and Log Data 11/10
 *              18. Corrected the Dive Main Page returning from Compass, during the After-Dive 11/10
 *              19. Add Battery Icon into Gauge and GSM Dive Modes 11/10
 *              20. Modified LOG List Menu's Log color turns RED only if that dive has VIOLATION 11/10
 *              21. Moved Ascend Rate AR bar's text further toward to the left side. 11/14
 *              22. Added GUI_DISPLAY_Update( ) function for better GUI response to DiverLog+ 11/14
 *              23. Enhanced algorithm accuracy for different water types by using SaltEqDensityFactor() 11/15
 *              24. Removed many issues still hidden in DIVE MENU for all modes 11/15
 *              25. Added one more Batter Reading Update_SystemSupplyMonitor ( &SystemSupplyMonitor ); prior to LowBatt shutdown 11/16
 *              26. Fixed layout battery overlap with Extra large dive time; Updated implementation display 3rd row left right  11/18
 *              27. Fixed CC mode Dive profile is missing Gas6 TMT info (2) Missing Max PO2 11/21
 *              28. Added PatchR1005( ) for BO mode to work with old units running older firmware 11/21
 *              29. Added ResetButtonMemory( ) to avoid premature button inputs or clean up 11/21
 *              30. Restored Welcome screens missing during Boot-up or New-Day Wakeup 11/21
 *              31. Made BO mode's SET GASES to check for BO-1 only (NOT TO BE DISABLED) 11/21
 *              32. Use ReturnToMainPage( ) for Main Page return for all cases (in both Surf 11/22
 *              33. Added decimal point for Real-Time Dive Charts and LOG3 Chart whenever Depth is shallower than 8Fit or 8 Meters 11/22
 *              34. Changed the GTR FOR LEFT & RIGHT is to be NO, after diver's RESET SETTIN 11/23
 *              35. Corrected CC/BO/OC/SM's MaxPO2 and MOD. 11/23
 *              36. Corrected the GUI text from lower case to upper case 11/28
 *              37. Correct NO DIVE YET with multiple languages, text abbriviation to Surface alternate page-4 11/28
 *              38. Update the flashing GF bar, overlap display when Violation 11/29
 *              39. Fixed Auto SP Hi and Lo issues posted by Murat 11/29
 *              40. Auto SP High/Low improvements 11/29
 *              41. Corrected C-100/00 issue showing at TMT duplicated link warning page 12/1
 *              42. Improved Better Gas and Best Gas for OC, SM, CC and BO modes 12/6
 *              43. Fixed and removed this issue: Premature Violation asserting to DSX system 12/6
 *              44. (1)- DO not display OC-1 21/00 yellow color after used Simulator 12/7
 *              45. Added "Forced Bluetooth Chip to Reset" at the moment that DSX Wakes up 12/7
 *              46. Removed the false YELLOW color of Surface Main's FO2/FHe text that occur deeper than MOD 12/9
 *              47. Fixed the OC-L and OC-R at SM mode LOG Data2. Fixed the TMT-L and TMT-R 12/9
 *              48. Improved on Best Gas, Better Gas, and SWITCH GAS XX/XX 12/10
 *              49. Instead of using a constant PO2 = 1.6. this update opened up the MOD PO2 12/11
 *              50. Fixed the "Safety Stop Time being Frozen" issue.12/15
 *
 *******************************************************************************************************************************************************************************************/