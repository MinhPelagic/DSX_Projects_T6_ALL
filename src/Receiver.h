/**-------------------------------------------------------------------------
@file	Receiver.h

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
#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "EMPulse.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

bool ReceiverInit(int alwaysOn);
void ReceiverPoweroff();
bool ReceiverRead(TankData_t *pData);

#ifdef __cplusplus
}
#endif // __cplusplus
  
#endif // __RECEIVER_H__

