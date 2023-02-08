/**-------------------------------------------------------------------------
@file	lcd_com24h2p39ulc.h

@brief	COM24H2P39ULC LCD display driver for emWin

@author	Hoang Nguyen Hoan
@date	May 17, 2021

Copyright (c) 2021 Pelagic Pressure Systems, all rights reserved

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------*/

#ifndef __EMWIN_COM24H2P39ULC_H__
#define __EMWIN_COM24H2P39ULC_H__

#include <stdint.h>

#include "stm32l4xx.h"

/// COM24H2P39ULC Resolution
#define COM24H2P39ULC_XSIZE_PHYS  240
#define COM24H2P39ULC_YSIZE_PHYS  320

#define BACKLIGHT_ON    2
#define BACKLIGHT_DIM   1
#define BACKLIGHT_OFF   0

#ifdef __cplusplus
extern "C" {
#endif

void lcd_com24h2p39ulc_init(void);
void lcd_com24h2p39ulc_poweroff(void);
void lcd_com24h2p39ulc_backlight_init();
void lcd_com24h2p39ulc_backlight_set(int Level);

#ifdef __cplusplus
}
#endif

#endif // __EMWIN_COM24H2P39ULC_H__
