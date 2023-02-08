/*******************************************************************************
 * @file        : DRV8601.c
 * @brief       : Low Level Driver for DRV8601 Haptic Driver for DC Motors.
 *                The Driver is implemented on the Timer A or B module as 
 *                specified in TIMER_MODULE/TIMER_CC.
 *                It is possible to set the drive strength (Max levels 16).
 *                Set the PWM frequency in VIBE_PWM_FREQ_HZ.
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
 * 	The DRV8601 driver is build on the 
 *
 ******************************************************************************/

#include "stdbool.h"
#include "stdint.h"
#include "string.h"

#include "msp430.h"

/*******************************************************************************
 *      DEFINES
 ******************************************************************************/

/* I2C Hardware Settings */
#define VIBE_PORT       2
#define VIBE_CTRL       BIT7
#define VIBE_PWM        BIT2

/* Must be less or equal than 256Hz */
#define VIBE_PWM_FREQ_HZ        64

/* Vibe Strength max levels */
#define VIBE_LEVEL_MAX          16

/* Selects the Timer Module */
/* 0: Timer A0; 1: Timer A1 */
/* 2: Timer B0; 3: Timer B1 */
#define TIMER_MODULE    1

/* Selects the Timer Module Capture/Compare Submodule */
#define TIMER_CC        1

#if defined(VIBE_PORT) && (VIBE_PORT == 1) && defined(P1SEL)
  #define PSEL          P1SEL
  #define PDIR          P1DIR
  #define POUT          P1OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 2) && defined(P2SEL)
  #define PSEL          P2SEL
  #define PDIR          P2DIR
  #define POUT          P2OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 3) && defined(P3SEL)
  #define PSEL          P3SEL
  #define PDIR          P3DIR
  #define POUT          P3OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 4) && defined(P4SEL)
  #define PSEL          P4SEL
  #define PDIR          P4DIR
  #define POUT          P4OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 5) && defined(P5SEL)
  #define PSEL          P5SEL
  #define PDIR          P5DIR
  #define POUT          P5OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 6) && defined(P6SEL)
  #define PSEL          P6SEL
  #define PDIR          P6DIR
  #define POUT          P6OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 7) && defined(P7SEL)
  #define PSEL          P7SEL
  #define PDIR          P7DIR
  #define POUT          P7OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 8) && defined(P8SEL)
  #define PSEL          P8SEL
  #define PDIR          P8DIR
  #define POUT          P8OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 9) && defined(P9SEL)
  #define PSEL          P9SEL
  #define PDIR          P9DIR
  #define POUT          P9OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 10) && defined(P10SEL)
  #define PSEL          P10SEL
  #define PDIR          P10DIR
  #define POUT          P10OUT
#elif defined(VIBE_PORT) && (VIBE_PORT == 11) && defined(P11SEL)
  #define PSEL          P11SEL
  #define PDIR          P11DIR
  #define POUT          P11OUT
#endif


#if defined(TIMER_MODULE) && (TIMER_MODULE == 0)

  #define TIMER_CTRL    TA0CTL
  #define TIMER_CNT     TA0R
  #define TIMER_CCR0    TA0CCR0

  #if defined(TIMER_CC) && (TIMER_CC == 0)
    #define TIMER_CCCTL    TA0CCTL0
    #define TIMER_CCREG    TA0CCR0
  #elif defined(TIMER_CC) && (TIMER_CC == 1)
    #define TIMER_CCCTL    TA0CCTL1
    #define TIMER_CCREG    TA0CCR1
  #elif defined(TIMER_CC) && (TIMER_CC == 2)
    #define TIMER_CCCTL    TA0CCTL2
    #define TIMER_CCREG    TA0CCR2
  #elif defined(TIMER_CC) && (TIMER_CC == 3)
    #define TIMER_CCCTL    TA0CCTL3
    #define TIMER_CCREG    TA0CCR3
  #elif defined(TIMER_CC) && (TIMER_CC == 4)
    #define TIMER_CCCTL    TA0CCTL4
    #define TIMER_CCREG    TA0CCR4
  #elif defined(TIMER_CC) && (TIMER_CC == 5)
    #define TIMER_CCCTL    TA0CCTL5
    #define TIMER_CCREG    TA0CCR5
  #elif defined(TIMER_CC) && (TIMER_CC == 6)
    #define TIMER_CCCTL    TA0CCTL6
    #define TIMER_CCREG    TA0CCR6
  #endif

