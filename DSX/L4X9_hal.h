/*******************************************************************************
 * @file        : L4X9_hal.h
 * @brief       : Physical Board abstraction layer.
 *                In this file are specified all Default System initilization 
 *                settings, MCU-Peripherals and external Peripherals settings 
 *                and PinOut Configurations 
 *
 * @version     0.0.0
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2021.
 * Author: Attilio Piacente - Deep InnTech S.r.l.s.
 *******************************************************************************
 *
 *
 ******************************************************************************/


/*******************************************************************************
 * @brief   Debug Pin Configuration
 *
 * @note    If set 1 Debug Pins are available. 
 ******************************************************************************/
#if defined ( BUILD_DEBUG )
  #define ENABLE_DEBUG_PINS       1     
#endif

/*******************************************************************************
 * @brief   GPIO Default Configuration
 ******************************************************************************/

#define GPIO_PIN_NO_DBG         ( GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |\
                                GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 |  \
                                GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 |  \
                                GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |\
                                GPIO_PIN_12 | GPIO_PIN_15 ) 

#define SYSTEM_GPIO_DEFAULT                                                     \
  {                                                                             \
    GPIO_PIN_All,               /* Set all Pins */                              \
    GPIO_MODE_ANALOG,           /* Set to analog input mode */                  \
    GPIO_NOPULL,                /* Set I/O no pull */                           \
    GPIO_SPEED_FREQ_VERY_HIGH,  /* Set Pins to very high frequency operation */ \
    0                          /* Set Alternate Port Funciton 0*/              \
  }

/*******************************************************************************
 * @brief   RTCC Configuration
 *
 * @note    Use BYPSHAD = 1 for workaround ERRATA SHEET STM32L15xxE p.24
 ******************************************************************************/

/* If External Low Frequency Crystal is 32.768kHz the following settings will generate a ck_spre of 1Hz */
#define RTC_ASYNC_DEFAULT_PRESCALER     3		//127
#define RTC_SYNC_DEFAULT_PRESCALER      8191	//255    //  3/8191 => +2 sec faster per hour; 3/8196 => -1 sec slower per hour, 3/8194 => -1 sec slower per hour 

#define HIGH    1
#define LOW     0
   
#define RTC_INIT_DEFAULT                                        \
  {                                                             \
    LL_RTC_HOURFORMAT_24HOUR,     /* 24Hr format */             \
    RTC_ASYNC_DEFAULT_PRESCALER,  /* Asynchronous prescaler */  \
    RTC_SYNC_DEFAULT_PRESCALER,   /* Synchronous prescaler */   \
  }

#define RTC_INIT_TIME_DEFAULT                                                   \
  {                                                                             \
    LL_RTC_TIME_FORMAT_AM_OR_24,  /* 24Hr format @ref RTC_LL_EC_TIME_FORMAT */  \
    0x12,                         /* Hour: in BCD format */                     \
    0x00,                         /* Minutes: in BCD format */                  \
    0x00,                         /* Seconds: in BCD format */                  \
  }

#define RTC_INIT_DATE_DEFAULT                                   \
  {                                                             \
    0x01,                         /* Week Day: in BCD format */ \
    0x08,                         /* Month: in BCD format */    \
    0x01,                         /* Day: in BCD format */      \
    0x22,                         /* Year: in BCD format */     \
  }

#define RTC_WAKEUP_RELOAD       255UL//2047UL
#define RTC_WAKEUP_PRESCALER    LL_RTC_WAKEUPCLOCK_DIV_16
#define RTC_WAKEUP_EXTI_LINE    EXTI_IMR1_IM20          /* See RM0351 p. 404 */                           


/*******************************************************************************
 * @brief   I2C_1 BUS Configuration
 ******************************************************************************/
#define I2C1_SCL_PIN            GPIO_PIN_6
#define I2C1_SCL_PORT           GPIOB
#define I2C1_SDA_PIN            GPIO_PIN_13
#define I2C1_SDA_PORT           GPIOG

/* I2C CLOCK xxx KHz */
#define I2C1_TIMING             0x307077B2// 0x307077B2 for 100khz// 0x00B045E1 for 400khz//0x00501D55 for 1MHz

/*******************************************************************************
 * @brief   I2C_2 BUS Configuration
 ******************************************************************************/
#define I2C2_SCL_PIN            GPIO_PIN_1
#define I2C2_SCL_PORT           GPIOF
#define I2C2_SDA_PIN            GPIO_PIN_0
#define I2C2_SDA_PORT           GPIOF

