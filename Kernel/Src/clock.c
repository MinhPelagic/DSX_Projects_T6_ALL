#include "msp430f5438a.h"

void SetVcoreUp (unsigned int level);
extern void CLOCK(void);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//#pragma location = "MCODE"

extern void CLOCK(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

  SetVcoreUp (PMMCOREV_2);                  // Set VCore = 1.4V for 4MHz clock

  UCSCTL1 = DCORSEL_5;                      // Select DCO range 4MHz operation
  UCSCTL2 = FLLD_1 + 488;                   // Set DCO Multiplier for 4MHz
                                            // (N + 1) * FLLRef = Fdco
                                            // (488 + 1) * 32768 = 16MHz
                                            // Set FLL Div = fDCOCLK/2
  UCSCTL6 = (UCSCTL6 | XCAP_3 | XT1DRIVE1) & (~XT1OFF) & (~XT1DRIVE1);
                                            // Internal load cap
  UCSCTL3 |= SELREF_0;                      // Set DCO FLL reference = ACLK
  UCSCTL4 |= SELA_0;                        // Set ACLK = XT1CLK
  UCSCTL5 = 0x0030;
  UCSCTL0 = 0x0005;                         // Set lowest possible DCOx, MODx
  
}

//#pragma location = "MCODE"
void SetVcoreUp (unsigned int level)
{
  // Open PMM registers for write
  PMMCTL0_H = PMMPW_H ;
  // Set SVS/SVM high side new level
  SVSMHCTL = SVSHE + SVSHRVL0 * level + SVMHE + SVSMHRRL0 * level;
  // Set SVM low side to new level
  SVSMLCTL = SVSLE + SVMLE + SVSMLRRL0 * level;
  // Wait till SVM is settled
  while ((PMMIFG & SVSMLDLYIFG) == 0);
  // Clear already set flags
  PMMIFG &= ~(SVMLVLRIFG + SVMLIFG);
  // Set VCore to new level
  PMMCTL0_L = PMMCOREV0 * level;
  // Wait till new level reached
  if ((PMMIFG & SVMLIFG))
    while ((PMMIFG & SVMLVLRIFG) == 0);
  // Set SVS/SVM low side to new level
  SVSMLCTL = SVSLE + SVSLRVL0 * level + SVMLE + SVSMLRRL0 * level;
  // Lock PMM registers for write access
  PMMCTL0_H = 0x00;
}