#elif defined(TIMER_MODULE) && (TIMER_MODULE == 1)

  #define TIMER_CTRL    TA1CTL
  #define TIMER_CNT     TA1R
  #define TIMER_CCR0    TA1CCR0

  #if defined(TIMER_CC) && (TIMER_CC == 0)
    #define TIMER_CCCTL    TA1CCTL0
    #define TIMER_CCREG    TA1CCR0
  #elif defined(TIMER_CC) && (TIMER_CC == 1)
    #define TIMER_CCCTL    TA1CCTL1
    #define TIMER_CCREG    TA1CCR1
  #elif defined(TIMER_CC) && (TIMER_CC == 2)
    #define TIMER_CCCTL    TA1CCTL2
    #define TIMER_CCREG    TA1CCR2
  #elif defined(TIMER_CC) && (TIMER_CC == 3)
    #define TIMER_CCCTL    TA1CCTL3
    #define TIMER_CCREG    TA1CCR3
  #elif defined(TIMER_CC) && (TIMER_CC == 4)
    #define TIMER_CCCTL    TA1CCTL4
    #define TIMER_CCREG    TA1CCR4
  #elif defined(TIMER_CC) && (TIMER_CC == 5)
    #define TIMER_CCCTL    TA1CCTL5
    #define TIMER_CCREG    TA1CCR5
  #elif defined(TIMER_CC) && (TIMER_CC == 6)
    #define TIMER_CCCTL    TA1CCTL6
    #define TIMER_CCREG    TA1CCR6
  #endif

#elif defined(TIMER_MODULE) && (TIMER_MODULE == 2)

  #define TIMER_CTRL    TB0CTL
  #define TIMER_CNT     TB0R
  #define TIMER_CCR0    TB0CCR0

  #if defined(TIMER_CC) && (TIMER_CC == 0)
    #define TIMER_CCCTL    TB0CCTL0
    #define TIMER_CCREG    TB0CCR0
  #elif defined(TIMER_CC) && (TIMER_CC == 1)
    #define TIMER_CCCTL    TB0CCTL1
    #define TIMER_CCREG    TB0CCR1
  #elif defined(TIMER_CC) && (TIMER_CC == 2)
    #define TIMER_CCCTL    TB0CCTL2
    #define TIMER_CCREG    TB0CCR2
  #elif defined(TIMER_CC) && (TIMER_CC == 3)
    #define TIMER_CCCTL    TB0CCTL3
    #define TIMER_CCREG    TB0CCR3
  #elif defined(TIMER_CC) && (TIMER_CC == 4)
    #define TIMER_CCCTL    TB0CCTL4
    #define TIMER_CCREG    TB0CCR4
  #elif defined(TIMER_CC) && (TIMER_CC == 5)
    #define TIMER_CCCTL    TB0CCTL5
    #define TIMER_CCREG    TB0CCR5
  #elif defined(TIMER_CC) && (TIMER_CC == 6)
    #define TIMER_CCCTL    TB0CCTL6
    #define TIMER_CCREG    TB0CCR6
  #endif

