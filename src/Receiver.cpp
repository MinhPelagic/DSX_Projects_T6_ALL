/**-------------------------------------------------------------------------
@file	Receiver.cpp

@brief	Wrapper over Pulse Receiver

@author	Hoang Nguyen Hoan
@date	June 17, 2021

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

#include "coredev/timer.h"
#include "idelay.h"
#include "convutil.h"
#include "iopinctrl.h"
#include "Receiver.h"
#include "board.h"

#define MAX_NUM_TANK    6

#define TIMER_INT_PRIO				3
/*
#define TIMER_TRIG_WKUP_ID			0
#define TIMER_TRIG_WKUP_PERIOD		4600UL
#define TIMER_TRIG_TIMOUT_ID		1
#define TIMER_TRIG_TIMOUT_PERIOD	1500UL

#define PULSE_RCV_INT_PRIO			2

#define SLEEP_CNT					4
#define TIMEOUT_CNT					3
*/
extern "C" bool DEV_Board(void);

static const IOPinCfg_t s_PulseRcvDevPins[] = PULSE_RCV_DEV_PIN_MAP;
static const int s_NbPulseRcvDevPins = sizeof(s_PulseRcvDevPins) / sizeof(IOPinCfg_t);

static void ReceiverEvtHandler(EMPULSE_EVENT Evt);

static const EMPuslseRcvrCfg_t s_PulseReceiverDevCfg = {
  	.TimerNo = 0,
	.IntPrio = 3,
	.pPins = s_PulseRcvDevPins,
	.NbPins = sizeof(s_PulseRcvDevPins) / sizeof(IOPinCfg_t),
	.EvtHandler = ReceiverEvtHandler
};

static const IOPinCfg_t s_PulseRcvPins[] = PULSE_RCV_PIN_MAP;
static const int s_NbPulseRcvPins = sizeof(s_PulseRcvPins) / sizeof(IOPinCfg_t);

static EMPuslseRcvrCfg_t s_PulseReceiverCfg = {
  	.TimerNo = 0,
	.IntPrio = 3,
	.pPins = s_PulseRcvPins,
	.NbPins = sizeof(s_PulseRcvPins) / sizeof(IOPinCfg_t),
	.EvtHandler = ReceiverEvtHandler,
        .options = 0
};

// EMPulse receiver handle
static EMPulseRcvrDev_t s_ReceiverDev;
static bool s_DidReceiverInit = false;

static TankData_t g_TankData[MAX_NUM_TANK] = {0,};

static uint32_t s_TankDataReadIndex = MAX_NUM_TANK-1;
static uint32_t s_TankDataWriteIndex = 0;

static void ReceiverEvtHandler(EMPULSE_EVENT Evt)
{
  	if (Evt == EMPULSE_EVENT_DATA_READY)
	{
	  	// Got new data
		if (EMPulseRcvrRead(&s_ReceiverDev, &g_TankData[s_TankDataWriteIndex]) == false)
		{
		  	g_TankData[s_TankDataWriteIndex].Pres = -1;
			g_TankData[s_TankDataWriteIndex].BatCond = -1;			  
		}
                int next_write_index = (s_TankDataWriteIndex+1) % MAX_NUM_TANK;
                if (next_write_index != s_TankDataReadIndex)
                {
                  __DMB();  // Make sure memory operations have been done according to expected order
                  s_TankDataWriteIndex = next_write_index;
                }
                  
	}
}

bool ReceiverInit(int alwaysOn)
{
  	bool retval = false;
       
        s_TankDataReadIndex = (s_TankDataWriteIndex + MAX_NUM_TANK - 1) % MAX_NUM_TANK;
        if(alwaysOn) 
        {
          s_PulseReceiverCfg.options |= EMPULSE_RCVR_OPTION_ALWAYS_ON;
        }
        else
        {
          s_PulseReceiverCfg.options &= ~EMPULSE_RCVR_OPTION_ALWAYS_ON;
        }

	if (DEV_Board() != 0)
	{
		retval = EMPulseRcvrInit(&s_ReceiverDev, &s_PulseReceiverDevCfg);
	}
	else
	{
		retval = EMPulseRcvrInit(&s_ReceiverDev, &s_PulseReceiverCfg);
	}
        s_DidReceiverInit = true;
	
	return retval;
}

void ReceiverPoweroff()
{
        if (!s_DidReceiverInit)
        {
          return;
        }
  	EMPulseRcvrPoweroff(&s_ReceiverDev);
}

bool ReceiverRead(TankData_t *pData)
{
        bool retval = false;
        
        if ((s_PulseReceiverCfg.options & EMPULSE_RCVR_OPTION_ALWAYS_ON) == 0)
        {
          // Flush previous entries from FIFO
          s_TankDataReadIndex = (s_TankDataWriteIndex + MAX_NUM_TANK - 1) % MAX_NUM_TANK;
        }
	memcpy(pData, &g_TankData[s_TankDataReadIndex], sizeof(TankData_t));
        int next_read_index = (s_TankDataReadIndex+1) % MAX_NUM_TANK;

        if (next_read_index != s_TankDataWriteIndex)
        {
          __DMB();  // Make sure memory operations have been done according to expected order
          s_TankDataReadIndex = next_read_index;
          retval = true;
        }
	
	return retval;  // Informs that more data is available
}

bool ReceiverEnabled(void)
{  
    if(HAL_GPIO_ReadPin((GPIO_TypeDef*) PULSE_RCVEN_PORT, PULSE_RCVEN_PIN) == 1)
      return 1;
    else
      return 0;
}