#define PROD_I2C2_SCL_PIN       GPIO_PIN_10
#define PROD_I2C2_SCL_PORT      GPIOB
#define PROD_I2C2_SDA_PIN       GPIO_PIN_11
#define PROD_I2C2_SDA_PORT      GPIOB   
   
/* I2C CLOCK xxx KHz */
#define I2C2_TIMING             0x307077B2// 0x307077B2 for 100khz// 0x00B045E1 for 400khz//0x00501D55 for 1MHz


/*******************************************************************************
 * @brief   SPI3 Configuration
 ******************************************************************************/ 

#define USE_MT25QL512ABB        1

#define SPI3_CS_PIN      GPIO_PIN_15
#define SPI3_CS_PORT     GPIOA
#define SPI3_CLK_PIN     GPIO_PIN_3
#define SPI3_CLK_PORT    GPIOB
#define SPI3_MISO_PIN    GPIO_PIN_4
#define SPI3_MISO_PORT   GPIOB
#define SPI3_MOSI_PIN    GPIO_PIN_12
#define SPI3_MOSI_PORT   GPIOC

#define PROD_OSPI2_CS_PIN      GPIO_PIN_12
#define PROD_OSPI2_CS_PORT     GPIOG
#define PROD_OSPI2_CLK_PIN     GPIO_PIN_4
#define PROD_OSPI2_CLK_PORT    GPIOF
#define PROD_OSPI2_MISO_PIN    GPIO_PIN_1
#define PROD_OSPI2_MISO_PORT   GPIOF
#define PROD_OSPI2_MOSI_PIN    GPIO_PIN_0
#define PROD_OSPI2_MOSI_PORT   GPIOF
#define PROD_OSPI2_IO2_PIN     GPIO_PIN_2
#define PROD_OSPI2_IO2_PORT    GPIOF
#define PROD_OSPI2_IO3_PIN     GPIO_PIN_3
#define PROD_OSPI2_IO3_PORT    GPIOF

/*******************************************************************************
 * @brief   MicroChip 24Cxx6X EEPROM Configuration
 ******************************************************************************/

#define USE_EE24CWxxX   1

#define EE24CW16X       0       //16kbit
#define EE24CW32X       0       //32kbit
#define EE24CW64X       0       //64kbit
#define EE24CW128X      1      //128kbit


/*******************************************************************************
 * @brief   TE Pressure and Temperature Sensor MS5837_30BA
 ******************************************************************************/
#define USE_MS5837_30BA         1
    
#define MS5837_30BA_OSR_DIVE    MS5837_OSR_256
#define MS5837_30BA_OSR_SURF    MS5837_OSR_8192


/*******************************************************************************
 * @brief   ECompass Defines
 ******************************************************************************/
#define USE_LSM303AGR           1

// LSM303AGR Defines
#define LSM303AGR_NVIC_PRIORITY         3
#define LSM303AGR_NVIC_SUBPRIORITY      3

#define LSM303AGR_INTMAG_PORT           GPIOD
#define LSM303AGR_INTMAG_PIN            GPIO_PIN_11
#define LSM303AGR_INTMAG_IRQ            EXTI15_10_IRQn   
#define LSM303AGR_INTMAG_IRQHANDLER     EXTI15_10_IRQHandler

#define LSM303AGR_INT1_PORT             GPIOD
#define LSM303AGR_INT1_PIN              GPIO_PIN_12
#define LSM303AGR_INT1_IRQ              EXTI15_10_IRQn   
#define LSM303AGR_INT1_IRQHANDLER       EXTI15_10_IRQHandler

#define LSM303AGR_INT2_PORT             GPIOD
#define LSM303AGR_INT2_PIN              GPIO_PIN_13
#define LSM303AGR_INT2_IRQ              EXTI15_10_IRQn   
#define LSM303AGR_INT2_IRQHANDLER       EXTI15_10_IRQHandler



/*******************************************************************************
 * @brief   MAX17262 FUEL GAUGE Defines
 ******************************************************************************/
#define USE_MAX17262            1

#define MAX17262_ALRT_PIN       GPIO_PIN_4
#define MAX17262_ALRT_PORT      GPIOC

#define PROD_MAX17262_ALRT_PIN  GPIO_PIN_8
#define PROD_MAX17262_ALRT_PORT GPIOB

