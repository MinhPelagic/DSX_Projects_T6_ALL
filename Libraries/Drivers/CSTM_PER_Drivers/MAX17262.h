/*******************************************************************************
 * @file        MAX17262.h
 * @brief       MAX17262 Fuel Gauge 1-Cell with internal Sense
 * @version     1.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020 Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

#ifndef _MAX17262_H_
#define _MAX17262_H_


#define MAX17262_I2C_ADDR               0x006C

// Register Address
#define	MAX17262_STATUS                 0x00
#define	MAX17262_FSTATUS                0x3D
#define	MAX17262_HIBCFG                 0xBA
#define	MAX17262_SWCMD                  0x60

#define	MAX17262_DESIGNCAP              0x18
#define	MAX17262_VEMPTY                 0x3A
#define	MAX17262_MODELCFG               0xDB
#define	MAX17262_ICHRTERM               0x1E
#define	MAX17262_CFG1                   0x1D
#define	MAX17262_CFG2                   0xBB

#define	MAX17262_REPSOC                 0x06
#define	MAX17262_TTE                    0x11
#define	MAX17262_TTF                    0x20
#define	MAX17262_VOLT_AVG               0x19
#define	MAX17262_CURR_AVG               0x0B

#define	MAX17262_FULLCAPREP             0x10
#define	MAX17262_CYCLES                 0x17


#define	MAX17262_VALRT_TH               0x01


#define	MAX17262_RCOMP0                 0x38
#define	MAX17262_TEMPCO                 0x39
#define	MAX17262_FULLCAPNOM             0x23
#define	MAX17262_DPACC                  0x46
#define	MAX17262_DQACC                  0x45



// Masks
#define MAX17262_STAT_POR_MSK           0x0002	// Power On Reset
#define MAX17262_FSTAT_DNR_MSK          0x0001	// Data Not Ready


#define MAX17262_MODELCFG_REFRESH_MSK   0x8000	// Refresh

#define MAX17262_CFG1_TSEL_MSK          0x8000	// Temperature Sensor Select
#define _MAX17262_CFG1_TSEL_POS         15
#define MAX17262_CFG1_SS_MSK            0x4000	// SOC Alert Sticky
#define _MAX17262_CFG1_SS_POS           14
#define MAX17262_CFG1_TS_MSK            0x2000	// Temeprature Alert Stiky
#define _MAX17262_CFG1_TS_POS           13
#define MAX17262_CFG1_VS_MSK            0x1000	// Voltage Alert Sticky
#define _MAX17262_CFG1_VS_POS           12
#define MAX17262_CFG1_IS_MSK            0x0800	// Current Alert Sticky
#define _MAX17262_CFG1_IS_POS           11
#define MAX17262_CFG1_THSH_MSK          0x0400	// TH Pin Shutdown
#define _MAX17262_CFG1_THSH_POS         10
#define MAX17262_CFG1_TEN_MSK           0x0200	// Temperature channel enable
#define _MAX17262_CFG1_TEN_POS          9
#define MAX17262_CFG1_TEX_MSK           0x0100	// Temperature External
#define _MAX17262_CFG1_TEX_POS          8
#define MAX17262_CFG1_SHDN_MSK          0x0080	// Shutdown
#define _MAX17262_CFG1_SHDN_POS         7
#define MAX17262_CFG1_COMMSH_MSK        0x0040	// Comunication ShutDown
#define _MAX17262_CFG1_COMMSH_POS       6
#define MAX17262_CFG1_ETHRM_MSK         0x0010	// Enable thermistor
#define _MAX17262_CFG1_ETHRM_POS        4
#define MAX17262_CFG1_FTHRM_MSK         0x0008	// Froce Thermistor Bias Switch
#define _MAX17262_CFG1_FTHRM_POS        3
#define MAX17262_CFG1_AEN_MSK           0x0004	// Enable Alert on Output
#define _MAX17262_CFG1_AEN_POS          2
#define MAX17262_CFG1_BEI_MSK           0x0002	// Enable Alert on Battery insertion
#define _MAX17262_CFG1_BEI_POS          1
#define MAX17262_CFG1_BER_MSK           0x0001	// Enable Alert on Battery removal
#define _MAX17262_CFG1_BER_POS          0

#define MAX17262_CFG2_ATRATEN_MSK       0x2000	// At Rate Enable
#define _MAX17262_CFG2_ATRATEN_POS      13
#define MAX17262_CFG2_DPEN_MSK          0x1000	// Dynamic Power Enable
#define _MAX17262_CFG2_DPEN_POS         12
#define MAX17262_CFG2_POWR_MSK          0x0F00	// Avg Power time Constant
#define _MAX17262_CFG2_POWR_POS         8
#define MAX17262_CFG2_DSOCEN_MSK        0x0080	// SOC Change Alert Enable
#define _MAX17262_CFG2_DSOCEN_POS       7
#define MAX17262_CFG2_TALRTEN_MSK       0x0040	// Temperature Change Alert Enable
#define _MAX17262_CFG2_TALRTEN_POS      6
#define MAX17262_CFG2_LDMDL_MSK         0x0020	// Model Load
#define _MAX17262_CFG2_LDMDL_POS        5
#define MAX17262_CFG2_DRCFG_MSK         0x000C	// Deep Relax Time
#define _MAX17262_CFG2_DRCFG_POS        2
#define MAX17262_CFG2_CPM_MSK           0x0002	// Constant Power Mode Enable
#define _MAX17262_CFG2_CPM_POS          1



// Enumerators
typedef enum
{
  MAX17262_CFG1_TSEL_INTERNAL   = (0x00 << _MAX17262_CFG1_TSEL_POS),
  MAX17262_CFG1_TSEL_EXTERNAL   = (0x01 << _MAX17262_CFG1_TSEL_POS)
} MAX17262_CFG1_TSEL_t;

typedef enum
{
  MAX17262_CFG1_VS_AUTO         = (0x00 << _MAX17262_CFG1_VS_POS),
  MAX17262_CFG1_VS_SW           = (0x01 << _MAX17262_CFG1_VS_POS)
} MAX17262_CFG1_VS_t;

typedef enum
{
  MAX17262_CFG1_AEN_OFF         = (0x00 << _MAX17262_CFG1_AEN_POS),
  MAX17262_CFG1_AEN_ON          = (0x01 << _MAX17262_CFG1_AEN_POS)
} MAX17262_CFG1_AEN_t;

typedef enum
{
  MAX17262_CFG1_TEN_CHOFF       = (0x00 << _MAX17262_CFG1_TEN_POS),
  MAX17262_CFG1_TEN_CHON        = (0x01 << _MAX17262_CFG1_TEN_POS)
} MAX17262_CFG1_TEN_t;

typedef enum
{
  MAX17262_CFG1_TEX_OFF         = (0x00 << _MAX17262_CFG1_TEX_POS),
  MAX17262_CFG1_TEX_ON          = (0x01 << _MAX17262_CFG1_TEX_POS)
} MAX17262_CFG1_TEX_t;

typedef enum
{
  MAX17262_CFG1_ETHRM_OFF       = (0x00 << _MAX17262_CFG1_ETHRM_POS),
  MAX17262_CFG1_ETHRM_ON        = (0x01 << _MAX17262_CFG1_ETHRM_POS)
} MAX17262_CFG1_ETHRM_t;

typedef enum
{
  MAX17262_CFG1_FTHRM_OFF       = (0x00 << _MAX17262_CFG1_FTHRM_POS),
  MAX17262_CFG1_FTHRM_ON        = (0x01 << _MAX17262_CFG1_FTHRM_POS)
} MAX17262_CFG1_FTHRM_t;


typedef enum
{
  MAX17262_CFG2_CPM_OFF         = (0x00 << _MAX17262_CFG2_CPM_POS),
  MAX17262_CFG2_CPM_ON          = (0x01 << _MAX17262_CFG2_CPM_POS)
} MAX17262_CFG2_CPM_t;

typedef enum
{
  MAX17262_CFG2_DRCFG_SHORTEST  = (0x00 << _MAX17262_CFG2_DRCFG_POS),
  MAX17262_CFG2_DRCFG_SHORT     = (0x02 << _MAX17262_CFG2_DRCFG_POS),
  MAX17262_CFG2_DRCFG_LONG      = (0x03 << _MAX17262_CFG2_DRCFG_POS),
  MAX17262_CFG2_DRCFG_LONGEST   = (0x04 << _MAX17262_CFG2_DRCFG_POS),
} MAX17262_CFG2_DRCFG_t;

typedef enum
{
  MAX17262_CFG2_TALRTEN_OFF     = (0x00 << _MAX17262_CFG2_TALRTEN_POS),
  MAX17262_CFG2_TALRTEN_ON      = (0x01 << _MAX17262_CFG2_TALRTEN_POS)
} MAX17262_CFG2_TALRTEN_t;

typedef enum
{
  MAX17262_CFG2_DSOCEN_OFF      = (0x00 << _MAX17262_CFG2_DSOCEN_POS),
  MAX17262_CFG2_DSOCEN_ON       = (0x01 << _MAX17262_CFG2_DSOCEN_POS)
} MAX17262_CFG2_DSOCEN_t;

typedef enum
{
  MAX17262_CFG2_POWR_00S70      = (0x00 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_01S40      = (0x01 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_02S80      = (0x02 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_05S62      = (0x03 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_11S25      = (0x04 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_22S50      = (0x05 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_45S00      = (0x06 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_90S00      = (0x07 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_03M00      = (0x08 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_06M00      = (0x09 << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_12M00      = (0x0A << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_24M00      = (0x0B << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_48M00      = (0x0C << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_96M00      = (0x0D << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_192M00     = (0x0E << _MAX17262_CFG2_POWR_POS),
  MAX17262_CFG2_POWR_384M00     = (0x0F << _MAX17262_CFG2_POWR_POS),
} MAX17262_CFG2_POWR_t;

typedef enum
{
  MAX17262_CFG2_DPEN_OFF        = (0x00 << _MAX17262_CFG2_DPEN_POS),
  MAX17262_CFG2_DPEN_ON         = (0x01 << _MAX17262_CFG2_DPEN_POS)
} MAX17262_CFG2_DPEN_t;

typedef enum
{
  MAX17262_CFG2_ATRATEN_OFF     = (0x00 << _MAX17262_CFG2_ATRATEN_POS),
  MAX17262_CFG2_ATRATEN_ON      = (0x01 << _MAX17262_CFG2_ATRATEN_POS)
} MAX17262_CFG2_ATRATEN_t;



typedef struct
{
  uint32_t RepSoc_cx100;
  uint32_t TTE_s;
  uint32_t TTF_s;
  uint32_t AvgVoltage_mV;
  int32_t AvgCurrent_uA;
} MAX17262_Output_t;


typedef struct
{
  uint16_t RCOMP0;
  uint16_t TempCo;
  uint16_t FullCapRep;
  uint16_t Cycles;
  uint16_t FullCapNom;
  bool valid;
  uint8_t res;
} MAX17262_Learned_t;


/*******************************************************************************
 * @brief
 *   Reads one 16bit register
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_ReadRegister (uint8_t register_address, uint16_t *register_value);


/*******************************************************************************
 * @brief
 *   Write one 16bit register
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_WriteRegister (uint8_t register_address, uint16_t register_value);


/*******************************************************************************
 * @brief
 *   Write/Read/Verify one 16bit register
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_WriteReadVerifyRegister (uint8_t register_address, uint16_t register_value);

/*******************************************************************************
 * @brief
 *   Save Learned Parameters
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_SaveLearnedParameters ( MAX17262_Learned_t *data );

/*******************************************************************************
 * @brief
 *   Set Learned Parameters
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_SetLearnedParameters ( MAX17262_Learned_t data );

/*******************************************************************************
 * @brief
 *   Initialize Fuel Gauge
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_Init ( MAX17262_Learned_t learned_data );

/*******************************************************************************
 * @brief
 *   Reset Fuel Gauge
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_Reset ( void );

/*******************************************************************************
 * @brief
 *   Get Fuel Gauge Output
 *
 * @note
 *
 * @return
 *	true : if successful
 *	false : on error
 ******************************************************************************/
bool MAX17262_GetFgOutput ( void );

#endif //_MAX17262_H_