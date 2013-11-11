#include "limits/all.h"
#include "limits/char.h"
#include "limits/short.h"
#include "limits/long.h"
#include "limits/ill.h"
#include "limits/int.h"
#include "limits/imax.h"
#include "limits/size_t.h"
#include "limits/bool.h"
#include "std/arch.h"

#pragma once
#ifndef ZX_LIMITS_H
#define ZX_LIMITS_H


static zxui   const zxuc_bits   = CHAR_BIT;
static zxuc   const zxuc_last   = ZX_LB( CHAR_BIT );
static zxui   const zxus_bits   = ZXSHRT_BITS;
static zxus   const zxus_last   = ZX_LB( ZXSHRT_BITS );
static zxui   const zxul_bits   = ZXLONG_BITS;
static zxul   const zxul_last   = ZX_LB( ZXLONG_BITS );
static zxui   const zxui_bits   = ZXINT_BITS;
static zxui   const zxui_last   = ZX_LB( ZXINT_BITS );
static zxui   const zxum_bits   = ZXIMAX_BITS;
static zxum   const zxum_last   = ZX_LB( ZXIMAX_BITS );
static zxui   const zxsize_bits = ZXSIZE_BITS;
static size_t const zxsize_last = ZX_LB( ZXSIZE_BITS );
#ifdef ZXUILL_MAX
static zxui   const zxull_bits  = ZXILL_BITS;
static zxull  const zxull_last  = ZX_LB( ZXILL_BITS );
#endif

#endif
