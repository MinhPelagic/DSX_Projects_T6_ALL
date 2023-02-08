/*******************************************************************************
 * @file        : LSM303AGR.h
 * @brief       : Low Level Driver for 6-Axis Mems LSM303AGR
 *                                   
 *
 * @version     0.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018 --------.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 * @note
 *
 ******************************************************************************/

#ifndef _LSM303AGR_H_
#define _LSM303AGR_H_

#define LSM303AGR_I2C_ADD_A             0x0032
#define LSM303AGR_I2C_ADD_M             0x003C

// Device ID (Who am I)
#define LSM303AGR_ID_A                  0x33
#define LSM303AGR_ID_M                  0x40


// Register definition
#define LSM303AGR_WHO_AM_I_A            0x0F
#define LSM303AGR_CTRL1_A               0x20
#define LSM303AGR_CTRL2_A               0x21
#define LSM303AGR_CTRL3_A               0x22
#define LSM303AGR_CTRL4_A               0x23
#define LSM303AGR_CTRL5_A               0x24
#define LSM303AGR_CTRL6_A               0x25
#define LSM303AGR_STATUS_A              0x27
#define LSM303AGR_OUT_X_L_A             0x28
#define LSM303AGR_OUT_X_H_A             0x29
#define LSM303AGR_OUT_Y_L_A             0x2A
#define LSM303AGR_OUT_Y_H_A             0x2B
#define LSM303AGR_OUT_Z_L_A             0x2C
#define LSM303AGR_OUT_Z_H_A             0x2D

#define LSM303AGR_OFFSET_X_REG_L_M      0x45U
#define LSM303AGR_OFFSET_X_REG_H_M      0x46U
#define LSM303AGR_OFFSET_Y_REG_L_M      0x47U
#define LSM303AGR_OFFSET_Y_REG_H_M      0x48U
#define LSM303AGR_OFFSET_Z_REG_L_M      0x49U
#define LSM303AGR_OFFSET_Z_REG_H_M      0x4AU
#define LSM303AGR_WHO_AM_I_M            0x4FU
#define LSM303AGR_CFG_REG_A_M           0x60U
#define LSM303AGR_CFG_REG_B_M           0x61U
#define LSM303AGR_CFG_REG_C_M           0x62U
#define LSM303AGR_INTCTRL_REG_M         0x63U
   
#define LSM303AGR_OUTX_L_REG_M          0x68U
#define LSM303AGR_OUTX_H_REG_M          0x69U
#define LSM303AGR_OUTY_L_REG_M          0x6AU
#define LSM303AGR_OUTY_H_REG_M          0x6BU
#define LSM303AGR_OUTZ_L_REG_M          0x6CU
#define LSM303AGR_OUTZ_H_REG_M          0x6DU

bool LSM303AGR_GetReg_A( uint8_t RegAddress, uint8_t *reg );
bool LSM303AGR_SetReg_A( uint8_t RegAddress, uint8_t reg );

bool LSM303AGR_GetReg_M( uint8_t RegAddress, uint8_t *reg );
bool LSM303AGR_SetReg_M( uint8_t RegAddress, uint8_t reg );

//-------------------------------- Accelerometer -------------------------------

typedef enum 
{
  LSM303AGR_A_ODR_PD            = 0x00,
  LSM303AGR_A_ODR_1Hz           = 0x01,
  LSM303AGR_A_ODR_10Hz          = 0x02,
  LSM303AGR_A_ODR_25Hz          = 0x03,
  LSM303AGR_A_ODR_50Hz          = 0x04,
  LSM303AGR_A_ODR_100Hz         = 0x05,
  LSM303AGR_A_ODR_200Hz         = 0x06,
  LSM303AGR_A_ODR_400Hz         = 0x07,
  LSM303AGR_A_ODR_1k34Hz        = 0x09,
  LSM303AGR_A_ODR_1k62Hz        = 0x08,
  LSM303AGR_A_ODR_5k37Hz        = 0x09

} Lsm303agr_Acc_Odr_t;

typedef enum 
{
  LSM303AGR_A_2g         = 0,
  LSM303AGR_A_4g         = 1,
  LSM303AGR_A_8g         = 2,
  LSM303AGR_A_16g        = 3,
} Lsm303agr_Acc_Fs_t;

typedef enum 
{
  LSM303AGR_A_8B        = 0,
  LSM303AGR_A_10B       = 1,
  LSM303AGR_A_12B       = 2
} Lsm303gr_Acc_Res_t;

bool LSM303AGR_WhoAmI_A( uint8_t *value );
bool LSM303AGR_Reboot_A( void );
bool LSM303AGR_SetOdr_A( uint8_t Odr);
bool LSM303AGR_SetFs_A( uint8_t Fs);
bool LSM303AGR_SetBdu_A( bool enable );
bool LSM303AGR_SetResolution( uint8_t Resolution );

bool LSM303AGR_GetRawData_A( int16_t *x, int16_t *y, int16_t *z );


//-------------------------------- Magnetometer --------------------------------

typedef enum 
{
  LSM303AGR_M_ODR_10Hz   = 0,
  LSM303AGR_M_ODR_20Hz   = 1,
  LSM303AGR_M_ODR_50Hz   = 2,
  LSM303AGR_M_ODR_100Hz  = 3,
} Lsm303agr_Mag_Odr_t;

typedef enum 
{
  LSM303AGR_M_MODE_CONTINOUSE    = 0,
  LSM303AGR_M_MODE_SINGLE        = 1,
  LSM303AGR_M_MODE_OFF1          = 2,
  LSM303AGR_M_MODE_OFF2          = 3,
} Lsm303agr_Mag_Mode_t;


bool LSM303AGR_WhoAmI_M( uint8_t *value );
bool LSM303AGR_SoftReset_M( void );
bool LSM303AGR_SetOdr_M( uint8_t Odr);
bool LSM303AGR_SetMode_M( uint8_t Mode);
bool LSM303AGR_SetLP_M( bool enable );
bool LSM303AGR_SetTempComp_M( bool enable );
bool LSM303AGR_SetOffCanc_M( bool enable, bool OnlyAtStart );
bool LSM303AGR_SetLpFilter_M( bool enable );
bool LSM303AGR_SetBdu_M( bool enable );

bool LSM303AGR_SaveOffSetValues_M( int16_t X, int16_t Y, int16_t Z );

bool LSM303AGR_GetRawData_M( int16_t *x, int16_t *y, int16_t *z );


//----------------------------------- Module -----------------------------------

bool LSM303AGR_Init( void );

bool LSM303AGR_On( void );

bool LSM303AGR_Off( void );

bool LSM303AGR_MagCalModeOn( void );

bool LSM303AGR_MagCalModeOff( void );

#endif