#define MAX17262_CAP_MA         1500    // Battery Nominal Capacity in mA       
#define MAX17262_ITERM_MA       150     // Battery End Charge Current in mA      
#define MAX17262_VEMPTY_V       0xA061  // Battery Empty Voltage 3.2V / 3.8V
#define MAX17262_CH_VOLT_HIGH   1       // 0 if Charge Voltage not higher than 4.25V
        
#define MAX17262_LOW_BAT_ALRT_MV        3200       // Is in mV    


/*******************************************************************************
 * @brief   MAX77950 WPC/PMA Dual Mode Wirless Power Receiver
 ******************************************************************************/
#define USE_MAX77950            1

#define MAX77950_WPEN_PIN       GPIO_PIN_8
#define MAX77950_WPEN_PORT      GPIOB
#define MAX77950_WPDET_PIN      GPIO_PIN_0
#define MAX77950_WPDET_PORT     GPIOC
#define MAX77950_P2PEN_PIN      GPIO_PIN_7
#define MAX77950_P2PEN_PORT     GPIOB
#define MAX77950_INT_PIN        GPIO_PIN_4
#define MAX77950_INT_PORT       GPIOC

/*******************************************************************************
 * @brief   Button Pin Configuration
 ******************************************************************************/
#define BUTTON_NVIC_PRIORITY            3
#define BUTTON_NVIC_SUBPRIORITY         3
 
#define BUTTON_BL_PIN                   GPIO_PIN_0
#define BUTTON_BL_PORT                  GPIOG
#define BUTTON_BL_IRQ                   EXTI0_IRQn   
#define BUTTON_BL_IRQHANDLER            EXTI0_IRQHandler

#define BUTTON_TL_PIN                   GPIO_PIN_1
#define BUTTON_TL_PORT                  GPIOG
#define BUTTON_TL_IRQ                   EXTI1_IRQn   
#define BUTTON_TL_IRQHANDLER            EXTI1_IRQHandler

/*
#define BUTTON_TR_PIN                   GPIO_PIN_2
#define BUTTON_TR_PORT                  GPIOG
#define BUTTON_TR_IRQ                   EXTI2_IRQn  
#define BUTTON_TR_IRQHANDLER            EXTI2_IRQHandler
*/
   
#define BUTTON_BR_PIN                   GPIO_PIN_3
#define BUTTON_BR_PORT                  GPIOG
#define BUTTON_BR_IRQ                   EXTI3_IRQn  
#define BUTTON_BR_IRQHANDLER            EXTI3_IRQHandler
   
//-------------------------------------------------------------
#define PROD_BUTTON_L_PIN                   GPIO_PIN_0
#define PROD_BUTTON_L_PORT                  GPIOG
#define PROD_BUTTON_L_IRQ                   EXTI0_IRQn   
#define PROD_BUTTON_L_IRQHANDLER            EXTI0_IRQHandler

#define PROD_BUTTON_M_PIN                   GPIO_PIN_1
#define PROD_BUTTON_M_PORT                  GPIOG
#define PROD_BUTTON_M_IRQ                   EXTI1_IRQn  
#define PROD_BUTTON_M_IRQHANDLER            EXTI1_IRQHandler

/*
#define PROD_BUTTON_X_PIN                   GPIO_PIN_2
#define PROD_BUTTON_X_PORT                  GPIOG
#define PROD_BUTTON_X_IRQ                   EXTI2_IRQn   
#define PROD_BUTTON_X_IRQHANDLER            EXTI2_IRQHandler
*/

#define PROD_BUTTON_R_PIN                   GPIO_PIN_3
#define PROD_BUTTON_R_PORT                  GPIOG
#define PROD_BUTTON_R_IRQ                   EXTI3_IRQn  
#define PROD_BUTTON_R_IRQHANDLER            EXTI3_IRQHandler   
   
/*******************************************************************************
 * @brief   BUZZER ALARM HW Pin Configuration
 ******************************************************************************/

#define BUZZER_FREQUENCY_HZ     4000
#define BUZZER_DUTY_PERCENT     50

#define BUZZER_DRIVE_PORT       GPIOB
#define BUZZER_DRIVE_PIN        GPIO_PIN_5

#define BUZZER_ENABLE_PORT      GPIOB
#define BUZZER_ENABLE_PIN       GPIO_PIN_1

#define BUZZER_MODE_PORT        GPIOB
#define BUZZER_MODE_PIN         GPIO_PIN_0

/*******************************************************************************
 * @brief   VIBRATOR HW Pin Configuration
 ******************************************************************************/

#define VIBRATOR_FREQUENCY_HZ     40
#define VIBRATOR_DUTY_PERCENT     10

