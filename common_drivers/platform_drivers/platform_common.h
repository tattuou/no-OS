// ***************************************************************************
// ***************************************************************************
// Copyright 2014 - 2017 (c) Analog Devices, Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// - Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in
// the documentation and/or other materials provided with the
// distribution.
// - Neither the name of Analog Devices, Inc. nor the names of its
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
// - The use of this software may or may not infringe the patent rights
// of one or more patent holders. This license does not release you
// from the requirement that you obtain separate licenses from these
// patent holders to use this software.
// - Use of the software either in source or binary form, must be run
// on or directly connected to an Analog Devices Inc. component.
//
// THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ***************************************************************************
// ***************************************************************************

#ifndef PLATFORM_COMMON_H
#define PLATFORM_COMMON_H

// ***************************************************************************
// ***************************************************************************
/* altera */

#ifdef ALTERA

#include <io.h>
#include <unistd.h>
#include <stdio.h>
#include <system.h>
#include <alt_stdio.h>
#include <alt_cache.h>
#include <alt_types.h>

#define int8_t alt_8
#define int32_t alt_32
#define uint8_t alt_u8
#define uint16_t alt_u16
#define uint32_t alt_u32
#define uint64_t alt_u64

#define ad_printf printf
#define ad_reg_write(x,y) IOWR_32DIRECT(x,0,y)
#define ad_reg_read(x) IORD_32DIRECT(x,0)
#define ad_icache_flush alt_icache_flush_all
#define ad_dcache_flush alt_icache_flush_all
void ad_platform_init(void);
void ad_platform_close(void);
#define udelay(usecs) usleep(usecs)
#define mdelay(msecs) usleep(1000*msecs)

#endif

// ***************************************************************************
// ***************************************************************************
/* xilinx */

#ifdef XILINX

#include <xparameters.h>
#include <xil_printf.h>
#include <xil_io.h>
#include <xil_cache.h>
#include <sleep.h>
#include "platform.h"

#ifdef ZYNQ
#include <xuartps.h>
#endif

#define ad_printf xil_printf
#define ad_reg_write(x,y) Xil_Out32(x,y)
#define ad_reg_read(x) Xil_In32(x)
#define ad_icache_flush Xil_ICacheFlush
#define ad_dcache_flush Xil_DCacheFlush
#define ad_platform_init init_platform
#define ad_platform_close cleanup_platform
#define udelay(usecs) usleep(usecs)
#define mdelay(msecs) usleep(1000*msecs)

#endif

// ***************************************************************************
// ***************************************************************************
/* common */

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define min_t(type, x, y) (type)min((type)(x), (type)(y))
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define max_t(type, x, y) (type)max((type)(x), (type)(y))
#define clamp(val, min_val, max_val) (max(min((val), (max_val)), (min_val)))
#define clamp_t(type, val, min_val, max_val) (type)clamp((type)(val), \
		(type)(min_val), (type)(max_val))

void ad_reg_write_16(uint32_t addr, uint32_t data);
uint64_t do_div(uint64_t* n, uint64_t base);
uint32_t ad_pow2(uint32_t number);

#endif

// ***************************************************************************
// ***************************************************************************
