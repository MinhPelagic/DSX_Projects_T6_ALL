/**-------------------------------------------------------------------------
@file	flash_cmd.h

@brief	Flash command implementation

This file implement the flash command handler

@author	Hoang Nguyen Hoan
@date	Aug. 13, 2019

Copyright (c) 2019 Pelagic Pressure Systems, all rights reserved

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
#ifndef __FLASH_CMD_H__
#define __FLASH_CMD_H__

#define FLASH_READ_MAX_SIZE		96	// This value is defined based on max BLE notification size

void FlashReadCmd(PelagicPacket_t * const pPk);
bool FlashReadData(PelagicPacket_t * const pPk);
void FlashWriteCmd(PelagicPacket_t * const pPkt);
bool FlashWriteData(PelagicPacket_t * const pPk);
void FlashWriteAbort();
bool isFlashBusy();

#endif // __FLASH_CMD_H__