#define VIBRATOR_DRIVE_PORT       GPIOC
#define VIBRATOR_DRIVE_PIN        GPIO_PIN_6

#define VIBRATOR_ENABLE_PORT      GPIOC
#define VIBRATOR_ENABLE_PIN       GPIO_PIN_7

/*******************************************************************************
 * @brief   BACKLIGHT Configuration
 ******************************************************************************/
#define BKL_PORT        GPIOC
#define BKL_PIN         GPIO_PIN_13

#define PROD_BKL_PORT   GPIOB
#define PROD_BKL_PIN    GPIO_PIN_3

/*******************************************************************************
 * @brief   BLUETOOTH Configuration
 ******************************************************************************/
#define BT_RST_PORT             GPIOG
#define BT_RST_PIN              GPIO_PIN_4

#define BT_P1_PORT              GPIOF
#define BT_P1_PIN               GPIO_PIN_2
#define BT_P2_PORT              GPIOF
#define BT_P2_PIN               GPIO_PIN_3
#define BT_P3_PORT              GPIOF
#define BT_P3_PIN               GPIO_PIN_4
#define BT_P4_PORT              GPIOF
#define BT_P4_PIN               GPIO_PIN_5

#define BT_USART                LPUART1
#define BT_USART_SWAP_PINS      0
//-----------------------------------------------------------------

#define PROD_BT_P1_PORT              GPIOI
#define PROD_BT_P1_PIN               GPIO_PIN_4
#define PROD_BT_P2_PORT              GPIOI
#define PROD_BT_P2_PIN               GPIO_PIN_5
#define PROD_BT_P3_PORT              GPIOI
#define PROD_BT_P3_PIN               GPIO_PIN_6
#define PROD_BT_P4_PORT              GPIOI
#define PROD_BT_P4_PIN               GPIO_PIN_7

//-----------------------------------------------------------------
   
#define USART_TX_BT_RX_PORT     GPIOG
#define USART_TX_BT_RX_PIN      GPIO_PIN_7
#define USART_TX_BT_RX_AF       GPIO_AF8_LPUART1

#define USART_RX_BT_TX_PORT     GPIOG
#define USART_RX_BT_TX_PIN      GPIO_PIN_8
#define USART_RX_BT_TX_AF       GPIO_AF8_LPUART1

#define USART_BT_IRQHDL         LPUART1_IRQHandler 
#define USART_BT_IRQ            LPUART1_IRQn


/*******************************************************************************
 * @brief   USB Configuration
 ******************************************************************************/
#define USB_CHARGING_PORT       GPIOA
#define USB_CHARGING_PIN        GPIO_PIN_0

/*******************************************************************************
 * @brief   GPS Configuration
 ******************************************************************************/

#define USE_CXD5605GF           1

#define GPS_PW_CTRL_PORT        GPIOI
#define GPS_PW_CTRL_PIN         GPIO_PIN_2

#define GPS_RST_PORT            GPIOI
#define GPS_RST_PIN             GPIO_PIN_1

#define GPS_RX_USART1_TX_PORT   GPIOA
#define GPS_RX_USART1_TX_PIN    GPIO_PIN_9
#define GPS_RX_USART1_TX_AF     GPIO_AF7_USART1

#define GPS_TX_USART1_RX_PORT   GPIOA
#define GPS_TX_USART1_RX_PIN    GPIO_PIN_10
#define GPS_TX_USART1_RX_AF     GPIO_AF7_USART1

#define UART_GNSS_IRQHDL        USART1_IRQHandler 
#define UART_GNSS_IRQ           USART1_IRQn


/*******************************************************************************
 * @brief   Receiver Configuration
 ******************************************************************************/

#define RCVE_ENABLE_PORT        GPIOG
#define RCVE_ENABLE_PIN         GPIO_PIN_10

/*******************************************************************************
 * @brief   O2 Port Configuration
 ******************************************************************************/

#define O2_SEL_PORT             GPIOA
#define O2_SEL_PIN              GPIO_PIN_3

/*******************************************************************************
 * @brief   ALS Configuration
 ******************************************************************************/

#define OPT3001_INT_PORT        GPIOA
#define OPT3001_INT_PIN         GPIO_PIN_5

/*******************************************************************************
 * @brief   Charge Detector Configuration
 ******************************************************************************/

#define VCHG_FLG_PORT           GPIOH
#define VCHG_FLG_PIN            GPIO_PIN_4


/*******************************************************************************
 * @brief   Battery Charger Config Configuration
 ******************************************************************************/