#elif defined(TIMER_MODULE) && (TIMER_MODULE == 3)

  #define TIMER_CTRL    TB1CTL
  #define TIMER_CNT     TB1R
  #define TIMER_CCR0    TB1CCR0

  #if defined(TIMER_CC) && (TIMER_CC == 0)
    #define TIMER_CCCTL    TB1CCTL0
    #define TIMER_CCREG    TB1CCR0
  #elif defined(TIMER_CC) && (TIMER_CC == 1)
    #define TIMER_CCCTL    TB1CCTL1
    #define TIMER_CCREG    TB1CCR1
  #elif defined(TIMER_CC) && (TIMER_CC == 2)
    #define TIMER_CCCTL    TB1CCTL2
    #define TIMER_CCREG    TB1CCR2
  #elif defined(TIMER_CC) && (TIMER_CC == 3)
    #define TIMER_CCCTL    TB1CCTL3
    #define TIMER_CCREG    TB1CCR3
  #elif defined(TIMER_CC) && (TIMER_CC == 4)
    #define TIMER_CCCTL    TB1CCTL4
    #define TIMER_CCREG    TB1CCR4
  #elif defined(TIMER_CC) && (TIMER_CC == 5)
    #define TIMER_CCCTL    TB1CCTL5
    #define TIMER_CCREG    TB1CCR5
  #elif defined(TIMER_CC) && (TIMER_CC == 6)
    #define TIMER_CCCTL    TB1CCTL6
    #define TIMER_CCREG    TB1CCR6
  #endif

#endif



/*******************************************************************************
 *      EXTERN FUNCTIONS PROTOTYPE
 ******************************************************************************/

#ifdef __cplusplus  
extern "C" 
#else
extern 
#endif
void VibeOff( void );


#ifdef __cplusplus  
extern "C" 
#else
extern 
#endif
void VibeOn( uint16_t level );


#ifdef __cplusplus  
extern "C" 
#else
extern 
#endif
void VibeOff( void )
{
  /* Stop Timer */
  TIMER_CTRL &= ~(MC0 | MC1);
    
  /* Set Vibe Ctrl pin as Output and Low*/
  PSEL &= ~VIBE_CTRL;
  PDIR |= VIBE_CTRL;
  POUT &= ~VIBE_CTRL;
  
  /* Set Vibe PWM pin as Output and Low*/
  PSEL &= ~VIBE_PWM;
  PDIR |= VIBE_PWM;
  POUT &= ~VIBE_PWM; 
}

#ifdef __cplusplus  
extern "C" 
#else
extern 
#endif
void VibeOn( uint16_t level )
{
  if( level == 0 )
    VibeOff();
  else
  {
    /* Set Vibe PWM pin as PWM Output */
    PSEL |= VIBE_PWM;
    PDIR |= VIBE_PWM;
    POUT &= ~VIBE_CTRL;
    
    /* Stop Timer to allow correct configuration */
    TIMER_CTRL &= ~(MC0 | MC1);
    
    /* Set ACLK as clock source */
    TIMER_CTRL &= ~(TASSEL0 | TASSEL1);
    TIMER_CTRL |= TASSEL_1;
    
    /* Set Clock input divider as /1 */
    TIMER_CTRL &= ~(ID_0 | ID_1 | ID_2 | ID_3);
    TIMER_CTRL |= ID__1;
    
    /* Clear Timer Counter */
    TIMER_CTRL |= TACLR;
    
    /* Set Output mode as PWM Reset/Set */
    TIMER_CCCTL &= ~(OUTMOD0 | OUTMOD1 | OUTMOD2);
    TIMER_CCCTL |= OUTMOD_7;
    
    /* Set PWM Frequency */
    TIMER_CCR0 = (32768/(VIBE_PWM_FREQ_HZ))-1;
    
    /* Set PWM Duty Cycle (Vibe Strength) */
    if( level >= VIBE_LEVEL_MAX )
      TIMER_CCREG = 0;//TIMER_CCR0/2;
    else
      TIMER_CCREG = (uint16_t)((((uint32_t)(TIMER_CCR0+1)*(VIBE_LEVEL_MAX - level))/VIBE_LEVEL_MAX)/2)-1;
    
    /* Start Counter in Up mode */
    TIMER_CTRL |= MC__UP;
    
    /* Set Vibe Ctrl pin as Output and High*/
    PSEL &= ~VIBE_CTRL;
    PDIR |= VIBE_CTRL;
    POUT |= VIBE_CTRL;
  }
}