#define PG_CHARGER_PORT         GPIOH
#define PG_CHARGER_PIN          GPIO_PIN_5

#define CHG_STATUS_PORT         GPIOH
#define CHG_STATUS_PIN          GPIO_PIN_8

/*******************************************************************************
 * @brief   I330C LCD Configuration
 *
 * @note
 ******************************************************************************/

#define USE_LCD_COM24H2P39ULC         1

// LCD Hw Defines
#define LCD_DPVCC_PORT          GPIOG
#define LCD_DPVCC_PIN           GPIO_PIN_15

#define LCD_RST_PORT            GPIOE
#define LCD_RST_PIN             GPIO_PIN_2

#define LCD_IM0_PORT            GPIOE
#define LCD_IM0_PIN             GPIO_PIN_0

#define LCD_IM3_PORT            GPIOE
#define LCD_IM3_PIN             GPIO_PIN_1

#define LCD_CS_PORT             GPIOD
#define LCD_CS_PIN              GPIO_PIN_7

#define LCD_WE_PORT             GPIOD
#define LCD_WE_PIN              GPIO_PIN_5

#define LCD_OE_PORT             GPIOD
#define LCD_OE_PIN              GPIO_PIN_4

#define LCD_RS_PORT             GPIOE
#define LCD_RS_PIN              GPIO_PIN_3

#define LCD_PORTD               GPIOD
#define LCD_D0_PIN              GPIO_PIN_14
#define LCD_D1_PIN              GPIO_PIN_15
#define LCD_D2_PIN              GPIO_PIN_0
#define LCD_D3_PIN              GPIO_PIN_1
#define LCD_D13_PIN             GPIO_PIN_8
#define LCD_D14_PIN             GPIO_PIN_9
#define LCD_D15_PIN             GPIO_PIN_10

#define LCD_PORTD_PINS          (LCD_D0_PIN | LCD_D1_PIN | LCD_D2_PIN | \
                                 LCD_D3_PIN | LCD_D13_PIN | LCD_D14_PIN | \
                                 LCD_D15_PIN | LCD_CS_PIN | LCD_WE_PIN | LCD_OE_PIN)

#define LCD_PORTE               GPIOE
#define LCD_D4_PIN              GPIO_PIN_7
#define LCD_D5_PIN              GPIO_PIN_8
#define LCD_D6_PIN              GPIO_PIN_9
#define LCD_D7_PIN              GPIO_PIN_10
#define LCD_D8_PIN              GPIO_PIN_11
#define LCD_D9_PIN              GPIO_PIN_12
#define LCD_D10_PIN             GPIO_PIN_13
#define LCD_D11_PIN             GPIO_PIN_14
#define LCD_D12_PIN             GPIO_PIN_15

#define LCD_PORTE_PINS          (LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | \
                                LCD_D7_PIN | LCD_D8_PIN | LCD_D9_PIN | \
                                LCD_D10_PIN | LCD_D11_PIN | LCD_D12_PIN | \
                                LCD_RS_PIN)

/*******************************************************************************
 * @brief   Simulation Pin Configuration
 ******************************************************************************/
#define USER_SIMULATE_PORT              GPIOF

#define USER_DOWN_PIN                   GPIO_PIN_15
#define USER_SHIFT_PIN                  GPIO_PIN_14
#define USER_X60_PIN                    GPIO_PIN_13
#define USER_UP_PIN                     GPIO_PIN_12
#define USER_DEMO_PIN                   GPIO_PIN_11

#define PROD_USER_SIMULATE_PORT         GPIOF

#define PROD_USER_DOWN_PIN              GPIO_PIN_15
#define PROD_USER_SHIFT_PIN             GPIO_PIN_14
#define PROD_USER_X60_PIN               GPIO_PIN_13
#define PROD_USER_UP_PIN                GPIO_PIN_12
#define PROD_USER_DEMO_PIN              GPIO_PIN_11

/*******************************************************************************
 * @brief   TEST Pin Configuration
 ******************************************************************************/

#define TP0_PIN                GPIO_PIN_8
#define TP0_PORT               GPIOC

#define TP1_PIN                GPIO_PIN_9
#define TP1_PORT               GPIOC
   
#define TP2_PIN                GPIO_PIN_10
#define TP2_PORT               GPIOC

#define TP3_PIN                GPIO_PIN_11
#define TP3_PORT               GPIOC

#define BOARD_DETECT_PIN        GPIO_PIN_13
#define BOARD_DETECT_PORT       GPIOH
